#include "Common.hpp"
#include "Features.hpp"

static safetyhook::MidHook GammaColorScaleHook{};

constexpr float FullFadeAmount = 0.9999f;
constexpr float TinyScale = 1e-30f;

// eax = ColorScale, esi = overlay (FadeColor, A = FadeAmount), [ebp-0x20..0x18] = clamped scale
static void OnGammaColorScale(safetyhook::Context& ctx)
{
	const float* overlay = reinterpret_cast<const float*>(ctx.esi);
	if (overlay[0] != 0.0f || overlay[1] != 0.0f || overlay[2] != 0.0f)
		return;

	const float* colorScale = reinterpret_cast<const float*>(ctx.eax);
	float* scale = reinterpret_cast<float*>(ctx.ebp - 0x20);
	float keep = overlay[3] >= FullFadeAmount ? 0.0f : 1.0f - overlay[3];

	for (int i = 0; i < 3; i++)
	{
		float value = colorScale[i] * keep;
		scale[i] = value > TinyScale ? value : TinyScale;
	}
}

void ApplyFixFadeToBlack()
{
	if (!FixFadeToBlackEnabled) return;

	GammaColorScaleHook = safetyhook::create_mid(GetAddress(Addr::GammaColorScale), OnGammaColorScale);
}
