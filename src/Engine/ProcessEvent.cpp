#include "Common.hpp"
#include "Features.hpp"

safetyhook::InlineHook ProcessEvent;

static UFunction* g_tickAlice = nullptr;
static UFunction* g_calloutPC = nullptr;
static UFunction* g_updateCam = nullptr;
static UFunction* g_viewportPostRender = nullptr;

static UFunction* g_meleeAttack = nullptr;
static UFunction* g_weaponAttack = nullptr;
static UFunction* g_switchWeaponGroup = nullptr;
static UFunction* g_rightClickAttack = nullptr;
static UFunction* g_switchVorpal = nullptr;
static UFunction* g_switchHobby = nullptr;
static UFunction* g_switchEyeStaff = nullptr;
static UFunction* g_pcCanFire = nullptr;
static UFunction* g_pawnFadeOutWeapon = nullptr;
static UFunction* g_pawnClearDelayAttach = nullptr;

static AWeapon* volatile g_weaponToRefresh = nullptr;
static AWeapon* s_lastSeenWeapon = nullptr;

static void __fastcall ProcessEvent_Hook(int This, void*, UFunction* Function, int uParams, int uResult)
{
	bool isWeaponSwitch = FixWeaponSwitchFadeInEnabled && g_meleeAttack && (Function == g_meleeAttack || Function == g_weaponAttack || Function == g_switchWeaponGroup || Function == g_rightClickAttack || Function == g_switchVorpal || Function == g_switchHobby || Function == g_switchEyeStaff);

	bool switchWeaponWasHidden = false;
	if (isWeaponSwitch)
	{
		AAlicePlayerController* wpc = g_State.AlicePlayerController;
		AWeaponForAlice* w = (wpc && wpc->MyAlicePawn) ? reinterpret_cast<AWeaponForAlice*>(wpc->MyAlicePawn->Weapon) : nullptr;
		switchWeaponWasHidden = (w == nullptr) || w->bFadeToHide;
	}

	if (UnlockCompleteEditionDLC && Function == g_tickAlice)
	{
		AAlicePlayerController* pc = g_State.AlicePlayerController;
		if (pc && pc->WorldInfo && pc->WorldInfo->Game && pc->Pawn)
		{
			AAliceGameInfo* gi = (AAliceGameInfo*)pc->WorldInfo->Game;
			gi->DLC_VB_UnLock = 1;
			gi->DLC_ES_UnLock = 1;
			gi->DLC_HH_UnLock = 1;
			gi->DLC_TC_UnLock = 1;

			AWeapon* w = pc->Pawn->Weapon;
			if (w && w != s_lastSeenWeapon)
			{
				s_lastSeenWeapon = w;
				g_weaponToRefresh = w;
			}
		}
		else
		{
			s_lastSeenWeapon = nullptr;
			g_weaponToRefresh = nullptr;
		}
	}

	size_t cameraEvent = HighFPSCamera::BeforeEvent((UObject*)This, Function, (void*)uParams);
	ProcessEvent.thiscall<void>(This, Function, uParams, uResult);
	HighFPSCamera::AfterEvent(cameraEvent);

	if (isWeaponSwitch && switchWeaponWasHidden && g_pcCanFire && g_pawnFadeOutWeapon)
	{
		AAlicePlayerController* wpc = g_State.AlicePlayerController;
		AAlicePawn* pawn = wpc ? wpc->MyAlicePawn : nullptr;
		AWeaponForAlice* w = pawn ? reinterpret_cast<AWeaponForAlice*>(pawn->Weapon) : nullptr;

		if (w && !w->bInUse)
		{
			struct { uint32_t ReturnValue; } canFire{};
			wpc->ProcessEvent(g_pcCanFire, &canFire, nullptr);
			if (!canFire.ReturnValue)
			{
				if (g_pawnClearDelayAttach)
				{
					int noParams = 0;
					pawn->ProcessEvent(g_pawnClearDelayAttach, &noParams, nullptr);
				}

				AAlicePawn_execFadeOutWeapon_Params fade{};
				fade.bDetachFromPawn = 1;
				pawn->ProcessEvent(g_pawnFadeOutWeapon, &fade, nullptr);
			}
		}
	}

	if (AchievementSupport && Function == g_viewportPostRender && uParams)
	{
		AchievementOverlay::OnPostRender(reinterpret_cast<UGameViewportClient_eventPostRender_Params*>(uParams)->Canvas);
	}

	if (FixAspectRatio && g_State.isWideScreen && Function == g_updateCam && This && g_State.bRealGameplay)
	{
		AAlicePlayerController* pc = g_State.AlicePlayerController;
		AAlicePawn* pawn = pc ? (AAlicePawn*)pc->Pawn : nullptr;

		if (pawn)
		{
			float base = pawn->AliceCameraFOV;
			float want = ScaleFOV(base, ASPECT_RATIO_16_9, g_State.currentAspectRatio);
			ACamera* cam = (ACamera*)This;

			static float eased = 0.0f;
			if (eased <= 1.0f)
			{
				eased = want;
			}

			eased += (want - eased) * 0.05f;
			cam->CameraCache.POV.FOV = eased;
		}
	}
}

void ResolveProcessEventFunctions()
{
	g_tickAlice = UFunction::FindFunction("Function AliceGame.AlicePlayerController.PlayerTick");
	g_calloutPC = UFunction::FindFunction("Function AliceGame.AlicePlayerController.GetCalloutPlatform");
	g_updateCam = UFunction::FindFunction("Function AliceGame.AlicePlayerCamera.UpdateCamera");
	g_viewportPostRender = UFunction::FindFunction("Function Engine.GameViewportClient.PostRender");

	g_meleeAttack = UFunction::FindFunction("Function AliceGame.AlicePlayerController.MeleeAttack");
	g_weaponAttack = UFunction::FindFunction("Function AliceGame.AlicePlayerController.WeaponAttack");
	g_switchWeaponGroup = UFunction::FindFunction("Function AliceGame.AlicePlayerController.SwitchWeaponGroup");
	g_rightClickAttack = UFunction::FindFunction("Function AliceGame.AlicePlayerController.RightClickAttack");
	g_switchVorpal = UFunction::FindFunction("Function AliceGame.AlicePlayerController.SwitchToVorpalBlade");
	g_switchHobby = UFunction::FindFunction("Function AliceGame.AlicePlayerController.SwitchToHobbyHorse");
	g_switchEyeStaff = UFunction::FindFunction("Function AliceGame.AlicePlayerController.SwitchToEyeStaff");
	g_pcCanFire = UFunction::FindFunction("Function AliceGame.AlicePlayerController.CanFire");
	g_pawnFadeOutWeapon = UFunction::FindFunction("Function AliceGame.AlicePawn.FadeOutWeapon");
	g_pawnClearDelayAttach = UFunction::FindFunction("Function AliceGame.AlicePawn.ClearDelayAttachWeapon");
}

void RefreshDLCWeapon()
{
	AWeapon* w = g_weaponToRefresh;
	if (w)
	{
		g_weaponToRefresh = nullptr;
		((AWeaponForAlice*)w)->ChangeDLCData();
	}
}

int QueryCalloutPlatform()
{
	AAlicePlayerController* pc = g_State.AlicePlayerController;

	if (!pc || !g_calloutPC)
		return 0;

	int platform = 0;
	pc->ProcessEvent(g_calloutPC, &platform, nullptr);
	return platform;
}

void ApplyProcessEventHook()
{
	ProcessEvent = HookHelper::CreateHook((void*)GetAddress(Addr::ProcessEvent), &ProcessEvent_Hook);
}