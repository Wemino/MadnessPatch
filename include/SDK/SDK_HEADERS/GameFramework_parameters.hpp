/*
#############################################################################################
# Alice2 (ASDK) SDK 1.0.0.0
# Generated with the CodeRedGenerator v1.2.0
# ========================================================================================= #
# File: GameFramework_parameters.hpp
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

// Function GameFramework.GameAIController.GetActionString
// [0x00020903] 
struct AGameAIController_eventGetActionString_Params
{
	class FString                                      ReturnValue;                                      // 0x0000 (0x000C) [0x0000000000400580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
	// class FString                                   ActionStr;                                        // 0x000C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	// class UGameAICommand*                           ActiveCmd;                                        // 0x0018 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameAIController.GeneratePathToLocation
// [0x00024800] 
struct AGameAIController_eventGeneratePathToLocation_Params
{
	struct FVector                                     Goal;                                             // 0x0000 (0x000C) [0x0000000000000080] (CPF_Parm)    
	float                                              WithinDistance;                                   // 0x000C (0x0004) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
	uint32_t                                           bAllowPartialPath : 1;                            // 0x0010 (0x0004) [0x0000000000000090] [0x00000001] (CPF_OptionalParm | CPF_Parm)
	uint32_t : 0;                                  // 0x0014 CLOSE BITFIELD STORAGE UNIT
	bool                                               ReturnValue : 1;                                  // 0x0014 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameAIController.GeneratePathToActor
// [0x00024800] 
struct AGameAIController_eventGeneratePathToActor_Params
{
	class AActor*                                      Goal;                                             // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	float                                              WithinDistance;                                   // 0x0004 (0x0004) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
	uint32_t                                           bAllowPartialPath : 1;                            // 0x0008 (0x0004) [0x0000000000000090] [0x00000001] (CPF_OptionalParm | CPF_Parm)
	uint32_t : 0;                                  // 0x000C CLOSE BITFIELD STORAGE UNIT
	bool                                               ReturnValue : 1;                                  // 0x000C (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameAIController.SetDesiredRotation
// [0x00024002] 
struct AGameAIController_execSetDesiredRotation_Params
{
	struct FRotator                                    TargetDesiredRotation;                            // 0x0000 (0x000C) [0x0000000000000080] (CPF_Parm)    
	uint32_t                                           InLockDesiredRotation : 1;                        // 0x000C (0x0004) [0x0000000000000090] [0x00000001] (CPF_OptionalParm | CPF_Parm)
	uint32_t : 0;                                  // 0x0010 CLOSE BITFIELD STORAGE UNIT
	uint32_t                                           InUnlockWhenReached : 1;                          // 0x0010 (0x0004) [0x0000000000000090] [0x00000001] (CPF_OptionalParm | CPF_Parm)
	float                                              InterpolationTime;                                // 0x0014 (0x0004) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
};

// Function GameFramework.GameAIController.AILog_Internal
// [0x00024802] 
struct AGameAIController_eventAILog_Internal_Params
{
	class FString                                      LogText;                                          // 0x0000 (0x000C) [0x0000000000400880] (CPF_Parm | CPF_CoerceParm | CPF_NeedCtorLink)
	class FName                                        LogCategory;                                      // 0x000C (0x0008) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
	uint32_t                                           bForce : 1;                                       // 0x0014 (0x0004) [0x0000000000000090] [0x00000001] (CPF_OptionalParm | CPF_Parm)
	// int32_t                                         Idx;                                              // 0x0018 (0x0004) [0x0000000000000000]               
	// class FString                                   ActionStr;                                        // 0x001C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	// class FString                                   FinalStr;                                         // 0x0028 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	// class FString                                   Filename;                                         // 0x0034 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	// class UGameAICommand*                           ActiveCommand;                                    // 0x0040 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameAIController.RecordDemoAILog
// [0x00080000] 
struct AGameAIController_execRecordDemoAILog_Params
{
	class FString                                      LogText;                                          // 0x0000 (0x000C) [0x0000000000400880] (CPF_Parm | CPF_CoerceParm | CPF_NeedCtorLink)
};

// Function GameFramework.GameAIController.Destroyed
// [0x00020802] 
struct AGameAIController_eventDestroyed_Params
{
};

// Function GameFramework.GameAIController.GetAICommandInStack
// [0x00020400] 
struct AGameAIController_execGetAICommandInStack_Params
{
	class UClass*                                      InClass;                                          // 0x0000 (0x0004) [0x0000000000000082] (CPF_Const | CPF_Parm)
	class UGameAICommand*                              ReturnValue;                                      // 0x0004 (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameAIController.FindCommandOfClass
// [0x00020401] 
struct AGameAIController_execFindCommandOfClass_Params
{
	class UClass*                                      SearchClass;                                      // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class UGameAICommand*                              ReturnValue;                                      // 0x0004 (0x0004) [0x0000000000000D80] (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_CoerceParm)
};

// Function GameFramework.GameAIController.DumpCommandStack
// [0x00020401] 
struct AGameAIController_execDumpCommandStack_Params
{
};

// Function GameFramework.GameAIController.CheckCommandCount
// [0x00020401] 
struct AGameAIController_execCheckCommandCount_Params
{
};

// Function GameFramework.GameAIController.GetActiveCommand
// [0x00020401] 
struct AGameAIController_execGetActiveCommand_Params
{
	class UGameAICommand*                              ReturnValue;                                      // 0x0000 (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameAIController.AbortCommand
// [0x00024401] 
struct AGameAIController_execAbortCommand_Params
{
	class UGameAICommand*                              AbortCmd;                                         // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class UClass*                                      AbortClass;                                       // 0x0004 (0x0004) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
	bool                                               ReturnValue : 1;                                  // 0x0008 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameAIController.PopCommand
// [0x00020401] 
struct AGameAIController_execPopCommand_Params
{
	class UGameAICommand*                              ToBePoppedCommand;                                // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameAIController.PushCommand
// [0x00020401] 
struct AGameAIController_execPushCommand_Params
{
	class UGameAICommand*                              NewCommand;                                       // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameAICommand.GetDebugOverheadText
// [0x00420000] 
struct UGameAICommand_execGetDebugOverheadText_Params
{
	class APlayerController*                           PC;                                               // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class TArray<class FString>                        OutText;                                          // 0x0004 (0x000C) [0x0000000000400180] (CPF_Parm | CPF_OutParm | CPF_NeedCtorLink)
};

// Function GameFramework.GameAICommand.DrawDebug
// [0x00020800] 
struct UGameAICommand_eventDrawDebug_Params
{
	class AHUD*                                        H;                                                // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class FName                                        Category;                                         // 0x0004 (0x0008) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameAICommand.GetDumpString
// [0x00020802] 
struct UGameAICommand_eventGetDumpString_Params
{
	class FString                                      ReturnValue;                                      // 0x0000 (0x000C) [0x0000000000400580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
};

// Function GameFramework.GameAICommand.Resumed
// [0x00020002] 
struct UGameAICommand_execResumed_Params
{
	class FName                                        OldCommandName;                                   // 0x0000 (0x0008) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameAICommand.Paused
// [0x00020002] 
struct UGameAICommand_execPaused_Params
{
	class UGameAICommand*                              NewCommand;                                       // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameAICommand.Popped
// [0x00020002] 
struct UGameAICommand_execPopped_Params
{
};

// Function GameFramework.GameAICommand.Pushed
// [0x00020002] 
struct UGameAICommand_execPushed_Params
{
};

// Function GameFramework.GameAICommand.PostPopped
// [0x00020000] 
struct UGameAICommand_execPostPopped_Params
{
};

// Function GameFramework.GameAICommand.PrePushed
// [0x00020000] 
struct UGameAICommand_execPrePushed_Params
{
	class AGameAIController*                           AI;                                               // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameAICommand.AllowStateTransitionTo
// [0x00020002] 
struct UGameAICommand_execAllowStateTransitionTo_Params
{
	class FName                                        StateName;                                        // 0x0000 (0x0008) [0x0000000000000080] (CPF_Parm)    
	bool                                               ReturnValue : 1;                                  // 0x0008 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameAICommand.AllowTransitionTo
// [0x00020002] 
struct UGameAICommand_execAllowTransitionTo_Params
{
	class UClass*                                      AttemptCommand;                                   // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	bool                                               ReturnValue : 1;                                  // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameAICommand.Tick
// [0x00020000] 
struct UGameAICommand_execTick_Params
{
	float                                              DeltaTime;                                        // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameAICommand.ShouldIgnoreNotifies
// [0x00020401] 
struct UGameAICommand_execShouldIgnoreNotifies_Params
{
	bool                                               ReturnValue : 1;                                  // 0x0000 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameAICommand.InternalTick
// [0x00020803] 
struct UGameAICommand_eventInternalTick_Params
{
	float                                              DeltaTime;                                        // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameAICommand.InternalResumed
// [0x00020803] 
struct UGameAICommand_eventInternalResumed_Params
{
	class FName                                        OldCommandName;                                   // 0x0000 (0x0008) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameAICommand.InternalPaused
// [0x00020803] 
struct UGameAICommand_eventInternalPaused_Params
{
	class UGameAICommand*                              NewCommand;                                       // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameAICommand.InternalPopped
// [0x00020802] 
struct UGameAICommand_eventInternalPopped_Params
{
};

// Function GameFramework.GameAICommand.InternalPushed
// [0x00020803] 
struct UGameAICommand_eventInternalPushed_Params
{
};

// Function GameFramework.GameAICommand.InternalPrePushed
// [0x00020803] 
struct UGameAICommand_eventInternalPrePushed_Params
{
	class AGameAIController*                           AI;                                               // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameAICommand.InitCommand
// [0x00022002] 
struct UGameAICommand_execInitCommand_Params
{
	class AGameAIController*                           AI;                                               // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	bool                                               ReturnValue : 1;                                  // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
	// class UGameAICommand*                           Cmd;                                              // 0x0008 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameAICommand.InitCommandUserActor
// [0x00022002] 
struct UGameAICommand_execInitCommandUserActor_Params
{
	class AGameAIController*                           AI;                                               // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class AActor*                                      UserActor;                                        // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
	bool                                               ReturnValue : 1;                                  // 0x0008 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameCrowdAgent.GetBehaviorString
// [0x00020002] 
struct AGameCrowdAgent_execGetBehaviorString_Params
{
	class FString                                      ReturnValue;                                      // 0x0000 (0x000C) [0x0000000000400580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
	// class FString                                   BehaviorString;                                   // 0x000C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// Function GameFramework.GameCrowdAgent.GetDestString
// [0x00020002] 
struct AGameCrowdAgent_execGetDestString_Params
{
	class FString                                      ReturnValue;                                      // 0x0000 (0x000C) [0x0000000000400580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
	// class FString                                   DestString;                                       // 0x000C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// Function GameFramework.GameCrowdAgent.PostRenderFor
// [0x00820902] 
struct AGameCrowdAgent_eventPostRenderFor_Params
{
	class APlayerController*                           PC;                                               // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class UCanvas*                                     Canvas;                                           // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FVector                                     CameraPosition;                                   // 0x0008 (0x000C) [0x0000000000000080] (CPF_Parm)    
	struct FVector                                     CameraDir;                                        // 0x0014 (0x000C) [0x0000000000000080] (CPF_Parm)    
	// float                                           NameXL;                                           // 0x0020 (0x0004) [0x0000000000000000]               
	// float                                           TextXL;                                           // 0x0024 (0x0004) [0x0000000000000000]               
	// float                                           BehavXL;                                          // 0x0028 (0x0004) [0x0000000000000000]               
	// float                                           TextYL;                                           // 0x002C (0x0004) [0x0000000000000000]               
	// float                                           YL;                                               // 0x0030 (0x0004) [0x0000000000000000]               
	// float                                           XL;                                               // 0x0034 (0x0004) [0x0000000000000000]               
	// struct FVector                                  ScreenLoc;                                        // 0x0038 (0x000C) [0x0000000000000000]               
	// class FString                                   ScreenName;                                       // 0x0044 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	// class FString                                   DestString;                                       // 0x0050 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	// class FString                                   BehaviorString;                                   // 0x005C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	// struct FFontRenderInfo                          FontInfo;                                         // 0x0068 (0x0028) [0x0000000000000000]               
};

// Function GameFramework.GameCrowdAgent.NativePostRenderFor
// [0x00020500] 
struct AGameCrowdAgent_execNativePostRenderFor_Params
{
	class APlayerController*                           PC;                                               // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class UCanvas*                                     Canvas;                                           // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FVector                                     CameraPosition;                                   // 0x0008 (0x000C) [0x0000000000000080] (CPF_Parm)    
	struct FVector                                     CameraDir;                                        // 0x0014 (0x000C) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameCrowdAgent.GeneratePathToActor
// [0x00824802] 
struct AGameCrowdAgent_eventGeneratePathToActor_Params
{
	class AActor*                                      Goal;                                             // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	float                                              WithinDistance;                                   // 0x0004 (0x0004) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
	uint32_t                                           bAllowPartialPath : 1;                            // 0x0008 (0x0004) [0x0000000000000090] [0x00000001] (CPF_OptionalParm | CPF_Parm)
	struct FVector                                     ReturnValue;                                      // 0x000C (0x000C) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
	// struct FVector                                  NextDest;                                         // 0x0018 (0x000C) [0x0000000000000000]               
};

// Function GameFramework.GameCrowdAgent.InitNavigationHandle
// [0x00020802] 
struct AGameCrowdAgent_eventInitNavigationHandle_Params
{
};

// Function GameFramework.GameCrowdAgent.OverlappedActorEvent
// [0x00020800] 
struct AGameCrowdAgent_eventOverlappedActorEvent_Params
{
	class AActor*                                      A;                                                // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameCrowdAgent.TakeDamage
// [0x00024002] 
struct AGameCrowdAgent_execTakeDamage_Params
{
	int32_t                                            DamageAmount;                                     // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class AController*                                 EventInstigator;                                  // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FVector                                     HitLocation;                                      // 0x0008 (0x000C) [0x0000000000000080] (CPF_Parm)    
	struct FVector                                     Momentum;                                         // 0x0014 (0x000C) [0x0000000000000080] (CPF_Parm)    
	class UClass*                                      DamageType;                                       // 0x0020 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FTraceHitInfo                               HitInfo;                                          // 0x0024 (0x001C) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
	class AActor*                                      DamageCauser;                                     // 0x0040 (0x0004) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
};

// Function GameFramework.GameCrowdAgent.FireDeathEvent
// [0x00020902] 
struct AGameCrowdAgent_eventFireDeathEvent_Params
{
};

// Function GameFramework.GameCrowdAgent.PlayDeath
// [0x00020400] 
struct AGameCrowdAgent_execPlayDeath_Params
{
	struct FVector                                     KillMomentum;                                     // 0x0000 (0x000C) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameCrowdAgent.UpdateIntermediatePoint
// [0x00024802] 
struct AGameCrowdAgent_eventUpdateIntermediatePoint_Params
{
	class AActor*                                      DestinationActor;                                 // 0x0000 (0x0004) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
};

// Function GameFramework.GameCrowdAgent.CalcCamera
// [0x00C20102] 
struct AGameCrowdAgent_execCalcCamera_Params
{
	float                                              fDeltaTime;                                       // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FVector                                     out_CamLoc;                                       // 0x0004 (0x000C) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
	struct FRotator                                    out_CamRot;                                       // 0x0010 (0x000C) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
	float                                              out_FOV;                                          // 0x001C (0x0004) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
	bool                                               ReturnValue : 1;                                  // 0x0020 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
	// struct FVector                                  HitNormal;                                        // 0x0024 (0x000C) [0x0000000000000000]               
	// float                                           Radius;                                           // 0x0030 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameCrowdAgent.IsIdle
// [0x00020400] 
struct AGameCrowdAgent_execIsIdle_Params
{
	bool                                               ReturnValue : 1;                                  // 0x0000 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameCrowdAgent.SetCurrentBehavior
// [0x00020401] 
struct AGameCrowdAgent_execSetCurrentBehavior_Params
{
	class UGameCrowdAgentBehavior*                     BehaviorArchetype;                                // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameCrowdAgent.StopBehavior
// [0x00020802] 
struct AGameCrowdAgent_eventStopBehavior_Params
{
};

// Function GameFramework.GameCrowdAgent.ActivateInstancedBehavior
// [0x00020002] 
struct AGameCrowdAgent_execActivateInstancedBehavior_Params
{
	class UGameCrowdAgentBehavior*                     NewBehaviorObject;                                // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameCrowdAgent.ActivateBehavior
// [0x00020802] 
struct AGameCrowdAgent_eventActivateBehavior_Params
{
	class UGameCrowdAgentBehavior*                     NewBehaviorArchetype;                             // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameCrowdAgent.ResetSeePlayer
// [0x00020002] 
struct AGameCrowdAgent_execResetSeePlayer_Params
{
};

// Function GameFramework.GameCrowdAgent.TryRandomBehavior
// [0x00020002] 
struct AGameCrowdAgent_execTryRandomBehavior_Params
{
	// uint32_t                                        bFoundBehavior : 1;                               // 0x0000 (0x0004) [0x0000000000000000] [0x00000001] 
	// int32_t                                         I;                                                // 0x0004 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameCrowdAgent.NotifySeePlayer
// [0x00020802] 
struct AGameCrowdAgent_eventNotifySeePlayer_Params
{
	class APlayerController*                           PC;                                               // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	// uint32_t                                        bFoundBehavior : 1;                               // 0x0004 (0x0004) [0x0000000000000000] [0x00000001] 
	// int32_t                                         I;                                                // 0x0008 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameCrowdAgent.PlaySpawnBehavior
// [0x00020002] 
struct AGameCrowdAgent_execPlaySpawnBehavior_Params
{
};

// Function GameFramework.GameCrowdAgent.HandlePotentialAgentEncounter
// [0x00020802] 
struct AGameCrowdAgent_eventHandlePotentialAgentEncounter_Params
{
};

// Function GameFramework.GameCrowdAgent.StopIdleAnimation
// [0x00020900] 
struct AGameCrowdAgent_eventStopIdleAnimation_Params
{
};

// Function GameFramework.GameCrowdAgent.PlayIdleAnimation
// [0x00020900] 
struct AGameCrowdAgent_eventPlayIdleAnimation_Params
{
};

// Function GameFramework.GameCrowdAgent.OnPlayAgentAnimation
// [0x00020102] 
struct AGameCrowdAgent_execOnPlayAgentAnimation_Params
{
	class USeqAct_PlayAgentAnimation*                  Action;                                           // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameCrowdAgent.InitializeAgent
// [0x00820102] 
struct AGameCrowdAgent_execInitializeAgent_Params
{
	class AActor*                                      SpawnLoc;                                         // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class AGameCrowdAgent*                             AgentTemplate;                                    // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class UGameCrowdGroup*                             NewGroup;                                         // 0x0008 (0x0004) [0x0000000000000080] (CPF_Parm)    
	float                                              AgentWarmupTime;                                  // 0x000C (0x0004) [0x0000000000000080] (CPF_Parm)    
	uint32_t                                           bWarmupPosition : 1;                              // 0x0010 (0x0004) [0x0000000000000080] [0x00000001] (CPF_Parm)
	uint32_t : 0;                                  // 0x0014 CLOSE BITFIELD STORAGE UNIT
	uint32_t                                           bCheckWarmupVisibility : 1;                       // 0x0014 (0x0004) [0x0000000000000080] [0x00000001] (CPF_Parm)
	// uint32_t                                        bGroupDestination : 1;                            // 0x0018 (0x0004) [0x0000000000000000] [0x00000001] 
	// uint32_t                                        bRealPreferVisible : 1;                           // 0x001C (0x0004) [0x0000000000000000] [0x00000001] 
	// class AGameCrowdDestination*                    SpawnDest;                                        // 0x0020 (0x0004) [0x0000000000000000]               
	// float                                           TryPct;                                           // 0x0024 (0x0004) [0x0000000000000000]               
	// float                                           MaxSpawnDist;                                     // 0x0028 (0x0004) [0x0000000000000000]               
	// float                                           DestDist;                                         // 0x002C (0x0004) [0x0000000000000000]               
	// float                                           StartDist;                                        // 0x0030 (0x0004) [0x0000000000000000]               
	// struct FVector                                  TryLoc;                                           // 0x0034 (0x000C) [0x0000000000000000]               
	// class AActor*                                   HitActor;                                         // 0x0040 (0x0004) [0x0000000000000000]               
	// struct FVector                                  HitLocation;                                      // 0x0044 (0x000C) [0x0000000000000000]               
	// struct FVector                                  HitNormal;                                        // 0x0050 (0x000C) [0x0000000000000000]               
	// struct FVector                                  ViewLocation;                                     // 0x005C (0x000C) [0x0000000000000000]               
	// struct FVector                                  YAdjust;                                          // 0x0068 (0x000C) [0x0000000000000000]               
	// struct FRotator                                 ViewRotation;                                     // 0x0074 (0x000C) [0x0000000000000000]               
	// class APlayerController*                        PC;                                               // 0x0080 (0x0004) [0x0000000000000000]               
	// uint32_t                                        bVisibleTryLoc : 1;                               // 0x0084 (0x0004) [0x0000000000000000] [0x00000001] 
};

// Function GameFramework.GameCrowdAgent.SetLighting
// [0x00020102] 
struct AGameCrowdAgent_execSetLighting_Params
{
	uint32_t                                           bEnableLightEnvironment : 1;                      // 0x0000 (0x0004) [0x0000000000000080] [0x00000001] (CPF_Parm)
	struct FLightingChannelContainer                   AgentLightingChannel;                             // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
	uint32_t                                           bCastShadows : 1;                                 // 0x0008 (0x0004) [0x0000000000000080] [0x00000001] (CPF_Parm)
};

// Function GameFramework.GameCrowdAgent.DisplayDebug
// [0x00420102] 
struct AGameCrowdAgent_execDisplayDebug_Params
{
	class AHUD*                                        HUD;                                              // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	float                                              out_YL;                                           // 0x0004 (0x0004) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
	float                                              out_YPos;                                         // 0x0008 (0x0004) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
	// class FString                                   T;                                                // 0x000C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	// class UCanvas*                                  Canvas;                                           // 0x0018 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameCrowdAgent.Destroyed
// [0x00020102] 
struct AGameCrowdAgent_execDestroyed_Params
{
};

// Function GameFramework.GameCrowdAgent.ResetPooledAgent
// [0x00020002] 
struct AGameCrowdAgent_execResetPooledAgent_Params
{
};

// Function GameFramework.GameCrowdAgent.KillAgent
// [0x00020802] 
struct AGameCrowdAgent_eventKillAgent_Params
{
};

// Function GameFramework.GameCrowdAgent.PostBeginPlay
// [0x00820102] 
struct AGameCrowdAgent_execPostBeginPlay_Params
{
	// struct FVector                                  AgentScale3D;                                     // 0x0000 (0x000C) [0x0000000000000000]               
	// int32_t                                         I;                                                // 0x000C (0x0004) [0x0000000000000000]               
	// float                                           MaxSeePlayerDist;                                 // 0x0010 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameCrowdAgent.SetMaxSpeed
// [0x00020002] 
struct AGameCrowdAgent_execSetMaxSpeed_Params
{
};

// Function GameFramework.GameCrowdAgent.SetCurrentDestination
// [0x00020802] 
struct AGameCrowdAgent_eventSetCurrentDestination_Params
{
	class AGameCrowdDestination*                       NewDest;                                          // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameCrowdAgent.WaitForGroupMembers
// [0x00020802] 
struct AGameCrowdAgent_eventWaitForGroupMembers_Params
{
	// int32_t                                         I;                                                // 0x0000 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameCrowdAgent.PickBehaviorFrom
// [0x00824002] 
struct AGameCrowdAgent_execPickBehaviorFrom_Params
{
	class TArray<struct FBehaviorEntry>                BehaviorList;                                     // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	struct FVector                                     BestCameraLoc;                                    // 0x000C (0x000C) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
	bool                                               ReturnValue : 1;                                  // 0x0018 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
	// struct FVector                                  cameraLoc;                                        // 0x001C (0x000C) [0x0000000000000000]               
	// struct FRotator                                 cameraRot;                                        // 0x0028 (0x000C) [0x0000000000000000]               
	// class APlayerController*                        PC;                                               // 0x0034 (0x0004) [0x0000000000000000]               
	// float                                           BestDistSq;                                       // 0x0038 (0x0004) [0x0000000000000000]               
	// float                                           NewDistSq;                                        // 0x003C (0x0004) [0x0000000000000000]               
	// int32_t                                         I;                                                // 0x0040 (0x0004) [0x0000000000000000]               
	// float                                           FreqSum;                                          // 0x0044 (0x0004) [0x0000000000000000]               
	// float                                           RandPick;                                         // 0x0048 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameCrowdAgent.SetPanic
// [0x00020002] 
struct AGameCrowdAgent_execSetPanic_Params
{
	class AActor*                                      PanicActor;                                       // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	uint32_t                                           bNewPanic : 1;                                    // 0x0004 (0x0004) [0x0000000000000080] [0x00000001] (CPF_Parm)
};

// Function GameFramework.GameCrowdAgent.IsPanicked
// [0x00020400] 
struct AGameCrowdAgent_execIsPanicked_Params
{
	bool                                               ReturnValue : 1;                                  // 0x0000 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameCrowdAgent.FellOutOfWorld
// [0x00020902] 
struct AGameCrowdAgent_eventFellOutOfWorld_Params
{
	class UClass*                                      dmgType;                                          // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameCrowdAgentSkeletal.CreateAttachments
// [0x00020102] 
struct AGameCrowdAgentSkeletal_execCreateAttachments_Params
{
	// int32_t                                         AttachIdx;                                        // 0x0000 (0x0004) [0x0000000000000000]               
	// int32_t                                         InfoIdx;                                          // 0x0004 (0x0004) [0x0000000000000000]               
	// int32_t                                         PickedInfoIdx;                                    // 0x0008 (0x0004) [0x0000000000000000]               
	// float                                           ChanceTotal;                                      // 0x000C (0x0004) [0x0000000000000000]               
	// float                                           RandVal;                                          // 0x0010 (0x0004) [0x0000000000000000]               
	// class UStaticMeshComponent*                     StaticMeshComp;                                   // 0x0014 (0x0004) [0x0000000004000000] (CPF_EditInline)
	// uint32_t                                        bUseSocket : 1;                                   // 0x0018 (0x0004) [0x0000000000000000] [0x00000001] 
	// uint32_t                                        bUseBone : 1;                                     // 0x001C (0x0004) [0x0000000000000000] [0x00000001] 
};

// Function GameFramework.GameCrowdAgentSkeletal.OnAnimEnd
// [0x00020802] 
struct AGameCrowdAgentSkeletal_eventOnAnimEnd_Params
{
	class UAnimNodeSequence*                           SeqNode;                                          // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	float                                              PlayedTime;                                       // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
	float                                              ExcessTime;                                       // 0x0008 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameCrowdAgentSkeletal.StopIdleAnimation
// [0x00020902] 
struct AGameCrowdAgentSkeletal_eventStopIdleAnimation_Params
{
};

// Function GameFramework.GameCrowdAgentSkeletal.PlayIdleAnimation
// [0x00020902] 
struct AGameCrowdAgentSkeletal_eventPlayIdleAnimation_Params
{
};

// Function GameFramework.GameCrowdAgentSkeletal.ClearLatentAnimation
// [0x00020802] 
struct AGameCrowdAgentSkeletal_eventClearLatentAnimation_Params
{
};

// Function GameFramework.GameCrowdAgentSkeletal.OnPlayAgentAnimation
// [0x00020102] 
struct AGameCrowdAgentSkeletal_execOnPlayAgentAnimation_Params
{
	class USeqAct_PlayAgentAnimation*                  Action;                                           // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameCrowdAgentSkeletal.SetRootMotion
// [0x00020400] 
struct AGameCrowdAgentSkeletal_execSetRootMotion_Params
{
	uint32_t                                           bRootMotionEnabled : 1;                           // 0x0000 (0x0004) [0x0000000000000080] [0x00000001] (CPF_Parm)
};

// Function GameFramework.GameCrowdAgentSkeletal.PlayDeath
// [0x00020400] 
struct AGameCrowdAgentSkeletal_execPlayDeath_Params
{
	struct FVector                                     KillMomentum;                                     // 0x0000 (0x000C) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameCrowdAgentSkeletal.SetLighting
// [0x00020102] 
struct AGameCrowdAgentSkeletal_execSetLighting_Params
{
	uint32_t                                           bEnableLightEnvironment : 1;                      // 0x0000 (0x0004) [0x0000000000000080] [0x00000001] (CPF_Parm)
	struct FLightingChannelContainer                   AgentLightingChannel;                             // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
	uint32_t                                           bCastShadows : 1;                                 // 0x0008 (0x0004) [0x0000000000000080] [0x00000001] (CPF_Parm)
};

// Function GameFramework.GameCrowdAgentSkeletal.PostBeginPlay
// [0x00020102] 
struct AGameCrowdAgentSkeletal_execPostBeginPlay_Params
{
};

// Function GameFramework.GameCrowdAgentBehavior.AllowBehaviorAt
// [0x00020002] 
struct UGameCrowdAgentBehavior_execAllowBehaviorAt_Params
{
	class AGameCrowdDestination*                       Destination;                                      // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	bool                                               ReturnValue : 1;                                  // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameCrowdAgentBehavior.AllowThisDestination
// [0x00020002] 
struct UGameCrowdAgentBehavior_execAllowThisDestination_Params
{
	class AGameCrowdDestination*                       Destination;                                      // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	bool                                               ReturnValue : 1;                                  // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameCrowdAgentBehavior.PropagateViralBehaviorTo
// [0x00020800] 
struct UGameCrowdAgentBehavior_eventPropagateViralBehaviorTo_Params
{
	class AGameCrowdAgent*                             OtherAgent;                                       // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameCrowdAgentBehavior.ActivatedBy
// [0x00020002] 
struct UGameCrowdAgentBehavior_execActivatedBy_Params
{
	class AActor*                                      NewActionTarget;                                  // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameCrowdAgentBehavior.GetDestinationActor
// [0x00020002] 
struct UGameCrowdAgentBehavior_execGetDestinationActor_Params
{
	class AActor*                                      ReturnValue;                                      // 0x0000 (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameCrowdAgentBehavior.ChangingDestination
// [0x00020000] 
struct UGameCrowdAgentBehavior_execChangingDestination_Params
{
	class AGameCrowdDestination*                       NewDest;                                          // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameCrowdAgentBehavior.GetBehaviorString
// [0x00020002] 
struct UGameCrowdAgentBehavior_execGetBehaviorString_Params
{
	class FString                                      ReturnValue;                                      // 0x0000 (0x000C) [0x0000000000400580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
};

// Function GameFramework.GameCrowdAgentBehavior.OnAnimEnd
// [0x00020800] 
struct UGameCrowdAgentBehavior_eventOnAnimEnd_Params
{
	class UAnimNodeSequence*                           SeqNode;                                          // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	float                                              PlayedTime;                                       // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
	float                                              ExcessTime;                                       // 0x0008 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameCrowdAgentBehavior.StopBehavior
// [0x00020000] 
struct UGameCrowdAgentBehavior_execStopBehavior_Params
{
};

// Function GameFramework.GameCrowdAgentBehavior.InitBehavior
// [0x00020002] 
struct UGameCrowdAgentBehavior_execInitBehavior_Params
{
	class AGameCrowdAgent*                             Agent;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameCrowdAgentBehavior.HandleMovement
// [0x00020400] 
struct UGameCrowdAgentBehavior_execHandleMovement_Params
{
	bool                                               ReturnValue : 1;                                  // 0x0000 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameCrowdAgentBehavior.FinishedTargetRotation
// [0x00020800] 
struct UGameCrowdAgentBehavior_eventFinishedTargetRotation_Params
{
};

// Function GameFramework.GameCrowdAgentBehavior.CanBeUsedBy
// [0x00020002] 
struct UGameCrowdAgentBehavior_execCanBeUsedBy_Params
{
	class AGameCrowdAgent*                             Agent;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FVector                                     cameraLoc;                                        // 0x0004 (0x000C) [0x0000000000000080] (CPF_Parm)    
	bool                                               ReturnValue : 1;                                  // 0x0010 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameCrowdAgentBehavior.Tick
// [0x00020400] 
struct UGameCrowdAgentBehavior_execTick_Params
{
	float                                              DeltaTime;                                        // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameCrowdAgentBehavior.ShouldEndIdle
// [0x00020400] 
struct UGameCrowdAgentBehavior_execShouldEndIdle_Params
{
	bool                                               ReturnValue : 1;                                  // 0x0000 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameCrowdBehavior_PlayAnimation.GetBehaviorString
// [0x00020002] 
struct UGameCrowdBehavior_PlayAnimation_execGetBehaviorString_Params
{
	class FString                                      ReturnValue;                                      // 0x0000 (0x000C) [0x0000000000400580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
	// class FString                                   BehaviorString;                                   // 0x000C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// Function GameFramework.GameCrowdBehavior_PlayAnimation.StopBehavior
// [0x00020002] 
struct UGameCrowdBehavior_PlayAnimation_execStopBehavior_Params
{
};

// Function GameFramework.GameCrowdBehavior_PlayAnimation.PlayAgentAnimationNow
// [0x00020002] 
struct UGameCrowdBehavior_PlayAnimation_execPlayAgentAnimationNow_Params
{
	// float                                           CurrentBlendInTime;                               // 0x0000 (0x0004) [0x0000000000000000]               
	// float                                           CurrentBlendOutTime;                              // 0x0004 (0x0004) [0x0000000000000000]               
	// class AGameCrowdAgentSkeletal*                  MySkAgent;                                        // 0x0008 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameCrowdBehavior_PlayAnimation.OnAnimEnd
// [0x00020802] 
struct UGameCrowdBehavior_PlayAnimation_eventOnAnimEnd_Params
{
	class UAnimNodeSequence*                           SeqNode;                                          // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	float                                              PlayedTime;                                       // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
	float                                              ExcessTime;                                       // 0x0008 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameCrowdBehavior_PlayAnimation.SetSequenceOutput
// [0x00020400] 
struct UGameCrowdBehavior_PlayAnimation_execSetSequenceOutput_Params
{
};

// Function GameFramework.GameCrowdBehavior_PlayAnimation.FinishedTargetRotation
// [0x00020802] 
struct UGameCrowdBehavior_PlayAnimation_eventFinishedTargetRotation_Params
{
};

// Function GameFramework.GameCrowdBehavior_PlayAnimation.InitBehavior
// [0x00020002] 
struct UGameCrowdBehavior_PlayAnimation_execInitBehavior_Params
{
	class AGameCrowdAgent*                             Agent;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	// class APlayerController*                        PC;                                               // 0x0004 (0x0004) [0x0000000000000000]               
	// class APlayerController*                        ClosestPC;                                        // 0x0008 (0x0004) [0x0000000000000000]               
	// float                                           ClosestDist;                                      // 0x000C (0x0004) [0x0000000000000000]               
	// float                                           newdist;                                          // 0x0010 (0x0004) [0x0000000000000000]               
	// class AGameCrowdAgentSkeletal*                  SkAgent;                                          // 0x0014 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameCrowdBehavior_RunFromPanic.GetBehaviorString
// [0x00020002] 
struct UGameCrowdBehavior_RunFromPanic_execGetBehaviorString_Params
{
	class FString                                      ReturnValue;                                      // 0x0000 (0x000C) [0x0000000000400580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
};

// Function GameFramework.GameCrowdBehavior_RunFromPanic.AllowBehaviorAt
// [0x00020002] 
struct UGameCrowdBehavior_RunFromPanic_execAllowBehaviorAt_Params
{
	class AGameCrowdDestination*                       Destination;                                      // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	bool                                               ReturnValue : 1;                                  // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameCrowdBehavior_RunFromPanic.AllowThisDestination
// [0x00020002] 
struct UGameCrowdBehavior_RunFromPanic_execAllowThisDestination_Params
{
	class AGameCrowdDestination*                       Destination;                                      // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	bool                                               ReturnValue : 1;                                  // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameCrowdBehavior_RunFromPanic.PropagateViralBehaviorTo
// [0x00020802] 
struct UGameCrowdBehavior_RunFromPanic_eventPropagateViralBehaviorTo_Params
{
	class AGameCrowdAgent*                             OtherAgent;                                       // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameCrowdBehavior_RunFromPanic.StopBehavior
// [0x00020002] 
struct UGameCrowdBehavior_RunFromPanic_execStopBehavior_Params
{
};

// Function GameFramework.GameCrowdBehavior_RunFromPanic.InitBehavior
// [0x00020002] 
struct UGameCrowdBehavior_RunFromPanic_execInitBehavior_Params
{
	class AGameCrowdAgent*                             Agent;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameCrowdBehavior_RunFromPanic.ActivatedBy
// [0x00020002] 
struct UGameCrowdBehavior_RunFromPanic_execActivatedBy_Params
{
	class AActor*                                      NewActionTarget;                                  // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	// class AGameCrowdDestination*                    TempDest;                                         // 0x0004 (0x0004) [0x0000000000000000]               
	// class AGameCrowdDestination*                    PrevDest;                                         // 0x0008 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameCrowdBehavior_WaitForGroup.StopBehavior
// [0x00020002] 
struct UGameCrowdBehavior_WaitForGroup_execStopBehavior_Params
{
};

// Function GameFramework.GameCrowdBehavior_WaitForGroup.ShouldEndIdle
// [0x00020400] 
struct UGameCrowdBehavior_WaitForGroup_execShouldEndIdle_Params
{
	bool                                               ReturnValue : 1;                                  // 0x0000 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameCrowdBehavior_WaitForGroup.GetBehaviorString
// [0x00020002] 
struct UGameCrowdBehavior_WaitForGroup_execGetBehaviorString_Params
{
	class FString                                      ReturnValue;                                      // 0x0000 (0x000C) [0x0000000000400580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
	// class FString                                   BehaviorString;                                   // 0x000C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// Function GameFramework.GameCrowdBehavior_WaitForGroup.InitBehavior
// [0x00020002] 
struct UGameCrowdBehavior_WaitForGroup_execInitBehavior_Params
{
	class AGameCrowdAgent*                             Agent;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameCrowdBehavior_WaitInQueue.StopBehavior
// [0x00020002] 
struct UGameCrowdBehavior_WaitInQueue_execStopBehavior_Params
{
};

// Function GameFramework.GameCrowdBehavior_WaitInQueue.ShouldEndIdle
// [0x00020400] 
struct UGameCrowdBehavior_WaitInQueue_execShouldEndIdle_Params
{
	bool                                               ReturnValue : 1;                                  // 0x0000 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameCrowdBehavior_WaitInQueue.GetBehaviorString
// [0x00020002] 
struct UGameCrowdBehavior_WaitInQueue_execGetBehaviorString_Params
{
	class FString                                      ReturnValue;                                      // 0x0000 (0x000C) [0x0000000000400580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
};

// Function GameFramework.GameCrowdBehavior_WaitInQueue.GetDestinationActor
// [0x00020002] 
struct UGameCrowdBehavior_WaitInQueue_execGetDestinationActor_Params
{
	class AActor*                                      ReturnValue;                                      // 0x0000 (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameCrowdBehavior_WaitInQueue.ChangingDestination
// [0x00020002] 
struct UGameCrowdBehavior_WaitInQueue_execChangingDestination_Params
{
	class AGameCrowdDestination*                       NewDest;                                          // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameCrowdBehavior_WaitInQueue.HandleMovement
// [0x00020400] 
struct UGameCrowdBehavior_WaitInQueue_execHandleMovement_Params
{
	bool                                               ReturnValue : 1;                                  // 0x0000 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameCrowdGroup.UpdateDestinations
// [0x00020002] 
struct UGameCrowdGroup_execUpdateDestinations_Params
{
	class AGameCrowdDestination*                       NewDestination;                                   // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	// int32_t                                         I;                                                // 0x0004 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameCrowdGroup.RemoveMember
// [0x00020002] 
struct UGameCrowdGroup_execRemoveMember_Params
{
	class AGameCrowdAgent*                             Agent;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameCrowdGroup.AddMember
// [0x00020002] 
struct UGameCrowdGroup_execAddMember_Params
{
	class AGameCrowdAgent*                             Agent;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameCrowdInteractionPoint.OnToggle
// [0x00020002] 
struct AGameCrowdInteractionPoint_execOnToggle_Params
{
	class USeqAct_Toggle*                              Action;                                           // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameCrowdDestination.GetSpawnPosition
// [0x00C20102] 
struct AGameCrowdDestination_execGetSpawnPosition_Params
{
	class USeqAct_GameCrowdSpawner*                    Spawner;                                          // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FVector                                     SpawnPos;                                         // 0x0004 (0x000C) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
	struct FRotator                                    SpawnRot;                                         // 0x0010 (0x000C) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
	// struct FVector                                  SpawnLine;                                        // 0x001C (0x000C) [0x0000000000000000]               
	// float                                           RandScale;                                        // 0x0028 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameCrowdDestination.AllowableDestinationFor
// [0x00020902] 
struct AGameCrowdDestination_eventAllowableDestinationFor_Params
{
	class AGameCrowdAgent*                             Agent;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	bool                                               ReturnValue : 1;                                  // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
	// int32_t                                         I;                                                // 0x0008 (0x0004) [0x0000000000000000]               
	// int32_t                                         Num;                                              // 0x000C (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameCrowdDestination.AtCapacity
// [0x00020102] 
struct AGameCrowdDestination_execAtCapacity_Params
{
	bool                                               ReturnValue : 1;                                  // 0x0000 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameCrowdDestination.IncrementCustomerCount
// [0x00020902] 
struct AGameCrowdDestination_eventIncrementCustomerCount_Params
{
	class AGameCrowdAgent*                             ArrivingAgent;                                    // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameCrowdDestination.DecrementCustomerCount
// [0x00020902] 
struct AGameCrowdDestination_eventDecrementCustomerCount_Params
{
	class AGameCrowdAgent*                             DepartingAgent;                                   // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	// class AGameCrowdDestinationQueuePoint*          QP;                                               // 0x0004 (0x0004) [0x0000000000000000]               
	// uint32_t                                        bIsInQueue : 1;                                   // 0x0008 (0x0004) [0x0000000000000000] [0x00000001] 
};

// Function GameFramework.GameCrowdDestination.PickNewDestinationFor
// [0x00020102] 
struct AGameCrowdDestination_execPickNewDestinationFor_Params
{
	class AGameCrowdAgent*                             Agent;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	uint32_t                                           bIgnoreRestrictions : 1;                          // 0x0004 (0x0004) [0x0000000000000080] [0x00000001] (CPF_Parm)
	// int32_t                                         I;                                                // 0x0008 (0x0004) [0x0000000000000000]               
	// float                                           DestinationFrequencySum;                          // 0x000C (0x0004) [0x0000000000000000]               
	// float                                           DestinationPickValue;                             // 0x0010 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameCrowdDestination.ReachedDestination
// [0x00020902] 
struct AGameCrowdDestination_eventReachedDestination_Params
{
	class AGameCrowdAgent*                             Agent;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	// int32_t                                         I;                                                // 0x0004 (0x0004) [0x0000000000000000]               
	// int32_t                                         J;                                                // 0x0008 (0x0004) [0x0000000000000000]               
	// class USeqEvent_CrowdAgentReachedDestination*   ReachedEvent;                                     // 0x000C (0x0004) [0x0000000000000000]               
	// uint32_t                                        bEventActivated : 1;                              // 0x0010 (0x0004) [0x0000000000000000] [0x00000001] 
};

// Function GameFramework.GameCrowdDestination.Destroyed
// [0x00020102] 
struct AGameCrowdDestination_execDestroyed_Params
{
};

// Function GameFramework.GameCrowdDestination.PostBeginPlay
// [0x00020102] 
struct AGameCrowdDestination_execPostBeginPlay_Params
{
	// int32_t                                         I;                                                // 0x0000 (0x0004) [0x0000000000000000]               
	// class AGameCrowdPopulationManager*              PopMgr;                                           // 0x0004 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameCrowdDestination.ReachedByAgent
// [0x00020500] 
struct AGameCrowdDestination_execReachedByAgent_Params
{
	class AGameCrowdAgent*                             Agent;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FVector                                     TestPosition;                                     // 0x0004 (0x000C) [0x0000000000000080] (CPF_Parm)    
	uint32_t                                           bTestExactly : 1;                                 // 0x0010 (0x0004) [0x0000000000000080] [0x00000001] (CPF_Parm)
	uint32_t : 0;                                  // 0x0014 CLOSE BITFIELD STORAGE UNIT
	bool                                               ReturnValue : 1;                                  // 0x0014 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameCrowdDestinationQueuePoint.HasCustomer
// [0x00020102] 
struct AGameCrowdDestinationQueuePoint_execHasCustomer_Params
{
	bool                                               ReturnValue : 1;                                  // 0x0000 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameCrowdDestinationQueuePoint.ClearQueue
// [0x00020102] 
struct AGameCrowdDestinationQueuePoint_execClearQueue_Params
{
	class AGameCrowdAgent*                             OldCustomer;                                      // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameCrowdDestinationQueuePoint.AddCustomer
// [0x00020102] 
struct AGameCrowdDestinationQueuePoint_execAddCustomer_Params
{
	class AGameCrowdAgent*                             NewCustomer;                                      // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class AGameCrowdInteractionPoint*                  PreviousPosition;                                 // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameCrowdDestinationQueuePoint.ActuallyAdvance
// [0x00040103] 
struct AGameCrowdDestinationQueuePoint_execActuallyAdvance_Params
{
	// class AGameCrowdDestinationQueuePoint*          FrontQueuePosition;                               // 0x0000 (0x0004) [0x0000000000000000]               
	// class AGameCrowdDestination*                    QueueFront;                                       // 0x0004 (0x0004) [0x0000000000000000]               
	// class AGameCrowdAgent*                          TempAgent;                                        // 0x0008 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameCrowdDestinationQueuePoint.AdvanceCustomerTo
// [0x00020102] 
struct AGameCrowdDestinationQueuePoint_execAdvanceCustomerTo_Params
{
	class AGameCrowdInteractionPoint*                  FrontPosition;                                    // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameCrowdDestinationQueuePoint.ReachedDestination
// [0x00020902] 
struct AGameCrowdDestinationQueuePoint_eventReachedDestination_Params
{
	class AGameCrowdAgent*                             Agent;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	// class AGameCrowdDestinationQueuePoint*          QueuePoint;                                       // 0x0004 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameCrowdDestinationQueuePoint.HasSpace
// [0x00020102] 
struct AGameCrowdDestinationQueuePoint_execHasSpace_Params
{
	bool                                               ReturnValue : 1;                                  // 0x0000 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameCrowdDestinationQueuePoint.QueueReachedBy
// [0x00020400] 
struct AGameCrowdDestinationQueuePoint_execQueueReachedBy_Params
{
	class AGameCrowdAgent*                             Agent;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FVector                                     TestPosition;                                     // 0x0004 (0x000C) [0x0000000000000080] (CPF_Parm)    
	bool                                               ReturnValue : 1;                                  // 0x0010 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameCrowdForcePoint.AppliedForce
// [0x00020800] 
struct AGameCrowdForcePoint_eventAppliedForce_Params
{
	class AGameCrowdAgent*                             Agent;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FVector                                     ReturnValue;                                      // 0x0004 (0x000C) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameCrowdForcePoint.UnTouch
// [0x00020802] 
struct AGameCrowdForcePoint_eventUnTouch_Params
{
	class AActor*                                      Other;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	// class AGameCrowdAgent*                          Agent;                                            // 0x0004 (0x0004) [0x0000000000000000]               
	// int32_t                                         I;                                                // 0x0008 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameCrowdForcePoint.Touch
// [0x00020802] 
struct AGameCrowdForcePoint_eventTouch_Params
{
	class AActor*                                      Other;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class UPrimitiveComponent*                         OtherComp;                                        // 0x0004 (0x0004) [0x0000000004000080] (CPF_Parm | CPF_EditInline)
	struct FVector                                     HitLocation;                                      // 0x0008 (0x000C) [0x0000000000000080] (CPF_Parm)    
	struct FVector                                     HitNormal;                                        // 0x0014 (0x000C) [0x0000000000000080] (CPF_Parm)    
	// class AGameCrowdAgent*                          Agent;                                            // 0x0020 (0x0004) [0x0000000000000000]               
	// int32_t                                         I;                                                // 0x0024 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameCrowdAttractor.AppliedForce
// [0x00820802] 
struct AGameCrowdAttractor_eventAppliedForce_Params
{
	class AGameCrowdAgent*                             Agent;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FVector                                     ReturnValue;                                      // 0x0004 (0x000C) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
	// struct FVector                                  ToAttractor;                                      // 0x0010 (0x000C) [0x0000000000000000]               
	// float                                           CurrentAttraction;                                // 0x001C (0x0004) [0x0000000000000000]               
	// float                                           Distance;                                         // 0x0020 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameCrowdRepulsor.AppliedForce
// [0x00820802] 
struct AGameCrowdRepulsor_eventAppliedForce_Params
{
	class AGameCrowdAgent*                             Agent;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FVector                                     ReturnValue;                                      // 0x0004 (0x000C) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
	// struct FVector                                  FromAttractor;                                    // 0x0010 (0x000C) [0x0000000000000000]               
	// float                                           CurrentRepulsion;                                 // 0x001C (0x0004) [0x0000000000000000]               
	// float                                           Distance;                                         // 0x0020 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameCrowdPopulationManager.CreateNewAgent
// [0x00820002] 
struct AGameCrowdPopulationManager_execCreateNewAgent_Params
{
	class AGameCrowdDestination*                       SpawnLoc;                                         // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class AGameCrowdAgent*                             AgentTemplate;                                    // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class UGameCrowdGroup*                             NewGroup;                                         // 0x0008 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class AGameCrowdAgent*                             ReturnValue;                                      // 0x000C (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
	// class AGameCrowdAgent*                          Agent;                                            // 0x0010 (0x0004) [0x0000000000000000]               
	// class AGameCrowdAgentSkeletal*                  SkAgent;                                          // 0x0014 (0x0004) [0x0000000000000000]               
	// struct FRotator                                 SpawnRot;                                         // 0x0018 (0x000C) [0x0000000000000000]               
	// struct FVector                                  SpawnPos;                                         // 0x0024 (0x000C) [0x0000000000000000]               
	// int32_t                                         I;                                                // 0x0030 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameCrowdPopulationManager.SpawnAgent
// [0x00020802] 
struct AGameCrowdPopulationManager_eventSpawnAgent_Params
{
	class AGameCrowdDestination*                       SpawnLoc;                                         // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class AGameCrowdAgent*                             ReturnValue;                                      // 0x0004 (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
	// class AGameCrowdAgent*                          Agent;                                            // 0x0008 (0x0004) [0x0000000000000000]               
	// float                                           AgentPickValue;                                   // 0x000C (0x0004) [0x0000000000000000]               
	// float                                           PickSum;                                          // 0x0010 (0x0004) [0x0000000000000000]               
	// int32_t                                         I;                                                // 0x0014 (0x0004) [0x0000000000000000]               
	// int32_t                                         PickedInfo;                                       // 0x0018 (0x0004) [0x0000000000000000]               
	// class AGameCrowdAgent*                          AgentTemplate;                                    // 0x001C (0x0004) [0x0000000000000000]               
	// class UGameCrowdGroup*                          NewGroup;                                         // 0x0020 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameCrowdPopulationManager.ValidateSpawnAt
// [0x00820002] 
struct AGameCrowdPopulationManager_execValidateSpawnAt_Params
{
	class AGameCrowdDestination*                       Candidate;                                        // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	bool                                               ReturnValue : 1;                                  // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
	// class AActor*                                   HitActor;                                         // 0x0008 (0x0004) [0x0000000000000000]               
	// struct FVector                                  HitLocation;                                      // 0x000C (0x000C) [0x0000000000000000]               
	// struct FVector                                  HitNormal;                                        // 0x0018 (0x000C) [0x0000000000000000]               
	// struct FVector                                  ViewLocation;                                     // 0x0024 (0x000C) [0x0000000000000000]               
	// struct FRotator                                 ViewRotation;                                     // 0x0030 (0x000C) [0x0000000000000000]               
	// class APlayerController*                        PC;                                               // 0x003C (0x0004) [0x0000000000000000]               
	// float                                           DistSq;                                           // 0x0040 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameCrowdPopulationManager.AddPrioritizedSpawnPoint
// [0x00020002] 
struct AGameCrowdPopulationManager_execAddPrioritizedSpawnPoint_Params
{
	class AGameCrowdDestination*                       GCD;                                              // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FVector                                     ViewLocation;                                     // 0x0004 (0x000C) [0x0000000000000080] (CPF_Parm)    
	// int32_t                                         I;                                                // 0x0010 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameCrowdPopulationManager.AnalyzeSpawnPoints
// [0x00820002] 
struct AGameCrowdPopulationManager_execAnalyzeSpawnPoints_Params
{
	int32_t                                            StartIndex;                                       // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	int32_t                                            StopIndex;                                        // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FVector                                     ViewLocation;                                     // 0x0008 (0x000C) [0x0000000000000080] (CPF_Parm)    
	struct FVector                                     PredictionLocation;                               // 0x0014 (0x000C) [0x0000000000000080] (CPF_Parm)    
	// class AActor*                                   HitActor;                                         // 0x0020 (0x0004) [0x0000000000000000]               
	// int32_t                                         I;                                                // 0x0024 (0x0004) [0x0000000000000000]               
	// int32_t                                         J;                                                // 0x0028 (0x0004) [0x0000000000000000]               
	// class AGameCrowdDestination*                    GCD;                                              // 0x002C (0x0004) [0x0000000000000000]               
	// class AGameCrowdDestination*                    NextGCD;                                          // 0x0030 (0x0004) [0x0000000000000000]               
	// struct FVector                                  HitLocation;                                      // 0x0034 (0x000C) [0x0000000000000000]               
	// struct FVector                                  HitNormal;                                        // 0x0040 (0x000C) [0x0000000000000000]               
};

// Function GameFramework.GameCrowdPopulationManager.PrioritizeSpawnPoints
// [0x00820002] 
struct AGameCrowdPopulationManager_execPrioritizeSpawnPoints_Params
{
	float                                              DeltaSeconds;                                     // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	// class AActor*                                   HitActor;                                         // 0x0004 (0x0004) [0x0000000000000000]               
	// struct FVector                                  HitLocation;                                      // 0x0008 (0x000C) [0x0000000000000000]               
	// struct FVector                                  HitNormal;                                        // 0x0014 (0x000C) [0x0000000000000000]               
	// struct FVector                                  ViewLocation;                                     // 0x0020 (0x000C) [0x0000000000000000]               
	// struct FVector                                  PredictionLocation;                               // 0x002C (0x000C) [0x0000000000000000]               
	// class APlayerController*                        PC;                                               // 0x0038 (0x0004) [0x0000000000000000]               
	// int32_t                                         UpdateNum;                                        // 0x003C (0x0004) [0x0000000000000000]               
	// struct FRotator                                 ViewRotation;                                     // 0x0040 (0x000C) [0x0000000000000000]               
};

// Function GameFramework.GameCrowdPopulationManager.PickSpawnPoint
// [0x00020002] 
struct AGameCrowdPopulationManager_execPickSpawnPoint_Params
{
	class AGameCrowdDestination*                       ReturnValue;                                      // 0x0000 (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
	// int32_t                                         StartingIndex;                                    // 0x0004 (0x0004) [0x0000000000000000]               
	// class AGameCrowdDestination*                    Candidate;                                        // 0x0008 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameCrowdPopulationManager.Tick
// [0x00020002] 
struct AGameCrowdPopulationManager_execTick_Params
{
	float                                              DeltaSeconds;                                     // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	// class AGameCrowdDestination*                    PickedSpawnPoint;                                 // 0x0004 (0x0004) [0x0000000000000000]               
	// float                                           CurrentSpawnRate;                                 // 0x0008 (0x0004) [0x0000000000000000]               
	// uint32_t                                        bSpawnedAgent : 1;                                // 0x000C (0x0004) [0x0000000000000000] [0x00000001] 
};

// Function GameFramework.GameCrowdPopulationManager.DisplayDebug
// [0x00C20102] 
struct AGameCrowdPopulationManager_execDisplayDebug_Params
{
	class AHUD*                                        HUD;                                              // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	float                                              out_YL;                                           // 0x0004 (0x0004) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
	float                                              out_YPos;                                         // 0x0008 (0x0004) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
	// class UCanvas*                                  Canvas;                                           // 0x000C (0x0004) [0x0000000000000000]               
	// int32_t                                         RenderedNum;                                      // 0x0010 (0x0004) [0x0000000000000000]               
	// int32_t                                         LOSNum;                                           // 0x0014 (0x0004) [0x0000000000000000]               
	// int32_t                                         SimNum;                                           // 0x0018 (0x0004) [0x0000000000000000]               
	// int32_t                                         ActualCount;                                      // 0x001C (0x0004) [0x0000000000000000]               
	// int32_t                                         WTFNum;                                           // 0x0020 (0x0004) [0x0000000000000000]               
	// int32_t                                         DistanceBucket[10];                               // 0x0024 (0x0028) [0x0000000000000000]               
	// int32_t                                         I;                                                // 0x004C (0x0004) [0x0000000000000000]               
	// class AActor*                                   HitActor;                                         // 0x0050 (0x0004) [0x0000000000000000]               
	// struct FVector                                  HitNormal;                                        // 0x0054 (0x000C) [0x0000000000000000]               
	// struct FVector                                  HitLocation;                                      // 0x0060 (0x000C) [0x0000000000000000]               
	// struct FVector                                  ViewLocation;                                     // 0x006C (0x000C) [0x0000000000000000]               
	// struct FRotator                                 ViewRotation;                                     // 0x0078 (0x000C) [0x0000000000000000]               
	// class APlayerController*                        PC;                                               // 0x0084 (0x0004) [0x0000000000000000]               
	// class AGameCrowdAgent*                          GCD;                                              // 0x0088 (0x0004) [0x0000000000000000]               
	// float                                           Dist;                                             // 0x008C (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameCrowdPopulationManager.AddToAgentPool
// [0x00020002] 
struct AGameCrowdPopulationManager_execAddToAgentPool_Params
{
	class AGameCrowdAgent*                             Agent;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	bool                                               ReturnValue : 1;                                  // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameCrowdPopulationManager.AgentDestroyed
// [0x00020002] 
struct AGameCrowdPopulationManager_execAgentDestroyed_Params
{
	class AGameCrowdAgent*                             Agent;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameCrowdPopulationManager.OnGameCrowdPopulationManagerToggle
// [0x00020002] 
struct AGameCrowdPopulationManager_execOnGameCrowdPopulationManagerToggle_Params
{
	class USeqAct_GameCrowdPopulationManagerToggle*    inAction;                                         // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	// class AGameCrowdAgent*                          Agent;                                            // 0x0004 (0x0004) [0x0000000000000000]               
	// int32_t                                         I;                                                // 0x0008 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameCrowdPopulationManager.RemoveSpawnPoint
// [0x00020002] 
struct AGameCrowdPopulationManager_execRemoveSpawnPoint_Params
{
	class AGameCrowdDestination*                       GCD;                                              // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameCrowdPopulationManager.AddSpawnPoint
// [0x00820002] 
struct AGameCrowdPopulationManager_execAddSpawnPoint_Params
{
	class AGameCrowdDestination*                       GCD;                                              // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	// class AActor*                                   HitActor;                                         // 0x0004 (0x0004) [0x0000000000000000]               
	// struct FVector                                  HitLocation;                                      // 0x0008 (0x000C) [0x0000000000000000]               
	// struct FVector                                  HitNormal;                                        // 0x0014 (0x000C) [0x0000000000000000]               
	// int32_t                                         J;                                                // 0x0020 (0x0004) [0x0000000000000000]               
	// uint32_t                                        bInsertedSpawnPoint : 1;                          // 0x0024 (0x0004) [0x0000000000000000] [0x00000001] 
	// struct FVector                                  ViewLocation;                                     // 0x0028 (0x000C) [0x0000000000000000]               
	// struct FVector                                  PredictionLocation;                               // 0x0034 (0x000C) [0x0000000000000000]               
	// struct FRotator                                 ViewRotation;                                     // 0x0040 (0x000C) [0x0000000000000000]               
	// class APlayerController*                        PC;                                               // 0x004C (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameCrowdPopulationManager.GetMaxSpawnDist
// [0x00020002] 
struct AGameCrowdPopulationManager_execGetMaxSpawnDist_Params
{
	float                                              ReturnValue;                                      // 0x0000 (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameCrowdPopulationManager.NotifyPathChanged
// [0x00020800] 
struct AGameCrowdPopulationManager_eventNotifyPathChanged_Params
{
};

// Function GameFramework.GameCrowdPopulationManager.PostBeginPlay
// [0x00020002] 
struct AGameCrowdPopulationManager_execPostBeginPlay_Params
{
	// class AGameCrowdDestination*                    GCD;                                              // 0x0000 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameCrowdReplicationActor.ReplicatedEvent
// [0x00020902] 
struct AGameCrowdReplicationActor_eventReplicatedEvent_Params
{
	class FName                                        VarName;                                          // 0x0000 (0x0008) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameDamageType.HandleDamageFX
// [0x00422000] 
struct UGameDamageType_execHandleDamageFX_Params
{
	class AGamePawn*                                   DamagedPawn;                                      // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FTakeHitInfo                                HitInfo;                                          // 0x0004 (0x0038) [0x0000000000000182] (CPF_Const | CPF_Parm | CPF_OutParm)
};

// Function GameFramework.GameDamageType.ShouldHeadShotGib
// [0x00022002] 
struct UGameDamageType_execShouldHeadShotGib_Params
{
	class APawn*                                       TestPawn;                                         // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class APawn*                                       Instigator;                                       // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
	bool                                               ReturnValue : 1;                                  // 0x0008 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
	// class AGamePawn*                                GP;                                               // 0x000C (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameDamageType.PlayExtraDamageSound
// [0x00022002] 
struct UGameDamageType_execPlayExtraDamageSound_Params
{
	class APawn*                                       VictimPawn;                                       // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameDamageType.IsScriptedDamageType
// [0x00022002] 
struct UGameDamageType_execIsScriptedDamageType_Params
{
	bool                                               ReturnValue : 1;                                  // 0x0000 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameDamageType.ShouldPlayForceFeedback
// [0x00022002] 
struct UGameDamageType_execShouldPlayForceFeedback_Params
{
	class APawn*                                       DamagedPawn;                                      // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	bool                                               ReturnValue : 1;                                  // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameDamageType.HandleDeadPlayer
// [0x00022000] 
struct UGameDamageType_execHandleDeadPlayer_Params
{
	class AGamePlayerController*                       Player;                                           // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameDamageType.HandleKilledPawn
// [0x00022000] 
struct UGameDamageType_execHandleKilledPawn_Params
{
	class APawn*                                       KilledPawn;                                       // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class APawn*                                       Instigator;                                       // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameDamageType.HandleDamagedPawn
// [0x00022000] 
struct UGameDamageType_execHandleDamagedPawn_Params
{
	class APawn*                                       DamagedPawn;                                      // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class APawn*                                       Instigator;                                       // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
	int32_t                                            DamageAmt;                                        // 0x0008 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FVector                                     Momentum;                                         // 0x000C (0x000C) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameDamageType.ModifyDamage
// [0x00422000] 
struct UGameDamageType_execModifyDamage_Params
{
	class APawn*                                       Victim;                                           // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class AController*                                 InstigatedBy;                                     // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
	int32_t                                            out_Damage;                                       // 0x0008 (0x0004) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
	struct FVector                                     out_Momentum;                                     // 0x000C (0x000C) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
	struct FVector                                     HitLocation;                                      // 0x0018 (0x000C) [0x0000000000000080] (CPF_Parm)    
	struct FTraceHitInfo                               HitInfo;                                          // 0x0024 (0x001C) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameDamageType.ShouldGib
// [0x00022002] 
struct UGameDamageType_execShouldGib_Params
{
	class APawn*                                       TestPawn;                                         // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class APawn*                                       Instigator;                                       // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
	bool                                               ReturnValue : 1;                                  // 0x0008 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameExplosionActor.ChooseCameraShake
// [0x00880102] 
struct AGameExplosionActor_execChooseCameraShake_Params
{
	struct FVector                                     Epicenter;                                        // 0x0000 (0x000C) [0x0000000000000080] (CPF_Parm)    
	class APlayerController*                           PC;                                               // 0x000C (0x0004) [0x0000000000000080] (CPF_Parm)    
	class UCameraShake*                                ReturnValue;                                      // 0x0010 (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
	// struct FVector                                  CamX;                                             // 0x0014 (0x000C) [0x0000000000000000]               
	// struct FVector                                  CamY;                                             // 0x0020 (0x000C) [0x0000000000000000]               
	// struct FVector                                  CamZ;                                             // 0x002C (0x000C) [0x0000000000000000]               
	// struct FVector                                  ToEpicenter;                                      // 0x0038 (0x000C) [0x0000000000000000]               
	// float                                           FwdDot;                                           // 0x0044 (0x0004) [0x0000000000000000]               
	// float                                           RtDot;                                            // 0x0048 (0x0004) [0x0000000000000000]               
	// class UCameraShake*                             ChosenShake;                                      // 0x004C (0x0004) [0x0000000000000000]               
	// struct FRotator                                 NoPitchRot;                                       // 0x0050 (0x000C) [0x0000000000000000]               
};

// Function GameFramework.GameExplosionActor.SpawnCameraLensEffects
// [0x00020102] 
struct AGameExplosionActor_execSpawnCameraLensEffects_Params
{
	// class APlayerController*                        PC;                                               // 0x0000 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameExplosionActor.DoExplosionCameraEffects
// [0x00020102] 
struct AGameExplosionActor_execDoExplosionCameraEffects_Params
{
	// class UCameraShake*                             Shake;                                            // 0x0000 (0x0004) [0x0000000000000000]               
	// float                                           ShakeScale;                                       // 0x0004 (0x0004) [0x0000000000000000]               
	// class APlayerController*                        PC;                                               // 0x0008 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameExplosionActor.Tick
// [0x00020102] 
struct AGameExplosionActor_execTick_Params
{
	float                                              DeltaTime;                                        // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	// float                                           Pct;                                              // 0x0004 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameExplosionActor.DoExplosionDamage
// [0x00020102] 
struct AGameExplosionActor_execDoExplosionDamage_Params
{
};

// Function GameFramework.GameExplosionActor.DrawDebug
// [0x00820102] 
struct AGameExplosionActor_execDrawDebug_Params
{
	// struct FColor                                   C;                                                // 0x0000 (0x0004) [0x0000000000000000]               
	// float                                           Angle;                                            // 0x0004 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameExplosionActor.Explode
// [0x00024102] 
struct AGameExplosionActor_execExplode_Params
{
	class UGameExplosion*                              NewExplosionTemplate;                             // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FVector                                     Direction;                                        // 0x0004 (0x000C) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
	// float                                           HowLongToLive;                                    // 0x0010 (0x0004) [0x0000000000000000]               
	// class UPhysicalMaterial*                        PhysMat;                                          // 0x0014 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameExplosionActor.SpawnExplosionFogVolume
// [0x00020100] 
struct AGameExplosionActor_execSpawnExplosionFogVolume_Params
{
};

// Function GameFramework.GameExplosionActor.SpawnExplosionDecal
// [0x00020100] 
struct AGameExplosionActor_execSpawnExplosionDecal_Params
{
};

// Function GameFramework.GameExplosionActor.SpawnExplosionParticleSystem
// [0x00020100] 
struct AGameExplosionActor_execSpawnExplosionParticleSystem_Params
{
	class UParticleSystem*                             Template;                                         // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameExplosionActor.UpdateExplosionTemplateWithPerMaterialFX
// [0x00080100] 
struct AGameExplosionActor_execUpdateExplosionTemplateWithPerMaterialFX_Params
{
	class UPhysicalMaterial*                           PhysMaterial;                                     // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameExplosionActor.KnockdownPawn
// [0x00080002] 
struct AGameExplosionActor_execKnockdownPawn_Params
{
	class AGamePawn*                                   Victim;                                           // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	float                                              DistFromExplosion;                                // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameExplosionActor.CringePawn
// [0x00080002] 
struct AGameExplosionActor_execCringePawn_Params
{
	class AGamePawn*                                   Victim;                                           // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	float                                              DistFromExplosion;                                // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
	// float                                           CringeTime;                                       // 0x0008 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameExplosionActor.DoCringesAndKnockdowns
// [0x00880002] 
struct AGameExplosionActor_execDoCringesAndKnockdowns_Params
{
	// class AGamePawn*                                Victim;                                           // 0x0000 (0x0004) [0x0000000000000000]               
	// float                                           DistFromExplosion;                                // 0x0004 (0x0004) [0x0000000000000000]               
	// struct FVector                                  ExplosionToVictimDir;                             // 0x0008 (0x000C) [0x0000000000000000]               
	// float                                           KnockDownRad;                                     // 0x0014 (0x0004) [0x0000000000000000]               
	// float                                           CringeRad;                                        // 0x0018 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameExplosionActor.ShouldDoCringeFor
// [0x00080002] 
struct AGameExplosionActor_execShouldDoCringeFor_Params
{
	class AGamePawn*                                   Victim;                                           // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	bool                                               ReturnValue : 1;                                  // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameExplosionActor.DoBreakFracturedMeshes
// [0x00080102] 
struct AGameExplosionActor_execDoBreakFracturedMeshes_Params
{
	struct FVector                                     ExploOrigin;                                      // 0x0000 (0x000C) [0x0000000000000080] (CPF_Parm)    
	float                                              DamageRadius;                                     // 0x000C (0x0004) [0x0000000000000080] (CPF_Parm)    
	float                                              RBStrength;                                       // 0x0010 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class UClass*                                      dmgType;                                          // 0x0014 (0x0004) [0x0000000000000080] (CPF_Parm)    
	// class AFracturedStaticMeshActor*                FracActor;                                        // 0x0018 (0x0004) [0x0000000000000000]               
	// uint8_t                                         bWantPhysChunksAndParticles;                      // 0x001C (0x0001) [0x0000000000000000]               
};

// Function GameFramework.GameExplosionActor.HurtExplosion
// [0x00880102] 
struct AGameExplosionActor_execHurtExplosion_Params
{
	float                                              BaseDamage;                                       // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	float                                              DamageRadius;                                     // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
	float                                              DamageFalloffExp;                                 // 0x0008 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class UClass*                                      DamageType;                                       // 0x000C (0x0004) [0x0000000000000080] (CPF_Parm)    
	float                                              MomentumScale;                                    // 0x0010 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FVector                                     ExploOrigin;                                      // 0x0014 (0x000C) [0x0000000000000080] (CPF_Parm)    
	class AActor*                                      IgnoredActor;                                     // 0x0020 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class UClass*                                      ActorClassToIgnoreForDamage;                      // 0x0024 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class AController*                                 InstigatedByController;                           // 0x0028 (0x0004) [0x0000000000000080] (CPF_Parm)    
	uint32_t                                           bDoFullDamage : 1;                                // 0x002C (0x0004) [0x0000000000000080] [0x00000001] (CPF_Parm)
	// class AActor*                                   Victim;                                           // 0x0030 (0x0004) [0x0000000000000000]               
	// class AActor*                                   HitActor;                                         // 0x0034 (0x0004) [0x0000000000000000]               
	// struct FVector                                  HitL;                                             // 0x0038 (0x000C) [0x0000000000000000]               
	// struct FVector                                  HitN;                                             // 0x0044 (0x000C) [0x0000000000000000]               
	// struct FVector                                  Dir;                                              // 0x0050 (0x000C) [0x0000000000000000]               
	// uint32_t                                        bDamageBlocked : 1;                               // 0x005C (0x0004) [0x0000000000000000] [0x00000001] 
	// float                                           ColRadius;                                        // 0x0060 (0x0004) [0x0000000000000000]               
	// float                                           ColHeight;                                        // 0x0064 (0x0004) [0x0000000000000000]               
	// class TArray<class AActor*>                     VictimsList;                                      // 0x0068 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	// struct FBox                                     BBox;                                             // 0x0074 (0x001C) [0x0000000000000000]               
	// struct FVector                                  BBoxCenter;                                       // 0x0090 (0x000C) [0x0000000000000000]               
	// class AController*                              ModInstigator;                                    // 0x009C (0x0004) [0x0000000000000000]               
	// class APawn*                                    VictimPawn;                                       // 0x00A0 (0x0004) [0x0000000000000000]               
	// class UClass*                                   ModDamageType;                                    // 0x00A4 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameExplosionActor.IsBehindExplosion
// [0x00080102] 
struct AGameExplosionActor_execIsBehindExplosion_Params
{
	class AActor*                                      A;                                                // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	bool                                               ReturnValue : 1;                                  // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameExplosionActor.DoFullDamageToActor
// [0x00020102] 
struct AGameExplosionActor_execDoFullDamageToActor_Params
{
	class AActor*                                      Victim;                                           // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	bool                                               ReturnValue : 1;                                  // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameExplosionActor.GetPhysicalMaterial
// [0x00880102] 
struct AGameExplosionActor_execGetPhysicalMaterial_Params
{
	class UPhysicalMaterial*                           ReturnValue;                                      // 0x0000 (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
	// class UPhysicalMaterial*                        retval;                                           // 0x0004 (0x0004) [0x0000000000000000]               
	// struct FVector                                  TraceStart;                                       // 0x0008 (0x000C) [0x0000000000000000]               
	// struct FVector                                  TraceDest;                                        // 0x0014 (0x000C) [0x0000000000000000]               
	// struct FVector                                  OutHitNorm;                                       // 0x0020 (0x000C) [0x0000000000000000]               
	// struct FVector                                  ExploNormal;                                      // 0x002C (0x000C) [0x0000000000000000]               
	// struct FTraceHitInfo                            OutHitInfo;                                       // 0x0038 (0x001C) [0x0000000000000000]               
};

// Function GameFramework.GameExplosionActor.PreBeginPlay
// [0x00020802] 
struct AGameExplosionActor_eventPreBeginPlay_Params
{
};

// Function GameFramework.MobileHUD.ResetMobileInputConfig
// [0x00020202] 
struct AMobileHUD_execResetMobileInputConfig_Params
{
};

// Function GameFramework.MobileHUD.NextMobileInputConfig
// [0x00020202] 
struct AMobileHUD_execNextMobileInputConfig_Params
{
};

// Function GameFramework.MobileHUD.DrawInputOverlays
// [0x00820002] 
struct AMobileHUD_execDrawInputOverlays_Params
{
	// int32_t                                         ZoneIndex;                                        // 0x0000 (0x0004) [0x0000000000000000]               
	// float                                           TextX;                                            // 0x0004 (0x0004) [0x0000000000000000]               
	// float                                           TextY;                                            // 0x0008 (0x0004) [0x0000000000000000]               
	// struct FMobileInputZone                         Zone;                                             // 0x000C (0x005C) [0x0000000000400000] (CPF_NeedCtorLink)
	// int32_t                                         ZoneAdjustedX;                                    // 0x0068 (0x0004) [0x0000000000000000]               
	// int32_t                                         ZoneAdjustedY;                                    // 0x006C (0x0004) [0x0000000000000000]               
	// int32_t                                         ZoneAdjustedSizeX;                                // 0x0070 (0x0004) [0x0000000000000000]               
	// int32_t                                         ZoneAdjustedSizeY;                                // 0x0074 (0x0004) [0x0000000000000000]               
	// float                                           ClampedX;                                         // 0x0078 (0x0004) [0x0000000000000000]               
	// float                                           ClampedY;                                         // 0x007C (0x0004) [0x0000000000000000]               
	// float                                           Scale;                                            // 0x0080 (0x0004) [0x0000000000000000]               
	// class UTexture2D*                               BackgroundTexture;                                // 0x0084 (0x0004) [0x0000000000000000]               
	// struct FColor                                   LineColor;                                        // 0x0088 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.MobileHUD.PostRender
// [0x00020002] 
struct AMobileHUD_execPostRender_Params
{
};

// Function GameFramework.MobileHUD.PostBeginPlay
// [0x00020102] 
struct AMobileHUD_execPostBeginPlay_Params
{
	// int32_t                                         ZoneIndex;                                        // 0x0000 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GamePawn.SphinxNotifyDestory
// [0x00020800] 
struct AGamePawn_eventSphinxNotifyDestory_Params
{
};

// Function GameFramework.GamePawn.PlayCustomParticleOnSocket
// [0x00820802] 
struct AGamePawn_eventPlayCustomParticleOnSocket_Params
{
	class UParticleSystem*                             PS;                                               // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class FName                                        Socket;                                           // 0x0004 (0x0008) [0x0000000000000080] (CPF_Parm)    
	// class UParticleSystemComponent*                 CustomParticleSC;                                 // 0x000C (0x0004) [0x0000000004000000] (CPF_EditInline)
	// struct FVector                                  SocketLoc;                                        // 0x0010 (0x000C) [0x0000000000000000]               
	// struct FRotator                                 SocketRotator;                                    // 0x001C (0x000C) [0x0000000000000000]               
};

// Function GameFramework.GamePawn.ReattachMeshWithoutBeingSeen
// [0x00020102] 
struct AGamePawn_execReattachMeshWithoutBeingSeen_Params
{
};

// Function GameFramework.GamePawn.ReattachMesh
// [0x00020102] 
struct AGamePawn_execReattachMesh_Params
{
};

// Function GameFramework.GamePawn.UpdateShadowSettings
// [0x00020902] 
struct AGamePawn_eventUpdateShadowSettings_Params
{
	uint32_t                                           bInWantShadow : 1;                                // 0x0000 (0x0004) [0x0000000000000080] [0x00000001] (CPF_Parm)
	// uint32_t                                        bNewCastShadow : 1;                               // 0x0004 (0x0004) [0x0000000000000000] [0x00000001] 
	// uint32_t                                        bNewCastDynamicShadow : 1;                        // 0x0008 (0x0004) [0x0000000000000000] [0x00000001] 
};

// Function GameFramework.GamePawn.Cringe
// [0x00024800] 
struct AGamePawn_eventCringe_Params
{
	float                                              Duration;                                         // 0x0000 (0x0004) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
};

// Function GameFramework.GamePawn.ServerKnockdown
// [0x002240C0] 
struct AGamePawn_execServerKnockdown_Params
{
	struct FVector                                     RBLinearVelocity;                                 // 0x0000 (0x000C) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
	struct FVector                                     RBAngularVelocity;                                // 0x000C (0x000C) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
	struct FVector                                     RadialOrigin;                                     // 0x0018 (0x000C) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
	float                                              RadialRadius;                                     // 0x0024 (0x0004) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
	float                                              RadialStrength;                                   // 0x0028 (0x0004) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
	struct FVector                                     PointImpulse;                                     // 0x002C (0x000C) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
	struct FVector                                     PointImpulsePosition;                             // 0x0038 (0x000C) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
	class FName                                        PointImpulseBoneName;                             // 0x0044 (0x0008) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
};

// Function GameFramework.GamePawn.GetTargetFrictionCylinder
// [0x00420102] 
struct AGamePawn_execGetTargetFrictionCylinder_Params
{
	float                                              CylinderRadius;                                   // 0x0000 (0x0004) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
	float                                              CylinderHeight;                                   // 0x0004 (0x0004) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
};

// Function GameFramework.GamePawn.StopAllConfigAnim
// [0x00024400] 
struct AGamePawn_execStopAllConfigAnim_Params
{
	float                                              BlendOutTime;                                     // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	uint32_t                                           bForceStop : 1;                                   // 0x0004 (0x0004) [0x0000000000000090] [0x00000001] (CPF_OptionalParm | CPF_Parm)
	uint32_t : 0;                                  // 0x0008 CLOSE BITFIELD STORAGE UNIT
	uint32_t                                           bForceAnimNotify : 1;                             // 0x0008 (0x0004) [0x0000000000000090] [0x00000001] (CPF_OptionalParm | CPF_Parm)
	uint32_t : 0;                                  // 0x000C CLOSE BITFIELD STORAGE UNIT
	uint32_t                                           bForceAnimEnd : 1;                                // 0x000C (0x0004) [0x0000000000000090] [0x00000001] (CPF_OptionalParm | CPF_Parm)
};

// Function GameFramework.GamePlayerController.ClientColorFade
// [0x010201C0] 
struct AGamePlayerController_execClientColorFade_Params
{
	struct FColor                                      FadeColor;                                        // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	uint8_t                                            FromAlpha;                                        // 0x0004 (0x0001) [0x0000000000000080] (CPF_Parm)    
	uint8_t                                            ToAlpha;                                          // 0x0005 (0x0001) [0x0000000000000080] (CPF_Parm)    
	uint8_t                                            UnknownData00[0x2];                              // 0x0006 (0x0002) MISSED OFFSET
	float                                              FadeTime;                                         // 0x0008 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GamePlayerController.WarmupPause
// [0x00820802] 
struct AGamePlayerController_eventWarmupPause_Params
{
	uint32_t                                           bDesiredPauseState : 1;                           // 0x0000 (0x0004) [0x0000000000000080] [0x00000001] (CPF_Parm)
	// struct FColor                                   FadeColor;                                        // 0x0004 (0x0004) [0x0000000000000000]               
	// class APlayerController*                        PC;                                               // 0x0008 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GamePlayerController.CanUnpauseWarmup
// [0x00020002] 
struct AGamePlayerController_execCanUnpauseWarmup_Params
{
	bool                                               ReturnValue : 1;                                  // 0x0000 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GamePlayerController.GetCurrentMovie
// [0x00420401] 
struct AGamePlayerController_execGetCurrentMovie_Params
{
	class FString                                      MovieName;                                        // 0x0000 (0x000C) [0x0000000000400180] (CPF_Parm | CPF_OutParm | CPF_NeedCtorLink)
};

// Function GameFramework.GamePlayerController.ClientStopMovie
// [0x01020DC1] 
struct AGamePlayerController_eventClientStopMovie_Params
{
	float                                              DelayInSeconds;                                   // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	uint32_t                                           bAllowMovieToFinish : 1;                          // 0x0004 (0x0004) [0x0000000000000080] [0x00000001] (CPF_Parm)
	uint32_t : 0;                                  // 0x0008 CLOSE BITFIELD STORAGE UNIT
	uint32_t                                           bForceStopNonSkippable : 1;                       // 0x0008 (0x0004) [0x0000000000000080] [0x00000001] (CPF_Parm)
	uint32_t : 0;                                  // 0x000C CLOSE BITFIELD STORAGE UNIT
	uint32_t                                           bForceStopLoadingMovie : 1;                       // 0x000C (0x0004) [0x0000000000000080] [0x00000001] (CPF_Parm)
};

// Function GameFramework.GamePlayerController.ClientPlayMovie
// [0x01024DC1] 
struct AGamePlayerController_eventClientPlayMovie_Params
{
	class FString                                      MovieName;                                        // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	int32_t                                            InStartOfRenderingMovieFrame;                     // 0x000C (0x0004) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
	int32_t                                            InEndOfRenderingMovieFrame;                       // 0x0010 (0x0004) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
};

// Function GameFramework.GamePlayerController.KeepPlayingLoadingMovie
// [0x00022401] 
struct AGamePlayerController_execKeepPlayingLoadingMovie_Params
{
};

// Function GameFramework.GamePlayerController.ShowLoadingMovie
// [0x00026401] 
struct AGamePlayerController_execShowLoadingMovie_Params
{
	uint32_t                                           bShowMovie : 1;                                   // 0x0000 (0x0004) [0x0000000000000080] [0x00000001] (CPF_Parm)
	uint32_t : 0;                                  // 0x0004 CLOSE BITFIELD STORAGE UNIT
	uint32_t                                           bPauseAfterHide : 1;                              // 0x0004 (0x0004) [0x0000000000000090] [0x00000001] (CPF_OptionalParm | CPF_Parm)
	float                                              PauseDuration;                                    // 0x0008 (0x0004) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
	float                                              KeepPlayingDuration;                              // 0x000C (0x0004) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
	uint32_t                                           bOverridePreviousDelays : 1;                      // 0x0010 (0x0004) [0x0000000000000090] [0x00000001] (CPF_OptionalParm | CPF_Parm)
};

// Function GameFramework.GamePlayerController.GetCurrentSoundMode
// [0x00020103] 
struct AGamePlayerController_execGetCurrentSoundMode_Params
{
	class FName                                        ReturnValue;                                      // 0x0000 (0x0008) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GamePlayerController.SetSoundMode
// [0x00020102] 
struct AGamePlayerController_execSetSoundMode_Params
{
	class FName                                        InSoundModeName;                                  // 0x0000 (0x0008) [0x0000000000000080] (CPF_Parm)    
	bool                                               ReturnValue : 1;                                  // 0x0008 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
	// class UAudioDevice*                             Audio;                                            // 0x000C (0x0004) [0x0000000000000000]               
	// uint32_t                                        bSet : 1;                                         // 0x0010 (0x0004) [0x0000000000000000] [0x00000001] 
};

// Function GameFramework.GamePlayerController.DoForceFeedbackForScreenShake
// [0x00080102] 
struct AGamePlayerController_execDoForceFeedbackForScreenShake_Params
{
	class UCameraShake*                                ShakeData;                                        // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	float                                              Scale;                                            // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
	// int32_t                                         ShakeLevel;                                       // 0x0008 (0x0004) [0x0000000000000000]               
	// float                                           RotMag;                                           // 0x000C (0x0004) [0x0000000000000000]               
	// float                                           LocMag;                                           // 0x0010 (0x0004) [0x0000000000000000]               
	// float                                           FOVMag;                                           // 0x0014 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GamePlayerController.NotifyCrowdAgentInRadius
// [0x00020800] 
struct AGamePlayerController_eventNotifyCrowdAgentInRadius_Params
{
	class AGameCrowdAgent*                             Agent;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GamePlayerController.NotifyCrowdAgentRefresh
// [0x00020800] 
struct AGamePlayerController_eventNotifyCrowdAgentRefresh_Params
{
};

// Function GameFramework.GamePlayerController.CrowdDebug
// [0x00020202] 
struct AGamePlayerController_execCrowdDebug_Params
{
	uint32_t                                           bEnabled : 1;                                     // 0x0000 (0x0004) [0x0000000000000080] [0x00000001] (CPF_Parm)
	// class AGameCrowdAgent*                          GCA;                                              // 0x0004 (0x0004) [0x0000000000000000]               
	// int32_t                                         I;                                                // 0x0008 (0x0004) [0x0000000000000000]               
	// int32_t                                         AgentCount;                                       // 0x000C (0x0004) [0x0000000000000000]               
	// float                                           DebugRadius;                                      // 0x0010 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GamePlayerController.CrowdToggle
// [0x00020202] 
struct AGamePlayerController_execCrowdToggle_Params
{
	// class AGameCrowdPopulationManager*              PopMgr;                                           // 0x0000 (0x0004) [0x0000000000000000]               
	// class AGameCrowdAgent*                          Agent;                                            // 0x0004 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GamePlayerController.CrowdFocus
// [0x00020202] 
struct AGamePlayerController_execCrowdFocus_Params
{
	// class AGameCrowdAgent*                          GCA;                                              // 0x0000 (0x0004) [0x0000000000000000]               
	// class AGameCrowdPopulationManager*              PopMgr;                                           // 0x0004 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GamePlayerController.GetUIPlayerIndex
// [0x00020400] 
struct AGamePlayerController_execGetUIPlayerIndex_Params
{
	int32_t                                            ReturnValue;                                      // 0x0000 (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.NavMeshGoal_OutOfViewFrom.Recycle
// [0x00020002] 
struct UNavMeshGoal_OutOfViewFrom_execRecycle_Params
{
};

// Function GameFramework.NavMeshGoal_OutOfViewFrom.MustBeHiddenFromThisPoint
// [0x00022002] 
struct UNavMeshGoal_OutOfViewFrom_execMustBeHiddenFromThisPoint_Params
{
	class UNavigationHandle*                           NavHandle;                                        // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FVector                                     InOutOfViewLocation;                              // 0x0004 (0x000C) [0x0000000000000080] (CPF_Parm)    
	bool                                               ReturnValue : 1;                                  // 0x0010 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
	// class UNavMeshGoal_OutOfViewFrom*               Eval;                                             // 0x0014 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.NavMeshGoal_OutOfViewFrom.RecycleNative
// [0x00020400] 
struct UNavMeshGoal_OutOfViewFrom_execRecycleNative_Params
{
};

// Function GameFramework.NavMeshPath_BiasAgainstPolysWithinDistanceOfLocations.Recycle
// [0x00020002] 
struct UNavMeshPath_BiasAgainstPolysWithinDistanceOfLocations_execRecycle_Params
{
};

// Function GameFramework.NavMeshPath_BiasAgainstPolysWithinDistanceOfLocations.BiasAgainstPolysWithinDistanceOfLocations
// [0x00022002] 
struct UNavMeshPath_BiasAgainstPolysWithinDistanceOfLocations_execBiasAgainstPolysWithinDistanceOfLocations_Params
{
	class UNavigationHandle*                           NavHandle;                                        // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FVector                                     InLocation;                                       // 0x0004 (0x000C) [0x0000000000000082] (CPF_Const | CPF_Parm)
	struct FRotator                                    InRotation;                                       // 0x0010 (0x000C) [0x0000000000000082] (CPF_Const | CPF_Parm)
	float                                              InDistanceToCheck;                                // 0x001C (0x0004) [0x0000000000000082] (CPF_Const | CPF_Parm)
	class TArray<struct FVector>                       InLocationsToCheck;                               // 0x0020 (0x000C) [0x0000000000400082] (CPF_Const | CPF_Parm | CPF_NeedCtorLink)
	bool                                               ReturnValue : 1;                                  // 0x002C (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
	// class UNavMeshPath_BiasAgainstPolysWithinDistanceOfLocations* Con;                                              // 0x0030 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.SeqAct_GameCrowdPopulationManagerToggle.GetObjClassVersion
// [0x00022802] 
struct USeqAct_GameCrowdPopulationManagerToggle_eventGetObjClassVersion_Params
{
	int32_t                                            ReturnValue;                                      // 0x0000 (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.SeqAct_GameCrowdPopulationManagerToggle.FindPopMgrTarget
// [0x00020802] 
struct USeqAct_GameCrowdPopulationManagerToggle_eventFindPopMgrTarget_Params
{
};

// Function GameFramework.SeqAct_GameCrowdSpawner.GetObjClassVersion
// [0x00022802] 
struct USeqAct_GameCrowdSpawner_eventGetObjClassVersion_Params
{
	int32_t                                            ReturnValue;                                      // 0x0000 (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.SeqAct_GameCrowdSpawner.CreateNewAgent
// [0x00820002] 
struct USeqAct_GameCrowdSpawner_execCreateNewAgent_Params
{
	class AActor*                                      SpawnLoc;                                         // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class AGameCrowdAgent*                             AgentTemplate;                                    // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class UGameCrowdGroup*                             NewGroup;                                         // 0x0008 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class AGameCrowdAgent*                             ReturnValue;                                      // 0x000C (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
	// class AGameCrowdAgent*                          Agent;                                            // 0x0010 (0x0004) [0x0000000000000000]               
	// struct FRotator                                 SpawnRot;                                         // 0x0014 (0x000C) [0x0000000000000000]               
	// struct FVector                                  SpawnPos;                                         // 0x0020 (0x000C) [0x0000000000000000]               
};

// Function GameFramework.SeqAct_GameCrowdSpawner.SpawnAgent
// [0x00020802] 
struct USeqAct_GameCrowdSpawner_eventSpawnAgent_Params
{
	class AActor*                                      SpawnLoc;                                         // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class AGameCrowdAgent*                             ReturnValue;                                      // 0x0004 (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
	// class AGameCrowdAgent*                          Agent;                                            // 0x0008 (0x0004) [0x0000000000000000]               
	// float                                           AgentPickValue;                                   // 0x000C (0x0004) [0x0000000000000000]               
	// float                                           PickSum;                                          // 0x0010 (0x0004) [0x0000000000000000]               
	// int32_t                                         I;                                                // 0x0014 (0x0004) [0x0000000000000000]               
	// int32_t                                         PickedInfo;                                       // 0x0018 (0x0004) [0x0000000000000000]               
	// class AGameCrowdAgent*                          AgentTemplate;                                    // 0x001C (0x0004) [0x0000000000000000]               
	// class UGameCrowdGroup*                          NewGroup;                                         // 0x0020 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.SeqAct_GameCrowdSpawner.UpdateSpawning
// [0x00020500] 
struct USeqAct_GameCrowdSpawner_execUpdateSpawning_Params
{
	float                                              DeltaSeconds;                                     // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.SeqAct_GameCrowdSpawner.KillAgents
// [0x00020500] 
struct USeqAct_GameCrowdSpawner_execKillAgents_Params
{
};

// Function GameFramework.SeqAct_GameCrowdSpawner.CacheSpawnerVars
// [0x00020500] 
struct USeqAct_GameCrowdSpawner_execCacheSpawnerVars_Params
{
};

// Function GameFramework.SeqAct_GameCrowdSpawner.SpawnedAgent
// [0x00020400] 
struct USeqAct_GameCrowdSpawner_execSpawnedAgent_Params
{
	class AGameCrowdAgent*                             NewAgent;                                         // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.SeqAct_PlayAgentAnimation.SetCurrentAnimationActionFor
// [0x00020002] 
struct USeqAct_PlayAgentAnimation_execSetCurrentAnimationActionFor_Params
{
	class AGameCrowdAgentSkeletal*                     Agent;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	// class UGameCrowdBehavior_PlayAnimation*         AnimBehavior;                                     // 0x0004 (0x0004) [0x0000000000000000]               
	// int32_t                                         I;                                                // 0x0008 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.SeqAct_PlayAgentAnimation.GetObjClassVersion
// [0x00022802] 
struct USeqAct_PlayAgentAnimation_eventGetObjClassVersion_Params
{
	int32_t                                            ReturnValue;                                      // 0x0000 (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameCameraBase.ModifyPostProcessSettings
// [0x00420800] 
struct UGameCameraBase_eventModifyPostProcessSettings_Params
{
	struct FPostProcessSettings                        PP;                                               // 0x0000 (0x00E8) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
};

// Function GameFramework.GameCameraBase.Init
// [0x00020000] 
struct UGameCameraBase_execInit_Params
{
};

// Function GameFramework.GameCameraBase.ProcessViewRotation
// [0x00420000] 
struct UGameCameraBase_execProcessViewRotation_Params
{
	float                                              DeltaTime;                                        // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class AActor*                                      ViewTarget;                                       // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FRotator                                    out_ViewRotation;                                 // 0x0008 (0x000C) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
	struct FRotator                                    out_DeltaRot;                                     // 0x0014 (0x000C) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
};

// Function GameFramework.GameCameraBase.UpdateCamera
// [0x00420000] 
struct UGameCameraBase_execUpdateCamera_Params
{
	class APawn*                                       P;                                                // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class AGamePlayerCamera*                           CameraActor;                                      // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
	float                                              DeltaTime;                                        // 0x0008 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FTViewTarget                                OutVT;                                            // 0x000C (0x002C) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
};

// Function GameFramework.GameCameraBase.ResetInterpolation
// [0x00020002] 
struct UGameCameraBase_execResetInterpolation_Params
{
};

// Function GameFramework.GameCameraBase.OnBecomeInActive
// [0x00020000] 
struct UGameCameraBase_execOnBecomeInActive_Params
{
	class UGameCameraBase*                             NewCamera;                                        // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameCameraBase.OnBecomeActive
// [0x00020000] 
struct UGameCameraBase_execOnBecomeActive_Params
{
	class UGameCameraBase*                             OldCamera;                                        // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameThirdPersonCamera.ResetInterpolation
// [0x00020002] 
struct UGameThirdPersonCamera_execResetInterpolation_Params
{
};

// Function GameFramework.GameThirdPersonCamera.ModifyPostProcessSettings
// [0x00420802] 
struct UGameThirdPersonCamera_eventModifyPostProcessSettings_Params
{
	struct FPostProcessSettings                        PP;                                               // 0x0000 (0x00E8) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
};

// Function GameFramework.GameThirdPersonCamera.OnBecomeActive
// [0x00020002] 
struct UGameThirdPersonCamera_execOnBecomeActive_Params
{
	class UGameCameraBase*                             OldCamera;                                        // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameThirdPersonCamera.ProcessViewRotation
// [0x00420002] 
struct UGameThirdPersonCamera_execProcessViewRotation_Params
{
	float                                              DeltaTime;                                        // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class AActor*                                      ViewTarget;                                       // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FRotator                                    out_ViewRotation;                                 // 0x0008 (0x000C) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
	struct FRotator                                    out_DeltaRot;                                     // 0x0014 (0x000C) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
};

// Function GameFramework.GameThirdPersonCamera.UpdateCameraMode
// [0x00080003] 
struct UGameThirdPersonCamera_execUpdateCameraMode_Params
{
	class APawn*                                       P;                                                // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	// class UGameThirdPersonCameraMode*               NewCamMode;                                       // 0x0004 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameThirdPersonCamera.FindBestCameraMode
// [0x00020002] 
struct UGameThirdPersonCamera_execFindBestCameraMode_Params
{
	class APawn*                                       P;                                                // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class UGameThirdPersonCameraMode*                  ReturnValue;                                      // 0x0004 (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameThirdPersonCamera.AdjustFocusPointInterpolation
// [0x00020002] 
struct UGameThirdPersonCamera_execAdjustFocusPointInterpolation_Params
{
	struct FRotator                                    Delta;                                            // 0x0000 (0x000C) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameThirdPersonCamera.GetActualFocusLocation
// [0x00820002] 
struct UGameThirdPersonCamera_execGetActualFocusLocation_Params
{
	struct FVector                                     ReturnValue;                                      // 0x0000 (0x000C) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
	// struct FVector                                  FocusLoc;                                         // 0x000C (0x000C) [0x0000000000000000]               
	// class USkeletalMeshComponent*                   ComponentIt;                                      // 0x0018 (0x0004) [0x0000000004000000] (CPF_EditInline)
};

// Function GameFramework.GameThirdPersonCamera.UpdateFocusPoint
// [0x00080802] 
struct UGameThirdPersonCamera_eventUpdateFocusPoint_Params
{
	class APawn*                                       P;                                                // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameThirdPersonCamera.ClearFocusPoint
// [0x00024002] 
struct UGameThirdPersonCamera_execClearFocusPoint_Params
{
	uint32_t                                           bLeaveCameraRotation : 1;                         // 0x0000 (0x0004) [0x0000000000000090] [0x00000001] (CPF_OptionalParm | CPF_Parm)
};

// Function GameFramework.GameThirdPersonCamera.GetFocusActor
// [0x00020002] 
struct UGameThirdPersonCamera_execGetFocusActor_Params
{
	class AActor*                                      ReturnValue;                                      // 0x0000 (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameThirdPersonCamera.SetFocusOnActor
// [0x00024002] 
struct UGameThirdPersonCamera_execSetFocusOnActor_Params
{
	class AActor*                                      FocusActor;                                       // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class FName                                        FocusBoneName;                                    // 0x0004 (0x0008) [0x0000000000000080] (CPF_Parm)    
	struct FVector2D                                   InterpSpeedRange;                                 // 0x000C (0x0008) [0x0000000000000080] (CPF_Parm)    
	struct FVector2D                                   InFocusFOV;                                       // 0x0014 (0x0008) [0x0000000000000080] (CPF_Parm)    
	float                                              CameraFOV;                                        // 0x001C (0x0004) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
	uint32_t                                           bAlwaysFocus : 1;                                 // 0x0020 (0x0004) [0x0000000000000090] [0x00000001] (CPF_OptionalParm | CPF_Parm)
	uint32_t : 0;                                  // 0x0024 CLOSE BITFIELD STORAGE UNIT
	uint32_t                                           bAdjustCamera : 1;                                // 0x0024 (0x0004) [0x0000000000000090] [0x00000001] (CPF_OptionalParm | CPF_Parm)
	uint32_t : 0;                                  // 0x0028 CLOSE BITFIELD STORAGE UNIT
	uint32_t                                           bIgnoreTrace : 1;                                 // 0x0028 (0x0004) [0x0000000000000090] [0x00000001] (CPF_OptionalParm | CPF_Parm)
	float                                              FocusPitchOffsetDeg;                              // 0x002C (0x0004) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
};

// Function GameFramework.GameThirdPersonCamera.SetFocusOnLoc
// [0x00024002] 
struct UGameThirdPersonCamera_execSetFocusOnLoc_Params
{
	struct FVector                                     FocusWorldLoc;                                    // 0x0000 (0x000C) [0x0000000000000080] (CPF_Parm)    
	struct FVector2D                                   InterpSpeedRange;                                 // 0x000C (0x0008) [0x0000000000000080] (CPF_Parm)    
	struct FVector2D                                   InFocusFOV;                                       // 0x0014 (0x0008) [0x0000000000000080] (CPF_Parm)    
	float                                              CameraFOV;                                        // 0x001C (0x0004) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
	uint32_t                                           bAlwaysFocus : 1;                                 // 0x0020 (0x0004) [0x0000000000000090] [0x00000001] (CPF_OptionalParm | CPF_Parm)
	uint32_t : 0;                                  // 0x0024 CLOSE BITFIELD STORAGE UNIT
	uint32_t                                           bAdjustCamera : 1;                                // 0x0024 (0x0004) [0x0000000000000090] [0x00000001] (CPF_OptionalParm | CPF_Parm)
	uint32_t : 0;                                  // 0x0028 CLOSE BITFIELD STORAGE UNIT
	uint32_t                                           bIgnoreTrace : 1;                                 // 0x0028 (0x0004) [0x0000000000000090] [0x00000001] (CPF_OptionalParm | CPF_Parm)
	float                                              FocusPitchOffsetDeg;                              // 0x002C (0x0004) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
};

// Function GameFramework.GameThirdPersonCamera.AdjustTurn
// [0x00020002] 
struct UGameThirdPersonCamera_execAdjustTurn_Params
{
	int32_t                                            AngleOffset;                                      // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameThirdPersonCamera.EndTurn
// [0x00020400] 
struct UGameThirdPersonCamera_execEndTurn_Params
{
};

// Function GameFramework.GameThirdPersonCamera.BeginTurn
// [0x00024002] 
struct UGameThirdPersonCamera_execBeginTurn_Params
{
	int32_t                                            StartAngle;                                       // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	int32_t                                            EndAngle;                                         // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
	float                                              TimeSec;                                          // 0x0008 (0x0004) [0x0000000000000080] (CPF_Parm)    
	float                                              DelaySec;                                         // 0x000C (0x0004) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
	uint32_t                                           bAlignTargetWhenFinished : 1;                     // 0x0010 (0x0004) [0x0000000000000090] [0x00000001] (CPF_OptionalParm | CPF_Parm)
};

// Function GameFramework.GameThirdPersonCamera.PlayerUpdateCamera
// [0x00480400] 
struct UGameThirdPersonCamera_execPlayerUpdateCamera_Params
{
	class APawn*                                       P;                                                // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class AGamePlayerCamera*                           CameraActor;                                      // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
	float                                              DeltaTime;                                        // 0x0008 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FTViewTarget                                OutVT;                                            // 0x000C (0x002C) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
};

// Function GameFramework.GameThirdPersonCamera.UpdateCamera
// [0x00420002] 
struct UGameThirdPersonCamera_execUpdateCamera_Params
{
	class APawn*                                       P;                                                // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class AGamePlayerCamera*                           CameraActor;                                      // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
	float                                              DeltaTime;                                        // 0x0008 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FTViewTarget                                OutVT;                                            // 0x000C (0x002C) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
};

// Function GameFramework.GameThirdPersonCamera.GetDesiredFOV
// [0x00020802] 
struct UGameThirdPersonCamera_eventGetDesiredFOV_Params
{
	class APawn*                                       ViewedPawn;                                       // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	float                                              ReturnValue;                                      // 0x0004 (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameThirdPersonCamera.Init
// [0x00020002] 
struct UGameThirdPersonCamera_execInit_Params
{
};

// Function GameFramework.GameThirdPersonCamera.Reset
// [0x00020002] 
struct UGameThirdPersonCamera_execReset_Params
{
};

// Function GameFramework.GameThirdPersonCamera.CreateCameraMode
// [0x00080002] 
struct UGameThirdPersonCamera_execCreateCameraMode_Params
{
	class UClass*                                      ModeClass;                                        // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class UGameThirdPersonCameraMode*                  ReturnValue;                                      // 0x0004 (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
	// class UGameThirdPersonCameraMode*               NewMode;                                          // 0x0008 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GamePlayerCamera.AdjustFOVForViewport
// [0x00080401] 
struct AGamePlayerCamera_execAdjustFOVForViewport_Params
{
	float                                              inHorizFOV;                                       // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class APawn*                                       CameraTargetPawn;                                 // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
	float                                              ReturnValue;                                      // 0x0008 (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GamePlayerCamera.GetActualLookatLocation
// [0x00420000] 
struct AGamePlayerCamera_execGetActualLookatLocation_Params
{
	struct FVector                                     FocusLoc;                                         // 0x0000 (0x000C) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
	class AActor*                                      FocusActor;                                       // 0x000C (0x0004) [0x0000000000000080] (CPF_Parm)    
	bool                                               ReturnValue : 1;                                  // 0x0010 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GamePlayerCamera.ClearFocusActor
// [0x00020000] 
struct AGamePlayerCamera_execClearFocusActor_Params
{
};

// Function GameFramework.GamePlayerCamera.ProcessViewRotation
// [0x00420002] 
struct AGamePlayerCamera_execProcessViewRotation_Params
{
	float                                              DeltaTime;                                        // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FRotator                                    out_ViewRotation;                                 // 0x0004 (0x000C) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
	struct FRotator                                    out_DeltaRot;                                     // 0x0010 (0x000C) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
};

// Function GameFramework.GamePlayerCamera.ResetInterpolation
// [0x00020102] 
struct AGamePlayerCamera_execResetInterpolation_Params
{
};

// Function GameFramework.GamePlayerCamera.SetColorScale
// [0x00020102] 
struct AGamePlayerCamera_execSetColorScale_Params
{
	struct FVector                                     NewColorScale;                                    // 0x0000 (0x000C) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GamePlayerCamera.DisplayDebug
// [0x00420102] 
struct AGamePlayerCamera_execDisplayDebug_Params
{
	class AHUD*                                        HUD;                                              // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	float                                              out_YL;                                           // 0x0004 (0x0004) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
	float                                              out_YPos;                                         // 0x0008 (0x0004) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
	// class UCanvas*                                  Canvas;                                           // 0x000C (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GamePlayerCamera.ExecCameraLensEffects
// [0x00420102] 
struct AGamePlayerCamera_execExecCameraLensEffects_Params
{
	struct FVector                                     CamLoc;                                           // 0x0000 (0x000C) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
	struct FRotator                                    CamRot;                                           // 0x000C (0x000C) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
	float                                              CamFOVDeg;                                        // 0x0018 (0x0004) [0x0000000000000080] (CPF_Parm)    
	// int32_t                                         Idx;                                              // 0x001C (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GamePlayerCamera.UpdateCameraLensEffects
// [0x00420102] 
struct AGamePlayerCamera_execUpdateCameraLensEffects_Params
{
	struct FTViewTarget                                OutVT;                                            // 0x0000 (0x002C) [0x0000000000000182] (CPF_Const | CPF_Parm | CPF_OutParm)
	// int32_t                                         Idx;                                              // 0x002C (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GamePlayerCamera.UpdateViewTarget
// [0x00420002] 
struct AGamePlayerCamera_execUpdateViewTarget_Params
{
	struct FTViewTarget                                OutVT;                                            // 0x0000 (0x002C) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
	float                                              DeltaTime;                                        // 0x002C (0x0004) [0x0000000000000080] (CPF_Parm)    
	// class APawn*                                    P;                                                // 0x0030 (0x0004) [0x0000000000000000]               
	// class UGameCameraBase*                          NewCamera;                                        // 0x0034 (0x0004) [0x0000000000000000]               
	// class ACameraActor*                             CamActor;                                         // 0x0038 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GamePlayerCamera.ShouldConstrainAspectRatio
// [0x00020002] 
struct AGamePlayerCamera_execShouldConstrainAspectRatio_Params
{
	bool                                               ReturnValue : 1;                                  // 0x0000 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GamePlayerCamera.FindBestCameraType
// [0x00080002] 
struct AGamePlayerCamera_execFindBestCameraType_Params
{
	class AActor*                                      CameraTarget;                                     // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class UGameCameraBase*                             ReturnValue;                                      // 0x0004 (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
	// class UGameCameraBase*                          BestCam;                                          // 0x0008 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GamePlayerCamera.Reset
// [0x00020002] 
struct AGamePlayerCamera_execReset_Params
{
};

// Function GameFramework.GamePlayerCamera.PostBeginPlay
// [0x00020002] 
struct AGamePlayerCamera_execPostBeginPlay_Params
{
};

// Function GameFramework.GamePlayerCamera.CacheLastTargetBaseInfo
// [0x00080400] 
struct AGamePlayerCamera_execCacheLastTargetBaseInfo_Params
{
	class AActor*                                      TargetBase;                                       // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GamePlayerCamera.CreateCamera
// [0x00080002] 
struct AGamePlayerCamera_execCreateCamera_Params
{
	class UClass*                                      CameraClass;                                      // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class UGameCameraBase*                             ReturnValue;                                      // 0x0004 (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
	// class UGameCameraBase*                          NewCam;                                           // 0x0008 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameThirdPersonCameraMode.SetViewOffset
// [0x00420401] 
struct UGameThirdPersonCameraMode_execSetViewOffset_Params
{
	struct FViewOffsetData                             NewViewOffset;                                    // 0x0000 (0x0024) [0x0000000000000182] (CPF_Const | CPF_Parm | CPF_OutParm)
};

// Function GameFramework.GameThirdPersonCameraMode.ModifyPostProcessSettings
// [0x00420102] 
struct UGameThirdPersonCameraMode_execModifyPostProcessSettings_Params
{
	struct FPostProcessSettings                        PP;                                               // 0x0000 (0x00E8) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
};

// Function GameFramework.GameThirdPersonCameraMode.UpdatePostProcess
// [0x00C20102] 
struct UGameThirdPersonCameraMode_execUpdatePostProcess_Params
{
	struct FTViewTarget                                VT;                                               // 0x0000 (0x002C) [0x0000000000000182] (CPF_Const | CPF_Parm | CPF_OutParm)
	float                                              DeltaTime;                                        // 0x002C (0x0004) [0x0000000000000080] (CPF_Parm)    
	// struct FVector                                  FocusLoc;                                         // 0x0030 (0x000C) [0x0000000000000000]               
	// struct FVector                                  StartTrace;                                       // 0x003C (0x000C) [0x0000000000000000]               
	// struct FVector                                  EndTrace;                                         // 0x0048 (0x000C) [0x0000000000000000]               
	// struct FVector                                  CamDir;                                           // 0x0054 (0x000C) [0x0000000000000000]               
	// float                                           FocusDist;                                        // 0x0060 (0x0004) [0x0000000000000000]               
	// float                                           SubjectDist;                                      // 0x0064 (0x0004) [0x0000000000000000]               
	// float                                           Pct;                                              // 0x0068 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameThirdPersonCameraMode.DOFTrace
// [0x00880102] 
struct UGameThirdPersonCameraMode_execDOFTrace_Params
{
	class AActor*                                      TraceOwner;                                       // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FVector                                     StartTrace;                                       // 0x0004 (0x000C) [0x0000000000000080] (CPF_Parm)    
	struct FVector                                     EndTrace;                                         // 0x0010 (0x000C) [0x0000000000000080] (CPF_Parm)    
	struct FVector                                     ReturnValue;                                      // 0x001C (0x000C) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
	// struct FVector                                  HitLocation;                                      // 0x0028 (0x000C) [0x0000000000000000]               
	// struct FVector                                  HitNormal;                                        // 0x0034 (0x000C) [0x0000000000000000]               
	// class AActor*                                   HitActor;                                         // 0x0040 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameThirdPersonCameraMode.GetDOFFocusLoc
// [0x00080102] 
struct UGameThirdPersonCameraMode_execGetDOFFocusLoc_Params
{
	class AActor*                                      TraceOwner;                                       // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FVector                                     StartTrace;                                       // 0x0004 (0x000C) [0x0000000000000080] (CPF_Parm)    
	struct FVector                                     EndTrace;                                         // 0x0010 (0x000C) [0x0000000000000080] (CPF_Parm)    
	struct FVector                                     ReturnValue;                                      // 0x001C (0x000C) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameThirdPersonCameraMode.ProcessViewRotation
// [0x00420100] 
struct UGameThirdPersonCameraMode_execProcessViewRotation_Params
{
	float                                              DeltaTime;                                        // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class AActor*                                      ViewTarget;                                       // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FRotator                                    out_ViewRotation;                                 // 0x0008 (0x000C) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
	struct FRotator                                    out_DeltaRot;                                     // 0x0014 (0x000C) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
};

// Function GameFramework.GameThirdPersonCameraMode.SetFocusPoint
// [0x00020102] 
struct UGameThirdPersonCameraMode_execSetFocusPoint_Params
{
	class APawn*                                       ViewedPawn;                                       // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	bool                                               ReturnValue : 1;                                  // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameThirdPersonCameraMode.GetCameraWorstCaseLoc
// [0x00020902] 
struct UGameThirdPersonCameraMode_eventGetCameraWorstCaseLoc_Params
{
	class APawn*                                       TargetPawn;                                       // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FVector                                     ReturnValue;                                      // 0x0004 (0x000C) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameThirdPersonCameraMode.GetDesiredFOV
// [0x00020002] 
struct UGameThirdPersonCameraMode_execGetDesiredFOV_Params
{
	class APawn*                                       ViewedPawn;                                       // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	float                                              ReturnValue;                                      // 0x0004 (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameThirdPersonCameraMode.AdjustViewOffset
// [0x00020802] 
struct UGameThirdPersonCameraMode_eventAdjustViewOffset_Params
{
	class APawn*                                       P;                                                // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FVector                                     Offset;                                           // 0x0004 (0x000C) [0x0000000000000080] (CPF_Parm)    
	struct FVector                                     ReturnValue;                                      // 0x0010 (0x000C) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameThirdPersonCameraMode.OnBecomeInActive
// [0x00020000] 
struct UGameThirdPersonCameraMode_execOnBecomeInActive_Params
{
	class APawn*                                       TargetPawn;                                       // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class UGameThirdPersonCameraMode*                  NewMode;                                          // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameThirdPersonCameraMode.OnBecomeActive
// [0x00020002] 
struct UGameThirdPersonCameraMode_execOnBecomeActive_Params
{
	class APawn*                                       TargetPawn;                                       // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class UGameThirdPersonCameraMode*                  PrevMode;                                         // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameThirdPersonCameraMode.Init
// [0x00020000] 
struct UGameThirdPersonCameraMode_execInit_Params
{
};

// Function GameFramework.GameDecalManager.SpawnDecalMinimal
// [0x00C20003] 
struct AGameDecalManager_execSpawnDecalMinimal_Params
{
	struct FVector                                     DecalLocation;                                    // 0x0000 (0x000C) [0x0000000000000182] (CPF_Const | CPF_Parm | CPF_OutParm)
	float                                              InDecalLifeSpan;                                  // 0x000C (0x0004) [0x0000000000000082] (CPF_Const | CPF_Parm)
	float                                              InCanSpawnDistance;                               // 0x0010 (0x0004) [0x0000000000000082] (CPF_Const | CPF_Parm)
	class UGameDecal*                                  ReturnValue;                                      // 0x0014 (0x0004) [0x0000000004000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_EditInline)
	// class UGameDecal*                               Result;                                           // 0x0018 (0x0004) [0x0000000004000000] (CPF_EditInline)
	// struct FActiveDecalInfo                         DecalInfo;                                        // 0x001C (0x0008) [0x0000000000000000]               
};

// Function GameFramework.GameDecalManager.IsTooCloseToActiveDecal
// [0x00420401] 
struct AGameDecalManager_execIsTooCloseToActiveDecal_Params
{
	struct FVector                                     DecalLocation;                                    // 0x0000 (0x000C) [0x0000000000000182] (CPF_Const | CPF_Parm | CPF_OutParm)
	float                                              InCanSpawnDistance;                               // 0x000C (0x0004) [0x0000000000000082] (CPF_Const | CPF_Parm)
	bool                                               ReturnValue : 1;                                  // 0x0010 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameParticleEventManager.HandleParticleModuleEventSendToGame
// [0x00420802] 
struct AGameParticleEventManager_eventHandleParticleModuleEventSendToGame_Params
{
	class UParticleModuleEventSendToGame*              InEvent;                                          // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FVector                                     InCollideDirection;                               // 0x0004 (0x000C) [0x0000000000000182] (CPF_Const | CPF_Parm | CPF_OutParm)
	struct FVector                                     InHitLocation;                                    // 0x0010 (0x000C) [0x0000000000000182] (CPF_Const | CPF_Parm | CPF_OutParm)
	struct FVector                                     InHitNormal;                                      // 0x001C (0x000C) [0x0000000000000182] (CPF_Const | CPF_Parm | CPF_OutParm)
	class FName                                        InBoneName;                                       // 0x0028 (0x0008) [0x0000000000000182] (CPF_Const | CPF_Parm | CPF_OutParm)
};

// Function GameFramework.GameSpecialMove.RelativeToWorldOffset
// [0x00020401] 
struct UGameSpecialMove_execRelativeToWorldOffset_Params
{
	struct FRotator                                    InRotation;                                       // 0x0000 (0x000C) [0x0000000000000080] (CPF_Parm)    
	struct FVector                                     RelativeSpaceOffset;                              // 0x000C (0x000C) [0x0000000000000080] (CPF_Parm)    
	struct FVector                                     ReturnValue;                                      // 0x0018 (0x000C) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameSpecialMove.WorldToRelativeOffset
// [0x00020401] 
struct UGameSpecialMove_execWorldToRelativeOffset_Params
{
	struct FRotator                                    InRotation;                                       // 0x0000 (0x000C) [0x0000000000000080] (CPF_Parm)    
	struct FVector                                     WorldSpaceOffset;                                 // 0x000C (0x000C) [0x0000000000000080] (CPF_Parm)    
	struct FVector                                     ReturnValue;                                      // 0x0018 (0x000C) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameSpecialMove.ForcePawnRotation
// [0x00020401] 
struct UGameSpecialMove_execForcePawnRotation_Params
{
	class APawn*                                       P;                                                // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FRotator                                    NewRotation;                                      // 0x0004 (0x000C) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameSpecialMove.MessageEvent
// [0x00020002] 
struct UGameSpecialMove_execMessageEvent_Params
{
	class FName                                        EventName;                                        // 0x0000 (0x0008) [0x0000000000000080] (CPF_Parm)    
	class UObject*                                     Sender;                                           // 0x0008 (0x0004) [0x0000000000000080] (CPF_Parm)    
	bool                                               ReturnValue : 1;                                  // 0x000C (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameSpecialMove.ResetFacePreciseRotation
// [0x00020401] 
struct UGameSpecialMove_execResetFacePreciseRotation_Params
{
};

// Function GameFramework.GameSpecialMove.ReachedPrecisePosition
// [0x00020800] 
struct UGameSpecialMove_eventReachedPrecisePosition_Params
{
};

// Function GameFramework.GameSpecialMove.SetFacePreciseRotation
// [0x00020401] 
struct UGameSpecialMove_execSetFacePreciseRotation_Params
{
	struct FRotator                                    RotationToFace;                                   // 0x0000 (0x000C) [0x0000000000000080] (CPF_Parm)    
	float                                              InterpolationTime;                                // 0x000C (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameSpecialMove.SetReachPreciseDestination
// [0x00024401] 
struct UGameSpecialMove_execSetReachPreciseDestination_Params
{
	struct FVector                                     DestinationToReach;                               // 0x0000 (0x000C) [0x0000000000000080] (CPF_Parm)    
	uint32_t                                           bCancel : 1;                                      // 0x000C (0x0004) [0x0000000000000090] [0x00000001] (CPF_OptionalParm | CPF_Parm)
};

// Function GameFramework.GameSpecialMove.ShouldReplicate
// [0x00020002] 
struct UGameSpecialMove_execShouldReplicate_Params
{
	bool                                               ReturnValue : 1;                                  // 0x0000 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameSpecialMove.SpecialMoveFlagsUpdated
// [0x00020000] 
struct UGameSpecialMove_execSpecialMoveFlagsUpdated_Params
{
};

// Function GameFramework.GameSpecialMove.Tick
// [0x00020000] 
struct UGameSpecialMove_execTick_Params
{
	float                                              DeltaTime;                                        // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameSpecialMove.SpecialMoveEnded
// [0x00020000] 
struct UGameSpecialMove_execSpecialMoveEnded_Params
{
	class FName                                        PrevMove;                                         // 0x0000 (0x0008) [0x0000000000000080] (CPF_Parm)    
	class FName                                        NextMove;                                         // 0x0008 (0x0008) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameSpecialMove.SpecialMoveStarted
// [0x00020000] 
struct UGameSpecialMove_execSpecialMoveStarted_Params
{
	uint32_t                                           bForced : 1;                                      // 0x0000 (0x0004) [0x0000000000000080] [0x00000001] (CPF_Parm)
	class FName                                        PrevMove;                                         // 0x0004 (0x0008) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameSpecialMove.InternalCanDoSpecialMove
// [0x00080002] 
struct UGameSpecialMove_execInternalCanDoSpecialMove_Params
{
	bool                                               ReturnValue : 1;                                  // 0x0000 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameSpecialMove.CanDoSpecialMove
// [0x00024003] 
struct UGameSpecialMove_execCanDoSpecialMove_Params
{
	uint32_t                                           bForceCheck : 1;                                  // 0x0000 (0x0004) [0x0000000000000090] [0x00000001] (CPF_OptionalParm | CPF_Parm)
	uint32_t : 0;                                  // 0x0004 CLOSE BITFIELD STORAGE UNIT
	bool                                               ReturnValue : 1;                                  // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameSpecialMove.CanOverrideSpecialMove
// [0x00020002] 
struct UGameSpecialMove_execCanOverrideSpecialMove_Params
{
	class FName                                        InMove;                                           // 0x0000 (0x0008) [0x0000000000000080] (CPF_Parm)    
	bool                                               ReturnValue : 1;                                  // 0x0008 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameSpecialMove.CanOverrideMoveWith
// [0x00020002] 
struct UGameSpecialMove_execCanOverrideMoveWith_Params
{
	class FName                                        NewMove;                                          // 0x0000 (0x0008) [0x0000000000000080] (CPF_Parm)    
	bool                                               ReturnValue : 1;                                  // 0x0008 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameSpecialMove.CanChainMove
// [0x00020002] 
struct UGameSpecialMove_execCanChainMove_Params
{
	class FName                                        NextMove;                                         // 0x0000 (0x0008) [0x0000000000000080] (CPF_Parm)    
	bool                                               ReturnValue : 1;                                  // 0x0008 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameSpecialMove.ExtractSpecialMoveFlags
// [0x00020000] 
struct UGameSpecialMove_execExtractSpecialMoveFlags_Params
{
	int32_t                                            Flags;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameSpecialMove.InitSpecialMoveFlags
// [0x00420000] 
struct UGameSpecialMove_execInitSpecialMoveFlags_Params
{
	int32_t                                            out_Flags;                                        // 0x0000 (0x0004) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
};

// Function GameFramework.GameSpecialMove.InitSpecialMove
// [0x00020002] 
struct UGameSpecialMove_execInitSpecialMove_Params
{
	class AGamePawn*                                   inPawn;                                           // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class FName                                        InHandle;                                         // 0x0004 (0x0008) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameCrowdSpawnerInterface.GetMaxSpawnDist
// [0x00020000] 
struct UGameCrowdSpawnerInterface_execGetMaxSpawnDist_Params
{
	float                                              ReturnValue;                                      // 0x0000 (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameCrowdSpawnerInterface.AddToAgentPool
// [0x00020000] 
struct UGameCrowdSpawnerInterface_execAddToAgentPool_Params
{
	class AGameCrowdAgent*                             Agent;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	bool                                               ReturnValue : 1;                                  // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameCrowdSpawnerInterface.AgentDestroyed
// [0x00020000] 
struct UGameCrowdSpawnerInterface_execAgentDestroyed_Params
{
	class AGameCrowdAgent*                             Agent;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameCrowdSpawnInterface.GetSpawnPosition
// [0x00420000] 
struct UGameCrowdSpawnInterface_execGetSpawnPosition_Params
{
	class USeqAct_GameCrowdSpawner*                    Spawner;                                          // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FVector                                     SpawnPos;                                         // 0x0004 (0x000C) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
	struct FRotator                                    SpawnRot;                                         // 0x0010 (0x000C) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
};

// Function GameFramework.GameFixedCamera.OnBecomeActive
// [0x00020002] 
struct UGameFixedCamera_execOnBecomeActive_Params
{
	class UGameCameraBase*                             OldCamera;                                        // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameFixedCamera.UpdateCamera
// [0x00420102] 
struct UGameFixedCamera_execUpdateCamera_Params
{
	class APawn*                                       P;                                                // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class AGamePlayerCamera*                           CameraActor;                                      // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
	float                                              DeltaTime;                                        // 0x0008 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FTViewTarget                                OutVT;                                            // 0x000C (0x002C) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
	// class ACameraActor*                             CamActor;                                         // 0x0038 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameFreeCamera.LimitViewRotation
// [0x00020102] 
struct UGameFreeCamera_execLimitViewRotation_Params
{
	struct FRotator                                    ViewRotation;                                     // 0x0000 (0x000C) [0x0000000000000080] (CPF_Parm)    
	float                                              ViewPitchMin;                                     // 0x000C (0x0004) [0x0000000000000080] (CPF_Parm)    
	float                                              ViewPitchMax;                                     // 0x0010 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FRotator                                    ReturnValue;                                      // 0x0014 (0x000C) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GameFramework.GameFreeCamera.ClearMoveFlags
// [0x00020102] 
struct UGameFreeCamera_execClearMoveFlags_Params
{
};

// Function GameFramework.GameFreeCamera.ProcessInputInfo
// [0x00C20102] 
struct UGameFreeCamera_execProcessInputInfo_Params
{
	float                                              DeltaTime;                                        // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FTViewTarget                                OutVT;                                            // 0x0004 (0x002C) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
	// struct FVector                                  DeltaLoc;                                         // 0x0030 (0x000C) [0x0000000000000000]               
	// struct FVector                                  CamForward;                                       // 0x003C (0x000C) [0x0000000000000000]               
	// struct FVector                                  CamRightward;                                     // 0x0048 (0x000C) [0x0000000000000000]               
	// struct FVector                                  CamUpward;                                        // 0x0054 (0x000C) [0x0000000000000000]               
};

// Function GameFramework.GameFreeCamera.GetInputInfo
// [0x00020102] 
struct UGameFreeCamera_execGetInputInfo_Params
{
	// class UPlayerInput*                             InputInfo;                                        // 0x0000 (0x0004) [0x0000000000000000]               
	// float                                           RawJoyUp;                                         // 0x0004 (0x0004) [0x0000000000000000]               
	// float                                           RawJoyRight;                                      // 0x0008 (0x0004) [0x0000000000000000]               
	// float                                           RawJoyLookRight;                                  // 0x000C (0x0004) [0x0000000000000000]               
	// float                                           RawJoyLookUp;                                     // 0x0010 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameFreeCamera.IsKeyPressed
// [0x00020002] 
struct UGameFreeCamera_execIsKeyPressed_Params
{
	class UPlayerInput*                                InputInfo;                                        // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class FName                                        KeyName;                                          // 0x0004 (0x0008) [0x0000000000000080] (CPF_Parm)    
	bool                                               ReturnValue : 1;                                  // 0x000C (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
	// int32_t                                         I;                                                // 0x0010 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameFreeCamera.GetDeflection
// [0x00024102] 
struct UGameFreeCamera_execGetDeflection_Params
{
	float                                              F;                                                // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	float                                              Epsilon;                                          // 0x0004 (0x0004) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
	float                                              ReturnValue;                                      // 0x0008 (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
	// float                                           R;                                                // 0x000C (0x0004) [0x0000000000000000]               
	// float                                           abs_f;                                            // 0x0010 (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameFreeCamera.GetSign
// [0x00024102] 
struct UGameFreeCamera_execGetSign_Params
{
	float                                              F;                                                // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	float                                              Epsilon;                                          // 0x0004 (0x0004) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
	float                                              ReturnValue;                                      // 0x0008 (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
	// float                                           R;                                                // 0x000C (0x0004) [0x0000000000000000]               
};

// Function GameFramework.GameFreeCamera.ProcessViewRotation
// [0x00420000] 
struct UGameFreeCamera_execProcessViewRotation_Params
{
	float                                              DeltaTime;                                        // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class AActor*                                      ViewTarget;                                       // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FRotator                                    out_ViewRotation;                                 // 0x0008 (0x000C) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
	struct FRotator                                    out_DeltaRot;                                     // 0x0014 (0x000C) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
};

// Function GameFramework.GameFreeCamera.OnBecomeActive
// [0x00020002] 
struct UGameFreeCamera_execOnBecomeActive_Params
{
	class UGameCameraBase*                             OldCamera;                                        // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameFreeCamera.UpdateCamera
// [0x00420002] 
struct UGameFreeCamera_execUpdateCamera_Params
{
	class APawn*                                       P;                                                // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class AGamePlayerCamera*                           CameraActor;                                      // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
	float                                              DeltaTime;                                        // 0x0008 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FTViewTarget                                OutVT;                                            // 0x000C (0x002C) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
};

// Function GameFramework.GameKActorSpawnableEffect.Tick
// [0x00020902] 
struct AGameKActorSpawnableEffect_eventTick_Params
{
	float                                              DeltaTime;                                        // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameKActorSpawnableEffect.FellOutOfWorld
// [0x00020902] 
struct AGameKActorSpawnableEffect_eventFellOutOfWorld_Params
{
	class UClass*                                      dmgType;                                          // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GameFramework.GameKActorSpawnableEffect.PostBeginPlay
// [0x00020900] 
struct AGameKActorSpawnableEffect_eventPostBeginPlay_Params
{
};

/*
# ========================================================================================= #
#
# ========================================================================================= #
*/

#ifdef _MSC_VER
#pragma pack(pop)
#endif
