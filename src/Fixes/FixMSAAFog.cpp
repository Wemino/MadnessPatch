#include "Common.hpp"
#include "Features.hpp"

#include <d3d9.h>

static safetyhook::MidHook UpdateD3DDeviceHook{};

static void* D3D9DynamicRHI = nullptr;
static uintptr_t DrawIndexedPrimitiveUP = 0;

static IDirect3DDevice9* FogDevice = nullptr;
static IDirect3DPixelShader9* SplitAveragePS = nullptr;
static IDirect3DPixelShader9* SplitBehindPS = nullptr;
static IDirect3DPixelShader9* SplitBehindSidePS = nullptr;
static IDirect3DPixelShader9* SplitFrontSidePS = nullptr;
static IDirect3DPixelShader9* GroupDepthPS = nullptr;
static IDirect3DPixelShader9* ConstantPS = nullptr;
static IDirect3DSurface9* CountSurface = nullptr;
static IDirect3DTexture9* SplitTexture = nullptr;
static IDirect3DTexture9* FirstResolveTexture = nullptr;
static IDirect3DTexture9* SecondResolveTexture = nullptr;
static IDirect3DTexture9* ThirdResolveTexture = nullptr;
static IDirect3DTexture9* CountTexture = nullptr;
static IDirect3DTexture9* FrontDepthTexture = nullptr;
static IDirect3DTexture9* FrontBackDepthTexture = nullptr;
static IDirect3DTexture9* BehindFrontDepthTexture = nullptr;
static IDirect3DTexture9* BehindDepthTexture = nullptr;
static bool bShadersFailed = false;
static bool bResolveFailed = false;

static const DWORD ParamsRegister = 223;
static const DWORD ThirdResolveSampler = 10;
static const DWORD SplitSampler = 11;
static const DWORD CountSampler = 12;
static const DWORD SecondResolveSampler = 13;
static const DWORD FirstResolveSampler = 14;
static const DWORD SceneSampler = 15;

static const DWORD SplitStencilMask = 0xE0;
static const DWORD ScaledStencilBit = 0x80;
static const DWORD BehindStencil = 0xA0;
static const DWORD FrontStencil = 0x40;
static const DWORD BehindFrontStencil = 0x60;
static const DWORD FrontBackStencil = 0xE0;

// ps_3_0
// def c220, 0, 0.9990234375, 1, 0.0078125
// def c222, -1, 0, 1, 0
// dcl_texcoord0 v0.xy
// dcl_2d s15
// mov r13.xy, c223.xy
// mov r0.xy, v0.xy
// mov r0.zw, c220.x
// texldl r1, r0, s15
// mov r4.x, r1.w
// mov r2.x, r1.w
// mov r2.y, r1.w
// mad r0.xy, c222.xx, r13.xy, v0.xy / texldl r1, r0, s15 / min r2.x, r2.x, r1.w / max r2.y, r2.y, r1.w
// mad r0.xy, c222.yx, r13.xy, v0.xy / texldl r1, r0, s15 / min r2.x, r2.x, r1.w / max r2.y, r2.y, r1.w
// mad r0.xy, c222.zx, r13.xy, v0.xy / texldl r1, r0, s15 / min r2.x, r2.x, r1.w / max r2.y, r2.y, r1.w
// mad r0.xy, c222.xy, r13.xy, v0.xy / texldl r1, r0, s15 / min r2.x, r2.x, r1.w / max r2.y, r2.y, r1.w
// mad r0.xy, c222.zy, r13.xy, v0.xy / texldl r1, r0, s15 / min r2.x, r2.x, r1.w / max r2.y, r2.y, r1.w
// mad r0.xy, c222.xz, r13.xy, v0.xy / texldl r1, r0, s15 / min r2.x, r2.x, r1.w / max r2.y, r2.y, r1.w
// mad r0.xy, c222.yz, r13.xy, v0.xy / texldl r1, r0, s15 / min r2.x, r2.x, r1.w / max r2.y, r2.y, r1.w
// mad r0.xy, c222.zz, r13.xy, v0.xy / texldl r1, r0, s15 / min r2.x, r2.x, r1.w / max r2.y, r2.y, r1.w
// add r3.x, r2.y, -r2.x
// mad r3.x, r2.y, -c220.w, r3.x
// mul r4.y, r4.x, c220.y
// cmp r5, -r3.x, c220.x, r4.y
// mov oC0, r5
static const DWORD SplitAverageShader[] =
{
	0xFFFF0300, 0x0200001F, 0x80000005, 0x90030000, 0x05000051, 0xA00F00DC, 0x00000000, 0x3F7FC000,
	0x3F800000, 0x3C000000, 0x05000051, 0xA00F00DE, 0xBF800000, 0x00000000, 0x3F800000, 0x00000000,
	0x0200001F, 0x90000000, 0xA00F080F, 0x02000001, 0x8003000D, 0xA05400DF, 0x02000001, 0x80030000,
	0x90540000, 0x02000001, 0x800C0000, 0xA00000DC, 0x0300005F, 0x800F0001, 0x80E40000, 0xA0E4080F,
	0x02000001, 0x80010004, 0x80FF0001, 0x02000001, 0x80010002, 0x80FF0001, 0x02000001, 0x80020002,
	0x80FF0001, 0x04000004, 0x80030000, 0xA00000DE, 0x8054000D, 0x90540000, 0x0300005F, 0x800F0001,
	0x80E40000, 0xA0E4080F, 0x0300000A, 0x80010002, 0x80000002, 0x80FF0001, 0x0300000B, 0x80020002,
	0x80550002, 0x80FF0001, 0x04000004, 0x80030000, 0xA00100DE, 0x8054000D, 0x90540000, 0x0300005F,
	0x800F0001, 0x80E40000, 0xA0E4080F, 0x0300000A, 0x80010002, 0x80000002, 0x80FF0001, 0x0300000B,
	0x80020002, 0x80550002, 0x80FF0001, 0x04000004, 0x80030000, 0xA00200DE, 0x8054000D, 0x90540000,
	0x0300005F, 0x800F0001, 0x80E40000, 0xA0E4080F, 0x0300000A, 0x80010002, 0x80000002, 0x80FF0001,
	0x0300000B, 0x80020002, 0x80550002, 0x80FF0001, 0x04000004, 0x80030000, 0xA05400DE, 0x8054000D,
	0x90540000, 0x0300005F, 0x800F0001, 0x80E40000, 0xA0E4080F, 0x0300000A, 0x80010002, 0x80000002,
	0x80FF0001, 0x0300000B, 0x80020002, 0x80550002, 0x80FF0001, 0x04000004, 0x80030000, 0xA05600DE,
	0x8054000D, 0x90540000, 0x0300005F, 0x800F0001, 0x80E40000, 0xA0E4080F, 0x0300000A, 0x80010002,
	0x80000002, 0x80FF0001, 0x0300000B, 0x80020002, 0x80550002, 0x80FF0001, 0x04000004, 0x80030000,
	0xA0A800DE, 0x8054000D, 0x90540000, 0x0300005F, 0x800F0001, 0x80E40000, 0xA0E4080F, 0x0300000A,
	0x80010002, 0x80000002, 0x80FF0001, 0x0300000B, 0x80020002, 0x80550002, 0x80FF0001, 0x04000004,
	0x80030000, 0xA0A900DE, 0x8054000D, 0x90540000, 0x0300005F, 0x800F0001, 0x80E40000, 0xA0E4080F,
	0x0300000A, 0x80010002, 0x80000002, 0x80FF0001, 0x0300000B, 0x80020002, 0x80550002, 0x80FF0001,
	0x04000004, 0x80030000, 0xA0AA00DE, 0x8054000D, 0x90540000, 0x0300005F, 0x800F0001, 0x80E40000,
	0xA0E4080F, 0x0300000A, 0x80010002, 0x80000002, 0x80FF0001, 0x0300000B, 0x80020002, 0x80550002,
	0x80FF0001, 0x03000002, 0x80010003, 0x80550002, 0x81000002, 0x04000004, 0x80010003, 0x80550002,
	0xA1FF00DC, 0x80000003, 0x03000005, 0x80020004, 0x80000004, 0xA05500DC, 0x04000058, 0x800F0005,
	0x81000003, 0xA00000DC, 0x80550004, 0x02000001, 0x800F0800, 0x80E40005, 0x0000FFFF
};

