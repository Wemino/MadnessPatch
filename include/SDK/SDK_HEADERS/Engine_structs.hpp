/*
#############################################################################################
# Alice2 (ASDK) SDK 1.0.0.0
# Generated with the CodeRedGenerator v1.2.0
# ========================================================================================= #
# File: Engine_structs.hpp
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

// ScriptStruct Engine.Actor.AnimSlotDesc
// 0x000C
struct FAnimSlotDesc
{
	class FName                                        SlotName;                                      // 0x0000 (0x0008) [0x0000000000100000]               
	int32_t                                            NumChannels;                                   // 0x0008 (0x0004) [0x0000000000100000]               
};

// ScriptStruct Engine.Actor.RigidBodyState
// 0x0039
struct FRigidBodyState
{
	struct FVector                                     Position;                                      // 0x0000 (0x000C) [0x0000000000000000]               
	uint8_t                                            UnknownData00[0x4];                              // 0x000C (0x0004) MISSED OFFSET
	struct FQuat                                       Quaternion;                                    // 0x0010 (0x0010) [0x0000000000000000]               
	struct FVector                                     LinVel;                                        // 0x0020 (0x000C) [0x0000000000000000]               
	struct FVector                                     AngVel;                                        // 0x002C (0x000C) [0x0000000000000000]               
	uint8_t                                            bNewData;                                      // 0x0038 (0x0001) [0x0000000000000000]               
	uint8_t                                            MinStructAlignment[0x7];                         // 0x0039 (0x0007) ADDED PADDING
};

// ScriptStruct Engine.Actor.RigidBodyContactInfo
// 0x003C
struct FRigidBodyContactInfo
{
	struct FVector                                     ContactPosition;                               // 0x0000 (0x000C) [0x0000000000000000]               
	struct FVector                                     ContactNormal;                                 // 0x000C (0x000C) [0x0000000000000000]               
	float                                              ContactPenetration;                            // 0x0018 (0x0004) [0x0000000000000000]               
	struct FVector                                     ContactVelocity[2];                            // 0x001C (0x0018) [0x0000000000000000]               
	class UPhysicalMaterial*                           PhysMaterial[2];                               // 0x0034 (0x0008) [0x0000000000000000]               
};

// ScriptStruct Engine.Actor.CollisionImpactData
// 0x0024
struct FCollisionImpactData
{
	class TArray<struct FRigidBodyContactInfo>         ContactInfos;                                  // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	struct FVector                                     TotalNormalForceVector;                        // 0x000C (0x000C) [0x0000000000000000]               
	struct FVector                                     TotalFrictionForceVector;                      // 0x0018 (0x000C) [0x0000000000000000]               
};

// ScriptStruct Engine.Actor.ReplicatedHitImpulse
// 0x0028
struct FReplicatedHitImpulse
{
	struct FVector                                     AppliedImpulse;                                // 0x0000 (0x000C) [0x0000000000000000]               
	struct FVector                                     HitLocation;                                   // 0x000C (0x000C) [0x0000000000000000]               
	class FName                                        BoneName;                                      // 0x0018 (0x0008) [0x0000000000000000]               
	uint8_t                                            ImpulseCount;                                  // 0x0020 (0x0001) [0x0000000000000000]               
	uint8_t                                            UnknownData00[0x3];                              // 0x0021 (0x0003) MISSED OFFSET
	uint32_t                                           bRadialImpulse : 1;                            // 0x0024 (0x0004) [0x0000000000000000] [0x00000001] 
};

// ScriptStruct Engine.Actor.PhysEffectInfo
// 0x0010
struct FPhysEffectInfo
{
	float                                              Threshold;                                     // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              ReFireDelay;                                   // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class UParticleSystem*                             Effect;                                        // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class USoundCue*                                   Sound;                                         // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.Actor.ActorReference
// 0x0014
struct FActorReference
{
	class AActor*                                      Actor;                                         // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FGuid                                       Guid;                                          // 0x0004 (0x0010) [0x0000000000020003] (CPF_Edit | CPF_Const | CPF_EditConst)
};

// ScriptStruct Engine.Actor.NavReference
// 0x0014
struct FNavReference
{
	class ANavigationPoint*                            Nav;                                           // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FGuid                                       Guid;                                          // 0x0004 (0x0010) [0x0000000000020003] (CPF_Edit | CPF_Const | CPF_EditConst)
};

// ScriptStruct Engine.Actor.BasedPosition
// 0x0034
struct FBasedPosition
{
	class AActor*                                      Base;                                          // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FVector                                     Position;                                      // 0x0004 (0x000C) [0x0000000000000001] (CPF_Edit)    
	struct FVector                                     CachedBaseLocation;                            // 0x0010 (0x000C) [0x0000000000000000]               
	struct FRotator                                    CachedBaseRotation;                            // 0x001C (0x000C) [0x0000000000000000]               
	struct FVector                                     CachedTransPosition;                           // 0x0028 (0x000C) [0x0000000000000000]               
};

// ScriptStruct Engine.Actor.TraceHitInfo
// 0x001C
struct FTraceHitInfo
{
	class UMaterial*                                   Material;                                      // 0x0000 (0x0004) [0x0000000000100000]               
	class UPhysicalMaterial*                           PhysMaterial;                                  // 0x0004 (0x0004) [0x0000000000100000]               
	int32_t                                            Item;                                          // 0x0008 (0x0004) [0x0000000000100000]               
	int32_t                                            LevelIndex;                                    // 0x000C (0x0004) [0x0000000000100000]               
	class FName                                        BoneName;                                      // 0x0010 (0x0008) [0x0000000000100000]               
	class UPrimitiveComponent*                         HitComponent;                                  // 0x0018 (0x0004) [0x0000000004180008] (CPF_ExportObject | CPF_Component | CPF_EditInline)
};

// ScriptStruct Engine.Actor.ImpactInfo
// 0x0050
struct FImpactInfo
{
	class AActor*                                      HitActor;                                      // 0x0000 (0x0004) [0x0000000000100000]               
	struct FVector                                     HitLocation;                                   // 0x0004 (0x000C) [0x0000000000100000]               
	struct FVector                                     HitNormal;                                     // 0x0010 (0x000C) [0x0000000000100000]               
	struct FVector                                     RayDir;                                        // 0x001C (0x000C) [0x0000000000100000]               
	struct FVector                                     StartTrace;                                    // 0x0028 (0x000C) [0x0000000000100000]               
	struct FTraceHitInfo                               HitInfo;                                       // 0x0034 (0x001C) [0x0000000000180000] (CPF_Component)
};

// ScriptStruct Engine.SequenceOp.SeqOpInputLink
// 0x0028
struct FSeqOpInputLink
{
	class FString                                      LinkDesc;                                      // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	uint32_t                                           bHasImpulse : 1;                               // 0x000C (0x0004) [0x0000000000000000] [0x00000001] 
	int32_t                                            QueuedActivations;                             // 0x0010 (0x0004) [0x0000000000000000]               
	uint32_t                                           bDisabled : 1;                                 // 0x0014 (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bDisabledPIE : 1;                              // 0x0014 (0x0004) [0x0000000000000000] [0x00000002] 
	uint32_t                                           bDisabledPIG : 1;                              // 0x0014 (0x0004) [0x0000000000000000] [0x00000004] 
	class USequenceOp*                                 LinkedOp;                                      // 0x0018 (0x0004) [0x0000000000000000]               
	int32_t                                            DrawY;                                         // 0x001C (0x0004) [0x0000000000000000]               
	uint32_t                                           bHidden : 1;                                   // 0x0020 (0x0004) [0x0000000000000000] [0x00000001] 
	float                                              ActivateDelay;                                 // 0x0024 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.Actor.AnimSlotInfo
// 0x0014
struct FAnimSlotInfo
{
	class FName                                        SlotName;                                      // 0x0000 (0x0008) [0x0000000000100000]               
	class TArray<float>                                ChannelWeights;                                // 0x0008 (0x000C) [0x0000000000500000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.Actor.TimerData
// 0x001C
struct FTimerData
{
	uint32_t                                           bLoop : 1;                                     // 0x0000 (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bPaused : 1;                                   // 0x0000 (0x0004) [0x0000000000000000] [0x00000002] 
	class FName                                        FuncName;                                      // 0x0004 (0x0008) [0x0000000000000000]               
	float                                              Rate;                                          // 0x000C (0x0004) [0x0000000000000000]               
	float                                              Count;                                         // 0x0010 (0x0004) [0x0000000000000000]               
	float                                              TimerTimeDilation;                             // 0x0014 (0x0004) [0x0000000000000000]               
	class UObject*                                     TimerObj;                                      // 0x0018 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.PrimitiveComponent.RBCollisionChannelContainer
// 0x0004
struct FRBCollisionChannelContainer
{
	uint32_t                                           Default : 1;                                   // 0x0000 (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)
	uint32_t                                           Nothing : 1;                                   // 0x0000 (0x0004) [0x0000000000000002] [0x00000002] (CPF_Const)
	uint32_t                                           Pawn : 1;                                      // 0x0000 (0x0004) [0x0000000000000003] [0x00000004] (CPF_Edit | CPF_Const)
	uint32_t                                           Vehicle : 1;                                   // 0x0000 (0x0004) [0x0000000000000003] [0x00000008] (CPF_Edit | CPF_Const)
	uint32_t                                           Water : 1;                                     // 0x0000 (0x0004) [0x0000000000000003] [0x00000010] (CPF_Edit | CPF_Const)
	uint32_t                                           GameplayPhysics : 1;                           // 0x0000 (0x0004) [0x0000000000000003] [0x00000020] (CPF_Edit | CPF_Const)
	uint32_t                                           EffectPhysics : 1;                             // 0x0000 (0x0004) [0x0000000000000003] [0x00000040] (CPF_Edit | CPF_Const)
	uint32_t                                           Untitled1 : 1;                                 // 0x0000 (0x0004) [0x0000000000000003] [0x00000080] (CPF_Edit | CPF_Const)
	uint32_t                                           Untitled2 : 1;                                 // 0x0000 (0x0004) [0x0000000000000003] [0x00000100] (CPF_Edit | CPF_Const)
	uint32_t                                           Untitled3 : 1;                                 // 0x0000 (0x0004) [0x0000000000000003] [0x00000200] (CPF_Edit | CPF_Const)
	uint32_t                                           Untitled4 : 1;                                 // 0x0000 (0x0004) [0x0000000000000003] [0x00000400] (CPF_Edit | CPF_Const)
	uint32_t                                           Cloth : 1;                                     // 0x0000 (0x0004) [0x0000000000000003] [0x00000800] (CPF_Edit | CPF_Const)
	uint32_t                                           FluidDrain : 1;                                // 0x0000 (0x0004) [0x0000000000000003] [0x00001000] (CPF_Edit | CPF_Const)
	uint32_t                                           SoftBody : 1;                                  // 0x0000 (0x0004) [0x0000000000000003] [0x00002000] (CPF_Edit | CPF_Const)
	uint32_t                                           FracturedMeshPart : 1;                         // 0x0000 (0x0004) [0x0000000000000003] [0x00004000] (CPF_Edit | CPF_Const)
	uint32_t                                           BlockingVolume : 1;                            // 0x0000 (0x0004) [0x0000000000000003] [0x00008000] (CPF_Edit | CPF_Const)
	uint32_t                                           DeadPawn : 1;                                  // 0x0000 (0x0004) [0x0000000000000003] [0x00010000] (CPF_Edit | CPF_Const)
	uint32_t                                           Clothing : 1;                                  // 0x0000 (0x0004) [0x0000000000000003] [0x00020000] (CPF_Edit | CPF_Const)
	uint32_t                                           ClothingCollision : 1;                         // 0x0000 (0x0004) [0x0000000000000003] [0x00040000] (CPF_Edit | CPF_Const)
};

// ScriptStruct Engine.LightComponent.LightingChannelContainer
// 0x0004
struct FLightingChannelContainer
{
	uint32_t                                           bInitialized : 1;                              // 0x0000 (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           BSP : 1;                                       // 0x0000 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint32_t                                           Static : 1;                                    // 0x0000 (0x0004) [0x0000000000000001] [0x00000004] (CPF_Edit)
	uint32_t                                           Dynamic : 1;                                   // 0x0000 (0x0004) [0x0000000000000001] [0x00000008] (CPF_Edit)
	uint32_t                                           CompositeDynamic : 1;                          // 0x0000 (0x0004) [0x0000000000000001] [0x00000010] (CPF_Edit)
	uint32_t                                           Skybox : 1;                                    // 0x0000 (0x0004) [0x0000000000000001] [0x00000020] (CPF_Edit)
	uint32_t                                           Unnamed_1 : 1;                                 // 0x0000 (0x0004) [0x0000000000000001] [0x00000040] (CPF_Edit)
	uint32_t                                           Unnamed_2 : 1;                                 // 0x0000 (0x0004) [0x0000000000000001] [0x00000080] (CPF_Edit)
	uint32_t                                           Unnamed_3 : 1;                                 // 0x0000 (0x0004) [0x0000000000000001] [0x00000100] (CPF_Edit)
	uint32_t                                           PhysXLighting_1 : 1;                           // 0x0000 (0x0004) [0x0000000000000001] [0x00000200] (CPF_Edit)
	uint32_t                                           PhysXLighting_2 : 1;                           // 0x0000 (0x0004) [0x0000000000000001] [0x00000400] (CPF_Edit)
	uint32_t                                           PhysXLighting_3 : 1;                           // 0x0000 (0x0004) [0x0000000000000001] [0x00000800] (CPF_Edit)
	uint32_t                                           Cinematic_1 : 1;                               // 0x0000 (0x0004) [0x0000000000000001] [0x00001000] (CPF_Edit)
	uint32_t                                           Cinematic_2 : 1;                               // 0x0000 (0x0004) [0x0000000000000001] [0x00002000] (CPF_Edit)
	uint32_t                                           Cinematic_3 : 1;                               // 0x0000 (0x0004) [0x0000000000000001] [0x00004000] (CPF_Edit)
	uint32_t                                           Cinematic_4 : 1;                               // 0x0000 (0x0004) [0x0000000000000001] [0x00008000] (CPF_Edit)
	uint32_t                                           Cinematic_5 : 1;                               // 0x0000 (0x0004) [0x0000000000000001] [0x00010000] (CPF_Edit)
	uint32_t                                           Cinematic_6 : 1;                               // 0x0000 (0x0004) [0x0000000000000001] [0x00020000] (CPF_Edit)
	uint32_t                                           Cinematic_7 : 1;                               // 0x0000 (0x0004) [0x0000000000000001] [0x00040000] (CPF_Edit)
	uint32_t                                           Cinematic_8 : 1;                               // 0x0000 (0x0004) [0x0000000000000001] [0x00080000] (CPF_Edit)
	uint32_t                                           Cinematic_9 : 1;                               // 0x0000 (0x0004) [0x0000000000000001] [0x00100000] (CPF_Edit)
	uint32_t                                           Cinematic_10 : 1;                              // 0x0000 (0x0004) [0x0000000000000001] [0x00200000] (CPF_Edit)
	uint32_t                                           Gameplay_1 : 1;                                // 0x0000 (0x0004) [0x0000000000000001] [0x00400000] (CPF_Edit)
	uint32_t                                           Gameplay_2 : 1;                                // 0x0000 (0x0004) [0x0000000000000001] [0x00800000] (CPF_Edit)
	uint32_t                                           Gameplay_3 : 1;                                // 0x0000 (0x0004) [0x0000000000000001] [0x01000000] (CPF_Edit)
	uint32_t                                           Gameplay_4 : 1;                                // 0x0000 (0x0004) [0x0000000000000001] [0x02000000] (CPF_Edit)
	uint32_t                                           Crowd : 1;                                     // 0x0000 (0x0004) [0x0000000000000001] [0x04000000] (CPF_Edit)
};

// ScriptStruct Engine.PrimitiveComponent.MaterialViewRelevance
// 0x0004
struct FMaterialViewRelevance
{
	uint32_t                                           bOpaque : 1;                                   // 0x0000 (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bTranslucent : 1;                              // 0x0000 (0x0004) [0x0000000000000000] [0x00000002] 
	uint32_t                                           bDistortion : 1;                               // 0x0000 (0x0004) [0x0000000000000000] [0x00000004] 
	uint32_t                                           bOneLayerDistortionRelevance : 1;              // 0x0000 (0x0004) [0x0000000000000000] [0x00000008] 
	uint32_t                                           bLit : 1;                                      // 0x0000 (0x0004) [0x0000000000000000] [0x00000010] 
	uint32_t                                           bUsesSceneColor : 1;                           // 0x0000 (0x0004) [0x0000000000000000] [0x00000020] 
};

// ScriptStruct Engine.Texture.TextureGroupContainer
// 0x0004
struct FTextureGroupContainer
{
	uint32_t                                           TEXTUREGROUP_World : 1;                        // 0x0000 (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)
	uint32_t                                           TEXTUREGROUP_WorldNormalMap : 1;               // 0x0000 (0x0004) [0x0000000000000003] [0x00000002] (CPF_Edit | CPF_Const)
	uint32_t                                           TEXTUREGROUP_WorldSpecular : 1;                // 0x0000 (0x0004) [0x0000000000000003] [0x00000004] (CPF_Edit | CPF_Const)
	uint32_t                                           TEXTUREGROUP_Character : 1;                    // 0x0000 (0x0004) [0x0000000000000003] [0x00000008] (CPF_Edit | CPF_Const)
	uint32_t                                           TEXTUREGROUP_CharacterNormalMap : 1;           // 0x0000 (0x0004) [0x0000000000000003] [0x00000010] (CPF_Edit | CPF_Const)
	uint32_t                                           TEXTUREGROUP_CharacterSpecular : 1;            // 0x0000 (0x0004) [0x0000000000000003] [0x00000020] (CPF_Edit | CPF_Const)
	uint32_t                                           TEXTUREGROUP_Weapon : 1;                       // 0x0000 (0x0004) [0x0000000000000003] [0x00000040] (CPF_Edit | CPF_Const)
	uint32_t                                           TEXTUREGROUP_WeaponNormalMap : 1;              // 0x0000 (0x0004) [0x0000000000000003] [0x00000080] (CPF_Edit | CPF_Const)
	uint32_t                                           TEXTUREGROUP_WeaponSpecular : 1;               // 0x0000 (0x0004) [0x0000000000000003] [0x00000100] (CPF_Edit | CPF_Const)
	uint32_t                                           TEXTUREGROUP_Vehicle : 1;                      // 0x0000 (0x0004) [0x0000000000000003] [0x00000200] (CPF_Edit | CPF_Const)
	uint32_t                                           TEXTUREGROUP_VehicleNormalMap : 1;             // 0x0000 (0x0004) [0x0000000000000003] [0x00000400] (CPF_Edit | CPF_Const)
	uint32_t                                           TEXTUREGROUP_VehicleSpecular : 1;              // 0x0000 (0x0004) [0x0000000000000003] [0x00000800] (CPF_Edit | CPF_Const)
	uint32_t                                           TEXTUREGROUP_Cinematic : 1;                    // 0x0000 (0x0004) [0x0000000000000003] [0x00001000] (CPF_Edit | CPF_Const)
	uint32_t                                           TEXTUREGROUP_Effects : 1;                      // 0x0000 (0x0004) [0x0000000000000003] [0x00002000] (CPF_Edit | CPF_Const)
	uint32_t                                           TEXTUREGROUP_EffectsNotFiltered : 1;           // 0x0000 (0x0004) [0x0000000000000003] [0x00004000] (CPF_Edit | CPF_Const)
	uint32_t                                           TEXTUREGROUP_Skybox : 1;                       // 0x0000 (0x0004) [0x0000000000000003] [0x00008000] (CPF_Edit | CPF_Const)
	uint32_t                                           TEXTUREGROUP_UI : 1;                           // 0x0000 (0x0004) [0x0000000000000003] [0x00010000] (CPF_Edit | CPF_Const)
	uint32_t                                           TEXTUREGROUP_Lightmap : 1;                     // 0x0000 (0x0004) [0x0000000000000003] [0x00020000] (CPF_Edit | CPF_Const)
	uint32_t                                           TEXTUREGROUP_RenderTarget : 1;                 // 0x0000 (0x0004) [0x0000000000000003] [0x00040000] (CPF_Edit | CPF_Const)
	uint32_t                                           TEXTUREGROUP_MobileFlattened : 1;              // 0x0000 (0x0004) [0x0000000000000003] [0x00080000] (CPF_Edit | CPF_Const)
	uint32_t                                           TEXTUREGROUP_ProcBuilding_Face : 1;            // 0x0000 (0x0004) [0x0000000000000003] [0x00100000] (CPF_Edit | CPF_Const)
	uint32_t                                           TEXTUREGROUP_ProcBuilding_LightMap : 1;        // 0x0000 (0x0004) [0x0000000000000003] [0x00200000] (CPF_Edit | CPF_Const)
	uint32_t                                           TEXTUREGROUP_Shadowmap : 1;                    // 0x0000 (0x0004) [0x0000000000000003] [0x00400000] (CPF_Edit | CPF_Const)
	uint32_t                                           TEXTUREGROUP_ColorLookupTable : 1;             // 0x0000 (0x0004) [0x0000000000000003] [0x00800000] (CPF_Edit | CPF_Const)
};

// ScriptStruct Engine.Texture2D.Texture2DMipMap
// 0x003C
struct FTexture2DMipMap
{
	struct FUntypedBulkData_Mirror                     Data;                                          // 0x0000 (0x0034) [0x0000000000001000] (CPF_Native)  
	int32_t                                            SizeX;                                         // 0x0034 (0x0004) [0x0000000000001000] (CPF_Native)  
	int32_t                                            SizeY;                                         // 0x0038 (0x0004) [0x0000000000001000] (CPF_Native)  
};

// ScriptStruct Engine.Texture2D.TextureLinkedListMirror
// 0x000C
struct FTextureLinkedListMirror
{
	struct FPointer                                    Element;                                       // 0x0000 (0x0004) [0x0000000000001002] (CPF_Const | CPF_Native)
	struct FPointer                                    Next;                                          // 0x0004 (0x0004) [0x0000000000001002] (CPF_Const | CPF_Native)
	struct FPointer                                    PrevLink;                                      // 0x0008 (0x0004) [0x0000000000001002] (CPF_Const | CPF_Native)
};

// ScriptStruct Engine.Info.KeyValuePair
// 0x0018
struct FKeyValuePair
{
	class FString                                      Key;                                           // 0x0000 (0x000C) [0x0000000000500001] (CPF_Edit | CPF_NeedCtorLink)
	class FString                                      Value;                                         // 0x000C (0x000C) [0x0000000000500001] (CPF_Edit | CPF_NeedCtorLink)
};

// ScriptStruct Engine.Info.PlayerResponseLine
// 0x002C
struct FPlayerResponseLine
{
	int32_t                                            PlayerNum;                                     // 0x0000 (0x0004) [0x0000000000100001] (CPF_Edit)    
	int32_t                                            PlayerID;                                      // 0x0004 (0x0004) [0x0000000000100001] (CPF_Edit)    
	class FString                                      PlayerName;                                    // 0x0008 (0x000C) [0x0000000000500001] (CPF_Edit | CPF_NeedCtorLink)
	int32_t                                            Ping;                                          // 0x0014 (0x0004) [0x0000000000100001] (CPF_Edit)    
	int32_t                                            Score;                                         // 0x0018 (0x0004) [0x0000000000100001] (CPF_Edit)    
	int32_t                                            StatsID;                                       // 0x001C (0x0004) [0x0000000000100001] (CPF_Edit)    
	class TArray<struct FKeyValuePair>                 PlayerInfo;                                    // 0x0020 (0x000C) [0x0000000000500001] (CPF_Edit | CPF_NeedCtorLink)
};

// ScriptStruct Engine.Info.ServerResponseLine
// 0x0060
struct FServerResponseLine
{
	int32_t                                            ServerID;                                      // 0x0000 (0x0004) [0x0000000000100001] (CPF_Edit)    
	class FString                                      IP;                                            // 0x0004 (0x000C) [0x0000000000500001] (CPF_Edit | CPF_NeedCtorLink)
	int32_t                                            Port;                                          // 0x0010 (0x0004) [0x0000000000100001] (CPF_Edit)    
	int32_t                                            QueryPort;                                     // 0x0014 (0x0004) [0x0000000000100001] (CPF_Edit)    
	class FString                                      ServerName;                                    // 0x0018 (0x000C) [0x0000000000500001] (CPF_Edit | CPF_NeedCtorLink)
	class FString                                      MapName;                                       // 0x0024 (0x000C) [0x0000000000500001] (CPF_Edit | CPF_NeedCtorLink)
	class FString                                      GameType;                                      // 0x0030 (0x000C) [0x0000000000500001] (CPF_Edit | CPF_NeedCtorLink)
	int32_t                                            CurrentPlayers;                                // 0x003C (0x0004) [0x0000000000100001] (CPF_Edit)    
	int32_t                                            MaxPlayers;                                    // 0x0040 (0x0004) [0x0000000000100001] (CPF_Edit)    
	int32_t                                            Ping;                                          // 0x0044 (0x0004) [0x0000000000100001] (CPF_Edit)    
	class TArray<struct FKeyValuePair>                 ServerInfo;                                    // 0x0048 (0x000C) [0x0000000000500001] (CPF_Edit | CPF_NeedCtorLink)
	class TArray<struct FPlayerResponseLine>           PlayerInfo;                                    // 0x0054 (0x000C) [0x0000000000500001] (CPF_Edit | CPF_NeedCtorLink)
};

// ScriptStruct Engine.Settings.LocalizedStringSetting
// 0x0009
struct FLocalizedStringSetting
{
	int32_t                                            Id;                                            // 0x0000 (0x0004) [0x0000000000000000]               
	int32_t                                            ValueIndex;                                    // 0x0004 (0x0004) [0x0000000000000000]               
	uint8_t                                            AdvertisementType;                             // 0x0008 (0x0001) [0x0000000000000000]               
	uint8_t                                            MinStructAlignment[0x3];                         // 0x0009 (0x0003) ADDED PADDING
};

// ScriptStruct Engine.Settings.SettingsData
// 0x000C
struct FSettingsData
{
	uint8_t                                            Type;                                          // 0x0000 (0x0001) [0x0000000000000002] (CPF_Const)   
	uint8_t                                            UnknownData00[0x3];                              // 0x0001 (0x0003) MISSED OFFSET
	int32_t                                            Value1;                                        // 0x0004 (0x0004) [0x0000000000000002] (CPF_Const)   
	struct FPointer                                    Value2;                                        // 0x0008 (0x0004) [0x0000000000003002] (CPF_Const | CPF_Native | CPF_Transient)
};

// ScriptStruct Engine.Settings.SettingsProperty
// 0x0011
struct FSettingsProperty
{
	int32_t                                            PropertyId;                                    // 0x0000 (0x0004) [0x0000000000000000]               
	struct FSettingsData                               Data;                                          // 0x0004 (0x000C) [0x0000000000000000]               
	uint8_t                                            AdvertisementType;                             // 0x0010 (0x0001) [0x0000000000000000]               
	uint8_t                                            MinStructAlignment[0x3];                         // 0x0011 (0x0003) ADDED PADDING
};

// ScriptStruct Engine.Settings.IdToStringMapping
// 0x000C
struct FIdToStringMapping
{
	int32_t                                            Id;                                            // 0x0000 (0x0004) [0x0000000000000002] (CPF_Const)   
	class FName                                        Name;                                          // 0x0004 (0x0008) [0x0000000000008002] (CPF_Const | CPF_Localized)
};

// ScriptStruct Engine.Settings.StringIdToStringMapping
// 0x0010
struct FStringIdToStringMapping
{
	int32_t                                            Id;                                            // 0x0000 (0x0004) [0x0000000000000002] (CPF_Const)   
	class FName                                        Name;                                          // 0x0004 (0x0008) [0x0000000000008002] (CPF_Const | CPF_Localized)
	uint32_t                                           bIsWildcard : 1;                               // 0x000C (0x0004) [0x0000000000000002] [0x00000001] (CPF_Const)
};

// ScriptStruct Engine.Settings.LocalizedStringSettingMetaData
// 0x0024
struct FLocalizedStringSettingMetaData
{
	int32_t                                            Id;                                            // 0x0000 (0x0004) [0x0000000000000002] (CPF_Const)   
	class FName                                        Name;                                          // 0x0004 (0x0008) [0x0000000000000002] (CPF_Const)   
	class FString                                      ColumnHeaderText;                              // 0x000C (0x000C) [0x0000000000408002] (CPF_Const | CPF_Localized | CPF_NeedCtorLink)
	class TArray<struct FStringIdToStringMapping>      ValueMappings;                                 // 0x0018 (0x000C) [0x0000000000400002] (CPF_Const | CPF_NeedCtorLink)
};

// ScriptStruct Engine.Settings.SettingsPropertyPropertyMetaData
// 0x0040
struct FSettingsPropertyPropertyMetaData
{
	int32_t                                            Id;                                            // 0x0000 (0x0004) [0x0000000000000002] (CPF_Const)   
	class FName                                        Name;                                          // 0x0004 (0x0008) [0x0000000000000002] (CPF_Const)   
	class FString                                      ColumnHeaderText;                              // 0x000C (0x000C) [0x0000000000408002] (CPF_Const | CPF_Localized | CPF_NeedCtorLink)
	uint8_t                                            MappingType;                                   // 0x0018 (0x0001) [0x0000000000000002] (CPF_Const)   
	uint8_t                                            UnknownData00[0x3];                              // 0x0019 (0x0003) MISSED OFFSET
	class TArray<struct FIdToStringMapping>            ValueMappings;                                 // 0x001C (0x000C) [0x0000000000400002] (CPF_Const | CPF_NeedCtorLink)
	class TArray<struct FSettingsData>                 PredefinedValues;                              // 0x0028 (0x000C) [0x0000000000400002] (CPF_Const | CPF_NeedCtorLink)
	float                                              MinVal;                                        // 0x0034 (0x0004) [0x0000000000000002] (CPF_Const)   
	float                                              MaxVal;                                        // 0x0038 (0x0004) [0x0000000000000002] (CPF_Const)   
	float                                              RangeIncrement;                                // 0x003C (0x0004) [0x0000000000000002] (CPF_Const)   
};

// ScriptStruct Engine.OnlineSubsystem.UniqueNetId
// 0x0008
struct FUniqueNetId
{
	struct FQWord                                      Uid;                                           // 0x0000 (0x0008) [0x0000000000000000]               
};

// ScriptStruct Engine.OnlineSubsystem.OnlineRegistrant
// 0x0008
struct FOnlineRegistrant
{
	struct FUniqueNetId                                PlayerNetId;                                   // 0x0000 (0x0008) [0x0000000000000002] (CPF_Const)   
};

// ScriptStruct Engine.OnlineSubsystem.OnlineArbitrationRegistrant
// 0x000C (0x0008 - 0x0014)
struct FOnlineArbitrationRegistrant : FOnlineRegistrant
{
	struct FQWord                                      MachineId;                                     // 0x0008 (0x0008) [0x0000000000000002] (CPF_Const)   
	int32_t                                            Trustworthiness;                               // 0x0010 (0x0004) [0x0000000000000002] (CPF_Const)   
};

// ScriptStruct Engine.OnlineSubsystem.NamedSession
// 0x0028
struct FNamedSession
{
	class FName                                        SessionName;                                   // 0x0000 (0x0008) [0x0000000000000000]               
	struct FPointer                                    SessionInfo;                                   // 0x0008 (0x0004) [0x0000000000003002] (CPF_Const | CPF_Native | CPF_Transient)
	class UOnlineGameSettings*                         GameSettings;                                  // 0x000C (0x0004) [0x0000000000000000]               
	class TArray<struct FOnlineRegistrant>             Registrants;                                   // 0x0010 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<struct FOnlineArbitrationRegistrant>  ArbitrationRegistrants;                        // 0x001C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.OnlineSubsystem.NamedInterface
// 0x000C
struct FNamedInterface
{
	class FName                                        InterfaceName;                                 // 0x0000 (0x0008) [0x0000000000000000]               
	class UObject*                                     InterfaceObject;                               // 0x0008 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.OnlineSubsystem.OnlinePartyMember
// 0x0034
struct FOnlinePartyMember
{
	struct FUniqueNetId                                UniqueId;                                      // 0x0000 (0x0008) [0x0000000000000002] (CPF_Const)   
	class FString                                      NickName;                                      // 0x0008 (0x000C) [0x0000000000400002] (CPF_Const | CPF_NeedCtorLink)
	uint8_t                                            LocalUserNum;                                  // 0x0014 (0x0001) [0x0000000000000002] (CPF_Const)   
	uint8_t                                            NatType;                                       // 0x0015 (0x0001) [0x0000000000000002] (CPF_Const)   
	uint8_t                                            UnknownData00[0x2];                              // 0x0016 (0x0002) MISSED OFFSET
	int32_t                                            TitleId;                                       // 0x0018 (0x0004) [0x0000000000000002] (CPF_Const)   
	uint32_t                                           bIsLocal : 1;                                  // 0x001C (0x0004) [0x0000000000000002] [0x00000001] (CPF_Const)
	uint32_t                                           bIsInPartyVoice : 1;                           // 0x001C (0x0004) [0x0000000000000002] [0x00000002] (CPF_Const)
	uint32_t                                           bIsTalking : 1;                                // 0x001C (0x0004) [0x0000000000000002] [0x00000004] (CPF_Const)
	uint32_t                                           bIsInGameSession : 1;                          // 0x001C (0x0004) [0x0000000000000002] [0x00000008] (CPF_Const)
	struct FPointer                                    SessionInfo;                                   // 0x0020 (0x0004) [0x0000000000003002] (CPF_Const | CPF_Native | CPF_Transient)
	struct FQWord                                      Data1;                                         // 0x0024 (0x0008) [0x0000000000000002] (CPF_Const)   
	struct FQWord                                      Data2;                                         // 0x002C (0x0008) [0x0000000000000002] (CPF_Const)   
};

// ScriptStruct Engine.OnlineSubsystem.AchievementDetails
// 0x0034
struct FAchievementDetails
{
	int32_t                                            Id;                                            // 0x0000 (0x0004) [0x0000000000000002] (CPF_Const)   
	class FString                                      AchievementName;                               // 0x0004 (0x000C) [0x0000000000400002] (CPF_Const | CPF_NeedCtorLink)
	class FString                                      Description;                                   // 0x0010 (0x000C) [0x0000000000400002] (CPF_Const | CPF_NeedCtorLink)
	class FString                                      HowTo;                                         // 0x001C (0x000C) [0x0000000000400002] (CPF_Const | CPF_NeedCtorLink)
	class USurface*                                    Image;                                         // 0x0028 (0x0004) [0x0000000000000000]               
	int32_t                                            GamerPoints;                                   // 0x002C (0x0004) [0x0000000000000002] (CPF_Const)   
	uint32_t                                           bIsSecret : 1;                                 // 0x0030 (0x0004) [0x0000000000000002] [0x00000001] (CPF_Const)
	uint32_t                                           bWasAchievedOnline : 1;                        // 0x0030 (0x0004) [0x0000000000000002] [0x00000002] (CPF_Const)
	uint32_t                                           bWasAchievedOffline : 1;                       // 0x0030 (0x0004) [0x0000000000000002] [0x00000004] (CPF_Const)
};

// ScriptStruct Engine.OnlineSubsystem.CommunityContentMetadata
// 0x0010
struct FCommunityContentMetadata
{
	int32_t                                            ContentType;                                   // 0x0000 (0x0004) [0x0000000000000000]               
	class TArray<struct FSettingsProperty>             MetadataItems;                                 // 0x0004 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.OnlineSubsystem.CommunityContentFile
// 0x0034
struct FCommunityContentFile
{
	int32_t                                            ContentId;                                     // 0x0000 (0x0004) [0x0000000000000000]               
	int32_t                                            FileId;                                        // 0x0004 (0x0004) [0x0000000000000000]               
	int32_t                                            ContentType;                                   // 0x0008 (0x0004) [0x0000000000000000]               
	int32_t                                            FileSize;                                      // 0x000C (0x0004) [0x0000000000000000]               
	struct FUniqueNetId                                Owner;                                         // 0x0010 (0x0008) [0x0000000000000000]               
	int32_t                                            DownloadCount;                                 // 0x0018 (0x0004) [0x0000000000000000]               
	float                                              AverageRating;                                 // 0x001C (0x0004) [0x0000000000000000]               
	int32_t                                            RatingCount;                                   // 0x0020 (0x0004) [0x0000000000000000]               
	int32_t                                            LastRatingGiven;                               // 0x0024 (0x0004) [0x0000000000000000]               
	class FString                                      LocalFilePath;                                 // 0x0028 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.OnlineSubsystem.TitleFile
// 0x001C
struct FTitleFile
{
	class FString                                      Filename;                                      // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	uint8_t                                            AsyncState;                                    // 0x000C (0x0001) [0x0000000000000000]               
	uint8_t                                            UnknownData00[0x3];                              // 0x000D (0x0003) MISSED OFFSET
	class TArray<uint8_t>                              Data;                                          // 0x0010 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.OnlineSubsystem.NamedInterfaceDef
// 0x0014
struct FNamedInterfaceDef
{
	class FName                                        InterfaceName;                                 // 0x0000 (0x0008) [0x0000000000000000]               
	class FString                                      InterfaceClassName;                            // 0x0008 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.OnlineSubsystem.OnlineFriendMessage
// 0x0024
struct FOnlineFriendMessage
{
	struct FUniqueNetId                                SendingPlayerId;                               // 0x0000 (0x0008) [0x0000000000000000]               
	class FString                                      SendingPlayerNick;                             // 0x0008 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	uint32_t                                           bIsFriendInvite : 1;                           // 0x0014 (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bIsGameInvite : 1;                             // 0x0014 (0x0004) [0x0000000000000000] [0x00000002] 
	uint32_t                                           bWasAccepted : 1;                              // 0x0014 (0x0004) [0x0000000000000000] [0x00000004] 
	uint32_t                                           bWasDenied : 1;                                // 0x0014 (0x0004) [0x0000000000000000] [0x00000008] 
	class FString                                      Message;                                       // 0x0018 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.OnlineSubsystem.RemoteTalker
// 0x0010
struct FRemoteTalker
{
	struct FUniqueNetId                                TalkerId;                                      // 0x0000 (0x0008) [0x0000000000000000]               
	float                                              LastNotificationTime;                          // 0x0008 (0x0004) [0x0000000000000000]               
	uint32_t                                           bWasTalking : 1;                               // 0x000C (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bIsTalking : 1;                                // 0x000C (0x0004) [0x0000000000000000] [0x00000002] 
	uint32_t                                           bIsRegistered : 1;                             // 0x000C (0x0004) [0x0000000000000000] [0x00000004] 
};

// ScriptStruct Engine.OnlineSubsystem.LocalTalker
// 0x0004
struct FLocalTalker
{
	uint32_t                                           bHasVoice : 1;                                 // 0x0000 (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bHasNetworkedVoice : 1;                        // 0x0000 (0x0004) [0x0000000000000000] [0x00000002] 
	uint32_t                                           bIsRecognizingSpeech : 1;                      // 0x0000 (0x0004) [0x0000000000000000] [0x00000004] 
	uint32_t                                           bWasTalking : 1;                               // 0x0000 (0x0004) [0x0000000000000000] [0x00000008] 
	uint32_t                                           bIsTalking : 1;                                // 0x0000 (0x0004) [0x0000000000000000] [0x00000010] 
	uint32_t                                           bIsRegistered : 1;                             // 0x0000 (0x0004) [0x0000000000000000] [0x00000020] 
};

// ScriptStruct Engine.OnlineSubsystem.OnlinePlayerScore
// 0x0010
struct FOnlinePlayerScore
{
	struct FUniqueNetId                                PlayerID;                                      // 0x0000 (0x0008) [0x0000000000000000]               
	int32_t                                            TeamID;                                        // 0x0008 (0x0004) [0x0000000000000000]               
	int32_t                                            Score;                                         // 0x000C (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.OnlineSubsystem.SpeechRecognizedWord
// 0x0014
struct FSpeechRecognizedWord
{
	int32_t                                            WordId;                                        // 0x0000 (0x0004) [0x0000000000000000]               
	class FString                                      WordText;                                      // 0x0004 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	float                                              Confidence;                                    // 0x0010 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.OnlineSubsystem.OnlineContent
// 0x0034
struct FOnlineContent
{
	int32_t                                            UserIndex;                                     // 0x0000 (0x0004) [0x0000000000000000]               
	class FString                                      FriendlyName;                                  // 0x0004 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class FString                                      ContentPath;                                   // 0x0010 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<class FString>                        ContentPackages;                               // 0x001C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<class FString>                        ContentFiles;                                  // 0x0028 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.OnlineSubsystem.OnlineFriend
// 0x0030
struct FOnlineFriend
{
	struct FUniqueNetId                                UniqueId;                                      // 0x0000 (0x0008) [0x0000000000000002] (CPF_Const)   
	struct FQWord                                      SessionId;                                     // 0x0008 (0x0008) [0x0000000000000002] (CPF_Const)   
	class FString                                      NickName;                                      // 0x0010 (0x000C) [0x0000000000400002] (CPF_Const | CPF_NeedCtorLink)
	class FString                                      PresenceInfo;                                  // 0x001C (0x000C) [0x0000000000400002] (CPF_Const | CPF_NeedCtorLink)
	uint8_t                                            FriendState;                                   // 0x0028 (0x0001) [0x0000000000000002] (CPF_Const)   
	uint8_t                                            UnknownData00[0x3];                              // 0x0029 (0x0003) MISSED OFFSET
	uint32_t                                           bIsOnline : 1;                                 // 0x002C (0x0004) [0x0000000000000002] [0x00000001] (CPF_Const)
	uint32_t                                           bIsPlaying : 1;                                // 0x002C (0x0004) [0x0000000000000002] [0x00000002] (CPF_Const)
	uint32_t                                           bIsPlayingThisGame : 1;                        // 0x002C (0x0004) [0x0000000000000002] [0x00000004] (CPF_Const)
	uint32_t                                           bIsJoinable : 1;                               // 0x002C (0x0004) [0x0000000000000002] [0x00000008] (CPF_Const)
	uint32_t                                           bHasVoiceSupport : 1;                          // 0x002C (0x0004) [0x0000000000000002] [0x00000010] (CPF_Const)
	uint32_t                                           bHaveInvited : 1;                              // 0x002C (0x0004) [0x0000000000000000] [0x00000020] 
	uint32_t                                           bHasInvitedYou : 1;                            // 0x002C (0x0004) [0x0000000000000002] [0x00000040] (CPF_Const)
};

// ScriptStruct Engine.OnlineSubsystem.FriendsQuery
// 0x000C
struct FFriendsQuery
{
	struct FUniqueNetId                                UniqueId;                                      // 0x0000 (0x0008) [0x0000000000000000]               
	uint32_t                                           bIsFriend : 1;                                 // 0x0008 (0x0004) [0x0000000000000000] [0x00000001] 
};

// ScriptStruct Engine.Controller.VisiblePortalInfo
// 0x0008
struct FVisiblePortalInfo
{
	class AActor*                                      Source;                                        // 0x0000 (0x0004) [0x0000000000000000]               
	class AActor*                                      Destination;                                   // 0x0004 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.Camera.TViewTarget
// 0x002C
struct FTViewTarget
{
	class AActor*                                      Target;                                        // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class AController*                                 Controller;                                    // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FTPOV                                       POV;                                           // 0x0008 (0x001C) [0x0000000000000001] (CPF_Edit)    
	float                                              AspectRatio;                                   // 0x0024 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class APlayerReplicationInfo*                      PRI;                                           // 0x0028 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.Camera.TCameraCache
// 0x0020
struct FTCameraCache
{
	float                                              TimeStamp;                                     // 0x0000 (0x0004) [0x0000000000000000]               
	struct FTPOV                                       POV;                                           // 0x0004 (0x001C) [0x0000000000000000]               
};

// ScriptStruct Engine.Camera.ViewTargetTransitionParams
// 0x0014
struct FViewTargetTransitionParams
{
	float                                              BlendTime;                                     // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            BlendFunction;                                 // 0x0004 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            UnknownData00[0x3];                              // 0x0005 (0x0003) MISSED OFFSET
	float                                              BlendExp;                                      // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bLockOutgoing : 1;                             // 0x000C (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	float                                              MaxAngle;                                      // 0x0010 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.CameraActor.ControllableParams
// 0x0028
struct FControllableParams
{
	uint32_t                                           bCanBeRotated : 1;                             // 0x0000 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	float                                              PitchLimit;                                    // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              YawLimit;                                      // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bCanBeMovedAlongX : 1;                         // 0x000C (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	float                                              XLimit;                                        // 0x0010 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bCanBeMovedAlongY : 1;                         // 0x0014 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	float                                              YLimit;                                        // 0x0018 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bCanBeMovedAlongZ : 1;                         // 0x001C (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	float                                              ZLimit;                                        // 0x0020 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bHideAlice : 1;                                // 0x0024 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
};

// ScriptStruct Engine.PostProcessVolume.PostProcessSettings
// 0x00E8
struct FPostProcessSettings
{
	uint32_t                                           bOverride_EnableBloom : 1;                     // 0x0000 (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bOverride_EnableDOF : 1;                       // 0x0000 (0x0004) [0x0000000000000000] [0x00000002] 
	uint32_t                                           bOverride_EnableMotionBlur : 1;                // 0x0000 (0x0004) [0x0000000000000000] [0x00000004] 
	uint32_t                                           bOverride_EnableDynamicTonemapping : 1;        // 0x0000 (0x0004) [0x0000000000000000] [0x00000008] 
	uint32_t                                           bOverride_EnableSceneEffect : 1;               // 0x0000 (0x0004) [0x0000000000000000] [0x00000010] 
	uint32_t                                           bOverride_AllowAmbientOcclusion : 1;           // 0x0000 (0x0004) [0x0000000000000000] [0x00000020] 
	uint32_t                                           bOverride_OverrideRimShaderColor : 1;          // 0x0000 (0x0004) [0x0000000000000000] [0x00000040] 
	uint32_t                                           bOverride_Bloom_Scale : 1;                     // 0x0000 (0x0004) [0x0000000000000000] [0x00000080] 
	uint32_t                                           bOverride_Bloom_InterpolationDuration : 1;     // 0x0000 (0x0004) [0x0000000000000000] [0x00000100] 
	uint32_t                                           bOverride_DOF_FalloffExponent : 1;             // 0x0000 (0x0004) [0x0000000000000000] [0x00000200] 
	uint32_t                                           bOverride_DOF_BlurKernelSize : 1;              // 0x0000 (0x0004) [0x0000000000000000] [0x00000400] 
	uint32_t                                           bOverride_DOF_BlurBloomKernelSize : 1;         // 0x0000 (0x0004) [0x0000000000000000] [0x00000800] 
	uint32_t                                           bOverride_DOF_MaxNearBlurAmount : 1;           // 0x0000 (0x0004) [0x0000000000000000] [0x00001000] 
	uint32_t                                           bOverride_DOF_MaxFarBlurAmount : 1;            // 0x0000 (0x0004) [0x0000000000000000] [0x00002000] 
	uint32_t                                           bOverride_DOF_ModulateBlurColor : 1;           // 0x0000 (0x0004) [0x0000000000000000] [0x00004000] 
	uint32_t                                           bOverride_DOF_FocusType : 1;                   // 0x0000 (0x0004) [0x0000000000000000] [0x00008000] 
	uint32_t                                           bOverride_DOF_FocusNearInnerRadius : 1;        // 0x0000 (0x0004) [0x0000000000000000] [0x00010000] 
	uint32_t                                           bOverride_DOF_FocusFarInnerRadius : 1;         // 0x0000 (0x0004) [0x0000000000000000] [0x00020000] 
	uint32_t                                           bOverride_DOF_FocusDistance : 1;               // 0x0000 (0x0004) [0x0000000000000000] [0x00040000] 
	uint32_t                                           bOverride_DOF_FarFocusDistance : 1;            // 0x0000 (0x0004) [0x0000000000000000] [0x00080000] 
	uint32_t                                           bOverride_DOF_FocusPosition : 1;               // 0x0000 (0x0004) [0x0000000000000000] [0x00100000] 
	uint32_t                                           bOverride_DOF_InterpolationDuration : 1;       // 0x0000 (0x0004) [0x0000000000000000] [0x00200000] 
	uint32_t                                           bOverride_DOF_EnableDynamicDoF : 1;            // 0x0000 (0x0004) [0x0000000000000000] [0x00400000] 
	uint32_t                                           bOverride_DOF_AdaptationRate : 1;              // 0x0000 (0x0004) [0x0000000000000000] [0x00800000] 
	uint32_t                                           bOverride_DOF_WaitingTime : 1;                 // 0x0000 (0x0004) [0x0000000000000000] [0x01000000] 
	uint32_t                                           bOverride_DOF_AimingPoint : 1;                 // 0x0000 (0x0004) [0x0000000000000000] [0x02000000] 
	uint32_t                                           bOverride_DOF_MinFarInnerRadius : 1;           // 0x0000 (0x0004) [0x0000000000000000] [0x04000000] 
	uint32_t                                           bOverride_DOF_DDofRange : 1;                   // 0x0000 (0x0004) [0x0000000000000000] [0x08000000] 
	uint32_t                                           bOverride_DOF_ResetAdaptationRate : 1;         // 0x0000 (0x0004) [0x0000000000000000] [0x10000000] 
	uint32_t                                           bOverride_DOF_ResetDistDifference : 1;         // 0x0000 (0x0004) [0x0000000000000000] [0x20000000] 
	uint32_t                                           bOverride_MotionBlur_MaxVelocity : 1;          // 0x0000 (0x0004) [0x0000000000000000] [0x40000000] 
	uint32_t                                           bOverride_MotionBlur_Amount : 1;               // 0x0000 (0x0004) [0x0000000000000000] [0x80000000] 
	uint32_t : 0;                                  // 0x0004 CLOSE BITFIELD STORAGE UNIT
	uint32_t                                           bOverride_MotionBlur_FullMotionBlur : 1;       // 0x0004 (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bOverride_MotionBlur_CameraRotationThreshold : 1;// 0x0004 (0x0004) [0x0000000000000000] [0x00000002] 
	uint32_t                                           bOverride_MotionBlur_CameraTranslationThreshold : 1;// 0x0004 (0x0004) [0x0000000000000000] [0x00000004] 
	uint32_t                                           bOverride_MotionBlur_InterpolationDuration : 1;// 0x0004 (0x0004) [0x0000000000000000] [0x00000008] 
	uint32_t                                           bOverride_DynamicTonemapping_MiddleGray : 1;   // 0x0004 (0x0004) [0x0000000000000000] [0x00000010] 
	uint32_t                                           bOverride_DynamicTonemapping_AdaptationRate : 1;// 0x0004 (0x0004) [0x0000000000000000] [0x00000020] 
	uint32_t                                           bOverride_DynamicTonemapping_LuminanceScale : 1;// 0x0004 (0x0004) [0x0000000000000000] [0x00000040] 
	uint32_t                                           bOverride_DynamicTonemapping_MinGray : 1;      // 0x0004 (0x0004) [0x0000000000000000] [0x00000080] 
	uint32_t                                           bOverride_DynamicTonemapping_MinColorScale : 1;// 0x0004 (0x0004) [0x0000000000000000] [0x00000100] 
	uint32_t                                           bOverride_DynamicTonemapping_MaxColorScale : 1;// 0x0004 (0x0004) [0x0000000000000000] [0x00000200] 
	uint32_t                                           bOverride_Scene_Desaturation : 1;              // 0x0004 (0x0004) [0x0000000000000000] [0x00000400] 
	uint32_t                                           bOverride_Scene_HighLights : 1;                // 0x0004 (0x0004) [0x0000000000000000] [0x00000800] 
	uint32_t                                           bOverride_Scene_MidTones : 1;                  // 0x0004 (0x0004) [0x0000000000000000] [0x00001000] 
	uint32_t                                           bOverride_Scene_Shadows : 1;                   // 0x0004 (0x0004) [0x0000000000000000] [0x00002000] 
	uint32_t                                           bOverride_Scene_InterpolationDuration : 1;     // 0x0004 (0x0004) [0x0000000000000000] [0x00004000] 
	uint32_t                                           bOverride_RimShader_Color : 1;                 // 0x0004 (0x0004) [0x0000000000000000] [0x00008000] 
	uint32_t                                           bOverride_RimShader_InterpolationDuration : 1; // 0x0004 (0x0004) [0x0000000000000000] [0x00010000] 
	uint32_t                                           bEnableBloom : 1;                              // 0x0004 (0x0004) [0x0000000000000001] [0x00020000] (CPF_Edit)
	uint32_t                                           bEnableDOF : 1;                                // 0x0004 (0x0004) [0x0000000000000001] [0x00040000] (CPF_Edit)
	uint32_t                                           bEnableMotionBlur : 1;                         // 0x0004 (0x0004) [0x0000000000000001] [0x00080000] (CPF_Edit)
	uint32_t                                           bEnableSceneEffect : 1;                        // 0x0004 (0x0004) [0x0000000000000001] [0x00100000] (CPF_Edit)
	uint32_t                                           bAllowAmbientOcclusion : 1;                    // 0x0004 (0x0004) [0x0000000000000001] [0x00200000] (CPF_Edit)
	uint32_t                                           bOverrideRimShaderColor : 1;                   // 0x0004 (0x0004) [0x0000000000000001] [0x00400000] (CPF_Edit)
	uint32_t                                           bEnableDynamicTonemapping : 1;                 // 0x0004 (0x0004) [0x0000000000000001] [0x00800000] (CPF_Edit)
	float                                              Bloom_Scale;                                   // 0x0008 (0x0004) [0x0000000200000001] (CPF_Edit | CPF_Interp)
	float                                              Bloom_InterpolationDuration;                   // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              DOF_FalloffExponent;                           // 0x0010 (0x0004) [0x0000000200000001] (CPF_Edit | CPF_Interp)
	float                                              DOF_BlurKernelSize;                            // 0x0014 (0x0004) [0x0000000200000001] (CPF_Edit | CPF_Interp)
	float                                              DOF_BlurBloomKernelSize;                       // 0x0018 (0x0004) [0x0000000200000001] (CPF_Edit | CPF_Interp)
	float                                              DOF_MaxNearBlurAmount;                         // 0x001C (0x0004) [0x0000000200000001] (CPF_Edit | CPF_Interp)
	float                                              DOF_MaxFarBlurAmount;                          // 0x0020 (0x0004) [0x0000000200000001] (CPF_Edit | CPF_Interp)
	struct FColor                                      DOF_ModulateBlurColor;                         // 0x0024 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            DOF_FocusType;                                 // 0x0028 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            UnknownData00[0x3];                              // 0x0029 (0x0003) MISSED OFFSET
	float                                              DOF_FocusNearInnerRadius;                      // 0x002C (0x0004) [0x0000000200000001] (CPF_Edit | CPF_Interp)
	float                                              DOF_FocusFarInnerRadius;                       // 0x0030 (0x0004) [0x0000000200000001] (CPF_Edit | CPF_Interp)
	float                                              DOF_FocusDistance;                             // 0x0034 (0x0004) [0x0000000200000001] (CPF_Edit | CPF_Interp)
	float                                              DOF_FarFocusDistance;                          // 0x0038 (0x0004) [0x0000000200000001] (CPF_Edit | CPF_Interp)
	struct FVector                                     DOF_FocusPosition;                             // 0x003C (0x000C) [0x0000000000000001] (CPF_Edit)    
	float                                              DOF_InterpolationDuration;                     // 0x0048 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           DOF_EnableDynamicDoF : 1;                      // 0x004C (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	float                                              DOF_AdaptationRate;                            // 0x0050 (0x0004) [0x0000000200000001] (CPF_Edit | CPF_Interp)
	float                                              DOF_WaitingTime;                               // 0x0054 (0x0004) [0x0000000200000001] (CPF_Edit | CPF_Interp)
	struct FVector                                     DOF_AimingPoint;                               // 0x0058 (0x000C) [0x0000000200000001] (CPF_Edit | CPF_Interp)
	float                                              DOF_MinFarInnerRadius;                         // 0x0064 (0x0004) [0x0000000200000001] (CPF_Edit | CPF_Interp)
	float                                              DOF_DDofRange;                                 // 0x0068 (0x0004) [0x0000000200000001] (CPF_Edit | CPF_Interp)
	float                                              DOF_ResetAdaptationRate;                       // 0x006C (0x0004) [0x0000000200000001] (CPF_Edit | CPF_Interp)
	float                                              DOF_ResetDistDifference;                       // 0x0070 (0x0004) [0x0000000200000001] (CPF_Edit | CPF_Interp)
	float                                              MotionBlur_MaxVelocity;                        // 0x0074 (0x0004) [0x0000000200000001] (CPF_Edit | CPF_Interp)
	float                                              MotionBlur_Amount;                             // 0x0078 (0x0004) [0x0000000200000001] (CPF_Edit | CPF_Interp)
	uint32_t                                           MotionBlur_FullMotionBlur : 1;                 // 0x007C (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	float                                              MotionBlur_CameraRotationThreshold;            // 0x0080 (0x0004) [0x0000000200000001] (CPF_Edit | CPF_Interp)
	float                                              MotionBlur_CameraTranslationThreshold;         // 0x0084 (0x0004) [0x0000000200000001] (CPF_Edit | CPF_Interp)
	float                                              MotionBlur_InterpolationDuration;              // 0x0088 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              DynamicTonemapping_MiddleGray;                 // 0x008C (0x0004) [0x0000000200000001] (CPF_Edit | CPF_Interp)
	float                                              DynamicTonemapping_AdaptationRate;             // 0x0090 (0x0004) [0x0000000200000001] (CPF_Edit | CPF_Interp)
	float                                              DynamicTonemapping_LuminanceScale;             // 0x0094 (0x0004) [0x0000000200000001] (CPF_Edit | CPF_Interp)
	float                                              DynamicTonemapping_MinGray;                    // 0x0098 (0x0004) [0x0000000200000001] (CPF_Edit | CPF_Interp)
	float                                              DynamicTonemapping_MinColorScale;              // 0x009C (0x0004) [0x0000000200000001] (CPF_Edit | CPF_Interp)
	float                                              DynamicTonemapping_MaxColorScale;              // 0x00A0 (0x0004) [0x0000000200000001] (CPF_Edit | CPF_Interp)
	float                                              Scene_Desaturation;                            // 0x00A4 (0x0004) [0x0000000200000001] (CPF_Edit | CPF_Interp)
	struct FVector                                     Scene_HighLights;                              // 0x00A8 (0x000C) [0x0000000200000001] (CPF_Edit | CPF_Interp)
	struct FVector                                     Scene_MidTones;                                // 0x00B4 (0x000C) [0x0000000200000001] (CPF_Edit | CPF_Interp)
	struct FVector                                     Scene_Shadows;                                 // 0x00C0 (0x000C) [0x0000000200000001] (CPF_Edit | CPF_Interp)
	float                                              Scene_InterpolationDuration;                   // 0x00CC (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FLinearColor                                RimShader_Color;                               // 0x00D0 (0x0010) [0x0000000000000001] (CPF_Edit)    
	float                                              RimShader_InterpolationDuration;               // 0x00E0 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class UTexture*                                    ColorGrading_LookupTable;                      // 0x00E4 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.SequenceOp.SeqOpOutputInputLink
// 0x0008
struct FSeqOpOutputInputLink
{
	class USequenceOp*                                 LinkedOp;                                      // 0x0000 (0x0004) [0x0000000000000000]               
	int32_t                                            InputLinkIdx;                                  // 0x0004 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.SequenceOp.SeqOpOutputLink
// 0x0030
struct FSeqOpOutputLink
{
	class TArray<struct FSeqOpOutputInputLink>         Links;                                         // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class FString                                      LinkDesc;                                      // 0x000C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	uint32_t                                           bHasImpulse : 1;                               // 0x0018 (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bDisabled : 1;                                 // 0x0018 (0x0004) [0x0000000000000000] [0x00000002] 
	uint32_t                                           bDisabledPIE : 1;                              // 0x0018 (0x0004) [0x0000000000000000] [0x00000004] 
	uint32_t                                           bDisabledPIG : 1;                              // 0x0018 (0x0004) [0x0000000000000000] [0x00000008] 
	class USequenceOp*                                 LinkedOp;                                      // 0x001C (0x0004) [0x0000000000000000]               
	float                                              ActivateDelay;                                 // 0x0020 (0x0004) [0x0000000000000000]               
	int32_t                                            DrawY;                                         // 0x0024 (0x0004) [0x0000000000000000]               
	uint32_t                                           bHidden : 1;                                   // 0x0028 (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bMoving : 1;                                   // 0x0028 (0x0004) [0x0000000800002000] [0x00000002] (CPF_Transient | CPF_EditorOnly)
	uint32_t                                           bClampedMax : 1;                               // 0x0028 (0x0004) [0x0000000800000000] [0x00000004] (CPF_EditorOnly)
	uint32_t                                           bClampedMin : 1;                               // 0x0028 (0x0004) [0x0000000800000000] [0x00000008] (CPF_EditorOnly)
	int32_t                                            OverrideDelta;                                 // 0x002C (0x0004) [0x0000000800000000] (CPF_EditorOnly)
};

// ScriptStruct Engine.SequenceOp.SeqVarLink
// 0x0048
struct FSeqVarLink
{
	class UClass*                                      ExpectedType;                                  // 0x0000 (0x0004) [0x0000000000000000]               
	class TArray<class USequenceVariable*>             LinkedVariables;                               // 0x0004 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class FString                                      LinkDesc;                                      // 0x0010 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class FName                                        LinkVar;                                       // 0x001C (0x0008) [0x0000000000000000]               
	class FName                                        PropertyName;                                  // 0x0024 (0x0008) [0x0000000000000000]               
	uint32_t                                           bWriteable : 1;                                // 0x002C (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bModifiesLinkedObject : 1;                     // 0x002C (0x0004) [0x0000000000000000] [0x00000002] 
	uint32_t                                           bHidden : 1;                                   // 0x002C (0x0004) [0x0000000000000000] [0x00000004] 
	int32_t                                            MinVars;                                       // 0x0030 (0x0004) [0x0000000000000000]               
	int32_t                                            MaxVars;                                       // 0x0034 (0x0004) [0x0000000000000000]               
	int32_t                                            DrawX;                                         // 0x0038 (0x0004) [0x0000000000000000]               
	class UProperty*                                   CachedProperty;                                // 0x003C (0x0004) [0x0000000000002002] (CPF_Const | CPF_Transient)
	uint32_t                                           bAllowAnyType : 1;                             // 0x0040 (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bMoving : 1;                                   // 0x0040 (0x0004) [0x0000000800002000] [0x00000002] (CPF_Transient | CPF_EditorOnly)
	uint32_t                                           bClampedMax : 1;                               // 0x0040 (0x0004) [0x0000000800000000] [0x00000004] (CPF_EditorOnly)
	uint32_t                                           bClampedMin : 1;                               // 0x0040 (0x0004) [0x0000000800000000] [0x00000008] (CPF_EditorOnly)
	int32_t                                            OverrideDelta;                                 // 0x0044 (0x0004) [0x0000000800000000] (CPF_EditorOnly)
};

// ScriptStruct Engine.SequenceOp.SeqEventLink
// 0x0028
struct FSeqEventLink
{
	class UClass*                                      ExpectedType;                                  // 0x0000 (0x0004) [0x0000000000000000]               
	class TArray<class USequenceEvent*>                LinkedEvents;                                  // 0x0004 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class FString                                      LinkDesc;                                      // 0x0010 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	int32_t                                            DrawX;                                         // 0x001C (0x0004) [0x0000000000000000]               
	uint32_t                                           bHidden : 1;                                   // 0x0020 (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bMoving : 1;                                   // 0x0020 (0x0004) [0x0000000800002000] [0x00000002] (CPF_Transient | CPF_EditorOnly)
	uint32_t                                           bClampedMax : 1;                               // 0x0020 (0x0004) [0x0000000800000000] [0x00000004] (CPF_EditorOnly)
	uint32_t                                           bClampedMin : 1;                               // 0x0020 (0x0004) [0x0000000800000000] [0x00000008] (CPF_EditorOnly)
	int32_t                                            OverrideDelta;                                 // 0x0024 (0x0004) [0x0000000800000000] (CPF_EditorOnly)
};

// ScriptStruct Engine.OnlineGameSearch.OnlineGameSearchParameter
// 0x000E
struct FOnlineGameSearchParameter
{
	int32_t                                            EntryId;                                       // 0x0000 (0x0004) [0x0000000000000000]               
	class FName                                        ObjectPropertyName;                            // 0x0004 (0x0008) [0x0000000000000000]               
	uint8_t                                            EntryType;                                     // 0x000C (0x0001) [0x0000000000000000]               
	uint8_t                                            ComparisonType;                                // 0x000D (0x0001) [0x0000000000000000]               
	uint8_t                                            MinStructAlignment[0x2];                         // 0x000E (0x0002) ADDED PADDING
};

// ScriptStruct Engine.OnlineGameSearch.OnlineGameSearchORClause
// 0x000C
struct FOnlineGameSearchORClause
{
	class TArray<struct FOnlineGameSearchParameter>    OrParams;                                      // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.OnlineGameSearch.OnlineGameSearchSortClause
// 0x000E
struct FOnlineGameSearchSortClause
{
	int32_t                                            EntryId;                                       // 0x0000 (0x0004) [0x0000000000000000]               
	class FName                                        ObjectPropertyName;                            // 0x0004 (0x0008) [0x0000000000000000]               
	uint8_t                                            EntryType;                                     // 0x000C (0x0001) [0x0000000000000000]               
	uint8_t                                            SortType;                                      // 0x000D (0x0001) [0x0000000000000000]               
	uint8_t                                            MinStructAlignment[0x2];                         // 0x000E (0x0002) ADDED PADDING
};

// ScriptStruct Engine.OnlineGameSearch.OnlineGameSearchQuery
// 0x0018
struct FOnlineGameSearchQuery
{
	class TArray<struct FOnlineGameSearchORClause>     OrClauses;                                     // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<struct FOnlineGameSearchSortClause>   SortClauses;                                   // 0x000C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.OnlineGameSearch.OverrideSkill
// 0x0028
struct FOverrideSkill
{
	int32_t                                            LeaderboardId;                                 // 0x0000 (0x0004) [0x0000000000000000]               
	class TArray<struct FUniqueNetId>                  Players;                                       // 0x0004 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<struct FDouble>                       Mus;                                           // 0x0010 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<struct FDouble>                       Sigmas;                                        // 0x001C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.OnlineGameSearch.NamedObjectProperty
// 0x0014
struct FNamedObjectProperty
{
	class FName                                        ObjectPropertyName;                            // 0x0000 (0x0008) [0x0000000000000000]               
	class FString                                      ObjectPropertyValue;                           // 0x0008 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.OnlineGameSearch.OnlineGameSearchResult
// 0x0008
struct FOnlineGameSearchResult
{
	class UOnlineGameSettings*                         GameSettings;                                  // 0x0000 (0x0004) [0x0000000000000002] (CPF_Const)   
	struct FPointer                                    PlatformData;                                  // 0x0004 (0x0004) [0x0000000000001002] (CPF_Const | CPF_Native)
};

// ScriptStruct Engine.PlayerController.DebugTextInfo
// 0x0038
struct FDebugTextInfo
{
	class AActor*                                      SrcActor;                                      // 0x0000 (0x0004) [0x0000000000000000]               
	struct FVector                                     SrcActorOffset;                                // 0x0004 (0x000C) [0x0000000000000000]               
	struct FVector                                     SrcActorDesiredOffset;                         // 0x0010 (0x000C) [0x0000000000000000]               
	class FString                                      DebugText;                                     // 0x001C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	float                                              TimeRemaining;                                 // 0x0028 (0x0004) [0x0000000000002000] (CPF_Transient)
	float                                              Duration;                                      // 0x002C (0x0004) [0x0000000000000000]               
	struct FColor                                      TextColor;                                     // 0x0030 (0x0004) [0x0000000000000000]               
	uint32_t                                           bAbsoluteLocation : 1;                         // 0x0034 (0x0004) [0x0000000000000000] [0x00000001] 
};

// ScriptStruct Engine.SkeletalMeshComponent.BonePair
// 0x0010
struct FBonePair
{
	class FName                                        Bones[2];                                      // 0x0000 (0x0010) [0x0000000000000000]               
};

// ScriptStruct Engine.SkeletalMeshComponent.Attachment
// 0x0030
struct FAttachment
{
	class UActorComponent*                             Component;                                     // 0x0000 (0x0004) [0x0000000004080009] (CPF_Edit | CPF_ExportObject | CPF_Component | CPF_EditInline)
	class FName                                        BoneName;                                      // 0x0004 (0x0008) [0x0000000000000001] (CPF_Edit)    
	struct FVector                                     RelativeLocation;                              // 0x000C (0x000C) [0x0000000000000001] (CPF_Edit)    
	struct FRotator                                    RelativeRotation;                              // 0x0018 (0x000C) [0x0000000000000001] (CPF_Edit)    
	struct FVector                                     RelativeScale;                                 // 0x0024 (0x000C) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.AnimNodeBlendBase.AnimBlendChild
// 0x0048
struct FAnimBlendChild
{
	class FName                                        Name;                                          // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	class UAnimNode*                                   Anim;                                          // 0x0008 (0x0004) [0x0000000004400008] (CPF_ExportObject | CPF_NeedCtorLink | CPF_EditInline)
	float                                              Weight;                                        // 0x000C (0x0004) [0x0000000000000000]               
	float                                              TotalWeight;                                   // 0x0010 (0x0004) [0x0000000000000002] (CPF_Const)   
	float                                              BlendWeight;                                   // 0x0014 (0x0004) [0x0000000000002002] (CPF_Const | CPF_Transient)
	int32_t                                            bHasRootMotion;                                // 0x0018 (0x0004) [0x0000000000002002] (CPF_Const | CPF_Transient)
	uint8_t                                            UnknownData00[0x4];                              // 0x001C (0x0004) MISSED OFFSET
	struct FBoneAtom                                   RootMotion;                                    // 0x0020 (0x0020) [0x0000000000002002] (CPF_Const | CPF_Transient)
	uint32_t                                           bMirrorSkeleton : 1;                           // 0x0040 (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bIsAdditive : 1;                               // 0x0040 (0x0004) [0x0000000000000000] [0x00000002] 
	int32_t                                            DrawY;                                         // 0x0044 (0x0004) [0x0000000800000000] (CPF_EditorOnly)
	uint8_t                                            MinStructAlignment[0x8];                         // 0x0048 (0x0008) ADDED PADDING
};

// ScriptStruct Engine.SkeletalMeshComponent.ActiveMorph
// 0x0008
struct FActiveMorph
{
	class UMorphTarget*                                Target;                                        // 0x0000 (0x0004) [0x0000000000000000]               
	float                                              Weight;                                        // 0x0004 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.PlayerController.ClientAdjustment
// 0x0031
struct FClientAdjustment
{
	float                                              TimeStamp;                                     // 0x0000 (0x0004) [0x0000000000000000]               
	uint8_t                                            newPhysics;                                    // 0x0004 (0x0001) [0x0000000000000000]               
	uint8_t                                            UnknownData00[0x3];                              // 0x0005 (0x0003) MISSED OFFSET
	struct FVector                                     NewLoc;                                        // 0x0008 (0x000C) [0x0000000000000000]               
	struct FVector                                     NewVel;                                        // 0x0014 (0x000C) [0x0000000000000000]               
	class AActor*                                      NewBase;                                       // 0x0020 (0x0004) [0x0000000000000000]               
	struct FVector                                     NewFloor;                                      // 0x0024 (0x000C) [0x0000000000000000]               
	uint8_t                                            bAckGoodMove;                                  // 0x0030 (0x0001) [0x0000000000000000]               
	uint8_t                                            MinStructAlignment[0x3];                         // 0x0031 (0x0003) ADDED PADDING
};

// ScriptStruct Engine.HUD.KismetDrawTextInfo
// 0x0028
struct FKismetDrawTextInfo
{
	class FString                                      MessageText;                                   // 0x0000 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class UFont*                                       MessageFont;                                   // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FVector2D                                   MessageFontScale;                              // 0x0010 (0x0008) [0x0000000000000001] (CPF_Edit)    
	struct FVector2D                                   MessageOffset;                                 // 0x0018 (0x0008) [0x0000000000000001] (CPF_Edit)    
	struct FColor                                      MessageColor;                                  // 0x0020 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              MessageEndTime;                                // 0x0024 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.HUD.ConsoleMessage
// 0x0018
struct FConsoleMessage
{
	class FString                                      Text;                                          // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	struct FColor                                      TextColor;                                     // 0x000C (0x0004) [0x0000000000000000]               
	float                                              MessageLife;                                   // 0x0010 (0x0004) [0x0000000000000000]               
	class APlayerReplicationInfo*                      PRI;                                           // 0x0014 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.HUD.HudLocalizedMessage
// 0x0040
struct FHudLocalizedMessage
{
	class UClass*                                      Message;                                       // 0x0000 (0x0004) [0x0000000000000000]               
	class FString                                      StringMessage;                                 // 0x0004 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	int32_t                                            Switch;                                        // 0x0010 (0x0004) [0x0000000000000000]               
	float                                              EndOfLife;                                     // 0x0014 (0x0004) [0x0000000000000000]               
	float                                              Lifetime;                                      // 0x0018 (0x0004) [0x0000000000000000]               
	float                                              PosY;                                          // 0x001C (0x0004) [0x0000000000000000]               
	struct FColor                                      DrawColor;                                     // 0x0020 (0x0004) [0x0000000000000000]               
	int32_t                                            FontSize;                                      // 0x0024 (0x0004) [0x0000000000000000]               
	class UFont*                                       StringFont;                                    // 0x0028 (0x0004) [0x0000000000000000]               
	float                                              DX;                                            // 0x002C (0x0004) [0x0000000000000000]               
	float                                              DY;                                            // 0x0030 (0x0004) [0x0000000000000000]               
	uint32_t                                           Drawn : 1;                                     // 0x0034 (0x0004) [0x0000000000000000] [0x00000001] 
	int32_t                                            Count;                                         // 0x0038 (0x0004) [0x0000000000000000]               
	class UObject*                                     OptionalObject;                                // 0x003C (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.PlayerReplicationInfo.AutomatedTestingDatum
// 0x0008
struct FAutomatedTestingDatum
{
	int32_t                                            NumberOfMatchesPlayed;                         // 0x0000 (0x0004) [0x0000000000000000]               
	int32_t                                            NumMapListCyclesDone;                          // 0x0004 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.PlayerController.InputEntry
// 0x000D
struct FInputEntry
{
	uint8_t                                            Type;                                          // 0x0000 (0x0001) [0x0000000000000000]               
	uint8_t                                            UnknownData00[0x3];                              // 0x0001 (0x0003) MISSED OFFSET
	float                                              Value;                                         // 0x0004 (0x0004) [0x0000000000000000]               
	float                                              TimeDelta;                                     // 0x0008 (0x0004) [0x0000000000000000]               
	uint8_t                                            Action;                                        // 0x000C (0x0001) [0x0000000000000000]               
	uint8_t                                            MinStructAlignment[0x3];                         // 0x000D (0x0003) ADDED PADDING
};

// ScriptStruct Engine.PlayerController.InputMatchRequest
// 0x003C
struct FInputMatchRequest
{
	class TArray<struct FInputEntry>                   Inputs;                                        // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class AActor*                                      MatchActor;                                    // 0x000C (0x0004) [0x0000000000000000]               
	class FName                                        MatchFuncName;                                 // 0x0010 (0x0008) [0x0000000000000000]               
	struct FScriptDelegate                             MatchDelegate;                                 // 0x0018 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class FName                                        FailedFuncName;                                // 0x0024 (0x0008) [0x0000000000000000]               
	class FName                                        RequestName;                                   // 0x002C (0x0008) [0x0000000000000000]               
	int32_t                                            MatchIdx;                                      // 0x0034 (0x0004) [0x0000000000002000] (CPF_Transient)
	float                                              LastMatchTime;                                 // 0x0038 (0x0004) [0x0000000000002000] (CPF_Transient)
};

// ScriptStruct Engine.NavigationPoint.DebugNavCost
// 0x0010
struct FDebugNavCost
{
	class FString                                      Desc;                                          // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	int32_t                                            Cost;                                          // 0x000C (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.NavigationPoint.NavigationOctreeObject
// 0x0031
struct FNavigationOctreeObject
{
	struct FBox                                        BoundingBox;                                   // 0x0000 (0x001C) [0x0000000000000000]               
	struct FVector                                     BoxCenter;                                     // 0x001C (0x000C) [0x0000000000000000]               
	struct FPointer                                    OctreeNode;                                    // 0x0028 (0x0004) [0x0000000000003002] (CPF_Const | CPF_Native | CPF_Transient)
	class UObject*                                     Owner;                                         // 0x002C (0x0004) [0x0000000000800002] (CPF_Const | CPF_NoExport)
	uint8_t                                            OwnerType;                                     // 0x0030 (0x0001) [0x0000000000800002] (CPF_Const | CPF_NoExport)
	uint8_t                                            MinStructAlignment[0x3];                         // 0x0031 (0x0003) ADDED PADDING
};

// ScriptStruct Engine.Pylon.PolyReference
// 0x0018
struct FPolyReference
{
	struct FActorReference                             OwningPylon;                                   // 0x0000 (0x0014) [0x0000000000000000]               
	int32_t                                            PolyId;                                        // 0x0014 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.GameplayEvents.PlayerInformationNew
// 0x001C
struct FPlayerInformationNew
{
	class FString                                      ControllerName;                                // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class FString                                      PlayerName;                                    // 0x000C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	uint32_t                                           bIsBot : 1;                                    // 0x0018 (0x0004) [0x0000000000000000] [0x00000001] 
};

// ScriptStruct Engine.GameplayEvents.TeamInformation
// 0x0018
struct FTeamInformation
{
	int32_t                                            TeamIndex;                                     // 0x0000 (0x0004) [0x0000000000000000]               
	class FString                                      TeamName;                                      // 0x0004 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	struct FColor                                      TeamColor;                                     // 0x0010 (0x0004) [0x0000000000000000]               
	int32_t                                            MaxSize;                                       // 0x0014 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.GameplayEvents.GameplayEventMetaData
// 0x0014
struct FGameplayEventMetaData
{
	int32_t                                            EventID;                                       // 0x0000 (0x0004) [0x0000000000000002] (CPF_Const)   
	class FName                                        EventName;                                     // 0x0004 (0x0008) [0x0000000000000002] (CPF_Const)   
	uint8_t                                            MappingType;                                   // 0x000C (0x0001) [0x0000000000000002] (CPF_Const)   
	uint8_t                                            UnknownData00[0x3];                              // 0x000D (0x0003) MISSED OFFSET
	int32_t                                            MaxValue;                                      // 0x0010 (0x0004) [0x0000000000000002] (CPF_Const)   
};

// ScriptStruct Engine.GameplayEvents.WeaponClassEventData
// 0x000C
struct FWeaponClassEventData
{
	class FString                                      WeaponClassName;                               // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.GameplayEvents.DamageClassEventData
// 0x000C
struct FDamageClassEventData
{
	class FString                                      DamageClassName;                               // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.GameplayEvents.ProjectileClassEventData
// 0x000C
struct FProjectileClassEventData
{
	class FString                                      ProjectileClassName;                           // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.GameplayEvents.PawnClassEventData
// 0x000C
struct FPawnClassEventData
{
	class FString                                      PawnClassName;                                 // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.GameplayEvents.GameplayEventsHeader
// 0x0018
struct FGameplayEventsHeader
{
	int32_t                                            EngineVersion;                                 // 0x0000 (0x0004) [0x0000000000000002] (CPF_Const)   
	int32_t                                            StatsWriterVersion;                            // 0x0004 (0x0004) [0x0000000000000002] (CPF_Const)   
	int32_t                                            StreamOffset;                                  // 0x0008 (0x0004) [0x0000000000000002] (CPF_Const)   
	int32_t                                            FooterOffset;                                  // 0x000C (0x0004) [0x0000000000000002] (CPF_Const)   
	int32_t                                            TotalStreamSize;                               // 0x0010 (0x0004) [0x0000000000000002] (CPF_Const)   
	int32_t                                            FileSize;                                      // 0x0014 (0x0004) [0x0000000000000002] (CPF_Const)   
};

// ScriptStruct Engine.GameplayEvents.GameSessionInformation
// 0x005C
struct FGameSessionInformation
{
	int32_t                                            AppTitleID;                                    // 0x0000 (0x0004) [0x0000000000000000]               
	int32_t                                            PlatformType;                                  // 0x0004 (0x0004) [0x0000000000000000]               
	class FString                                      Language;                                      // 0x0008 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class FString                                      GameplaySessionTimestamp;                      // 0x0014 (0x000C) [0x0000000000400002] (CPF_Const | CPF_NeedCtorLink)
	float                                              GameplaySessionStartTime;                      // 0x0020 (0x0004) [0x0000000000000002] (CPF_Const)   
	float                                              GameplaySessionEndTime;                        // 0x0024 (0x0004) [0x0000000000000002] (CPF_Const)   
	uint32_t                                           bGameplaySessionInProgress : 1;                // 0x0028 (0x0004) [0x0000000000000002] [0x00000001] (CPF_Const)
	class FString                                      GameplaySessionID;                             // 0x002C (0x000C) [0x0000000000400002] (CPF_Const | CPF_NeedCtorLink)
	class FString                                      GameClassName;                                 // 0x0038 (0x000C) [0x0000000000400002] (CPF_Const | CPF_NeedCtorLink)
	class FString                                      MapName;                                       // 0x0044 (0x000C) [0x0000000000400002] (CPF_Const | CPF_NeedCtorLink)
	class FString                                      MapURL;                                        // 0x0050 (0x000C) [0x0000000000400002] (CPF_Const | CPF_NeedCtorLink)
};

// ScriptStruct Engine.AudioComponent.AudioComponentParam
// 0x0010
struct FAudioComponentParam
{
	class FName                                        ParamName;                                     // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	float                                              FloatParam;                                    // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class USoundNodeWave*                              WaveParam;                                     // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.EngineTypes.SubtitleCue
// 0x0010
struct FSubtitleCue
{
	class FString                                      Text;                                          // 0x0000 (0x000C) [0x0000000000408003] (CPF_Edit | CPF_Const | CPF_Localized | CPF_NeedCtorLink)
	float                                              Time;                                          // 0x000C (0x0004) [0x0000000000008003] (CPF_Edit | CPF_Const | CPF_Localized)
};

// ScriptStruct Engine.SoundCue.SoundNodeEditorData
// 0x0008
struct FSoundNodeEditorData
{
	int32_t                                            NodePosX;                                      // 0x0000 (0x0004) [0x0000000000001002] (CPF_Const | CPF_Native)
	int32_t                                            NodePosY;                                      // 0x0004 (0x0004) [0x0000000000001002] (CPF_Const | CPF_Native)
};

// ScriptStruct Engine.SoundNodeAmbient.AmbientSoundSlot
// 0x0010
struct FAmbientSoundSlot
{
	class USoundNodeWave*                              Wave;                                          // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              PitchScale;                                    // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              VolumeScale;                                   // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              Weight;                                        // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.AmbientSoundSimpleToggleable.CheckpointRecord
// 0x0004
struct AAmbientSoundSimpleToggleable_FCheckpointRecord
{
	uint32_t                                           bCurrentlyPlaying : 1;                         // 0x0000 (0x0004) [0x0000000000000000] [0x00000001] 
};

// ScriptStruct Engine.AnimSequence.CompressedTrack
// 0x0030
struct FCompressedTrack
{
	class TArray<uint8_t>                              ByteStream;                                    // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<float>                                Times;                                         // 0x000C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	float                                              Mins[3];                                       // 0x0018 (0x000C) [0x0000000000000000]               
	float                                              Ranges[3];                                     // 0x0024 (0x000C) [0x0000000000000000]               
};

// ScriptStruct Engine.AnimSequence.NativeStructGuy
// 0x000C
struct FNativeStructGuy
{
	struct FPointer                                    dummydata0;                                    // 0x0000 (0x0004) [0x0000000000000000]               
	int32_t                                            dummyint1;                                     // 0x0004 (0x0004) [0x0000000000000000]               
	int32_t                                            dummyint2;                                     // 0x0008 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.AnimSequence.AnimTag
// 0x0018
struct FAnimTag
{
	class FString                                      Tag;                                           // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<class FString>                        Contains;                                      // 0x000C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.AnimSequence.CurveTrack
// 0x0014
struct FCurveTrack
{
	class FName                                        CurveName;                                     // 0x0000 (0x0008) [0x0000000000000000]               
	class TArray<float>                                CurveWeights;                                  // 0x0008 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.AnimSequence.RotationTrack
// 0x0018
struct FRotationTrack
{
	class TArray<struct FQuat>                         RotKeys;                                       // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<float>                                Times;                                         // 0x000C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.AnimSequence.TranslationTrack
// 0x0018
struct FTranslationTrack
{
	class TArray<struct FVector>                       PosKeys;                                       // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<float>                                Times;                                         // 0x000C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.AnimSequence.TimeModifier
// 0x0008
struct FTimeModifier
{
	float                                              Time;                                          // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              TargetStrength;                                // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.AnimSequence.SkelControlModifier
// 0x0014
struct FSkelControlModifier
{
	class FName                                        SkelControlName;                               // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	class TArray<struct FTimeModifier>                 Modifiers;                                     // 0x0008 (0x000C) [0x0000000004400001] (CPF_Edit | CPF_NeedCtorLink | CPF_EditInline)
};

// ScriptStruct Engine.AnimSequence.AnimNotifyEvent
// 0x0014
struct FAnimNotifyEvent
{
	float                                              Time;                                          // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class UAnimNotify*                                 Notify;                                        // 0x0004 (0x0004) [0x0000000004400009] (CPF_Edit | CPF_ExportObject | CPF_NeedCtorLink | CPF_EditInline)
	class FName                                        Comment;                                       // 0x0008 (0x0008) [0x0000000000000001] (CPF_Edit)    
	float                                              Duration;                                      // 0x0010 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.AnimSequence.RawAnimSequenceTrack
// 0x0018
struct FRawAnimSequenceTrack
{
	class TArray<struct FVector>                       PosKeys;                                       // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<struct FQuat>                         RotKeys;                                       // 0x000C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.AnimNode.CurveKey
// 0x000C
struct FCurveKey
{
	class FName                                        CurveName;                                     // 0x0000 (0x0008) [0x0000000000000000]               
	float                                              Weight;                                        // 0x0008 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.AnimNode.BoneTransform
// 0x0000
struct FBoneTransform
{
};

// ScriptStruct Engine.AnimNode_MultiBlendPerBone.WeightNodeRule
// 0x0018
struct FWeightNodeRule
{
	class FName                                        NodeName;                                      // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	class UAnimNodeBlendBase*                          CachedNode;                                    // 0x0008 (0x0004) [0x0000000000000000]               
	class UAnimNodeSlot*                               CachedSlotNode;                                // 0x000C (0x0004) [0x0000000000000000]               
	uint8_t                                            WeightCheck;                                   // 0x0010 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            UnknownData00[0x3];                              // 0x0011 (0x0003) MISSED OFFSET
	int32_t                                            ChildIndex;                                    // 0x0014 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.AnimNode_MultiBlendPerBone.WeightRule
// 0x0030
struct FWeightRule
{
	struct FWeightNodeRule                             FirstNode;                                     // 0x0000 (0x0018) [0x0000000000000001] (CPF_Edit)    
	struct FWeightNodeRule                             SecondNode;                                    // 0x0018 (0x0018) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.AnimNode_MultiBlendPerBone.BranchInfo
// 0x000C
struct FBranchInfo
{
	class FName                                        BoneName;                                      // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	float                                              PerBoneWeightIncrease;                         // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.AnimNode_MultiBlendPerBone.PerBoneMaskInfo
// 0x0040
struct FPerBoneMaskInfo
{
	class TArray<struct FBranchInfo>                   BranchList;                                    // 0x0000 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	float                                              DesiredWeight;                                 // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              BlendTimeToGo;                                 // 0x0010 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class TArray<struct FWeightRule>                   WeightRuleList;                                // 0x0014 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	uint32_t                                           bWeightBasedOnNodeRules : 1;                   // 0x0020 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bDisableForNonLocalHumanPlayers : 1;           // 0x0020 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint32_t                                           bPendingBlend : 1;                             // 0x0020 (0x0004) [0x0000000000002000] [0x00000004] (CPF_Transient)
	class TArray<float>                                PerBoneWeights;                                // 0x0024 (0x000C) [0x0000000000402000] (CPF_Transient | CPF_NeedCtorLink)
	class TArray<uint8_t>                              TransformReqBone;                              // 0x0030 (0x000C) [0x0000000000402000] (CPF_Transient | CPF_NeedCtorLink)
	int32_t                                            TransformReqBoneIndex;                         // 0x003C (0x0004) [0x0000000000002000] (CPF_Transient)
};

// ScriptStruct Engine.AnimNodeAimOffset.AimTransform
// 0x001C
struct FAimTransform
{
	struct FQuat                                       Quaternion;                                    // 0x0000 (0x0010) [0x0000000000000001] (CPF_Edit)    
	struct FVector                                     Translation;                                   // 0x0010 (0x000C) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            MinStructAlignment[0x4];                         // 0x001C (0x0004) ADDED PADDING
};

// ScriptStruct Engine.AnimNodeAimOffset.AimComponent
// 0x0130
struct FAimComponent
{
	class FName                                        BoneName;                                      // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            UnknownData00[0x8];                              // 0x0008 (0x0008) MISSED OFFSET
	struct FAimTransform                               LU;                                            // 0x0010 (0x0020) [0x0000000000000001] (CPF_Edit)    
	struct FAimTransform                               LC;                                            // 0x0030 (0x0020) [0x0000000000000001] (CPF_Edit)    
	struct FAimTransform                               LD;                                            // 0x0050 (0x0020) [0x0000000000000001] (CPF_Edit)    
	struct FAimTransform                               CU;                                            // 0x0070 (0x0020) [0x0000000000000001] (CPF_Edit)    
	struct FAimTransform                               CC;                                            // 0x0090 (0x0020) [0x0000000000000001] (CPF_Edit)    
	struct FAimTransform                               CD;                                            // 0x00B0 (0x0020) [0x0000000000000001] (CPF_Edit)    
	struct FAimTransform                               RU;                                            // 0x00D0 (0x0020) [0x0000000000000001] (CPF_Edit)    
	struct FAimTransform                               RC;                                            // 0x00F0 (0x0020) [0x0000000000000001] (CPF_Edit)    
	struct FAimTransform                               RD;                                            // 0x0110 (0x0020) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.AnimNodeAimOffset.AimOffsetProfile
// 0x006C
struct FAimOffsetProfile
{
	class FName                                        ProfileName;                                   // 0x0000 (0x0008) [0x0000000000020003] (CPF_Edit | CPF_Const | CPF_EditConst)
	struct FVector2D                                   HorizontalRange;                               // 0x0008 (0x0008) [0x0000000000000001] (CPF_Edit)    
	struct FVector2D                                   VerticalRange;                                 // 0x0010 (0x0008) [0x0000000000000001] (CPF_Edit)    
	class TArray<struct FAimComponent>                 AimComponents;                                 // 0x0018 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class FName                                        AnimName_LU;                                   // 0x0024 (0x0008) [0x0000000000000001] (CPF_Edit)    
	class FName                                        AnimName_LC;                                   // 0x002C (0x0008) [0x0000000000000001] (CPF_Edit)    
	class FName                                        AnimName_LD;                                   // 0x0034 (0x0008) [0x0000000000000001] (CPF_Edit)    
	class FName                                        AnimName_CU;                                   // 0x003C (0x0008) [0x0000000000000001] (CPF_Edit)    
	class FName                                        AnimName_CC;                                   // 0x0044 (0x0008) [0x0000000000000001] (CPF_Edit)    
	class FName                                        AnimName_CD;                                   // 0x004C (0x0008) [0x0000000000000001] (CPF_Edit)    
	class FName                                        AnimName_RU;                                   // 0x0054 (0x0008) [0x0000000000000001] (CPF_Edit)    
	class FName                                        AnimName_RC;                                   // 0x005C (0x0008) [0x0000000000000001] (CPF_Edit)    
	class FName                                        AnimName_RD;                                   // 0x0064 (0x0008) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.AnimNodeBlendMultiBone.ChildBoneBlendInfo
// 0x0030
struct FChildBoneBlendInfo
{
	class TArray<float>                                TargetPerBoneWeight;                           // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class FName                                        InitTargetStartBone;                           // 0x000C (0x0008) [0x0000000000000001] (CPF_Edit)    
	float                                              InitPerBoneIncrease;                           // 0x0014 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class FName                                        OldStartBone;                                  // 0x0018 (0x0008) [0x0000000000000002] (CPF_Const)   
	float                                              OldBoneIncrease;                               // 0x0020 (0x0004) [0x0000000000000002] (CPF_Const)   
	class TArray<uint8_t>                              TargetRequiredBones;                           // 0x0024 (0x000C) [0x0000000000402000] (CPF_Transient | CPF_NeedCtorLink)
};

// ScriptStruct Engine.AnimNodeRandom.RandomAnimInfo
// 0x0019
struct FRandomAnimInfo
{
	float                                              Chance;                                        // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            LoopCountMin;                                  // 0x0004 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            LoopCountMax;                                  // 0x0005 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            UnknownData00[0x2];                              // 0x0006 (0x0002) MISSED OFFSET
	float                                              BlendInTime;                                   // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FVector2D                                   PlayRateRange;                                 // 0x000C (0x0008) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bStillFrame : 1;                               // 0x0014 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint8_t                                            LoopCount;                                     // 0x0018 (0x0001) [0x0000000000002000] (CPF_Transient)
	uint8_t                                            MinStructAlignment[0x3];                         // 0x0019 (0x0003) ADDED PADDING
};

// ScriptStruct Engine.AnimNodeSequenceBlendBase.AnimInfo
// 0x0010
struct FAnimInfo
{
	class FName                                        AnimSeqName;                                   // 0x0000 (0x0008) [0x0000000000000002] (CPF_Const)   
	class UAnimSequence*                               AnimSeq;                                       // 0x0008 (0x0004) [0x0000000000002002] (CPF_Const | CPF_Transient)
	int32_t                                            AnimLinkupIndex;                               // 0x000C (0x0004) [0x0000000000002002] (CPF_Const | CPF_Transient)
};

// ScriptStruct Engine.AnimNodeSequenceBlendBase.AnimBlendInfo
// 0x001C
struct FAnimBlendInfo
{
	class FName                                        AnimName;                                      // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	struct FAnimInfo                                   AnimInfo;                                      // 0x0008 (0x0010) [0x0000000000000000]               
	float                                              Weight;                                        // 0x0018 (0x0004) [0x0000000000002000] (CPF_Transient)
};

// ScriptStruct Engine.AnimNodeSynch.SynchGroup
// 0x0020
struct FSynchGroup
{
	class TArray<class UAnimNodeSequence*>             SeqNodes;                                      // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class UAnimNodeSequence*                           MasterNode;                                    // 0x000C (0x0004) [0x0000000000002000] (CPF_Transient)
	class FName                                        GroupName;                                     // 0x0010 (0x0008) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bFireSlaveNotifies : 1;                        // 0x0018 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	float                                              RateScale;                                     // 0x001C (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.Pawn.FacialFaceFXAnimInfo
// 0x0020
struct FFacialFaceFXAnimInfo
{
	int32_t                                            FacialAnimSetIndex;                            // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class FString                                      FacialAnimName;                                // 0x0004 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class FString                                      FacialAnimGroupName;                           // 0x0010 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class USoundCue*                                   FacialSoundCue;                                // 0x001C (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.AnimTree.AnimGroup
// 0x0024
struct FAnimGroup
{
	class TArray<class UAnimNodeSequence*>             SeqNodes;                                      // 0x0000 (0x000C) [0x0000000000402002] (CPF_Const | CPF_Transient | CPF_NeedCtorLink)
	class UAnimNodeSequence*                           SynchMaster;                                   // 0x000C (0x0004) [0x0000000000002002] (CPF_Const | CPF_Transient)
	class UAnimNodeSequence*                           NotifyMaster;                                  // 0x0010 (0x0004) [0x0000000000002002] (CPF_Const | CPF_Transient)
	class FName                                        GroupName;                                     // 0x0014 (0x0008) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              RateScale;                                     // 0x001C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              SynchPctPosition;                              // 0x0020 (0x0004) [0x0000000000000002] (CPF_Const)   
};

// ScriptStruct Engine.Pawn.ScalarParameterInterpStruct
// 0x0014
struct FScalarParameterInterpStruct
{
	class FName                                        ParameterName;                                 // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	float                                              ParameterValue;                                // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              InterpTime;                                    // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              WarmupTime;                                    // 0x0010 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.EngineTypes.RootMotionCurve
// 0x001C
struct FRootMotionCurve
{
	class FName                                        AnimName;                                      // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	struct FInterpCurveVector                          Curve;                                         // 0x0008 (0x0010) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	float                                              MaxCurveTime;                                  // 0x0018 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.EngineTypes.SwarmDebugOptions
// 0x0004
struct FSwarmDebugOptions
{
	uint32_t                                           bDistributionEnabled : 1;                      // 0x0000 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bForceContentExport : 1;                       // 0x0000 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint32_t                                           bInitialized : 1;                              // 0x0000 (0x0004) [0x0000000000000000] [0x00000004] 
};

// ScriptStruct Engine.EngineTypes.LocalizedSubtitle
// 0x001C
struct FLocalizedSubtitle
{
	class FString                                      LanguageExt;                                   // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<struct FSubtitleCue>                  Subtitles;                                     // 0x000C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	uint32_t                                           bMature : 1;                                   // 0x0018 (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bManualWordWrap : 1;                           // 0x0018 (0x0004) [0x0000000000000000] [0x00000002] 
};

// ScriptStruct Engine.EngineTypes.DominantShadowInfo
// 0x00A4
struct FDominantShadowInfo
{
	struct FMatrix                                     WorldToLight;                                  // 0x0000 (0x0040) [0x0000000000000000]               
	struct FMatrix                                     LightToWorld;                                  // 0x0040 (0x0040) [0x0000000000000000]               
	struct FBox                                        LightSpaceImportanceBounds;                    // 0x0080 (0x001C) [0x0000000000000000]               
	int32_t                                            ShadowMapSizeX;                                // 0x009C (0x0004) [0x0000000000000000]               
	int32_t                                            ShadowMapSizeY;                                // 0x00A0 (0x0004) [0x0000000000000000]               
	uint8_t                                            MinStructAlignment[0xC];                         // 0x00A4 (0x000C) ADDED PADDING
};

// ScriptStruct Engine.EngineTypes.LightmassLightSettings
// 0x000C
struct FLightmassLightSettings
{
	float                                              IndirectLightingScale;                         // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              IndirectLightingSaturation;                    // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              ShadowExponent;                                // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.EngineTypes.LightmassPointLightSettings
// 0x0004 (0x000C - 0x0010)
struct FLightmassPointLightSettings : FLightmassLightSettings
{
	float                                              LightSourceRadius;                             // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.EngineTypes.LightmassDirectionalLightSettings
// 0x0004 (0x000C - 0x0010)
struct FLightmassDirectionalLightSettings : FLightmassLightSettings
{
	float                                              LightSourceAngle;                              // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.EngineTypes.LightmassPrimitiveSettings
// 0x001C
struct FLightmassPrimitiveSettings
{
	uint32_t                                           bUseTwoSidedLighting : 1;                      // 0x0000 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bShadowIndirectOnly : 1;                       // 0x0000 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint32_t                                           bUseEmissiveForStaticLighting : 1;             // 0x0000 (0x0004) [0x0000000000000001] [0x00000004] (CPF_Edit)
	float                                              EmissiveLightFalloffExponent;                  // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              EmissiveLightExplicitInfluenceRadius;          // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              EmissiveBoost;                                 // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              DiffuseBoost;                                  // 0x0010 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              SpecularBoost;                                 // 0x0014 (0x0004) [0x0000000000000000]               
	float                                              FullyOccludedSamplesFraction;                  // 0x0018 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.EngineTypes.LightmassDebugOptions
// 0x0014
struct FLightmassDebugOptions
{
	uint32_t                                           bDebugMode : 1;                                // 0x0000 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bStatsEnabled : 1;                             // 0x0000 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint32_t                                           bGatherBSPSurfacesAcrossComponents : 1;        // 0x0000 (0x0004) [0x0000000000000001] [0x00000004] (CPF_Edit)
	float                                              CoplanarTolerance;                             // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bUseDeterministicLighting : 1;                 // 0x0008 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bUseImmediateImport : 1;                       // 0x0008 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint32_t                                           bImmediateProcessMappings : 1;                 // 0x0008 (0x0004) [0x0000000000000001] [0x00000004] (CPF_Edit)
	uint32_t                                           bSortMappings : 1;                             // 0x0008 (0x0004) [0x0000000000000001] [0x00000008] (CPF_Edit)
	uint32_t                                           bDumpBinaryFiles : 1;                          // 0x0008 (0x0004) [0x0000000000000001] [0x00000010] (CPF_Edit)
	uint32_t                                           bDebugMaterials : 1;                           // 0x0008 (0x0004) [0x0000000000000001] [0x00000020] (CPF_Edit)
	uint32_t                                           bPadMappings : 1;                              // 0x0008 (0x0004) [0x0000000000000001] [0x00000040] (CPF_Edit)
	uint32_t                                           bDebugPaddings : 1;                            // 0x0008 (0x0004) [0x0000000000000001] [0x00000080] (CPF_Edit)
	uint32_t                                           bOnlyCalcDebugTexelMappings : 1;               // 0x0008 (0x0004) [0x0000000000000001] [0x00000100] (CPF_Edit)
	uint32_t                                           bUseRandomColors : 1;                          // 0x0008 (0x0004) [0x0000000000000001] [0x00000200] (CPF_Edit)
	uint32_t                                           bColorBordersGreen : 1;                        // 0x0008 (0x0004) [0x0000000000000001] [0x00000400] (CPF_Edit)
	uint32_t                                           bColorByExecutionTime : 1;                     // 0x0008 (0x0004) [0x0000000000000001] [0x00000800] (CPF_Edit)
	float                                              ExecutionTimeDivisor;                          // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bInitialized : 1;                              // 0x0010 (0x0004) [0x0000000000000000] [0x00000001] 
};

// ScriptStruct Engine.AnimNotify_Trails.TrailSocketSamplePoint
// 0x0018
struct FTrailSocketSamplePoint
{
	struct FVector                                     Position;                                      // 0x0000 (0x000C) [0x0000000000000000]               
	struct FVector                                     Velocity;                                      // 0x000C (0x000C) [0x0000000000000000]               
};

// ScriptStruct Engine.AnimNotify_Trails.TrailSamplePoint
// 0x004C
struct FTrailSamplePoint
{
	float                                              RelativeTime;                                  // 0x0000 (0x0004) [0x0000000000000000]               
	struct FTrailSocketSamplePoint                     FirstEdgeSample;                               // 0x0004 (0x0018) [0x0000000000000000]               
	struct FTrailSocketSamplePoint                     SecondEdgeSample;                              // 0x001C (0x0018) [0x0000000000000000]               
	struct FTrailSocketSamplePoint                     ControlPointSample;                            // 0x0034 (0x0018) [0x0000000000000000]               
};

// ScriptStruct Engine.AnimNotify_Trails.TrailSample
// 0x0028
struct FTrailSample
{
	float                                              RelativeTime;                                  // 0x0000 (0x0004) [0x0000000000000000]               
	struct FVector                                     FirstEdgeSample;                               // 0x0004 (0x000C) [0x0000000000000000]               
	struct FVector                                     SecondEdgeSample;                              // 0x0010 (0x000C) [0x0000000000000000]               
	struct FVector                                     ControlPointSample;                            // 0x001C (0x000C) [0x0000000000000000]               
};

// ScriptStruct Engine.AnimSet.AnimSetMeshLinkup
// 0x002C
struct FAnimSetMeshLinkup
{
	struct FQWord                                      SkelMeshLinkupRUID;                            // 0x0000 (0x0008) [0x0000000000000000]               
	class TArray<int32_t>                              BoneToTrackTable;                              // 0x0008 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<uint8_t>                              BoneUseAnimTranslation;                        // 0x0014 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<uint8_t>                              ForceUseMeshTranslation;                       // 0x0020 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.AnimTree.SkelControlListHead
// 0x0010
struct FSkelControlListHead
{
	class FName                                        BoneName;                                      // 0x0000 (0x0008) [0x0000000000000000]               
	class USkelControlBase*                            ControlHead;                                   // 0x0008 (0x0004) [0x0000000004400008] (CPF_ExportObject | CPF_NeedCtorLink | CPF_EditInline)
	int32_t                                            DrawY;                                         // 0x000C (0x0004) [0x0000000800000000] (CPF_EditorOnly)
};

// ScriptStruct Engine.AnimTree.PreviewSkelMeshStruct
// 0x0018
struct FPreviewSkelMeshStruct
{
	class FName                                        DisplayName;                                   // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	class USkeletalMesh*                               PreviewSkelMesh;                               // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class TArray<class UMorphTargetSet*>               PreviewMorphSets;                              // 0x000C (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
};

// ScriptStruct Engine.AnimTree.PreviewSocketStruct
// 0x0018
struct FPreviewSocketStruct
{
	class FName                                        DisplayName;                                   // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	class FName                                        SocketName;                                    // 0x0008 (0x0008) [0x0000000000000001] (CPF_Edit)    
	class USkeletalMesh*                               PreviewSkelMesh;                               // 0x0010 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class UStaticMesh*                                 PreviewStaticMesh;                             // 0x0014 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.AnimTree.PreviewAnimSetsStruct
// 0x0014
struct FPreviewAnimSetsStruct
{
	class FName                                        DisplayName;                                   // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	class TArray<class UAnimSet*>                      PreviewAnimSets;                               // 0x0008 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
};

// ScriptStruct Engine.ApexDestructibleActor.CheckpointRecord
// 0x001C
struct AApexDestructibleActor_FCheckpointRecord
{
	class FString                                      initMostOutName;                               // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class FString                                      initActorFName;                                // 0x000C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	uint32_t                                           bPlayed : 1;                                   // 0x0018 (0x0004) [0x0000000000000000] [0x00000001] 
};

// ScriptStruct Engine.ApexDestructibleAsset.NxDestructibleParametersFlag
// 0x0004
struct FNxDestructibleParametersFlag
{
	uint32_t                                           ACCUMULATE_DAMAGE : 1;                         // 0x0000 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           ASSET_DEFINED_SUPPORT : 1;                     // 0x0000 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint32_t                                           WORLD_SUPPORT : 1;                             // 0x0000 (0x0004) [0x0000000000000001] [0x00000004] (CPF_Edit)
	uint32_t                                           DEBRIS_TIMEOUT : 1;                            // 0x0000 (0x0004) [0x0000000000000001] [0x00000008] (CPF_Edit)
	uint32_t                                           DEBRIS_MAX_SEPARATION : 1;                     // 0x0000 (0x0004) [0x0000000000000001] [0x00000010] (CPF_Edit)
	uint32_t                                           CRUMBLE_SMALLEST_CHUNKS : 1;                   // 0x0000 (0x0004) [0x0000000000000001] [0x00000020] (CPF_Edit)
	uint32_t                                           ACCURATE_RAYCASTS : 1;                         // 0x0000 (0x0004) [0x0000000000000001] [0x00000040] (CPF_Edit)
	uint32_t                                           USE_VALID_BOUNDS : 1;                          // 0x0000 (0x0004) [0x0000000000000001] [0x00000080] (CPF_Edit)
};

// ScriptStruct Engine.ApexDestructibleAsset.NxDestructibleDepthParameters
// 0x0004
struct FNxDestructibleDepthParameters
{
	uint32_t                                           TAKE_IMPACT_DAMAGE : 1;                        // 0x0000 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           IGNORE_POSE_UPDATES : 1;                       // 0x0000 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint32_t                                           IGNORE_RAYCAST_CALLBACKS : 1;                  // 0x0000 (0x0004) [0x0000000000000001] [0x00000004] (CPF_Edit)
	uint32_t                                           IGNORE_CONTACT_CALLBACKS : 1;                  // 0x0000 (0x0004) [0x0000000000000001] [0x00000008] (CPF_Edit)
	uint32_t                                           USER_FLAG_0 : 1;                               // 0x0000 (0x0004) [0x0000000000000001] [0x00000010] (CPF_Edit)
	uint32_t                                           USER_FLAG_1 : 1;                               // 0x0000 (0x0004) [0x0000000000000001] [0x00000020] (CPF_Edit)
	uint32_t                                           USER_FLAG_2 : 1;                               // 0x0000 (0x0004) [0x0000000000000001] [0x00000040] (CPF_Edit)
	uint32_t                                           USER_FLAG_3 : 1;                               // 0x0000 (0x0004) [0x0000000000000001] [0x00000080] (CPF_Edit)
};

// ScriptStruct Engine.ApexDestructibleAsset.NxDestructibleParameters
// 0x0080
struct FNxDestructibleParameters
{
	float                                              DamageThreshold;                               // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              DamageToRadius;                                // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              DamageCap;                                     // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              ForceToDamage;                                 // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              ImpactVelocityThreshold;                       // 0x0010 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              MaterialStrength;                              // 0x0014 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              DamageToPercentDeformation;                    // 0x0018 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              DeformationPercentLimit;                       // 0x001C (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bFormExtendedStructures : 1;                   // 0x0020 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	int32_t                                            SupportDepth;                                  // 0x0024 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            DebrisDepth;                                   // 0x0028 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            EssentialDepth;                                // 0x002C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              DebrisLifetimeMin;                             // 0x0030 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              DebrisLifetimeMax;                             // 0x0034 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              DebrisMaxSeparationMin;                        // 0x0038 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              DebrisMaxSeparationMax;                        // 0x003C (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FBox                                        ValidBounds;                                   // 0x0040 (0x001C) [0x0000000000000001] (CPF_Edit)    
	float                                              MaxChunkSpeed;                                 // 0x005C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              MassScaleExponent;                             // 0x0060 (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FNxDestructibleParametersFlag               Flags;                                         // 0x0064 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              GrbVolumeLimit;                                // 0x0068 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              GrbParticleSpacing;                            // 0x006C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              FractureImpulseScale;                          // 0x0070 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class TArray<struct FNxDestructibleDepthParameters> DepthParameters;                               // 0x0074 (0x000C) [0x0000000000400041] (CPF_Edit | CPF_EditFixedSize | CPF_NeedCtorLink)
};

// ScriptStruct Engine.ApexDestructibleDamageParameters.DamageParameters
// 0x0010
struct FDamageParameters
{
	uint8_t                                            OverrideMode;                                  // 0x0000 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            UnknownData00[0x3];                              // 0x0001 (0x0003) MISSED OFFSET
	float                                              BaseDamage;                                    // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              Radius;                                        // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              Momentum;                                      // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.ApexDestructibleDamageParameters.DamagePair
// 0x0014
struct FDamagePair
{
	class UClass*                                      DamageTypeClass;                               // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FDamageParameters                           Params;                                        // 0x0004 (0x0010) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.KMeshProps.KSphereElem
// 0x0048
struct FKSphereElem
{
	struct FMatrix                                     TM;                                            // 0x0000 (0x0040) [0x0000000000020001] (CPF_Edit | CPF_EditConst)
	float                                              Radius;                                        // 0x0040 (0x0004) [0x0000000000020001] (CPF_Edit | CPF_EditConst)
	uint32_t                                           bNoRBCollision : 1;                            // 0x0044 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bPerPolyShape : 1;                             // 0x0044 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint8_t                                            MinStructAlignment[0x8];                         // 0x0048 (0x0008) ADDED PADDING
};

// ScriptStruct Engine.KMeshProps.KBoxElem
// 0x0050
struct FKBoxElem
{
	struct FMatrix                                     TM;                                            // 0x0000 (0x0040) [0x0000000000020001] (CPF_Edit | CPF_EditConst)
	float                                              X;                                             // 0x0040 (0x0004) [0x0000000000020001] (CPF_Edit | CPF_EditConst)
	float                                              Y;                                             // 0x0044 (0x0004) [0x0000000000020001] (CPF_Edit | CPF_EditConst)
	float                                              Z;                                             // 0x0048 (0x0004) [0x0000000000020001] (CPF_Edit | CPF_EditConst)
	uint32_t                                           bNoRBCollision : 1;                            // 0x004C (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bPerPolyShape : 1;                             // 0x004C (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
};

// ScriptStruct Engine.KMeshProps.KSphylElem
// 0x004C
struct FKSphylElem
{
	struct FMatrix                                     TM;                                            // 0x0000 (0x0040) [0x0000000000020001] (CPF_Edit | CPF_EditConst)
	float                                              Radius;                                        // 0x0040 (0x0004) [0x0000000000020001] (CPF_Edit | CPF_EditConst)
	float                                              Length;                                        // 0x0044 (0x0004) [0x0000000000020001] (CPF_Edit | CPF_EditConst)
	uint32_t                                           bNoRBCollision : 1;                            // 0x0048 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bPerPolyShape : 1;                             // 0x0048 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint8_t                                            MinStructAlignment[0x4];                         // 0x004C (0x0004) ADDED PADDING
};

// ScriptStruct Engine.KMeshProps.KConvexElem
// 0x0064
struct FKConvexElem
{
	class TArray<struct FVector>                       VertexData;                                    // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<struct FPlane>                        PermutedVertexData;                            // 0x000C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<int32_t>                              FaceTriData;                                   // 0x0018 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<struct FVector>                       EdgeDirections;                                // 0x0024 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<struct FVector>                       FaceNormalDirections;                          // 0x0030 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<struct FPlane>                        FacePlaneData;                                 // 0x003C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	struct FBox                                        ElemBox;                                       // 0x0048 (0x001C) [0x0000000000000000]               
};

// ScriptStruct Engine.KMeshProps.KAggregateGeom
// 0x0038
struct FKAggregateGeom
{
	class TArray<struct FKSphereElem>                  SphereElems;                                   // 0x0000 (0x000C) [0x0000000000400041] (CPF_Edit | CPF_EditFixedSize | CPF_NeedCtorLink)
	class TArray<struct FKBoxElem>                     BoxElems;                                      // 0x000C (0x000C) [0x0000000000400041] (CPF_Edit | CPF_EditFixedSize | CPF_NeedCtorLink)
	class TArray<struct FKSphylElem>                   SphylElems;                                    // 0x0018 (0x000C) [0x0000000000400041] (CPF_Edit | CPF_EditFixedSize | CPF_NeedCtorLink)
	class TArray<struct FKConvexElem>                  ConvexElems;                                   // 0x0024 (0x000C) [0x0000000000400041] (CPF_Edit | CPF_EditFixedSize | CPF_NeedCtorLink)
	struct FPointer                                    RenderInfo;                                    // 0x0030 (0x0004) [0x0000000401001000] (CPF_Native | CPF_NonTransactional)
	uint32_t                                           bSkipCloseAndParallelChecks : 1;               // 0x0034 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
};

// ScriptStruct Engine.BrushComponent.KCachedConvexData_Mirror
// 0x000C
struct FKCachedConvexData_Mirror
{
	class TArray<int32_t>                              CachedConvexElements;                          // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.Brush.GeomSelection
// 0x000C
struct FGeomSelection
{
	int32_t                                            Type;                                          // 0x0000 (0x0004) [0x0000000000000000]               
	int32_t                                            Index;                                         // 0x0004 (0x0004) [0x0000000000000000]               
	int32_t                                            SelectionIndex;                                // 0x0008 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.ReverbVolume.InteriorSettings
// 0x0024
struct FInteriorSettings
{
	uint32_t                                           bIsWorldInfo : 1;                              // 0x0000 (0x0004) [0x0000000000000000] [0x00000001] 
	float                                              ExteriorVolume;                                // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              ExteriorTime;                                  // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              ExteriorLPF;                                   // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              ExteriorLPFTime;                               // 0x0010 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              InteriorVolume;                                // 0x0014 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              InteriorTime;                                  // 0x0018 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              InteriorLPF;                                   // 0x001C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              InteriorLPFTime;                               // 0x0020 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.ReverbVolume.ReverbSettings
// 0x0010
struct FReverbSettings
{
	uint32_t                                           bApplyReverb : 1;                              // 0x0000 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint8_t                                            ReverbType;                                    // 0x0004 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            UnknownData00[0x3];                              // 0x0005 (0x0003) MISSED OFFSET
	float                                              Volume;                                        // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              FadeTime;                                      // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.AudioDevice.Listener
// 0x0034
struct FListener
{
	class APortalVolume*                               PortalVolume;                                  // 0x0000 (0x0004) [0x0000000000000002] (CPF_Const)   
	struct FVector                                     Location;                                      // 0x0004 (0x000C) [0x0000000000000000]               
	struct FVector                                     Up;                                            // 0x0010 (0x000C) [0x0000000000000000]               
	struct FVector                                     Right;                                         // 0x001C (0x000C) [0x0000000000000000]               
	struct FVector                                     Front;                                         // 0x0028 (0x000C) [0x0000000000000000]               
};

// ScriptStruct Engine.AudioDevice.AudioClassInfo
// 0x0010
struct FAudioClassInfo
{
	int32_t                                            NumResident;                                   // 0x0000 (0x0004) [0x0000000000000002] (CPF_Const)   
	int32_t                                            SizeResident;                                  // 0x0004 (0x0004) [0x0000000000000002] (CPF_Const)   
	int32_t                                            NumRealTime;                                   // 0x0008 (0x0004) [0x0000000000000002] (CPF_Const)   
	int32_t                                            SizeRealTime;                                  // 0x000C (0x0004) [0x0000000000000002] (CPF_Const)   
};

// ScriptStruct Engine.StaticMeshComponent.StaticMeshComponentLODInfo
// 0x0020
struct FStaticMeshComponentLODInfo
{
	class TArray<class UShadowMap2D*>                  ShadowMaps;                                    // 0x0000 (0x000C) [0x0000000000400002] (CPF_Const | CPF_NeedCtorLink)
	class TArray<class UObject*>                       ShadowVertexBuffers;                           // 0x000C (0x000C) [0x0000000000400002] (CPF_Const | CPF_NeedCtorLink)
	struct FPointer                                    LightMap;                                      // 0x0018 (0x0004) [0x0000000000001002] (CPF_Const | CPF_Native)
	struct FPointer                                    OverrideVertexColors;                          // 0x001C (0x0004) [0x0000000000001002] (CPF_Const | CPF_Native)
};

// ScriptStruct Engine.CameraShake.FOscillator
// 0x0009
struct FFOscillator
{
	float                                              Amplitude;                                     // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              Frequency;                                     // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            InitialOffset;                                 // 0x0008 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            MinStructAlignment[0x3];                         // 0x0009 (0x0003) ADDED PADDING
};

// ScriptStruct Engine.CameraShake.VOscillator
// 0x0024
struct FVOscillator
{
	struct FFOscillator                                X;                                             // 0x0000 (0x000C) [0x0000000000000001] (CPF_Edit)    
	struct FFOscillator                                Y;                                             // 0x000C (0x000C) [0x0000000000000001] (CPF_Edit)    
	struct FFOscillator                                Z;                                             // 0x0018 (0x000C) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.CameraShake.ROscillator
// 0x0024
struct FROscillator
{
	struct FFOscillator                                Pitch;                                         // 0x0000 (0x000C) [0x0000000000000001] (CPF_Edit)    
	struct FFOscillator                                Yaw;                                           // 0x000C (0x000C) [0x0000000000000001] (CPF_Edit)    
	struct FFOscillator                                Roll;                                          // 0x0018 (0x000C) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.CameraModifier_CameraShake.CameraShakeInstance
// 0x0080
struct FCameraShakeInstance
{
	class UCameraShake*                                SourceShake;                                   // 0x0000 (0x0004) [0x0000000000000000]               
	float                                              OscillatorTimeRemaining;                       // 0x0004 (0x0004) [0x0000000000000000]               
	uint32_t                                           bBlendingIn : 1;                               // 0x0008 (0x0004) [0x0000000000000000] [0x00000001] 
	float                                              CurrentBlendInTime;                            // 0x000C (0x0004) [0x0000000000000000]               
	uint32_t                                           bBlendingOut : 1;                              // 0x0010 (0x0004) [0x0000000000000000] [0x00000001] 
	float                                              CurrentBlendOutTime;                           // 0x0014 (0x0004) [0x0000000000000000]               
	struct FVector                                     LocSinOffset;                                  // 0x0018 (0x000C) [0x0000000000000000]               
	struct FVector                                     RotSinOffset;                                  // 0x0024 (0x000C) [0x0000000000000000]               
	float                                              FOVSinOffset;                                  // 0x0030 (0x0004) [0x0000000000000000]               
	float                                              Scale;                                         // 0x0034 (0x0004) [0x0000000000000000]               
	class UCameraAnimInst*                             AnimInst;                                      // 0x0038 (0x0004) [0x0000000000000000]               
	uint8_t                                            PlaySpace;                                     // 0x003C (0x0001) [0x0000000000000000]               
	uint8_t                                            UnknownData00[0x3];                              // 0x003D (0x0003) MISSED OFFSET
	struct FMatrix                                     UserPlaySpaceMatrix;                           // 0x0040 (0x0040) [0x0000000000000000]               
};

// ScriptStruct Engine.FontImportOptions.FontImportOptionsData
// 0x0094
struct FFontImportOptionsData
{
	class FString                                      FontName;                                      // 0x0000 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	float                                              Height;                                        // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bEnableAntialiasing : 1;                       // 0x0010 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bEnableBold : 1;                               // 0x0010 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint32_t                                           bEnableItalic : 1;                             // 0x0010 (0x0004) [0x0000000000000001] [0x00000004] (CPF_Edit)
	uint32_t                                           bEnableUnderline : 1;                          // 0x0010 (0x0004) [0x0000000000000001] [0x00000008] (CPF_Edit)
	uint32_t                                           bAlphaOnly : 1;                                // 0x0010 (0x0004) [0x0000000000000001] [0x00000010] (CPF_Edit)
	uint8_t                                            CharacterSet;                                  // 0x0014 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            UnknownData00[0x3];                              // 0x0015 (0x0003) MISSED OFFSET
	class FString                                      Chars;                                         // 0x0018 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class FString                                      UnicodeRange;                                  // 0x0024 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class FString                                      CharsFilePath;                                 // 0x0030 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class FString                                      CharsFileWildcard;                             // 0x003C (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	uint32_t                                           bCreatePrintableOnly : 1;                      // 0x0048 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bIncludeASCIIRange : 1;                        // 0x0048 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	struct FLinearColor                                ForegroundColor;                               // 0x004C (0x0010) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bEnableDropShadow : 1;                         // 0x005C (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	int32_t                                            TexturePageWidth;                              // 0x0060 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            TexturePageMaxHeight;                          // 0x0064 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            XPadding;                                      // 0x0068 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            YPadding;                                      // 0x006C (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            ExtendBoxTop;                                  // 0x0070 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            ExtendBoxBottom;                               // 0x0074 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            ExtendBoxRight;                                // 0x0078 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            ExtendBoxLeft;                                 // 0x007C (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bEnableLegacyMode : 1;                         // 0x0080 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	int32_t                                            Kerning;                                       // 0x0084 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bUseDistanceFieldAlpha : 1;                    // 0x0088 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	int32_t                                            DistanceFieldScaleFactor;                      // 0x008C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              DistanceFieldScanRadiusScale;                  // 0x0090 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.Font.FontCharacter
// 0x0018
struct FFontCharacter
{
	int32_t                                            StartU;                                        // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            StartV;                                        // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            USize;                                         // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            VSize;                                         // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            TextureIndex;                                  // 0x0010 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            UnknownData00[0x3];                              // 0x0011 (0x0003) MISSED OFFSET
	int32_t                                            VerticalOffset;                                // 0x0014 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.Canvas.CanvasIcon
// 0x0014
struct FCanvasIcon
{
	class UTexture*                                    Texture;                                       // 0x0000 (0x0004) [0x0000000000000000]               
	float                                              U;                                             // 0x0004 (0x0004) [0x0000000000000000]               
	float                                              V;                                             // 0x0008 (0x0004) [0x0000000000000000]               
	float                                              UL;                                            // 0x000C (0x0004) [0x0000000000000000]               
	float                                              VL;                                            // 0x0010 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.Canvas.DepthFieldGlowInfo
// 0x0024
struct FDepthFieldGlowInfo
{
	uint32_t                                           bEnableGlow : 1;                               // 0x0000 (0x0004) [0x0000000000000000] [0x00000001] 
	struct FLinearColor                                GlowColor;                                     // 0x0004 (0x0010) [0x0000000000000000]               
	struct FVector2D                                   GlowOuterRadius;                               // 0x0014 (0x0008) [0x0000000000000000]               
	struct FVector2D                                   GlowInnerRadius;                               // 0x001C (0x0008) [0x0000000000000000]               
};

// ScriptStruct Engine.Canvas.FontRenderInfo
// 0x0028
struct FFontRenderInfo
{
	uint32_t                                           bClipText : 1;                                 // 0x0000 (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bEnableShadow : 1;                             // 0x0000 (0x0004) [0x0000000000000000] [0x00000002] 
	struct FDepthFieldGlowInfo                         GlowInfo;                                      // 0x0004 (0x0024) [0x0000000000000000]               
};

// ScriptStruct Engine.PhysicsVolume.CheckpointRecord
// 0x0004
struct APhysicsVolume_FCheckpointRecord
{
	uint32_t                                           bPainCausing : 1;                              // 0x0000 (0x0004) [0x0000000000000000] [0x00000001] 
};

// ScriptStruct Engine.CombatGlobalConfig.KnockBackParameters
// 0x0014
struct FKnockBackParameters
{
	float                                              KnockBackScale;                                // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              KnockBackTotalTime;                            // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FRotator                                    KnockBackRefAngle;                             // 0x0008 (0x000C) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.GameEffectSpeedController.GameEffectSpeedControlPara
// 0x0015
struct FGameEffectSpeedControlPara
{
	float                                              CurScale;                                      // 0x0000 (0x0004) [0x0000000000000000]               
	float                                              MinScale;                                      // 0x0004 (0x0004) [0x0000000000000000]               
	float                                              DecTime;                                       // 0x0008 (0x0004) [0x0000000000000000]               
	float                                              FrzTime;                                       // 0x000C (0x0004) [0x0000000000000000]               
	float                                              IncTime;                                       // 0x0010 (0x0004) [0x0000000000000000]               
	uint8_t                                            Priority;                                      // 0x0014 (0x0001) [0x0000000000000000]               
	uint8_t                                            MinStructAlignment[0x3];                         // 0x0015 (0x0003) ADDED PADDING
};

// ScriptStruct Engine.WorldInfo.WorldFractureSettings
// 0x001C
struct FWorldFractureSettings
{
	float                                              ChanceOfPhysicsChunkOverride;                  // 0x0000 (0x0004) [0x0000000000000000]               
	uint32_t                                           bEnableChanceOfPhysicsChunkOverride : 1;       // 0x0004 (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bLimitExplosionChunkSize : 1;                  // 0x0004 (0x0004) [0x0000000000000000] [0x00000002] 
	float                                              MaxExplosionChunkSize;                         // 0x0008 (0x0004) [0x0000000000000000]               
	uint32_t                                           bLimitDamageChunkSize : 1;                     // 0x000C (0x0004) [0x0000000000000000] [0x00000001] 
	float                                              MaxDamageChunkSize;                            // 0x0010 (0x0004) [0x0000000000000000]               
	int32_t                                            MaxNumFacturedChunksToSpawnInAFrame;           // 0x0014 (0x0004) [0x0000000000000000]               
	float                                              FractureExplosionVelScale;                     // 0x0018 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.WorldInfo.ScreenMessageString
// 0x0020
struct FScreenMessageString
{
	struct FQWord                                      Key;                                           // 0x0000 (0x0008) [0x0000000000102000] (CPF_Transient)
	class FString                                      ScreenMessage;                                 // 0x0008 (0x000C) [0x0000000000502000] (CPF_Transient | CPF_NeedCtorLink)
	struct FColor                                      DisplayColor;                                  // 0x0014 (0x0004) [0x0000000000102000] (CPF_Transient)
	float                                              TimeToDisplay;                                 // 0x0018 (0x0004) [0x0000000000102000] (CPF_Transient)
	float                                              CurrentTimeDisplayed;                          // 0x001C (0x0004) [0x0000000000102000] (CPF_Transient)
};

// ScriptStruct Engine.WorldInfo.LightmassWorldInfoSettings
// 0x0040
struct FLightmassWorldInfoSettings
{
	float                                              StaticLightingLevelScale;                      // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            NumIndirectLightingBounces;                    // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FColor                                      EnvironmentColor;                              // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              EnvironmentIntensity;                          // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              EmissiveBoost;                                 // 0x0010 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              DiffuseBoost;                                  // 0x0014 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              SpecularBoost;                                 // 0x0018 (0x0004) [0x0000000000000000]               
	float                                              IndirectNormalInfluenceBoost;                  // 0x001C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              LightEnvironmentIndirectContrastFactor;        // 0x0020 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bUseAmbientOcclusion : 1;                      // 0x0024 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	float                                              DirectIlluminationOcclusionFraction;           // 0x0028 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              IndirectIlluminationOcclusionFraction;         // 0x002C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              OcclusionExponent;                             // 0x0030 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              FullyOccludedSamplesFraction;                  // 0x0034 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              MaxOcclusionDistance;                          // 0x0038 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bVisualizeMaterialDiffuse : 1;                 // 0x003C (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bVisualizeAmbientOcclusion : 1;                // 0x003C (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
};

// ScriptStruct Engine.WorldInfo.NavMeshPathConstraintCacheDatum
// 0x0018
struct FNavMeshPathConstraintCacheDatum
{
	int32_t                                            ListIdx;                                       // 0x0000 (0x0004) [0x0000000000000000]               
	class UNavMeshPathConstraint*                      List[5];                                       // 0x0004 (0x0014) [0x0000000000000000]               
};

// ScriptStruct Engine.WorldInfo.NavMeshPathGoalEvaluatorCacheDatum
// 0x0018
struct FNavMeshPathGoalEvaluatorCacheDatum
{
	int32_t                                            ListIdx;                                       // 0x0000 (0x0004) [0x0000000000000000]               
	class UNavMeshPathGoalEvaluator*                   List[5];                                       // 0x0004 (0x0014) [0x0000000000000000]               
};

// ScriptStruct Engine.MusicTrackDataStructures.MusicTrackStruct
// 0x0018
struct FMusicTrackStruct
{
	class USoundCue*                                   TheSoundCue;                                   // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bAutoPlay : 1;                                 // 0x0004 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bPersistentAcrossLevels : 1;                   // 0x0004 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	float                                              FadeInTime;                                    // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              FadeInVolumeLevel;                             // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              FadeOutTime;                                   // 0x0010 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              FadeOutVolumeLevel;                            // 0x0014 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.WorldInfo.PhysXEmitterVerticalProperties
// 0x0018
struct FPhysXEmitterVerticalProperties
{
	uint32_t                                           bDisableLod : 1;                               // 0x0000 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	int32_t                                            ParticlesLodMin;                               // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            ParticlesLodMax;                               // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            PacketsPerPhysXParticleSystemMax;              // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bApplyCylindricalPacketCulling : 1;            // 0x0010 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	float                                              SpawnLodVsFifoBias;                            // 0x0014 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.WorldInfo.PhysXVerticalProperties
// 0x0018
struct FPhysXVerticalProperties
{
	struct FPhysXEmitterVerticalProperties             Emitters;                                      // 0x0000 (0x0018) [0x0000000004000001] (CPF_Edit | CPF_EditInline)
};

// ScriptStruct Engine.WorldInfo.ApexModuleDestructibleSettings
// 0x0010
struct FApexModuleDestructibleSettings
{
	int32_t                                            MaxChunkIslandCount;                           // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            MaxRrbActorCount;                              // 0x0004 (0x0004) [0x0000000000000000]               
	float                                              MaxChunkSeparationLOD;                         // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bOverrideMaxChunkSeparationLOD : 1;            // 0x000C (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
};

// ScriptStruct Engine.WorldInfo.PhysXSimulationProperties
// 0x000C
struct FPhysXSimulationProperties
{
	uint32_t                                           bUseHardware : 1;                              // 0x0000 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bFixedTimeStep : 1;                            // 0x0000 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	float                                              TimeStep;                                      // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            MaxSubSteps;                                   // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.WorldInfo.PhysXSceneProperties
// 0x003C
struct FPhysXSceneProperties
{
	struct FPhysXSimulationProperties                  PrimaryScene;                                  // 0x0000 (0x000C) [0x0000000004000001] (CPF_Edit | CPF_EditInline)
	struct FPhysXSimulationProperties                  CompartmentRigidBody;                          // 0x000C (0x000C) [0x0000000004000001] (CPF_Edit | CPF_EditInline)
	struct FPhysXSimulationProperties                  CompartmentFluid;                              // 0x0018 (0x000C) [0x0000000004000001] (CPF_Edit | CPF_EditInline)
	struct FPhysXSimulationProperties                  CompartmentCloth;                              // 0x0024 (0x000C) [0x0000000004000001] (CPF_Edit | CPF_EditInline)
	struct FPhysXSimulationProperties                  CompartmentSoftBody;                           // 0x0030 (0x000C) [0x0000000004000001] (CPF_Edit | CPF_EditInline)
};

// ScriptStruct Engine.WorldInfo.CompartmentRunList
// 0x0004
struct FCompartmentRunList
{
	uint32_t                                           RigidBody : 1;                                 // 0x0000 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           Fluid : 1;                                     // 0x0000 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint32_t                                           Cloth : 1;                                     // 0x0000 (0x0004) [0x0000000000000001] [0x00000004] (CPF_Edit)
	uint32_t                                           SoftBody : 1;                                  // 0x0000 (0x0004) [0x0000000000000001] [0x00000008] (CPF_Edit)
};

// ScriptStruct Engine.WorldInfo.NetViewer
// 0x0020
struct FNetViewer
{
	class APlayerController*                           InViewer;                                      // 0x0000 (0x0004) [0x0000000000000000]               
	class AActor*                                      Viewer;                                        // 0x0004 (0x0004) [0x0000000000000000]               
	struct FVector                                     ViewLocation;                                  // 0x0008 (0x000C) [0x0000000000000000]               
	struct FVector                                     ViewDir;                                       // 0x0014 (0x000C) [0x0000000000000000]               
};

// ScriptStruct Engine.UIRoot.WIDGET_ID
// 0x0000 (0x0010 - 0x0010)
struct FWIDGET_ID : FGuid
{
};

// ScriptStruct Engine.UIRoot.STYLE_ID
// 0x0000 (0x0010 - 0x0010)
struct FSTYLE_ID : FGuid
{
};

// ScriptStruct Engine.UIRoot.UIRangeData
// 0x0014
struct FUIRangeData
{
	float                                              CurrentValue;                                  // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              MinValue;                                      // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              MaxValue;                                      // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              NudgeValue;                                    // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bIntRange : 1;                                 // 0x0010 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
};

// ScriptStruct Engine.UIRoot.TextureCoordinates
// 0x0010
struct FTextureCoordinates
{
	float                                              U;                                             // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              V;                                             // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              UL;                                            // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              VL;                                            // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.UIRoot.UIProviderScriptFieldValue
// 0x0054
struct FUIProviderScriptFieldValue
{
	class FName                                        PropertyTag;                                   // 0x0000 (0x0008) [0x0000000000000000]               
	uint8_t                                            PropertyType;                                  // 0x0008 (0x0001) [0x0000000000000000]               
	uint8_t                                            UnknownData00[0x3];                              // 0x0009 (0x0003) MISSED OFFSET
	class FString                                      StringValue;                                   // 0x000C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class USurface*                                    ImageValue;                                    // 0x0018 (0x0004) [0x0000000000000000]               
	class TArray<int32_t>                              ArrayValue;                                    // 0x001C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	struct FUIRangeData                                RangeValue;                                    // 0x0028 (0x0014) [0x0000000000000000]               
	struct FUniqueNetId                                NetIdValue;                                    // 0x003C (0x0008) [0x0000000000000000]               
	struct FTextureCoordinates                         AtlasCoordinates;                              // 0x0044 (0x0010) [0x0000000000000000]               
};

// ScriptStruct Engine.UIRoot.UIProviderFieldValue
// 0x0004 (0x0054 - 0x0058)
struct FUIProviderFieldValue : FUIProviderScriptFieldValue
{
	struct FPointer                                    CustomStringNode;                              // 0x0054 (0x0004) [0x0000000000003002] (CPF_Const | CPF_Native | CPF_Transient)
};

// ScriptStruct Engine.UIRoot.UIStyleReference
// 0x0020
struct FUIStyleReference
{
	class FName                                        DefaultStyleTag;                               // 0x0000 (0x0008) [0x0000000000000000]               
	class UClass*                                      RequiredStyleClass;                            // 0x0008 (0x0004) [0x0000000000000002] (CPF_Const)   
	struct FSTYLE_ID                                   AssignedStyleID;                               // 0x000C (0x0010) [0x0000000000000002] (CPF_Const)   
	class UUIStyle*                                    ResolvedStyle;                                 // 0x001C (0x0004) [0x0000000000002002] (CPF_Const | CPF_Transient)
};

// ScriptStruct Engine.UIRoot.UIScreenValue
// 0x0006
struct FUIScreenValue
{
	float                                              Value;                                         // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            ScaleType;                                     // 0x0004 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            Orientation;                                   // 0x0005 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            MinStructAlignment[0x2];                         // 0x0006 (0x0002) ADDED PADDING
};

// ScriptStruct Engine.UIRoot.UIScreenValue_Extent
// 0x0006
struct FUIScreenValue_Extent
{
	float                                              Value;                                         // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            ScaleType;                                     // 0x0004 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            Orientation;                                   // 0x0005 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            MinStructAlignment[0x2];                         // 0x0006 (0x0002) ADDED PADDING
};

// ScriptStruct Engine.UIRoot.UIScreenValue_Position
// 0x000A
struct FUIScreenValue_Position
{
	float                                              Value[2];                                      // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            ScaleType[2];                                  // 0x0008 (0x0002) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            MinStructAlignment[0x2];                         // 0x000A (0x0002) ADDED PADDING
};

// ScriptStruct Engine.UIRoot.UIScreenValue_Bounds
// 0x0019
struct FUIScreenValue_Bounds
{
	float                                              Value[4];                                      // 0x0000 (0x0010) [0x0000000000020001] (CPF_Edit | CPF_EditConst)
	uint8_t                                            ScaleType[4];                                  // 0x0010 (0x0004) [0x0000000000020001] (CPF_Edit | CPF_EditConst)
	uint8_t                                            bInvalidated[4];                               // 0x0014 (0x0004) [0x0000000000002000] (CPF_Transient)
	uint8_t                                            AspectRatioMode;                               // 0x0018 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            MinStructAlignment[0x3];                         // 0x0019 (0x0003) ADDED PADDING
};

// ScriptStruct Engine.UIRoot.UIAnchorPosition
// 0x0006 (0x000A - 0x0010)
struct FUIAnchorPosition : FUIScreenValue_Position
{
	float                                              ZDepth;                                        // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.UIRoot.ScreenPositionRange
// 0x0000 (0x000A - 0x000A)
struct FScreenPositionRange : FUIScreenValue_Position
{
};

// ScriptStruct Engine.UIRoot.UIScreenValue_DockPadding
// 0x0014
struct FUIScreenValue_DockPadding
{
	float                                              PaddingValue[4];                               // 0x0000 (0x0010) [0x0000000000020001] (CPF_Edit | CPF_EditConst)
	uint8_t                                            PaddingScaleType[4];                           // 0x0010 (0x0004) [0x0000000000020001] (CPF_Edit | CPF_EditConst)
};

// ScriptStruct Engine.UIRoot.UIScreenValue_AutoSizeRegion
// 0x000A
struct FUIScreenValue_AutoSizeRegion
{
	float                                              Value[2];                                      // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            EvalType[2];                                   // 0x0008 (0x0002) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            MinStructAlignment[0x2];                         // 0x000A (0x0002) ADDED PADDING
};

// ScriptStruct Engine.UIRoot.AutoSizePadding
// 0x0000 (0x000A - 0x000A)
struct FAutoSizePadding : FUIScreenValue_AutoSizeRegion
{
};

// ScriptStruct Engine.UIRoot.AutoSizeData
// 0x001C
struct FAutoSizeData
{
	struct FUIScreenValue_AutoSizeRegion               Extent;                                        // 0x0000 (0x000C) [0x0000000000000001] (CPF_Edit)    
	struct FAutoSizePadding                            Padding;                                       // 0x000C (0x000C) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bAutoSizeEnabled : 1;                          // 0x0018 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
};

// ScriptStruct Engine.UIRoot.UIRenderingSubregion
// 0x0018
struct FUIRenderingSubregion
{
	struct FUIScreenValue_Extent                       ClampRegionSize;                               // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	struct FUIScreenValue_Extent                       ClampRegionOffset;                             // 0x0008 (0x0008) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            ClampRegionAlignment;                          // 0x0010 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            UnknownData00[0x3];                              // 0x0011 (0x0003) MISSED OFFSET
	uint32_t                                           bSubregionEnabled : 1;                         // 0x0014 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
};

// ScriptStruct Engine.UIRoot.InputEventSubscription
// 0x0014
struct FInputEventSubscription
{
	class FName                                        KeyName;                                       // 0x0000 (0x0008) [0x0000000000100000]               
	class TArray<class UUIScreenObject*>               Subscribers;                                   // 0x0008 (0x000C) [0x0000000000500000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.UIRoot.DefaultEventSpecification
// 0x0008
struct FDefaultEventSpecification
{
	class UUIEvent*                                    EventTemplate;                                 // 0x0000 (0x0004) [0x0000000000000000]               
	class UClass*                                      EventState;                                    // 0x0004 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.UIRoot.InputKeyAction
// 0x0024
struct FInputKeyAction
{
	class FName                                        InputKeyName;                                  // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            InputKeyState;                                 // 0x0008 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            UnknownData00[0x3];                              // 0x0009 (0x0003) MISSED OFFSET
	class TArray<struct FSeqOpOutputInputLink>         TriggeredOps;                                  // 0x000C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<class USequenceOp*>                   ActionsToExecute;                              // 0x0018 (0x000C) [0x0000000020400000] (CPF_NeedCtorLink | CPF_Deprecated)
};

// ScriptStruct Engine.UIRoot.StateInputKeyAction
// 0x0004 (0x0024 - 0x0028)
struct FStateInputKeyAction : FInputKeyAction
{
	class UClass*                                      Scope;                                         // 0x0024 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.UIRoot.PlayerInteractionData
// 0x0008
struct FPlayerInteractionData
{
	class UUIObject*                                   FocusedControl;                                // 0x0000 (0x0004) [0x0000000000102000] (CPF_Transient)
	class UUIObject*                                   LastFocusedControl;                            // 0x0004 (0x0004) [0x0000000000102000] (CPF_Transient)
};

// ScriptStruct Engine.UIRoot.UIFocusPropagationData
// 0x0014
struct FUIFocusPropagationData
{
	class UUIObject*                                   FirstFocusTarget;                              // 0x0000 (0x0004) [0x0000000000022003] (CPF_Edit | CPF_Const | CPF_Transient | CPF_EditConst)
	class UUIObject*                                   LastFocusTarget;                               // 0x0004 (0x0004) [0x0000000000022003] (CPF_Edit | CPF_Const | CPF_Transient | CPF_EditConst)
	class UUIObject*                                   NextFocusTarget;                               // 0x0008 (0x0004) [0x0000000000022003] (CPF_Edit | CPF_Const | CPF_Transient | CPF_EditConst)
	class UUIObject*                                   PrevFocusTarget;                               // 0x000C (0x0004) [0x0000000000022003] (CPF_Edit | CPF_Const | CPF_Transient | CPF_EditConst)
	uint32_t                                           bPendingReceiveFocus : 1;                      // 0x0010 (0x0004) [0x0000000000002000] [0x00000001] (CPF_Transient)
};

// ScriptStruct Engine.UIRoot.UINavigationData
// 0x0024
struct FUINavigationData
{
	class UUIObject*                                   NavigationTarget[4];                           // 0x0000 (0x0010) [0x0000000000022001] (CPF_Edit | CPF_Transient | CPF_EditConst)
	class UUIObject*                                   ForcedNavigationTarget[4];                     // 0x0010 (0x0010) [0x0000000000020001] (CPF_Edit | CPF_EditConst)
	uint8_t                                            bNullOverride[4];                              // 0x0020 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.UIRoot.UIDockingSet
// 0x0038
struct FUIDockingSet
{
	class UUIObject*                                   OwnerWidget;                                   // 0x0000 (0x0004) [0x0000000000000002] (CPF_Const)   
	class UUIObject*                                   TargetWidget[4];                               // 0x0004 (0x0010) [0x0000000000020001] (CPF_Edit | CPF_EditConst)
	struct FUIScreenValue_DockPadding                  DockPadding;                                   // 0x0014 (0x0014) [0x0000000000020001] (CPF_Edit | CPF_EditConst)
	uint32_t                                           bLockWidthWhenDocked : 1;                      // 0x0028 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bLockHeightWhenDocked : 1;                     // 0x0028 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint8_t                                            TargetFace[4];                                 // 0x002C (0x0004) [0x0000000000020001] (CPF_Edit | CPF_EditConst)
	uint8_t                                            bResolved[4];                                  // 0x0030 (0x0004) [0x0000000000002000] (CPF_Transient)
	uint8_t                                            bLinking[4];                                   // 0x0034 (0x0004) [0x0000000000002000] (CPF_Transient)
};

// ScriptStruct Engine.UIRoot.UIDockingNode
// 0x0005
struct FUIDockingNode
{
	class UUIObject*                                   Widget;                                        // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            Face;                                          // 0x0004 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            MinStructAlignment[0x3];                         // 0x0005 (0x0003) ADDED PADDING
};

// ScriptStruct Engine.UIRoot.UIRotation
// 0x0061
struct FUIRotation
{
	struct FRotator                                    Rotation;                                      // 0x0000 (0x000C) [0x0000000000000003] (CPF_Edit | CPF_Const)
	uint8_t                                            UnknownData00[0x4];                              // 0x000C (0x0004) MISSED OFFSET
	struct FMatrix                                     TransformMatrix;                               // 0x0010 (0x0040) [0x0000000000002002] (CPF_Const | CPF_Transient)
	struct FUIAnchorPosition                           AnchorPosition;                                // 0x0050 (0x0010) [0x0000000000000003] (CPF_Edit | CPF_Const)
	uint8_t                                            AnchorType;                                    // 0x0060 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            MinStructAlignment[0xF];                         // 0x0061 (0x000F) ADDED PADDING
};

// ScriptStruct Engine.UIRoot.UIDataStoreBinding
// 0x0030
struct FUIDataStoreBinding
{
	class UUIDataStoreSubscriber*                      Subscriber_Object;                             // 0x0000 (0x0008) [0x0000000000002002] (CPF_Const | CPF_Transient)
	class UUIDataStoreSubscriber*                      Subscriber_Interface;                          // 0x0000 (0x0008) [0x0000000000002002] (CPF_Const | CPF_Transient)
	uint8_t                                            RequiredFieldType;                             // 0x0008 (0x0001) [0x0000000000020003] (CPF_Edit | CPF_Const | CPF_EditConst)
	uint8_t                                            UnknownData00[0x3];                              // 0x0009 (0x0003) MISSED OFFSET
	class FString                                      MarkupString;                                  // 0x000C (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	int32_t                                            BindingIndex;                                  // 0x0018 (0x0004) [0x0000000000002002] (CPF_Const | CPF_Transient)
	class FName                                        DataStoreName;                                 // 0x001C (0x0008) [0x0000000000002002] (CPF_Const | CPF_Transient)
	class FName                                        DataStoreField;                                // 0x0024 (0x0008) [0x0000000000002002] (CPF_Const | CPF_Transient)
	class UUIDataStore*                                ResolvedDataStore;                             // 0x002C (0x0004) [0x0000000000002002] (CPF_Const | CPF_Transient)
};

// ScriptStruct Engine.UIRoot.UIStyleSubscriberReference
// 0x0010
struct FUIStyleSubscriberReference
{
	class FName                                        SubscriberId;                                  // 0x0000 (0x0008) [0x0000000000100000]               
	class UUIStyleResolver*                            Subscriber_Object;                             // 0x0008 (0x0008) [0x0000000000100000] 
	class UUIStyleResolver*                            Subscriber_Interface;                          // 0x0008 (0x0008) [0x0000000000100000]               
};

// ScriptStruct Engine.UIRoot.StyleReferenceId
// 0x000C
struct FStyleReferenceId
{
	class FName                                        StyleReferenceTag;                             // 0x0000 (0x0008) [0x0000000000100000]               
	class UProperty*                                   StyleProperty;                                 // 0x0008 (0x0004) [0x0000000000100000]               
};

// ScriptStruct Engine.UIRoot.UITextAttributes
// 0x0004
struct FUITextAttributes
{
	uint32_t                                           Bold : 1;                                      // 0x0000 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           Italic : 1;                                    // 0x0000 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint32_t                                           Underline : 1;                                 // 0x0000 (0x0004) [0x0000000000000001] [0x00000004] (CPF_Edit)
	uint32_t                                           Shadow : 1;                                    // 0x0000 (0x0004) [0x0000000000000001] [0x00000008] (CPF_Edit)
	uint32_t                                           Strikethrough : 1;                             // 0x0000 (0x0004) [0x0000000000000001] [0x00000010] (CPF_Edit)
};

// ScriptStruct Engine.UIRoot.UIImageAdjustmentData
// 0x0012
struct FUIImageAdjustmentData
{
	struct FUIScreenValue_Extent                       ProtectedRegion[2];                            // 0x0000 (0x0010) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            AdjustmentType;                                // 0x0010 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            Alignment;                                     // 0x0011 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            MinStructAlignment[0x2];                         // 0x0012 (0x0002) ADDED PADDING
};

// ScriptStruct Engine.UIRoot.UIStringCaretParameters
// 0x001C
struct FUIStringCaretParameters
{
	uint32_t                                           bDisplayCaret : 1;                             // 0x0000 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint8_t                                            CaretType;                                     // 0x0004 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            UnknownData00[0x3];                              // 0x0005 (0x0003) MISSED OFFSET
	float                                              CaretWidth;                                    // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class FName                                        CaretStyle;                                    // 0x000C (0x0008) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            CaretPosition;                                 // 0x0014 (0x0004) [0x0000000000002000] (CPF_Transient)
	class UMaterialInterface*                          CaretMaterial;                                 // 0x0018 (0x0004) [0x0000000000002000] (CPF_Transient)
};

// ScriptStruct Engine.UIRoot.RenderParameters
// 0x005C
struct FRenderParameters
{
	float                                              DrawX;                                         // 0x0000 (0x0004) [0x0000000000100000]               
	float                                              DrawY;                                         // 0x0004 (0x0004) [0x0000000000100000]               
	float                                              DrawZ;                                         // 0x0008 (0x0004) [0x0000000000100000]               
	float                                              DrawXL;                                        // 0x000C (0x0004) [0x0000000000100000]               
	float                                              DrawYL;                                        // 0x0010 (0x0004) [0x0000000000100000]               
	struct FVector2D                                   Scaling;                                       // 0x0014 (0x0008) [0x0000000000100000]               
	class UFont*                                       DrawFont;                                      // 0x001C (0x0004) [0x0000000000100000]               
	uint8_t                                            TextAlignment[2];                              // 0x0020 (0x0002) [0x0000000000100000]               
	uint8_t                                            UnknownData00[0x2];                              // 0x0022 (0x0002) MISSED OFFSET
	struct FVector2D                                   ImageExtent;                                   // 0x0024 (0x0008) [0x0000000000100000]               
	struct FTextureCoordinates                         DrawCoords;                                    // 0x002C (0x0010) [0x0000000000100000]               
	struct FVector2D                                   SpacingAdjust;                                 // 0x003C (0x0008) [0x0000000000100000]               
	float                                              ViewportHeight;                                // 0x0044 (0x0004) [0x0000000000100000]               
	uint32_t                                           bUseOverrideColor : 1;                         // 0x0048 (0x0004) [0x0000000000100000] [0x00000001] 
	struct FLinearColor                                OverideDrawColor;                              // 0x004C (0x0010) [0x0000000000100000]               
};

// ScriptStruct Engine.UIRoot.TextAutoScaleValue
// 0x0005
struct FTextAutoScaleValue
{
	float                                              MinScale;                                      // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            AutoScaleMode;                                 // 0x0004 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            MinStructAlignment[0x3];                         // 0x0005 (0x0003) ADDED PADDING
};

// ScriptStruct Engine.UIRoot.UIStyleOverride
// 0x0020
struct FUIStyleOverride
{
	struct FLinearColor                                DrawColor;                                     // 0x0000 (0x0010) [0x0000000000000001] (CPF_Edit)    
	float                                              Opacity;                                       // 0x0010 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              Padding[2];                                    // 0x0014 (0x0008) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bOverrideDrawColor : 1;                        // 0x001C (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bOverrideOpacity : 1;                          // 0x001C (0x0004) [0x0000000000000000] [0x00000002] 
	uint32_t                                           bOverridePadding : 1;                          // 0x001C (0x0004) [0x0000000000000000] [0x00000004] 
};

// ScriptStruct Engine.UIRoot.UITextStyleOverride
// 0x0028 (0x0020 - 0x0048)
struct FUITextStyleOverride : FUIStyleOverride
{
	class UFont*                                       DrawFont;                                      // 0x0020 (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FUITextAttributes                           TextAttributes;                                // 0x0024 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            TextAlignment[2];                              // 0x0028 (0x0002) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            ClipMode;                                      // 0x002A (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            ClipAlignment;                                 // 0x002B (0x0001) [0x0000000000000001] (CPF_Edit)    
	struct FTextAutoScaleValue                         AutoScaling;                                   // 0x002C (0x0008) [0x0000000000000001] (CPF_Edit)    
	float                                              DrawScale[2];                                  // 0x0034 (0x0008) [0x0000000000000001] (CPF_Edit)    
	float                                              SpacingAdjust[2];                              // 0x003C (0x0008) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bOverrideDrawFont : 1;                         // 0x0044 (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bOverrideAttributes : 1;                       // 0x0044 (0x0004) [0x0000000000000000] [0x00000002] 
	uint32_t                                           bOverrideAlignment : 1;                        // 0x0044 (0x0004) [0x0000000000000000] [0x00000004] 
	uint32_t                                           bOverrideClipMode : 1;                         // 0x0044 (0x0004) [0x0000000000000000] [0x00000008] 
	uint32_t                                           bOverrideClipAlignment : 1;                    // 0x0044 (0x0004) [0x0000000000000000] [0x00000010] 
	uint32_t                                           bOverrideAutoScale : 1;                        // 0x0044 (0x0004) [0x0000000000000000] [0x00000020] 
	uint32_t                                           bOverrideScale : 1;                            // 0x0044 (0x0004) [0x0000000000000000] [0x00000040] 
	uint32_t                                           bOverrideSpacingAdjust : 1;                    // 0x0044 (0x0004) [0x0000000000000000] [0x00000080] 
};

// ScriptStruct Engine.UIRoot.UIImageStyleOverride
// 0x003C (0x0020 - 0x005C)
struct FUIImageStyleOverride : FUIStyleOverride
{
	struct FTextureCoordinates                         Coordinates;                                   // 0x0020 (0x0010) [0x0000000000000001] (CPF_Edit)    
	struct FUIImageAdjustmentData                      Formatting[2];                                 // 0x0030 (0x0028) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bOverrideCoordinates : 1;                      // 0x0058 (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bOverrideFormatting : 1;                       // 0x0058 (0x0004) [0x0000000000000000] [0x00000002] 
};

// ScriptStruct Engine.UIRoot.UICombinedStyleData
// 0x0094
struct FUICombinedStyleData
{
	struct FLinearColor                                TextColor;                                     // 0x0000 (0x0010) [0x0000000000100000]               
	struct FLinearColor                                ImageColor;                                    // 0x0010 (0x0010) [0x0000000000100000]               
	float                                              TextPadding[2];                                // 0x0020 (0x0008) [0x0000000000100000]               
	float                                              ImagePadding[2];                               // 0x0028 (0x0008) [0x0000000000100000]               
	class UFont*                                       DrawFont;                                      // 0x0030 (0x0004) [0x0000000000100000]               
	class USurface*                                    FallbackImage;                                 // 0x0034 (0x0004) [0x0000000000100000]               
	struct FTextureCoordinates                         AtlasCoords;                                   // 0x0038 (0x0010) [0x0000000000100000]               
	struct FUITextAttributes                           TextAttributes;                                // 0x0048 (0x0004) [0x0000000000100000]               
	uint8_t                                            TextAlignment[2];                              // 0x004C (0x0002) [0x0000000000100000]               
	uint8_t                                            TextClipMode;                                  // 0x004E (0x0001) [0x0000000000100000]               
	uint8_t                                            TextClipAlignment;                             // 0x004F (0x0001) [0x0000000000100000]               
	struct FUIImageAdjustmentData                      AdjustmentType[2];                             // 0x0050 (0x0028) [0x0000000000100000]               
	struct FTextAutoScaleValue                         TextAutoScaling;                               // 0x0078 (0x0008) [0x0000000000100000]               
	struct FVector2D                                   TextScale;                                     // 0x0080 (0x0008) [0x0000000000100000]               
	struct FVector2D                                   TextSpacingAdjust;                             // 0x0088 (0x0008) [0x0000000000100000]               
	uint32_t                                           bInitialized : 1;                              // 0x0090 (0x0004) [0x0000000000100002] [0x00000001] (CPF_Const)
};

// ScriptStruct Engine.UIRoot.UIStringNodeModifier.ModifierData
// 0x0010
struct FModifierData
{
	class UUIStyle_Data*                               Style;                                         // 0x0000 (0x0004) [0x0000000000102002] (CPF_Const | CPF_Transient)
	class TArray<class UFont*>                         InlineFontStack;                               // 0x0004 (0x000C) [0x0000000000502002] (CPF_Const | CPF_Transient | CPF_NeedCtorLink)
};

// ScriptStruct Engine.UIRoot.UIStringNodeModifier
// 0x0138
struct FUIStringNodeModifier
{
	struct FUICombinedStyleData                        CustomStyleData;                               // 0x0000 (0x0094) [0x0000000000102002] (CPF_Const | CPF_Transient)
	struct FUICombinedStyleData                        BaseStyleData;                                 // 0x0094 (0x0094) [0x0000000000102002] (CPF_Const | CPF_Transient)
	class TArray<struct FModifierData>                 ModifierStack;                                 // 0x0128 (0x000C) [0x0000000000502002] (CPF_Const | CPF_Transient | CPF_NeedCtorLink)
	class UUIState*                                    CurrentMenuState;                              // 0x0134 (0x0004) [0x0000000000102002] (CPF_Const | CPF_Transient)
};

// ScriptStruct Engine.UIRoot.UIStringNode
// 0x002C
struct FUIStringNode
{
	struct FPointer                                    VfTable;                                       // 0x0000 (0x0004) [0x0000000000903002] (CPF_Const | CPF_Native | CPF_Transient | CPF_NoExport)
	class UUIDataStore*                                NodeDataStore;                                 // 0x0004 (0x0004) [0x0000000000102002] (CPF_Const | CPF_Transient)
	struct FPointer                                    ParentNode;                                    // 0x0008 (0x0004) [0x0000000000103002] (CPF_Const | CPF_Native | CPF_Transient)
	class FString                                      SourceText;                                    // 0x000C (0x000C) [0x0000000000500001] (CPF_Edit | CPF_NeedCtorLink)
	struct FVector2D                                   Extent;                                        // 0x0018 (0x0008) [0x0000000000100001] (CPF_Edit)    
	struct FVector2D                                   Scaling;                                       // 0x0020 (0x0008) [0x0000000000100001] (CPF_Edit)    
	uint32_t                                           bForceWrap : 1;                                // 0x0028 (0x0004) [0x0000000000100000] [0x00000001] 
};

// ScriptStruct Engine.UIRoot.UIStringNode_Text
// 0x00A0 (0x002C - 0x00CC)
struct FUIStringNode_Text : FUIStringNode
{
	class FString                                      RenderedText;                                  // 0x002C (0x000C) [0x0000000000500001] (CPF_Edit | CPF_NeedCtorLink)
	struct FUICombinedStyleData                        NodeStyleParameters;                           // 0x0038 (0x0094) [0x0000000000100000]               
};

// ScriptStruct Engine.UIRoot.UIStringNode_Image
// 0x001C (0x002C - 0x0048)
struct FUIStringNode_Image : FUIStringNode
{
	struct FVector2D                                   ForcedExtent;                                  // 0x002C (0x0008) [0x0000000000100001] (CPF_Edit)    
	struct FTextureCoordinates                         TexCoords;                                     // 0x0034 (0x0010) [0x0000000000100001] (CPF_Edit)    
	class UUITexture*                                  RenderedImage;                                 // 0x0044 (0x0004) [0x0000000000100001] (CPF_Edit)    
};

// ScriptStruct Engine.UIRoot.UIStringNode_NestedMarkupParent
// 0x0000 (0x002C - 0x002C)
struct FUIStringNode_NestedMarkupParent : FUIStringNode
{
};

// ScriptStruct Engine.UIRoot.UIStringNode_FormattedNodeParent
// 0x0000 (0x00CC - 0x00CC)
struct FUIStringNode_FormattedNodeParent : FUIStringNode_Text
{
};

// ScriptStruct Engine.UIRoot.WrappedStringElement
// 0x0014
struct FWrappedStringElement
{
	class FString                                      Value;                                         // 0x0000 (0x000C) [0x0000000000500000] (CPF_NeedCtorLink)
	struct FVector2D                                   LineExtent;                                    // 0x000C (0x0008) [0x0000000000100000]               
};

// ScriptStruct Engine.UIRoot.UIMouseCursor
// 0x000C
struct FUIMouseCursor
{
	class FName                                        CursorStyle;                                   // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	class UUITexture*                                  Cursor;                                        // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.UIRoot.InputEventParameters
// 0x0020
struct FInputEventParameters
{
	int32_t                                            PlayerIndex;                                   // 0x0000 (0x0004) [0x0000000000102002] (CPF_Const | CPF_Transient)
	int32_t                                            ControllerId;                                  // 0x0004 (0x0004) [0x0000000000102002] (CPF_Const | CPF_Transient)
	class FName                                        InputKeyName;                                  // 0x0008 (0x0008) [0x0000000000102002] (CPF_Const | CPF_Transient)
	uint8_t                                            EventType;                                     // 0x0010 (0x0001) [0x0000000000102002] (CPF_Const | CPF_Transient)
	uint8_t                                            UnknownData00[0x3];                              // 0x0011 (0x0003) MISSED OFFSET
	float                                              InputDelta;                                    // 0x0014 (0x0004) [0x0000000000102002] (CPF_Const | CPF_Transient)
	float                                              DeltaTime;                                     // 0x0018 (0x0004) [0x0000000000102002] (CPF_Const | CPF_Transient)
	uint32_t                                           bAltPressed : 1;                               // 0x001C (0x0004) [0x0000000000102002] [0x00000001] (CPF_Const | CPF_Transient)
	uint32_t                                           bCtrlPressed : 1;                              // 0x001C (0x0004) [0x0000000000102002] [0x00000002] (CPF_Const | CPF_Transient)
	uint32_t                                           bShiftPressed : 1;                             // 0x001C (0x0004) [0x0000000000102002] [0x00000004] (CPF_Const | CPF_Transient)
};

// ScriptStruct Engine.UIRoot.SubscribedInputEventParameters
// 0x0008 (0x0020 - 0x0028)
struct FSubscribedInputEventParameters : FInputEventParameters
{
	class FName                                        InputAliasName;                                // 0x0020 (0x0008) [0x0000000000102002] (CPF_Const | CPF_Transient)
};

// ScriptStruct Engine.UIRoot.UIAxisEmulationDefinition
// 0x0024
struct FUIAxisEmulationDefinition
{
	class FName                                        AxisInputKey;                                  // 0x0000 (0x0008) [0x0000000000000000]               
	class FName                                        AdjacentAxisInputKey;                          // 0x0008 (0x0008) [0x0000000000000000]               
	uint32_t                                           bEmulateButtonPress : 1;                       // 0x0010 (0x0004) [0x0000000000000000] [0x00000001] 
	class FName                                        InputKeyToEmulate[2];                          // 0x0014 (0x0010) [0x0000000000000000]               
};

// ScriptStruct Engine.UIRoot.RawInputKeyEventData
// 0x0009
struct FRawInputKeyEventData
{
	class FName                                        InputKeyName;                                  // 0x0000 (0x0008) [0x0000000000000000]               
	uint8_t                                            ModifierKeyFlags;                              // 0x0008 (0x0001) [0x0000000000000000]               
	uint8_t                                            MinStructAlignment[0x3];                         // 0x0009 (0x0003) ADDED PADDING
};

// ScriptStruct Engine.UIRoot.UIInputActionAlias
// 0x0014
struct FUIInputActionAlias
{
	class FName                                        InputAliasName;                                // 0x0000 (0x0008) [0x0000000000000000]               
	class TArray<struct FRawInputKeyEventData>         LinkedInputKeys;                               // 0x0008 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.UIRoot.UIInputAliasValue
// 0x000C
struct FUIInputAliasValue
{
	uint8_t                                            ModifierFlagMask;                              // 0x0000 (0x0001) [0x0000000000100000]               
	uint8_t                                            UnknownData00[0x3];                              // 0x0001 (0x0003) MISSED OFFSET
	class FName                                        InputAliasName;                                // 0x0004 (0x0008) [0x0000000000100000]               
};

// ScriptStruct Engine.UIRoot.UIInputAliasMap
// 0x003C
struct FUIInputAliasMap
{
	struct FMultiMap_Mirror                            InputAliasLookupTable;                         // 0x0000 (0x003C) [0x0000000000003002] (CPF_Const | CPF_Native | CPF_Transient)
};

// ScriptStruct Engine.UIRoot.UIInputAliasStateMap
// 0x001C
struct FUIInputAliasStateMap
{
	class FString                                      StateClassName;                                // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class UClass*                                      State;                                         // 0x000C (0x0004) [0x0000000000000000]               
	class TArray<struct FUIInputActionAlias>           StateInputAliases;                             // 0x0010 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.UIRoot.UIInputAliasClassMap
// 0x0094
struct FUIInputAliasClassMap
{
	class FString                                      WidgetClassName;                               // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class UClass*                                      WidgetClass;                                   // 0x000C (0x0004) [0x0000000000000000]               
	class TArray<struct FUIInputAliasStateMap>         WidgetStates;                                  // 0x0010 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	struct FMap_Mirror                                 StateLookupTable;                              // 0x001C (0x003C) [0x0000000000003002] (CPF_Const | CPF_Native | CPF_Transient)
	struct FMap_Mirror                                 StateReverseLookupTable;                       // 0x0058 (0x003C) [0x0000000000003002] (CPF_Const | CPF_Native | CPF_Transient)
};

// ScriptStruct Engine.Console.AutoCompleteCommand
// 0x0018
struct FAutoCompleteCommand
{
	class FString                                      Command;                                       // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class FString                                      Desc;                                          // 0x000C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.Console.AutoCompleteNode
// 0x001C
struct FAutoCompleteNode
{
	int32_t                                            IndexChar;                                     // 0x0000 (0x0004) [0x0000000000000000]               
	class TArray<int32_t>                              AutoCompleteListIndices;                       // 0x0004 (0x000C) [0x0000000000500000] (CPF_NeedCtorLink)
	class TArray<struct FPointer>                      ChildNodes;                                    // 0x0010 (0x000C) [0x0000000000500000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.UIAnimation.UIAnimationNotify
// 0x000C
struct FUIAnimationNotify
{
	uint8_t                                            NotifyType;                                    // 0x0000 (0x0001) [0x0000000000000000]               
	uint8_t                                            UnknownData00[0x3];                              // 0x0001 (0x0003) MISSED OFFSET
	class FName                                        NotifyName;                                    // 0x0004 (0x0008) [0x0000000000000000]               
};

// ScriptStruct Engine.UIAnimation.UIAnimationRawData
// 0x0038
struct FUIAnimationRawData
{
	float                                              DestAsFloat;                                   // 0x0000 (0x0004) [0x0000000000000000]               
	struct FLinearColor                                DestAsColor;                                   // 0x0004 (0x0010) [0x0000000000000000]               
	struct FRotator                                    DestAsRotator;                                 // 0x0014 (0x000C) [0x0000000000000000]               
	struct FVector                                     DestAsVector;                                  // 0x0020 (0x000C) [0x0000000000000000]               
	struct FUIAnimationNotify                          DestAsNotify;                                  // 0x002C (0x000C) [0x0000000000000000]               
};

// ScriptStruct Engine.UIAnimation.UIAnimationKeyFrame
// 0x0044
struct FUIAnimationKeyFrame
{
	float                                              RemainingTime;                                 // 0x0000 (0x0004) [0x0000000000000000]               
	uint8_t                                            InterpMode;                                    // 0x0004 (0x0001) [0x0000000000000000]               
	uint8_t                                            UnknownData00[0x3];                              // 0x0005 (0x0003) MISSED OFFSET
	float                                              InterpExponent;                                // 0x0008 (0x0004) [0x0000000000000000]               
	struct FUIAnimationRawData                         Data;                                          // 0x000C (0x0038) [0x0000000000000000]               
};

// ScriptStruct Engine.UIAnimation.UIAnimTrack
// 0x001C
struct FUIAnimTrack
{
	uint8_t                                            TrackType;                                     // 0x0000 (0x0001) [0x0000000000000000]               
	uint8_t                                            UnknownData00[0x3];                              // 0x0001 (0x0003) MISSED OFFSET
	class TArray<struct FUIAnimationKeyFrame>          KeyFrames;                                     // 0x0004 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<struct FUIAnimationKeyFrame>          LoopFrames;                                    // 0x0010 (0x000C) [0x0000000000402000] (CPF_Transient | CPF_NeedCtorLink)
};

// ScriptStruct Engine.UIAnimation.UIAnimSequence
// 0x0018
struct FUIAnimSequence
{
	class UUIAnimationSeq*                             SequenceRef;                                   // 0x0000 (0x0004) [0x0000000000100000]               
	class TArray<struct FUIAnimTrack>                  AnimationTracks;                               // 0x0004 (0x000C) [0x0000000000500000] (CPF_NeedCtorLink)
	uint8_t                                            LoopMode;                                      // 0x0010 (0x0001) [0x0000000000100000]               
	uint8_t                                            UnknownData00[0x3];                              // 0x0011 (0x0003) MISSED OFFSET
	float                                              PlaybackRate;                                  // 0x0014 (0x0004) [0x0000000000100000]               
};

// ScriptStruct Engine.UIComp_DrawStringEditbox.UIStringSelectionRegion
// 0x0008
struct FUIStringSelectionRegion
{
	int32_t                                            SelectionStartCharIndex;                       // 0x0000 (0x0004) [0x0000000000100000]               
	int32_t                                            SelectionEndCharIndex;                         // 0x0004 (0x0004) [0x0000000000100000]               
};

// ScriptStruct Engine.CoverMeshComponent.CoverMeshes
// 0x002C
struct FCoverMeshes
{
	class UStaticMesh*                                 Base;                                          // 0x0000 (0x0004) [0x0000000000000000]               
	class UStaticMesh*                                 LeanLeft;                                      // 0x0004 (0x0004) [0x0000000000000000]               
	class UStaticMesh*                                 LeanRight;                                     // 0x0008 (0x0004) [0x0000000000000000]               
	class UStaticMesh*                                 Climb;                                         // 0x000C (0x0004) [0x0000000000000000]               
	class UStaticMesh*                                 Mantle;                                        // 0x0010 (0x0004) [0x0000000000000000]               
	class UStaticMesh*                                 SlipLeft;                                      // 0x0014 (0x0004) [0x0000000000000000]               
	class UStaticMesh*                                 SlipRight;                                     // 0x0018 (0x0004) [0x0000000000000000]               
	class UStaticMesh*                                 SwatLeft;                                      // 0x001C (0x0004) [0x0000000000000000]               
	class UStaticMesh*                                 SwatRight;                                     // 0x0020 (0x0004) [0x0000000000000000]               
	class UStaticMesh*                                 PopUp;                                         // 0x0024 (0x0004) [0x0000000000000000]               
	class UStaticMesh*                                 PlayerOnly;                                    // 0x0028 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.CoverLink.CovPosInfo
// 0x0034
struct FCovPosInfo
{
	class ACoverLink*                                  Link;                                          // 0x0000 (0x0004) [0x0000000000000000]               
	int32_t                                            LtSlotIdx;                                     // 0x0004 (0x0004) [0x0000000000000000]               
	int32_t                                            RtSlotIdx;                                     // 0x0008 (0x0004) [0x0000000000000000]               
	float                                              LtToRtPct;                                     // 0x000C (0x0004) [0x0000000000000000]               
	struct FVector                                     Location;                                      // 0x0010 (0x000C) [0x0000000000000000]               
	struct FVector                                     Normal;                                        // 0x001C (0x000C) [0x0000000000000000]               
	struct FVector                                     Tangent;                                       // 0x0028 (0x000C) [0x0000000000000000]               
};

// ScriptStruct Engine.CoverLink.FireLinkItem
// 0x0004
struct FFireLinkItem
{
	uint8_t                                            SrcType;                                       // 0x0000 (0x0001) [0x0000000000000000]               
	uint8_t                                            SrcAction;                                     // 0x0001 (0x0001) [0x0000000000000000]               
	uint8_t                                            DestType;                                      // 0x0002 (0x0001) [0x0000000000000000]               
	uint8_t                                            DestAction;                                    // 0x0003 (0x0001) [0x0000000000000000]               
};

// ScriptStruct Engine.CoverLink.CoverReference
// 0x0008 (0x0014 - 0x001C)
struct FCoverReference : FActorReference
{
	int32_t                                            SlotIdx;                                       // 0x0014 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            Direction;                                     // 0x0018 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.CoverLink.FireLink
// 0x0030
struct FFireLink
{
	struct FCoverReference                             TargetActor;                                   // 0x0000 (0x001C) [0x0000000000020003] (CPF_Edit | CPF_Const | CPF_EditConst)
	class TArray<struct FFireLinkItem>                 Items;                                         // 0x001C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	uint8_t                                            DynamicLinkInfoIndex;                          // 0x0028 (0x0001) [0x0000000000000000]               
	uint8_t                                            DynamicLinkInfoIndexHigh;                      // 0x0029 (0x0001) [0x0000000000000000]               
	uint8_t                                            UnknownData00[0x2];                              // 0x002A (0x0002) MISSED OFFSET
	uint32_t                                           bDynamicIndexInited : 1;                       // 0x002C (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bFallbackLink : 1;                             // 0x002C (0x0004) [0x0000000000000000] [0x00000002] 
};

// ScriptStruct Engine.CoverLink.DynamicLinkInfo
// 0x0018
struct FDynamicLinkInfo
{
	struct FVector                                     LastTargetLocation;                            // 0x0000 (0x000C) [0x0000000000000000]               
	struct FVector                                     LastSrcLocation;                               // 0x000C (0x000C) [0x0000000000000000]               
};

// ScriptStruct Engine.CoverLink.ExposedLink
// 0x001D
struct FExposedLink
{
	struct FCoverReference                             TargetActor;                                   // 0x0000 (0x001C) [0x0000000000020003] (CPF_Edit | CPF_Const | CPF_EditConst)
	uint8_t                                            ExposedScale;                                  // 0x001C (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            MinStructAlignment[0x3];                         // 0x001D (0x0003) ADDED PADDING
};

// ScriptStruct Engine.CoverLink.DangerLink
// 0x0018
struct FDangerLink
{
	struct FActorReference                             DangerNav;                                     // 0x0000 (0x0014) [0x0000000000020003] (CPF_Edit | CPF_Const | CPF_EditConst)
	int32_t                                            DangerCost;                                    // 0x0014 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.CoverLink.SlotMoveRef
// 0x0050
struct FSlotMoveRef
{
	struct FPolyReference                              Poly;                                          // 0x0000 (0x0018) [0x0000000000000001] (CPF_Edit)    
	struct FBasedPosition                              Dest;                                          // 0x0018 (0x0034) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            Direction;                                     // 0x004C (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.CoverLink.CoverSlot
// 0x00A8
struct FCoverSlot
{
	class APawn*                                       SlotOwner;                                     // 0x0000 (0x0004) [0x0000000000000000]               
	float                                              SlotValidAfterTime;                            // 0x0004 (0x0004) [0x0000000000002000] (CPF_Transient)
	uint8_t                                            ForceCoverType;                                // 0x0008 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            CoverType;                                     // 0x0009 (0x0001) [0x0000000000020001] (CPF_Edit | CPF_EditConst)
	uint8_t                                            UnknownData00[0x2];                              // 0x000A (0x0002) MISSED OFFSET
	struct FVector                                     LocationOffset;                                // 0x000C (0x000C) [0x0000000000000000]               
	struct FRotator                                    RotationOffset;                                // 0x0018 (0x000C) [0x0000000000000000]               
	class TArray<uint8_t>                              Actions;                                       // 0x0024 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<struct FFireLink>                     FireLinks;                                     // 0x0030 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<struct FFireLink>                     ForcedFireLinks;                               // 0x003C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<struct FFireLink>                     RejectedFireLinks;                             // 0x0048 (0x000C) [0x0000000000402000] (CPF_Transient | CPF_NeedCtorLink)
	class TArray<struct FExposedLink>                  ExposedFireLinks;                              // 0x0054 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class TArray<struct FDangerLink>                   DangerLinks;                                   // 0x0060 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class TArray<struct FCoverReference>               TurnTarget;                                    // 0x006C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<struct FSlotMoveRef>                  SlipRefs;                                      // 0x0078 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<struct FCoverReference>               OverlapClaims;                                 // 0x0084 (0x000C) [0x0000000000420001] (CPF_Edit | CPF_EditConst | CPF_NeedCtorLink)
	uint32_t                                           bLeanLeft : 1;                                 // 0x0090 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bLeanRight : 1;                                // 0x0090 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint32_t                                           bForceCanPopUp : 1;                            // 0x0090 (0x0004) [0x0000000000000001] [0x00000004] (CPF_Edit)
	uint32_t                                           bCanPopUp : 1;                                 // 0x0090 (0x0004) [0x0000000000020001] [0x00000008] (CPF_Edit | CPF_EditConst)
	uint32_t                                           bCanMantle : 1;                                // 0x0090 (0x0004) [0x0000000000020001] [0x00000010] (CPF_Edit | CPF_EditConst)
	uint32_t                                           bCanClimbUp : 1;                               // 0x0090 (0x0004) [0x0000000000020001] [0x00000020] (CPF_Edit | CPF_EditConst)
	uint32_t                                           bForceCanCoverSlip_Left : 1;                   // 0x0090 (0x0004) [0x0000000000000001] [0x00000040] (CPF_Edit)
	uint32_t                                           bForceCanCoverSlip_Right : 1;                  // 0x0090 (0x0004) [0x0000000000000001] [0x00000080] (CPF_Edit)
	uint32_t                                           bCanCoverSlip_Left : 1;                        // 0x0090 (0x0004) [0x0000000000020001] [0x00000100] (CPF_Edit | CPF_EditConst)
	uint32_t                                           bCanCoverSlip_Right : 1;                       // 0x0090 (0x0004) [0x0000000000020001] [0x00000200] (CPF_Edit | CPF_EditConst)
	uint32_t                                           bCanSwatTurn_Left : 1;                         // 0x0090 (0x0004) [0x0000000000020001] [0x00000400] (CPF_Edit | CPF_EditConst)
	uint32_t                                           bCanSwatTurn_Right : 1;                        // 0x0090 (0x0004) [0x0000000000020001] [0x00000800] (CPF_Edit | CPF_EditConst)
	uint32_t                                           bEnabled : 1;                                  // 0x0090 (0x0004) [0x0000000000000001] [0x00001000] (CPF_Edit)
	uint32_t                                           bAllowPopup : 1;                               // 0x0090 (0x0004) [0x0000000000000001] [0x00002000] (CPF_Edit)
	uint32_t                                           bAllowMantle : 1;                              // 0x0090 (0x0004) [0x0000000000000001] [0x00004000] (CPF_Edit)
	uint32_t                                           bAllowCoverSlip : 1;                           // 0x0090 (0x0004) [0x0000000000000001] [0x00008000] (CPF_Edit)
	uint32_t                                           bAllowClimbUp : 1;                             // 0x0090 (0x0004) [0x0000000000000001] [0x00010000] (CPF_Edit)
	uint32_t                                           bAllowSwatTurn : 1;                            // 0x0090 (0x0004) [0x0000000000000001] [0x00020000] (CPF_Edit)
	uint32_t                                           bForceNoGroundAdjust : 1;                      // 0x0090 (0x0004) [0x0000000000000001] [0x00040000] (CPF_Edit)
	uint32_t                                           bPlayerOnly : 1;                               // 0x0090 (0x0004) [0x0000000000000001] [0x00080000] (CPF_Edit)
	uint32_t                                           bSelected : 1;                                 // 0x0090 (0x0004) [0x0000000000002000] [0x00100000] (CPF_Transient)
	int32_t                                            ExtraCost;                                     // 0x0094 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              LeanTraceDist;                                 // 0x0098 (0x0004) [0x0000000000000000]               
	class ACoverSlotMarker*                            SlotMarker;                                    // 0x009C (0x0004) [0x0000000000020001] (CPF_Edit | CPF_EditConst)
	uint8_t                                            LocationDescription;                           // 0x00A0 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            UnknownData01[0x3];                              // 0x00A1 (0x0003) MISSED OFFSET
	uint32_t                                           bFailedToFindSurface : 1;                      // 0x00A4 (0x0004) [0x0000000000000000] [0x00000001] 
};

// ScriptStruct Engine.CoverLink.CoverInfo
// 0x0008
struct FCoverInfo
{
	class ACoverLink*                                  Link;                                          // 0x0000 (0x0004) [0x0000000000020001] (CPF_Edit | CPF_EditConst)
	int32_t                                            SlotIdx;                                       // 0x0004 (0x0004) [0x0000000000020001] (CPF_Edit | CPF_EditConst)
};

// ScriptStruct Engine.CoverLink.LinkSlotHelper
// 0x0010
struct FLinkSlotHelper
{
	class ACoverLink*                                  Link;                                          // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class TArray<int32_t>                              Slots;                                         // 0x0004 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
};

// ScriptStruct Engine.CoverLink.TargetInfo
// 0x000C
struct FTargetInfo
{
	class AActor*                                      Target;                                        // 0x0000 (0x0004) [0x0000000000000000]               
	int32_t                                            SlotIdx;                                       // 0x0004 (0x0004) [0x0000000000000000]               
	int32_t                                            Direction;                                     // 0x0008 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.CoverReplicator.ManualCoverTypeInfo
// 0x0002
struct FManualCoverTypeInfo
{
	uint8_t                                            SlotIndex;                                     // 0x0000 (0x0001) [0x0000000000000000]               
	uint8_t                                            ManualCoverType;                               // 0x0001 (0x0001) [0x0000000000000000]               
	uint8_t                                            MinStructAlignment[0x2];                         // 0x0002 (0x0002) ADDED PADDING
};

// ScriptStruct Engine.CoverReplicator.CoverReplicationInfo
// 0x0034
struct FCoverReplicationInfo
{
	class ACoverLink*                                  Link;                                          // 0x0000 (0x0004) [0x0000000000000000]               
	class TArray<uint8_t>                              SlotsEnabled;                                  // 0x0004 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<uint8_t>                              SlotsDisabled;                                 // 0x0010 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<uint8_t>                              SlotsAdjusted;                                 // 0x001C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<struct FManualCoverTypeInfo>          SlotsCoverTypeChanged;                         // 0x0028 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.CullDistanceVolume.CullDistanceSizePair
// 0x0008
struct FCullDistanceSizePair
{
	float                                              Size;                                          // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              CullDistance;                                  // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.UIDataProvider.UIDataProviderField
// 0x0018
struct FUIDataProviderField
{
	class FName                                        FieldTag;                                      // 0x0000 (0x0008) [0x0000000000100000]               
	uint8_t                                            FieldType;                                     // 0x0008 (0x0001) [0x0000000000100000]               
	uint8_t                                            UnknownData00[0x3];                              // 0x0009 (0x0003) MISSED OFFSET
	class TArray<class UUIDataProvider*>               FieldProviders;                                // 0x000C (0x000C) [0x0000000000500000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.CurrentGameDataStore.GameDataProviderTypes
// 0x000C
struct FGameDataProviderTypes
{
	class UClass*                                      GameDataProviderClass;                         // 0x0000 (0x0004) [0x0000000000000002] (CPF_Const)   
	class UClass*                                      PlayerDataProviderClass;                       // 0x0004 (0x0004) [0x0000000000000002] (CPF_Const)   
	class UClass*                                      TeamDataProviderClass;                         // 0x0008 (0x0004) [0x0000000000000002] (CPF_Const)   
};

// ScriptStruct Engine.CurveEdPresetCurve.PresetGeneratedPoint
// 0x0015
struct FPresetGeneratedPoint
{
	float                                              KeyIn;                                         // 0x0000 (0x0004) [0x0000000000000000]               
	float                                              KeyOut;                                        // 0x0004 (0x0004) [0x0000000000000000]               
	uint32_t                                           TangentsValid : 1;                             // 0x0008 (0x0004) [0x0000000000000000] [0x00000001] 
	float                                              TangentIn;                                     // 0x000C (0x0004) [0x0000000000000000]               
	float                                              TangentOut;                                    // 0x0010 (0x0004) [0x0000000000000000]               
	uint8_t                                            IntepMode;                                     // 0x0014 (0x0001) [0x0000000000000000]               
	uint8_t                                            MinStructAlignment[0x3];                         // 0x0015 (0x0003) ADDED PADDING
};

// ScriptStruct Engine.DataStoreClient.PlayerDataStoreGroup
// 0x0010
struct FPlayerDataStoreGroup
{
	class ULocalPlayer*                                PlayerOwner;                                   // 0x0000 (0x0004) [0x0000000000102002] (CPF_Const | CPF_Transient)
	class TArray<class UUIDataStore*>                  DataStores;                                    // 0x0004 (0x000C) [0x0000000000502002] (CPF_Const | CPF_Transient | CPF_NeedCtorLink)
};

// ScriptStruct Engine.Input.KeyBind
// 0x0018
struct FKeyBind
{
	class FName                                        Name;                                          // 0x0000 (0x0008) [0x0000000000004000] (CPF_Config)  
	class FString                                      Command;                                       // 0x0008 (0x000C) [0x0000000000404000] (CPF_Config | CPF_NeedCtorLink)
	uint32_t                                           Control : 1;                                   // 0x0014 (0x0004) [0x0000000000004000] [0x00000001] (CPF_Config)
	uint32_t                                           Shift : 1;                                     // 0x0014 (0x0004) [0x0000000000004000] [0x00000002] (CPF_Config)
	uint32_t                                           Alt : 1;                                       // 0x0014 (0x0004) [0x0000000000004000] [0x00000004] (CPF_Config)
	uint32_t                                           bIgnoreCtrl : 1;                               // 0x0014 (0x0004) [0x0000000000004000] [0x00000008] (CPF_Config)
	uint32_t                                           bIgnoreShift : 1;                              // 0x0014 (0x0004) [0x0000000000004000] [0x00000010] (CPF_Config)
	uint32_t                                           bIgnoreAlt : 1;                                // 0x0014 (0x0004) [0x0000000000004000] [0x00000020] (CPF_Config)
};

// ScriptStruct Engine.DecalComponent.DecalReceiver
// 0x0008
struct FDecalReceiver
{
	class UPrimitiveComponent*                         Component;                                     // 0x0000 (0x0004) [0x000000000408000A] (CPF_Const | CPF_ExportObject | CPF_Component | CPF_EditInline)
	struct FPointer                                    RenderData;                                    // 0x0004 (0x0004) [0x0000000000001002] (CPF_Const | CPF_Native)
};

// ScriptStruct Engine.DecalManager.ActiveDecalInfo
// 0x0008
struct FActiveDecalInfo
{
	class UDecalComponent*                             Decal;                                         // 0x0000 (0x0004) [0x0000000004080008] (CPF_ExportObject | CPF_Component | CPF_EditInline)
	float                                              LifetimeRemaining;                             // 0x0004 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.MaterialInterface.LightmassMaterialInterfaceSettings
// 0x0018
struct FLightmassMaterialInterfaceSettings
{
	float                                              EmissiveBoost;                                 // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              DiffuseBoost;                                  // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              SpecularBoost;                                 // 0x0008 (0x0004) [0x0000000000000000]               
	float                                              ExportResolutionScale;                         // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              DistanceFieldPenumbraScale;                    // 0x0010 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bOverrideEmissiveBoost : 1;                    // 0x0014 (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bOverrideDiffuseBoost : 1;                     // 0x0014 (0x0004) [0x0000000000000000] [0x00000002] 
	uint32_t                                           bOverrideSpecularBoost : 1;                    // 0x0014 (0x0004) [0x0000000000000000] [0x00000004] 
	uint32_t                                           bOverrideExportResolutionScale : 1;            // 0x0014 (0x0004) [0x0000000000000000] [0x00000008] 
	uint32_t                                           bOverrideDistanceFieldPenumbraScale : 1;       // 0x0014 (0x0004) [0x0000000000000000] [0x00000010] 
};

// ScriptStruct Engine.Material.MaterialInput
// 0x001C
struct FMaterialInput
{
	class UMaterialExpression*                         Expression;                                    // 0x0000 (0x0004) [0x0000000000000000]               
	int32_t                                            Mask;                                          // 0x0004 (0x0004) [0x0000000000000000]               
	int32_t                                            MaskR;                                         // 0x0008 (0x0004) [0x0000000000000000]               
	int32_t                                            MaskG;                                         // 0x000C (0x0004) [0x0000000000000000]               
	int32_t                                            MaskB;                                         // 0x0010 (0x0004) [0x0000000000000000]               
	int32_t                                            MaskA;                                         // 0x0014 (0x0004) [0x0000000000000000]               
	int32_t                                            GCC64_Padding;                                 // 0x0018 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.Material.ColorMaterialInput
// 0x0008 (0x001C - 0x0024)
struct FColorMaterialInput : FMaterialInput
{
	uint32_t                                           UseConstant : 1;                               // 0x001C (0x0004) [0x0000000000000000] [0x00000001] 
	struct FColor                                      Constant;                                      // 0x0020 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.Material.ScalarMaterialInput
// 0x0008 (0x001C - 0x0024)
struct FScalarMaterialInput : FMaterialInput
{
	uint32_t                                           UseConstant : 1;                               // 0x001C (0x0004) [0x0000000000000000] [0x00000001] 
	float                                              Constant;                                      // 0x0020 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.Material.VectorMaterialInput
// 0x0010 (0x001C - 0x002C)
struct FVectorMaterialInput : FMaterialInput
{
	uint32_t                                           UseConstant : 1;                               // 0x001C (0x0004) [0x0000000000000000] [0x00000001] 
	struct FVector                                     Constant;                                      // 0x0020 (0x000C) [0x0000000000000000]               
};

// ScriptStruct Engine.Material.Vector2MaterialInput
// 0x000C (0x001C - 0x0028)
struct FVector2MaterialInput : FMaterialInput
{
	uint32_t                                           UseConstant : 1;                               // 0x001C (0x0004) [0x0000000000000000] [0x00000001] 
	float                                              ConstantX;                                     // 0x0020 (0x0004) [0x0000000000000000]               
	float                                              ConstantY;                                     // 0x0024 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.DynamicBlockingVolume.CheckpointRecord
// 0x0039
struct ADynamicBlockingVolume_FCheckpointRecord
{
	struct FVector                                     Location;                                      // 0x0000 (0x000C) [0x0000000000000000]               
	struct FRotator                                    Rotation;                                      // 0x000C (0x000C) [0x0000000000000000]               
	uint32_t                                           bCollideActors : 1;                            // 0x0018 (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bBlockActors : 1;                              // 0x0018 (0x0004) [0x0000000000000000] [0x00000002] 
	uint32_t                                           bNeedsReplication : 1;                         // 0x0018 (0x0004) [0x0000000000000000] [0x00000004] 
	class FString                                      initMostOutName;                               // 0x001C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class FString                                      initActorFName;                                // 0x0028 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	uint32_t                                           bEnabled : 1;                                  // 0x0034 (0x0004) [0x0000000000000000] [0x00000001] 
	uint8_t                                            CollisionType;                                 // 0x0038 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            MinStructAlignment[0x3];                         // 0x0039 (0x0003) ADDED PADDING
};

// ScriptStruct Engine.ParticleSystemComponent.ViewParticleEmitterInstanceMotionBlurInfo
// 0x003C
struct FViewParticleEmitterInstanceMotionBlurInfo
{
	struct FMap_Mirror                                 EmitterInstanceMBInfoMap;                      // 0x0000 (0x003C) [0x0000000000003002] (CPF_Const | CPF_Native | CPF_Transient)
};

// ScriptStruct Engine.ParticleSystemComponent.ParticleSysParam
// 0x0028
struct FParticleSysParam
{
	class FName                                        Name;                                          // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            ParamType;                                     // 0x0008 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            UnknownData00[0x3];                              // 0x0009 (0x0003) MISSED OFFSET
	float                                              Scalar;                                        // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FVector                                     Vector;                                        // 0x0010 (0x000C) [0x0000000000000001] (CPF_Edit)    
	struct FColor                                      Color;                                         // 0x001C (0x0004) [0x0000000000000001] (CPF_Edit)    
	class AActor*                                      Actor;                                         // 0x0020 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class UMaterialInterface*                          Material;                                      // 0x0024 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.ParticleSystemComponent.ParticleEventData
// 0x0034
struct FParticleEventData
{
	int32_t                                            Type;                                          // 0x0000 (0x0004) [0x0000000000000000]               
	class FName                                        EventName;                                     // 0x0004 (0x0008) [0x0000000000000000]               
	float                                              EmitterTime;                                   // 0x000C (0x0004) [0x0000000000000000]               
	struct FVector                                     Location;                                      // 0x0010 (0x000C) [0x0000000000000000]               
	struct FVector                                     Direction;                                     // 0x001C (0x000C) [0x0000000000000000]               
	struct FVector                                     Velocity;                                      // 0x0028 (0x000C) [0x0000000000000000]               
};

// ScriptStruct Engine.ParticleSystemComponent.ParticleEventSpawnData
// 0x0000 (0x0034 - 0x0034)
struct FParticleEventSpawnData : FParticleEventData
{
};

// ScriptStruct Engine.ParticleSystemComponent.ParticleEventDeathData
// 0x0004 (0x0034 - 0x0038)
struct FParticleEventDeathData : FParticleEventData
{
	float                                              ParticleTime;                                  // 0x0034 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.ParticleSystemComponent.ParticleEventCollideData
// 0x0020 (0x0034 - 0x0054)
struct FParticleEventCollideData : FParticleEventData
{
	float                                              ParticleTime;                                  // 0x0034 (0x0004) [0x0000000000000000]               
	struct FVector                                     Normal;                                        // 0x0038 (0x000C) [0x0000000000000000]               
	float                                              Time;                                          // 0x0044 (0x0004) [0x0000000000000000]               
	int32_t                                            Item;                                          // 0x0048 (0x0004) [0x0000000000000000]               
	class FName                                        BoneName;                                      // 0x004C (0x0008) [0x0000000000000000]               
};

// ScriptStruct Engine.ParticleSystemComponent.ParticleEventKismetData
// 0x0010 (0x0034 - 0x0044)
struct FParticleEventKismetData : FParticleEventData
{
	uint32_t                                           UsePSysCompLocation : 1;                       // 0x0034 (0x0004) [0x0000000000000000] [0x00000001] 
	struct FVector                                     Normal;                                        // 0x0038 (0x000C) [0x0000000000000000]               
};

// ScriptStruct Engine.ParticleSystemComponent.ParticleEmitterInstanceMotionBlurInfo
// 0x003C
struct FParticleEmitterInstanceMotionBlurInfo
{
	struct FMap_Mirror                                 ParticleMBInfoMap;                             // 0x0000 (0x003C) [0x0000000000003002] (CPF_Const | CPF_Native | CPF_Transient)
};

// ScriptStruct Engine.ParticleSystemComponent.ParticleEmitterInstance
// 0x0000
struct FParticleEmitterInstance
{
};

// ScriptStruct Engine.Emitter.CheckpointRecord
// 0x0004
struct AEmitter_FCheckpointRecord
{
	uint32_t                                           bIsActive : 1;                                 // 0x0000 (0x0004) [0x0000000000000000] [0x00000001] 
};

// ScriptStruct Engine.EmitterPool.EmitterBaseInfo
// 0x0024
struct FEmitterBaseInfo
{
	class UParticleSystemComponent*                    PSC;                                           // 0x0000 (0x0004) [0x0000000004080008] (CPF_ExportObject | CPF_Component | CPF_EditInline)
	class AActor*                                      Base;                                          // 0x0004 (0x0004) [0x0000000000000000]               
	struct FVector                                     RelativeLocation;                              // 0x0008 (0x000C) [0x0000000000000000]               
	struct FRotator                                    RelativeRotation;                              // 0x0014 (0x000C) [0x0000000000000000]               
	uint32_t                                           bInheritBaseScale : 1;                         // 0x0020 (0x0004) [0x0000000000000000] [0x00000001] 
};

// ScriptStruct Engine.Engine.StatColorMapEntry
// 0x0008
struct FStatColorMapEntry
{
	float                                              In;                                            // 0x0000 (0x0004) [0x0000000000044000] (CPF_Config | CPF_GlobalConfig)
	struct FColor                                      Out;                                           // 0x0004 (0x0004) [0x0000000000044000] (CPF_Config | CPF_GlobalConfig)
};

// ScriptStruct Engine.Engine.StatColorMapping
// 0x001C
struct FStatColorMapping
{
	class FString                                      StatName;                                      // 0x0000 (0x000C) [0x0000000000444000] (CPF_Config | CPF_GlobalConfig | CPF_NeedCtorLink)
	class TArray<struct FStatColorMapEntry>            ColorMap;                                      // 0x000C (0x000C) [0x0000000000444000] (CPF_Config | CPF_GlobalConfig | CPF_NeedCtorLink)
	uint32_t                                           DisableBlend : 1;                              // 0x0018 (0x0004) [0x0000000000044000] [0x00000001] (CPF_Config | CPF_GlobalConfig)
};

// ScriptStruct Engine.Engine.DropNoteInfo
// 0x0024
struct FDropNoteInfo
{
	struct FVector                                     Location;                                      // 0x0000 (0x000C) [0x0000000000000000]               
	struct FRotator                                    Rotation;                                      // 0x000C (0x000C) [0x0000000000000000]               
	class FString                                      Comment;                                       // 0x0018 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.Engine.AliceGamePlayerProfileData
// 0x0018
struct FAliceGamePlayerProfileData
{
	float                                              CompletPercent;                                // 0x0000 (0x0004) [0x0000000000000000]               
	float                                              PlayedHours;                                   // 0x0004 (0x0004) [0x0000000000000000]               
	float                                              PlayedMin;                                     // 0x0008 (0x0004) [0x0000000000000000]               
	class FString                                      PlayerName;                                    // 0x000C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.EngineTypes.MeshMaterialRef
// 0x0008
struct FMeshMaterialRef
{
	class UMeshComponent*                              MeshComp;                                      // 0x0000 (0x0004) [0x0000000004080008] (CPF_ExportObject | CPF_Component | CPF_EditInline)
	int32_t                                            MaterialIndex;                                 // 0x0004 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.EngineTypes.MaterialReferenceList
// 0x001C
struct FMaterialReferenceList
{
	class UMaterialInterface*                          TargetMaterial;                                // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class TArray<struct FMeshMaterialRef>              AffectedMeshMaterialRefs;                      // 0x0004 (0x000C) [0x0000020000480000] (CPF_Component | CPF_NeedCtorLink | CPF_EditHide)
	class TArray<class UDecalComponent*>               AffectedDecalMaterialRefs;                     // 0x0010 (0x000C) [0x0000020004480008] (CPF_ExportObject | CPF_Component | CPF_NeedCtorLink | CPF_EditInline | CPF_EditHide)
};

// ScriptStruct Engine.FluidSurfaceComponent.LightMapRef
// 0x0004
struct UFluidSurfaceComponent_FLightMapRef
{
	struct FPointer                                    Reference;                                     // 0x0000 (0x0004) [0x0000000000001002] (CPF_Const | CPF_Native)
};

// ScriptStruct Engine.FogVolumeDensityInfo.CheckpointRecord
// 0x0004
struct AFogVolumeDensityInfo_FCheckpointRecord
{
	uint32_t                                           bEnabled : 1;                                  // 0x0000 (0x0004) [0x0000000000000000] [0x00000001] 
};

// ScriptStruct Engine.FoliageComponent.FoliageInstanceBase
// 0x0034
struct FFoliageInstanceBase
{
	struct FVector                                     Location;                                      // 0x0000 (0x000C) [0x0000000000000000]               
	struct FVector                                     XAxis;                                         // 0x000C (0x000C) [0x0000000000000000]               
	struct FVector                                     YAxis;                                         // 0x0018 (0x000C) [0x0000000000000000]               
	struct FVector                                     ZAxis;                                         // 0x0024 (0x000C) [0x0000000000000000]               
	float                                              DistanceFactorSquared;                         // 0x0030 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.FoliageComponent.StoredFoliageInstance
// 0x000C (0x0034 - 0x0040)
struct FStoredFoliageInstance : FFoliageInstanceBase
{
	struct FColor                                      StaticLighting[3];                             // 0x0034 (0x000C) [0x0000000000000000]               
};

// ScriptStruct Engine.FoliageFactory.FoliageMesh
// 0x0064
struct FFoliageMesh
{
	class UStaticMesh*                                 InstanceStaticMesh;                            // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class UMaterialInterface*                          Material;                                      // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              MaxDrawRadius;                                 // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              MinTransitionRadius;                           // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              MinThinningRadius;                             // 0x0010 (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FVector                                     MinScale;                                      // 0x0014 (0x000C) [0x0000000000000001] (CPF_Edit)    
	struct FVector                                     MaxScale;                                      // 0x0020 (0x000C) [0x0000000000000001] (CPF_Edit)    
	float                                              MinUniformScale;                               // 0x002C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              MaxUniformScale;                               // 0x0030 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              SwayScale;                                     // 0x0034 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            Seed;                                          // 0x0038 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              SurfaceAreaPerInstance;                        // 0x003C (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bCreateInstancesOnBSP : 1;                     // 0x0040 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bCreateInstancesOnStaticMeshes : 1;            // 0x0040 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint32_t                                           bCreateInstancesOnTerrain : 1;                 // 0x0040 (0x0004) [0x0000000000000001] [0x00000004] (CPF_Edit)
	struct FLightmassPrimitiveSettings                 LightmassSettings;                             // 0x0044 (0x001C) [0x0000000000000001] (CPF_Edit)    
	class UFoliageComponent*                           Component;                                     // 0x0060 (0x0004) [0x0000000004080008] (CPF_ExportObject | CPF_Component | CPF_EditInline)
};

// ScriptStruct Engine.ForceFeedbackWaveform.WaveformSample
// 0x0008
struct FWaveformSample
{
	uint8_t                                            LeftAmplitude;                                 // 0x0000 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            RightAmplitude;                                // 0x0001 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            LeftFunction;                                  // 0x0002 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            RightFunction;                                 // 0x0003 (0x0001) [0x0000000000000001] (CPF_Edit)    
	float                                              Duration;                                      // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.FracturedStaticMeshComponent.FragmentGroup
// 0x0010
struct FFragmentGroup
{
	class TArray<int32_t>                              FragmentIndices;                               // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	uint32_t                                           bGroupIsRooted : 1;                            // 0x000C (0x0004) [0x0000000000000000] [0x00000001] 
};

// ScriptStruct Engine.FracturedStaticMeshActor.DeferredPartToSpawn
// 0x0024
struct FDeferredPartToSpawn
{
	int32_t                                            ChunkIndex;                                    // 0x0000 (0x0004) [0x0000000000000000]               
	struct FVector                                     InitialVel;                                    // 0x0004 (0x000C) [0x0000000000000000]               
	struct FVector                                     InitialAngVel;                                 // 0x0010 (0x000C) [0x0000000000000000]               
	float                                              RelativeScale;                                 // 0x001C (0x0004) [0x0000000000000000]               
	uint32_t                                           bExplosion : 1;                                // 0x0020 (0x0004) [0x0000000000000000] [0x00000001] 
};

// ScriptStruct Engine.GameEngine.LevelStreamingStatus
// 0x000C
struct FLevelStreamingStatus
{
	class FName                                        PackageName;                                   // 0x0000 (0x0008) [0x0000000000000000]               
	uint32_t                                           bShouldBeLoaded : 1;                           // 0x0008 (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bShouldBeVisible : 1;                          // 0x0008 (0x0004) [0x0000000000000000] [0x00000002] 
};

// ScriptStruct Engine.GameEngine.FullyLoadedPackagesInfo
// 0x0028
struct FFullyLoadedPackagesInfo
{
	uint8_t                                            FullyLoadType;                                 // 0x0000 (0x0001) [0x0000000000000000]               
	uint8_t                                            UnknownData00[0x3];                              // 0x0001 (0x0003) MISSED OFFSET
	class FString                                      Tag;                                           // 0x0004 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<class FName>                          PackagesToLoad;                                // 0x0010 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<class UObject*>                       LoadedObjects;                                 // 0x001C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.GameEngine.NamedNetDriver
// 0x000C
struct FNamedNetDriver
{
	class FName                                        NetDriverName;                                 // 0x0000 (0x0008) [0x0000000000000000]               
	struct FPointer                                    NetDriver;                                     // 0x0008 (0x0004) [0x0000000000001002] (CPF_Const | CPF_Native)
};

// ScriptStruct Engine.GameEngine.URL
// 0x0044
struct FURL
{
	class FString                                      Protocol;                                      // 0x0000 (0x000C) [0x0000000000500000] (CPF_NeedCtorLink)
	class FString                                      Host;                                          // 0x000C (0x000C) [0x0000000000500000] (CPF_NeedCtorLink)
	int32_t                                            Port;                                          // 0x0018 (0x0004) [0x0000000000100000]               
	class FString                                      Map;                                           // 0x001C (0x000C) [0x0000000000500000] (CPF_NeedCtorLink)
	class TArray<class FString>                        Op;                                            // 0x0028 (0x000C) [0x0000000000500000] (CPF_NeedCtorLink)
	class FString                                      Portal;                                        // 0x0034 (0x000C) [0x0000000000500000] (CPF_NeedCtorLink)
	int32_t                                            Valid;                                         // 0x0040 (0x0004) [0x0000000000100000]               
};

// ScriptStruct Engine.GameInfo.GameTypePrefix
// 0x0034
struct FGameTypePrefix
{
	class FString                                      Prefix;                                        // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	uint32_t                                           bUsesCommonPackage : 1;                        // 0x000C (0x0004) [0x0000000000000000] [0x00000001] 
	class FString                                      GameType;                                      // 0x0010 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<class FString>                        AdditionalGameTypes;                           // 0x001C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<class FString>                        ForcedObjects;                                 // 0x0028 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.GameInfo.GameClassShortName
// 0x0018
struct FGameClassShortName
{
	class FString                                      ShortName;                                     // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class FString                                      GameClassName;                                 // 0x000C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.GameViewportClient.TitleSafeZoneArea
// 0x0010
struct FTitleSafeZoneArea
{
	float                                              MaxPercentX;                                   // 0x0000 (0x0004) [0x0000000000000000]               
	float                                              MaxPercentY;                                   // 0x0004 (0x0004) [0x0000000000000000]               
	float                                              RecommendedPercentX;                           // 0x0008 (0x0004) [0x0000000000000000]               
	float                                              RecommendedPercentY;                           // 0x000C (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.GameViewportClient.PerPlayerSplitscreenData
// 0x0010
struct FPerPlayerSplitscreenData
{
	float                                              SizeX;                                         // 0x0000 (0x0004) [0x0000000000000000]               
	float                                              SizeY;                                         // 0x0004 (0x0004) [0x0000000000000000]               
	float                                              OriginX;                                       // 0x0008 (0x0004) [0x0000000000000000]               
	float                                              OriginY;                                       // 0x000C (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.GameViewportClient.SplitscreenData
// 0x000C
struct FSplitscreenData
{
	class TArray<struct FPerPlayerSplitscreenData>     PlayerData;                                    // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.GameViewportClient.DebugDisplayProperty
// 0x0010
struct FDebugDisplayProperty
{
	class UObject*                                     Obj;                                           // 0x0000 (0x0004) [0x0000000000000000]               
	class FName                                        PropertyName;                                  // 0x0004 (0x0008) [0x0000000000000000]               
	uint32_t                                           bSpecialProperty : 1;                          // 0x000C (0x0004) [0x0000000000000000] [0x00000001] 
};

// ScriptStruct Engine.Hair.Node
// 0x0010
struct FNode
{
	struct FVector                                     Position;                                      // 0x0000 (0x000C) [0x0000000000000000]               
	float                                              GuideRestitution;                              // 0x000C (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.Hair.Strand
// 0x0008
struct FStrand
{
	int32_t                                            StartNodeIndex;                                // 0x0000 (0x0004) [0x0000000000000000]               
	int32_t                                            NodeCount;                                     // 0x0004 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.Hair.Patch
// 0x000C
struct FPatch
{
	int32_t                                            StrandIndices[3];                              // 0x0000 (0x000C) [0x0000000000000000]               
};

// ScriptStruct Engine.IniLocPatcher.IniLocFileEntry
// 0x000D
struct FIniLocFileEntry
{
	class FString                                      Filename;                                      // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	uint8_t                                            ReadState;                                     // 0x000C (0x0001) [0x0000000000000000]               
	uint8_t                                            MinStructAlignment[0x3];                         // 0x000D (0x0003) ADDED PADDING
};

// ScriptStruct Engine.InstancedStaticMeshComponent.InstancedStaticMeshInstanceData
// 0x0050
struct FInstancedStaticMeshInstanceData
{
	struct FMatrix                                     Transform;                                     // 0x0000 (0x0040) [0x0000000000000000]               
	struct FVector2D                                   LightmapUVBias;                                // 0x0040 (0x0008) [0x0000000000000000]               
	struct FVector2D                                   ShadowmapUVBias;                               // 0x0048 (0x0008) [0x0000000000000000]               
};

// ScriptStruct Engine.InstancedStaticMeshComponent.InstancedStaticMeshMappingInfo
// 0x0010
struct FInstancedStaticMeshMappingInfo
{
	struct FPointer                                    Mapping;                                       // 0x0000 (0x0004) [0x0000000000001000] (CPF_Native)  
	struct FPointer                                    LightMap;                                      // 0x0004 (0x0004) [0x0000000000001000] (CPF_Native)  
	class UTexture2D*                                  LightmapTexture;                               // 0x0008 (0x0004) [0x0000000000000000]               
	class UShadowMap2D*                                ShadowmapTexture;                              // 0x000C (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.InterpActor.CheckpointRecord
// 0x0020
struct AInterpActor_FCheckpointRecord
{
	struct FVector                                     Location;                                      // 0x0000 (0x000C) [0x0000000000000000]               
	struct FRotator                                    Rotation;                                      // 0x000C (0x000C) [0x0000000000000000]               
	uint8_t                                            CollisionType;                                 // 0x0018 (0x0001) [0x0000000000000000]               
	uint8_t                                            UnknownData00[0x3];                              // 0x0019 (0x0003) MISSED OFFSET
	uint32_t                                           bHidden : 1;                                   // 0x001C (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bIsShutdown : 1;                               // 0x001C (0x0004) [0x0000000000000000] [0x00000002] 
	uint32_t                                           bNeedsPositionReplication : 1;                 // 0x001C (0x0004) [0x0000000000000000] [0x00000004] 
};

// ScriptStruct Engine.InterpCurveEdSetup.CurveEdEntry
// 0x002C
struct FCurveEdEntry
{
	class UObject*                                     CurveObject;                                   // 0x0000 (0x0004) [0x0000000000000000]               
	struct FColor                                      CurveColor;                                    // 0x0004 (0x0004) [0x0000000000000000]               
	class FString                                      CurveName;                                     // 0x0008 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	int32_t                                            bHideCurve;                                    // 0x0014 (0x0004) [0x0000000000000000]               
	int32_t                                            bColorCurve;                                   // 0x0018 (0x0004) [0x0000000000000000]               
	int32_t                                            bFloatingPointColorCurve;                      // 0x001C (0x0004) [0x0000000000000000]               
	int32_t                                            bClamp;                                        // 0x0020 (0x0004) [0x0000000000000000]               
	float                                              ClampLow;                                      // 0x0024 (0x0004) [0x0000000000000000]               
	float                                              ClampHigh;                                     // 0x0028 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.InterpCurveEdSetup.CurveEdTab
// 0x0028
struct FCurveEdTab
{
	class FString                                      TabName;                                       // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<struct FCurveEdEntry>                 Curves;                                        // 0x000C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	float                                              ViewStartInput;                                // 0x0018 (0x0004) [0x0000000000000000]               
	float                                              ViewEndInput;                                  // 0x001C (0x0004) [0x0000000000000000]               
	float                                              ViewStartOutput;                               // 0x0020 (0x0004) [0x0000000000000000]               
	float                                              ViewEndOutput;                                 // 0x0024 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.InterpGroup.InterpEdSelKey
// 0x0010
struct FInterpEdSelKey
{
	class UInterpGroup*                                Group;                                         // 0x0000 (0x0004) [0x0000000000000000]               
	int32_t                                            TrackIndex;                                    // 0x0004 (0x0004) [0x0000000000000000]               
	int32_t                                            KeyIndex;                                      // 0x0008 (0x0004) [0x0000000000000000]               
	float                                              UnsnappedPosition;                             // 0x000C (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.InterpTrackAnimControl.AnimControlTrackKey
// 0x001C
struct FAnimControlTrackKey
{
	float                                              StartTime;                                     // 0x0000 (0x0004) [0x0000000000000000]               
	class FName                                        AnimSeqName;                                   // 0x0004 (0x0008) [0x0000000000000000]               
	float                                              AnimStartOffset;                               // 0x000C (0x0004) [0x0000000000000000]               
	float                                              AnimEndOffset;                                 // 0x0010 (0x0004) [0x0000000000000000]               
	float                                              AnimPlayRate;                                  // 0x0014 (0x0004) [0x0000000000000000]               
	uint32_t                                           bLooping : 1;                                  // 0x0018 (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bReverse : 1;                                  // 0x0018 (0x0004) [0x0000000000000000] [0x00000002] 
	uint32_t                                           bDiscardRootMotion : 1;                        // 0x0018 (0x0004) [0x0000000000000000] [0x00000004] 
	uint32_t                                           bDiscardRootMotionFull : 1;                    // 0x0018 (0x0004) [0x0000000000000000] [0x00000008] 
	uint32_t                                           bMoveRootMotion : 1;                           // 0x0018 (0x0004) [0x0000000000000000] [0x00000010] 
};

// ScriptStruct Engine.InterpTrackDirector.DirectorTrackCut
// 0x0010
struct FDirectorTrackCut
{
	float                                              Time;                                          // 0x0000 (0x0004) [0x0000000000000000]               
	float                                              TransitionTime;                                // 0x0004 (0x0004) [0x0000000000000000]               
	class FName                                        TargetCamGroup;                                // 0x0008 (0x0008) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.InterpTrackEvent.EventTrackKey
// 0x000C
struct FEventTrackKey
{
	float                                              Time;                                          // 0x0000 (0x0004) [0x0000000000000000]               
	class FName                                        EventName;                                     // 0x0004 (0x0008) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.InterpTrackEventPPEffect.EventPPEffect_MatParameter
// 0x0010
struct FEventPPEffect_MatParameter
{
	class FName                                        ParamName;                                     // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	float                                              ScalarValue;                                   // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bActiveVaryingTime : 1;                        // 0x000C (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
};

// ScriptStruct Engine.InterpTrackEventPPEffect.PPEffectEvent
// 0x0020
struct FPPEffectEvent
{
	float                                              Time;                                          // 0x0000 (0x0004) [0x0000000000000000]               
	class FName                                        EffectName;                                    // 0x0004 (0x0008) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bShowInEditor : 1;                             // 0x000C (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bShowInGame : 1;                               // 0x000C (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint32_t                                           bSetNewMaterial : 1;                           // 0x000C (0x0004) [0x0000000000000001] [0x00000004] (CPF_Edit)
	uint32_t                                           bUseScreenAsTexture : 1;                       // 0x000C (0x0004) [0x0000000000000001] [0x00000008] (CPF_Edit)
	class UMaterialInterface*                          NewMaterial;                                   // 0x0010 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class TArray<struct FEventPPEffect_MatParameter>   MatParameters;                                 // 0x0014 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
};

// ScriptStruct Engine.InterpTrackFaceFX.FaceFXTrackKey
// 0x001C
struct FFaceFXTrackKey
{
	float                                              StartTime;                                     // 0x0000 (0x0004) [0x0000000000000000]               
	class FString                                      FaceFXGroupName;                               // 0x0004 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class FString                                      FaceFXSeqName;                                 // 0x0010 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.InterpTrackFaceFX.FaceFXSoundCueKey
// 0x0004
struct FFaceFXSoundCueKey
{
	class USoundCue*                                   FaceFXSoundCue;                                // 0x0000 (0x0004) [0x0000000000000002] (CPF_Const)   
};

// ScriptStruct Engine.InterpTrackInstFloatMaterialParam.FloatMaterialParamMICData
// 0x0030
struct FFloatMaterialParamMICData
{
	class TArray<class UMaterialInstanceConstant*>     MeshMICs;                                      // 0x0000 (0x000C) [0x0000000000400002] (CPF_Const | CPF_NeedCtorLink)
	class TArray<float>                                MeshMICResetFloats;                            // 0x000C (0x000C) [0x0000000000400002] (CPF_Const | CPF_NeedCtorLink)
	class TArray<class UMaterialInstanceConstant*>     DecalMICs;                                     // 0x0018 (0x000C) [0x0000000000400002] (CPF_Const | CPF_NeedCtorLink)
	class TArray<float>                                DecalMICResetFloats;                           // 0x0024 (0x000C) [0x0000000000400002] (CPF_Const | CPF_NeedCtorLink)
};

// ScriptStruct Engine.InterpTrackToggle.ToggleTrackKey
// 0x0005
struct FToggleTrackKey
{
	float                                              Time;                                          // 0x0000 (0x0004) [0x0000000000000000]               
	uint8_t                                            ToggleAction;                                  // 0x0004 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            MinStructAlignment[0x3];                         // 0x0005 (0x0003) ADDED PADDING
};

// ScriptStruct Engine.InterpTrackInstVectorMaterialParam.VectorMaterialParamMICData
// 0x0030
struct FVectorMaterialParamMICData
{
	class TArray<class UMaterialInstanceConstant*>     MeshMICs;                                      // 0x0000 (0x000C) [0x0000000000400002] (CPF_Const | CPF_NeedCtorLink)
	class TArray<struct FVector>                       MeshMICResetVectors;                           // 0x000C (0x000C) [0x0000000000400002] (CPF_Const | CPF_NeedCtorLink)
	class TArray<class UMaterialInstanceConstant*>     DecalMICs;                                     // 0x0018 (0x000C) [0x0000000000400002] (CPF_Const | CPF_NeedCtorLink)
	class TArray<struct FVector>                       DecalMICResetVectors;                          // 0x0024 (0x000C) [0x0000000000400002] (CPF_Const | CPF_NeedCtorLink)
};

// ScriptStruct Engine.InterpTrackVisibility.VisibilityTrackKey
// 0x0006
struct FVisibilityTrackKey
{
	float                                              Time;                                          // 0x0000 (0x0004) [0x0000000000000000]               
	uint8_t                                            Action;                                        // 0x0004 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            ActiveCondition;                               // 0x0005 (0x0001) [0x0000000000000000]               
	uint8_t                                            MinStructAlignment[0x2];                         // 0x0006 (0x0002) ADDED PADDING
};

// ScriptStruct Engine.InterpTrackMove.InterpLookupPoint
// 0x000C
struct FInterpLookupPoint
{
	class FName                                        GroupName;                                     // 0x0000 (0x0008) [0x0000000000000000]               
	float                                              Time;                                          // 0x0008 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.InterpTrackMove.InterpLookupTrack
// 0x000C
struct FInterpLookupTrack
{
	class TArray<struct FInterpLookupPoint>            Points;                                        // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.InterpTrackParticleReplay.ParticleReplayTrackKey
// 0x000C
struct FParticleReplayTrackKey
{
	float                                              Time;                                          // 0x0000 (0x0004) [0x0000000000000000]               
	float                                              Duration;                                      // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            ClipIDNumber;                                  // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.InterpTrackSound.SoundTrackKey
// 0x0010
struct FSoundTrackKey
{
	float                                              Time;                                          // 0x0000 (0x0004) [0x0000000000000000]               
	float                                              Volume;                                        // 0x0004 (0x0004) [0x0000000000000000]               
	float                                              Pitch;                                         // 0x0008 (0x0004) [0x0000000000000000]               
	class USoundCue*                                   Sound;                                         // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.LensFlare.LensFlareElement
// 0x0140
struct FLensFlareElement
{
	class FName                                        ElementName;                                   // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	float                                              RayDistance;                                   // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bIsEnabled : 1;                                // 0x000C (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bUseSourceDistance : 1;                        // 0x000C (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint32_t                                           bNormalizeRadialDistance : 1;                  // 0x000C (0x0004) [0x0000000000000001] [0x00000004] (CPF_Edit)
	uint32_t                                           bModulateColorBySource : 1;                    // 0x000C (0x0004) [0x0000000000000001] [0x00000008] (CPF_Edit)
	struct FVector                                     Size;                                          // 0x0010 (0x000C) [0x0000000000000001] (CPF_Edit)    
	class TArray<class UMaterialInterface*>            LFMaterials;                                   // 0x001C (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	struct FRawDistributionFloat                       LFMaterialIndex;                               // 0x0028 (0x001C) [0x0000000000480001] (CPF_Edit | CPF_Component | CPF_NeedCtorLink)
	struct FRawDistributionFloat                       Scaling;                                       // 0x0044 (0x001C) [0x0000000000480001] (CPF_Edit | CPF_Component | CPF_NeedCtorLink)
	struct FRawDistributionVector                      AxisScaling;                                   // 0x0060 (0x001C) [0x0000000000480001] (CPF_Edit | CPF_Component | CPF_NeedCtorLink)
	struct FRawDistributionFloat                       Rotation;                                      // 0x007C (0x001C) [0x0000000000480001] (CPF_Edit | CPF_Component | CPF_NeedCtorLink)
	struct FRawDistributionVector                      Color;                                         // 0x0098 (0x001C) [0x0000000000480001] (CPF_Edit | CPF_Component | CPF_NeedCtorLink)
	struct FRawDistributionFloat                       Alpha;                                         // 0x00B4 (0x001C) [0x0000000000480001] (CPF_Edit | CPF_Component | CPF_NeedCtorLink)
	struct FRawDistributionVector                      Offset;                                        // 0x00D0 (0x001C) [0x0000000000480001] (CPF_Edit | CPF_Component | CPF_NeedCtorLink)
	struct FRawDistributionVector                      DistMap_Scale;                                 // 0x00EC (0x001C) [0x0000000000480001] (CPF_Edit | CPF_Component | CPF_NeedCtorLink)
	struct FRawDistributionVector                      DistMap_Color;                                 // 0x0108 (0x001C) [0x0000000000480001] (CPF_Edit | CPF_Component | CPF_NeedCtorLink)
	struct FRawDistributionFloat                       DistMap_Alpha;                                 // 0x0124 (0x001C) [0x0000000000480001] (CPF_Edit | CPF_Component | CPF_NeedCtorLink)
};

// ScriptStruct Engine.LensFlare.LensFlareElementCurvePair
// 0x0010
struct FLensFlareElementCurvePair
{
	class FString                                      CurveName;                                     // 0x0000 (0x000C) [0x0000000000500000] (CPF_NeedCtorLink)
	class UObject*                                     CurveObject;                                   // 0x000C (0x0004) [0x0000000000100000]               
};

// ScriptStruct Engine.LensFlareComponent.LensFlareElementInstance
// 0x0000
struct FLensFlareElementInstance
{
};

// ScriptStruct Engine.LevelGridVolume.LevelGridCellCoordinate
// 0x000C
struct FLevelGridCellCoordinate
{
	int32_t                                            X;                                             // 0x0000 (0x0004) [0x0000000000000000]               
	int32_t                                            Y;                                             // 0x0004 (0x0004) [0x0000000000000000]               
	int32_t                                            Z;                                             // 0x0008 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.LevelStreamingVolume.CheckpointRecord
// 0x0004
struct ALevelStreamingVolume_FCheckpointRecord
{
	uint32_t                                           bDisabled : 1;                                 // 0x0000 (0x0004) [0x0000000000000000] [0x00000001] 
};

// ScriptStruct Engine.LocalPlayer.CurrentPostProcessVolumeInfo
// 0x00F4
struct FCurrentPostProcessVolumeInfo
{
	struct FPostProcessSettings                        LastSettings;                                  // 0x0000 (0x00E8) [0x0000000000000000]               
	class APostProcessVolume*                          LastVolumeUsed;                                // 0x00E8 (0x0004) [0x0000000000000000]               
	float                                              BlendStartTime;                                // 0x00EC (0x0004) [0x0000000000000000]               
	float                                              LastBlendTime;                                 // 0x00F0 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.LocalPlayer.SynchronizedActorVisibilityHistory
// 0x0008
struct FSynchronizedActorVisibilityHistory
{
	struct FPointer                                    State;                                         // 0x0000 (0x0004) [0x0000000000000000]               
	struct FPointer                                    CriticalSection;                               // 0x0004 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.MaterialExpression.ExpressionInput
// 0x001C
struct FExpressionInput
{
	class UMaterialExpression*                         Expression;                                    // 0x0000 (0x0004) [0x0000000000000000]               
	int32_t                                            Mask;                                          // 0x0004 (0x0004) [0x0000000000000000]               
	int32_t                                            MaskR;                                         // 0x0008 (0x0004) [0x0000000000000000]               
	int32_t                                            MaskG;                                         // 0x000C (0x0004) [0x0000000000000000]               
	int32_t                                            MaskB;                                         // 0x0010 (0x0004) [0x0000000000000000]               
	int32_t                                            MaskA;                                         // 0x0014 (0x0004) [0x0000000000000000]               
	int32_t                                            GCC64_Padding;                                 // 0x0018 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.MaterialExpressionCustom.CustomInput
// 0x0028
struct FCustomInput
{
	class FString                                      InputName;                                     // 0x0000 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	struct FExpressionInput                            Input;                                         // 0x000C (0x001C) [0x0000020000000000] (CPF_EditHide)
};

// ScriptStruct Engine.MaterialInstanceConstant.FontParameterValue
// 0x0020
struct FFontParameterValue
{
	class FName                                        ParameterName;                                 // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	class UFont*                                       FontValue;                                     // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            FontPage;                                      // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FGuid                                       ExpressionGUID;                                // 0x0010 (0x0010) [0x0000000000000000]               
};

// ScriptStruct Engine.MaterialInstanceConstant.ScalarParameterValue
// 0x001C
struct FScalarParameterValue
{
	class FName                                        ParameterName;                                 // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	float                                              ParameterValue;                                // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FGuid                                       ExpressionGUID;                                // 0x000C (0x0010) [0x0000000000000000]               
};

// ScriptStruct Engine.MaterialInstanceConstant.TextureParameterValue
// 0x001C
struct FTextureParameterValue
{
	class FName                                        ParameterName;                                 // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	class UTexture*                                    ParameterValue;                                // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FGuid                                       ExpressionGUID;                                // 0x000C (0x0010) [0x0000000000000000]               
};

// ScriptStruct Engine.MaterialInstanceConstant.VectorParameterValue
// 0x0028
struct FVectorParameterValue
{
	class FName                                        ParameterName;                                 // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	struct FLinearColor                                ParameterValue;                                // 0x0008 (0x0010) [0x0000000000000001] (CPF_Edit)    
	struct FGuid                                       ExpressionGUID;                                // 0x0018 (0x0010) [0x0000000000000000]               
};

// ScriptStruct Engine.MaterialInstanceTimeVarying.ParameterValueOverTime
// 0x0030
struct FParameterValueOverTime
{
	struct FGuid                                       ExpressionGUID;                                // 0x0000 (0x0010) [0x0000000000000000]               
	float                                              StartTime;                                     // 0x0010 (0x0004) [0x0000000000002000] (CPF_Transient)
	class FName                                        ParameterName;                                 // 0x0014 (0x0008) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bLoop : 1;                                     // 0x001C (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bAutoActivate : 1;                             // 0x001C (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	float                                              CycleTime;                                     // 0x0020 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bNormalizeTime : 1;                            // 0x0024 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	float                                              OffsetTime;                                    // 0x0028 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bOffsetFromEnd : 1;                            // 0x002C (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
};

// ScriptStruct Engine.MaterialInstanceTimeVarying.FontParameterValueOverTime
// 0x0008 (0x0030 - 0x0038)
struct FFontParameterValueOverTime : FParameterValueOverTime
{
	class UFont*                                       FontValue;                                     // 0x0030 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            FontPage;                                      // 0x0034 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.MaterialInstanceTimeVarying.ScalarParameterValueOverTime
// 0x0014 (0x0030 - 0x0044)
struct FScalarParameterValueOverTime : FParameterValueOverTime
{
	float                                              ParameterValue;                                // 0x0030 (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FInterpCurveFloat                           ParameterValueCurve;                           // 0x0034 (0x0010) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
};

// ScriptStruct Engine.MaterialInstanceTimeVarying.TextureParameterValueOverTime
// 0x0004 (0x0030 - 0x0034)
struct FTextureParameterValueOverTime : FParameterValueOverTime
{
	class UTexture*                                    ParameterValue;                                // 0x0030 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.MaterialInstanceTimeVarying.VectorParameterValueOverTime
// 0x0020 (0x0030 - 0x0050)
struct FVectorParameterValueOverTime : FParameterValueOverTime
{
	struct FLinearColor                                ParameterValue;                                // 0x0030 (0x0010) [0x0000000000000001] (CPF_Edit)    
	struct FInterpCurveVector                          ParameterValueCurve;                           // 0x0040 (0x0010) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
};

// ScriptStruct Engine.MorphNodePose.MorphMaterialParameter
// 0x0010
struct FMorphMaterialParameter
{
	int32_t                                            MorphMaterialSlotID;                           // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class FName                                        ScalarParameterName;                           // 0x0004 (0x0008) [0x0000000000000001] (CPF_Edit)    
	class UMaterialInstanceConstant*                   MaterialInstanceConstant;                      // 0x000C (0x0004) [0x0000000000002000] (CPF_Transient)
};

// ScriptStruct Engine.MorphNodeWeightBase.MorphNodeConn
// 0x0018
struct FMorphNodeConn
{
	class TArray<class UMorphNodeBase*>                ChildNodes;                                    // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class FName                                        ConnName;                                      // 0x000C (0x0008) [0x0000000000000000]               
	int32_t                                            DrawY;                                         // 0x0014 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.MorphNodeWeightByBoneAngle.BoneAngleMorph
// 0x0008
struct FBoneAngleMorph
{
	float                                              Angle;                                         // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              TargetWeight;                                  // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.NavigationHandle.PolySegmentSpan
// 0x001C
struct FPolySegmentSpan
{
	struct FPointer                                    Poly;                                          // 0x0000 (0x0004) [0x0000000000001000] (CPF_Native)  
	struct FVector                                     P1;                                            // 0x0004 (0x000C) [0x0000000000000000]               
	struct FVector                                     P2;                                            // 0x0010 (0x000C) [0x0000000000000000]               
};

// ScriptStruct Engine.NavigationHandle.NavMeshPathParams
// 0x002C
struct FNavMeshPathParams
{
	struct FPointer                                    Interface;                                     // 0x0000 (0x0004) [0x0000000000001000] (CPF_Native)  
	uint32_t                                           bCanMantle : 1;                                // 0x0004 (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bNeedsMantleValidityTest : 1;                  // 0x0004 (0x0004) [0x0000000000000000] [0x00000002] 
	uint32_t                                           bAbleToSearch : 1;                             // 0x0004 (0x0004) [0x0000000000000000] [0x00000004] 
	struct FVector                                     SearchExtent;                                  // 0x0008 (0x000C) [0x0000000000000000]               
	struct FVector                                     SearchStart;                                   // 0x0014 (0x000C) [0x0000000000000000]               
	float                                              MaxDropHeight;                                 // 0x0020 (0x0004) [0x0000000000000000]               
	float                                              MinWalkableZ;                                  // 0x0024 (0x0004) [0x0000000000000000]               
	float                                              MaxHoverDistance;                              // 0x0028 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.NavigationHandle.EdgePointer
// 0x0004
struct FEdgePointer
{
	struct FPointer                                    Dummy;                                         // 0x0000 (0x0004) [0x0000000000001002] (CPF_Const | CPF_Native)
};

// ScriptStruct Engine.NavigationHandle.PathStore
// 0x000C
struct FPathStore
{
	class TArray<struct FEdgePointer>                  EdgeList;                                      // 0x0000 (0x000C) [0x0000000000001002] (CPF_Const | CPF_Native)
};

// ScriptStruct Engine.NavMeshPathGoalEvaluator.BiasedGoalActor
// 0x0008
struct FBiasedGoalActor
{
	class AActor*                                      Goal;                                          // 0x0000 (0x0004) [0x0000000000000000]               
	int32_t                                            ExtraCost;                                     // 0x0004 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.OnlineGameplayEvents.PlayerInformation
// 0x0028
struct FPlayerInformation
{
	class FString                                      ControllerName;                                // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class FString                                      PlayerName;                                    // 0x000C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	struct FUniqueNetId                                UniqueId;                                      // 0x0018 (0x0008) [0x0000000000000000]               
	uint32_t                                           bIsBot : 1;                                    // 0x0020 (0x0004) [0x0000000000000000] [0x00000001] 
	int32_t                                            LastPlayerEventIdx;                            // 0x0024 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.OnlineGameplayEvents.GameplayEvent
// 0x0008
struct FGameplayEvent
{
	int32_t                                            PlayerEventAndTarget;                          // 0x0000 (0x0004) [0x0000000000000000]               
	int32_t                                            EventNameAndDesc;                              // 0x0004 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.OnlineGameplayEvents.PlayerEvent
// 0x0018
struct FPlayerEvent
{
	float                                              EventTime;                                     // 0x0000 (0x0004) [0x0000000000000000]               
	struct FVector                                     EventLocation;                                 // 0x0004 (0x000C) [0x0000000000000000]               
	int32_t                                            PlayerIndexAndYaw;                             // 0x0010 (0x0004) [0x0000000000000000]               
	int32_t                                            PlayerPitchAndRoll;                            // 0x0014 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.OnlinePlayerStorage.OnlineProfileSetting
// 0x0018
struct FOnlineProfileSetting
{
	uint8_t                                            Owner;                                         // 0x0000 (0x0001) [0x0000000000000000]               
	uint8_t                                            UnknownData00[0x3];                              // 0x0001 (0x0003) MISSED OFFSET
	struct FSettingsProperty                           ProfileSetting;                                // 0x0004 (0x0014) [0x0000000000000000]               
};

// ScriptStruct Engine.OnlinePlaylistManager.ConfiguredGameSetting
// 0x0020
struct FConfiguredGameSetting
{
	int32_t                                            GameSettingId;                                 // 0x0000 (0x0004) [0x0000000000000000]               
	class FString                                      GameSettingsClassName;                         // 0x0004 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class FString                                      URL;                                           // 0x0010 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class UOnlineGameSettings*                         GameSettings;                                  // 0x001C (0x0004) [0x0000000000002000] (CPF_Transient)
};

// ScriptStruct Engine.OnlinePlaylistManager.Playlist
// 0x0040
struct FPlaylist
{
	class TArray<struct FConfiguredGameSetting>        ConfiguredGames;                               // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	int32_t                                            PlaylistId;                                    // 0x000C (0x0004) [0x0000000000000000]               
	class FString                                      LocalizationString;                            // 0x0010 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<int32_t>                              ContentIds;                                    // 0x001C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	int32_t                                            TeamSize;                                      // 0x0028 (0x0004) [0x0000000000000000]               
	int32_t                                            TeamCount;                                     // 0x002C (0x0004) [0x0000000000000000]               
	class FString                                      Name;                                          // 0x0030 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	uint32_t                                           bIsArbitrated : 1;                             // 0x003C (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bDisableDedicatedServerSearches : 1;           // 0x003C (0x0004) [0x0000000000000000] [0x00000002] 
};

// ScriptStruct Engine.OnlineRecentPlayersList.RecentParty
// 0x0014
struct FRecentParty
{
	struct FUniqueNetId                                PartyLeader;                                   // 0x0000 (0x0008) [0x0000000000000000]               
	class TArray<struct FUniqueNetId>                  PartyMembers;                                  // 0x0008 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.OnlineRecentPlayersList.CurrentPlayerMet
// 0x0010
struct FCurrentPlayerMet
{
	int32_t                                            TeamNum;                                       // 0x0000 (0x0004) [0x0000000000000000]               
	int32_t                                            Skill;                                         // 0x0004 (0x0004) [0x0000000000000000]               
	struct FUniqueNetId                                NetId;                                         // 0x0008 (0x0008) [0x0000000000000000]               
};

// ScriptStruct Engine.OnlineStatsRead.OnlineStatsColumn
// 0x0010
struct FOnlineStatsColumn
{
	int32_t                                            ColumnNo;                                      // 0x0000 (0x0004) [0x0000000000000000]               
	struct FSettingsData                               StatValue;                                     // 0x0004 (0x000C) [0x0000000000000000]               
};

// ScriptStruct Engine.OnlineStatsRead.OnlineStatsRow
// 0x002C
struct FOnlineStatsRow
{
	struct FUniqueNetId                                PlayerID;                                      // 0x0000 (0x0008) [0x0000000000000002] (CPF_Const)   
	struct FSettingsData                               Rank;                                          // 0x0008 (0x000C) [0x0000000000000002] (CPF_Const)   
	class FString                                      NickName;                                      // 0x0014 (0x000C) [0x0000000000400002] (CPF_Const | CPF_NeedCtorLink)
	class TArray<struct FOnlineStatsColumn>            Columns;                                       // 0x0020 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.OnlineStatsRead.ColumnMetaData
// 0x0018
struct FColumnMetaData
{
	int32_t                                            Id;                                            // 0x0000 (0x0004) [0x0000000000000002] (CPF_Const)   
	class FName                                        Name;                                          // 0x0004 (0x0008) [0x0000000000000002] (CPF_Const)   
	class FString                                      ColumnName;                                    // 0x000C (0x000C) [0x0000000000408002] (CPF_Const | CPF_Localized | CPF_NeedCtorLink)
};

// ScriptStruct Engine.ParticleEmitter.ParticleBurst
// 0x000C
struct FParticleBurst
{
	int32_t                                            Count;                                         // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            CountLow;                                      // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              Time;                                          // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.ParticleModule.ParticleCurvePair
// 0x0010
struct FParticleCurvePair
{
	class FString                                      CurveName;                                     // 0x0000 (0x000C) [0x0000000000500000] (CPF_NeedCtorLink)
	class UObject*                                     CurveObject;                                   // 0x000C (0x0004) [0x0000000000100000]               
};

// ScriptStruct Engine.ParticleModuleBeamModifier.BeamModifierOptions
// 0x0004
struct FBeamModifierOptions
{
	uint32_t                                           bModify : 1;                                   // 0x0000 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bScale : 1;                                    // 0x0000 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint32_t                                           bLock : 1;                                     // 0x0000 (0x0004) [0x0000000000000001] [0x00000004] (CPF_Edit)
};

// ScriptStruct Engine.ParticleModuleEventGenerator.ParticleEvent_GenerateInfo
// 0x0028
struct FParticleEvent_GenerateInfo
{
	uint8_t                                            Type;                                          // 0x0000 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            UnknownData00[0x3];                              // 0x0001 (0x0003) MISSED OFFSET
	int32_t                                            Frequency;                                     // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            LowFreq;                                       // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            ParticleFrequency;                             // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           FirstTimeOnly : 1;                             // 0x0010 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           LastTimeOnly : 1;                              // 0x0010 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint32_t                                           UseReflectedImpactVector : 1;                  // 0x0010 (0x0004) [0x0000000000000001] [0x00000004] (CPF_Edit)
	class FName                                        CustomName;                                    // 0x0014 (0x0008) [0x0000000000000001] (CPF_Edit)    
	class TArray<class UParticleModuleEventSendToGame*> ParticleModuleEventsToSendToGame;              // 0x001C (0x000C) [0x0000000004400001] (CPF_Edit | CPF_NeedCtorLink | CPF_EditInline)
};

// ScriptStruct Engine.ParticleModuleOrbit.OrbitOptions
// 0x0004
struct FOrbitOptions
{
	uint32_t                                           bProcessDuringSpawn : 1;                       // 0x0000 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bProcessDuringUpdate : 1;                      // 0x0000 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint32_t                                           bUseEmitterTime : 1;                           // 0x0000 (0x0004) [0x0000000000000001] [0x00000004] (CPF_Edit)
};

// ScriptStruct Engine.ParticleModuleParameterDynamic.EmitterDynamicParameter
// 0x0030
struct FEmitterDynamicParameter
{
	class FName                                        ParamName;                                     // 0x0000 (0x0008) [0x0000000000020001] (CPF_Edit | CPF_EditConst)
	uint32_t                                           bUseEmitterTime : 1;                           // 0x0008 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bSpawnTimeOnly : 1;                            // 0x0008 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint8_t                                            ValueMethod;                                   // 0x000C (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            UnknownData00[0x3];                              // 0x000D (0x0003) MISSED OFFSET
	uint32_t                                           bScaleVelocityByParamValue : 1;                // 0x0010 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	struct FRawDistributionFloat                       ParamValue;                                    // 0x0014 (0x001C) [0x0000000000480001] (CPF_Edit | CPF_Component | CPF_NeedCtorLink)
};

// ScriptStruct Engine.ParticleModuleTypeDataBeam2.BeamTargetData
// 0x000C
struct FBeamTargetData
{
	class FName                                        TargetName;                                    // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	float                                              TargetPercentage;                              // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.ParticleModuleTypeDataPhysX.PhysXEmitterVerticalLodProperties
// 0x0010
struct FPhysXEmitterVerticalLodProperties
{
	float                                              WeightForFifo;                                 // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              WeightForSpawnLod;                             // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              SpawnLodRateVsLifeBias;                        // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              RelativeFadeoutTime;                           // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.ParticleSystem.ParticleSystemLOD
// 0x0004
struct FParticleSystemLOD
{
	uint32_t                                           bLit : 1;                                      // 0x0000 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
};

// ScriptStruct Engine.ParticleSystem.LODSoloTrack
// 0x000C
struct FLODSoloTrack
{
	class TArray<uint8_t>                              SoloEnableSetting;                             // 0x0000 (0x000C) [0x0000000000402000] (CPF_Transient | CPF_NeedCtorLink)
};

// ScriptStruct Engine.ParticleSystemReplay.ParticleEmitterReplayFrame
// 0x000C
struct FParticleEmitterReplayFrame
{
	int32_t                                            EmitterType;                                   // 0x0000 (0x0004) [0x0000000000001002] (CPF_Const | CPF_Native)
	int32_t                                            OriginalEmitterIndex;                          // 0x0004 (0x0004) [0x0000000000001002] (CPF_Const | CPF_Native)
	struct FPointer                                    FrameState;                                    // 0x0008 (0x0004) [0x0000000000001002] (CPF_Const | CPF_Native)
};

// ScriptStruct Engine.ParticleSystemReplay.ParticleSystemReplayFrame
// 0x000C
struct FParticleSystemReplayFrame
{
	class TArray<struct FParticleEmitterReplayFrame>   Emitters;                                      // 0x0000 (0x000C) [0x0000000000001002] (CPF_Const | CPF_Native)
};

// ScriptStruct Engine.PBRuleNodeBase.PBRuleLink
// 0x0010
struct FPBRuleLink
{
	class UPBRuleNodeBase*                             NextRule;                                      // 0x0000 (0x0004) [0x0000000004400009] (CPF_Edit | CPF_ExportObject | CPF_NeedCtorLink | CPF_EditInline)
	class FName                                        LinkName;                                      // 0x0004 (0x0008) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            DrawY;                                         // 0x000C (0x0004) [0x0000000800000000] (CPF_EditorOnly)
};

// ScriptStruct Engine.ProcBuilding.PBMaterialParam
// 0x0018
struct FPBMaterialParam
{
	class FName                                        ParamName;                                     // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	struct FLinearColor                                Color;                                         // 0x0008 (0x0010) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.ProcBuildingRuleset.PBParamSwatch
// 0x0014
struct FPBParamSwatch
{
	class FName                                        SwatchName;                                    // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	class TArray<struct FPBMaterialParam>              Params;                                        // 0x0008 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
};

// ScriptStruct Engine.ProcBuildingRuleset.PBVariationInfo
// 0x000C
struct FPBVariationInfo
{
	class FName                                        VariationName;                                 // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bMeshOnTopOfFacePoly : 1;                      // 0x0008 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
};

// ScriptStruct Engine.ProcBuilding.PBFracMeshCompInfo
// 0x0008
struct FPBFracMeshCompInfo
{
	class UFracturedStaticMeshComponent*               FracMeshComp;                                  // 0x0000 (0x0004) [0x0000000004080008] (CPF_ExportObject | CPF_Component | CPF_EditInline)
	int32_t                                            TopLevelScopeIndex;                            // 0x0004 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.ProcBuilding.PBFaceUVInfo
// 0x0010
struct FPBFaceUVInfo
{
	struct FVector2D                                   Offset;                                        // 0x0000 (0x0008) [0x0000000000000000]               
	struct FVector2D                                   Size;                                          // 0x0008 (0x0008) [0x0000000000000000]               
};

// ScriptStruct Engine.ProcBuilding.PBMemUsageInfo
// 0x0024
struct FPBMemUsageInfo
{
	class AProcBuilding*                               Building;                                      // 0x0000 (0x0004) [0x0000000000000000]               
	class UProcBuildingRuleset*                        Ruleset;                                       // 0x0004 (0x0004) [0x0000000000000000]               
	int32_t                                            NumStaticMeshComponent;                        // 0x0008 (0x0004) [0x0000000000000000]               
	int32_t                                            NumInstancedStaticMeshComponents;              // 0x000C (0x0004) [0x0000000000000000]               
	int32_t                                            NumInstancedTris;                              // 0x0010 (0x0004) [0x0000000000000000]               
	int32_t                                            LightmapMemBytes;                              // 0x0014 (0x0004) [0x0000000000000000]               
	int32_t                                            ShadowmapMemBytes;                             // 0x0018 (0x0004) [0x0000000000000000]               
	int32_t                                            LODDiffuseMemBytes;                            // 0x001C (0x0004) [0x0000000000000000]               
	int32_t                                            LODLightingMemBytes;                           // 0x0020 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.ProcBuilding.PBMeshCompInfo
// 0x0008
struct FPBMeshCompInfo
{
	class UStaticMeshComponent*                        MeshComp;                                      // 0x0000 (0x0004) [0x0000000004080008] (CPF_ExportObject | CPF_Component | CPF_EditInline)
	int32_t                                            TopLevelScopeIndex;                            // 0x0004 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.ProcBuilding.PBScopeProcessInfo
// 0x0014
struct FPBScopeProcessInfo
{
	class AProcBuilding*                               OwningBuilding;                                // 0x0000 (0x0004) [0x0000000000000000]               
	class UProcBuildingRuleset*                        Ruleset;                                       // 0x0004 (0x0004) [0x0000000000000000]               
	class FName                                        RulesetVariation;                              // 0x0008 (0x0008) [0x0000000000000000]               
	uint32_t                                           bGenerateLODPoly : 1;                          // 0x0010 (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bPartOfNonRect : 1;                            // 0x0010 (0x0004) [0x0000000000000000] [0x00000002] 
};

// ScriptStruct Engine.ProcBuilding.PBScope2D
// 0x0048
struct FPBScope2D
{
	struct FMatrix                                     ScopeFrame;                                    // 0x0000 (0x0040) [0x0000000000000000]               
	float                                              DimX;                                          // 0x0040 (0x0004) [0x0000000000000000]               
	float                                              DimZ;                                          // 0x0044 (0x0004) [0x0000000000000000]               
	uint8_t                                            MinStructAlignment[0x8];                         // 0x0048 (0x0008) ADDED PADDING
};

// ScriptStruct Engine.ProcBuilding.PBEdgeInfo
// 0x002C
struct FPBEdgeInfo
{
	struct FVector                                     EdgeEnd;                                       // 0x0000 (0x000C) [0x0000000000000000]               
	struct FVector                                     EdgeStart;                                     // 0x000C (0x000C) [0x0000000000000000]               
	int32_t                                            ScopeAIndex;                                   // 0x0018 (0x0004) [0x0000000000000000]               
	uint8_t                                            ScopeAEdge;                                    // 0x001C (0x0001) [0x0000000000000000]               
	uint8_t                                            UnknownData00[0x3];                              // 0x001D (0x0003) MISSED OFFSET
	int32_t                                            ScopeBIndex;                                   // 0x0020 (0x0004) [0x0000000000000000]               
	uint8_t                                            ScopeBEdge;                                    // 0x0024 (0x0001) [0x0000000000000000]               
	uint8_t                                            UnknownData01[0x3];                              // 0x0025 (0x0003) MISSED OFFSET
	float                                              EdgeAngle;                                     // 0x0028 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.PBRuleNodeCorner.RBCornerAngleInfo
// 0x0008
struct FRBCornerAngleInfo
{
	float                                              Angle;                                         // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              CornerSize;                                    // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.PBRuleNodeEdgeAngle.RBEdgeAngleInfo
// 0x0004
struct FRBEdgeAngleInfo
{
	float                                              Angle;                                         // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.PBRuleNodeMesh.BuildingMatOverrides
// 0x000C
struct FBuildingMatOverrides
{
	class TArray<class UMaterialInterface*>            MaterialOptions;                               // 0x0000 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
};

// ScriptStruct Engine.PBRuleNodeMesh.BuildingMeshInfo
// 0x0038
struct FBuildingMeshInfo
{
	class UStaticMesh*                                 Mesh;                                          // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              DimX;                                          // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              DimZ;                                          // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              Chance;                                        // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	class UDistributionVector*                         Translation;                                   // 0x0010 (0x0004) [0x0000000004080009] (CPF_Edit | CPF_ExportObject | CPF_Component | CPF_EditInline)
	class UDistributionVector*                         Rotation;                                      // 0x0014 (0x0004) [0x0000000004080009] (CPF_Edit | CPF_ExportObject | CPF_Component | CPF_EditInline)
	uint32_t                                           bMeshScaleTranslation : 1;                     // 0x0018 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bOverrideMeshLightMapRes : 1;                  // 0x0018 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	int32_t                                            OverriddenMeshLightMapRes;                     // 0x001C (0x0004) [0x0000000000000001] (CPF_Edit)    
	class TArray<class UMaterialInterface*>            MaterialOverrides;                             // 0x0020 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<struct FBuildingMatOverrides>         SectionOverrides;                              // 0x002C (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
};

// ScriptStruct Engine.PBRuleNodeSplit.RBSplitInfo
// 0x0014
struct FRBSplitInfo
{
	uint32_t                                           bFixSize : 1;                                  // 0x0000 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	float                                              FixedSize;                                     // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              ExpandRatio;                                   // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class FName                                        SplitName;                                     // 0x000C (0x0008) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.PhysXDestructible.PhysXDestructibleDepthParameters
// 0x0004
struct FPhysXDestructibleDepthParameters
{
	uint32_t                                           bTakeImpactDamage : 1;                         // 0x0000 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bPlaySoundEffect : 1;                          // 0x0000 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint32_t                                           bPlayParticleEffect : 1;                       // 0x0000 (0x0004) [0x0000000000000001] [0x00000004] (CPF_Edit)
	uint32_t                                           bDoNotTimeOut : 1;                             // 0x0000 (0x0004) [0x0000000000000001] [0x00000008] (CPF_Edit)
	uint32_t                                           bNoKillDummy : 1;                              // 0x0000 (0x0004) [0x0000000000000000] [0x00000010] 
};

// ScriptStruct Engine.PhysXDestructible.PhysXDestructibleParameters
// 0x0030
struct FPhysXDestructibleParameters
{
	float                                              DamageThreshold;                               // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              DamageToRadius;                                // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              DamageCap;                                     // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              ForceToDamage;                                 // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	class USoundCue*                                   FractureSound;                                 // 0x0010 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class UParticleSystem*                             CrumbleParticleSystem;                         // 0x0014 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              CrumbleParticleSize;                           // 0x0018 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bAccumulateDamage : 1;                         // 0x001C (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	float                                              ScaledDamageToRadius;                          // 0x0020 (0x0004) [0x0000000000000000]               
	class TArray<struct FPhysXDestructibleDepthParameters> DepthParameters;                               // 0x0024 (0x000C) [0x0000000000400041] (CPF_Edit | CPF_EditFixedSize | CPF_NeedCtorLink)
};

// ScriptStruct Engine.PhysXDestructibleActor.SpawnBasis
// 0x001C
struct FSpawnBasis
{
	struct FVector                                     Location;                                      // 0x0000 (0x000C) [0x0000000000000000]               
	struct FRotator                                    Rotation;                                      // 0x000C (0x000C) [0x0000000000000000]               
	float                                              Scale;                                         // 0x0018 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.PhysXDestructibleAsset.PhysXDestructibleAssetChunk
// 0x0034
struct FPhysXDestructibleAssetChunk
{
	int32_t                                            Index;                                         // 0x0000 (0x0004) [0x0000000000000000]               
	int32_t                                            FragmentIndex;                                 // 0x0004 (0x0004) [0x0000000000000000]               
	float                                              Volume;                                        // 0x0008 (0x0004) [0x0000000000000000]               
	float                                              Size;                                          // 0x000C (0x0004) [0x0000000000000000]               
	int32_t                                            Depth;                                         // 0x0010 (0x0004) [0x0000000000000000]               
	int32_t                                            ParentIndex;                                   // 0x0014 (0x0004) [0x0000000000000000]               
	int32_t                                            FirstChildIndex;                               // 0x0018 (0x0004) [0x0000000000000000]               
	int32_t                                            NumChildren;                                   // 0x001C (0x0004) [0x0000000000000000]               
	int32_t                                            MeshIndex;                                     // 0x0020 (0x0004) [0x0000000000000000]               
	int32_t                                            BoneIndex;                                     // 0x0024 (0x0004) [0x0000000000000000]               
	class FName                                        BoneName;                                      // 0x0028 (0x0008) [0x0000000000000000]               
	int32_t                                            BodyIndex;                                     // 0x0030 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.PhysXDestructibleStructure.PhysXDestructibleChunk
// 0x0100
struct FPhysXDestructibleChunk
{
	uint32_t                                           WorldCentroidValid : 1;                        // 0x0000 (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           WorldMatrixValid : 1;                          // 0x0000 (0x0004) [0x0000000000000000] [0x00000002] 
	uint32_t                                           bCrumble : 1;                                  // 0x0000 (0x0004) [0x0000000000000000] [0x00000004] 
	uint32_t                                           IsEnvironmentSupported : 1;                    // 0x0000 (0x0004) [0x0000000000000000] [0x00000008] 
	uint32_t                                           IsRouting : 1;                                 // 0x0000 (0x0004) [0x0000000000000000] [0x00000010] 
	uint32_t                                           IsRouteValid : 1;                              // 0x0000 (0x0004) [0x0000000000000000] [0x00000020] 
	uint32_t                                           IsRouteBlocker : 1;                            // 0x0000 (0x0004) [0x0000000000000000] [0x00000040] 
	int32_t                                            ActorIndex;                                    // 0x0004 (0x0004) [0x0000000000000000]               
	int32_t                                            FragmentIndex;                                 // 0x0008 (0x0004) [0x0000000000000000]               
	int32_t                                            Index;                                         // 0x000C (0x0004) [0x0000000000000000]               
	int32_t                                            MeshIndex;                                     // 0x0010 (0x0004) [0x0000000000000000]               
	int32_t                                            BoneIndex;                                     // 0x0014 (0x0004) [0x0000000000000000]               
	class FName                                        BoneName;                                      // 0x0018 (0x0008) [0x0000000000000000]               
	int32_t                                            BodyIndex;                                     // 0x0020 (0x0004) [0x0000000000000000]               
	struct FVector                                     RelativeCentroid;                              // 0x0024 (0x000C) [0x0000000000000000]               
	struct FVector                                     WorldCentroid;                                 // 0x0030 (0x000C) [0x0000000000000000]               
	uint8_t                                            UnknownData00[0x4];                              // 0x003C (0x0004) MISSED OFFSET
	struct FMatrix                                     RelativeMatrix;                                // 0x0040 (0x0040) [0x0000000000000000]               
	struct FMatrix                                     WorldMatrix;                                   // 0x0080 (0x0040) [0x0000000000000000]               
	float                                              Radius;                                        // 0x00C0 (0x0004) [0x0000000000000000]               
	int32_t                                            ParentIndex;                                   // 0x00C4 (0x0004) [0x0000000000000000]               
	int32_t                                            FirstChildIndex;                               // 0x00C8 (0x0004) [0x0000000000000000]               
	int32_t                                            NumChildren;                                   // 0x00CC (0x0004) [0x0000000000000000]               
	int32_t                                            Depth;                                         // 0x00D0 (0x0004) [0x0000000000000000]               
	float                                              Age;                                           // 0x00D4 (0x0004) [0x0000000000000000]               
	float                                              Damage;                                        // 0x00D8 (0x0004) [0x0000000000000000]               
	float                                              Size;                                          // 0x00DC (0x0004) [0x0000000000000000]               
	uint8_t                                            CurrentState;                                  // 0x00E0 (0x0001) [0x0000000000000000]               
	uint8_t                                            UnknownData01[0x3];                              // 0x00E1 (0x0003) MISSED OFFSET
	struct FPointer                                    Structure;                                     // 0x00E4 (0x0004) [0x0000000000001000] (CPF_Native)  
	int32_t                                            FIFOIndex;                                     // 0x00E8 (0x0004) [0x0000000000001000] (CPF_Native)  
	int32_t                                            FirstOverlapIndex;                             // 0x00EC (0x0004) [0x0000000000000000]               
	int32_t                                            NumOverlaps;                                   // 0x00F0 (0x0004) [0x0000000000000000]               
	int32_t                                            ShortestRoute;                                 // 0x00F4 (0x0004) [0x0000000000000000]               
	int32_t                                            NumSupporters;                                 // 0x00F8 (0x0004) [0x0000000000000000]               
	int32_t                                            NumChildrenDup;                                // 0x00FC (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.PhysXDestructibleStructure.PhysXDestructibleOverlap
// 0x000C
struct FPhysXDestructibleOverlap
{
	int32_t                                            ChunkIndex0;                                   // 0x0000 (0x0004) [0x0000000000000000]               
	int32_t                                            ChunkIndex1;                                   // 0x0004 (0x0004) [0x0000000000000000]               
	int32_t                                            Adjacent;                                      // 0x0008 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.PhysXEmitterSpawnable.IndexedRBState
// 0x0028
struct FIndexedRBState
{
	struct FVector                                     CenterOfMass;                                  // 0x0000 (0x000C) [0x0000000000000000]               
	struct FVector                                     LinearVelocity;                                // 0x000C (0x000C) [0x0000000000000000]               
	struct FVector                                     AngularVelocity;                               // 0x0018 (0x000C) [0x0000000000000000]               
	int32_t                                            Index;                                         // 0x0024 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.PhysXEmitterSpawnable.RBVolumeFill
// 0x0018
struct FRBVolumeFill
{
	class TArray<struct FIndexedRBState>               RBStates;                                      // 0x0000 (0x000C) [0x0000000000500000] (CPF_NeedCtorLink)
	class TArray<struct FVector>                       Positions;                                     // 0x000C (0x000C) [0x0000000000500000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.PlayerOwnerDataStore.PlayerDataProviderTypes
// 0x0010
struct FPlayerDataProviderTypes
{
	class UClass*                                      PlayerOwnerDataProviderClass;                  // 0x0000 (0x0004) [0x0000000000000002] (CPF_Const)   
	class UClass*                                      CurrentWeaponDataProviderClass;                // 0x0004 (0x0004) [0x0000000000000002] (CPF_Const)   
	class UClass*                                      WeaponDataProviderClass;                       // 0x0008 (0x0004) [0x0000000000000002] (CPF_Const)   
	class UClass*                                      PowerupDataProviderClass;                      // 0x000C (0x0004) [0x0000000000000002] (CPF_Const)   
};

// ScriptStruct Engine.PointLightToggleable.CheckpointRecord
// 0x0004
struct APointLightToggleable_FCheckpointRecord
{
	uint32_t                                           bEnabled : 1;                                  // 0x0000 (0x0004) [0x0000000000000000] [0x00000001] 
};

// ScriptStruct Engine.PostProcessVolume.PPV_MatParameter
// 0x0010
struct FPPV_MatParameter
{
	class FName                                        ParamName;                                     // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	float                                              ScalarValue;                                   // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bActiveVaryingTime : 1;                        // 0x000C (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
};

// ScriptStruct Engine.PostProcessVolume.PPV_MaterialEffect
// 0x001C
struct FPPV_MaterialEffect
{
	class FName                                        EffectName;                                    // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bShowInEditor : 1;                             // 0x0008 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bShowInGame : 1;                               // 0x0008 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint32_t                                           bSetNewMaterial : 1;                           // 0x0008 (0x0004) [0x0000000000000001] [0x00000004] (CPF_Edit)
	uint32_t                                           bUseScreenAsTexture : 1;                       // 0x0008 (0x0004) [0x0000000000000001] [0x00000008] (CPF_Edit)
	class UMaterialInterface*                          NewMaterial;                                   // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	class TArray<struct FPPV_MatParameter>             MatParameters;                                 // 0x0010 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
};

// ScriptStruct Engine.Sequence.ActivateOp
// 0x0010
struct FActivateOp
{
	class USequenceOp*                                 ActivatorOp;                                   // 0x0000 (0x0004) [0x0000000000000000]               
	class USequenceOp*                                 Op;                                            // 0x0004 (0x0004) [0x0000000000000000]               
	int32_t                                            InputIdx;                                      // 0x0008 (0x0004) [0x0000000000000000]               
	float                                              RemainingDelay;                                // 0x000C (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.Sequence.QueuedActivationInfo
// 0x001C
struct FQueuedActivationInfo
{
	class USequenceEvent*                              ActivatedEvent;                                // 0x0000 (0x0004) [0x0000000000000000]               
	class AActor*                                      InOriginator;                                  // 0x0004 (0x0004) [0x0000000000000000]               
	class AActor*                                      InInstigator;                                  // 0x0008 (0x0004) [0x0000000000000000]               
	class TArray<int32_t>                              ActivateIndices;                               // 0x000C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	uint32_t                                           bPushTop : 1;                                  // 0x0018 (0x0004) [0x0000000000000000] [0x00000001] 
};

// ScriptStruct Engine.RB_BodySetup.KCachedConvexDataElement
// 0x000C
struct FKCachedConvexDataElement
{
	class TArray<uint8_t>                              ConvexElementData;                             // 0x0000 (0x000C) [0x0000000000001000] (CPF_Native)  
};

// ScriptStruct Engine.RB_BodySetup.KCachedConvexData
// 0x000C
struct FKCachedConvexData
{
	class TArray<struct FKCachedConvexDataElement>     CachedConvexElements;                          // 0x0000 (0x000C) [0x0000000000001000] (CPF_Native)  
};

// ScriptStruct Engine.RB_ConstraintSetup.LinearDOFSetup
// 0x0008
struct FLinearDOFSetup
{
	uint8_t                                            bLimited;                                      // 0x0000 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            UnknownData00[0x3];                              // 0x0001 (0x0003) MISSED OFFSET
	float                                              LimitSize;                                     // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.Scout.PathSizeInfo
// 0x0015
struct FPathSizeInfo
{
	class FName                                        Desc;                                          // 0x0000 (0x0008) [0x0000000000000000]               
	float                                              Radius;                                        // 0x0008 (0x0004) [0x0000000000000000]               
	float                                              Height;                                        // 0x000C (0x0004) [0x0000000000000000]               
	float                                              CrouchHeight;                                  // 0x0010 (0x0004) [0x0000000000000000]               
	uint8_t                                            PathColor;                                     // 0x0014 (0x0001) [0x0000000000000000]               
	uint8_t                                            MinStructAlignment[0x3];                         // 0x0015 (0x0003) ADDED PADDING
};

// ScriptStruct Engine.SeqAct_Interp.CameraCutInfo
// 0x0010
struct FCameraCutInfo
{
	struct FVector                                     Location;                                      // 0x0000 (0x000C) [0x0000000000000000]               
	float                                              TimeStamp;                                     // 0x000C (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.SeqAct_Interp.SavedTransform
// 0x0018
struct FSavedTransform
{
	struct FVector                                     Location;                                      // 0x0000 (0x000C) [0x0000000000000000]               
	struct FRotator                                    Rotation;                                      // 0x000C (0x000C) [0x0000000000000000]               
};

// ScriptStruct Engine.SeqAct_MultiLevelStreaming.LevelStreamingNameCombo
// 0x000C
struct FLevelStreamingNameCombo
{
	class ULevelStreaming*                             Level;                                         // 0x0000 (0x0004) [0x0000000000000002] (CPF_Const)   
	class FName                                        LevelName;                                     // 0x0004 (0x0008) [0x0000000000000003] (CPF_Edit | CPF_Const)
};

// ScriptStruct Engine.SeqAct_RangeSwitch.SwitchRange
// 0x0008
struct FSwitchRange
{
	int32_t                                            Min;                                           // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            Max;                                           // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.SeqAct_SetMaterialEffect.MatParameter
// 0x0010
struct FMatParameter
{
	class FName                                        ParamName;                                     // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	float                                              ScalarValue;                                   // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bActiveVaryingTime : 1;                        // 0x000C (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
};

// ScriptStruct Engine.SeqCond_SwitchClass.SwitchClassInfo
// 0x0009
struct FSwitchClassInfo
{
	class FName                                        ClassName;                                     // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            bFallThru;                                     // 0x0008 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            MinStructAlignment[0x3];                         // 0x0009 (0x0003) ADDED PADDING
};

// ScriptStruct Engine.SeqCond_SwitchObject.SwitchObjectCase
// 0x0008
struct FSwitchObjectCase
{
	class UObject*                                     ObjectValue;                                   // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bFallThru : 1;                                 // 0x0004 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bDefaultValue : 1;                             // 0x0004 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
};

// ScriptStruct Engine.SkelControlCloth.SimBone
// 0x0010
struct FSimBone
{
	struct FPointer                                    Simulator;                                     // 0x0000 (0x0004) [0x0000000000001002] (CPF_Const | CPF_Native)
	class TArray<int32_t>                              BoneIndices;                                   // 0x0004 (0x000C) [0x0000000000500000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.SkeletalMesh.SoftBodyTetraLink
// 0x0010
struct FSoftBodyTetraLink
{
	int32_t                                            Index;                                         // 0x0000 (0x0004) [0x0000000000000000]               
	struct FVector                                     Bary;                                          // 0x0004 (0x000C) [0x0000000000000000]               
};

// ScriptStruct Engine.SkeletalMesh.SoftBodySpecialBoneInfo
// 0x0018
struct FSoftBodySpecialBoneInfo
{
	class FName                                        BoneName;                                      // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            BoneType;                                      // 0x0008 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            UnknownData00[0x3];                              // 0x0009 (0x0003) MISSED OFFSET
	class TArray<int32_t>                              AttachedVertexIndices;                         // 0x000C (0x000C) [0x0000000000400002] (CPF_Const | CPF_NeedCtorLink)
};

// ScriptStruct Engine.SkeletalMesh.VertexModifierParam
// 0x0028
struct FVertexModifierParam
{
	struct FVector                                     FixedPoint;                                    // 0x0000 (0x000C) [0x0000000000000001] (CPF_Edit)    
	float                                              Amplitude;                                     // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              Frequency;                                     // 0x0010 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              Speed;                                         // 0x0014 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              Intensity;                                     // 0x0018 (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FVector                                     DirRefPoint;                                   // 0x001C (0x000C) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.SkeletalMesh.ClothSpecialBoneInfo
// 0x0018
struct FClothSpecialBoneInfo
{
	class FName                                        BoneName;                                      // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            BoneType;                                      // 0x0008 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            UnknownData00[0x3];                              // 0x0009 (0x0003) MISSED OFFSET
	class TArray<int32_t>                              AttachedVertexIndices;                         // 0x000C (0x000C) [0x0000000000400002] (CPF_Const | CPF_NeedCtorLink)
};

// ScriptStruct Engine.SkeletalMesh.SkeletalMeshLODInfo
// 0x002C
struct FSkeletalMeshLODInfo
{
	float                                              DisplayFactor;                                 // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              LODHysteresis;                                 // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class TArray<int32_t>                              LODMaterialMap;                                // 0x0008 (0x000C) [0x0000000000400041] (CPF_Edit | CPF_EditFixedSize | CPF_NeedCtorLink)
	class TArray<uint32_t>                             bEnableShadowCasting;                          // 0x0014 (0x000C) [0x0000000000400041] (CPF_Edit | CPF_EditFixedSize | CPF_NeedCtorLink)
	class TArray<uint8_t>                              TriangleSorting;                               // 0x0020 (0x000C) [0x0000000000400041] (CPF_Edit | CPF_EditFixedSize | CPF_NeedCtorLink)
};

// ScriptStruct Engine.SkeletalMesh.BoneMirrorExport
// 0x0011
struct FBoneMirrorExport
{
	class FName                                        BoneName;                                      // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	class FName                                        SourceBoneName;                                // 0x0008 (0x0008) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            BoneFlipAxis;                                  // 0x0010 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            MinStructAlignment[0x3];                         // 0x0011 (0x0003) ADDED PADDING
};

// ScriptStruct Engine.SkeletalMesh.BoneMirrorInfo
// 0x0005
struct FBoneMirrorInfo
{
	int32_t                                            SourceIndex;                                   // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            BoneFlipAxis;                                  // 0x0004 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            MinStructAlignment[0x3];                         // 0x0005 (0x0003) ADDED PADDING
};

// ScriptStruct Engine.SkeletalMeshActor.SkelMeshActorControlTarget
// 0x000C
struct FSkelMeshActorControlTarget
{
	class FName                                        ControlName;                                   // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	class AActor*                                      TargetActor;                                   // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.SkeletalMeshActor.SpeakLineParamStruct
// 0x002C
struct FSpeakLineParamStruct
{
	class AActor*                                      Addressee;                                     // 0x0000 (0x0004) [0x0000000000000000]               
	class USoundCue*                                   Audio;                                         // 0x0004 (0x0004) [0x0000000000000000]               
	class FString                                      DebugText;                                     // 0x0008 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	uint32_t                                           bNoHeadTrack : 1;                              // 0x0014 (0x0004) [0x0000000000000000] [0x00000001] 
	uint8_t                                            BroadcastFilter;                               // 0x0018 (0x0001) [0x0000000000000000]               
	uint8_t                                            UnknownData00[0x3];                              // 0x0019 (0x0003) MISSED OFFSET
	uint32_t                                           bSuppressSubtitle : 1;                         // 0x001C (0x0004) [0x0000000000000000] [0x00000001] 
	uint8_t                                            Priority;                                      // 0x0020 (0x0001) [0x0000000000000000]               
	uint8_t                                            UnknownData01[0x3];                              // 0x0021 (0x0003) MISSED OFFSET
	float                                              DelayTime;                                     // 0x0024 (0x0004) [0x0000000000000000]               
	float                                              ExtraHeadTrackTime;                            // 0x0028 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.SkeletalMeshActorBasedOnExtremeContent.SkelMaterialSetterDatum
// 0x0008
struct FSkelMaterialSetterDatum
{
	int32_t                                            MaterialIndex;                                 // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class UMaterialInterface*                          TheMaterial;                                   // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.SkeletalMeshActorMAT.CheckpointRecord
// 0x0020
struct ASkeletalMeshActorMAT_FCheckpointRecord
{
	struct FVector                                     Location;                                      // 0x0000 (0x000C) [0x0000000000000000]               
	struct FRotator                                    Rotation;                                      // 0x000C (0x000C) [0x0000000000000000]               
	uint8_t                                            CollisionType;                                 // 0x0018 (0x0001) [0x0000000000000000]               
	uint8_t                                            UnknownData00[0x3];                              // 0x0019 (0x0003) MISSED OFFSET
	uint32_t                                           bHidden : 1;                                   // 0x001C (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bIsShutdown : 1;                               // 0x001C (0x0004) [0x0000000000000000] [0x00000002] 
	uint32_t                                           bNeedsPositionReplication : 1;                 // 0x001C (0x0004) [0x0000000000000000] [0x00000004] 
};

// ScriptStruct Engine.SoundClass.SoundClassEditorData
// 0x0008
struct FSoundClassEditorData
{
	int32_t                                            NodePosX;                                      // 0x0000 (0x0004) [0x0000000000001002] (CPF_Const | CPF_Native)
	int32_t                                            NodePosY;                                      // 0x0004 (0x0004) [0x0000000000001002] (CPF_Const | CPF_Native)
};

// ScriptStruct Engine.SoundClass.SoundClassProperties
// 0x001C
struct FSoundClassProperties
{
	float                                              Volume;                                        // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              Pitch;                                         // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              StereoBleed;                                   // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              LFEBleed;                                      // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              VoiceCenterChannelVolume;                      // 0x0010 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              VoiceRadioVolume;                              // 0x0014 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bApplyEffects : 1;                             // 0x0018 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bAlwaysPlay : 1;                               // 0x0018 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint32_t                                           bIsUISound : 1;                                // 0x0018 (0x0004) [0x0000000000000001] [0x00000004] (CPF_Edit)
	uint32_t                                           bIsMusic : 1;                                  // 0x0018 (0x0004) [0x0000000000000001] [0x00000008] (CPF_Edit)
	uint32_t                                           bReverb : 1;                                   // 0x0018 (0x0004) [0x0000000000000001] [0x00000010] (CPF_Edit)
};

// ScriptStruct Engine.SoundMode.SoundClassAdjuster
// 0x0018
struct FSoundClassAdjuster
{
	uint8_t                                            SoundClassName;                                // 0x0000 (0x0001) [0x0000000000002001] (CPF_Edit | CPF_Transient)
	uint8_t                                            UnknownData00[0x3];                              // 0x0001 (0x0003) MISSED OFFSET
	class FName                                        SoundClass;                                    // 0x0004 (0x0008) [0x0000000000020001] (CPF_Edit | CPF_EditConst)
	float                                              VolumeAdjuster;                                // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              PitchAdjuster;                                 // 0x0010 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bApplyToChildren : 1;                          // 0x0014 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
};

// ScriptStruct Engine.SoundMode.AudioEQEffect
// 0x0024
struct FAudioEQEffect
{
	struct FDouble                                     RootTime;                                      // 0x0000 (0x0008) [0x0000000000003000] (CPF_Native | CPF_Transient)
	float                                              HFFrequency;                                   // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              HFGain;                                        // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              MFCutoffFrequency;                             // 0x0010 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              MFBandwidth;                                   // 0x0014 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              MFGain;                                        // 0x0018 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              LFFrequency;                                   // 0x001C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              LFGain;                                        // 0x0020 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.SoundNodeDistanceCrossFade.DistanceDatum
// 0x004C
struct FDistanceDatum
{
	float                                              FadeInDistanceStart;                           // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              FadeInDistanceEnd;                             // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              FadeOutDistanceStart;                          // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              FadeOutDistanceEnd;                            // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              Volume;                                        // 0x0010 (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FRawDistributionFloat                       FadeInDistance;                                // 0x0014 (0x001C) [0x0000000020480000] (CPF_Component | CPF_NeedCtorLink | CPF_Deprecated)
	struct FRawDistributionFloat                       FadeOutDistance;                               // 0x0030 (0x001C) [0x0000000020480000] (CPF_Component | CPF_NeedCtorLink | CPF_Deprecated)
};

// ScriptStruct Engine.SpeechRecognition.RecognisableWord
// 0x001C
struct FRecognisableWord
{
	int32_t                                            Id;                                            // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class FString                                      ReferenceWord;                                 // 0x0004 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class FString                                      PhoneticWord;                                  // 0x0010 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
};

// ScriptStruct Engine.SpeechRecognition.RecogVocabulary
// 0x0048
struct FRecogVocabulary
{
	class TArray<struct FRecognisableWord>             WhoDictionary;                                 // 0x0000 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class TArray<struct FRecognisableWord>             WhatDictionary;                                // 0x000C (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class TArray<struct FRecognisableWord>             WhereDictionary;                               // 0x0018 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class FString                                      VocabName;                                     // 0x0024 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<uint8_t>                              VocabData;                                     // 0x0030 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<uint8_t>                              WorkingVocabData;                              // 0x003C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.SpeechRecognition.RecogUserData
// 0x0010
struct FRecogUserData
{
	int32_t                                            ActiveVocabularies;                            // 0x0000 (0x0004) [0x0000000000000000]               
	class TArray<uint8_t>                              UserData;                                      // 0x0004 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.SpeedTreeComponent.SpeedTreeStaticLight
// 0x0024
struct FSpeedTreeStaticLight
{
	struct FGuid                                       Guid;                                          // 0x0000 (0x0010) [0x0000000000000002] (CPF_Const)   
	class UShadowMap1D*                                BranchShadowMap;                               // 0x0010 (0x0004) [0x0000000000000002] (CPF_Const)   
	class UShadowMap1D*                                FrondShadowMap;                                // 0x0014 (0x0004) [0x0000000000000002] (CPF_Const)   
	class UShadowMap1D*                                LeafMeshShadowMap;                             // 0x0018 (0x0004) [0x0000000000000002] (CPF_Const)   
	class UShadowMap1D*                                LeafCardShadowMap;                             // 0x001C (0x0004) [0x0000000000000002] (CPF_Const)   
	class UShadowMap1D*                                BillboardShadowMap;                            // 0x0020 (0x0004) [0x0000000000000002] (CPF_Const)   
};

// ScriptStruct Engine.SpeedTreeComponent.LightMapRef
// 0x0004
struct USpeedTreeComponent_FLightMapRef
{
	struct FPointer                                    Reference;                                     // 0x0000 (0x0004) [0x0000000000001002] (CPF_Const | CPF_Native)
};

// ScriptStruct Engine.SplineActor.SplineConnection
// 0x0008
struct FSplineConnection
{
	class USplineComponent*                            SplineComponent;                               // 0x0000 (0x0004) [0x0000000004080009] (CPF_Edit | CPF_ExportObject | CPF_Component | CPF_EditInline)
	class ASplineActor*                                ConnectTo;                                     // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.SplineMeshComponent.SplineMeshParams
// 0x0058
struct FSplineMeshParams
{
	struct FVector                                     StartPos;                                      // 0x0000 (0x000C) [0x0000000000000000]               
	struct FVector                                     StartTangent;                                  // 0x000C (0x000C) [0x0000000000000000]               
	struct FVector2D                                   StartScale;                                    // 0x0018 (0x0008) [0x0000000000000000]               
	float                                              StartRoll;                                     // 0x0020 (0x0004) [0x0000000000000000]               
	struct FVector2D                                   StartOffset;                                   // 0x0024 (0x0008) [0x0000000000000000]               
	struct FVector                                     EndPos;                                        // 0x002C (0x000C) [0x0000000000000000]               
	struct FVector                                     EndTangent;                                    // 0x0038 (0x000C) [0x0000000000000000]               
	struct FVector2D                                   EndScale;                                      // 0x0044 (0x0008) [0x0000000000000000]               
	float                                              EndRoll;                                       // 0x004C (0x0004) [0x0000000000000000]               
	struct FVector2D                                   EndOffset;                                     // 0x0050 (0x0008) [0x0000000000000000]               
};

// ScriptStruct Engine.SpotLightToggleable.CheckpointRecord
// 0x0004
struct ASpotLightToggleable_FCheckpointRecord
{
	uint32_t                                           bEnabled : 1;                                  // 0x0000 (0x0004) [0x0000000000000000] [0x00000001] 
};

// ScriptStruct Engine.StaticMeshActorBasedOnExtremeContent.SMMaterialSetterDatum
// 0x0008
struct FSMMaterialSetterDatum
{
	int32_t                                            MaterialIndex;                                 // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class UMaterialInterface*                          TheMaterial;                                   // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.SVehicle.VehicleState
// 0x004C
struct FVehicleState
{
	struct FRigidBodyState                             RBState;                                       // 0x0000 (0x0040) [0x0000000000000000]               
	uint8_t                                            ServerBrake;                                   // 0x0040 (0x0001) [0x0000000000000000]               
	uint8_t                                            ServerGas;                                     // 0x0041 (0x0001) [0x0000000000000000]               
	uint8_t                                            ServerSteering;                                // 0x0042 (0x0001) [0x0000000000000000]               
	uint8_t                                            ServerRise;                                    // 0x0043 (0x0001) [0x0000000000000000]               
	uint32_t                                           bServerHandbrake : 1;                          // 0x0044 (0x0004) [0x0000000000000000] [0x00000001] 
	int32_t                                            ServerView;                                    // 0x0048 (0x0004) [0x0000000000000000]               
	uint8_t                                            MinStructAlignment[0x4];                         // 0x004C (0x0004) ADDED PADDING
};

// ScriptStruct Engine.Terrain.TerrainHeight
// 0x0000
struct FTerrainHeight
{
};

// ScriptStruct Engine.Terrain.TerrainInfoData
// 0x0000
struct FTerrainInfoData
{
};

// ScriptStruct Engine.Terrain.TerrainLayer
// 0x0030
struct FTerrainLayer
{
	class FString                                      Name;                                          // 0x0000 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class UTerrainLayerSetup*                          Setup;                                         // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            AlphaMapIndex;                                 // 0x0010 (0x0004) [0x0000000000000000]               
	uint32_t                                           Highlighted : 1;                               // 0x0014 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           WireframeHighlighted : 1;                      // 0x0014 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint32_t                                           Hidden : 1;                                    // 0x0014 (0x0004) [0x0000000000000001] [0x00000004] (CPF_Edit)
	struct FColor                                      HighlightColor;                                // 0x0018 (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FColor                                      WireframeColor;                                // 0x001C (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            MinX;                                          // 0x0020 (0x0004) [0x0000000000000000]               
	int32_t                                            MinY;                                          // 0x0024 (0x0004) [0x0000000000000000]               
	int32_t                                            MaxX;                                          // 0x0028 (0x0004) [0x0000000000000000]               
	int32_t                                            MaxY;                                          // 0x002C (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.Terrain.TerrainDecorationInstance
// 0x0014
struct FTerrainDecorationInstance
{
	class UPrimitiveComponent*                         Component;                                     // 0x0000 (0x0004) [0x0000000004080008] (CPF_ExportObject | CPF_Component | CPF_EditInline)
	float                                              X;                                             // 0x0004 (0x0004) [0x0000000000000000]               
	float                                              Y;                                             // 0x0008 (0x0004) [0x0000000000000000]               
	float                                              Scale;                                         // 0x000C (0x0004) [0x0000000000000000]               
	int32_t                                            Yaw;                                           // 0x0010 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.Terrain.TerrainDecoration
// 0x0024
struct FTerrainDecoration
{
	class UPrimitiveComponentFactory*                  Factory;                                       // 0x0000 (0x0004) [0x0000000004000001] (CPF_Edit | CPF_EditInline)
	float                                              MinScale;                                      // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              MaxScale;                                      // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              Density;                                       // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              SlopeRotationBlend;                            // 0x0010 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            RandSeed;                                      // 0x0014 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class TArray<struct FTerrainDecorationInstance>    Instances;                                     // 0x0018 (0x000C) [0x0000000000480000] (CPF_Component | CPF_NeedCtorLink)
};

// ScriptStruct Engine.Terrain.TerrainDecoLayer
// 0x001C
struct FTerrainDecoLayer
{
	class FString                                      Name;                                          // 0x0000 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class TArray<struct FTerrainDecoration>            Decorations;                                   // 0x000C (0x000C) [0x0000000000480001] (CPF_Edit | CPF_Component | CPF_NeedCtorLink)
	int32_t                                            AlphaMapIndex;                                 // 0x0018 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.Terrain.AlphaMap
// 0x0000
struct FAlphaMap
{
};

// ScriptStruct Engine.Terrain.TerrainWeightedMaterial
// 0x0000
struct ATerrain_FTerrainWeightedMaterial
{
};

// ScriptStruct Engine.Terrain.SelectedTerrainVertex
// 0x000C
struct FSelectedTerrainVertex
{
	int32_t                                            X;                                             // 0x0000 (0x0004) [0x0000000000000000]               
	int32_t                                            Y;                                             // 0x0004 (0x0004) [0x0000000000000000]               
	int32_t                                            Weight;                                        // 0x0008 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.Terrain.TerrainMaterialResource
// 0x0000
struct FTerrainMaterialResource
{
};

// ScriptStruct Engine.Terrain.CachedTerrainMaterialArray
// 0x000C
struct FCachedTerrainMaterialArray
{
	class TArray<struct FPointer>                      CachedMaterials;                               // 0x0000 (0x000C) [0x0000000000001002] (CPF_Const | CPF_Native)
};

// ScriptStruct Engine.TerrainComponent.TerrainBVTree
// 0x000C
struct FTerrainBVTree
{
	class TArray<int32_t>                              Nodes;                                         // 0x0000 (0x000C) [0x0000000000001002] (CPF_Const | CPF_Native)
};

// ScriptStruct Engine.TerrainComponent.TerrainkDOPTree
// 0x0018
struct FTerrainkDOPTree
{
	class TArray<int32_t>                              Nodes;                                         // 0x0000 (0x000C) [0x0000000000001002] (CPF_Const | CPF_Native)
	class TArray<int32_t>                              Triangles;                                     // 0x000C (0x000C) [0x0000000000001002] (CPF_Const | CPF_Native)
};

// ScriptStruct Engine.TerrainLayerSetup.FilterLimit
// 0x0010
struct FFilterLimit
{
	uint32_t                                           Enabled : 1;                                   // 0x0000 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	float                                              Base;                                          // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              NoiseScale;                                    // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              NoiseAmount;                                   // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.TerrainLayerSetup.TerrainFilteredMaterial
// 0x0054
struct FTerrainFilteredMaterial
{
	uint32_t                                           UseNoise : 1;                                  // 0x0000 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	float                                              NoiseScale;                                    // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              NoisePercent;                                  // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FFilterLimit                                MinHeight;                                     // 0x000C (0x0010) [0x0000000000000001] (CPF_Edit)    
	struct FFilterLimit                                MaxHeight;                                     // 0x001C (0x0010) [0x0000000000000001] (CPF_Edit)    
	struct FFilterLimit                                MinSlope;                                      // 0x002C (0x0010) [0x0000000000000001] (CPF_Edit)    
	struct FFilterLimit                                MaxSlope;                                      // 0x003C (0x0010) [0x0000000000000001] (CPF_Edit)    
	float                                              Alpha;                                         // 0x004C (0x0004) [0x0000000000000001] (CPF_Edit)    
	class UTerrainMaterial*                            Material;                                      // 0x0050 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.TerrainMaterial.TerrainFoliageMesh
// 0x0038
struct FTerrainFoliageMesh
{
	class UStaticMesh*                                 StaticMesh;                                    // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class UMaterialInterface*                          Material;                                      // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            Density;                                       // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              MaxDrawRadius;                                 // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              MinTransitionRadius;                           // 0x0010 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              MinScale;                                      // 0x0014 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              MaxScale;                                      // 0x0018 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              MinUniformScale;                               // 0x001C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              MaxUniformScale;                               // 0x0020 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              MinThinningRadius;                             // 0x0024 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            Seed;                                          // 0x0028 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              SwayScale;                                     // 0x002C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              AlphaMapThreshold;                             // 0x0030 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              SlopeRotationBlend;                            // 0x0034 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.TerrainWeightMapTexture.TerrainWeightedMaterial
// 0x0000
struct UTerrainWeightMapTexture_FTerrainWeightedMaterial
{
};

// ScriptStruct Engine.Texture2DComposite.SourceTexture2DRegion
// 0x0014
struct FSourceTexture2DRegion
{
	int32_t                                            OffsetX;                                       // 0x0000 (0x0004) [0x0000000000000000]               
	int32_t                                            OffsetY;                                       // 0x0004 (0x0004) [0x0000000000000000]               
	int32_t                                            SizeX;                                         // 0x0008 (0x0004) [0x0000000000000000]               
	int32_t                                            SizeY;                                         // 0x000C (0x0004) [0x0000000000000000]               
	class UTexture2D*                                  Texture2D;                                     // 0x0010 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.Trigger.CheckpointRecord
// 0x0024
struct ATrigger_FCheckpointRecord
{
	uint32_t                                           bCollideActors : 1;                            // 0x0000 (0x0004) [0x0000000000000000] [0x00000001] 
	int32_t                                            TriggerTimes;                                  // 0x0004 (0x0004) [0x0000000000000000]               
	uint32_t                                           bEnabled : 1;                                  // 0x0008 (0x0004) [0x0000000000000000] [0x00000001] 
	class FString                                      initMostOutName;                               // 0x000C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class FString                                      initActorFName;                                // 0x0018 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.TriggerStreamingLevel.LevelStreamingData
// 0x0008
struct FLevelStreamingData
{
	uint32_t                                           bShouldBeLoaded : 1;                           // 0x0000 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bShouldBeVisible : 1;                          // 0x0000 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint32_t                                           bShouldBlockOnLoad : 1;                        // 0x0000 (0x0004) [0x0000000000000001] [0x00000004] (CPF_Edit)
	class ULevelStreaming*                             Level;                                         // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.UIComp_ListPresenterBase.UIListItemDataBinding
// 0x0014
struct FUIListItemDataBinding
{
	class UUIListElementCellProvider*                  DataSourceProvider_Object;                     // 0x0000 (0x0008) [0x0000000000000000] 
	class UUIListElementCellProvider*                  DataSourceProvider_Interface;                  // 0x0000 (0x0008) [0x0000000000000000]               
	class FName                                        DataSourceTag;                                 // 0x0008 (0x0008) [0x0000000000000000]               
	int32_t                                            DataSourceIndex;                               // 0x0010 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.UIComp_ListPresenter.UIListElementCell
// 0x008C
struct FUIListElementCell
{
	int32_t                                            ContainerElementIndex;                         // 0x0000 (0x0004) [0x0000000000003002] (CPF_Const | CPF_Native | CPF_Transient)
	class UUIList*                                     OwnerList;                                     // 0x0004 (0x0004) [0x0000000000002002] (CPF_Const | CPF_Transient)
	struct FUIStyleReference                           CellStyle[4];                                  // 0x0008 (0x0080) [0x0000000000000000]               
	class UObject*                                     ValueObject;                                   // 0x0088 (0x0004) [0x0000000000802000] (CPF_Transient | CPF_NoExport)
};

// ScriptStruct Engine.UIComp_ListPresenter.UIListItem
// 0x0028
struct FUIListItem
{
	struct FUIListItemDataBinding                      DataSource;                                    // 0x0000 (0x0014) [0x0000000000000002] (CPF_Const)   
	class TArray<struct FUIListElementCell>            Cells;                                         // 0x0014 (0x000C) [0x0000000004420041] (CPF_Edit | CPF_EditFixedSize | CPF_EditConst | CPF_NeedCtorLink | CPF_EditInline)
	uint8_t                                            ElementState;                                  // 0x0020 (0x0001) [0x0000000001022001] (CPF_Edit | CPF_Transient | CPF_EditConst)
	uint8_t                                            UnknownData00[0x3];                              // 0x0021 (0x0003) MISSED OFFSET
	class UUIObject*                                   ElementWidget;                                 // 0x0024 (0x0004) [0x0000000004020001] (CPF_Edit | CPF_EditConst | CPF_EditInline)
};

// ScriptStruct Engine.UIComp_ListPresenter.UIListElementCellTemplate
// 0x0020 (0x008C - 0x00AC)
struct FUIListElementCellTemplate : FUIListElementCell
{
	class FName                                        CellDataField;                                 // 0x008C (0x0008) [0x0000000004000001] (CPF_Edit | CPF_EditInline)
	class FString                                      ColumnHeaderText;                              // 0x0094 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	struct FUIScreenValue_Extent                       CellSize;                                      // 0x00A0 (0x0008) [0x0000000000000001] (CPF_Edit)    
	float                                              CellPosition;                                  // 0x00A8 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.UIComp_ListPresenter.UIElementCellSchema
// 0x000C
struct FUIElementCellSchema
{
	class TArray<struct FUIListElementCellTemplate>    Cells;                                         // 0x0000 (0x000C) [0x0000000004400001] (CPF_Edit | CPF_NeedCtorLink | CPF_EditInline)
};

// ScriptStruct Engine.UIComp_ListElementSorter.UIListSortingParameters
// 0x000C
struct FUIListSortingParameters
{
	int32_t                                            PrimaryIndex;                                  // 0x0000 (0x0004) [0x0000000000100000]               
	int32_t                                            SecondaryIndex;                                // 0x0004 (0x0004) [0x0000000000100000]               
	uint32_t                                           bReversePrimarySorting : 1;                    // 0x0008 (0x0004) [0x0000000000100000] [0x00000001] 
	uint32_t                                           bReverseSecondarySorting : 1;                  // 0x0008 (0x0004) [0x0000000000100000] [0x00000002] 
	uint32_t                                           bCaseSensitive : 1;                            // 0x0008 (0x0004) [0x0000000000100000] [0x00000004] 
	uint32_t                                           bIntSortPrimary : 1;                           // 0x0008 (0x0004) [0x0000000000100000] [0x00000008] 
	uint32_t                                           bIntSortSecondary : 1;                         // 0x0008 (0x0004) [0x0000000000100000] [0x00000010] 
	uint32_t                                           bFloatSortPrimary : 1;                         // 0x0008 (0x0004) [0x0000000000100000] [0x00000020] 
	uint32_t                                           bFloatSortSecondary : 1;                       // 0x0008 (0x0004) [0x0000000000100000] [0x00000040] 
};

// ScriptStruct Engine.UIList.CellHitDetectionInfo
// 0x0010
struct FCellHitDetectionInfo
{
	int32_t                                            HitColumn;                                     // 0x0000 (0x0004) [0x0000000000100000]               
	int32_t                                            HitRow;                                        // 0x0004 (0x0004) [0x0000000000100000]               
	int32_t                                            ResizeColumn;                                  // 0x0008 (0x0004) [0x0000000000100000]               
	int32_t                                            ResizeRow;                                     // 0x000C (0x0004) [0x0000000000100000]               
};

// ScriptStruct Engine.UIContextMenu.ContextMenuItem
// 0x001C
struct FContextMenuItem
{
	class UUIContextMenu*                              OwnerMenu;                                     // 0x0000 (0x0004) [0x0000000000102002] (CPF_Const | CPF_Transient)
	struct FPointer                                    ParentItem;                                    // 0x0004 (0x0004) [0x0000000000103002] (CPF_Const | CPF_Native | CPF_Transient)
	uint8_t                                            ItemType;                                      // 0x0008 (0x0001) [0x0000000000100000]               
	uint8_t                                            UnknownData00[0x3];                              // 0x0009 (0x0003) MISSED OFFSET
	class FString                                      ItemText;                                      // 0x000C (0x000C) [0x0000000000500000] (CPF_NeedCtorLink)
	int32_t                                            ItemId;                                        // 0x0018 (0x0004) [0x0000000000100000]               
};

// ScriptStruct Engine.UISkin.UISoundCue
// 0x000C
struct FUISoundCue
{
	class FName                                        SoundName;                                     // 0x0000 (0x0008) [0x0000000000000000]               
	class USoundCue*                                   SoundToPlay;                                   // 0x0008 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.UIDataProvider_OnlinePlayerStorage.PlayerStorageArrayProvider
// 0x0010
struct FPlayerStorageArrayProvider
{
	int32_t                                            PlayerStorageId;                               // 0x0000 (0x0004) [0x0000000000000000]               
	class FName                                        PlayerStorageName;                             // 0x0004 (0x0008) [0x0000000000000000]               
	class UUIDataProvider_OnlinePlayerStorageArray*    Provider;                                      // 0x000C (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.UIDataProvider_Settings.SettingsArrayProvider
// 0x0010
struct FSettingsArrayProvider
{
	int32_t                                            SettingsId;                                    // 0x0000 (0x0004) [0x0000000000000000]               
	class FName                                        SettingsName;                                  // 0x0004 (0x0008) [0x0000000000000000]               
	class UUIDataProvider_SettingsArray*               Provider;                                      // 0x000C (0x0004) [0x0000000000000000]               
};

// ScriptStruct Engine.UIDataStore_DynamicResource.DynamicResourceProviderDefinition
// 0x0018
struct FDynamicResourceProviderDefinition
{
	class FName                                        ProviderTag;                                   // 0x0000 (0x0008) [0x0000000000004000] (CPF_Config)  
	class FString                                      ProviderClassName;                             // 0x0008 (0x000C) [0x0000000000404000] (CPF_Config | CPF_NeedCtorLink)
	class UClass*                                      ProviderClass;                                 // 0x0014 (0x0004) [0x0000000000002000] (CPF_Transient)
};

// ScriptStruct Engine.UIDataStore_GameResource.GameResourceDataProvider
// 0x001C
struct FGameResourceDataProvider
{
	class FName                                        ProviderTag;                                   // 0x0000 (0x0008) [0x0000000000004000] (CPF_Config)  
	class FString                                      ProviderClassName;                             // 0x0008 (0x000C) [0x0000000000404000] (CPF_Config | CPF_NeedCtorLink)
	uint32_t                                           bExpandProviders : 1;                          // 0x0014 (0x0004) [0x0000000000004000] [0x00000001] (CPF_Config)
	class UClass*                                      ProviderClass;                                 // 0x0018 (0x0004) [0x0000000000002000] (CPF_Transient)
};

// ScriptStruct Engine.UIDataStore_InputAlias.UIInputKeyData
// 0x0018
struct FUIInputKeyData
{
	struct FRawInputKeyEventData                       InputKeyData;                                  // 0x0000 (0x000C) [0x0000000000004000] (CPF_Config)  
	class FString                                      ButtonFontMarkupString;                        // 0x000C (0x000C) [0x0000000000404000] (CPF_Config | CPF_NeedCtorLink)
};

// ScriptStruct Engine.UIDataStore_InputAlias.UIDataStoreInputAlias
// 0x0050
struct FUIDataStoreInputAlias
{
	class FName                                        AliasName;                                     // 0x0000 (0x0008) [0x0000000000004000] (CPF_Config)  
	struct FUIInputKeyData                             PlatformInputKeys[3];                          // 0x0008 (0x0048) [0x0000000000404000] (CPF_Config | CPF_NeedCtorLink)
};

// ScriptStruct Engine.UIDataStore_OnlineGameSearch.GameSearchCfg
// 0x0028
struct FGameSearchCfg
{
	class UClass*                                      GameSearchClass;                               // 0x0000 (0x0004) [0x0000000000000000]               
	class UClass*                                      DefaultGameSettingsClass;                      // 0x0004 (0x0004) [0x0000000000000000]               
	class UClass*                                      SearchResultsProviderClass;                    // 0x0008 (0x0004) [0x0000000000000000]               
	class UUIDataProvider_Settings*                    DesiredSettingsProvider;                       // 0x000C (0x0004) [0x0000000000000000]               
	class TArray<class UUIDataProvider_Settings*>      SearchResults;                                 // 0x0010 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class UOnlineGameSearch*                           Search;                                        // 0x001C (0x0004) [0x0000000000000000]               
	class FName                                        SearchName;                                    // 0x0020 (0x0008) [0x0000000000000000]               
};

// ScriptStruct Engine.UIDataStore_OnlineGameSettings.GameSettingsCfg
// 0x0014
struct FGameSettingsCfg
{
	class UClass*                                      GameSettingsClass;                             // 0x0000 (0x0004) [0x0000000000000000]               
	class UUIDataProvider_Settings*                    Provider;                                      // 0x0004 (0x0004) [0x0000000000000000]               
	class UOnlineGameSettings*                         GameSettings;                                  // 0x0008 (0x0004) [0x0000000000000000]               
	class FName                                        SettingsName;                                  // 0x000C (0x0008) [0x0000000000000000]               
};

// ScriptStruct Engine.UIDataStore_OnlineStats.RankMetaData
// 0x0014
struct FRankMetaData
{
	class FName                                        RankName;                                      // 0x0000 (0x0008) [0x0000000000000002] (CPF_Const)   
	class FString                                      RankColumnName;                                // 0x0008 (0x000C) [0x0000000000408002] (CPF_Const | CPF_Localized | CPF_NeedCtorLink)
};

// ScriptStruct Engine.UIDataStore_OnlineStats.PlayerNickMetaData
// 0x0014
struct FPlayerNickMetaData
{
	class FName                                        PlayerNickName;                                // 0x0000 (0x0008) [0x0000000000000002] (CPF_Const)   
	class FString                                      PlayerNickColumnName;                          // 0x0008 (0x000C) [0x0000000000408002] (CPF_Const | CPF_Localized | CPF_NeedCtorLink)
};

// ScriptStruct Engine.UIDataStore_StringAliasMap.UIMenuInputMap
// 0x001C
struct FUIMenuInputMap
{
	class FName                                        FieldName;                                     // 0x0000 (0x0008) [0x0000000000000000]               
	class FName                                        Set;                                           // 0x0008 (0x0008) [0x0000000000000000]               
	class FString                                      MappedText;                                    // 0x0010 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
};

// ScriptStruct Engine.UIFrameBox.CornerSizes
// 0x0030
struct FCornerSizes
{
	float                                              TopLeft[2];                                    // 0x0000 (0x0008) [0x0000000000000001] (CPF_Edit)    
	float                                              TopRight[2];                                   // 0x0008 (0x0008) [0x0000000000000001] (CPF_Edit)    
	float                                              BottomLeft[2];                                 // 0x0010 (0x0008) [0x0000000000000001] (CPF_Edit)    
	float                                              BottomRight[2];                                // 0x0018 (0x0008) [0x0000000000000001] (CPF_Edit)    
	float                                              TopHeight;                                     // 0x0020 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              BottomHeight;                                  // 0x0024 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              CenterLeftWidth;                               // 0x0028 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              CenterRightWidth;                              // 0x002C (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Engine.UIInteraction.UIKeyRepeatData
// 0x0010
struct FUIKeyRepeatData
{
	class FName                                        CurrentRepeatKey;                              // 0x0000 (0x0008) [0x0000000000100000]               
	struct FDouble                                     NextRepeatTime;                                // 0x0008 (0x0008) [0x0000000000100000]               
};

// ScriptStruct Engine.UIInteraction.UIAxisEmulationData
// 0x0004 (0x0010 - 0x0014)
struct FUIAxisEmulationData : FUIKeyRepeatData
{
	uint32_t                                           bEnabled : 1;                                  // 0x0010 (0x0004) [0x0000000000100000] [0x00000001] 
};

// ScriptStruct Engine.StaticMesh.StaticMeshLODElement
// 0x000C
struct FStaticMeshLODElement
{
	class UMaterialInterface*                          Material;                                      // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bEnableShadowCasting : 1;                      // 0x0004 (0x0004) [0x0000000000001001] [0x00000001] (CPF_Edit | CPF_Native)
	uint32_t : 0;                                  // 0x0008 CLOSE BITFIELD STORAGE UNIT
	uint32_t                                           bEnableCollision : 1;                          // 0x0008 (0x0004) [0x0000000000001001] [0x00000001] (CPF_Edit | CPF_Native)
};

// ScriptStruct Engine.StaticMesh.StaticMeshLODInfo
// 0x000C
struct FStaticMeshLODInfo
{
	class TArray<struct FStaticMeshLODElement>         Elements;                                      // 0x0000 (0x000C) [0x0000000000001041] (CPF_Edit | CPF_EditFixedSize | CPF_Native)
};

// ScriptStruct Engine.UIPrefab.ArchetypeInstancePair
// 0x0028
struct FArchetypeInstancePair
{
	class UUIObject*                                   WidgetArchetype;                               // 0x0000 (0x0004) [0x0000000000102000] (CPF_Transient)
	class UUIObject*                                   WidgetInstance;                                // 0x0004 (0x0004) [0x0000000000102000] (CPF_Transient)
	float                                              ArchetypeBounds[4];                            // 0x0008 (0x0010) [0x0000000000102000] (CPF_Transient)
	float                                              InstanceBounds[4];                             // 0x0018 (0x0010) [0x0000000000102000] (CPF_Transient)
};

// ScriptStruct Engine.UIStyle_Combo.StyleDataReference
// 0x0020
struct FStyleDataReference
{
	class UUIStyle*                                    OwnerStyle;                                    // 0x0000 (0x0004) [0x0000000000000000]               
	struct FSTYLE_ID                                   SourceStyleID;                                 // 0x0004 (0x0010) [0x0000000000000000]               
	class UUIStyle*                                    SourceStyle;                                   // 0x0014 (0x0004) [0x0000000000002000] (CPF_Transient)
	class UUIState*                                    SourceState;                                   // 0x0018 (0x0004) [0x0000000000000000]               
	class UUIStyle_Data*                               CustomStyleData;                               // 0x001C (0x0004) [0x0000000000000000]               
};

/*
# ========================================================================================= #
#
# ========================================================================================= #
*/

#ifdef _MSC_VER
#pragma pack(pop)
#endif
