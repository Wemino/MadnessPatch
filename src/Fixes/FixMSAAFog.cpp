#include "Common.hpp"
#include "Features.hpp"

#include <d3d9.h>
#include <cstring>
#include <cfloat>

static safetyhook::MidHook UpdateD3DDeviceHook{};

static void* D3D9DynamicRHI = nullptr;
static uintptr_t DrawIndexedPrimitiveUP = 0;

static IDirect3DDevice9* FogDevice = nullptr;
static IDirect3DPixelShader9* ClassifyPS = nullptr;
static IDirect3DPixelShader9* ClassifyBackPS = nullptr;
static IDirect3DPixelShader9* GroupDepthPS = nullptr;
static IDirect3DPixelShader9* GroupDepth3PS = nullptr;
static IDirect3DPixelShader9* FrontCopyPS = nullptr;
static IDirect3DPixelShader9* ConstantPS = nullptr;
static IDirect3DSurface9* CountSurface = nullptr;
static IDirect3DTexture9* SumTexture = nullptr;
static IDirect3DTexture9* FarSumTexture = nullptr;
static IDirect3DTexture9* CountTexture = nullptr;
static IDirect3DTexture9* BackDepthTexture = nullptr;
static IDirect3DTexture9* FarDepthTexture = nullptr;
static DWORD MiscCaps = 0;
static DWORD MaxRenderTargets = 0;
static bool bCountWithScene = false;
static bool bThreeGroups = false;
static bool bShadersFailed = false;
static bool bResolveFailed = false;

static float HalfToFloat(uint16_t Half)
{
	const uint32_t Sign = static_cast<uint32_t>(Half & 0x8000) << 16;
	const uint32_t Exponent = (Half >> 10) & 0x1F;
	const uint32_t Mantissa = Half & 0x3FF;

	if (Exponent == 0)
	{
		const float Value = static_cast<float>(Mantissa) * (1.0f / 16777216.0f);
		return Sign ? -Value : Value;
	}

	const uint32_t Bits = Exponent == 31 ? Sign | 0x7F800000 | (Mantissa << 13) : Sign | ((Exponent + 112) << 23) | (Mantissa << 13);
	float Value;
	memcpy(&Value, &Bits, sizeof(Value));
	return Value;
}

static const DWORD ParamsRegister = 223;
static const DWORD FarSumSampler = 11;
static const DWORD CountSampler = 12;
static const DWORD BackDepthSampler = 13;
static const DWORD SumSampler = 14;
static const DWORD SceneSampler = 15;

static const DWORD BackStencil = 0x80;
static const DWORD FarStencil = 0x40;

// ps_3_0
// def c220, 0, 255, 1, 0.98
// dcl_texcoord0 v0.xy
// dcl_2d s15
// mov r0.xy, v0.xy
// mov r0.zw, c220.x
// texldl r1, r0, s15
// mul r2.x, r1.w, c220.w
// add r2.x, -r2.x, c220.z
// mov oDepth, r2.x
// mov oC0, c220.xxxy
// mov oC1, c220.z
static const DWORD ClassifyShader[] =
{
	0xFFFF0300, 0x0200001F, 0x80000005, 0x90030000, 0x05000051, 0xA00F00DC, 0x00000000, 0x437F0000,
	0x3F800000, 0x3F7AE148, 0x0200001F, 0x90000000, 0xA00F080F, 0x02000001, 0x80030000, 0x90540000,
	0x02000001, 0x800C0000, 0xA00000DC, 0x0300005F, 0x800F0001, 0x80E40000, 0xA0E4080F, 0x03000005,
	0x80010002, 0x80FF0001, 0xA0FF00DC, 0x03000002, 0x80010002, 0x81000002, 0xA0AA00DC, 0x02000001,
	0x900F0800, 0x80000002, 0x02000001, 0x800F0800, 0xA04000DC, 0x02000001, 0x800F0801, 0xA0AA00DC,
	0x0000FFFF
};

// ps_3_0
// def c220, 0, 0.5, 1, -0.5
// dcl_texcoord0 v0.xy
// dcl_2d s12
// dcl_2d s14
// dcl_2d s15
// mov r0.xy, v0.xy
// mov r0.zw, c220.x
// texldl r1, r0, s12
// mul r2.x, r1.y, c223.x
// add r2.x, r2.x, c220.y
// frc r2.y, r2.x
// add r2.x, r2.x, -r2.y
// add r3.x, r2.x, c220.w
// mov r8, c220.x
// if_gt r3.x, c220.x
//     texldl r4, r0, s15
//     texldl r5, r0, s14
//     add r6.x, r5.w, -r4.w
//     mul r6.x, r6.x, c223.y
//     mul r6.y, r4.w, c223.x
//     add r6.y, r6.y, -r6.x
//     add r7.x, c223.x, -r2.x
//     max r7.x, r7.x, c220.z
//     rcp r7.y, r7.x
//     rcp r7.z, r2.x
//     mul r8.x, r6.y, r7.y
//     mul r8.w, r6.x, r7.z
// endif
// mov r3, r3.x
// texkill r3
// mov oC0, r8
static const DWORD GroupDepthShader[] =
{
	0xFFFF0300, 0x0200001F, 0x80000005, 0x90030000, 0x05000051, 0xA00F00DC, 0x00000000, 0x3F000000,
	0x3F800000, 0xBF000000, 0x0200001F, 0x90000000, 0xA00F080C, 0x0200001F, 0x90000000, 0xA00F080E,
	0x0200001F, 0x90000000, 0xA00F080F, 0x02000001, 0x80030000, 0x90540000, 0x02000001, 0x800C0000,
	0xA00000DC, 0x0300005F, 0x800F0001, 0x80E40000, 0xA0E4080C, 0x03000005, 0x80010002, 0x80550001,
	0xA00000DF, 0x03000002, 0x80010002, 0x80000002, 0xA05500DC, 0x02000013, 0x80020002, 0x80000002,
	0x03000002, 0x80010002, 0x80000002, 0x81550002, 0x03000002, 0x80010003, 0x80000002, 0xA0FF00DC,
	0x02000001, 0x800F0008, 0xA00000DC, 0x02010029, 0x80000003, 0xA00000DC, 0x0300005F, 0x800F0004,
	0x80E40000, 0xA0E4080F, 0x0300005F, 0x800F0005, 0x80E40000, 0xA0E4080E, 0x03000002, 0x80010006,
	0x80FF0005, 0x81FF0004, 0x03000005, 0x80010006, 0x80000006, 0xA05500DF, 0x03000005, 0x80020006,
	0x80FF0004, 0xA00000DF, 0x03000002, 0x80020006, 0x80550006, 0x81000006, 0x03000002, 0x80010007,
	0xA00000DF, 0x81000002, 0x0300000B, 0x80010007, 0x80000007, 0xA0AA00DC, 0x02000006, 0x80020007,
	0x80000007, 0x02000006, 0x80040007, 0x80000002, 0x03000005, 0x80010008, 0x80550006, 0x80550007,
	0x03000005, 0x80080008, 0x80000006, 0x80AA0007, 0x0000002B, 0x02000001, 0x800F0003, 0x80000003,
	0x01000041, 0x800F0003, 0x02000001, 0x800F0800, 0x80E40008, 0x0000FFFF
};

