/*
#############################################################################################
# Alice2 (ASDK) SDK 1.0.0.0
# Generated with the CodeRedGenerator v1.2.0
# ========================================================================================= #
# File: Kynapse_classes.cpp
# ========================================================================================= #
# Credits: ItsBranK, TheFeckless
# Links: www.github.com/CodeRedModding/CodeRed-Generator
#############################################################################################
*/
#include "../SdkHeaders.hpp"

#ifdef _MSC_VER
#pragma pack(push, 0x4)
#endif

/*
# ========================================================================================= #
# Functions
# ========================================================================================= #
*/

// Function Kynapse.KynapseAIController.OnAIFollow
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class USeqAct_AIFollow*        Action                         (CPF_Parm)

void AKynapseAIController::OnAIFollow(class USeqAct_AIFollow* Action)
{
	static UFunction* uFnOnAIFollow = nullptr;

	if (!uFnOnAIFollow)
	{
		uFnOnAIFollow = UFunction::FindFunction("Function Kynapse.KynapseAIController.OnAIFollow");
	}

	AKynapseAIController_execOnAIFollow_Params OnAIFollow_Params;
	memset(&OnAIFollow_Params, 0, sizeof(OnAIFollow_Params));

	if (!uFnOnAIFollow)
	{
		return;
	}
	OnAIFollow_Params.Action = Action;

	this->ProcessEvent(uFnOnAIFollow, &OnAIFollow_Params, nullptr);
}

// Function Kynapse.KynapseAIController.OnAIShoot
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class USeqAct_AIShoot*         Action                         (CPF_Parm)

void AKynapseAIController::OnAIShoot(class USeqAct_AIShoot* Action)
{
	static UFunction* uFnOnAIShoot = nullptr;

	if (!uFnOnAIShoot)
	{
		uFnOnAIShoot = UFunction::FindFunction("Function Kynapse.KynapseAIController.OnAIShoot");
	}

	AKynapseAIController_execOnAIShoot_Params OnAIShoot_Params;
	memset(&OnAIShoot_Params, 0, sizeof(OnAIShoot_Params));

	if (!uFnOnAIShoot)
	{
		return;
	}
	OnAIShoot_Params.Action = Action;

	this->ProcessEvent(uFnOnAIShoot, &OnAIShoot_Params, nullptr);
}

// Function Kynapse.KynapseAIController.OnAIHide
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class USeqAct_AIHide*          Action                         (CPF_Parm)

void AKynapseAIController::OnAIHide(class USeqAct_AIHide* Action)
{
	static UFunction* uFnOnAIHide = nullptr;

	if (!uFnOnAIHide)
	{
		uFnOnAIHide = UFunction::FindFunction("Function Kynapse.KynapseAIController.OnAIHide");
	}

	AKynapseAIController_execOnAIHide_Params OnAIHide_Params;
	memset(&OnAIHide_Params, 0, sizeof(OnAIHide_Params));

	if (!uFnOnAIHide)
	{
		return;
	}
	OnAIHide_Params.Action = Action;

	this->ProcessEvent(uFnOnAIHide, &OnAIHide_Params, nullptr);
}

// Function Kynapse.KynapseAIController.OnAIFlee
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class USeqAct_AIFlee*          Action                         (CPF_Parm)

void AKynapseAIController::OnAIFlee(class USeqAct_AIFlee* Action)
{
	static UFunction* uFnOnAIFlee = nullptr;

	if (!uFnOnAIFlee)
	{
		uFnOnAIFlee = UFunction::FindFunction("Function Kynapse.KynapseAIController.OnAIFlee");
	}

	AKynapseAIController_execOnAIFlee_Params OnAIFlee_Params;
	memset(&OnAIFlee_Params, 0, sizeof(OnAIFlee_Params));

	if (!uFnOnAIFlee)
	{
		return;
	}
	OnAIFlee_Params.Action = Action;

	this->ProcessEvent(uFnOnAIFlee, &OnAIFlee_Params, nullptr);
}

// Function Kynapse.KynapseAIController.OnAIWander
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class USeqAct_AIWander*        Action                         (CPF_Parm)