// ps_3_0
// def c220, 0, 255, 1, 0
// dcl_texcoord0 v0.xy
// dcl_2d s11
// mov r0.xy, v0.xy
// mov r0.zw, c220.x
// texldl r1, r0, s11
// add r2.x, -r1.x, c220.z
// mov oDepth, r2.x
// mov oC0, c220.xxxy
static const DWORD SplitBehindShader[] =
{
	0xFFFF0300, 0x0200001F, 0x80000005, 0x90030000, 0x05000051, 0xA00F00DC, 0x00000000, 0x437F0000,
	0x3F800000, 0x00000000, 0x0200001F, 0x90000000, 0xA00F080B, 0x02000001, 0x80030000, 0x90540000,
	0x02000001, 0x800C0000, 0xA00000DC, 0x0300005F, 0x800F0001, 0x80E40000, 0xA0E4080B, 0x03000002,
	0x80010002, 0x81000001, 0xA0AA00DC, 0x02000001, 0x900F0800, 0x80000002, 0x02000001, 0x800F0800,
	0xA04000DC, 0x0000FFFF
};

// ps_3_0
// def c220, 0, 0.00390625, 1, -0.00000001
// def c221, 1.0009765625, 0.5, 1.5, 2
// dcl_texcoord0 v0.xy
// dcl_2d s11
// dcl_2d s12
// dcl_2d s14
// dcl_2d s15
// mov r0.xy, v0.xy
// mov r0.zw, c220.x
// texldl r1, r0, s11
// mov r10, c221.w
// if_gt r1.x, c220.x
//     texldl r2, r0, s15
//     texldl r3, r0, s14
//     texldl r5, r0, s12
//     add r6.x, r3.w, -r2.w
//     mul r6.x, r6.x, c223.y
//     mul r7.x, r5.x, c223.x
//     add r7.x, r7.x, c221.y
//     frc r8.x, r7.x
//     add r7.x, r7.x, -r8.x
//     max r9.x, r7.x, c220.z
//     rcp r9.x, r9.x
//     mul r10.x, r6.x, r9.x
//     mul r10.x, r10.x, c221.x
//     add r8.x, r7.x, -c221.z
//     cmp r10.x, r8.x, r10.x, c221.w
// endif
// add r11.x, r1.x, c220.w
// mov r11, r11.x
// texkill r11
// add r4.x, -r10.x, c220.z
// mov oDepth, r4.x
// mov oC0, c220.xxxy
static const DWORD SplitBehindSideShader[] =
{
	0xFFFF0300, 0x0200001F, 0x80000005, 0x90030000, 0x05000051, 0xA00F00DC, 0x00000000, 0x3B800000,
	0x3F800000, 0xB22BCC77, 0x05000051, 0xA00F00DD, 0x3F802000, 0x3F000000, 0x3FC00000, 0x40000000,
	0x0200001F, 0x90000000, 0xA00F080B, 0x0200001F, 0x90000000, 0xA00F080C, 0x0200001F, 0x90000000,
	0xA00F080E, 0x0200001F, 0x90000000, 0xA00F080F, 0x02000001, 0x80030000, 0x90540000, 0x02000001,
	0x800C0000, 0xA00000DC, 0x0300005F, 0x800F0001, 0x80E40000, 0xA0E4080B, 0x02000001, 0x800F000A,
	0xA0FF00DD, 0x02010029, 0x80000001, 0xA00000DC, 0x0300005F, 0x800F0002, 0x80E40000, 0xA0E4080F,
	0x0300005F, 0x800F0003, 0x80E40000, 0xA0E4080E, 0x0300005F, 0x800F0005, 0x80E40000, 0xA0E4080C,
	0x03000002, 0x80010006, 0x80FF0003, 0x81FF0002, 0x03000005, 0x80010006, 0x80000006, 0xA05500DF,
	0x03000005, 0x80010007, 0x80000005, 0xA00000DF, 0x03000002, 0x80010007, 0x80000007, 0xA05500DD,
	0x02000013, 0x80010008, 0x80000007, 0x03000002, 0x80010007, 0x80000007, 0x81000008, 0x0300000B,
	0x80010009, 0x80000007, 0xA0AA00DC, 0x02000006, 0x80010009, 0x80000009, 0x03000005, 0x8001000A,
	0x80000006, 0x80000009, 0x03000005, 0x8001000A, 0x8000000A, 0xA00000DD, 0x03000002, 0x80010008,
	0x80000007, 0xA1AA00DD, 0x04000058, 0x8001000A, 0x80000008, 0x8000000A, 0xA0FF00DD, 0x0000002B,
	0x03000002, 0x8001000B, 0x80000001, 0xA0FF00DC, 0x02000001, 0x800F000B, 0x8000000B, 0x01000041,
	0x800F000B, 0x03000002, 0x80010004, 0x8100000A, 0xA0AA00DC, 0x02000001, 0x900F0800, 0x80000004,
	0x02000001, 0x800F0800, 0xA04000DC, 0x0000FFFF
};