// ps_3_0
// def c220, 0, 0.5, 1, -0.5
// def c221, 0.98, 0.00390625, 0, 0
// dcl_texcoord0 v0.xy
// dcl_2d s12
// dcl_2d s14
// dcl_2d s15
// mov r0.xy, v0.xy
// mov r0.zw, c220.x
// texldl r1, r0, s12
// mul r2.x, r1.y, c223.x
// add r2.x, r2.x, c220.y
// frc r2.y, r2.x
// add r2.x, r2.x, -r2.y
// add r3.x, r2.x, c220.w
// mov r6, c220.z
// if_gt r3.x, c220.x
//     texldl r4, r0, s15
//     texldl r5, r0, s14
//     add r6.x, r5.w, -r4.w
//     mul r6.x, r6.x, c223.y
//     rcp r6.y, r2.x
//     mul r6.x, r6.x, r6.y
//     mul r6.x, r6.x, c221.x
//     add r6.x, -r6.x, c220.z
// endif
// mov r3, r3.x
// texkill r3
// mov oDepth, r6.x
// mov oC0, c221.zzzy
// mov oC1, c220.z
static const DWORD ClassifyBackShader[] =
{
	0xFFFF0300, 0x0200001F, 0x80000005, 0x90030000, 0x05000051, 0xA00F00DC, 0x00000000, 0x3F000000,
	0x3F800000, 0xBF000000, 0x05000051, 0xA00F00DD, 0x3F7AE148, 0x3B800000, 0x00000000, 0x00000000,
	0x0200001F, 0x90000000, 0xA00F080C, 0x0200001F, 0x90000000, 0xA00F080E, 0x0200001F, 0x90000000,
	0xA00F080F, 0x02000001, 0x80030000, 0x90540000, 0x02000001, 0x800C0000, 0xA00000DC, 0x0300005F,
	0x800F0001, 0x80E40000, 0xA0E4080C, 0x03000005, 0x80010002, 0x80550001, 0xA00000DF, 0x03000002,
	0x80010002, 0x80000002, 0xA05500DC, 0x02000013, 0x80020002, 0x80000002, 0x03000002, 0x80010002,
	0x80000002, 0x81550002, 0x03000002, 0x80010003, 0x80000002, 0xA0FF00DC, 0x02000001, 0x800F0006,
	0xA0AA00DC, 0x02010029, 0x80000003, 0xA00000DC, 0x0300005F, 0x800F0004, 0x80E40000, 0xA0E4080F,
	0x0300005F, 0x800F0005, 0x80E40000, 0xA0E4080E, 0x03000002, 0x80010006, 0x80FF0005, 0x81FF0004,
	0x03000005, 0x80010006, 0x80000006, 0xA05500DF, 0x02000006, 0x80020006, 0x80000002, 0x03000005,
	0x80010006, 0x80000006, 0x80550006, 0x03000005, 0x80010006, 0x80000006, 0xA00000DD, 0x03000002,
	0x80010006, 0x81000006, 0xA0AA00DC, 0x0000002B, 0x02000001, 0x800F0003, 0x80000003, 0x01000041,
	0x800F0003, 0x02000001, 0x900F0800, 0x80000006, 0x02000001, 0x800F0800, 0xA06A00DD, 0x02000001,
	0x800F0801, 0xA0AA00DC, 0x0000FFFF
};

// ps_3_0
// def c220, 0, 0.5, 1, -0.5
// dcl_texcoord0 v0.xy
// dcl_2d s11
// dcl_2d s12
// dcl_2d s14
// dcl_2d s15
// mov r0.xy, v0.xy
// mov r0.zw, c220.x
// texldl r1, r0, s12
// mul r2.xy, r1.yx, c223.x
// add r2.xy, r2.xy, c220.y
// frc r3.xy, r2.xy
// add r2.xy, r2.xy, -r3.xy
// add r3.x, r2.x, c220.w
// mov r8, c220.x
// mov r9, c220.x
// if_gt r3.x, c220.x
//     texldl r4, r0, s15
//     texldl r5, r0, s14
//     texldl r6, r0, s11
//     add r7.x, r5.w, -r4.w
//     add r7.y, r6.w, -r4.w
//     mul r7.xy, r7.xy, c223.y
//     mul r7.z, r4.w, c223.x
//     add r7.z, r7.z, -r7.x
//     add r7.w, r7.x, -r7.y
//     add r10.x, c223.x, -r2.x
//     add r10.y, r2.x, -r2.y
//     mov r10.z, r2.y
//     max r10.xyz, r10.xyz, c220.z
//     rcp r11.x, r10.x
//     rcp r11.y, r10.y
//     rcp r11.z, r10.z
//     mul r8.x, r7.z, r11.x
//     mul r8.w, r7.w, r11.z
//     mul r9.w, r7.y, r11.y
// endif
// mov r3, r3.x
// texkill r3
// mov oC0, r8
// mov oC1, r9
static const DWORD GroupDepth3Shader[] =
{
	0xFFFF0300, 0x0200001F, 0x80000005, 0x90030000, 0x05000051, 0xA00F00DC, 0x00000000, 0x3F000000,
	0x3F800000, 0xBF000000, 0x0200001F, 0x90000000, 0xA00F080B, 0x0200001F, 0x90000000, 0xA00F080C,
	0x0200001F, 0x90000000, 0xA00F080E, 0x0200001F, 0x90000000, 0xA00F080F, 0x02000001, 0x80030000,
	0x90540000, 0x02000001, 0x800C0000, 0xA00000DC, 0x0300005F, 0x800F0001, 0x80E40000, 0xA0E4080C,
	0x03000005, 0x80030002, 0x80010001, 0xA00000DF, 0x03000002, 0x80030002, 0x80540002, 0xA05500DC,
	0x02000013, 0x80030003, 0x80540002, 0x03000002, 0x80030002, 0x80540002, 0x81540003, 0x03000002,
	0x80010003, 0x80000002, 0xA0FF00DC, 0x02000001, 0x800F0008, 0xA00000DC, 0x02000001, 0x800F0009,
	0xA00000DC, 0x02010029, 0x80000003, 0xA00000DC, 0x0300005F, 0x800F0004, 0x80E40000, 0xA0E4080F,
	0x0300005F, 0x800F0005, 0x80E40000, 0xA0E4080E, 0x0300005F, 0x800F0006, 0x80E40000, 0xA0E4080B,
	0x03000002, 0x80010007, 0x80FF0005, 0x81FF0004, 0x03000002, 0x80020007, 0x80FF0006, 0x81FF0004,
	0x03000005, 0x80030007, 0x80540007, 0xA05500DF, 0x03000005, 0x80040007, 0x80FF0004, 0xA00000DF,
	0x03000002, 0x80040007, 0x80AA0007, 0x81000007, 0x03000002, 0x80080007, 0x80000007, 0x81550007,
	0x03000002, 0x8001000A, 0xA00000DF, 0x81000002, 0x03000002, 0x8002000A, 0x80000002, 0x81550002,
	0x02000001, 0x8004000A, 0x80550002, 0x0300000B, 0x8007000A, 0x80A4000A, 0xA0AA00DC, 0x02000006,
	0x8001000B, 0x8000000A, 0x02000006, 0x8002000B, 0x8055000A, 0x02000006, 0x8004000B, 0x80AA000A,
	0x03000005, 0x80010008, 0x80AA0007, 0x8000000B, 0x03000005, 0x80080008, 0x80FF0007, 0x80AA000B,
	0x03000005, 0x80080009, 0x80550007, 0x8055000B, 0x0000002B, 0x02000001, 0x800F0003, 0x80000003,
	0x01000041, 0x800F0003, 0x02000001, 0x800F0800, 0x80E40008, 0x02000001, 0x800F0801, 0x80E40009,
	0x0000FFFF
};

