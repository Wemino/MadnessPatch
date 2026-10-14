/*
#############################################################################################
# Alice2 (ASDK) SDK 1.0.0.0
# Generated with the CodeRedGenerator v1.2.0
# ========================================================================================= #
# File: Kynapse_classes.hpp
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

#define CONST_nbMaxAdditionalData                                   4
#define CONST_nbBrainServices                                       5
#define CONST_nbAgents                                              15
#define CONST_smallestMove                                          10.0
#define CONST_smallestSize                                          30.0
#define CONST_fastestSpeed                                          200.0
#define CONST_nbAdditionalData                                      5
#define CONST_nbWorldServices                                       10
#define CONST_nbTeams                                               10
#define CONST_nbTaskSetPriorities                                   8

/*
# ========================================================================================= #
# Enums
# ========================================================================================= #
*/

// Enum Kynapse.FpdBuilder.E_FB_ProjectType
enum class E_FB_ProjectType : uint8_t
{
	E_FB_Dynamic                                       = 0,
	E_FB_Direct                                        = 1,
	E_FB_Default                                       = 2,
	E_FB_END                                           = 3
};

// Enum Kynapse.FpdBuilder.EDisplayInEditorType
enum class EDisplayInEditorType : uint8_t
{
	DisplayEditor_None                                 = 0,
	DisplayEditor_All_Always                           = 1,
	DisplayEditor_Links_Always                         = 2,
	DisplayEditor_All_Selected                         = 3,
	DisplayEditor_Links_Selected                       = 4,
	DisplayEditor_PO_Only                              = 5,
	DisplayEditor_END                                  = 6
};

// Enum Kynapse.FpdBuilder.EPrelinkCanGoCbk
enum class EPrelinkCanGoCbk : uint8_t
{
	CanGo_AiMesh                                       = 0,
	CanGo_Capsule                                      = 1,
	CanGo_END                                          = 2
};

// Enum Kynapse.SphinxTeamContainer.ESphinxTeamContainerType
enum class ESphinxTeamContainerType : uint8_t
{
	ESTCT_NormalFightTeam                              = 0,
	ESTCT_SwarmFightTeam                               = 1,
	ESTCT_END                                          = 2
};

// Enum Kynapse.KynapseWorldServiceLpfManager.ELpf3dMode
enum class ELpf3dMode : uint8_t
{
	LPF2D                                              = 0,
	LPF3D                                              = 1,
	ELpf3dMode_END                                     = 2
};

// Enum Kynapse.KynapseWorldServiceMapBuilder.ECollisionModel
enum class ECollisionModel : uint8_t
{
	A_Sphere                                           = 0,
	B_SweptSphere                                      = 1,
	ECollisionModel_END                                = 2
};

// Enum Kynapse.KynapseWorldServiceMapBuilder.EProcessStep
enum class EProcessStep : uint8_t
{
	A_Exploration                                      = 0,
	B_Analysis                                         = 1,
	C_GraphCreation                                    = 2,
	D_GraphOptimization                                = 3,
	EProcessStep_END                                   = 4
};

// Enum Kynapse.SphinxAgentFight.EAliceWeaponType_REF
enum class EAliceWeaponType_REF : uint8_t
{
	EAWTR_None                                         = 0,
	EAWTR_VorpalBlade                                  = 1,
	EAWTR_HobbyHorse                                   = 2,
	EAWTR_EyeStaff                                     = 3,
	EAWTR_TeapotCannon                                 = 4,
	EAWTR_NpcProject                                   = 5,
	EAWTR_All                                          = 6,
	EAWTR_END                                          = 7
};

// Enum Kynapse.SphinxAgentFight.SphinxMiscActionConditionType
enum class ESphinxMiscActionConditionType : uint8_t
{
	e_SMACT_IsLockedOn                                 = 0,
	e_SMACT_NPCNumReduceChange                         = 1,
	e_SMACT_NameTrigger                                = 2,
	e_SMACT_DetectLightRange                           = 3,
	e_SMACT_DetectHeavyRange                           = 4,
	e_SMACT_DetectLightMelee                           = 5,
	e_SMACT_DetectHeavyMelee                           = 6,
	e_SMACT_DetectDamage                               = 7,
	e_SMACT_DetectCollisionWithPlayer                  = 8,
	e_SMACT_DetectDistSmallThanHappen                  = 9,
	e_SMACT_DetectDistBigThanHappen                    = 10,
	e_SMACT_DetectAllNPCAttachedActorDead              = 11,
	e_SMACT_DetectNPCAttachedActorDead                 = 12,
	e_SMACT_DetectNPCAttachedActorDamage               = 13,
	e_SMACT_DetectNPCLandedFromFalling                 = 14,
	e_SMACT_DetectAliceEscapeGrab                      = 15,
	e_SMACT_DetectPawnOccupyCurrentGotoIndex           = 16,
	e_SMACT_DetectAliceDamage                          = 17,
	e_SMACT_DetectNPCAttachedActorDamagePercent        = 18,
	e_SMACT_Detect_Absoult_Height_Different_SmallThan_Happen = 19,
	e_SMACT_Detect_Absoult_Height_Different_BigThan_Happen = 20,
	e_SMACT_NoCondition                                = 21,
	e_SMACT_END                                        = 22
};

// Enum Kynapse.SphinxInterstingPoint.ESphinxIP
enum class ESphinxIP : uint8_t
{
	InteractIP                                         = 0,
	LookAtIP                                           = 1,
	ESphinxIP_END                                      = 2
};

// Enum Kynapse.SphinxSequenceEventBase.SphinxSequenceEventType
enum class ESphinxSequenceEventType : uint8_t
{
	e_SphinxSequenceET_PlayAnim                        = 0,
	e_SphinxSequenceET_PlaySound                       = 1,
	e_SphinxSequenceET_WaitTime                        = 2,
	e_SphinxSequenceET_PlayParticle                    = 3,
	e_SphinxSequenceET_PreAttackDist                   = 4,
	e_SphinxSequenceET_EventRagdoll                    = 5,
	e_SphinxSequenceET_DestroyComponent                = 6,
	e_SphinxSequenceET_ChangeMaterial                  = 7,
	e_SphinxSequenceET_FadeComponent                   = 8,
	e_SphinxSequenceET_SpawnPickup                     = 9,
	e_SphinxSequenceET_LockTargets                     = 10,
	e_SphinxSequenceET_UnattachComponent               = 11,
	e_SphinxSequenceET_ActiveShield                    = 12,
	e_SphinxSequenceET_ChangeAnimTreeBlendingBranch    = 13,
	e_SphinxSequenceAC_ConditionJump                   = 14,
	e_SphinxSequenceET_ChangeConditionIndex            = 15,
	e_SphinxSequenceET_RemoteEvent                     = 16,
	e_SphinxSequenceAC_Exit                            = 17,
	e_SphinxSequenceET_ModifyPawnHealth                = 18,
	e_SphinxSequenceET_SetNoDamageEffect               = 19,
	e_SphinxSequenceET_SetKnockBackPara                = 20,
	e_SphinxSequenceET_SetPhysic                       = 21,
	e_SphinxSequenceET_PlayMorphTarget                 = 22,
	e_SphinxSequenceET_RandomJump                      = 23,
	e_SphinxSequenceET_ChangeCollisionPhAT             = 24,
	e_SphinxSequenceET_AttchAlice                      = 25,
	e_SphinxSequenceET_RunAnotherPackage               = 26,
	e_SphinxSequenceET_ModifyRotateAndSpeed            = 27,
	e_SphinxSequenceET_ToggleSkeletalControl           = 28,
	e_SphinxSequenceET_AnnounceInFightProcess          = 29,
	e_SphinxSequenceET_ToggleCriticalUI                = 30,
	e_SphinxSequenceET_ChangeDamageAnim                = 31,
	e_SphinxSequenceET_ChangeAttachedActorDamageAnim   = 32,
	e_SphinxSequenceET_ChangeCollisionType             = 33,
	e_SphinxSequenceET_SetHideComponent                = 34,
	e_SphinxSequenceET_SetSonarActive                  = 35,
	e_SphinxSequenceET_SetSonarInfo                    = 36,
	e_SphinxSequenceET_SetNPCScale                     = 37,
	e_SphinxSequenceET_KillAttachedActor               = 38,
	e_SphinxSequenceET_ToggleAttachedActor             = 39,
	e_SphinxSequenceET_ToggleAttachedActorHidden       = 40,
	e_SphinxSequenceET_PlayAnimOnAttachedActor         = 41,
	e_SphinxSequenceET_SetHideSelf                     = 42,
	e_SphinxSequenceET_ToggleSubConditionActive        = 43,
	e_SphinxSequenceET_ToggleLoopSound                 = 44,
	e_SphinxSequenceET_ToggleLoopParticle              = 45,
	e_SphinxSequenceET_ToggleBlockingCheckWithDesiredBlockingVolumn = 46,
	e_SphinxSequenceET_ToggleBlockingCheckWithAlice    = 47,
	e_SphinxSequenceET_SetNPCDeath                     = 48,
	e_SphinxSequenceET_SetNPCFightAgentParam           = 49,
	e_SphinxSequenceET_ToggleNPCGodMode                = 50,
	e_SphinxSequenceET_ChangeMovingPhAT                = 51,
	e_SphinxSequenceET_SwitchCollisionBetweenPhATAndCylider = 52,
	e_SphinxSequenceET_Teleport                        = 53,
	e_SphinxSequenceET_SetGDGlobeValue                 = 54,
	e_SphinxSequenceET_SetGotoLocation                 = 55,
	e_SphinxSequenceET_MoveToGotoLocation              = 56,
	e_SphinxSequenceET_BlendToLocation                 = 57,
	e_SphinxSequenceET_SetAccelerate                   = 58,
	e_SphinxSequenceET_ActiveUIPrompt                  = 59,
	e_SphinxSequenceET_ToggleMessageEvent              = 60,
	e_SphinxSequenceET_ModifyPawnMaxHealth             = 61,
	e_SphinxSequenceET_MoveToOriginalSpawnLocation     = 62,
	e_END                                              = 63
};

// Enum Kynapse.SphinxSequenceActionConditionJump.SphinxSequenceConditionCheckType
enum class ESphinxSequenceConditionCheckType : uint8_t
{
	e_SSCCT_LastSequenceHitPlayer                      = 0,
	e_SSCCT_NoBlockToPlayer                            = 1,
	e_SSCCT_DistPlayer                                 = 2,
	e_SSCCT_DistPlayer2D                               = 3,
	e_SSCCT_AnglePlayer                                = 4,
	e_SSCCT_SelfHpPercent                              = 5,
	e_SSCCT_SelfHpAbsolute                             = 6,
	e_SSCCT_SelfInPlayerCamaraView                     = 7,
	e_SSCCT_PlayerHpPercent                            = 8,
	e_SSCCT_CheckComponentAttach                       = 9,
	e_SSCCT_CheckCurrentConditionIndex                 = 10,
	e_SSCCT_NumberOfTeammatesAttacking                 = 11,
	e_SSCCT_TriggerCountZero                           = 12,
	e_SSCCT_CheckPreviousConditionIndex                = 13,
	e_SSCCT_DistPlayer_X                               = 14,
	e_SSCCT_DistPlayer_Y                               = 15,
	e_SSCCT_DistPlayer_Z                               = 16,
	e_SSCCT_AliceDodgeing                              = 17,
	e_SSCCT_AliceDeflecting                            = 18,
	e_SSCCT_AliceJumping                               = 19,
	e_SSCCT_AliceShield                                = 20,
	e_SSCCT_NoWallInNPC_Direct                         = 21,
	e_SSCCT_NoWallInNPC_Left                           = 22,
	e_SSCCT_NoWallInNPC_Right                          = 23,
	e_SSCCT_CheckNPCAttachedActorAlive                 = 24,
	e_SSCCT_CheckNPCAttachedActorAwake                 = 25,
	e_SSCCT_CheckAliceAtNPCLeftOrRight                 = 26,
	e_SSCCT_CheckNPCAtAliceLeftOrRight                 = 27,
	e_SSCCT_CheckGD_GlobeValue                         = 28,
	e_SSCCT_CheckCurrentDifficult                      = 29,
	e_SSCCT_CheckSelfInSideCollision                   = 30,
	e_SSCCT_CheckAliceWeaponLevel                      = 31,
	e_SSCCT_CheckCountOfAttachedActorAlive             = 32,
	e_SSCCT_END                                        = 33
};

// Enum Kynapse.SphinxSequenceActionConditionJump.SphinxConditionExpressionType
enum class ESphinxConditionExpressionType : uint8_t
{
	e_SSET_Equal                                       = 0,
	e_SSET_GreaterThan                                 = 1,
	e_SSET_LessThan                                    = 2,
	e_SSET_END                                         = 3
};

// Enum Kynapse.SphinxSequenceEventChangeDamageAnim.EDamageStrengthTypeSphinx
enum class EDamageStrengthTypeSphinx : uint8_t
{
	EDSTRS_Weak                                        = 0,
	EDSTRS_Light                                       = 1,
	EDSTRS_Medium                                      = 2,
	EDSTRS_Heavy                                       = 3,
	EDSTRS_HeaveyWithoutKnockback                      = 4,
	EDSTRS_END                                         = 5
};


/*
# ========================================================================================= #
# Classes
# ========================================================================================= #
*/