// ps_3_0
// def c220, 0, 255, 1, -0.00000001
// def c221, 0.9990234375, 0.5, 1.5, 0
// dcl_texcoord0 v0.xy
// dcl_2d s11
// dcl_2d s12
// dcl_2d s14
// dcl_2d s15
// mov r0.xy, v0.xy
// mov r0.zw, c220.x
// texldl r1, r0, s11
// mov r10, c220.x
// if_gt r1.x, c220.x
//     texldl r2, r0, s15
//     texldl r3, r0, s14
//     texldl r5, r0, s12
//     add r6.y, r3.w, -r2.w
//     mul r6.y, r6.y, c223.y
//     mad r6.x, r2.w, c223.x, -r6.y
//     mul r7.y, r5.x, c223.x
//     add r7.y, r7.y, c221.y
//     frc r8.y, r7.y
//     add r7.y, r7.y, -r8.y
//     add r7.x, c223.x, -r7.y
//     max r9.x, r7.x, c220.z
//     rcp r9.x, r9.x
//     mul r10.x, r6.x, r9.x
//     mul r10.x, r10.x, c221.x
//     add r8.x, r7.x, -c221.z
//     cmp r10.x, r8.x, r10.x, c221.w
// endif
// add r11.x, r1.x, c220.w
// mov r11, r11.x
// texkill r11
// add r4.x, -r10.x, c220.z
// mov oDepth, r4.x
// mov oC0, c220.xxxy
static const DWORD SplitFrontSideShader[] =
{
	0xFFFF0300, 0x0200001F, 0x80000005, 0x90030000, 0x05000051, 0xA00F00DC, 0x00000000, 0x437F0000,
	0x3F800000, 0xB22BCC77, 0x05000051, 0xA00F00DD, 0x3F7FC000, 0x3F000000, 0x3FC00000, 0x00000000,
	0x0200001F, 0x90000000, 0xA00F080B, 0x0200001F, 0x90000000, 0xA00F080C, 0x0200001F, 0x90000000,
	0xA00F080E, 0x0200001F, 0x90000000, 0xA00F080F, 0x02000001, 0x80030000, 0x90540000, 0x02000001,
	0x800C0000, 0xA00000DC, 0x0300005F, 0x800F0001, 0x80E40000, 0xA0E4080B, 0x02000001, 0x800F000A,
	0xA00000DC, 0x02010029, 0x80000001, 0xA00000DC, 0x0300005F, 0x800F0002, 0x80E40000, 0xA0E4080F,
	0x0300005F, 0x800F0003, 0x80E40000, 0xA0E4080E, 0x0300005F, 0x800F0005, 0x80E40000, 0xA0E4080C,
	0x03000002, 0x80020006, 0x80FF0003, 0x81FF0002, 0x03000005, 0x80020006, 0x80550006, 0xA05500DF,
	0x04000004, 0x80010006, 0x80FF0002, 0xA00000DF, 0x81550006, 0x03000005, 0x80020007, 0x80000005,
	0xA00000DF, 0x03000002, 0x80020007, 0x80550007, 0xA05500DD, 0x02000013, 0x80020008, 0x80550007,
	0x03000002, 0x80020007, 0x80550007, 0x81550008, 0x03000002, 0x80010007, 0xA00000DF, 0x81550007,
	0x0300000B, 0x80010009, 0x80000007, 0xA0AA00DC, 0x02000006, 0x80010009, 0x80000009, 0x03000005,
	0x8001000A, 0x80000006, 0x80000009, 0x03000005, 0x8001000A, 0x8000000A, 0xA00000DD, 0x03000002,
	0x80010008, 0x80000007, 0xA1AA00DD, 0x04000058, 0x8001000A, 0x80000008, 0x8000000A, 0xA0FF00DD,
	0x0000002B, 0x03000002, 0x8001000B, 0x80000001, 0xA0FF00DC, 0x02000001, 0x800F000B, 0x8000000B,
	0x01000041, 0x800F000B, 0x03000002, 0x80010004, 0x8100000A, 0xA0AA00DC, 0x02000001, 0x900F0800,
	0x80000004, 0x02000001, 0x800F0800, 0xA04000DC, 0x0000FFFF
};

