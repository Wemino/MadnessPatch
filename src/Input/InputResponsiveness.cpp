#include "Common.hpp"
#include "Features.hpp"

using namespace ScriptHelper;

static bool smoothingDisabled = false;

bool LookAccelerationDisabled(AAlicePlayerController* pc)
{
	UPlayerInput* input = pc ? pc->PlayerInput : nullptr;
	if (!input)
		return false;

	return input->bUsingGamepad ? DisableControllerAcceleration : DisableMouseAcceleration;
}

bool MouseSmoothingDisabled()
{
	return smoothingDisabled;
}

// SpeedScale = aTurnElapsedTime / MyAlicePawn.AliceCameraRevolAccelTime, the turn starts at full speed
static void NoLookAcceleration(Site&, Frame* stack, void* result)
{
	if (result && LookAccelerationDisabled(static_cast<AAlicePlayerController*>(stack->Object)))
	{
		*reinterpret_cast<float*>(result) = 1.0f;
	}
}

// if (bEnableMouseSmoothing), read as false without touching the saved setting
static void NoMouseSmoothing(Site&, Frame*, void* result)
{
	if (result)
	{
		*reinterpret_cast<uint32_t*>(result) = 0;
	}
}

// SpeedScale = aTurnElapsedTime / ...
static const Expect turnSpeedUp[] =
{
	{ 0, Token::Divide_FloatFloat },
	{ 1, Token::InstanceVariable, Expect::Member, "aTurnElapsedTime", &AAlicePlayerController::StaticClass },
	{ -9, Token::LocalVariable, Expect::Local, "SpeedScale" },
	{ -10, Token::Let },
};

// SpeedScale = aLookUpElapsedTime / ...
static const Expect lookUpSpeedUp[] =
{
	{ 0, Token::Divide_FloatFloat },
	{ 1, Token::InstanceVariable, Expect::Member, "aLookUpElapsedTime", &AAlicePlayerController::StaticClass },
	{ -9, Token::LocalVariable, Expect::Local, "SpeedScale" },
	{ -10, Token::Let },
};

// if (bEnableMouseSmoothing)
static const Expect mouseSmoothing[] =
{
	{ 0, Token::BoolVariable },
	{ 1, Token::InstanceVariable, Expect::Member, "bEnableMouseSmoothing", &UPlayerInput::StaticClass },
	{ -3, Token::JumpIfNot },
};

static const SiteSpec turnSpeedUpSite = { "Function AliceGame.AlicePlayerController.ModifyRotationSpeed", turnSpeedUp, std::size(turnSpeedUp), &NoLookAcceleration };
static const SiteSpec lookUpSpeedUpSite = { "Function AliceGame.AlicePlayerController.ModifyRotationSpeed", lookUpSpeedUp, std::size(lookUpSpeedUp), &NoLookAcceleration };
static const SiteSpec mouseSmoothingSite = { "Function AliceGame.AlicePlayerInput.PlayerInput", mouseSmoothing, std::size(mouseSmoothing), &NoMouseSmoothing };

void ResolveInputResponsiveness()
{
	if (DisableMouseAcceleration || DisableControllerAcceleration)
	{
		InstallSite(turnSpeedUpSite);
		InstallSite(lookUpSpeedUpSite);
	}

	if (DisableMouseSmoothing)
	{
		smoothingDisabled = InstallSite(mouseSmoothingSite);
	}
}