// Class Kynapse.FpdBuilder
// 0x0069 (0x003C - 0x00A5)
class UFpdBuilder : public UObject
{
public:
	uint32_t                                           Active : 1;                                    // 0x003C (0x0004) [0x0000000000000002] [0x00000001] (CPF_Const)
	uint32_t                                           displayInGame : 1;                             // 0x003C (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	struct FPrelinkProcessParams                       preLinkerProcess;                              // 0x0040 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	struct FFpdBuilderParams                           FpdBuilder;                                    // 0x004C (0x0044) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	class UKynapseTag*                                 DataTag;                                       // 0x0090 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class UKynapseFpdDatabase*                         database;                                      // 0x0094 (0x0004) [0x000000000440000B] (CPF_Edit | CPF_Const | CPF_ExportObject | CPF_NeedCtorLink | CPF_EditInline)
	class TArray<class UKynapseAdditionalData*>        AdditionalDataList;                            // 0x0098 (0x000C) [0x000000000440000B] (CPF_Edit | CPF_Const | CPF_ExportObject | CPF_NeedCtorLink | CPF_EditInline)
	EDisplayInEditorType                               displayInEditor;                               // 0x00A4 (0x0001) [0x0000000000000001] (CPF_Edit)    

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.FpdBuilder");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseActorFactoryAI
// 0x0004 (0x0084 - 0x0088)
class UKynapseActorFactoryAI : public UActorFactoryAI
{
public:
	class UKynapseEntityDefinitionActive*              kynapseDefinition;                             // 0x0084 (0x0004) [0x0000000000000001] (CPF_Edit)    

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseActorFactoryAI");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseAdditionalData
// 0x0018 (0x003C - 0x0054)
class UKynapseAdditionalData : public UObject
{
public:
	class TArray<uint8_t>                              Data;                                          // 0x003C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class FString                                      MultiAdditionalClassName;                      // 0x0048 (0x000C) [0x0000000000400002] (CPF_Const | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseAdditionalData");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdAdditionalDataVertex
// 0x0000 (0x0054 - 0x0054)
class UKynapseFpdAdditionalDataVertex : public UKynapseAdditionalData
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdAdditionalDataVertex");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdAdditionalDataVertexHidingData
// 0x0000 (0x0054 - 0x0054)
class UKynapseFpdAdditionalDataVertexHidingData : public UKynapseFpdAdditionalDataVertex
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdAdditionalDataVertexHidingData");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseAgent
// 0x0030 (0x003C - 0x006C)
class UKynapseAgent : public UObject
{
public:
	class TArray<struct FAgentAperiodicTask>           time_aperiodicTasksList;                       // 0x003C (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	class TArray<struct FAgentPeriodicTask>            time_periodicTasksList;                        // 0x0048 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	class FString                                      agentName;                                     // 0x0054 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	class FString                                      ClassName;                                     // 0x0060 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseAgent");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdAgentFlee
// 0x0024 (0x006C - 0x0090)
class UKynapseFpdAgentFlee : public UKynapseAgent
{
public:
	class UKynapseFpdTraversalDefinitionFlee*          FpdFleeTraversal;                              // 0x006C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              Speed;                                         // 0x0070 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	uint32_t                                           StopWhenSafe : 1;                              // 0x0074 (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)
	float                                              FindSafePlaceInterval;                         // 0x0078 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	class FString                                      CheckDangerVisible;                            // 0x007C (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	int32_t                                            MaxDangerousEntities;                          // 0x0088 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            MaxDangerousPoints;                            // 0x008C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdAgentFlee");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdAgentFollow
// 0x001C (0x006C - 0x0088)
class UKynapseFpdAgentFollow : public UKynapseAgent
{
public:
	float                                              DistFromEntity;                                // 0x006C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              AngleFromEntity;                               // 0x0070 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              MinimalImportantMove;                          // 0x0074 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              Speed;                                         // 0x0078 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	class FString                                      AperiodicTask;                                 // 0x007C (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdAgentFollow");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdAgentGoto
// 0x0004 (0x006C - 0x0070)
class UKynapseFpdAgentGoto : public UKynapseAgent
{
public:
	float                                              Speed;                                         // 0x006C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdAgentGoto");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdAgentHide
// 0x0020 (0x006C - 0x008C)
class UKynapseFpdAgentHide : public UKynapseAgent
{
public:
	class UKynapseFpdTraversalDefinitionHide*          FpdHideTraversal;                              // 0x006C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              Speed;                                         // 0x0070 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	uint32_t                                           StopWhenHidden : 1;                            // 0x0074 (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)
	class FString                                      CheckIfHiddenTask;                             // 0x0078 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	int32_t                                            MaxDangerousEntities;                          // 0x0084 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            MaxDangerousPoints;                            // 0x0088 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdAgentHide");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdAgentShoot
// 0x0024 (0x006C - 0x0090)
class UKynapseFpdAgentShoot : public UKynapseAgent
{
public:
	float                                              GunRange;                                      // 0x006C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              DangerousConeAngle;                            // 0x0070 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              LineOfFireValidityInterval;                    // 0x0074 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            NumPotentialSideSteps;                         // 0x0078 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              SideStepAngle;                                 // 0x007C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              Speed;                                         // 0x0080 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	class FString                                      CheckLineOfFireTask;                           // 0x0084 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdAgentShoot");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdAgentWander
// 0x0008 (0x006C - 0x0074)
class UKynapseFpdAgentWander : public UKynapseAgent
{
public:
	class UKynapseFpdTraversalDefinitionWander*        FpdWanderTraversal;                            // 0x006C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              Speed;                                         // 0x0070 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdAgentWander");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxAgentChase
// 0x0000 (0x006C - 0x006C)
class USphinxAgentChase : public UKynapseAgent
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxAgentChase");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxAgentCommonInfo
// 0x0000 (0x006C - 0x006C)
class USphinxAgentCommonInfo : public UKynapseAgent
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxAgentCommonInfo");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxAgentFight
// 0x0074 (0x006C - 0x00E0)
class USphinxAgentFight : public UKynapseAgent
{
public:
	float                                              m_NearGroupDistance;                           // 0x006C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              m_NearGroupSkipCheckMultiFactor;               // 0x0070 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              m_NearGroupDistanceOffset;                     // 0x0074 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            m_NearGroupFormationAngle;                     // 0x0078 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              m_FarGroupDistance;                            // 0x007C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              m_FarGroupDistanceOffset;                      // 0x0080 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            m_FarGroupFormationAngle;                      // 0x0084 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            m_NearGroupMaxPawn;                            // 0x0088 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            m_FarGroupMaxPawn;                             // 0x008C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              m_ChanceSwitchToFarGroup;                      // 0x0090 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              m_ChanceSwitchToNearGroup;                     // 0x0094 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	uint32_t                                           m_ChooseNearGroupFirst : 1;                    // 0x0098 (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)
	uint32_t                                           m_SwarmCircleActived : 1;                      // 0x0098 (0x0004) [0x0000000000000003] [0x00000002] (CPF_Edit | CPF_Const)
	float                                              m_ShuffleDelay;                                // 0x009C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            m_SwarmFanAngle;                               // 0x00A0 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              m_SwarmSubOffset;                              // 0x00A4 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            m_SwarmMainCount;                              // 0x00A8 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            m_SwarmSubCount;                               // 0x00AC (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	class TArray<struct FSphinxMeleeAttackInfo>        m_MeleeAttackInfo;                             // 0x00B0 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	class TArray<struct FSphinxRangeAttackInfo>        m_RangeAttackInfo;                             // 0x00BC (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	class TArray<struct FSphinxMiscActionInfo>         m_MiscActionInfo;                              // 0x00C8 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	class TArray<struct FSphinxFightSwitchCondition>   m_ConditionArray;                              // 0x00D4 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxAgentFight");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxAgentFlee
// 0x0000 (0x006C - 0x006C)
class USphinxAgentFlee : public UKynapseAgent
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxAgentFlee");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxAgentFollow
// 0x001C (0x006C - 0x0088)
class USphinxAgentFollow : public UKynapseAgent
{
public:
	float                                              DistFromEntity;                                // 0x006C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              AngleFromEntity;                               // 0x0070 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              MinimalImportantMove;                          // 0x0074 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              Speed;                                         // 0x0078 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	class FString                                      AperiodicTask;                                 // 0x007C (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxAgentFollow");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxAgentGoto
// 0x0018 (0x006C - 0x0084)
class USphinxAgentGoto : public UKynapseAgent
{
public:
	float                                              Speed;                                         // 0x006C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	struct FRotator                                    m_DefaultRotatorRate;                          // 0x0070 (0x000C) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              m_SpeedReduceFactor;                           // 0x007C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              m_ReachedFactor;                               // 0x0080 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxAgentGoto");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxAgentHide
// 0x0000 (0x006C - 0x006C)
class USphinxAgentHide : public UKynapseAgent
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxAgentHide");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxAgentInterestPointAlert
// 0x0004 (0x006C - 0x0070)
class USphinxAgentInterestPointAlert : public UKynapseAgent
{
public:
	uint32_t                                           IPAlertIsOn : 1;                               // 0x006C (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxAgentInterestPointAlert");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxAgentShoot
// 0x0000 (0x006C - 0x006C)
class USphinxAgentShoot : public UKynapseAgent
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxAgentShoot");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxAgentWander
// 0x0024 (0x006C - 0x0090)
class USphinxAgentWander : public UKynapseAgent
{
public:
	class USphinxTraversalDefinitionWander*            HierarchicalWanderTraversal;                   // 0x006C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              m_Speed;                                       // 0x0070 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	struct FRotator                                    m_RotationRate;                                // 0x0074 (0x000C) [0x0000000000000003] (CPF_Edit | CPF_Const)
	uint32_t                                           m_bAvoidsPlayer : 1;                           // 0x0080 (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)
	uint32_t                                           m_bAvoidsNPCs : 1;                             // 0x0080 (0x0004) [0x0000000000000003] [0x00000002] (CPF_Edit | CPF_Const)
	float                                              m_WanderTime;                                  // 0x0084 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              m_IdleChance;                                  // 0x0088 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              m_IdleTime;                                    // 0x008C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxAgentWander");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxAgentWayPath
// 0x0018 (0x006C - 0x0084)
class USphinxAgentWayPath : public UKynapseAgent
{
public:
	float                                              m_Speed;                                       // 0x006C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	struct FRotator                                    m_RotationRate;                                // 0x0070 (0x000C) [0x0000000000000003] (CPF_Edit | CPF_Const)
	uint32_t                                           m_bAvoidsPawn : 1;                             // 0x007C (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)
	uint32_t                                           m_bPushPawn : 1;                               // 0x007C (0x0004) [0x0000000000000003] [0x00000002] (CPF_Edit | CPF_Const)
	uint32_t                                           m_bStopsWithPawn : 1;                          // 0x007C (0x0004) [0x0000000000000003] [0x00000004] (CPF_Edit | CPF_Const)
	float                                              m_PathEndTime;                                 // 0x0080 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxAgentWayPath");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseAIController
// 0x0070 (0x03DC - 0x044C)
class AKynapseAIController : public AAIController
{
public:
	class AActor*                                      hideAndShootTarget;                            // 0x03DC (0x0004) [0x0000000000002000] (CPF_Transient)
	class AActor*                                      shootTarget;                                   // 0x03E0 (0x0004) [0x0000000000002000] (CPF_Transient)
	class AActor*                                      followTarget;                                  // 0x03E4 (0x0004) [0x0000000000002000] (CPF_Transient)
	class APawn*                                       tmpPawn;                                       // 0x03E8 (0x0004) [0x0000000000002000] (CPF_Transient)
	class UKynapseHandle*                              myKynapseHandle;                               // 0x03EC (0x0004) [0x0000000004082008] (CPF_ExportObject | CPF_Transient | CPF_Component | CPF_EditInline)
	struct FPointer                                    KynapseEntity;                                 // 0x03F0 (0x0004) [0x0000000000000000]               
	float                                              activityTimer;                                 // 0x03F4 (0x0004) [0x0000000000000000]               
	uint32_t                                           pathComputed : 1;                              // 0x03F8 (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           newLatentAction : 1;                           // 0x03F8 (0x0004) [0x0000000000002000] [0x00000002] (CPF_Transient)
	float                                              taskDuration;                                  // 0x03FC (0x0004) [0x0000000000000000]               
	class AActor*                                      DangerousNode;                                 // 0x0400 (0x0004) [0x0000000000000000]               
	class AActor*                                      DangerousEntity;                               // 0x0404 (0x0004) [0x0000000000002000] (CPF_Transient)
	class TArray<class AActor*>                        FleeDangerousNodes;                            // 0x0408 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<class AActor*>                        FleeDangerousEntities;                         // 0x0414 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<class AActor*>                        HideDangerousNodes;                            // 0x0420 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<class AActor*>                        HideDangerousEntities;                         // 0x042C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	struct FVector                                     latentDestination;                             // 0x0438 (0x000C) [0x0000000000002000] (CPF_Transient)
	class AActor*                                      latentTarget;                                  // 0x0444 (0x0004) [0x0000000000002000] (CPF_Transient)
	float                                              latentDuration;                                // 0x0448 (0x0004) [0x0000000000002000] (CPF_Transient)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseAIController");
		}

		return uClassPointer;
	};