// ps_3_0
// def c220, 0, 0.5, 1, -0.00000001
// dcl_texcoord0 v0.xy
// dcl_2d s10
// dcl_2d s11
// dcl_2d s12
// dcl_2d s13
// dcl_2d s14
// dcl_2d s15
// mov r0.xy, v0.xy
// mov r0.zw, c220.x
// texldl r1, r0, s11
// mov r10, c220.x
// if_gt r1.x, c220.x
//     texldl r2, r0, s15
//     texldl r3, r0, s14
//     texldl r4, r0, s13
//     texldl r5, r0, s10
//     texldl r6, r0, s12
//     add r7.y, r3.w, -r2.w
//     mul r7.y, r7.y, c223.y
//     mad r7.x, r2.w, c223.x, -r7.y
//     add r7.z, r5.w, -r4.w
//     mul r7.z, r7.z, c223.y
//     add r7.w, r3.w, -r4.w
//     mul r7.w, r7.w, c223.y
//     mul r8.xyz, r6.xyz, c223.x
//     add r8.xyz, r8.xyz, c220.y
//     frc r9.xyz, r8.xyz
//     add r8.xyz, r8.xyz, -r9.xyz
//     add r8.w, c223.x, -r8.x
//     add r11.x, r7.x, -r7.z
//     mov r11.y, r7.z
//     mov r11.z, r7.w
//     add r11.w, r7.y, -r7.w
//     add r12.x, r8.w, -r8.z
//     mov r12.y, r8.z
//     mov r12.z, r8.y
//     add r12.w, r8.x, -r8.y
//     max r12, r12, c220.z
//     rcp r13.x, r12.x
//     rcp r13.y, r12.y
//     rcp r13.z, r12.z
//     rcp r13.w, r12.w
//     mul r10, r11, r13
// endif
// add r11.x, r1.x, c220.w
// mov r11, r11.x
// texkill r11
// mov r12.xyz, c220.x
// mov r12.w, r10.x
// mov oC0, r12
// mov r12.w, r10.y
// mov oC1, r12
// mov r12.w, r10.z
// mov oC2, r12
// mov r12.w, r10.w
// mov oC3, r12
static const DWORD GroupDepthShader[] =
{
	0xFFFF0300, 0x0200001F, 0x80000005, 0x90030000, 0x05000051, 0xA00F00DC, 0x00000000, 0x3F000000,
	0x3F800000, 0xB22BCC77, 0x0200001F, 0x90000000, 0xA00F080A, 0x0200001F, 0x90000000, 0xA00F080B,
	0x0200001F, 0x90000000, 0xA00F080C, 0x0200001F, 0x90000000, 0xA00F080D, 0x0200001F, 0x90000000,
	0xA00F080E, 0x0200001F, 0x90000000, 0xA00F080F, 0x02000001, 0x80030000, 0x90540000, 0x02000001,
	0x800C0000, 0xA00000DC, 0x0300005F, 0x800F0001, 0x80E40000, 0xA0E4080B, 0x02000001, 0x800F000A,
	0xA00000DC, 0x02010029, 0x80000001, 0xA00000DC, 0x0300005F, 0x800F0002, 0x80E40000, 0xA0E4080F,
	0x0300005F, 0x800F0003, 0x80E40000, 0xA0E4080E, 0x0300005F, 0x800F0004, 0x80E40000, 0xA0E4080D,
	0x0300005F, 0x800F0005, 0x80E40000, 0xA0E4080A, 0x0300005F, 0x800F0006, 0x80E40000, 0xA0E4080C,
	0x03000002, 0x80020007, 0x80FF0003, 0x81FF0002, 0x03000005, 0x80020007, 0x80550007, 0xA05500DF,
	0x04000004, 0x80010007, 0x80FF0002, 0xA00000DF, 0x81550007, 0x03000002, 0x80040007, 0x80FF0005,
	0x81FF0004, 0x03000005, 0x80040007, 0x80AA0007, 0xA05500DF, 0x03000002, 0x80080007, 0x80FF0003,
	0x81FF0004, 0x03000005, 0x80080007, 0x80FF0007, 0xA05500DF, 0x03000005, 0x80070008, 0x80A40006,
	0xA00000DF, 0x03000002, 0x80070008, 0x80A40008, 0xA05500DC, 0x02000013, 0x80070009, 0x80A40008,
	0x03000002, 0x80070008, 0x80A40008, 0x81A40009, 0x03000002, 0x80080008, 0xA00000DF, 0x81000008,
	0x03000002, 0x8001000B, 0x80000007, 0x81AA0007, 0x02000001, 0x8002000B, 0x80AA0007, 0x02000001,
	0x8004000B, 0x80FF0007, 0x03000002, 0x8008000B, 0x80550007, 0x81FF0007, 0x03000002, 0x8001000C,
	0x80FF0008, 0x81AA0008, 0x02000001, 0x8002000C, 0x80AA0008, 0x02000001, 0x8004000C, 0x80550008,
	0x03000002, 0x8008000C, 0x80000008, 0x81550008, 0x0300000B, 0x800F000C, 0x80E4000C, 0xA0AA00DC,
	0x02000006, 0x8001000D, 0x8000000C, 0x02000006, 0x8002000D, 0x8055000C, 0x02000006, 0x8004000D,
	0x80AA000C, 0x02000006, 0x8008000D, 0x80FF000C, 0x03000005, 0x800F000A, 0x80E4000B, 0x80E4000D,
	0x0000002B, 0x03000002, 0x8001000B, 0x80000001, 0xA0FF00DC, 0x02000001, 0x800F000B, 0x8000000B,
	0x01000041, 0x800F000B, 0x02000001, 0x8007000C, 0xA00000DC, 0x02000001, 0x8008000C, 0x8000000A,
	0x02000001, 0x800F0800, 0x80E4000C, 0x02000001, 0x8008000C, 0x8055000A, 0x02000001, 0x800F0801,
	0x80E4000C, 0x02000001, 0x8008000C, 0x80AA000A, 0x02000001, 0x800F0802, 0x80E4000C, 0x02000001,
	0x8008000C, 0x80FF000A, 0x02000001, 0x800F0803, 0x80E4000C, 0x0000FFFF
};

