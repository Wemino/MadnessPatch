#include "Common.hpp"
#include "Features.hpp"

static safetyhook::InlineHook GaussianBlurFilterBuffer{};
static uintptr_t ApplyGaussianBlurStep = 0;
static UINT* FilterBufferSizeY = nullptr;
static UINT* FilterBufferSizeX = nullptr;
static UINT* FilterDownsampleFactor = nullptr;

constexpr float MaxStepRadius = 15.0f;
constexpr int MaxPasses = 16;

// Radius in xmm1, the rest on the stack
static void BlurStep(float radius, UINT sizeX, UINT sizeY, float dirX, float dirY, UINT bSecond)
{
	uintptr_t step = ApplyGaussianBlurStep;

	__asm
	{
		push bSecond
		push dirY
		push dirX
		push sizeY
		push sizeX
		movss xmm1, radius
		call step
		add esp, 0x14
	}
}

static void __cdecl GaussianBlurFilterBuffer_Hook(UINT sizeX, UINT sizeY, float kernelRadius, UINT bSecond)
{
	UINT factor = *FilterDownsampleFactor;
	float scale = (float)(sizeX * factor) / 1280.0f;
	float variance = std::min(kernelRadius / (float)factor, MaxStepRadius) * scale * scale;

	int passes = std::clamp((int)std::ceil(variance / MaxStepRadius), 1, MaxPasses);
	float radius = variance / (float)passes;
	float dirX = 1.0f / (float)*FilterBufferSizeX;
	float dirY = 1.0f / (float)*FilterBufferSizeY;

	for (int i = 0; i < passes; i++)
	{
		BlurStep(radius, sizeX, sizeY, dirX, 0.0f, bSecond);
		BlurStep(radius, sizeX, sizeY, 0.0f, dirY, bSecond);
	}
}

void ApplyFixBlurScaling()
{
	if (!FixBlurScaling) return;

	uintptr_t addr_GaussianBlurFilterBuffer = GetAddress(Addr::GaussianBlurFilterBuffer);
	FilterBufferSizeY = *reinterpret_cast<UINT**>(addr_GaussianBlurFilterBuffer + 0x7);
	FilterBufferSizeX = *reinterpret_cast<UINT**>(addr_GaussianBlurFilterBuffer + 0xD);
	FilterDownsampleFactor = *reinterpret_cast<UINT**>(addr_GaussianBlurFilterBuffer + 0x16);
	ApplyGaussianBlurStep = addr_GaussianBlurFilterBuffer + 0xB4 + 0x5 + *reinterpret_cast<int32_t*>(addr_GaussianBlurFilterBuffer + 0xB5);

	GaussianBlurFilterBuffer = HookHelper::CreateHook((void*)addr_GaussianBlurFilterBuffer, &GaussianBlurFilterBuffer_Hook);
}
