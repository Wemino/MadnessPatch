/*
#############################################################################################
# Alice2 (ASDK) SDK 1.0.0.0
# Generated with the CodeRedGenerator v1.2.0
# ========================================================================================= #
# File: GameFramework_classes.hpp
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
# Constants
# ========================================================================================= #
*/

#define CONST_LOADING_MOVIE                                         "LoadingMovie"

/*
# ========================================================================================= #
# Enums
# ========================================================================================= #
*/

// Enum GameFramework.GameCrowdAgent.EConformType
enum class EConformType : uint8_t
{
	CFM_NavMesh                                        = 0,
	CFM_BSP                                            = 1,
	CFM_World                                          = 2,
	CFM_None                                           = 3,
	CFM_END                                            = 4
};

// Enum GameFramework.GameTypes.EShakeParam
enum class EShakeParam : uint8_t
{
	ESP_OffsetRandom                                   = 0,
	ESP_OffsetZero                                     = 1,
	ESP_END                                            = 2
};

// Enum GameFramework.GameSkelCtrl_Recoil.ERecoilStart
enum class ERecoilStart : uint8_t
{
	ERS_Zero                                           = 0,
	ERS_Random                                         = 1,
	ERS_END                                            = 2
};

// Enum GameFramework.GameThirdPersonCameraMode.ECameraViewportTypes
enum class ECameraViewportTypes : uint8_t
{
	CVT_16to9_Full                                     = 0,
	CVT_16to9_VertSplit                                = 1,
	CVT_16to9_HorizSplit                               = 2,
	CVT_4to3_Full                                      = 3,
	CVT_4to3_HorizSplit                                = 4,
	CVT_4to3_VertSplit                                 = 5,
	CVT_END                                            = 6
};

// Enum GameFramework.MobileHUD.EZoneType
enum class EZoneType : uint8_t
{
	ZoneType_Button                                    = 0,
	ZoneType_Joystick                                  = 1,
	ZoneType_Trackball                                 = 2,
	ZoneType_Tilt                                      = 3,
	ZoneType_END                                       = 4
};

// Enum GameFramework.MobileHUD.EZoneState
enum class EZoneState : uint8_t
{
	ZoneState_Inactive                                 = 0,
	ZoneState_Activating                               = 1,
	ZoneState_Active                                   = 2,
	ZoneState_Deactivating                             = 3,
	ZoneState_END                                      = 4
};


/*
# ========================================================================================= #
# Classes
# ========================================================================================= #
*/