void AKynapseAIController::OnAIWander(class USeqAct_AIWander* Action)
{
	static UFunction* uFnOnAIWander = nullptr;

	if (!uFnOnAIWander)
	{
		uFnOnAIWander = UFunction::FindFunction("Function Kynapse.KynapseAIController.OnAIWander");
	}

	AKynapseAIController_execOnAIWander_Params OnAIWander_Params;
	memset(&OnAIWander_Params, 0, sizeof(OnAIWander_Params));

	if (!uFnOnAIWander)
	{
		return;
	}
	OnAIWander_Params.Action = Action;

	this->ProcessEvent(uFnOnAIWander, &OnAIWander_Params, nullptr);
}

// Function Kynapse.KynapseAIController.Possess
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class APawn*                   aPawn                          (CPF_Parm)
// uint32_t                       bVehicleTransition             (CPF_Parm)

void AKynapseAIController::Possess(class APawn* aPawn, bool bVehicleTransition)
{
	static UFunction* uFnPossess = nullptr;

	if (!uFnPossess)
	{
		uFnPossess = UFunction::FindFunction("Function Kynapse.KynapseAIController.Possess");
	}

	AKynapseAIController_execPossess_Params Possess_Params;
	memset(&Possess_Params, 0, sizeof(Possess_Params));

	if (!uFnPossess)
	{
		return;
	}
	Possess_Params.aPawn = aPawn;
	Possess_Params.bVehicleTransition = bVehicleTransition;

	this->ProcessEvent(uFnPossess, &Possess_Params, nullptr);
}

// Function Kynapse.KynapseAIController.KynapseFollow
// [0x00020408] (FUNC_Latent | FUNC_Native | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class AActor*                  TargetEntity                   (CPF_Parm)
// float                          Duration                       (CPF_Parm)

bool AKynapseAIController::KynapseFollow(class AActor* TargetEntity, float Duration)
{
	static UFunction* uFnKynapseFollow = nullptr;

	if (!uFnKynapseFollow)
	{
		uFnKynapseFollow = UFunction::FindFunction("Function Kynapse.KynapseAIController.KynapseFollow");
	}

	AKynapseAIController_execKynapseFollow_Params KynapseFollow_Params;
	memset(&KynapseFollow_Params, 0, sizeof(KynapseFollow_Params));

	if (!uFnKynapseFollow)
	{
		return KynapseFollow_Params.ReturnValue;
	}
	KynapseFollow_Params.TargetEntity = TargetEntity;
	KynapseFollow_Params.Duration = Duration;

	return KynapseFollow_Params.ReturnValue;
}

// Function Kynapse.KynapseAIController.KynapseShoot
// [0x00020408] (FUNC_Latent | FUNC_Native | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class AActor*                  TargetEntity                   (CPF_Parm)
// float                          Duration                       (CPF_Parm)

bool AKynapseAIController::KynapseShoot(class AActor* TargetEntity, float Duration)
{
	static UFunction* uFnKynapseShoot = nullptr;

	if (!uFnKynapseShoot)
	{
		uFnKynapseShoot = UFunction::FindFunction("Function Kynapse.KynapseAIController.KynapseShoot");
	}

	AKynapseAIController_execKynapseShoot_Params KynapseShoot_Params;
	memset(&KynapseShoot_Params, 0, sizeof(KynapseShoot_Params));

	if (!uFnKynapseShoot)
	{
		return KynapseShoot_Params.ReturnValue;
	}
	KynapseShoot_Params.TargetEntity = TargetEntity;
	KynapseShoot_Params.Duration = Duration;

	return KynapseShoot_Params.ReturnValue;
}

// Function Kynapse.KynapseAIController.KynapseHide
// [0x00020408] (FUNC_Latent | FUNC_Native | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          Duration                       (CPF_Parm)

bool AKynapseAIController::KynapseHide(float Duration)
{
	static UFunction* uFnKynapseHide = nullptr;

	if (!uFnKynapseHide)
	{
		uFnKynapseHide = UFunction::FindFunction("Function Kynapse.KynapseAIController.KynapseHide");
	}

	AKynapseAIController_execKynapseHide_Params KynapseHide_Params;
	memset(&KynapseHide_Params, 0, sizeof(KynapseHide_Params));

	if (!uFnKynapseHide)
	{
		return KynapseHide_Params.ReturnValue;
	}
	KynapseHide_Params.Duration = Duration;

	return KynapseHide_Params.ReturnValue;
}

