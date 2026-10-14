/*
#############################################################################################
# Alice2 (ASDK) SDK 1.0.0.0
# Generated with the CodeRedGenerator v1.2.0
# ========================================================================================= #
# File: Kynapse_parameters.hpp
# ========================================================================================= #
# Credits: ItsBranK, TheFeckless
# Links: www.github.com/CodeRedModding/CodeRed-Generator
#############################################################################################
*/
#pragma once

#ifdef _MSC_VER
#pragma pack(push, 0x4)
#endif

/*
# ========================================================================================= #
# Parameters
# ========================================================================================= #
*/

// Function Kynapse.KynapseAIController.OnAIFollow
// [0x00020002] 
struct AKynapseAIController_execOnAIFollow_Params
{
	class USeqAct_AIFollow*                            Action;                                           // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	// class USeqVar_Object*                           ObjVar;                                           // 0x0004 (0x0004) [0x0000000000000000]               
};

// Function Kynapse.KynapseAIController.OnAIShoot
// [0x00020002] 
struct AKynapseAIController_execOnAIShoot_Params
{
	class USeqAct_AIShoot*                             Action;                                           // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	// class USeqVar_Object*                           ObjVar;                                           // 0x0004 (0x0004) [0x0000000000000000]               
};

// Function Kynapse.KynapseAIController.OnAIHide
// [0x00020002] 
struct AKynapseAIController_execOnAIHide_Params
{
	class USeqAct_AIHide*                              Action;                                           // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	// class USeqVar_Object*                           ObjVar;                                           // 0x0004 (0x0004) [0x0000000000000000]               
};

// Function Kynapse.KynapseAIController.OnAIFlee
// [0x00020002] 
struct AKynapseAIController_execOnAIFlee_Params
{
	class USeqAct_AIFlee*                              Action;                                           // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	// class USeqVar_Object*                           ObjVar;                                           // 0x0004 (0x0004) [0x0000000000000000]               
};

// Function Kynapse.KynapseAIController.OnAIWander
// [0x00020002] 
struct AKynapseAIController_execOnAIWander_Params
{
	class USeqAct_AIWander*                            Action;                                           // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	// class USeqVar_Object*                           ObjVar;                                           // 0x0004 (0x0004) [0x0000000000000000]               
};

// Function Kynapse.KynapseAIController.Possess
// [0x00020002] 
struct AKynapseAIController_execPossess_Params
{
	class APawn*                                       aPawn;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	uint32_t                                           bVehicleTransition : 1;                           // 0x0004 (0x0004) [0x0000000000000080] [0x00000001] (CPF_Parm)
};

