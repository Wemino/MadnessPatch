#include "Common.hpp"
#include "Features.hpp"

static safetyhook::MidHook MapLoadedCountStepHook{};
static uintptr_t MapLoadedCountStepEnd = 0;
static int32_t* MapLoadedCount = nullptr; // GMapLoadedCount
static int32_t* MapLoadedMaxCount = nullptr; // GMapLoadedMaxCount, [FullScreenMovie] DelayCountAfterMapLoaded

static struct
{
	AWorldInfo* worldInfo = nullptr;
	float lastTime = 0.0f;
	float carry = 0.0f;
	bool steps = true;
} countdown;

static void OnMapLoadedCountStep(safetyhook::Context& ctx)
{
	const int32_t count = *MapLoadedCount;
	const int32_t max = *MapLoadedMaxCount;
	if (count > max)
		return; // no loading screen counting down

	AWorldInfo* worldInfo = reinterpret_cast<AWorldInfo*>(ctx.edi);
	const float now = worldInfo->RealTimeSeconds;

	if (count == 0 || worldInfo != countdown.worldInfo || now < countdown.lastTime)
	{
		countdown = { worldInfo, now, 0.0f, true };
	}
	else if (now != countdown.lastTime)
	{
		bool own;
		countdown.steps = CountTargetFrames(now - countdown.lastTime, countdown.carry, own) > 0;
		countdown.lastTime = now;
	}

	if (!countdown.steps)
	{
		ctx.eip = MapLoadedCountStepEnd;
	}
}

void ApplyFixHighFPSLoading()
{
	if (!FixHighFPSLoading) return;

	MapLoadedCountStepEnd = GetAddress(Addr::MapLoadedCountStepEnd);
	MapLoadedCount = reinterpret_cast<int32_t*>(GetAddress(Addr::MapLoadedCount));
	MapLoadedMaxCount = reinterpret_cast<int32_t*>(GetAddress(Addr::MapLoadedMaxCount));
	MapLoadedCountStepHook = safetyhook::create_mid(GetAddress(Addr::MapLoadedCountStep), OnMapLoadedCountStep);
}