// Function Kynapse.KynapseAIController.KynapseFlee
// [0x00020408] (FUNC_Latent | FUNC_Native | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          Duration                       (CPF_Parm)

bool AKynapseAIController::KynapseFlee(float Duration)
{
	static UFunction* uFnKynapseFlee = nullptr;

	if (!uFnKynapseFlee)
	{
		uFnKynapseFlee = UFunction::FindFunction("Function Kynapse.KynapseAIController.KynapseFlee");
	}

	AKynapseAIController_execKynapseFlee_Params KynapseFlee_Params;
	memset(&KynapseFlee_Params, 0, sizeof(KynapseFlee_Params));

	if (!uFnKynapseFlee)
	{
		return KynapseFlee_Params.ReturnValue;
	}
	KynapseFlee_Params.Duration = Duration;

	return KynapseFlee_Params.ReturnValue;
}

// Function Kynapse.KynapseAIController.KynapseWander
// [0x00020408] (FUNC_Latent | FUNC_Native | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          Duration                       (CPF_Parm)

bool AKynapseAIController::KynapseWander(float Duration)
{
	static UFunction* uFnKynapseWander = nullptr;

	if (!uFnKynapseWander)
	{
		uFnKynapseWander = UFunction::FindFunction("Function Kynapse.KynapseAIController.KynapseWander");
	}

	AKynapseAIController_execKynapseWander_Params KynapseWander_Params;
	memset(&KynapseWander_Params, 0, sizeof(KynapseWander_Params));

	if (!uFnKynapseWander)
	{
		return KynapseWander_Params.ReturnValue;
	}
	KynapseWander_Params.Duration = Duration;

	return KynapseWander_Params.ReturnValue;
}

// Function Kynapse.KynapseAIController.KynapseGoTo
// [0x00020408] (FUNC_Latent | FUNC_Native | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 KynapseDestination             (CPF_Parm)

bool AKynapseAIController::KynapseGoTo(const struct FVector& KynapseDestination)
{
	static UFunction* uFnKynapseGoTo = nullptr;

	if (!uFnKynapseGoTo)
	{
		uFnKynapseGoTo = UFunction::FindFunction("Function Kynapse.KynapseAIController.KynapseGoTo");
	}

	AKynapseAIController_execKynapseGoTo_Params KynapseGoTo_Params;
	memset(&KynapseGoTo_Params, 0, sizeof(KynapseGoTo_Params));

	if (!uFnKynapseGoTo)
	{
		return KynapseGoTo_Params.ReturnValue;
	}
	memcpy_s(&KynapseGoTo_Params.KynapseDestination, sizeof(KynapseGoTo_Params.KynapseDestination), &KynapseDestination, sizeof(KynapseDestination));

	return KynapseGoTo_Params.ReturnValue;
}

// Function Kynapse.KynapseAIController.SetBrainState
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// int32_t                        Set                            (CPF_Parm)

void AKynapseAIController::SetBrainState(int32_t Set)
{
	static UFunction* uFnSetBrainState = nullptr;

	if (!uFnSetBrainState)
	{
		uFnSetBrainState = UFunction::FindFunction("Function Kynapse.KynapseAIController.SetBrainState");
	}

	AKynapseAIController_execSetBrainState_Params SetBrainState_Params;
	memset(&SetBrainState_Params, 0, sizeof(SetBrainState_Params));

	if (!uFnSetBrainState)
	{
		return;
	}
	SetBrainState_Params.Set = Set;

	uint16_t nativeIndex = uFnSetBrainState->iNative;
	uFnSetBrainState->iNative = 0;
	this->ProcessEvent(uFnSetBrainState, &SetBrainState_Params, nullptr);
	uFnSetBrainState->iNative = nativeIndex;
}

// Function Kynapse.KynapseAIController.GetBrainState
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

