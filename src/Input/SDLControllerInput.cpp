#include "Common.hpp"
#include "Features.hpp"

safetyhook::InlineHook XInputGetStateHook;
safetyhook::InlineHook XInputSetStateHook;

static DWORD WINAPI XInputGetState_Hook(DWORD dwUserIndex, XINPUT_STATE* pState)
{
	static bool s_inHook = false;
	if (s_inHook)
	{
		return XInputGetStateHook.stdcall<DWORD>(dwUserIndex, pState);
	}

	if (dwUserIndex != 0) return ERROR_DEVICE_NOT_CONNECTED;

	s_inHook = true;
	DWORD result = ControllerHelper::PollController(pState, InvertABXYButtons, InvertShoulderTriggers);
	s_inHook = false;

	g_State.padConnected = (result == ERROR_SUCCESS);
	if (g_State.padConnected && pState) g_State.padState = pState->Gamepad;

	if (AchievementSupport && pState)
	{
		AchievementOverlay::FeedControllerState(*pState, result == ERROR_SUCCESS);

		if (AchievementOverlay::WantCaptureController())
		{
			ZeroMemory(&pState->Gamepad, sizeof(XINPUT_GAMEPAD)); // hide input from the game
		}
	}

	return result;
}

static DWORD WINAPI XInputSetState_Hook(DWORD dwUserIndex, XINPUT_VIBRATION* pVibration)
{
	static bool s_inHook = false;
	if (s_inHook)
	{
		return XInputSetStateHook.stdcall<DWORD>(dwUserIndex, pVibration);
	}

	if (dwUserIndex != 0) return ERROR_DEVICE_NOT_CONNECTED;

	s_inHook = true;
	DWORD result = ControllerHelper::SetVibration(pVibration);
	s_inHook = false;
	return result;
}

void ApplyUseSDLControllerInput()
{
	if (!UseSDLControllerInput) return;

	ControllerHelper::InitializeSDLGamepad();
	XInputGetStateHook = HookHelper::CreateHookAPI(L"XINPUT1_3.dll", "XInputGetState", &XInputGetState_Hook);
	XInputSetStateHook = HookHelper::CreateHookAPI(L"XINPUT1_3.dll", "XInputSetState", &XInputSetState_Hook);
}