	void OnAIFollow(class USeqAct_AIFollow* Action);
	void OnAIShoot(class USeqAct_AIShoot* Action);
	void OnAIHide(class USeqAct_AIHide* Action);
	void OnAIFlee(class USeqAct_AIFlee* Action);
	void OnAIWander(class USeqAct_AIWander* Action);
	void Possess(class APawn* aPawn, bool bVehicleTransition);
	bool KynapseFollow(class AActor* TargetEntity, float Duration);
	bool KynapseShoot(class AActor* TargetEntity, float Duration);
	bool KynapseHide(float Duration);
	bool KynapseFlee(float Duration);
	bool KynapseWander(float Duration);
	bool KynapseGoTo(const struct FVector& KynapseDestination);
	void SetBrainState(int32_t Set);
	int32_t GetBrainState();
	void ActivateKynapseBrain(bool Activate);
	bool KynapseHasArrived(const struct FVector& Dest);
	void eventHearNoise(float Loudness, class AActor* NoiseMaker, const class FName& optionalNoiseType);
};
// Class Kynapse.KynapseAiMeshLayerDefinition
// 0x000C (0x003C - 0x0048)
class UKynapseAiMeshLayerDefinition : public UObject
{
public:
	class FString                                      ClassName;                                     // 0x003C (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseAiMeshLayerDefinition");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseObstacleLayerDefinition
// 0x0028 (0x0048 - 0x0070)
class UKynapseObstacleLayerDefinition : public UKynapseAiMeshLayerDefinition
{
public:
	int32_t                                            maxMeshCount;                                  // 0x0048 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            maxObstacles;                                  // 0x004C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	class FString                                      aiMeshAccessorClassName;                       // 0x0050 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	class FString                                      obstaclesAccessorClassName;                    // 0x005C (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	class UKynapseTag*                                 pathdataTag;                                   // 0x0068 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            MaxProjections;                                // 0x006C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseObstacleLayerDefinition");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseBrain
// 0x0068 (0x003C - 0x00A4)
class UKynapseBrain : public UObject
{
public:
	class FString                                      brainName;                                     // 0x003C (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	class FString                                      ClassName;                                     // 0x0048 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	class UKynapseBrainService*                        servicesList[5];                               // 0x0054 (0x0014) [0x000000000440000B] (CPF_Edit | CPF_Const | CPF_ExportObject | CPF_NeedCtorLink | CPF_EditInline)
	class UKynapseAgent*                               agentsList[15];                                // 0x0068 (0x003C) [0x000000000440000B] (CPF_Edit | CPF_Const | CPF_ExportObject | CPF_NeedCtorLink | CPF_EditInline)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseBrain");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseBrainService
// 0x0030 (0x003C - 0x006C)
class UKynapseBrainService : public UObject
{
public:
	class TArray<struct FBServiceAperiodicTask>        time_aperiodicTasksList;                       // 0x003C (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	class TArray<struct FBServicePeriodicTask>         time_periodicTasksList;                        // 0x0048 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	class FString                                      serviceName;                                   // 0x0054 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	class FString                                      ClassName;                                     // 0x0060 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseBrainService");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseBrainServiceFpdPathfinder
// 0x0068 (0x006C - 0x00D4)
class UKynapseBrainServiceFpdPathfinder : public UKynapseBrainService
{
public:
	class UKynapseFpdDatabase*                         database;                                      // 0x006C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	struct FFpdModifiers                               Modifiers;                                     // 0x0070 (0x0030) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	uint32_t                                           AvoidCpuPeaks : 1;                             // 0x00A0 (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)
	float                                              CpuPrudence;                                   // 0x00A4 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              MaxPathSize;                                   // 0x00A8 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            PathObjectMemory;                              // 0x00AC (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	struct FLocalPathFinding_Fpd                       lpfConfig;                                     // 0x00B0 (0x0024) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseBrainServiceFpdPathfinder");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseEngineService
// 0x0018 (0x003C - 0x0054)
class UKynapseEngineService : public UObject
{
public:
	class FString                                      serviceName;                                   // 0x003C (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	class FString                                      ClassName;                                     // 0x0048 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseEngineService");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseEngineServiceFpdPathDataManager
// 0x0008 (0x0054 - 0x005C)
class UKynapseEngineServiceFpdPathDataManager : public UKynapseEngineService
{
public:
	int32_t                                            MaxRegisteredCallbacks;                        // 0x0054 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            AstarMemory;                                   // 0x0058 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseEngineServiceFpdPathDataManager");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseEntityDefinition
// 0x0000 (0x003C - 0x003C)
class UKynapseEntityDefinition : public UObject
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseEntityDefinition");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseEntityDefinitionActive
// 0x0028 (0x003C - 0x0064)
class UKynapseEntityDefinitionActive : public UKynapseEntityDefinition
{
public:
	class FString                                      EntityClassName;                               // 0x003C (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	class FString                                      ActionClassName;                               // 0x0048 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	class UKynapseBrain*                               KynapseBrainDefinition;                        // 0x0054 (0x0004) [0x000000000440000B] (CPF_Edit | CPF_Const | CPF_ExportObject | CPF_NeedCtorLink | CPF_EditInline)
	class UKynapseProfileDefinition*                   Profile;                                       // 0x0058 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	class UKynapseMesh*                                AiMesh;                                        // 0x005C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	class UKynapseTag*                                 DefaultDataTag;                                // 0x0060 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseEntityDefinitionActive");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseEntityDefinitionPassive
// 0x0010 (0x003C - 0x004C)
class UKynapseEntityDefinitionPassive : public UKynapseEntityDefinition
{
public:
	class FString                                      EntityClassName;                               // 0x003C (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	class UKynapseProfileDefinition*                   Profile;                                       // 0x0048 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseEntityDefinitionPassive");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseEntityDefinitionPathObject
// 0x0008 (0x004C - 0x0054)
class UKynapseEntityDefinitionPathObject : public UKynapseEntityDefinitionPassive
{
public:
	int32_t                                            PoolCount;                                     // 0x004C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            MaxLinkedEdges;                                // 0x0050 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseEntityDefinitionPathObject");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseEntityDefinitionDynamicPathObject
// 0x0004 (0x0054 - 0x0058)
class UKynapseEntityDefinitionDynamicPathObject : public UKynapseEntityDefinitionPathObject
{
public:
	class UKynapseTag*                                 ImpactedDataTag;                               // 0x0054 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseEntityDefinitionDynamicPathObject");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseEntityDefinitionStaticPathObject
// 0x0010 (0x0054 - 0x0064)
class UKynapseEntityDefinitionStaticPathObject : public UKynapseEntityDefinitionPathObject
{
public:
	int32_t                                            TypeId;                                        // 0x0054 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	class FString                                      TypeName;                                      // 0x0058 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseEntityDefinitionStaticPathObject");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseEntityInfoDefinition
// 0x001C (0x003C - 0x0058)
class UKynapseEntityInfoDefinition : public UObject
{
public:
	class FString                                      infoClass;                                     // 0x003C (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	float                                              validTime;                                     // 0x0048 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              unsafeTime;                                    // 0x004C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              estimatedComputationTime;                      // 0x0050 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           immediateMode : 1;                             // 0x0054 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseEntityInfoDefinition");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseExclusionVolume
// 0x0000 (0x0268 - 0x0268)
class AKynapseExclusionVolume : public ABlockingVolume
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseExclusionVolume");
		}

		return uClassPointer;
	};


	bool StopsProjectile(class AProjectile* P);
};
// Class Kynapse.KynapseExplorationVolume
// 0x0000 (0x0264 - 0x0264)
class AKynapseExplorationVolume : public ATriggerVolume
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseExplorationVolume");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFilter
// 0x000C (0x003C - 0x0048)
class UKynapseFilter : public UObject
{
public:
	class FString                                      filterClass;                                   // 0x003C (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFilter");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFilterDistance
// 0x0010 (0x0048 - 0x0058)
class UKynapseFilterDistance : public UKynapseFilter
{
public:
	struct FVector                                     ReferencePoint;                                // 0x0048 (0x000C) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              Distance;                                      // 0x0054 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFilterDistance");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFilterFrustum
// 0x0024 (0x0048 - 0x006C)
class UKynapseFilterFrustum : public UKynapseFilter
{
public:
	struct FVector                                     EyePosition;                                   // 0x0048 (0x000C) [0x0000000000000003] (CPF_Edit | CPF_Const)
	struct FVector                                     At;                                            // 0x0054 (0x000C) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              NearClip;                                      // 0x0060 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              FarClip;                                       // 0x0064 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              Angle;                                         // 0x0068 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFilterFrustum");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFilterUnconditional
// 0x0000 (0x0048 - 0x0048)
class UKynapseFilterUnconditional : public UKynapseFilter
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFilterUnconditional");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdDatabase
// 0x000C (0x003C - 0x0048)
class UKynapseFpdDatabase : public UObject
{
public:
	struct FFpdDatabase                                Settings;                                      // 0x003C (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdDatabase");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdTraversalDefinition
// 0x0028 (0x003C - 0x0064)
class UKynapseFpdTraversalDefinition : public UObject
{
public:
	struct FFpdTraversalAperiodicTask                  AperiodicTask;                                 // 0x003C (0x0018) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	int32_t                                            InstanceCount;                                 // 0x0054 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	class FString                                      ClassName;                                     // 0x0058 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdTraversalDefinition");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdTraversalDefinitionFlee
// 0x0008 (0x0064 - 0x006C)
class UKynapseFpdTraversalDefinitionFlee : public UKynapseFpdTraversalDefinition
{
public:
	float                                              MaxDistance;                                   // 0x0064 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              MaxCost;                                       // 0x0068 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdTraversalDefinitionFlee");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdTraversalDefinitionHide
// 0x0008 (0x0064 - 0x006C)
class UKynapseFpdTraversalDefinitionHide : public UKynapseFpdTraversalDefinition
{
public:
	float                                              MaxDistance;                                   // 0x0064 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              MaxCost;                                       // 0x0068 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdTraversalDefinitionHide");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdTraversalDefinitionWander
// 0x0010 (0x0064 - 0x0074)
class UKynapseFpdTraversalDefinitionWander : public UKynapseFpdTraversalDefinition
{
public:
	float                                              MaxDistance;                                   // 0x0064 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              MaxCost;                                       // 0x0068 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              WanderDistance;                                // 0x006C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              WanderPropagationAngle;                        // 0x0070 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdTraversalDefinitionWander");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxTraversalDefinitionWander
// 0x0018 (0x0064 - 0x007C)
class USphinxTraversalDefinitionWander : public UKynapseFpdTraversalDefinition
{
public:
	float                                              MaxDistance;                                   // 0x0064 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            TraversalAstarMemory;                          // 0x0068 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              MaxCost;                                       // 0x006C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            ExtractionBufferSize;                          // 0x0070 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              WanderDistance;                                // 0x0074 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              WanderPropagationAngle;                        // 0x0078 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxTraversalDefinitionWander");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFracturedComponent
// 0x0007 (0x0055 - 0x005C)
class UKynapseFracturedComponent : public UActorComponent
{
public:
	uint32_t                                           isNew : 1;                                     // 0x0058 (0x0004) [0x0000000000000000] [0x00000001] 

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFracturedComponent");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFracturedStaticMeshActor
// 0x0000 (0x0290 - 0x0290)
class AKynapseFracturedStaticMeshActor : public AFracturedStaticMeshActor
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFracturedStaticMeshActor");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseGraph
// 0x0040 (0x003C - 0x007C)
class UKynapseGraph : public UObject
{
public:
	class TArray<uint8_t>                              Data;                                          // 0x003C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	int32_t                                            generationBuildNumber;                         // 0x0048 (0x0004) [0x0000000000000000]               
	struct FVector                                     generationBBoxMin;                             // 0x004C (0x000C) [0x0000000000000000]               
	struct FVector                                     generationBBoxMax;                             // 0x0058 (0x000C) [0x0000000000000000]               
	class UKynapseAdditionalData*                      additionalData[5];                             // 0x0064 (0x0014) [0x0000000000000003] (CPF_Edit | CPF_Const)
	class UKynapseTag*                                 DataTag;                                       // 0x0078 (0x0004) [0x0000000000000001] (CPF_Edit)    

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseGraph");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseHandle
// 0x0023 (0x0055 - 0x0078)
class UKynapseHandle : public UActorComponent
{
public:
	class UKynapseEntityDefinition*                    KEntityDefinition;                             // 0x0058 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class TArray<struct FPointer>                      kynapseEntityArray;                            // 0x005C (0x000C) [0x0000000000402000] (CPF_Transient | CPF_NeedCtorLink)
	class TArray<struct FPointer>                      kynapseEntityHandleArray;                      // 0x0068 (0x000C) [0x0000000000402000] (CPF_Transient | CPF_NeedCtorLink)
	uint32_t                                           creationDone : 1;                              // 0x0074 (0x0004) [0x0000000000002000] [0x00000001] (CPF_Transient)
	uint32_t                                           entityAddedToWorld : 1;                        // 0x0074 (0x0004) [0x0000000000002000] [0x00000002] (CPF_Transient)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseHandle");
		}

		return uClassPointer;
	};


	void RegisterToProfile(const class FString& ProfileName);
	void AddKynapseEntity();
	void InitKynapseEntity();
};
// Class Kynapse.KynapseLadderVolume
// 0x000C (0x02D8 - 0x02E4)
class AKynapseLadderVolume : public ALadderVolume
{
public:
	struct FRotator                                    KynapseWallDir;                                // 0x02D8 (0x000C) [0x0000000000000001] (CPF_Edit)    

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseLadderVolume");
		}

		return uClassPointer;
	};


	void eventPostBeginPlay();
};
// Class Kynapse.KynapseLocalRecomputationVolume
// 0x0004 (0x0264 - 0x0268)
class AKynapseLocalRecomputationVolume : public AVolume
{
public:
	uint32_t                                           bEnabled : 1;                                  // 0x0264 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseLocalRecomputationVolume");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseLpfPreMerger
// 0x000C (0x003C - 0x0048)
class UKynapseLpfPreMerger : public UObject
{
public:
	class FString                                      ClassName;                                     // 0x003C (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseLpfPreMerger");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseLpfPreMerger_Grid
// 0x0010 (0x0048 - 0x0058)
class UKynapseLpfPreMerger_Grid : public UKynapseLpfPreMerger
{
public:
	float                                              MaxGridWidth;                                  // 0x0048 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              MaxPrecision;                                  // 0x004C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            MaxVertexCount;                                // 0x0050 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            MaxContourCount;                               // 0x0054 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseLpfPreMerger_Grid");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseLpfPreMerger_Polygon
// 0x0000 (0x0048 - 0x0048)
class UKynapseLpfPreMerger_Polygon : public UKynapseLpfPreMerger
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseLpfPreMerger_Polygon");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseMesh
// 0x0010 (0x003C - 0x004C)
class UKynapseMesh : public UObject
{
public:
	class TArray<uint8_t>                              Data;                                          // 0x003C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class UKynapseTag*                                 DataTag;                                       // 0x0048 (0x0004) [0x0000000000000001] (CPF_Edit)    

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseMesh");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseObstacleFractured
// 0x0000 (0x0290 - 0x0290)
class AKynapseObstacleFractured : public AFracturedStaticMeshActor
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseObstacleFractured");
		}

		return uClassPointer;
	};


	void eventExplode();
	void eventTakeDamage(int32_t Damage, class AController* EventInstigator, const struct FVector& HitLocation, const struct FVector& Momentum, class UClass* DamageType, const struct FTraceHitInfo& optionalHitInfo, class AActor* optionalDamageCauser);
};
// Class Kynapse.KynapsePawn
// 0x0008 (0x05DC - 0x05E4)
class AKynapsePawn : public AGamePawn
{
public:
	class UKynapseHandle*                              KynapseHandle;                                 // 0x05DC (0x0004) [0x000000000408000B] (CPF_Edit | CPF_Const | CPF_ExportObject | CPF_Component | CPF_EditInline)
	class UDynamicLightEnvironmentComponent*           LightEnvironment;                              // 0x05E0 (0x0004) [0x00000000040A000B] (CPF_Edit | CPF_Const | CPF_ExportObject | CPF_EditConst | CPF_Component | CPF_EditInline)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapsePawn");
		}

		return uClassPointer;
	};