int32_t AKynapseAIController::GetBrainState()
{
	static UFunction* uFnGetBrainState = nullptr;

	if (!uFnGetBrainState)
	{
		uFnGetBrainState = UFunction::FindFunction("Function Kynapse.KynapseAIController.GetBrainState");
	}

	AKynapseAIController_execGetBrainState_Params GetBrainState_Params;
	memset(&GetBrainState_Params, 0, sizeof(GetBrainState_Params));

	if (!uFnGetBrainState)
	{
		return GetBrainState_Params.ReturnValue;
	}

	uint16_t nativeIndex = uFnGetBrainState->iNative;
	uFnGetBrainState->iNative = 0;
	this->ProcessEvent(uFnGetBrainState, &GetBrainState_Params, nullptr);
	uFnGetBrainState->iNative = nativeIndex;

	return GetBrainState_Params.ReturnValue;
}

// Function Kynapse.KynapseAIController.ActivateKynapseBrain
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// uint32_t                       Activate                       (CPF_Parm)

void AKynapseAIController::ActivateKynapseBrain(bool Activate)
{
	static UFunction* uFnActivateKynapseBrain = nullptr;

	if (!uFnActivateKynapseBrain)
	{
		uFnActivateKynapseBrain = UFunction::FindFunction("Function Kynapse.KynapseAIController.ActivateKynapseBrain");
	}

	AKynapseAIController_execActivateKynapseBrain_Params ActivateKynapseBrain_Params;
	memset(&ActivateKynapseBrain_Params, 0, sizeof(ActivateKynapseBrain_Params));

	if (!uFnActivateKynapseBrain)
	{
		return;
	}
	ActivateKynapseBrain_Params.Activate = Activate;

	uint16_t nativeIndex = uFnActivateKynapseBrain->iNative;
	uFnActivateKynapseBrain->iNative = 0;
	this->ProcessEvent(uFnActivateKynapseBrain, &ActivateKynapseBrain_Params, nullptr);
	uFnActivateKynapseBrain->iNative = nativeIndex;
}

// Function Kynapse.KynapseAIController.KynapseHasArrived
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 Dest                           (CPF_Parm)

bool AKynapseAIController::KynapseHasArrived(const struct FVector& Dest)
{
	static UFunction* uFnKynapseHasArrived = nullptr;

	if (!uFnKynapseHasArrived)
	{
		uFnKynapseHasArrived = UFunction::FindFunction("Function Kynapse.KynapseAIController.KynapseHasArrived");
	}

	AKynapseAIController_execKynapseHasArrived_Params KynapseHasArrived_Params;
	memset(&KynapseHasArrived_Params, 0, sizeof(KynapseHasArrived_Params));

	if (!uFnKynapseHasArrived)
	{
		return KynapseHasArrived_Params.ReturnValue;
	}
	memcpy_s(&KynapseHasArrived_Params.Dest, sizeof(KynapseHasArrived_Params.Dest), &Dest, sizeof(Dest));

	uint16_t nativeIndex = uFnKynapseHasArrived->iNative;
	uFnKynapseHasArrived->iNative = 0;
	this->ProcessEvent(uFnKynapseHasArrived, &KynapseHasArrived_Params, nullptr);
	uFnKynapseHasArrived->iNative = nativeIndex;

	return KynapseHasArrived_Params.ReturnValue;
}

// Function Kynapse.KynapseAIController.HearNoise
// [0x00024802] (FUNC_Defined | FUNC_Event | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// float                          Loudness                       (CPF_Parm)
// class AActor*                  NoiseMaker                     (CPF_Parm)
// class FName                    NoiseType                      (CPF_OptionalParm | CPF_Parm)

