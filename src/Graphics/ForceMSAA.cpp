#include "Common.hpp"
#include "Features.hpp"

#include <d3d9.h>

#pragma comment(lib, "d3d9.lib")

static safetyhook::MidHook ActivateSystemSettingsHook{};
static int MultiSamples = 1;

static void OnActivateSystemSettings(safetyhook::Context& ctx)
{
	int* Settings = *reinterpret_cast<int**>(ctx.esp + 0x4);
	Settings[6] = MultiSamples;
}

void ApplyForceMSAA()
{
	if (ForceMSAA < 0) return;

	if (IDirect3D9* Direct3D = Direct3DCreate9(D3D_SDK_VERSION))
	{
		const D3DFORMAT Formats[] = { D3DFMT_A16B16G16R16F, D3DFMT_D24S8, D3DFMT_A8R8G8B8 };
		for (int Count = ForceMSAA; Count > 1 && MultiSamples == 1; Count--)
		{
			bool bSupported = true;
			for (D3DFORMAT Format : Formats)
			{
				bSupported = bSupported && SUCCEEDED(Direct3D->CheckDeviceMultiSampleType(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, Format, FALSE, static_cast<D3DMULTISAMPLE_TYPE>(Count), nullptr));
			}

			if (bSupported) MultiSamples = Count;
		}

		Direct3D->Release();
	}

	ActivateSystemSettingsHook = safetyhook::create_mid(GetAddress(Addr::ActivateSystemSettings), OnActivateSystemSettings);
}
