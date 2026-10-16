#include "Common.hpp"
#include "Features.hpp"

#include <algorithm>
#include <cctype>

using namespace ScriptHelper;

template <typename T>
static T& Local(Frame* stack, UProperty* local)
{
	return *reinterpret_cast<T*>(stack->Locals + local->Offset);
}

static float GameTime(AActor* actor)
{
	return actor && actor->WorldInfo ? actor->WorldInfo->TimeSeconds : 0.0f;
}

static bool IsRangeMove(uint8_t move)
{
	return move > static_cast<uint8_t>(ESpecialMove::SM_Range_begin) && move < static_cast<uint8_t>(ESpecialMove::SM_Range_end);
}

static bool IsHitReaction(uint8_t move)
{
	return move == static_cast<uint8_t>(ESpecialMove::SM_Combat_GetHurt) || move == static_cast<uint8_t>(ESpecialMove::SM_Combat_GetHurtWhenJump) || move == static_cast<uint8_t>(ESpecialMove::SM_HoverHit);
}

// ---- Lock-on ----

static UProperty* localTargetActor = nullptr;

static bool IsDead(AActor* actor)
{
	if (!actor)
		return false;

	if (actor->IsA(AAliceGameKynapsePawn::StaticClass()))
	{
		APawn* pawn = static_cast<APawn*>(actor);
		return pawn->Health <= 0 || pawn->bDeleteMe;
	}

	return actor->IsA(AGameBreakableActor::StaticClass()) && static_cast<AGameBreakableActor*>(actor)->bPendingDestroySelf;
}

// AlicePlayerController(Killer): the lock on an enemy is let go 5 s after its death only if Alice's controller killed it
static void CreditDeathToAlice(Site&, Frame*, void* result)
{
	AAlicePlayerController* pc = g_State.AlicePlayerController;
	if (!result || *reinterpret_cast<UObject**>(result) || !pc || !pc->MyAlicePawn)
		return;

	*reinterpret_cast<AAlicePlayerController**>(result) = pc;
}

// APC.ClearAllTargets() clears the soft lock, where nobody in view leaves the lock on a dead target
static void DropDeadTarget(Site&, Frame* stack, void*)
{
	auto* manager = static_cast<UTargetingMode_MergeManager*>(stack->Object);
	AAlicePlayerController* pc = manager ? manager->APC : nullptr;
	if (pc && IsDead(pc->TargetingActor))
	{
		pc->ClearTargetInfo();
	}
}

// The target lists aren't updated while aiming: a dead enemy found there isn't selected
static void RefuseDeadTarget(Site&, Frame* stack, void* result)
{
	auto* manager = static_cast<UTargetingMode_MergeManager*>(stack->Object);
	AAlicePlayerController* pc = manager ? manager->APC : nullptr;
	if (!result || *reinterpret_cast<uint32_t*>(result) || !pc || !localTargetActor)
		return;

	AActor* target = Local<AActor*>(stack, localTargetActor);
	if (target && target != pc->TargetingActor && IsDead(target))
	{
		*reinterpret_cast<uint32_t*>(result) = 1;
	}
}

// ---- Ranged weapons ----

constexpr float ResumeMaxHitTime = 10.0f; // game time

static UProperty* localNextMove = nullptr;
static UProperty* localNewMove = nullptr;
static UFunction* fnPawnFadeOutWeapon = nullptr;
static UFunction* fnAttachWeaponToAlice = nullptr;
static UFunction* fnDelayAttachWeapon = nullptr;
static UFunction* fnEyeStaffFirePress = nullptr;
static UFunction* fnTeapotCannonFirePress = nullptr;

static struct
{
	AAliceGamePawn* pawn = nullptr;
	float since = 0.0f;
	AWeaponForAliceRange* stopped = nullptr;
} hit;

static bool InFiringState(AWeapon* weapon)
{
	static const FName windUp("WindUpState"), normalFire("NormalFireState"), rangeFire("AliceWeaponRangeFire");
	return weapon->IsInState(windUp, false) || weapon->IsInState(normalFire, false) || weapon->IsInState(rangeFire, false);
}

