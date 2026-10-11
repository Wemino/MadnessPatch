#include "Common.hpp"
#include "Features.hpp"

static safetyhook::InlineHook MainLoop_Hook{};

static void* __fastcall Loop_Hook(int thisp, int)
{
	if (g_State.AlicePlayerController && g_State.AlicePlayerController->PlayerInput)
		g_State.isUsingGamepad = g_State.AlicePlayerController->PlayerInput->bUsingGamepad;

	if (HysteriaLockOnGuardEnabled) HysteriaLockOnGuard::Tick();
	if (FixMissingMusicEnabled) FixMissingMusic::Tick();
	if (FixMapPropertiesEnabled) FixMapProperties::Tick();
	if (FixHatterElevatorEnabled) FixHatterElevator::Tick();
	if (UnlockCompleteEditionDLC) RefreshDLCWeapon();
	InputResponsiveness::Tick();
	if (FixAspectRatio) BlackBarGuard::Tick();
	if (RestoreMenuMouseCursor && EnableControllerIcons) MenuMouseCursor::Tick();

	if (AchievementSupport)
	{
		UpdateAchievementProgress();
		AchievementOverlay::Update();
		BlockCameraInMenu::Tick();
	}

	return MainLoop_Hook.fastcall<void*>(thisp);
}

void ApplyMainLoopHooks()
{
	MainLoop_Hook = HookHelper::CreateHook((void*)GetAddress(Addr::EngineTick), &Loop_Hook);
}