	void eventOnAnimEnd(class UAnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime);
	void eventBump(class AActor* Other, class UPrimitiveComponent* OtherComp, const struct FVector& HitNormal);
	void SphinxAnimEnd(class UAnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime);
};
// Class Kynapse.KynapseProfileDefinition
// 0x0010 (0x003C - 0x004C)
class UKynapseProfileDefinition : public UObject
{
public:
	int32_t                                            profileMaxCount;                               // 0x003C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	class TArray<struct FEntityInfoUse>                EntityInfos;                                   // 0x0040 (0x000C) [0x000000000440000B] (CPF_Edit | CPF_Const | CPF_ExportObject | CPF_NeedCtorLink | CPF_EditInline)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseProfileDefinition");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseSeedGraphPoint
// 0x0004 (0x0228 - 0x022C)
class AKynapseSeedGraphPoint : public AActor
{
public:
	class UKynapseTag*                                 DataTag;                                       // 0x0228 (0x0004) [0x0000000000000001] (CPF_Edit)    

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseSeedGraphPoint");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseJumpSeedGraphPoint
// 0x0000 (0x022C - 0x022C)
class AKynapseJumpSeedGraphPoint : public AKynapseSeedGraphPoint
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseJumpSeedGraphPoint");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseStandardPathdataGenerationService
// 0x007C (0x0228 - 0x02A4)
class AKynapseStandardPathdataGenerationService : public AActor
{
public:
	uint32_t                                           Active : 1;                                    // 0x0228 (0x0004) [0x0000000000000002] [0x00000001] (CPF_Const)
	uint32_t                                           displayInEditor : 1;                           // 0x0228 (0x0004) [0x0000000000000003] [0x00000002] (CPF_Edit | CPF_Const)
	uint32_t                                           displayInGame : 1;                             // 0x0228 (0x0004) [0x0000000000000002] [0x00000004] (CPF_Const)
	uint32_t                                           streamed : 1;                                  // 0x0228 (0x0004) [0x0000000000000002] [0x00000008] (CPF_Const)
	uint32_t                                           UseKynapseDataPackage : 1;                     // 0x0228 (0x0004) [0x0000000000000001] [0x00000010] (CPF_Edit)
	struct FPointer                                    displayGraph;                                  // 0x022C (0x0004) [0x0000000000000000]               
	class AKynapseExplorationVolume*                   ExplorationBoundingBox;                        // 0x0230 (0x0004) [0x0000000014000003] (CPF_Edit | CPF_Const | CPF_EditInline | CPF_EditInlineUse)
	class TArray<class AActor*>                        seeds;                                         // 0x0234 (0x000C) [0x0000000014400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink | CPF_EditInline | CPF_EditInlineUse)
	float                                              DistEdgeMax;                                   // 0x0240 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              EntityRadius;                                  // 0x0244 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	class FString                                      displayNameInPie;                              // 0x0248 (0x000C) [0x0000000000600001] (CPF_Edit | CPF_NeedCtorLink)
	class UKynapseGraph*                               outputGraph;                                   // 0x0254 (0x0004) [0x0000000000220001] (CPF_Edit | CPF_EditConst)
	class UKynapseGraph*                               outputLinkedGraph;                             // 0x0258 (0x0004) [0x0000000000220001] (CPF_Edit | CPF_EditConst)
	class UKynapseMesh*                                outputLinkedAiMesh;                            // 0x025C (0x0004) [0x0000000000220001] (CPF_Edit | CPF_EditConst)
	struct FPointer                                    loadedGraph;                                   // 0x0260 (0x0004) [0x0000000000000000]               
	struct FPointer                                    loadedAIMesh;                                  // 0x0264 (0x0004) [0x0000000000000000]               
	class UKynapseTag*                                 DataTag;                                       // 0x0268 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	struct FGuid                                       MapBuilderGuid;                                // 0x026C (0x0010) [0x0000000000220003] (CPF_Edit | CPF_Const | CPF_EditConst)
	int32_t                                            Uid;                                           // 0x027C (0x0004) [0x0000000000000002] (CPF_Const)   
	struct FAdditionalDataParams                       additionalData;                                // 0x0280 (0x0018) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	class TArray<class UKynapsePathdataGenerationModifier*> Modifiers;                                     // 0x0298 (0x000C) [0x0000000004400009] (CPF_Edit | CPF_ExportObject | CPF_NeedCtorLink | CPF_EditInline)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseStandardPathdataGenerationService");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseWorldServiceFlyBuilder
// 0x0028 (0x02A4 - 0x02CC)
class AKynapseWorldServiceFlyBuilder : public AKynapseStandardPathdataGenerationService
{
public:
	float                                              Pitch;                                         // 0x02A4 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              BoxSize;                                       // 0x02A8 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              VerticalBoxSize;                               // 0x02AC (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	struct FKynapseWorldServiceFlyBuilderAdvancedParameters AdvancedParams;                                // 0x02B0 (0x001C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseWorldServiceFlyBuilder");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseWorldServiceMapBuilder
// 0x0098 (0x02A4 - 0x033C)
class AKynapseWorldServiceMapBuilder : public AKynapseStandardPathdataGenerationService
{
public:
	class FString                                      Filename;                                      // 0x02A4 (0x000C) [0x0000000000400002] (CPF_Const | CPF_NeedCtorLink)
	class UKynapseMesh*                                outputAiMesh;                                  // 0x02B0 (0x0004) [0x0000000000200001] (CPF_Edit)    
	class UKynapseUDG*                                 outputUDG;                                     // 0x02B4 (0x0004) [0x0000000000200000]               
	uint32_t                                           useUDGAlts : 1;                                // 0x02B8 (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)
	uint32_t                                           ExploreAll : 1;                                // 0x02B8 (0x0004) [0x0000000000000002] [0x00000002] (CPF_Const)
	class TArray<class AKynapseExclusionVolume*>       exclusionAreas;                                // 0x02BC (0x000C) [0x0000000014400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink | CPF_EditInline | CPF_EditInlineUse)
	class TArray<class AKynapseLocalRecomputationVolume*> areasToExplore;                                // 0x02C8 (0x000C) [0x0000000000400002] (CPF_Const | CPF_NeedCtorLink)
	struct FPointer                                    areasToExplorePointer;                         // 0x02D4 (0x0004) [0x0000000000000000]               
	struct FPhysicalParams                             Physical;                                      // 0x02D8 (0x001C) [0x0000000000000003] (CPF_Edit | CPF_Const)
	struct FAccuracyParams                             Accuracy;                                      // 0x02F4 (0x0014) [0x0000000000000003] (CPF_Edit | CPF_Const)
	struct FProcessParams                              Process;                                       // 0x0308 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	struct FAdvancedParams                             Advanced;                                      // 0x030C (0x0018) [0x0000000000000003] (CPF_Edit | CPF_Const)
	struct FPointer                                    displayAIMesh;                                 // 0x0324 (0x0004) [0x0000000000000000]               
	struct FHidingDataParams                           hidingData;                                    // 0x0328 (0x0014) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseWorldServiceMapBuilder");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseTag
// 0x0000 (0x003C - 0x003C)
class UKynapseTag : public UObject
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseTag");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseTeamCreationData
// 0x001C (0x003C - 0x0058)
class UKynapseTeamCreationData : public UObject
{
public:
	class FString                                      TeamName;                                      // 0x003C (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	ESphinxTeamContainerType                           TeamType;                                      // 0x0048 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            UnknownData00[0x3];                              // 0x0049 (0x0003) MISSED OFFSET
	int32_t                                            TeamSize;                                      // 0x004C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	class UKynapseTeamDefinition*                      TeamDefinition;                                // 0x0050 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	struct FPointer                                    KynapseTeam;                                   // 0x0054 (0x0004) [0x0000000000000002] (CPF_Const)   

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseTeamCreationData");
		}

		return uClassPointer;
	};


	void PostInitializeTeam();
	void CreateKynapseTeam();
};
// Class Kynapse.SphinxTeamCreationDataFight
// 0x0000 (0x0058 - 0x0058)
class USphinxTeamCreationDataFight : public UKynapseTeamCreationData
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxTeamCreationDataFight");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseTeamDefinition
// 0x000C (0x003C - 0x0048)
class UKynapseTeamDefinition : public UObject
{
public:
	class FString                                      ClassName;                                     // 0x003C (0x000C) [0x0000000000420003] (CPF_Edit | CPF_Const | CPF_EditConst | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseTeamDefinition");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxTeamDefinitionFight
// 0x0000 (0x0048 - 0x0048)
class USphinxTeamDefinitionFight : public UKynapseTeamDefinition
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxTeamDefinitionFight");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseTraversalDefinition
// 0x0030 (0x003C - 0x006C)
class UKynapseTraversalDefinition : public UObject
{
public:
	struct FTraversalAperiodicTask                     AperiodicTask;                                 // 0x003C (0x0018) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	float                                              MaxDistance;                                   // 0x0054 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            MaxEdgeCount;                                  // 0x0058 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            InstanceCount;                                 // 0x005C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	class FString                                      ClassName;                                     // 0x0060 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseTraversalDefinition");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseUDG
// 0x0010 (0x003C - 0x004C)
class UKynapseUDG : public UObject
{
public:
	class TArray<uint8_t>                              Data;                                          // 0x003C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	uint32_t                                           isUDGAlts : 1;                                 // 0x0048 (0x0004) [0x0000000000000000] [0x00000001] 

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseUDG");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseWorld
// 0x00A8 (0x0228 - 0x02D0)
class AKynapseWorld : public AActor
{
public:
	class FString                                      World_Name;                                    // 0x0228 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	float                                              World_OneMeter;                                // 0x0234 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            World_nbEntities;                              // 0x0238 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            World_nbTeams;                                 // 0x023C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	class UKynapseTeamCreationData*                    TeamCreationDataSet[10];                       // 0x0240 (0x0028) [0x000000000440000B] (CPF_Edit | CPF_Const | CPF_ExportObject | CPF_NeedCtorLink | CPF_EditInline)
	float                                              World_TimePerFrame;                            // 0x0268 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	class UKynapseWorldService*                        servicesList[10];                              // 0x026C (0x0028) [0x000000000440000B] (CPF_Edit | CPF_Const | CPF_ExportObject | CPF_NeedCtorLink | CPF_EditInline)
	class TArray<class UKynapseWorldService*>          servicesList_Win32Only;                        // 0x0294 (0x000C) [0x000000000440000B] (CPF_Edit | CPF_Const | CPF_ExportObject | CPF_NeedCtorLink | CPF_EditInline)
	class TArray<class UKynapseWorldService*>          servicesList_XBox360Only;                      // 0x02A0 (0x000C) [0x000000000440000B] (CPF_Edit | CPF_Const | CPF_ExportObject | CPF_NeedCtorLink | CPF_EditInline)
	class TArray<class UKynapseWorldService*>          servicesList_PS3Only;                          // 0x02AC (0x000C) [0x000000000440000B] (CPF_Edit | CPF_Const | CPF_ExportObject | CPF_NeedCtorLink | CPF_EditInline)
	class TArray<class UKynapseEntityDefinition*>      EntityDefinitionList;                          // 0x02B8 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	class TArray<class UFpdBuilder*>                   FpdBuildersList;                               // 0x02C4 (0x000C) [0x000000000440000B] (CPF_Edit | CPF_Const | CPF_ExportObject | CPF_NeedCtorLink | CPF_EditInline)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseWorld");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseWorldService
// 0x0030 (0x003C - 0x006C)
class UKynapseWorldService : public UObject
{
public:
	class TArray<struct FWServiceAperiodicTask>        time_aperiodicTasksList;                       // 0x003C (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	class TArray<struct FWServicePeriodicTask>         time_periodicTasksList;                        // 0x0048 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	class FString                                      serviceName;                                   // 0x0054 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	class FString                                      ClassName;                                     // 0x0060 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseWorldService");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseWorldServiceAiMeshLayerManager
// 0x000C (0x006C - 0x0078)
class UKynapseWorldServiceAiMeshLayerManager : public UKynapseWorldService
{
public:
	class TArray<class UKynapseAiMeshLayerDefinition*> Layers;                                        // 0x006C (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseWorldServiceAiMeshLayerManager");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseWorldServiceAIMeshManager
// 0x0000 (0x006C - 0x006C)
class UKynapseWorldServiceAIMeshManager : public UKynapseWorldService
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseWorldServiceAIMeshManager");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseWorldServiceEntityManager
// 0x0018 (0x006C - 0x0084)
class UKynapseWorldServiceEntityManager : public UKynapseWorldService
{
public:
	class TArray<class UKynapseFilter*>                declaredFilters;                               // 0x006C (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	class TArray<class UKynapseProfileDefinition*>     Profiles;                                      // 0x0078 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseWorldServiceEntityManager");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseWorldServiceFpdGraphToolBoxManager
// 0x0000 (0x006C - 0x006C)
class UKynapseWorldServiceFpdGraphToolBoxManager : public UKynapseWorldService
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseWorldServiceFpdGraphToolBoxManager");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseWorldServiceFpdPathObjectManager
// 0x000C (0x006C - 0x0078)
class UKynapseWorldServiceFpdPathObjectManager : public UKynapseWorldService
{
public:
	class TArray<class UKynapseEntityDefinitionStaticPathObject*> POEntityDefs;                                  // 0x006C (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseWorldServiceFpdPathObjectManager");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseWorldServiceGapManager
// 0x0004 (0x006C - 0x0070)
class UKynapseWorldServiceGapManager : public UKynapseWorldService
{
public:
	int32_t                                            MaxGaps;                                       // 0x006C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseWorldServiceGapManager");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseWorldServiceGraphManager
// 0x0000 (0x006C - 0x006C)
class UKynapseWorldServiceGraphManager : public UKynapseWorldService
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseWorldServiceGraphManager");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseWorldServiceLpfManager
// 0x000C (0x006C - 0x0078)
class UKynapseWorldServiceLpfManager : public UKynapseWorldService
{
public:
	class TArray<struct FLpfContext>                   contexts;                                      // 0x006C (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseWorldServiceLpfManager");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseWorldServiceOutlineComputation
// 0x0000 (0x006C - 0x006C)
class UKynapseWorldServiceOutlineComputation : public UKynapseWorldService
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseWorldServiceOutlineComputation");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseWorldServicePointLockManager
// 0x0018 (0x006C - 0x0084)
class UKynapseWorldServicePointLockManager : public UKynapseWorldService
{
public:
	uint32_t                                           AutoLock : 1;                                  // 0x006C (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)
	int32_t                                            MaxLockPerEntity;                              // 0x0070 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              ExpirationDelay;                               // 0x0074 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              GridPitch;                                     // 0x0078 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              ImmobilityDelay;                               // 0x007C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              ImmobilityDistance;                            // 0x0080 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseWorldServicePointLockManager");
		}

		return uClassPointer;
	};

};
// Class Kynapse.LinkedPathdataRenderingComponent
// 0x0000 (0x01D4 - 0x01D4)
class ULinkedPathdataRenderingComponent : public UPrimitiveComponent
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.LinkedPathdataRenderingComponent");
		}