static bool FireHeld(AAlicePlayerController* pc)
{
	static const char* const presses[] = { "eyestafffirepress", "teapotcannonfirepress", "rangeweaponfirepress", "rightclickattack" };
	UPlayerInput* input = pc->PlayerInput;
	if (!input)
		return false;

	for (int32_t k = 0; k < input->PressedKeys.size(); k++)
	{
		for (int32_t b = 0; b < input->Bindings.size(); b++)
		{
			if (input->Bindings[b].Name != input->PressedKeys[k])
				continue;

			std::string command = input->Bindings[b].Command.ToString();
			std::transform(command.begin(), command.end(), command.begin(), [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
			for (const char* press : presses)
			{
				if (command.find(press) != std::string::npos)
					return true;
			}
		}
	}

	return false;
}

static void RangedWeaponStopsOnHit(Site&, Frame* stack, void*)
{
	auto* move = static_cast<UAliceSpecialMove*>(stack->Object);
	AAliceGamePawn* pawn = move ? move->PawnOwner : nullptr;
	if (!pawn)
		return;

	AWeapon* weapon = pawn->Weapon;
	hit = {};
	hit.pawn = pawn;
	hit.since = GameTime(pawn);
	if (!weapon || !weapon->IsA(AWeaponForAliceRange::StaticClass()))
		return;

	static const FName active("Active"), pressTimer("PressFireButton"), releaseTimer("ReleaseFireButton"), shotTimer("StartNormalFire");
	auto* rangedWeapon = static_cast<AWeaponForAliceRange*>(weapon);
	const bool firing = InFiringState(weapon);
	const bool pending = weapon->IsTimerActive(pressTimer, nullptr) || weapon->IsTimerActive(releaseTimer, nullptr) || weapon->IsTimerActive(shotTimer, nullptr);
	if (firing)
	{
		weapon->GotoState(active, FName(0), false, false);
	}

	if (pending)
	{
		weapon->ClearTimer(pressTimer, nullptr);
		weapon->ClearTimer(releaseTimer, nullptr);
		weapon->ClearTimer(shotTimer, nullptr);
		rangedWeapon->bSwitchWeaponFire = 0;
		rangedWeapon->bReleasedFireButtonWhilePendingFire = 0;
	}

	if (firing || pending)
	{
		hit.stopped = rangedWeapon;
	}
}

static void FireResumesAfterHit(Site&, Frame* stack, void*)
{
	auto* move = static_cast<UAliceSpecialMove*>(stack->Object);
	AAliceGamePawn* pawn = move ? move->PawnOwner : nullptr;
	AAlicePlayerController* pc = move ? move->PCOwner : nullptr;
	if (!pawn || !localNextMove)
		return;

	const uint8_t next = Local<uint8_t>(stack, localNextMove);
	const bool tracked = hit.pawn == pawn;
	const float length = tracked ? GameTime(pawn) - hit.since : -1.0f;
	AWeaponForAliceRange* stopped = tracked ? hit.stopped : nullptr;
	hit = {};

	static const FName active("Active");
	if (!stopped || next != static_cast<uint8_t>(ESpecialMove::SM_None) || !pc || pawn->Weapon != stopped || length > ResumeMaxHitTime || !FireHeld(pc) || !stopped->IsInState(active, false))
		return;

	if (stopped->IsA(AEyeStaff::StaticClass()))
	{
		pc->EyeStaffFirePress();
	}
	else
	{
		pc->TeapotCannonFirePress();
	}
}

static void RangeMoveWaitsForHit(Site&, Frame* stack, void* result)
{
	auto* pawn = static_cast<AAliceGamePawn*>(stack->Object);
	if (!result || *reinterpret_cast<uint32_t*>(result) || !localNewMove || !pawn || !pawn->IsA(AAlicePawn::StaticClass()))
		return;

	if (IsRangeMove(Local<uint8_t>(stack, localNewMove)) && IsHitReaction(static_cast<uint8_t>(pawn->SpecialMove)))
	{
		*reinterpret_cast<uint32_t*>(result) = 1;
	}
}

static void FireWaitsForHit(Site&, Frame* stack, void* result)
{
	auto* pc = static_cast<AAlicePlayerController*>(stack->Object);
	AAlicePawn* pawn = pc ? pc->MyAlicePawn : nullptr;
	const Frame* caller = stack->PreviousFrame;
	if (!result || !*reinterpret_cast<uint32_t*>(result) || !pawn || !caller || (caller->Node != fnEyeStaffFirePress && caller->Node != fnTeapotCannonFirePress))
		return;

	const uint8_t move = static_cast<uint8_t>(pawn->SpecialMove);
	if (IsHitReaction(move) || move == static_cast<uint8_t>(ESpecialMove::SM_Combat_HitShieldReaction))
	{
		*reinterpret_cast<uint32_t*>(result) = 0;
	}
}

static void GrinderReleased(Site&, Frame* stack, void*)
{
	auto* pc = static_cast<AAlicePlayerController*>(stack->Object);
	AAlicePawn* pawn = pc ? pc->MyAlicePawn : nullptr;
	AWeapon* weapon = pawn ? pawn->Weapon : nullptr;
	if (!weapon || !weapon->IsA(AEyeStaff::StaticClass()))
		return;

	auto* grinder = static_cast<AEyeStaff*>(weapon);
	if (!grinder->bSwitchWeaponFire && !grinder->bReleasedFireButton && !pc->CanFire())
	{
		grinder->bReleasedFireButton = 1;
	}
}

static void JamWaitsForHit(Site&, Frame* stack, void* result)
{
	auto* grinder = static_cast<AEyeStaff*>(stack->Object);
	AActor* instigator = grinder ? grinder->Instigator : nullptr;
	if (!result || !*reinterpret_cast<uint32_t*>(result) || !instigator || !instigator->IsA(AAliceGamePawn::StaticClass()))
		return;

	if (IsHitReaction(static_cast<uint8_t>(static_cast<AAliceGamePawn*>(instigator)->SpecialMove)))
	{
		*reinterpret_cast<uint32_t*>(result) = 0;
	}
}

// ---- Weapon switch ----

static void FadeInKeepsFiring(Site&, Frame* stack, void* result)
{
	auto* weapon = static_cast<AWeapon*>(stack->Object);
	if (!result || !*reinterpret_cast<uint32_t*>(result) || !weapon || !weapon->IsA(AWeaponForAliceRange::StaticClass()))
		return;

	static const FName windUp("WindUpState"), rangeFire("AliceWeaponRangeFire");
	if (weapon->IsInState(windUp, false) || weapon->IsInState(rangeFire, false))
	{
		*reinterpret_cast<uint32_t*>(result) = 0;
	}
}

static void AttachKeepsFiring(Site&, Frame* stack, void* result)
{
	auto* weapon = static_cast<AWeapon*>(stack->Object);
	if (!result || !*reinterpret_cast<uint32_t*>(result) || !weapon || !weapon->IsA(AWeaponForAliceRange::StaticClass()))
		return;

	const Frame* pawnFade = stack->PreviousFrame;
	const Frame* attach = pawnFade ? pawnFade->PreviousFrame : nullptr;
	const Frame* delayed = attach ? attach->PreviousFrame : nullptr;
	if (delayed && pawnFade->Node == fnPawnFadeOutWeapon && attach->Node == fnAttachWeaponToAlice && delayed->Node == fnDelayAttachWeapon && InFiringState(weapon))
	{
		*reinterpret_cast<uint32_t*>(result) = 0;
	}
}

// ---- Sites ----

// APC = AlicePlayerController(Killer)
static const Expect deathCredit[] =
{
	{ 0, Token::DynamicCast },
	{ 9, Token::LocalVariable, Expect::Local, "Killer" },
	{ -9, Token::LocalVariable, Expect::Local, "APC" },
	{ -10, Token::Let },
};

// APC.ClearAllTargets()
static const Expect noTargetInView[] =
{
	{ 0, Token::VirtualFunction, Expect::Name, "ClearAllTargets" },
	{ -20, Token::InstanceVariable, Expect::Member, "APC", &UTargetingMode_MergeManager::StaticClass },
	{ -21, Token::Context },
};

// if (TargetActor == APC.TargetNPCSocket.Pawn && APC.TargetNPCSocket.SocketIndex == SocketID) return false
static const Expect selectedAgain[] =
{
	{ 0, Token::AndAnd_BoolBool },
	{ 1, Token::EqualEqual_ObjectObject },
	{ 2, Token::LocalVariable, Expect::Local, "TargetActor" },
	{ 30, Token::Context },
	{ 31, Token::InstanceVariable, Expect::Member, "APC", &UTargetingMode_MergeManager::StaticClass },
	{ -3, Token::JumpIfNot },
};

// WeaponForAlice(PawnOwner.Weapon).ClearAllFireTimers()
static const Expect hurtStarts[] =
{
	{ 0, Token::VirtualFunction, Expect::Name, "ClearAllFireTimers" },
	{ -51, Token::Context },
};

// the final return
static const Expect hurtEnds[] =
{
	{ 0, Token::Nothing },
	{ -1, Token::Return },
	{ 1, Token::EndOfScript },
};

// if (NewMove == SpecialMove && ...)
static const Expect sameMove[] =
{
	{ 0, Token::AndAnd_BoolBool },
	{ 1, Token::EqualEqual_ByteByte },
	{ 2, Token::PrimitiveCast },
	{ 4, Token::LocalVariable, Expect::Local, "NewMove" },
	{ -3, Token::JumpIfNot },
};

// wpn.CanPerformNextAction()
static const Expect comboWindow[] =
{
	{ 0, Token::VirtualFunction, Expect::Name, "CanPerformNextAction" },
	{ -20, Token::LocalVariable, Expect::Local, "Wpn" },
	{ -21, Token::Context },
};

// if (IsMeleeCharging()) return
static const Expect padRelease[] =
{
	{ 0, Token::VirtualFunction, Expect::Name, "IsMeleeCharging" },
	{ -3, Token::JumpIfNot },
};

// !AlicePawn(Instigator).IsDoingSpecialMove(SM_EyeStaffNoAmmo)
static const Expect jamNotPlaying[] =
{
	{ 0, Token::Not_PreBool },
	{ 1, Token::Context },
	{ 2, Token::DynamicCast },
	{ 11, Token::InstanceVariable, Expect::Member, "Instigator", &AActor::StaticClass },
	{ 40, Token::ByteConst },
};

// !IsInState('NormalFireState')
static const Expect fadeInNotFiring[] =
{
	{ 0, Token::Not_PreBool },
	{ 3, Token::NameConst, Expect::Name, "NormalFireState" },
};

// !IsInState('Inactive')
static const Expect fadeOutNotInactive[] =
{
	{ 0, Token::Not_PreBool },
	{ 3, Token::NameConst, Expect::Name, "Inactive" },
};

static const SiteSpec scriptFixes[] =
{
	{ "Function AliceGame.AliceGameKynapsePawn.NotifyDied", deathCredit, std::size(deathCredit), &CreditDeathToAlice },
	{ "Function AliceGame.TargetingMode_MergeManager.DetermineFirstTarget", noTargetInView, std::size(noTargetInView), &DropDeadTarget },
	{ "Function AliceGame.TargetingMode_MergeManager.ChooseByPotentialField", noTargetInView, std::size(noTargetInView), &DropDeadTarget },
	{ "Function AliceGame.TargetingMode_MergeManager.SelectTarget", selectedAgain, std::size(selectedAgain), &RefuseDeadTarget },
	{ "Function AliceGame.ASM_GetHurt.SpecialMoveStarted", hurtStarts, std::size(hurtStarts), &RangedWeaponStopsOnHit },
	{ "Function AliceGame.ASM_GetHurt.SpecialMoveEnded", hurtEnds, std::size(hurtEnds), &FireResumesAfterHit },
	{ "Function AliceGame.AliceGamePawn.DoSpecialMove", sameMove, std::size(sameMove), &RangeMoveWaitsForHit },
	{ "Function AliceGame.AlicePlayerController.CanFire", comboWindow, std::size(comboWindow), &FireWaitsForHit },
	{ "Function AliceGame.AlicePlayerController.EyeStaffFireRelease", padRelease, std::size(padRelease), &GrinderReleased },
	{ "Function AliceGame.EyeStaff.WeaponOverHeatState.Tick", jamNotPlaying, std::size(jamNotPlaying), &JamWaitsForHit },
	{ "Function AliceGame.WeaponForAlice.FadeInWeapon", fadeInNotFiring, std::size(fadeInNotFiring), &FadeInKeepsFiring },
	{ "Function AliceGame.WeaponForAlice.FadeOutWeapon", fadeOutNotInactive, std::size(fadeOutNotInactive), &AttachKeepsFiring },
};

void ResolveScriptFixes()
{
	if (!ScriptFixes) return;

	UFunction* fnSelectTarget = UFunction::FindFunction("Function AliceGame.TargetingMode_MergeManager.SelectTarget");
	UFunction* fnHurtEnded = UFunction::FindFunction("Function AliceGame.ASM_GetHurt.SpecialMoveEnded");
	UFunction* fnDoSpecialMove = UFunction::FindFunction("Function AliceGame.AliceGamePawn.DoSpecialMove");
	localTargetActor = fnSelectTarget ? FindProperty(fnSelectTarget, "TargetActor", false) : nullptr;
	localNextMove = fnHurtEnded ? FindProperty(fnHurtEnded, "NextMove", false) : nullptr;
	localNewMove = fnDoSpecialMove ? FindProperty(fnDoSpecialMove, "NewMove", false) : nullptr;
	fnPawnFadeOutWeapon = UFunction::FindFunction("Function AliceGame.AlicePawn.FadeOutWeapon");
	fnAttachWeaponToAlice = UFunction::FindFunction("Function AliceGame.AliceGameWeapon.AttachWeaponToAlice");
	fnDelayAttachWeapon = UFunction::FindFunction("Function AliceGame.AlicePawn.DelayAttachWeapon");
	fnEyeStaffFirePress = UFunction::FindFunction("Function AliceGame.AlicePlayerController.EyeStaffFirePress");
	fnTeapotCannonFirePress = UFunction::FindFunction("Function AliceGame.AlicePlayerController.TeapotCannonFirePress");

	for (const SiteSpec& spec : scriptFixes)
	{
		InstallSite(spec);
	}
}
