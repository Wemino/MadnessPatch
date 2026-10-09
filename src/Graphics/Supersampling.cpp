#include "Common.hpp"
#include "Features.hpp"

#include <d3d9.h>

static safetyhook::InlineHook AllocateSceneTargets{};
static safetyhook::InlineHook AllocateSceneTargetsCommand{};
static safetyhook::MidHook UpdateD3DDeviceRHI{};

static void* D3D9DynamicRHI = nullptr;
static void* ViewTargetView = nullptr;
static uintptr_t SetSceneTargetsSize = 0;
static uintptr_t DrawDenormalizedQuad = 0;

static IDirect3DDevice9* SupersamplingDevice = nullptr;
static IDirect3DVertexShader9* DownsampleVS = nullptr;
static IDirect3DPixelShader9* DownsamplePS = nullptr;
static IDirect3DTexture9* FrameTexture = nullptr;
static bool bShadersFailed = false;
static bool bLinearDownsample = false;

static const DWORD TapParamsRegister = 221;

// vs_3_0
// dcl_position v0
// dcl_texcoord v1
// dcl_position o0
// dcl_texcoord o1
// mov o0, v0
// mov o1, v1
static const DWORD DownsampleVertexShader[] =
{
	0xFFFE0300, 0x0200001F, 0x80000000, 0x900F0000, 0x0200001F, 0x80000005, 0x900F0001, 0x0200001F,
	0x80000000, 0xE00F0000, 0x0200001F, 0x80000005, 0xE00F0001, 0x02000001, 0xE00F0000, 0x90E40000,
	0x02000001, 0xE00F0001, 0x90E40001, 0x0000FFFF
};

// ps_3_0
// def c220, 0, 0.5, 1, 0
// dcl_texcoord v0.xy
// dcl_2d s0
// mul r4.xy, v0.xy, c221.xy
// add r5.xy, r4.xy, -c222.xy
// add r6.xy, r4.xy, c222.xy
// frc r7.xy, r5.xy
// add r7.xy, r5.xy, -r7.xy
// mov r0, c220.x
// mov r1.zw, c220.x
// mov r8.y, r7.y
// rep i0
//     add r9.y, r8.y, c220.z
//     min r9.y, r9.y, r6.y
//     max r9.w, r8.y, r5.y
//     add_sat r9.y, r9.y, -r9.w
//     mov r8.x, r7.x
//     rep i0
//         add r9.x, r8.x, c220.z
//         min r9.x, r9.x, r6.x
//         max r9.z, r8.x, r5.x
//         add_sat r9.x, r9.x, -r9.z
//         mul r9.x, r9.x, r9.y
//         add r1.xy, r8.xy, c220.y
//         mul r1.xy, r1.xy, c221.zw
//         texldl r3, r1, s0
//         mad r0, r3, r9.x, r0
//         add r8.x, r8.x, c220.z
//     endrep
//     add r8.y, r8.y, c220.z
// endrep
// mul oC0, r0, c222.z
static const DWORD DownsamplePixelShader[] =
{
	0xFFFF0300, 0x0200001F, 0x80000005, 0x90030000, 0x05000051, 0xA00F00DC, 0x00000000, 0x3F000000,
	0x3F800000, 0x00000000, 0x0200001F, 0x90000000, 0xA00F0800, 0x03000005, 0x80030004, 0x90540000,
	0xA05400DD, 0x03000002, 0x80030005, 0x80540004, 0xA15400DE, 0x03000002, 0x80030006, 0x80540004,
	0xA05400DE, 0x02000013, 0x80030007, 0x80540005, 0x03000002, 0x80030007, 0x80540005, 0x81540007,
	0x02000001, 0x800F0000, 0xA00000DC, 0x02000001, 0x800C0001, 0xA00000DC, 0x02000001, 0x80020008,
	0x80550007, 0x01000026, 0xF0E40000, 0x03000002, 0x80020009, 0x80550008, 0xA0AA00DC, 0x0300000A,
	0x80020009, 0x80550009, 0x80550006, 0x0300000B, 0x80080009, 0x80550008, 0x80550005, 0x03000002,
	0x80120009, 0x80550009, 0x81FF0009, 0x02000001, 0x80010008, 0x80000007, 0x01000026, 0xF0E40000,
	0x03000002, 0x80010009, 0x80000008, 0xA0AA00DC, 0x0300000A, 0x80010009, 0x80000009, 0x80000006,
	0x0300000B, 0x80040009, 0x80000008, 0x80000005, 0x03000002, 0x80110009, 0x80000009, 0x81AA0009,
	0x03000005, 0x80010009, 0x80000009, 0x80550009, 0x03000002, 0x80030001, 0x80540008, 0xA05500DC,
	0x03000005, 0x80030001, 0x80540001, 0xA0FE00DD, 0x0300005F, 0x800F0003, 0x80E40001, 0xA0E40800,
	0x04000004, 0x800F0000, 0x80E40003, 0x80000009, 0x80E40000, 0x03000002, 0x80010008, 0x80000008,
	0xA0AA00DC, 0x00000027, 0x03000002, 0x80020008, 0x80550008, 0xA0AA00DC, 0x00000027, 0x03000005,
	0x800F0800, 0x80E40000, 0xA0AA00DE, 0x0000FFFF
};

