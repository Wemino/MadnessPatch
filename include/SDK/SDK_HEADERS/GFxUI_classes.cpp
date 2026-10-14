/*
#############################################################################################
# Alice2 (ASDK) SDK 1.0.0.0
# Generated with the CodeRedGenerator v1.2.0
# ========================================================================================= #
# File: GFxUI_classes.cpp
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

// Function GFxUI.GFxFSCmdHandler.FSCommand
// [0x00020800] (FUNC_Event | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class UGFxMovie*               Movie                          (CPF_Parm)
// class FString                  Cmd                            (CPF_Parm | CPF_NeedCtorLink)
// class FString                  Arg                            (CPF_Parm | CPF_NeedCtorLink)

bool UGFxFSCmdHandler::eventFSCommand(class UGFxMovie* Movie, const class FString& Cmd, const class FString& Arg)
{
	static UFunction* uFnFSCommand = nullptr;

	if (!uFnFSCommand)
	{
		uFnFSCommand = UFunction::FindFunction("Function GFxUI.GFxFSCmdHandler.FSCommand");
	}

	UGFxFSCmdHandler_eventFSCommand_Params FSCommand_Params;
	memset(&FSCommand_Params, 0, sizeof(FSCommand_Params));

	if (!uFnFSCommand)
	{
		return FSCommand_Params.ReturnValue;
	}
	FSCommand_Params.Movie = Movie;
	memcpy_s(&FSCommand_Params.Cmd, sizeof(FSCommand_Params.Cmd), &Cmd, sizeof(Cmd));
	memcpy_s(&FSCommand_Params.Arg, sizeof(FSCommand_Params.Arg), &Arg, sizeof(Arg));

	this->ProcessEvent(uFnFSCommand, &FSCommand_Params, nullptr);

	return FSCommand_Params.ReturnValue;
}

// Function GFxUI.GFxGameViewportClient.Init
// [0x00420802] (FUNC_Defined | FUNC_Event | FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FString                  OutError                       (CPF_Parm | CPF_OutParm | CPF_NeedCtorLink)

bool UGFxGameViewportClient::eventInit(class FString& outOutError)
{
	static UFunction* uFnInit = nullptr;

	if (!uFnInit)
	{
		uFnInit = UFunction::FindFunction("Function GFxUI.GFxGameViewportClient.Init");
	}

	UGFxGameViewportClient_eventInit_Params Init_Params;
	memset(&Init_Params, 0, sizeof(Init_Params));

	if (!uFnInit)
	{
		return Init_Params.ReturnValue;
	}
	memcpy_s(&Init_Params.OutError, sizeof(Init_Params.OutError), &outOutError, sizeof(outOutError));

	this->ProcessEvent(uFnInit, &Init_Params, nullptr);

	memcpy_s(&outOutError, sizeof(outOutError), &Init_Params.OutError, sizeof(Init_Params.OutError));

	return Init_Params.ReturnValue;
}

// Function GFxUI.GFxInteraction.NotifyGameSessionEnded
// [0x00020400] (FUNC_Native | FUNC_Public)
// Parameter Info:

void UGFxInteraction::NotifyGameSessionEnded()
{
	static UFunction* uFnNotifyGameSessionEnded = nullptr;

	if (!uFnNotifyGameSessionEnded)
	{
		uFnNotifyGameSessionEnded = UFunction::FindFunction("Function GFxUI.GFxInteraction.NotifyGameSessionEnded");
	}

	UGFxInteraction_execNotifyGameSessionEnded_Params NotifyGameSessionEnded_Params;
	memset(&NotifyGameSessionEnded_Params, 0, sizeof(NotifyGameSessionEnded_Params));

	if (!uFnNotifyGameSessionEnded)
	{
		return;
	}

	uint16_t nativeIndex = uFnNotifyGameSessionEnded->iNative;
	uFnNotifyGameSessionEnded->iNative = 0;
	this->ProcessEvent(uFnNotifyGameSessionEnded, &NotifyGameSessionEnded_Params, nullptr);
	uFnNotifyGameSessionEnded->iNative = nativeIndex;
}

// Function GFxUI.GFxInteraction.GetFocusMovie
// [0x00020400] (FUNC_Native | FUNC_Public)
// Parameter Info:
// class UGFxMovie*               ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

class UGFxMovie* UGFxInteraction::GetFocusMovie()
{
	static UFunction* uFnGetFocusMovie = nullptr;

	if (!uFnGetFocusMovie)
	{
		uFnGetFocusMovie = UFunction::FindFunction("Function GFxUI.GFxInteraction.GetFocusMovie");
	}

	UGFxInteraction_execGetFocusMovie_Params GetFocusMovie_Params;
	memset(&GetFocusMovie_Params, 0, sizeof(GetFocusMovie_Params));

	if (!uFnGetFocusMovie)
	{
		return GetFocusMovie_Params.ReturnValue;
	}

	uint16_t nativeIndex = uFnGetFocusMovie->iNative;
	uFnGetFocusMovie->iNative = 0;
	this->ProcessEvent(uFnGetFocusMovie, &GetFocusMovie_Params, nullptr);
	uFnGetFocusMovie->iNative = nativeIndex;

	return GetFocusMovie_Params.ReturnValue;
}

// Function GFxUI.GFxInteraction.SetFocusMovie
// [0x00020400] (FUNC_Native | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FString                  MovieName                      (CPF_Parm | CPF_NeedCtorLink)
// uint32_t                       captureInput                   (CPF_Parm)

bool UGFxInteraction::SetFocusMovie(const class FString& MovieName, bool captureInput)
{
	static UFunction* uFnSetFocusMovie = nullptr;

	if (!uFnSetFocusMovie)
	{
		uFnSetFocusMovie = UFunction::FindFunction("Function GFxUI.GFxInteraction.SetFocusMovie");
	}

	UGFxInteraction_execSetFocusMovie_Params SetFocusMovie_Params;
	memset(&SetFocusMovie_Params, 0, sizeof(SetFocusMovie_Params));

	if (!uFnSetFocusMovie)
	{
		return SetFocusMovie_Params.ReturnValue;
	}
	memcpy_s(&SetFocusMovie_Params.MovieName, sizeof(SetFocusMovie_Params.MovieName), &MovieName, sizeof(MovieName));
	SetFocusMovie_Params.captureInput = captureInput;

	uint16_t nativeIndex = uFnSetFocusMovie->iNative;
	uFnSetFocusMovie->iNative = 0;
	this->ProcessEvent(uFnSetFocusMovie, &SetFocusMovie_Params, nullptr);
	uFnSetFocusMovie->iNative = nativeIndex;

	return SetFocusMovie_Params.ReturnValue;
}

// Function GFxUI.GFxMovie.ActionScriptSetFunction
// [0x00080401] (FUNC_Final | FUNC_Native | FUNC_Protected)
// Parameter Info:
// class UGFxValue*               Obj                            (CPF_Parm)
// class FString                  member                         (CPF_Parm | CPF_NeedCtorLink)

void UGFxMovie::ActionScriptSetFunction(class UGFxValue* Obj, const class FString& member)
{
	static UFunction* uFnActionScriptSetFunction = nullptr;

	if (!uFnActionScriptSetFunction)
	{
		uFnActionScriptSetFunction = UFunction::FindFunction("Function GFxUI.GFxMovie.ActionScriptSetFunction");
	}

	UGFxMovie_execActionScriptSetFunction_Params ActionScriptSetFunction_Params;
	memset(&ActionScriptSetFunction_Params, 0, sizeof(ActionScriptSetFunction_Params));

	if (!uFnActionScriptSetFunction)
	{
		return;
	}
	ActionScriptSetFunction_Params.Obj = Obj;
	memcpy_s(&ActionScriptSetFunction_Params.member, sizeof(ActionScriptSetFunction_Params.member), &member, sizeof(member));

	uint16_t nativeIndex = uFnActionScriptSetFunction->iNative;
	uFnActionScriptSetFunction->iNative = 0;
	this->ProcessEvent(uFnActionScriptSetFunction, &ActionScriptSetFunction_Params, nullptr);
	uFnActionScriptSetFunction->iNative = nativeIndex;
}

// Function GFxUI.GFxMovie.ActionScriptObject
// [0x00080401] (FUNC_Final | FUNC_Native | FUNC_Protected)
// Parameter Info:
// class UGFxValue*               ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FString                  Path                           (CPF_Parm | CPF_NeedCtorLink)

class UGFxValue* UGFxMovie::ActionScriptObject(const class FString& Path)
{
	static UFunction* uFnActionScriptObject = nullptr;

	if (!uFnActionScriptObject)
	{
		uFnActionScriptObject = UFunction::FindFunction("Function GFxUI.GFxMovie.ActionScriptObject");
	}

	UGFxMovie_execActionScriptObject_Params ActionScriptObject_Params;
	memset(&ActionScriptObject_Params, 0, sizeof(ActionScriptObject_Params));

	if (!uFnActionScriptObject)
	{
		return ActionScriptObject_Params.ReturnValue;
	}
	memcpy_s(&ActionScriptObject_Params.Path, sizeof(ActionScriptObject_Params.Path), &Path, sizeof(Path));

	uint16_t nativeIndex = uFnActionScriptObject->iNative;
	uFnActionScriptObject->iNative = 0;
	this->ProcessEvent(uFnActionScriptObject, &ActionScriptObject_Params, nullptr);
	uFnActionScriptObject->iNative = nativeIndex;

	return ActionScriptObject_Params.ReturnValue;
}

// Function GFxUI.GFxMovie.ActionScriptString
// [0x00080401] (FUNC_Final | FUNC_Native | FUNC_Protected)
// Parameter Info:
// class FString                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
// class FString                  Path                           (CPF_Parm | CPF_NeedCtorLink)

class FString UGFxMovie::ActionScriptString(const class FString& Path)
{
	static UFunction* uFnActionScriptString = nullptr;

	if (!uFnActionScriptString)
	{
		uFnActionScriptString = UFunction::FindFunction("Function GFxUI.GFxMovie.ActionScriptString");
	}

	UGFxMovie_execActionScriptString_Params ActionScriptString_Params;
	memset(&ActionScriptString_Params, 0, sizeof(ActionScriptString_Params));

	if (!uFnActionScriptString)
	{
		return ActionScriptString_Params.ReturnValue;
	}
	memcpy_s(&ActionScriptString_Params.Path, sizeof(ActionScriptString_Params.Path), &Path, sizeof(Path));

	uint16_t nativeIndex = uFnActionScriptString->iNative;
	uFnActionScriptString->iNative = 0;
	this->ProcessEvent(uFnActionScriptString, &ActionScriptString_Params, nullptr);
	uFnActionScriptString->iNative = nativeIndex;

	return ActionScriptString_Params.ReturnValue;
}

// Function GFxUI.GFxMovie.ActionScriptFloat
// [0x00080401] (FUNC_Final | FUNC_Native | FUNC_Protected)
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FString                  Path                           (CPF_Parm | CPF_NeedCtorLink)

float UGFxMovie::ActionScriptFloat(const class FString& Path)
{
	static UFunction* uFnActionScriptFloat = nullptr;

	if (!uFnActionScriptFloat)
	{
		uFnActionScriptFloat = UFunction::FindFunction("Function GFxUI.GFxMovie.ActionScriptFloat");
	}

	UGFxMovie_execActionScriptFloat_Params ActionScriptFloat_Params;
	memset(&ActionScriptFloat_Params, 0, sizeof(ActionScriptFloat_Params));

	if (!uFnActionScriptFloat)
	{
		return ActionScriptFloat_Params.ReturnValue;
	}
	memcpy_s(&ActionScriptFloat_Params.Path, sizeof(ActionScriptFloat_Params.Path), &Path, sizeof(Path));

	uint16_t nativeIndex = uFnActionScriptFloat->iNative;
	uFnActionScriptFloat->iNative = 0;
	this->ProcessEvent(uFnActionScriptFloat, &ActionScriptFloat_Params, nullptr);
	uFnActionScriptFloat->iNative = nativeIndex;

	return ActionScriptFloat_Params.ReturnValue;
}

// Function GFxUI.GFxMovie.ActionScriptInt
// [0x00080401] (FUNC_Final | FUNC_Native | FUNC_Protected)
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FString                  Path                           (CPF_Parm | CPF_NeedCtorLink)

int32_t UGFxMovie::ActionScriptInt(const class FString& Path)
{
	static UFunction* uFnActionScriptInt = nullptr;

	if (!uFnActionScriptInt)
	{
		uFnActionScriptInt = UFunction::FindFunction("Function GFxUI.GFxMovie.ActionScriptInt");
	}

	UGFxMovie_execActionScriptInt_Params ActionScriptInt_Params;
	memset(&ActionScriptInt_Params, 0, sizeof(ActionScriptInt_Params));

	if (!uFnActionScriptInt)
	{
		return ActionScriptInt_Params.ReturnValue;
	}
	memcpy_s(&ActionScriptInt_Params.Path, sizeof(ActionScriptInt_Params.Path), &Path, sizeof(Path));

	uint16_t nativeIndex = uFnActionScriptInt->iNative;
	uFnActionScriptInt->iNative = 0;
	this->ProcessEvent(uFnActionScriptInt, &ActionScriptInt_Params, nullptr);
	uFnActionScriptInt->iNative = nativeIndex;

	return ActionScriptInt_Params.ReturnValue;
}

// Function GFxUI.GFxMovie.ActionScriptVoid
// [0x00080401] (FUNC_Final | FUNC_Native | FUNC_Protected)
// Parameter Info:
// class FString                  Path                           (CPF_Parm | CPF_NeedCtorLink)

void UGFxMovie::ActionScriptVoid(const class FString& Path)
{
	static UFunction* uFnActionScriptVoid = nullptr;

	if (!uFnActionScriptVoid)
	{
		uFnActionScriptVoid = UFunction::FindFunction("Function GFxUI.GFxMovie.ActionScriptVoid");
	}

	UGFxMovie_execActionScriptVoid_Params ActionScriptVoid_Params;
	memset(&ActionScriptVoid_Params, 0, sizeof(ActionScriptVoid_Params));

	if (!uFnActionScriptVoid)
	{
		return;
	}
	memcpy_s(&ActionScriptVoid_Params.Path, sizeof(ActionScriptVoid_Params.Path), &Path, sizeof(Path));

	uint16_t nativeIndex = uFnActionScriptVoid->iNative;
	uFnActionScriptVoid->iNative = 0;
	this->ProcessEvent(uFnActionScriptVoid, &ActionScriptVoid_Params, nullptr);
	uFnActionScriptVoid->iNative = nativeIndex;
}

// Function GFxUI.GFxMovie.UserTick
// [0x00020800] (FUNC_Event | FUNC_Public)
// Parameter Info:

void UGFxMovie::eventUserTick()
{
	static UFunction* uFnUserTick = nullptr;

	if (!uFnUserTick)
	{
		uFnUserTick = UFunction::FindFunction("Function GFxUI.GFxMovie.UserTick");
	}

	UGFxMovie_eventUserTick_Params UserTick_Params;
	memset(&UserTick_Params, 0, sizeof(UserTick_Params));

	if (!uFnUserTick)
	{
		return;
	}

	this->ProcessEvent(uFnUserTick, &UserTick_Params, nullptr);
}

// Function GFxUI.GFxMovie.SetExternalInterface
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class UObject*                 H                              (CPF_Parm)

void UGFxMovie::SetExternalInterface(class UObject* H)
{
	static UFunction* uFnSetExternalInterface = nullptr;

	if (!uFnSetExternalInterface)
	{
		uFnSetExternalInterface = UFunction::FindFunction("Function GFxUI.GFxMovie.SetExternalInterface");
	}

	UGFxMovie_execSetExternalInterface_Params SetExternalInterface_Params;
	memset(&SetExternalInterface_Params, 0, sizeof(SetExternalInterface_Params));

	if (!uFnSetExternalInterface)
	{
		return;
	}
	SetExternalInterface_Params.H = H;

	this->ProcessEvent(uFnSetExternalInterface, &SetExternalInterface_Params, nullptr);
}

// Function GFxUI.GFxMovie.SetFsCmdHandler
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class UGFxFSCmdHandler*        H                              (CPF_Parm)

void UGFxMovie::SetFsCmdHandler(class UGFxFSCmdHandler* H)
{
	static UFunction* uFnSetFsCmdHandler = nullptr;

	if (!uFnSetFsCmdHandler)
	{
		uFnSetFsCmdHandler = UFunction::FindFunction("Function GFxUI.GFxMovie.SetFsCmdHandler");
	}

	UGFxMovie_execSetFsCmdHandler_Params SetFsCmdHandler_Params;
	memset(&SetFsCmdHandler_Params, 0, sizeof(SetFsCmdHandler_Params));

	if (!uFnSetFsCmdHandler)
	{
		return;
	}
	SetFsCmdHandler_Params.H = H;

	this->ProcessEvent(uFnSetFsCmdHandler, &SetFsCmdHandler_Params, nullptr);
}

// Function GFxUI.GFxMovie.SetVariableObject
// [0x00020400] (FUNC_Native | FUNC_Public)
// Parameter Info:
// class FString                  Path                           (CPF_Parm | CPF_NeedCtorLink)
// class UGFxValue*               Value                          (CPF_Parm)

void UGFxMovie::SetVariableObject(const class FString& Path, class UGFxValue* Value)
{
	static UFunction* uFnSetVariableObject = nullptr;

	if (!uFnSetVariableObject)
	{
		uFnSetVariableObject = UFunction::FindFunction("Function GFxUI.GFxMovie.SetVariableObject");
	}

	UGFxMovie_execSetVariableObject_Params SetVariableObject_Params;
	memset(&SetVariableObject_Params, 0, sizeof(SetVariableObject_Params));

	if (!uFnSetVariableObject)
	{
		return;
	}
	memcpy_s(&SetVariableObject_Params.Path, sizeof(SetVariableObject_Params.Path), &Path, sizeof(Path));
	SetVariableObject_Params.Value = Value;

	uint16_t nativeIndex = uFnSetVariableObject->iNative;
	uFnSetVariableObject->iNative = 0;
	this->ProcessEvent(uFnSetVariableObject, &SetVariableObject_Params, nullptr);
	uFnSetVariableObject->iNative = nativeIndex;
}

// Function GFxUI.GFxMovie.GetVariableObject
// [0x00024400] (FUNC_Native | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// class UGFxValue*               ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FString                  Path                           (CPF_Parm | CPF_NeedCtorLink)
// class UClass*                  Type                           (CPF_OptionalParm | CPF_Parm)

class UGFxValue* UGFxMovie::GetVariableObject(const class FString& Path, class UClass* optionalType)
{
	static UFunction* uFnGetVariableObject = nullptr;

	if (!uFnGetVariableObject)
	{
		uFnGetVariableObject = UFunction::FindFunction("Function GFxUI.GFxMovie.GetVariableObject");
	}

	UGFxMovie_execGetVariableObject_Params GetVariableObject_Params;
	memset(&GetVariableObject_Params, 0, sizeof(GetVariableObject_Params));

	if (!uFnGetVariableObject)
	{
		return GetVariableObject_Params.ReturnValue;
	}
	memcpy_s(&GetVariableObject_Params.Path, sizeof(GetVariableObject_Params.Path), &Path, sizeof(Path));
	GetVariableObject_Params.Type = optionalType;

	uint16_t nativeIndex = uFnGetVariableObject->iNative;
	uFnGetVariableObject->iNative = 0;
	this->ProcessEvent(uFnGetVariableObject, &GetVariableObject_Params, nullptr);
	uFnGetVariableObject->iNative = nativeIndex;

	return GetVariableObject_Params.ReturnValue;
}

// Function GFxUI.GFxMovie.CreateArray
// [0x00020400] (FUNC_Native | FUNC_Public)
// Parameter Info:
// class UGFxValue*               ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

class UGFxValue* UGFxMovie::CreateArray()
{
	static UFunction* uFnCreateArray = nullptr;

	if (!uFnCreateArray)
	{
		uFnCreateArray = UFunction::FindFunction("Function GFxUI.GFxMovie.CreateArray");
	}

	UGFxMovie_execCreateArray_Params CreateArray_Params;
	memset(&CreateArray_Params, 0, sizeof(CreateArray_Params));

	if (!uFnCreateArray)
	{
		return CreateArray_Params.ReturnValue;
	}

	uint16_t nativeIndex = uFnCreateArray->iNative;
	uFnCreateArray->iNative = 0;
	this->ProcessEvent(uFnCreateArray, &CreateArray_Params, nullptr);
	uFnCreateArray->iNative = nativeIndex;

	return CreateArray_Params.ReturnValue;
}

// Function GFxUI.GFxMovie.CreateObject
// [0x00024400] (FUNC_Native | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// class UGFxValue*               ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FString                  ASClass                        (CPF_Parm | CPF_NeedCtorLink)
// class UClass*                  Type                           (CPF_OptionalParm | CPF_Parm)

class UGFxValue* UGFxMovie::CreateObject(const class FString& ASClass, class UClass* optionalType)
{
	static UFunction* uFnCreateObject = nullptr;

	if (!uFnCreateObject)
	{
		uFnCreateObject = UFunction::FindFunction("Function GFxUI.GFxMovie.CreateObject");
	}

	UGFxMovie_execCreateObject_Params CreateObject_Params;
	memset(&CreateObject_Params, 0, sizeof(CreateObject_Params));

	if (!uFnCreateObject)
	{
		return CreateObject_Params.ReturnValue;
	}
	memcpy_s(&CreateObject_Params.ASClass, sizeof(CreateObject_Params.ASClass), &ASClass, sizeof(ASClass));
	CreateObject_Params.Type = optionalType;

	uint16_t nativeIndex = uFnCreateObject->iNative;
	uFnCreateObject->iNative = 0;
	this->ProcessEvent(uFnCreateObject, &CreateObject_Params, nullptr);
	uFnCreateObject->iNative = nativeIndex;

	return CreateObject_Params.ReturnValue;
}

// Function GFxUI.GFxMovie.SetVariableStringArray
// [0x00020400] (FUNC_Native | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FString                  Path                           (CPF_Parm | CPF_NeedCtorLink)
// int32_t                        Index                          (CPF_Parm)
// class TArray<class FString>    Arg                            (CPF_Parm | CPF_NeedCtorLink)

bool UGFxMovie::SetVariableStringArray(const class FString& Path, int32_t Index, const class TArray<class FString>& Arg)
{
	static UFunction* uFnSetVariableStringArray = nullptr;

	if (!uFnSetVariableStringArray)
	{
		uFnSetVariableStringArray = UFunction::FindFunction("Function GFxUI.GFxMovie.SetVariableStringArray");
	}

	UGFxMovie_execSetVariableStringArray_Params SetVariableStringArray_Params;
	memset(&SetVariableStringArray_Params, 0, sizeof(SetVariableStringArray_Params));

	if (!uFnSetVariableStringArray)
	{
		return SetVariableStringArray_Params.ReturnValue;
	}
	memcpy_s(&SetVariableStringArray_Params.Path, sizeof(SetVariableStringArray_Params.Path), &Path, sizeof(Path));
	SetVariableStringArray_Params.Index = Index;
	memcpy_s(&SetVariableStringArray_Params.Arg, sizeof(SetVariableStringArray_Params.Arg), &Arg, sizeof(Arg));

	uint16_t nativeIndex = uFnSetVariableStringArray->iNative;
	uFnSetVariableStringArray->iNative = 0;
	this->ProcessEvent(uFnSetVariableStringArray, &SetVariableStringArray_Params, nullptr);
	uFnSetVariableStringArray->iNative = nativeIndex;

	return SetVariableStringArray_Params.ReturnValue;
}

// Function GFxUI.GFxMovie.SetVariableFloatArray
// [0x00020400] (FUNC_Native | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FString                  Path                           (CPF_Parm | CPF_NeedCtorLink)
// int32_t                        Index                          (CPF_Parm)
// class TArray<float>            Arg                            (CPF_Parm | CPF_NeedCtorLink)

bool UGFxMovie::SetVariableFloatArray(const class FString& Path, int32_t Index, const class TArray<float>& Arg)
{
	static UFunction* uFnSetVariableFloatArray = nullptr;

	if (!uFnSetVariableFloatArray)
	{
		uFnSetVariableFloatArray = UFunction::FindFunction("Function GFxUI.GFxMovie.SetVariableFloatArray");
	}

	UGFxMovie_execSetVariableFloatArray_Params SetVariableFloatArray_Params;
	memset(&SetVariableFloatArray_Params, 0, sizeof(SetVariableFloatArray_Params));

	if (!uFnSetVariableFloatArray)
	{
		return SetVariableFloatArray_Params.ReturnValue;
	}
	memcpy_s(&SetVariableFloatArray_Params.Path, sizeof(SetVariableFloatArray_Params.Path), &Path, sizeof(Path));
	SetVariableFloatArray_Params.Index = Index;
	memcpy_s(&SetVariableFloatArray_Params.Arg, sizeof(SetVariableFloatArray_Params.Arg), &Arg, sizeof(Arg));

	uint16_t nativeIndex = uFnSetVariableFloatArray->iNative;
	uFnSetVariableFloatArray->iNative = 0;
	this->ProcessEvent(uFnSetVariableFloatArray, &SetVariableFloatArray_Params, nullptr);
	uFnSetVariableFloatArray->iNative = nativeIndex;

	return SetVariableFloatArray_Params.ReturnValue;
}

// Function GFxUI.GFxMovie.SetVariableIntArray
// [0x00020400] (FUNC_Native | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FString                  Path                           (CPF_Parm | CPF_NeedCtorLink)
// int32_t                        Index                          (CPF_Parm)
// class TArray<int32_t>          Arg                            (CPF_Parm | CPF_NeedCtorLink)

bool UGFxMovie::SetVariableIntArray(const class FString& Path, int32_t Index, const class TArray<int32_t>& Arg)
{
	static UFunction* uFnSetVariableIntArray = nullptr;

	if (!uFnSetVariableIntArray)
	{
		uFnSetVariableIntArray = UFunction::FindFunction("Function GFxUI.GFxMovie.SetVariableIntArray");
	}

	UGFxMovie_execSetVariableIntArray_Params SetVariableIntArray_Params;
	memset(&SetVariableIntArray_Params, 0, sizeof(SetVariableIntArray_Params));

	if (!uFnSetVariableIntArray)
	{
		return SetVariableIntArray_Params.ReturnValue;
	}
	memcpy_s(&SetVariableIntArray_Params.Path, sizeof(SetVariableIntArray_Params.Path), &Path, sizeof(Path));
	SetVariableIntArray_Params.Index = Index;
	memcpy_s(&SetVariableIntArray_Params.Arg, sizeof(SetVariableIntArray_Params.Arg), &Arg, sizeof(Arg));

	uint16_t nativeIndex = uFnSetVariableIntArray->iNative;
	uFnSetVariableIntArray->iNative = 0;
	this->ProcessEvent(uFnSetVariableIntArray, &SetVariableIntArray_Params, nullptr);
	uFnSetVariableIntArray->iNative = nativeIndex;

	return SetVariableIntArray_Params.ReturnValue;
}

// Function GFxUI.GFxMovie.SetVariableArray
// [0x00020400] (FUNC_Native | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FString                  Path                           (CPF_Parm | CPF_NeedCtorLink)
// int32_t                        Index                          (CPF_Parm)
// class TArray<struct FASValue>  Arg                            (CPF_Parm | CPF_NeedCtorLink)

bool UGFxMovie::SetVariableArray(const class FString& Path, int32_t Index, const class TArray<struct FASValue>& Arg)
{
	static UFunction* uFnSetVariableArray = nullptr;

	if (!uFnSetVariableArray)
	{
		uFnSetVariableArray = UFunction::FindFunction("Function GFxUI.GFxMovie.SetVariableArray");
	}

	UGFxMovie_execSetVariableArray_Params SetVariableArray_Params;
	memset(&SetVariableArray_Params, 0, sizeof(SetVariableArray_Params));

	if (!uFnSetVariableArray)
	{
		return SetVariableArray_Params.ReturnValue;
	}
	memcpy_s(&SetVariableArray_Params.Path, sizeof(SetVariableArray_Params.Path), &Path, sizeof(Path));
	SetVariableArray_Params.Index = Index;
	memcpy_s(&SetVariableArray_Params.Arg, sizeof(SetVariableArray_Params.Arg), &Arg, sizeof(Arg));

	uint16_t nativeIndex = uFnSetVariableArray->iNative;
	uFnSetVariableArray->iNative = 0;
	this->ProcessEvent(uFnSetVariableArray, &SetVariableArray_Params, nullptr);
	uFnSetVariableArray->iNative = nativeIndex;

	return SetVariableArray_Params.ReturnValue;
}

// Function GFxUI.GFxMovie.GetVariableStringArray
// [0x00420400] (FUNC_Native | FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FString                  Path                           (CPF_Parm | CPF_NeedCtorLink)
// int32_t                        Index                          (CPF_Parm)
// class TArray<class FString>    Arg                            (CPF_Parm | CPF_OutParm | CPF_NeedCtorLink)

bool UGFxMovie::GetVariableStringArray(const class FString& Path, int32_t Index, class TArray<class FString>& outArg)
{
	static UFunction* uFnGetVariableStringArray = nullptr;

	if (!uFnGetVariableStringArray)
	{
		uFnGetVariableStringArray = UFunction::FindFunction("Function GFxUI.GFxMovie.GetVariableStringArray");
	}

	UGFxMovie_execGetVariableStringArray_Params GetVariableStringArray_Params;
	memset(&GetVariableStringArray_Params, 0, sizeof(GetVariableStringArray_Params));

	if (!uFnGetVariableStringArray)
	{
		return GetVariableStringArray_Params.ReturnValue;
	}
	memcpy_s(&GetVariableStringArray_Params.Path, sizeof(GetVariableStringArray_Params.Path), &Path, sizeof(Path));
	GetVariableStringArray_Params.Index = Index;
	memcpy_s(&GetVariableStringArray_Params.Arg, sizeof(GetVariableStringArray_Params.Arg), &outArg, sizeof(outArg));

	uint16_t nativeIndex = uFnGetVariableStringArray->iNative;
	uFnGetVariableStringArray->iNative = 0;
	this->ProcessEvent(uFnGetVariableStringArray, &GetVariableStringArray_Params, nullptr);
	uFnGetVariableStringArray->iNative = nativeIndex;

	memcpy_s(&outArg, sizeof(outArg), &GetVariableStringArray_Params.Arg, sizeof(GetVariableStringArray_Params.Arg));

	return GetVariableStringArray_Params.ReturnValue;
}

// Function GFxUI.GFxMovie.GetVariableFloatArray
// [0x00420400] (FUNC_Native | FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FString                  Path                           (CPF_Parm | CPF_NeedCtorLink)
// int32_t                        Index                          (CPF_Parm)
// class TArray<float>            Arg                            (CPF_Parm | CPF_OutParm | CPF_NeedCtorLink)

bool UGFxMovie::GetVariableFloatArray(const class FString& Path, int32_t Index, class TArray<float>& outArg)
{
	static UFunction* uFnGetVariableFloatArray = nullptr;

	if (!uFnGetVariableFloatArray)
	{
		uFnGetVariableFloatArray = UFunction::FindFunction("Function GFxUI.GFxMovie.GetVariableFloatArray");
	}

	UGFxMovie_execGetVariableFloatArray_Params GetVariableFloatArray_Params;
	memset(&GetVariableFloatArray_Params, 0, sizeof(GetVariableFloatArray_Params));

	if (!uFnGetVariableFloatArray)
	{
		return GetVariableFloatArray_Params.ReturnValue;
	}
	memcpy_s(&GetVariableFloatArray_Params.Path, sizeof(GetVariableFloatArray_Params.Path), &Path, sizeof(Path));
	GetVariableFloatArray_Params.Index = Index;
	memcpy_s(&GetVariableFloatArray_Params.Arg, sizeof(GetVariableFloatArray_Params.Arg), &outArg, sizeof(outArg));

	uint16_t nativeIndex = uFnGetVariableFloatArray->iNative;
	uFnGetVariableFloatArray->iNative = 0;
	this->ProcessEvent(uFnGetVariableFloatArray, &GetVariableFloatArray_Params, nullptr);
	uFnGetVariableFloatArray->iNative = nativeIndex;

	memcpy_s(&outArg, sizeof(outArg), &GetVariableFloatArray_Params.Arg, sizeof(GetVariableFloatArray_Params.Arg));

	return GetVariableFloatArray_Params.ReturnValue;
}

// Function GFxUI.GFxMovie.GetVariableIntArray
// [0x00420400] (FUNC_Native | FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FString                  Path                           (CPF_Parm | CPF_NeedCtorLink)
// int32_t                        Index                          (CPF_Parm)
// class TArray<int32_t>          Arg                            (CPF_Parm | CPF_OutParm | CPF_NeedCtorLink)

bool UGFxMovie::GetVariableIntArray(const class FString& Path, int32_t Index, class TArray<int32_t>& outArg)
{
	static UFunction* uFnGetVariableIntArray = nullptr;

	if (!uFnGetVariableIntArray)
	{
		uFnGetVariableIntArray = UFunction::FindFunction("Function GFxUI.GFxMovie.GetVariableIntArray");
	}

	UGFxMovie_execGetVariableIntArray_Params GetVariableIntArray_Params;
	memset(&GetVariableIntArray_Params, 0, sizeof(GetVariableIntArray_Params));

	if (!uFnGetVariableIntArray)
	{
		return GetVariableIntArray_Params.ReturnValue;
	}
	memcpy_s(&GetVariableIntArray_Params.Path, sizeof(GetVariableIntArray_Params.Path), &Path, sizeof(Path));
	GetVariableIntArray_Params.Index = Index;
	memcpy_s(&GetVariableIntArray_Params.Arg, sizeof(GetVariableIntArray_Params.Arg), &outArg, sizeof(outArg));

	uint16_t nativeIndex = uFnGetVariableIntArray->iNative;
	uFnGetVariableIntArray->iNative = 0;
	this->ProcessEvent(uFnGetVariableIntArray, &GetVariableIntArray_Params, nullptr);
	uFnGetVariableIntArray->iNative = nativeIndex;

	memcpy_s(&outArg, sizeof(outArg), &GetVariableIntArray_Params.Arg, sizeof(GetVariableIntArray_Params.Arg));

	return GetVariableIntArray_Params.ReturnValue;
}

// Function GFxUI.GFxMovie.GetVariableArray
// [0x00420400] (FUNC_Native | FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FString                  Path                           (CPF_Parm | CPF_NeedCtorLink)
// int32_t                        Index                          (CPF_Parm)
// class TArray<struct FASValue>  Arg                            (CPF_Parm | CPF_OutParm | CPF_NeedCtorLink)

bool UGFxMovie::GetVariableArray(const class FString& Path, int32_t Index, class TArray<struct FASValue>& outArg)
{
	static UFunction* uFnGetVariableArray = nullptr;

	if (!uFnGetVariableArray)
	{
		uFnGetVariableArray = UFunction::FindFunction("Function GFxUI.GFxMovie.GetVariableArray");
	}

	UGFxMovie_execGetVariableArray_Params GetVariableArray_Params;
	memset(&GetVariableArray_Params, 0, sizeof(GetVariableArray_Params));

	if (!uFnGetVariableArray)
	{
		return GetVariableArray_Params.ReturnValue;
	}
	memcpy_s(&GetVariableArray_Params.Path, sizeof(GetVariableArray_Params.Path), &Path, sizeof(Path));
	GetVariableArray_Params.Index = Index;
	memcpy_s(&GetVariableArray_Params.Arg, sizeof(GetVariableArray_Params.Arg), &outArg, sizeof(outArg));

	uint16_t nativeIndex = uFnGetVariableArray->iNative;
	uFnGetVariableArray->iNative = 0;
	this->ProcessEvent(uFnGetVariableArray, &GetVariableArray_Params, nullptr);
	uFnGetVariableArray->iNative = nativeIndex;

	memcpy_s(&outArg, sizeof(outArg), &GetVariableArray_Params.Arg, sizeof(GetVariableArray_Params.Arg));

	return GetVariableArray_Params.ReturnValue;
}

// Function GFxUI.GFxMovie.SetVariableString
// [0x00020400] (FUNC_Native | FUNC_Public)
// Parameter Info:
// class FString                  Path                           (CPF_Parm | CPF_NeedCtorLink)
// class FString                  S                              (CPF_Parm | CPF_NeedCtorLink)

void UGFxMovie::SetVariableString(const class FString& Path, const class FString& S)
{
	static UFunction* uFnSetVariableString = nullptr;

	if (!uFnSetVariableString)
	{
		uFnSetVariableString = UFunction::FindFunction("Function GFxUI.GFxMovie.SetVariableString");
	}

	UGFxMovie_execSetVariableString_Params SetVariableString_Params;
	memset(&SetVariableString_Params, 0, sizeof(SetVariableString_Params));

	if (!uFnSetVariableString)
	{
		return;
	}
	memcpy_s(&SetVariableString_Params.Path, sizeof(SetVariableString_Params.Path), &Path, sizeof(Path));
	memcpy_s(&SetVariableString_Params.S, sizeof(SetVariableString_Params.S), &S, sizeof(S));

	uint16_t nativeIndex = uFnSetVariableString->iNative;
	uFnSetVariableString->iNative = 0;
	this->ProcessEvent(uFnSetVariableString, &SetVariableString_Params, nullptr);
	uFnSetVariableString->iNative = nativeIndex;
}

// Function GFxUI.GFxMovie.SetVariableNumber
// [0x00020400] (FUNC_Native | FUNC_Public)
// Parameter Info:
// class FString                  Path                           (CPF_Parm | CPF_NeedCtorLink)
// float                          F                              (CPF_Parm)

void UGFxMovie::SetVariableNumber(const class FString& Path, float F)
{
	static UFunction* uFnSetVariableNumber = nullptr;

	if (!uFnSetVariableNumber)
	{
		uFnSetVariableNumber = UFunction::FindFunction("Function GFxUI.GFxMovie.SetVariableNumber");
	}

	UGFxMovie_execSetVariableNumber_Params SetVariableNumber_Params;
	memset(&SetVariableNumber_Params, 0, sizeof(SetVariableNumber_Params));

	if (!uFnSetVariableNumber)
	{
		return;
	}
	memcpy_s(&SetVariableNumber_Params.Path, sizeof(SetVariableNumber_Params.Path), &Path, sizeof(Path));
	SetVariableNumber_Params.F = F;

	uint16_t nativeIndex = uFnSetVariableNumber->iNative;
	uFnSetVariableNumber->iNative = 0;
	this->ProcessEvent(uFnSetVariableNumber, &SetVariableNumber_Params, nullptr);
	uFnSetVariableNumber->iNative = nativeIndex;
}

// Function GFxUI.GFxMovie.SetVariableBool
// [0x00020400] (FUNC_Native | FUNC_Public)
// Parameter Info:
// class FString                  Path                           (CPF_Parm | CPF_NeedCtorLink)
// uint32_t                       B                              (CPF_Parm)

void UGFxMovie::SetVariableBool(const class FString& Path, bool B)
{
	static UFunction* uFnSetVariableBool = nullptr;

	if (!uFnSetVariableBool)
	{
		uFnSetVariableBool = UFunction::FindFunction("Function GFxUI.GFxMovie.SetVariableBool");
	}

	UGFxMovie_execSetVariableBool_Params SetVariableBool_Params;
	memset(&SetVariableBool_Params, 0, sizeof(SetVariableBool_Params));

	if (!uFnSetVariableBool)
	{
		return;
	}
	memcpy_s(&SetVariableBool_Params.Path, sizeof(SetVariableBool_Params.Path), &Path, sizeof(Path));
	SetVariableBool_Params.B = B;

	uint16_t nativeIndex = uFnSetVariableBool->iNative;
	uFnSetVariableBool->iNative = 0;
	this->ProcessEvent(uFnSetVariableBool, &SetVariableBool_Params, nullptr);
	uFnSetVariableBool->iNative = nativeIndex;
}

// Function GFxUI.GFxMovie.SetVariable
// [0x00020400] (FUNC_Native | FUNC_Public)
// Parameter Info:
// class FString                  Path                           (CPF_Parm | CPF_NeedCtorLink)
// struct FASValue                Arg                            (CPF_Parm | CPF_NeedCtorLink)

void UGFxMovie::SetVariable(const class FString& Path, const struct FASValue& Arg)
{
	static UFunction* uFnSetVariable = nullptr;

	if (!uFnSetVariable)
	{
		uFnSetVariable = UFunction::FindFunction("Function GFxUI.GFxMovie.SetVariable");
	}

	UGFxMovie_execSetVariable_Params SetVariable_Params;
	memset(&SetVariable_Params, 0, sizeof(SetVariable_Params));

	if (!uFnSetVariable)
	{
		return;
	}
	memcpy_s(&SetVariable_Params.Path, sizeof(SetVariable_Params.Path), &Path, sizeof(Path));
	memcpy_s(&SetVariable_Params.Arg, sizeof(SetVariable_Params.Arg), &Arg, sizeof(Arg));

	uint16_t nativeIndex = uFnSetVariable->iNative;
	uFnSetVariable->iNative = 0;
	this->ProcessEvent(uFnSetVariable, &SetVariable_Params, nullptr);
	uFnSetVariable->iNative = nativeIndex;
}

// Function GFxUI.GFxMovie.GetVariableString
// [0x00020400] (FUNC_Native | FUNC_Public)
// Parameter Info:
// class FString                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
// class FString                  Path                           (CPF_Parm | CPF_NeedCtorLink)

class FString UGFxMovie::GetVariableString(const class FString& Path)
{
	static UFunction* uFnGetVariableString = nullptr;

	if (!uFnGetVariableString)
	{
		uFnGetVariableString = UFunction::FindFunction("Function GFxUI.GFxMovie.GetVariableString");
	}

	UGFxMovie_execGetVariableString_Params GetVariableString_Params;
	memset(&GetVariableString_Params, 0, sizeof(GetVariableString_Params));

	if (!uFnGetVariableString)
	{
		return GetVariableString_Params.ReturnValue;
	}
	memcpy_s(&GetVariableString_Params.Path, sizeof(GetVariableString_Params.Path), &Path, sizeof(Path));

	uint16_t nativeIndex = uFnGetVariableString->iNative;
	uFnGetVariableString->iNative = 0;
	this->ProcessEvent(uFnGetVariableString, &GetVariableString_Params, nullptr);
	uFnGetVariableString->iNative = nativeIndex;

	return GetVariableString_Params.ReturnValue;
}

// Function GFxUI.GFxMovie.GetVariableNumber
// [0x00020400] (FUNC_Native | FUNC_Public)
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FString                  Path                           (CPF_Parm | CPF_NeedCtorLink)

float UGFxMovie::GetVariableNumber(const class FString& Path)
{
	static UFunction* uFnGetVariableNumber = nullptr;

	if (!uFnGetVariableNumber)
	{
		uFnGetVariableNumber = UFunction::FindFunction("Function GFxUI.GFxMovie.GetVariableNumber");
	}

	UGFxMovie_execGetVariableNumber_Params GetVariableNumber_Params;
	memset(&GetVariableNumber_Params, 0, sizeof(GetVariableNumber_Params));

	if (!uFnGetVariableNumber)
	{
		return GetVariableNumber_Params.ReturnValue;
	}
	memcpy_s(&GetVariableNumber_Params.Path, sizeof(GetVariableNumber_Params.Path), &Path, sizeof(Path));

	uint16_t nativeIndex = uFnGetVariableNumber->iNative;
	uFnGetVariableNumber->iNative = 0;
	this->ProcessEvent(uFnGetVariableNumber, &GetVariableNumber_Params, nullptr);
	uFnGetVariableNumber->iNative = nativeIndex;

	return GetVariableNumber_Params.ReturnValue;
}

// Function GFxUI.GFxMovie.GetVariableBool
// [0x00020400] (FUNC_Native | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FString                  Path                           (CPF_Parm | CPF_NeedCtorLink)

bool UGFxMovie::GetVariableBool(const class FString& Path)
{
	static UFunction* uFnGetVariableBool = nullptr;

	if (!uFnGetVariableBool)
	{
		uFnGetVariableBool = UFunction::FindFunction("Function GFxUI.GFxMovie.GetVariableBool");
	}

	UGFxMovie_execGetVariableBool_Params GetVariableBool_Params;
	memset(&GetVariableBool_Params, 0, sizeof(GetVariableBool_Params));

	if (!uFnGetVariableBool)
	{
		return GetVariableBool_Params.ReturnValue;
	}
	memcpy_s(&GetVariableBool_Params.Path, sizeof(GetVariableBool_Params.Path), &Path, sizeof(Path));

	uint16_t nativeIndex = uFnGetVariableBool->iNative;
	uFnGetVariableBool->iNative = 0;
	this->ProcessEvent(uFnGetVariableBool, &GetVariableBool_Params, nullptr);
	uFnGetVariableBool->iNative = nativeIndex;

	return GetVariableBool_Params.ReturnValue;
}

// Function GFxUI.GFxMovie.GetVariable
// [0x00020400] (FUNC_Native | FUNC_Public)
// Parameter Info:
// struct FASValue                ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
// class FString                  Path                           (CPF_Parm | CPF_NeedCtorLink)

struct FASValue UGFxMovie::GetVariable(const class FString& Path)
{
	static UFunction* uFnGetVariable = nullptr;

	if (!uFnGetVariable)
	{
		uFnGetVariable = UFunction::FindFunction("Function GFxUI.GFxMovie.GetVariable");
	}

	UGFxMovie_execGetVariable_Params GetVariable_Params;
	memset(&GetVariable_Params, 0, sizeof(GetVariable_Params));

	if (!uFnGetVariable)
	{
		return GetVariable_Params.ReturnValue;
	}
	memcpy_s(&GetVariable_Params.Path, sizeof(GetVariable_Params.Path), &Path, sizeof(Path));

	uint16_t nativeIndex = uFnGetVariable->iNative;
	uFnGetVariable->iNative = 0;
	this->ProcessEvent(uFnGetVariable, &GetVariable_Params, nullptr);
	uFnGetVariable->iNative = nativeIndex;

	return GetVariable_Params.ReturnValue;
}

// Function GFxUI.GFxMovie.PublishDataStoreValues
// [0x00020400] (FUNC_Native | FUNC_Public)
// Parameter Info:

void UGFxMovie::PublishDataStoreValues()
{
	static UFunction* uFnPublishDataStoreValues = nullptr;

	if (!uFnPublishDataStoreValues)
	{
		uFnPublishDataStoreValues = UFunction::FindFunction("Function GFxUI.GFxMovie.PublishDataStoreValues");
	}

	UGFxMovie_execPublishDataStoreValues_Params PublishDataStoreValues_Params;
	memset(&PublishDataStoreValues_Params, 0, sizeof(PublishDataStoreValues_Params));

	if (!uFnPublishDataStoreValues)
	{
		return;
	}

	uint16_t nativeIndex = uFnPublishDataStoreValues->iNative;
	uFnPublishDataStoreValues->iNative = 0;
	this->ProcessEvent(uFnPublishDataStoreValues, &PublishDataStoreValues_Params, nullptr);
	uFnPublishDataStoreValues->iNative = nativeIndex;
}

// Function GFxUI.GFxMovie.RefreshDataStoreBindings
// [0x00020400] (FUNC_Native | FUNC_Public)
// Parameter Info:

void UGFxMovie::RefreshDataStoreBindings()
{
	static UFunction* uFnRefreshDataStoreBindings = nullptr;

	if (!uFnRefreshDataStoreBindings)
	{
		uFnRefreshDataStoreBindings = UFunction::FindFunction("Function GFxUI.GFxMovie.RefreshDataStoreBindings");
	}

	UGFxMovie_execRefreshDataStoreBindings_Params RefreshDataStoreBindings_Params;
	memset(&RefreshDataStoreBindings_Params, 0, sizeof(RefreshDataStoreBindings_Params));

	if (!uFnRefreshDataStoreBindings)
	{
		return;
	}

	uint16_t nativeIndex = uFnRefreshDataStoreBindings->iNative;
	uFnRefreshDataStoreBindings->iNative = 0;
	this->ProcessEvent(uFnRefreshDataStoreBindings, &RefreshDataStoreBindings_Params, nullptr);
	uFnRefreshDataStoreBindings->iNative = nativeIndex;
}

// Function GFxUI.GFxMovie.Invoke
// [0x00020400] (FUNC_Native | FUNC_Public)
// Parameter Info:
// struct FASValue                ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
// class FString                  method                         (CPF_Parm | CPF_NeedCtorLink)
// class TArray<struct FASValue>  args                           (CPF_Parm | CPF_NeedCtorLink)

struct FASValue UGFxMovie::Invoke(const class FString& method, const class TArray<struct FASValue>& args)
{
	static UFunction* uFnInvoke = nullptr;

	if (!uFnInvoke)
	{
		uFnInvoke = UFunction::FindFunction("Function GFxUI.GFxMovie.Invoke");
	}

	UGFxMovie_execInvoke_Params Invoke_Params;
	memset(&Invoke_Params, 0, sizeof(Invoke_Params));

	if (!uFnInvoke)
	{
		return Invoke_Params.ReturnValue;
	}
	memcpy_s(&Invoke_Params.method, sizeof(Invoke_Params.method), &method, sizeof(method));
	memcpy_s(&Invoke_Params.args, sizeof(Invoke_Params.args), &args, sizeof(args));

	uint16_t nativeIndex = uFnInvoke->iNative;
	uFnInvoke->iNative = 0;
	this->ProcessEvent(uFnInvoke, &Invoke_Params, nullptr);
	uFnInvoke->iNative = nativeIndex;

	return Invoke_Params.ReturnValue;
}

// Function GFxUI.GFxMovie.SetTimingMode
// [0x00020400] (FUNC_Native | FUNC_Public)
// Parameter Info:
// EGFxTimingMode                 Mode                           (CPF_Parm)

void UGFxMovie::SetTimingMode(EGFxTimingMode Mode)
{
	static UFunction* uFnSetTimingMode = nullptr;

	if (!uFnSetTimingMode)
	{
		uFnSetTimingMode = UFunction::FindFunction("Function GFxUI.GFxMovie.SetTimingMode");
	}

	UGFxMovie_execSetTimingMode_Params SetTimingMode_Params;
	memset(&SetTimingMode_Params, 0, sizeof(SetTimingMode_Params));

	if (!uFnSetTimingMode)
	{
		return;
	}
	SetTimingMode_Params.Mode = static_cast<uint8_t>(Mode);

	uint16_t nativeIndex = uFnSetTimingMode->iNative;
	uFnSetTimingMode->iNative = 0;
	this->ProcessEvent(uFnSetTimingMode, &SetTimingMode_Params, nullptr);
	uFnSetTimingMode->iNative = nativeIndex;
}

// Function GFxUI.GFxMovie.Pause
// [0x00024400] (FUNC_Native | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// uint32_t                       pauseplay                      (CPF_OptionalParm | CPF_Parm)

void UGFxMovie::Pause(bool optionalPauseplay)
{
	static UFunction* uFnPause = nullptr;

	if (!uFnPause)
	{
		uFnPause = UFunction::FindFunction("Function GFxUI.GFxMovie.Pause");
	}

	UGFxMovie_execPause_Params Pause_Params;
	memset(&Pause_Params, 0, sizeof(Pause_Params));

	if (!uFnPause)
	{
		return;
	}
	Pause_Params.pauseplay = optionalPauseplay;

	uint16_t nativeIndex = uFnPause->iNative;
	uFnPause->iNative = 0;
	this->ProcessEvent(uFnPause, &Pause_Params, nullptr);
	uFnPause->iNative = nativeIndex;
}

// Function GFxUI.GFxMovie.Advance
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// float                          Time                           (CPF_Parm)

void UGFxMovie::Advance(float Time)
{
	static UFunction* uFnAdvance = nullptr;

	if (!uFnAdvance)
	{
		uFnAdvance = UFunction::FindFunction("Function GFxUI.GFxMovie.Advance");
	}

	UGFxMovie_execAdvance_Params Advance_Params;
	memset(&Advance_Params, 0, sizeof(Advance_Params));

	if (!uFnAdvance)
	{
		return;
	}
	Advance_Params.Time = Time;

	uint16_t nativeIndex = uFnAdvance->iNative;
	uFnAdvance->iNative = 0;
	this->ProcessEvent(uFnAdvance, &Advance_Params, nullptr);
	uFnAdvance->iNative = nativeIndex;
}

// Function GFxUI.GFxMovie.SetExternalTexture
// [0x00020400] (FUNC_Native | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FString                  Resource                       (CPF_Parm | CPF_NeedCtorLink)
// class UTexture*                Texture                        (CPF_Parm)

bool UGFxMovie::SetExternalTexture(const class FString& Resource, class UTexture* Texture)
{
	static UFunction* uFnSetExternalTexture = nullptr;

	if (!uFnSetExternalTexture)
	{
		uFnSetExternalTexture = UFunction::FindFunction("Function GFxUI.GFxMovie.SetExternalTexture");
	}

	UGFxMovie_execSetExternalTexture_Params SetExternalTexture_Params;
	memset(&SetExternalTexture_Params, 0, sizeof(SetExternalTexture_Params));

	if (!uFnSetExternalTexture)
	{
		return SetExternalTexture_Params.ReturnValue;
	}
	memcpy_s(&SetExternalTexture_Params.Resource, sizeof(SetExternalTexture_Params.Resource), &Resource, sizeof(Resource));
	SetExternalTexture_Params.Texture = Texture;

	uint16_t nativeIndex = uFnSetExternalTexture->iNative;
	uFnSetExternalTexture->iNative = 0;
	this->ProcessEvent(uFnSetExternalTexture, &SetExternalTexture_Params, nullptr);
	uFnSetExternalTexture->iNative = nativeIndex;

	return SetExternalTexture_Params.ReturnValue;
}

// Function GFxUI.GFxMovie.FlushPlayerInput
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// uint32_t                       capturekeysonly                (CPF_Parm)

void UGFxMovie::FlushPlayerInput(bool capturekeysonly)
{
	static UFunction* uFnFlushPlayerInput = nullptr;

	if (!uFnFlushPlayerInput)
	{
		uFnFlushPlayerInput = UFunction::FindFunction("Function GFxUI.GFxMovie.FlushPlayerInput");
	}

	UGFxMovie_execFlushPlayerInput_Params FlushPlayerInput_Params;
	memset(&FlushPlayerInput_Params, 0, sizeof(FlushPlayerInput_Params));

	if (!uFnFlushPlayerInput)
	{
		return;
	}
	FlushPlayerInput_Params.capturekeysonly = capturekeysonly;

	uint16_t nativeIndex = uFnFlushPlayerInput->iNative;
	uFnFlushPlayerInput->iNative = 0;
	this->ProcessEvent(uFnFlushPlayerInput, &FlushPlayerInput_Params, nullptr);
	uFnFlushPlayerInput->iNative = nativeIndex;
}

// Function GFxUI.GFxMovie.ClearFocusIgnoreKeys
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:

void UGFxMovie::ClearFocusIgnoreKeys()
{
	static UFunction* uFnClearFocusIgnoreKeys = nullptr;

	if (!uFnClearFocusIgnoreKeys)
	{
		uFnClearFocusIgnoreKeys = UFunction::FindFunction("Function GFxUI.GFxMovie.ClearFocusIgnoreKeys");
	}

	UGFxMovie_execClearFocusIgnoreKeys_Params ClearFocusIgnoreKeys_Params;
	memset(&ClearFocusIgnoreKeys_Params, 0, sizeof(ClearFocusIgnoreKeys_Params));

	if (!uFnClearFocusIgnoreKeys)
	{
		return;
	}

	uint16_t nativeIndex = uFnClearFocusIgnoreKeys->iNative;
	uFnClearFocusIgnoreKeys->iNative = 0;
	this->ProcessEvent(uFnClearFocusIgnoreKeys, &ClearFocusIgnoreKeys_Params, nullptr);
	uFnClearFocusIgnoreKeys->iNative = nativeIndex;
}

// Function GFxUI.GFxMovie.AddFocusIgnoreKey
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// class FName                    Key                            (CPF_Parm)

void UGFxMovie::AddFocusIgnoreKey(const class FName& Key)
{
	static UFunction* uFnAddFocusIgnoreKey = nullptr;

	if (!uFnAddFocusIgnoreKey)
	{
		uFnAddFocusIgnoreKey = UFunction::FindFunction("Function GFxUI.GFxMovie.AddFocusIgnoreKey");
	}

	UGFxMovie_execAddFocusIgnoreKey_Params AddFocusIgnoreKey_Params;
	memset(&AddFocusIgnoreKey_Params, 0, sizeof(AddFocusIgnoreKey_Params));

	if (!uFnAddFocusIgnoreKey)
	{
		return;
	}
	memcpy_s(&AddFocusIgnoreKey_Params.Key, sizeof(AddFocusIgnoreKey_Params.Key), &Key, sizeof(Key));

	uint16_t nativeIndex = uFnAddFocusIgnoreKey->iNative;
	uFnAddFocusIgnoreKey->iNative = 0;
	this->ProcessEvent(uFnAddFocusIgnoreKey, &AddFocusIgnoreKey_Params, nullptr);
	uFnAddFocusIgnoreKey->iNative = nativeIndex;
}

// Function GFxUI.GFxMovie.ClearCaptureKeys
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:

void UGFxMovie::ClearCaptureKeys()
{
	static UFunction* uFnClearCaptureKeys = nullptr;

	if (!uFnClearCaptureKeys)
	{
		uFnClearCaptureKeys = UFunction::FindFunction("Function GFxUI.GFxMovie.ClearCaptureKeys");
	}

	UGFxMovie_execClearCaptureKeys_Params ClearCaptureKeys_Params;
	memset(&ClearCaptureKeys_Params, 0, sizeof(ClearCaptureKeys_Params));

	if (!uFnClearCaptureKeys)
	{
		return;
	}

	uint16_t nativeIndex = uFnClearCaptureKeys->iNative;
	uFnClearCaptureKeys->iNative = 0;
	this->ProcessEvent(uFnClearCaptureKeys, &ClearCaptureKeys_Params, nullptr);
	uFnClearCaptureKeys->iNative = nativeIndex;
}

// Function GFxUI.GFxMovie.AddCaptureKey
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// class FName                    Key                            (CPF_Parm)

void UGFxMovie::AddCaptureKey(const class FName& Key)
{
	static UFunction* uFnAddCaptureKey = nullptr;

	if (!uFnAddCaptureKey)
	{
		uFnAddCaptureKey = UFunction::FindFunction("Function GFxUI.GFxMovie.AddCaptureKey");
	}

	UGFxMovie_execAddCaptureKey_Params AddCaptureKey_Params;
	memset(&AddCaptureKey_Params, 0, sizeof(AddCaptureKey_Params));

	if (!uFnAddCaptureKey)
	{
		return;
	}
	memcpy_s(&AddCaptureKey_Params.Key, sizeof(AddCaptureKey_Params.Key), &Key, sizeof(Key));

	uint16_t nativeIndex = uFnAddCaptureKey->iNative;
	uFnAddCaptureKey->iNative = 0;
	this->ProcessEvent(uFnAddCaptureKey, &AddCaptureKey_Params, nullptr);
	uFnAddCaptureKey->iNative = nativeIndex;
}

// Function GFxUI.GFxMovie.SetFocus
// [0x00024401] (FUNC_Final | FUNC_Native | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// uint32_t                       captureInput                   (CPF_Parm)
// uint32_t                       Focus                          (CPF_OptionalParm | CPF_Parm)

void UGFxMovie::SetFocus(bool captureInput, bool optionalFocus)
{
	static UFunction* uFnSetFocus = nullptr;

	if (!uFnSetFocus)
	{
		uFnSetFocus = UFunction::FindFunction("Function GFxUI.GFxMovie.SetFocus");
	}

	UGFxMovie_execSetFocus_Params SetFocus_Params;
	memset(&SetFocus_Params, 0, sizeof(SetFocus_Params));

	if (!uFnSetFocus)
	{
		return;
	}
	SetFocus_Params.captureInput = captureInput;
	SetFocus_Params.Focus = optionalFocus;

	uint16_t nativeIndex = uFnSetFocus->iNative;
	uFnSetFocus->iNative = 0;
	this->ProcessEvent(uFnSetFocus, &SetFocus_Params, nullptr);
	uFnSetFocus->iNative = nativeIndex;
}

// Function GFxUI.GFxMovie.SetSceneDPG
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// ESceneDepthPriorityGroup       NewDPG                         (CPF_Parm)

void UGFxMovie::SetSceneDPG(ESceneDepthPriorityGroup NewDPG)
{
	static UFunction* uFnSetSceneDPG = nullptr;

	if (!uFnSetSceneDPG)
	{
		uFnSetSceneDPG = UFunction::FindFunction("Function GFxUI.GFxMovie.SetSceneDPG");
	}

	UGFxMovie_execSetSceneDPG_Params SetSceneDPG_Params;
	memset(&SetSceneDPG_Params, 0, sizeof(SetSceneDPG_Params));

	if (!uFnSetSceneDPG)
	{
		return;
	}
	SetSceneDPG_Params.NewDPG = static_cast<uint8_t>(NewDPG);

	uint16_t nativeIndex = uFnSetSceneDPG->iNative;
	uFnSetSceneDPG->iNative = 0;
	this->ProcessEvent(uFnSetSceneDPG, &SetSceneDPG_Params, nullptr);
	uFnSetSceneDPG->iNative = nativeIndex;
}

// Function GFxUI.GFxMovie.SetPerspective3D
// [0x00420401] (FUNC_Final | FUNC_Native | FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// struct FMatrix                 matPersp                       (CPF_Const | CPF_Parm | CPF_OutParm)

void UGFxMovie::SetPerspective3D(struct FMatrix& outMatPersp)
{
	static UFunction* uFnSetPerspective3D = nullptr;

	if (!uFnSetPerspective3D)
	{
		uFnSetPerspective3D = UFunction::FindFunction("Function GFxUI.GFxMovie.SetPerspective3D");
	}

	UGFxMovie_execSetPerspective3D_Params SetPerspective3D_Params;
	memset(&SetPerspective3D_Params, 0, sizeof(SetPerspective3D_Params));

	if (!uFnSetPerspective3D)
	{
		return;
	}
	memcpy_s(&SetPerspective3D_Params.matPersp, sizeof(SetPerspective3D_Params.matPersp), &outMatPersp, sizeof(outMatPersp));

	uint16_t nativeIndex = uFnSetPerspective3D->iNative;
	uFnSetPerspective3D->iNative = 0;
	this->ProcessEvent(uFnSetPerspective3D, &SetPerspective3D_Params, nullptr);
	uFnSetPerspective3D->iNative = nativeIndex;

	memcpy_s(&outMatPersp, sizeof(outMatPersp), &SetPerspective3D_Params.matPersp, sizeof(SetPerspective3D_Params.matPersp));
}

// Function GFxUI.GFxMovie.SetView3D
// [0x00420401] (FUNC_Final | FUNC_Native | FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// struct FMatrix                 matView                        (CPF_Const | CPF_Parm | CPF_OutParm)

void UGFxMovie::SetView3D(struct FMatrix& outMatView)
{
	static UFunction* uFnSetView3D = nullptr;

	if (!uFnSetView3D)
	{
		uFnSetView3D = UFunction::FindFunction("Function GFxUI.GFxMovie.SetView3D");
	}

	UGFxMovie_execSetView3D_Params SetView3D_Params;
	memset(&SetView3D_Params, 0, sizeof(SetView3D_Params));

	if (!uFnSetView3D)
	{
		return;
	}
	memcpy_s(&SetView3D_Params.matView, sizeof(SetView3D_Params.matView), &outMatView, sizeof(outMatView));

	uint16_t nativeIndex = uFnSetView3D->iNative;
	uFnSetView3D->iNative = 0;
	this->ProcessEvent(uFnSetView3D, &SetView3D_Params, nullptr);
	uFnSetView3D->iNative = nativeIndex;

	memcpy_s(&outMatView, sizeof(outMatView), &SetView3D_Params.matView, sizeof(SetView3D_Params.matView));
}

// Function GFxUI.GFxMovie.GetVisibleFrameRect
// [0x00420401] (FUNC_Final | FUNC_Native | FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// float                          x0                             (CPF_Parm | CPF_OutParm)
// float                          y0                             (CPF_Parm | CPF_OutParm)
// float                          X1                             (CPF_Parm | CPF_OutParm)
// float                          Y1                             (CPF_Parm | CPF_OutParm)

void UGFxMovie::GetVisibleFrameRect(float& outX0, float& outY0, float& outX1, float& outY1)
{
	static UFunction* uFnGetVisibleFrameRect = nullptr;

	if (!uFnGetVisibleFrameRect)
	{
		uFnGetVisibleFrameRect = UFunction::FindFunction("Function GFxUI.GFxMovie.GetVisibleFrameRect");
	}

	UGFxMovie_execGetVisibleFrameRect_Params GetVisibleFrameRect_Params;
	memset(&GetVisibleFrameRect_Params, 0, sizeof(GetVisibleFrameRect_Params));

	if (!uFnGetVisibleFrameRect)
	{
		return;
	}
	GetVisibleFrameRect_Params.x0 = outX0;
	GetVisibleFrameRect_Params.y0 = outY0;
	GetVisibleFrameRect_Params.X1 = outX1;
	GetVisibleFrameRect_Params.Y1 = outY1;

	uint16_t nativeIndex = uFnGetVisibleFrameRect->iNative;
	uFnGetVisibleFrameRect->iNative = 0;
	this->ProcessEvent(uFnGetVisibleFrameRect, &GetVisibleFrameRect_Params, nullptr);
	uFnGetVisibleFrameRect->iNative = nativeIndex;

	outX0 = GetVisibleFrameRect_Params.x0;
	outY0 = GetVisibleFrameRect_Params.y0;
	outX1 = GetVisibleFrameRect_Params.X1;
	outY1 = GetVisibleFrameRect_Params.Y1;
}

// Function GFxUI.GFxMovie.SetAlignment
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// EGFxAlign                      A                              (CPF_Parm)

void UGFxMovie::SetAlignment(EGFxAlign A)
{
	static UFunction* uFnSetAlignment = nullptr;

	if (!uFnSetAlignment)
	{
		uFnSetAlignment = UFunction::FindFunction("Function GFxUI.GFxMovie.SetAlignment");
	}

	UGFxMovie_execSetAlignment_Params SetAlignment_Params;
	memset(&SetAlignment_Params, 0, sizeof(SetAlignment_Params));

	if (!uFnSetAlignment)
	{
		return;
	}
	SetAlignment_Params.A = static_cast<uint8_t>(A);

	uint16_t nativeIndex = uFnSetAlignment->iNative;
	uFnSetAlignment->iNative = 0;
	this->ProcessEvent(uFnSetAlignment, &SetAlignment_Params, nullptr);
	uFnSetAlignment->iNative = nativeIndex;
}

// Function GFxUI.GFxMovie.SetViewScaleMode
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// EGFxScaleMode                  sm                             (CPF_Parm)

void UGFxMovie::SetViewScaleMode(EGFxScaleMode sm)
{
	static UFunction* uFnSetViewScaleMode = nullptr;

	if (!uFnSetViewScaleMode)
	{
		uFnSetViewScaleMode = UFunction::FindFunction("Function GFxUI.GFxMovie.SetViewScaleMode");
	}

	UGFxMovie_execSetViewScaleMode_Params SetViewScaleMode_Params;
	memset(&SetViewScaleMode_Params, 0, sizeof(SetViewScaleMode_Params));

	if (!uFnSetViewScaleMode)
	{
		return;
	}
	SetViewScaleMode_Params.sm = static_cast<uint8_t>(sm);

	uint16_t nativeIndex = uFnSetViewScaleMode->iNative;
	uFnSetViewScaleMode->iNative = 0;
	this->ProcessEvent(uFnSetViewScaleMode, &SetViewScaleMode_Params, nullptr);
	uFnSetViewScaleMode->iNative = nativeIndex;
}

// Function GFxUI.GFxMovie.SetViewport
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// int32_t                        X                              (CPF_Parm)
// int32_t                        Y                              (CPF_Parm)
// int32_t                        Width                          (CPF_Parm)
// int32_t                        Height                         (CPF_Parm)

void UGFxMovie::SetViewport(int32_t X, int32_t Y, int32_t Width, int32_t Height)
{
	static UFunction* uFnSetViewport = nullptr;

	if (!uFnSetViewport)
	{
		uFnSetViewport = UFunction::FindFunction("Function GFxUI.GFxMovie.SetViewport");
	}

	UGFxMovie_execSetViewport_Params SetViewport_Params;
	memset(&SetViewport_Params, 0, sizeof(SetViewport_Params));

	if (!uFnSetViewport)
	{
		return;
	}
	SetViewport_Params.X = X;
	SetViewport_Params.Y = Y;
	SetViewport_Params.Width = Width;
	SetViewport_Params.Height = Height;

	uint16_t nativeIndex = uFnSetViewport->iNative;
	uFnSetViewport->iNative = 0;
	this->ProcessEvent(uFnSetViewport, &SetViewport_Params, nullptr);
	uFnSetViewport->iNative = nativeIndex;
}

// Function GFxUI.GFxMovie.GetGameViewportClient
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// class UGameViewportClient*     ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

class UGameViewportClient* UGFxMovie::GetGameViewportClient()
{
	static UFunction* uFnGetGameViewportClient = nullptr;

	if (!uFnGetGameViewportClient)
	{
		uFnGetGameViewportClient = UFunction::FindFunction("Function GFxUI.GFxMovie.GetGameViewportClient");
	}

	UGFxMovie_execGetGameViewportClient_Params GetGameViewportClient_Params;
	memset(&GetGameViewportClient_Params, 0, sizeof(GetGameViewportClient_Params));

	if (!uFnGetGameViewportClient)
	{
		return GetGameViewportClient_Params.ReturnValue;
	}

	uint16_t nativeIndex = uFnGetGameViewportClient->iNative;
	uFnGetGameViewportClient->iNative = 0;
	this->ProcessEvent(uFnGetGameViewportClient, &GetGameViewportClient_Params, nullptr);
	uFnGetGameViewportClient->iNative = nativeIndex;

	return GetGameViewportClient_Params.ReturnValue;
}

// Function GFxUI.GFxMovie.SetMovieInfo
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class UGFxMovieInfo*           Data                           (CPF_Parm)

void UGFxMovie::SetMovieInfo(class UGFxMovieInfo* Data)
{
	static UFunction* uFnSetMovieInfo = nullptr;

	if (!uFnSetMovieInfo)
	{
		uFnSetMovieInfo = UFunction::FindFunction("Function GFxUI.GFxMovie.SetMovieInfo");
	}

	UGFxMovie_execSetMovieInfo_Params SetMovieInfo_Params;
	memset(&SetMovieInfo_Params, 0, sizeof(SetMovieInfo_Params));

	if (!uFnSetMovieInfo)
	{
		return;
	}
	SetMovieInfo_Params.Data = Data;

	this->ProcessEvent(uFnSetMovieInfo, &SetMovieInfo_Params, nullptr);
}

// Function GFxUI.GFxMovie.OnClose
// [0x00020800] (FUNC_Event | FUNC_Public)
// Parameter Info:

void UGFxMovie::eventOnClose()
{
	static UFunction* uFnOnClose = nullptr;

	if (!uFnOnClose)
	{
		uFnOnClose = UFunction::FindFunction("Function GFxUI.GFxMovie.OnClose");
	}

	UGFxMovie_eventOnClose_Params OnClose_Params;
	memset(&OnClose_Params, 0, sizeof(OnClose_Params));

	if (!uFnOnClose)
	{
		return;
	}

	this->ProcessEvent(uFnOnClose, &OnClose_Params, nullptr);
}

// Function GFxUI.GFxMovie.Close
// [0x00024401] (FUNC_Final | FUNC_Native | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// uint32_t                       Unload                         (CPF_OptionalParm | CPF_Parm)

void UGFxMovie::Close(bool optionalUnload)
{
	static UFunction* uFnClose = nullptr;

	if (!uFnClose)
	{
		uFnClose = UFunction::FindFunction("Function GFxUI.GFxMovie.Close");
	}

	UGFxMovie_execClose_Params Close_Params;
	memset(&Close_Params, 0, sizeof(Close_Params));

	if (!uFnClose)
	{
		return;
	}
	Close_Params.Unload = optionalUnload;

	uint16_t nativeIndex = uFnClose->iNative;
	uFnClose->iNative = 0;
	this->ProcessEvent(uFnClose, &Close_Params, nullptr);
	uFnClose->iNative = nativeIndex;
}

// Function GFxUI.GFxMovie.Start
// [0x00024C00] (FUNC_Native | FUNC_Event | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// uint32_t                       StartPaused                    (CPF_OptionalParm | CPF_Parm)

bool UGFxMovie::eventStart(bool optionalStartPaused)
{
	static UFunction* uFnStart = nullptr;

	if (!uFnStart)
	{
		uFnStart = UFunction::FindFunction("Function GFxUI.GFxMovie.Start");
	}

	UGFxMovie_eventStart_Params Start_Params;
	memset(&Start_Params, 0, sizeof(Start_Params));

	if (!uFnStart)
	{
		return Start_Params.ReturnValue;
	}
	Start_Params.StartPaused = optionalStartPaused;

	uint16_t nativeIndex = uFnStart->iNative;
	uFnStart->iNative = 0;
	this->ProcessEvent(uFnStart, &Start_Params, nullptr);
	uFnStart->iNative = nativeIndex;

	return Start_Params.ReturnValue;
}

// Function GFxUI.GFxMovie.HandleInputKey
// [0x00124000] (FUNC_OptionalParm | FUNC_Public | FUNC_Delegate)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        ControllerId                   (CPF_Parm)
// class FName                    Key                            (CPF_Parm)
// EInputEvent                    EventType                      (CPF_Parm)
// float                          AmountDepressed                (CPF_Parm)
// uint32_t                       bGamepad                       (CPF_OptionalParm | CPF_Parm)

bool UGFxMovie::HandleInputKey(int32_t ControllerId, const class FName& Key, EInputEvent EventType, float AmountDepressed, bool optionalBGamepad)
{
	static UFunction* uFnHandleInputKey = nullptr;

	if (!uFnHandleInputKey)
	{
		uFnHandleInputKey = UFunction::FindFunction("Function GFxUI.GFxMovie.HandleInputKey");
	}

	UGFxMovie_execHandleInputKey_Params HandleInputKey_Params;
	memset(&HandleInputKey_Params, 0, sizeof(HandleInputKey_Params));

	if (!uFnHandleInputKey)
	{
		return HandleInputKey_Params.ReturnValue;
	}
	HandleInputKey_Params.ControllerId = ControllerId;
	memcpy_s(&HandleInputKey_Params.Key, sizeof(HandleInputKey_Params.Key), &Key, sizeof(Key));
	HandleInputKey_Params.EventType = static_cast<uint8_t>(EventType);
	HandleInputKey_Params.AmountDepressed = AmountDepressed;
	HandleInputKey_Params.bGamepad = optionalBGamepad;

	this->ProcessEvent(uFnHandleInputKey, &HandleInputKey_Params, nullptr);

	return HandleInputKey_Params.ReturnValue;
}

// Function GFxUI.GFxValue.ActionScriptSetFunctionOn
// [0x00080401] (FUNC_Final | FUNC_Native | FUNC_Protected)
// Parameter Info:
// class UGFxValue*               Target                         (CPF_Parm)
// class FString                  member                         (CPF_Parm | CPF_NeedCtorLink)

void UGFxValue::ActionScriptSetFunctionOn(class UGFxValue* Target, const class FString& member)
{
	static UFunction* uFnActionScriptSetFunctionOn = nullptr;

	if (!uFnActionScriptSetFunctionOn)
	{
		uFnActionScriptSetFunctionOn = UFunction::FindFunction("Function GFxUI.GFxValue.ActionScriptSetFunctionOn");
	}

	UGFxValue_execActionScriptSetFunctionOn_Params ActionScriptSetFunctionOn_Params;
	memset(&ActionScriptSetFunctionOn_Params, 0, sizeof(ActionScriptSetFunctionOn_Params));

	if (!uFnActionScriptSetFunctionOn)
	{
		return;
	}
	ActionScriptSetFunctionOn_Params.Target = Target;
	memcpy_s(&ActionScriptSetFunctionOn_Params.member, sizeof(ActionScriptSetFunctionOn_Params.member), &member, sizeof(member));

	uint16_t nativeIndex = uFnActionScriptSetFunctionOn->iNative;
	uFnActionScriptSetFunctionOn->iNative = 0;
	this->ProcessEvent(uFnActionScriptSetFunctionOn, &ActionScriptSetFunctionOn_Params, nullptr);
	uFnActionScriptSetFunctionOn->iNative = nativeIndex;
}

// Function GFxUI.GFxValue.ActionScriptSetFunction
// [0x00080401] (FUNC_Final | FUNC_Native | FUNC_Protected)
// Parameter Info:
// class FString                  member                         (CPF_Parm | CPF_NeedCtorLink)

void UGFxValue::ActionScriptSetFunction(const class FString& member)
{
	static UFunction* uFnActionScriptSetFunction = nullptr;

	if (!uFnActionScriptSetFunction)
	{
		uFnActionScriptSetFunction = UFunction::FindFunction("Function GFxUI.GFxValue.ActionScriptSetFunction");
	}

	UGFxValue_execActionScriptSetFunction_Params ActionScriptSetFunction_Params;
	memset(&ActionScriptSetFunction_Params, 0, sizeof(ActionScriptSetFunction_Params));

	if (!uFnActionScriptSetFunction)
	{
		return;
	}
	memcpy_s(&ActionScriptSetFunction_Params.member, sizeof(ActionScriptSetFunction_Params.member), &member, sizeof(member));

	uint16_t nativeIndex = uFnActionScriptSetFunction->iNative;
	uFnActionScriptSetFunction->iNative = 0;
	this->ProcessEvent(uFnActionScriptSetFunction, &ActionScriptSetFunction_Params, nullptr);
	uFnActionScriptSetFunction->iNative = nativeIndex;
}

// Function GFxUI.GFxValue.ActionScriptArray
// [0x00080401] (FUNC_Final | FUNC_Native | FUNC_Protected)
// Parameter Info:
// class TArray<class UGFxValue*> ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
// class FString                  Path                           (CPF_Parm | CPF_NeedCtorLink)

class TArray<class UGFxValue*> UGFxValue::ActionScriptArray(const class FString& Path)
{
	static UFunction* uFnActionScriptArray = nullptr;

	if (!uFnActionScriptArray)
	{
		uFnActionScriptArray = UFunction::FindFunction("Function GFxUI.GFxValue.ActionScriptArray");
	}

	UGFxValue_execActionScriptArray_Params ActionScriptArray_Params;
	memset(&ActionScriptArray_Params, 0, sizeof(ActionScriptArray_Params));

	if (!uFnActionScriptArray)
	{
		return ActionScriptArray_Params.ReturnValue;
	}
	memcpy_s(&ActionScriptArray_Params.Path, sizeof(ActionScriptArray_Params.Path), &Path, sizeof(Path));

	uint16_t nativeIndex = uFnActionScriptArray->iNative;
	uFnActionScriptArray->iNative = 0;
	this->ProcessEvent(uFnActionScriptArray, &ActionScriptArray_Params, nullptr);
	uFnActionScriptArray->iNative = nativeIndex;

	return ActionScriptArray_Params.ReturnValue;
}

// Function GFxUI.GFxValue.ActionScriptObject
// [0x00080401] (FUNC_Final | FUNC_Native | FUNC_Protected)
// Parameter Info:
// class UGFxValue*               ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FString                  Path                           (CPF_Parm | CPF_NeedCtorLink)

class UGFxValue* UGFxValue::ActionScriptObject(const class FString& Path)
{
	static UFunction* uFnActionScriptObject = nullptr;

	if (!uFnActionScriptObject)
	{
		uFnActionScriptObject = UFunction::FindFunction("Function GFxUI.GFxValue.ActionScriptObject");
	}

	UGFxValue_execActionScriptObject_Params ActionScriptObject_Params;
	memset(&ActionScriptObject_Params, 0, sizeof(ActionScriptObject_Params));

	if (!uFnActionScriptObject)
	{
		return ActionScriptObject_Params.ReturnValue;
	}
	memcpy_s(&ActionScriptObject_Params.Path, sizeof(ActionScriptObject_Params.Path), &Path, sizeof(Path));

	uint16_t nativeIndex = uFnActionScriptObject->iNative;
	uFnActionScriptObject->iNative = 0;
	this->ProcessEvent(uFnActionScriptObject, &ActionScriptObject_Params, nullptr);
	uFnActionScriptObject->iNative = nativeIndex;

	return ActionScriptObject_Params.ReturnValue;
}

// Function GFxUI.GFxValue.ActionScriptString
// [0x00080401] (FUNC_Final | FUNC_Native | FUNC_Protected)
// Parameter Info:
// class FString                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
// class FString                  method                         (CPF_Parm | CPF_NeedCtorLink)

class FString UGFxValue::ActionScriptString(const class FString& method)
{
	static UFunction* uFnActionScriptString = nullptr;

	if (!uFnActionScriptString)
	{
		uFnActionScriptString = UFunction::FindFunction("Function GFxUI.GFxValue.ActionScriptString");
	}

	UGFxValue_execActionScriptString_Params ActionScriptString_Params;
	memset(&ActionScriptString_Params, 0, sizeof(ActionScriptString_Params));

	if (!uFnActionScriptString)
	{
		return ActionScriptString_Params.ReturnValue;
	}
	memcpy_s(&ActionScriptString_Params.method, sizeof(ActionScriptString_Params.method), &method, sizeof(method));

	uint16_t nativeIndex = uFnActionScriptString->iNative;
	uFnActionScriptString->iNative = 0;
	this->ProcessEvent(uFnActionScriptString, &ActionScriptString_Params, nullptr);
	uFnActionScriptString->iNative = nativeIndex;

	return ActionScriptString_Params.ReturnValue;
}

// Function GFxUI.GFxValue.ActionScriptFloat
// [0x00080401] (FUNC_Final | FUNC_Native | FUNC_Protected)
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FString                  method                         (CPF_Parm | CPF_NeedCtorLink)

float UGFxValue::ActionScriptFloat(const class FString& method)
{
	static UFunction* uFnActionScriptFloat = nullptr;

	if (!uFnActionScriptFloat)
	{
		uFnActionScriptFloat = UFunction::FindFunction("Function GFxUI.GFxValue.ActionScriptFloat");
	}

	UGFxValue_execActionScriptFloat_Params ActionScriptFloat_Params;
	memset(&ActionScriptFloat_Params, 0, sizeof(ActionScriptFloat_Params));

	if (!uFnActionScriptFloat)
	{
		return ActionScriptFloat_Params.ReturnValue;
	}
	memcpy_s(&ActionScriptFloat_Params.method, sizeof(ActionScriptFloat_Params.method), &method, sizeof(method));

	uint16_t nativeIndex = uFnActionScriptFloat->iNative;
	uFnActionScriptFloat->iNative = 0;
	this->ProcessEvent(uFnActionScriptFloat, &ActionScriptFloat_Params, nullptr);
	uFnActionScriptFloat->iNative = nativeIndex;

	return ActionScriptFloat_Params.ReturnValue;
}

// Function GFxUI.GFxValue.ActionScriptInt
// [0x00080401] (FUNC_Final | FUNC_Native | FUNC_Protected)
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FString                  method                         (CPF_Parm | CPF_NeedCtorLink)

int32_t UGFxValue::ActionScriptInt(const class FString& method)
{
	static UFunction* uFnActionScriptInt = nullptr;

	if (!uFnActionScriptInt)
	{
		uFnActionScriptInt = UFunction::FindFunction("Function GFxUI.GFxValue.ActionScriptInt");
	}

	UGFxValue_execActionScriptInt_Params ActionScriptInt_Params;
	memset(&ActionScriptInt_Params, 0, sizeof(ActionScriptInt_Params));

	if (!uFnActionScriptInt)
	{
		return ActionScriptInt_Params.ReturnValue;
	}
	memcpy_s(&ActionScriptInt_Params.method, sizeof(ActionScriptInt_Params.method), &method, sizeof(method));

	uint16_t nativeIndex = uFnActionScriptInt->iNative;
	uFnActionScriptInt->iNative = 0;
	this->ProcessEvent(uFnActionScriptInt, &ActionScriptInt_Params, nullptr);
	uFnActionScriptInt->iNative = nativeIndex;

	return ActionScriptInt_Params.ReturnValue;
}

// Function GFxUI.GFxValue.ActionScriptVoid
// [0x00080401] (FUNC_Final | FUNC_Native | FUNC_Protected)
// Parameter Info:
// class FString                  method                         (CPF_Parm | CPF_NeedCtorLink)

void UGFxValue::ActionScriptVoid(const class FString& method)
{
	static UFunction* uFnActionScriptVoid = nullptr;

	if (!uFnActionScriptVoid)
	{
		uFnActionScriptVoid = UFunction::FindFunction("Function GFxUI.GFxValue.ActionScriptVoid");
	}

	UGFxValue_execActionScriptVoid_Params ActionScriptVoid_Params;
	memset(&ActionScriptVoid_Params, 0, sizeof(ActionScriptVoid_Params));

	if (!uFnActionScriptVoid)
	{
		return;
	}
	memcpy_s(&ActionScriptVoid_Params.method, sizeof(ActionScriptVoid_Params.method), &method, sizeof(method));

	uint16_t nativeIndex = uFnActionScriptVoid->iNative;
	uFnActionScriptVoid->iNative = 0;
	this->ProcessEvent(uFnActionScriptVoid, &ActionScriptVoid_Params, nullptr);
	uFnActionScriptVoid->iNative = nativeIndex;
}

// Function GFxUI.GFxValue.SetElementMemberString
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// int32_t                        Index                          (CPF_Parm)
// class FString                  member                         (CPF_Parm | CPF_NeedCtorLink)
// class FString                  S                              (CPF_Parm | CPF_NeedCtorLink)

void UGFxValue::SetElementMemberString(int32_t Index, const class FString& member, const class FString& S)
{
	static UFunction* uFnSetElementMemberString = nullptr;

	if (!uFnSetElementMemberString)
	{
		uFnSetElementMemberString = UFunction::FindFunction("Function GFxUI.GFxValue.SetElementMemberString");
	}

	UGFxValue_execSetElementMemberString_Params SetElementMemberString_Params;
	memset(&SetElementMemberString_Params, 0, sizeof(SetElementMemberString_Params));

	if (!uFnSetElementMemberString)
	{
		return;
	}
	SetElementMemberString_Params.Index = Index;
	memcpy_s(&SetElementMemberString_Params.member, sizeof(SetElementMemberString_Params.member), &member, sizeof(member));
	memcpy_s(&SetElementMemberString_Params.S, sizeof(SetElementMemberString_Params.S), &S, sizeof(S));

	uint16_t nativeIndex = uFnSetElementMemberString->iNative;
	uFnSetElementMemberString->iNative = 0;
	this->ProcessEvent(uFnSetElementMemberString, &SetElementMemberString_Params, nullptr);
	uFnSetElementMemberString->iNative = nativeIndex;
}

// Function GFxUI.GFxValue.SetElementMemberNumber
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// int32_t                        Index                          (CPF_Parm)
// class FString                  member                         (CPF_Parm | CPF_NeedCtorLink)
// float                          F                              (CPF_Parm)

void UGFxValue::SetElementMemberNumber(int32_t Index, const class FString& member, float F)
{
	static UFunction* uFnSetElementMemberNumber = nullptr;

	if (!uFnSetElementMemberNumber)
	{
		uFnSetElementMemberNumber = UFunction::FindFunction("Function GFxUI.GFxValue.SetElementMemberNumber");
	}

	UGFxValue_execSetElementMemberNumber_Params SetElementMemberNumber_Params;
	memset(&SetElementMemberNumber_Params, 0, sizeof(SetElementMemberNumber_Params));

	if (!uFnSetElementMemberNumber)
	{
		return;
	}
	SetElementMemberNumber_Params.Index = Index;
	memcpy_s(&SetElementMemberNumber_Params.member, sizeof(SetElementMemberNumber_Params.member), &member, sizeof(member));
	SetElementMemberNumber_Params.F = F;

	uint16_t nativeIndex = uFnSetElementMemberNumber->iNative;
	uFnSetElementMemberNumber->iNative = 0;
	this->ProcessEvent(uFnSetElementMemberNumber, &SetElementMemberNumber_Params, nullptr);
	uFnSetElementMemberNumber->iNative = nativeIndex;
}

// Function GFxUI.GFxValue.SetElementMemberBool
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// int32_t                        Index                          (CPF_Parm)
// class FString                  member                         (CPF_Parm | CPF_NeedCtorLink)
// uint32_t                       B                              (CPF_Parm)

void UGFxValue::SetElementMemberBool(int32_t Index, const class FString& member, bool B)
{
	static UFunction* uFnSetElementMemberBool = nullptr;

	if (!uFnSetElementMemberBool)
	{
		uFnSetElementMemberBool = UFunction::FindFunction("Function GFxUI.GFxValue.SetElementMemberBool");
	}

	UGFxValue_execSetElementMemberBool_Params SetElementMemberBool_Params;
	memset(&SetElementMemberBool_Params, 0, sizeof(SetElementMemberBool_Params));

	if (!uFnSetElementMemberBool)
	{
		return;
	}
	SetElementMemberBool_Params.Index = Index;
	memcpy_s(&SetElementMemberBool_Params.member, sizeof(SetElementMemberBool_Params.member), &member, sizeof(member));
	SetElementMemberBool_Params.B = B;

	uint16_t nativeIndex = uFnSetElementMemberBool->iNative;
	uFnSetElementMemberBool->iNative = 0;
	this->ProcessEvent(uFnSetElementMemberBool, &SetElementMemberBool_Params, nullptr);
	uFnSetElementMemberBool->iNative = nativeIndex;
}

// Function GFxUI.GFxValue.SetElementMemberObject
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// int32_t                        Index                          (CPF_Parm)
// class FString                  member                         (CPF_Parm | CPF_NeedCtorLink)
// class UGFxValue*               val                            (CPF_Parm)

void UGFxValue::SetElementMemberObject(int32_t Index, const class FString& member, class UGFxValue* val)
{
	static UFunction* uFnSetElementMemberObject = nullptr;

	if (!uFnSetElementMemberObject)
	{
		uFnSetElementMemberObject = UFunction::FindFunction("Function GFxUI.GFxValue.SetElementMemberObject");
	}

	UGFxValue_execSetElementMemberObject_Params SetElementMemberObject_Params;
	memset(&SetElementMemberObject_Params, 0, sizeof(SetElementMemberObject_Params));

	if (!uFnSetElementMemberObject)
	{
		return;
	}
	SetElementMemberObject_Params.Index = Index;
	memcpy_s(&SetElementMemberObject_Params.member, sizeof(SetElementMemberObject_Params.member), &member, sizeof(member));
	SetElementMemberObject_Params.val = val;

	uint16_t nativeIndex = uFnSetElementMemberObject->iNative;
	uFnSetElementMemberObject->iNative = 0;
	this->ProcessEvent(uFnSetElementMemberObject, &SetElementMemberObject_Params, nullptr);
	uFnSetElementMemberObject->iNative = nativeIndex;
}

// Function GFxUI.GFxValue.SetElementMember
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// int32_t                        Index                          (CPF_Parm)
// class FString                  member                         (CPF_Parm | CPF_NeedCtorLink)
// struct FASValue                Arg                            (CPF_Parm | CPF_NeedCtorLink)

void UGFxValue::SetElementMember(int32_t Index, const class FString& member, const struct FASValue& Arg)
{
	static UFunction* uFnSetElementMember = nullptr;

	if (!uFnSetElementMember)
	{
		uFnSetElementMember = UFunction::FindFunction("Function GFxUI.GFxValue.SetElementMember");
	}

	UGFxValue_execSetElementMember_Params SetElementMember_Params;
	memset(&SetElementMember_Params, 0, sizeof(SetElementMember_Params));

	if (!uFnSetElementMember)
	{
		return;
	}
	SetElementMember_Params.Index = Index;
	memcpy_s(&SetElementMember_Params.member, sizeof(SetElementMember_Params.member), &member, sizeof(member));
	memcpy_s(&SetElementMember_Params.Arg, sizeof(SetElementMember_Params.Arg), &Arg, sizeof(Arg));

	uint16_t nativeIndex = uFnSetElementMember->iNative;
	uFnSetElementMember->iNative = 0;
	this->ProcessEvent(uFnSetElementMember, &SetElementMember_Params, nullptr);
	uFnSetElementMember->iNative = nativeIndex;
}

// Function GFxUI.GFxValue.GetElementMemberString
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// class FString                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
// int32_t                        Index                          (CPF_Parm)
// class FString                  member                         (CPF_Parm | CPF_NeedCtorLink)

class FString UGFxValue::GetElementMemberString(int32_t Index, const class FString& member)
{
	static UFunction* uFnGetElementMemberString = nullptr;

	if (!uFnGetElementMemberString)
	{
		uFnGetElementMemberString = UFunction::FindFunction("Function GFxUI.GFxValue.GetElementMemberString");
	}

	UGFxValue_execGetElementMemberString_Params GetElementMemberString_Params;
	memset(&GetElementMemberString_Params, 0, sizeof(GetElementMemberString_Params));

	if (!uFnGetElementMemberString)
	{
		return GetElementMemberString_Params.ReturnValue;
	}
	GetElementMemberString_Params.Index = Index;
	memcpy_s(&GetElementMemberString_Params.member, sizeof(GetElementMemberString_Params.member), &member, sizeof(member));

	uint16_t nativeIndex = uFnGetElementMemberString->iNative;
	uFnGetElementMemberString->iNative = 0;
	this->ProcessEvent(uFnGetElementMemberString, &GetElementMemberString_Params, nullptr);
	uFnGetElementMemberString->iNative = nativeIndex;

	return GetElementMemberString_Params.ReturnValue;
}

// Function GFxUI.GFxValue.GetElementMemberNumber
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        Index                          (CPF_Parm)
// class FString                  member                         (CPF_Parm | CPF_NeedCtorLink)

float UGFxValue::GetElementMemberNumber(int32_t Index, const class FString& member)
{
	static UFunction* uFnGetElementMemberNumber = nullptr;

	if (!uFnGetElementMemberNumber)
	{
		uFnGetElementMemberNumber = UFunction::FindFunction("Function GFxUI.GFxValue.GetElementMemberNumber");
	}

	UGFxValue_execGetElementMemberNumber_Params GetElementMemberNumber_Params;
	memset(&GetElementMemberNumber_Params, 0, sizeof(GetElementMemberNumber_Params));

	if (!uFnGetElementMemberNumber)
	{
		return GetElementMemberNumber_Params.ReturnValue;
	}
	GetElementMemberNumber_Params.Index = Index;
	memcpy_s(&GetElementMemberNumber_Params.member, sizeof(GetElementMemberNumber_Params.member), &member, sizeof(member));

	uint16_t nativeIndex = uFnGetElementMemberNumber->iNative;
	uFnGetElementMemberNumber->iNative = 0;
	this->ProcessEvent(uFnGetElementMemberNumber, &GetElementMemberNumber_Params, nullptr);
	uFnGetElementMemberNumber->iNative = nativeIndex;

	return GetElementMemberNumber_Params.ReturnValue;
}

// Function GFxUI.GFxValue.GetElementMemberBool
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        Index                          (CPF_Parm)
// class FString                  member                         (CPF_Parm | CPF_NeedCtorLink)

bool UGFxValue::GetElementMemberBool(int32_t Index, const class FString& member)
{
	static UFunction* uFnGetElementMemberBool = nullptr;

	if (!uFnGetElementMemberBool)
	{
		uFnGetElementMemberBool = UFunction::FindFunction("Function GFxUI.GFxValue.GetElementMemberBool");
	}

	UGFxValue_execGetElementMemberBool_Params GetElementMemberBool_Params;
	memset(&GetElementMemberBool_Params, 0, sizeof(GetElementMemberBool_Params));

	if (!uFnGetElementMemberBool)
	{
		return GetElementMemberBool_Params.ReturnValue;
	}
	GetElementMemberBool_Params.Index = Index;
	memcpy_s(&GetElementMemberBool_Params.member, sizeof(GetElementMemberBool_Params.member), &member, sizeof(member));

	uint16_t nativeIndex = uFnGetElementMemberBool->iNative;
	uFnGetElementMemberBool->iNative = 0;
	this->ProcessEvent(uFnGetElementMemberBool, &GetElementMemberBool_Params, nullptr);
	uFnGetElementMemberBool->iNative = nativeIndex;

	return GetElementMemberBool_Params.ReturnValue;
}

// Function GFxUI.GFxValue.GetElementMemberObject
// [0x00024401] (FUNC_Final | FUNC_Native | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// class UGFxValue*               ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        Index                          (CPF_Parm)
// class FString                  member                         (CPF_Parm | CPF_NeedCtorLink)
// class UClass*                  Type                           (CPF_OptionalParm | CPF_Parm)

class UGFxValue* UGFxValue::GetElementMemberObject(int32_t Index, const class FString& member, class UClass* optionalType)
{
	static UFunction* uFnGetElementMemberObject = nullptr;

	if (!uFnGetElementMemberObject)
	{
		uFnGetElementMemberObject = UFunction::FindFunction("Function GFxUI.GFxValue.GetElementMemberObject");
	}

	UGFxValue_execGetElementMemberObject_Params GetElementMemberObject_Params;
	memset(&GetElementMemberObject_Params, 0, sizeof(GetElementMemberObject_Params));

	if (!uFnGetElementMemberObject)
	{
		return GetElementMemberObject_Params.ReturnValue;
	}
	GetElementMemberObject_Params.Index = Index;
	memcpy_s(&GetElementMemberObject_Params.member, sizeof(GetElementMemberObject_Params.member), &member, sizeof(member));
	GetElementMemberObject_Params.Type = optionalType;

	uint16_t nativeIndex = uFnGetElementMemberObject->iNative;
	uFnGetElementMemberObject->iNative = 0;
	this->ProcessEvent(uFnGetElementMemberObject, &GetElementMemberObject_Params, nullptr);
	uFnGetElementMemberObject->iNative = nativeIndex;

	return GetElementMemberObject_Params.ReturnValue;
}

// Function GFxUI.GFxValue.GetElementMember
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// struct FASValue                ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
// int32_t                        Index                          (CPF_Parm)
// class FString                  member                         (CPF_Parm | CPF_NeedCtorLink)

struct FASValue UGFxValue::GetElementMember(int32_t Index, const class FString& member)
{
	static UFunction* uFnGetElementMember = nullptr;

	if (!uFnGetElementMember)
	{
		uFnGetElementMember = UFunction::FindFunction("Function GFxUI.GFxValue.GetElementMember");
	}

	UGFxValue_execGetElementMember_Params GetElementMember_Params;
	memset(&GetElementMember_Params, 0, sizeof(GetElementMember_Params));

	if (!uFnGetElementMember)
	{
		return GetElementMember_Params.ReturnValue;
	}
	GetElementMember_Params.Index = Index;
	memcpy_s(&GetElementMember_Params.member, sizeof(GetElementMember_Params.member), &member, sizeof(member));

	uint16_t nativeIndex = uFnGetElementMember->iNative;
	uFnGetElementMember->iNative = 0;
	this->ProcessEvent(uFnGetElementMember, &GetElementMember_Params, nullptr);
	uFnGetElementMember->iNative = nativeIndex;

	return GetElementMember_Params.ReturnValue;
}

// Function GFxUI.GFxValue.SetElementColorTransform
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// int32_t                        Index                          (CPF_Parm)
// struct FASColorTransform       cxform                         (CPF_Parm)

void UGFxValue::SetElementColorTransform(int32_t Index, const struct FASColorTransform& cxform)
{
	static UFunction* uFnSetElementColorTransform = nullptr;

	if (!uFnSetElementColorTransform)
	{
		uFnSetElementColorTransform = UFunction::FindFunction("Function GFxUI.GFxValue.SetElementColorTransform");
	}

	UGFxValue_execSetElementColorTransform_Params SetElementColorTransform_Params;
	memset(&SetElementColorTransform_Params, 0, sizeof(SetElementColorTransform_Params));

	if (!uFnSetElementColorTransform)
	{
		return;
	}
	SetElementColorTransform_Params.Index = Index;
	memcpy_s(&SetElementColorTransform_Params.cxform, sizeof(SetElementColorTransform_Params.cxform), &cxform, sizeof(cxform));

	uint16_t nativeIndex = uFnSetElementColorTransform->iNative;
	uFnSetElementColorTransform->iNative = 0;
	this->ProcessEvent(uFnSetElementColorTransform, &SetElementColorTransform_Params, nullptr);
	uFnSetElementColorTransform->iNative = nativeIndex;
}

// Function GFxUI.GFxValue.SetElementPosition
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// int32_t                        Index                          (CPF_Parm)
// float                          X                              (CPF_Parm)
// float                          Y                              (CPF_Parm)

void UGFxValue::SetElementPosition(int32_t Index, float X, float Y)
{
	static UFunction* uFnSetElementPosition = nullptr;

	if (!uFnSetElementPosition)
	{
		uFnSetElementPosition = UFunction::FindFunction("Function GFxUI.GFxValue.SetElementPosition");
	}

	UGFxValue_execSetElementPosition_Params SetElementPosition_Params;
	memset(&SetElementPosition_Params, 0, sizeof(SetElementPosition_Params));

	if (!uFnSetElementPosition)
	{
		return;
	}
	SetElementPosition_Params.Index = Index;
	SetElementPosition_Params.X = X;
	SetElementPosition_Params.Y = Y;

	uint16_t nativeIndex = uFnSetElementPosition->iNative;
	uFnSetElementPosition->iNative = 0;
	this->ProcessEvent(uFnSetElementPosition, &SetElementPosition_Params, nullptr);
	uFnSetElementPosition->iNative = nativeIndex;
}

// Function GFxUI.GFxValue.SetElementVisible
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// int32_t                        Index                          (CPF_Parm)
// uint32_t                       Visible                        (CPF_Parm)

void UGFxValue::SetElementVisible(int32_t Index, bool Visible)
{
	static UFunction* uFnSetElementVisible = nullptr;

	if (!uFnSetElementVisible)
	{
		uFnSetElementVisible = UFunction::FindFunction("Function GFxUI.GFxValue.SetElementVisible");
	}

	UGFxValue_execSetElementVisible_Params SetElementVisible_Params;
	memset(&SetElementVisible_Params, 0, sizeof(SetElementVisible_Params));

	if (!uFnSetElementVisible)
	{
		return;
	}
	SetElementVisible_Params.Index = Index;
	SetElementVisible_Params.Visible = Visible;

	uint16_t nativeIndex = uFnSetElementVisible->iNative;
	uFnSetElementVisible->iNative = 0;
	this->ProcessEvent(uFnSetElementVisible, &SetElementVisible_Params, nullptr);
	uFnSetElementVisible->iNative = nativeIndex;
}

// Function GFxUI.GFxValue.SetElementDisplayMatrix
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// int32_t                        Index                          (CPF_Parm)
// struct FMatrix                 M                              (CPF_Parm)

void UGFxValue::SetElementDisplayMatrix(int32_t Index, const struct FMatrix& M)
{
	static UFunction* uFnSetElementDisplayMatrix = nullptr;

	if (!uFnSetElementDisplayMatrix)
	{
		uFnSetElementDisplayMatrix = UFunction::FindFunction("Function GFxUI.GFxValue.SetElementDisplayMatrix");
	}

	UGFxValue_execSetElementDisplayMatrix_Params SetElementDisplayMatrix_Params;
	memset(&SetElementDisplayMatrix_Params, 0, sizeof(SetElementDisplayMatrix_Params));

	if (!uFnSetElementDisplayMatrix)
	{
		return;
	}
	SetElementDisplayMatrix_Params.Index = Index;
	memcpy_s(&SetElementDisplayMatrix_Params.M, sizeof(SetElementDisplayMatrix_Params.M), &M, sizeof(M));

	uint16_t nativeIndex = uFnSetElementDisplayMatrix->iNative;
	uFnSetElementDisplayMatrix->iNative = 0;
	this->ProcessEvent(uFnSetElementDisplayMatrix, &SetElementDisplayMatrix_Params, nullptr);
	uFnSetElementDisplayMatrix->iNative = nativeIndex;
}

// Function GFxUI.GFxValue.SetElementDisplayInfo
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// int32_t                        Index                          (CPF_Parm)
// struct FASDisplayInfo          D                              (CPF_Parm)

void UGFxValue::SetElementDisplayInfo(int32_t Index, const struct FASDisplayInfo& D)
{
	static UFunction* uFnSetElementDisplayInfo = nullptr;

	if (!uFnSetElementDisplayInfo)
	{
		uFnSetElementDisplayInfo = UFunction::FindFunction("Function GFxUI.GFxValue.SetElementDisplayInfo");
	}

	UGFxValue_execSetElementDisplayInfo_Params SetElementDisplayInfo_Params;
	memset(&SetElementDisplayInfo_Params, 0, sizeof(SetElementDisplayInfo_Params));

	if (!uFnSetElementDisplayInfo)
	{
		return;
	}
	SetElementDisplayInfo_Params.Index = Index;
	memcpy_s(&SetElementDisplayInfo_Params.D, sizeof(SetElementDisplayInfo_Params.D), &D, sizeof(D));

	uint16_t nativeIndex = uFnSetElementDisplayInfo->iNative;
	uFnSetElementDisplayInfo->iNative = 0;
	this->ProcessEvent(uFnSetElementDisplayInfo, &SetElementDisplayInfo_Params, nullptr);
	uFnSetElementDisplayInfo->iNative = nativeIndex;
}

// Function GFxUI.GFxValue.SetElementString
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// int32_t                        Index                          (CPF_Parm)
// class FString                  S                              (CPF_Parm | CPF_NeedCtorLink)

void UGFxValue::SetElementString(int32_t Index, const class FString& S)
{
	static UFunction* uFnSetElementString = nullptr;

	if (!uFnSetElementString)
	{
		uFnSetElementString = UFunction::FindFunction("Function GFxUI.GFxValue.SetElementString");
	}

	UGFxValue_execSetElementString_Params SetElementString_Params;
	memset(&SetElementString_Params, 0, sizeof(SetElementString_Params));

	if (!uFnSetElementString)
	{
		return;
	}
	SetElementString_Params.Index = Index;
	memcpy_s(&SetElementString_Params.S, sizeof(SetElementString_Params.S), &S, sizeof(S));

	uint16_t nativeIndex = uFnSetElementString->iNative;
	uFnSetElementString->iNative = 0;
	this->ProcessEvent(uFnSetElementString, &SetElementString_Params, nullptr);
	uFnSetElementString->iNative = nativeIndex;
}

// Function GFxUI.GFxValue.SetElementNumber
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// int32_t                        Index                          (CPF_Parm)
// float                          F                              (CPF_Parm)

void UGFxValue::SetElementNumber(int32_t Index, float F)
{
	static UFunction* uFnSetElementNumber = nullptr;

	if (!uFnSetElementNumber)
	{
		uFnSetElementNumber = UFunction::FindFunction("Function GFxUI.GFxValue.SetElementNumber");
	}

	UGFxValue_execSetElementNumber_Params SetElementNumber_Params;
	memset(&SetElementNumber_Params, 0, sizeof(SetElementNumber_Params));

	if (!uFnSetElementNumber)
	{
		return;
	}
	SetElementNumber_Params.Index = Index;
	SetElementNumber_Params.F = F;

	uint16_t nativeIndex = uFnSetElementNumber->iNative;
	uFnSetElementNumber->iNative = 0;
	this->ProcessEvent(uFnSetElementNumber, &SetElementNumber_Params, nullptr);
	uFnSetElementNumber->iNative = nativeIndex;
}

// Function GFxUI.GFxValue.SetElementBool
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// int32_t                        Index                          (CPF_Parm)
// uint32_t                       B                              (CPF_Parm)

void UGFxValue::SetElementBool(int32_t Index, bool B)
{
	static UFunction* uFnSetElementBool = nullptr;

	if (!uFnSetElementBool)
	{
		uFnSetElementBool = UFunction::FindFunction("Function GFxUI.GFxValue.SetElementBool");
	}

	UGFxValue_execSetElementBool_Params SetElementBool_Params;
	memset(&SetElementBool_Params, 0, sizeof(SetElementBool_Params));

	if (!uFnSetElementBool)
	{
		return;
	}
	SetElementBool_Params.Index = Index;
	SetElementBool_Params.B = B;

	uint16_t nativeIndex = uFnSetElementBool->iNative;
	uFnSetElementBool->iNative = 0;
	this->ProcessEvent(uFnSetElementBool, &SetElementBool_Params, nullptr);
	uFnSetElementBool->iNative = nativeIndex;
}

// Function GFxUI.GFxValue.SetElementObject
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// int32_t                        Index                          (CPF_Parm)
// class UGFxValue*               val                            (CPF_Parm)

void UGFxValue::SetElementObject(int32_t Index, class UGFxValue* val)
{
	static UFunction* uFnSetElementObject = nullptr;

	if (!uFnSetElementObject)
	{
		uFnSetElementObject = UFunction::FindFunction("Function GFxUI.GFxValue.SetElementObject");
	}

	UGFxValue_execSetElementObject_Params SetElementObject_Params;
	memset(&SetElementObject_Params, 0, sizeof(SetElementObject_Params));

	if (!uFnSetElementObject)
	{
		return;
	}
	SetElementObject_Params.Index = Index;
	SetElementObject_Params.val = val;

	uint16_t nativeIndex = uFnSetElementObject->iNative;
	uFnSetElementObject->iNative = 0;
	this->ProcessEvent(uFnSetElementObject, &SetElementObject_Params, nullptr);
	uFnSetElementObject->iNative = nativeIndex;
}

// Function GFxUI.GFxValue.SetElement
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// int32_t                        Index                          (CPF_Parm)
// struct FASValue                Arg                            (CPF_Parm | CPF_NeedCtorLink)

void UGFxValue::SetElement(int32_t Index, const struct FASValue& Arg)
{
	static UFunction* uFnSetElement = nullptr;

	if (!uFnSetElement)
	{
		uFnSetElement = UFunction::FindFunction("Function GFxUI.GFxValue.SetElement");
	}

	UGFxValue_execSetElement_Params SetElement_Params;
	memset(&SetElement_Params, 0, sizeof(SetElement_Params));

	if (!uFnSetElement)
	{
		return;
	}
	SetElement_Params.Index = Index;
	memcpy_s(&SetElement_Params.Arg, sizeof(SetElement_Params.Arg), &Arg, sizeof(Arg));

	uint16_t nativeIndex = uFnSetElement->iNative;
	uFnSetElement->iNative = 0;
	this->ProcessEvent(uFnSetElement, &SetElement_Params, nullptr);
	uFnSetElement->iNative = nativeIndex;
}

// Function GFxUI.GFxValue.GetElementDisplayMatrix
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// struct FMatrix                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        Index                          (CPF_Parm)

struct FMatrix UGFxValue::GetElementDisplayMatrix(int32_t Index)
{
	static UFunction* uFnGetElementDisplayMatrix = nullptr;

	if (!uFnGetElementDisplayMatrix)
	{
		uFnGetElementDisplayMatrix = UFunction::FindFunction("Function GFxUI.GFxValue.GetElementDisplayMatrix");
	}

	UGFxValue_execGetElementDisplayMatrix_Params GetElementDisplayMatrix_Params;
	memset(&GetElementDisplayMatrix_Params, 0, sizeof(GetElementDisplayMatrix_Params));

	if (!uFnGetElementDisplayMatrix)
	{
		return GetElementDisplayMatrix_Params.ReturnValue;
	}
	GetElementDisplayMatrix_Params.Index = Index;

	uint16_t nativeIndex = uFnGetElementDisplayMatrix->iNative;
	uFnGetElementDisplayMatrix->iNative = 0;
	this->ProcessEvent(uFnGetElementDisplayMatrix, &GetElementDisplayMatrix_Params, nullptr);
	uFnGetElementDisplayMatrix->iNative = nativeIndex;

	return GetElementDisplayMatrix_Params.ReturnValue;
}

// Function GFxUI.GFxValue.GetElementDisplayInfo
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// struct FASDisplayInfo          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        Index                          (CPF_Parm)

struct FASDisplayInfo UGFxValue::GetElementDisplayInfo(int32_t Index)
{
	static UFunction* uFnGetElementDisplayInfo = nullptr;

	if (!uFnGetElementDisplayInfo)
	{
		uFnGetElementDisplayInfo = UFunction::FindFunction("Function GFxUI.GFxValue.GetElementDisplayInfo");
	}

	UGFxValue_execGetElementDisplayInfo_Params GetElementDisplayInfo_Params;
	memset(&GetElementDisplayInfo_Params, 0, sizeof(GetElementDisplayInfo_Params));

	if (!uFnGetElementDisplayInfo)
	{
		return GetElementDisplayInfo_Params.ReturnValue;
	}
	GetElementDisplayInfo_Params.Index = Index;

	uint16_t nativeIndex = uFnGetElementDisplayInfo->iNative;
	uFnGetElementDisplayInfo->iNative = 0;
	this->ProcessEvent(uFnGetElementDisplayInfo, &GetElementDisplayInfo_Params, nullptr);
	uFnGetElementDisplayInfo->iNative = nativeIndex;

	return GetElementDisplayInfo_Params.ReturnValue;
}

// Function GFxUI.GFxValue.GetElementString
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// class FString                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
// int32_t                        Index                          (CPF_Parm)

class FString UGFxValue::GetElementString(int32_t Index)
{
	static UFunction* uFnGetElementString = nullptr;

	if (!uFnGetElementString)
	{
		uFnGetElementString = UFunction::FindFunction("Function GFxUI.GFxValue.GetElementString");
	}

	UGFxValue_execGetElementString_Params GetElementString_Params;
	memset(&GetElementString_Params, 0, sizeof(GetElementString_Params));

	if (!uFnGetElementString)
	{
		return GetElementString_Params.ReturnValue;
	}
	GetElementString_Params.Index = Index;

	uint16_t nativeIndex = uFnGetElementString->iNative;
	uFnGetElementString->iNative = 0;
	this->ProcessEvent(uFnGetElementString, &GetElementString_Params, nullptr);
	uFnGetElementString->iNative = nativeIndex;

	return GetElementString_Params.ReturnValue;
}

// Function GFxUI.GFxValue.GetElementNumber
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        Index                          (CPF_Parm)

float UGFxValue::GetElementNumber(int32_t Index)
{
	static UFunction* uFnGetElementNumber = nullptr;

	if (!uFnGetElementNumber)
	{
		uFnGetElementNumber = UFunction::FindFunction("Function GFxUI.GFxValue.GetElementNumber");
	}

	UGFxValue_execGetElementNumber_Params GetElementNumber_Params;
	memset(&GetElementNumber_Params, 0, sizeof(GetElementNumber_Params));

	if (!uFnGetElementNumber)
	{
		return GetElementNumber_Params.ReturnValue;
	}
	GetElementNumber_Params.Index = Index;

	uint16_t nativeIndex = uFnGetElementNumber->iNative;
	uFnGetElementNumber->iNative = 0;
	this->ProcessEvent(uFnGetElementNumber, &GetElementNumber_Params, nullptr);
	uFnGetElementNumber->iNative = nativeIndex;

	return GetElementNumber_Params.ReturnValue;
}

// Function GFxUI.GFxValue.GetElementBool
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        Index                          (CPF_Parm)

bool UGFxValue::GetElementBool(int32_t Index)
{
	static UFunction* uFnGetElementBool = nullptr;

	if (!uFnGetElementBool)
	{
		uFnGetElementBool = UFunction::FindFunction("Function GFxUI.GFxValue.GetElementBool");
	}

	UGFxValue_execGetElementBool_Params GetElementBool_Params;
	memset(&GetElementBool_Params, 0, sizeof(GetElementBool_Params));

	if (!uFnGetElementBool)
	{
		return GetElementBool_Params.ReturnValue;
	}
	GetElementBool_Params.Index = Index;

	uint16_t nativeIndex = uFnGetElementBool->iNative;
	uFnGetElementBool->iNative = 0;
	this->ProcessEvent(uFnGetElementBool, &GetElementBool_Params, nullptr);
	uFnGetElementBool->iNative = nativeIndex;

	return GetElementBool_Params.ReturnValue;
}

// Function GFxUI.GFxValue.GetElementObject
// [0x00024401] (FUNC_Final | FUNC_Native | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// class UGFxValue*               ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        Index                          (CPF_Parm)
// class UClass*                  Type                           (CPF_OptionalParm | CPF_Parm)

class UGFxValue* UGFxValue::GetElementObject(int32_t Index, class UClass* optionalType)
{
	static UFunction* uFnGetElementObject = nullptr;

	if (!uFnGetElementObject)
	{
		uFnGetElementObject = UFunction::FindFunction("Function GFxUI.GFxValue.GetElementObject");
	}

	UGFxValue_execGetElementObject_Params GetElementObject_Params;
	memset(&GetElementObject_Params, 0, sizeof(GetElementObject_Params));

	if (!uFnGetElementObject)
	{
		return GetElementObject_Params.ReturnValue;
	}
	GetElementObject_Params.Index = Index;
	GetElementObject_Params.Type = optionalType;

	uint16_t nativeIndex = uFnGetElementObject->iNative;
	uFnGetElementObject->iNative = 0;
	this->ProcessEvent(uFnGetElementObject, &GetElementObject_Params, nullptr);
	uFnGetElementObject->iNative = nativeIndex;

	return GetElementObject_Params.ReturnValue;
}

// Function GFxUI.GFxValue.GetElement
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// struct FASValue                ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
// int32_t                        Index                          (CPF_Parm)

struct FASValue UGFxValue::GetElement(int32_t Index)
{
	static UFunction* uFnGetElement = nullptr;

	if (!uFnGetElement)
	{
		uFnGetElement = UFunction::FindFunction("Function GFxUI.GFxValue.GetElement");
	}

	UGFxValue_execGetElement_Params GetElement_Params;
	memset(&GetElement_Params, 0, sizeof(GetElement_Params));

	if (!uFnGetElement)
	{
		return GetElement_Params.ReturnValue;
	}
	GetElement_Params.Index = Index;

	uint16_t nativeIndex = uFnGetElement->iNative;
	uFnGetElement->iNative = 0;
	this->ProcessEvent(uFnGetElement, &GetElement_Params, nullptr);
	uFnGetElement->iNative = nativeIndex;

	return GetElement_Params.ReturnValue;
}

// Function GFxUI.GFxValue.SetText
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// class FString                  Text                           (CPF_Parm | CPF_CoerceParm | CPF_NeedCtorLink)

void UGFxValue::SetText(const class FString& Text)
{
	static UFunction* uFnSetText = nullptr;

	if (!uFnSetText)
	{
		uFnSetText = UFunction::FindFunction("Function GFxUI.GFxValue.SetText");
	}

	UGFxValue_execSetText_Params SetText_Params;
	memset(&SetText_Params, 0, sizeof(SetText_Params));

	if (!uFnSetText)
	{
		return;
	}
	memcpy_s(&SetText_Params.Text, sizeof(SetText_Params.Text), &Text, sizeof(Text));

	uint16_t nativeIndex = uFnSetText->iNative;
	uFnSetText->iNative = 0;
	this->ProcessEvent(uFnSetText, &SetText_Params, nullptr);
	uFnSetText->iNative = nativeIndex;
}

// Function GFxUI.GFxValue.GetText
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// class FString                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)

class FString UGFxValue::GetText()
{
	static UFunction* uFnGetText = nullptr;

	if (!uFnGetText)
	{
		uFnGetText = UFunction::FindFunction("Function GFxUI.GFxValue.GetText");
	}

	UGFxValue_execGetText_Params GetText_Params;
	memset(&GetText_Params, 0, sizeof(GetText_Params));

	if (!uFnGetText)
	{
		return GetText_Params.ReturnValue;
	}

	uint16_t nativeIndex = uFnGetText->iNative;
	uFnGetText->iNative = 0;
	this->ProcessEvent(uFnGetText, &GetText_Params, nullptr);
	uFnGetText->iNative = nativeIndex;

	return GetText_Params.ReturnValue;
}

// Function GFxUI.GFxValue.AttachMovie
// [0x00024401] (FUNC_Final | FUNC_Native | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// class UGFxValue*               ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FString                  symbolname                     (CPF_Parm | CPF_NeedCtorLink)
// class FString                  instancename                   (CPF_Parm | CPF_NeedCtorLink)
// int32_t                        Depth                          (CPF_OptionalParm | CPF_Parm)
// class UClass*                  Type                           (CPF_OptionalParm | CPF_Parm)

class UGFxValue* UGFxValue::AttachMovie(const class FString& symbolname, const class FString& instancename, int32_t optionalDepth, class UClass* optionalType)
{
	static UFunction* uFnAttachMovie = nullptr;

	if (!uFnAttachMovie)
	{
		uFnAttachMovie = UFunction::FindFunction("Function GFxUI.GFxValue.AttachMovie");
	}

	UGFxValue_execAttachMovie_Params AttachMovie_Params;
	memset(&AttachMovie_Params, 0, sizeof(AttachMovie_Params));

	if (!uFnAttachMovie)
	{
		return AttachMovie_Params.ReturnValue;
	}
	memcpy_s(&AttachMovie_Params.symbolname, sizeof(AttachMovie_Params.symbolname), &symbolname, sizeof(symbolname));
	memcpy_s(&AttachMovie_Params.instancename, sizeof(AttachMovie_Params.instancename), &instancename, sizeof(instancename));
	AttachMovie_Params.Depth = optionalDepth;
	AttachMovie_Params.Type = optionalType;

	uint16_t nativeIndex = uFnAttachMovie->iNative;
	uFnAttachMovie->iNative = 0;
	this->ProcessEvent(uFnAttachMovie, &AttachMovie_Params, nullptr);
	uFnAttachMovie->iNative = nativeIndex;

	return AttachMovie_Params.ReturnValue;
}

// Function GFxUI.GFxValue.CreateEmptyMovieClip
// [0x00024401] (FUNC_Final | FUNC_Native | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// class UGFxValue*               ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FString                  instancename                   (CPF_Parm | CPF_NeedCtorLink)
// int32_t                        Depth                          (CPF_OptionalParm | CPF_Parm)
// class UClass*                  Type                           (CPF_OptionalParm | CPF_Parm)

class UGFxValue* UGFxValue::CreateEmptyMovieClip(const class FString& instancename, int32_t optionalDepth, class UClass* optionalType)
{
	static UFunction* uFnCreateEmptyMovieClip = nullptr;

	if (!uFnCreateEmptyMovieClip)
	{
		uFnCreateEmptyMovieClip = UFunction::FindFunction("Function GFxUI.GFxValue.CreateEmptyMovieClip");
	}

	UGFxValue_execCreateEmptyMovieClip_Params CreateEmptyMovieClip_Params;
	memset(&CreateEmptyMovieClip_Params, 0, sizeof(CreateEmptyMovieClip_Params));

	if (!uFnCreateEmptyMovieClip)
	{
		return CreateEmptyMovieClip_Params.ReturnValue;
	}
	memcpy_s(&CreateEmptyMovieClip_Params.instancename, sizeof(CreateEmptyMovieClip_Params.instancename), &instancename, sizeof(instancename));
	CreateEmptyMovieClip_Params.Depth = optionalDepth;
	CreateEmptyMovieClip_Params.Type = optionalType;

	uint16_t nativeIndex = uFnCreateEmptyMovieClip->iNative;
	uFnCreateEmptyMovieClip->iNative = 0;
	this->ProcessEvent(uFnCreateEmptyMovieClip, &CreateEmptyMovieClip_Params, nullptr);
	uFnCreateEmptyMovieClip->iNative = nativeIndex;

	return CreateEmptyMovieClip_Params.ReturnValue;
}

// Function GFxUI.GFxValue.GotoAndStopI
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// int32_t                        frame                          (CPF_Parm)

void UGFxValue::GotoAndStopI(int32_t frame)
{
	static UFunction* uFnGotoAndStopI = nullptr;

	if (!uFnGotoAndStopI)
	{
		uFnGotoAndStopI = UFunction::FindFunction("Function GFxUI.GFxValue.GotoAndStopI");
	}

	UGFxValue_execGotoAndStopI_Params GotoAndStopI_Params;
	memset(&GotoAndStopI_Params, 0, sizeof(GotoAndStopI_Params));

	if (!uFnGotoAndStopI)
	{
		return;
	}
	GotoAndStopI_Params.frame = frame;

	uint16_t nativeIndex = uFnGotoAndStopI->iNative;
	uFnGotoAndStopI->iNative = 0;
	this->ProcessEvent(uFnGotoAndStopI, &GotoAndStopI_Params, nullptr);
	uFnGotoAndStopI->iNative = nativeIndex;
}

// Function GFxUI.GFxValue.GotoAndStop
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// class FString                  frame                          (CPF_Parm | CPF_NeedCtorLink)

void UGFxValue::GotoAndStop(const class FString& frame)
{
	static UFunction* uFnGotoAndStop = nullptr;

	if (!uFnGotoAndStop)
	{
		uFnGotoAndStop = UFunction::FindFunction("Function GFxUI.GFxValue.GotoAndStop");
	}

	UGFxValue_execGotoAndStop_Params GotoAndStop_Params;
	memset(&GotoAndStop_Params, 0, sizeof(GotoAndStop_Params));

	if (!uFnGotoAndStop)
	{
		return;
	}
	memcpy_s(&GotoAndStop_Params.frame, sizeof(GotoAndStop_Params.frame), &frame, sizeof(frame));

	uint16_t nativeIndex = uFnGotoAndStop->iNative;
	uFnGotoAndStop->iNative = 0;
	this->ProcessEvent(uFnGotoAndStop, &GotoAndStop_Params, nullptr);
	uFnGotoAndStop->iNative = nativeIndex;
}

// Function GFxUI.GFxValue.GotoAndPlayI
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// int32_t                        frame                          (CPF_Parm)

void UGFxValue::GotoAndPlayI(int32_t frame)
{
	static UFunction* uFnGotoAndPlayI = nullptr;

	if (!uFnGotoAndPlayI)
	{
		uFnGotoAndPlayI = UFunction::FindFunction("Function GFxUI.GFxValue.GotoAndPlayI");
	}

	UGFxValue_execGotoAndPlayI_Params GotoAndPlayI_Params;
	memset(&GotoAndPlayI_Params, 0, sizeof(GotoAndPlayI_Params));

	if (!uFnGotoAndPlayI)
	{
		return;
	}
	GotoAndPlayI_Params.frame = frame;

	uint16_t nativeIndex = uFnGotoAndPlayI->iNative;
	uFnGotoAndPlayI->iNative = 0;
	this->ProcessEvent(uFnGotoAndPlayI, &GotoAndPlayI_Params, nullptr);
	uFnGotoAndPlayI->iNative = nativeIndex;
}

// Function GFxUI.GFxValue.GotoAndPlay
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// class FString                  frame                          (CPF_Parm | CPF_NeedCtorLink)

void UGFxValue::GotoAndPlay(const class FString& frame)
{
	static UFunction* uFnGotoAndPlay = nullptr;

	if (!uFnGotoAndPlay)
	{
		uFnGotoAndPlay = UFunction::FindFunction("Function GFxUI.GFxValue.GotoAndPlay");
	}

	UGFxValue_execGotoAndPlay_Params GotoAndPlay_Params;
	memset(&GotoAndPlay_Params, 0, sizeof(GotoAndPlay_Params));

	if (!uFnGotoAndPlay)
	{
		return;
	}
	memcpy_s(&GotoAndPlay_Params.frame, sizeof(GotoAndPlay_Params.frame), &frame, sizeof(frame));

	uint16_t nativeIndex = uFnGotoAndPlay->iNative;
	uFnGotoAndPlay->iNative = 0;
	this->ProcessEvent(uFnGotoAndPlay, &GotoAndPlay_Params, nullptr);
	uFnGotoAndPlay->iNative = nativeIndex;
}

// Function GFxUI.GFxValue.SetColorTransform
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// struct FASColorTransform       cxform                         (CPF_Parm)

void UGFxValue::SetColorTransform(const struct FASColorTransform& cxform)
{
	static UFunction* uFnSetColorTransform = nullptr;

	if (!uFnSetColorTransform)
	{
		uFnSetColorTransform = UFunction::FindFunction("Function GFxUI.GFxValue.SetColorTransform");
	}

	UGFxValue_execSetColorTransform_Params SetColorTransform_Params;
	memset(&SetColorTransform_Params, 0, sizeof(SetColorTransform_Params));

	if (!uFnSetColorTransform)
	{
		return;
	}
	memcpy_s(&SetColorTransform_Params.cxform, sizeof(SetColorTransform_Params.cxform), &cxform, sizeof(cxform));

	uint16_t nativeIndex = uFnSetColorTransform->iNative;
	uFnSetColorTransform->iNative = 0;
	this->ProcessEvent(uFnSetColorTransform, &SetColorTransform_Params, nullptr);
	uFnSetColorTransform->iNative = nativeIndex;
}

// Function GFxUI.GFxValue.SetPosition
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// float                          X                              (CPF_Parm)
// float                          Y                              (CPF_Parm)

void UGFxValue::SetPosition(float X, float Y)
{
	static UFunction* uFnSetPosition = nullptr;

	if (!uFnSetPosition)
	{
		uFnSetPosition = UFunction::FindFunction("Function GFxUI.GFxValue.SetPosition");
	}

	UGFxValue_execSetPosition_Params SetPosition_Params;
	memset(&SetPosition_Params, 0, sizeof(SetPosition_Params));

	if (!uFnSetPosition)
	{
		return;
	}
	SetPosition_Params.X = X;
	SetPosition_Params.Y = Y;

	uint16_t nativeIndex = uFnSetPosition->iNative;
	uFnSetPosition->iNative = 0;
	this->ProcessEvent(uFnSetPosition, &SetPosition_Params, nullptr);
	uFnSetPosition->iNative = nativeIndex;
}

// Function GFxUI.GFxValue.SetVisible
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// uint32_t                       Visible                        (CPF_Parm)

void UGFxValue::SetVisible(bool Visible)
{
	static UFunction* uFnSetVisible = nullptr;

	if (!uFnSetVisible)
	{
		uFnSetVisible = UFunction::FindFunction("Function GFxUI.GFxValue.SetVisible");
	}

	UGFxValue_execSetVisible_Params SetVisible_Params;
	memset(&SetVisible_Params, 0, sizeof(SetVisible_Params));

	if (!uFnSetVisible)
	{
		return;
	}
	SetVisible_Params.Visible = Visible;

	uint16_t nativeIndex = uFnSetVisible->iNative;
	uFnSetVisible->iNative = 0;
	this->ProcessEvent(uFnSetVisible, &SetVisible_Params, nullptr);
	uFnSetVisible->iNative = nativeIndex;
}

// Function GFxUI.GFxValue.SetDisplayMatrix3D
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// struct FMatrix                 M                              (CPF_Parm)

void UGFxValue::SetDisplayMatrix3D(const struct FMatrix& M)
{
	static UFunction* uFnSetDisplayMatrix3D = nullptr;

	if (!uFnSetDisplayMatrix3D)
	{
		uFnSetDisplayMatrix3D = UFunction::FindFunction("Function GFxUI.GFxValue.SetDisplayMatrix3D");
	}

	UGFxValue_execSetDisplayMatrix3D_Params SetDisplayMatrix3D_Params;
	memset(&SetDisplayMatrix3D_Params, 0, sizeof(SetDisplayMatrix3D_Params));

	if (!uFnSetDisplayMatrix3D)
	{
		return;
	}
	memcpy_s(&SetDisplayMatrix3D_Params.M, sizeof(SetDisplayMatrix3D_Params.M), &M, sizeof(M));

	uint16_t nativeIndex = uFnSetDisplayMatrix3D->iNative;
	uFnSetDisplayMatrix3D->iNative = 0;
	this->ProcessEvent(uFnSetDisplayMatrix3D, &SetDisplayMatrix3D_Params, nullptr);
	uFnSetDisplayMatrix3D->iNative = nativeIndex;
}

// Function GFxUI.GFxValue.SetDisplayMatrix
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// struct FMatrix                 M                              (CPF_Parm)

void UGFxValue::SetDisplayMatrix(const struct FMatrix& M)
{
	static UFunction* uFnSetDisplayMatrix = nullptr;

	if (!uFnSetDisplayMatrix)
	{
		uFnSetDisplayMatrix = UFunction::FindFunction("Function GFxUI.GFxValue.SetDisplayMatrix");
	}

	UGFxValue_execSetDisplayMatrix_Params SetDisplayMatrix_Params;
	memset(&SetDisplayMatrix_Params, 0, sizeof(SetDisplayMatrix_Params));

	if (!uFnSetDisplayMatrix)
	{
		return;
	}
	memcpy_s(&SetDisplayMatrix_Params.M, sizeof(SetDisplayMatrix_Params.M), &M, sizeof(M));

	uint16_t nativeIndex = uFnSetDisplayMatrix->iNative;
	uFnSetDisplayMatrix->iNative = 0;
	this->ProcessEvent(uFnSetDisplayMatrix, &SetDisplayMatrix_Params, nullptr);
	uFnSetDisplayMatrix->iNative = nativeIndex;
}

// Function GFxUI.GFxValue.SetDisplayInfo
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// struct FASDisplayInfo          D                              (CPF_Parm)

void UGFxValue::SetDisplayInfo(const struct FASDisplayInfo& D)
{
	static UFunction* uFnSetDisplayInfo = nullptr;

	if (!uFnSetDisplayInfo)
	{
		uFnSetDisplayInfo = UFunction::FindFunction("Function GFxUI.GFxValue.SetDisplayInfo");
	}

	UGFxValue_execSetDisplayInfo_Params SetDisplayInfo_Params;
	memset(&SetDisplayInfo_Params, 0, sizeof(SetDisplayInfo_Params));

	if (!uFnSetDisplayInfo)
	{
		return;
	}
	memcpy_s(&SetDisplayInfo_Params.D, sizeof(SetDisplayInfo_Params.D), &D, sizeof(D));

	uint16_t nativeIndex = uFnSetDisplayInfo->iNative;
	uFnSetDisplayInfo->iNative = 0;
	this->ProcessEvent(uFnSetDisplayInfo, &SetDisplayInfo_Params, nullptr);
	uFnSetDisplayInfo->iNative = nativeIndex;
}

// Function GFxUI.GFxValue.GetPosition
// [0x00420401] (FUNC_Final | FUNC_Native | FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          X                              (CPF_Parm | CPF_OutParm)
// float                          Y                              (CPF_Parm | CPF_OutParm)

bool UGFxValue::GetPosition(float& outX, float& outY)
{
	static UFunction* uFnGetPosition = nullptr;

	if (!uFnGetPosition)
	{
		uFnGetPosition = UFunction::FindFunction("Function GFxUI.GFxValue.GetPosition");
	}

	UGFxValue_execGetPosition_Params GetPosition_Params;
	memset(&GetPosition_Params, 0, sizeof(GetPosition_Params));

	if (!uFnGetPosition)
	{
		return GetPosition_Params.ReturnValue;
	}
	GetPosition_Params.X = outX;
	GetPosition_Params.Y = outY;

	uint16_t nativeIndex = uFnGetPosition->iNative;
	uFnGetPosition->iNative = 0;
	this->ProcessEvent(uFnGetPosition, &GetPosition_Params, nullptr);
	uFnGetPosition->iNative = nativeIndex;

	outX = GetPosition_Params.X;
	outY = GetPosition_Params.Y;

	return GetPosition_Params.ReturnValue;
}

// Function GFxUI.GFxValue.GetColorTransform
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// struct FASColorTransform       ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

struct FASColorTransform UGFxValue::GetColorTransform()
{
	static UFunction* uFnGetColorTransform = nullptr;

	if (!uFnGetColorTransform)
	{
		uFnGetColorTransform = UFunction::FindFunction("Function GFxUI.GFxValue.GetColorTransform");
	}

	UGFxValue_execGetColorTransform_Params GetColorTransform_Params;
	memset(&GetColorTransform_Params, 0, sizeof(GetColorTransform_Params));

	if (!uFnGetColorTransform)
	{
		return GetColorTransform_Params.ReturnValue;
	}

	uint16_t nativeIndex = uFnGetColorTransform->iNative;
	uFnGetColorTransform->iNative = 0;
	this->ProcessEvent(uFnGetColorTransform, &GetColorTransform_Params, nullptr);
	uFnGetColorTransform->iNative = nativeIndex;

	return GetColorTransform_Params.ReturnValue;
}

// Function GFxUI.GFxValue.GetDisplayMatrix
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// struct FMatrix                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

struct FMatrix UGFxValue::GetDisplayMatrix()
{
	static UFunction* uFnGetDisplayMatrix = nullptr;

	if (!uFnGetDisplayMatrix)
	{
		uFnGetDisplayMatrix = UFunction::FindFunction("Function GFxUI.GFxValue.GetDisplayMatrix");
	}

	UGFxValue_execGetDisplayMatrix_Params GetDisplayMatrix_Params;
	memset(&GetDisplayMatrix_Params, 0, sizeof(GetDisplayMatrix_Params));

	if (!uFnGetDisplayMatrix)
	{
		return GetDisplayMatrix_Params.ReturnValue;
	}

	uint16_t nativeIndex = uFnGetDisplayMatrix->iNative;
	uFnGetDisplayMatrix->iNative = 0;
	this->ProcessEvent(uFnGetDisplayMatrix, &GetDisplayMatrix_Params, nullptr);
	uFnGetDisplayMatrix->iNative = nativeIndex;

	return GetDisplayMatrix_Params.ReturnValue;
}

// Function GFxUI.GFxValue.GetDisplayInfo
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// struct FASDisplayInfo          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

struct FASDisplayInfo UGFxValue::GetDisplayInfo()
{
	static UFunction* uFnGetDisplayInfo = nullptr;

	if (!uFnGetDisplayInfo)
	{
		uFnGetDisplayInfo = UFunction::FindFunction("Function GFxUI.GFxValue.GetDisplayInfo");
	}

	UGFxValue_execGetDisplayInfo_Params GetDisplayInfo_Params;
	memset(&GetDisplayInfo_Params, 0, sizeof(GetDisplayInfo_Params));

	if (!uFnGetDisplayInfo)
	{
		return GetDisplayInfo_Params.ReturnValue;
	}

	uint16_t nativeIndex = uFnGetDisplayInfo->iNative;
	uFnGetDisplayInfo->iNative = 0;
	this->ProcessEvent(uFnGetDisplayInfo, &GetDisplayInfo_Params, nullptr);
	uFnGetDisplayInfo->iNative = nativeIndex;

	return GetDisplayInfo_Params.ReturnValue;
}

// Function GFxUI.GFxValue.SetString
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// class FString                  member                         (CPF_Parm | CPF_NeedCtorLink)
// class FString                  S                              (CPF_Parm | CPF_NeedCtorLink)

void UGFxValue::SetString(const class FString& member, const class FString& S)
{
	static UFunction* uFnSetString = nullptr;

	if (!uFnSetString)
	{
		uFnSetString = UFunction::FindFunction("Function GFxUI.GFxValue.SetString");
	}

	UGFxValue_execSetString_Params SetString_Params;
	memset(&SetString_Params, 0, sizeof(SetString_Params));

	if (!uFnSetString)
	{
		return;
	}
	memcpy_s(&SetString_Params.member, sizeof(SetString_Params.member), &member, sizeof(member));
	memcpy_s(&SetString_Params.S, sizeof(SetString_Params.S), &S, sizeof(S));

	uint16_t nativeIndex = uFnSetString->iNative;
	uFnSetString->iNative = 0;
	this->ProcessEvent(uFnSetString, &SetString_Params, nullptr);
	uFnSetString->iNative = nativeIndex;
}

// Function GFxUI.GFxValue.SetNumber
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// class FString                  member                         (CPF_Parm | CPF_NeedCtorLink)
// float                          F                              (CPF_Parm)

void UGFxValue::SetNumber(const class FString& member, float F)
{
	static UFunction* uFnSetNumber = nullptr;

	if (!uFnSetNumber)
	{
		uFnSetNumber = UFunction::FindFunction("Function GFxUI.GFxValue.SetNumber");
	}

	UGFxValue_execSetNumber_Params SetNumber_Params;
	memset(&SetNumber_Params, 0, sizeof(SetNumber_Params));

	if (!uFnSetNumber)
	{
		return;
	}
	memcpy_s(&SetNumber_Params.member, sizeof(SetNumber_Params.member), &member, sizeof(member));
	SetNumber_Params.F = F;

	uint16_t nativeIndex = uFnSetNumber->iNative;
	uFnSetNumber->iNative = 0;
	this->ProcessEvent(uFnSetNumber, &SetNumber_Params, nullptr);
	uFnSetNumber->iNative = nativeIndex;
}

// Function GFxUI.GFxValue.SetBool
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// class FString                  member                         (CPF_Parm | CPF_NeedCtorLink)
// uint32_t                       B                              (CPF_Parm)

void UGFxValue::SetBool(const class FString& member, bool B)
{
	static UFunction* uFnSetBool = nullptr;

	if (!uFnSetBool)
	{
		uFnSetBool = UFunction::FindFunction("Function GFxUI.GFxValue.SetBool");
	}

	UGFxValue_execSetBool_Params SetBool_Params;
	memset(&SetBool_Params, 0, sizeof(SetBool_Params));

	if (!uFnSetBool)
	{
		return;
	}
	memcpy_s(&SetBool_Params.member, sizeof(SetBool_Params.member), &member, sizeof(member));
	SetBool_Params.B = B;

	uint16_t nativeIndex = uFnSetBool->iNative;
	uFnSetBool->iNative = 0;
	this->ProcessEvent(uFnSetBool, &SetBool_Params, nullptr);
	uFnSetBool->iNative = nativeIndex;
}

// Function GFxUI.GFxValue.SetFunction
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// class FString                  member                         (CPF_Parm | CPF_NeedCtorLink)
// class UObject*                 context                        (CPF_Parm)
// class FName                    fname                          (CPF_Parm)

void UGFxValue::SetFunction(const class FString& member, class UObject* context, const class FName& fname)
{
	static UFunction* uFnSetFunction = nullptr;

	if (!uFnSetFunction)
	{
		uFnSetFunction = UFunction::FindFunction("Function GFxUI.GFxValue.SetFunction");
	}

	UGFxValue_execSetFunction_Params SetFunction_Params;
	memset(&SetFunction_Params, 0, sizeof(SetFunction_Params));

	if (!uFnSetFunction)
	{
		return;
	}
	memcpy_s(&SetFunction_Params.member, sizeof(SetFunction_Params.member), &member, sizeof(member));
	SetFunction_Params.context = context;
	memcpy_s(&SetFunction_Params.fname, sizeof(SetFunction_Params.fname), &fname, sizeof(fname));

	uint16_t nativeIndex = uFnSetFunction->iNative;
	uFnSetFunction->iNative = 0;
	this->ProcessEvent(uFnSetFunction, &SetFunction_Params, nullptr);
	uFnSetFunction->iNative = nativeIndex;
}

// Function GFxUI.GFxValue.SetObject
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// class FString                  member                         (CPF_Parm | CPF_NeedCtorLink)
// class UGFxValue*               val                            (CPF_Parm)

void UGFxValue::SetObject(const class FString& member, class UGFxValue* val)
{
	static UFunction* uFnSetObject = nullptr;

	if (!uFnSetObject)
	{
		uFnSetObject = UFunction::FindFunction("Function GFxUI.GFxValue.SetObject");
	}

	UGFxValue_execSetObject_Params SetObject_Params;
	memset(&SetObject_Params, 0, sizeof(SetObject_Params));

	if (!uFnSetObject)
	{
		return;
	}
	memcpy_s(&SetObject_Params.member, sizeof(SetObject_Params.member), &member, sizeof(member));
	SetObject_Params.val = val;

	uint16_t nativeIndex = uFnSetObject->iNative;
	uFnSetObject->iNative = 0;
	this->ProcessEvent(uFnSetObject, &SetObject_Params, nullptr);
	uFnSetObject->iNative = nativeIndex;
}

// Function GFxUI.GFxValue.Set
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// class FString                  member                         (CPF_Parm | CPF_NeedCtorLink)
// struct FASValue                Arg                            (CPF_Parm | CPF_NeedCtorLink)

void UGFxValue::Set(const class FString& member, const struct FASValue& Arg)
{
	static UFunction* uFnSet = nullptr;

	if (!uFnSet)
	{
		uFnSet = UFunction::FindFunction("Function GFxUI.GFxValue.Set");
	}

	UGFxValue_execSet_Params Set_Params;
	memset(&Set_Params, 0, sizeof(Set_Params));

	if (!uFnSet)
	{
		return;
	}
	memcpy_s(&Set_Params.member, sizeof(Set_Params.member), &member, sizeof(member));
	memcpy_s(&Set_Params.Arg, sizeof(Set_Params.Arg), &Arg, sizeof(Arg));

	uint16_t nativeIndex = uFnSet->iNative;
	uFnSet->iNative = 0;
	this->ProcessEvent(uFnSet, &Set_Params, nullptr);
	uFnSet->iNative = nativeIndex;
}

// Function GFxUI.GFxValue.GetString
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// class FString                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
// class FString                  member                         (CPF_Parm | CPF_NeedCtorLink)

class FString UGFxValue::GetString(const class FString& member)
{
	static UFunction* uFnGetString = nullptr;

	if (!uFnGetString)
	{
		uFnGetString = UFunction::FindFunction("Function GFxUI.GFxValue.GetString");
	}

	UGFxValue_execGetString_Params GetString_Params;
	memset(&GetString_Params, 0, sizeof(GetString_Params));

	if (!uFnGetString)
	{
		return GetString_Params.ReturnValue;
	}
	memcpy_s(&GetString_Params.member, sizeof(GetString_Params.member), &member, sizeof(member));

	uint16_t nativeIndex = uFnGetString->iNative;
	uFnGetString->iNative = 0;
	this->ProcessEvent(uFnGetString, &GetString_Params, nullptr);
	uFnGetString->iNative = nativeIndex;

	return GetString_Params.ReturnValue;
}

// Function GFxUI.GFxValue.GetNumber
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FString                  member                         (CPF_Parm | CPF_NeedCtorLink)

float UGFxValue::GetNumber(const class FString& member)
{
	static UFunction* uFnGetNumber = nullptr;

	if (!uFnGetNumber)
	{
		uFnGetNumber = UFunction::FindFunction("Function GFxUI.GFxValue.GetNumber");
	}

	UGFxValue_execGetNumber_Params GetNumber_Params;
	memset(&GetNumber_Params, 0, sizeof(GetNumber_Params));

	if (!uFnGetNumber)
	{
		return GetNumber_Params.ReturnValue;
	}
	memcpy_s(&GetNumber_Params.member, sizeof(GetNumber_Params.member), &member, sizeof(member));

	uint16_t nativeIndex = uFnGetNumber->iNative;
	uFnGetNumber->iNative = 0;
	this->ProcessEvent(uFnGetNumber, &GetNumber_Params, nullptr);
	uFnGetNumber->iNative = nativeIndex;

	return GetNumber_Params.ReturnValue;
}

// Function GFxUI.GFxValue.GetBool
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FString                  member                         (CPF_Parm | CPF_NeedCtorLink)

bool UGFxValue::GetBool(const class FString& member)
{
	static UFunction* uFnGetBool = nullptr;

	if (!uFnGetBool)
	{
		uFnGetBool = UFunction::FindFunction("Function GFxUI.GFxValue.GetBool");
	}

	UGFxValue_execGetBool_Params GetBool_Params;
	memset(&GetBool_Params, 0, sizeof(GetBool_Params));

	if (!uFnGetBool)
	{
		return GetBool_Params.ReturnValue;
	}
	memcpy_s(&GetBool_Params.member, sizeof(GetBool_Params.member), &member, sizeof(member));

	uint16_t nativeIndex = uFnGetBool->iNative;
	uFnGetBool->iNative = 0;
	this->ProcessEvent(uFnGetBool, &GetBool_Params, nullptr);
	uFnGetBool->iNative = nativeIndex;

	return GetBool_Params.ReturnValue;
}

// Function GFxUI.GFxValue.GetObject
// [0x00024401] (FUNC_Final | FUNC_Native | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// class UGFxValue*               ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FString                  member                         (CPF_Parm | CPF_NeedCtorLink)
// class UClass*                  Type                           (CPF_OptionalParm | CPF_Parm)

class UGFxValue* UGFxValue::GetObjectWin(const class FString& member, class UClass* optionalType)
{
	static UFunction* uFnGetObjectWin = nullptr;

	if (!uFnGetObjectWin)
	{
		uFnGetObjectWin = UFunction::FindFunction("Function GFxUI.GFxValue.GetObject");
	}

	UGFxValue_execGetObjectWin_Params GetObjectWin_Params;
	memset(&GetObjectWin_Params, 0, sizeof(GetObjectWin_Params));

	if (!uFnGetObjectWin)
	{
		return GetObjectWin_Params.ReturnValue;
	}
	memcpy_s(&GetObjectWin_Params.member, sizeof(GetObjectWin_Params.member), &member, sizeof(member));
	GetObjectWin_Params.Type = optionalType;

	uint16_t nativeIndex = uFnGetObjectWin->iNative;
	uFnGetObjectWin->iNative = 0;
	this->ProcessEvent(uFnGetObjectWin, &GetObjectWin_Params, nullptr);
	uFnGetObjectWin->iNative = nativeIndex;

	return GetObjectWin_Params.ReturnValue;
}

// Function GFxUI.GFxValue.Get
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// struct FASValue                ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
// class FString                  member                         (CPF_Parm | CPF_NeedCtorLink)

struct FASValue UGFxValue::Get(const class FString& member)
{
	static UFunction* uFnGet = nullptr;

	if (!uFnGet)
	{
		uFnGet = UFunction::FindFunction("Function GFxUI.GFxValue.Get");
	}

	UGFxValue_execGet_Params Get_Params;
	memset(&Get_Params, 0, sizeof(Get_Params));

	if (!uFnGet)
	{
		return Get_Params.ReturnValue;
	}
	memcpy_s(&Get_Params.member, sizeof(Get_Params.member), &member, sizeof(member));

	uint16_t nativeIndex = uFnGet->iNative;
	uFnGet->iNative = 0;
	this->ProcessEvent(uFnGet, &Get_Params, nullptr);
	uFnGet->iNative = nativeIndex;

	return Get_Params.ReturnValue;
}

// Function GFxUI.GFxValue.Invoke
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// struct FASValue                ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
// class FString                  member                         (CPF_Parm | CPF_NeedCtorLink)
// class TArray<struct FASValue>  args                           (CPF_Parm | CPF_NeedCtorLink)

struct FASValue UGFxValue::Invoke(const class FString& member, const class TArray<struct FASValue>& args)
{
	static UFunction* uFnInvoke = nullptr;

	if (!uFnInvoke)
	{
		uFnInvoke = UFunction::FindFunction("Function GFxUI.GFxValue.Invoke");
	}

	UGFxValue_execInvoke_Params Invoke_Params;
	memset(&Invoke_Params, 0, sizeof(Invoke_Params));

	if (!uFnInvoke)
	{
		return Invoke_Params.ReturnValue;
	}
	memcpy_s(&Invoke_Params.member, sizeof(Invoke_Params.member), &member, sizeof(member));
	memcpy_s(&Invoke_Params.args, sizeof(Invoke_Params.args), &args, sizeof(args));

	uint16_t nativeIndex = uFnInvoke->iNative;
	uFnInvoke->iNative = 0;
	this->ProcessEvent(uFnInvoke, &Invoke_Params, nullptr);
	uFnInvoke->iNative = nativeIndex;

	return Invoke_Params.ReturnValue;
}

// Function GFxUI.GFxAction_CloseMovie.IsValidLevelSequenceObject
// [0x00020802] (FUNC_Defined | FUNC_Event | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

bool UGFxAction_CloseMovie::eventIsValidLevelSequenceObject()
{
	static UFunction* uFnIsValidLevelSequenceObject = nullptr;

	if (!uFnIsValidLevelSequenceObject)
	{
		uFnIsValidLevelSequenceObject = UFunction::FindFunction("Function GFxUI.GFxAction_CloseMovie.IsValidLevelSequenceObject");
	}

	UGFxAction_CloseMovie_eventIsValidLevelSequenceObject_Params IsValidLevelSequenceObject_Params;
	memset(&IsValidLevelSequenceObject_Params, 0, sizeof(IsValidLevelSequenceObject_Params));

	if (!uFnIsValidLevelSequenceObject)
	{
		return IsValidLevelSequenceObject_Params.ReturnValue;
	}

	this->ProcessEvent(uFnIsValidLevelSequenceObject, &IsValidLevelSequenceObject_Params, nullptr);

	return IsValidLevelSequenceObject_Params.ReturnValue;
}

// Function GFxUI.GFxAction_GetVariable.IsValidLevelSequenceObject
// [0x00020802] (FUNC_Defined | FUNC_Event | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

bool UGFxAction_GetVariable::eventIsValidLevelSequenceObject()
{
	static UFunction* uFnIsValidLevelSequenceObject = nullptr;

	if (!uFnIsValidLevelSequenceObject)
	{
		uFnIsValidLevelSequenceObject = UFunction::FindFunction("Function GFxUI.GFxAction_GetVariable.IsValidLevelSequenceObject");
	}

	UGFxAction_GetVariable_eventIsValidLevelSequenceObject_Params IsValidLevelSequenceObject_Params;
	memset(&IsValidLevelSequenceObject_Params, 0, sizeof(IsValidLevelSequenceObject_Params));

	if (!uFnIsValidLevelSequenceObject)
	{
		return IsValidLevelSequenceObject_Params.ReturnValue;
	}

	this->ProcessEvent(uFnIsValidLevelSequenceObject, &IsValidLevelSequenceObject_Params, nullptr);

	return IsValidLevelSequenceObject_Params.ReturnValue;
}

// Function GFxUI.GFxAction_Invoke.IsValidLevelSequenceObject
// [0x00020802] (FUNC_Defined | FUNC_Event | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

bool UGFxAction_Invoke::eventIsValidLevelSequenceObject()
{
	static UFunction* uFnIsValidLevelSequenceObject = nullptr;

	if (!uFnIsValidLevelSequenceObject)
	{
		uFnIsValidLevelSequenceObject = UFunction::FindFunction("Function GFxUI.GFxAction_Invoke.IsValidLevelSequenceObject");
	}

	UGFxAction_Invoke_eventIsValidLevelSequenceObject_Params IsValidLevelSequenceObject_Params;
	memset(&IsValidLevelSequenceObject_Params, 0, sizeof(IsValidLevelSequenceObject_Params));

	if (!uFnIsValidLevelSequenceObject)
	{
		return IsValidLevelSequenceObject_Params.ReturnValue;
	}

	this->ProcessEvent(uFnIsValidLevelSequenceObject, &IsValidLevelSequenceObject_Params, nullptr);

	return IsValidLevelSequenceObject_Params.ReturnValue;
}

// Function GFxUI.GFxAction_OpenMovie.IsValidLevelSequenceObject
// [0x00020802] (FUNC_Defined | FUNC_Event | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

bool UGFxAction_OpenMovie::eventIsValidLevelSequenceObject()
{
	static UFunction* uFnIsValidLevelSequenceObject = nullptr;

	if (!uFnIsValidLevelSequenceObject)
	{
		uFnIsValidLevelSequenceObject = UFunction::FindFunction("Function GFxUI.GFxAction_OpenMovie.IsValidLevelSequenceObject");
	}

	UGFxAction_OpenMovie_eventIsValidLevelSequenceObject_Params IsValidLevelSequenceObject_Params;
	memset(&IsValidLevelSequenceObject_Params, 0, sizeof(IsValidLevelSequenceObject_Params));

	if (!uFnIsValidLevelSequenceObject)
	{
		return IsValidLevelSequenceObject_Params.ReturnValue;
	}

	this->ProcessEvent(uFnIsValidLevelSequenceObject, &IsValidLevelSequenceObject_Params, nullptr);

	return IsValidLevelSequenceObject_Params.ReturnValue;
}

// Function GFxUI.GFxAction_SetVariable.IsValidLevelSequenceObject
// [0x00020802] (FUNC_Defined | FUNC_Event | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

bool UGFxAction_SetVariable::eventIsValidLevelSequenceObject()
{
	static UFunction* uFnIsValidLevelSequenceObject = nullptr;

	if (!uFnIsValidLevelSequenceObject)
	{
		uFnIsValidLevelSequenceObject = UFunction::FindFunction("Function GFxUI.GFxAction_SetVariable.IsValidLevelSequenceObject");
	}

	UGFxAction_SetVariable_eventIsValidLevelSequenceObject_Params IsValidLevelSequenceObject_Params;
	memset(&IsValidLevelSequenceObject_Params, 0, sizeof(IsValidLevelSequenceObject_Params));

	if (!uFnIsValidLevelSequenceObject)
	{
		return IsValidLevelSequenceObject_Params.ReturnValue;
	}

	this->ProcessEvent(uFnIsValidLevelSequenceObject, &IsValidLevelSequenceObject_Params, nullptr);

	return IsValidLevelSequenceObject_Params.ReturnValue;
}

// Function GFxUI.GFxFSCmdHandler_Kismet.FSCommand
// [0x00020C00] (FUNC_Native | FUNC_Event | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class UGFxMovie*               Movie                          (CPF_Parm)
// class FString                  Cmd                            (CPF_Parm | CPF_NeedCtorLink)
// class FString                  Arg                            (CPF_Parm | CPF_NeedCtorLink)

bool UGFxFSCmdHandler_Kismet::eventFSCommand(class UGFxMovie* Movie, const class FString& Cmd, const class FString& Arg)
{
	static UFunction* uFnFSCommand = nullptr;

	if (!uFnFSCommand)
	{
		uFnFSCommand = UFunction::FindFunction("Function GFxUI.GFxFSCmdHandler_Kismet.FSCommand");
	}

	UGFxFSCmdHandler_Kismet_eventFSCommand_Params FSCommand_Params;
	memset(&FSCommand_Params, 0, sizeof(FSCommand_Params));

	if (!uFnFSCommand)
	{
		return FSCommand_Params.ReturnValue;
	}
	FSCommand_Params.Movie = Movie;
	memcpy_s(&FSCommand_Params.Cmd, sizeof(FSCommand_Params.Cmd), &Cmd, sizeof(Cmd));
	memcpy_s(&FSCommand_Params.Arg, sizeof(FSCommand_Params.Arg), &Arg, sizeof(Arg));

	uint16_t nativeIndex = uFnFSCommand->iNative;
	uFnFSCommand->iNative = 0;
	this->ProcessEvent(uFnFSCommand, &FSCommand_Params, nullptr);
	uFnFSCommand->iNative = nativeIndex;

	return FSCommand_Params.ReturnValue;
}

// Function GFxUI.GFxDataStoreSubscriber.SaveSubscriberValue
// [0x00424400] (FUNC_Native | FUNC_OptionalParm | FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        BindingIndex                   (CPF_OptionalParm | CPF_Parm)
// class TArray<class UUIDataStore*> out_BoundDataStores            (CPF_Parm | CPF_OutParm | CPF_NeedCtorLink)

bool UGFxDataStoreSubscriber::SaveSubscriberValue(int32_t optionalBindingIndex, class TArray<class UUIDataStore*>& outOut_BoundDataStores)
{
	static UFunction* uFnSaveSubscriberValue = nullptr;

	if (!uFnSaveSubscriberValue)
	{
		uFnSaveSubscriberValue = UFunction::FindFunction("Function GFxUI.GFxDataStoreSubscriber.SaveSubscriberValue");
	}

	UGFxDataStoreSubscriber_execSaveSubscriberValue_Params SaveSubscriberValue_Params;
	memset(&SaveSubscriberValue_Params, 0, sizeof(SaveSubscriberValue_Params));

	if (!uFnSaveSubscriberValue)
	{
		return SaveSubscriberValue_Params.ReturnValue;
	}
	SaveSubscriberValue_Params.BindingIndex = optionalBindingIndex;
	memcpy_s(&SaveSubscriberValue_Params.out_BoundDataStores, sizeof(SaveSubscriberValue_Params.out_BoundDataStores), &outOut_BoundDataStores, sizeof(outOut_BoundDataStores));

	uint16_t nativeIndex = uFnSaveSubscriberValue->iNative;
	uFnSaveSubscriberValue->iNative = 0;
	this->ProcessEvent(uFnSaveSubscriberValue, &SaveSubscriberValue_Params, nullptr);
	uFnSaveSubscriberValue->iNative = nativeIndex;

	memcpy_s(&outOut_BoundDataStores, sizeof(outOut_BoundDataStores), &SaveSubscriberValue_Params.out_BoundDataStores, sizeof(SaveSubscriberValue_Params.out_BoundDataStores));

	return SaveSubscriberValue_Params.ReturnValue;
}

// Function GFxUI.GFxDataStoreSubscriber.ClearBoundDataStores
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:

void UGFxDataStoreSubscriber::ClearBoundDataStores()
{
	static UFunction* uFnClearBoundDataStores = nullptr;

	if (!uFnClearBoundDataStores)
	{
		uFnClearBoundDataStores = UFunction::FindFunction("Function GFxUI.GFxDataStoreSubscriber.ClearBoundDataStores");
	}

	UGFxDataStoreSubscriber_execClearBoundDataStores_Params ClearBoundDataStores_Params;
	memset(&ClearBoundDataStores_Params, 0, sizeof(ClearBoundDataStores_Params));

	if (!uFnClearBoundDataStores)
	{
		return;
	}

	uint16_t nativeIndex = uFnClearBoundDataStores->iNative;
	uFnClearBoundDataStores->iNative = 0;
	this->ProcessEvent(uFnClearBoundDataStores, &ClearBoundDataStores_Params, nullptr);
	uFnClearBoundDataStores->iNative = nativeIndex;
}

// Function GFxUI.GFxDataStoreSubscriber.GetBoundDataStores
// [0x00420401] (FUNC_Final | FUNC_Native | FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// class TArray<class UUIDataStore*> out_BoundDataStores            (CPF_Parm | CPF_OutParm | CPF_NeedCtorLink)

void UGFxDataStoreSubscriber::GetBoundDataStores(class TArray<class UUIDataStore*>& outOut_BoundDataStores)
{
	static UFunction* uFnGetBoundDataStores = nullptr;

	if (!uFnGetBoundDataStores)
	{
		uFnGetBoundDataStores = UFunction::FindFunction("Function GFxUI.GFxDataStoreSubscriber.GetBoundDataStores");
	}

	UGFxDataStoreSubscriber_execGetBoundDataStores_Params GetBoundDataStores_Params;
	memset(&GetBoundDataStores_Params, 0, sizeof(GetBoundDataStores_Params));

	if (!uFnGetBoundDataStores)
	{
		return;
	}
	memcpy_s(&GetBoundDataStores_Params.out_BoundDataStores, sizeof(GetBoundDataStores_Params.out_BoundDataStores), &outOut_BoundDataStores, sizeof(outOut_BoundDataStores));

	uint16_t nativeIndex = uFnGetBoundDataStores->iNative;
	uFnGetBoundDataStores->iNative = 0;
	this->ProcessEvent(uFnGetBoundDataStores, &GetBoundDataStores_Params, nullptr);
	uFnGetBoundDataStores->iNative = nativeIndex;

	memcpy_s(&outOut_BoundDataStores, sizeof(outOut_BoundDataStores), &GetBoundDataStores_Params.out_BoundDataStores, sizeof(GetBoundDataStores_Params.out_BoundDataStores));
}

// Function GFxUI.GFxDataStoreSubscriber.NotifyDataStoreValueUpdated
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// class UUIDataStore*            SourceDataStore                (CPF_Parm)
// uint32_t                       bValuesInvalidated             (CPF_Parm)
// class FName                    PropertyTag                    (CPF_Parm)
// class UUIDataProvider*         SourceProvider                 (CPF_Parm)
// int32_t                        ArrayIndex                     (CPF_Parm)

void UGFxDataStoreSubscriber::NotifyDataStoreValueUpdated(class UUIDataStore* SourceDataStore, bool bValuesInvalidated, const class FName& PropertyTag, class UUIDataProvider* SourceProvider, int32_t ArrayIndex)
{
	static UFunction* uFnNotifyDataStoreValueUpdated = nullptr;

	if (!uFnNotifyDataStoreValueUpdated)
	{
		uFnNotifyDataStoreValueUpdated = UFunction::FindFunction("Function GFxUI.GFxDataStoreSubscriber.NotifyDataStoreValueUpdated");
	}

	UGFxDataStoreSubscriber_execNotifyDataStoreValueUpdated_Params NotifyDataStoreValueUpdated_Params;
	memset(&NotifyDataStoreValueUpdated_Params, 0, sizeof(NotifyDataStoreValueUpdated_Params));

	if (!uFnNotifyDataStoreValueUpdated)
	{
		return;
	}
	NotifyDataStoreValueUpdated_Params.SourceDataStore = SourceDataStore;
	NotifyDataStoreValueUpdated_Params.bValuesInvalidated = bValuesInvalidated;
	memcpy_s(&NotifyDataStoreValueUpdated_Params.PropertyTag, sizeof(NotifyDataStoreValueUpdated_Params.PropertyTag), &PropertyTag, sizeof(PropertyTag));
	NotifyDataStoreValueUpdated_Params.SourceProvider = SourceProvider;
	NotifyDataStoreValueUpdated_Params.ArrayIndex = ArrayIndex;

	uint16_t nativeIndex = uFnNotifyDataStoreValueUpdated->iNative;
	uFnNotifyDataStoreValueUpdated->iNative = 0;
	this->ProcessEvent(uFnNotifyDataStoreValueUpdated, &NotifyDataStoreValueUpdated_Params, nullptr);
	uFnNotifyDataStoreValueUpdated->iNative = nativeIndex;
}

// Function GFxUI.GFxDataStoreSubscriber.RefreshSubscriberValue
// [0x00024401] (FUNC_Final | FUNC_Native | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        BindingIndex                   (CPF_OptionalParm | CPF_Parm)

bool UGFxDataStoreSubscriber::RefreshSubscriberValue(int32_t optionalBindingIndex)
{
	static UFunction* uFnRefreshSubscriberValue = nullptr;

	if (!uFnRefreshSubscriberValue)
	{
		uFnRefreshSubscriberValue = UFunction::FindFunction("Function GFxUI.GFxDataStoreSubscriber.RefreshSubscriberValue");
	}

	UGFxDataStoreSubscriber_execRefreshSubscriberValue_Params RefreshSubscriberValue_Params;
	memset(&RefreshSubscriberValue_Params, 0, sizeof(RefreshSubscriberValue_Params));

	if (!uFnRefreshSubscriberValue)
	{
		return RefreshSubscriberValue_Params.ReturnValue;
	}
	RefreshSubscriberValue_Params.BindingIndex = optionalBindingIndex;

	uint16_t nativeIndex = uFnRefreshSubscriberValue->iNative;
	uFnRefreshSubscriberValue->iNative = 0;
	this->ProcessEvent(uFnRefreshSubscriberValue, &RefreshSubscriberValue_Params, nullptr);
	uFnRefreshSubscriberValue->iNative = nativeIndex;

	return RefreshSubscriberValue_Params.ReturnValue;
}

// Function GFxUI.GFxDataStoreSubscriber.GetDataStoreBinding
// [0x00024401] (FUNC_Final | FUNC_Native | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// class FString                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
// int32_t                        BindingIndex                   (CPF_OptionalParm | CPF_Parm)

class FString UGFxDataStoreSubscriber::GetDataStoreBinding(int32_t optionalBindingIndex)
{
	static UFunction* uFnGetDataStoreBinding = nullptr;

	if (!uFnGetDataStoreBinding)
	{
		uFnGetDataStoreBinding = UFunction::FindFunction("Function GFxUI.GFxDataStoreSubscriber.GetDataStoreBinding");
	}

	UGFxDataStoreSubscriber_execGetDataStoreBinding_Params GetDataStoreBinding_Params;
	memset(&GetDataStoreBinding_Params, 0, sizeof(GetDataStoreBinding_Params));

	if (!uFnGetDataStoreBinding)
	{
		return GetDataStoreBinding_Params.ReturnValue;
	}
	GetDataStoreBinding_Params.BindingIndex = optionalBindingIndex;

	uint16_t nativeIndex = uFnGetDataStoreBinding->iNative;
	uFnGetDataStoreBinding->iNative = 0;
	this->ProcessEvent(uFnGetDataStoreBinding, &GetDataStoreBinding_Params, nullptr);
	uFnGetDataStoreBinding->iNative = nativeIndex;

	return GetDataStoreBinding_Params.ReturnValue;
}

// Function GFxUI.GFxDataStoreSubscriber.SetDataStoreBinding
// [0x00024401] (FUNC_Final | FUNC_Native | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// class FString                  MarkupText                     (CPF_Parm | CPF_NeedCtorLink)
// int32_t                        BindingIndex                   (CPF_OptionalParm | CPF_Parm)

void UGFxDataStoreSubscriber::SetDataStoreBinding(const class FString& MarkupText, int32_t optionalBindingIndex)
{
	static UFunction* uFnSetDataStoreBinding = nullptr;

	if (!uFnSetDataStoreBinding)
	{
		uFnSetDataStoreBinding = UFunction::FindFunction("Function GFxUI.GFxDataStoreSubscriber.SetDataStoreBinding");
	}

	UGFxDataStoreSubscriber_execSetDataStoreBinding_Params SetDataStoreBinding_Params;
	memset(&SetDataStoreBinding_Params, 0, sizeof(SetDataStoreBinding_Params));

	if (!uFnSetDataStoreBinding)
	{
		return;
	}
	memcpy_s(&SetDataStoreBinding_Params.MarkupText, sizeof(SetDataStoreBinding_Params.MarkupText), &MarkupText, sizeof(MarkupText));
	SetDataStoreBinding_Params.BindingIndex = optionalBindingIndex;

	uint16_t nativeIndex = uFnSetDataStoreBinding->iNative;
	uFnSetDataStoreBinding->iNative = 0;
	this->ProcessEvent(uFnSetDataStoreBinding, &SetDataStoreBinding_Params, nullptr);
	uFnSetDataStoreBinding->iNative = nativeIndex;
}

// Function GFxUI.GFxDataStoreSubscriber.PublishValues
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:

void UGFxDataStoreSubscriber::PublishValues()
{
	static UFunction* uFnPublishValues = nullptr;

	if (!uFnPublishValues)
	{
		uFnPublishValues = UFunction::FindFunction("Function GFxUI.GFxDataStoreSubscriber.PublishValues");
	}

	UGFxDataStoreSubscriber_execPublishValues_Params PublishValues_Params;
	memset(&PublishValues_Params, 0, sizeof(PublishValues_Params));

	if (!uFnPublishValues)
	{
		return;
	}

	uint16_t nativeIndex = uFnPublishValues->iNative;
	uFnPublishValues->iNative = 0;
	this->ProcessEvent(uFnPublishValues, &PublishValues_Params, nullptr);
	uFnPublishValues->iNative = nativeIndex;
}

/*
# ========================================================================================= #
#
# ========================================================================================= #
*/

#ifdef _MSC_VER
#pragma pack(pop)
#endif