// ps_3_0
// def c220, 0, 0.5, 1, -0.5
// dcl_texcoord0 v0.xy
// dcl_2d s12
// dcl_2d s13
// mov r0.xy, v0.xy
// mov r0.zw, c220.x
// texldl r1, r0, s12
// mul r2.x, r1.y, c223.x
// add r3.x, r2.x, c220.w
// mov r5, c220.x
// if_gt r3.x, c220.x
//     texldl r4, r0, s13
//     mov r5.w, r4.x
// endif
// mov r3, r3.x
// texkill r3
// mov oC0, r5
static const DWORD FrontCopyShader[] =
{
	0xFFFF0300, 0x0200001F, 0x80000005, 0x90030000, 0x05000051, 0xA00F00DC, 0x00000000, 0x3F000000,
	0x3F800000, 0xBF000000, 0x0200001F, 0x90000000, 0xA00F080C, 0x0200001F, 0x90000000, 0xA00F080D,
	0x02000001, 0x80030000, 0x90540000, 0x02000001, 0x800C0000, 0xA00000DC, 0x0300005F, 0x800F0001,
	0x80E40000, 0xA0E4080C, 0x03000005, 0x80010002, 0x80550001, 0xA00000DF, 0x03000002, 0x80010003,
	0x80000002, 0xA0FF00DC, 0x02000001, 0x800F0005, 0xA00000DC, 0x02010029, 0x80000003, 0xA00000DC,
	0x0300005F, 0x800F0004, 0x80E40000, 0xA0E4080D, 0x02000001, 0x80080005, 0x80000004, 0x0000002B,
	0x02000001, 0x800F0003, 0x80000003, 0x01000041, 0x800F0003, 0x02000001, 0x800F0800, 0x80E40005,
	0x0000FFFF
};

// ps_3_0
// mov oC0, c223
// mov oC1, c223
static const DWORD ConstantShader[] =
{
	0xFFFF0300, 0x02000001, 0x800F0800, 0xA0E400DF, 0x02000001, 0x800F0801, 0xA0E400DF, 0x0000FFFF
};

static void ReleaseFogTextures()
{
	if (CountSurface) CountSurface->Release();
	if (SumTexture) SumTexture->Release();
	if (FarSumTexture) FarSumTexture->Release();
	if (CountTexture) CountTexture->Release();
	if (BackDepthTexture) BackDepthTexture->Release();
	if (FarDepthTexture) FarDepthTexture->Release();

	CountSurface = nullptr;
	SumTexture = nullptr;
	FarSumTexture = nullptr;
	CountTexture = nullptr;
	BackDepthTexture = nullptr;
	FarDepthTexture = nullptr;
	bThreeGroups = false;
}

static void ReleaseFogResources()
{
	IDirect3DPixelShader9** Shaders[] = { &ClassifyPS, &ClassifyBackPS, &GroupDepthPS, &GroupDepth3PS, &FrontCopyPS, &ConstantPS };
	for (IDirect3DPixelShader9** Shader : Shaders)
	{
		if (*Shader) (*Shader)->Release();
		*Shader = nullptr;
	}

	ReleaseFogTextures();
	FogDevice = nullptr;
}

struct FogDrawArgs
{
	void* RHI;
	UINT PrimitiveType, MinVertexIndex, NumVertices, NumPrimitives;
	const void* IndexData;
	UINT IndexDataStride;
	const void* VertexData;
	UINT VertexDataStride;
};

static void DrawFogQuad(const FogDrawArgs& Args)
{
	reinterpret_cast<void(__thiscall*)(void*, UINT, UINT, UINT, UINT, const void*, UINT, const void*, UINT)>(DrawIndexedPrimitiveUP)(Args.RHI, Args.PrimitiveType, Args.MinVertexIndex, Args.NumVertices, Args.NumPrimitives, Args.IndexData, Args.IndexDataStride, Args.VertexData, Args.VertexDataStride);
}

static const D3DRENDERSTATETYPE SavedRenderStates[] =
{
	D3DRS_ZENABLE, D3DRS_ZWRITEENABLE, D3DRS_ZFUNC, D3DRS_DEPTHBIAS, D3DRS_SLOPESCALEDEPTHBIAS,
	D3DRS_ALPHABLENDENABLE, D3DRS_SRCBLEND, D3DRS_DESTBLEND, D3DRS_BLENDOP, D3DRS_SEPARATEALPHABLENDENABLE,
	D3DRS_ALPHATESTENABLE, D3DRS_COLORWRITEENABLE, D3DRS_COLORWRITEENABLE1, D3DRS_MULTISAMPLEANTIALIAS, D3DRS_MULTISAMPLEMASK, D3DRS_SRGBWRITEENABLE,
	D3DRS_STENCILENABLE, D3DRS_TWOSIDEDSTENCILMODE, D3DRS_STENCILFUNC, D3DRS_STENCILREF, D3DRS_STENCILMASK, D3DRS_STENCILWRITEMASK,
	D3DRS_STENCILPASS, D3DRS_STENCILFAIL, D3DRS_STENCILZFAIL
};

static const D3DSAMPLERSTATETYPE SavedSamplerStates[] =
{
	D3DSAMP_MINFILTER, D3DSAMP_MAGFILTER, D3DSAMP_MIPFILTER, D3DSAMP_ADDRESSU, D3DSAMP_ADDRESSV, D3DSAMP_SRGBTEXTURE
};

static HRESULT ResolveInto(IDirect3DDevice9* Device, IDirect3DSurface9* Source, IDirect3DTexture9* Target)
{
	IDirect3DSurface9* TargetSurface = nullptr;
	HRESULT hr = Target->GetSurfaceLevel(0, &TargetSurface);
	if (SUCCEEDED(hr))
	{
		hr = Device->StretchRect(Source, nullptr, TargetSurface, nullptr, D3DTEXF_NONE);
		TargetSurface->Release();
	}
	return hr;
}

static bool DepthMatches(IDirect3DDevice9* Device, D3DFORMAT Format, D3DFORMAT DepthFormat)
{
	IDirect3D9* Direct3D = nullptr;
	if (FAILED(Device->GetDirect3D(&Direct3D)))
		return true;

	D3DDEVICE_CREATION_PARAMETERS Creation;
	D3DDISPLAYMODE Mode;
	bool bMatch = true;
	if (SUCCEEDED(Device->GetCreationParameters(&Creation)) && SUCCEEDED(Direct3D->GetAdapterDisplayMode(Creation.AdapterOrdinal, &Mode)))
	{
		bMatch = SUCCEEDED(Direct3D->CheckDepthStencilMatch(Creation.AdapterOrdinal, Creation.DeviceType, Mode.Format, Format, DepthFormat));
	}
	Direct3D->Release();
	return bMatch;
}

