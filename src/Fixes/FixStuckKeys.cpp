#include "Common.hpp"
#include "Features.hpp"

safetyhook::InlineHook PlayerInputInputKey;

static uintptr_t UInputInputKey = 0;
static int* PlayerInputDisabled = nullptr; // UPlayerInput::gDisabled

constexpr int IE_Released = 1;

static int __fastcall PlayerInputInputKey_Hook(uintptr_t thisp, int, int controllerId, int keyIndex, int keyNumber, int event, float amountDepressed, BOOL bGamepad)
{
	if (*PlayerInputDisabled && event == IE_Released)
	{
		return reinterpret_cast<int(__thiscall*)(uintptr_t, int, int, int, int, float, BOOL)>(UInputInputKey)(thisp, controllerId, keyIndex, keyNumber, event, amountDepressed, bGamepad);
	}

	return PlayerInputInputKey.unsafe_thiscall<int>(thisp, controllerId, keyIndex, keyNumber, event, amountDepressed, bGamepad);
}

void ApplyFixStuckKeys()
{
	if (!FixStuckKeys) return;

	UInputInputKey = GetAddress(Addr::UInputInputKey);
	PlayerInputDisabled = reinterpret_cast<int*>(GetAddress(Addr::PlayerInputDisabled));
	PlayerInputInputKey = HookHelper::CreateHook((void*)GetAddress(Addr::PlayerInputInputKey), &PlayerInputInputKey_Hook);
}