// ps_3_0
// mov oC0, c223
static const DWORD ConstantShader[] =
{
	0xFFFF0300, 0x02000001, 0x800F0800, 0xA0E400DF, 0x0000FFFF
};

static void ReleaseFogTextures()
{
	if (CountSurface) CountSurface->Release();
	if (SplitTexture) SplitTexture->Release();
	if (FirstResolveTexture) FirstResolveTexture->Release();
	if (SecondResolveTexture) SecondResolveTexture->Release();
	if (ThirdResolveTexture) ThirdResolveTexture->Release();
	if (CountTexture) CountTexture->Release();
	if (FrontDepthTexture) FrontDepthTexture->Release();
	if (FrontBackDepthTexture) FrontBackDepthTexture->Release();
	if (BehindFrontDepthTexture) BehindFrontDepthTexture->Release();
	if (BehindDepthTexture) BehindDepthTexture->Release();

	CountSurface = nullptr;
	SplitTexture = nullptr;
	FirstResolveTexture = nullptr;
	SecondResolveTexture = nullptr;
	ThirdResolveTexture = nullptr;
	CountTexture = nullptr;
	FrontDepthTexture = nullptr;
	FrontBackDepthTexture = nullptr;
	BehindFrontDepthTexture = nullptr;
	BehindDepthTexture = nullptr;
}

static void ReleaseFogResources()
{
	IDirect3DPixelShader9** Shaders[] = { &SplitAveragePS, &SplitBehindPS, &SplitBehindSidePS, &SplitFrontSidePS, &GroupDepthPS, &ConstantPS };
	for (IDirect3DPixelShader9** Shader : Shaders)
	{
		if (*Shader) (*Shader)->Release();
		*Shader = nullptr;
	}

	ReleaseFogTextures();
	FogDevice = nullptr;
}

static bool CreateFogResources(IDirect3DDevice9* Device, IDirect3DSurface9* SceneSurface, const D3DSURFACE_DESC& TargetDesc, const D3DSURFACE_DESC& SceneDesc)
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

		// The four group depths are written at once (four render targets)
		D3DCAPS9 Caps;
		if (FAILED(Device->GetDeviceCaps(&Caps)) || Caps.NumSimultaneousRTs < 4 ||
			FAILED(Device->CreatePixelShader(SplitAverageShader, &SplitAveragePS)) || FAILED(Device->CreatePixelShader(SplitBehindShader, &SplitBehindPS)) ||
			FAILED(Device->CreatePixelShader(SplitBehindSideShader, &SplitBehindSidePS)) || FAILED(Device->CreatePixelShader(SplitFrontSideShader, &SplitFrontSidePS)) ||
			FAILED(Device->CreatePixelShader(GroupDepthShader, &GroupDepthPS)) || FAILED(Device->CreatePixelShader(ConstantShader, &ConstantPS)))
		{
			bShadersFailed = true;
			ReleaseFogResources();
			return false;
		}
	}

	if (CountSurface)
	{
		D3DSURFACE_DESC Desc;
		CountSurface->GetDesc(&Desc);

		if (Desc.Width != SceneDesc.Width || Desc.Height != SceneDesc.Height || Desc.Format != SceneDesc.Format || Desc.MultiSampleType != TargetDesc.MultiSampleType || Desc.MultiSampleQuality != TargetDesc.MultiSampleQuality)
		{
			ReleaseFogTextures();
		}
	}

	if (!CountSurface)
	{
		IDirect3DTexture9** Textures[] = { &FirstResolveTexture, &SecondResolveTexture, &ThirdResolveTexture, &CountTexture, &FrontDepthTexture, &FrontBackDepthTexture, &BehindFrontDepthTexture, &BehindDepthTexture };

		bool bCreated = SUCCEEDED(Device->CreateRenderTarget(SceneDesc.Width, SceneDesc.Height, SceneDesc.Format, TargetDesc.MultiSampleType, TargetDesc.MultiSampleQuality, FALSE, &CountSurface, nullptr)) &&
			(SUCCEEDED(Device->CreateTexture(SceneDesc.Width, SceneDesc.Height, 1, D3DUSAGE_RENDERTARGET, D3DFMT_R32F, D3DPOOL_DEFAULT, &SplitTexture, nullptr)) ||
			SUCCEEDED(Device->CreateTexture(SceneDesc.Width, SceneDesc.Height, 1, D3DUSAGE_RENDERTARGET, SceneDesc.Format, D3DPOOL_DEFAULT, &SplitTexture, nullptr)));
		for (IDirect3DTexture9** Texture : Textures)
		{
			bCreated = bCreated && SUCCEEDED(Device->CreateTexture(SceneDesc.Width, SceneDesc.Height, 1, D3DUSAGE_RENDERTARGET, SceneDesc.Format, D3DPOOL_DEFAULT, Texture, nullptr));
		}

		if (!bCreated)
		{
			ReleaseFogTextures();
			return false;
		}

		// The scene can be resolved into them, checked once before anything gets touched
		IDirect3DSurface9* ResolveSurface = nullptr;
		FirstResolveTexture->GetSurfaceLevel(0, &ResolveSurface);
		const HRESULT hr = Device->StretchRect(SceneSurface, nullptr, ResolveSurface, nullptr, D3DTEXF_NONE);
		ResolveSurface->Release();

		if (FAILED(hr))
		{
			bResolveFailed = true;
			ReleaseFogResources();
			return false;
		}
	}

	return true;
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
	D3DRS_ALPHATESTENABLE, D3DRS_COLORWRITEENABLE, D3DRS_COLORWRITEENABLE1, D3DRS_COLORWRITEENABLE2, D3DRS_COLORWRITEENABLE3, D3DRS_MULTISAMPLEANTIALIAS, D3DRS_MULTISAMPLEMASK,
	D3DRS_STENCILENABLE, D3DRS_TWOSIDEDSTENCILMODE, D3DRS_STENCILFUNC, D3DRS_STENCILREF, D3DRS_STENCILMASK, D3DRS_STENCILWRITEMASK,
	D3DRS_STENCILPASS, D3DRS_STENCILFAIL, D3DRS_STENCILZFAIL
};

