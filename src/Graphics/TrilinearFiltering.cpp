#include "Common.hpp"
#include "Features.hpp"

void ApplyTrilinearFiltering()
{
	if (!TrilinearFiltering) return;

	// case SF_AnisotropicPoint: jmp to MipFilter = D3DTEXF_POINT -> jmp back to MipFilter = D3DTEXF_LINEAR of case SF_AnisotropicLinear
	MemoryHelper::WriteMemory<uint8_t>(GetAddress(Addr::AnisotropicPointMipFilter) + 0x1, 0xEF);
}