void AKynapseAIController::eventHearNoise(float Loudness, class AActor* NoiseMaker, const class FName& optionalNoiseType)
{
	static UFunction* uFnHearNoise = nullptr;

	if (!uFnHearNoise)
	{
		uFnHearNoise = UFunction::FindFunction("Function Kynapse.KynapseAIController.HearNoise");
	}

	AKynapseAIController_eventHearNoise_Params HearNoise_Params;
	memset(&HearNoise_Params, 0, sizeof(HearNoise_Params));

	if (!uFnHearNoise)
	{
		return;
	}
	HearNoise_Params.Loudness = Loudness;
	HearNoise_Params.NoiseMaker = NoiseMaker;
	memcpy_s(&HearNoise_Params.NoiseType, sizeof(HearNoise_Params.NoiseType), &optionalNoiseType, sizeof(optionalNoiseType));

	this->ProcessEvent(uFnHearNoise, &HearNoise_Params, nullptr);
}

// Function Kynapse.KynapseExclusionVolume.StopsProjectile
// [0x00020102] (FUNC_Defined | FUNC_Simulated | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class AProjectile*             P                              (CPF_Parm)

bool AKynapseExclusionVolume::StopsProjectile(class AProjectile* P)
{
	static UFunction* uFnStopsProjectile = nullptr;

	if (!uFnStopsProjectile)
	{
		uFnStopsProjectile = UFunction::FindFunction("Function Kynapse.KynapseExclusionVolume.StopsProjectile");
	}

	AKynapseExclusionVolume_execStopsProjectile_Params StopsProjectile_Params;
	memset(&StopsProjectile_Params, 0, sizeof(StopsProjectile_Params));

	if (!uFnStopsProjectile)
	{
		return StopsProjectile_Params.ReturnValue;
	}
	StopsProjectile_Params.P = P;

	this->ProcessEvent(uFnStopsProjectile, &StopsProjectile_Params, nullptr);

	return StopsProjectile_Params.ReturnValue;
}

// Function Kynapse.KynapseHandle.RegisterToProfile
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// class FString                  ProfileName                    (CPF_Parm | CPF_CoerceParm | CPF_NeedCtorLink)

void UKynapseHandle::RegisterToProfile(const class FString& ProfileName)
{
	static UFunction* uFnRegisterToProfile = nullptr;

	if (!uFnRegisterToProfile)
	{
		uFnRegisterToProfile = UFunction::FindFunction("Function Kynapse.KynapseHandle.RegisterToProfile");
	}

	UKynapseHandle_execRegisterToProfile_Params RegisterToProfile_Params;
	memset(&RegisterToProfile_Params, 0, sizeof(RegisterToProfile_Params));

	if (!uFnRegisterToProfile)
	{
		return;
	}
	memcpy_s(&RegisterToProfile_Params.ProfileName, sizeof(RegisterToProfile_Params.ProfileName), &ProfileName, sizeof(ProfileName));

	uint16_t nativeIndex = uFnRegisterToProfile->iNative;
	uFnRegisterToProfile->iNative = 0;
	this->ProcessEvent(uFnRegisterToProfile, &RegisterToProfile_Params, nullptr);
	uFnRegisterToProfile->iNative = nativeIndex;
}

// Function Kynapse.KynapseHandle.AddKynapseEntity
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:

void UKynapseHandle::AddKynapseEntity()
{
	static UFunction* uFnAddKynapseEntity = nullptr;

	if (!uFnAddKynapseEntity)
	{
		uFnAddKynapseEntity = UFunction::FindFunction("Function Kynapse.KynapseHandle.AddKynapseEntity");
	}

	UKynapseHandle_execAddKynapseEntity_Params AddKynapseEntity_Params;
	memset(&AddKynapseEntity_Params, 0, sizeof(AddKynapseEntity_Params));

	if (!uFnAddKynapseEntity)
	{
		return;
	}

	uint16_t nativeIndex = uFnAddKynapseEntity->iNative;
	uFnAddKynapseEntity->iNative = 0;
	this->ProcessEvent(uFnAddKynapseEntity, &AddKynapseEntity_Params, nullptr);
	uFnAddKynapseEntity->iNative = nativeIndex;
}

// Function Kynapse.KynapseHandle.InitKynapseEntity
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:

void UKynapseHandle::InitKynapseEntity()
{
	static UFunction* uFnInitKynapseEntity = nullptr;

	if (!uFnInitKynapseEntity)
	{
		uFnInitKynapseEntity = UFunction::FindFunction("Function Kynapse.KynapseHandle.InitKynapseEntity");
	}

	UKynapseHandle_execInitKynapseEntity_Params InitKynapseEntity_Params;
	memset(&InitKynapseEntity_Params, 0, sizeof(InitKynapseEntity_Params));

	if (!uFnInitKynapseEntity)
	{
		return;
	}

	uint16_t nativeIndex = uFnInitKynapseEntity->iNative;
	uFnInitKynapseEntity->iNative = 0;
	this->ProcessEvent(uFnInitKynapseEntity, &InitKynapseEntity_Params, nullptr);
	uFnInitKynapseEntity->iNative = nativeIndex;
}

// Function Kynapse.KynapseLadderVolume.PostBeginPlay
// [0x00820902] (FUNC_Defined | FUNC_Simulated | FUNC_Event | FUNC_Public | FUNC_HasDefaults)
// Parameter Info:

void AKynapseLadderVolume::eventPostBeginPlay()
{
	static UFunction* uFnPostBeginPlay = nullptr;

	if (!uFnPostBeginPlay)
	{
		uFnPostBeginPlay = UFunction::FindFunction("Function Kynapse.KynapseLadderVolume.PostBeginPlay");
	}

	AKynapseLadderVolume_eventPostBeginPlay_Params PostBeginPlay_Params;
	memset(&PostBeginPlay_Params, 0, sizeof(PostBeginPlay_Params));

	if (!uFnPostBeginPlay)
	{
		return;
	}

	this->ProcessEvent(uFnPostBeginPlay, &PostBeginPlay_Params, nullptr);
}

// Function Kynapse.KynapseObstacleFractured.Explode
// [0x00020902] (FUNC_Defined | FUNC_Simulated | FUNC_Event | FUNC_Public)
// Parameter Info:

void AKynapseObstacleFractured::eventExplode()
{
	static UFunction* uFnExplode = nullptr;

	if (!uFnExplode)
	{
		uFnExplode = UFunction::FindFunction("Function Kynapse.KynapseObstacleFractured.Explode");
	}

	AKynapseObstacleFractured_eventExplode_Params Explode_Params;
	memset(&Explode_Params, 0, sizeof(Explode_Params));

	if (!uFnExplode)
	{
		return;
	}

	this->ProcessEvent(uFnExplode, &Explode_Params, nullptr);
}

// Function Kynapse.KynapseObstacleFractured.TakeDamage
// [0x00024902] (FUNC_Defined | FUNC_Simulated | FUNC_Event | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// int32_t                        Damage                         (CPF_Parm)
// class AController*             EventInstigator                (CPF_Parm)
// struct FVector                 HitLocation                    (CPF_Parm)
// struct FVector                 Momentum                       (CPF_Parm)
// class UClass*                  DamageType                     (CPF_Parm)
// struct FTraceHitInfo           HitInfo                        (CPF_OptionalParm | CPF_Parm)
// class AActor*                  DamageCauser                   (CPF_OptionalParm | CPF_Parm)

void AKynapseObstacleFractured::eventTakeDamage(int32_t Damage, class AController* EventInstigator, const struct FVector& HitLocation, const struct FVector& Momentum, class UClass* DamageType, const struct FTraceHitInfo& optionalHitInfo, class AActor* optionalDamageCauser)
{
	static UFunction* uFnTakeDamage = nullptr;

	if (!uFnTakeDamage)
	{
		uFnTakeDamage = UFunction::FindFunction("Function Kynapse.KynapseObstacleFractured.TakeDamage");
	}

	AKynapseObstacleFractured_eventTakeDamage_Params TakeDamage_Params;
	memset(&TakeDamage_Params, 0, sizeof(TakeDamage_Params));

	if (!uFnTakeDamage)
	{
		return;
	}
	TakeDamage_Params.Damage = Damage;
	TakeDamage_Params.EventInstigator = EventInstigator;
	memcpy_s(&TakeDamage_Params.HitLocation, sizeof(TakeDamage_Params.HitLocation), &HitLocation, sizeof(HitLocation));
	memcpy_s(&TakeDamage_Params.Momentum, sizeof(TakeDamage_Params.Momentum), &Momentum, sizeof(Momentum));
	TakeDamage_Params.DamageType = DamageType;
	memcpy_s(&TakeDamage_Params.HitInfo, sizeof(TakeDamage_Params.HitInfo), &optionalHitInfo, sizeof(optionalHitInfo));
	TakeDamage_Params.DamageCauser = optionalDamageCauser;

	this->ProcessEvent(uFnTakeDamage, &TakeDamage_Params, nullptr);
}