static float ReadCountGreen(D3DFORMAT Format, const BYTE* Texel)
{
	uint16_t Half;
	float Value;
	switch (Format)
	{
		case D3DFMT_R5G6B5:
			memcpy(&Half, Texel, sizeof(Half));
			return ((Half >> 5) & 63) / 63.0f;
		case D3DFMT_A8R8G8B8: case D3DFMT_X8R8G8B8:
			return Texel[1] / 255.0f;
		case D3DFMT_A16B16G16R16F:
			memcpy(&Half, Texel + 2, sizeof(Half));
			return HalfToFloat(Half);
		case D3DFMT_A32B32G32R32F:
			memcpy(&Value, Texel + 4, sizeof(Value));
			return Value;
		default:
			return -1.0f;
	}
}

static UINT TexelBytes(D3DFORMAT Format)
{
	return Format == D3DFMT_R5G6B5 ? 2 : Format == D3DFMT_A16B16G16R16F ? 8 : Format == D3DFMT_A32B32G32R32F ? 16 : 4;
}

static float TestCountTarget(IDirect3DDevice9* Device, const FogDrawArgs& Args, IDirect3DSurface9* SceneSurface, D3DFORMAT Format, bool bWithScene)
{
	const UINT BlockSize = 16;
	IDirect3DTexture9* BlockTexture = nullptr;
	IDirect3DSurface9* BlockSurface = nullptr;
	IDirect3DSurface9* BlockCopy = nullptr;
	if (FAILED(Device->CreateTexture(BlockSize, BlockSize, 1, D3DUSAGE_RENDERTARGET, Format, D3DPOOL_DEFAULT, &BlockTexture, nullptr)) || FAILED(BlockTexture->GetSurfaceLevel(0, &BlockSurface)) || FAILED(Device->CreateOffscreenPlainSurface(BlockSize, BlockSize, Format, D3DPOOL_SYSTEMMEM, &BlockCopy, nullptr)))
	{
		if (BlockCopy) BlockCopy->Release();
		if (BlockSurface) BlockSurface->Release();
		if (BlockTexture) BlockTexture->Release();
		return -1.0f;
	}

	D3DVIEWPORT9 Viewport;
	DWORD RenderStates[std::size(SavedRenderStates)];
	IDirect3DPixelShader9* GameShader = nullptr;
	float GameParams[4];
	const float One[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
	Device->GetViewport(&Viewport);
	for (size_t i = 0; i < std::size(SavedRenderStates); i++) Device->GetRenderState(SavedRenderStates[i], &RenderStates[i]);
	Device->GetPixelShader(&GameShader);
	Device->GetPixelShaderConstantF(ParamsRegister, GameParams, 1);

	IDirect3DBaseTexture9* GameSceneSamplerTexture = nullptr;
	DWORD SceneSamplerStates[std::size(SavedSamplerStates)];
	if (bWithScene)
	{
		Device->GetTexture(SceneSampler, &GameSceneSamplerTexture);
		for (size_t i = 0; i < std::size(SavedSamplerStates); i++) Device->GetSamplerState(SceneSampler, SavedSamplerStates[i], &SceneSamplerStates[i]);
		Device->SetSamplerState(SceneSampler, D3DSAMP_MINFILTER, D3DTEXF_POINT);
		Device->SetSamplerState(SceneSampler, D3DSAMP_MAGFILTER, D3DTEXF_POINT);
		Device->SetSamplerState(SceneSampler, D3DSAMP_MIPFILTER, D3DTEXF_NONE);
		Device->SetSamplerState(SceneSampler, D3DSAMP_ADDRESSU, D3DTADDRESS_CLAMP);
		Device->SetSamplerState(SceneSampler, D3DSAMP_ADDRESSV, D3DTADDRESS_CLAMP);
		Device->SetSamplerState(SceneSampler, D3DSAMP_SRGBTEXTURE, FALSE);
		Device->SetTexture(SceneSampler, SumTexture);
	}

	Device->SetRenderTarget(0, CountSurface);
	Device->SetViewport(&Viewport);
	Device->Clear(0, nullptr, D3DCLEAR_TARGET, D3DCOLOR_ARGB(255, 0, 0, 0), 1.0f, 0);
	if (bWithScene)
	{
		Device->SetRenderTarget(0, SceneSurface);
		Device->SetRenderTarget(1, CountSurface);
		Device->SetViewport(&Viewport);
	}

	Device->SetRenderState(D3DRS_ZENABLE, D3DZB_TRUE);
	Device->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);
	Device->SetRenderState(D3DRS_ZFUNC, D3DCMP_ALWAYS);
	Device->SetRenderState(D3DRS_DEPTHBIAS, 0);
	Device->SetRenderState(D3DRS_SLOPESCALEDEPTHBIAS, 0);
	Device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	Device->SetRenderState(D3DRS_SEPARATEALPHABLENDENABLE, FALSE);
	Device->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	Device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_DESTALPHA);
	Device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);
	Device->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
	Device->SetRenderState(D3DRS_SRGBWRITEENABLE, FALSE);
	Device->SetRenderState(D3DRS_COLORWRITEENABLE, bWithScene ? 0 : D3DCOLORWRITEENABLE_GREEN);
	Device->SetRenderState(D3DRS_COLORWRITEENABLE1, D3DCOLORWRITEENABLE_GREEN);
	Device->SetRenderState(D3DRS_MULTISAMPLEANTIALIAS, TRUE);
	Device->SetRenderState(D3DRS_MULTISAMPLEMASK, 0xFFFFFFFF);
	Device->SetRenderState(D3DRS_STENCILENABLE, TRUE);
	Device->SetRenderState(D3DRS_TWOSIDEDSTENCILMODE, FALSE);
	Device->SetRenderState(D3DRS_STENCILFUNC, D3DCMP_ALWAYS);
	Device->SetRenderState(D3DRS_STENCILWRITEMASK, 0);
	Device->SetPixelShader(bWithScene ? ClassifyPS : ConstantPS);
	Device->SetPixelShaderConstantF(ParamsRegister, One, 1);
	DrawFogQuad(Args);

	if (bWithScene)
	{
		Device->SetRenderTarget(1, nullptr);
		Device->SetTexture(SceneSampler, GameSceneSamplerTexture);
		for (size_t i = 0; i < std::size(SavedSamplerStates); i++)
		{
			Device->SetSamplerState(SceneSampler, SavedSamplerStates[i], SceneSamplerStates[i]);
		}
		if (GameSceneSamplerTexture) GameSceneSamplerTexture->Release();
	}
	Device->SetRenderTarget(0, SceneSurface);
	Device->SetViewport(&Viewport);
	for (size_t i = 0; i < std::size(SavedRenderStates); i++)
	{
		Device->SetRenderState(SavedRenderStates[i], RenderStates[i]);
	}
	Device->SetPixelShader(GameShader);
	if (GameShader) GameShader->Release();
	Device->SetPixelShaderConstantF(ParamsRegister, GameParams, 1);

	const LONG X = static_cast<LONG>(Viewport.X + Viewport.Width / 2) - static_cast<LONG>(BlockSize / 2);
	const LONG Y = static_cast<LONG>(Viewport.Y + Viewport.Height / 2) - static_cast<LONG>(BlockSize / 2);
	const RECT Block = { X, Y, X + static_cast<LONG>(BlockSize), Y + static_cast<LONG>(BlockSize) };
	float Green = -1.0f;
	D3DLOCKED_RECT Locked;
	if (SUCCEEDED(Device->StretchRect(CountSurface, &Block, BlockSurface, nullptr, D3DTEXF_NONE)) && SUCCEEDED(Device->GetRenderTargetData(BlockSurface, BlockCopy)) && SUCCEEDED(BlockCopy->LockRect(&Locked, nullptr, D3DLOCK_READONLY)))
	{
		Green = FLT_MAX;
		for (UINT y = 0; y < BlockSize; y++)
		{
			for (UINT x = 0; x < BlockSize; x++)
			{
				Green = std::min(Green, ReadCountGreen(Format, static_cast<const BYTE*>(Locked.pBits) + y * Locked.Pitch + x * TexelBytes(Format)));
			}
		}
		BlockCopy->UnlockRect();
	}

	BlockCopy->Release();
	BlockSurface->Release();
	BlockTexture->Release();
	return Green;
}

