/*
#############################################################################################
# Alice2 (ASDK) SDK 1.0.0.0
# Generated with the CodeRedGenerator v1.2.0
# ========================================================================================= #
# File: Kynapse_structs.hpp
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

// ScriptStruct Kynapse.FpdBuilder.FpdBuilderGraphParams
// 0x0040
struct FFpdBuilderGraphParams
{
	class FString                                      Name;                                          // 0x0000 (0x000C) [0x0000000000500003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	class FString                                      GraphPath;                                     // 0x000C (0x000C) [0x0000000000500003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	int32_t                                            NbVertices;                                    // 0x0018 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            NbEdges;                                       // 0x001C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            GraphFileSize;                                 // 0x0020 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	struct FBox                                        BoundingBox;                                   // 0x0024 (0x001C) [0x0000000000000003] (CPF_Edit | CPF_Const)
};

// ScriptStruct Kynapse.FpdBuilder.FpdBuilderGraphParamsList
// 0x0010
struct FFpdBuilderGraphParamsList
{
	class TArray<struct FFpdBuilderGraphParams>        Graphs;                                        // 0x0000 (0x000C) [0x0000000000500000] (CPF_NeedCtorLink)
	int32_t                                            alternateId;                                   // 0x000C (0x0004) [0x0000000000000002] (CPF_Const)   
};

// ScriptStruct Kynapse.FpdBuilder.FpdBuilderParams
// 0x0044
struct FFpdBuilderParams
{
	uint8_t                                            ProjectType;                                   // 0x0000 (0x0001) [0x0000000000000002] (CPF_Const)   
	uint8_t                                            UnknownData00[0x3];                              // 0x0001 (0x0003) MISSED OFFSET
	int32_t                                            RuntimeMemory;                                 // 0x0004 (0x0004) [0x0000000000000002] (CPF_Const)   
	class FString                                      TargetDirectory;                               // 0x0008 (0x000C) [0x0000000000400002] (CPF_Const | CPF_NeedCtorLink)
	class FString                                      TargetName;                                    // 0x0014 (0x000C) [0x0000000000400002] (CPF_Const | CPF_NeedCtorLink)
	class FString                                      PoDefPath;                                     // 0x0020 (0x000C) [0x0000000000400002] (CPF_Const | CPF_NeedCtorLink)
	class TArray<struct FFpdBuilderGraphParamsList>    GraphsList;                                    // 0x002C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class FString                                      WorkspaceFilename;                             // 0x0038 (0x000C) [0x0000000000400002] (CPF_Const | CPF_NeedCtorLink)
};

// ScriptStruct Kynapse.FpdBuilder.LinkedEdgeStruct
// 0x001C
struct FLinkedEdgeStruct
{
	struct FVector                                     Start;                                         // 0x0000 (0x000C) [0x0000000000000000]               
	struct FVector                                     End;                                           // 0x000C (0x000C) [0x0000000000000000]               
	int32_t                                            Uid;                                           // 0x0018 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Kynapse.FpdBuilder.StaticPathobjectEntry
// 0x0018
struct FStaticPathobjectEntry
{
	int32_t                                            Uid;                                           // 0x0000 (0x0004) [0x0000000000000000]               
	class UKynapseEntityDefinitionStaticPathObject*    PathobjectDefinition;                          // 0x0004 (0x0004) [0x0000000000000000]               
	int32_t                                            POD_Mask;                                      // 0x0008 (0x0004) [0x0000000000000000]               
	class TArray<struct FLinkedEdgeStruct>             SeedEdges;                                     // 0x000C (0x000C) [0x0000000000500000] (CPF_NeedCtorLink)
};

// ScriptStruct Kynapse.FpdBuilder.SectorDefinition
// 0x0044
struct FSectorDefinition
{
	class FString                                      inputGraphPath;                                // 0x0000 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class FString                                      inputAIMeshPath;                               // 0x000C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class FString                                      outputGraphPath;                               // 0x0018 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	struct FBox                                        BoundingBox;                                   // 0x0024 (0x001C) [0x0000000000000000]               
	int32_t                                            Id;                                            // 0x0040 (0x0004) [0x0000000000000000]               
};

// ScriptStruct Kynapse.FpdBuilder.SectorDefinitionList
// 0x0010
struct FSectorDefinitionList
{
	class TArray<struct FSectorDefinition>             sectors;                                       // 0x0000 (0x000C) [0x0000000000500000] (CPF_NeedCtorLink)
	int32_t                                            alternateId;                                   // 0x000C (0x0004) [0x0000000000000002] (CPF_Const)   
};

// ScriptStruct Kynapse.FpdBuilder.PrelinkProcessParams
// 0x000C
struct FPrelinkProcessParams
{
	class TArray<struct FSectorDefinitionList>         sectorsList;                                   // 0x0000 (0x000C) [0x0000000000500000] (CPF_NeedCtorLink)
};

// ScriptStruct Kynapse.KynapseBrainService.BServiceAperiodicTask
// 0x0018
struct FBServiceAperiodicTask
{
	class FString                                      taskName;                                      // 0x0000 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	float                                              Priority;                                      // 0x000C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              tpf;                                           // 0x0010 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            maxCall;                                       // 0x0014 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
};

// ScriptStruct Kynapse.KynapseBrainService.BServicePeriodicTask
// 0x0010
struct FBServicePeriodicTask
{
	class FString                                      taskName;                                      // 0x0000 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	float                                              Period;                                        // 0x000C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
};

// ScriptStruct Kynapse.KynapseFpdModifierGoto_GapDynamicAvoidance.FpdGoto_GapDynamicAvoidance_TechnicalSettings
// 0x0010
struct FFpdGoto_GapDynamicAvoidance_TechnicalSettings
{
	int32_t                                            MaxCollisionTestsPerFrame;                     // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              CandidateSpacing;                              // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              DiagramRefreshPeriod;                          // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              EntityDistMax;                                 // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Kynapse.KynapseFpdModifierGoto_GapDynamicAvoidance.FpdGoto_GapDynamicAvoidance_SecondarySettings
// 0x0028
struct FFpdGoto_GapDynamicAvoidance_SecondarySettings
{
	float                                              QueueingDelay;                                 // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              PushingDelay;                                  // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              StuckDelay;                                    // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              MaxAngularSpeed;                               // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              MinSpeed;                                      // 0x0010 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              ExtraGap;                                      // 0x0014 (0x0004) [0x0000000000000001] (CPF_Edit)    
	struct FFpdGoto_GapDynamicAvoidance_TechnicalSettings technicalSettings;                             // 0x0018 (0x0010) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Kynapse.KynapseFpdModifierGoto_GapDynamicAvoidance.FpdGoto_GapDynamicAvoidance_MainSettings
// 0x0038
struct FFpdGoto_GapDynamicAvoidance_MainSettings
{
	float                                              Courtesy;                                      // 0x0000 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	uint32_t                                           ContinuousSpeed : 1;                           // 0x0004 (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)
	float                                              DiagramHalfWidth;                              // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              DiagramMaxLength;                              // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            MaxCollisionTestsPerFrame;                     // 0x0010 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              CandidateSpacing;                              // 0x0014 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              DiagramRefreshPeriod;                          // 0x0018 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              EntityDistMax;                                 // 0x001C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              QueueingDelay;                                 // 0x0020 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              PushingDelay;                                  // 0x0024 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              StuckDelay;                                    // 0x0028 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              MaxAngularSpeed;                               // 0x002C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              MinSpeed;                                      // 0x0030 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              ExtraGap;                                      // 0x0034 (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Kynapse.KynapseBrainServiceFpdPathfinder.LocalPathFinding_Fpd
// 0x0024
struct FLocalPathFinding_Fpd
{
	class FString                                      context;                                       // 0x0000 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	float                                              Radius;                                        // 0x000C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            pathMaxLength;                                 // 0x0010 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              smoothingPeriod;                               // 0x0014 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              smoothingDistance;                             // 0x0018 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            smoothingMaxNodeSkip;                          // 0x001C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            tabooEdgeMaxCount;                             // 0x0020 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
};

// ScriptStruct Kynapse.KynapseBrainServiceFpdPathfinder.FpdModifiers
// 0x0030
struct FFpdModifiers
{
	class UKynapseFpdModifierRefineGoal*               RefineGoal;                                    // 0x0000 (0x0004) [0x000000000440000B] (CPF_Edit | CPF_Const | CPF_ExportObject | CPF_NeedCtorLink | CPF_EditInline)
	class UKynapseFpdModifierDetectGoalReached*        DetectGoalReached;                             // 0x0004 (0x0004) [0x000000000440000B] (CPF_Edit | CPF_Const | CPF_ExportObject | CPF_NeedCtorLink | CPF_EditInline)
	class UKynapseFpdModifierDetectAccident*           DetectAccident;                                // 0x0008 (0x0004) [0x000000000440000B] (CPF_Edit | CPF_Const | CPF_ExportObject | CPF_NeedCtorLink | CPF_EditInline)
	class UKynapseFpdModifierFindNodesFromPositions*   FindNodesFromPositions;                        // 0x000C (0x0004) [0x000000000440000B] (CPF_Edit | CPF_Const | CPF_ExportObject | CPF_NeedCtorLink | CPF_EditInline)
	class UKynapseFpdModifierCanGo*                    CanGo;                                         // 0x0010 (0x0004) [0x000000000440000B] (CPF_Edit | CPF_Const | CPF_ExportObject | CPF_NeedCtorLink | CPF_EditInline)
	class UKynapseFpdModifierDetectGoalChanged*        DetectGoalChanged;                             // 0x0014 (0x0004) [0x000000000440000B] (CPF_Edit | CPF_Const | CPF_ExportObject | CPF_NeedCtorLink | CPF_EditInline)
	class UKynapseFpdModifierDetectPathNodeReached*    DetectPathNodeReached;                         // 0x0018 (0x0004) [0x000000000440000B] (CPF_Edit | CPF_Const | CPF_ExportObject | CPF_NeedCtorLink | CPF_EditInline)
	class UKynapseFpdModifierSelectPathNodeCandidate*  SelectPathNodeCandidate;                       // 0x001C (0x0004) [0x000000000440000B] (CPF_Edit | CPF_Const | CPF_ExportObject | CPF_NeedCtorLink | CPF_EditInline)
	class UKynapseFpdModifierComputeTargetPoint*       ComputeTargetPoint;                            // 0x0020 (0x0004) [0x000000000440000B] (CPF_Edit | CPF_Const | CPF_ExportObject | CPF_NeedCtorLink | CPF_EditInline)
	class UKynapseFpdModifierGoto*                     Goto;                                          // 0x0024 (0x0004) [0x000000000440000B] (CPF_Edit | CPF_Const | CPF_ExportObject | CPF_NeedCtorLink | CPF_EditInline)
	class UKynapseFpdModifierSteering*                 Steering;                                      // 0x0028 (0x0004) [0x000000000440000B] (CPF_Edit | CPF_Const | CPF_ExportObject | CPF_NeedCtorLink | CPF_EditInline)
	class UKynapseFpdModifierLpfShortcut*              LpfShortcut;                                   // 0x002C (0x0004) [0x000000000440000B] (CPF_Edit | CPF_Const | CPF_ExportObject | CPF_NeedCtorLink | CPF_EditInline)
};

// ScriptStruct Kynapse.KynapseAgent.AgentAperiodicTask
// 0x0018
struct FAgentAperiodicTask
{
	class FString                                      taskName;                                      // 0x0000 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	float                                              Priority;                                      // 0x000C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              tpf;                                           // 0x0010 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            maxCall;                                       // 0x0014 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
};

// ScriptStruct Kynapse.KynapseAgent.AgentPeriodicTask
// 0x0010
struct FAgentPeriodicTask
{
	class FString                                      taskName;                                      // 0x0000 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	float                                              Period;                                        // 0x000C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
};

// ScriptStruct Kynapse.KynapseFpdDatabase.FpdDatabase
// 0x000C
struct FFpdDatabase
{
	class FString                                      DatabaseName;                                  // 0x0000 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
};

// ScriptStruct Kynapse.KynapseFpdModifierGoto_Repulsor.FpdGoto_Repulsor_AdvancedSettings
// 0x0018
struct FFpdGoto_Repulsor_AdvancedSettings
{
	float                                              DynDelayTime;                                  // 0x0000 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              DynRatioAttrRep;                               // 0x0004 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              TimeMinTrigger;                                // 0x0008 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              TimeMaxTrigger;                                // 0x000C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              SlowSpeedFactor;                               // 0x0010 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              VerySlowSpeedFactor;                           // 0x0014 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
};

// ScriptStruct Kynapse.KynapseFpdTraversalDefinition.FpdTraversalAperiodicTask
// 0x0018
struct FFpdTraversalAperiodicTask
{
	class FString                                      taskName;                                      // 0x0000 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	float                                              Priority;                                      // 0x000C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              tpf;                                           // 0x0010 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            maxCall;                                       // 0x0014 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
};

// ScriptStruct Kynapse.KynapseProfileDefinition.EntityInfoUse
// 0x0028
struct FEntityInfoUse
{
	class UKynapseEntityInfoDefinition*                entityInfo;                                    // 0x0000 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	class TArray<class UKynapseProfileDefinition*>     computeWith;                                   // 0x0004 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	class TArray<class UKynapseProfileDefinition*>     searchIn;                                      // 0x0010 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	class TArray<class UKynapseFilter*>                filters;                                       // 0x001C (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
};

// ScriptStruct Kynapse.KynapseStandardPathdataGenerationService.AdditionalDataParams
// 0x0018
struct FAdditionalDataParams
{
	class TArray<class UKynapseAdditionalData*>        VerticesAdditionalData;                        // 0x0000 (0x000C) [0x000000000440000B] (CPF_Edit | CPF_Const | CPF_ExportObject | CPF_NeedCtorLink | CPF_EditInline)
	class TArray<class UKynapseAdditionalData*>        EdgesAdditionalData;                           // 0x000C (0x000C) [0x000000000440000B] (CPF_Edit | CPF_Const | CPF_ExportObject | CPF_NeedCtorLink | CPF_EditInline)
};

// ScriptStruct Kynapse.KynapseTraversalDefinition.TraversalAperiodicTask
// 0x0018
struct FTraversalAperiodicTask
{
	class FString                                      taskName;                                      // 0x0000 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	float                                              Priority;                                      // 0x000C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              tpf;                                           // 0x0010 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            maxCall;                                       // 0x0014 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
};

// ScriptStruct Kynapse.KynapseWorldService.WServiceAperiodicTask
// 0x0018
struct FWServiceAperiodicTask
{
	class FString                                      taskName;                                      // 0x0000 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	float                                              Priority;                                      // 0x000C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              tpf;                                           // 0x0010 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            maxCall;                                       // 0x0014 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
};

// ScriptStruct Kynapse.KynapseWorldService.WServicePeriodicTask
// 0x0010
struct FWServicePeriodicTask
{
	class FString                                      taskName;                                      // 0x0000 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	float                                              Period;                                        // 0x000C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
};

// ScriptStruct Kynapse.KynapseWorldServiceLpfManager.LpfContext
// 0x002D
struct FLpfContext
{
	class FString                                      Name;                                          // 0x0000 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	class TArray<class UKynapseAiMeshLayerDefinition*> Layers;                                        // 0x000C (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	class UKynapseTag*                                 DataTag;                                       // 0x0018 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              edgeRadius;                                    // 0x001C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              minDeltaHeight;                                // 0x0020 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              inhibitionPeriod;                              // 0x0024 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	class UKynapseLpfPreMerger*                        lpfPreMerger;                                  // 0x0028 (0x0004) [0x000000000440000B] (CPF_Edit | CPF_Const | CPF_ExportObject | CPF_NeedCtorLink | CPF_EditInline)
	uint8_t                                            lpf3dMode;                                     // 0x002C (0x0001) [0x0000000000000003] (CPF_Edit | CPF_Const)
	uint8_t                                            MinStructAlignment[0x3];                         // 0x002D (0x0003) ADDED PADDING
};

// ScriptStruct Kynapse.KynapseWorldServiceAIMeshManager.AiMesh
// 0x0010
struct FAiMesh
{
	class FString                                      aiMeshName;                                    // 0x0000 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	class AKynapseWorldServiceMapBuilder*              mapBuilder;                                    // 0x000C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
};

// ScriptStruct Kynapse.KynapseWorldServiceFlyBuilder.FlyBuilderLocalZoneDefinition
// 0x0008
struct FFlyBuilderLocalZoneDefinition
{
	class AVolume*                                     ZoneVolume;                                    // 0x0000 (0x0004) [0x0000000014000003] (CPF_Edit | CPF_Const | CPF_EditInline | CPF_EditInlineUse)
	float                                              LocalPitch;                                    // 0x0004 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
};

// ScriptStruct Kynapse.KynapseWorldServiceFlyBuilder.KynapseWorldServiceFlyBuilderAdvancedParameters
// 0x001C
struct FKynapseWorldServiceFlyBuilderAdvancedParameters
{
	int32_t                                            MaxCollisionTestsPerFrame;                     // 0x0000 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              OverConnectionRatio;                           // 0x0004 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            ComponentSizeMin;                              // 0x0008 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              SimplificationAccuracy;                        // 0x000C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	class TArray<struct FFlyBuilderLocalZoneDefinition> LocalZones;                                    // 0x0010 (0x000C) [0x000000000440000B] (CPF_Edit | CPF_Const | CPF_ExportObject | CPF_NeedCtorLink | CPF_EditInline)
};

// ScriptStruct Kynapse.KynapseWorldServiceGraphManager.additionalData
// 0x000C
struct FadditionalData
{
	class FString                                      ClassName;                                     // 0x0000 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
};

// ScriptStruct Kynapse.KynapseWorldServiceGraphManager.Pathdata
// 0x0020
struct FPathdata
{
	class FString                                      pathdataName;                                  // 0x0000 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	class AKynapseWorldServiceMapBuilder*              mapBuilder;                                    // 0x000C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	uint32_t                                           usesPathObjectManager : 1;                     // 0x0010 (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)
	class TArray<struct FadditionalData>               additionalDataList_Pathdata;                   // 0x0014 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
};

// ScriptStruct Kynapse.KynapseWorldServiceMapBuilder.ProcessParams
// 0x0004
struct FProcessParams
{
	uint8_t                                            FirstStep;                                     // 0x0000 (0x0001) [0x0000000000000003] (CPF_Edit | CPF_Const)
	uint8_t                                            LastStep;                                      // 0x0001 (0x0001) [0x0000000000000003] (CPF_Edit | CPF_Const)
	uint8_t                                            dummy1;                                        // 0x0002 (0x0001) [0x0000000000000000]               
	uint8_t                                            dummy2;                                        // 0x0003 (0x0001) [0x0000000000000000]               
};

// ScriptStruct Kynapse.KynapseWorldServiceMapBuilder.AdvancedParams
// 0x0015
struct FAdvancedParams
{
	int32_t                                            LocalMapSize;                                  // 0x0000 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            MaxMapSize;                                    // 0x0004 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	uint32_t                                           SimulateGroundAroundBoundingBox : 1;           // 0x0008 (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)
	uint32_t                                           ForbidCollidingEdge : 1;                       // 0x0008 (0x0004) [0x0000000000000003] [0x00000002] (CPF_Edit | CPF_Const)
	float                                              OverConnectionRatio;                           // 0x000C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            ComponentSizeMin;                              // 0x0010 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	uint8_t                                            CollisionModel;                                // 0x0014 (0x0001) [0x0000000000000003] (CPF_Edit | CPF_Const)
	uint8_t                                            MinStructAlignment[0x3];                         // 0x0015 (0x0003) ADDED PADDING
};

// ScriptStruct Kynapse.KynapseWorldServiceMapBuilder.HidingDataParams
// 0x0014
struct FHidingDataParams
{
	uint32_t                                           GenerateHidingPoints : 1;                      // 0x0000 (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)
	float                                              MaxDistanceToWall;                             // 0x0004 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            SmallRaycastDelta;                             // 0x0008 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              MinDistanceBetweenVertices;                    // 0x000C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	int32_t                                            MinConeOfVisionSize;                           // 0x0010 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
};

// ScriptStruct Kynapse.KynapseWorldServiceMapBuilder.AccuracyParams
// 0x0014
struct FAccuracyParams
{
	float                                              Pitch;                                         // 0x0000 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              graphAccuracy;                                 // 0x0004 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              nbSectors;                                     // 0x0008 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              edgeRadius;                                    // 0x000C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              MaxDeltaHeight;                                // 0x0010 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
};

// ScriptStruct Kynapse.KynapseWorldServiceMapBuilder.PhysicalParams
// 0x001C
struct FPhysicalParams
{
	float                                              entityHeight;                                  // 0x0000 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              StepLength;                                    // 0x0004 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              stepMax;                                       // 0x0008 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              holeMax;                                       // 0x000C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	uint32_t                                           CheckGroundSlope : 1;                          // 0x0010 (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)
	float                                              groundSlopeMax;                                // 0x0014 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              groundSlopeMin;                                // 0x0018 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
};

// ScriptStruct Kynapse.SphinxAgentFight.SphinxMiscActionInfo
// 0x0010
struct FSphinxMiscActionInfo
{
	class FString                                      MiscEventNameTag;                              // 0x0000 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	int32_t                                            MiscEventIndex;                                // 0x000C (0x0004) [0x0000000000000000]               
};

// ScriptStruct Kynapse.SphinxAgentFight.SphinxMeleeAttackInfo
// 0x0010
struct FSphinxMeleeAttackInfo
{
	class FString                                      MAttackEventNameTag;                           // 0x0000 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	int32_t                                            MAttackEventIndex;                             // 0x000C (0x0004) [0x0000000000000000]               
};

// ScriptStruct Kynapse.SphinxAgentFight.SphinxRangeAttackInfo
// 0x0010
struct FSphinxRangeAttackInfo
{
	class FString                                      RAttackEventNameTag;                           // 0x0000 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	int32_t                                            RAttackEventIndex;                             // 0x000C (0x0004) [0x0000000000000000]               
};

// ScriptStruct Kynapse.SphinxAgentFight.StrikBackConditionData
// 0x0030
struct FStrikBackConditionData
{
	uint8_t                                            WeaponType;                                    // 0x0000 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            UnknownData00[0x3];                              // 0x0001 (0x0003) MISSED OFFSET
	uint32_t                                           bIsShield : 1;                                 // 0x0004 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bUseSpecialAssignShieldIndex : 1;              // 0x0004 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	int32_t                                            SpecialAssignShieldIndex1;                     // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            SpecialAssignShieldIndex2;                     // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bHaveStrikBackAblity : 1;                      // 0x0010 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	int32_t                                            MinComboCountActiveStrikBack;                  // 0x0014 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              ComboInterval;                                 // 0x0018 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	class FString                                      StrikBackEventsNameTag;                        // 0x001C (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	int32_t                                            StrikBackEventsIndex;                          // 0x0028 (0x0004) [0x0000000000000002] (CPF_Const)   
	float                                              ChangeActiveStrikBack;                         // 0x002C (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
};

// ScriptStruct Kynapse.SphinxAgentFight.SphinxMiscActionData
// 0x003C
struct FSphinxMiscActionData
{
	float                                              MiscActionChance;                              // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            MaxTriggerTimes;                               // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            MaxTriggerTimesBackUp;                         // 0x0008 (0x0004) [0x0000000000000000]               
	int32_t                                            MiscEventIndex;                                // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              ParamValue1;                                   // 0x0010 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              ParamValue2;                                   // 0x0014 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	class FString                                      ParamStr1;                                     // 0x0018 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	uint8_t                                            ParmWeaponType;                                // 0x0024 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            UnknownData00[0x3];                              // 0x0025 (0x0003) MISSED OFFSET
	class FName                                        ParamStr1Fname;                                // 0x0028 (0x0008) [0x0000000000000000]               
	uint32_t                                           DoBreakCurrentSubConditionEvent : 1;           // 0x0030 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           DoReturnOriginalPackage : 1;                   // 0x0030 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint8_t                                            ConditionType;                                 // 0x0034 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            UnknownData01[0x3];                              // 0x0035 (0x0003) MISSED OFFSET
	uint32_t                                           bAlwaysCheck : 1;                              // 0x0038 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bActived : 1;                                  // 0x0038 (0x0004) [0x0000000000000000] [0x00000002] 
};

// ScriptStruct Kynapse.SphinxAgentFight.SphinxFightSwitchCondition
// 0x0070
struct FSphinxFightSwitchCondition
{
	uint32_t                                           m_bFaceAliceOnlyInScriptedSphinxSequenceEvent : 1;// 0x0000 (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)
	float                                              m_Speed;                                       // 0x0004 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	struct FRotator                                    m_RotationRate;                                // 0x0008 (0x000C) [0x0000000000000003] (CPF_Edit | CPF_Const)
	float                                              MConditionStateAttackDelay;                    // 0x0014 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	class TArray<float>                                NearGroup_MConditionAttackChance;              // 0x0018 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	uint32_t                                           NearGroup_UseSubConditionAction : 1;           // 0x0024 (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)
	float                                              RConditionStateAttackDelay;                    // 0x0028 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	uint32_t                                           FarGroup_UseDefaultMeleeAttack : 1;            // 0x002C (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)
	int32_t                                            FarGroup_DefaultMeleeAttackIndex;              // 0x0030 (0x0004) [0x0000000000000003] (CPF_Edit | CPF_Const)
	uint32_t                                           FarGroup_SwitchBackToFarGroupAfterMeleeAttackIM : 1;// 0x0034 (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)
	class TArray<float>                                FarGroup_RConditionAttackChance;               // 0x0038 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	uint32_t                                           FarGroup_UseSubConditionAction : 1;            // 0x0044 (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)
	class TArray<struct FStrikBackConditionData>       StrikBackDataArray;                            // 0x0048 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	uint32_t                                           bRestoreMaxTriggerForSubConditions : 1;        // 0x0054 (0x0004) [0x0000000000000003] [0x00000001] (CPF_Edit | CPF_Const)
	class TArray<struct FSphinxMiscActionData>         SubConditionChance;                            // 0x0058 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
	class FString                                      ConditionNameTag;                              // 0x0064 (0x000C) [0x0000000000400003] (CPF_Edit | CPF_Const | CPF_NeedCtorLink)
};

// ScriptStruct Kynapse.SphinxInterstingPoint.AccessNPC
// 0x001C
struct FAccessNPC
{
	class APawn*                                       NPCPawn;                                       // 0x0000 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            AttractChance;                                 // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	float                                              BlockTime;                                     // 0x0008 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class FName                                        Animation;                                     // 0x000C (0x0008) [0x0000000000000001] (CPF_Edit)    
	float                                              LastUsedTime;                                  // 0x0014 (0x0004) [0x0000000000000000]               
	uint32_t                                           bEnable : 1;                                   // 0x0018 (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           bInAttractRadius : 1;                          // 0x0018 (0x0004) [0x0000000000000000] [0x00000002] 
};

// ScriptStruct Kynapse.SphinxSequenceActionConditionJump.ConditionCheckList
// 0x0010
struct FConditionCheckList
{
	uint8_t                                            CheckCondition;                                // 0x0000 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            UnknownData00[0x3];                              // 0x0001 (0x0003) MISSED OFFSET
	int32_t                                            AdditionPassParam;                             // 0x0004 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            ExpressionType;                                // 0x0008 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            UnknownData01[0x3];                              // 0x0009 (0x0003) MISSED OFFSET
	int32_t                                            CheckParam;                                    // 0x000C (0x0004) [0x0000000000000001] (CPF_Edit)    
};

// ScriptStruct Kynapse.SphinxSequenceEventSetGotoLocation.SphinxSquenceGotoInfo
// 0x001C
struct FSphinxSquenceGotoInfo
{
	uint32_t                                           EnableFaceAlice : 1;                           // 0x0000 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	struct FVector                                     GotoLocation;                                  // 0x0004 (0x000C) [0x0000000000000001] (CPF_Edit)    
	struct FRotator                                    GotoRotator;                                   // 0x0010 (0x000C) [0x0000000000000001] (CPF_Edit)    
};

/*
# ========================================================================================= #
#
# ========================================================================================= #
*/

#ifdef _MSC_VER
#pragma pack(pop)
#endif