// Function Kynapse.KynapsePawn.OnAnimEnd
// [0x00020802] (FUNC_Defined | FUNC_Event | FUNC_Public)
// Parameter Info:
// class UAnimNodeSequence*       SeqNode                        (CPF_Parm)
// float                          PlayedTime                     (CPF_Parm)
// float                          ExcessTime                     (CPF_Parm)

void AKynapsePawn::eventOnAnimEnd(class UAnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime)
{
	static UFunction* uFnOnAnimEnd = nullptr;

	if (!uFnOnAnimEnd)
	{
		uFnOnAnimEnd = UFunction::FindFunction("Function Kynapse.KynapsePawn.OnAnimEnd");
	}

	AKynapsePawn_eventOnAnimEnd_Params OnAnimEnd_Params;
	memset(&OnAnimEnd_Params, 0, sizeof(OnAnimEnd_Params));

	if (!uFnOnAnimEnd)
	{
		return;
	}
	OnAnimEnd_Params.SeqNode = SeqNode;
	OnAnimEnd_Params.PlayedTime = PlayedTime;
	OnAnimEnd_Params.ExcessTime = ExcessTime;

	this->ProcessEvent(uFnOnAnimEnd, &OnAnimEnd_Params, nullptr);
}

// Function Kynapse.KynapsePawn.Bump
// [0x00020802] (FUNC_Defined | FUNC_Event | FUNC_Public)
// Parameter Info:
// class AActor*                  Other                          (CPF_Parm)
// class UPrimitiveComponent*     OtherComp                      (CPF_Parm | CPF_EditInline)
// struct FVector                 HitNormal                      (CPF_Parm)

void AKynapsePawn::eventBump(class AActor* Other, class UPrimitiveComponent* OtherComp, const struct FVector& HitNormal)
{
	static UFunction* uFnBump = nullptr;

	if (!uFnBump)
	{
		uFnBump = UFunction::FindFunction("Function Kynapse.KynapsePawn.Bump");
	}

	AKynapsePawn_eventBump_Params Bump_Params;
	memset(&Bump_Params, 0, sizeof(Bump_Params));

	if (!uFnBump)
	{
		return;
	}
	Bump_Params.Other = Other;
	Bump_Params.OtherComp = OtherComp;
	memcpy_s(&Bump_Params.HitNormal, sizeof(Bump_Params.HitNormal), &HitNormal, sizeof(HitNormal));

	this->ProcessEvent(uFnBump, &Bump_Params, nullptr);
}

// Function Kynapse.KynapsePawn.SphinxAnimEnd
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// class UAnimNodeSequence*       SeqNode                        (CPF_Parm)
// float                          PlayedTime                     (CPF_Parm)
// float                          ExcessTime                     (CPF_Parm)

void AKynapsePawn::SphinxAnimEnd(class UAnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime)
{
	static UFunction* uFnSphinxAnimEnd = nullptr;

	if (!uFnSphinxAnimEnd)
	{
		uFnSphinxAnimEnd = UFunction::FindFunction("Function Kynapse.KynapsePawn.SphinxAnimEnd");
	}

	AKynapsePawn_execSphinxAnimEnd_Params SphinxAnimEnd_Params;
	memset(&SphinxAnimEnd_Params, 0, sizeof(SphinxAnimEnd_Params));

	if (!uFnSphinxAnimEnd)
	{
		return;
	}
	SphinxAnimEnd_Params.SeqNode = SeqNode;
	SphinxAnimEnd_Params.PlayedTime = PlayedTime;
	SphinxAnimEnd_Params.ExcessTime = ExcessTime;

	uint16_t nativeIndex = uFnSphinxAnimEnd->iNative;
	uFnSphinxAnimEnd->iNative = 0;
	this->ProcessEvent(uFnSphinxAnimEnd, &SphinxAnimEnd_Params, nullptr);
	uFnSphinxAnimEnd->iNative = nativeIndex;
}

