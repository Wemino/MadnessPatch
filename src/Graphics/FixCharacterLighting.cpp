#include "Common.hpp"
#include "Features.hpp"

void ApplyFixCharacterLighting()
{
	if (!FixCharacterLighting) return;

	// Refresh static lighting on the light environment timer, not only when the character moved on that exact frame
	MemoryHelper::MakeNOP(GetAddress(Addr::LightEnvStaticUpdate), 2);
}
