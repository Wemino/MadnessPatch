#include "Common.hpp"
#include "Features.hpp"

safetyhook::InlineHook ClothSimulator;

constexpr int CLOTH_MAX_PARTICLES = 80;

static uint32_t __fastcall ClothSimulator_Hook(void* thisPtr, int, float delta)
{
	uint8_t* cloth = (uint8_t*)thisPtr;
	int numParticles = *(int*)(cloth + 0xB8);

	bool bypass = numParticles > CLOTH_MAX_PARTICLES;

	// Dollmaker strings
	if (!bypass && *(int*)(cloth + 0xC0) == 0)
	{
		int constraints = *(int*)(cloth + 0xBC);
		bypass = (numParticles == 15 && constraints == 27) || (numParticles == 20 && constraints == 37);
	}

	if (bypass)
		return ClothSimulator.unsafe_thiscall<uint32_t>(thisPtr, delta);

	return StepClothAtFixedRate(ClothSimulator, thisPtr, delta);
}

void ApplyFixHighFPSClothPhysics()
{
	if (!FixHighFPSClothPhysics) return;

	ClothSimulator = HookHelper::CreateHook((void*)GetAddress(Addr::ClothSimulator), &ClothSimulator_Hook);
}
