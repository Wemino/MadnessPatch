/*
#############################################################################################
# Alice2 (ASDK) SDK 1.0.0.0
# Generated with the CodeRedGenerator v1.2.0
# ========================================================================================= #
# File: GFxUI_parameters.hpp
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

// Function GFxUI.GFxFSCmdHandler.FSCommand
// [0x00020800] 
struct UGFxFSCmdHandler_eventFSCommand_Params
{
	class UGFxMovie*                                   Movie;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class FString                                      Cmd;                                              // 0x0004 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	class FString                                      Arg;                                              // 0x0010 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	bool                                               ReturnValue : 1;                                  // 0x001C (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxGameViewportClient.Init
// [0x00420802] 
struct UGFxGameViewportClient_eventInit_Params
{
	class FString                                      OutError;                                         // 0x0000 (0x000C) [0x0000000000400180] (CPF_Parm | CPF_OutParm | CPF_NeedCtorLink)
	bool                                               ReturnValue : 1;                                  // 0x000C (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
	// int32_t                                         oldlen;                                           // 0x0010 (0x0004) [0x0000000000000000]               
};

// Function GFxUI.GFxInteraction.NotifyGameSessionEnded
// [0x00020400] 
struct UGFxInteraction_execNotifyGameSessionEnded_Params
{
};

// Function GFxUI.GFxInteraction.GetFocusMovie
// [0x00020400] 
struct UGFxInteraction_execGetFocusMovie_Params
{
	class UGFxMovie*                                   ReturnValue;                                      // 0x0000 (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxInteraction.SetFocusMovie
// [0x00020400] 
struct UGFxInteraction_execSetFocusMovie_Params
{
	class FString                                      MovieName;                                        // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	uint32_t                                           captureInput : 1;                                 // 0x000C (0x0004) [0x0000000000000080] [0x00000001] (CPF_Parm)
	uint32_t : 0;                                  // 0x0010 CLOSE BITFIELD STORAGE UNIT
	bool                                               ReturnValue : 1;                                  // 0x0010 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxMovie.ActionScriptSetFunction
// [0x00080401] 
struct UGFxMovie_execActionScriptSetFunction_Params
{
	class UGFxValue*                                   Obj;                                              // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class FString                                      member;                                           // 0x0004 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
};

// Function GFxUI.GFxMovie.ActionScriptObject
// [0x00080401] 
struct UGFxMovie_execActionScriptObject_Params
{
	class FString                                      Path;                                             // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	class UGFxValue*                                   ReturnValue;                                      // 0x000C (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxMovie.ActionScriptString
// [0x00080401] 
struct UGFxMovie_execActionScriptString_Params
{
	class FString                                      Path;                                             // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	class FString                                      ReturnValue;                                      // 0x000C (0x000C) [0x0000000000400580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
};

// Function GFxUI.GFxMovie.ActionScriptFloat
// [0x00080401] 
struct UGFxMovie_execActionScriptFloat_Params
{
	class FString                                      Path;                                             // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	float                                              ReturnValue;                                      // 0x000C (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxMovie.ActionScriptInt
// [0x00080401] 
struct UGFxMovie_execActionScriptInt_Params
{
	class FString                                      Path;                                             // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	int32_t                                            ReturnValue;                                      // 0x000C (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxMovie.ActionScriptVoid
// [0x00080401] 
struct UGFxMovie_execActionScriptVoid_Params
{
	class FString                                      Path;                                             // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
};

// Function GFxUI.GFxMovie.UserTick
// [0x00020800] 
struct UGFxMovie_eventUserTick_Params
{
};

// Function GFxUI.GFxMovie.SetExternalInterface
// [0x00020002] 
struct UGFxMovie_execSetExternalInterface_Params
{
	class UObject*                                     H;                                                // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GFxUI.GFxMovie.SetFsCmdHandler
// [0x00020002] 
struct UGFxMovie_execSetFsCmdHandler_Params
{
	class UGFxFSCmdHandler*                            H;                                                // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GFxUI.GFxMovie.SetVariableObject
// [0x00020400] 
struct UGFxMovie_execSetVariableObject_Params
{
	class FString                                      Path;                                             // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	class UGFxValue*                                   Value;                                            // 0x000C (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GFxUI.GFxMovie.GetVariableObject
// [0x00024400] 
struct UGFxMovie_execGetVariableObject_Params
{
	class FString                                      Path;                                             // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	class UClass*                                      Type;                                             // 0x000C (0x0004) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
	class UGFxValue*                                   ReturnValue;                                      // 0x0010 (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxMovie.CreateArray
// [0x00020400] 
struct UGFxMovie_execCreateArray_Params
{
	class UGFxValue*                                   ReturnValue;                                      // 0x0000 (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxMovie.CreateObject
// [0x00024400] 
struct UGFxMovie_execCreateObject_Params
{
	class FString                                      ASClass;                                          // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	class UClass*                                      Type;                                             // 0x000C (0x0004) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
	class UGFxValue*                                   ReturnValue;                                      // 0x0010 (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxMovie.SetVariableStringArray
// [0x00020400] 
struct UGFxMovie_execSetVariableStringArray_Params
{
	class FString                                      Path;                                             // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	int32_t                                            Index;                                            // 0x000C (0x0004) [0x0000000000000080] (CPF_Parm)    
	class TArray<class FString>                        Arg;                                              // 0x0010 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	bool                                               ReturnValue : 1;                                  // 0x001C (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxMovie.SetVariableFloatArray
// [0x00020400] 
struct UGFxMovie_execSetVariableFloatArray_Params
{
	class FString                                      Path;                                             // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	int32_t                                            Index;                                            // 0x000C (0x0004) [0x0000000000000080] (CPF_Parm)    
	class TArray<float>                                Arg;                                              // 0x0010 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	bool                                               ReturnValue : 1;                                  // 0x001C (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxMovie.SetVariableIntArray
// [0x00020400] 
struct UGFxMovie_execSetVariableIntArray_Params
{
	class FString                                      Path;                                             // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	int32_t                                            Index;                                            // 0x000C (0x0004) [0x0000000000000080] (CPF_Parm)    
	class TArray<int32_t>                              Arg;                                              // 0x0010 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	bool                                               ReturnValue : 1;                                  // 0x001C (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxMovie.SetVariableArray
// [0x00020400] 
struct UGFxMovie_execSetVariableArray_Params
{
	class FString                                      Path;                                             // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	int32_t                                            Index;                                            // 0x000C (0x0004) [0x0000000000000080] (CPF_Parm)    
	class TArray<struct FASValue>                      Arg;                                              // 0x0010 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	bool                                               ReturnValue : 1;                                  // 0x001C (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxMovie.GetVariableStringArray
// [0x00420400] 
struct UGFxMovie_execGetVariableStringArray_Params
{
	class FString                                      Path;                                             // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	int32_t                                            Index;                                            // 0x000C (0x0004) [0x0000000000000080] (CPF_Parm)    
	class TArray<class FString>                        Arg;                                              // 0x0010 (0x000C) [0x0000000000400180] (CPF_Parm | CPF_OutParm | CPF_NeedCtorLink)
	bool                                               ReturnValue : 1;                                  // 0x001C (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxMovie.GetVariableFloatArray
// [0x00420400] 
struct UGFxMovie_execGetVariableFloatArray_Params
{
	class FString                                      Path;                                             // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	int32_t                                            Index;                                            // 0x000C (0x0004) [0x0000000000000080] (CPF_Parm)    
	class TArray<float>                                Arg;                                              // 0x0010 (0x000C) [0x0000000000400180] (CPF_Parm | CPF_OutParm | CPF_NeedCtorLink)
	bool                                               ReturnValue : 1;                                  // 0x001C (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxMovie.GetVariableIntArray
// [0x00420400] 
struct UGFxMovie_execGetVariableIntArray_Params
{
	class FString                                      Path;                                             // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	int32_t                                            Index;                                            // 0x000C (0x0004) [0x0000000000000080] (CPF_Parm)    
	class TArray<int32_t>                              Arg;                                              // 0x0010 (0x000C) [0x0000000000400180] (CPF_Parm | CPF_OutParm | CPF_NeedCtorLink)
	bool                                               ReturnValue : 1;                                  // 0x001C (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxMovie.GetVariableArray
// [0x00420400] 
struct UGFxMovie_execGetVariableArray_Params
{
	class FString                                      Path;                                             // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	int32_t                                            Index;                                            // 0x000C (0x0004) [0x0000000000000080] (CPF_Parm)    
	class TArray<struct FASValue>                      Arg;                                              // 0x0010 (0x000C) [0x0000000000400180] (CPF_Parm | CPF_OutParm | CPF_NeedCtorLink)
	bool                                               ReturnValue : 1;                                  // 0x001C (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxMovie.SetVariableString
// [0x00020400] 
struct UGFxMovie_execSetVariableString_Params
{
	class FString                                      Path;                                             // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	class FString                                      S;                                                // 0x000C (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
};

// Function GFxUI.GFxMovie.SetVariableNumber
// [0x00020400] 
struct UGFxMovie_execSetVariableNumber_Params
{
	class FString                                      Path;                                             // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	float                                              F;                                                // 0x000C (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GFxUI.GFxMovie.SetVariableBool
// [0x00020400] 
struct UGFxMovie_execSetVariableBool_Params
{
	class FString                                      Path;                                             // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	uint32_t                                           B : 1;                                            // 0x000C (0x0004) [0x0000000000000080] [0x00000001] (CPF_Parm)
};

// Function GFxUI.GFxMovie.SetVariable
// [0x00020400] 
struct UGFxMovie_execSetVariable_Params
{
	class FString                                      Path;                                             // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	struct FASValue                                    Arg;                                              // 0x000C (0x0018) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
};

// Function GFxUI.GFxMovie.GetVariableString
// [0x00020400] 
struct UGFxMovie_execGetVariableString_Params
{
	class FString                                      Path;                                             // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	class FString                                      ReturnValue;                                      // 0x000C (0x000C) [0x0000000000400580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
};

// Function GFxUI.GFxMovie.GetVariableNumber
// [0x00020400] 
struct UGFxMovie_execGetVariableNumber_Params
{
	class FString                                      Path;                                             // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	float                                              ReturnValue;                                      // 0x000C (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxMovie.GetVariableBool
// [0x00020400] 
struct UGFxMovie_execGetVariableBool_Params
{
	class FString                                      Path;                                             // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	bool                                               ReturnValue : 1;                                  // 0x000C (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxMovie.GetVariable
// [0x00020400] 
struct UGFxMovie_execGetVariable_Params
{
	class FString                                      Path;                                             // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	struct FASValue                                    ReturnValue;                                      // 0x000C (0x0018) [0x0000000000400580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
};

// Function GFxUI.GFxMovie.PublishDataStoreValues
// [0x00020400] 
struct UGFxMovie_execPublishDataStoreValues_Params
{
};

// Function GFxUI.GFxMovie.RefreshDataStoreBindings
// [0x00020400] 
struct UGFxMovie_execRefreshDataStoreBindings_Params
{
};

// Function GFxUI.GFxMovie.Invoke
// [0x00020400] 
struct UGFxMovie_execInvoke_Params
{
	class FString                                      method;                                           // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	class TArray<struct FASValue>                      args;                                             // 0x000C (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	struct FASValue                                    ReturnValue;                                      // 0x0018 (0x0018) [0x0000000000400580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
};

// Function GFxUI.GFxMovie.SetTimingMode
// [0x00020400] 
struct UGFxMovie_execSetTimingMode_Params
{
	uint8_t                                            Mode;                                             // 0x0000 (0x0001) [0x0000000000000080] (CPF_Parm)    
};

// Function GFxUI.GFxMovie.Pause
// [0x00024400] 
struct UGFxMovie_execPause_Params
{
	uint32_t                                           pauseplay : 1;                                    // 0x0000 (0x0004) [0x0000000000000090] [0x00000001] (CPF_OptionalParm | CPF_Parm)
};

// Function GFxUI.GFxMovie.Advance
// [0x00020401] 
struct UGFxMovie_execAdvance_Params
{
	float                                              Time;                                             // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GFxUI.GFxMovie.SetExternalTexture
// [0x00020400] 
struct UGFxMovie_execSetExternalTexture_Params
{
	class FString                                      Resource;                                         // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	class UTexture*                                    Texture;                                          // 0x000C (0x0004) [0x0000000000000080] (CPF_Parm)    
	bool                                               ReturnValue : 1;                                  // 0x0010 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxMovie.FlushPlayerInput
// [0x00020401] 
struct UGFxMovie_execFlushPlayerInput_Params
{
	uint32_t                                           capturekeysonly : 1;                              // 0x0000 (0x0004) [0x0000000000000080] [0x00000001] (CPF_Parm)
};

// Function GFxUI.GFxMovie.ClearFocusIgnoreKeys
// [0x00020401] 
struct UGFxMovie_execClearFocusIgnoreKeys_Params
{
};

// Function GFxUI.GFxMovie.AddFocusIgnoreKey
// [0x00020401] 
struct UGFxMovie_execAddFocusIgnoreKey_Params
{
	class FName                                        Key;                                              // 0x0000 (0x0008) [0x0000000000000080] (CPF_Parm)    
};

// Function GFxUI.GFxMovie.ClearCaptureKeys
// [0x00020401] 
struct UGFxMovie_execClearCaptureKeys_Params
{
};

// Function GFxUI.GFxMovie.AddCaptureKey
// [0x00020401] 
struct UGFxMovie_execAddCaptureKey_Params
{
	class FName                                        Key;                                              // 0x0000 (0x0008) [0x0000000000000080] (CPF_Parm)    
};

// Function GFxUI.GFxMovie.SetFocus
// [0x00024401] 
struct UGFxMovie_execSetFocus_Params
{
	uint32_t                                           captureInput : 1;                                 // 0x0000 (0x0004) [0x0000000000000080] [0x00000001] (CPF_Parm)
	uint32_t : 0;                                  // 0x0004 CLOSE BITFIELD STORAGE UNIT
	uint32_t                                           Focus : 1;                                        // 0x0004 (0x0004) [0x0000000000000090] [0x00000001] (CPF_OptionalParm | CPF_Parm)
};

// Function GFxUI.GFxMovie.SetSceneDPG
// [0x00020401] 
struct UGFxMovie_execSetSceneDPG_Params
{
	uint8_t                                            NewDPG;                                           // 0x0000 (0x0001) [0x0000000000000080] (CPF_Parm)    
};

// Function GFxUI.GFxMovie.SetPerspective3D
// [0x00420401] 
struct UGFxMovie_execSetPerspective3D_Params
{
	struct FMatrix                                     matPersp;                                         // 0x0000 (0x0040) [0x0000000000000182] (CPF_Const | CPF_Parm | CPF_OutParm)
};

// Function GFxUI.GFxMovie.SetView3D
// [0x00420401] 
struct UGFxMovie_execSetView3D_Params
{
	struct FMatrix                                     matView;                                          // 0x0000 (0x0040) [0x0000000000000182] (CPF_Const | CPF_Parm | CPF_OutParm)
};

// Function GFxUI.GFxMovie.GetVisibleFrameRect
// [0x00420401] 
struct UGFxMovie_execGetVisibleFrameRect_Params
{
	float                                              x0;                                               // 0x0000 (0x0004) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
	float                                              y0;                                               // 0x0004 (0x0004) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
	float                                              X1;                                               // 0x0008 (0x0004) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
	float                                              Y1;                                               // 0x000C (0x0004) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
};

// Function GFxUI.GFxMovie.SetAlignment
// [0x00020401] 
struct UGFxMovie_execSetAlignment_Params
{
	uint8_t                                            A;                                                // 0x0000 (0x0001) [0x0000000000000080] (CPF_Parm)    
};

// Function GFxUI.GFxMovie.SetViewScaleMode
// [0x00020401] 
struct UGFxMovie_execSetViewScaleMode_Params
{
	uint8_t                                            sm;                                               // 0x0000 (0x0001) [0x0000000000000080] (CPF_Parm)    
};

// Function GFxUI.GFxMovie.SetViewport
// [0x00020401] 
struct UGFxMovie_execSetViewport_Params
{
	int32_t                                            X;                                                // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	int32_t                                            Y;                                                // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
	int32_t                                            Width;                                            // 0x0008 (0x0004) [0x0000000000000080] (CPF_Parm)    
	int32_t                                            Height;                                           // 0x000C (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GFxUI.GFxMovie.GetGameViewportClient
// [0x00020401] 
struct UGFxMovie_execGetGameViewportClient_Params
{
	class UGameViewportClient*                         ReturnValue;                                      // 0x0000 (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxMovie.SetMovieInfo
// [0x00020002] 
struct UGFxMovie_execSetMovieInfo_Params
{
	class UGFxMovieInfo*                               Data;                                             // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GFxUI.GFxMovie.OnClose
// [0x00020800] 
struct UGFxMovie_eventOnClose_Params
{
};

// Function GFxUI.GFxMovie.Close
// [0x00024401] 
struct UGFxMovie_execClose_Params
{
	uint32_t                                           Unload : 1;                                       // 0x0000 (0x0004) [0x0000000000000090] [0x00000001] (CPF_OptionalParm | CPF_Parm)
};

// Function GFxUI.GFxMovie.Start
// [0x00024C00] 
struct UGFxMovie_eventStart_Params
{
	uint32_t                                           StartPaused : 1;                                  // 0x0000 (0x0004) [0x0000000000000090] [0x00000001] (CPF_OptionalParm | CPF_Parm)
	uint32_t : 0;                                  // 0x0004 CLOSE BITFIELD STORAGE UNIT
	bool                                               ReturnValue : 1;                                  // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxMovie.HandleInputKey
// [0x00124000] 
struct UGFxMovie_execHandleInputKey_Params
{
	int32_t                                            ControllerId;                                     // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class FName                                        Key;                                              // 0x0004 (0x0008) [0x0000000000000080] (CPF_Parm)    
	uint8_t                                            EventType;                                        // 0x000C (0x0001) [0x0000000000000080] (CPF_Parm)    
	uint8_t                                            UnknownData00[0x3];                              // 0x000D (0x0003) MISSED OFFSET
	float                                              AmountDepressed;                                  // 0x0010 (0x0004) [0x0000000000000080] (CPF_Parm)    
	uint32_t                                           bGamepad : 1;                                     // 0x0014 (0x0004) [0x0000000000000090] [0x00000001] (CPF_OptionalParm | CPF_Parm)
	uint32_t : 0;                                  // 0x0018 CLOSE BITFIELD STORAGE UNIT
	bool                                               ReturnValue : 1;                                  // 0x0018 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxValue.ActionScriptSetFunctionOn
// [0x00080401] 
struct UGFxValue_execActionScriptSetFunctionOn_Params
{
	class UGFxValue*                                   Target;                                           // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class FString                                      member;                                           // 0x0004 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
};

// Function GFxUI.GFxValue.ActionScriptSetFunction
// [0x00080401] 
struct UGFxValue_execActionScriptSetFunction_Params
{
	class FString                                      member;                                           // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
};

// Function GFxUI.GFxValue.ActionScriptArray
// [0x00080401] 
struct UGFxValue_execActionScriptArray_Params
{
	class FString                                      Path;                                             // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	class TArray<class UGFxValue*>                     ReturnValue;                                      // 0x000C (0x000C) [0x0000000000400580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
};

// Function GFxUI.GFxValue.ActionScriptObject
// [0x00080401] 
struct UGFxValue_execActionScriptObject_Params
{
	class FString                                      Path;                                             // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	class UGFxValue*                                   ReturnValue;                                      // 0x000C (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxValue.ActionScriptString
// [0x00080401] 
struct UGFxValue_execActionScriptString_Params
{
	class FString                                      method;                                           // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	class FString                                      ReturnValue;                                      // 0x000C (0x000C) [0x0000000000400580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
};

// Function GFxUI.GFxValue.ActionScriptFloat
// [0x00080401] 
struct UGFxValue_execActionScriptFloat_Params
{
	class FString                                      method;                                           // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	float                                              ReturnValue;                                      // 0x000C (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxValue.ActionScriptInt
// [0x00080401] 
struct UGFxValue_execActionScriptInt_Params
{
	class FString                                      method;                                           // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	int32_t                                            ReturnValue;                                      // 0x000C (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxValue.ActionScriptVoid
// [0x00080401] 
struct UGFxValue_execActionScriptVoid_Params
{
	class FString                                      method;                                           // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
};

// Function GFxUI.GFxValue.SetElementMemberString
// [0x00020401] 
struct UGFxValue_execSetElementMemberString_Params
{
	int32_t                                            Index;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class FString                                      member;                                           // 0x0004 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	class FString                                      S;                                                // 0x0010 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
};

// Function GFxUI.GFxValue.SetElementMemberNumber
// [0x00020401] 
struct UGFxValue_execSetElementMemberNumber_Params
{
	int32_t                                            Index;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class FString                                      member;                                           // 0x0004 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	float                                              F;                                                // 0x0010 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GFxUI.GFxValue.SetElementMemberBool
// [0x00020401] 
struct UGFxValue_execSetElementMemberBool_Params
{
	int32_t                                            Index;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class FString                                      member;                                           // 0x0004 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	uint32_t                                           B : 1;                                            // 0x0010 (0x0004) [0x0000000000000080] [0x00000001] (CPF_Parm)
};

// Function GFxUI.GFxValue.SetElementMemberObject
// [0x00020401] 
struct UGFxValue_execSetElementMemberObject_Params
{
	int32_t                                            Index;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class FString                                      member;                                           // 0x0004 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	class UGFxValue*                                   val;                                              // 0x0010 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GFxUI.GFxValue.SetElementMember
// [0x00020401] 
struct UGFxValue_execSetElementMember_Params
{
	int32_t                                            Index;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class FString                                      member;                                           // 0x0004 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	struct FASValue                                    Arg;                                              // 0x0010 (0x0018) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
};

// Function GFxUI.GFxValue.GetElementMemberString
// [0x00020401] 
struct UGFxValue_execGetElementMemberString_Params
{
	int32_t                                            Index;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class FString                                      member;                                           // 0x0004 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	class FString                                      ReturnValue;                                      // 0x0010 (0x000C) [0x0000000000400580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
};

// Function GFxUI.GFxValue.GetElementMemberNumber
// [0x00020401] 
struct UGFxValue_execGetElementMemberNumber_Params
{
	int32_t                                            Index;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class FString                                      member;                                           // 0x0004 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	float                                              ReturnValue;                                      // 0x0010 (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxValue.GetElementMemberBool
// [0x00020401] 
struct UGFxValue_execGetElementMemberBool_Params
{
	int32_t                                            Index;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class FString                                      member;                                           // 0x0004 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	bool                                               ReturnValue : 1;                                  // 0x0010 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxValue.GetElementMemberObject
// [0x00024401] 
struct UGFxValue_execGetElementMemberObject_Params
{
	int32_t                                            Index;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class FString                                      member;                                           // 0x0004 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	class UClass*                                      Type;                                             // 0x0010 (0x0004) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
	class UGFxValue*                                   ReturnValue;                                      // 0x0014 (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxValue.GetElementMember
// [0x00020401] 
struct UGFxValue_execGetElementMember_Params
{
	int32_t                                            Index;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class FString                                      member;                                           // 0x0004 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	struct FASValue                                    ReturnValue;                                      // 0x0010 (0x0018) [0x0000000000400580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
};

// Function GFxUI.GFxValue.SetElementColorTransform
// [0x00020401] 
struct UGFxValue_execSetElementColorTransform_Params
{
	int32_t                                            Index;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FASColorTransform                           cxform;                                           // 0x0004 (0x0020) [0x0000000000000080] (CPF_Parm)    
};

// Function GFxUI.GFxValue.SetElementPosition
// [0x00020401] 
struct UGFxValue_execSetElementPosition_Params
{
	int32_t                                            Index;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	float                                              X;                                                // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
	float                                              Y;                                                // 0x0008 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GFxUI.GFxValue.SetElementVisible
// [0x00020401] 
struct UGFxValue_execSetElementVisible_Params
{
	int32_t                                            Index;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	uint32_t                                           Visible : 1;                                      // 0x0004 (0x0004) [0x0000000000000080] [0x00000001] (CPF_Parm)
};

// Function GFxUI.GFxValue.SetElementDisplayMatrix
// [0x00020401] 
struct UGFxValue_execSetElementDisplayMatrix_Params
{
	int32_t                                            Index;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	uint8_t                                            UnknownData00[0xC];                              // 0x0004 (0x000C) MISSED OFFSET
	struct FMatrix                                     M;                                                // 0x0010 (0x0040) [0x0000000000000080] (CPF_Parm)    
};

// Function GFxUI.GFxValue.SetElementDisplayInfo
// [0x00020401] 
struct UGFxValue_execSetElementDisplayInfo_Params
{
	int32_t                                            Index;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FASDisplayInfo                              D;                                                // 0x0004 (0x002C) [0x0000000000000080] (CPF_Parm)    
};

// Function GFxUI.GFxValue.SetElementString
// [0x00020401] 
struct UGFxValue_execSetElementString_Params
{
	int32_t                                            Index;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class FString                                      S;                                                // 0x0004 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
};

// Function GFxUI.GFxValue.SetElementNumber
// [0x00020401] 
struct UGFxValue_execSetElementNumber_Params
{
	int32_t                                            Index;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	float                                              F;                                                // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GFxUI.GFxValue.SetElementBool
// [0x00020401] 
struct UGFxValue_execSetElementBool_Params
{
	int32_t                                            Index;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	uint32_t                                           B : 1;                                            // 0x0004 (0x0004) [0x0000000000000080] [0x00000001] (CPF_Parm)
};

// Function GFxUI.GFxValue.SetElementObject
// [0x00020401] 
struct UGFxValue_execSetElementObject_Params
{
	int32_t                                            Index;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class UGFxValue*                                   val;                                              // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GFxUI.GFxValue.SetElement
// [0x00020401] 
struct UGFxValue_execSetElement_Params
{
	int32_t                                            Index;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FASValue                                    Arg;                                              // 0x0004 (0x0018) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
};

// Function GFxUI.GFxValue.GetElementDisplayMatrix
// [0x00020401] 
struct UGFxValue_execGetElementDisplayMatrix_Params
{
	int32_t                                            Index;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	uint8_t                                            UnknownData00[0xC];                              // 0x0004 (0x000C) MISSED OFFSET
	struct FMatrix                                     ReturnValue;                                      // 0x0010 (0x0040) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxValue.GetElementDisplayInfo
// [0x00020401] 
struct UGFxValue_execGetElementDisplayInfo_Params
{
	int32_t                                            Index;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FASDisplayInfo                              ReturnValue;                                      // 0x0004 (0x002C) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxValue.GetElementString
// [0x00020401] 
struct UGFxValue_execGetElementString_Params
{
	int32_t                                            Index;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class FString                                      ReturnValue;                                      // 0x0004 (0x000C) [0x0000000000400580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
};

// Function GFxUI.GFxValue.GetElementNumber
// [0x00020401] 
struct UGFxValue_execGetElementNumber_Params
{
	int32_t                                            Index;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	float                                              ReturnValue;                                      // 0x0004 (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxValue.GetElementBool
// [0x00020401] 
struct UGFxValue_execGetElementBool_Params
{
	int32_t                                            Index;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	bool                                               ReturnValue : 1;                                  // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxValue.GetElementObject
// [0x00024401] 
struct UGFxValue_execGetElementObject_Params
{
	int32_t                                            Index;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class UClass*                                      Type;                                             // 0x0004 (0x0004) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
	class UGFxValue*                                   ReturnValue;                                      // 0x0008 (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxValue.GetElement
// [0x00020401] 
struct UGFxValue_execGetElement_Params
{
	int32_t                                            Index;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	struct FASValue                                    ReturnValue;                                      // 0x0004 (0x0018) [0x0000000000400580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
};

// Function GFxUI.GFxValue.SetText
// [0x00020401] 
struct UGFxValue_execSetText_Params
{
	class FString                                      Text;                                             // 0x0000 (0x000C) [0x0000000000400880] (CPF_Parm | CPF_CoerceParm | CPF_NeedCtorLink)
};

// Function GFxUI.GFxValue.GetText
// [0x00020401] 
struct UGFxValue_execGetText_Params
{
	class FString                                      ReturnValue;                                      // 0x0000 (0x000C) [0x0000000000400580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
};

// Function GFxUI.GFxValue.AttachMovie
// [0x00024401] 
struct UGFxValue_execAttachMovie_Params
{
	class FString                                      symbolname;                                       // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	class FString                                      instancename;                                     // 0x000C (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	int32_t                                            Depth;                                            // 0x0018 (0x0004) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
	class UClass*                                      Type;                                             // 0x001C (0x0004) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
	class UGFxValue*                                   ReturnValue;                                      // 0x0020 (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxValue.CreateEmptyMovieClip
// [0x00024401] 
struct UGFxValue_execCreateEmptyMovieClip_Params
{
	class FString                                      instancename;                                     // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	int32_t                                            Depth;                                            // 0x000C (0x0004) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
	class UClass*                                      Type;                                             // 0x0010 (0x0004) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
	class UGFxValue*                                   ReturnValue;                                      // 0x0014 (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxValue.GotoAndStopI
// [0x00020401] 
struct UGFxValue_execGotoAndStopI_Params
{
	int32_t                                            frame;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GFxUI.GFxValue.GotoAndStop
// [0x00020401] 
struct UGFxValue_execGotoAndStop_Params
{
	class FString                                      frame;                                            // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
};

// Function GFxUI.GFxValue.GotoAndPlayI
// [0x00020401] 
struct UGFxValue_execGotoAndPlayI_Params
{
	int32_t                                            frame;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GFxUI.GFxValue.GotoAndPlay
// [0x00020401] 
struct UGFxValue_execGotoAndPlay_Params
{
	class FString                                      frame;                                            // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
};

// Function GFxUI.GFxValue.SetColorTransform
// [0x00020401] 
struct UGFxValue_execSetColorTransform_Params
{
	struct FASColorTransform                           cxform;                                           // 0x0000 (0x0020) [0x0000000000000080] (CPF_Parm)    
};

// Function GFxUI.GFxValue.SetPosition
// [0x00020401] 
struct UGFxValue_execSetPosition_Params
{
	float                                              X;                                                // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	float                                              Y;                                                // 0x0004 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GFxUI.GFxValue.SetVisible
// [0x00020401] 
struct UGFxValue_execSetVisible_Params
{
	uint32_t                                           Visible : 1;                                      // 0x0000 (0x0004) [0x0000000000000080] [0x00000001] (CPF_Parm)
};

// Function GFxUI.GFxValue.SetDisplayMatrix3D
// [0x00020401] 
struct UGFxValue_execSetDisplayMatrix3D_Params
{
	struct FMatrix                                     M;                                                // 0x0000 (0x0040) [0x0000000000000080] (CPF_Parm)    
};

// Function GFxUI.GFxValue.SetDisplayMatrix
// [0x00020401] 
struct UGFxValue_execSetDisplayMatrix_Params
{
	struct FMatrix                                     M;                                                // 0x0000 (0x0040) [0x0000000000000080] (CPF_Parm)    
};

// Function GFxUI.GFxValue.SetDisplayInfo
// [0x00020401] 
struct UGFxValue_execSetDisplayInfo_Params
{
	struct FASDisplayInfo                              D;                                                // 0x0000 (0x002C) [0x0000000000000080] (CPF_Parm)    
};

// Function GFxUI.GFxValue.GetPosition
// [0x00420401] 
struct UGFxValue_execGetPosition_Params
{
	float                                              X;                                                // 0x0000 (0x0004) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
	float                                              Y;                                                // 0x0004 (0x0004) [0x0000000000000180] (CPF_Parm | CPF_OutParm)
	bool                                               ReturnValue : 1;                                  // 0x0008 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxValue.GetColorTransform
// [0x00020401] 
struct UGFxValue_execGetColorTransform_Params
{
	struct FASColorTransform                           ReturnValue;                                      // 0x0000 (0x0020) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxValue.GetDisplayMatrix
// [0x00020401] 
struct UGFxValue_execGetDisplayMatrix_Params
{
	struct FMatrix                                     ReturnValue;                                      // 0x0000 (0x0040) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxValue.GetDisplayInfo
// [0x00020401] 
struct UGFxValue_execGetDisplayInfo_Params
{
	struct FASDisplayInfo                              ReturnValue;                                      // 0x0000 (0x002C) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxValue.SetString
// [0x00020401] 
struct UGFxValue_execSetString_Params
{
	class FString                                      member;                                           // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	class FString                                      S;                                                // 0x000C (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
};

// Function GFxUI.GFxValue.SetNumber
// [0x00020401] 
struct UGFxValue_execSetNumber_Params
{
	class FString                                      member;                                           // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	float                                              F;                                                // 0x000C (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GFxUI.GFxValue.SetBool
// [0x00020401] 
struct UGFxValue_execSetBool_Params
{
	class FString                                      member;                                           // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	uint32_t                                           B : 1;                                            // 0x000C (0x0004) [0x0000000000000080] [0x00000001] (CPF_Parm)
};

// Function GFxUI.GFxValue.SetFunction
// [0x00020401] 
struct UGFxValue_execSetFunction_Params
{
	class FString                                      member;                                           // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	class UObject*                                     context;                                          // 0x000C (0x0004) [0x0000000000000080] (CPF_Parm)    
	class FName                                        fname;                                            // 0x0010 (0x0008) [0x0000000000000080] (CPF_Parm)    
};

// Function GFxUI.GFxValue.SetObject
// [0x00020401] 
struct UGFxValue_execSetObject_Params
{
	class FString                                      member;                                           // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	class UGFxValue*                                   val;                                              // 0x000C (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GFxUI.GFxValue.Set
// [0x00020401] 
struct UGFxValue_execSet_Params
{
	class FString                                      member;                                           // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	struct FASValue                                    Arg;                                              // 0x000C (0x0018) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
};

// Function GFxUI.GFxValue.GetString
// [0x00020401] 
struct UGFxValue_execGetString_Params
{
	class FString                                      member;                                           // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	class FString                                      ReturnValue;                                      // 0x000C (0x000C) [0x0000000000400580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
};

// Function GFxUI.GFxValue.GetNumber
// [0x00020401] 
struct UGFxValue_execGetNumber_Params
{
	class FString                                      member;                                           // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	float                                              ReturnValue;                                      // 0x000C (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxValue.GetBool
// [0x00020401] 
struct UGFxValue_execGetBool_Params
{
	class FString                                      member;                                           // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	bool                                               ReturnValue : 1;                                  // 0x000C (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxValue.GetObject
// [0x00024401] 
struct UGFxValue_execGetObjectWin_Params
{
	class FString                                      member;                                           // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	class UClass*                                      Type;                                             // 0x000C (0x0004) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
	class UGFxValue*                                   ReturnValue;                                      // 0x0010 (0x0004) [0x0000000000000580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxValue.Get
// [0x00020401] 
struct UGFxValue_execGet_Params
{
	class FString                                      member;                                           // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	struct FASValue                                    ReturnValue;                                      // 0x000C (0x0018) [0x0000000000400580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
};

// Function GFxUI.GFxValue.Invoke
// [0x00020401] 
struct UGFxValue_execInvoke_Params
{
	class FString                                      member;                                           // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	class TArray<struct FASValue>                      args;                                             // 0x000C (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	struct FASValue                                    ReturnValue;                                      // 0x0018 (0x0018) [0x0000000000400580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
};

// Function GFxUI.GFxAction_CloseMovie.IsValidLevelSequenceObject
// [0x00020802] 
struct UGFxAction_CloseMovie_eventIsValidLevelSequenceObject_Params
{
	bool                                               ReturnValue : 1;                                  // 0x0000 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxAction_GetVariable.IsValidLevelSequenceObject
// [0x00020802] 
struct UGFxAction_GetVariable_eventIsValidLevelSequenceObject_Params
{
	bool                                               ReturnValue : 1;                                  // 0x0000 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxAction_Invoke.IsValidLevelSequenceObject
// [0x00020802] 
struct UGFxAction_Invoke_eventIsValidLevelSequenceObject_Params
{
	bool                                               ReturnValue : 1;                                  // 0x0000 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxAction_OpenMovie.IsValidLevelSequenceObject
// [0x00020802] 
struct UGFxAction_OpenMovie_eventIsValidLevelSequenceObject_Params
{
	bool                                               ReturnValue : 1;                                  // 0x0000 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxAction_SetVariable.IsValidLevelSequenceObject
// [0x00020802] 
struct UGFxAction_SetVariable_eventIsValidLevelSequenceObject_Params
{
	bool                                               ReturnValue : 1;                                  // 0x0000 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxFSCmdHandler_Kismet.FSCommand
// [0x00020C00] 
struct UGFxFSCmdHandler_Kismet_eventFSCommand_Params
{
	class UGFxMovie*                                   Movie;                                            // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	class FString                                      Cmd;                                              // 0x0004 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	class FString                                      Arg;                                              // 0x0010 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	bool                                               ReturnValue : 1;                                  // 0x001C (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxDataStoreSubscriber.SaveSubscriberValue
// [0x00424400] 
struct UGFxDataStoreSubscriber_execSaveSubscriberValue_Params
{
	class TArray<class UUIDataStore*>                  out_BoundDataStores;                              // 0x0000 (0x000C) [0x0000000000400180] (CPF_Parm | CPF_OutParm | CPF_NeedCtorLink)
	int32_t                                            BindingIndex;                                     // 0x000C (0x0004) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
	bool                                               ReturnValue : 1;                                  // 0x0010 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxDataStoreSubscriber.ClearBoundDataStores
// [0x00020401] 
struct UGFxDataStoreSubscriber_execClearBoundDataStores_Params
{
};

// Function GFxUI.GFxDataStoreSubscriber.GetBoundDataStores
// [0x00420401] 
struct UGFxDataStoreSubscriber_execGetBoundDataStores_Params
{
	class TArray<class UUIDataStore*>                  out_BoundDataStores;                              // 0x0000 (0x000C) [0x0000000000400180] (CPF_Parm | CPF_OutParm | CPF_NeedCtorLink)
};

// Function GFxUI.GFxDataStoreSubscriber.NotifyDataStoreValueUpdated
// [0x00020401] 
struct UGFxDataStoreSubscriber_execNotifyDataStoreValueUpdated_Params
{
	class UUIDataStore*                                SourceDataStore;                                  // 0x0000 (0x0004) [0x0000000000000080] (CPF_Parm)    
	uint32_t                                           bValuesInvalidated : 1;                           // 0x0004 (0x0004) [0x0000000000000080] [0x00000001] (CPF_Parm)
	class FName                                        PropertyTag;                                      // 0x0008 (0x0008) [0x0000000000000080] (CPF_Parm)    
	class UUIDataProvider*                             SourceProvider;                                   // 0x0010 (0x0004) [0x0000000000000080] (CPF_Parm)    
	int32_t                                            ArrayIndex;                                       // 0x0014 (0x0004) [0x0000000000000080] (CPF_Parm)    
};

// Function GFxUI.GFxDataStoreSubscriber.RefreshSubscriberValue
// [0x00024401] 
struct UGFxDataStoreSubscriber_execRefreshSubscriberValue_Params
{
	int32_t                                            BindingIndex;                                     // 0x0000 (0x0004) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
	bool                                               ReturnValue : 1;                                  // 0x0004 (0x0004) [0x0000000000000580] [0x00000001] (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
};

// Function GFxUI.GFxDataStoreSubscriber.GetDataStoreBinding
// [0x00024401] 
struct UGFxDataStoreSubscriber_execGetDataStoreBinding_Params
{
	int32_t                                            BindingIndex;                                     // 0x0000 (0x0004) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
	class FString                                      ReturnValue;                                      // 0x0004 (0x000C) [0x0000000000400580] (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
};

// Function GFxUI.GFxDataStoreSubscriber.SetDataStoreBinding
// [0x00024401] 
struct UGFxDataStoreSubscriber_execSetDataStoreBinding_Params
{
	class FString                                      MarkupText;                                       // 0x0000 (0x000C) [0x0000000000400080] (CPF_Parm | CPF_NeedCtorLink)
	int32_t                                            BindingIndex;                                     // 0x000C (0x0004) [0x0000000000000090] (CPF_OptionalParm | CPF_Parm)
};

// Function GFxUI.GFxDataStoreSubscriber.PublishValues
// [0x00020401] 
struct UGFxDataStoreSubscriber_execPublishValues_Params
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