static UINT ToRenderSize(UINT DisplaySize)
{
	return static_cast<UINT>(std::lround(DisplaySize * SSAAScale));
}

static void ReleaseSupersamplingResources()
{
	if (DownsampleVS) DownsampleVS->Release();
	if (DownsamplePS) DownsamplePS->Release();
	if (FrameTexture) FrameTexture->Release();

	DownsampleVS = nullptr;
	DownsamplePS = nullptr;
	FrameTexture = nullptr;
	SupersamplingDevice = nullptr;
}

static bool CreateSupersamplingResources(IDirect3DDevice9* Device, UINT Width, UINT Height, D3DFORMAT Format)
{
	if (SupersamplingDevice != Device)
	{
		ReleaseSupersamplingResources();
		SupersamplingDevice = Device;

		// Average in linear space when the back buffer format can be read and written as sRGB
		IDirect3D9* D3D = nullptr;
		D3DDEVICE_CREATION_PARAMETERS Params;
		bLinearDownsample = false;

		if (SUCCEEDED(Device->GetDirect3D(&D3D)) && SUCCEEDED(Device->GetCreationParameters(&Params)))
		{
			D3DDISPLAYMODE Mode;
			D3D->GetAdapterDisplayMode(Params.AdapterOrdinal, &Mode);
			bLinearDownsample = SUCCEEDED(D3D->CheckDeviceFormat(Params.AdapterOrdinal, Params.DeviceType, Mode.Format, D3DUSAGE_RENDERTARGET | D3DUSAGE_QUERY_SRGBREAD | D3DUSAGE_QUERY_SRGBWRITE, D3DRTYPE_TEXTURE, Format));
		}

		if (D3D) D3D->Release();
	}

	if (!DownsampleVS || !DownsamplePS)
	{
		if (bShadersFailed)
			return false;

		if (FAILED(Device->CreateVertexShader(DownsampleVertexShader, &DownsampleVS)) || FAILED(Device->CreatePixelShader(DownsamplePixelShader, &DownsamplePS)))
		{
			bShadersFailed = true;
			ReleaseSupersamplingResources();
			return false;
		}
	}

	// The frame at the render resolution, same format as the back buffer
	if (FrameTexture)
	{
		D3DSURFACE_DESC Desc;
		FrameTexture->GetLevelDesc(0, &Desc);

		if (Desc.Width != Width || Desc.Height != Height || Desc.Format != Format)
		{
			FrameTexture->Release();
			FrameTexture = nullptr;
		}
	}

	if (!FrameTexture && FAILED(Device->CreateTexture(Width, Height, 1, D3DUSAGE_RENDERTARGET, Format, D3DPOOL_DEFAULT, &FrameTexture, nullptr)))
	{
		FrameTexture = nullptr;
		return false;
	}

	return true;
}

static void DrawEngineQuad(float X, float Y, float SizeX, float SizeY, float U, float V, float SizeU, float SizeV, UINT TargetSizeX, UINT TargetSizeY, UINT TextureSizeX, UINT TextureSizeY, float ClipSpaceQuadZ)
{
	reinterpret_cast<void(__cdecl*)(float, float, float, float, float, float, float, float, UINT, UINT, UINT, UINT, float)>(DrawDenormalizedQuad)(X, Y, SizeX, SizeY, U, V, SizeU, SizeV, TargetSizeX, TargetSizeY, TextureSizeX, TextureSizeY, ClipSpaceQuadZ);
}