// Function Kynapse.KynapseTeamCreationData.PostInitializeTeam
// [0x00020400] (FUNC_Native | FUNC_Public)
// Parameter Info:

void UKynapseTeamCreationData::PostInitializeTeam()
{
	static UFunction* uFnPostInitializeTeam = nullptr;

	if (!uFnPostInitializeTeam)
	{
		uFnPostInitializeTeam = UFunction::FindFunction("Function Kynapse.KynapseTeamCreationData.PostInitializeTeam");
	}

	UKynapseTeamCreationData_execPostInitializeTeam_Params PostInitializeTeam_Params;
	memset(&PostInitializeTeam_Params, 0, sizeof(PostInitializeTeam_Params));

	if (!uFnPostInitializeTeam)
	{
		return;
	}

	uint16_t nativeIndex = uFnPostInitializeTeam->iNative;
	uFnPostInitializeTeam->iNative = 0;
	this->ProcessEvent(uFnPostInitializeTeam, &PostInitializeTeam_Params, nullptr);
	uFnPostInitializeTeam->iNative = nativeIndex;
}

// Function Kynapse.KynapseTeamCreationData.CreateKynapseTeam
// [0x00020400] (FUNC_Native | FUNC_Public)
// Parameter Info:

void UKynapseTeamCreationData::CreateKynapseTeam()
{
	static UFunction* uFnCreateKynapseTeam = nullptr;

	if (!uFnCreateKynapseTeam)
	{
		uFnCreateKynapseTeam = UFunction::FindFunction("Function Kynapse.KynapseTeamCreationData.CreateKynapseTeam");
	}

	UKynapseTeamCreationData_execCreateKynapseTeam_Params CreateKynapseTeam_Params;
	memset(&CreateKynapseTeam_Params, 0, sizeof(CreateKynapseTeam_Params));

	if (!uFnCreateKynapseTeam)
	{
		return;
	}

	uint16_t nativeIndex = uFnCreateKynapseTeam->iNative;
	uFnCreateKynapseTeam->iNative = 0;
	this->ProcessEvent(uFnCreateKynapseTeam, &CreateKynapseTeam_Params, nullptr);
	uFnCreateKynapseTeam->iNative = nativeIndex;
}

// Function Kynapse.SphinxInterstingPoint.ShowRadius
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:

void ASphinxInterstingPoint::ShowRadius()
{
	static UFunction* uFnShowRadius = nullptr;

	if (!uFnShowRadius)
	{
		uFnShowRadius = UFunction::FindFunction("Function Kynapse.SphinxInterstingPoint.ShowRadius");
	}

	ASphinxInterstingPoint_execShowRadius_Params ShowRadius_Params;
	memset(&ShowRadius_Params, 0, sizeof(ShowRadius_Params));

	if (!uFnShowRadius)
	{
		return;
	}

	this->ProcessEvent(uFnShowRadius, &ShowRadius_Params, nullptr);
}

// Function Kynapse.SphinxInterstingPoint.PostBeginPlay
// [0x00020802] (FUNC_Defined | FUNC_Event | FUNC_Public)
// Parameter Info:

void ASphinxInterstingPoint::eventPostBeginPlay()
{
	static UFunction* uFnPostBeginPlay = nullptr;

	if (!uFnPostBeginPlay)
	{
		uFnPostBeginPlay = UFunction::FindFunction("Function Kynapse.SphinxInterstingPoint.PostBeginPlay");
	}

	ASphinxInterstingPoint_eventPostBeginPlay_Params PostBeginPlay_Params;
	memset(&PostBeginPlay_Params, 0, sizeof(PostBeginPlay_Params));

	if (!uFnPostBeginPlay)
	{
		return;
	}

	this->ProcessEvent(uFnPostBeginPlay, &PostBeginPlay_Params, nullptr);
}

/*
# ========================================================================================= #
#
# ========================================================================================= #
*/

#ifdef _MSC_VER
#pragma pack(pop)
#endif