static const D3DSAMPLERSTATETYPE SavedSamplerStates[] =
{
	D3DSAMP_MINFILTER, D3DSAMP_MAGFILTER, D3DSAMP_MIPFILTER, D3DSAMP_ADDRESSU, D3DSAMP_ADDRESSV, D3DSAMP_SRGBTEXTURE
};

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
		const bool bStencil = DepthDesc.Format == D3DFMT_D24S8 || DepthDesc.Format == D3DFMT_D24FS8 || DepthDesc.Format == D3DFMT_D24X4S4 || DepthDesc.Format == MAKEFOURCC('I', 'N', 'T', 'Z');
		const bool bSameSize = TargetDesc.Width == SceneDesc.Width && TargetDesc.Height == SceneDesc.Height && TargetDesc.Format == SceneDesc.Format;

		if (bMultisampled && bStencil && bSameSize && CreateFogResources(Device, SceneSurface, TargetDesc, SceneDesc))
		{
			D3DVIEWPORT9 Viewport;
			DWORD RenderStates[std::size(SavedRenderStates)];
			const DWORD Samplers[] = { ThirdResolveSampler, SplitSampler, CountSampler, SecondResolveSampler, FirstResolveSampler, SceneSampler };
			IDirect3DBaseTexture9* const Textures[] = { ThirdResolveTexture, SplitTexture, CountTexture, SecondResolveTexture, FirstResolveTexture, SceneTexture };
			DWORD SamplerStates[std::size(Samplers)][std::size(SavedSamplerStates)];
			IDirect3DBaseTexture9* SamplerTextures[std::size(Samplers)] = {};
			float SavedParams[4];

			Device->GetViewport(&Viewport);

			// Same quad pushed out by one pixel, every output of the fog vertex shader is linear in the position
			float QuadVertices[4][2];
			const float* SourceVertices = static_cast<const float*>(Args.VertexData);
			for (int i = 0; i < 4; i++)
			{
				QuadVertices[i][0] = SourceVertices[i * 2] * (1.0f + 2.0f / Viewport.Width);
				QuadVertices[i][1] = SourceVertices[i * 2 + 1] * (1.0f + 2.0f / Viewport.Height);
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

			for (size_t s = 0; s < std::size(Samplers); s++)
			{
				Device->SetSamplerState(Samplers[s], D3DSAMP_MINFILTER, D3DTEXF_POINT);
				Device->SetSamplerState(Samplers[s], D3DSAMP_MAGFILTER, D3DTEXF_POINT);
				Device->SetSamplerState(Samplers[s], D3DSAMP_MIPFILTER, D3DTEXF_NONE);
				Device->SetSamplerState(Samplers[s], D3DSAMP_ADDRESSU, D3DTADDRESS_CLAMP);
				Device->SetSamplerState(Samplers[s], D3DSAMP_ADDRESSV, D3DTADDRESS_CLAMP);
				Device->SetSamplerState(Samplers[s], D3DSAMP_SRGBTEXTURE, FALSE);
				Device->SetTexture(Samplers[s], Textures[s]);
			}

			IDirect3DSurface9* SplitSurface = nullptr;
			IDirect3DSurface9* FirstResolveSurface = nullptr;
			IDirect3DSurface9* SecondResolveSurface = nullptr;
			IDirect3DSurface9* ThirdResolveSurface = nullptr;
			IDirect3DSurface9* CountResolveSurface = nullptr;
			IDirect3DSurface9* FrontDepthSurface = nullptr;
			IDirect3DSurface9* FrontBackDepthSurface = nullptr;
			IDirect3DSurface9* BehindFrontDepthSurface = nullptr;
			IDirect3DSurface9* BehindDepthSurface = nullptr;
			SplitTexture->GetSurfaceLevel(0, &SplitSurface);
			FirstResolveTexture->GetSurfaceLevel(0, &FirstResolveSurface);
			SecondResolveTexture->GetSurfaceLevel(0, &SecondResolveSurface);
			ThirdResolveTexture->GetSurfaceLevel(0, &ThirdResolveSurface);
			CountTexture->GetSurfaceLevel(0, &CountResolveSurface);
			FrontDepthTexture->GetSurfaceLevel(0, &FrontDepthSurface);
			FrontBackDepthTexture->GetSurfaceLevel(0, &FrontBackDepthSurface);
			BehindFrontDepthTexture->GetSurfaceLevel(0, &BehindFrontDepthSurface);
			BehindDepthTexture->GetSurfaceLevel(0, &BehindDepthSurface);

			const DWORD NumSamples = TargetDesc.MultiSampleType;
			const float TexelSize[4] = { 1.0f / SceneDesc.Width, 1.0f / SceneDesc.Height, 0.0f, 0.0f };
			const float SampleParams[4] = { static_cast<float>(NumSamples), NumSamples / 255.0f, 0.0f, 0.0f };

			auto SetTarget = [&](IDirect3DSurface9* Surface, IDirect3DSurface9* Depth)
			{
				Device->SetRenderTarget(0, Surface);
				Device->SetDepthStencilSurface(Depth);
				Device->SetViewport(&Viewport);
			};

			// Where to split the samples of each pixel
			SetTarget(SplitSurface, nullptr);
			Device->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
			Device->SetRenderState(D3DRS_STENCILENABLE, FALSE);
			Device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
			Device->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
			Device->SetRenderState(D3DRS_COLORWRITEENABLE, 0xF);
			Device->SetPixelShader(SplitAveragePS);
			Device->SetPixelShaderConstantF(ParamsRegister, TexelSize, 1);
			DrawFogQuad(QuadArgs);

			const float CountValue[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
			SetTarget(CountSurface, DepthSurface);
			Device->Clear(0, nullptr, D3DCLEAR_TARGET, 0, 1.0f, 0);

			auto CountSamples = [&](DWORD Stencil, DWORD Channel)
			{
				SetTarget(CountSurface, DepthSurface);
				Device->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
				Device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
				Device->SetRenderState(D3DRS_COLORWRITEENABLE, Channel);
				Device->SetRenderState(D3DRS_STENCILFUNC, D3DCMP_EQUAL);
				Device->SetRenderState(D3DRS_STENCILMASK, SplitStencilMask);
				Device->SetRenderState(D3DRS_STENCILREF, Stencil);
				Device->SetRenderState(D3DRS_STENCILWRITEMASK, 0);
				Device->SetPixelShader(ConstantPS);
				Device->SetPixelShaderConstantF(ParamsRegister, CountValue, 1);
				DrawFogQuad(QuadArgs);
			};

			SetTarget(SceneSurface, DepthSurface);
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
			Device->SetRenderState(D3DRS_COLORWRITEENABLE, D3DCOLORWRITEENABLE_ALPHA);
			Device->SetRenderState(D3DRS_MULTISAMPLEANTIALIAS, TRUE);
			Device->SetRenderState(D3DRS_MULTISAMPLEMASK, 0xFFFFFFFF);
			Device->SetRenderState(D3DRS_STENCILENABLE, TRUE);
			Device->SetRenderState(D3DRS_TWOSIDEDSTENCILMODE, FALSE);
			Device->SetRenderState(D3DRS_STENCILFUNC, D3DCMP_ALWAYS);
			Device->SetRenderState(D3DRS_STENCILREF, BehindStencil);
			Device->SetRenderState(D3DRS_STENCILWRITEMASK, SplitStencilMask);
			Device->SetRenderState(D3DRS_STENCILPASS, D3DSTENCILOP_REPLACE);
			Device->SetRenderState(D3DRS_STENCILZFAIL, D3DSTENCILOP_ZERO);
			Device->SetRenderState(D3DRS_STENCILFAIL, D3DSTENCILOP_KEEP);
			Device->SetPixelShader(SplitBehindPS);
			DrawFogQuad(QuadArgs);

			CountSamples(BehindStencil, D3DCOLORWRITEENABLE_RED);
			Device->StretchRect(SceneSurface, nullptr, FirstResolveSurface, nullptr, D3DTEXF_NONE);
			Device->StretchRect(CountSurface, nullptr, CountResolveSurface, nullptr, D3DTEXF_NONE);

			SetTarget(SceneSurface, DepthSurface);
			Device->SetRenderState(D3DRS_ZENABLE, D3DZB_TRUE);
			Device->SetRenderState(D3DRS_ZFUNC, D3DCMP_GREATER);
			Device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
			Device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_ZERO);
			Device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_SRCALPHA);
			Device->SetRenderState(D3DRS_COLORWRITEENABLE, D3DCOLORWRITEENABLE_ALPHA);
			Device->SetRenderState(D3DRS_STENCILFUNC, D3DCMP_EQUAL);
			Device->SetRenderState(D3DRS_STENCILMASK, ScaledStencilBit);
			Device->SetRenderState(D3DRS_STENCILREF, ScaledStencilBit);
			Device->SetRenderState(D3DRS_STENCILWRITEMASK, ScaledStencilBit | FrontStencil);
			Device->SetRenderState(D3DRS_STENCILPASS, D3DSTENCILOP_INVERT);
			Device->SetRenderState(D3DRS_STENCILZFAIL, D3DSTENCILOP_KEEP);
			Device->SetPixelShader(SplitBehindSidePS);
			Device->SetPixelShaderConstantF(ParamsRegister, SampleParams, 1);
			DrawFogQuad(QuadArgs);

			Device->StretchRect(SceneSurface, nullptr, SecondResolveSurface, nullptr, D3DTEXF_NONE);

			Device->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESS);
			Device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_DESTALPHA);
			Device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);
			Device->SetRenderState(D3DRS_STENCILMASK, BehindStencil);
			Device->SetRenderState(D3DRS_STENCILREF, FrontStencil);
			Device->SetRenderState(D3DRS_STENCILWRITEMASK, SplitStencilMask);
			Device->SetRenderState(D3DRS_STENCILZFAIL, D3DSTENCILOP_REPLACE);
			Device->SetPixelShader(SplitFrontSidePS);
			DrawFogQuad(QuadArgs);

			CountSamples(BehindFrontStencil, D3DCOLORWRITEENABLE_GREEN);
			CountSamples(FrontBackStencil, D3DCOLORWRITEENABLE_BLUE);
			Device->StretchRect(SceneSurface, nullptr, ThirdResolveSurface, nullptr, D3DTEXF_NONE);
			Device->StretchRect(CountSurface, nullptr, CountResolveSurface, nullptr, D3DTEXF_NONE);

			SetTarget(FrontDepthSurface, nullptr);
			Device->SetRenderTarget(1, FrontBackDepthSurface);
			Device->SetRenderTarget(2, BehindFrontDepthSurface);
			Device->SetRenderTarget(3, BehindDepthSurface);
			Device->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
			Device->SetRenderState(D3DRS_STENCILENABLE, FALSE);
			Device->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
			Device->SetRenderState(D3DRS_COLORWRITEENABLE, 0xF);
			Device->SetRenderState(D3DRS_COLORWRITEENABLE1, 0xF);
			Device->SetRenderState(D3DRS_COLORWRITEENABLE2, 0xF);
			Device->SetRenderState(D3DRS_COLORWRITEENABLE3, 0xF);
			Device->SetPixelShader(GroupDepthPS);
			Device->SetPixelShaderConstantF(ParamsRegister, SampleParams, 1);
			DrawFogQuad(QuadArgs);
			Device->SetRenderTarget(3, nullptr);
			Device->SetRenderTarget(2, nullptr);
			Device->SetRenderTarget(1, nullptr);
			SetTarget(SceneSurface, DepthSurface);

			const DWORD Groups[] = { 0, FrontStencil, FrontBackStencil, BehindFrontStencil, BehindStencil };
			IDirect3DTexture9* const GroupTextures[] = { static_cast<IDirect3DTexture9*>(SceneTexture), FrontDepthTexture, FrontBackDepthTexture, BehindFrontDepthTexture, BehindDepthTexture };
			RestoreGameStates();
			Device->SetRenderState(D3DRS_STENCILENABLE, TRUE);
			Device->SetRenderState(D3DRS_TWOSIDEDSTENCILMODE, FALSE);
			Device->SetRenderState(D3DRS_STENCILFUNC, D3DCMP_EQUAL);
			Device->SetRenderState(D3DRS_STENCILMASK, SplitStencilMask);
			Device->SetRenderState(D3DRS_STENCILPASS, D3DSTENCILOP_KEEP);
			Device->SetRenderState(D3DRS_STENCILFAIL, D3DSTENCILOP_KEEP);
			Device->SetRenderState(D3DRS_STENCILZFAIL, D3DSTENCILOP_KEEP);
			Device->SetPixelShader(FogShader);
			for (size_t g = 0; g < std::size(Groups); g++)
			{
				Device->SetRenderState(D3DRS_STENCILREF, Groups[g]);
				Device->SetTexture(0, GroupTextures[g]);
				DrawFogQuad(QuadArgs);
			}

			const float ScaleDown[4] = { 0.0f, 0.0f, 0.0f, 1.0f / 256.0f };
			Device->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
			Device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
			Device->SetRenderState(D3DRS_SEPARATEALPHABLENDENABLE, FALSE);
			Device->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
			Device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_ZERO);
			Device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_SRCALPHA);
			Device->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
			Device->SetRenderState(D3DRS_COLORWRITEENABLE, D3DCOLORWRITEENABLE_ALPHA);
			Device->SetRenderState(D3DRS_MULTISAMPLEANTIALIAS, TRUE);
			Device->SetRenderState(D3DRS_MULTISAMPLEMASK, 0xFFFFFFFF);
			Device->SetRenderState(D3DRS_STENCILMASK, ScaledStencilBit);
			Device->SetRenderState(D3DRS_STENCILREF, ScaledStencilBit);
			Device->SetRenderState(D3DRS_STENCILWRITEMASK, SplitStencilMask);
			Device->SetRenderState(D3DRS_STENCILPASS, D3DSTENCILOP_ZERO);
			Device->SetRenderState(D3DRS_STENCILFAIL, D3DSTENCILOP_ZERO);
			Device->SetPixelShader(ConstantPS);
			Device->SetPixelShaderConstantF(ParamsRegister, ScaleDown, 1);
			DrawFogQuad(QuadArgs);

			Device->SetPixelShader(FogShader);
			Device->SetTexture(0, SceneTexture);
			Device->SetPixelShaderConstantF(ParamsRegister, SavedParams, 1);
			for (size_t s = 0; s < std::size(Samplers); s++)
			{
				Device->SetTexture(Samplers[s], SamplerTextures[s]);
				for (size_t i = 0; i < std::size(SavedSamplerStates); i++) Device->SetSamplerState(Samplers[s], SavedSamplerStates[i], SamplerStates[s][i]);
				if (SamplerTextures[s]) SamplerTextures[s]->Release();
			}
			RestoreGameStates();

			SplitSurface->Release();
			FirstResolveSurface->Release();
			SecondResolveSurface->Release();
			ThirdResolveSurface->Release();
			CountResolveSurface->Release();
			FrontDepthSurface->Release();
			FrontBackDepthSurface->Release();
			BehindFrontDepthSurface->Release();
			BehindDepthSurface->Release();
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