// Class GameFramework.GameAIController
// 0x0024 (0x03DC - 0x0400)
class AGameAIController : public AAIController
{
public:
	class UGameAICommand*                              CommandList;                                   // 0x03DC (0x0004) [0x0000000000002002] (CPF_Const | CPF_Transient)
	uint32_t                                           bHasRunawayCommandList : 1;                    // 0x03E0 (0x0004) [0x0000000000002000] [0x00000001] (CPF_Transient)
	uint32_t                                           bAILogging : 1;                                // 0x03E0 (0x0004) [0x0000000000004001] [0x00000002] (CPF_Edit | CPF_Config)
	uint32_t                                           bAILogToWindow : 1;                            // 0x03E0 (0x0004) [0x0000000000004001] [0x00000004] (CPF_Edit | CPF_Config)
	uint32_t                                           bFlushAILogEachLine : 1;                       // 0x03E0 (0x0004) [0x0000000000004001] [0x00000008] (CPF_Edit | CPF_Config)
	uint32_t                                           bMapBasedLogName : 1;                          // 0x03E0 (0x0004) [0x0000000000004001] [0x00000010] (CPF_Edit | CPF_Config)
	uint32_t                                           bAIDrawDebug : 1;                              // 0x03E0 (0x0004) [0x0000000000004001] [0x00000020] (CPF_Edit | CPF_Config)
	uint32_t                                           bAIBroken : 1;                                 // 0x03E0 (0x0004) [0x0000000000002000] [0x00000040] (CPF_Transient)
	class AFileLog*                                    AILogFile;                                     // 0x03E4 (0x0004) [0x0000000000002000] (CPF_Transient)
	class TArray<class FName>                          AILogFilter;                                   // 0x03E8 (0x000C) [0x0000000000404001] (CPF_Edit | CPF_Config | CPF_NeedCtorLink)
	class FString                                      DemoActionString;                              // 0x03F4 (0x000C) [0x0000000000400020] (CPF_Net | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameAIController");
		}

		return uClassPointer;
	};


	class FString eventGetActionString();
	bool eventGeneratePathToLocation(const struct FVector& Goal, float optionalWithinDistance, bool optionalBAllowPartialPath);
	bool eventGeneratePathToActor(class AActor* Goal, float optionalWithinDistance, bool optionalBAllowPartialPath);
	void SetDesiredRotation(const struct FRotator& TargetDesiredRotation, bool optionalInLockDesiredRotation, bool optionalInUnlockWhenReached, float optionalInterpolationTime);
	void eventAILog_Internal(const class FString& LogText, const class FName& optionalLogCategory, bool optionalBForce);
	void RecordDemoAILog(const class FString& LogText);
	void eventDestroyed();
	class UGameAICommand* GetAICommandInStack(class UClass* InClass);
	class UGameAICommand* FindCommandOfClass(class UClass* SearchClass);
	void DumpCommandStack();
	void CheckCommandCount();
	class UGameAICommand* GetActiveCommand();
	bool AbortCommand(class UGameAICommand* AbortCmd, class UClass* optionalAbortClass);
	void PopCommand(class UGameAICommand* ToBePoppedCommand);
	void PushCommand(class UGameAICommand* NewCommand);
};
// Class GameFramework.GameAICommand
// 0x001C (0x003C - 0x0058)
class UGameAICommand : public UObject
{
public:
	class UGameAICommand*                              ChildCommand;                                  // 0x003C (0x0004) [0x0000000000002002] (CPF_Const | CPF_Transient)
	class FName                                        ChildStatus;                                   // 0x0040 (0x0008) [0x0000000000002002] (CPF_Const | CPF_Transient)
	class AGameAIController*                           GameAIOwner;                                   // 0x0048 (0x0004) [0x0000000000002000] (CPF_Transient)
	class FName                                        Status;                                        // 0x004C (0x0008) [0x0000000000002000] (CPF_Transient)
	uint32_t                                           bAllowNewSameClassInstance : 1;                // 0x0054 (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bReplaceActiveSameClassInstance : 1;           // 0x0054 (0x0004) [0x0000000000000000] [0x00000002] 
	uint32_t                                           bAborted : 1;                                  // 0x0054 (0x0004) [0x0000000000002000] [0x00000004] (CPF_Transient)
	uint32_t                                           bIgnoreNotifies : 1;                           // 0x0054 (0x0004) [0x0000000000000000] [0x00000008] 
	uint32_t                                           bPendingPop : 1;                               // 0x0054 (0x0004) [0x0000000000002000] [0x00000010] (CPF_Transient)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameAICommand");
		}

		return uClassPointer;
	};


	void GetDebugOverheadText(class APlayerController* PC, class TArray<class FString>& outOutText);
	void eventDrawDebug(class AHUD* H, const class FName& Category);
	class FString eventGetDumpString();
	void Resumed(const class FName& OldCommandName);
	void Paused(class UGameAICommand* NewCommand);
	void Popped();
	void Pushed();
	void PostPopped();
	void PrePushed(class AGameAIController* AI);
	bool AllowStateTransitionTo(const class FName& StateName);
	bool AllowTransitionTo(class UClass* AttemptCommand);
	void Tick(float DeltaTime);
	bool ShouldIgnoreNotifies();
	void eventInternalTick(float DeltaTime);
	void eventInternalResumed(const class FName& OldCommandName);
	void eventInternalPaused(class UGameAICommand* NewCommand);
	void eventInternalPopped();
	void eventInternalPushed();
	void eventInternalPrePushed(class AGameAIController* AI);
	static bool InitCommand(class AGameAIController* AI);
	static bool InitCommandUserActor(class AGameAIController* AI, class AActor* UserActor);
};
// Class GameFramework.GameCameraBlockingVolume
// 0x0000 (0x0268 - 0x0268)
class AGameCameraBlockingVolume : public ABlockingVolume
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameCameraBlockingVolume");
		}

		return uClassPointer;
	};

};
// Class GameFramework.GameCrowdAgent
// 0x01D8 (0x022C - 0x0404)
class AGameCrowdAgent : public ACrowdAgentBase
{
public:
	class UGameCrowdGroup*                             MyGroup;                                       // 0x022C (0x0004) [0x0000000000000000]               
	struct FVector                                     PreferredVelocity;                             // 0x0230 (0x000C) [0x0000000000000000]               
	float                                              AvoidanceShare;                                // 0x023C (0x0004) [0x0000000000000000]               
	class AGameCrowdDestination*                       CurrentDestination;                            // 0x0240 (0x0004) [0x0000000000000000]               
	class AGameCrowdDestination*                       BehaviorDestination;                           // 0x0244 (0x0004) [0x0000000000000000]               
	class AGameCrowdDestination*                       PreviousDestination;                           // 0x0248 (0x0004) [0x0000000000000000]               
	struct FVector                                     ExternalForce;                                 // 0x024C (0x000C) [0x0000000000000000]               
	float                                              InterpZTranslation;                            // 0x0258 (0x0004) [0x0000000000000000]               
	int32_t                                            Health;                                        // 0x025C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              DeadBodyDuration;                              // 0x0260 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class UDynamicLightEnvironmentComponent*           LightEnvironment;                              // 0x0264 (0x0004) [0x00000000040A000A] (CPF_Const | CPF_ExportObject | CPF_EditConst | CPF_Component | CPF_EditInline)
	int32_t                                            ConformTraceFrameCount;                        // 0x0268 (0x0004) [0x0000000000002000] (CPF_Transient)
	int32_t                                            AwareUpdateFrameCount;                         // 0x026C (0x0004) [0x0000000000002000] (CPF_Transient)
	class TArray<class AActor*>                        NearbyDynamics;                                // 0x0270 (0x000C) [0x0000000000402000] (CPF_Transient | CPF_NeedCtorLink)
	class TArray<class AGameCrowdForcePoint*>          RelevantAttractors;                            // 0x027C (0x000C) [0x0000000000402000] (CPF_Transient | CPF_NeedCtorLink)
	uint32_t                                           bUniformScale : 1;                             // 0x0288 (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bCheckForObstacles : 1;                        // 0x0288 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint32_t                                           bUseNavMeshPathing : 1;                        // 0x0288 (0x0004) [0x0000000000000001] [0x00000004] (CPF_Edit)
	uint32_t                                           bWantsSeePlayerNotification : 1;               // 0x0288 (0x0004) [0x0000000000000000] [0x00000008] 
	uint32_t                                           bAllowPitching : 1;                            // 0x0288 (0x0004) [0x0000000000000001] [0x00000010] (CPF_Edit)
	uint32_t                                           bHitObstacle : 1;                              // 0x0288 (0x0004) [0x0000000000000000] [0x00000020] 
	uint32_t                                           bBadHitNormal : 1;                             // 0x0288 (0x0004) [0x0000000000000000] [0x00000040] 
	uint32_t                                           bSimulateThisTick : 1;                         // 0x0288 (0x0004) [0x0000000000000000] [0x00000080] 
	uint32_t                                           bClampMovementSpeed : 1;                       // 0x0288 (0x0004) [0x0000000000000001] [0x00000100] (CPF_Edit)
	uint32_t                                           bPotentialEncounter : 1;                       // 0x0288 (0x0004) [0x0000000000000000] [0x00000200] 
	uint32_t                                           bIsPanicked : 1;                               // 0x0288 (0x0004) [0x0000000000000000] [0x00000400] 
	uint32_t                                           bWantsGroupIdle : 1;                           // 0x0288 (0x0004) [0x0000000000000000] [0x00000800] 
	uint32_t                                           bPreferVisibleDestination : 1;                 // 0x0288 (0x0004) [0x0000000000000001] [0x00001000] (CPF_Edit)
	uint32_t                                           bPreferVisibleDestinationOnSpawn : 1;          // 0x0288 (0x0004) [0x0000000000000001] [0x00002000] (CPF_Edit)
	uint32_t                                           bHasNotifiedSpawner : 1;                       // 0x0288 (0x0004) [0x0000000000000000] [0x00004000] 
	uint32_t                                           bIsInSpawnPool : 1;                            // 0x0288 (0x0004) [0x0000000000000000] [0x00008000] 
	EConformType                                       ConformType;                                   // 0x028C (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            UnknownData00[0x3];                              // 0x028D (0x0003) MISSED OFFSET
	float                                              ConformTraceDist;                              // 0x0290 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            ConformTraceInterval;                          // 0x0294 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            CurrentConformTraceInterval;                   // 0x0298 (0x0004) [0x0000000000000000]               
	float                                              LastGroundZ;                                   // 0x029C (0x0004) [0x0000000000000000]               
	float                                              AwareRadius;                                   // 0x02A0 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            AwareUpdateInterval;                           // 0x02A4 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              AvoidOtherStrength;                            // 0x02A8 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              AvoidPlayerStrength;                           // 0x02AC (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              AvoidOtherRadius;                              // 0x02B0 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              GroupAttractionStrength;                       // 0x02B4 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              MatchVelStrength;                              // 0x02B8 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              FollowPathStrength;                            // 0x02BC (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              VelocityDamping;                               // 0x02C0 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              RotateToTargetSpeed;                           // 0x02C4 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              MaxYawRate;                                    // 0x02C8 (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FVector                                     MeshMinScale3D;                                // 0x02CC (0x000C) [0x0000000000000001] (CPF_Edit)    
	struct FVector                                     MeshMaxScale3D;                                // 0x02D8 (0x000C) [0x0000000000000001] (CPF_Edit)    
	float                                              EyeZOffset;                                    // 0x02E4 (0x0004) [0x0000000000000000]               
	float                                              ProximityLODDist;                              // 0x02E8 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              VisibleProximityLODDist;                       // 0x02EC (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FVector                                     LastKnownGoodPosition;                         // 0x02F0 (0x000C) [0x0000000000000000]               
	float                                              GroundOffset;                                  // 0x02FC (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FVector                                     IntermediatePoint;                             // 0x0300 (0x000C) [0x0000000000000000]               
	struct FVector                                     SearchExtent;                                  // 0x030C (0x000C) [0x0000000000000000]               
	class UClass*                                      NavigationHandleClass;                         // 0x0318 (0x0004) [0x0000000000000000]               
	class UNavigationHandle*                           NavigationHandle;                              // 0x031C (0x0004) [0x0000000000000000]               
	int32_t                                            ObstacleCheckCount;                            // 0x0320 (0x0004) [0x0000000000000000]               
	float                                              WalkableFloorZ;                                // 0x0324 (0x0004) [0x0000000000000000]               
	float                                              LastPathingAttempt;                            // 0x0328 (0x0004) [0x0000000000000000]               
	float                                              LastUpdateTime;                                // 0x032C (0x0004) [0x0000000000000000]               
	float                                              NotVisibleLifeSpan;                            // 0x0330 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              NotVisibleTickScalingFactor;                   // 0x0334 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class AGameCrowdAgent*                             MyArchetype;                                   // 0x0338 (0x0004) [0x0000000000000000]               
	float                                              MaxWalkingSpeed;                               // 0x033C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              MaxRunningSpeed;                               // 0x0340 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              MaxSpeed;                                      // 0x0344 (0x0004) [0x0000000000000000]               
	class TArray<struct FRecentInteraction>            RecentInteractions;                            // 0x0348 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	float                                              BeaconMaxDist;                                 // 0x0354 (0x0004) [0x0000000000000000]               
	struct FVector                                     BeaconOffset;                                  // 0x0358 (0x000C) [0x0000000000000000]               
	class UTexture2D*                                  BeaconTexture;                                 // 0x0364 (0x0004) [0x0000000000000002] (CPF_Const)   
	struct FLinearColor                                BeaconColor;                                   // 0x0368 (0x0010) [0x0000000000000002] (CPF_Const)   
	class USoundCue*                                   AmbientSoundCue;                               // 0x0378 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class UAudioComponent*                             AmbientSoundComponent;                         // 0x037C (0x0004) [0x0000000004080008] (CPF_ExportObject | CPF_Component | CPF_EditInline)
	class UGameCrowdAgentBehavior*                     CurrentBehavior;                               // 0x0380 (0x0004) [0x0000000000000000]               
	class TArray<struct FBehaviorEntry>                EncounterAgentBehaviors;                       // 0x0384 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class TArray<struct FBehaviorEntry>                SeePlayerBehaviors;                            // 0x0390 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	float                                              MaxSeePlayerDistSq;                            // 0x039C (0x0004) [0x0000000000000000]               
	float                                              SeePlayerInterval;                             // 0x03A0 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class TArray<struct FBehaviorEntry>                SpawnBehaviors;                                // 0x03A4 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class TArray<struct FBehaviorEntry>                PanicBehaviors;                                // 0x03B0 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class TArray<struct FBehaviorEntry>                RandomBehaviors;                               // 0x03BC (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	float                                              RandomBehaviorInterval;                        // 0x03C8 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              ForceUpdateTime;                               // 0x03CC (0x0004) [0x0000000000000000]               
	float                                              ReachThreshold;                                // 0x03D0 (0x0004) [0x0000000000000000]               
	class TArray<struct FBehaviorEntry>                GroupWaitingBehaviors;                         // 0x03D4 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	float                                              DesiredGroupRadius;                            // 0x03E0 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              DesiredGroupRadiusSq;                          // 0x03E4 (0x0004) [0x0000000000000000]               
	float                                              MaxLOSLifeDistanceSq;                          // 0x03E8 (0x0004) [0x0000000000000000]               
	class UGameCrowdSpawnerInterface*                  MySpawner_Object;                              // 0x03EC (0x0004) [0x0000000000000000] 
	class UGameCrowdSpawnerInterface*                  MySpawner_Interface;                           // 0x03F0 (0x0004) [0x0000000000000000]               
	struct FVector                                     SpawnOffset;                                   // 0x03F4 (0x000C) [0x0000000000000000]               
	float                                              InitialLastRenderTime;                         // 0x0400 (0x0004) [0x0000000000000000]               

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameCrowdAgent");
		}

		return uClassPointer;
	};


	class FString GetBehaviorString();
	class FString GetDestString();
	void eventPostRenderFor(class APlayerController* PC, class UCanvas* Canvas, const struct FVector& CameraPosition, const struct FVector& CameraDir);
	void NativePostRenderFor(class APlayerController* PC, class UCanvas* Canvas, const struct FVector& CameraPosition, const struct FVector& CameraDir);
	struct FVector eventGeneratePathToActor(class AActor* Goal, float optionalWithinDistance, bool optionalBAllowPartialPath);
	void eventInitNavigationHandle();
	void eventOverlappedActorEvent(class AActor* A);
	void TakeDamage(int32_t DamageAmount, class AController* EventInstigator, const struct FVector& HitLocation, const struct FVector& Momentum, class UClass* DamageType, const struct FTraceHitInfo& optionalHitInfo, class AActor* optionalDamageCauser);
	void eventFireDeathEvent();
	void PlayDeath(const struct FVector& KillMomentum);
	void eventUpdateIntermediatePoint(class AActor* optionalDestinationActor);
	bool CalcCamera(float fDeltaTime, struct FVector& outOut_CamLoc, struct FRotator& outOut_CamRot, float& outOut_FOV);
	bool IsIdle();
	void SetCurrentBehavior(class UGameCrowdAgentBehavior* BehaviorArchetype);
	void eventStopBehavior();
	void ActivateInstancedBehavior(class UGameCrowdAgentBehavior* NewBehaviorObject);
	void eventActivateBehavior(class UGameCrowdAgentBehavior* NewBehaviorArchetype);
	void ResetSeePlayer();
	void TryRandomBehavior();
	void eventNotifySeePlayer(class APlayerController* PC);
	void PlaySpawnBehavior();
	void eventHandlePotentialAgentEncounter();
	void eventStopIdleAnimation();
	void eventPlayIdleAnimation();
	void OnPlayAgentAnimation(class USeqAct_PlayAgentAnimation* Action);
	void InitializeAgent(class AActor* SpawnLoc, class AGameCrowdAgent* AgentTemplate, class UGameCrowdGroup* NewGroup, float AgentWarmupTime, bool bWarmupPosition, bool bCheckWarmupVisibility);
	void SetLighting(bool bEnableLightEnvironment, const struct FLightingChannelContainer& AgentLightingChannel, bool bCastShadows);
	void DisplayDebug(class AHUD* HUD, float& outOut_YL, float& outOut_YPos);
	void Destroyed();
	void ResetPooledAgent();
	void eventKillAgent();
	void PostBeginPlay();
	void SetMaxSpeed();
	void eventSetCurrentDestination(class AGameCrowdDestination* NewDest);
	void eventWaitForGroupMembers();
	bool PickBehaviorFrom(const class TArray<struct FBehaviorEntry>& BehaviorList, const struct FVector& optionalBestCameraLoc);
	void SetPanic(class AActor* PanicActor, bool bNewPanic);
	bool IsPanicked();
	void eventFellOutOfWorld(class UClass* dmgType);
};
// Class GameFramework.GameCrowdAgentSkeletal
// 0x0080 (0x0404 - 0x0484)
class AGameCrowdAgentSkeletal : public AGameCrowdAgent
{
public:
	class USkeletalMeshComponent*                      SkeletalMeshComponent;                         // 0x0404 (0x0004) [0x0000000004080009] (CPF_Edit | CPF_ExportObject | CPF_Component | CPF_EditInline)
	class UAnimNodeBlend*                              SpeedBlendNode;                                // 0x0408 (0x0004) [0x0000000000000000]               
	class UAnimNodeSlot*                               FullBodySlot;                                  // 0x040C (0x0004) [0x0000000000000000]               
	class UAnimNodeSequence*                           ActionSeqNode;                                 // 0x0410 (0x0004) [0x0000000000000000]               
	class UAnimNodeSequence*                           WalkSeqNode;                                   // 0x0414 (0x0004) [0x0000000000000000]               
	class UAnimNodeSequence*                           RunSeqNode;                                    // 0x0418 (0x0004) [0x0000000000000000]               
	class UAnimTree*                                   AgentTree;                                     // 0x041C (0x0004) [0x0000000000000000]               
	class TArray<class FName>                          WalkAnimNames;                                 // 0x0420 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class TArray<class FName>                          RunAnimNames;                                  // 0x042C (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class TArray<class FName>                          IdleAnimNames;                                 // 0x0438 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class TArray<class FName>                          DeathAnimNames;                                // 0x0444 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	float                                              SpeedBlendStart;                               // 0x0450 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              SpeedBlendEnd;                                 // 0x0454 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              AnimVelRate;                                   // 0x0458 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              MaxSpeedBlendChangeSpeed;                      // 0x045C (0x0004) [0x0000000000000001] (CPF_Edit)    
	class FName                                        MoveSyncGroupName;                             // 0x0460 (0x0008) [0x0000000000000001] (CPF_Edit)    
	class TArray<struct FGameCrowdAttachmentList>      Attachments;                                   // 0x0468 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	float                                              MaxTargetAcquireTime;                          // 0x0474 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bUseRootMotionVelocity : 1;                    // 0x0478 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bIsPlayingIdleAnimation : 1;                   // 0x0478 (0x0004) [0x0000000000000000] [0x00000002] 
	uint32_t                                           bIsPlayingDeathAnimation : 1;                  // 0x0478 (0x0004) [0x0000000000000000] [0x00000004] 
	uint32_t                                           bAnimateThisTick : 1;                          // 0x0478 (0x0004) [0x0000000000000000] [0x00000008] 
	float                                              MaxAnimationDistance;                          // 0x047C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              MaxAnimationDistanceSq;                        // 0x0480 (0x0004) [0x0000000000000000]               

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameCrowdAgentSkeletal");
		}

		return uClassPointer;
	};


	void CreateAttachments();
	void eventOnAnimEnd(class UAnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime);
	void eventStopIdleAnimation();
	void eventPlayIdleAnimation();
	void eventClearLatentAnimation();
	void OnPlayAgentAnimation(class USeqAct_PlayAgentAnimation* Action);
	void SetRootMotion(bool bRootMotionEnabled);
	void PlayDeath(const struct FVector& KillMomentum);
	void SetLighting(bool bEnableLightEnvironment, const struct FLightingChannelContainer& AgentLightingChannel, bool bCastShadows);
	void PostBeginPlay();
};
// Class GameFramework.GameCrowdAgentBehavior
// 0x0010 (0x003C - 0x004C)
class UGameCrowdAgentBehavior : public UObject
{
public:
	uint32_t                                           bIdleBehavior : 1;                             // 0x003C (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bFaceActionTargetFirst : 1;                    // 0x003C (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint32_t                                           bIsViralBehavior : 1;                          // 0x003C (0x0004) [0x0000000000000001] [0x00000004] (CPF_Edit)
	uint32_t                                           bIsPanicked : 1;                               // 0x003C (0x0004) [0x0000000000000000] [0x00000008] 
	class AActor*                                      ActionTarget;                                  // 0x0040 (0x0004) [0x0000000000000000]               
	float                                              MaxPlayerDistance;                             // 0x0044 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class AGameCrowdAgent*                             MyAgent;                                       // 0x0048 (0x0004) [0x0000000000000000]               

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameCrowdAgentBehavior");
		}

		return uClassPointer;
	};


	bool AllowBehaviorAt(class AGameCrowdDestination* Destination);
	bool AllowThisDestination(class AGameCrowdDestination* Destination);
	void eventPropagateViralBehaviorTo(class AGameCrowdAgent* OtherAgent);
	void ActivatedBy(class AActor* NewActionTarget);
	class AActor* GetDestinationActor();
	void ChangingDestination(class AGameCrowdDestination* NewDest);
	class FString GetBehaviorString();
	void eventOnAnimEnd(class UAnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime);
	void StopBehavior();
	void InitBehavior(class AGameCrowdAgent* Agent);
	bool HandleMovement();
	void eventFinishedTargetRotation();
	bool CanBeUsedBy(class AGameCrowdAgent* Agent, const struct FVector& cameraLoc);
	void Tick(float DeltaTime);
	bool ShouldEndIdle();
};
// Class GameFramework.GameCrowdBehavior_PlayAnimation
// 0x002C (0x004C - 0x0078)
class UGameCrowdBehavior_PlayAnimation : public UGameCrowdAgentBehavior
{
public:
	class TArray<class FName>                          AnimationList;                                 // 0x004C (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	float                                              BlendInTime;                                   // 0x0058 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              BlendOutTime;                                  // 0x005C (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bUseRootMotion : 1;                            // 0x0060 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bLookAtPlayer : 1;                             // 0x0060 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint32_t                                           bLooping : 1;                                  // 0x0060 (0x0004) [0x0000000000000001] [0x00000004] (CPF_Edit)
	uint32_t                                           bBlendBetweenAnims : 1;                        // 0x0060 (0x0004) [0x0000000000000001] [0x00000008] (CPF_Edit)
	class AActor*                                      CustomActionTarget;                            // 0x0064 (0x0004) [0x0000000000000000]               
	int32_t                                            LoopIndex;                                     // 0x0068 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              LoopTime;                                      // 0x006C (0x0004) [0x0000000000000001] (CPF_Edit)    
	class USeqAct_PlayAgentAnimation*                  AnimSequence;                                  // 0x0070 (0x0004) [0x0000000000000000]               
	int32_t                                            AnimationIndex;                                // 0x0074 (0x0004) [0x0000000000000000]               

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameCrowdBehavior_PlayAnimation");
		}

		return uClassPointer;
	};


	class FString GetBehaviorString();
	void StopBehavior();
	void PlayAgentAnimationNow();
	void eventOnAnimEnd(class UAnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime);
	void SetSequenceOutput();
	void eventFinishedTargetRotation();
	void InitBehavior(class AGameCrowdAgent* Agent);
};
// Class GameFramework.GameCrowdBehavior_RunFromPanic
// 0x0004 (0x004C - 0x0050)
class UGameCrowdBehavior_RunFromPanic : public UGameCrowdAgentBehavior
{
public:
	class AActor*                                      PanicFocus;                                    // 0x004C (0x0004) [0x0000000000000000]               

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameCrowdBehavior_RunFromPanic");
		}

		return uClassPointer;
	};


	class FString GetBehaviorString();
	bool AllowBehaviorAt(class AGameCrowdDestination* Destination);
	bool AllowThisDestination(class AGameCrowdDestination* Destination);
	void eventPropagateViralBehaviorTo(class AGameCrowdAgent* OtherAgent);
	void StopBehavior();
	void InitBehavior(class AGameCrowdAgent* Agent);
	void ActivatedBy(class AActor* NewActionTarget);
};
// Class GameFramework.GameCrowdBehavior_WaitForGroup
// 0x0000 (0x004C - 0x004C)
class UGameCrowdBehavior_WaitForGroup : public UGameCrowdAgentBehavior
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameCrowdBehavior_WaitForGroup");
		}

		return uClassPointer;
	};


	void StopBehavior();
	bool ShouldEndIdle();
	class FString GetBehaviorString();
	void InitBehavior(class AGameCrowdAgent* Agent);
};
// Class GameFramework.GameCrowdBehavior_WaitInQueue
// 0x0008 (0x004C - 0x0054)
class UGameCrowdBehavior_WaitInQueue : public UGameCrowdAgentBehavior
{
public:
	uint32_t                                           bStoppingBehavior : 1;                         // 0x004C (0x0004) [0x0000000000000000] [0x00000001] 
	class AGameCrowdDestinationQueuePoint*             QueuePosition;                                 // 0x0050 (0x0004) [0x0000000000000000]               

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameCrowdBehavior_WaitInQueue");
		}

		return uClassPointer;
	};


	void StopBehavior();
	bool ShouldEndIdle();
	class FString GetBehaviorString();
	class AActor* GetDestinationActor();
	void ChangingDestination(class AGameCrowdDestination* NewDest);
	bool HandleMovement();
};
// Class GameFramework.GameCrowdGroup
// 0x000C (0x003C - 0x0048)
class UGameCrowdGroup : public UObject
{
public:
	class TArray<class AGameCrowdAgent*>               Members;                                       // 0x003C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameCrowdGroup");
		}

		return uClassPointer;
	};


	void UpdateDestinations(class AGameCrowdDestination* NewDestination);
	void RemoveMember(class AGameCrowdAgent* Agent);
	void AddMember(class AGameCrowdAgent* Agent);
};
// Class GameFramework.GameCrowdInteractionPoint
// 0x0008 (0x0228 - 0x0230)
class AGameCrowdInteractionPoint : public AActor
{
public:
	uint32_t                                           bIsEnabled : 1;                                // 0x0228 (0x0004) [0x0000000000000021] [0x00000001] (CPF_Edit | CPF_Net)
	class UCylinderComponent*                          CylinderComponent;                             // 0x022C (0x0004) [0x0000000004080009] (CPF_Edit | CPF_ExportObject | CPF_Component | CPF_EditInline)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameCrowdInteractionPoint");
		}

		return uClassPointer;
	};


	void OnToggle(class USeqAct_Toggle* Action);
};
// Class GameFramework.GameCrowdDestination
// 0x0084 (0x0230 - 0x02B4)
class AGameCrowdDestination : public AGameCrowdInteractionPoint
{
public:
	struct FPointer                                    VfTable_IEditorLinkSelectionInterface;         // 0x0230 (0x0004) [0x0000000000801002] (CPF_Const | CPF_Native | CPF_NoExport)
	uint32_t                                           bKillWhenReached : 1;                          // 0x0234 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bAllowAsPreviousDestination : 1;               // 0x0234 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint32_t                                           bLastAllowableResult : 1;                      // 0x0234 (0x0004) [0x0000000000000000] [0x00000004] 
	uint32_t                                           bAvoidWhenPanicked : 1;                        // 0x0234 (0x0004) [0x0000000000000001] [0x00000008] (CPF_Edit)
	uint32_t                                           bSkipBehaviorIfPanicked : 1;                   // 0x0234 (0x0004) [0x0000000000000001] [0x00000010] (CPF_Edit)
	uint32_t                                           bFleeDestination : 1;                          // 0x0234 (0x0004) [0x0000000000000001] [0x00000020] (CPF_Edit)
	uint32_t                                           bMustReachExactly : 1;                         // 0x0234 (0x0004) [0x0000000000000001] [0x00000040] (CPF_Edit)
	uint32_t                                           bHasRestrictions : 1;                          // 0x0234 (0x0004) [0x0000000000000000] [0x00000080] 
	uint32_t                                           bAllowsSpawning : 1;                           // 0x0234 (0x0004) [0x0000000000000001] [0x00000100] (CPF_Edit)
	uint32_t                                           bLineSpawner : 1;                              // 0x0234 (0x0004) [0x0000000000000001] [0x00000200] (CPF_Edit)
	uint32_t                                           bSpawnAtEdge : 1;                              // 0x0234 (0x0004) [0x0000000000000001] [0x00000400] (CPF_Edit)
	uint32_t                                           bSoftPerimeter : 1;                            // 0x0234 (0x0004) [0x0000000000000001] [0x00000800] (CPF_Edit)
	uint32_t                                           bIsVisible : 1;                                // 0x0234 (0x0004) [0x0000000000000000] [0x00001000] 
	uint32_t                                           bWillBeVisible : 1;                            // 0x0234 (0x0004) [0x0000000000000000] [0x00002000] 
	uint32_t                                           bCanSpawnHereNow : 1;                          // 0x0234 (0x0004) [0x0000000000000000] [0x00004000] 
	uint32_t                                           bIsBeyondSpawnDistance : 1;                    // 0x0234 (0x0004) [0x0000000000000000] [0x00008000] 
	uint32_t                                           bAdjacentToVisibleNode : 1;                    // 0x0234 (0x0004) [0x0000000000000000] [0x00010000] 
	uint32_t                                           bHasNavigationMesh : 1;                        // 0x0234 (0x0004) [0x0000000000000000] [0x00020000] 
	class TArray<class AGameCrowdDestination*>         NextDestinations;                              // 0x0238 (0x000C) [0x0000000000600001] (CPF_Edit | CPF_NeedCtorLink)
	class AGameCrowdDestinationQueuePoint*             QueueHead;                                     // 0x0244 (0x0004) [0x0000000000200001] (CPF_Edit)    
	int32_t                                            Capacity;                                      // 0x0248 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              Frequency;                                     // 0x024C (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            CustomerCount;                                 // 0x0250 (0x0004) [0x0000000000000000]               
	class TArray<class UClass*>                        SupportedAgentClasses;                         // 0x0254 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class TArray<class UObject*>                       SupportedArchetypes;                           // 0x0260 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class TArray<class UClass*>                        RestrictedAgentClasses;                        // 0x026C (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class TArray<class UObject*>                       RestrictedArchetypes;                          // 0x0278 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	float                                              ExactReachTolerance;                           // 0x0284 (0x0004) [0x0000000000000000]               
	class FName                                        InteractionTag;                                // 0x0288 (0x0008) [0x0000000000000001] (CPF_Edit)    
	float                                              InteractionDelay;                              // 0x0290 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              SpawnRadius;                                   // 0x0294 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class TArray<struct FBehaviorEntry>                ReachedBehaviors;                              // 0x0298 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class AGameCrowdAgent*                             AgentEnRoute;                                  // 0x02A4 (0x0004) [0x0000000000000000]               
	float                                              Priority;                                      // 0x02A8 (0x0004) [0x0000000000000000]               
	float                                              LastSpawnTime;                                 // 0x02AC (0x0004) [0x0000000000000000]               
	class AGameCrowdPopulationManager*                 MyPopMgr;                                      // 0x02B0 (0x0004) [0x0000000000002000] (CPF_Transient)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameCrowdDestination");
		}

		return uClassPointer;
	};


	void GetSpawnPosition(class USeqAct_GameCrowdSpawner* Spawner, struct FVector& outSpawnPos, struct FRotator& outSpawnRot);
	bool eventAllowableDestinationFor(class AGameCrowdAgent* Agent);
	bool AtCapacity();
	void eventIncrementCustomerCount(class AGameCrowdAgent* ArrivingAgent);
	void eventDecrementCustomerCount(class AGameCrowdAgent* DepartingAgent);
	void PickNewDestinationFor(class AGameCrowdAgent* Agent, bool bIgnoreRestrictions);
	void eventReachedDestination(class AGameCrowdAgent* Agent);
	void Destroyed();
	void PostBeginPlay();
	bool ReachedByAgent(class AGameCrowdAgent* Agent, const struct FVector& TestPosition, bool bTestExactly);
};
// Class GameFramework.GameCrowdDestinationQueuePoint
// 0x001C (0x0230 - 0x024C)
class AGameCrowdDestinationQueuePoint : public AGameCrowdInteractionPoint
{
public:
	class AGameCrowdDestinationQueuePoint*             NextQueuePosition;                             // 0x0230 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class AGameCrowdInteractionPoint*                  PreviousQueuePosition;                         // 0x0234 (0x0004) [0x0000000000000000]               
	class AGameCrowdAgent*                             QueuedAgent;                                   // 0x0238 (0x0004) [0x0000000000000000]               
	class AGameCrowdDestination*                       QueueDestination;                              // 0x023C (0x0004) [0x0000000000002000] (CPF_Transient)
	uint32_t                                           bClearingQueue : 1;                            // 0x0240 (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bPendingAdvance : 1;                           // 0x0240 (0x0004) [0x0000000000000000] [0x00000002] 
	float                                              AverageReactionTime;                           // 0x0244 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class UClass*                                      QueueBehaviorClass;                            // 0x0248 (0x0004) [0x0000000000000000]               

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameCrowdDestinationQueuePoint");
		}

		return uClassPointer;
	};


	bool HasCustomer();
	void ClearQueue(class AGameCrowdAgent* OldCustomer);
	void AddCustomer(class AGameCrowdAgent* NewCustomer, class AGameCrowdInteractionPoint* PreviousPosition);
	void ActuallyAdvance();
	void AdvanceCustomerTo(class AGameCrowdInteractionPoint* FrontPosition);
	void eventReachedDestination(class AGameCrowdAgent* Agent);
	bool HasSpace();
	bool QueueReachedBy(class AGameCrowdAgent* Agent, const struct FVector& TestPosition);
};
// Class GameFramework.GameCrowdForcePoint
// 0x0000 (0x0230 - 0x0230)
class AGameCrowdForcePoint : public AGameCrowdInteractionPoint
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameCrowdForcePoint");
		}

		return uClassPointer;
	};


	struct FVector eventAppliedForce(class AGameCrowdAgent* Agent);
	void eventUnTouch(class AActor* Other);
	void eventTouch(class AActor* Other, class UPrimitiveComponent* OtherComp, const struct FVector& HitLocation, const struct FVector& HitNormal);
};
// Class GameFramework.GameCrowdAttractor
// 0x0008 (0x0230 - 0x0238)
class AGameCrowdAttractor : public AGameCrowdForcePoint
{
public:
	float                                              Attraction;                                    // 0x0230 (0x0004) [0x0000000200000001] (CPF_Edit | CPF_Interp)
	uint32_t                                           bAttractionFalloff : 1;                        // 0x0234 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameCrowdAttractor");
		}

		return uClassPointer;
	};


	struct FVector eventAppliedForce(class AGameCrowdAgent* Agent);
};
// Class GameFramework.GameCrowdRepulsor
// 0x0008 (0x0230 - 0x0238)
class AGameCrowdRepulsor : public AGameCrowdForcePoint
{
public:
	float                                              Repulsion;                                     // 0x0230 (0x0004) [0x0000000200000001] (CPF_Edit | CPF_Interp)
	uint32_t                                           bAttractionFalloff : 1;                        // 0x0234 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameCrowdRepulsor");
		}

		return uClassPointer;
	};


	struct FVector eventAppliedForce(class AGameCrowdAgent* Agent);
};
// Class GameFramework.GameCrowdPopulationManager
// 0x0098 (0x0228 - 0x02C0)
class AGameCrowdPopulationManager : public ACrowdPopulationManagerBase
{
public:
	struct FPointer                                    VfTable_IInterface_NavigationHandle;           // 0x0228 (0x0004) [0x0000000000801002] (CPF_Const | CPF_Native | CPF_NoExport)
	uint32_t                                           bSpawningActive : 1;                           // 0x022C (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bEnableCrowdLightEnvironment : 1;              // 0x022C (0x0004) [0x0000000000000000] [0x00000002] 
	uint32_t                                           bCastShadows : 1;                              // 0x022C (0x0004) [0x0000000000000000] [0x00000004] 
	uint32_t                                           bForceObstacleChecking : 1;                    // 0x022C (0x0004) [0x0000000000000000] [0x00000008] 
	uint32_t                                           bForceNavMeshPathing : 1;                      // 0x022C (0x0004) [0x0000000000000000] [0x00000010] 
	uint32_t                                           bHaveInitialPopulation : 1;                    // 0x022C (0x0004) [0x0000000000000000] [0x00000020] 
	uint32_t                                           bWarmupPosition : 1;                           // 0x022C (0x0004) [0x0000000000000001] [0x00000040] (CPF_Edit)
	float                                              SpawnRate;                                     // 0x0230 (0x0004) [0x0000000000000000]               
	int32_t                                            SpawnNum;                                      // 0x0234 (0x0004) [0x0000000000000000]               
	float                                              SplitScreenNumReduction;                       // 0x0238 (0x0004) [0x0000000000000000]               
	float                                              Remainder;                                     // 0x023C (0x0004) [0x0000000000000000]               
	float                                              AgentFrequencySum;                             // 0x0240 (0x0004) [0x0000000000000000]               
	class TArray<struct FAgentArchetypeInfo>           AgentArchetypes;                               // 0x0244 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<class AGameCrowdAgent*>               AgentPool;                                     // 0x0250 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	int32_t                                            MaxAgentPoolSize;                              // 0x025C (0x0004) [0x0000000000000000]               
	int32_t                                            AgentCount;                                    // 0x0260 (0x0004) [0x0000000000000000]               
	struct FLightingChannelContainer                   AgentLightingChannel;                          // 0x0264 (0x0004) [0x0000000000000000]               
	float                                              AgentWarmupTime;                               // 0x0268 (0x0004) [0x0000000000000000]               
	float                                              SpawnPrioritizationInterval;                   // 0x026C (0x0004) [0x0000000000000000]               
	int32_t                                            PrioritizationIndex;                           // 0x0270 (0x0004) [0x0000000000000000]               
	int32_t                                            PrioritizationUpdateIndex;                     // 0x0274 (0x0004) [0x0000000000000000]               
	class TArray<class AGameCrowdDestination*>         PrioritizedSpawnPoints;                        // 0x0278 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	float                                              PlayerPositionPredictionTime;                  // 0x0284 (0x0004) [0x0000000000000000]               
	class TArray<class AGameCrowdDestination*>         PotentialSpawnPoints;                          // 0x0288 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	float                                              MaxSpawnDist;                                  // 0x0294 (0x0004) [0x0000000000000000]               
	float                                              MaxSpawnDistSq;                                // 0x0298 (0x0004) [0x0000000000000000]               
	float                                              MinBehindSpawnDistSq;                          // 0x029C (0x0004) [0x0000000000000000]               
	int32_t                                            SpawnedCount;                                  // 0x02A0 (0x0004) [0x0000000000000000]               
	int32_t                                            PoolCount;                                     // 0x02A4 (0x0004) [0x0000000000000000]               
	int32_t                                            KilledCount;                                   // 0x02A8 (0x0004) [0x0000000000000000]               
	float                                              HeadVisibilityOffset;                          // 0x02AC (0x0004) [0x0000000000000000]               
	float                                              InitialPopulationPct;                          // 0x02B0 (0x0004) [0x0000000000000000]               
	class UClass*                                      NavigationHandleClass;                         // 0x02B4 (0x0004) [0x0000000000000000]               
	class UNavigationHandle*                           NavigationHandle;                              // 0x02B8 (0x0004) [0x0000000000000000]               
	class AGameCrowdAgent*                             QueryingAgent;                                 // 0x02BC (0x0004) [0x0000000000000000]               

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameCrowdPopulationManager");
		}

		return uClassPointer;
	};


	class AGameCrowdAgent* CreateNewAgent(class AGameCrowdDestination* SpawnLoc, class AGameCrowdAgent* AgentTemplate, class UGameCrowdGroup* NewGroup);
	class AGameCrowdAgent* eventSpawnAgent(class AGameCrowdDestination* SpawnLoc);
	bool ValidateSpawnAt(class AGameCrowdDestination* Candidate);
	void AddPrioritizedSpawnPoint(class AGameCrowdDestination* GCD, const struct FVector& ViewLocation);
	void AnalyzeSpawnPoints(int32_t StartIndex, int32_t StopIndex, const struct FVector& ViewLocation, const struct FVector& PredictionLocation);
	void PrioritizeSpawnPoints(float DeltaSeconds);
	class AGameCrowdDestination* PickSpawnPoint();
	void Tick(float DeltaSeconds);
	void DisplayDebug(class AHUD* HUD, float& outOut_YL, float& outOut_YPos);
	bool AddToAgentPool(class AGameCrowdAgent* Agent);
	void AgentDestroyed(class AGameCrowdAgent* Agent);
	void OnGameCrowdPopulationManagerToggle(class USeqAct_GameCrowdPopulationManagerToggle* inAction);
	void RemoveSpawnPoint(class AGameCrowdDestination* GCD);
	void AddSpawnPoint(class AGameCrowdDestination* GCD);
	float GetMaxSpawnDist();
	void eventNotifyPathChanged();
	void PostBeginPlay();
};
// Class GameFramework.GameCrowdReplicationActor
// 0x000C (0x0228 - 0x0234)
class AGameCrowdReplicationActor : public AActor
{
public:
	class USeqAct_GameCrowdSpawner*                    Spawner;                                       // 0x0228 (0x0004) [0x0000000100000020] (CPF_Net | CPF_RepNotify)
	uint32_t                                           bSpawningActive : 1;                           // 0x022C (0x0004) [0x0000000100000020] [0x00000001] (CPF_Net | CPF_RepNotify)
	int32_t                                            DestroyAllCount;                               // 0x0230 (0x0004) [0x0000000100000020] (CPF_Net | CPF_RepNotify)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameCrowdReplicationActor");
		}

		return uClassPointer;
	};


	void eventReplicatedEvent(const class FName& VarName);
};
// Class GameFramework.GameDamageType
// 0x003C (0x006C - 0x00A8)
class UGameDamageType : public UDamageType
{
public:
	class UMaterialInterface*                          MI_DamageOverlay;                              // 0x006C (0x0004) [0x0000000000000002] (CPF_Const)   
	class USoundCue*                                   ExtraSoundToPlayWhenDamaged;                   // 0x0070 (0x0004) [0x0000000000000002] (CPF_Const)   
	uint32_t                                           bEnvironmentalDamage : 1;                      // 0x0074 (0x0004) [0x0000000000000002] [0x00000001] (CPF_Const)
	uint32_t                                           bHighKickDeathAnimation : 1;                   // 0x0074 (0x0004) [0x0000000000004002] [0x00000002] (CPF_Const | CPF_Config)
	uint32_t                                           bForceRagdollDeath : 1;                        // 0x0074 (0x0004) [0x0000000000000002] [0x00000004] (CPF_Const)
	uint32_t                                           bSuppressImpactFX : 1;                         // 0x0074 (0x0004) [0x0000000000000002] [0x00000008] (CPF_Const)
	uint32_t                                           bSuppressBloodDecals : 1;                      // 0x0074 (0x0004) [0x0000000000000002] [0x00000010] (CPF_Const)
	uint32_t                                           bSuppressPlayExplosiveRadialDamageEffects : 1; // 0x0074 (0x0004) [0x0000000000000002] [0x00000020] (CPF_Const)
	uint32_t                                           bAllowHeadShotGib : 1;                         // 0x0074 (0x0004) [0x0000000000004002] [0x00000040] (CPF_Const | CPF_Config)
	float                                              DistFromHitLocToGib;                           // 0x0078 (0x0004) [0x0000000000004002] (CPF_Const | CPF_Config)
	struct FCanvasIcon                                 KilledByIcon;                                  // 0x007C (0x0014) [0x0000000000000002] (CPF_Const)   
	struct FCanvasIcon                                 HeadshotIcon;                                  // 0x0090 (0x0014) [0x0000000000000002] (CPF_Const)   
	float                                              IconScale;                                     // 0x00A4 (0x0004) [0x0000000000000002] (CPF_Const)   

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameDamageType");
		}

		return uClassPointer;
	};


	static void HandleDamageFX(class AGamePawn* DamagedPawn, struct FTakeHitInfo& outHitInfo);
	static bool ShouldHeadShotGib(class APawn* TestPawn, class APawn* Instigator);
	static void PlayExtraDamageSound(class APawn* VictimPawn);
	static bool IsScriptedDamageType();
	static bool ShouldPlayForceFeedback(class APawn* DamagedPawn);
	static void HandleDeadPlayer(class AGamePlayerController* Player);
	static void HandleKilledPawn(class APawn* KilledPawn, class APawn* Instigator);
	static void HandleDamagedPawn(class APawn* DamagedPawn, class APawn* Instigator, int32_t DamageAmt, const struct FVector& Momentum);
	static void ModifyDamage(class APawn* Victim, class AController* InstigatedBy, const struct FVector& HitLocation, const struct FTraceHitInfo& HitInfo, int32_t& outOut_Damage, struct FVector& outOut_Momentum);
	static bool ShouldGib(class APawn* TestPawn, class APawn* Instigator);
};
// Class GameFramework.GameDestinationConnRenderingComponent
// 0x0000 (0x01D4 - 0x01D4)
class UGameDestinationConnRenderingComponent : public UPrimitiveComponent
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameDestinationConnRenderingComponent");
		}

		return uClassPointer;
	};

};
// Class GameFramework.GameExplosion
// 0x00B0 (0x003C - 0x00EC)
class UGameExplosion : public UObject
{
public:
	uint32_t                                           bDirectionalExplosion : 1;                     // 0x003C (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bAllowTeammateCringes : 1;                     // 0x003C (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint32_t                                           bFullDamageToAttachee : 1;                     // 0x003C (0x0004) [0x0000000000002000] [0x00000004] (CPF_Transient)
	uint32_t                                           bAttachExplosionEmitterToAttachee : 1;         // 0x003C (0x0004) [0x0000000000000001] [0x00000008] (CPF_Edit)
	uint32_t                                           bCausesFracture : 1;                           // 0x003C (0x0004) [0x0000000000000001] [0x00000010] (CPF_Edit)
	uint32_t                                           bAllowPerMaterialFX : 1;                       // 0x003C (0x0004) [0x0000000000000001] [0x00000020] (CPF_Edit)
	uint32_t                                           bParticleSystemIsBeingOverriddenDontUsePhysMatVersion : 1;// 0x003C (0x0004) [0x0000000000000001] [0x00000040] (CPF_Edit)
	uint32_t                                           bUseMapSpecificValues : 1;                     // 0x003C (0x0004) [0x0000000000000001] [0x00000080] (CPF_Edit)
	uint32_t                                           bUseOverlapCheck : 1;                          // 0x003C (0x0004) [0x0000000000000001] [0x00000100] (CPF_Edit)
	uint32_t                                           bOrientCameraShakeTowardsEpicenter : 1;        // 0x003C (0x0004) [0x0000000000000001] [0x00000200] (CPF_Edit)
	uint32_t                                           bAutoControllerVibration : 1;                  // 0x003C (0x0004) [0x0000000000000001] [0x00000400] (CPF_Edit)
	float                                              DirectionalExplosionAngleDeg;                  // 0x0040 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              DamageDelay;                                   // 0x0044 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              Damage;                                        // 0x0048 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              DamageRadius;                                  // 0x004C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              DamageFalloffExponent;                         // 0x0050 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class AActor*                                      ActorToIgnoreForDamage;                        // 0x0054 (0x0004) [0x0000000000002000] (CPF_Transient)
	class UClass*                                      ActorClassToIgnoreForDamage;                   // 0x0058 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class UClass*                                      ActorClassToIgnoreForKnockdownsAndCringes;     // 0x005C (0x0004) [0x0000000000000001] (CPF_Edit)    
	class UClass*                                      MyDamageType;                                  // 0x0060 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              KnockDownRadius;                               // 0x0064 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              KnockDownStrength;                             // 0x0068 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              CringeRadius;                                  // 0x006C (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FVector2D                                   CringeDuration;                                // 0x0070 (0x0008) [0x0000000000000001] (CPF_Edit)    
	float                                              MomentumTransferScale;                         // 0x0078 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class UParticleSystem*                             ParticleEmitterTemplate;                       // 0x007C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              ExplosionEmitterScale;                         // 0x0080 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class AActor*                                      HitActor;                                      // 0x0084 (0x0004) [0x0000000000000000]               
	struct FVector                                     HitLocation;                                   // 0x0088 (0x000C) [0x0000000000000000]               
	struct FVector                                     HitNormal;                                     // 0x0094 (0x000C) [0x0000000000000000]               
	class USoundCue*                                   ExplosionSound;                                // 0x00A0 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class UPointLightComponent*                        ExploLight;                                    // 0x00A4 (0x0004) [0x0000000004080009] (CPF_Edit | CPF_ExportObject | CPF_Component | CPF_EditInline)
	float                                              ExploLightFadeOutTime;                         // 0x00A8 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class URadialBlurComponent*                        ExploRadialBlur;                               // 0x00AC (0x0004) [0x0000000004080009] (CPF_Edit | CPF_ExportObject | CPF_Component | CPF_EditInline)
	float                                              ExploRadialBlurFadeOutTime;                    // 0x00B0 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              ExploRadialBlurMaxBlur;                        // 0x00B4 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              FractureMeshRadius;                            // 0x00B8 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              FracturePartVel;                               // 0x00BC (0x0004) [0x0000000000000001] (CPF_Edit)    
	class AActor*                                      Attachee;                                      // 0x00C0 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class AController*                                 AttacheeController;                            // 0x00C4 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class UCameraShake*                                CamShake;                                      // 0x00C8 (0x0004) [0x0000000004000001] (CPF_Edit | CPF_EditInline)
	class UCameraShake*                                CamShake_Left;                                 // 0x00CC (0x0004) [0x0000000004000001] (CPF_Edit | CPF_EditInline)
	class UCameraShake*                                CamShake_Right;                                // 0x00D0 (0x0004) [0x0000000004000001] (CPF_Edit | CPF_EditInline)
	class UCameraShake*                                CamShake_Rear;                                 // 0x00D4 (0x0004) [0x0000000004000001] (CPF_Edit | CPF_EditInline)
	float                                              CamShakeInnerRadius;                           // 0x00D8 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              CamShakeOuterRadius;                           // 0x00DC (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              CamShakeFalloff;                               // 0x00E0 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class UClass*                                      CameraLensEffect;                              // 0x00E4 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              CameraLensEffectRadius;                        // 0x00E8 (0x0004) [0x0000000000000001] (CPF_Edit)    

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameExplosion");
		}

		return uClassPointer;
	};

};
// Class GameFramework.GameExplosionActor
// 0x0050 (0x0228 - 0x0278)
class AGameExplosionActor : public AActor
{
public:
	uint32_t                                           bHasExploded : 1;                              // 0x0228 (0x0004) [0x0000000000002000] [0x00000001] (CPF_Transient)
	uint32_t                                           bActiveReloadBonusActive : 1;                  // 0x0228 (0x0004) [0x0000000000000000] [0x00000002] 
	uint32_t                                           bDrawDebug : 1;                                // 0x0228 (0x0004) [0x0000000000000000] [0x00000004] 
	class UPointLightComponent*                        ExplosionLight;                                // 0x022C (0x0004) [0x0000000004082008] (CPF_ExportObject | CPF_Transient | CPF_Component | CPF_EditInline)
	float                                              LightFadeTime;                                 // 0x0230 (0x0004) [0x0000000000002000] (CPF_Transient)
	float                                              LightFadeTimeRemaining;                        // 0x0234 (0x0004) [0x0000000000002000] (CPF_Transient)
	float                                              LightInitialBrightness;                        // 0x0238 (0x0004) [0x0000000000002000] (CPF_Transient)
	class URadialBlurComponent*                        ExplosionRadialBlur;                           // 0x023C (0x0004) [0x0000000004082008] (CPF_ExportObject | CPF_Transient | CPF_Component | CPF_EditInline)
	float                                              RadialBlurFadeTime;                            // 0x0240 (0x0004) [0x0000000000002000] (CPF_Transient)
	float                                              RadialBlurFadeTimeRemaining;                   // 0x0244 (0x0004) [0x0000000000002000] (CPF_Transient)
	float                                              RadialBlurMaxBlurAmount;                       // 0x0248 (0x0004) [0x0000000000002000] (CPF_Transient)
	class UGameExplosion*                              ExplosionTemplate;                             // 0x024C (0x0004) [0x0000000000000000]               
	class URB_RadialImpulseComponent*                  RadialImpulseComponent;                        // 0x0250 (0x0004) [0x0000000004080008] (CPF_ExportObject | CPF_Component | CPF_EditInline)
	class AController*                                 InstigatorController;                          // 0x0254 (0x0004) [0x0000000000000000]               
	class AActor*                                      HitActorFromPhysMaterialTrace;                 // 0x0258 (0x0004) [0x0000000000000000]               
	struct FVector                                     HitLocationFromPhysMaterialTrace;              // 0x025C (0x000C) [0x0000000000000000]               
	float                                              DirectionalExplosionMinDot;                    // 0x0268 (0x0004) [0x0000000000002000] (CPF_Transient)
	struct FVector                                     ExplosionDirection;                            // 0x026C (0x000C) [0x0000000000002020] (CPF_Net | CPF_Transient)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameExplosionActor");
		}

		return uClassPointer;
	};


	class UCameraShake* ChooseCameraShake(const struct FVector& Epicenter, class APlayerController* PC);
	void SpawnCameraLensEffects();
	void DoExplosionCameraEffects();
	void Tick(float DeltaTime);
	void DoExplosionDamage();
	void DrawDebug();
	void Explode(class UGameExplosion* NewExplosionTemplate, const struct FVector& optionalDirection);
	void SpawnExplosionFogVolume();
	void SpawnExplosionDecal();
	void SpawnExplosionParticleSystem(class UParticleSystem* Template);
	void UpdateExplosionTemplateWithPerMaterialFX(class UPhysicalMaterial* PhysMaterial);
	void KnockdownPawn(class AGamePawn* Victim, float DistFromExplosion);
	void CringePawn(class AGamePawn* Victim, float DistFromExplosion);
	void DoCringesAndKnockdowns();
	bool ShouldDoCringeFor(class AGamePawn* Victim);
	void DoBreakFracturedMeshes(const struct FVector& ExploOrigin, float DamageRadius, float RBStrength, class UClass* dmgType);
	void HurtExplosion(float BaseDamage, float DamageRadius, float DamageFalloffExp, class UClass* DamageType, float MomentumScale, const struct FVector& ExploOrigin, class AActor* IgnoredActor, class UClass* ActorClassToIgnoreForDamage, class AController* InstigatedByController, bool bDoFullDamage);
	bool IsBehindExplosion(class AActor* A);
	bool DoFullDamageToActor(class AActor* Victim);
	class UPhysicalMaterial* GetPhysicalMaterial();
	void eventPreBeginPlay();
};
// Class GameFramework.GameHUD
// 0x0000 (0x04B4 - 0x04B4)
class AGameHUD : public AHUD
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameHUD");
		}

		return uClassPointer;
	};

};
// Class GameFramework.MobileHUD
// 0x003C (0x04B4 - 0x04F0)
class AMobileHUD : public AGameHUD
{
public:
	uint32_t                                           bShowGameHUD : 1;                              // 0x04B4 (0x0004) [0x0000000000004000] [0x00000001] (CPF_Config)
	uint32_t                                           bForceMobileHUD : 1;                           // 0x04B4 (0x0004) [0x0000000000044000] [0x00000002] (CPF_Config | CPF_GlobalConfig)
	class UTexture2D*                                  ZoneBackgroundOn;                              // 0x04B8 (0x0004) [0x0000000000000000]               
	class UTexture2D*                                  ZoneBackgroundSmallOn;                         // 0x04BC (0x0004) [0x0000000000000000]               
	class UTexture2D*                                  ZoneBackgroundTinyOn;                          // 0x04C0 (0x0004) [0x0000000000000000]               
	class UTexture2D*                                  FireZoneBackground;                            // 0x04C4 (0x0004) [0x0000000000000000]               
	class UTexture2D*                                  MoveZoneBackground;                            // 0x04C8 (0x0004) [0x0000000000000000]               
	class UTexture2D*                                  SteerZoneBackground;                           // 0x04CC (0x0004) [0x0000000000000000]               
	struct FColor                                      ZoneTileColor;                                 // 0x04D0 (0x0004) [0x0000000000000000]               
	struct FColor                                      ZoneTextColor;                                 // 0x04D4 (0x0004) [0x0000000000000000]               
	class UTexture2D*                                  AnalogHat;                                     // 0x04D8 (0x0004) [0x0000000000000000]               
	class TArray<struct FMobileInputZone>              MobileInputZones;                              // 0x04DC (0x000C) [0x0000000000404000] (CPF_Config | CPF_NeedCtorLink)
	int32_t                                            MobileInputConfig;                             // 0x04E8 (0x0004) [0x0000000000000000]               
	int32_t                                            MobileInputConfigMAX;                          // 0x04EC (0x0004) [0x0000000000000000]               

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.MobileHUD");
		}

		return uClassPointer;
	};


	void ResetMobileInputConfig();
	void NextMobileInputConfig();
	void DrawInputOverlays();
	void PostRender();
	void PostBeginPlay();
};
// Class GameFramework.GamePawn
// 0x0004 (0x05D8 - 0x05DC)
class AGamePawn : public APawn
{
public:
	uint32_t                                           bLastHitWasHeadShot : 1;                       // 0x05D8 (0x0004) [0x0000000000002020] [0x00000001] (CPF_Net | CPF_Transient)
	uint32_t                                           bRespondToExplosions : 1;                      // 0x05D8 (0x0004) [0x0000000000000000] [0x00000002] 

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GamePawn");
		}

		return uClassPointer;
	};


	void eventSphinxNotifyDestory();
	void eventPlayCustomParticleOnSocket(class UParticleSystem* PS, const class FName& Socket);
	void ReattachMeshWithoutBeingSeen();
	void ReattachMesh();
	void eventUpdateShadowSettings(bool bInWantShadow);
	void eventCringe(float optionalDuration);
	void ServerKnockdown(const struct FVector& optionalRBLinearVelocity, const struct FVector& optionalRBAngularVelocity, const struct FVector& optionalRadialOrigin, float optionalRadialRadius, float optionalRadialStrength, const struct FVector& optionalPointImpulse, const struct FVector& optionalPointImpulsePosition, const class FName& optionalPointImpulseBoneName);
	void GetTargetFrictionCylinder(float& outCylinderRadius, float& outCylinderHeight);
	void StopAllConfigAnim(float BlendOutTime, bool optionalBForceStop, bool optionalBForceAnimNotify, bool optionalBForceAnimEnd);
};
// Class GameFramework.GamePlayerController
// 0x0010 (0x0604 - 0x0614)
class AGamePlayerController : public APlayerController
{
public:
	uint32_t                                           bWarnCrowdMembers : 1;                         // 0x0604 (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bDebugCrowdAwareness : 1;                      // 0x0604 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint32_t                                           bIsWarmupPaused : 1;                           // 0x0604 (0x0004) [0x0000000000002000] [0x00000004] (CPF_Transient)
	float                                              AgentAwareRadius;                              // 0x0608 (0x0004) [0x0000000000000000]               
	class FName                                        CurrentSoundMode;                              // 0x060C (0x0008) [0x0000000000002000] (CPF_Transient)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GamePlayerController");
		}

		return uClassPointer;
	};


	void ClientColorFade(const struct FColor& FadeColor, uint8_t FromAlpha, uint8_t ToAlpha, float FadeTime);
	void eventWarmupPause(bool bDesiredPauseState);
	bool CanUnpauseWarmup();
	void GetCurrentMovie(class FString& outMovieName);
	void eventClientStopMovie(float DelayInSeconds, bool bAllowMovieToFinish, bool bForceStopNonSkippable, bool bForceStopLoadingMovie);
	void eventClientPlayMovie(const class FString& MovieName, int32_t optionalInStartOfRenderingMovieFrame, int32_t optionalInEndOfRenderingMovieFrame);
	static void KeepPlayingLoadingMovie();
	static void ShowLoadingMovie(bool bShowMovie, bool optionalBPauseAfterHide, float optionalPauseDuration, float optionalKeepPlayingDuration, bool optionalBOverridePreviousDelays);
	class FName GetCurrentSoundMode();
	bool SetSoundMode(const class FName& InSoundModeName);
	void DoForceFeedbackForScreenShake(class UCameraShake* ShakeData, float Scale);
	void eventNotifyCrowdAgentInRadius(class AGameCrowdAgent* Agent);
	void eventNotifyCrowdAgentRefresh();
	void CrowdDebug(bool bEnabled);
	void CrowdToggle();
	void CrowdFocus();
	int32_t GetUIPlayerIndex();
};
// Class GameFramework.GamePlayerInput
// 0x0000 (0x0184 - 0x0184)
class UGamePlayerInput : public UPlayerInput
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GamePlayerInput");
		}

		return uClassPointer;
	};

};
// Class GameFramework.GameProjectile
// 0x0000 (0x0268 - 0x0268)
class AGameProjectile : public AProjectile
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameProjectile");
		}

		return uClassPointer;
	};

};
// Class GameFramework.GameTypes
// 0x0000 (0x003C - 0x003C)
class UGameTypes : public UObject
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameTypes");
		}

		return uClassPointer;
	};

};
// Class GameFramework.GameVehicle
// 0x0000 (0x0768 - 0x0768)
class AGameVehicle : public ASVehicle
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameVehicle");
		}

		return uClassPointer;
	};

};
// Class GameFramework.GameWeapon
// 0x0000 (0x0324 - 0x0324)
class AGameWeapon : public AWeapon
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameWeapon");
		}

		return uClassPointer;
	};

};
// Class GameFramework.NavMeshGoal_OutOfViewFrom
// 0x0014 (0x0050 - 0x0064)
class UNavMeshGoal_OutOfViewFrom : public UNavMeshPathGoalEvaluator
{
public:
	struct FPointer                                    GoalPoly;                                      // 0x0050 (0x0004) [0x0000000000001000] (CPF_Native)  
	struct FVector                                     OutOfViewLocation;                             // 0x0054 (0x000C) [0x0000000000000000]               
	uint32_t                                           bShowDebug : 1;                                // 0x0060 (0x0004) [0x0000000000000000] [0x00000001] 

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.NavMeshGoal_OutOfViewFrom");
		}

		return uClassPointer;
	};


	void Recycle();
	static bool MustBeHiddenFromThisPoint(class UNavigationHandle* NavHandle, const struct FVector& InOutOfViewLocation);
	void RecycleNative();
};
// Class GameFramework.NavMeshPath_BiasAgainstPolysWithinDistanceOfLocations
// 0x0028 (0x0050 - 0x0078)
class UNavMeshPath_BiasAgainstPolysWithinDistanceOfLocations : public UNavMeshPathConstraint
{
public:
	struct FVector                                     Location;                                      // 0x0050 (0x000C) [0x0000000000002000] (CPF_Transient)
	struct FVector                                     Rotation;                                      // 0x005C (0x000C) [0x0000000000002000] (CPF_Transient)
	float                                              DistanceToCheck;                               // 0x0068 (0x0004) [0x0000000000002000] (CPF_Transient)
	class TArray<struct FVector>                       LocationsToCheck;                              // 0x006C (0x000C) [0x0000000000402000] (CPF_Transient | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.NavMeshPath_BiasAgainstPolysWithinDistanceOfLocations");
		}

		return uClassPointer;
	};


	void Recycle();
	static bool BiasAgainstPolysWithinDistanceOfLocations(class UNavigationHandle* NavHandle, const struct FVector& InLocation, const struct FRotator& InRotation, float InDistanceToCheck, const class TArray<struct FVector>& InLocationsToCheck);
};
// Class GameFramework.SeqAct_ControlGameMovie
// 0x0014 (0x00F8 - 0x010C)
class USeqAct_ControlGameMovie : public USeqAct_Latent
{
public:
	class FString                                      MovieName;                                     // 0x00F8 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	int32_t                                            StartOfRenderingMovieFrame;                    // 0x0104 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            EndOfRenderingMovieFrame;                      // 0x0108 (0x0004) [0x0000000000000001] (CPF_Edit)    

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.SeqAct_ControlGameMovie");
		}

		return uClassPointer;
	};

};
// Class GameFramework.SeqAct_GameCrowdPopulationManagerToggle
// 0x0018 (0x00E8 - 0x0100)
class USeqAct_GameCrowdPopulationManagerToggle : public USequenceAction
{
public:
	float                                              WarmupPct;                                     // 0x00E8 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bKillAgentsInstantly : 1;                      // 0x00EC (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bClearOldArchetypes : 1;                       // 0x00EC (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint32_t                                           bEnableCrowdLightEnvironment : 1;              // 0x00EC (0x0004) [0x0000000000000001] [0x00000004] (CPF_Edit)
	uint32_t                                           bCastShadows : 1;                              // 0x00EC (0x0004) [0x0000000000000001] [0x00000008] (CPF_Edit)
	class UGameCrowd_ListOfAgents*                     CrowdAgentList;                                // 0x00F0 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            MaxAgents;                                     // 0x00F4 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              SpawnRate;                                     // 0x00F8 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              MaxSimulationDistance;                         // 0x00FC (0x0004) [0x0000000000000001] (CPF_Edit)    

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.SeqAct_GameCrowdPopulationManagerToggle");
		}

		return uClassPointer;
	};


	static int32_t eventGetObjClassVersion();
	void eventFindPopMgrTarget();
};
// Class GameFramework.SeqAct_GameCrowdSpawner
// 0x0058 (0x00F8 - 0x0150)
class USeqAct_GameCrowdSpawner : public USeqAct_Latent
{
public:
	uint32_t                                           bSpawningActive : 1;                           // 0x00F8 (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bCycleSpawnLocs : 1;                           // 0x00F8 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint32_t                                           bRespawnDeadAgents : 1;                        // 0x00F8 (0x0004) [0x0000000000000001] [0x00000004] (CPF_Edit)
	uint32_t                                           bHasReducedNumberDueToSplitScreen : 1;         // 0x00F8 (0x0004) [0x0000000000000000] [0x00000008] 
	uint32_t                                           bEnableCrowdLightEnvironment : 1;              // 0x00F8 (0x0004) [0x0000000000000001] [0x00000010] (CPF_Edit)
	uint32_t                                           bForceObstacleChecking : 1;                    // 0x00F8 (0x0004) [0x0000000000000001] [0x00000020] (CPF_Edit)
	uint32_t                                           bForceNavMeshPathing : 1;                      // 0x00F8 (0x0004) [0x0000000000000001] [0x00000040] (CPF_Edit)
	uint32_t                                           bOnlySpawnHidden : 1;                          // 0x00F8 (0x0004) [0x0000000000000001] [0x00000080] (CPF_Edit)
	uint32_t                                           bWarmupPosition : 1;                           // 0x00F8 (0x0004) [0x0000000000000001] [0x00000100] (CPF_Edit)
	uint32_t                                           bCastShadows : 1;                              // 0x00F8 (0x0004) [0x0000000000000001] [0x00000200] (CPF_Edit)
	int32_t                                            NextDestinationIndex;                          // 0x00FC (0x0004) [0x0000000000000000]               
	class TArray<class AActor*>                        SpawnLocs;                                     // 0x0100 (0x000C) [0x0000000000402000] (CPF_Transient | CPF_NeedCtorLink)
	int32_t                                            LastSpawnLocIndex;                             // 0x010C (0x0004) [0x0000000000002000] (CPF_Transient)
	float                                              SpawnRate;                                     // 0x0110 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            SpawnNum;                                      // 0x0114 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              SpawnRadius;                                   // 0x0118 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              SplitScreenNumReduction;                       // 0x011C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              Remainder;                                     // 0x0120 (0x0004) [0x0000000000000000]               
	float                                              AgentFrequencySum;                             // 0x0124 (0x0004) [0x0000000000000000]               
	class UGameCrowd_ListOfAgents*                     CrowdAgentList;                                // 0x0128 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class TArray<struct FAgentArchetypeInfo>           AgentArchetypes;                               // 0x012C (0x000C) [0x0000000000402000] (CPF_Transient | CPF_NeedCtorLink)
	class TArray<class AGameCrowdAgent*>               SpawnedList;                                   // 0x0138 (0x000C) [0x0000000000402000] (CPF_Transient | CPF_NeedCtorLink)
	struct FLightingChannelContainer                   AgentLightingChannel;                          // 0x0144 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class AGameCrowdReplicationActor*                  RepActor;                                      // 0x0148 (0x0004) [0x0000000000000000]               
	float                                              AgentWarmupTime;                               // 0x014C (0x0004) [0x0000000000000001] (CPF_Edit)    

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.SeqAct_GameCrowdSpawner");
		}

		return uClassPointer;
	};


	static int32_t eventGetObjClassVersion();
	class AGameCrowdAgent* CreateNewAgent(class AActor* SpawnLoc, class AGameCrowdAgent* AgentTemplate, class UGameCrowdGroup* NewGroup);
	class AGameCrowdAgent* eventSpawnAgent(class AActor* SpawnLoc);
	void UpdateSpawning(float DeltaSeconds);
	void KillAgents();
	void CacheSpawnerVars();
	void SpawnedAgent(class AGameCrowdAgent* NewAgent);
};
// Class GameFramework.SeqAct_ModifyProperty
// 0x000C (0x00E8 - 0x00F4)
class USeqAct_ModifyProperty : public USequenceAction
{
public:
	class TArray<struct FPropertyInfo>                 Properties;                                    // 0x00E8 (0x000C) [0x0000000004400001] (CPF_Edit | CPF_NeedCtorLink | CPF_EditInline)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.SeqAct_ModifyProperty");
		}

		return uClassPointer;
	};

};
// Class GameFramework.SeqAct_PlayAgentAnimation
// 0x0024 (0x00F8 - 0x011C)
class USeqAct_PlayAgentAnimation : public USeqAct_Latent
{
public:
	class TArray<class FName>                          AnimationList;                                 // 0x00F8 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	float                                              BlendInTime;                                   // 0x0104 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              BlendOutTime;                                  // 0x0108 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bUseRootMotion : 1;                            // 0x010C (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bFaceActionTargetFirst : 1;                    // 0x010C (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint32_t                                           bLooping : 1;                                  // 0x010C (0x0004) [0x0000000000000001] [0x00000004] (CPF_Edit)
	uint32_t                                           bBlendBetweenAnims : 1;                        // 0x010C (0x0004) [0x0000000000000001] [0x00000008] (CPF_Edit)
	int32_t                                            LoopIndex;                                     // 0x0110 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              LoopTime;                                      // 0x0114 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class AActor*                                      ActionTarget;                                  // 0x0118 (0x0004) [0x0000000000000000]               

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.SeqAct_PlayAgentAnimation");
		}

		return uClassPointer;
	};


	void SetCurrentAnimationActionFor(class AGameCrowdAgentSkeletal* Agent);
	static int32_t eventGetObjClassVersion();
};
// Class GameFramework.SeqEvent_CrowdAgentReachedDestination
// 0x0000 (0x0100 - 0x0100)
class USeqEvent_CrowdAgentReachedDestination : public USequenceEvent
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.SeqEvent_CrowdAgentReachedDestination");
		}

		return uClassPointer;
	};

};
// Class GameFramework.GameSkelCtrl_Recoil
// 0x007C (0x00C4 - 0x0140)
class UGameSkelCtrl_Recoil : public USkelControlBase
{
public:
	uint32_t                                           bBoneSpaceRecoil : 1;                          // 0x00C4 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bPlayRecoil : 1;                               // 0x00C4 (0x0004) [0x0000000000002001] [0x00000002] (CPF_Edit | CPF_Transient)
	uint32_t                                           bOldPlayRecoil : 1;                            // 0x00C4 (0x0004) [0x0000000000002000] [0x00000004] (CPF_Transient)
	uint32_t                                           bApplyControl : 1;                             // 0x00C4 (0x0004) [0x0000000000002000] [0x00000008] (CPF_Transient)
	struct FRecoilDef                                  Recoil;                                        // 0x00C8 (0x0070) [0x0000000000000001] (CPF_Edit)    
	struct FVector2D                                   Aim;                                           // 0x0138 (0x0008) [0x0000000000000001] (CPF_Edit)    

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameSkelCtrl_Recoil");
		}

		return uClassPointer;
	};

};
// Class GameFramework.GameCameraBase
// 0x0008 (0x003C - 0x0044)
class UGameCameraBase : public UObject
{
public:
	class AGamePlayerCamera*                           PlayerCamera;                                  // 0x003C (0x0004) [0x0000000000002000] (CPF_Transient)
	uint32_t                                           bResetCameraInterpolation : 1;                 // 0x0040 (0x0004) [0x0000000000002000] [0x00000001] (CPF_Transient)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameCameraBase");
		}

		return uClassPointer;
	};


	void eventModifyPostProcessSettings(struct FPostProcessSettings& outPP);
	void Init();
	void ProcessViewRotation(float DeltaTime, class AActor* ViewTarget, struct FRotator& outOut_ViewRotation, struct FRotator& outOut_DeltaRot);
	void UpdateCamera(class APawn* P, class AGamePlayerCamera* CameraActor, float DeltaTime, struct FTViewTarget& outOutVT);
	void ResetInterpolation();
	void OnBecomeInActive(class UGameCameraBase* NewCamera);
	void OnBecomeActive(class UGameCameraBase* OldCamera);
};
// Class GameFramework.GameThirdPersonCamera
// 0x0134 (0x0044 - 0x0178)
class UGameThirdPersonCamera : public UGameCameraBase
{
public:
	struct FVector                                     LastActualCameraOrigin;                        // 0x0044 (0x000C) [0x0000000000002000] (CPF_Transient)
	float                                              WorstLocBlockedPct;                            // 0x0050 (0x0004) [0x0000000000000000]               
	float                                              WorstLocPenetrationExtentScale;                // 0x0054 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              PenetrationBlendOutTime;                       // 0x0058 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              PenetrationBlendInTime;                        // 0x005C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              PenetrationBlockedPct;                         // 0x0060 (0x0004) [0x0000000000000000]               
	float                                              PenetrationExtentScale;                        // 0x0064 (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FVector                                     LastActualOriginOffset;                        // 0x0068 (0x000C) [0x0000000000002000] (CPF_Transient)
	struct FRotator                                    LastActualCameraOriginRot;                     // 0x0074 (0x000C) [0x0000000000002000] (CPF_Transient)
	float                                              OriginOffsetInterpSpeed;                       // 0x0080 (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FVector                                     LastViewOffset;                                // 0x0084 (0x000C) [0x0000000000002000] (CPF_Transient)
	float                                              LastCamFOV;                                    // 0x0090 (0x0004) [0x0000000000002000] (CPF_Transient)
	class UGameThirdPersonCameraMode*                  ThirdPersonCamDefault;                         // 0x0094 (0x0004) [0x0000000004000001] (CPF_Edit | CPF_EditInline)
	class UClass*                                      ThirdPersonCamDefaultClass;                    // 0x0098 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class UGameThirdPersonCameraMode*                  CurrentCamMode;                                // 0x009C (0x0004) [0x0000000004002001] (CPF_Edit | CPF_Transient | CPF_EditInline)
	float                                              LastHeightAdjustment;                          // 0x00A0 (0x0004) [0x0000000000002000] (CPF_Transient)
	float                                              LastPitchAdjustment;                           // 0x00A4 (0x0004) [0x0000000000002000] (CPF_Transient)
	float                                              LastYawAdjustment;                             // 0x00A8 (0x0004) [0x0000000000002000] (CPF_Transient)
	float                                              LeftoverPitchAdjustment;                       // 0x00AC (0x0004) [0x0000000000002000] (CPF_Transient)
	float                                              Focus_BackOffStrength;                         // 0x00B0 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              Focus_StepHeightAdjustment;                    // 0x00B4 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            Focus_MaxTries;                                // 0x00B8 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              Focus_FastAdjustKickInTime;                    // 0x00BC (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              LastFocusChangeTime;                           // 0x00C0 (0x0004) [0x0000000000002000] (CPF_Transient)
	struct FVector                                     ActualFocusPointWorldLoc;                      // 0x00C4 (0x000C) [0x0000000000002000] (CPF_Transient)
	struct FVector                                     LastFocusPointLoc;                             // 0x00D0 (0x000C) [0x0000000000002000] (CPF_Transient)
	struct FCamFocusPointParams                        FocusPoint;                                    // 0x00DC (0x0034) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bFocusPointSet : 1;                            // 0x0110 (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bFocusPointSuccessful : 1;                     // 0x0110 (0x0004) [0x0000000000002000] [0x00000002] (CPF_Transient)
	uint32_t                                           bDoingACameraTurn : 1;                         // 0x0110 (0x0004) [0x0000000000000000] [0x00000004] 
	uint32_t                                           bTurnAlignTargetWhenFinished : 1;              // 0x0110 (0x0004) [0x0000000000000000] [0x00000008] 
	uint32_t                                           bDrawDebug : 1;                                // 0x0110 (0x0004) [0x0000000000000001] [0x00000010] (CPF_Edit)
	uint32_t                                           bDoingDirectLook : 1;                          // 0x0110 (0x0004) [0x0000000000002000] [0x00000020] (CPF_Transient)
	uint32_t                                           bDebugChangedCameraMode : 1;                   // 0x0110 (0x0004) [0x0000000000000001] [0x00000040] (CPF_Edit)
	float                                              TurnCurTime;                                   // 0x0114 (0x0004) [0x0000000000000000]               
	int32_t                                            TurnStartAngle;                                // 0x0118 (0x0004) [0x0000000000000000]               
	int32_t                                            TurnEndAngle;                                  // 0x011C (0x0004) [0x0000000000000000]               
	float                                              TurnTotalTime;                                 // 0x0120 (0x0004) [0x0000000000000000]               
	float                                              TurnDelay;                                     // 0x0124 (0x0004) [0x0000000000000000]               
	int32_t                                            LastPostCamTurnYaw;                            // 0x0128 (0x0004) [0x0000000000002000] (CPF_Transient)
	int32_t                                            DirectLookYaw;                                 // 0x012C (0x0004) [0x0000000000002000] (CPF_Transient)
	float                                              DirectLookInterpSpeed;                         // 0x0130 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              WorstLocInterpSpeed;                           // 0x0134 (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FVector                                     LastWorstLocationLocal;                        // 0x0138 (0x000C) [0x0000000000002000] (CPF_Transient)
	struct FVector                                     LastPreModifierCameraLoc;                      // 0x0144 (0x000C) [0x0000000000002000] (CPF_Transient)
	struct FRotator                                    LastPreModifierCameraRot;                      // 0x0150 (0x000C) [0x0000000000002000] (CPF_Transient)
	class TArray<struct FPenetrationAvoidanceFeeler>   PenetrationAvoidanceFeelers;                   // 0x015C (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	float                                              OffsetAdjustmentInterpSpeed;                   // 0x0168 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	struct FVector                                     LastOffsetAdjustment;                          // 0x016C (0x000C) [0x0000008000002000] (CPF_Transient | CPF_ProtectedWrite)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameThirdPersonCamera");
		}

		return uClassPointer;
	};


	void ResetInterpolation();
	void eventModifyPostProcessSettings(struct FPostProcessSettings& outPP);
	void OnBecomeActive(class UGameCameraBase* OldCamera);
	void ProcessViewRotation(float DeltaTime, class AActor* ViewTarget, struct FRotator& outOut_ViewRotation, struct FRotator& outOut_DeltaRot);
	void UpdateCameraMode(class APawn* P);
	class UGameThirdPersonCameraMode* FindBestCameraMode(class APawn* P);
	void AdjustFocusPointInterpolation(const struct FRotator& Delta);
	struct FVector GetActualFocusLocation();
	void eventUpdateFocusPoint(class APawn* P);
	void ClearFocusPoint(bool optionalBLeaveCameraRotation);
	class AActor* GetFocusActor();
	void SetFocusOnActor(class AActor* FocusActor, const class FName& FocusBoneName, const struct FVector2D& InterpSpeedRange, const struct FVector2D& InFocusFOV, float optionalCameraFOV, bool optionalBAlwaysFocus, bool optionalBAdjustCamera, bool optionalBIgnoreTrace, float optionalFocusPitchOffsetDeg);
	void SetFocusOnLoc(const struct FVector& FocusWorldLoc, const struct FVector2D& InterpSpeedRange, const struct FVector2D& InFocusFOV, float optionalCameraFOV, bool optionalBAlwaysFocus, bool optionalBAdjustCamera, bool optionalBIgnoreTrace, float optionalFocusPitchOffsetDeg);
	void AdjustTurn(int32_t AngleOffset);
	void EndTurn();
	void BeginTurn(int32_t StartAngle, int32_t EndAngle, float TimeSec, float optionalDelaySec, bool optionalBAlignTargetWhenFinished);
	void PlayerUpdateCamera(class APawn* P, class AGamePlayerCamera* CameraActor, float DeltaTime, struct FTViewTarget& outOutVT);
	void UpdateCamera(class APawn* P, class AGamePlayerCamera* CameraActor, float DeltaTime, struct FTViewTarget& outOutVT);
	float eventGetDesiredFOV(class APawn* ViewedPawn);
	void Init();
	void Reset();
	class UGameThirdPersonCameraMode* CreateCameraMode(class UClass* ModeClass);
};
// Class GameFramework.GamePlayerCamera
// 0x0070 (0x04B0 - 0x0520)
class AGamePlayerCamera : public ACamera
{
public:
	class UGameCameraBase*                             ThirdPersonCam;                                // 0x04B0 (0x0004) [0x0000000004002001] (CPF_Edit | CPF_Transient | CPF_EditInline)
	class UClass*                                      ThirdPersonCameraClass;                        // 0x04B4 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	class UGameCameraBase*                             FixedCam;                                      // 0x04B8 (0x0004) [0x0000000004002001] (CPF_Edit | CPF_Transient | CPF_EditInline)
	class UClass*                                      FixedCameraClass;                              // 0x04BC (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	class UGameCameraBase*                             FreeCam;                                       // 0x04C0 (0x0004) [0x0000000004002001] (CPF_Edit | CPF_Transient | CPF_EditInline)
	class UClass*                                      FreeCameraClass;                               // 0x04C4 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	class UGameCameraBase*                             CurrentCamera;                                 // 0x04C8 (0x0004) [0x0000000004002001] (CPF_Edit | CPF_Transient | CPF_EditInline)
	uint32_t                                           bUseForcedCamFOV : 1;                          // 0x04CC (0x0004) [0x0000000000002000] [0x00000001] (CPF_Transient)
	uint32_t                                           bInterpolateCamChanges : 1;                    // 0x04CC (0x0004) [0x0000000000002000] [0x00000002] (CPF_Transient)
	uint32_t                                           bResetInterp : 1;                              // 0x04CC (0x0004) [0x0000000000002000] [0x00000004] (CPF_Transient)
	float                                              ForcedCamFOV;                                  // 0x04D0 (0x0004) [0x0000000000002000] (CPF_Transient)
	class AActor*                                      LastViewTarget;                                // 0x04D4 (0x0004) [0x0000000000002000] (CPF_Transient)
	float                                              SplitScreenShakeScale;                         // 0x04D8 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	class AActor*                                      LastTargetBase;                                // 0x04DC (0x0004) [0x0000000000002000] (CPF_Transient)
	struct FMatrix                                     LastTargetBaseTM;                              // 0x04E0 (0x0040) [0x0000000000002000] (CPF_Transient)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GamePlayerCamera");
		}

		return uClassPointer;
	};


	float AdjustFOVForViewport(float inHorizFOV, class APawn* CameraTargetPawn);
	bool GetActualLookatLocation(class AActor* FocusActor, struct FVector& outFocusLoc);
	void ClearFocusActor();
	void ProcessViewRotation(float DeltaTime, struct FRotator& outOut_ViewRotation, struct FRotator& outOut_DeltaRot);
	void ResetInterpolation();
	void SetColorScale(const struct FVector& NewColorScale);
	void DisplayDebug(class AHUD* HUD, float& outOut_YL, float& outOut_YPos);
	void ExecCameraLensEffects(float CamFOVDeg, struct FVector& outCamLoc, struct FRotator& outCamRot);
	void UpdateCameraLensEffects(struct FTViewTarget& outOutVT);
	void UpdateViewTarget(float DeltaTime, struct FTViewTarget& outOutVT);
	bool ShouldConstrainAspectRatio();
	class UGameCameraBase* FindBestCameraType(class AActor* CameraTarget);
	void Reset();
	void PostBeginPlay();
	void CacheLastTargetBaseInfo(class AActor* TargetBase);
	class UGameCameraBase* CreateCamera(class UClass* CameraClass);
};
// Class GameFramework.GameThirdPersonCameraMode
// 0x01FC (0x003C - 0x0238)
class UGameThirdPersonCameraMode : public UObject
{
public:
	class UGameThirdPersonCamera*                      ThirdPersonCam;                                // 0x003C (0x0004) [0x0000000000002000] (CPF_Transient)
	float                                              FOVAngle;                                      // 0x0040 (0x0004) [0x0000000000004003] (CPF_Edit | CPF_Const | CPF_Config)
	float                                              BlendTime;                                     // 0x0044 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	uint32_t                                           bLockedToViewTarget : 1;                       // 0x0048 (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)
	uint32_t                                           bDirectLook : 1;                               // 0x0048 (0x0004) [0x0000000000000003] [0x00000002] (CPF_Edit | CPF_Const)
	uint32_t                                           bFollowTarget : 1;                             // 0x0048 (0x0004) [0x0000000000000003] [0x00000004] (CPF_Edit | CPF_Const)
	uint32_t                                           bInterpLocation : 1;                           // 0x0048 (0x0004) [0x0000000000000001] [0x00000008] (CPF_Edit)
	uint32_t                                           bUsePerAxisOriginLocInterp : 1;                // 0x0048 (0x0004) [0x0000000000000001] [0x00000010] (CPF_Edit)
	uint32_t                                           bInterpRotation : 1;                           // 0x0048 (0x0004) [0x0000000000000001] [0x00000020] (CPF_Edit)
	uint32_t                                           bRotInterpSpeedConstant : 1;                   // 0x0048 (0x0004) [0x0000000000000001] [0x00000040] (CPF_Edit)
	uint32_t                                           bDoPredictiveAvoidance : 1;                    // 0x0048 (0x0004) [0x0000000000000003] [0x00000080] (CPF_Edit | CPF_Const)
	uint32_t                                           bValidateWorstLoc : 1;                         // 0x0048 (0x0004) [0x0000000000000003] [0x00000100] (CPF_Edit | CPF_Const)
	uint32_t                                           bSkipCameraCollision : 1;                      // 0x0048 (0x0004) [0x0000000000000001] [0x00000200] (CPF_Edit)
	uint32_t                                           bApplyDeltaViewOffset : 1;                     // 0x0048 (0x0004) [0x0000000000000001] [0x00000400] (CPF_Edit)
	uint32_t                                           bAdjustDOF : 1;                                // 0x0048 (0x0004) [0x0000000000000003] [0x00000800] (CPF_Edit | CPF_Const)
	uint32_t                                           bDOFUpdated : 1;                               // 0x0048 (0x0004) [0x0000000000002000] [0x00001000] (CPF_Transient)
	uint32_t                                           bInterpViewOffsetOnlyForCamTransition : 1;     // 0x0048 (0x0004) [0x0000000000000001] [0x00002000] (CPF_Edit)
	float                                              FollowingInterpSpeed_Pitch;                    // 0x004C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              FollowingInterpSpeed_Yaw;                      // 0x0050 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              FollowingInterpSpeed_Roll;                     // 0x0054 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              FollowingCameraVelThreshold;                   // 0x0058 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              OriginLocInterpSpeed;                          // 0x005C (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FVector                                     PerAxisOriginLocInterpSpeed;                   // 0x0060 (0x000C) [0x0000000000000001] (CPF_Edit)    
	float                                              OriginRotInterpSpeed;                          // 0x006C (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FVector                                     StrafeLeftAdjustment;                          // 0x0070 (0x000C) [0x0000000000000003] (CPF_Edit | CPF_Const)
	struct FVector                                     StrafeRightAdjustment;                         // 0x007C (0x000C) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              StrafeOffsetScalingThreshold;                  // 0x0088 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              StrafeOffsetInterpSpeedIn;                     // 0x008C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              StrafeOffsetInterpSpeedOut;                    // 0x0090 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	struct FVector                                     LastStrafeOffset;                              // 0x0094 (0x000C) [0x0000000000002000] (CPF_Transient)
	struct FVector                                     RunFwdAdjustment;                              // 0x00A0 (0x000C) [0x0000000000000003] (CPF_Edit | CPF_Const)
	struct FVector                                     RunBackAdjustment;                             // 0x00AC (0x000C) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              RunOffsetScalingThreshold;                     // 0x00B8 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              RunOffsetInterpSpeedIn;                        // 0x00BC (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              RunOffsetInterpSpeedOut;                       // 0x00C0 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	struct FVector                                     LastRunOffset;                                 // 0x00C4 (0x000C) [0x0000000000002000] (CPF_Transient)
	struct FVector                                     WorstLocOffset;                                // 0x00D0 (0x000C) [0x0000000000000001] (CPF_Edit)    
	struct FVector                                     TargetRelativeCameraOriginOffset;              // 0x00DC (0x000C) [0x0000000000000003] (CPF_Edit | CPF_Const)
	struct FViewOffsetData                             ViewOffset;                                    // 0x00E8 (0x0024) [0x0000000000000003] (CPF_Edit | CPF_Const)
	struct FViewOffsetData                             ViewOffset_ViewportAdjustments[6];             // 0x010C (0x00D8) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              DOF_FalloffExponent;                           // 0x01E4 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              DOF_BlurKernelSize;                            // 0x01E8 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              DOF_FocusNearInnerRadius;                      // 0x01EC (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              DOF_FocusFarInnerRadius;                       // 0x01F0 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              DOF_MaxNearBlurAmount;                         // 0x01F4 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              DOF_MaxFarBlurAmount;                          // 0x01F8 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              LastDOFRadius;                                 // 0x01FC (0x0004) [0x0000000000002000] (CPF_Transient)
	float                                              LastDOFDistance;                               // 0x0200 (0x0004) [0x0000000000002000] (CPF_Transient)
	float                                              DOFDistanceInterpSpeed;                        // 0x0204 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	struct FVector                                     DOFTraceExtent;                                // 0x0208 (0x000C) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              DOF_NearFocusDistance;                         // 0x0214 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              DOF_FarFocusDistance;                          // 0x0218 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              DOF_ResetAdaptationRate;                       // 0x021C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              DOF_RadiusFalloff;                             // 0x0220 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	struct FVector2D                                   DOF_RadiusRange;                               // 0x0224 (0x0008) [0x0000000000000003] (CPF_Edit | CPF_Const)
	struct FVector2D                                   DOF_RadiusDistRange;                           // 0x022C (0x0008) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              ViewOffsetInterp;                              // 0x0234 (0x0004) [0x0000000000000000]               

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameThirdPersonCameraMode");
		}

		return uClassPointer;
	};


	void SetViewOffset(struct FViewOffsetData& outNewViewOffset);
	void ModifyPostProcessSettings(struct FPostProcessSettings& outPP);
	void UpdatePostProcess(float DeltaTime, struct FTViewTarget& outVT);
	struct FVector DOFTrace(class AActor* TraceOwner, const struct FVector& StartTrace, const struct FVector& EndTrace);
	struct FVector GetDOFFocusLoc(class AActor* TraceOwner, const struct FVector& StartTrace, const struct FVector& EndTrace);
	void ProcessViewRotation(float DeltaTime, class AActor* ViewTarget, struct FRotator& outOut_ViewRotation, struct FRotator& outOut_DeltaRot);
	bool SetFocusPoint(class APawn* ViewedPawn);
	struct FVector eventGetCameraWorstCaseLoc(class APawn* TargetPawn);
	float GetDesiredFOV(class APawn* ViewedPawn);
	struct FVector eventAdjustViewOffset(class APawn* P, const struct FVector& Offset);
	void OnBecomeInActive(class APawn* TargetPawn, class UGameThirdPersonCameraMode* NewMode);
	void OnBecomeActive(class APawn* TargetPawn, class UGameThirdPersonCameraMode* PrevMode);
	void Init();
};
// Class GameFramework.GameThirdPersonCameraMode_Default
// 0x000C (0x0238 - 0x0244)
class UGameThirdPersonCameraMode_Default : public UGameThirdPersonCameraMode
{
public:
	float                                              WorstLocAimingZOffset;                         // 0x0238 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	uint32_t                                           bTemporaryOriginRotInterp : 1;                 // 0x023C (0x0004) [0x0000000000002000] [0x00000001] (CPF_Transient)
	float                                              TemporaryOriginRotInterpSpeed;                 // 0x0240 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameThirdPersonCameraMode_Default");
		}

		return uClassPointer;
	};

};
// Class GameFramework.GameDecal
// 0x0008 (0x0300 - 0x0308)
class UGameDecal : public UDecalComponent
{
public:
	class UMaterialInstanceTimeVarying*                MITV_Decal;                                    // 0x0300 (0x0004) [0x0000000000002000] (CPF_Transient)
	class APawn*                                       Instigator;                                    // 0x0304 (0x0004) [0x0000000000002000] (CPF_Transient)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameDecal");
		}

		return uClassPointer;
	};

};
// Class GameFramework.GameDecalManager
// 0x0004 (0x0258 - 0x025C)
class AGameDecalManager : public ADecalManager
{
public:
	float                                              MinDecalDistanceSq;                            // 0x0258 (0x0004) [0x0000000000000000]               

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameDecalManager");
		}

		return uClassPointer;
	};


	class UGameDecal* SpawnDecalMinimal(float InDecalLifeSpan, float InCanSpawnDistance, struct FVector& outDecalLocation);
	bool IsTooCloseToActiveDecal(float InCanSpawnDistance, struct FVector& outDecalLocation);
};
// Class GameFramework.GameParticleEventManager
// 0x0000 (0x0228 - 0x0228)
class AGameParticleEventManager : public AParticleEventManager
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameParticleEventManager");
		}

		return uClassPointer;
	};


	void eventHandleParticleModuleEventSendToGame(class UParticleModuleEventSendToGame* InEvent, struct FVector& outInCollideDirection, struct FVector& outInHitLocation, struct FVector& outInHitNormal, class FName& outInBoneName);
};
// Class GameFramework.GameSpecialMove
// 0x0040 (0x003C - 0x007C)
class UGameSpecialMove : public UObject
{
public:
	class AGamePawn*                                   PawnOwner;                                     // 0x003C (0x0004) [0x0000000000000000]               
	class FName                                        Handle;                                        // 0x0040 (0x0008) [0x0000000000000000]               
	float                                              LastCanDoSpecialMoveTime;                      // 0x0048 (0x0004) [0x0000000000002000] (CPF_Transient)
	uint32_t                                           bLastCanDoSpecialMove : 1;                     // 0x004C (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bReachPreciseDestination : 1;                  // 0x004C (0x0004) [0x0000000000000002] [0x00000002] (CPF_Const)
	uint32_t                                           bReachedPreciseDestination : 1;                // 0x004C (0x0004) [0x0000000000000002] [0x00000004] (CPF_Const)
	uint32_t                                           bReachPreciseRotation : 1;                     // 0x004C (0x0004) [0x0000000000000002] [0x00000008] (CPF_Const)
	uint32_t                                           bReachedPreciseRotation : 1;                   // 0x004C (0x0004) [0x0000000000000002] [0x00000010] (CPF_Const)
	uint32_t                                           bForcePrecisePosition : 1;                     // 0x004C (0x0004) [0x0000000000000000] [0x00000020] 
	struct FVector                                     PreciseDestination;                            // 0x0050 (0x000C) [0x0000000000000002] (CPF_Const)   
	class AActor*                                      PreciseDestBase;                               // 0x005C (0x0004) [0x0000000000000002] (CPF_Const)   
	struct FVector                                     PreciseDestRelOffset;                          // 0x0060 (0x000C) [0x0000000000000002] (CPF_Const)   
	float                                              PreciseRotationInterpolationTime;              // 0x006C (0x0004) [0x0000000000000002] (CPF_Const)   
	struct FRotator                                    PreciseRotation;                               // 0x0070 (0x000C) [0x0000000000000002] (CPF_Const)   

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameSpecialMove");
		}

		return uClassPointer;
	};


	struct FVector RelativeToWorldOffset(const struct FRotator& InRotation, const struct FVector& RelativeSpaceOffset);
	struct FVector WorldToRelativeOffset(const struct FRotator& InRotation, const struct FVector& WorldSpaceOffset);
	void ForcePawnRotation(class APawn* P, const struct FRotator& NewRotation);
	bool MessageEvent(const class FName& EventName, class UObject* Sender);
	void ResetFacePreciseRotation();
	void eventReachedPrecisePosition();
	void SetFacePreciseRotation(const struct FRotator& RotationToFace, float InterpolationTime);
	void SetReachPreciseDestination(const struct FVector& DestinationToReach, bool optionalBCancel);
	bool ShouldReplicate();
	void SpecialMoveFlagsUpdated();
	void Tick(float DeltaTime);
	void SpecialMoveEnded(const class FName& PrevMove, const class FName& NextMove);
	void SpecialMoveStarted(bool bForced, const class FName& PrevMove);
	bool InternalCanDoSpecialMove();
	bool CanDoSpecialMove(bool optionalBForceCheck);
	bool CanOverrideSpecialMove(const class FName& InMove);
	bool CanOverrideMoveWith(const class FName& NewMove);
	bool CanChainMove(const class FName& NextMove);
	void ExtractSpecialMoveFlags(int32_t Flags);
	void InitSpecialMoveFlags(int32_t& outOut_Flags);
	void InitSpecialMove(class AGamePawn* inPawn, const class FName& InHandle);
};
// Class GameFramework.GameCrowdSpawnerInterface
// 0x0000 (0x003C - 0x003C)
class UGameCrowdSpawnerInterface : public UInterface
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameCrowdSpawnerInterface");
		}

		return uClassPointer;
	};


	float GetMaxSpawnDist();
	bool AddToAgentPool(class AGameCrowdAgent* Agent);
	void AgentDestroyed(class AGameCrowdAgent* Agent);
};
// Class GameFramework.GameCrowdSpawnInterface
// 0x0000 (0x003C - 0x003C)
class UGameCrowdSpawnInterface : public UInterface
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameCrowdSpawnInterface");
		}

		return uClassPointer;
	};


	void GetSpawnPosition(class USeqAct_GameCrowdSpawner* Spawner, struct FVector& outSpawnPos, struct FRotator& outSpawnRot);
};
// Class GameFramework.DynamicGameCrowdDestination
// 0x0000 (0x02B4 - 0x02B4)
class ADynamicGameCrowdDestination : public AGameCrowdDestination
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.DynamicGameCrowdDestination");
		}

		return uClassPointer;
	};

};
// Class GameFramework.GameCrowd_ListOfAgents
// 0x000C (0x003C - 0x0048)
class UGameCrowd_ListOfAgents : public UObject
{
public:
	class TArray<struct FAgentArchetypeInfo>           ListOfAgents;                                  // 0x003C (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameCrowd_ListOfAgents");
		}

		return uClassPointer;
	};

};
// Class GameFramework.GameCrowdInteractionDestination
// 0x0000 (0x02B4 - 0x02B4)
class AGameCrowdInteractionDestination : public AGameCrowdDestination
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameCrowdInteractionDestination");
		}

		return uClassPointer;
	};

};
// Class GameFramework.GameExplosionContent
// 0x0048 (0x003C - 0x0084)
class UGameExplosionContent : public UObject
{
public:
	uint32_t                                           bAutoControllerVibration : 1;                  // 0x003C (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)
	uint32_t                                           bOrientCameraShakeTowardsEpicenter : 1;        // 0x003C (0x0004) [0x0000000000000003] [0x00000002] (CPF_Edit | CPF_Const)
	class USoundCue*                                   ExplosionSound;                                // 0x0040 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	class UCameraShake*                                CamShake;                                      // 0x0044 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	class UCameraShake*                                CamShake_Left;                                 // 0x0048 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	class UCameraShake*                                CamShake_Right;                                // 0x004C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	class UCameraShake*                                CamShake_Rear;                                 // 0x0050 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              CamShakeInnerRadius;                           // 0x0054 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              CamShakeOuterRadius;                           // 0x0058 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              CamShakeFalloff;                               // 0x005C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	class UClass*                                      CameraLensEffect;                              // 0x0060 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              CameraLensEffectRadius;                        // 0x0064 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	class UPointLightComponent*                        ExploLight;                                    // 0x0068 (0x0004) [0x000000000408000B] (CPF_Edit | CPF_Const | CPF_ExportObject | CPF_Component | CPF_EditInline)
	float                                              ExploLightFadeOutTime;                         // 0x006C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	class URadialBlurComponent*                        ExploRadialBlur;                               // 0x0070 (0x0004) [0x000000000408000B] (CPF_Edit | CPF_Const | CPF_ExportObject | CPF_Component | CPF_EditInline)
	float                                              ExploRadialBlurFadeOutTime;                    // 0x0074 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              ExploRadialBlurMaxBlur;                        // 0x0078 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	class UParticleSystem*                             ParticleEmitterTemplate;                       // 0x007C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	class AFogVolumeSphericalDensityInfo*              FogVolumeArchetype;                            // 0x0080 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameExplosionContent");
		}

		return uClassPointer;
	};

};
// Class GameFramework.GameFixedCamera
// 0x0004 (0x0044 - 0x0048)
class UGameFixedCamera : public UGameCameraBase
{
public:
	float                                              DefaultFOV;                                    // 0x0044 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameFixedCamera");
		}

		return uClassPointer;
	};


	void OnBecomeActive(class UGameCameraBase* OldCamera);
	void UpdateCamera(class APawn* P, class AGamePlayerCamera* CameraActor, float DeltaTime, struct FTViewTarget& outOutVT);
};
// Class GameFramework.GameFreeCamera
// 0x0070 (0x0044 - 0x00B4)
class UGameFreeCamera : public UGameCameraBase
{
public:
	float                                              DefaultFOV;                                    // 0x0044 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              MoveSpeed;                                     // 0x0048 (0x0004) [0x0000000000000000]               
	float                                              RotSpeed;                                      // 0x004C (0x0004) [0x0000000000000000]               
	float                                              ForwardSpeedFactor;                            // 0x0050 (0x0004) [0x0000000000000000]               
	float                                              RightwardSpeedFactor;                          // 0x0054 (0x0004) [0x0000000000000000]               
	struct FVector                                     Forward;                                       // 0x0058 (0x000C) [0x0000000000000000]               
	struct FVector                                     Rightward;                                     // 0x0064 (0x000C) [0x0000000000000000]               
	struct FVector                                     Upward;                                        // 0x0070 (0x000C) [0x0000000000000000]               
	float                                              ForwardSign;                                   // 0x007C (0x0004) [0x0000000000000000]               
	float                                              RightwardSign;                                 // 0x0080 (0x0004) [0x0000000000000000]               
	float                                              UpwardSign;                                    // 0x0084 (0x0004) [0x0000000000000000]               
	struct FRotator                                    RotSign;                                       // 0x0088 (0x000C) [0x0000000000000000]               
	float                                              PitchFactor;                                   // 0x0094 (0x0004) [0x0000000000000000]               
	float                                              YawFactor;                                     // 0x0098 (0x0004) [0x0000000000000000]               
	float                                              RollFactor;                                    // 0x009C (0x0004) [0x0000000000000000]               
	struct FRotator                                    InputRotator;                                  // 0x00A0 (0x000C) [0x0000000000000000]               
	int32_t                                            ControllerIndex;                               // 0x00AC (0x0004) [0x0000000000000000]               
	uint32_t                                           bSpeedUp : 1;                                  // 0x00B0 (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bSpeedDown : 1;                                // 0x00B0 (0x0004) [0x0000000000000000] [0x00000002] 

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameFreeCamera");
		}

		return uClassPointer;
	};


	struct FRotator LimitViewRotation(const struct FRotator& ViewRotation, float ViewPitchMin, float ViewPitchMax);
	void ClearMoveFlags();
	void ProcessInputInfo(float DeltaTime, struct FTViewTarget& outOutVT);
	void GetInputInfo();
	bool IsKeyPressed(class UPlayerInput* InputInfo, const class FName& KeyName);
	float GetDeflection(float F, float optionalEpsilon);
	float GetSign(float F, float optionalEpsilon);
	void ProcessViewRotation(float DeltaTime, class AActor* ViewTarget, struct FRotator& outOut_ViewRotation, struct FRotator& outOut_DeltaRot);
	void OnBecomeActive(class UGameCameraBase* OldCamera);
	void UpdateCamera(class APawn* P, class AGamePlayerCamera* CameraActor, float DeltaTime, struct FTViewTarget& outOutVT);
};
// Class GameFramework.GameKActorSpawnableEffect
// 0x0000 (0x0318 - 0x0318)
class AGameKActorSpawnableEffect : public AKActor
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameKActorSpawnableEffect");
		}

		return uClassPointer;
	};


	void eventTick(float DeltaTime);
	void eventFellOutOfWorld(class UClass* dmgType);
	void eventPostBeginPlay();
};
// Class GameFramework.GameWaveForms
// 0x0010 (0x003C - 0x004C)
class UGameWaveForms : public UObject
{
public:
	class UForceFeedbackWaveform*                      CameraShakeMediumShort;                        // 0x003C (0x0004) [0x0000000000000000]               
	class UForceFeedbackWaveform*                      CameraShakeMediumLong;                         // 0x0040 (0x0004) [0x0000000000000000]               
	class UForceFeedbackWaveform*                      CameraShakeBigShort;                           // 0x0044 (0x0004) [0x0000000000000000]               
	class UForceFeedbackWaveform*                      CameraShakeBigLong;                            // 0x0048 (0x0004) [0x0000000000000000]               

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.GameWaveForms");
		}

		return uClassPointer;
	};

};
// Class GameFramework.PMESTG_LeaveADecalBase
// 0x0004 (0x003C - 0x0040)
class UPMESTG_LeaveADecalBase : public UParticleModuleEventSendToGame
{
public:
	class UClass*                                      PhysicalMaterialPropertyClass;                 // 0x003C (0x0004) [0x0000000000000000]               

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GameFramework.PMESTG_LeaveADecalBase");
		}

		return uClassPointer;
	};

};
/*
# ========================================================================================= #
#
# ========================================================================================= #
*/

#ifdef _MSC_VER
#pragma pack(pop)
#endif