		return uClassPointer;
	};

};
// Class Kynapse.PathdataRenderingComponent
// 0x0000 (0x01D4 - 0x01D4)
class UPathdataRenderingComponent : public UPrimitiveComponent
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.PathdataRenderingComponent");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SeqAct_AIFlee
// 0x0008 (0x00F8 - 0x0100)
class USeqAct_AIFlee : public USeqAct_Latent
{
public:
	uint32_t                                           bInterruptable : 1;                            // 0x00F8 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	float                                              Duration;                                      // 0x00FC (0x0004) [0x0000000000000001] (CPF_Edit)    

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SeqAct_AIFlee");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SeqAct_AIFollow
// 0x0008 (0x00F8 - 0x0100)
class USeqAct_AIFollow : public USeqAct_Latent
{
public:
	uint32_t                                           bInterruptable : 1;                            // 0x00F8 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	float                                              Duration;                                      // 0x00FC (0x0004) [0x0000000000000001] (CPF_Edit)    

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SeqAct_AIFollow");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SeqAct_AIHide
// 0x0008 (0x00F8 - 0x0100)
class USeqAct_AIHide : public USeqAct_Latent
{
public:
	uint32_t                                           bInterruptable : 1;                            // 0x00F8 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	float                                              Duration;                                      // 0x00FC (0x0004) [0x0000000000000001] (CPF_Edit)    

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SeqAct_AIHide");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SeqAct_AIShoot
// 0x0008 (0x00F8 - 0x0100)
class USeqAct_AIShoot : public USeqAct_Latent
{
public:
	uint32_t                                           bInterruptable : 1;                            // 0x00F8 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	float                                              Duration;                                      // 0x00FC (0x0004) [0x0000000000000001] (CPF_Edit)    

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SeqAct_AIShoot");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SeqAct_AIWander
// 0x0008 (0x00F8 - 0x0100)
class USeqAct_AIWander : public USeqAct_Latent
{
public:
	uint32_t                                           bInterruptable : 1;                            // 0x00F8 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	float                                              Duration;                                      // 0x00FC (0x0004) [0x0000000000000001] (CPF_Edit)    

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SeqAct_AIWander");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SeqAct_ConfigSphinxAgent
// 0x0018 (0x00E8 - 0x0100)
class USeqAct_ConfigSphinxAgent : public USequenceAction
{
public:
	class TArray<class UObject*>                       ConfigObjects;                                 // 0x00E8 (0x000C) [0x0000000000402000] (CPF_Transient | CPF_NeedCtorLink)
	uint32_t                                           bIsSleeping : 1;                               // 0x00F4 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bIsIdle : 1;                                   // 0x00F4 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint32_t                                           bIsWandering : 1;                              // 0x00F4 (0x0004) [0x0000000000000001] [0x00000004] (CPF_Edit)
	uint32_t                                           bIsFollowingPath : 1;                          // 0x00F4 (0x0004) [0x0000000000000001] [0x00000008] (CPF_Edit)
	uint32_t                                           bIsFighting : 1;                               // 0x00F4 (0x0004) [0x0000000000000001] [0x00000010] (CPF_Edit)
	uint32_t                                           bNotifyTeammateToFight : 1;                    // 0x00F4 (0x0004) [0x0000000000000001] [0x00000020] (CPF_Edit)
	uint32_t                                           bOverWritteSightDistance : 1;                  // 0x00F4 (0x0004) [0x0000000000000001] [0x00000040] (CPF_Edit)
	int32_t                                            AlternateWarningPackageIndex;                  // 0x00F8 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              OverWritteSightDistanceValue;                  // 0x00FC (0x0004) [0x0000000000000001] (CPF_Edit)    

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SeqAct_ConfigSphinxAgent");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SeqAct_SphinxAIFollow
// 0x0008 (0x00F8 - 0x0100)
class USeqAct_SphinxAIFollow : public USeqAct_Latent
{
public:
	uint32_t                                           bInterruptable : 1;                            // 0x00F8 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	float                                              Duration;                                      // 0x00FC (0x0004) [0x0000000000000001] (CPF_Edit)    

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SeqAct_SphinxAIFollow");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SeqAct_SphinxNotifyKismetControl
// 0x0004 (0x00E8 - 0x00EC)
class USeqAct_SphinxNotifyKismetControl : public USequenceAction
{
public:
	uint32_t                                           bSetKismetControl : 1;                         // 0x00E8 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SeqAct_SphinxNotifyKismetControl");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SeqAct_SphinxNotifyTeammateFight
// 0x0004 (0x00E8 - 0x00EC)
class USeqAct_SphinxNotifyTeammateFight : public USequenceAction
{
public:
	uint32_t                                           bNotifyTeammate : 1;                           // 0x00E8 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SeqAct_SphinxNotifyTeammateFight");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SeqAct_SphinxSubConditionNotify
// 0x0008 (0x00E8 - 0x00F0)
class USeqAct_SphinxSubConditionNotify : public USequenceAction
{
public:
	class FName                                        EventName;                                     // 0x00E8 (0x0008) [0x0000000000000001] (CPF_Edit)    

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SeqAct_SphinxSubConditionNotify");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SeqEvent_SphinxSequenceActivated
// 0x0008 (0x010C - 0x0114)
class USeqEvent_SphinxSequenceActivated : public USeqEvent_SequenceActivated
{
public:
	class FName                                        EventName;                                     // 0x010C (0x0008) [0x0000000000000001] (CPF_Edit)    

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SeqEvent_SphinxSequenceActivated");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxInterstingPoint
// 0x0038 (0x0300 - 0x0338)
class ASphinxInterstingPoint : public ANavigationPoint
{
public:
	ESphinxIP                                          Type;                                          // 0x0300 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            UnknownData00[0x3];                              // 0x0301 (0x0003) MISSED OFFSET
	float                                              ToSeekerDistanceSQ;                            // 0x0304 (0x0004) [0x0000000000002000] (CPF_Transient)
	class APawn*                                       m_Pawn_MovingToHere;                           // 0x0308 (0x0004) [0x0000000000000000]               
	uint32_t                                           bEnabled : 1;                                  // 0x030C (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	float                                              AttractRadius;                                 // 0x0310 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              StopTurnTime;                                  // 0x0314 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class AActor*                                      EnterPointActor;                               // 0x0318 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class UAudioComponent*                             IPAmbientSound;                                // 0x031C (0x0004) [0x0000000004080009] (CPF_Edit | CPF_ExportObject | CPF_Component | CPF_EditInline)
	struct FVector                                     EnterPointPosition;                            // 0x0320 (0x000C) [0x0000000000000000]               
	class TArray<struct FAccessNPC>                    AccessNpcList;                                 // 0x032C (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxInterstingPoint");
		}

		return uClassPointer;
	};