static bool CreateFogResources(IDirect3DDevice9* Device, const FogDrawArgs& Args, IDirect3DSurface9* SceneSurface, const D3DSURFACE_DESC& TargetDesc, D3DFORMAT DepthFormat, const D3DSURFACE_DESC& SceneDesc)
{
	if (FogDevice != Device)
	{
		ReleaseFogResources();
		FogDevice = Device;
	}

	if (bResolveFailed)
		return false;

	if (!ConstantPS)
	{
		if (bShadersFailed)
			return false;

		D3DCAPS9 Caps;
		bool bCreated = SUCCEEDED(Device->GetDeviceCaps(&Caps));
		const struct { const DWORD* Code; IDirect3DPixelShader9** Shader; } Shaders[] =
		{
			{ ClassifyShader, &ClassifyPS }, { ClassifyBackShader, &ClassifyBackPS }, { GroupDepthShader, &GroupDepthPS },
			{ GroupDepth3Shader, &GroupDepth3PS }, { FrontCopyShader, &FrontCopyPS }, { ConstantShader, &ConstantPS }
		};
		for (const auto& Shader : Shaders)
		{
			bCreated = bCreated && SUCCEEDED(Device->CreatePixelShader(Shader.Code, Shader.Shader));
		}

		if (!bCreated)
		{
			bShadersFailed = true;
			ReleaseFogResources();
			return false;
		}

		MiscCaps = Caps.PrimitiveMiscCaps;
		MaxRenderTargets = Caps.NumSimultaneousRTs;
	}

	if (CountSurface)
	{
		D3DSURFACE_DESC CountDesc, SumDesc;
		CountSurface->GetDesc(&CountDesc);
		SumTexture->GetLevelDesc(0, &SumDesc);

		if (SumDesc.Width != SceneDesc.Width || SumDesc.Height != SceneDesc.Height || SumDesc.Format != SceneDesc.Format || CountDesc.MultiSampleType != TargetDesc.MultiSampleType || CountDesc.MultiSampleQuality != TargetDesc.MultiSampleQuality)
		{
			ReleaseFogTextures();
		}
	}

	if (!CountSurface)
	{
		const UINT Width = SceneDesc.Width;
		const UINT Height = SceneDesc.Height;

		IDirect3DTexture9** Textures[] = { &SumTexture, &BackDepthTexture };
		bool bCreated = true;
		for (IDirect3DTexture9** Texture : Textures)
		{
			bCreated = SUCCEEDED(Device->CreateTexture(Width, Height, 1, D3DUSAGE_RENDERTARGET, SceneDesc.Format, D3DPOOL_DEFAULT, Texture, nullptr)) && bCreated;
		}

		if (!bCreated)
		{
			ReleaseFogTextures();
			return false;
		}

		if (FixMSAAFog >= 2 && MaxRenderTargets >= 2)
		{
			bThreeGroups = SUCCEEDED(Device->CreateTexture(Width, Height, 1, D3DUSAGE_RENDERTARGET, SceneDesc.Format, D3DPOOL_DEFAULT, &FarSumTexture, nullptr)) && SUCCEEDED(Device->CreateTexture(Width, Height, 1, D3DUSAGE_RENDERTARGET, SceneDesc.Format, D3DPOOL_DEFAULT, &FarDepthTexture, nullptr));
			if (!bThreeGroups)
			{
				if (FarSumTexture) FarSumTexture->Release();
				if (FarDepthTexture) FarDepthTexture->Release();
				FarSumTexture = nullptr;
				FarDepthTexture = nullptr;
			}
		}

		if (FAILED(ResolveInto(Device, SceneSurface, SumTexture)))
		{
			bResolveFailed = true;
			ReleaseFogResources();
			return false;
		}

		const DWORD MRTCaps = D3DPMISCCAPS_INDEPENDENTWRITEMASKS | D3DPMISCCAPS_MRTPOSTPIXELSHADERBLENDING;
		const D3DFORMAT CountFormats[] = { TargetDesc.MultiSampleType <= D3DMULTISAMPLE_8_SAMPLES ? D3DFMT_R5G6B5 : D3DFMT_A8R8G8B8, D3DFMT_A8R8G8B8, SceneDesc.Format };
		for (size_t f = 0; f < std::size(CountFormats) && !CountSurface; f++)
		{
			const D3DFORMAT Format = CountFormats[f];
			const bool bSceneFormat = Format == SceneDesc.Format;
			if (std::find(CountFormats, CountFormats + f, Format) != CountFormats + f)
				continue;

			if (!bSceneFormat && !DepthMatches(Device, Format, DepthFormat))
				continue;

			const HRESULT hrSurface = Device->CreateRenderTarget(Width, Height, Format, TargetDesc.MultiSampleType, TargetDesc.MultiSampleQuality, FALSE, &CountSurface, nullptr);
			const HRESULT hrTexture = SUCCEEDED(hrSurface) ? Device->CreateTexture(Width, Height, 1, D3DUSAGE_RENDERTARGET, Format, D3DPOOL_DEFAULT, &CountTexture, nullptr) : E_FAIL;
			const HRESULT hrResolve = SUCCEEDED(hrTexture) ? ResolveInto(Device, CountSurface, CountTexture) : E_FAIL;
			if (SUCCEEDED(hrResolve))
			{
				const bool bMRT = MaxRenderTargets >= 2 && (MiscCaps & MRTCaps) == MRTCaps && (bSceneFormat || (MiscCaps & D3DPMISCCAPS_MRTINDEPENDENTBITDEPTHS));
				const float WithScene = bMRT ? TestCountTarget(Device, Args, SceneSurface, Format, true) : -1.0f;
				const float Alone = TestCountTarget(Device, Args, SceneSurface, Format, false);
				if (WithScene > 0.99f || Alone > 0.99f || (bSceneFormat && Alone < 0.0f))
				{
					bCountWithScene = WithScene > 0.99f;
					continue;
				}
			}

			if (CountSurface) CountSurface->Release();
			if (CountTexture) CountTexture->Release();
			CountSurface = nullptr;
			CountTexture = nullptr;
		}

		if (!CountSurface)
		{
			bResolveFailed = true;
			ReleaseFogResources();
			return false;
		}
	}

	return true;
}

