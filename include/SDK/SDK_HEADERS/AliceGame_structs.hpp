/*
#############################################################################################
# Alice2 (ASDK) SDK 1.0.0.0
# Generated with the CodeRedGenerator v1.2.0
# ========================================================================================= #
# File: AliceGame_structs.hpp
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
# Structs
# ========================================================================================= #
*/

// ScriptStruct AliceGame.AimSwitchActorBase.CheckpointRecord
// 0x0020
struct AAimSwitchActorBase_FCheckpointRecord
{
	class FString                                      initMostOutName;                               // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class FString                                      initActorFName;                                // 0x000C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	uint32_t                                           IsAvailable : 1;                               // 0x0018 (0x0004) [0x0000000000000000] [0x00000001] 
	int32_t                                            Health;                                        // 0x001C (0x0004) [0x0000000000000000]               
};

// ScriptStruct AliceGame.AliceAnimNotify_CameraTrack.CameraTrackSocket
// 0x000C
struct FCameraTrackSocket
{
	class FName                                        SocketName;                                    // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	float                                              KeyTime;                                       // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct AliceGame.AliceAnimNotify_ChangeMaterial.MaterialInfo
// 0x0008
struct FMaterialInfo
{
	int32_t                                            MatID;                                         // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class UMaterialInstance*                           NewMat;                                        // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct AliceGame.AliceAnimNotify_SetMatParam.MatParamInfo
// 0x0018
struct FMatParamInfo
{
	uint8_t                                            ParamType;                                     // 0x0000 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            UnknownData00[0x3];                              // 0x0001 (0x0003) MISSED OFFSET
	int32_t                                            MatID;                                         // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class FName                                        ParamName;                                     // 0x0008 (0x0008) [0x0000000000000001] (CPF_Edit)    
	float                                              ScalarValue;                                   // 0x0010 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           SwitchValue : 1;                               // 0x0014 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bActiveVaryingTime : 1;                        // 0x0014 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
};

// ScriptStruct AliceGame.AliceTypes.PieceLoc
// 0x0008
struct UAliceTypes_FPieceLoc
{
	int32_t                                            I;                                             // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            J;                                             // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct AliceGame.AliceTypes.SkeletalMeshActorLockOnInfo
// 0x004C
struct FSkeletalMeshActorLockOnInfo
{
	class ASkeletalMeshActor*                          Actor;                                         // 0x0000 (0x0004) [0x0000000000000000]               
	struct FVector                                     UILockOnLoc;                                   // 0x0004 (0x000C) [0x0000000000000000]               
	struct FVector                                     CollisionLockOnLoc;                            // 0x0010 (0x000C) [0x0000000000000000]               
	struct FVector                                     CameraLockOnLoc;                               // 0x001C (0x000C) [0x0000000000000000]               
	struct FRotator                                    UILockOnRot;                                   // 0x0028 (0x000C) [0x0000000000000000]               
	struct FRotator                                    CollisionLockOnRot;                            // 0x0034 (0x000C) [0x0000000000000000]               
	struct FRotator                                    CameraLockOnRot;                               // 0x0040 (0x000C) [0x0000000000000000]               
};

// ScriptStruct AliceGame.AliceTypes.BreakableActorLockOnInfo
// 0x0030
struct FBreakableActorLockOnInfo
{
	class AGameBreakableActor*                         BActor;                                        // 0x0000 (0x0004) [0x0000000000000000]               
	uint32_t                                           bIsLockable : 1;                               // 0x0004 (0x0004) [0x0000000000000000] [0x00000001] 
	int32_t                                            iPriority;                                     // 0x0008 (0x0004) [0x0000000000000000]               
	struct FVector                                     LockOffsetCamera;                              // 0x000C (0x000C) [0x0000000000000000]               
	struct FVector                                     LockOffsetUI;                                  // 0x0018 (0x000C) [0x0000000000000000]               
	struct FVector                                     vLocation;                                     // 0x0024 (0x000C) [0x0000000000000000]               
};

// ScriptStruct AliceGame.AliceTypes.TargetingNPCInfo
// 0x0038
struct FTargetingNPCInfo
{
	class AAliceGameKynapsePawn*                       Pawn;                                          // 0x0000 (0x0004) [0x0000000000000000]               
	int32_t                                            SocketIndex;                                   // 0x0004 (0x0004) [0x0000000000000000]               
	struct FVector                                     LockOnSocketLocation;                          // 0x0008 (0x000C) [0x0000000000000000]               
	struct FRotator                                    LockOnSocketRotation;                          // 0x0014 (0x000C) [0x0000000000000000]               
	struct FVector                                     CollisionSocketLocation;                       // 0x0020 (0x000C) [0x0000000000000000]               
	struct FRotator                                    CollisionSocketRotation;                       // 0x002C (0x000C) [0x0000000000000000]               
};

// ScriptStruct AliceGame.AliceTypes.DecalData
// 0x003C
struct FDecalData
{
	uint32_t                                           bIsValid : 1;                                  // 0x0000 (0x0004) [0x0000000000000000] [0x00000001] 
	class UMaterialInterface*                          DecalMaterial;                                 // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              Width;                                         // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              Height;                                        // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              WidthSK;                                       // 0x0010 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              HeightSK;                                      // 0x0014 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              Thickness;                                     // 0x0018 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bRandomizeRotation : 1;                        // 0x001C (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	struct FVector2D                                   RandomScalingRange;                            // 0x0020 (0x0008) [0x0000000000000001] (CPF_Edit)    
	float                                              LifeSpan;                                      // 0x0028 (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FVector2D                                   BlendRange;                                    // 0x002C (0x0008) [0x0000000000000001] (CPF_Edit)    
	float                                              RandomRadiusOffset;                            // 0x0034 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            WeaponLevel;                                   // 0x0038 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct AliceGame.AliceAnimNotify_TriggerAliceGhost.GhostPositionOption
// 0x0010
struct FGhostPositionOption
{
	struct FRotator                                    AngleOffset;                                   // 0x0000 (0x000C) [0x0000000000000001] (CPF_Edit)    
	float                                              DistOffset;                                    // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct AliceGame.AliceBlockPiece.CheckpointRecord
// 0x0028
struct AAliceBlockPiece_FCheckpointRecord
{
	struct FVector                                     Location;                                      // 0x0000 (0x000C) [0x0000000000000000]               
	struct FRotator                                    Rotation;                                      // 0x000C (0x000C) [0x0000000000000000]               
	float                                              DrawScale;                                     // 0x0018 (0x0004) [0x0000000000000000]               
	struct FVector                                     DrawScale3D;                                   // 0x001C (0x000C) [0x0000000000000000]               
};

// ScriptStruct AliceGame.AliceBlockPuzzleBoard.PieceLoc
// 0x0008
struct AAliceBlockPuzzleBoard_FPieceLoc
{
	int32_t                                            I;                                             // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            J;                                             // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct AliceGame.AliceExplosionLight.LightValues
// 0x0010
struct FLightValues
{
	float                                              StartTime;                                     // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              Radius;                                        // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              Brightness;                                    // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FColor                                      LightColor;                                    // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct AliceGame.AliceExplosionLight.AliceExplosionLightTemplate
// 0x0014
struct FAliceExplosionLightTemplate
{
	class TArray<struct FLightValues>                  TimeShift;                                     // 0x0000 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	float                                              HighDetailFrameTime;                           // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bCheckFrameRate : 1;                           // 0x0010 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           CastShadows : 1;                               // 0x0010 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
};

// ScriptStruct AliceGame.AlicePawn.AliceCameraProperties
// 0x0078
struct FAliceCameraProperties
{
	float                                              Distance;                                      // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              MaxDistance;                                   // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              MinDistance;                                   // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FRotator                                    Orientation;                                   // 0x000C (0x000C) [0x0000000000000001] (CPF_Edit)    
	struct FRotator                                    RevolutionSpeed;                               // 0x0018 (0x000C) [0x0000000000000001] (CPF_Edit)    
	struct FRotator                                    InitRevolutionSpeed;                           // 0x0024 (0x000C) [0x0000000000000001] (CPF_Edit)    
	float                                              FOV;                                           // 0x0030 (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FVector                                     Offset;                                        // 0x0034 (0x000C) [0x0000000000000001] (CPF_Edit)    
	class UCameraAnim*                                 Animation;                                     // 0x0040 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            BehaviorStyle;                                 // 0x0044 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            UnknownData00[0x3];                              // 0x0045 (0x0003) MISSED OFFSET
	float                                              DistScaleWhenFacingCam;                        // 0x0048 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              BlendTime;                                     // 0x004C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              RevolutionAccelTime;                           // 0x0050 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              RevolutionAccelExponent;                       // 0x0054 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              HeightUpDelay;                                 // 0x0058 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              HeightDownDelay;                               // 0x005C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              LocationDelay;                                 // 0x0060 (0x0004) [0x0000000000000000]               
	float                                              RotationDelay;                                 // 0x0064 (0x0004) [0x0000000000000000]               
	float                                              FOVDelay;                                      // 0x0068 (0x0004) [0x0000000000000000]               
	float                                              DistanceDelay;                                 // 0x006C (0x0004) [0x0000000000000000]               
	float                                              RevolutionDelay;                               // 0x0070 (0x0004) [0x0000000000000000]               
	int32_t                                            CameraID;                                      // 0x0074 (0x0004) [0x0000000000000000]               
};

// ScriptStruct AliceGame.AliceCheatManager.PFActorInfo
// 0x0028
struct FPFActorInfo
{
	struct FVector                                     OldCoorLoc;                                    // 0x0000 (0x000C) [0x0000000000000000]               
	struct FVector                                     NewCoorLoc;                                    // 0x000C (0x000C) [0x0000000000000000]               
	float                                              PFValue;                                       // 0x0018 (0x0004) [0x0000000000000000]               
	class FString                                      actorName;                                     // 0x001C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// ScriptStruct AliceGame.AliceCheckpoint.LevelRecord
// 0x000C
struct FLevelRecord
{
	class FName                                        LevelName;                                     // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bShouldBeLoaded : 1;                           // 0x0008 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bShouldBeVisible : 1;                          // 0x0008 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
};

// ScriptStruct AliceGame.AliceCheckpoint.ActorRecord
// 0x002C
struct FActorRecord
{
	class FString                                      actorName;                                     // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class FString                                      ActorClassPath;                                // 0x000C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	uint32_t                                           SpawnByArcheType : 1;                          // 0x0018 (0x0004) [0x0000000000000000] [0x00000001] 
	class AActor*                                      SpawnArcheType;                                // 0x001C (0x0004) [0x0000000000000000]               
	class TArray<uint8_t>                              RecordData;                                    // 0x0020 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// ScriptStruct AliceGame.AliceCheckpoint.CheckpointTime
// 0x0010
struct FCheckpointTime
{
	int32_t                                            SecondsSinceMidnight;                          // 0x0000 (0x0004) [0x0000000000000000]               
	int32_t                                            Day;                                           // 0x0004 (0x0004) [0x0000000000000000]               
	int32_t                                            Month;                                         // 0x0008 (0x0004) [0x0000000000000000]               
	int32_t                                            Year;                                          // 0x000C (0x0004) [0x0000000000000000]               
};

// ScriptStruct AliceGame.AliceGamePawn.AnimationParaConfig
// 0x0038
struct FAnimationParaConfig
{
	class TArray<class FName>                          AnimationNames;                                // 0x0000 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	uint8_t                                            BlendNodeIndex;                                // 0x000C (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            UnknownData00[0x3];                              // 0x000D (0x0003) MISSED OFFSET
	int32_t                                            AnimType;                                      // 0x0010 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              BlendInTime;                                   // 0x0014 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              BlendOutTime;                                  // 0x0018 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              PlayRate;                                      // 0x001C (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bLoop : 1;                                     // 0x0020 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bCauseActorAnimEnd : 1;                        // 0x0020 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint32_t                                           bTriggerFakeRootMotion : 1;                    // 0x0020 (0x0004) [0x0000000000000001] [0x00000004] (CPF_Edit)
	uint32_t                                           bNotExtendAnimTimeForFakeRootMotion : 1;       // 0x0020 (0x0004) [0x0000000000000001] [0x00000008] (CPF_Edit)
	uint8_t                                            AnimPlayType;                                  // 0x0024 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            RootBoneTransitionOption[3];                   // 0x0025 (0x0003) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            RootBoneRotationOption[3];                     // 0x0028 (0x0003) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            FakeRootMotionMode;                            // 0x002B (0x0001) [0x0000000000000001] (CPF_Edit)    
	class FString                                      AnimationDescName;                             // 0x002C (0x000C) [0x0000000800400001] (CPF_Edit | CPF_NeedCtorLink | CPF_EditorOnly)
};

// ScriptStruct AliceGame.AliceGamePawn.PhysicsImpactRBRemap
// 0x0010
struct FPhysicsImpactRBRemap
{
	class FName                                        RB_FromName;                                   // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	class FName                                        RB_ToName;                                     // 0x0008 (0x0008) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct AliceGame.AliceGamePawn.WeaponPara
// 0x0044
struct FWeaponPara
{
	class UClass*                                      WeaponClass;                                   // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bAvailable : 1;                                // 0x0004 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	class FName                                        DefaultAttachedSocketName;                     // 0x0008 (0x0008) [0x0000000000000001] (CPF_Edit)    
	class TArray<class UPhysicsAsset*>                 CollisionPhysicsAssets;                        // 0x0010 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class AWeapon*                                     WeaponArcheType;                               // 0x001C (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            ComponentIndex;                                // 0x0020 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              WeaponMeleeRange;                              // 0x0024 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class FName                                        RangeAttackSocket;                             // 0x0028 (0x0008) [0x0000000000000001] (CPF_Edit)    
	class TArray<class FName>                          RangeAttackSocketArray;                        // 0x0030 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class AProjectile*                                 ProjectileArchetype;                           // 0x003C (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bCannotBeShieldByAlice : 1;                    // 0x0040 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
};

// ScriptStruct AliceGame.AlicePhysicalMaterialProperty.AnimNotifyDatum
// 0x001C
struct FAnimNotifyDatum
{
	class FName                                        AnimSeqName;                                   // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	class USoundCue*                                   AnimSound;                                     // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class UParticleSystem*                             AnimParticle;                                  // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	class TArray<struct FDecalData>                    DecalData;                                     // 0x0010 (0x000C) [0x0000000004400001] (CPF_Edit | CPF_NeedCtorLink | CPF_EditInline)
};

// ScriptStruct AliceGame.AlicePhysicalMaterialProperty.FootStepDatum
// 0x0064
struct FFootStepDatum
{
	class FString                                      ArcheTypeName;                                 // 0x0000 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class USoundCue*                                   DefaultSound;                                  // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	class UParticleSystem*                             DefaultParticle;                               // 0x0010 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class UParticleSystem*                             LandedParticle;                                // 0x0014 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class USoundCue*                                   LandedSound;                                   // 0x0018 (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FDecalData                                  DefaultDecal;                                  // 0x001C (0x003C) [0x0000000000000001] (CPF_Edit)    
	class TArray<struct FAnimNotifyDatum>              AnimNotify;                                    // 0x0058 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
};

// ScriptStruct AliceGame.AliceGamePawn.SMStruct
// 0x000C
struct FSMStruct
{
	uint8_t                                            SpecialMove;                                   // 0x0000 (0x0001) [0x0000000000000000]               
	uint8_t                                            UnknownData00[0x3];                              // 0x0001 (0x0003) MISSED OFFSET
	class AAliceGamePawn*                              InteractionPawn;                               // 0x0004 (0x0004) [0x0000000000000000]               
	int32_t                                            Flags;                                         // 0x0008 (0x0004) [0x0000000000000000]               
};

// ScriptStruct AliceGame.AliceGameWeaponBase.ShieldTestResult
// 0x0008
struct FShieldTestResult
{
	int32_t                                            ShieldIndex;                                   // 0x0000 (0x0004) [0x0000000000000000]               
	uint32_t                                           bSpinningShield : 1;                           // 0x0004 (0x0004) [0x0000000000000000] [0x00000001] 
};

// ScriptStruct AliceGame.AttackActorInfo.AttackActorItem
// 0x0010
struct FAttackActorItem
{
	class AActor*                                      AttackActor;                                   // 0x0000 (0x0004) [0x0000000000000000]               
	int32_t                                            LeftTriggerCount;                              // 0x0004 (0x0004) [0x0000000000000000]               
	float                                              LeftRetriggerTime;                             // 0x0008 (0x0004) [0x0000000000000000]               
	uint32_t                                           bShieldDamage : 1;                             // 0x000C (0x0004) [0x0000000000000000] [0x00000001] 
};

// ScriptStruct AliceGame.AliceGameWeaponBase.MeleeAttackMessage
// 0x0034
struct FMeleeAttackMessage
{
	uint8_t                                            MeleeAttackMsg;                                // 0x0000 (0x0001) [0x0000000000000000]               
	uint8_t                                            UnknownData00[0x3];                              // 0x0001 (0x0003) MISSED OFFSET
	float                                              MsgTime;                                       // 0x0004 (0x0004) [0x0000000000000000]               
	float                                              AttackDamage;                                  // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            WeaponAttackCollisionMode;                     // 0x000C (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            PawnAttackCollisionMode;                       // 0x000D (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            UnknownData01[0x2];                              // 0x000E (0x0002) MISSED OFFSET
	int32_t                                            AttackPhysicsAssetConfigID;                    // 0x0010 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            KnockBackParamConfigID;                        // 0x0014 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              RetriggerTime;                                 // 0x0018 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            MaxTriggerCount;                               // 0x001C (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            DmgStrength;                                   // 0x0020 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            UnknownData02[0x3];                              // 0x0021 (0x0003) MISSED OFFSET
	class UForceFeedbackWaveform*                      FFWaveform;                                    // 0x0024 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bNPCWeaponCanAttackOtherNPC : 1;               // 0x0028 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	int32_t                                            DamageForNPCs;                                 // 0x002C (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           ActivateOnWeaponHit : 1;                       // 0x0030 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
};

// ScriptStruct AliceGame.AliceGameWeaponBase.ShapeCollisionResult
// 0x0014
struct FShapeCollisionResult
{
	struct FVector                                     HitDirection;                                  // 0x0000 (0x000C) [0x0000000000000000]               
	class URB_BodySetup*                               HitBodySetUp;                                  // 0x000C (0x0004) [0x0000000000000000]               
	int32_t                                            EffectSocketIndex;                             // 0x0010 (0x0004) [0x0000000000000000]               
};

// ScriptStruct AliceGame.AlicePlayerController.RespawnInfo
// 0x000C
struct FRespawnInfo
{
	uint8_t                                            Level;                                         // 0x0000 (0x0001) [0x0000000000000000]               
	uint8_t                                            UnknownData00[0x3];                              // 0x0001 (0x0003) MISSED OFFSET
	class UParticleSystem*                             ParticleRespawn;                               // 0x0004 (0x0004) [0x0000000000000000]               
	class USoundCue*                                   ParticleRespawnSound;                          // 0x0008 (0x0004) [0x0000000000000000]               
};

// ScriptStruct AliceGame.AlicePawn.AttachNPCSocketInfo
// 0x0028
struct FAttachNPCSocketInfo
{
	class FName                                        SocketName;                                    // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bOccupied : 1;                                 // 0x0008 (0x0004) [0x0000000000000000] [0x00000001] 
	class AAliceGameKynapsePawn*                       AttachedNPC;                                   // 0x000C (0x0004) [0x0000000000002000] (CPF_Transient)
	struct FVector                                     Location;                                      // 0x0010 (0x000C) [0x0000000000000000]               
	struct FRotator                                    Rotation;                                      // 0x001C (0x000C) [0x0000000000000000]               
};

// ScriptStruct AliceGame.AlicePawn.HairSimulationInfo
// 0x0078
struct FHairSimulationInfo
{
	class UHair*                                       HairTemplate;                                  // 0x0000 (0x0004) [0x0000000004400009] (CPF_Edit | CPF_ExportObject | CPF_NeedCtorLink | CPF_EditInline)
	class UPhysicsAsset*                               PhysicsAsset;                                  // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FVector                                     Force;                                         // 0x0008 (0x000C) [0x0000000000000001] (CPF_Edit)    
	struct FVector                                     PerturbAmplitude;                              // 0x0014 (0x000C) [0x0000000000000001] (CPF_Edit)    
	struct FVector                                     PerturbTemporalPeriod;                         // 0x0020 (0x000C) [0x0000000000000001] (CPF_Edit)    
	struct FVector                                     PerturbSpatialPeriod;                          // 0x002C (0x000C) [0x0000000000000001] (CPF_Edit)    
	struct FVector                                     PerturbPhaseShift;                             // 0x0038 (0x000C) [0x0000000000000001] (CPF_Edit)    
	float                                              Damping;                                       // 0x0044 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            Iteration;                                     // 0x0048 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              LengthScale;                                   // 0x004C (0x0004) [0x0000000000000001] (CPF_Edit)    
	class UMaterialInterface*                          Material;                                      // 0x0050 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            TessellationStep;                              // 0x0054 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              StrandWidth;                                   // 0x0058 (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FVector                                     FloatForce;                                    // 0x005C (0x000C) [0x0000000000000001] (CPF_Edit)    
	struct FVector                                     FloatPerturbAmplitude;                         // 0x0068 (0x000C) [0x0000000000000001] (CPF_Edit)    
	float                                              FloatDamping;                                  // 0x0074 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct AliceGame.AliceXPPickupFactory.CheckpointRecord
// 0x001C
struct AAliceXPPickupFactory_FCheckpointRecord
{
	class FString                                      initMostOutName;                               // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class FString                                      initActorFName;                                // 0x000C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	uint32_t                                           bPicked : 1;                                   // 0x0018 (0x0004) [0x0000000000000000] [0x00000001] 
};

// ScriptStruct AliceGame.AliceGameKynapsePawn.NPCAttachedActor
// 0x0018
struct FNPCAttachedActor
{
	class AAliceGameNPCAttachedActor*                  AttachedActorArcheType;                        // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class AAliceGameNPCAttachedActor*                  AttachedActor;                                 // 0x0004 (0x0004) [0x0000000000000000]               
	class FName                                        AttachSocketName;                              // 0x0008 (0x0008) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            LockOnSocketIndex;                             // 0x0010 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bSonarActive : 1;                              // 0x0014 (0x0004) [0x0000000000000000] [0x00000001] 
};

// ScriptStruct AliceGame.AliceGameKynapsePawn.MaterialSet
// 0x000C
struct FMaterialSet
{
	class TArray<class UMaterialInterface*>            Materails;                                     // 0x0000 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
};

// ScriptStruct AliceGame.AliceGameKynapsePawn.ComponentSkeletalMeshOption
// 0x0030
struct FComponentSkeletalMeshOption
{
	class USkeletalMesh*                               ComponentSkeletalMesh;                         // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class UPhysicsAsset*                               RagdollPhysicsAsset;                           // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            ExclusiveSubArrayIndex;                        // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class TArray<struct FMaterialSet>                  MaterialArray;                                 // 0x000C (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class TArray<struct FMaterialSet>                  LockOnHighlightMaterialArray;                  // 0x0018 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class TArray<struct FMaterialSet>                  DeathMaterialArray;                            // 0x0024 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
};

// ScriptStruct AliceGame.AliceGameKynapsePawn.NPCAttachmentComponent
// 0x0058
struct FNPCAttachmentComponent
{
	uint8_t                                            NPCAttachmentComponentType;                    // 0x0000 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            NPCAttachmentComponentAttachType;              // 0x0001 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            UnknownData00[0x2];                              // 0x0002 (0x0002) MISSED OFFSET
	class FName                                        AttachSocketName;                              // 0x0004 (0x0008) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            AttachSocketComponentIndex;                    // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            ExclusiveArrayIndex;                           // 0x0010 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            ComponentChance;                               // 0x0014 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class TArray<struct FComponentSkeletalMeshOption>  ComponentSkeletalMeshArray;                    // 0x0018 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	float                                              ScaleValue;                                    // 0x0024 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              RagdollTime;                                   // 0x0028 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              FadeOutTime;                                   // 0x002C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              LeftRagdollTime;                               // 0x0030 (0x0004) [0x0000000000002000] (CPF_Transient)
	float                                              LeftFadeOutTime;                               // 0x0034 (0x0004) [0x0000000000002000] (CPF_Transient)
	class FName                                        FadeOutTimeVaryParamName;                      // 0x0038 (0x0008) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           FadeOutMaterialUseDuplicate : 1;               // 0x0040 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           FadeOutAlpha : 1;                              // 0x0040 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	class USkeletalMeshComponent*                      CurrentAttachmentMeshComponent;                // 0x0044 (0x0004) [0x0000000004080008] (CPF_ExportObject | CPF_Component | CPF_EditInline)
	class AAliceGameDropActor*                         CurrentDropActor;                              // 0x0048 (0x0004) [0x0000000000000000]               
	int32_t                                            CurrentAttachmentMeshComponentIndex;           // 0x004C (0x0004) [0x0000000000000000]               
	int32_t                                            CurrentAttachmentMeshMaterialIndex;            // 0x0050 (0x0004) [0x0000000000000000]               
	uint32_t                                           bHiddenComponent : 1;                          // 0x0054 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bHited : 1;                                    // 0x0054 (0x0004) [0x0000000000000000] [0x00000002] 
	uint32_t                                           bSonarActive : 1;                              // 0x0054 (0x0004) [0x0000000000000000] [0x00000004] 
};

// ScriptStruct AliceGame.AliceGameKynapsePawn.TargetableSocketInfo
// 0x004C
struct FTargetableSocketInfo
{
	class FName                                        SocketName;                                    // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	class FName                                        CollisionSocketName;                           // 0x0008 (0x0008) [0x0000000000000001] (CPF_Edit)    
	class FName                                        CameraTargetSocket;                            // 0x0010 (0x0008) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bEnable : 1;                                   // 0x0018 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bHideUI : 1;                                   // 0x0018 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint32_t                                           bCriticalUI : 1;                               // 0x0018 (0x0004) [0x0000000000000001] [0x00000004] (CPF_Edit)
	struct FVector                                     LockOnLocation;                                // 0x001C (0x000C) [0x0000000000000000]               
	struct FRotator                                    LockOnRotation;                                // 0x0028 (0x000C) [0x0000000000000000]               
	struct FVector                                     CollisionLocation;                             // 0x0034 (0x000C) [0x0000000000000000]               
	struct FRotator                                    CollisionRotation;                             // 0x0040 (0x000C) [0x0000000000000000]               
};

// ScriptStruct AliceGame.AliceGameKynapsePawn.TagetInfo
// 0x0014
struct FTagetInfo
{
	class APawn*                                       Pawn;                                          // 0x0000 (0x0004) [0x0000000000000000]               
	int32_t                                            currentIndexOfTargetingSocket;                 // 0x0004 (0x0004) [0x0000000000000000]               
	class TArray<struct FTargetableSocketInfo>         TargetSockets;                                 // 0x0008 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
};

// ScriptStruct AliceGame.AliceGameKynapsePawn.LoopSoundInfo
// 0x0018
struct FLoopSoundInfo
{
	class USoundCue*                                   LoopSound;                                     // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class FName                                        SocketName;                                    // 0x0004 (0x0008) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            AttachComponentIndex;                          // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	class UAudioComponent*                             LoopSoundComponent;                            // 0x0010 (0x0004) [0x0000000004080008] (CPF_ExportObject | CPF_Component | CPF_EditInline)
	uint32_t                                           bEnable : 1;                                   // 0x0014 (0x0004) [0x0000000000000000] [0x00000001] 
};

// ScriptStruct AliceGame.AliceGameKynapsePawn.LoopParticleInfo
// 0x001C
struct FLoopParticleInfo
{
	class UParticleSystem*                             LoopPS;                                        // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class FName                                        SocketName;                                    // 0x0004 (0x0008) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            AttachComponentIndex;                          // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              DrawScale;                                     // 0x0010 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class UParticleSystemComponent*                    LoopPSComponent;                               // 0x0014 (0x0004) [0x0000000004080008] (CPF_ExportObject | CPF_Component | CPF_EditInline)
	uint32_t                                           bEnable : 1;                                   // 0x0018 (0x0004) [0x0000000000000000] [0x00000001] 
};

// ScriptStruct AliceGame.AliceGameKynapsePawn.NPCTakeDamageAnimInfo
// 0x0018
struct FNPCTakeDamageAnimInfo
{
	uint8_t                                            DmgStrength;                                   // 0x0000 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            UnknownData00[0x3];                              // 0x0001 (0x0003) MISSED OFFSET
	int32_t                                            AnimIndex;                                     // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FRotator                                    DamageRotationRate;                            // 0x0008 (0x000C) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bKnockBack : 1;                                // 0x0014 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bPhysicalAnim : 1;                             // 0x0014 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
};

// ScriptStruct AliceGame.AliceGameKynapsePawn.DropHPProbability
// 0x0010
struct FDropHPProbability
{
	int32_t                                            HP;                                            // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              Probability;                                   // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              BeginNumber;                                   // 0x0008 (0x0004) [0x0000000000000000]               
	float                                              EndNumber;                                     // 0x000C (0x0004) [0x0000000000000000]               
};

// ScriptStruct AliceGame.AliceGameKynapsePawn.SmartHP
// 0x0010
struct FSmartHP
{
	int32_t                                            HPPercentage;                                  // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class TArray<struct FDropHPProbability>            DropProbability;                               // 0x0004 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
};

// ScriptStruct AliceGame.AliceGameKynapsePawn.ShieldComponentInfo
// 0x00A0
struct FShieldComponentInfo
{
	class UPhysicsAsset*                               ShieldPhysicsAsset;                            // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            CollisionMode;                                 // 0x0004 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            ShieldOrient;                                  // 0x0005 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            UnknownData00[0x2];                              // 0x0006 (0x0002) MISSED OFFSET
	class FName                                        ShieldOrientSocket;                            // 0x0008 (0x0008) [0x0000000000000001] (CPF_Edit)    
	struct FRotator                                    ShieldOrientRefAngle;                          // 0x0010 (0x000C) [0x0000000000000001] (CPF_Edit)    
	float                                              ShieldAreaAngle0;                              // 0x001C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              ShieldAreaAngle1;                              // 0x0020 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           PlayAliceReactAnimVorpalBlade : 1;             // 0x0024 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           PlayAliceReactAnimHobbyHorse : 1;              // 0x0024 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	class FName                                        ReactByDashPackage;                            // 0x0028 (0x0008) [0x0000000000000000]               
	int32_t                                            ReactByDashPackageIndex;                       // 0x0030 (0x0004) [0x0000000000002000] (CPF_Transient)
	class FName                                        ReactByVorpalBladePackage;                     // 0x0034 (0x0008) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            ReactByVorpalBladePackageIndex;                // 0x003C (0x0004) [0x0000000000000000]               
	uint32_t                                           ReactByVorpalBladeSkipPlayPhysMaterialEffect : 1;// 0x0040 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	class FName                                        ReactByHobbyHorsePackage;                      // 0x0044 (0x0008) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            ReactByHobbyHorsePackageIndex;                 // 0x004C (0x0004) [0x0000000000000000]               
	uint32_t                                           ReactByHobbyHorseSkipPlayPhysMaterialEffect : 1;// 0x0050 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	class FName                                        ReactByPepperGrinderPackage;                   // 0x0054 (0x0008) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            ReactByPepperGrinderPackageIndex;              // 0x005C (0x0004) [0x0000000000000000]               
	uint32_t                                           ReactByPepperGrinderSkipPlayPhysMaterialEffect : 1;// 0x0060 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	class FName                                        ReactByPepperGrinderChargedPackage;            // 0x0064 (0x0008) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            ReactByPepperGrinderChargedPackageIndex;       // 0x006C (0x0004) [0x0000000000000000]               
	uint32_t                                           ReactByPepperGrinderChargedSkipPlayPhysMaterialEffect : 1;// 0x0070 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	class FName                                        ReactByTeaCannonPackage;                       // 0x0074 (0x0008) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            ReactByTeaCannonPackageIndex;                  // 0x007C (0x0004) [0x0000000000000000]               
	uint32_t                                           ReactByTeaCannonSkipPlayPhysMaterialEffect : 1;// 0x0080 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	class FName                                        ReactByDeflectProjectilePackage;               // 0x0084 (0x0008) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            ReactByDeflectProjectilePackageIndex;          // 0x008C (0x0004) [0x0000000000000000]               
	uint32_t                                           ReactByDeflectProjectileSkipPlayPhysMaterialEffect : 1;// 0x0090 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           CanBreakStrikBack : 1;                         // 0x0090 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	float                                              KnockBackDistScale;                            // 0x0094 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              KnockBackTimeScale;                            // 0x0098 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bPenetrableToProjectile : 1;                   // 0x009C (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bNoBlockVorpalBlade : 1;                       // 0x009C (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint32_t                                           bNoBlockHobbyHorse : 1;                        // 0x009C (0x0004) [0x0000000000000001] [0x00000004] (CPF_Edit)
	uint32_t                                           bNoBlockPepperGrinder : 1;                     // 0x009C (0x0004) [0x0000000000000001] [0x00000008] (CPF_Edit)
	uint32_t                                           bNoBlockTeapotCannon : 1;                      // 0x009C (0x0004) [0x0000000000000001] [0x00000010] (CPF_Edit)
};

// ScriptStruct AliceGame.AliceGameKynapsePawn.ShieldPara
// 0x00A8
struct FShieldPara
{
	uint32_t                                           bAvaliable : 1;                                // 0x0000 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bInShield : 1;                                 // 0x0000 (0x0004) [0x0000000000002000] [0x00000002] (CPF_Transient)
	struct FShieldComponentInfo                        ShieldInfo;                                    // 0x0004 (0x00A0) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            ComponentIndex;                                // 0x00A4 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct AliceGame.AliceGameKynapsePawn.NPCBackUpHeadSkeletalControllerInfo
// 0x000C
struct FNPCBackUpHeadSkeletalControllerInfo
{
	class FName                                        ControlName;                                   // 0x0000 (0x0008) [0x0000000000000000]               
	uint32_t                                           Actived : 1;                                   // 0x0008 (0x0004) [0x0000000000000000] [0x00000001] 
};

// ScriptStruct AliceGame.AlicePawn.WonderlandDress
// 0x0014
struct FWonderlandDress
{
	class USkeletalMesh*                               SkelMesh;                                      // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class USkeletalMesh*                               Bow;                                           // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class USkeletalMesh*                               Ribbon;                                        // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class USkeletalMesh*                               Skirt;                                         // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	class USkeletalMesh*                               Ear;                                           // 0x0010 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct AliceGame.AlicePawn.DelayedChangeDressData
// 0x000C
struct FDelayedChangeDressData
{
	uint8_t                                            NewDress;                                      // 0x0000 (0x0001) [0x0000000000000000]               
	uint8_t                                            UnknownData00[0x3];                              // 0x0001 (0x0003) MISSED OFFSET
	uint32_t                                           bShouldBlock : 1;                              // 0x0004 (0x0004) [0x0000000000000000] [0x00000001] 
	class UGFxMovie*                                   pGFXMovie;                                     // 0x0008 (0x0004) [0x0000000000000000]               
};

// ScriptStruct AliceGame.AlicePawn.XPEnum
// 0x0010
struct FXPEnum
{
	int32_t                                            Easy;                                          // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            Normal;                                        // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            Hard;                                          // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            VeryHard;                                      // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct AliceGame.AlicePawn.AliceCameraAnimInfo
// 0x0008
struct FAliceCameraAnimInfo
{
	class UCameraAnim*                                 Anim;                                          // 0x0000 (0x0004) [0x0000000000000000]               
	class UCameraAnimInst*                             AnimInst;                                      // 0x0004 (0x0004) [0x0000000000000000]               
};

// ScriptStruct AliceGame.AlicePawn.AliceCloseCameraProperties
// 0x0010
struct FAliceCloseCameraProperties
{
	float                                              DistanceScale;                                 // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FVector                                     Offset;                                        // 0x0004 (0x000C) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct AliceGame.AlicePawn.HealthLevel
// 0x0030
struct FHealthLevel
{
	float                                              HPPercentage;                                  // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              RegenRate;                                     // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class USoundCue*                                   HealthSound;                                   // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class UCameraAnim*                                 HealthCameraAnim;                              // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	class UForceFeedbackWaveform*                      FFWaveform;                                    // 0x0010 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bPlaysDamagedAnims : 1;                        // 0x0014 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	class TArray<class FName>                          PPEffectName;                                  // 0x0018 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class TArray<class UPostProcessEffect*>            PPEffects;                                     // 0x0024 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// ScriptStruct AliceGame.AlicePawn.WeaponFadeParEffect
// 0x000C
struct FWeaponFadeParEffect
{
	class UParticleSystem*                             EffectParticle;                                // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class FName                                        SocketToPlay;                                  // 0x0004 (0x0008) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct AliceGame.AlicePawn.DamageElement
// 0x0010
struct FDamageElement
{
	uint8_t                                            DmgStrength;                                   // 0x0000 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            UnknownData00[0x3];                              // 0x0001 (0x0003) MISSED OFFSET
	uint32_t                                           bKnockBack : 1;                                // 0x0004 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bPhysicalAnim : 1;                             // 0x0004 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	class USoundCue*                                   DamageSound;                                   // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class UCameraAnim*                                 DamageCameraAnim;                              // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct AliceGame.AlicePawn.EnduranceParams
// 0x0014
struct FEnduranceParams
{
	float                                              TotalEndurance;                                // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              Cost[2];                                       // 0x0004 (0x0008) [0x0000000000000001] (CPF_Edit)    
	float                                              Recovery;                                      // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              ThresholdToRest;                               // 0x0010 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct AliceGame.AlicePawn.StrafeSpeed
// 0x0010
struct FStrafeSpeed
{
	float                                              Forward;                                       // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              Backward;                                      // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              Left;                                          // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              Right;                                         // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct AliceGame.AlicePawn.DeathParticles
// 0x0014
struct FDeathParticles
{
	class UParticleSystem*                             Particle;                                      // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class FName                                        Socket;                                        // 0x0004 (0x0008) [0x0000000000000001] (CPF_Edit)    
	class FName                                        Bone;                                          // 0x000C (0x0008) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct AliceGame.AlicePawn.DeathMaterials
// 0x000C
struct FDeathMaterials
{
	int32_t                                            MaterialID;                                    // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class FName                                        ParameterName;                                 // 0x0004 (0x0008) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct AliceGame.AlicePawn.LockOnDOFSettings
// 0x0024
struct FLockOnDOFSettings
{
	float                                              FalloffExponent;                               // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              BlurKernelSize;                                // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              FocusNearInnerRadius;                          // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              FocusFarInnerRadius;                           // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              NearFocusDistance;                             // 0x0010 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              FarFocusDistanceOffset;                        // 0x0014 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              AdaptationRate;                                // 0x0018 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bEnableDOF : 1;                                // 0x001C (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bEnableDynamicDoF : 1;                         // 0x001C (0x0004) [0x0000000000000000] [0x00000002] 
	float                                              FarFocusDistance;                              // 0x0020 (0x0004) [0x0000000000000000]               
};

// ScriptStruct AliceGame.AlicePawn.AliceShieldInfo
// 0x002C
struct FAliceShieldInfo
{
	class TArray<class UClass*>                        NoBlockingWeaponFileter;                       // 0x0000 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class UPhysicsAsset*                               ShieldPhysicsAsset;                            // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              KnockBackDistScale;                            // 0x0010 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              KnockBackTimeScale;                            // 0x0014 (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FRotator                                    ShieldOrientRefAngle;                          // 0x0018 (0x000C) [0x0000000000000001] (CPF_Edit)    
	float                                              ShieldAreaAngle0;                              // 0x0024 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              ShieldAreaAngle1;                              // 0x0028 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct AliceGame.AlicePawn.AliceEnvironmentLockZone
// 0x0014
struct FAliceEnvironmentLockZone
{
	struct FVector                                     Center;                                        // 0x0000 (0x000C) [0x0000000000000000]               
	float                                              Radius;                                        // 0x000C (0x0004) [0x0000000000000000]               
	class APawn*                                       LockPawn;                                      // 0x0010 (0x0004) [0x0000000000000000]               
};

// ScriptStruct AliceGame.AliceGameInfo.AliceDLCDesc
// 0x0018
struct FAliceDLCDesc
{
	class FString                                      DLCName;                                       // 0x0000 (0x000C) [0x0000000000444000] (CPF_Config | CPF_GlobalConfig | CPF_NeedCtorLink)
	class FString                                      PS3UnlockFile;                                 // 0x000C (0x000C) [0x0000000000444000] (CPF_Config | CPF_GlobalConfig | CPF_NeedCtorLink)
};

// ScriptStruct AliceGame.AlicePhysicalMaterialProperty.SlideParam
// 0x0008
struct FSlideParam
{
	uint32_t                                           bCanControlWhenSlide : 1;                      // 0x0000 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bCanJumpWhenSlide : 1;                         // 0x0000 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	class UParticleSystem*                             SlidePS;                                       // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct AliceGame.AlicePlayerController.ButtonInputStatus
// 0x0018
struct FButtonInputStatus
{
	uint8_t                                            BtnType;                                       // 0x0000 (0x0001) [0x0000000000000000]               
	uint8_t                                            UnknownData00[0x3];                              // 0x0001 (0x0003) MISSED OFFSET
	uint32_t                                           Button_In_Pressed : 1;                         // 0x0004 (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           HoldFinshedEventDone : 1;                      // 0x0004 (0x0004) [0x0000000000000000] [0x00000002] 
	uint32_t                                           bInDoingHoldFinishEvent : 1;                   // 0x0004 (0x0004) [0x0000000000000000] [0x00000004] 
	uint32_t                                           bInDoingTap2HoldEvent : 1;                     // 0x0004 (0x0004) [0x0000000000000000] [0x00000008] 
	float                                              TapTime;                                       // 0x0008 (0x0004) [0x0000000000000000]               
	float                                              HoldTime;                                      // 0x000C (0x0004) [0x0000000000000000]               
	class FName                                        ButtonName;                                    // 0x0010 (0x0008) [0x0000000000000000]               
};

// ScriptStruct AliceGame.AlicePlayerController.ObjectiveInfo
// 0x0020
struct FObjectiveInfo
{
	class FName                                        ObjectiveName;                                 // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	class FString                                      ObjectiveDesc;                                 // 0x0008 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	uint32_t                                           bUpdated : 1;                                  // 0x0014 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bCompleted : 1;                                // 0x0014 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint32_t                                           bFailed : 1;                                   // 0x0014 (0x0004) [0x0000000000000001] [0x00000004] (CPF_Edit)
	float                                              UpdatedTime;                                   // 0x0018 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bNotifyPlayer : 1;                             // 0x001C (0x0004) [0x0000000000000000] [0x00000001] 
};

// ScriptStruct AliceGame.AlicePlayerController.CheckpointRecord
// 0x002A
struct AAlicePlayerController_FCheckpointRecord
{
	struct FVector                                     Location;                                      // 0x0000 (0x000C) [0x0000000000000000]               
	struct FRotator                                    Rotation;                                      // 0x000C (0x000C) [0x0000000000000000]               
	int32_t                                            Health;                                        // 0x0018 (0x0004) [0x0000000000000000]               
	class TArray<struct FObjectiveInfo>                Objectives;                                    // 0x001C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	uint8_t                                            AliceArcheTypeID;                              // 0x0028 (0x0001) [0x0000000000000000]               
	uint8_t                                            StoryModeSaveDressID;                          // 0x0029 (0x0001) [0x0000000000000000]               
	uint8_t                                            MinStructAlignment[0x2];                         // 0x002A (0x0002) ADDED PADDING
};

// ScriptStruct AliceGame.AliceGameWeapon.ProjectileLevelDataPackage
// 0x0030
struct FProjectileLevelDataPackage
{
	class UParticleSystem*                             PorjectTileLightEffect;                        // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              AccelRate;                                     // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              Speed;                                         // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              MaxSpeed;                                      // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              Damage;                                        // 0x0010 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              DamageRadius;                                  // 0x0014 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              MinShotDist;                                   // 0x0018 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              MaxShotDist;                                   // 0x001C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              CheckRadius;                                   // 0x0020 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              RadiusDamageTime;                              // 0x0024 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              RagdollImpulseScale;                           // 0x0028 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            KnockBackID;                                   // 0x002C (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct AliceGame.WeaponForAlice.AttachedLoopingParticleEffect
// 0x0010
struct FAttachedLoopingParticleEffect
{
	class UParticleSystem*                             WLDP_AttachedLoopingParticle;                  // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class FName                                        AttachedLoopingParticleSocket;                 // 0x0004 (0x0008) [0x0000000000000001] (CPF_Edit)    
	class UParticleSystemComponent*                    AttachedLoopingParticleComponent;              // 0x000C (0x0004) [0x0000000004080008] (CPF_ExportObject | CPF_Component | CPF_EditInline)
};

// ScriptStruct AliceGame.WeaponForAlice.MeleeComboInfo
// 0x0044
struct FMeleeComboInfo
{
	class FName                                        AnimationName;                                 // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	class FName                                        AnimationTransientName;                        // 0x0008 (0x0008) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           CanBreakTransient : 1;                         // 0x0010 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	float                                              PlayRate;                                      // 0x0014 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              TransientPlayRate;                             // 0x0018 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              BlendInTime;                                   // 0x001C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              BlendOutTime;                                  // 0x0020 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class FName                                        WeaponAnimationName;                           // 0x0024 (0x0008) [0x0000000000000001] (CPF_Edit)    
	class FName                                        WeaponAnimationNameHysteria;                   // 0x002C (0x0008) [0x0000000000000001] (CPF_Edit)    
	class FName                                        WeaponAnimationNameDLC;                        // 0x0034 (0x0008) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            Damage;                                        // 0x003C (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            RadiusDamage;                                  // 0x0040 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct AliceGame.WeaponForAlice.WeaponLevelDataPackage
// 0x00E4
struct FWeaponLevelDataPackage
{
	class USkeletalMesh*                               WLDP_SkeletalMesh;                             // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class UParticleSystem*                             WLDP_Particle_Trail;                           // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class TArray<class UParticleSystem*>               WLDP_WeaponEffect;                             // 0x0008 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class UParticleSystem*                             WLDP_Particle_Muzzle;                          // 0x0014 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class TArray<struct FAttachedLoopingParticleEffect> AttachedLoopingParticleArray;                  // 0x0018 (0x000C) [0x0000000000480001] (CPF_Edit | CPF_Component | CPF_NeedCtorLink)
	class TArray<class USoundCue*>                     WLDP_RangeFireSoundCue;                        // 0x0024 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class TArray<class USoundCue*>                     WLDP_ChargedRangeFireSoundCue;                 // 0x0030 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class UClass*                                      WLDP_Project1;                                 // 0x003C (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            WLDP_RunningNoLockMeleeDamage;                 // 0x0040 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            WLDP_SwitchMeleeDamage;                        // 0x0044 (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FProjectileLevelDataPackage                 ProjectilePackage[3];                          // 0x0048 (0x0090) [0x0000000000000001] (CPF_Edit)    
	class TArray<struct FMeleeComboInfo>               ComboArray;                                    // 0x00D8 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
};

// ScriptStruct AliceGame.AliceCycleFloatManager.CycleData
// 0x000C
struct FCycleData
{
	float                                              PrePreJumpZ;                                   // 0x0000 (0x0004) [0x0000000000000000]               
	float                                              PreJumpZ;                                      // 0x0004 (0x0004) [0x0000000000000000]               
	float                                              JumpZ;                                         // 0x0008 (0x0004) [0x0000000000000000]               
};

// ScriptStruct AliceGame.AliceEmitterPool.AttachedExplosionLight
// 0x0014
struct FAttachedExplosionLight
{
	class UAliceExplosionLight*                        Light;                                         // 0x0000 (0x0004) [0x0000000004080008] (CPF_ExportObject | CPF_Component | CPF_EditInline)
	class AActor*                                      Base;                                          // 0x0004 (0x0004) [0x0000000000000000]               
	struct FVector                                     RelativeLocation;                              // 0x0008 (0x000C) [0x0000000000000000]               
};

// ScriptStruct AliceGame.AliceGameAnimNode_Sequence.StopMotionParams
// 0x000C
struct FStopMotionParams
{
	float                                              RotationNoise;                                 // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              TranslationNoise;                              // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              LimitedFPS;                                    // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct AliceGame.AliceGameSkelControl_Cloth.ClothBoneStrip
// 0x0068
struct FClothBoneStrip
{
	class FName                                        ClothFixedBoneName;                            // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	class TArray<class FName>                          ClothBoneNames;                                // 0x0008 (0x000C) [0x0000000000420001] (CPF_Edit | CPF_EditConst | CPF_NeedCtorLink)
	int32_t                                            ClothFixedBoneIndex;                           // 0x0014 (0x0004) [0x0000000000020000] (CPF_EditConst)
	class TArray<int32_t>                              ClothBoneIndices;                              // 0x0018 (0x000C) [0x0000000000420000] (CPF_EditConst | CPF_NeedCtorLink)
	class TArray<float>                                ClothBoneLengths;                              // 0x0024 (0x000C) [0x0000000000420000] (CPF_EditConst | CPF_NeedCtorLink)
	struct FVector                                     LastClothFixedBonePos;                         // 0x0030 (0x000C) [0x0000000000000000]               
	uint8_t                                            UnknownData00[0x4];                              // 0x003C (0x0004) MISSED OFFSET
	struct FQuat                                       LastClothFixedBoneRot;                         // 0x0040 (0x0010) [0x0000000000000000]               
	class TArray<struct FVector>                       LastClothBonesPos;                             // 0x0050 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<struct FVector>                       LastClothBonesVel;                             // 0x005C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	uint8_t                                            MinStructAlignment[0x8];                         // 0x0068 (0x0008) ADDED PADDING
};

// ScriptStruct AliceGame.AliceGameSkelControl_Cloth.BonePoint
// 0x0020
struct FBonePoint
{
	int32_t                                            BoneIndex;                                     // 0x0000 (0x0004) [0x0000000000000000]               
	struct FVector                                     OldPos;                                        // 0x0004 (0x000C) [0x0000000000000000]               
	struct FVector                                     CurPos;                                        // 0x0010 (0x000C) [0x0000000000000000]               
	uint32_t                                           bFixed : 1;                                    // 0x001C (0x0004) [0x0000000000000000] [0x00000001] 
};

// ScriptStruct AliceGame.AliceGameSkelControl_Cloth.BoneLink
// 0x0010
struct FBoneLink
{
	int32_t                                            NodeIndex0;                                    // 0x0000 (0x0004) [0x0000000000000000]               
	int32_t                                            NodeIndex1;                                    // 0x0004 (0x0004) [0x0000000000000000]               
	float                                              Length;                                        // 0x0008 (0x0004) [0x0000000000000000]               
	float                                              Restitution;                                   // 0x000C (0x0004) [0x0000000000000000]               
};

// ScriptStruct AliceGame.AliceGameSkelControl_Cloth.CollisionSphere
// 0x001C
struct FCollisionSphere
{
	class FName                                        BoneName;                                      // 0x0000 (0x0008) [0x0000000000000000]               
	struct FVector                                     Center;                                        // 0x0008 (0x000C) [0x0000000000000000]               
	float                                              Radius;                                        // 0x0014 (0x0004) [0x0000000000000000]               
	float                                              sqRadius;                                      // 0x0018 (0x0004) [0x0000000000000000]               
};

// ScriptStruct AliceGame.AliceGib.StaticMeshDatum
// 0x0014
struct FStaticMeshDatum
{
	class UStaticMesh*                                 TheStaticMesh;                                 // 0x0000 (0x0004) [0x0000000000000000]               
	class USkeletalMesh*                               TheSkelMesh;                                   // 0x0004 (0x0004) [0x0000000000000000]               
	class UPhysicsAsset*                               ThePhysAsset;                                  // 0x0008 (0x0004) [0x0000000000000000]               
	float                                              DrawScale;                                     // 0x000C (0x0004) [0x0000000000000000]               
	uint32_t                                           bUseSecondaryGibMeshMITV : 1;                  // 0x0010 (0x0004) [0x0000000000000000] [0x00000001] 
};

// ScriptStruct AliceGame.AliceInventoryManager.AmmoStore
// 0x0008
struct FAmmoStore
{
	int32_t                                            Amount;                                        // 0x0000 (0x0004) [0x0000000000000000]               
	class UClass*                                      WeaponClass;                                   // 0x0004 (0x0004) [0x0000000000000000]               
};

// ScriptStruct AliceGame.AliceLocalizedStaticMeshActor.LocalizationMaterialSet
// 0x0010
struct FLocalizationMaterialSet
{
	int32_t                                            MaterialIndex;                                 // 0x0000 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	class TArray<class UMaterialInterface*>            Materials;                                     // 0x0004 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
};

// ScriptStruct AliceGame.AlicePhysicalMaterialProperty.ImpactFXExplosion
// 0x0074
struct FImpactFXExplosion
{
	class FString                                      WeaponType;                                    // 0x0000 (0x000C) [0x0000000000400002] (CPF_Const | CPF_NeedCtorLink)
	class UClass*                                      WeaponClass;                                   // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	class TArray<struct FDecalData>                    DecalData;                                     // 0x0010 (0x000C) [0x0000000004400001] (CPF_Edit | CPF_NeedCtorLink | CPF_EditInline)
	class USoundCue*                                   ImpactCue;                                     // 0x001C (0x0004) [0x0000000000000001] (CPF_Edit)    
	class UParticleSystem*                             DefaultImpactPS;                               // 0x0020 (0x0004) [0x0000000000000000]               
	uint32_t                                           bUseRandomImpactPS : 1;                        // 0x0024 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	class TArray<class UParticleSystem*>               RandomImpactPS;                                // 0x0028 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class TArray<class USoundCue*>                     ImpactCueWeapon;                               // 0x0034 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class TArray<class UParticleSystem*>               ImpactPSWeapon;                                // 0x0040 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class UClass*                                      CameraEffect;                                  // 0x004C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              CameraEffectRadius;                            // 0x0050 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class TArray<class USoundCue*>                     CriticalWeaponCue;                             // 0x0054 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<class UParticleSystem*>               CriticalWeaponPS;                              // 0x0060 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	uint32_t                                           bProjectOnSurface : 1;                         // 0x006C (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	float                                              ProjectionDistance;                            // 0x0070 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct AliceGame.AlicePhysicalMaterialProperty.ImpactFXBase
// 0x0054
struct FImpactFXBase
{
	class TArray<struct FDecalData>                    DecalData;                                     // 0x0000 (0x000C) [0x0000000004400001] (CPF_Edit | CPF_NeedCtorLink | CPF_EditInline)
	class USoundCue*                                   ImpactCue;                                     // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	class UParticleSystem*                             ImpactPS;                                      // 0x0010 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class TArray<class USoundCue*>                     ImpactCueWeapon;                               // 0x0014 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class TArray<class UParticleSystem*>               ImpactPSWeapon;                                // 0x0020 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class UClass*                                      CameraEffect;                                  // 0x002C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              CameraEffectRadius;                            // 0x0030 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class TArray<class USoundCue*>                     CriticalWeaponCue;                             // 0x0034 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<class UParticleSystem*>               CriticalWeaponPS;                              // 0x0040 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	uint32_t                                           bProjectOnSurface : 1;                         // 0x004C (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	float                                              ProjectionDistance;                            // 0x0050 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct AliceGame.AlicePhysicalMaterialProperty.ImpactFXProjectile
// 0x0010 (0x0054 - 0x0064)
struct FImpactFXProjectile : FImpactFXBase
{
	class FString                                      ProjectileType;                                // 0x0054 (0x000C) [0x0000000000400002] (CPF_Const | CPF_NeedCtorLink)
	class UClass*                                      ProjectileClass;                               // 0x0060 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct AliceGame.AlicePhysicalMaterialProperty.ImpactFXBallistic
// 0x0010 (0x0054 - 0x0064)
struct FImpactFXBallistic : FImpactFXBase
{
	class FString                                      WeaponType;                                    // 0x0054 (0x000C) [0x0000000000400002] (CPF_Const | CPF_NeedCtorLink)
	class UClass*                                      WeaponClass;                                   // 0x0060 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct AliceGame.AlicePlayerCamera.AliceCameraTrackKey
// 0x0050
struct FAliceCameraTrackKey
{
	struct FVector                                     PrevPos;                                       // 0x0000 (0x000C) [0x0000000000000000]               
	struct FVector                                     CurrentPos;                                    // 0x000C (0x000C) [0x0000000000000000]               
	struct FRotator                                    PrevRot;                                       // 0x0018 (0x000C) [0x0000000000000000]               
	struct FRotator                                    CurrentRot;                                    // 0x0024 (0x000C) [0x0000000000000000]               
	struct FVector                                     PrevLeaveTangent;                              // 0x0030 (0x000C) [0x0000000000000000]               
	struct FVector                                     CurrentArriveTangent;                          // 0x003C (0x000C) [0x0000000000000000]               
	float                                              KeyTime;                                       // 0x0048 (0x0004) [0x0000000000000000]               
	float                                              ElapsedTime;                                   // 0x004C (0x0004) [0x0000000000000000]               
};

// ScriptStruct AliceGame.AlicePlayerCamera.AliceCameraTrack
// 0x0014
struct FAliceCameraTrack
{
	class TArray<struct FAliceCameraTrackKey>          KeyArray;                                      // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	float                                              ElapsedTime;                                   // 0x000C (0x0004) [0x0000000000000000]               
	float                                              TotalTime;                                     // 0x0010 (0x0004) [0x0000000000000000]               
};

// ScriptStruct AliceGame.AliceRemoteSpeaker.RemoteSpeakerDelayedLine
// 0x0021
struct FRemoteSpeakerDelayedLine
{
	class AActor*                                      Addressee;                                     // 0x0000 (0x0004) [0x0000000000000000]               
	class USoundCue*                                   Audio;                                         // 0x0004 (0x0004) [0x0000000000000000]               
	uint32_t                                           bSuppressSubtitle : 1;                         // 0x0008 (0x0004) [0x0000000000000000] [0x00000001] 
	float                                              DelayTime;                                     // 0x000C (0x0004) [0x0000000000000000]               
	uint8_t                                            MPBroadcastFilter;                             // 0x0010 (0x0001) [0x0000000000000000]               
	uint8_t                                            UnknownData00[0x3];                              // 0x0011 (0x0003) MISSED OFFSET
	class FString                                      DebugText;                                     // 0x0014 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	uint8_t                                            Priority;                                      // 0x0020 (0x0001) [0x0000000000000000]               
	uint8_t                                            MinStructAlignment[0x3];                         // 0x0021 (0x0003) ADDED PADDING
};

// ScriptStruct AliceGame.AliceSpeechManager.ActiveDialogueLine
// 0x000D
struct FActiveDialogueLine
{
	class AActor*                                      Speaker;                                       // 0x0000 (0x0004) [0x0000000000000000]               
	class AActor*                                      Addressee;                                     // 0x0004 (0x0004) [0x0000000000000000]               
	class USoundCue*                                   Audio;                                         // 0x0008 (0x0004) [0x0000000000000000]               
	uint8_t                                            Priority;                                      // 0x000C (0x0001) [0x0000000000000000]               
	uint8_t                                            MinStructAlignment[0x3];                         // 0x000D (0x0003) ADDED PADDING
};

// ScriptStruct AliceGame.AliceVentActor.CheckpointRecord
// 0x0034
struct AAliceVentActor_FCheckpointRecord
{
	class FString                                      initMostOutName;                               // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class FString                                      initActorFName;                                // 0x000C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	uint32_t                                           bEnabled : 1;                                  // 0x0018 (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bInitHideSet : 1;                              // 0x0018 (0x0004) [0x0000000000000000] [0x00000002] 
	struct FVector                                     Location;                                      // 0x001C (0x000C) [0x0000000000000000]               
	struct FRotator                                    Rotation;                                      // 0x0028 (0x000C) [0x0000000000000000]               
};

// ScriptStruct AliceGame.AliceWeaponPickupFactory.UpgradeData
// 0x0008
struct FUpgradeData
{
	int32_t                                            AliceWeaponLevel;                              // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            UpgradeWeaponLevel;                            // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct AliceGame.MemoryFragmentNormal.CheckpointRecord
// 0x001C
struct AMemoryFragmentNormal_FCheckpointRecord
{
	class FString                                      initMostOutName;                               // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class FString                                      initActorFName;                                // 0x000C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	uint32_t                                           bPickUpedPdata : 1;                            // 0x0018 (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bPickupHidden : 1;                             // 0x0018 (0x0004) [0x0000000000000000] [0x00000002] 
};

// ScriptStruct AliceGame.CheshireCatSpawnPoint.HintsComponent
// 0x0018
struct FHintsComponent
{
	class USoundCue*                                   SoundCue;                                      // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class FName                                        Anim;                                          // 0x0004 (0x0008) [0x0000000000000001] (CPF_Edit)    
	class AActor*                                      Target;                                        // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bOrientToTarget : 1;                           // 0x0010 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	class AActor*                                      LookAtTarget;                                  // 0x0014 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct AliceGame.GameBreakableActor.BreakableStep.BreakableParticleSystem
// 0x0010
struct FBreakableStep_FBreakableParticleSystem
{
	class UParticleSystem*                             Emitter;                                       // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FVector                                     Offset;                                        // 0x0004 (0x000C) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct AliceGame.GameBreakableActor.BreakableStep
// 0x0044
struct FBreakableStep
{
	float                                              DamageThreshold;                               // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class TArray<struct FBreakableStep_FBreakableParticleSystem> ParticleEmitters;                              // 0x0004 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class UStaticMesh*                                 BreakMesh;                                     // 0x0010 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            Physics;                                       // 0x0014 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            UnknownData00[0x3];                              // 0x0015 (0x0003) MISSED OFFSET
	class USoundCue*                                   BreakSound;                                    // 0x0018 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bIsLockable : 1;                               // 0x001C (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	struct FVector                                     LockOffsetCamera;                              // 0x0020 (0x000C) [0x0000000000000001] (CPF_Edit)    
	struct FVector                                     LockOffsetUI;                                  // 0x002C (0x000C) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            iPriority;                                     // 0x0038 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bHideUI : 1;                                   // 0x003C (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	float                                              OriginalDamageThreshold;                       // 0x0040 (0x0004) [0x0000000000002000] (CPF_Transient)
};

// ScriptStruct AliceGame.GameBreakableActor.BreakablePiece.BreakableParticleSystem
// 0x0010
struct FBreakablePiece_FBreakableParticleSystem
{
	class UParticleSystem*                             Emitter;                                       // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FVector                                     Offset;                                        // 0x0004 (0x000C) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct AliceGame.GameBreakableActor.BreakablePiece
// 0x0028
struct FBreakablePiece
{
	struct FBreakablePiece_FBreakableParticleSystem    ParticleEmitter;                               // 0x0000 (0x0010) [0x0000000000000001] (CPF_Edit)    
	class UStaticMesh*                                 BreakMesh;                                     // 0x0010 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            Physics;                                       // 0x0014 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            UnknownData00[0x3];                              // 0x0015 (0x0003) MISSED OFFSET
	class USoundCue*                                   BreakSound;                                    // 0x0018 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              Lifetime;                                      // 0x001C (0x0004) [0x0000000000000001] (CPF_Edit)    
	class AKActorSpawnable*                            subKActor;                                     // 0x0020 (0x0004) [0x0000000000000000]               
	class AEmitterSpawnable*                           Emit;                                          // 0x0024 (0x0004) [0x0000000000000000]               
};

// ScriptStruct AliceGame.GameBreakableActor.CheckpointRecord
// 0x003C
struct AGameBreakableActor_FCheckpointRecord
{
	class FString                                      initMostOutName;                               // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class FString                                      initActorFName;                                // 0x000C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	uint32_t                                           bDestoryed : 1;                                // 0x0018 (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bSaveDestroyed : 1;                            // 0x0018 (0x0004) [0x0000000000000000] [0x00000002] 
	uint32_t                                           bInitHideSet : 1;                              // 0x0018 (0x0004) [0x0000000000000000] [0x00000004] 
	struct FVector                                     Location;                                      // 0x001C (0x000C) [0x0000000000000000]               
	struct FRotator                                    Rotation;                                      // 0x0028 (0x000C) [0x0000000000000000]               
	uint8_t                                            InitialPhysics;                                // 0x0034 (0x0001) [0x0000000000000000]               
	uint8_t                                            UnknownData00[0x3];                              // 0x0035 (0x0003) MISSED OFFSET
	uint32_t                                           CanSpawnHealth : 1;                            // 0x0038 (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           CanSpawnXP : 1;                                // 0x0038 (0x0004) [0x0000000000000000] [0x00000002] 
	uint32_t                                           Breakable : 1;                                 // 0x0038 (0x0004) [0x0000000000000000] [0x00000004] 
};

// ScriptStruct AliceGame.EyeStaff.EyeStaffLevelDataPackage
// 0x0048
struct FEyeStaffLevelDataPackage
{
	float                                              RegenDelayTime;                                // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              RegenRate;                                     // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            InitAmmoCount;                                 // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            MaxAmmo;                                       // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            OverHeatTime;                                  // 0x0010 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              ChargeTime;                                    // 0x0014 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              FullRefillTime;                                // 0x0018 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class TArray<int32_t>                              ShotCost;                                      // 0x001C (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class TArray<float>                                FireInterval;                                  // 0x0028 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	struct FAliceExplosionLightTemplate                MuzzleLightTemplate;                           // 0x0034 (0x0014) [0x0000000000480009] (CPF_Edit | CPF_ExportObject | CPF_Component | CPF_NeedCtorLink)
};

// ScriptStruct AliceGame.NoseActorBase.CheckpointRecord
// 0x0020
struct ANoseActorBase_FCheckpointRecord
{
	class FString                                      initMostOutName;                               // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class FString                                      initActorFName;                                // 0x000C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	uint32_t                                           bEnable : 1;                                   // 0x0018 (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bInitHidden : 1;                               // 0x0018 (0x0004) [0x0000000000000000] [0x00000002] 
	float                                              Health;                                        // 0x001C (0x0004) [0x0000000000000000]               
};

// ScriptStruct AliceGame.HealthUpgradePickup.CheckpointRecord
// 0x001C
struct AHealthUpgradePickup_FCheckpointRecord
{
	class FString                                      initMostOutName;                               // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class FString                                      initActorFName;                                // 0x000C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	uint32_t                                           bPickedSaveInPdata : 1;                        // 0x0018 (0x0004) [0x0000000000000000] [0x00000001] 
};

// ScriptStruct AliceGame.HobbyHorse.HobbyHorseLevelDataPackage
// 0x0014
struct FHobbyHorseLevelDataPackage
{
	struct FAliceExplosionLightTemplate                RadiusAttackLightTemplate;                     // 0x0000 (0x0014) [0x0000000000480009] (CPF_Edit | CPF_ExportObject | CPF_Component | CPF_NeedCtorLink)
};

// ScriptStruct AliceGame.JumpPadPhysics.JumpPadAnimation
// 0x0010
struct AJumpPadPhysics_FJumpPadAnimation
{
	class FName                                        Name;                                          // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	float                                              Time;                                          // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              Rate;                                          // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct AliceGame.JumpPadGrowing.CheckpointRecord
// 0x001C
struct AJumpPadGrowing_FCheckpointRecord
{
	class FString                                      initMostOutName;                               // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class FString                                      initActorFName;                                // 0x000C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	uint32_t                                           bEnableRadiusCheck : 1;                        // 0x0018 (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bEnable : 1;                                   // 0x0018 (0x0004) [0x0000000000000000] [0x00000002] 
};

// ScriptStruct AliceGame.JumpPadMushroom.JumpPadAnimation
// 0x0010
struct AJumpPadMushroom_FJumpPadAnimation
{
	class FName                                        Name;                                          // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	float                                              Time;                                          // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              Rate;                                          // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct AliceGame.SeqAct_SetDeath.DeathTypeFXInfo
// 0x0014
struct FDeathTypeFXInfo
{
	uint8_t                                            Type;                                          // 0x0000 (0x0001) [0x0000000000000000]               
	uint8_t                                            UnknownData00[0x3];                              // 0x0001 (0x0003) MISSED OFFSET
	class UParticleSystem*                             ParticleDeath;                                 // 0x0004 (0x0004) [0x0000000000000000]               
	class UParticleSystem*                             ParticleRespawn;                               // 0x0008 (0x0004) [0x0000000000000000]               
	class USoundCue*                                   ParticleDeathSound;                            // 0x000C (0x0004) [0x0000000000000000]               
	class USoundCue*                                   ParticleRespawnSound;                          // 0x0010 (0x0004) [0x0000000000000000]               
};

// ScriptStruct AliceGame.ShrinkFlowerInteractive.CheckpointRecord
// 0x001C
struct AShrinkFlowerInteractive_FCheckpointRecord
{
	class FString                                      initMostOutName;                               // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class FString                                      initActorFName;                                // 0x000C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	uint32_t                                           bPickedSaveInPdata : 1;                        // 0x0018 (0x0004) [0x0000000000000000] [0x00000001] 
};

// ScriptStruct AliceGame.TeapotCannon.TeapotCannonLevelDataPackage
// 0x0050
struct FTeapotCannonLevelDataPackage
{
	float                                              RegenRate;                                     // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              RegenDelayTimePerAmmo;                         // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            InitAmmoCount;                                 // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            MaxAmmo;                                       // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            OverHeatTime;                                  // 0x0010 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              ChargeTime;                                    // 0x0014 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              FullRefillTime;                                // 0x0018 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              DamageValueCore;                               // 0x001C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              DamageValueSplash;                             // 0x0020 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              NormalCoreRadius;                              // 0x0024 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              NormalSplashRadius;                            // 0x0028 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              ChargedCoreRadius;                             // 0x002C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              ChargedSplashRadius;                           // 0x0030 (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FAliceExplosionLightTemplate                RadiusAttackLightTemplate;                     // 0x0034 (0x0014) [0x0000000000480009] (CPF_Edit | CPF_ExportObject | CPF_Component | CPF_NeedCtorLink)
	class UParticleSystem*                             ChargedProjectileParticle;                     // 0x0048 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class UParticleSystem*                             ChargedImpactParticle;                         // 0x004C (0x0004) [0x0000000000000001] (CPF_Edit)    
};

/*
# ========================================================================================= #
#
# ========================================================================================= #
*/

#ifdef _MSC_VER
#pragma pack(pop)
#endif