static const D3DRENDERSTATETYPE SavedRenderStates[] =
{
	D3DRS_ZENABLE, D3DRS_ZWRITEENABLE, D3DRS_STENCILENABLE, D3DRS_ALPHABLENDENABLE, D3DRS_ALPHATESTENABLE, D3DRS_SCISSORTESTENABLE,
	D3DRS_CLIPPLANEENABLE, D3DRS_CULLMODE, D3DRS_FILLMODE, D3DRS_COLORWRITEENABLE, D3DRS_SRGBWRITEENABLE
};

static const D3DSAMPLERSTATETYPE SavedSamplerStates[] =
{
	D3DSAMP_MINFILTER, D3DSAMP_MAGFILTER, D3DSAMP_MIPFILTER, D3DSAMP_ADDRESSU, D3DSAMP_ADDRESSV, D3DSAMP_SRGBTEXTURE
};

static bool DrawDownsampledQuad(IDirect3DDevice9* Device, float X, float Y, float SizeX, float SizeY, float U, float V, float SizeU, float SizeV, UINT TargetSizeX, UINT TargetSizeY, UINT TextureSizeX, UINT TextureSizeY, float ClipSpaceQuadZ)
{
	IDirect3DSurface9* TargetSurface = nullptr;
	IDirect3DSurface9* BackBuffer = nullptr;
	IDirect3DSurface9* DepthSurface = nullptr;
	bool bResult = false;

	Device->GetRenderTarget(0, &TargetSurface);
	Device->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &BackBuffer);
	Device->GetDepthStencilSurface(&DepthSurface);

	// Only the frame going to the screen, render to texture targets keep the engine's copy
	D3DSURFACE_DESC TargetDesc;
	if (TargetSurface && TargetSurface == BackBuffer && SizeU > SizeX && SizeV > SizeY && SUCCEEDED(TargetSurface->GetDesc(&TargetDesc)) && CreateSupersamplingResources(Device, TextureSizeX, TextureSizeY, TargetDesc.Format))
	{
		IDirect3DSurface9* FrameSurface = nullptr;
		FrameTexture->GetSurfaceLevel(0, &FrameSurface);

		D3DVIEWPORT9 Viewport;
		Device->GetViewport(&Viewport);

		// The engine's copy (gamma, color scale, overlay) one to one at the render resolution
		const D3DVIEWPORT9 FrameViewport = { 0, 0, TextureSizeX, TextureSizeY, 0.0f, 1.0f };
		Device->SetRenderTarget(0, FrameSurface);
		Device->SetDepthStencilSurface(nullptr);
		Device->SetViewport(&FrameViewport);
		DrawEngineQuad(U, V, SizeU, SizeV, U, V, SizeU, SizeV, TextureSizeX, TextureSizeY, TextureSizeX, TextureSizeY, ClipSpaceQuadZ);

		Device->SetRenderTarget(0, TargetSurface);
		Device->SetDepthStencilSurface(DepthSurface);
		Device->SetViewport(&Viewport);
		FrameSurface->Release();

		DWORD RenderStates[std::size(SavedRenderStates)];
		DWORD SamplerStates[std::size(SavedSamplerStates)];
		IDirect3DVertexShader9* VertexShader = nullptr;
		IDirect3DPixelShader9* PixelShader = nullptr;
		IDirect3DVertexDeclaration9* VertexDeclaration = nullptr;
		IDirect3DBaseTexture9* Texture = nullptr;
		IDirect3DVertexBuffer9* StreamData = nullptr;
		UINT StreamOffset = 0, StreamStride = 0;
		DWORD FVF = 0;
		float SavedParams[2][4];
		int SavedTapCount[4];

		for (size_t i = 0; i < std::size(SavedRenderStates); i++) Device->GetRenderState(SavedRenderStates[i], &RenderStates[i]);
		for (size_t i = 0; i < std::size(SavedSamplerStates); i++) Device->GetSamplerState(0, SavedSamplerStates[i], &SamplerStates[i]);
		Device->GetVertexShader(&VertexShader);
		Device->GetPixelShader(&PixelShader);
		Device->GetVertexDeclaration(&VertexDeclaration);
		Device->GetFVF(&FVF);
		Device->GetTexture(0, &Texture);
		Device->GetStreamSource(0, &StreamData, &StreamOffset, &StreamStride);
		Device->GetPixelShaderConstantF(TapParamsRegister, SavedParams[0], 2);
		Device->GetPixelShaderConstantI(0, SavedTapCount, 1);

		// Average the render pixels covered by each display pixel
		const float FootprintX = SizeU / SizeX;
		const float FootprintY = SizeV / SizeY;
		const int TapCount = std::min(static_cast<int>(std::ceil(std::max(FootprintX, FootprintY))) + 1, 9);
		const float TapParams[2][4] =
		{
			{ static_cast<float>(TextureSizeX), static_cast<float>(TextureSizeY), 1.0f / TextureSizeX, 1.0f / TextureSizeY },
			{ FootprintX * 0.5f, FootprintY * 0.5f, 1.0f / (FootprintX * FootprintY), 0.0f }
		};
		const int TapCountParams[4] = { TapCount, 0, 0, 0 };

		// Offset the quad by half a pixel so that pixels line up with texels
		const float Left = X / TargetSizeX * 2.0f - 1.0f - 1.0f / TargetSizeX;
		const float Right = (X + SizeX) / TargetSizeX * 2.0f - 1.0f - 1.0f / TargetSizeX;
		const float Top = 1.0f - Y / TargetSizeY * 2.0f + 1.0f / TargetSizeY;
		const float Bottom = 1.0f - (Y + SizeY) / TargetSizeY * 2.0f + 1.0f / TargetSizeY;
		const float MinU = U / TextureSizeX, MaxU = (U + SizeU) / TextureSizeX;
		const float MinV = V / TextureSizeY, MaxV = (V + SizeV) / TextureSizeY;

		const float Quad[4][5] =
		{
			{ Left,  Top,    0.5f, MinU, MinV },
			{ Right, Top,    0.5f, MaxU, MinV },
			{ Left,  Bottom, 0.5f, MinU, MaxV },
			{ Right, Bottom, 0.5f, MaxU, MaxV }
		};

		Device->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
		Device->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);
		Device->SetRenderState(D3DRS_STENCILENABLE, FALSE);
		Device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
		Device->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
		Device->SetRenderState(D3DRS_SCISSORTESTENABLE, FALSE);
		Device->SetRenderState(D3DRS_CLIPPLANEENABLE, 0);
		Device->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
		Device->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
		Device->SetRenderState(D3DRS_COLORWRITEENABLE, 0xF);
		Device->SetRenderState(D3DRS_SRGBWRITEENABLE, bLinearDownsample);

		Device->SetTexture(0, FrameTexture);
		Device->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_POINT);
		Device->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_POINT);
		Device->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_NONE);
		Device->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_CLAMP);
		Device->SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_CLAMP);
		Device->SetSamplerState(0, D3DSAMP_SRGBTEXTURE, bLinearDownsample);

		Device->SetPixelShaderConstantF(TapParamsRegister, TapParams[0], 2);
		Device->SetPixelShaderConstantI(0, TapCountParams, 1);
		Device->SetVertexShader(DownsampleVS);
		Device->SetPixelShader(DownsamplePS);
		Device->SetFVF(D3DFVF_XYZ | D3DFVF_TEX1);
		Device->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, Quad, sizeof(Quad[0]));

		// Every state back to what it was, sRGB included
		for (size_t i = 0; i < std::size(SavedRenderStates); i++) Device->SetRenderState(SavedRenderStates[i], RenderStates[i]);
		for (size_t i = 0; i < std::size(SavedSamplerStates); i++) Device->SetSamplerState(0, SavedSamplerStates[i], SamplerStates[i]);
		Device->SetPixelShaderConstantF(TapParamsRegister, SavedParams[0], 2);
		Device->SetPixelShaderConstantI(0, SavedTapCount, 1);
		Device->SetVertexShader(VertexShader);
		Device->SetPixelShader(PixelShader);
		if (VertexDeclaration) Device->SetVertexDeclaration(VertexDeclaration);
		else Device->SetFVF(FVF);
		Device->SetTexture(0, Texture);
		Device->SetStreamSource(0, StreamData, StreamOffset, StreamStride);

		if (VertexShader) VertexShader->Release();
		if (PixelShader) PixelShader->Release();
		if (VertexDeclaration) VertexDeclaration->Release();
		if (Texture) Texture->Release();
		if (StreamData) StreamData->Release();
		bResult = true;
	}

	if (TargetSurface) TargetSurface->Release();
	if (BackBuffer) BackBuffer->Release();
	if (DepthSurface) DepthSurface->Release();
	return bResult;
}