	void ShowRadius();
	void eventPostBeginPlay();
};
// Class Kynapse.SphinxScriptSequenceEventPackage
// 0x0028 (0x003C - 0x0064)
class USphinxScriptSequenceEventPackage : public UObject
{
public:
	class FString                                      EventPackageNameTag;                           // 0x003C (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	uint32_t                                           bIsInAttackProcess : 1;                        // 0x0048 (0x0004) [0x0000000000000002] [0x00000001] (CPF_Const)
	class TArray<class USphinxSequenceEventBase*>      ScriptEvents;                                  // 0x004C (0x000C) [0x000000000440000B] (CPF_Edit | CPF_Const | CPF_ExportObject | CPF_NeedCtorLink | CPF_EditInline)
	class TArray<class USphinxSequenceEventBase*>      EditorOnlyBackupScriptEvents;                  // 0x0058 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxScriptSequenceEventPackage");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxScriptSequenceHealthEventPackage
// 0x000C (0x0064 - 0x0070)
class USphinxScriptSequenceHealthEventPackage : public USphinxScriptSequenceEventPackage
{
public:
	int32_t                                            AbsoulteHealthValue;                           // 0x0064 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            HealthPercent;                                 // 0x0068 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	uint32_t                                           CanBreakBySubCondition : 1;                    // 0x006C (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)
	uint32_t                                           ShouldReturnOriginalPackage : 1;               // 0x006C (0x0004) [0x0000000000000003] [0x00000002] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxScriptSequenceHealthEventPackage");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventBase
// 0x0001 (0x003C - 0x003D)
class USphinxSequenceEventBase : public UObject
{
public:
	ESphinxSequenceEventType                           SequenceType;                                  // 0x003C (0x0001) [0x0000000000000002] (CPF_Const)   

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventBase");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceActionConditionJump
// 0x0013 (0x003D - 0x0050)
class USphinxSequenceActionConditionJump : public USphinxSequenceEventBase
{
public:
	class TArray<struct FConditionCheckList>           Conditions;                                    // 0x0040 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	int32_t                                            FailJumpIndex;                                 // 0x004C (0x0004) [0x0000000000000001] (CPF_Edit)    

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceActionConditionJump");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceActionExit
// 0x0000 (0x003D - 0x003D)
class USphinxSequenceActionExit : public USphinxSequenceEventBase
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceActionExit");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventActiveShield
// 0x000B (0x003D - 0x0048)
class USphinxSequenceEventActiveShield : public USphinxSequenceEventBase
{
public:
	uint32_t                                           Actived : 1;                                   // 0x0040 (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)
	int32_t                                            ShieldIndex;                                   // 0x0044 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventActiveShield");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventActiveUIPrompt
// 0x0007 (0x003D - 0x0044)
class USphinxSequenceEventActiveUIPrompt : public USphinxSequenceEventBase
{
public:
	uint32_t                                           ActiveGrabEndUI : 1;                           // 0x0040 (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventActiveUIPrompt");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventAnnounceInFightProcess
// 0x0007 (0x003D - 0x0044)
class USphinxSequenceEventAnnounceInFightProcess : public USphinxSequenceEventBase
{
public:
	uint32_t                                           Actived : 1;                                   // 0x0040 (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventAnnounceInFightProcess");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventAttachAlice
// 0x002B (0x003D - 0x0068)
class USphinxSequenceEventAttachAlice : public USphinxSequenceEventBase
{
public:
	float                                              AttachTime;                                    // 0x0040 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class FName                                        AttachAnimName;                                // 0x0044 (0x0008) [0x0000000000020003] (CPF_Edit | CPF_Const | CPF_EditConst)
	int32_t                                            AttachAnimIndex;                               // 0x004C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	class FName                                        DetachAnimName;                                // 0x0050 (0x0008) [0x0000000000020003] (CPF_Edit | CPF_Const | CPF_EditConst)
	int32_t                                            DetachAnimIndex;                               // 0x0058 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	struct FRotator                                    PlayRotator;                                   // 0x005C (0x000C) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventAttachAlice");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventBlendToLocation
// 0x001B (0x003D - 0x0058)
class USphinxSequenceEventBlendToLocation : public USphinxSequenceEventBase
{
public:
	int32_t                                            Index;                                         // 0x0040 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              BlendSpeed;                                    // 0x0044 (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FRotator                                    RotationRate;                                  // 0x0048 (0x000C) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           UsingNewBlendingCode_RemoveIfNoBug : 1;        // 0x0054 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventBlendToLocation");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventChangeAnimTreeBlendingBranch
// 0x0007 (0x003D - 0x0044)
class USphinxSequenceEventChangeAnimTreeBlendingBranch : public USphinxSequenceEventBase
{
public:
	int32_t                                            BranchIndex;                                   // 0x0040 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventChangeAnimTreeBlendingBranch");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventChangeAttachedActorDamageAnim
// 0x000F (0x003D - 0x004C)
class USphinxSequenceEventChangeAttachedActorDamageAnim : public USphinxSequenceEventBase
{
public:
	int32_t                                            ActorID;                                       // 0x0040 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	EDamageStrengthTypeSphinx                          DamageStrength;                                // 0x0044 (0x0001) [0x0000000000000003] (CPF_Edit | CPF_Const)
	uint8_t                                            UnknownData00[0x3];                              // 0x0045 (0x0003) MISSED OFFSET
	int32_t                                            AnimIndex;                                     // 0x0048 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventChangeAttachedActorDamageAnim");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventChangeCollisionPhAT
// 0x0007 (0x003D - 0x0044)
class USphinxSequenceEventChangeCollisionPhAT : public USphinxSequenceEventBase
{
public:
	int32_t                                            CollisionPhysicAssetIndex;                     // 0x0040 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventChangeCollisionPhAT");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventChangeCollisionType
// 0x000C (0x003D - 0x0049)
class USphinxSequenceEventChangeCollisionType : public USphinxSequenceEventBase
{
public:
	int32_t                                            dumysize;                                      // 0x0040 (0x0004) [0x0000000000000000]               
	uint32_t                                           bBlockVB : 1;                                  // 0x0044 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bBlockHH : 1;                                  // 0x0044 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint32_t                                           bBlockES : 1;                                  // 0x0044 (0x0004) [0x0000000000000001] [0x00000004] (CPF_Edit)
	uint32_t                                           bBlockTC : 1;                                  // 0x0044 (0x0004) [0x0000000000000001] [0x00000008] (CPF_Edit)
	ECollisionType                                     CollisionType;                                 // 0x0048 (0x0001) [0x0000000000000001] (CPF_Edit)    

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventChangeCollisionType");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventChangeDamageAnim
// 0x001B (0x003D - 0x0058)
class USphinxSequenceEventChangeDamageAnim : public USphinxSequenceEventBase
{
public:
	int32_t                                            AnimIndex;                                     // 0x0040 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	EDamageStrengthTypeSphinx                          DamageStrength;                                // 0x0044 (0x0001) [0x0000000000000003] (CPF_Edit | CPF_Const)
	uint8_t                                            UnknownData00[0x3];                              // 0x0045 (0x0003) MISSED OFFSET
	struct FRotator                                    DamageRotationRate;                            // 0x0048 (0x000C) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bKnockBack : 1;                                // 0x0054 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bPhysicalAnim : 1;                             // 0x0054 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventChangeDamageAnim");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventChangeFightConditionIndex
// 0x000B (0x003D - 0x0048)
class USphinxSequenceEventChangeFightConditionIndex : public USphinxSequenceEventBase
{
public:
	int32_t                                            ConditionIndex;                                // 0x0040 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	uint32_t                                           bCleanOldInfo : 1;                             // 0x0044 (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)
	uint32_t                                           bBreakCurrentPackage : 1;                      // 0x0044 (0x0004) [0x0000000000000003] [0x00000002] (CPF_Edit | CPF_Const)
	uint32_t                                           ReturnPrevConditionIndex : 1;                  // 0x0044 (0x0004) [0x0000000000000001] [0x00000004] (CPF_Edit)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventChangeFightConditionIndex");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventChangeMaterial
// 0x0047 (0x003D - 0x0084)
class USphinxSequenceEventChangeMaterial : public USphinxSequenceEventBase
{
public:
	class TArray<int32_t>                              MatID;                                         // 0x0040 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	class TArray<class UMaterialInstance*>             ChangeMaterial;                                // 0x004C (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	class TArray<class UMaterialInstance*>             ChangeLockOnHighlightMaterial;                 // 0x0058 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	class TArray<class UMaterialInstance*>             ChangeDeathMaterial;                           // 0x0064 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	class TArray<class FName>                          TimeVaryParamName;                             // 0x0070 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	uint32_t                                           UseDuplicate : 1;                              // 0x007C (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)
	int32_t                                            ComponentID;                                   // 0x0080 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventChangeMaterial");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventChangeMovingPhAT
// 0x0007 (0x003D - 0x0044)
class USphinxSequenceEventChangeMovingPhAT : public USphinxSequenceEventBase
{
public:
	class UPhysicsAsset*                               SetPhysicsAsset;                               // 0x0040 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventChangeMovingPhAT");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventChangePhysic
// 0x0008 (0x003D - 0x0045)
class USphinxSequenceEventChangePhysic : public USphinxSequenceEventBase
{
public:
	int32_t                                            Dummy;                                         // 0x0040 (0x0004) [0x0000000000000000]               
	EPhysics                                           SetPhysics;                                    // 0x0044 (0x0001) [0x0000000000000001] (CPF_Edit)    

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventChangePhysic");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventDestroyComponent
// 0x0007 (0x003D - 0x0044)
class USphinxSequenceEventDestroyComponent : public USphinxSequenceEventBase
{
public:
	int32_t                                            ComponentIndex;                                // 0x0040 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventDestroyComponent");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventFadeComponent
// 0x0013 (0x003D - 0x0050)
class USphinxSequenceEventFadeComponent : public USphinxSequenceEventBase
{
public:
	class FName                                        TimeVaryParamName;                             // 0x0040 (0x0008) [0x0000000000000003] (CPF_Edit | CPF_Const)
	uint32_t                                           UseDuplicate : 1;                              // 0x0048 (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)
	int32_t                                            ComponentID;                                   // 0x004C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventFadeComponent");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventKillAttachedActor
// 0x0007 (0x003D - 0x0044)
class USphinxSequenceEventKillAttachedActor : public USphinxSequenceEventBase
{
public:
	int32_t                                            ActorID;                                       // 0x0040 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventKillAttachedActor");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventLockTargets
// 0x000B (0x003D - 0x0048)
class USphinxSequenceEventLockTargets : public USphinxSequenceEventBase
{
public:
	int32_t                                            LockIndex;                                     // 0x0040 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	uint32_t                                           bEnabled : 1;                                  // 0x0044 (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventLockTargets");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventModifyPawnHealth
// 0x000F (0x003D - 0x004C)
class USphinxSequenceEventModifyPawnHealth : public USphinxSequenceEventBase
{
public:
	int32_t                                            Value;                                         // 0x0040 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	uint32_t                                           bSetHealthValue : 1;                           // 0x0044 (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)
	float                                              absolute_HealthSetValue;                       // 0x0048 (0x0004) [0x0000000000000001] (CPF_Edit)    

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventModifyPawnHealth");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventModifyPawnMaxHealth
// 0x0007 (0x003D - 0x0044)
class USphinxSequenceEventModifyPawnMaxHealth : public USphinxSequenceEventBase
{
public:
	int32_t                                            MaxHealthValue;                                // 0x0040 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventModifyPawnMaxHealth");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventModifyRotateAndSpeed
// 0x0013 (0x003D - 0x0050)
class USphinxSequenceEventModifyRotateAndSpeed : public USphinxSequenceEventBase
{
public:
	struct FRotator                                    SetRotation;                                   // 0x0040 (0x000C) [0x0000000000000001] (CPF_Edit)    
	float                                              SetSpeed;                                      // 0x004C (0x0004) [0x0000000000000001] (CPF_Edit)    

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventModifyRotateAndSpeed");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventMoveToGotoLocation
// 0x0007 (0x003D - 0x0044)
class USphinxSequenceEventMoveToGotoLocation : public USphinxSequenceEventBase
{
public:
	int32_t                                            Index;                                         // 0x0040 (0x0004) [0x0000000000000001] (CPF_Edit)    

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventMoveToGotoLocation");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventMoveToOriginalSpawnLocation
// 0x0000 (0x003D - 0x003D)
class USphinxSequenceEventMoveToOriginalSpawnLocation : public USphinxSequenceEventBase
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventMoveToOriginalSpawnLocation");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventPlayAnim
// 0x0023 (0x003D - 0x0060)
class USphinxSequenceEventPlayAnim : public USphinxSequenceEventBase
{
public:
	class FName                                        AnimName;                                      // 0x0040 (0x0008) [0x0000000000020003] (CPF_Edit | CPF_Const | CPF_EditConst)
	int32_t                                            AnimNameIndex;                                 // 0x0048 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	struct FRotator                                    PlayRotator;                                   // 0x004C (0x000C) [0x0000000000000003] (CPF_Edit | CPF_Const)
	uint32_t                                           bCleanConditionHitPlayerInfo : 1;              // 0x0058 (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)
	uint32_t                                           EnableSwitchLockOnTarget : 1;                  // 0x0058 (0x0004) [0x0000000000000003] [0x00000002] (CPF_Edit | CPF_Const)
	uint32_t                                           DoBreakWhenSwitchPackage : 1;                  // 0x0058 (0x0004) [0x0000000000000003] [0x00000004] (CPF_Edit | CPF_Const)
	int32_t                                            LockIndex;                                     // 0x005C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventPlayAnim");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventPlayAnimOnAttachedActor
// 0x000B (0x003D - 0x0048)
class USphinxSequenceEventPlayAnimOnAttachedActor : public USphinxSequenceEventBase
{
public:
	int32_t                                            ActorID;                                       // 0x0040 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            AnimIndex;                                     // 0x0044 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventPlayAnimOnAttachedActor");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventPlayMorphTarget
// 0x0017 (0x003D - 0x0054)
class USphinxSequenceEventPlayMorphTarget : public USphinxSequenceEventBase
{
public:
	float                                              MorphStartValue;                               // 0x0040 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              MorphEndValue;                                 // 0x0044 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              MorphTime;                                     // 0x0048 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	class FName                                        MorphNodeName;                                 // 0x004C (0x0008) [0x0000000000000001] (CPF_Edit)    

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventPlayMorphTarget");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventPlayParticle
// 0x0023 (0x003D - 0x0060)
class USphinxSequenceEventPlayParticle : public USphinxSequenceEventBase
{
public:
	class UParticleSystem*                             Particle;                                      // 0x0040 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	class FName                                        Socket;                                        // 0x0044 (0x0008) [0x0000000000000001] (CPF_Edit)    
	class FName                                        Bone;                                          // 0x004C (0x0008) [0x0000000000000001] (CPF_Edit)    
	float                                              DrawScale;                                     // 0x0054 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            ComponentIndex;                                // 0x0058 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bAttach : 1;                                   // 0x005C (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bIgnoreOwnerHiddenIfAttached : 1;              // 0x005C (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint32_t                                           bLoadIfPhysXLevel0 : 1;                        // 0x005C (0x0004) [0x0000000000000001] [0x00000004] (CPF_Edit)
	uint32_t                                           bLoadIfPhysXLevel1 : 1;                        // 0x005C (0x0004) [0x0000000000000001] [0x00000008] (CPF_Edit)
	uint32_t                                           bLoadIfPhysXLevel2 : 1;                        // 0x005C (0x0004) [0x0000000000000001] [0x00000010] (CPF_Edit)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventPlayParticle");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventPlaySound
// 0x0007 (0x003D - 0x0044)
class USphinxSequenceEventPlaySound : public USphinxSequenceEventBase
{
public:
	class USoundCue*                                   Sound;                                         // 0x0040 (0x0004) [0x0000000000000001] (CPF_Edit)    

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventPlaySound");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventPreAttackDist
// 0x0017 (0x003D - 0x0054)
class USphinxSequenceEventPreAttackDist : public USphinxSequenceEventBase
{
public:
	float                                              Dist;                                          // 0x0040 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	uint32_t                                           MoveIntoCameraDir : 1;                         // 0x0044 (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)
	uint32_t                                           bStopWhenMeetNPCBlock : 1;                     // 0x0044 (0x0004) [0x0000000000000003] [0x00000002] (CPF_Edit | CPF_Const)
	uint32_t                                           bFacingAlice : 1;                              // 0x0044 (0x0004) [0x0000000000000003] [0x00000004] (CPF_Edit | CPF_Const)
	float                                              Speed;                                         // 0x0048 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              DefaultUpdateTime;                             // 0x004C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              UpdateTolerateRadius;                          // 0x0050 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventPreAttackDist");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventRagdoll
// 0x0007 (0x003D - 0x0044)
class USphinxSequenceEventRagdoll : public USphinxSequenceEventBase
{
public:
	float                                              PlayTime;                                      // 0x0040 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventRagdoll");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventRandomJump
// 0x000F (0x003D - 0x004C)
class USphinxSequenceEventRandomJump : public USphinxSequenceEventBase
{
public:
	class TArray<int32_t>                              RandomJumpIndexList;                           // 0x0040 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventRandomJump");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventRemoteEvent
// 0x000B (0x003D - 0x0048)
class USphinxSequenceEventRemoteEvent : public USphinxSequenceEventBase
{
public:
	class FName                                        ActiveEventName;                               // 0x0040 (0x0008) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventRemoteEvent");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventRunAnotherPackage
// 0x0013 (0x003D - 0x0050)
class USphinxSequenceEventRunAnotherPackage : public USphinxSequenceEventBase
{
public:
	class FName                                        PackageName;                                   // 0x0040 (0x0008) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            PackageNameIndex;                              // 0x0048 (0x0004) [0x0000000000000002] (CPF_Const)   
	uint32_t                                           PackageNameIndexInited : 1;                    // 0x004C (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           NeedReturnToCurrentPackage : 1;                // 0x004C (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventRunAnotherPackage");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventSetAccelerate
// 0x0007 (0x003D - 0x0044)
class USphinxSequenceEventSetAccelerate : public USphinxSequenceEventBase
{
public:
	float                                              Accelerate;                                    // 0x0040 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventSetAccelerate");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventSetGDGlobeValue
// 0x0013 (0x003D - 0x0050)
class USphinxSequenceEventSetGDGlobeValue : public USphinxSequenceEventBase
{
public:
	int32_t                                            Index;                                         // 0x0040 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            Value;                                         // 0x0044 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class FName                                        CommentName;                                   // 0x0048 (0x0008) [0x0000000000000001] (CPF_Edit)    

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventSetGDGlobeValue");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventSetGotoLocation
// 0x000F (0x003D - 0x004C)
class USphinxSequenceEventSetGotoLocation : public USphinxSequenceEventBase
{
public:
	class TArray<struct FSphinxSquenceGotoInfo>        GotoArray;                                     // 0x0040 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventSetGotoLocation");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventSetHideComponent
// 0x000B (0x003D - 0x0048)
class USphinxSequenceEventSetHideComponent : public USphinxSequenceEventBase
{
public:
	uint32_t                                           bHide : 1;                                     // 0x0040 (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)
	int32_t                                            ComponentID;                                   // 0x0044 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventSetHideComponent");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventSetHideSelf
// 0x0007 (0x003D - 0x0044)
class USphinxSequenceEventSetHideSelf : public USphinxSequenceEventBase
{
public:
	uint32_t                                           bHide : 1;                                     // 0x0040 (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventSetHideSelf");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventSetKnockBackPara
// 0x000B (0x003D - 0x0048)
class USphinxSequenceEventSetKnockBackPara : public USphinxSequenceEventBase
{
public:
	float                                              AbsKnockBackScale;                             // 0x0040 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              AbsKnockBackTotalTime;                         // 0x0044 (0x0004) [0x0000000000000001] (CPF_Edit)    

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventSetKnockBackPara");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventSetNoDamageEffect
// 0x0007 (0x003D - 0x0044)
class USphinxSequenceEventSetNoDamageEffect : public USphinxSequenceEventBase
{
public:
	uint32_t                                           NoDamageEffect : 1;                            // 0x0040 (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)
	uint32_t                                           BlockVorpalBlade : 1;                          // 0x0040 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint32_t                                           BlockHobbyHorse : 1;                           // 0x0040 (0x0004) [0x0000000000000001] [0x00000004] (CPF_Edit)
	uint32_t                                           BlockEyeStaff : 1;                             // 0x0040 (0x0004) [0x0000000000000001] [0x00000008] (CPF_Edit)
	uint32_t                                           BlockTeapotCannon : 1;                         // 0x0040 (0x0004) [0x0000000000000001] [0x00000010] (CPF_Edit)
	uint32_t                                           BlockNPCProject : 1;                           // 0x0040 (0x0004) [0x0000000000000001] [0x00000020] (CPF_Edit)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventSetNoDamageEffect");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventSetNPCDeath
// 0x000B (0x003D - 0x0048)
class USphinxSequenceEventSetNPCDeath : public USphinxSequenceEventBase
{
public:
	int32_t                                            Dummy;                                         // 0x0040 (0x0004) [0x0000000000000000]               
	class UClass*                                      KillDamageType;                                // 0x0044 (0x0004) [0x0000000000000001] (CPF_Edit)    

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventSetNPCDeath");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventSetNPCFightAgentParam
// 0x0017 (0x003D - 0x0054)
class USphinxSequenceEventSetNPCFightAgentParam : public USphinxSequenceEventBase
{
public:
	float                                              m_NearGroupDistance;                           // 0x0040 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              m_NearGroupDistanceOffset;                     // 0x0044 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              m_FarGroupDistance;                            // 0x0048 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              m_FarGroupDistanceOffset;                      // 0x004C (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           m_ChooseNearGroupFirst : 1;                    // 0x0050 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventSetNPCFightAgentParam");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventSetNPCScale
// 0x0007 (0x003D - 0x0044)
class USphinxSequenceEventSetNPCScale : public USphinxSequenceEventBase
{
public:
	float                                              DesiredScale;                                  // 0x0040 (0x0004) [0x0000000000000001] (CPF_Edit)    

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventSetNPCScale");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventSetSonarActive
// 0x0007 (0x003D - 0x0044)
class USphinxSequenceEventSetSonarActive : public USphinxSequenceEventBase
{
public:
	uint32_t                                           bActive : 1;                                   // 0x0040 (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventSetSonarActive");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventSetSonarInfo
// 0x000F (0x003D - 0x004C)
class USphinxSequenceEventSetSonarInfo : public USphinxSequenceEventBase
{
public:
	uint32_t                                           bActive : 1;                                   // 0x0040 (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)
	int32_t                                            ComponentID;                                   // 0x0044 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            AttachedActorID;                               // 0x0048 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventSetSonarInfo");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventSpawnPickup
// 0x0000 (0x003D - 0x003D)
class USphinxSequenceEventSpawnPickup : public USphinxSequenceEventBase
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventSpawnPickup");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventSwitchCollisionBetweenPhATAndCylider
// 0x000B (0x003D - 0x0048)
class USphinxSequenceEventSwitchCollisionBetweenPhATAndCylider : public USphinxSequenceEventBase
{
public:
	int32_t                                            Dummy;                                         // 0x0040 (0x0004) [0x0000000000000000]               
	uint32_t                                           SwitchToCyliderCollision : 1;                  // 0x0044 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           SwitchToPhATCollision : 1;                     // 0x0044 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventSwitchCollisionBetweenPhATAndCylider");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventTeleport
// 0x001B (0x003D - 0x0058)
class USphinxSequenceEventTeleport : public USphinxSequenceEventBase
{
public:
	int32_t                                            TeleRadius;                                    // 0x0040 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            TeleAngle;                                     // 0x0044 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            CandidatePositionNumber;                       // 0x0048 (0x0004) [0x0000000000000000]               
	struct FVector                                     TeleportLocation;                              // 0x004C (0x000C) [0x0000000000000000]               

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventTeleport");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventToggleAttachedActor
// 0x000F (0x003D - 0x004C)
class USphinxSequenceEventToggleAttachedActor : public USphinxSequenceEventBase
{
public:
	uint32_t                                           bActive : 1;                                   // 0x0040 (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)
	int32_t                                            ActorID;                                       // 0x0044 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            HP;                                            // 0x0048 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventToggleAttachedActor");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventToggleAttachedActorHidden
// 0x000B (0x003D - 0x0048)
class USphinxSequenceEventToggleAttachedActorHidden : public USphinxSequenceEventBase
{
public:
	uint32_t                                           bHidden : 1;                                   // 0x0040 (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)
	int32_t                                            ActorID;                                       // 0x0044 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventToggleAttachedActorHidden");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventToggleBlockingCheckWithAlice
// 0x0007 (0x003D - 0x0044)
class USphinxSequenceEventToggleBlockingCheckWithAlice : public USphinxSequenceEventBase
{
public:
	uint32_t                                           bSkipBlockCheck : 1;                           // 0x0040 (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)
	uint32_t                                           bSkipBlockCheckWithNPC : 1;                    // 0x0040 (0x0004) [0x0000000000000003] [0x00000002] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventToggleBlockingCheckWithAlice");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventToggleBlockingCheckWithDesiredBlockingVolumn
// 0x0007 (0x003D - 0x0044)
class USphinxSequenceEventToggleBlockingCheckWithDesiredBlockingVolumn : public USphinxSequenceEventBase
{
public:
	uint32_t                                           bSkipBlockCheck : 1;                           // 0x0040 (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventToggleBlockingCheckWithDesiredBlockingVolumn");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventToggleCriticalUI
// 0x000B (0x003D - 0x0048)
class USphinxSequenceEventToggleCriticalUI : public USphinxSequenceEventBase
{
public:
	uint32_t                                           Actived : 1;                                   // 0x0040 (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)
	int32_t                                            TargetSocketIndex;                             // 0x0044 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventToggleCriticalUI");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventToggleLoopParticle
// 0x000B (0x003D - 0x0048)
class USphinxSequenceEventToggleLoopParticle : public USphinxSequenceEventBase
{
public:
	uint32_t                                           bEnable : 1;                                   // 0x0040 (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)
	int32_t                                            ParticleID;                                    // 0x0044 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventToggleLoopParticle");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventToggleLoopSound
// 0x000F (0x003D - 0x004C)
class USphinxSequenceEventToggleLoopSound : public USphinxSequenceEventBase
{
public:
	uint32_t                                           bEnable : 1;                                   // 0x0040 (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)
	int32_t                                            SoundID;                                       // 0x0044 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              FadeTime;                                      // 0x0048 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventToggleLoopSound");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventToggleMessageEvent
// 0x0007 (0x003D - 0x0044)
class USphinxSequenceEventToggleMessageEvent : public USphinxSequenceEventBase
{
public:
	uint32_t                                           bAcceptStrikeBack : 1;                         // 0x0040 (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)
	uint32_t                                           bAcceptShieldReact : 1;                        // 0x0040 (0x0004) [0x0000000000000003] [0x00000002] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventToggleMessageEvent");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventToggleNPCGodMode
// 0x0007 (0x003D - 0x0044)
class USphinxSequenceEventToggleNPCGodMode : public USphinxSequenceEventBase
{
public:
	uint32_t                                           Actived : 1;                                   // 0x0040 (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventToggleNPCGodMode");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventToggleSkeletalControl
// 0x000F (0x003D - 0x004C)
class USphinxSequenceEventToggleSkeletalControl : public USphinxSequenceEventBase
{
public:
	class FName                                        ControlName;                                   // 0x0040 (0x0008) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           Active : 1;                                    // 0x0048 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventToggleSkeletalControl");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventToggleSubConditionActive
// 0x0017 (0x003D - 0x0054)
class USphinxSequenceEventToggleSubConditionActive : public USphinxSequenceEventBase
{
public:
	int32_t                                            ConditionIndex;                                // 0x0040 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           NearGroupSubConditionCheckActive : 1;          // 0x0044 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           FarGroupSubConditionCheckActive : 1;           // 0x0044 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	class TArray<uint8_t>                              DetailToggle;                                  // 0x0048 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventToggleSubConditionActive");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventUnattachComponent
// 0x000F (0x003D - 0x004C)
class USphinxSequenceEventUnattachComponent : public USphinxSequenceEventBase
{
public:
	class TArray<int32_t>                              ComponentArrayIndex;                           // 0x0040 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventUnattachComponent");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxSequenceEventWaitTime
// 0x0007 (0x003D - 0x0044)
class USphinxSequenceEventWaitTime : public USphinxSequenceEventBase
{
public:
	float                                              WaitTime;                                      // 0x0040 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxSequenceEventWaitTime");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxTeamContainer
// 0x0009 (0x0228 - 0x0231)
class ASphinxTeamContainer : public AActor
{
public:
	class FName                                        TeamName;                                      // 0x0228 (0x0008) [0x0000000000000001] (CPF_Edit)    
	ESphinxTeamContainerType                           TeamType;                                      // 0x0230 (0x0001) [0x0000000000000001] (CPF_Edit)    

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxTeamContainer");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxWanderVolume
// 0x0000 (0x0264 - 0x0264)
class ASphinxWanderVolume : public AVolume
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxWanderVolume");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdModifierCanGo
// 0x000C (0x003C - 0x0048)
class UKynapseFpdModifierCanGo : public UObject
{
public:
	class FString                                      ClassName;                                     // 0x003C (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdModifierCanGo");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdModifierCanGo_AiMesh
// 0x0018 (0x0048 - 0x0060)
class UKynapseFpdModifierCanGo_AiMesh : public UKynapseFpdModifierCanGo
{
public:
	class TArray<class UKynapseAiMeshLayerDefinition*> Layers;                                        // 0x0048 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	class TArray<class UKynapseAiMeshLayerDefinition*> PathObjectLayers;                              // 0x0054 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdModifierCanGo_AiMesh");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdModifierCanGo_RayCast
// 0x0000 (0x0048 - 0x0048)
class UKynapseFpdModifierCanGo_RayCast : public UKynapseFpdModifierCanGo
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdModifierCanGo_RayCast");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdModifierComputeTargetPoint
// 0x000C (0x003C - 0x0048)
class UKynapseFpdModifierComputeTargetPoint : public UObject
{
public:
	class FString                                      ClassName;                                     // 0x003C (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdModifierComputeTargetPoint");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdModifierComputeTargetPoint_Queue
// 0x0004 (0x0048 - 0x004C)
class UKynapseFpdModifierComputeTargetPoint_Queue : public UKynapseFpdModifierComputeTargetPoint
{
public:
	float                                              MaxDist;                                       // 0x0048 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdModifierComputeTargetPoint_Queue");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdModifierComputeTargetPoint_ShortCut
// 0x0008 (0x0048 - 0x0050)
class UKynapseFpdModifierComputeTargetPoint_ShortCut : public UKynapseFpdModifierComputeTargetPoint
{
public:
	float                                              SamplingStep;                                  // 0x0048 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              UpdatePeriod;                                  // 0x004C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdModifierComputeTargetPoint_ShortCut");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdModifierComputeTargetPoint_Trivial
// 0x0000 (0x0048 - 0x0048)
class UKynapseFpdModifierComputeTargetPoint_Trivial : public UKynapseFpdModifierComputeTargetPoint
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdModifierComputeTargetPoint_Trivial");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdModifierDetectAccident
// 0x000C (0x003C - 0x0048)
class UKynapseFpdModifierDetectAccident : public UObject
{
public:
	class FString                                      ClassName;                                     // 0x003C (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdModifierDetectAccident");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdModifierDetectAccident_PredictMove
// 0x0004 (0x0048 - 0x004C)
class UKynapseFpdModifierDetectAccident_PredictMove : public UKynapseFpdModifierDetectAccident
{
public:
	float                                              AccidentRatio;                                 // 0x0048 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdModifierDetectAccident_PredictMove");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdModifierDetectGoalChanged
// 0x000C (0x003C - 0x0048)
class UKynapseFpdModifierDetectGoalChanged : public UObject
{
public:
	class FString                                      ClassName;                                     // 0x003C (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdModifierDetectGoalChanged");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdModifierDetectGoalChanged_Distance3D
// 0x0004 (0x0048 - 0x004C)
class UKynapseFpdModifierDetectGoalChanged_Distance3D : public UKynapseFpdModifierDetectGoalChanged
{
public:
	float                                              MaxDist;                                       // 0x0048 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdModifierDetectGoalChanged_Distance3D");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdModifierDetectGoalReached
// 0x000C (0x003C - 0x0048)
class UKynapseFpdModifierDetectGoalReached : public UObject
{
public:
	class FString                                      ClassName;                                     // 0x003C (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdModifierDetectGoalReached");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdModifierDetectGoalReached_Distance2D5
// 0x0008 (0x0048 - 0x0050)
class UKynapseFpdModifierDetectGoalReached_Distance2D5 : public UKynapseFpdModifierDetectGoalReached
{
public:
	float                                              MaxDeltaHeight;                                // 0x0048 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              EntityRadius;                                  // 0x004C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdModifierDetectGoalReached_Distance2D5");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdModifierDetectGoalReached_Distance3D
// 0x0004 (0x0048 - 0x004C)
class UKynapseFpdModifierDetectGoalReached_Distance3D : public UKynapseFpdModifierDetectGoalReached
{
public:
	float                                              EntityRadius;                                  // 0x0048 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdModifierDetectGoalReached_Distance3D");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdModifierDetectPathNodeReached
// 0x000C (0x003C - 0x0048)
class UKynapseFpdModifierDetectPathNodeReached : public UObject
{
public:
	class FString                                      ClassName;                                     // 0x003C (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdModifierDetectPathNodeReached");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdModifierDetectPathNodeReached_Distance2D5
// 0x0008 (0x0048 - 0x0050)
class UKynapseFpdModifierDetectPathNodeReached_Distance2D5 : public UKynapseFpdModifierDetectPathNodeReached
{
public:
	float                                              MaxDist;                                       // 0x0048 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              MaxDeltaHeight;                                // 0x004C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdModifierDetectPathNodeReached_Distance2D5");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdModifierDetectPathNodeReached_Distance3D
// 0x0004 (0x0048 - 0x004C)
class UKynapseFpdModifierDetectPathNodeReached_Distance3D : public UKynapseFpdModifierDetectPathNodeReached
{
public:
	float                                              MaxDist;                                       // 0x0048 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdModifierDetectPathNodeReached_Distance3D");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdModifierFindNodesFromPositions
// 0x000C (0x003C - 0x0048)
class UKynapseFpdModifierFindNodesFromPositions : public UObject
{
public:
	class FString                                      ClassName;                                     // 0x003C (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdModifierFindNodesFromPositions");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdModifierFindNodesFromPositions_NearestReachable
// 0x0000 (0x0048 - 0x0048)
class UKynapseFpdModifierFindNodesFromPositions_NearestReachable : public UKynapseFpdModifierFindNodesFromPositions
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdModifierFindNodesFromPositions_NearestReachable");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdModifierFindNodesFromPositions_AsyncNearestReachable
// 0x0000 (0x0048 - 0x0048)
class UKynapseFpdModifierFindNodesFromPositions_AsyncNearestReachable : public UKynapseFpdModifierFindNodesFromPositions_NearestReachable
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdModifierFindNodesFromPositions_AsyncNearestReachable");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdModifierGoto
// 0x000C (0x003C - 0x0048)
class UKynapseFpdModifierGoto : public UObject
{
public:
	class FString                                      ClassName;                                     // 0x003C (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdModifierGoto");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdModifierGoto_GapDynamicAvoidance
// 0x0038 (0x0048 - 0x0080)
class UKynapseFpdModifierGoto_GapDynamicAvoidance : public UKynapseFpdModifierGoto
{
public:
	struct FFpdGoto_GapDynamicAvoidance_MainSettings   mainSettings;                                  // 0x0048 (0x0038) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdModifierGoto_GapDynamicAvoidance");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdModifierGoto_AsyncGapDynamicAvoidance
// 0x0000 (0x0080 - 0x0080)
class UKynapseFpdModifierGoto_AsyncGapDynamicAvoidance : public UKynapseFpdModifierGoto_GapDynamicAvoidance
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdModifierGoto_AsyncGapDynamicAvoidance");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdModifierGoto_Repulsor
// 0x0018 (0x0048 - 0x0060)
class UKynapseFpdModifierGoto_Repulsor : public UKynapseFpdModifierGoto
{
public:
	struct FFpdGoto_Repulsor_AdvancedSettings          Advanced;                                      // 0x0048 (0x0018) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdModifierGoto_Repulsor");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdModifierGoto_Trivial
// 0x0000 (0x0048 - 0x0048)
class UKynapseFpdModifierGoto_Trivial : public UKynapseFpdModifierGoto
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdModifierGoto_Trivial");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdModifierLpfShortcut
// 0x000C (0x003C - 0x0048)
class UKynapseFpdModifierLpfShortcut : public UObject
{
public:
	class FString                                      ClassName;                                     // 0x003C (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdModifierLpfShortcut");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdModifierLpfShortcut_SimpleJump
// 0x0004 (0x0048 - 0x004C)
class UKynapseFpdModifierLpfShortcut_SimpleJump : public UKynapseFpdModifierLpfShortcut
{
public:
	float                                              DistanceMax;                                   // 0x0048 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdModifierLpfShortcut_SimpleJump");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdModifierRefineGoal
// 0x000C (0x003C - 0x0048)
class UKynapseFpdModifierRefineGoal : public UObject
{
public:
	class FString                                      ClassName;                                     // 0x003C (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdModifierRefineGoal");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdModifierRefineGoal_NearestInsideAiMesh
// 0x0000 (0x0048 - 0x0048)
class UKynapseFpdModifierRefineGoal_NearestInsideAiMesh : public UKynapseFpdModifierRefineGoal
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdModifierRefineGoal_NearestInsideAiMesh");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdModifierRefineGoal_Trivial
// 0x0000 (0x0048 - 0x0048)
class UKynapseFpdModifierRefineGoal_Trivial : public UKynapseFpdModifierRefineGoal
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdModifierRefineGoal_Trivial");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxModifierRefineGoal_NearestInsideAiMesh_Fly
// 0x0000 (0x0048 - 0x0048)
class USphinxModifierRefineGoal_NearestInsideAiMesh_Fly : public UKynapseFpdModifierRefineGoal
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxModifierRefineGoal_NearestInsideAiMesh_Fly");
		}