static bool DrawSplitFog(IDirect3DDevice9* Device, const FogDrawArgs& Args)
{
	IDirect3DSurface9* SceneSurface = nullptr;
	IDirect3DSurface9* SecondSurface = nullptr;
	IDirect3DSurface9* DepthSurface = nullptr;
	IDirect3DBaseTexture9* SceneTexture = nullptr;
	IDirect3DPixelShader9* FogShader = nullptr;
	bool bResult = false;

	Device->GetRenderTarget(0, &SceneSurface);
	Device->GetRenderTarget(1, &SecondSurface);
	Device->GetDepthStencilSurface(&DepthSurface);
	Device->GetTexture(0, &SceneTexture);
	Device->GetPixelShader(&FogShader);

	D3DSURFACE_DESC TargetDesc, DepthDesc, SceneDesc;
	if (Args.NumVertices == 4 && Args.VertexDataStride == sizeof(float) * 2 &&
		SceneSurface && !SecondSurface && DepthSurface && SceneTexture && FogShader && SceneTexture->GetType() == D3DRTYPE_TEXTURE &&
		SUCCEEDED(SceneSurface->GetDesc(&TargetDesc)) && SUCCEEDED(DepthSurface->GetDesc(&DepthDesc)) &&
		SUCCEEDED(static_cast<IDirect3DTexture9*>(SceneTexture)->GetLevelDesc(0, &SceneDesc)))
	{
		const bool bMultisampled = TargetDesc.MultiSampleType >= D3DMULTISAMPLE_2_SAMPLES && TargetDesc.MultiSampleType <= D3DMULTISAMPLE_16_SAMPLES;
		const bool bStencil = DepthDesc.Format == D3DFMT_D24S8 || DepthDesc.Format == D3DFMT_D24FS8 || DepthDesc.Format == MAKEFOURCC('I', 'N', 'T', 'Z');
		const bool bSameSize = TargetDesc.Width == SceneDesc.Width && TargetDesc.Height == SceneDesc.Height && TargetDesc.Format == SceneDesc.Format;

		if (bMultisampled && bStencil && bSameSize && CreateFogResources(Device, Args, SceneSurface, TargetDesc, DepthDesc.Format, SceneDesc))
		{
			D3DVIEWPORT9 Viewport;
			DWORD RenderStates[std::size(SavedRenderStates)];
			const DWORD Samplers[] = { FarSumSampler, CountSampler, BackDepthSampler, SumSampler, SceneSampler };
			DWORD SamplerStates[std::size(Samplers)][std::size(SavedSamplerStates)];
			IDirect3DBaseTexture9* SamplerTextures[std::size(Samplers)] = {};
			float SavedParams[4];

			Device->GetViewport(&Viewport);

			// Same quad pushed out by one pixel, every output of the fog vertex shader is linear in the position
			float QuadVertices[4][2];
			const float* SourceVertices = static_cast<const float*>(Args.VertexData);
			for (int i = 0; i < 4; i++)
			{
				QuadVertices[i][0] = SourceVertices[i * 2] * (1.0f + 2.0f / static_cast<float>(Viewport.Width));
				QuadVertices[i][1] = SourceVertices[i * 2 + 1] * (1.0f + 2.0f / static_cast<float>(Viewport.Height));
			}

			FogDrawArgs QuadArgs = Args;
			QuadArgs.VertexData = QuadVertices;

			for (size_t i = 0; i < std::size(SavedRenderStates); i++)
			{
				Device->GetRenderState(SavedRenderStates[i], &RenderStates[i]);
			}
			for (size_t s = 0; s < std::size(Samplers); s++)
			{
				for (size_t i = 0; i < std::size(SavedSamplerStates); i++) Device->GetSamplerState(Samplers[s], SavedSamplerStates[i], &SamplerStates[s][i]);
				Device->GetTexture(Samplers[s], &SamplerTextures[s]);
			}
			Device->GetPixelShaderConstantF(ParamsRegister, SavedParams, 1);

			auto RestoreGameStates = [&]()
			{
				for (size_t i = 0; i < std::size(SavedRenderStates); i++)
				{
					Device->SetRenderState(SavedRenderStates[i], RenderStates[i]);
				}
			};

			auto RestoreSamplers = [&]()
			{
				for (size_t s = 0; s < std::size(Samplers); s++)
				{
					Device->SetTexture(Samplers[s], SamplerTextures[s]);
					for (size_t i = 0; i < std::size(SavedSamplerStates); i++) Device->SetSamplerState(Samplers[s], SavedSamplerStates[i], SamplerStates[s][i]);
				}
			};

			// A texture is only bound while it isn't being drawn to
			for (DWORD Sampler : Samplers)
			{
				Device->SetSamplerState(Sampler, D3DSAMP_MINFILTER, D3DTEXF_POINT);
				Device->SetSamplerState(Sampler, D3DSAMP_MAGFILTER, D3DTEXF_POINT);
				Device->SetSamplerState(Sampler, D3DSAMP_MIPFILTER, D3DTEXF_NONE);
				Device->SetSamplerState(Sampler, D3DSAMP_ADDRESSU, D3DTADDRESS_CLAMP);
				Device->SetSamplerState(Sampler, D3DSAMP_ADDRESSV, D3DTADDRESS_CLAMP);
				Device->SetSamplerState(Sampler, D3DSAMP_SRGBTEXTURE, FALSE);
			}
			Device->SetTexture(FarSumSampler, FarSumTexture);
			Device->SetTexture(CountSampler, CountTexture);
			Device->SetTexture(BackDepthSampler, nullptr);
			Device->SetTexture(SumSampler, SumTexture);
			Device->SetTexture(SceneSampler, SceneTexture);

			IDirect3DSurface9* SumSurface = nullptr;
			IDirect3DSurface9* FarSumSurface = nullptr;
			IDirect3DSurface9* CountResolveSurface = nullptr;
			IDirect3DSurface9* BackDepthSurface = nullptr;
			IDirect3DSurface9* FarDepthSurface = nullptr;
			SumTexture->GetSurfaceLevel(0, &SumSurface);
			CountTexture->GetSurfaceLevel(0, &CountResolveSurface);
			BackDepthTexture->GetSurfaceLevel(0, &BackDepthSurface);
			if (bThreeGroups)
			{
				FarSumTexture->GetSurfaceLevel(0, &FarSumSurface);
				FarDepthTexture->GetSurfaceLevel(0, &FarDepthSurface);
			}
			const DWORD GroupStencilMask = bThreeGroups ? BackStencil | FarStencil : BackStencil;

			const DWORD NumSamples = TargetDesc.MultiSampleType;
			const float SampleParams[4] = { static_cast<float>(NumSamples), static_cast<float>(NumSamples) / 255.0f, 0.0f, 0.0f };
			const float CountValue[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
			const float ScaleDown[4] = { 0.0f, 0.0f, 0.0f, 1.0f / 256.0f };
			const RECT ViewRect = { static_cast<LONG>(Viewport.X), static_cast<LONG>(Viewport.Y), static_cast<LONG>(Viewport.X + Viewport.Width), static_cast<LONG>(Viewport.Y + Viewport.Height) };

			auto SetTarget = [&](IDirect3DSurface9* Surface, IDirect3DSurface9* Depth)
			{
				Device->SetRenderTarget(0, Surface);
				Device->SetDepthStencilSurface(Depth);
				Device->SetViewport(&Viewport);
			};

			auto Resolve = [&](IDirect3DSurface9* Source, IDirect3DSurface9* Target)
			{
				Device->StretchRect(Source, &ViewRect, Target, &ViewRect, D3DTEXF_NONE);
			};

			// Alpha cleared to 1 for the blend of the sorting pass, formats without alpha read 1 anyway
			SetTarget(CountSurface, DepthSurface);
			Device->Clear(0, nullptr, D3DCLEAR_TARGET, D3DCOLOR_ARGB(255, 0, 0, 0), 1.0f, 0);

			// Samples behind the split: stencil bit set, alpha scaled up, counted
			SetTarget(SceneSurface, DepthSurface);
			if (bCountWithScene) Device->SetRenderTarget(1, CountSurface);
			Device->SetRenderState(D3DRS_ZENABLE, D3DZB_TRUE);
			Device->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);
			Device->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESS);
			Device->SetRenderState(D3DRS_DEPTHBIAS, 0);
			Device->SetRenderState(D3DRS_SLOPESCALEDEPTHBIAS, 0);
			Device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
			Device->SetRenderState(D3DRS_SEPARATEALPHABLENDENABLE, FALSE);
			Device->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
			Device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_DESTALPHA);
			Device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);
			Device->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
			Device->SetRenderState(D3DRS_SRGBWRITEENABLE, FALSE);
			Device->SetRenderState(D3DRS_COLORWRITEENABLE, D3DCOLORWRITEENABLE_ALPHA);
			Device->SetRenderState(D3DRS_COLORWRITEENABLE1, D3DCOLORWRITEENABLE_GREEN);
			Device->SetRenderState(D3DRS_MULTISAMPLEANTIALIAS, TRUE);
			Device->SetRenderState(D3DRS_MULTISAMPLEMASK, 0xFFFFFFFF);
			Device->SetRenderState(D3DRS_STENCILENABLE, TRUE);
			Device->SetRenderState(D3DRS_TWOSIDEDSTENCILMODE, FALSE);
			Device->SetRenderState(D3DRS_STENCILFUNC, D3DCMP_ALWAYS);
			Device->SetRenderState(D3DRS_STENCILREF, BackStencil);
			Device->SetRenderState(D3DRS_STENCILMASK, BackStencil);
			Device->SetRenderState(D3DRS_STENCILWRITEMASK, BackStencil);
			Device->SetRenderState(D3DRS_STENCILPASS, D3DSTENCILOP_REPLACE);
			Device->SetRenderState(D3DRS_STENCILFAIL, D3DSTENCILOP_KEEP);
			Device->SetRenderState(D3DRS_STENCILZFAIL, D3DSTENCILOP_KEEP);
			Device->SetPixelShader(ClassifyPS);
			DrawFogQuad(QuadArgs);

			if (bCountWithScene)
			{
				Device->SetRenderTarget(1, nullptr);
			}
			else
			{
				SetTarget(CountSurface, DepthSurface);
				Device->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
				Device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
				Device->SetRenderState(D3DRS_COLORWRITEENABLE, D3DCOLORWRITEENABLE_GREEN);
				Device->SetRenderState(D3DRS_STENCILFUNC, D3DCMP_EQUAL);
				Device->SetRenderState(D3DRS_STENCILWRITEMASK, 0);
				Device->SetPixelShader(ConstantPS);
				Device->SetPixelShaderConstantF(ParamsRegister, CountValue, 1);
				DrawFogQuad(QuadArgs);
			}

			Resolve(SceneSurface, SumSurface);
			Resolve(CountSurface, CountResolveSurface);

			if (bThreeGroups)
			{
				// Samples behind the split and in front of the second one: alpha scaled back, counted. The ones behind it: far bit
				SetTarget(SceneSurface, DepthSurface);
				if (bCountWithScene) Device->SetRenderTarget(1, CountSurface);
				Device->SetRenderState(D3DRS_ZENABLE, D3DZB_TRUE);
				Device->SetRenderState(D3DRS_ZFUNC, D3DCMP_GREATEREQUAL);
				Device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
				Device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ZERO);
				Device->SetRenderState(D3DRS_COLORWRITEENABLE, D3DCOLORWRITEENABLE_ALPHA);
				Device->SetRenderState(D3DRS_COLORWRITEENABLE1, D3DCOLORWRITEENABLE_RED);
				Device->SetRenderState(D3DRS_STENCILENABLE, TRUE);
				Device->SetRenderState(D3DRS_STENCILFUNC, D3DCMP_EQUAL);
				Device->SetRenderState(D3DRS_STENCILMASK, BackStencil);
				Device->SetRenderState(D3DRS_STENCILREF, BackStencil | FarStencil);
				Device->SetRenderState(D3DRS_STENCILWRITEMASK, FarStencil);
				Device->SetRenderState(D3DRS_STENCILPASS, D3DSTENCILOP_KEEP);
				Device->SetRenderState(D3DRS_STENCILZFAIL, D3DSTENCILOP_REPLACE);
				Device->SetPixelShader(ClassifyBackPS);
				Device->SetPixelShaderConstantF(ParamsRegister, SampleParams, 1);
				DrawFogQuad(QuadArgs);

				if (bCountWithScene)
				{
					Device->SetRenderTarget(1, nullptr);
				}
				else
				{
					SetTarget(CountSurface, DepthSurface);
					Device->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
					Device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
					Device->SetRenderState(D3DRS_COLORWRITEENABLE, D3DCOLORWRITEENABLE_RED);
					Device->SetRenderState(D3DRS_STENCILMASK, BackStencil | FarStencil);
					Device->SetRenderState(D3DRS_STENCILREF, BackStencil);
					Device->SetRenderState(D3DRS_STENCILWRITEMASK, 0);
					Device->SetPixelShader(ConstantPS);
					Device->SetPixelShaderConstantF(ParamsRegister, CountValue, 1);
					DrawFogQuad(QuadArgs);
				}

				Resolve(SceneSurface, FarSumSurface);
				Resolve(CountSurface, CountResolveSurface);

				SetTarget(BackDepthSurface, nullptr);
				Device->SetRenderTarget(1, FarDepthSurface);
				Device->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
				Device->SetRenderState(D3DRS_STENCILENABLE, FALSE);
				Device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
				Device->SetRenderState(D3DRS_COLORWRITEENABLE, 0xF);
				Device->SetRenderState(D3DRS_COLORWRITEENABLE1, 0xF);
				Device->SetPixelShader(GroupDepth3PS);
				Device->SetPixelShaderConstantF(ParamsRegister, SampleParams, 1);
				DrawFogQuad(QuadArgs);
				Device->SetRenderTarget(1, nullptr);
			}
			else
			{
				SetTarget(BackDepthSurface, nullptr);
				Device->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
				Device->SetRenderState(D3DRS_STENCILENABLE, FALSE);
				Device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
				Device->SetRenderState(D3DRS_COLORWRITEENABLE, 0xF);
				Device->SetPixelShader(GroupDepthPS);
				Device->SetPixelShaderConstantF(ParamsRegister, SampleParams, 1);
				DrawFogQuad(QuadArgs);
			}

			SetTarget(SumSurface, nullptr);
			Device->SetTexture(SumSampler, nullptr);
			Device->SetTexture(BackDepthSampler, BackDepthTexture);
			Device->SetRenderState(D3DRS_COLORWRITEENABLE, D3DCOLORWRITEENABLE_ALPHA);
			Device->SetPixelShader(FrontCopyPS);
			DrawFogQuad(QuadArgs);

			// The fog of the game on each side of the split with its own depth
			SetTarget(SceneSurface, DepthSurface);
			RestoreSamplers();
			RestoreGameStates();
			Device->SetRenderState(D3DRS_STENCILENABLE, TRUE);
			Device->SetRenderState(D3DRS_TWOSIDEDSTENCILMODE, FALSE);
			Device->SetRenderState(D3DRS_STENCILFUNC, D3DCMP_EQUAL);
			Device->SetRenderState(D3DRS_STENCILMASK, BackStencil);
			Device->SetRenderState(D3DRS_STENCILWRITEMASK, 0);
			Device->SetRenderState(D3DRS_STENCILPASS, D3DSTENCILOP_KEEP);
			Device->SetRenderState(D3DRS_STENCILFAIL, D3DSTENCILOP_KEEP);
			Device->SetRenderState(D3DRS_STENCILZFAIL, D3DSTENCILOP_KEEP);
			Device->SetPixelShader(FogShader);
			Device->SetPixelShaderConstantF(ParamsRegister, SavedParams, 1);
			Device->SetRenderState(D3DRS_STENCILREF, 0);
			Device->SetTexture(0, SumTexture);
			DrawFogQuad(QuadArgs);
			Device->SetRenderState(D3DRS_STENCILMASK, GroupStencilMask);
			Device->SetRenderState(D3DRS_STENCILREF, BackStencil);
			Device->SetTexture(0, BackDepthTexture);
			DrawFogQuad(QuadArgs);
			if (bThreeGroups)
			{
				Device->SetRenderState(D3DRS_STENCILREF, BackStencil | FarStencil);
				Device->SetTexture(0, FarDepthTexture);
				DrawFogQuad(QuadArgs);
			}

			Device->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
			Device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
			Device->SetRenderState(D3DRS_SEPARATEALPHABLENDENABLE, FALSE);
			Device->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
			Device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_ZERO);
			Device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_SRCALPHA);
			Device->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
			Device->SetRenderState(D3DRS_SRGBWRITEENABLE, FALSE);
			Device->SetRenderState(D3DRS_COLORWRITEENABLE, D3DCOLORWRITEENABLE_ALPHA);
			Device->SetRenderState(D3DRS_MULTISAMPLEANTIALIAS, TRUE);
			Device->SetRenderState(D3DRS_MULTISAMPLEMASK, 0xFFFFFFFF);
			Device->SetRenderState(D3DRS_STENCILREF, GroupStencilMask);
			Device->SetRenderState(D3DRS_STENCILWRITEMASK, GroupStencilMask);
			Device->SetRenderState(D3DRS_STENCILPASS, D3DSTENCILOP_ZERO);
			Device->SetRenderState(D3DRS_STENCILFAIL, bThreeGroups ? D3DSTENCILOP_ZERO : D3DSTENCILOP_KEEP);
			Device->SetPixelShader(ConstantPS);
			Device->SetPixelShaderConstantF(ParamsRegister, ScaleDown, 1);
			DrawFogQuad(QuadArgs);

			Device->SetPixelShader(FogShader);
			Device->SetTexture(0, SceneTexture);
			Device->SetPixelShaderConstantF(ParamsRegister, SavedParams, 1);
			RestoreGameStates();

			for (IDirect3DBaseTexture9* Texture : SamplerTextures)
			{
				if (Texture) Texture->Release();
			}

			SumSurface->Release();
			CountResolveSurface->Release();
			BackDepthSurface->Release();
			if (FarSumSurface) FarSumSurface->Release();
			if (FarDepthSurface) FarDepthSurface->Release();
			bResult = true;
		}
	}

	if (SceneSurface) SceneSurface->Release();
	if (SecondSurface) SecondSurface->Release();
	if (DepthSurface) DepthSurface->Release();
	if (SceneTexture) SceneTexture->Release();
	if (FogShader) FogShader->Release();
	return bResult;
}