static void ConstrainViewTarget(IDirect3DDevice9* Device, float& X, float& Y, float& SizeX, float& SizeY)
{
	UAliceGameEngine* Engine = g_State.AliceEngine;
	if (!ViewTargetView || !Engine || !Engine->bConstrainAspectRatio || Engine->ConstrainedAspectRatio <= 0.0f) return;

	const uintptr_t Family = *reinterpret_cast<uintptr_t*>(ViewTargetView);
	const UINT Width = static_cast<UINT>(SizeX);
	const UINT Height = static_cast<UINT>(SizeY);
	const float AspectRatio = *reinterpret_cast<BOOL*>(Family + 0x44) ? *reinterpret_cast<float*>(Family + 0x48) : static_cast<float>(Width) / Height;
	const float Ratio = AspectRatio / Engine->ConstrainedAspectRatio;

	if (std::fabs(1.0f - Ratio) <= 0.0001f) return;

	const D3DRECT ViewRect = { std::lround(X), std::lround(Y), std::lround(X) + static_cast<LONG>(Width), std::lround(Y) + static_cast<LONG>(Height) };
	Device->Clear(1, &ViewRect, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

	if (Ratio < 1.0f)
	{
		// Letterbox
		const float ConstrainedSizeY = Height * Ratio;
		Y += (Height - ConstrainedSizeY) * 0.5f;
		SizeY = ConstrainedSizeY;
	}
	else
	{
		// Pillarbox
		const float ConstrainedSizeX = Width * (1.0f / Ratio);
		X += (Width - ConstrainedSizeX) * 0.5f;
		SizeX = ConstrainedSizeX;
	}
}

static void __cdecl ViewTargetQuad_Hook(float X, float Y, float SizeX, float SizeY, float U, float V, float SizeU, float SizeV, UINT TargetSizeX, UINT TargetSizeY, UINT TextureSizeX, UINT TextureSizeY, float ClipSpaceQuadZ)
{
	IDirect3DDevice9* Device = D3D9DynamicRHI ? *reinterpret_cast<IDirect3DDevice9**>(reinterpret_cast<uintptr_t>(D3D9DynamicRHI) + 0x8) : nullptr;
	const bool bDeviceLost = D3D9DynamicRHI && *reinterpret_cast<BOOL*>(reinterpret_cast<uintptr_t>(D3D9DynamicRHI) + 0x20);

	if (Device)
		ConstrainViewTarget(Device, X, Y, SizeX, SizeY);

	if (!Device || bDeviceLost || !DrawDownsampledQuad(Device, X, Y, SizeX, SizeY, U, V, SizeU, SizeV, TargetSizeX, TargetSizeY, TextureSizeX, TextureSizeY, ClipSpaceQuadZ))
	{
		DrawEngineQuad(X, Y, SizeX, SizeY, U, V, SizeU, SizeV, TargetSizeX, TargetSizeY, TextureSizeX, TextureSizeY, ClipSpaceQuadZ);
	}
}

__declspec(naked) static void ViewTargetQuad_Stub()
{
	__asm
	{
		mov dword ptr[ViewTargetView], esi
		jmp ViewTargetQuad_Hook
	}
}

// FSystemSettings::ScaleScreenCoords, the views render at the supersampled resolution
static void __fastcall ScaleScreenCoords_Hook(void* SystemSettings, int, int* X, int* Y, UINT* SizeX, UINT* SizeY)
{
	*X = std::lround(*X * SSAAScale);
	*Y = std::lround(*Y * SSAAScale);
	*SizeX = ToRenderSize(*SizeX);
	*SizeY = ToRenderSize(*SizeY);
}

// FSystemSettings::UnScaleScreenCoords, where the view lands on the back buffer
static void __fastcall UnScaleScreenCoords_Hook(void* SystemSettings, int, int* OutX, int* OutY, UINT* OutSizeX, UINT* OutSizeY, float InX, float InY, float InSizeX, float InSizeY)
{
	*OutX = std::lround(InX / SSAAScale);
	*OutY = std::lround(InY / SSAAScale);
	*OutSizeX = static_cast<UINT>(std::lround(InSizeX / SSAAScale));
	*OutSizeY = static_cast<UINT>(std::lround(InSizeY / SSAAScale));
}

// FSystemSettings::NeedsUpscale, post processing then leaves the copy to the back buffer to FinishRenderViewTarget
static BOOL __fastcall NeedsUpscale_Hook(void* SystemSettings, int)
{
	return TRUE;
}

// FSceneRenderTargets::Allocate, requested with the view size
static void __fastcall AllocateSceneTargets_Hook(void* SceneRenderTargets, int, UINT MinSizeX, UINT MinSizeY)
{
	AllocateSceneTargets.thiscall<void>(SceneRenderTargets, ToRenderSize(MinSizeX), ToRenderSize(MinSizeY));
}

// FSceneRenderTargetProxy::SetSizes, scene color as a render target sized like the viewport (allocated or enqueued)
static UINT __fastcall AllocateSceneTargetsCommand_Hook(void* Command, int, UINT MinSizeX, UINT MinSizeY)
{
	return AllocateSceneTargetsCommand.thiscall<UINT>(Command, ToRenderSize(MinSizeX), ToRenderSize(MinSizeY));
}

// UpdateD3DDeviceFromViewports: the scene render targets follow the viewport before the device reset
static void __fastcall ResetSceneTargets_Hook(void* SceneRenderTargets, int, UINT SizeX, UINT SizeY)
{
	reinterpret_cast<void(__thiscall*)(void*, UINT, UINT)>(SetSceneTargetsSize)(SceneRenderTargets, ToRenderSize(SizeX), ToRenderSize(SizeY));
}

static void OnUpdateD3DDeviceRHI(safetyhook::Context& ctx)
{
	D3D9DynamicRHI = reinterpret_cast<void*>(ctx.esi);

	ReleaseSupersamplingResources();
}

void ApplySupersampling()
{
	if (SSAAScale <= 1.0f) return;

	MemoryHelper::MakeJMP(GetAddress(Addr::ScaleScreenCoords), reinterpret_cast<uintptr_t>(&ScaleScreenCoords_Hook));
	MemoryHelper::MakeJMP(GetAddress(Addr::UnScaleScreenCoords), reinterpret_cast<uintptr_t>(&UnScaleScreenCoords_Hook));
	MemoryHelper::MakeJMP(GetAddress(Addr::NeedsUpscale), reinterpret_cast<uintptr_t>(&NeedsUpscale_Hook));

	// RenderTargetSizeX/Y = Min(View size, viewport size): jg -> NOP, the view size is always taken
	DWORD addr_ViewRectClamp = GetAddress(Addr::ViewRectClamp);
	MemoryHelper::MakeNOP(addr_ViewRectClamp, 2);
	MemoryHelper::MakeNOP(addr_ViewRectClamp + 0x29, 2);

	AllocateSceneTargets = HookHelper::CreateHook((void*)GetAddress(Addr::AllocateSceneTargets), &AllocateSceneTargets_Hook);
	AllocateSceneTargetsCommand = HookHelper::CreateHook((void*)GetAddress(Addr::AllocateSceneTargetsCommand), &AllocateSceneTargetsCommand_Hook);

	DWORD addr_ResetSceneTargets = GetAddress(Addr::ResetSceneTargets);
	SetSceneTargetsSize = addr_ResetSceneTargets + 0x5 + *reinterpret_cast<int32_t*>(addr_ResetSceneTargets + 0x1);
	MemoryHelper::MakeCALL(addr_ResetSceneTargets, reinterpret_cast<uintptr_t>(&ResetSceneTargets_Hook));

	DWORD addr_ViewTargetQuad = GetAddress(Addr::ViewTargetQuad);
	DrawDenormalizedQuad = addr_ViewTargetQuad + 0x5 + *reinterpret_cast<int32_t*>(addr_ViewTargetQuad + 0x1);
	MemoryHelper::MakeCALL(addr_ViewTargetQuad, reinterpret_cast<uintptr_t>(&ViewTargetQuad_Stub));

	UpdateD3DDeviceRHI = safetyhook::create_mid(GetAddress(Addr::UpdateD3DDeviceRHI), OnUpdateD3DDeviceRHI);
}