		return uClassPointer;
	};

};
// Class Kynapse.SphinxModifierRefineGoal_NearestInsideAiMesh_Walk
// 0x0000 (0x0048 - 0x0048)
class USphinxModifierRefineGoal_NearestInsideAiMesh_Walk : public UKynapseFpdModifierRefineGoal
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.SphinxModifierRefineGoal_NearestInsideAiMesh_Walk");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdModifierSelectPathNodeCandidate
// 0x000C (0x003C - 0x0048)
class UKynapseFpdModifierSelectPathNodeCandidate : public UObject
{
public:
	class FString                                      ClassName;                                     // 0x003C (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdModifierSelectPathNodeCandidate");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdModifierSelectPathNodeCandidate_NextPathNode
// 0x0008 (0x0048 - 0x0050)
class UKynapseFpdModifierSelectPathNodeCandidate_NextPathNode : public UKynapseFpdModifierSelectPathNodeCandidate
{
public:
	int32_t                                            MaxCandidatePerFrame;                          // 0x0048 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              MaxDistPathNode;                               // 0x004C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdModifierSelectPathNodeCandidate_NextPathNode");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdModifierSelectPathNodeCandidate_AsyncNextPathNode
// 0x0000 (0x0050 - 0x0050)
class UKynapseFpdModifierSelectPathNodeCandidate_AsyncNextPathNode : public UKynapseFpdModifierSelectPathNodeCandidate_NextPathNode
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdModifierSelectPathNodeCandidate_AsyncNextPathNode");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdModifierSteering
// 0x000C (0x003C - 0x0048)
class UKynapseFpdModifierSteering : public UObject
{
public:
	class FString                                      ClassName;                                     // 0x003C (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdModifierSteering");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdModifierSteering_Fly
// 0x0000 (0x0048 - 0x0048)
class UKynapseFpdModifierSteering_Fly : public UKynapseFpdModifierSteering
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdModifierSteering_Fly");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdModifierSteering_SimpleBiped
// 0x0000 (0x0048 - 0x0048)
class UKynapseFpdModifierSteering_SimpleBiped : public UKynapseFpdModifierSteering
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdModifierSteering_SimpleBiped");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapsePathdataGenerationModifier
// 0x0000 (0x003C - 0x003C)
class UKynapsePathdataGenerationModifier : public UObject
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapsePathdataGenerationModifier");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapsePathdataGenerationModifier_Doors
// 0x0004 (0x003C - 0x0040)
class UKynapsePathdataGenerationModifier_Doors : public UKynapsePathdataGenerationModifier
{
public:
	class UKynapseEntityDefinitionStaticPathObject*    DoorEntityDef;                                 // 0x003C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapsePathdataGenerationModifier_Doors");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapsePathdataGenerationModifier_Jumps
// 0x0004 (0x003C - 0x0040)
class UKynapsePathdataGenerationModifier_Jumps : public UKynapsePathdataGenerationModifier
{
public:
	class UKynapseEntityDefinitionStaticPathObject*    jumpEntityDef;                                 // 0x003C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapsePathdataGenerationModifier_Jumps");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapsePathdataGenerationModifier_Ladders
// 0x0004 (0x003C - 0x0040)
class UKynapsePathdataGenerationModifier_Ladders : public UKynapsePathdataGenerationModifier
{
public:
	class UKynapseEntityDefinitionStaticPathObject*    ladderEntityDef;                               // 0x003C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapsePathdataGenerationModifier_Ladders");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapsePathdataGenerationModifier_Lifts
// 0x0004 (0x003C - 0x0040)
class UKynapsePathdataGenerationModifier_Lifts : public UKynapsePathdataGenerationModifier
{
public:
	class UKynapseEntityDefinitionStaticPathObject*    liftEntityDef;                                 // 0x003C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapsePathdataGenerationModifier_Lifts");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapsePathdataGenerationModifier_SeedPoint
// 0x0000 (0x003C - 0x003C)
class UKynapsePathdataGenerationModifier_SeedPoint : public UKynapsePathdataGenerationModifier
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapsePathdataGenerationModifier_SeedPoint");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapsePathdataGenerationModifier_Teleport
// 0x0004 (0x003C - 0x0040)
class UKynapsePathdataGenerationModifier_Teleport : public UKynapsePathdataGenerationModifier
{
public:
	class UKynapseEntityDefinitionStaticPathObject*    TeleportEntityDef;                             // 0x003C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapsePathdataGenerationModifier_Teleport");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseAsyncModule
// 0x0018 (0x003C - 0x0054)
class UKynapseAsyncModule : public UObject
{
public:
	class FString                                      AsyncModuleName;                               // 0x003C (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	class FString                                      ClassName;                                     // 0x0048 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseAsyncModule");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseAsyncModuleCanGo_PS3
// 0x0004 (0x0054 - 0x0058)
class UKynapseAsyncModuleCanGo_PS3 : public UKynapseAsyncModule
{
public:
	int32_t                                            TaskCount;                                     // 0x0054 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseAsyncModuleCanGo_PS3");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseAsyncModuleFindNodes
// 0x0000 (0x0054 - 0x0054)
class UKynapseAsyncModuleFindNodes : public UKynapseAsyncModule
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseAsyncModuleFindNodes");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseAsyncModuleFindNodes_PS3
// 0x0008 (0x0054 - 0x005C)
class UKynapseAsyncModuleFindNodes_PS3 : public UKynapseAsyncModuleFindNodes
{
public:
	int32_t                                            TaskCount;                                     // 0x0054 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            MaxNodesPerRequest;                            // 0x0058 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseAsyncModuleFindNodes_PS3");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseAsyncModuleFindNodes_ST
// 0x0004 (0x0054 - 0x0058)
class UKynapseAsyncModuleFindNodes_ST : public UKynapseAsyncModuleFindNodes
{
public:
	int32_t                                            MaxSimultaneousRequests;                       // 0x0054 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseAsyncModuleFindNodes_ST");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseAsyncModuleGapDA
// 0x0000 (0x0054 - 0x0054)
class UKynapseAsyncModuleGapDA : public UKynapseAsyncModule
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseAsyncModuleGapDA");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseAsyncModuleGapDA_PS3
// 0x000C (0x0054 - 0x0060)
class UKynapseAsyncModuleGapDA_PS3 : public UKynapseAsyncModuleGapDA
{
public:
	int32_t                                            TaskCount;                                     // 0x0054 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            CanGoResultQueueDepth;                         // 0x0058 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            MaxPassivePerRequest;                          // 0x005C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseAsyncModuleGapDA_PS3");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseAsyncModuleGapDA_ST
// 0x0004 (0x0054 - 0x0058)
class UKynapseAsyncModuleGapDA_ST : public UKynapseAsyncModuleGapDA
{
public:
	int32_t                                            MaxSimultaneousRequests;                       // 0x0054 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseAsyncModuleGapDA_ST");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseAsyncModuleLpfManager
// 0x0000 (0x0054 - 0x0054)
class UKynapseAsyncModuleLpfManager : public UKynapseAsyncModule
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseAsyncModuleLpfManager");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseAsyncModuleSelectPathNode
// 0x0004 (0x0054 - 0x0058)
class UKynapseAsyncModuleSelectPathNode : public UKynapseAsyncModule
{
public:
	int32_t                                            MaxSimultaneousRequests;                       // 0x0054 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseAsyncModuleSelectPathNode");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseAsyncModuleSelectPathNode_PS3
// 0x0004 (0x0058 - 0x005C)
class UKynapseAsyncModuleSelectPathNode_PS3 : public UKynapseAsyncModuleSelectPathNode
{
public:
	int32_t                                            TaskCount;                                     // 0x0058 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseAsyncModuleSelectPathNode_PS3");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseAsyncModuleSelectPathNode_ST
// 0x0000 (0x0058 - 0x0058)
class UKynapseAsyncModuleSelectPathNode_ST : public UKynapseAsyncModuleSelectPathNode
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseAsyncModuleSelectPathNode_ST");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseWorldServiceAsyncManager
// 0x000C (0x006C - 0x0078)
class UKynapseWorldServiceAsyncManager : public UKynapseWorldService
{
public:
	class TArray<class UKynapseAsyncModule*>           AsyncModulesList;                              // 0x006C (0x000C) [0x0000000004400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink | CPF_EditInline)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseWorldServiceAsyncManager");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseWorldServiceAsyncManager_PS3
// 0x0024 (0x0078 - 0x009C)
class UKynapseWorldServiceAsyncManager_PS3 : public UKynapseWorldServiceAsyncManager
{
public:
	int32_t                                            TaskSetContention;                             // 0x0078 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            TaskSetPriorities[8];                          // 0x007C (0x0020) [0x0000000000000003] (CPF_Edit | CPF_Const)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseWorldServiceAsyncManager_PS3");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseWorldServiceAsyncManager_Win32
// 0x0000 (0x0078 - 0x0078)
class UKynapseWorldServiceAsyncManager_Win32 : public UKynapseWorldServiceAsyncManager
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseWorldServiceAsyncManager_Win32");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseWorldServiceAsyncManager_XBox360
// 0x0000 (0x0078 - 0x0078)
class UKynapseWorldServiceAsyncManager_XBox360 : public UKynapseWorldServiceAsyncManager
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseWorldServiceAsyncManager_XBox360");
		}