static void __fastcall FogDraw_Hook(void* RHI, int, UINT PrimitiveType, UINT MinVertexIndex, UINT NumVertices, UINT NumPrimitives, const void* IndexData, UINT IndexDataStride, const void* VertexData, UINT VertexDataStride)
{
	const FogDrawArgs Args = { RHI, PrimitiveType, MinVertexIndex, NumVertices, NumPrimitives, IndexData, IndexDataStride, VertexData, VertexDataStride };

	// DrawIndexedPrimitiveUP at +0x1AC in the vtable
	DrawIndexedPrimitiveUP = (*reinterpret_cast<uintptr_t**>(RHI))[0x1AC / 4];

	// FD3D9DynamicRHI only, Direct3DDevice at +0x8, bDeviceLost at +0x20
	if (RHI != D3D9DynamicRHI || *reinterpret_cast<BOOL*>(reinterpret_cast<uintptr_t>(RHI) + 0x20) || !DrawSplitFog(*reinterpret_cast<IDirect3DDevice9**>(reinterpret_cast<uintptr_t>(RHI) + 0x8), Args))
	{
		DrawFogQuad(Args);
	}
}

static void OnUpdateD3DDevice(safetyhook::Context& ctx)
{
	D3D9DynamicRHI = reinterpret_cast<void*>(ctx.esi);

	ReleaseFogResources();
}

void ApplyFixMSAAFog()
{
	if (!FixMSAAFog) return;

	DWORD addr_FogDrawCall = GetAddress(Addr::FogDrawCall);

	// RenderFog: mov eax, [edx+1ACh] -> mov eax, offset FogDraw_Hook
	MemoryHelper::WriteMemory<uint8_t>(addr_FogDrawCall, 0xB8);
	MemoryHelper::WriteMemory<uintptr_t>(addr_FogDrawCall + 0x1, reinterpret_cast<uintptr_t>(&FogDraw_Hook));
	MemoryHelper::MakeNOP(addr_FogDrawCall + 0x5, 1);

	UpdateD3DDeviceHook = safetyhook::create_mid(GetAddress(Addr::UpdateD3DDevice), OnUpdateD3DDevice);
}