// Function Kynapse.KynapseAIController.KynapseFollow
// [0x00020408] 
struct AKynapseAIController_execKynapseFollow_Params
{
	class AActor*                                      TargetEntity;                                     // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	float                                              Duration;                                         // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
	bool                                               ReturnValue : 1;                                  // 0x0008 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function Kynapse.KynapseAIController.KynapseShoot
// [0x00020408] 
struct AKynapseAIController_execKynapseShoot_Params
{
	class AActor*                                      TargetEntity;                                     // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	float                                              Duration;                                         // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
	bool                                               ReturnValue : 1;                                  // 0x0008 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function Kynapse.KynapseAIController.KynapseHide
// [0x00020408] 
struct AKynapseAIController_execKynapseHide_Params
{
	float                                              Duration;                                         // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	bool                                               ReturnValue : 1;                                  // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function Kynapse.KynapseAIController.KynapseFlee
// [0x00020408] 
struct AKynapseAIController_execKynapseFlee_Params
{
	float                                              Duration;                                         // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	bool                                               ReturnValue : 1;                                  // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function Kynapse.KynapseAIController.KynapseWander
// [0x00020408] 
struct AKynapseAIController_execKynapseWander_Params
{
	float                                              Duration;                                         // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	bool                                               ReturnValue : 1;                                  // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function Kynapse.KynapseAIController.KynapseGoTo
// [0x00020408] 
struct AKynapseAIController_execKynapseGoTo_Params
{
	struct FVector                                     KynapseDestination;                               // 0x0000 (0x000C) [0x0000000000000080] (CPF_Parm)    
	bool                                               ReturnValue : 1;                                  // 0x000C (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function Kynapse.KynapseAIController.SetBrainState
// [0x00020401] 
struct AKynapseAIController_execSetBrainState_Params
{
	int32_t                                            Set;                                              // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function Kynapse.KynapseAIController.GetBrainState
// [0x00020401] 
struct AKynapseAIController_execGetBrainState_Params
{
	int32_t                                            ReturnValue;                                      // 0x0000 (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function Kynapse.KynapseAIController.ActivateKynapseBrain
// [0x00020401] 
struct AKynapseAIController_execActivateKynapseBrain_Params
{
	uint32_t                                           Activate : 1;                                     // 0x0000 (0x0004) [0x0000000000000080] [0x00000001] (CPF_Parm)
};

// Function Kynapse.KynapseAIController.KynapseHasArrived
// [0x00020401] 
struct AKynapseAIController_execKynapseHasArrived_Params
{
	struct FVector                                     Dest;                                             // 0x0000 (0x000C) [0x0000000000000080] (CPF_Parm)    
	bool                                               ReturnValue : 1;                                  // 0x000C (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function Kynapse.KynapseAIController.HearNoise
// [0x00024802] 
struct AKynapseAIController_eventHearNoise_Params
{
	float                                              Loudness;                                         // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class AActor*                                      NoiseMaker;                                       // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class FName                                        NoiseType;                                        // 0x0008 (0x0008) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
};

// Function Kynapse.KynapseExclusionVolume.StopsProjectile
// [0x00020102] 
struct AKynapseExclusionVolume_execStopsProjectile_Params
{
	class AProjectile*                                 P;                                                // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	bool                                               ReturnValue : 1;                                  // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function Kynapse.KynapseHandle.RegisterToProfile
// [0x00020401] 
struct UKynapseHandle_execRegisterToProfile_Params
{
	class FString                                      ProfileName;                                      // 0x0000 (0x000C) [0x0000000000400880] (CPF_Parm | CPF_CoerceParm | CPF_NeedCtorLink)
};

// Function Kynapse.KynapseHandle.AddKynapseEntity
// [0x00020401] 
struct UKynapseHandle_execAddKynapseEntity_Params
{
};

// Function Kynapse.KynapseHandle.InitKynapseEntity
// [0x00020401] 
struct UKynapseHandle_execInitKynapseEntity_Params
{
};

// Function Kynapse.KynapseLadderVolume.PostBeginPlay
// [0x00820902] 
struct AKynapseLadderVolume_eventPostBeginPlay_Params
{
	// class ALadder*                                  L;                                                // 0x0000 (0x0004) [0x0000000000000000]               
	// class ALadder*                                  M;                                                // 0x0004 (0x0004) [0x0000000000000000]               
	// struct FVector                                  Dir;                                              // 0x0008 (0x000C) [0x0000000000000000]               
};

// Function Kynapse.KynapseObstacleFractured.Explode
// [0x00020902] 
struct AKynapseObstacleFractured_eventExplode_Params
{
};

// Function Kynapse.KynapseObstacleFractured.TakeDamage
// [0x00024902] 
struct AKynapseObstacleFractured_eventTakeDamage_Params
{
	int32_t                                            Damage;                                           // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class AController*                                 EventInstigator;                                  // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FVector                                     HitLocation;                                      // 0x0008 (0x000C) [0x0000000000000080] (CPF_Parm)    
	struct FVector                                     Momentum;                                         // 0x0014 (0x000C) [0x0000000000000080] (CPF_Parm)    
	class UClass*                                      DamageType;                                       // 0x0020 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FTraceHitInfo                               HitInfo;                                          // 0x0024 (0x001C) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
	class AActor*                                      DamageCauser;                                     // 0x0040 (0x0004) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
};

// Function Kynapse.KynapsePawn.OnAnimEnd
// [0x00020802] 
struct AKynapsePawn_eventOnAnimEnd_Params
{
	class UAnimNodeSequence*                           SeqNode;                                          // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	float                                              PlayedTime;                                       // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
	float                                              ExcessTime;                                       // 0x0008 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function Kynapse.KynapsePawn.Bump
// [0x00020802] 
struct AKynapsePawn_eventBump_Params
{
	class AActor*                                      Other;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class UPrimitiveComponent*                         OtherComp;                                        // 0x0004 (0x0004) [0x0000000004000080] (CPF_Parm | CPF_EditInline)
	struct FVector                                     HitNormal;                                        // 0x0008 (0x000C) [0x0000000000000080] (CPF_Parm)    
};

// Function Kynapse.KynapsePawn.SphinxAnimEnd
// [0x00020401] 
struct AKynapsePawn_execSphinxAnimEnd_Params
{
	class UAnimNodeSequence*                           SeqNode;                                          // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	float                                              PlayedTime;                                       // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
	float                                              ExcessTime;                                       // 0x0008 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function Kynapse.KynapseTeamCreationData.PostInitializeTeam
// [0x00020400] 
struct UKynapseTeamCreationData_execPostInitializeTeam_Params
{
};

// Function Kynapse.KynapseTeamCreationData.CreateKynapseTeam
// [0x00020400] 
struct UKynapseTeamCreationData_execCreateKynapseTeam_Params
{
};

// Function Kynapse.SphinxInterstingPoint.ShowRadius
// [0x00020002] 
struct ASphinxInterstingPoint_execShowRadius_Params
{
};

// Function Kynapse.SphinxInterstingPoint.PostBeginPlay
// [0x00020802] 
struct ASphinxInterstingPoint_eventPostBeginPlay_Params
{
	// int32_t                                         I;                                                // 0x0000 (0x0004) [0x0000000000000000]               
};

/*
# ========================================================================================= #
#
# ========================================================================================= #
*/

#ifdef _MSC_VER
#pragma pack(pop)
#endif