		return uClassPointer;
	};

};
// Class Kynapse.ActorFactoryKynapseFracturedStaticMesh
// 0x0000 (0x006C - 0x006C)
class UActorFactoryKynapseFracturedStaticMesh : public UActorFactoryFracturedStaticMesh
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.ActorFactoryKynapseFracturedStaticMesh");
		}

		return uClassPointer;
	};

};
// Class Kynapse.ActorFactoryKynapseKAsset
// 0x0000 (0x0080 - 0x0080)
class UActorFactoryKynapseKAsset : public UActorFactoryPhysicsAsset
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.ActorFactoryKynapseKAsset");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseKAsset
// 0x0004 (0x0238 - 0x023C)
class AKynapseKAsset : public AKAsset
{
public:
	class UKynapseHandle*                              KynapseHandle;                                 // 0x0238 (0x0004) [0x000000000408000B] (CPF_Edit | CPF_Const | CPF_ExportObject | CPF_Component | CPF_EditInline)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseKAsset");
		}

		return uClassPointer;
	};

};
// Class Kynapse.ActorFactoryKynapseObstacleBig
// 0x0000 (0x0098 - 0x0098)
class UActorFactoryKynapseObstacleBig : public UActorFactoryRigidBody
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.ActorFactoryKynapseObstacleBig");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseObstacleBig
// 0x0004 (0x031C - 0x0320)
class AKynapseObstacleBig : public AKActorSpawnable
{
public:
	class UKynapseHandle*                              KynapseHandle;                                 // 0x031C (0x0004) [0x000000000408000B] (CPF_Edit | CPF_Const | CPF_ExportObject | CPF_Component | CPF_EditInline)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseObstacleBig");
		}

		return uClassPointer;
	};

};
// Class Kynapse.ActorFactoryKynapseObstacleFractured
// 0x0000 (0x006C - 0x006C)
class UActorFactoryKynapseObstacleFractured : public UActorFactoryFracturedStaticMesh
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.ActorFactoryKynapseObstacleFractured");
		}

		return uClassPointer;
	};

};
// Class Kynapse.ActorFactoryKynapseObstacleLpf
// 0x0000 (0x0098 - 0x0098)
class UActorFactoryKynapseObstacleLpf : public UActorFactoryRigidBody
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.ActorFactoryKynapseObstacleLpf");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseObstacleLpf
// 0x0004 (0x031C - 0x0320)
class AKynapseObstacleLpf : public AKActorSpawnable
{
public:
	class UKynapseHandle*                              KynapseHandle;                                 // 0x031C (0x0004) [0x000000000408000B] (CPF_Edit | CPF_Const | CPF_ExportObject | CPF_Component | CPF_EditInline)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseObstacleLpf");
		}

		return uClassPointer;
	};

};
// Class Kynapse.ActorFactoryKynapseObstacleSmall
// 0x0000 (0x0098 - 0x0098)
class UActorFactoryKynapseObstacleSmall : public UActorFactoryRigidBody
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.ActorFactoryKynapseObstacleSmall");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseObstacleSmall
// 0x0004 (0x031C - 0x0320)
class AKynapseObstacleSmall : public AKActorSpawnable
{
public:
	class UKynapseHandle*                              KynapseHandle;                                 // 0x031C (0x0004) [0x000000000408000B] (CPF_Edit | CPF_Const | CPF_ExportObject | CPF_Component | CPF_EditInline)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseObstacleSmall");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFpdBrainUnreal
// 0x0000 (0x00A4 - 0x00A4)
class UKynapseFpdBrainUnreal : public UKynapseBrain
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFpdBrainUnreal");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFlyPawn
// 0x0000 (0x05E4 - 0x05E4)
class AKynapseFlyPawn : public AKynapsePawn
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFlyPawn");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseFracturedLayerDefinition
// 0x0000 (0x0070 - 0x0070)
class UKynapseFracturedLayerDefinition : public UKynapseObstacleLayerDefinition
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseFracturedLayerDefinition");
		}

		return uClassPointer;
	};

};
// Class Kynapse.KynapseSeedPoint
// 0x0000 (0x0228 - 0x0228)
class AKynapseSeedPoint : public AActor
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Kynapse.KynapseSeedPoint");
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
