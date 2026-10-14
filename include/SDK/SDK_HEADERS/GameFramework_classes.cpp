/*
#############################################################################################
# Alice2 (ASDK) SDK 1.0.0.0
# Generated with the CodeRedGenerator v1.2.0
# ========================================================================================= #
# File: GameFramework_classes.cpp
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

// Function GameFramework.GameAIController.GetActionString
// [0x00020903] (FUNC_Final | FUNC_Defined | FUNC_Simulated | FUNC_Event | FUNC_Public)
// Parameter Info:
// class FString                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)

class FString AGameAIController::eventGetActionString()
{
	static UFunction* uFnGetActionString = nullptr;

	if (!uFnGetActionString)
	{
		uFnGetActionString = UFunction::FindFunction("Function GameFramework.GameAIController.GetActionString");
	}

	AGameAIController_eventGetActionString_Params GetActionString_Params;
	memset(&GetActionString_Params, 0, sizeof(GetActionString_Params));

	if (!uFnGetActionString)
	{
		return GetActionString_Params.ReturnValue;
	}

	this->ProcessEvent(uFnGetActionString, &GetActionString_Params, nullptr);

	return GetActionString_Params.ReturnValue;
}

// Function GameFramework.GameAIController.GeneratePathToLocation
// [0x00024800] (FUNC_Event | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 Goal                           (CPF_Parm)
// float                          WithinDistance                 (CPF_OptionalParm | CPF_Parm)
// uint32_t                       bAllowPartialPath              (CPF_OptionalParm | CPF_Parm)

bool AGameAIController::eventGeneratePathToLocation(const struct FVector& Goal, float optionalWithinDistance, bool optionalBAllowPartialPath)
{
	static UFunction* uFnGeneratePathToLocation = nullptr;

	if (!uFnGeneratePathToLocation)
	{
		uFnGeneratePathToLocation = UFunction::FindFunction("Function GameFramework.GameAIController.GeneratePathToLocation");
	}

	AGameAIController_eventGeneratePathToLocation_Params GeneratePathToLocation_Params;
	memset(&GeneratePathToLocation_Params, 0, sizeof(GeneratePathToLocation_Params));

	if (!uFnGeneratePathToLocation)
	{
		return GeneratePathToLocation_Params.ReturnValue;
	}
	memcpy_s(&GeneratePathToLocation_Params.Goal, sizeof(GeneratePathToLocation_Params.Goal), &Goal, sizeof(Goal));
	GeneratePathToLocation_Params.WithinDistance = optionalWithinDistance;
	GeneratePathToLocation_Params.bAllowPartialPath = optionalBAllowPartialPath;

	this->ProcessEvent(uFnGeneratePathToLocation, &GeneratePathToLocation_Params, nullptr);

	return GeneratePathToLocation_Params.ReturnValue;
}

// Function GameFramework.GameAIController.GeneratePathToActor
// [0x00024800] (FUNC_Event | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class AActor*                  Goal                           (CPF_Parm)
// float                          WithinDistance                 (CPF_OptionalParm | CPF_Parm)
// uint32_t                       bAllowPartialPath              (CPF_OptionalParm | CPF_Parm)

bool AGameAIController::eventGeneratePathToActor(class AActor* Goal, float optionalWithinDistance, bool optionalBAllowPartialPath)
{
	static UFunction* uFnGeneratePathToActor = nullptr;

	if (!uFnGeneratePathToActor)
	{
		uFnGeneratePathToActor = UFunction::FindFunction("Function GameFramework.GameAIController.GeneratePathToActor");
	}

	AGameAIController_eventGeneratePathToActor_Params GeneratePathToActor_Params;
	memset(&GeneratePathToActor_Params, 0, sizeof(GeneratePathToActor_Params));

	if (!uFnGeneratePathToActor)
	{
		return GeneratePathToActor_Params.ReturnValue;
	}
	GeneratePathToActor_Params.Goal = Goal;
	GeneratePathToActor_Params.WithinDistance = optionalWithinDistance;
	GeneratePathToActor_Params.bAllowPartialPath = optionalBAllowPartialPath;

	this->ProcessEvent(uFnGeneratePathToActor, &GeneratePathToActor_Params, nullptr);

	return GeneratePathToActor_Params.ReturnValue;
}

// Function GameFramework.GameAIController.SetDesiredRotation
// [0x00024002] (FUNC_Defined | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// struct FRotator                TargetDesiredRotation          (CPF_Parm)
// uint32_t                       InLockDesiredRotation          (CPF_OptionalParm | CPF_Parm)
// uint32_t                       InUnlockWhenReached            (CPF_OptionalParm | CPF_Parm)
// float                          InterpolationTime              (CPF_OptionalParm | CPF_Parm)

void AGameAIController::SetDesiredRotation(const struct FRotator& TargetDesiredRotation, bool optionalInLockDesiredRotation, bool optionalInUnlockWhenReached, float optionalInterpolationTime)
{
	static UFunction* uFnSetDesiredRotation = nullptr;

	if (!uFnSetDesiredRotation)
	{
		uFnSetDesiredRotation = UFunction::FindFunction("Function GameFramework.GameAIController.SetDesiredRotation");
	}

	AGameAIController_execSetDesiredRotation_Params SetDesiredRotation_Params;
	memset(&SetDesiredRotation_Params, 0, sizeof(SetDesiredRotation_Params));

	if (!uFnSetDesiredRotation)
	{
		return;
	}
	memcpy_s(&SetDesiredRotation_Params.TargetDesiredRotation, sizeof(SetDesiredRotation_Params.TargetDesiredRotation), &TargetDesiredRotation, sizeof(TargetDesiredRotation));
	SetDesiredRotation_Params.InLockDesiredRotation = optionalInLockDesiredRotation;
	SetDesiredRotation_Params.InUnlockWhenReached = optionalInUnlockWhenReached;
	SetDesiredRotation_Params.InterpolationTime = optionalInterpolationTime;

	this->ProcessEvent(uFnSetDesiredRotation, &SetDesiredRotation_Params, nullptr);
}

// Function GameFramework.GameAIController.AILog_Internal
// [0x00024802] (FUNC_Defined | FUNC_Event | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// class FString                  LogText                        (CPF_Parm | CPF_CoerceParm | CPF_NeedCtorLink)
// class FName                    LogCategory                    (CPF_OptionalParm | CPF_Parm)
// uint32_t                       bForce                         (CPF_OptionalParm | CPF_Parm)

void AGameAIController::eventAILog_Internal(const class FString& LogText, const class FName& optionalLogCategory, bool optionalBForce)
{
	static UFunction* uFnAILog_Internal = nullptr;

	if (!uFnAILog_Internal)
	{
		uFnAILog_Internal = UFunction::FindFunction("Function GameFramework.GameAIController.AILog_Internal");
	}

	AGameAIController_eventAILog_Internal_Params AILog_Internal_Params;
	memset(&AILog_Internal_Params, 0, sizeof(AILog_Internal_Params));

	if (!uFnAILog_Internal)
	{
		return;
	}
	memcpy_s(&AILog_Internal_Params.LogText, sizeof(AILog_Internal_Params.LogText), &LogText, sizeof(LogText));
	memcpy_s(&AILog_Internal_Params.LogCategory, sizeof(AILog_Internal_Params.LogCategory), &optionalLogCategory, sizeof(optionalLogCategory));
	AILog_Internal_Params.bForce = optionalBForce;

	this->ProcessEvent(uFnAILog_Internal, &AILog_Internal_Params, nullptr);
}

// Function GameFramework.GameAIController.RecordDemoAILog
// [0x00080000] (FUNC_Protected)
// Parameter Info:
// class FString                  LogText                        (CPF_Parm | CPF_CoerceParm | CPF_NeedCtorLink)

void AGameAIController::RecordDemoAILog(const class FString& LogText)
{
	static UFunction* uFnRecordDemoAILog = nullptr;

	if (!uFnRecordDemoAILog)
	{
		uFnRecordDemoAILog = UFunction::FindFunction("Function GameFramework.GameAIController.RecordDemoAILog");
	}

	AGameAIController_execRecordDemoAILog_Params RecordDemoAILog_Params;
	memset(&RecordDemoAILog_Params, 0, sizeof(RecordDemoAILog_Params));

	if (!uFnRecordDemoAILog)
	{
		return;
	}
	memcpy_s(&RecordDemoAILog_Params.LogText, sizeof(RecordDemoAILog_Params.LogText), &LogText, sizeof(LogText));

	this->ProcessEvent(uFnRecordDemoAILog, &RecordDemoAILog_Params, nullptr);
}

// Function GameFramework.GameAIController.Destroyed
// [0x00020802] (FUNC_Defined | FUNC_Event | FUNC_Public)
// Parameter Info:

void AGameAIController::eventDestroyed()
{
	static UFunction* uFnDestroyed = nullptr;

	if (!uFnDestroyed)
	{
		uFnDestroyed = UFunction::FindFunction("Function GameFramework.GameAIController.Destroyed");
	}

	AGameAIController_eventDestroyed_Params Destroyed_Params;
	memset(&Destroyed_Params, 0, sizeof(Destroyed_Params));

	if (!uFnDestroyed)
	{
		return;
	}

	this->ProcessEvent(uFnDestroyed, &Destroyed_Params, nullptr);
}

// Function GameFramework.GameAIController.GetAICommandInStack
// [0x00020400] (FUNC_Native | FUNC_Public)
// Parameter Info:
// class UGameAICommand*          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class UClass*                  InClass                        (CPF_Const | CPF_Parm)

class UGameAICommand* AGameAIController::GetAICommandInStack(class UClass* InClass)
{
	static UFunction* uFnGetAICommandInStack = nullptr;

	if (!uFnGetAICommandInStack)
	{
		uFnGetAICommandInStack = UFunction::FindFunction("Function GameFramework.GameAIController.GetAICommandInStack");
	}

	AGameAIController_execGetAICommandInStack_Params GetAICommandInStack_Params;
	memset(&GetAICommandInStack_Params, 0, sizeof(GetAICommandInStack_Params));

	if (!uFnGetAICommandInStack)
	{
		return GetAICommandInStack_Params.ReturnValue;
	}
	GetAICommandInStack_Params.InClass = InClass;

	uint16_t nativeIndex = uFnGetAICommandInStack->iNative;
	uFnGetAICommandInStack->iNative = 0;
	this->ProcessEvent(uFnGetAICommandInStack, &GetAICommandInStack_Params, nullptr);
	uFnGetAICommandInStack->iNative = nativeIndex;

	return GetAICommandInStack_Params.ReturnValue;
}

// Function GameFramework.GameAIController.FindCommandOfClass
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// class UGameAICommand*          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_CoerceParm)
// class UClass*                  SearchClass                    (CPF_Parm)

class UGameAICommand* AGameAIController::FindCommandOfClass(class UClass* SearchClass)
{
	static UFunction* uFnFindCommandOfClass = nullptr;

	if (!uFnFindCommandOfClass)
	{
		uFnFindCommandOfClass = UFunction::FindFunction("Function GameFramework.GameAIController.FindCommandOfClass");
	}

	AGameAIController_execFindCommandOfClass_Params FindCommandOfClass_Params;
	memset(&FindCommandOfClass_Params, 0, sizeof(FindCommandOfClass_Params));

	if (!uFnFindCommandOfClass)
	{
		return FindCommandOfClass_Params.ReturnValue;
	}
	FindCommandOfClass_Params.SearchClass = SearchClass;

	uint16_t nativeIndex = uFnFindCommandOfClass->iNative;
	uFnFindCommandOfClass->iNative = 0;
	this->ProcessEvent(uFnFindCommandOfClass, &FindCommandOfClass_Params, nullptr);
	uFnFindCommandOfClass->iNative = nativeIndex;

	return FindCommandOfClass_Params.ReturnValue;
}

// Function GameFramework.GameAIController.DumpCommandStack
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:

void AGameAIController::DumpCommandStack()
{
	static UFunction* uFnDumpCommandStack = nullptr;

	if (!uFnDumpCommandStack)
	{
		uFnDumpCommandStack = UFunction::FindFunction("Function GameFramework.GameAIController.DumpCommandStack");
	}

	AGameAIController_execDumpCommandStack_Params DumpCommandStack_Params;
	memset(&DumpCommandStack_Params, 0, sizeof(DumpCommandStack_Params));

	if (!uFnDumpCommandStack)
	{
		return;
	}

	uint16_t nativeIndex = uFnDumpCommandStack->iNative;
	uFnDumpCommandStack->iNative = 0;
	this->ProcessEvent(uFnDumpCommandStack, &DumpCommandStack_Params, nullptr);
	uFnDumpCommandStack->iNative = nativeIndex;
}

// Function GameFramework.GameAIController.CheckCommandCount
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:

void AGameAIController::CheckCommandCount()
{
	static UFunction* uFnCheckCommandCount = nullptr;

	if (!uFnCheckCommandCount)
	{
		uFnCheckCommandCount = UFunction::FindFunction("Function GameFramework.GameAIController.CheckCommandCount");
	}

	AGameAIController_execCheckCommandCount_Params CheckCommandCount_Params;
	memset(&CheckCommandCount_Params, 0, sizeof(CheckCommandCount_Params));

	if (!uFnCheckCommandCount)
	{
		return;
	}

	uint16_t nativeIndex = uFnCheckCommandCount->iNative;
	uFnCheckCommandCount->iNative = 0;
	this->ProcessEvent(uFnCheckCommandCount, &CheckCommandCount_Params, nullptr);
	uFnCheckCommandCount->iNative = nativeIndex;
}

// Function GameFramework.GameAIController.GetActiveCommand
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// class UGameAICommand*          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

class UGameAICommand* AGameAIController::GetActiveCommand()
{
	static UFunction* uFnGetActiveCommand = nullptr;

	if (!uFnGetActiveCommand)
	{
		uFnGetActiveCommand = UFunction::FindFunction("Function GameFramework.GameAIController.GetActiveCommand");
	}

	AGameAIController_execGetActiveCommand_Params GetActiveCommand_Params;
	memset(&GetActiveCommand_Params, 0, sizeof(GetActiveCommand_Params));

	if (!uFnGetActiveCommand)
	{
		return GetActiveCommand_Params.ReturnValue;
	}

	uint16_t nativeIndex = uFnGetActiveCommand->iNative;
	uFnGetActiveCommand->iNative = 0;
	this->ProcessEvent(uFnGetActiveCommand, &GetActiveCommand_Params, nullptr);
	uFnGetActiveCommand->iNative = nativeIndex;

	return GetActiveCommand_Params.ReturnValue;
}

// Function GameFramework.GameAIController.AbortCommand
// [0x00024401] (FUNC_Final | FUNC_Native | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class UGameAICommand*          AbortCmd                       (CPF_Parm)
// class UClass*                  AbortClass                     (CPF_OptionalParm | CPF_Parm)

bool AGameAIController::AbortCommand(class UGameAICommand* AbortCmd, class UClass* optionalAbortClass)
{
	static UFunction* uFnAbortCommand = nullptr;

	if (!uFnAbortCommand)
	{
		uFnAbortCommand = UFunction::FindFunction("Function GameFramework.GameAIController.AbortCommand");
	}

	AGameAIController_execAbortCommand_Params AbortCommand_Params;
	memset(&AbortCommand_Params, 0, sizeof(AbortCommand_Params));

	if (!uFnAbortCommand)
	{
		return AbortCommand_Params.ReturnValue;
	}
	AbortCommand_Params.AbortCmd = AbortCmd;
	AbortCommand_Params.AbortClass = optionalAbortClass;

	uint16_t nativeIndex = uFnAbortCommand->iNative;
	uFnAbortCommand->iNative = 0;
	this->ProcessEvent(uFnAbortCommand, &AbortCommand_Params, nullptr);
	uFnAbortCommand->iNative = nativeIndex;

	return AbortCommand_Params.ReturnValue;
}

// Function GameFramework.GameAIController.PopCommand
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// class UGameAICommand*          ToBePoppedCommand              (CPF_Parm)

void AGameAIController::PopCommand(class UGameAICommand* ToBePoppedCommand)
{
	static UFunction* uFnPopCommand = nullptr;

	if (!uFnPopCommand)
	{
		uFnPopCommand = UFunction::FindFunction("Function GameFramework.GameAIController.PopCommand");
	}

	AGameAIController_execPopCommand_Params PopCommand_Params;
	memset(&PopCommand_Params, 0, sizeof(PopCommand_Params));

	if (!uFnPopCommand)
	{
		return;
	}
	PopCommand_Params.ToBePoppedCommand = ToBePoppedCommand;

	uint16_t nativeIndex = uFnPopCommand->iNative;
	uFnPopCommand->iNative = 0;
	this->ProcessEvent(uFnPopCommand, &PopCommand_Params, nullptr);
	uFnPopCommand->iNative = nativeIndex;
}

// Function GameFramework.GameAIController.PushCommand
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// class UGameAICommand*          NewCommand                     (CPF_Parm)

void AGameAIController::PushCommand(class UGameAICommand* NewCommand)
{
	static UFunction* uFnPushCommand = nullptr;

	if (!uFnPushCommand)
	{
		uFnPushCommand = UFunction::FindFunction("Function GameFramework.GameAIController.PushCommand");
	}

	AGameAIController_execPushCommand_Params PushCommand_Params;
	memset(&PushCommand_Params, 0, sizeof(PushCommand_Params));

	if (!uFnPushCommand)
	{
		return;
	}
	PushCommand_Params.NewCommand = NewCommand;

	uint16_t nativeIndex = uFnPushCommand->iNative;
	uFnPushCommand->iNative = 0;
	this->ProcessEvent(uFnPushCommand, &PushCommand_Params, nullptr);
	uFnPushCommand->iNative = nativeIndex;
}

// Function GameFramework.GameAICommand.GetDebugOverheadText
// [0x00420000] (FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// class APlayerController*       PC                             (CPF_Parm)
// class TArray<class FString>    OutText                        (CPF_Parm | CPF_OutParm | CPF_NeedCtorLink)

void UGameAICommand::GetDebugOverheadText(class APlayerController* PC, class TArray<class FString>& outOutText)
{
	static UFunction* uFnGetDebugOverheadText = nullptr;

	if (!uFnGetDebugOverheadText)
	{
		uFnGetDebugOverheadText = UFunction::FindFunction("Function GameFramework.GameAICommand.GetDebugOverheadText");
	}

	UGameAICommand_execGetDebugOverheadText_Params GetDebugOverheadText_Params;
	memset(&GetDebugOverheadText_Params, 0, sizeof(GetDebugOverheadText_Params));

	if (!uFnGetDebugOverheadText)
	{
		return;
	}
	GetDebugOverheadText_Params.PC = PC;
	memcpy_s(&GetDebugOverheadText_Params.OutText, sizeof(GetDebugOverheadText_Params.OutText), &outOutText, sizeof(outOutText));

	this->ProcessEvent(uFnGetDebugOverheadText, &GetDebugOverheadText_Params, nullptr);

	memcpy_s(&outOutText, sizeof(outOutText), &GetDebugOverheadText_Params.OutText, sizeof(GetDebugOverheadText_Params.OutText));
}

// Function GameFramework.GameAICommand.DrawDebug
// [0x00020800] (FUNC_Event | FUNC_Public)
// Parameter Info:
// class AHUD*                    H                              (CPF_Parm)
// class FName                    Category                       (CPF_Parm)

void UGameAICommand::eventDrawDebug(class AHUD* H, const class FName& Category)
{
	static UFunction* uFnDrawDebug = nullptr;

	if (!uFnDrawDebug)
	{
		uFnDrawDebug = UFunction::FindFunction("Function GameFramework.GameAICommand.DrawDebug");
	}

	UGameAICommand_eventDrawDebug_Params DrawDebug_Params;
	memset(&DrawDebug_Params, 0, sizeof(DrawDebug_Params));

	if (!uFnDrawDebug)
	{
		return;
	}
	DrawDebug_Params.H = H;
	memcpy_s(&DrawDebug_Params.Category, sizeof(DrawDebug_Params.Category), &Category, sizeof(Category));

	this->ProcessEvent(uFnDrawDebug, &DrawDebug_Params, nullptr);
}

// Function GameFramework.GameAICommand.GetDumpString
// [0x00020802] (FUNC_Defined | FUNC_Event | FUNC_Public)
// Parameter Info:
// class FString                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)

class FString UGameAICommand::eventGetDumpString()
{
	static UFunction* uFnGetDumpString = nullptr;

	if (!uFnGetDumpString)
	{
		uFnGetDumpString = UFunction::FindFunction("Function GameFramework.GameAICommand.GetDumpString");
	}

	UGameAICommand_eventGetDumpString_Params GetDumpString_Params;
	memset(&GetDumpString_Params, 0, sizeof(GetDumpString_Params));

	if (!uFnGetDumpString)
	{
		return GetDumpString_Params.ReturnValue;
	}

	this->ProcessEvent(uFnGetDumpString, &GetDumpString_Params, nullptr);

	return GetDumpString_Params.ReturnValue;
}

// Function GameFramework.GameAICommand.Resumed
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class FName                    OldCommandName                 (CPF_Parm)

void UGameAICommand::Resumed(const class FName& OldCommandName)
{
	static UFunction* uFnResumed = nullptr;

	if (!uFnResumed)
	{
		uFnResumed = UFunction::FindFunction("Function GameFramework.GameAICommand.Resumed");
	}

	UGameAICommand_execResumed_Params Resumed_Params;
	memset(&Resumed_Params, 0, sizeof(Resumed_Params));

	if (!uFnResumed)
	{
		return;
	}
	memcpy_s(&Resumed_Params.OldCommandName, sizeof(Resumed_Params.OldCommandName), &OldCommandName, sizeof(OldCommandName));

	this->ProcessEvent(uFnResumed, &Resumed_Params, nullptr);
}

// Function GameFramework.GameAICommand.Paused
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class UGameAICommand*          NewCommand                     (CPF_Parm)

void UGameAICommand::Paused(class UGameAICommand* NewCommand)
{
	static UFunction* uFnPaused = nullptr;

	if (!uFnPaused)
	{
		uFnPaused = UFunction::FindFunction("Function GameFramework.GameAICommand.Paused");
	}

	UGameAICommand_execPaused_Params Paused_Params;
	memset(&Paused_Params, 0, sizeof(Paused_Params));

	if (!uFnPaused)
	{
		return;
	}
	Paused_Params.NewCommand = NewCommand;

	this->ProcessEvent(uFnPaused, &Paused_Params, nullptr);
}

// Function GameFramework.GameAICommand.Popped
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:

void UGameAICommand::Popped()
{
	static UFunction* uFnPopped = nullptr;

	if (!uFnPopped)
	{
		uFnPopped = UFunction::FindFunction("Function GameFramework.GameAICommand.Popped");
	}

	UGameAICommand_execPopped_Params Popped_Params;
	memset(&Popped_Params, 0, sizeof(Popped_Params));

	if (!uFnPopped)
	{
		return;
	}

	this->ProcessEvent(uFnPopped, &Popped_Params, nullptr);
}

// Function GameFramework.GameAICommand.Pushed
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:

void UGameAICommand::Pushed()
{
	static UFunction* uFnPushed = nullptr;

	if (!uFnPushed)
	{
		uFnPushed = UFunction::FindFunction("Function GameFramework.GameAICommand.Pushed");
	}

	UGameAICommand_execPushed_Params Pushed_Params;
	memset(&Pushed_Params, 0, sizeof(Pushed_Params));

	if (!uFnPushed)
	{
		return;
	}

	this->ProcessEvent(uFnPushed, &Pushed_Params, nullptr);
}

// Function GameFramework.GameAICommand.PostPopped
// [0x00020000] (FUNC_Public)
// Parameter Info:

void UGameAICommand::PostPopped()
{
	static UFunction* uFnPostPopped = nullptr;

	if (!uFnPostPopped)
	{
		uFnPostPopped = UFunction::FindFunction("Function GameFramework.GameAICommand.PostPopped");
	}

	UGameAICommand_execPostPopped_Params PostPopped_Params;
	memset(&PostPopped_Params, 0, sizeof(PostPopped_Params));

	if (!uFnPostPopped)
	{
		return;
	}

	this->ProcessEvent(uFnPostPopped, &PostPopped_Params, nullptr);
}

// Function GameFramework.GameAICommand.PrePushed
// [0x00020000] (FUNC_Public)
// Parameter Info:
// class AGameAIController*       AI                             (CPF_Parm)

void UGameAICommand::PrePushed(class AGameAIController* AI)
{
	static UFunction* uFnPrePushed = nullptr;

	if (!uFnPrePushed)
	{
		uFnPrePushed = UFunction::FindFunction("Function GameFramework.GameAICommand.PrePushed");
	}

	UGameAICommand_execPrePushed_Params PrePushed_Params;
	memset(&PrePushed_Params, 0, sizeof(PrePushed_Params));

	if (!uFnPrePushed)
	{
		return;
	}
	PrePushed_Params.AI = AI;

	this->ProcessEvent(uFnPrePushed, &PrePushed_Params, nullptr);
}

// Function GameFramework.GameAICommand.AllowStateTransitionTo
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FName                    StateName                      (CPF_Parm)

bool UGameAICommand::AllowStateTransitionTo(const class FName& StateName)
{
	static UFunction* uFnAllowStateTransitionTo = nullptr;

	if (!uFnAllowStateTransitionTo)
	{
		uFnAllowStateTransitionTo = UFunction::FindFunction("Function GameFramework.GameAICommand.AllowStateTransitionTo");
	}

	UGameAICommand_execAllowStateTransitionTo_Params AllowStateTransitionTo_Params;
	memset(&AllowStateTransitionTo_Params, 0, sizeof(AllowStateTransitionTo_Params));

	if (!uFnAllowStateTransitionTo)
	{
		return AllowStateTransitionTo_Params.ReturnValue;
	}
	memcpy_s(&AllowStateTransitionTo_Params.StateName, sizeof(AllowStateTransitionTo_Params.StateName), &StateName, sizeof(StateName));

	this->ProcessEvent(uFnAllowStateTransitionTo, &AllowStateTransitionTo_Params, nullptr);

	return AllowStateTransitionTo_Params.ReturnValue;
}

// Function GameFramework.GameAICommand.AllowTransitionTo
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class UClass*                  AttemptCommand                 (CPF_Parm)

bool UGameAICommand::AllowTransitionTo(class UClass* AttemptCommand)
{
	static UFunction* uFnAllowTransitionTo = nullptr;

	if (!uFnAllowTransitionTo)
	{
		uFnAllowTransitionTo = UFunction::FindFunction("Function GameFramework.GameAICommand.AllowTransitionTo");
	}

	UGameAICommand_execAllowTransitionTo_Params AllowTransitionTo_Params;
	memset(&AllowTransitionTo_Params, 0, sizeof(AllowTransitionTo_Params));

	if (!uFnAllowTransitionTo)
	{
		return AllowTransitionTo_Params.ReturnValue;
	}
	AllowTransitionTo_Params.AttemptCommand = AttemptCommand;

	this->ProcessEvent(uFnAllowTransitionTo, &AllowTransitionTo_Params, nullptr);

	return AllowTransitionTo_Params.ReturnValue;
}

// Function GameFramework.GameAICommand.Tick
// [0x00020000] (FUNC_Public)
// Parameter Info:
// float                          DeltaTime                      (CPF_Parm)

void UGameAICommand::Tick(float DeltaTime)
{
	static UFunction* uFnTick = nullptr;

	if (!uFnTick)
	{
		uFnTick = UFunction::FindFunction("Function GameFramework.GameAICommand.Tick");
	}

	UGameAICommand_execTick_Params Tick_Params;
	memset(&Tick_Params, 0, sizeof(Tick_Params));

	if (!uFnTick)
	{
		return;
	}
	Tick_Params.DeltaTime = DeltaTime;

	this->ProcessEvent(uFnTick, &Tick_Params, nullptr);
}

// Function GameFramework.GameAICommand.ShouldIgnoreNotifies
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

bool UGameAICommand::ShouldIgnoreNotifies()
{
	static UFunction* uFnShouldIgnoreNotifies = nullptr;

	if (!uFnShouldIgnoreNotifies)
	{
		uFnShouldIgnoreNotifies = UFunction::FindFunction("Function GameFramework.GameAICommand.ShouldIgnoreNotifies");
	}

	UGameAICommand_execShouldIgnoreNotifies_Params ShouldIgnoreNotifies_Params;
	memset(&ShouldIgnoreNotifies_Params, 0, sizeof(ShouldIgnoreNotifies_Params));

	if (!uFnShouldIgnoreNotifies)
	{
		return ShouldIgnoreNotifies_Params.ReturnValue;
	}

	uint16_t nativeIndex = uFnShouldIgnoreNotifies->iNative;
	uFnShouldIgnoreNotifies->iNative = 0;
	this->ProcessEvent(uFnShouldIgnoreNotifies, &ShouldIgnoreNotifies_Params, nullptr);
	uFnShouldIgnoreNotifies->iNative = nativeIndex;

	return ShouldIgnoreNotifies_Params.ReturnValue;
}

// Function GameFramework.GameAICommand.InternalTick
// [0x00020803] (FUNC_Final | FUNC_Defined | FUNC_Event | FUNC_Public)
// Parameter Info:
// float                          DeltaTime                      (CPF_Parm)

void UGameAICommand::eventInternalTick(float DeltaTime)
{
	static UFunction* uFnInternalTick = nullptr;

	if (!uFnInternalTick)
	{
		uFnInternalTick = UFunction::FindFunction("Function GameFramework.GameAICommand.InternalTick");
	}

	UGameAICommand_eventInternalTick_Params InternalTick_Params;
	memset(&InternalTick_Params, 0, sizeof(InternalTick_Params));

	if (!uFnInternalTick)
	{
		return;
	}
	InternalTick_Params.DeltaTime = DeltaTime;

	this->ProcessEvent(uFnInternalTick, &InternalTick_Params, nullptr);
}

// Function GameFramework.GameAICommand.InternalResumed
// [0x00020803] (FUNC_Final | FUNC_Defined | FUNC_Event | FUNC_Public)
// Parameter Info:
// class FName                    OldCommandName                 (CPF_Parm)

void UGameAICommand::eventInternalResumed(const class FName& OldCommandName)
{
	static UFunction* uFnInternalResumed = nullptr;

	if (!uFnInternalResumed)
	{
		uFnInternalResumed = UFunction::FindFunction("Function GameFramework.GameAICommand.InternalResumed");
	}

	UGameAICommand_eventInternalResumed_Params InternalResumed_Params;
	memset(&InternalResumed_Params, 0, sizeof(InternalResumed_Params));

	if (!uFnInternalResumed)
	{
		return;
	}
	memcpy_s(&InternalResumed_Params.OldCommandName, sizeof(InternalResumed_Params.OldCommandName), &OldCommandName, sizeof(OldCommandName));

	this->ProcessEvent(uFnInternalResumed, &InternalResumed_Params, nullptr);
}

// Function GameFramework.GameAICommand.InternalPaused
// [0x00020803] (FUNC_Final | FUNC_Defined | FUNC_Event | FUNC_Public)
// Parameter Info:
// class UGameAICommand*          NewCommand                     (CPF_Parm)

void UGameAICommand::eventInternalPaused(class UGameAICommand* NewCommand)
{
	static UFunction* uFnInternalPaused = nullptr;

	if (!uFnInternalPaused)
	{
		uFnInternalPaused = UFunction::FindFunction("Function GameFramework.GameAICommand.InternalPaused");
	}

	UGameAICommand_eventInternalPaused_Params InternalPaused_Params;
	memset(&InternalPaused_Params, 0, sizeof(InternalPaused_Params));

	if (!uFnInternalPaused)
	{
		return;
	}
	InternalPaused_Params.NewCommand = NewCommand;

	this->ProcessEvent(uFnInternalPaused, &InternalPaused_Params, nullptr);
}

// Function GameFramework.GameAICommand.InternalPopped
// [0x00020802] (FUNC_Defined | FUNC_Event | FUNC_Public)
// Parameter Info:

void UGameAICommand::eventInternalPopped()
{
	static UFunction* uFnInternalPopped = nullptr;

	if (!uFnInternalPopped)
	{
		uFnInternalPopped = UFunction::FindFunction("Function GameFramework.GameAICommand.InternalPopped");
	}

	UGameAICommand_eventInternalPopped_Params InternalPopped_Params;
	memset(&InternalPopped_Params, 0, sizeof(InternalPopped_Params));

	if (!uFnInternalPopped)
	{
		return;
	}

	this->ProcessEvent(uFnInternalPopped, &InternalPopped_Params, nullptr);
}

// Function GameFramework.GameAICommand.InternalPushed
// [0x00020803] (FUNC_Final | FUNC_Defined | FUNC_Event | FUNC_Public)
// Parameter Info:

void UGameAICommand::eventInternalPushed()
{
	static UFunction* uFnInternalPushed = nullptr;

	if (!uFnInternalPushed)
	{
		uFnInternalPushed = UFunction::FindFunction("Function GameFramework.GameAICommand.InternalPushed");
	}

	UGameAICommand_eventInternalPushed_Params InternalPushed_Params;
	memset(&InternalPushed_Params, 0, sizeof(InternalPushed_Params));

	if (!uFnInternalPushed)
	{
		return;
	}

	this->ProcessEvent(uFnInternalPushed, &InternalPushed_Params, nullptr);
}

// Function GameFramework.GameAICommand.InternalPrePushed
// [0x00020803] (FUNC_Final | FUNC_Defined | FUNC_Event | FUNC_Public)
// Parameter Info:
// class AGameAIController*       AI                             (CPF_Parm)

void UGameAICommand::eventInternalPrePushed(class AGameAIController* AI)
{
	static UFunction* uFnInternalPrePushed = nullptr;

	if (!uFnInternalPrePushed)
	{
		uFnInternalPrePushed = UFunction::FindFunction("Function GameFramework.GameAICommand.InternalPrePushed");
	}

	UGameAICommand_eventInternalPrePushed_Params InternalPrePushed_Params;
	memset(&InternalPrePushed_Params, 0, sizeof(InternalPrePushed_Params));

	if (!uFnInternalPrePushed)
	{
		return;
	}
	InternalPrePushed_Params.AI = AI;

	this->ProcessEvent(uFnInternalPrePushed, &InternalPrePushed_Params, nullptr);
}

// Function GameFramework.GameAICommand.InitCommand
// [0x00022002] (FUNC_Defined | FUNC_Static | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class AGameAIController*       AI                             (CPF_Parm)

bool UGameAICommand::InitCommand(class AGameAIController* AI)
{
	static UFunction* uFnInitCommand = nullptr;

	if (!uFnInitCommand)
	{
		uFnInitCommand = UFunction::FindFunction("Function GameFramework.GameAICommand.InitCommand");
	}

	UGameAICommand_execInitCommand_Params InitCommand_Params;
	memset(&InitCommand_Params, 0, sizeof(InitCommand_Params));

	if (!uFnInitCommand)
	{
		return InitCommand_Params.ReturnValue;
	}
	InitCommand_Params.AI = AI;

	UGameAICommand::StaticClass()->ClassDefaultObject->ProcessEvent(uFnInitCommand, &InitCommand_Params, nullptr);

	return InitCommand_Params.ReturnValue;
}

// Function GameFramework.GameAICommand.InitCommandUserActor
// [0x00022002] (FUNC_Defined | FUNC_Static | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class AGameAIController*       AI                             (CPF_Parm)
// class AActor*                  UserActor                      (CPF_Parm)

bool UGameAICommand::InitCommandUserActor(class AGameAIController* AI, class AActor* UserActor)
{
	static UFunction* uFnInitCommandUserActor = nullptr;

	if (!uFnInitCommandUserActor)
	{
		uFnInitCommandUserActor = UFunction::FindFunction("Function GameFramework.GameAICommand.InitCommandUserActor");
	}

	UGameAICommand_execInitCommandUserActor_Params InitCommandUserActor_Params;
	memset(&InitCommandUserActor_Params, 0, sizeof(InitCommandUserActor_Params));

	if (!uFnInitCommandUserActor)
	{
		return InitCommandUserActor_Params.ReturnValue;
	}
	InitCommandUserActor_Params.AI = AI;
	InitCommandUserActor_Params.UserActor = UserActor;

	UGameAICommand::StaticClass()->ClassDefaultObject->ProcessEvent(uFnInitCommandUserActor, &InitCommandUserActor_Params, nullptr);

	return InitCommandUserActor_Params.ReturnValue;
}

// Function GameFramework.GameCrowdAgent.GetBehaviorString
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class FString                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)

class FString AGameCrowdAgent::GetBehaviorString()
{
	static UFunction* uFnGetBehaviorString = nullptr;

	if (!uFnGetBehaviorString)
	{
		uFnGetBehaviorString = UFunction::FindFunction("Function GameFramework.GameCrowdAgent.GetBehaviorString");
	}

	AGameCrowdAgent_execGetBehaviorString_Params GetBehaviorString_Params;
	memset(&GetBehaviorString_Params, 0, sizeof(GetBehaviorString_Params));

	if (!uFnGetBehaviorString)
	{
		return GetBehaviorString_Params.ReturnValue;
	}

	this->ProcessEvent(uFnGetBehaviorString, &GetBehaviorString_Params, nullptr);

	return GetBehaviorString_Params.ReturnValue;
}

// Function GameFramework.GameCrowdAgent.GetDestString
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class FString                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)

class FString AGameCrowdAgent::GetDestString()
{
	static UFunction* uFnGetDestString = nullptr;

	if (!uFnGetDestString)
	{
		uFnGetDestString = UFunction::FindFunction("Function GameFramework.GameCrowdAgent.GetDestString");
	}

	AGameCrowdAgent_execGetDestString_Params GetDestString_Params;
	memset(&GetDestString_Params, 0, sizeof(GetDestString_Params));

	if (!uFnGetDestString)
	{
		return GetDestString_Params.ReturnValue;
	}

	this->ProcessEvent(uFnGetDestString, &GetDestString_Params, nullptr);

	return GetDestString_Params.ReturnValue;
}

// Function GameFramework.GameCrowdAgent.PostRenderFor
// [0x00820902] (FUNC_Defined | FUNC_Simulated | FUNC_Event | FUNC_Public | FUNC_HasDefaults)
// Parameter Info:
// class APlayerController*       PC                             (CPF_Parm)
// class UCanvas*                 Canvas                         (CPF_Parm)
// struct FVector                 CameraPosition                 (CPF_Parm)
// struct FVector                 CameraDir                      (CPF_Parm)

void AGameCrowdAgent::eventPostRenderFor(class APlayerController* PC, class UCanvas* Canvas, const struct FVector& CameraPosition, const struct FVector& CameraDir)
{
	static UFunction* uFnPostRenderFor = nullptr;

	if (!uFnPostRenderFor)
	{
		uFnPostRenderFor = UFunction::FindFunction("Function GameFramework.GameCrowdAgent.PostRenderFor");
	}

	AGameCrowdAgent_eventPostRenderFor_Params PostRenderFor_Params;
	memset(&PostRenderFor_Params, 0, sizeof(PostRenderFor_Params));

	if (!uFnPostRenderFor)
	{
		return;
	}
	PostRenderFor_Params.PC = PC;
	PostRenderFor_Params.Canvas = Canvas;
	memcpy_s(&PostRenderFor_Params.CameraPosition, sizeof(PostRenderFor_Params.CameraPosition), &CameraPosition, sizeof(CameraPosition));
	memcpy_s(&PostRenderFor_Params.CameraDir, sizeof(PostRenderFor_Params.CameraDir), &CameraDir, sizeof(CameraDir));

	this->ProcessEvent(uFnPostRenderFor, &PostRenderFor_Params, nullptr);
}

// Function GameFramework.GameCrowdAgent.NativePostRenderFor
// [0x00020500] (FUNC_Simulated | FUNC_Native | FUNC_Public)
// Parameter Info:
// class APlayerController*       PC                             (CPF_Parm)
// class UCanvas*                 Canvas                         (CPF_Parm)
// struct FVector                 CameraPosition                 (CPF_Parm)
// struct FVector                 CameraDir                      (CPF_Parm)

void AGameCrowdAgent::NativePostRenderFor(class APlayerController* PC, class UCanvas* Canvas, const struct FVector& CameraPosition, const struct FVector& CameraDir)
{
	static UFunction* uFnNativePostRenderFor = nullptr;

	if (!uFnNativePostRenderFor)
	{
		uFnNativePostRenderFor = UFunction::FindFunction("Function GameFramework.GameCrowdAgent.NativePostRenderFor");
	}

	AGameCrowdAgent_execNativePostRenderFor_Params NativePostRenderFor_Params;
	memset(&NativePostRenderFor_Params, 0, sizeof(NativePostRenderFor_Params));

	if (!uFnNativePostRenderFor)
	{
		return;
	}
	NativePostRenderFor_Params.PC = PC;
	NativePostRenderFor_Params.Canvas = Canvas;
	memcpy_s(&NativePostRenderFor_Params.CameraPosition, sizeof(NativePostRenderFor_Params.CameraPosition), &CameraPosition, sizeof(CameraPosition));
	memcpy_s(&NativePostRenderFor_Params.CameraDir, sizeof(NativePostRenderFor_Params.CameraDir), &CameraDir, sizeof(CameraDir));

	uint16_t nativeIndex = uFnNativePostRenderFor->iNative;
	uFnNativePostRenderFor->iNative = 0;
	this->ProcessEvent(uFnNativePostRenderFor, &NativePostRenderFor_Params, nullptr);
	uFnNativePostRenderFor->iNative = nativeIndex;
}

// Function GameFramework.GameCrowdAgent.GeneratePathToActor
// [0x00824802] (FUNC_Defined | FUNC_Event | FUNC_OptionalParm | FUNC_Public | FUNC_HasDefaults)
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class AActor*                  Goal                           (CPF_Parm)
// float                          WithinDistance                 (CPF_OptionalParm | CPF_Parm)
// uint32_t                       bAllowPartialPath              (CPF_OptionalParm | CPF_Parm)

struct FVector AGameCrowdAgent::eventGeneratePathToActor(class AActor* Goal, float optionalWithinDistance, bool optionalBAllowPartialPath)
{
	static UFunction* uFnGeneratePathToActor = nullptr;

	if (!uFnGeneratePathToActor)
	{
		uFnGeneratePathToActor = UFunction::FindFunction("Function GameFramework.GameCrowdAgent.GeneratePathToActor");
	}

	AGameCrowdAgent_eventGeneratePathToActor_Params GeneratePathToActor_Params;
	memset(&GeneratePathToActor_Params, 0, sizeof(GeneratePathToActor_Params));

	if (!uFnGeneratePathToActor)
	{
		return GeneratePathToActor_Params.ReturnValue;
	}
	GeneratePathToActor_Params.Goal = Goal;
	GeneratePathToActor_Params.WithinDistance = optionalWithinDistance;
	GeneratePathToActor_Params.bAllowPartialPath = optionalBAllowPartialPath;

	this->ProcessEvent(uFnGeneratePathToActor, &GeneratePathToActor_Params, nullptr);

	return GeneratePathToActor_Params.ReturnValue;
}

// Function GameFramework.GameCrowdAgent.InitNavigationHandle
// [0x00020802] (FUNC_Defined | FUNC_Event | FUNC_Public)
// Parameter Info:

void AGameCrowdAgent::eventInitNavigationHandle()
{
	static UFunction* uFnInitNavigationHandle = nullptr;

	if (!uFnInitNavigationHandle)
	{
		uFnInitNavigationHandle = UFunction::FindFunction("Function GameFramework.GameCrowdAgent.InitNavigationHandle");
	}

	AGameCrowdAgent_eventInitNavigationHandle_Params InitNavigationHandle_Params;
	memset(&InitNavigationHandle_Params, 0, sizeof(InitNavigationHandle_Params));

	if (!uFnInitNavigationHandle)
	{
		return;
	}

	this->ProcessEvent(uFnInitNavigationHandle, &InitNavigationHandle_Params, nullptr);
}

// Function GameFramework.GameCrowdAgent.OverlappedActorEvent
// [0x00020800] (FUNC_Event | FUNC_Public)
// Parameter Info:
// class AActor*                  A                              (CPF_Parm)

void AGameCrowdAgent::eventOverlappedActorEvent(class AActor* A)
{
	static UFunction* uFnOverlappedActorEvent = nullptr;

	if (!uFnOverlappedActorEvent)
	{
		uFnOverlappedActorEvent = UFunction::FindFunction("Function GameFramework.GameCrowdAgent.OverlappedActorEvent");
	}

	AGameCrowdAgent_eventOverlappedActorEvent_Params OverlappedActorEvent_Params;
	memset(&OverlappedActorEvent_Params, 0, sizeof(OverlappedActorEvent_Params));

	if (!uFnOverlappedActorEvent)
	{
		return;
	}
	OverlappedActorEvent_Params.A = A;

	this->ProcessEvent(uFnOverlappedActorEvent, &OverlappedActorEvent_Params, nullptr);
}

// Function GameFramework.GameCrowdAgent.TakeDamage
// [0x00024002] (FUNC_Defined | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// int32_t                        DamageAmount                   (CPF_Parm)
// class AController*             EventInstigator                (CPF_Parm)
// struct FVector                 HitLocation                    (CPF_Parm)
// struct FVector                 Momentum                       (CPF_Parm)
// class UClass*                  DamageType                     (CPF_Parm)
// struct FTraceHitInfo           HitInfo                        (CPF_OptionalParm | CPF_Parm)
// class AActor*                  DamageCauser                   (CPF_OptionalParm | CPF_Parm)

void AGameCrowdAgent::TakeDamage(int32_t DamageAmount, class AController* EventInstigator, const struct FVector& HitLocation, const struct FVector& Momentum, class UClass* DamageType, const struct FTraceHitInfo& optionalHitInfo, class AActor* optionalDamageCauser)
{
	static UFunction* uFnTakeDamage = nullptr;

	if (!uFnTakeDamage)
	{
		uFnTakeDamage = UFunction::FindFunction("Function GameFramework.GameCrowdAgent.TakeDamage");
	}

	AGameCrowdAgent_execTakeDamage_Params TakeDamage_Params;
	memset(&TakeDamage_Params, 0, sizeof(TakeDamage_Params));

	if (!uFnTakeDamage)
	{
		return;
	}
	TakeDamage_Params.DamageAmount = DamageAmount;
	TakeDamage_Params.EventInstigator = EventInstigator;
	memcpy_s(&TakeDamage_Params.HitLocation, sizeof(TakeDamage_Params.HitLocation), &HitLocation, sizeof(HitLocation));
	memcpy_s(&TakeDamage_Params.Momentum, sizeof(TakeDamage_Params.Momentum), &Momentum, sizeof(Momentum));
	TakeDamage_Params.DamageType = DamageType;
	memcpy_s(&TakeDamage_Params.HitInfo, sizeof(TakeDamage_Params.HitInfo), &optionalHitInfo, sizeof(optionalHitInfo));
	TakeDamage_Params.DamageCauser = optionalDamageCauser;

	this->ProcessEvent(uFnTakeDamage, &TakeDamage_Params, nullptr);
}

// Function GameFramework.GameCrowdAgent.FireDeathEvent
// [0x00020902] (FUNC_Defined | FUNC_Simulated | FUNC_Event | FUNC_Public)
// Parameter Info:

void AGameCrowdAgent::eventFireDeathEvent()
{
	static UFunction* uFnFireDeathEvent = nullptr;

	if (!uFnFireDeathEvent)
	{
		uFnFireDeathEvent = UFunction::FindFunction("Function GameFramework.GameCrowdAgent.FireDeathEvent");
	}

	AGameCrowdAgent_eventFireDeathEvent_Params FireDeathEvent_Params;
	memset(&FireDeathEvent_Params, 0, sizeof(FireDeathEvent_Params));

	if (!uFnFireDeathEvent)
	{
		return;
	}

	this->ProcessEvent(uFnFireDeathEvent, &FireDeathEvent_Params, nullptr);
}

// Function GameFramework.GameCrowdAgent.PlayDeath
// [0x00020400] (FUNC_Native | FUNC_Public)
// Parameter Info:
// struct FVector                 KillMomentum                   (CPF_Parm)

void AGameCrowdAgent::PlayDeath(const struct FVector& KillMomentum)
{
	static UFunction* uFnPlayDeath = nullptr;

	if (!uFnPlayDeath)
	{
		uFnPlayDeath = UFunction::FindFunction("Function GameFramework.GameCrowdAgent.PlayDeath");
	}

	AGameCrowdAgent_execPlayDeath_Params PlayDeath_Params;
	memset(&PlayDeath_Params, 0, sizeof(PlayDeath_Params));

	if (!uFnPlayDeath)
	{
		return;
	}
	memcpy_s(&PlayDeath_Params.KillMomentum, sizeof(PlayDeath_Params.KillMomentum), &KillMomentum, sizeof(KillMomentum));

	uint16_t nativeIndex = uFnPlayDeath->iNative;
	uFnPlayDeath->iNative = 0;
	this->ProcessEvent(uFnPlayDeath, &PlayDeath_Params, nullptr);
	uFnPlayDeath->iNative = nativeIndex;
}

// Function GameFramework.GameCrowdAgent.UpdateIntermediatePoint
// [0x00024802] (FUNC_Defined | FUNC_Event | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// class AActor*                  DestinationActor               (CPF_OptionalParm | CPF_Parm)

void AGameCrowdAgent::eventUpdateIntermediatePoint(class AActor* optionalDestinationActor)
{
	static UFunction* uFnUpdateIntermediatePoint = nullptr;

	if (!uFnUpdateIntermediatePoint)
	{
		uFnUpdateIntermediatePoint = UFunction::FindFunction("Function GameFramework.GameCrowdAgent.UpdateIntermediatePoint");
	}

	AGameCrowdAgent_eventUpdateIntermediatePoint_Params UpdateIntermediatePoint_Params;
	memset(&UpdateIntermediatePoint_Params, 0, sizeof(UpdateIntermediatePoint_Params));

	if (!uFnUpdateIntermediatePoint)
	{
		return;
	}
	UpdateIntermediatePoint_Params.DestinationActor = optionalDestinationActor;

	this->ProcessEvent(uFnUpdateIntermediatePoint, &UpdateIntermediatePoint_Params, nullptr);
}

// Function GameFramework.GameCrowdAgent.CalcCamera
// [0x00C20102] (FUNC_Defined | FUNC_Simulated | FUNC_Public | FUNC_HasOutParms | FUNC_HasDefaults)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          fDeltaTime                     (CPF_Parm)
// struct FVector                 out_CamLoc                     (CPF_Parm | CPF_OutParm)
// struct FRotator                out_CamRot                     (CPF_Parm | CPF_OutParm)
// float                          out_FOV                        (CPF_Parm | CPF_OutParm)

bool AGameCrowdAgent::CalcCamera(float fDeltaTime, struct FVector& outOut_CamLoc, struct FRotator& outOut_CamRot, float& outOut_FOV)
{
	static UFunction* uFnCalcCamera = nullptr;

	if (!uFnCalcCamera)
	{
		uFnCalcCamera = UFunction::FindFunction("Function GameFramework.GameCrowdAgent.CalcCamera");
	}

	AGameCrowdAgent_execCalcCamera_Params CalcCamera_Params;
	memset(&CalcCamera_Params, 0, sizeof(CalcCamera_Params));

	if (!uFnCalcCamera)
	{
		return CalcCamera_Params.ReturnValue;
	}
	CalcCamera_Params.fDeltaTime = fDeltaTime;
	memcpy_s(&CalcCamera_Params.out_CamLoc, sizeof(CalcCamera_Params.out_CamLoc), &outOut_CamLoc, sizeof(outOut_CamLoc));
	memcpy_s(&CalcCamera_Params.out_CamRot, sizeof(CalcCamera_Params.out_CamRot), &outOut_CamRot, sizeof(outOut_CamRot));
	CalcCamera_Params.out_FOV = outOut_FOV;

	this->ProcessEvent(uFnCalcCamera, &CalcCamera_Params, nullptr);

	memcpy_s(&outOut_CamLoc, sizeof(outOut_CamLoc), &CalcCamera_Params.out_CamLoc, sizeof(CalcCamera_Params.out_CamLoc));
	memcpy_s(&outOut_CamRot, sizeof(outOut_CamRot), &CalcCamera_Params.out_CamRot, sizeof(CalcCamera_Params.out_CamRot));
	outOut_FOV = CalcCamera_Params.out_FOV;

	return CalcCamera_Params.ReturnValue;
}

// Function GameFramework.GameCrowdAgent.IsIdle
// [0x00020400] (FUNC_Native | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

bool AGameCrowdAgent::IsIdle()
{
	static UFunction* uFnIsIdle = nullptr;

	if (!uFnIsIdle)
	{
		uFnIsIdle = UFunction::FindFunction("Function GameFramework.GameCrowdAgent.IsIdle");
	}

	AGameCrowdAgent_execIsIdle_Params IsIdle_Params;
	memset(&IsIdle_Params, 0, sizeof(IsIdle_Params));

	if (!uFnIsIdle)
	{
		return IsIdle_Params.ReturnValue;
	}

	uint16_t nativeIndex = uFnIsIdle->iNative;
	uFnIsIdle->iNative = 0;
	this->ProcessEvent(uFnIsIdle, &IsIdle_Params, nullptr);
	uFnIsIdle->iNative = nativeIndex;

	return IsIdle_Params.ReturnValue;
}

// Function GameFramework.GameCrowdAgent.SetCurrentBehavior
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// class UGameCrowdAgentBehavior* BehaviorArchetype              (CPF_Parm)

void AGameCrowdAgent::SetCurrentBehavior(class UGameCrowdAgentBehavior* BehaviorArchetype)
{
	static UFunction* uFnSetCurrentBehavior = nullptr;

	if (!uFnSetCurrentBehavior)
	{
		uFnSetCurrentBehavior = UFunction::FindFunction("Function GameFramework.GameCrowdAgent.SetCurrentBehavior");
	}

	AGameCrowdAgent_execSetCurrentBehavior_Params SetCurrentBehavior_Params;
	memset(&SetCurrentBehavior_Params, 0, sizeof(SetCurrentBehavior_Params));

	if (!uFnSetCurrentBehavior)
	{
		return;
	}
	SetCurrentBehavior_Params.BehaviorArchetype = BehaviorArchetype;

	uint16_t nativeIndex = uFnSetCurrentBehavior->iNative;
	uFnSetCurrentBehavior->iNative = 0;
	this->ProcessEvent(uFnSetCurrentBehavior, &SetCurrentBehavior_Params, nullptr);
	uFnSetCurrentBehavior->iNative = nativeIndex;
}

// Function GameFramework.GameCrowdAgent.StopBehavior
// [0x00020802] (FUNC_Defined | FUNC_Event | FUNC_Public)
// Parameter Info:

void AGameCrowdAgent::eventStopBehavior()
{
	static UFunction* uFnStopBehavior = nullptr;

	if (!uFnStopBehavior)
	{
		uFnStopBehavior = UFunction::FindFunction("Function GameFramework.GameCrowdAgent.StopBehavior");
	}

	AGameCrowdAgent_eventStopBehavior_Params StopBehavior_Params;
	memset(&StopBehavior_Params, 0, sizeof(StopBehavior_Params));

	if (!uFnStopBehavior)
	{
		return;
	}

	this->ProcessEvent(uFnStopBehavior, &StopBehavior_Params, nullptr);
}

// Function GameFramework.GameCrowdAgent.ActivateInstancedBehavior
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class UGameCrowdAgentBehavior* NewBehaviorObject              (CPF_Parm)

void AGameCrowdAgent::ActivateInstancedBehavior(class UGameCrowdAgentBehavior* NewBehaviorObject)
{
	static UFunction* uFnActivateInstancedBehavior = nullptr;

	if (!uFnActivateInstancedBehavior)
	{
		uFnActivateInstancedBehavior = UFunction::FindFunction("Function GameFramework.GameCrowdAgent.ActivateInstancedBehavior");
	}

	AGameCrowdAgent_execActivateInstancedBehavior_Params ActivateInstancedBehavior_Params;
	memset(&ActivateInstancedBehavior_Params, 0, sizeof(ActivateInstancedBehavior_Params));

	if (!uFnActivateInstancedBehavior)
	{
		return;
	}
	ActivateInstancedBehavior_Params.NewBehaviorObject = NewBehaviorObject;

	this->ProcessEvent(uFnActivateInstancedBehavior, &ActivateInstancedBehavior_Params, nullptr);
}

// Function GameFramework.GameCrowdAgent.ActivateBehavior
// [0x00020802] (FUNC_Defined | FUNC_Event | FUNC_Public)
// Parameter Info:
// class UGameCrowdAgentBehavior* NewBehaviorArchetype           (CPF_Parm)

void AGameCrowdAgent::eventActivateBehavior(class UGameCrowdAgentBehavior* NewBehaviorArchetype)
{
	static UFunction* uFnActivateBehavior = nullptr;

	if (!uFnActivateBehavior)
	{
		uFnActivateBehavior = UFunction::FindFunction("Function GameFramework.GameCrowdAgent.ActivateBehavior");
	}

	AGameCrowdAgent_eventActivateBehavior_Params ActivateBehavior_Params;
	memset(&ActivateBehavior_Params, 0, sizeof(ActivateBehavior_Params));

	if (!uFnActivateBehavior)
	{
		return;
	}
	ActivateBehavior_Params.NewBehaviorArchetype = NewBehaviorArchetype;

	this->ProcessEvent(uFnActivateBehavior, &ActivateBehavior_Params, nullptr);
}

// Function GameFramework.GameCrowdAgent.ResetSeePlayer
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:

void AGameCrowdAgent::ResetSeePlayer()
{
	static UFunction* uFnResetSeePlayer = nullptr;

	if (!uFnResetSeePlayer)
	{
		uFnResetSeePlayer = UFunction::FindFunction("Function GameFramework.GameCrowdAgent.ResetSeePlayer");
	}

	AGameCrowdAgent_execResetSeePlayer_Params ResetSeePlayer_Params;
	memset(&ResetSeePlayer_Params, 0, sizeof(ResetSeePlayer_Params));

	if (!uFnResetSeePlayer)
	{
		return;
	}

	this->ProcessEvent(uFnResetSeePlayer, &ResetSeePlayer_Params, nullptr);
}

// Function GameFramework.GameCrowdAgent.TryRandomBehavior
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:

void AGameCrowdAgent::TryRandomBehavior()
{
	static UFunction* uFnTryRandomBehavior = nullptr;

	if (!uFnTryRandomBehavior)
	{
		uFnTryRandomBehavior = UFunction::FindFunction("Function GameFramework.GameCrowdAgent.TryRandomBehavior");
	}

	AGameCrowdAgent_execTryRandomBehavior_Params TryRandomBehavior_Params;
	memset(&TryRandomBehavior_Params, 0, sizeof(TryRandomBehavior_Params));

	if (!uFnTryRandomBehavior)
	{
		return;
	}

	this->ProcessEvent(uFnTryRandomBehavior, &TryRandomBehavior_Params, nullptr);
}

// Function GameFramework.GameCrowdAgent.NotifySeePlayer
// [0x00020802] (FUNC_Defined | FUNC_Event | FUNC_Public)
// Parameter Info:
// class APlayerController*       PC                             (CPF_Parm)

void AGameCrowdAgent::eventNotifySeePlayer(class APlayerController* PC)
{
	static UFunction* uFnNotifySeePlayer = nullptr;

	if (!uFnNotifySeePlayer)
	{
		uFnNotifySeePlayer = UFunction::FindFunction("Function GameFramework.GameCrowdAgent.NotifySeePlayer");
	}

	AGameCrowdAgent_eventNotifySeePlayer_Params NotifySeePlayer_Params;
	memset(&NotifySeePlayer_Params, 0, sizeof(NotifySeePlayer_Params));

	if (!uFnNotifySeePlayer)
	{
		return;
	}
	NotifySeePlayer_Params.PC = PC;

	this->ProcessEvent(uFnNotifySeePlayer, &NotifySeePlayer_Params, nullptr);
}

// Function GameFramework.GameCrowdAgent.PlaySpawnBehavior
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:

void AGameCrowdAgent::PlaySpawnBehavior()
{
	static UFunction* uFnPlaySpawnBehavior = nullptr;

	if (!uFnPlaySpawnBehavior)
	{
		uFnPlaySpawnBehavior = UFunction::FindFunction("Function GameFramework.GameCrowdAgent.PlaySpawnBehavior");
	}

	AGameCrowdAgent_execPlaySpawnBehavior_Params PlaySpawnBehavior_Params;
	memset(&PlaySpawnBehavior_Params, 0, sizeof(PlaySpawnBehavior_Params));

	if (!uFnPlaySpawnBehavior)
	{
		return;
	}

	this->ProcessEvent(uFnPlaySpawnBehavior, &PlaySpawnBehavior_Params, nullptr);
}

// Function GameFramework.GameCrowdAgent.HandlePotentialAgentEncounter
// [0x00020802] (FUNC_Defined | FUNC_Event | FUNC_Public)
// Parameter Info:

void AGameCrowdAgent::eventHandlePotentialAgentEncounter()
{
	static UFunction* uFnHandlePotentialAgentEncounter = nullptr;

	if (!uFnHandlePotentialAgentEncounter)
	{
		uFnHandlePotentialAgentEncounter = UFunction::FindFunction("Function GameFramework.GameCrowdAgent.HandlePotentialAgentEncounter");
	}

	AGameCrowdAgent_eventHandlePotentialAgentEncounter_Params HandlePotentialAgentEncounter_Params;
	memset(&HandlePotentialAgentEncounter_Params, 0, sizeof(HandlePotentialAgentEncounter_Params));

	if (!uFnHandlePotentialAgentEncounter)
	{
		return;
	}

	this->ProcessEvent(uFnHandlePotentialAgentEncounter, &HandlePotentialAgentEncounter_Params, nullptr);
}

// Function GameFramework.GameCrowdAgent.StopIdleAnimation
// [0x00020900] (FUNC_Simulated | FUNC_Event | FUNC_Public)
// Parameter Info:

void AGameCrowdAgent::eventStopIdleAnimation()
{
	static UFunction* uFnStopIdleAnimation = nullptr;

	if (!uFnStopIdleAnimation)
	{
		uFnStopIdleAnimation = UFunction::FindFunction("Function GameFramework.GameCrowdAgent.StopIdleAnimation");
	}

	AGameCrowdAgent_eventStopIdleAnimation_Params StopIdleAnimation_Params;
	memset(&StopIdleAnimation_Params, 0, sizeof(StopIdleAnimation_Params));

	if (!uFnStopIdleAnimation)
	{
		return;
	}

	this->ProcessEvent(uFnStopIdleAnimation, &StopIdleAnimation_Params, nullptr);
}

// Function GameFramework.GameCrowdAgent.PlayIdleAnimation
// [0x00020900] (FUNC_Simulated | FUNC_Event | FUNC_Public)
// Parameter Info:

void AGameCrowdAgent::eventPlayIdleAnimation()
{
	static UFunction* uFnPlayIdleAnimation = nullptr;

	if (!uFnPlayIdleAnimation)
	{
		uFnPlayIdleAnimation = UFunction::FindFunction("Function GameFramework.GameCrowdAgent.PlayIdleAnimation");
	}

	AGameCrowdAgent_eventPlayIdleAnimation_Params PlayIdleAnimation_Params;
	memset(&PlayIdleAnimation_Params, 0, sizeof(PlayIdleAnimation_Params));

	if (!uFnPlayIdleAnimation)
	{
		return;
	}

	this->ProcessEvent(uFnPlayIdleAnimation, &PlayIdleAnimation_Params, nullptr);
}

// Function GameFramework.GameCrowdAgent.OnPlayAgentAnimation
// [0x00020102] (FUNC_Defined | FUNC_Simulated | FUNC_Public)
// Parameter Info:
// class USeqAct_PlayAgentAnimation* Action                         (CPF_Parm)

void AGameCrowdAgent::OnPlayAgentAnimation(class USeqAct_PlayAgentAnimation* Action)
{
	static UFunction* uFnOnPlayAgentAnimation = nullptr;

	if (!uFnOnPlayAgentAnimation)
	{
		uFnOnPlayAgentAnimation = UFunction::FindFunction("Function GameFramework.GameCrowdAgent.OnPlayAgentAnimation");
	}

	AGameCrowdAgent_execOnPlayAgentAnimation_Params OnPlayAgentAnimation_Params;
	memset(&OnPlayAgentAnimation_Params, 0, sizeof(OnPlayAgentAnimation_Params));

	if (!uFnOnPlayAgentAnimation)
	{
		return;
	}
	OnPlayAgentAnimation_Params.Action = Action;

	this->ProcessEvent(uFnOnPlayAgentAnimation, &OnPlayAgentAnimation_Params, nullptr);
}

// Function GameFramework.GameCrowdAgent.InitializeAgent
// [0x00820102] (FUNC_Defined | FUNC_Simulated | FUNC_Public | FUNC_HasDefaults)
// Parameter Info:
// class AActor*                  SpawnLoc                       (CPF_Parm)
// class AGameCrowdAgent*         AgentTemplate                  (CPF_Parm)
// class UGameCrowdGroup*         NewGroup                       (CPF_Parm)
// float                          AgentWarmupTime                (CPF_Parm)
// uint32_t                       bWarmupPosition                (CPF_Parm)
// uint32_t                       bCheckWarmupVisibility         (CPF_Parm)

void AGameCrowdAgent::InitializeAgent(class AActor* SpawnLoc, class AGameCrowdAgent* AgentTemplate, class UGameCrowdGroup* NewGroup, float AgentWarmupTime, bool bWarmupPosition, bool bCheckWarmupVisibility)
{
	static UFunction* uFnInitializeAgent = nullptr;

	if (!uFnInitializeAgent)
	{
		uFnInitializeAgent = UFunction::FindFunction("Function GameFramework.GameCrowdAgent.InitializeAgent");
	}

	AGameCrowdAgent_execInitializeAgent_Params InitializeAgent_Params;
	memset(&InitializeAgent_Params, 0, sizeof(InitializeAgent_Params));

	if (!uFnInitializeAgent)
	{
		return;
	}
	InitializeAgent_Params.SpawnLoc = SpawnLoc;
	InitializeAgent_Params.AgentTemplate = AgentTemplate;
	InitializeAgent_Params.NewGroup = NewGroup;
	InitializeAgent_Params.AgentWarmupTime = AgentWarmupTime;
	InitializeAgent_Params.bWarmupPosition = bWarmupPosition;
	InitializeAgent_Params.bCheckWarmupVisibility = bCheckWarmupVisibility;

	this->ProcessEvent(uFnInitializeAgent, &InitializeAgent_Params, nullptr);
}

// Function GameFramework.GameCrowdAgent.SetLighting
// [0x00020102] (FUNC_Defined | FUNC_Simulated | FUNC_Public)
// Parameter Info:
// uint32_t                       bEnableLightEnvironment        (CPF_Parm)
// struct FLightingChannelContainer AgentLightingChannel           (CPF_Parm)
// uint32_t                       bCastShadows                   (CPF_Parm)

void AGameCrowdAgent::SetLighting(bool bEnableLightEnvironment, const struct FLightingChannelContainer& AgentLightingChannel, bool bCastShadows)
{
	static UFunction* uFnSetLighting = nullptr;

	if (!uFnSetLighting)
	{
		uFnSetLighting = UFunction::FindFunction("Function GameFramework.GameCrowdAgent.SetLighting");
	}

	AGameCrowdAgent_execSetLighting_Params SetLighting_Params;
	memset(&SetLighting_Params, 0, sizeof(SetLighting_Params));

	if (!uFnSetLighting)
	{
		return;
	}
	SetLighting_Params.bEnableLightEnvironment = bEnableLightEnvironment;
	memcpy_s(&SetLighting_Params.AgentLightingChannel, sizeof(SetLighting_Params.AgentLightingChannel), &AgentLightingChannel, sizeof(AgentLightingChannel));
	SetLighting_Params.bCastShadows = bCastShadows;

	this->ProcessEvent(uFnSetLighting, &SetLighting_Params, nullptr);
}

// Function GameFramework.GameCrowdAgent.DisplayDebug
// [0x00420102] (FUNC_Defined | FUNC_Simulated | FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// class AHUD*                    HUD                            (CPF_Parm)
// float                          out_YL                         (CPF_Parm | CPF_OutParm)
// float                          out_YPos                       (CPF_Parm | CPF_OutParm)

void AGameCrowdAgent::DisplayDebug(class AHUD* HUD, float& outOut_YL, float& outOut_YPos)
{
	static UFunction* uFnDisplayDebug = nullptr;

	if (!uFnDisplayDebug)
	{
		uFnDisplayDebug = UFunction::FindFunction("Function GameFramework.GameCrowdAgent.DisplayDebug");
	}

	AGameCrowdAgent_execDisplayDebug_Params DisplayDebug_Params;
	memset(&DisplayDebug_Params, 0, sizeof(DisplayDebug_Params));

	if (!uFnDisplayDebug)
	{
		return;
	}
	DisplayDebug_Params.HUD = HUD;
	DisplayDebug_Params.out_YL = outOut_YL;
	DisplayDebug_Params.out_YPos = outOut_YPos;

	this->ProcessEvent(uFnDisplayDebug, &DisplayDebug_Params, nullptr);

	outOut_YL = DisplayDebug_Params.out_YL;
	outOut_YPos = DisplayDebug_Params.out_YPos;
}

// Function GameFramework.GameCrowdAgent.Destroyed
// [0x00020102] (FUNC_Defined | FUNC_Simulated | FUNC_Public)
// Parameter Info:

void AGameCrowdAgent::Destroyed()
{
	static UFunction* uFnDestroyed = nullptr;

	if (!uFnDestroyed)
	{
		uFnDestroyed = UFunction::FindFunction("Function GameFramework.GameCrowdAgent.Destroyed");
	}

	AGameCrowdAgent_execDestroyed_Params Destroyed_Params;
	memset(&Destroyed_Params, 0, sizeof(Destroyed_Params));

	if (!uFnDestroyed)
	{
		return;
	}

	this->ProcessEvent(uFnDestroyed, &Destroyed_Params, nullptr);
}

// Function GameFramework.GameCrowdAgent.ResetPooledAgent
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:

void AGameCrowdAgent::ResetPooledAgent()
{
	static UFunction* uFnResetPooledAgent = nullptr;

	if (!uFnResetPooledAgent)
	{
		uFnResetPooledAgent = UFunction::FindFunction("Function GameFramework.GameCrowdAgent.ResetPooledAgent");
	}

	AGameCrowdAgent_execResetPooledAgent_Params ResetPooledAgent_Params;
	memset(&ResetPooledAgent_Params, 0, sizeof(ResetPooledAgent_Params));

	if (!uFnResetPooledAgent)
	{
		return;
	}

	this->ProcessEvent(uFnResetPooledAgent, &ResetPooledAgent_Params, nullptr);
}

// Function GameFramework.GameCrowdAgent.KillAgent
// [0x00020802] (FUNC_Defined | FUNC_Event | FUNC_Public)
// Parameter Info:

void AGameCrowdAgent::eventKillAgent()
{
	static UFunction* uFnKillAgent = nullptr;

	if (!uFnKillAgent)
	{
		uFnKillAgent = UFunction::FindFunction("Function GameFramework.GameCrowdAgent.KillAgent");
	}

	AGameCrowdAgent_eventKillAgent_Params KillAgent_Params;
	memset(&KillAgent_Params, 0, sizeof(KillAgent_Params));

	if (!uFnKillAgent)
	{
		return;
	}

	this->ProcessEvent(uFnKillAgent, &KillAgent_Params, nullptr);
}

// Function GameFramework.GameCrowdAgent.PostBeginPlay
// [0x00820102] (FUNC_Defined | FUNC_Simulated | FUNC_Public | FUNC_HasDefaults)
// Parameter Info:

void AGameCrowdAgent::PostBeginPlay()
{
	static UFunction* uFnPostBeginPlay = nullptr;

	if (!uFnPostBeginPlay)
	{
		uFnPostBeginPlay = UFunction::FindFunction("Function GameFramework.GameCrowdAgent.PostBeginPlay");
	}

	AGameCrowdAgent_execPostBeginPlay_Params PostBeginPlay_Params;
	memset(&PostBeginPlay_Params, 0, sizeof(PostBeginPlay_Params));

	if (!uFnPostBeginPlay)
	{
		return;
	}

	this->ProcessEvent(uFnPostBeginPlay, &PostBeginPlay_Params, nullptr);
}

// Function GameFramework.GameCrowdAgent.SetMaxSpeed
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:

void AGameCrowdAgent::SetMaxSpeed()
{
	static UFunction* uFnSetMaxSpeed = nullptr;

	if (!uFnSetMaxSpeed)
	{
		uFnSetMaxSpeed = UFunction::FindFunction("Function GameFramework.GameCrowdAgent.SetMaxSpeed");
	}

	AGameCrowdAgent_execSetMaxSpeed_Params SetMaxSpeed_Params;
	memset(&SetMaxSpeed_Params, 0, sizeof(SetMaxSpeed_Params));

	if (!uFnSetMaxSpeed)
	{
		return;
	}

	this->ProcessEvent(uFnSetMaxSpeed, &SetMaxSpeed_Params, nullptr);
}

// Function GameFramework.GameCrowdAgent.SetCurrentDestination
// [0x00020802] (FUNC_Defined | FUNC_Event | FUNC_Public)
// Parameter Info:
// class AGameCrowdDestination*   NewDest                        (CPF_Parm)

void AGameCrowdAgent::eventSetCurrentDestination(class AGameCrowdDestination* NewDest)
{
	static UFunction* uFnSetCurrentDestination = nullptr;

	if (!uFnSetCurrentDestination)
	{
		uFnSetCurrentDestination = UFunction::FindFunction("Function GameFramework.GameCrowdAgent.SetCurrentDestination");
	}

	AGameCrowdAgent_eventSetCurrentDestination_Params SetCurrentDestination_Params;
	memset(&SetCurrentDestination_Params, 0, sizeof(SetCurrentDestination_Params));

	if (!uFnSetCurrentDestination)
	{
		return;
	}
	SetCurrentDestination_Params.NewDest = NewDest;

	this->ProcessEvent(uFnSetCurrentDestination, &SetCurrentDestination_Params, nullptr);
}

// Function GameFramework.GameCrowdAgent.WaitForGroupMembers
// [0x00020802] (FUNC_Defined | FUNC_Event | FUNC_Public)
// Parameter Info:

void AGameCrowdAgent::eventWaitForGroupMembers()
{
	static UFunction* uFnWaitForGroupMembers = nullptr;

	if (!uFnWaitForGroupMembers)
	{
		uFnWaitForGroupMembers = UFunction::FindFunction("Function GameFramework.GameCrowdAgent.WaitForGroupMembers");
	}

	AGameCrowdAgent_eventWaitForGroupMembers_Params WaitForGroupMembers_Params;
	memset(&WaitForGroupMembers_Params, 0, sizeof(WaitForGroupMembers_Params));

	if (!uFnWaitForGroupMembers)
	{
		return;
	}

	this->ProcessEvent(uFnWaitForGroupMembers, &WaitForGroupMembers_Params, nullptr);
}

// Function GameFramework.GameCrowdAgent.PickBehaviorFrom
// [0x00824002] (FUNC_Defined | FUNC_OptionalParm | FUNC_Public | FUNC_HasDefaults)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class TArray<struct FBehaviorEntry> BehaviorList                   (CPF_Parm | CPF_NeedCtorLink)
// struct FVector                 BestCameraLoc                  (CPF_OptionalParm | CPF_Parm)

bool AGameCrowdAgent::PickBehaviorFrom(const class TArray<struct FBehaviorEntry>& BehaviorList, const struct FVector& optionalBestCameraLoc)
{
	static UFunction* uFnPickBehaviorFrom = nullptr;

	if (!uFnPickBehaviorFrom)
	{
		uFnPickBehaviorFrom = UFunction::FindFunction("Function GameFramework.GameCrowdAgent.PickBehaviorFrom");
	}

	AGameCrowdAgent_execPickBehaviorFrom_Params PickBehaviorFrom_Params;
	memset(&PickBehaviorFrom_Params, 0, sizeof(PickBehaviorFrom_Params));

	if (!uFnPickBehaviorFrom)
	{
		return PickBehaviorFrom_Params.ReturnValue;
	}
	memcpy_s(&PickBehaviorFrom_Params.BehaviorList, sizeof(PickBehaviorFrom_Params.BehaviorList), &BehaviorList, sizeof(BehaviorList));
	memcpy_s(&PickBehaviorFrom_Params.BestCameraLoc, sizeof(PickBehaviorFrom_Params.BestCameraLoc), &optionalBestCameraLoc, sizeof(optionalBestCameraLoc));

	this->ProcessEvent(uFnPickBehaviorFrom, &PickBehaviorFrom_Params, nullptr);

	return PickBehaviorFrom_Params.ReturnValue;
}

// Function GameFramework.GameCrowdAgent.SetPanic
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class AActor*                  PanicActor                     (CPF_Parm)
// uint32_t                       bNewPanic                      (CPF_Parm)

void AGameCrowdAgent::SetPanic(class AActor* PanicActor, bool bNewPanic)
{
	static UFunction* uFnSetPanic = nullptr;

	if (!uFnSetPanic)
	{
		uFnSetPanic = UFunction::FindFunction("Function GameFramework.GameCrowdAgent.SetPanic");
	}

	AGameCrowdAgent_execSetPanic_Params SetPanic_Params;
	memset(&SetPanic_Params, 0, sizeof(SetPanic_Params));

	if (!uFnSetPanic)
	{
		return;
	}
	SetPanic_Params.PanicActor = PanicActor;
	SetPanic_Params.bNewPanic = bNewPanic;

	this->ProcessEvent(uFnSetPanic, &SetPanic_Params, nullptr);
}

// Function GameFramework.GameCrowdAgent.IsPanicked
// [0x00020400] (FUNC_Native | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

bool AGameCrowdAgent::IsPanicked()
{
	static UFunction* uFnIsPanicked = nullptr;

	if (!uFnIsPanicked)
	{
		uFnIsPanicked = UFunction::FindFunction("Function GameFramework.GameCrowdAgent.IsPanicked");
	}

	AGameCrowdAgent_execIsPanicked_Params IsPanicked_Params;
	memset(&IsPanicked_Params, 0, sizeof(IsPanicked_Params));

	if (!uFnIsPanicked)
	{
		return IsPanicked_Params.ReturnValue;
	}

	uint16_t nativeIndex = uFnIsPanicked->iNative;
	uFnIsPanicked->iNative = 0;
	this->ProcessEvent(uFnIsPanicked, &IsPanicked_Params, nullptr);
	uFnIsPanicked->iNative = nativeIndex;

	return IsPanicked_Params.ReturnValue;
}

// Function GameFramework.GameCrowdAgent.FellOutOfWorld
// [0x00020902] (FUNC_Defined | FUNC_Simulated | FUNC_Event | FUNC_Public)
// Parameter Info:
// class UClass*                  dmgType                        (CPF_Parm)

void AGameCrowdAgent::eventFellOutOfWorld(class UClass* dmgType)
{
	static UFunction* uFnFellOutOfWorld = nullptr;

	if (!uFnFellOutOfWorld)
	{
		uFnFellOutOfWorld = UFunction::FindFunction("Function GameFramework.GameCrowdAgent.FellOutOfWorld");
	}

	AGameCrowdAgent_eventFellOutOfWorld_Params FellOutOfWorld_Params;
	memset(&FellOutOfWorld_Params, 0, sizeof(FellOutOfWorld_Params));

	if (!uFnFellOutOfWorld)
	{
		return;
	}
	FellOutOfWorld_Params.dmgType = dmgType;

	this->ProcessEvent(uFnFellOutOfWorld, &FellOutOfWorld_Params, nullptr);
}

// Function GameFramework.GameCrowdAgentSkeletal.CreateAttachments
// [0x00020102] (FUNC_Defined | FUNC_Simulated | FUNC_Public)
// Parameter Info:

void AGameCrowdAgentSkeletal::CreateAttachments()
{
	static UFunction* uFnCreateAttachments = nullptr;

	if (!uFnCreateAttachments)
	{
		uFnCreateAttachments = UFunction::FindFunction("Function GameFramework.GameCrowdAgentSkeletal.CreateAttachments");
	}

	AGameCrowdAgentSkeletal_execCreateAttachments_Params CreateAttachments_Params;
	memset(&CreateAttachments_Params, 0, sizeof(CreateAttachments_Params));

	if (!uFnCreateAttachments)
	{
		return;
	}

	this->ProcessEvent(uFnCreateAttachments, &CreateAttachments_Params, nullptr);
}

// Function GameFramework.GameCrowdAgentSkeletal.OnAnimEnd
// [0x00020802] (FUNC_Defined | FUNC_Event | FUNC_Public)
// Parameter Info:
// class UAnimNodeSequence*       SeqNode                        (CPF_Parm)
// float                          PlayedTime                     (CPF_Parm)
// float                          ExcessTime                     (CPF_Parm)

void AGameCrowdAgentSkeletal::eventOnAnimEnd(class UAnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime)
{
	static UFunction* uFnOnAnimEnd = nullptr;

	if (!uFnOnAnimEnd)
	{
		uFnOnAnimEnd = UFunction::FindFunction("Function GameFramework.GameCrowdAgentSkeletal.OnAnimEnd");
	}

	AGameCrowdAgentSkeletal_eventOnAnimEnd_Params OnAnimEnd_Params;
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

// Function GameFramework.GameCrowdAgentSkeletal.StopIdleAnimation
// [0x00020902] (FUNC_Defined | FUNC_Simulated | FUNC_Event | FUNC_Public)
// Parameter Info:

void AGameCrowdAgentSkeletal::eventStopIdleAnimation()
{
	static UFunction* uFnStopIdleAnimation = nullptr;

	if (!uFnStopIdleAnimation)
	{
		uFnStopIdleAnimation = UFunction::FindFunction("Function GameFramework.GameCrowdAgentSkeletal.StopIdleAnimation");
	}

	AGameCrowdAgentSkeletal_eventStopIdleAnimation_Params StopIdleAnimation_Params;
	memset(&StopIdleAnimation_Params, 0, sizeof(StopIdleAnimation_Params));

	if (!uFnStopIdleAnimation)
	{
		return;
	}

	this->ProcessEvent(uFnStopIdleAnimation, &StopIdleAnimation_Params, nullptr);
}

// Function GameFramework.GameCrowdAgentSkeletal.PlayIdleAnimation
// [0x00020902] (FUNC_Defined | FUNC_Simulated | FUNC_Event | FUNC_Public)
// Parameter Info:

void AGameCrowdAgentSkeletal::eventPlayIdleAnimation()
{
	static UFunction* uFnPlayIdleAnimation = nullptr;

	if (!uFnPlayIdleAnimation)
	{
		uFnPlayIdleAnimation = UFunction::FindFunction("Function GameFramework.GameCrowdAgentSkeletal.PlayIdleAnimation");
	}

	AGameCrowdAgentSkeletal_eventPlayIdleAnimation_Params PlayIdleAnimation_Params;
	memset(&PlayIdleAnimation_Params, 0, sizeof(PlayIdleAnimation_Params));

	if (!uFnPlayIdleAnimation)
	{
		return;
	}

	this->ProcessEvent(uFnPlayIdleAnimation, &PlayIdleAnimation_Params, nullptr);
}

// Function GameFramework.GameCrowdAgentSkeletal.ClearLatentAnimation
// [0x00020802] (FUNC_Defined | FUNC_Event | FUNC_Public)
// Parameter Info:

void AGameCrowdAgentSkeletal::eventClearLatentAnimation()
{
	static UFunction* uFnClearLatentAnimation = nullptr;

	if (!uFnClearLatentAnimation)
	{
		uFnClearLatentAnimation = UFunction::FindFunction("Function GameFramework.GameCrowdAgentSkeletal.ClearLatentAnimation");
	}

	AGameCrowdAgentSkeletal_eventClearLatentAnimation_Params ClearLatentAnimation_Params;
	memset(&ClearLatentAnimation_Params, 0, sizeof(ClearLatentAnimation_Params));

	if (!uFnClearLatentAnimation)
	{
		return;
	}

	this->ProcessEvent(uFnClearLatentAnimation, &ClearLatentAnimation_Params, nullptr);
}

// Function GameFramework.GameCrowdAgentSkeletal.OnPlayAgentAnimation
// [0x00020102] (FUNC_Defined | FUNC_Simulated | FUNC_Public)
// Parameter Info:
// class USeqAct_PlayAgentAnimation* Action                         (CPF_Parm)

void AGameCrowdAgentSkeletal::OnPlayAgentAnimation(class USeqAct_PlayAgentAnimation* Action)
{
	static UFunction* uFnOnPlayAgentAnimation = nullptr;

	if (!uFnOnPlayAgentAnimation)
	{
		uFnOnPlayAgentAnimation = UFunction::FindFunction("Function GameFramework.GameCrowdAgentSkeletal.OnPlayAgentAnimation");
	}

	AGameCrowdAgentSkeletal_execOnPlayAgentAnimation_Params OnPlayAgentAnimation_Params;
	memset(&OnPlayAgentAnimation_Params, 0, sizeof(OnPlayAgentAnimation_Params));

	if (!uFnOnPlayAgentAnimation)
	{
		return;
	}
	OnPlayAgentAnimation_Params.Action = Action;

	this->ProcessEvent(uFnOnPlayAgentAnimation, &OnPlayAgentAnimation_Params, nullptr);
}

// Function GameFramework.GameCrowdAgentSkeletal.SetRootMotion
// [0x00020400] (FUNC_Native | FUNC_Public)
// Parameter Info:
// uint32_t                       bRootMotionEnabled             (CPF_Parm)

void AGameCrowdAgentSkeletal::SetRootMotion(bool bRootMotionEnabled)
{
	static UFunction* uFnSetRootMotion = nullptr;

	if (!uFnSetRootMotion)
	{
		uFnSetRootMotion = UFunction::FindFunction("Function GameFramework.GameCrowdAgentSkeletal.SetRootMotion");
	}

	AGameCrowdAgentSkeletal_execSetRootMotion_Params SetRootMotion_Params;
	memset(&SetRootMotion_Params, 0, sizeof(SetRootMotion_Params));

	if (!uFnSetRootMotion)
	{
		return;
	}
	SetRootMotion_Params.bRootMotionEnabled = bRootMotionEnabled;

	uint16_t nativeIndex = uFnSetRootMotion->iNative;
	uFnSetRootMotion->iNative = 0;
	this->ProcessEvent(uFnSetRootMotion, &SetRootMotion_Params, nullptr);
	uFnSetRootMotion->iNative = nativeIndex;
}

// Function GameFramework.GameCrowdAgentSkeletal.PlayDeath
// [0x00020400] (FUNC_Native | FUNC_Public)
// Parameter Info:
// struct FVector                 KillMomentum                   (CPF_Parm)

void AGameCrowdAgentSkeletal::PlayDeath(const struct FVector& KillMomentum)
{
	static UFunction* uFnPlayDeath = nullptr;

	if (!uFnPlayDeath)
	{
		uFnPlayDeath = UFunction::FindFunction("Function GameFramework.GameCrowdAgentSkeletal.PlayDeath");
	}

	AGameCrowdAgentSkeletal_execPlayDeath_Params PlayDeath_Params;
	memset(&PlayDeath_Params, 0, sizeof(PlayDeath_Params));

	if (!uFnPlayDeath)
	{
		return;
	}
	memcpy_s(&PlayDeath_Params.KillMomentum, sizeof(PlayDeath_Params.KillMomentum), &KillMomentum, sizeof(KillMomentum));

	uint16_t nativeIndex = uFnPlayDeath->iNative;
	uFnPlayDeath->iNative = 0;
	this->ProcessEvent(uFnPlayDeath, &PlayDeath_Params, nullptr);
	uFnPlayDeath->iNative = nativeIndex;
}

// Function GameFramework.GameCrowdAgentSkeletal.SetLighting
// [0x00020102] (FUNC_Defined | FUNC_Simulated | FUNC_Public)
// Parameter Info:
// uint32_t                       bEnableLightEnvironment        (CPF_Parm)
// struct FLightingChannelContainer AgentLightingChannel           (CPF_Parm)
// uint32_t                       bCastShadows                   (CPF_Parm)

void AGameCrowdAgentSkeletal::SetLighting(bool bEnableLightEnvironment, const struct FLightingChannelContainer& AgentLightingChannel, bool bCastShadows)
{
	static UFunction* uFnSetLighting = nullptr;

	if (!uFnSetLighting)
	{
		uFnSetLighting = UFunction::FindFunction("Function GameFramework.GameCrowdAgentSkeletal.SetLighting");
	}

	AGameCrowdAgentSkeletal_execSetLighting_Params SetLighting_Params;
	memset(&SetLighting_Params, 0, sizeof(SetLighting_Params));

	if (!uFnSetLighting)
	{
		return;
	}
	SetLighting_Params.bEnableLightEnvironment = bEnableLightEnvironment;
	memcpy_s(&SetLighting_Params.AgentLightingChannel, sizeof(SetLighting_Params.AgentLightingChannel), &AgentLightingChannel, sizeof(AgentLightingChannel));
	SetLighting_Params.bCastShadows = bCastShadows;

	this->ProcessEvent(uFnSetLighting, &SetLighting_Params, nullptr);
}

// Function GameFramework.GameCrowdAgentSkeletal.PostBeginPlay
// [0x00020102] (FUNC_Defined | FUNC_Simulated | FUNC_Public)
// Parameter Info:

void AGameCrowdAgentSkeletal::PostBeginPlay()
{
	static UFunction* uFnPostBeginPlay = nullptr;

	if (!uFnPostBeginPlay)
	{
		uFnPostBeginPlay = UFunction::FindFunction("Function GameFramework.GameCrowdAgentSkeletal.PostBeginPlay");
	}

	AGameCrowdAgentSkeletal_execPostBeginPlay_Params PostBeginPlay_Params;
	memset(&PostBeginPlay_Params, 0, sizeof(PostBeginPlay_Params));

	if (!uFnPostBeginPlay)
	{
		return;
	}

	this->ProcessEvent(uFnPostBeginPlay, &PostBeginPlay_Params, nullptr);
}

// Function GameFramework.GameCrowdAgentBehavior.AllowBehaviorAt
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class AGameCrowdDestination*   Destination                    (CPF_Parm)

bool UGameCrowdAgentBehavior::AllowBehaviorAt(class AGameCrowdDestination* Destination)
{
	static UFunction* uFnAllowBehaviorAt = nullptr;

	if (!uFnAllowBehaviorAt)
	{
		uFnAllowBehaviorAt = UFunction::FindFunction("Function GameFramework.GameCrowdAgentBehavior.AllowBehaviorAt");
	}

	UGameCrowdAgentBehavior_execAllowBehaviorAt_Params AllowBehaviorAt_Params;
	memset(&AllowBehaviorAt_Params, 0, sizeof(AllowBehaviorAt_Params));

	if (!uFnAllowBehaviorAt)
	{
		return AllowBehaviorAt_Params.ReturnValue;
	}
	AllowBehaviorAt_Params.Destination = Destination;

	this->ProcessEvent(uFnAllowBehaviorAt, &AllowBehaviorAt_Params, nullptr);

	return AllowBehaviorAt_Params.ReturnValue;
}

// Function GameFramework.GameCrowdAgentBehavior.AllowThisDestination
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class AGameCrowdDestination*   Destination                    (CPF_Parm)

bool UGameCrowdAgentBehavior::AllowThisDestination(class AGameCrowdDestination* Destination)
{
	static UFunction* uFnAllowThisDestination = nullptr;

	if (!uFnAllowThisDestination)
	{
		uFnAllowThisDestination = UFunction::FindFunction("Function GameFramework.GameCrowdAgentBehavior.AllowThisDestination");
	}

	UGameCrowdAgentBehavior_execAllowThisDestination_Params AllowThisDestination_Params;
	memset(&AllowThisDestination_Params, 0, sizeof(AllowThisDestination_Params));

	if (!uFnAllowThisDestination)
	{
		return AllowThisDestination_Params.ReturnValue;
	}
	AllowThisDestination_Params.Destination = Destination;

	this->ProcessEvent(uFnAllowThisDestination, &AllowThisDestination_Params, nullptr);

	return AllowThisDestination_Params.ReturnValue;
}

// Function GameFramework.GameCrowdAgentBehavior.PropagateViralBehaviorTo
// [0x00020800] (FUNC_Event | FUNC_Public)
// Parameter Info:
// class AGameCrowdAgent*         OtherAgent                     (CPF_Parm)

void UGameCrowdAgentBehavior::eventPropagateViralBehaviorTo(class AGameCrowdAgent* OtherAgent)
{
	static UFunction* uFnPropagateViralBehaviorTo = nullptr;

	if (!uFnPropagateViralBehaviorTo)
	{
		uFnPropagateViralBehaviorTo = UFunction::FindFunction("Function GameFramework.GameCrowdAgentBehavior.PropagateViralBehaviorTo");
	}

	UGameCrowdAgentBehavior_eventPropagateViralBehaviorTo_Params PropagateViralBehaviorTo_Params;
	memset(&PropagateViralBehaviorTo_Params, 0, sizeof(PropagateViralBehaviorTo_Params));

	if (!uFnPropagateViralBehaviorTo)
	{
		return;
	}
	PropagateViralBehaviorTo_Params.OtherAgent = OtherAgent;

	this->ProcessEvent(uFnPropagateViralBehaviorTo, &PropagateViralBehaviorTo_Params, nullptr);
}

// Function GameFramework.GameCrowdAgentBehavior.ActivatedBy
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class AActor*                  NewActionTarget                (CPF_Parm)

void UGameCrowdAgentBehavior::ActivatedBy(class AActor* NewActionTarget)
{
	static UFunction* uFnActivatedBy = nullptr;

	if (!uFnActivatedBy)
	{
		uFnActivatedBy = UFunction::FindFunction("Function GameFramework.GameCrowdAgentBehavior.ActivatedBy");
	}

	UGameCrowdAgentBehavior_execActivatedBy_Params ActivatedBy_Params;
	memset(&ActivatedBy_Params, 0, sizeof(ActivatedBy_Params));

	if (!uFnActivatedBy)
	{
		return;
	}
	ActivatedBy_Params.NewActionTarget = NewActionTarget;

	this->ProcessEvent(uFnActivatedBy, &ActivatedBy_Params, nullptr);
}

// Function GameFramework.GameCrowdAgentBehavior.GetDestinationActor
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class AActor*                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

class AActor* UGameCrowdAgentBehavior::GetDestinationActor()
{
	static UFunction* uFnGetDestinationActor = nullptr;

	if (!uFnGetDestinationActor)
	{
		uFnGetDestinationActor = UFunction::FindFunction("Function GameFramework.GameCrowdAgentBehavior.GetDestinationActor");
	}

	UGameCrowdAgentBehavior_execGetDestinationActor_Params GetDestinationActor_Params;
	memset(&GetDestinationActor_Params, 0, sizeof(GetDestinationActor_Params));

	if (!uFnGetDestinationActor)
	{
		return GetDestinationActor_Params.ReturnValue;
	}

	this->ProcessEvent(uFnGetDestinationActor, &GetDestinationActor_Params, nullptr);

	return GetDestinationActor_Params.ReturnValue;
}

// Function GameFramework.GameCrowdAgentBehavior.ChangingDestination
// [0x00020000] (FUNC_Public)
// Parameter Info:
// class AGameCrowdDestination*   NewDest                        (CPF_Parm)

void UGameCrowdAgentBehavior::ChangingDestination(class AGameCrowdDestination* NewDest)
{
	static UFunction* uFnChangingDestination = nullptr;

	if (!uFnChangingDestination)
	{
		uFnChangingDestination = UFunction::FindFunction("Function GameFramework.GameCrowdAgentBehavior.ChangingDestination");
	}

	UGameCrowdAgentBehavior_execChangingDestination_Params ChangingDestination_Params;
	memset(&ChangingDestination_Params, 0, sizeof(ChangingDestination_Params));

	if (!uFnChangingDestination)
	{
		return;
	}
	ChangingDestination_Params.NewDest = NewDest;

	this->ProcessEvent(uFnChangingDestination, &ChangingDestination_Params, nullptr);
}

// Function GameFramework.GameCrowdAgentBehavior.GetBehaviorString
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class FString                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)

class FString UGameCrowdAgentBehavior::GetBehaviorString()
{
	static UFunction* uFnGetBehaviorString = nullptr;

	if (!uFnGetBehaviorString)
	{
		uFnGetBehaviorString = UFunction::FindFunction("Function GameFramework.GameCrowdAgentBehavior.GetBehaviorString");
	}

	UGameCrowdAgentBehavior_execGetBehaviorString_Params GetBehaviorString_Params;
	memset(&GetBehaviorString_Params, 0, sizeof(GetBehaviorString_Params));

	if (!uFnGetBehaviorString)
	{
		return GetBehaviorString_Params.ReturnValue;
	}

	this->ProcessEvent(uFnGetBehaviorString, &GetBehaviorString_Params, nullptr);

	return GetBehaviorString_Params.ReturnValue;
}

// Function GameFramework.GameCrowdAgentBehavior.OnAnimEnd
// [0x00020800] (FUNC_Event | FUNC_Public)
// Parameter Info:
// class UAnimNodeSequence*       SeqNode                        (CPF_Parm)
// float                          PlayedTime                     (CPF_Parm)
// float                          ExcessTime                     (CPF_Parm)

void UGameCrowdAgentBehavior::eventOnAnimEnd(class UAnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime)
{
	static UFunction* uFnOnAnimEnd = nullptr;

	if (!uFnOnAnimEnd)
	{
		uFnOnAnimEnd = UFunction::FindFunction("Function GameFramework.GameCrowdAgentBehavior.OnAnimEnd");
	}

	UGameCrowdAgentBehavior_eventOnAnimEnd_Params OnAnimEnd_Params;
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

// Function GameFramework.GameCrowdAgentBehavior.StopBehavior
// [0x00020000] (FUNC_Public)
// Parameter Info:

void UGameCrowdAgentBehavior::StopBehavior()
{
	static UFunction* uFnStopBehavior = nullptr;

	if (!uFnStopBehavior)
	{
		uFnStopBehavior = UFunction::FindFunction("Function GameFramework.GameCrowdAgentBehavior.StopBehavior");
	}

	UGameCrowdAgentBehavior_execStopBehavior_Params StopBehavior_Params;
	memset(&StopBehavior_Params, 0, sizeof(StopBehavior_Params));

	if (!uFnStopBehavior)
	{
		return;
	}

	this->ProcessEvent(uFnStopBehavior, &StopBehavior_Params, nullptr);
}

// Function GameFramework.GameCrowdAgentBehavior.InitBehavior
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class AGameCrowdAgent*         Agent                          (CPF_Parm)

void UGameCrowdAgentBehavior::InitBehavior(class AGameCrowdAgent* Agent)
{
	static UFunction* uFnInitBehavior = nullptr;

	if (!uFnInitBehavior)
	{
		uFnInitBehavior = UFunction::FindFunction("Function GameFramework.GameCrowdAgentBehavior.InitBehavior");
	}

	UGameCrowdAgentBehavior_execInitBehavior_Params InitBehavior_Params;
	memset(&InitBehavior_Params, 0, sizeof(InitBehavior_Params));

	if (!uFnInitBehavior)
	{
		return;
	}
	InitBehavior_Params.Agent = Agent;

	this->ProcessEvent(uFnInitBehavior, &InitBehavior_Params, nullptr);
}

// Function GameFramework.GameCrowdAgentBehavior.HandleMovement
// [0x00020400] (FUNC_Native | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

bool UGameCrowdAgentBehavior::HandleMovement()
{
	static UFunction* uFnHandleMovement = nullptr;

	if (!uFnHandleMovement)
	{
		uFnHandleMovement = UFunction::FindFunction("Function GameFramework.GameCrowdAgentBehavior.HandleMovement");
	}

	UGameCrowdAgentBehavior_execHandleMovement_Params HandleMovement_Params;
	memset(&HandleMovement_Params, 0, sizeof(HandleMovement_Params));

	if (!uFnHandleMovement)
	{
		return HandleMovement_Params.ReturnValue;
	}

	uint16_t nativeIndex = uFnHandleMovement->iNative;
	uFnHandleMovement->iNative = 0;
	this->ProcessEvent(uFnHandleMovement, &HandleMovement_Params, nullptr);
	uFnHandleMovement->iNative = nativeIndex;

	return HandleMovement_Params.ReturnValue;
}

// Function GameFramework.GameCrowdAgentBehavior.FinishedTargetRotation
// [0x00020800] (FUNC_Event | FUNC_Public)
// Parameter Info:

void UGameCrowdAgentBehavior::eventFinishedTargetRotation()
{
	static UFunction* uFnFinishedTargetRotation = nullptr;

	if (!uFnFinishedTargetRotation)
	{
		uFnFinishedTargetRotation = UFunction::FindFunction("Function GameFramework.GameCrowdAgentBehavior.FinishedTargetRotation");
	}

	UGameCrowdAgentBehavior_eventFinishedTargetRotation_Params FinishedTargetRotation_Params;
	memset(&FinishedTargetRotation_Params, 0, sizeof(FinishedTargetRotation_Params));

	if (!uFnFinishedTargetRotation)
	{
		return;
	}

	this->ProcessEvent(uFnFinishedTargetRotation, &FinishedTargetRotation_Params, nullptr);
}

// Function GameFramework.GameCrowdAgentBehavior.CanBeUsedBy
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class AGameCrowdAgent*         Agent                          (CPF_Parm)
// struct FVector                 cameraLoc                      (CPF_Parm)

bool UGameCrowdAgentBehavior::CanBeUsedBy(class AGameCrowdAgent* Agent, const struct FVector& cameraLoc)
{
	static UFunction* uFnCanBeUsedBy = nullptr;

	if (!uFnCanBeUsedBy)
	{
		uFnCanBeUsedBy = UFunction::FindFunction("Function GameFramework.GameCrowdAgentBehavior.CanBeUsedBy");
	}

	UGameCrowdAgentBehavior_execCanBeUsedBy_Params CanBeUsedBy_Params;
	memset(&CanBeUsedBy_Params, 0, sizeof(CanBeUsedBy_Params));

	if (!uFnCanBeUsedBy)
	{
		return CanBeUsedBy_Params.ReturnValue;
	}
	CanBeUsedBy_Params.Agent = Agent;
	memcpy_s(&CanBeUsedBy_Params.cameraLoc, sizeof(CanBeUsedBy_Params.cameraLoc), &cameraLoc, sizeof(cameraLoc));

	this->ProcessEvent(uFnCanBeUsedBy, &CanBeUsedBy_Params, nullptr);

	return CanBeUsedBy_Params.ReturnValue;
}

// Function GameFramework.GameCrowdAgentBehavior.Tick
// [0x00020400] (FUNC_Native | FUNC_Public)
// Parameter Info:
// float                          DeltaTime                      (CPF_Parm)

void UGameCrowdAgentBehavior::Tick(float DeltaTime)
{
	static UFunction* uFnTick = nullptr;

	if (!uFnTick)
	{
		uFnTick = UFunction::FindFunction("Function GameFramework.GameCrowdAgentBehavior.Tick");
	}

	UGameCrowdAgentBehavior_execTick_Params Tick_Params;
	memset(&Tick_Params, 0, sizeof(Tick_Params));

	if (!uFnTick)
	{
		return;
	}
	Tick_Params.DeltaTime = DeltaTime;

	uint16_t nativeIndex = uFnTick->iNative;
	uFnTick->iNative = 0;
	this->ProcessEvent(uFnTick, &Tick_Params, nullptr);
	uFnTick->iNative = nativeIndex;
}

// Function GameFramework.GameCrowdAgentBehavior.ShouldEndIdle
// [0x00020400] (FUNC_Native | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

bool UGameCrowdAgentBehavior::ShouldEndIdle()
{
	static UFunction* uFnShouldEndIdle = nullptr;

	if (!uFnShouldEndIdle)
	{
		uFnShouldEndIdle = UFunction::FindFunction("Function GameFramework.GameCrowdAgentBehavior.ShouldEndIdle");
	}

	UGameCrowdAgentBehavior_execShouldEndIdle_Params ShouldEndIdle_Params;
	memset(&ShouldEndIdle_Params, 0, sizeof(ShouldEndIdle_Params));

	if (!uFnShouldEndIdle)
	{
		return ShouldEndIdle_Params.ReturnValue;
	}

	uint16_t nativeIndex = uFnShouldEndIdle->iNative;
	uFnShouldEndIdle->iNative = 0;
	this->ProcessEvent(uFnShouldEndIdle, &ShouldEndIdle_Params, nullptr);
	uFnShouldEndIdle->iNative = nativeIndex;

	return ShouldEndIdle_Params.ReturnValue;
}

// Function GameFramework.GameCrowdBehavior_PlayAnimation.GetBehaviorString
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class FString                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)

class FString UGameCrowdBehavior_PlayAnimation::GetBehaviorString()
{
	static UFunction* uFnGetBehaviorString = nullptr;

	if (!uFnGetBehaviorString)
	{
		uFnGetBehaviorString = UFunction::FindFunction("Function GameFramework.GameCrowdBehavior_PlayAnimation.GetBehaviorString");
	}

	UGameCrowdBehavior_PlayAnimation_execGetBehaviorString_Params GetBehaviorString_Params;
	memset(&GetBehaviorString_Params, 0, sizeof(GetBehaviorString_Params));

	if (!uFnGetBehaviorString)
	{
		return GetBehaviorString_Params.ReturnValue;
	}

	this->ProcessEvent(uFnGetBehaviorString, &GetBehaviorString_Params, nullptr);

	return GetBehaviorString_Params.ReturnValue;
}

// Function GameFramework.GameCrowdBehavior_PlayAnimation.StopBehavior
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:

void UGameCrowdBehavior_PlayAnimation::StopBehavior()
{
	static UFunction* uFnStopBehavior = nullptr;

	if (!uFnStopBehavior)
	{
		uFnStopBehavior = UFunction::FindFunction("Function GameFramework.GameCrowdBehavior_PlayAnimation.StopBehavior");
	}

	UGameCrowdBehavior_PlayAnimation_execStopBehavior_Params StopBehavior_Params;
	memset(&StopBehavior_Params, 0, sizeof(StopBehavior_Params));

	if (!uFnStopBehavior)
	{
		return;
	}

	this->ProcessEvent(uFnStopBehavior, &StopBehavior_Params, nullptr);
}

// Function GameFramework.GameCrowdBehavior_PlayAnimation.PlayAgentAnimationNow
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:

void UGameCrowdBehavior_PlayAnimation::PlayAgentAnimationNow()
{
	static UFunction* uFnPlayAgentAnimationNow = nullptr;

	if (!uFnPlayAgentAnimationNow)
	{
		uFnPlayAgentAnimationNow = UFunction::FindFunction("Function GameFramework.GameCrowdBehavior_PlayAnimation.PlayAgentAnimationNow");
	}

	UGameCrowdBehavior_PlayAnimation_execPlayAgentAnimationNow_Params PlayAgentAnimationNow_Params;
	memset(&PlayAgentAnimationNow_Params, 0, sizeof(PlayAgentAnimationNow_Params));

	if (!uFnPlayAgentAnimationNow)
	{
		return;
	}

	this->ProcessEvent(uFnPlayAgentAnimationNow, &PlayAgentAnimationNow_Params, nullptr);
}

// Function GameFramework.GameCrowdBehavior_PlayAnimation.OnAnimEnd
// [0x00020802] (FUNC_Defined | FUNC_Event | FUNC_Public)
// Parameter Info:
// class UAnimNodeSequence*       SeqNode                        (CPF_Parm)
// float                          PlayedTime                     (CPF_Parm)
// float                          ExcessTime                     (CPF_Parm)

void UGameCrowdBehavior_PlayAnimation::eventOnAnimEnd(class UAnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime)
{
	static UFunction* uFnOnAnimEnd = nullptr;

	if (!uFnOnAnimEnd)
	{
		uFnOnAnimEnd = UFunction::FindFunction("Function GameFramework.GameCrowdBehavior_PlayAnimation.OnAnimEnd");
	}

	UGameCrowdBehavior_PlayAnimation_eventOnAnimEnd_Params OnAnimEnd_Params;
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

// Function GameFramework.GameCrowdBehavior_PlayAnimation.SetSequenceOutput
// [0x00020400] (FUNC_Native | FUNC_Public)
// Parameter Info:

void UGameCrowdBehavior_PlayAnimation::SetSequenceOutput()
{
	static UFunction* uFnSetSequenceOutput = nullptr;

	if (!uFnSetSequenceOutput)
	{
		uFnSetSequenceOutput = UFunction::FindFunction("Function GameFramework.GameCrowdBehavior_PlayAnimation.SetSequenceOutput");
	}

	UGameCrowdBehavior_PlayAnimation_execSetSequenceOutput_Params SetSequenceOutput_Params;
	memset(&SetSequenceOutput_Params, 0, sizeof(SetSequenceOutput_Params));

	if (!uFnSetSequenceOutput)
	{
		return;
	}

	uint16_t nativeIndex = uFnSetSequenceOutput->iNative;
	uFnSetSequenceOutput->iNative = 0;
	this->ProcessEvent(uFnSetSequenceOutput, &SetSequenceOutput_Params, nullptr);
	uFnSetSequenceOutput->iNative = nativeIndex;
}

// Function GameFramework.GameCrowdBehavior_PlayAnimation.FinishedTargetRotation
// [0x00020802] (FUNC_Defined | FUNC_Event | FUNC_Public)
// Parameter Info:

void UGameCrowdBehavior_PlayAnimation::eventFinishedTargetRotation()
{
	static UFunction* uFnFinishedTargetRotation = nullptr;

	if (!uFnFinishedTargetRotation)
	{
		uFnFinishedTargetRotation = UFunction::FindFunction("Function GameFramework.GameCrowdBehavior_PlayAnimation.FinishedTargetRotation");
	}

	UGameCrowdBehavior_PlayAnimation_eventFinishedTargetRotation_Params FinishedTargetRotation_Params;
	memset(&FinishedTargetRotation_Params, 0, sizeof(FinishedTargetRotation_Params));

	if (!uFnFinishedTargetRotation)
	{
		return;
	}

	this->ProcessEvent(uFnFinishedTargetRotation, &FinishedTargetRotation_Params, nullptr);
}

// Function GameFramework.GameCrowdBehavior_PlayAnimation.InitBehavior
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class AGameCrowdAgent*         Agent                          (CPF_Parm)

void UGameCrowdBehavior_PlayAnimation::InitBehavior(class AGameCrowdAgent* Agent)
{
	static UFunction* uFnInitBehavior = nullptr;

	if (!uFnInitBehavior)
	{
		uFnInitBehavior = UFunction::FindFunction("Function GameFramework.GameCrowdBehavior_PlayAnimation.InitBehavior");
	}

	UGameCrowdBehavior_PlayAnimation_execInitBehavior_Params InitBehavior_Params;
	memset(&InitBehavior_Params, 0, sizeof(InitBehavior_Params));

	if (!uFnInitBehavior)
	{
		return;
	}
	InitBehavior_Params.Agent = Agent;

	this->ProcessEvent(uFnInitBehavior, &InitBehavior_Params, nullptr);
}

// Function GameFramework.GameCrowdBehavior_RunFromPanic.GetBehaviorString
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class FString                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)

class FString UGameCrowdBehavior_RunFromPanic::GetBehaviorString()
{
	static UFunction* uFnGetBehaviorString = nullptr;

	if (!uFnGetBehaviorString)
	{
		uFnGetBehaviorString = UFunction::FindFunction("Function GameFramework.GameCrowdBehavior_RunFromPanic.GetBehaviorString");
	}

	UGameCrowdBehavior_RunFromPanic_execGetBehaviorString_Params GetBehaviorString_Params;
	memset(&GetBehaviorString_Params, 0, sizeof(GetBehaviorString_Params));

	if (!uFnGetBehaviorString)
	{
		return GetBehaviorString_Params.ReturnValue;
	}

	this->ProcessEvent(uFnGetBehaviorString, &GetBehaviorString_Params, nullptr);

	return GetBehaviorString_Params.ReturnValue;
}

// Function GameFramework.GameCrowdBehavior_RunFromPanic.AllowBehaviorAt
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class AGameCrowdDestination*   Destination                    (CPF_Parm)

bool UGameCrowdBehavior_RunFromPanic::AllowBehaviorAt(class AGameCrowdDestination* Destination)
{
	static UFunction* uFnAllowBehaviorAt = nullptr;

	if (!uFnAllowBehaviorAt)
	{
		uFnAllowBehaviorAt = UFunction::FindFunction("Function GameFramework.GameCrowdBehavior_RunFromPanic.AllowBehaviorAt");
	}

	UGameCrowdBehavior_RunFromPanic_execAllowBehaviorAt_Params AllowBehaviorAt_Params;
	memset(&AllowBehaviorAt_Params, 0, sizeof(AllowBehaviorAt_Params));

	if (!uFnAllowBehaviorAt)
	{
		return AllowBehaviorAt_Params.ReturnValue;
	}
	AllowBehaviorAt_Params.Destination = Destination;

	this->ProcessEvent(uFnAllowBehaviorAt, &AllowBehaviorAt_Params, nullptr);

	return AllowBehaviorAt_Params.ReturnValue;
}

// Function GameFramework.GameCrowdBehavior_RunFromPanic.AllowThisDestination
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class AGameCrowdDestination*   Destination                    (CPF_Parm)

bool UGameCrowdBehavior_RunFromPanic::AllowThisDestination(class AGameCrowdDestination* Destination)
{
	static UFunction* uFnAllowThisDestination = nullptr;

	if (!uFnAllowThisDestination)
	{
		uFnAllowThisDestination = UFunction::FindFunction("Function GameFramework.GameCrowdBehavior_RunFromPanic.AllowThisDestination");
	}

	UGameCrowdBehavior_RunFromPanic_execAllowThisDestination_Params AllowThisDestination_Params;
	memset(&AllowThisDestination_Params, 0, sizeof(AllowThisDestination_Params));

	if (!uFnAllowThisDestination)
	{
		return AllowThisDestination_Params.ReturnValue;
	}
	AllowThisDestination_Params.Destination = Destination;

	this->ProcessEvent(uFnAllowThisDestination, &AllowThisDestination_Params, nullptr);

	return AllowThisDestination_Params.ReturnValue;
}

// Function GameFramework.GameCrowdBehavior_RunFromPanic.PropagateViralBehaviorTo
// [0x00020802] (FUNC_Defined | FUNC_Event | FUNC_Public)
// Parameter Info:
// class AGameCrowdAgent*         OtherAgent                     (CPF_Parm)

void UGameCrowdBehavior_RunFromPanic::eventPropagateViralBehaviorTo(class AGameCrowdAgent* OtherAgent)
{
	static UFunction* uFnPropagateViralBehaviorTo = nullptr;

	if (!uFnPropagateViralBehaviorTo)
	{
		uFnPropagateViralBehaviorTo = UFunction::FindFunction("Function GameFramework.GameCrowdBehavior_RunFromPanic.PropagateViralBehaviorTo");
	}

	UGameCrowdBehavior_RunFromPanic_eventPropagateViralBehaviorTo_Params PropagateViralBehaviorTo_Params;
	memset(&PropagateViralBehaviorTo_Params, 0, sizeof(PropagateViralBehaviorTo_Params));

	if (!uFnPropagateViralBehaviorTo)
	{
		return;
	}
	PropagateViralBehaviorTo_Params.OtherAgent = OtherAgent;

	this->ProcessEvent(uFnPropagateViralBehaviorTo, &PropagateViralBehaviorTo_Params, nullptr);
}

// Function GameFramework.GameCrowdBehavior_RunFromPanic.StopBehavior
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:

void UGameCrowdBehavior_RunFromPanic::StopBehavior()
{
	static UFunction* uFnStopBehavior = nullptr;

	if (!uFnStopBehavior)
	{
		uFnStopBehavior = UFunction::FindFunction("Function GameFramework.GameCrowdBehavior_RunFromPanic.StopBehavior");
	}

	UGameCrowdBehavior_RunFromPanic_execStopBehavior_Params StopBehavior_Params;
	memset(&StopBehavior_Params, 0, sizeof(StopBehavior_Params));

	if (!uFnStopBehavior)
	{
		return;
	}

	this->ProcessEvent(uFnStopBehavior, &StopBehavior_Params, nullptr);
}

// Function GameFramework.GameCrowdBehavior_RunFromPanic.InitBehavior
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class AGameCrowdAgent*         Agent                          (CPF_Parm)

void UGameCrowdBehavior_RunFromPanic::InitBehavior(class AGameCrowdAgent* Agent)
{
	static UFunction* uFnInitBehavior = nullptr;

	if (!uFnInitBehavior)
	{
		uFnInitBehavior = UFunction::FindFunction("Function GameFramework.GameCrowdBehavior_RunFromPanic.InitBehavior");
	}

	UGameCrowdBehavior_RunFromPanic_execInitBehavior_Params InitBehavior_Params;
	memset(&InitBehavior_Params, 0, sizeof(InitBehavior_Params));

	if (!uFnInitBehavior)
	{
		return;
	}
	InitBehavior_Params.Agent = Agent;

	this->ProcessEvent(uFnInitBehavior, &InitBehavior_Params, nullptr);
}

// Function GameFramework.GameCrowdBehavior_RunFromPanic.ActivatedBy
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class AActor*                  NewActionTarget                (CPF_Parm)

void UGameCrowdBehavior_RunFromPanic::ActivatedBy(class AActor* NewActionTarget)
{
	static UFunction* uFnActivatedBy = nullptr;

	if (!uFnActivatedBy)
	{
		uFnActivatedBy = UFunction::FindFunction("Function GameFramework.GameCrowdBehavior_RunFromPanic.ActivatedBy");
	}

	UGameCrowdBehavior_RunFromPanic_execActivatedBy_Params ActivatedBy_Params;
	memset(&ActivatedBy_Params, 0, sizeof(ActivatedBy_Params));

	if (!uFnActivatedBy)
	{
		return;
	}
	ActivatedBy_Params.NewActionTarget = NewActionTarget;

	this->ProcessEvent(uFnActivatedBy, &ActivatedBy_Params, nullptr);
}

// Function GameFramework.GameCrowdBehavior_WaitForGroup.StopBehavior
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:

void UGameCrowdBehavior_WaitForGroup::StopBehavior()
{
	static UFunction* uFnStopBehavior = nullptr;

	if (!uFnStopBehavior)
	{
		uFnStopBehavior = UFunction::FindFunction("Function GameFramework.GameCrowdBehavior_WaitForGroup.StopBehavior");
	}

	UGameCrowdBehavior_WaitForGroup_execStopBehavior_Params StopBehavior_Params;
	memset(&StopBehavior_Params, 0, sizeof(StopBehavior_Params));

	if (!uFnStopBehavior)
	{
		return;
	}

	this->ProcessEvent(uFnStopBehavior, &StopBehavior_Params, nullptr);
}

// Function GameFramework.GameCrowdBehavior_WaitForGroup.ShouldEndIdle
// [0x00020400] (FUNC_Native | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

bool UGameCrowdBehavior_WaitForGroup::ShouldEndIdle()
{
	static UFunction* uFnShouldEndIdle = nullptr;

	if (!uFnShouldEndIdle)
	{
		uFnShouldEndIdle = UFunction::FindFunction("Function GameFramework.GameCrowdBehavior_WaitForGroup.ShouldEndIdle");
	}

	UGameCrowdBehavior_WaitForGroup_execShouldEndIdle_Params ShouldEndIdle_Params;
	memset(&ShouldEndIdle_Params, 0, sizeof(ShouldEndIdle_Params));

	if (!uFnShouldEndIdle)
	{
		return ShouldEndIdle_Params.ReturnValue;
	}

	uint16_t nativeIndex = uFnShouldEndIdle->iNative;
	uFnShouldEndIdle->iNative = 0;
	this->ProcessEvent(uFnShouldEndIdle, &ShouldEndIdle_Params, nullptr);
	uFnShouldEndIdle->iNative = nativeIndex;

	return ShouldEndIdle_Params.ReturnValue;
}

// Function GameFramework.GameCrowdBehavior_WaitForGroup.GetBehaviorString
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class FString                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)

class FString UGameCrowdBehavior_WaitForGroup::GetBehaviorString()
{
	static UFunction* uFnGetBehaviorString = nullptr;

	if (!uFnGetBehaviorString)
	{
		uFnGetBehaviorString = UFunction::FindFunction("Function GameFramework.GameCrowdBehavior_WaitForGroup.GetBehaviorString");
	}

	UGameCrowdBehavior_WaitForGroup_execGetBehaviorString_Params GetBehaviorString_Params;
	memset(&GetBehaviorString_Params, 0, sizeof(GetBehaviorString_Params));

	if (!uFnGetBehaviorString)
	{
		return GetBehaviorString_Params.ReturnValue;
	}

	this->ProcessEvent(uFnGetBehaviorString, &GetBehaviorString_Params, nullptr);

	return GetBehaviorString_Params.ReturnValue;
}

// Function GameFramework.GameCrowdBehavior_WaitForGroup.InitBehavior
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class AGameCrowdAgent*         Agent                          (CPF_Parm)

void UGameCrowdBehavior_WaitForGroup::InitBehavior(class AGameCrowdAgent* Agent)
{
	static UFunction* uFnInitBehavior = nullptr;

	if (!uFnInitBehavior)
	{
		uFnInitBehavior = UFunction::FindFunction("Function GameFramework.GameCrowdBehavior_WaitForGroup.InitBehavior");
	}

	UGameCrowdBehavior_WaitForGroup_execInitBehavior_Params InitBehavior_Params;
	memset(&InitBehavior_Params, 0, sizeof(InitBehavior_Params));

	if (!uFnInitBehavior)
	{
		return;
	}
	InitBehavior_Params.Agent = Agent;

	this->ProcessEvent(uFnInitBehavior, &InitBehavior_Params, nullptr);
}

// Function GameFramework.GameCrowdBehavior_WaitInQueue.StopBehavior
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:

void UGameCrowdBehavior_WaitInQueue::StopBehavior()
{
	static UFunction* uFnStopBehavior = nullptr;

	if (!uFnStopBehavior)
	{
		uFnStopBehavior = UFunction::FindFunction("Function GameFramework.GameCrowdBehavior_WaitInQueue.StopBehavior");
	}

	UGameCrowdBehavior_WaitInQueue_execStopBehavior_Params StopBehavior_Params;
	memset(&StopBehavior_Params, 0, sizeof(StopBehavior_Params));

	if (!uFnStopBehavior)
	{
		return;
	}

	this->ProcessEvent(uFnStopBehavior, &StopBehavior_Params, nullptr);
}

// Function GameFramework.GameCrowdBehavior_WaitInQueue.ShouldEndIdle
// [0x00020400] (FUNC_Native | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

bool UGameCrowdBehavior_WaitInQueue::ShouldEndIdle()
{
	static UFunction* uFnShouldEndIdle = nullptr;

	if (!uFnShouldEndIdle)
	{
		uFnShouldEndIdle = UFunction::FindFunction("Function GameFramework.GameCrowdBehavior_WaitInQueue.ShouldEndIdle");
	}

	UGameCrowdBehavior_WaitInQueue_execShouldEndIdle_Params ShouldEndIdle_Params;
	memset(&ShouldEndIdle_Params, 0, sizeof(ShouldEndIdle_Params));

	if (!uFnShouldEndIdle)
	{
		return ShouldEndIdle_Params.ReturnValue;
	}

	uint16_t nativeIndex = uFnShouldEndIdle->iNative;
	uFnShouldEndIdle->iNative = 0;
	this->ProcessEvent(uFnShouldEndIdle, &ShouldEndIdle_Params, nullptr);
	uFnShouldEndIdle->iNative = nativeIndex;

	return ShouldEndIdle_Params.ReturnValue;
}

// Function GameFramework.GameCrowdBehavior_WaitInQueue.GetBehaviorString
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class FString                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)

class FString UGameCrowdBehavior_WaitInQueue::GetBehaviorString()
{
	static UFunction* uFnGetBehaviorString = nullptr;

	if (!uFnGetBehaviorString)
	{
		uFnGetBehaviorString = UFunction::FindFunction("Function GameFramework.GameCrowdBehavior_WaitInQueue.GetBehaviorString");
	}

	UGameCrowdBehavior_WaitInQueue_execGetBehaviorString_Params GetBehaviorString_Params;
	memset(&GetBehaviorString_Params, 0, sizeof(GetBehaviorString_Params));

	if (!uFnGetBehaviorString)
	{
		return GetBehaviorString_Params.ReturnValue;
	}

	this->ProcessEvent(uFnGetBehaviorString, &GetBehaviorString_Params, nullptr);

	return GetBehaviorString_Params.ReturnValue;
}

// Function GameFramework.GameCrowdBehavior_WaitInQueue.GetDestinationActor
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class AActor*                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

class AActor* UGameCrowdBehavior_WaitInQueue::GetDestinationActor()
{
	static UFunction* uFnGetDestinationActor = nullptr;

	if (!uFnGetDestinationActor)
	{
		uFnGetDestinationActor = UFunction::FindFunction("Function GameFramework.GameCrowdBehavior_WaitInQueue.GetDestinationActor");
	}

	UGameCrowdBehavior_WaitInQueue_execGetDestinationActor_Params GetDestinationActor_Params;
	memset(&GetDestinationActor_Params, 0, sizeof(GetDestinationActor_Params));

	if (!uFnGetDestinationActor)
	{
		return GetDestinationActor_Params.ReturnValue;
	}

	this->ProcessEvent(uFnGetDestinationActor, &GetDestinationActor_Params, nullptr);

	return GetDestinationActor_Params.ReturnValue;
}

// Function GameFramework.GameCrowdBehavior_WaitInQueue.ChangingDestination
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class AGameCrowdDestination*   NewDest                        (CPF_Parm)

void UGameCrowdBehavior_WaitInQueue::ChangingDestination(class AGameCrowdDestination* NewDest)
{
	static UFunction* uFnChangingDestination = nullptr;

	if (!uFnChangingDestination)
	{
		uFnChangingDestination = UFunction::FindFunction("Function GameFramework.GameCrowdBehavior_WaitInQueue.ChangingDestination");
	}

	UGameCrowdBehavior_WaitInQueue_execChangingDestination_Params ChangingDestination_Params;
	memset(&ChangingDestination_Params, 0, sizeof(ChangingDestination_Params));

	if (!uFnChangingDestination)
	{
		return;
	}
	ChangingDestination_Params.NewDest = NewDest;

	this->ProcessEvent(uFnChangingDestination, &ChangingDestination_Params, nullptr);
}

// Function GameFramework.GameCrowdBehavior_WaitInQueue.HandleMovement
// [0x00020400] (FUNC_Native | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

bool UGameCrowdBehavior_WaitInQueue::HandleMovement()
{
	static UFunction* uFnHandleMovement = nullptr;

	if (!uFnHandleMovement)
	{
		uFnHandleMovement = UFunction::FindFunction("Function GameFramework.GameCrowdBehavior_WaitInQueue.HandleMovement");
	}

	UGameCrowdBehavior_WaitInQueue_execHandleMovement_Params HandleMovement_Params;
	memset(&HandleMovement_Params, 0, sizeof(HandleMovement_Params));

	if (!uFnHandleMovement)
	{
		return HandleMovement_Params.ReturnValue;
	}

	uint16_t nativeIndex = uFnHandleMovement->iNative;
	uFnHandleMovement->iNative = 0;
	this->ProcessEvent(uFnHandleMovement, &HandleMovement_Params, nullptr);
	uFnHandleMovement->iNative = nativeIndex;

	return HandleMovement_Params.ReturnValue;
}

// Function GameFramework.GameCrowdGroup.UpdateDestinations
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class AGameCrowdDestination*   NewDestination                 (CPF_Parm)

void UGameCrowdGroup::UpdateDestinations(class AGameCrowdDestination* NewDestination)
{
	static UFunction* uFnUpdateDestinations = nullptr;

	if (!uFnUpdateDestinations)
	{
		uFnUpdateDestinations = UFunction::FindFunction("Function GameFramework.GameCrowdGroup.UpdateDestinations");
	}

	UGameCrowdGroup_execUpdateDestinations_Params UpdateDestinations_Params;
	memset(&UpdateDestinations_Params, 0, sizeof(UpdateDestinations_Params));

	if (!uFnUpdateDestinations)
	{
		return;
	}
	UpdateDestinations_Params.NewDestination = NewDestination;

	this->ProcessEvent(uFnUpdateDestinations, &UpdateDestinations_Params, nullptr);
}

// Function GameFramework.GameCrowdGroup.RemoveMember
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class AGameCrowdAgent*         Agent                          (CPF_Parm)

void UGameCrowdGroup::RemoveMember(class AGameCrowdAgent* Agent)
{
	static UFunction* uFnRemoveMember = nullptr;

	if (!uFnRemoveMember)
	{
		uFnRemoveMember = UFunction::FindFunction("Function GameFramework.GameCrowdGroup.RemoveMember");
	}

	UGameCrowdGroup_execRemoveMember_Params RemoveMember_Params;
	memset(&RemoveMember_Params, 0, sizeof(RemoveMember_Params));

	if (!uFnRemoveMember)
	{
		return;
	}
	RemoveMember_Params.Agent = Agent;

	this->ProcessEvent(uFnRemoveMember, &RemoveMember_Params, nullptr);
}

// Function GameFramework.GameCrowdGroup.AddMember
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class AGameCrowdAgent*         Agent                          (CPF_Parm)

void UGameCrowdGroup::AddMember(class AGameCrowdAgent* Agent)
{
	static UFunction* uFnAddMember = nullptr;

	if (!uFnAddMember)
	{
		uFnAddMember = UFunction::FindFunction("Function GameFramework.GameCrowdGroup.AddMember");
	}

	UGameCrowdGroup_execAddMember_Params AddMember_Params;
	memset(&AddMember_Params, 0, sizeof(AddMember_Params));

	if (!uFnAddMember)
	{
		return;
	}
	AddMember_Params.Agent = Agent;

	this->ProcessEvent(uFnAddMember, &AddMember_Params, nullptr);
}

// Function GameFramework.GameCrowdInteractionPoint.OnToggle
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class USeqAct_Toggle*          Action                         (CPF_Parm)

void AGameCrowdInteractionPoint::OnToggle(class USeqAct_Toggle* Action)
{
	static UFunction* uFnOnToggle = nullptr;

	if (!uFnOnToggle)
	{
		uFnOnToggle = UFunction::FindFunction("Function GameFramework.GameCrowdInteractionPoint.OnToggle");
	}

	AGameCrowdInteractionPoint_execOnToggle_Params OnToggle_Params;
	memset(&OnToggle_Params, 0, sizeof(OnToggle_Params));

	if (!uFnOnToggle)
	{
		return;
	}
	OnToggle_Params.Action = Action;

	this->ProcessEvent(uFnOnToggle, &OnToggle_Params, nullptr);
}

// Function GameFramework.GameCrowdDestination.GetSpawnPosition
// [0x00C20102] (FUNC_Defined | FUNC_Simulated | FUNC_Public | FUNC_HasOutParms | FUNC_HasDefaults)
// Parameter Info:
// class USeqAct_GameCrowdSpawner* Spawner                        (CPF_Parm)
// struct FVector                 SpawnPos                       (CPF_Parm | CPF_OutParm)
// struct FRotator                SpawnRot                       (CPF_Parm | CPF_OutParm)

void AGameCrowdDestination::GetSpawnPosition(class USeqAct_GameCrowdSpawner* Spawner, struct FVector& outSpawnPos, struct FRotator& outSpawnRot)
{
	static UFunction* uFnGetSpawnPosition = nullptr;

	if (!uFnGetSpawnPosition)
	{
		uFnGetSpawnPosition = UFunction::FindFunction("Function GameFramework.GameCrowdDestination.GetSpawnPosition");
	}

	AGameCrowdDestination_execGetSpawnPosition_Params GetSpawnPosition_Params;
	memset(&GetSpawnPosition_Params, 0, sizeof(GetSpawnPosition_Params));

	if (!uFnGetSpawnPosition)
	{
		return;
	}
	GetSpawnPosition_Params.Spawner = Spawner;
	memcpy_s(&GetSpawnPosition_Params.SpawnPos, sizeof(GetSpawnPosition_Params.SpawnPos), &outSpawnPos, sizeof(outSpawnPos));
	memcpy_s(&GetSpawnPosition_Params.SpawnRot, sizeof(GetSpawnPosition_Params.SpawnRot), &outSpawnRot, sizeof(outSpawnRot));

	this->ProcessEvent(uFnGetSpawnPosition, &GetSpawnPosition_Params, nullptr);

	memcpy_s(&outSpawnPos, sizeof(outSpawnPos), &GetSpawnPosition_Params.SpawnPos, sizeof(GetSpawnPosition_Params.SpawnPos));
	memcpy_s(&outSpawnRot, sizeof(outSpawnRot), &GetSpawnPosition_Params.SpawnRot, sizeof(GetSpawnPosition_Params.SpawnRot));
}

// Function GameFramework.GameCrowdDestination.AllowableDestinationFor
// [0x00020902] (FUNC_Defined | FUNC_Simulated | FUNC_Event | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class AGameCrowdAgent*         Agent                          (CPF_Parm)

bool AGameCrowdDestination::eventAllowableDestinationFor(class AGameCrowdAgent* Agent)
{
	static UFunction* uFnAllowableDestinationFor = nullptr;

	if (!uFnAllowableDestinationFor)
	{
		uFnAllowableDestinationFor = UFunction::FindFunction("Function GameFramework.GameCrowdDestination.AllowableDestinationFor");
	}

	AGameCrowdDestination_eventAllowableDestinationFor_Params AllowableDestinationFor_Params;
	memset(&AllowableDestinationFor_Params, 0, sizeof(AllowableDestinationFor_Params));

	if (!uFnAllowableDestinationFor)
	{
		return AllowableDestinationFor_Params.ReturnValue;
	}
	AllowableDestinationFor_Params.Agent = Agent;

	this->ProcessEvent(uFnAllowableDestinationFor, &AllowableDestinationFor_Params, nullptr);

	return AllowableDestinationFor_Params.ReturnValue;
}

// Function GameFramework.GameCrowdDestination.AtCapacity
// [0x00020102] (FUNC_Defined | FUNC_Simulated | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

bool AGameCrowdDestination::AtCapacity()
{
	static UFunction* uFnAtCapacity = nullptr;

	if (!uFnAtCapacity)
	{
		uFnAtCapacity = UFunction::FindFunction("Function GameFramework.GameCrowdDestination.AtCapacity");
	}

	AGameCrowdDestination_execAtCapacity_Params AtCapacity_Params;
	memset(&AtCapacity_Params, 0, sizeof(AtCapacity_Params));

	if (!uFnAtCapacity)
	{
		return AtCapacity_Params.ReturnValue;
	}

	this->ProcessEvent(uFnAtCapacity, &AtCapacity_Params, nullptr);

	return AtCapacity_Params.ReturnValue;
}

// Function GameFramework.GameCrowdDestination.IncrementCustomerCount
// [0x00020902] (FUNC_Defined | FUNC_Simulated | FUNC_Event | FUNC_Public)
// Parameter Info:
// class AGameCrowdAgent*         ArrivingAgent                  (CPF_Parm)

void AGameCrowdDestination::eventIncrementCustomerCount(class AGameCrowdAgent* ArrivingAgent)
{
	static UFunction* uFnIncrementCustomerCount = nullptr;

	if (!uFnIncrementCustomerCount)
	{
		uFnIncrementCustomerCount = UFunction::FindFunction("Function GameFramework.GameCrowdDestination.IncrementCustomerCount");
	}

	AGameCrowdDestination_eventIncrementCustomerCount_Params IncrementCustomerCount_Params;
	memset(&IncrementCustomerCount_Params, 0, sizeof(IncrementCustomerCount_Params));

	if (!uFnIncrementCustomerCount)
	{
		return;
	}
	IncrementCustomerCount_Params.ArrivingAgent = ArrivingAgent;

	this->ProcessEvent(uFnIncrementCustomerCount, &IncrementCustomerCount_Params, nullptr);
}

// Function GameFramework.GameCrowdDestination.DecrementCustomerCount
// [0x00020902] (FUNC_Defined | FUNC_Simulated | FUNC_Event | FUNC_Public)
// Parameter Info:
// class AGameCrowdAgent*         DepartingAgent                 (CPF_Parm)

void AGameCrowdDestination::eventDecrementCustomerCount(class AGameCrowdAgent* DepartingAgent)
{
	static UFunction* uFnDecrementCustomerCount = nullptr;

	if (!uFnDecrementCustomerCount)
	{
		uFnDecrementCustomerCount = UFunction::FindFunction("Function GameFramework.GameCrowdDestination.DecrementCustomerCount");
	}

	AGameCrowdDestination_eventDecrementCustomerCount_Params DecrementCustomerCount_Params;
	memset(&DecrementCustomerCount_Params, 0, sizeof(DecrementCustomerCount_Params));

	if (!uFnDecrementCustomerCount)
	{
		return;
	}
	DecrementCustomerCount_Params.DepartingAgent = DepartingAgent;

	this->ProcessEvent(uFnDecrementCustomerCount, &DecrementCustomerCount_Params, nullptr);
}

// Function GameFramework.GameCrowdDestination.PickNewDestinationFor
// [0x00020102] (FUNC_Defined | FUNC_Simulated | FUNC_Public)
// Parameter Info:
// class AGameCrowdAgent*         Agent                          (CPF_Parm)
// uint32_t                       bIgnoreRestrictions            (CPF_Parm)

void AGameCrowdDestination::PickNewDestinationFor(class AGameCrowdAgent* Agent, bool bIgnoreRestrictions)
{
	static UFunction* uFnPickNewDestinationFor = nullptr;

	if (!uFnPickNewDestinationFor)
	{
		uFnPickNewDestinationFor = UFunction::FindFunction("Function GameFramework.GameCrowdDestination.PickNewDestinationFor");
	}

	AGameCrowdDestination_execPickNewDestinationFor_Params PickNewDestinationFor_Params;
	memset(&PickNewDestinationFor_Params, 0, sizeof(PickNewDestinationFor_Params));

	if (!uFnPickNewDestinationFor)
	{
		return;
	}
	PickNewDestinationFor_Params.Agent = Agent;
	PickNewDestinationFor_Params.bIgnoreRestrictions = bIgnoreRestrictions;

	this->ProcessEvent(uFnPickNewDestinationFor, &PickNewDestinationFor_Params, nullptr);
}

// Function GameFramework.GameCrowdDestination.ReachedDestination
// [0x00020902] (FUNC_Defined | FUNC_Simulated | FUNC_Event | FUNC_Public)
// Parameter Info:
// class AGameCrowdAgent*         Agent                          (CPF_Parm)

void AGameCrowdDestination::eventReachedDestination(class AGameCrowdAgent* Agent)
{
	static UFunction* uFnReachedDestination = nullptr;

	if (!uFnReachedDestination)
	{
		uFnReachedDestination = UFunction::FindFunction("Function GameFramework.GameCrowdDestination.ReachedDestination");
	}

	AGameCrowdDestination_eventReachedDestination_Params ReachedDestination_Params;
	memset(&ReachedDestination_Params, 0, sizeof(ReachedDestination_Params));

	if (!uFnReachedDestination)
	{
		return;
	}
	ReachedDestination_Params.Agent = Agent;

	this->ProcessEvent(uFnReachedDestination, &ReachedDestination_Params, nullptr);
}

// Function GameFramework.GameCrowdDestination.Destroyed
// [0x00020102] (FUNC_Defined | FUNC_Simulated | FUNC_Public)
// Parameter Info:

void AGameCrowdDestination::Destroyed()
{
	static UFunction* uFnDestroyed = nullptr;

	if (!uFnDestroyed)
	{
		uFnDestroyed = UFunction::FindFunction("Function GameFramework.GameCrowdDestination.Destroyed");
	}

	AGameCrowdDestination_execDestroyed_Params Destroyed_Params;
	memset(&Destroyed_Params, 0, sizeof(Destroyed_Params));

	if (!uFnDestroyed)
	{
		return;
	}

	this->ProcessEvent(uFnDestroyed, &Destroyed_Params, nullptr);
}

// Function GameFramework.GameCrowdDestination.PostBeginPlay
// [0x00020102] (FUNC_Defined | FUNC_Simulated | FUNC_Public)
// Parameter Info:

void AGameCrowdDestination::PostBeginPlay()
{
	static UFunction* uFnPostBeginPlay = nullptr;

	if (!uFnPostBeginPlay)
	{
		uFnPostBeginPlay = UFunction::FindFunction("Function GameFramework.GameCrowdDestination.PostBeginPlay");
	}

	AGameCrowdDestination_execPostBeginPlay_Params PostBeginPlay_Params;
	memset(&PostBeginPlay_Params, 0, sizeof(PostBeginPlay_Params));

	if (!uFnPostBeginPlay)
	{
		return;
	}

	this->ProcessEvent(uFnPostBeginPlay, &PostBeginPlay_Params, nullptr);
}

// Function GameFramework.GameCrowdDestination.ReachedByAgent
// [0x00020500] (FUNC_Simulated | FUNC_Native | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class AGameCrowdAgent*         Agent                          (CPF_Parm)
// struct FVector                 TestPosition                   (CPF_Parm)
// uint32_t                       bTestExactly                   (CPF_Parm)

bool AGameCrowdDestination::ReachedByAgent(class AGameCrowdAgent* Agent, const struct FVector& TestPosition, bool bTestExactly)
{
	static UFunction* uFnReachedByAgent = nullptr;

	if (!uFnReachedByAgent)
	{
		uFnReachedByAgent = UFunction::FindFunction("Function GameFramework.GameCrowdDestination.ReachedByAgent");
	}

	AGameCrowdDestination_execReachedByAgent_Params ReachedByAgent_Params;
	memset(&ReachedByAgent_Params, 0, sizeof(ReachedByAgent_Params));

	if (!uFnReachedByAgent)
	{
		return ReachedByAgent_Params.ReturnValue;
	}
	ReachedByAgent_Params.Agent = Agent;
	memcpy_s(&ReachedByAgent_Params.TestPosition, sizeof(ReachedByAgent_Params.TestPosition), &TestPosition, sizeof(TestPosition));
	ReachedByAgent_Params.bTestExactly = bTestExactly;

	uint16_t nativeIndex = uFnReachedByAgent->iNative;
	uFnReachedByAgent->iNative = 0;
	this->ProcessEvent(uFnReachedByAgent, &ReachedByAgent_Params, nullptr);
	uFnReachedByAgent->iNative = nativeIndex;

	return ReachedByAgent_Params.ReturnValue;
}

// Function GameFramework.GameCrowdDestinationQueuePoint.HasCustomer
// [0x00020102] (FUNC_Defined | FUNC_Simulated | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

bool AGameCrowdDestinationQueuePoint::HasCustomer()
{
	static UFunction* uFnHasCustomer = nullptr;

	if (!uFnHasCustomer)
	{
		uFnHasCustomer = UFunction::FindFunction("Function GameFramework.GameCrowdDestinationQueuePoint.HasCustomer");
	}

	AGameCrowdDestinationQueuePoint_execHasCustomer_Params HasCustomer_Params;
	memset(&HasCustomer_Params, 0, sizeof(HasCustomer_Params));

	if (!uFnHasCustomer)
	{
		return HasCustomer_Params.ReturnValue;
	}

	this->ProcessEvent(uFnHasCustomer, &HasCustomer_Params, nullptr);

	return HasCustomer_Params.ReturnValue;
}

// Function GameFramework.GameCrowdDestinationQueuePoint.ClearQueue
// [0x00020102] (FUNC_Defined | FUNC_Simulated | FUNC_Public)
// Parameter Info:
// class AGameCrowdAgent*         OldCustomer                    (CPF_Parm)

void AGameCrowdDestinationQueuePoint::ClearQueue(class AGameCrowdAgent* OldCustomer)
{
	static UFunction* uFnClearQueue = nullptr;

	if (!uFnClearQueue)
	{
		uFnClearQueue = UFunction::FindFunction("Function GameFramework.GameCrowdDestinationQueuePoint.ClearQueue");
	}

	AGameCrowdDestinationQueuePoint_execClearQueue_Params ClearQueue_Params;
	memset(&ClearQueue_Params, 0, sizeof(ClearQueue_Params));

	if (!uFnClearQueue)
	{
		return;
	}
	ClearQueue_Params.OldCustomer = OldCustomer;

	this->ProcessEvent(uFnClearQueue, &ClearQueue_Params, nullptr);
}

// Function GameFramework.GameCrowdDestinationQueuePoint.AddCustomer
// [0x00020102] (FUNC_Defined | FUNC_Simulated | FUNC_Public)
// Parameter Info:
// class AGameCrowdAgent*         NewCustomer                    (CPF_Parm)
// class AGameCrowdInteractionPoint* PreviousPosition               (CPF_Parm)

void AGameCrowdDestinationQueuePoint::AddCustomer(class AGameCrowdAgent* NewCustomer, class AGameCrowdInteractionPoint* PreviousPosition)
{
	static UFunction* uFnAddCustomer = nullptr;

	if (!uFnAddCustomer)
	{
		uFnAddCustomer = UFunction::FindFunction("Function GameFramework.GameCrowdDestinationQueuePoint.AddCustomer");
	}

	AGameCrowdDestinationQueuePoint_execAddCustomer_Params AddCustomer_Params;
	memset(&AddCustomer_Params, 0, sizeof(AddCustomer_Params));

	if (!uFnAddCustomer)
	{
		return;
	}
	AddCustomer_Params.NewCustomer = NewCustomer;
	AddCustomer_Params.PreviousPosition = PreviousPosition;

	this->ProcessEvent(uFnAddCustomer, &AddCustomer_Params, nullptr);
}

// Function GameFramework.GameCrowdDestinationQueuePoint.ActuallyAdvance
// [0x00040103] (FUNC_Final | FUNC_Defined | FUNC_Simulated | FUNC_Private)
// Parameter Info:

void AGameCrowdDestinationQueuePoint::ActuallyAdvance()
{
	static UFunction* uFnActuallyAdvance = nullptr;

	if (!uFnActuallyAdvance)
	{
		uFnActuallyAdvance = UFunction::FindFunction("Function GameFramework.GameCrowdDestinationQueuePoint.ActuallyAdvance");
	}

	AGameCrowdDestinationQueuePoint_execActuallyAdvance_Params ActuallyAdvance_Params;
	memset(&ActuallyAdvance_Params, 0, sizeof(ActuallyAdvance_Params));

	if (!uFnActuallyAdvance)
	{
		return;
	}

	this->ProcessEvent(uFnActuallyAdvance, &ActuallyAdvance_Params, nullptr);
}

// Function GameFramework.GameCrowdDestinationQueuePoint.AdvanceCustomerTo
// [0x00020102] (FUNC_Defined | FUNC_Simulated | FUNC_Public)
// Parameter Info:
// class AGameCrowdInteractionPoint* FrontPosition                  (CPF_Parm)

void AGameCrowdDestinationQueuePoint::AdvanceCustomerTo(class AGameCrowdInteractionPoint* FrontPosition)
{
	static UFunction* uFnAdvanceCustomerTo = nullptr;

	if (!uFnAdvanceCustomerTo)
	{
		uFnAdvanceCustomerTo = UFunction::FindFunction("Function GameFramework.GameCrowdDestinationQueuePoint.AdvanceCustomerTo");
	}

	AGameCrowdDestinationQueuePoint_execAdvanceCustomerTo_Params AdvanceCustomerTo_Params;
	memset(&AdvanceCustomerTo_Params, 0, sizeof(AdvanceCustomerTo_Params));

	if (!uFnAdvanceCustomerTo)
	{
		return;
	}
	AdvanceCustomerTo_Params.FrontPosition = FrontPosition;

	this->ProcessEvent(uFnAdvanceCustomerTo, &AdvanceCustomerTo_Params, nullptr);
}

// Function GameFramework.GameCrowdDestinationQueuePoint.ReachedDestination
// [0x00020902] (FUNC_Defined | FUNC_Simulated | FUNC_Event | FUNC_Public)
// Parameter Info:
// class AGameCrowdAgent*         Agent                          (CPF_Parm)

void AGameCrowdDestinationQueuePoint::eventReachedDestination(class AGameCrowdAgent* Agent)
{
	static UFunction* uFnReachedDestination = nullptr;

	if (!uFnReachedDestination)
	{
		uFnReachedDestination = UFunction::FindFunction("Function GameFramework.GameCrowdDestinationQueuePoint.ReachedDestination");
	}

	AGameCrowdDestinationQueuePoint_eventReachedDestination_Params ReachedDestination_Params;
	memset(&ReachedDestination_Params, 0, sizeof(ReachedDestination_Params));

	if (!uFnReachedDestination)
	{
		return;
	}
	ReachedDestination_Params.Agent = Agent;

	this->ProcessEvent(uFnReachedDestination, &ReachedDestination_Params, nullptr);
}

// Function GameFramework.GameCrowdDestinationQueuePoint.HasSpace
// [0x00020102] (FUNC_Defined | FUNC_Simulated | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

bool AGameCrowdDestinationQueuePoint::HasSpace()
{
	static UFunction* uFnHasSpace = nullptr;

	if (!uFnHasSpace)
	{
		uFnHasSpace = UFunction::FindFunction("Function GameFramework.GameCrowdDestinationQueuePoint.HasSpace");
	}

	AGameCrowdDestinationQueuePoint_execHasSpace_Params HasSpace_Params;
	memset(&HasSpace_Params, 0, sizeof(HasSpace_Params));

	if (!uFnHasSpace)
	{
		return HasSpace_Params.ReturnValue;
	}

	this->ProcessEvent(uFnHasSpace, &HasSpace_Params, nullptr);

	return HasSpace_Params.ReturnValue;
}

// Function GameFramework.GameCrowdDestinationQueuePoint.QueueReachedBy
// [0x00020400] (FUNC_Native | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class AGameCrowdAgent*         Agent                          (CPF_Parm)
// struct FVector                 TestPosition                   (CPF_Parm)

bool AGameCrowdDestinationQueuePoint::QueueReachedBy(class AGameCrowdAgent* Agent, const struct FVector& TestPosition)
{
	static UFunction* uFnQueueReachedBy = nullptr;

	if (!uFnQueueReachedBy)
	{
		uFnQueueReachedBy = UFunction::FindFunction("Function GameFramework.GameCrowdDestinationQueuePoint.QueueReachedBy");
	}

	AGameCrowdDestinationQueuePoint_execQueueReachedBy_Params QueueReachedBy_Params;
	memset(&QueueReachedBy_Params, 0, sizeof(QueueReachedBy_Params));

	if (!uFnQueueReachedBy)
	{
		return QueueReachedBy_Params.ReturnValue;
	}
	QueueReachedBy_Params.Agent = Agent;
	memcpy_s(&QueueReachedBy_Params.TestPosition, sizeof(QueueReachedBy_Params.TestPosition), &TestPosition, sizeof(TestPosition));

	uint16_t nativeIndex = uFnQueueReachedBy->iNative;
	uFnQueueReachedBy->iNative = 0;
	this->ProcessEvent(uFnQueueReachedBy, &QueueReachedBy_Params, nullptr);
	uFnQueueReachedBy->iNative = nativeIndex;

	return QueueReachedBy_Params.ReturnValue;
}

// Function GameFramework.GameCrowdForcePoint.AppliedForce
// [0x00020800] (FUNC_Event | FUNC_Public)
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class AGameCrowdAgent*         Agent                          (CPF_Parm)

struct FVector AGameCrowdForcePoint::eventAppliedForce(class AGameCrowdAgent* Agent)
{
	static UFunction* uFnAppliedForce = nullptr;

	if (!uFnAppliedForce)
	{
		uFnAppliedForce = UFunction::FindFunction("Function GameFramework.GameCrowdForcePoint.AppliedForce");
	}

	AGameCrowdForcePoint_eventAppliedForce_Params AppliedForce_Params;
	memset(&AppliedForce_Params, 0, sizeof(AppliedForce_Params));

	if (!uFnAppliedForce)
	{
		return AppliedForce_Params.ReturnValue;
	}
	AppliedForce_Params.Agent = Agent;

	this->ProcessEvent(uFnAppliedForce, &AppliedForce_Params, nullptr);

	return AppliedForce_Params.ReturnValue;
}

// Function GameFramework.GameCrowdForcePoint.UnTouch
// [0x00020802] (FUNC_Defined | FUNC_Event | FUNC_Public)
// Parameter Info:
// class AActor*                  Other                          (CPF_Parm)

void AGameCrowdForcePoint::eventUnTouch(class AActor* Other)
{
	static UFunction* uFnUnTouch = nullptr;

	if (!uFnUnTouch)
	{
		uFnUnTouch = UFunction::FindFunction("Function GameFramework.GameCrowdForcePoint.UnTouch");
	}

	AGameCrowdForcePoint_eventUnTouch_Params UnTouch_Params;
	memset(&UnTouch_Params, 0, sizeof(UnTouch_Params));

	if (!uFnUnTouch)
	{
		return;
	}
	UnTouch_Params.Other = Other;

	this->ProcessEvent(uFnUnTouch, &UnTouch_Params, nullptr);
}

// Function GameFramework.GameCrowdForcePoint.Touch
// [0x00020802] (FUNC_Defined | FUNC_Event | FUNC_Public)
// Parameter Info:
// class AActor*                  Other                          (CPF_Parm)
// class UPrimitiveComponent*     OtherComp                      (CPF_Parm | CPF_EditInline)
// struct FVector                 HitLocation                    (CPF_Parm)
// struct FVector                 HitNormal                      (CPF_Parm)

void AGameCrowdForcePoint::eventTouch(class AActor* Other, class UPrimitiveComponent* OtherComp, const struct FVector& HitLocation, const struct FVector& HitNormal)
{
	static UFunction* uFnTouch = nullptr;

	if (!uFnTouch)
	{
		uFnTouch = UFunction::FindFunction("Function GameFramework.GameCrowdForcePoint.Touch");
	}

	AGameCrowdForcePoint_eventTouch_Params Touch_Params;
	memset(&Touch_Params, 0, sizeof(Touch_Params));

	if (!uFnTouch)
	{
		return;
	}
	Touch_Params.Other = Other;
	Touch_Params.OtherComp = OtherComp;
	memcpy_s(&Touch_Params.HitLocation, sizeof(Touch_Params.HitLocation), &HitLocation, sizeof(HitLocation));
	memcpy_s(&Touch_Params.HitNormal, sizeof(Touch_Params.HitNormal), &HitNormal, sizeof(HitNormal));

	this->ProcessEvent(uFnTouch, &Touch_Params, nullptr);
}

// Function GameFramework.GameCrowdAttractor.AppliedForce
// [0x00820802] (FUNC_Defined | FUNC_Event | FUNC_Public | FUNC_HasDefaults)
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class AGameCrowdAgent*         Agent                          (CPF_Parm)

struct FVector AGameCrowdAttractor::eventAppliedForce(class AGameCrowdAgent* Agent)
{
	static UFunction* uFnAppliedForce = nullptr;

	if (!uFnAppliedForce)
	{
		uFnAppliedForce = UFunction::FindFunction("Function GameFramework.GameCrowdAttractor.AppliedForce");
	}

	AGameCrowdAttractor_eventAppliedForce_Params AppliedForce_Params;
	memset(&AppliedForce_Params, 0, sizeof(AppliedForce_Params));

	if (!uFnAppliedForce)
	{
		return AppliedForce_Params.ReturnValue;
	}
	AppliedForce_Params.Agent = Agent;

	this->ProcessEvent(uFnAppliedForce, &AppliedForce_Params, nullptr);

	return AppliedForce_Params.ReturnValue;
}

// Function GameFramework.GameCrowdRepulsor.AppliedForce
// [0x00820802] (FUNC_Defined | FUNC_Event | FUNC_Public | FUNC_HasDefaults)
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class AGameCrowdAgent*         Agent                          (CPF_Parm)

struct FVector AGameCrowdRepulsor::eventAppliedForce(class AGameCrowdAgent* Agent)
{
	static UFunction* uFnAppliedForce = nullptr;

	if (!uFnAppliedForce)
	{
		uFnAppliedForce = UFunction::FindFunction("Function GameFramework.GameCrowdRepulsor.AppliedForce");
	}

	AGameCrowdRepulsor_eventAppliedForce_Params AppliedForce_Params;
	memset(&AppliedForce_Params, 0, sizeof(AppliedForce_Params));

	if (!uFnAppliedForce)
	{
		return AppliedForce_Params.ReturnValue;
	}
	AppliedForce_Params.Agent = Agent;

	this->ProcessEvent(uFnAppliedForce, &AppliedForce_Params, nullptr);

	return AppliedForce_Params.ReturnValue;
}

// Function GameFramework.GameCrowdPopulationManager.CreateNewAgent
// [0x00820002] (FUNC_Defined | FUNC_Public | FUNC_HasDefaults)
// Parameter Info:
// class AGameCrowdAgent*         ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class AGameCrowdDestination*   SpawnLoc                       (CPF_Parm)
// class AGameCrowdAgent*         AgentTemplate                  (CPF_Parm)
// class UGameCrowdGroup*         NewGroup                       (CPF_Parm)

class AGameCrowdAgent* AGameCrowdPopulationManager::CreateNewAgent(class AGameCrowdDestination* SpawnLoc, class AGameCrowdAgent* AgentTemplate, class UGameCrowdGroup* NewGroup)
{
	static UFunction* uFnCreateNewAgent = nullptr;

	if (!uFnCreateNewAgent)
	{
		uFnCreateNewAgent = UFunction::FindFunction("Function GameFramework.GameCrowdPopulationManager.CreateNewAgent");
	}

	AGameCrowdPopulationManager_execCreateNewAgent_Params CreateNewAgent_Params;
	memset(&CreateNewAgent_Params, 0, sizeof(CreateNewAgent_Params));

	if (!uFnCreateNewAgent)
	{
		return CreateNewAgent_Params.ReturnValue;
	}
	CreateNewAgent_Params.SpawnLoc = SpawnLoc;
	CreateNewAgent_Params.AgentTemplate = AgentTemplate;
	CreateNewAgent_Params.NewGroup = NewGroup;

	this->ProcessEvent(uFnCreateNewAgent, &CreateNewAgent_Params, nullptr);

	return CreateNewAgent_Params.ReturnValue;
}

// Function GameFramework.GameCrowdPopulationManager.SpawnAgent
// [0x00020802] (FUNC_Defined | FUNC_Event | FUNC_Public)
// Parameter Info:
// class AGameCrowdAgent*         ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class AGameCrowdDestination*   SpawnLoc                       (CPF_Parm)

class AGameCrowdAgent* AGameCrowdPopulationManager::eventSpawnAgent(class AGameCrowdDestination* SpawnLoc)
{
	static UFunction* uFnSpawnAgent = nullptr;

	if (!uFnSpawnAgent)
	{
		uFnSpawnAgent = UFunction::FindFunction("Function GameFramework.GameCrowdPopulationManager.SpawnAgent");
	}

	AGameCrowdPopulationManager_eventSpawnAgent_Params SpawnAgent_Params;
	memset(&SpawnAgent_Params, 0, sizeof(SpawnAgent_Params));

	if (!uFnSpawnAgent)
	{
		return SpawnAgent_Params.ReturnValue;
	}
	SpawnAgent_Params.SpawnLoc = SpawnLoc;

	this->ProcessEvent(uFnSpawnAgent, &SpawnAgent_Params, nullptr);

	return SpawnAgent_Params.ReturnValue;
}

// Function GameFramework.GameCrowdPopulationManager.ValidateSpawnAt
// [0x00820002] (FUNC_Defined | FUNC_Public | FUNC_HasDefaults)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class AGameCrowdDestination*   Candidate                      (CPF_Parm)

bool AGameCrowdPopulationManager::ValidateSpawnAt(class AGameCrowdDestination* Candidate)
{
	static UFunction* uFnValidateSpawnAt = nullptr;

	if (!uFnValidateSpawnAt)
	{
		uFnValidateSpawnAt = UFunction::FindFunction("Function GameFramework.GameCrowdPopulationManager.ValidateSpawnAt");
	}

	AGameCrowdPopulationManager_execValidateSpawnAt_Params ValidateSpawnAt_Params;
	memset(&ValidateSpawnAt_Params, 0, sizeof(ValidateSpawnAt_Params));

	if (!uFnValidateSpawnAt)
	{
		return ValidateSpawnAt_Params.ReturnValue;
	}
	ValidateSpawnAt_Params.Candidate = Candidate;

	this->ProcessEvent(uFnValidateSpawnAt, &ValidateSpawnAt_Params, nullptr);

	return ValidateSpawnAt_Params.ReturnValue;
}

// Function GameFramework.GameCrowdPopulationManager.AddPrioritizedSpawnPoint
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class AGameCrowdDestination*   GCD                            (CPF_Parm)
// struct FVector                 ViewLocation                   (CPF_Parm)

void AGameCrowdPopulationManager::AddPrioritizedSpawnPoint(class AGameCrowdDestination* GCD, const struct FVector& ViewLocation)
{
	static UFunction* uFnAddPrioritizedSpawnPoint = nullptr;

	if (!uFnAddPrioritizedSpawnPoint)
	{
		uFnAddPrioritizedSpawnPoint = UFunction::FindFunction("Function GameFramework.GameCrowdPopulationManager.AddPrioritizedSpawnPoint");
	}

	AGameCrowdPopulationManager_execAddPrioritizedSpawnPoint_Params AddPrioritizedSpawnPoint_Params;
	memset(&AddPrioritizedSpawnPoint_Params, 0, sizeof(AddPrioritizedSpawnPoint_Params));

	if (!uFnAddPrioritizedSpawnPoint)
	{
		return;
	}
	AddPrioritizedSpawnPoint_Params.GCD = GCD;
	memcpy_s(&AddPrioritizedSpawnPoint_Params.ViewLocation, sizeof(AddPrioritizedSpawnPoint_Params.ViewLocation), &ViewLocation, sizeof(ViewLocation));

	this->ProcessEvent(uFnAddPrioritizedSpawnPoint, &AddPrioritizedSpawnPoint_Params, nullptr);
}

// Function GameFramework.GameCrowdPopulationManager.AnalyzeSpawnPoints
// [0x00820002] (FUNC_Defined | FUNC_Public | FUNC_HasDefaults)
// Parameter Info:
// int32_t                        StartIndex                     (CPF_Parm)
// int32_t                        StopIndex                      (CPF_Parm)
// struct FVector                 ViewLocation                   (CPF_Parm)
// struct FVector                 PredictionLocation             (CPF_Parm)

void AGameCrowdPopulationManager::AnalyzeSpawnPoints(int32_t StartIndex, int32_t StopIndex, const struct FVector& ViewLocation, const struct FVector& PredictionLocation)
{
	static UFunction* uFnAnalyzeSpawnPoints = nullptr;

	if (!uFnAnalyzeSpawnPoints)
	{
		uFnAnalyzeSpawnPoints = UFunction::FindFunction("Function GameFramework.GameCrowdPopulationManager.AnalyzeSpawnPoints");
	}

	AGameCrowdPopulationManager_execAnalyzeSpawnPoints_Params AnalyzeSpawnPoints_Params;
	memset(&AnalyzeSpawnPoints_Params, 0, sizeof(AnalyzeSpawnPoints_Params));

	if (!uFnAnalyzeSpawnPoints)
	{
		return;
	}
	AnalyzeSpawnPoints_Params.StartIndex = StartIndex;
	AnalyzeSpawnPoints_Params.StopIndex = StopIndex;
	memcpy_s(&AnalyzeSpawnPoints_Params.ViewLocation, sizeof(AnalyzeSpawnPoints_Params.ViewLocation), &ViewLocation, sizeof(ViewLocation));
	memcpy_s(&AnalyzeSpawnPoints_Params.PredictionLocation, sizeof(AnalyzeSpawnPoints_Params.PredictionLocation), &PredictionLocation, sizeof(PredictionLocation));

	this->ProcessEvent(uFnAnalyzeSpawnPoints, &AnalyzeSpawnPoints_Params, nullptr);
}

// Function GameFramework.GameCrowdPopulationManager.PrioritizeSpawnPoints
// [0x00820002] (FUNC_Defined | FUNC_Public | FUNC_HasDefaults)
// Parameter Info:
// float                          DeltaSeconds                   (CPF_Parm)

void AGameCrowdPopulationManager::PrioritizeSpawnPoints(float DeltaSeconds)
{
	static UFunction* uFnPrioritizeSpawnPoints = nullptr;

	if (!uFnPrioritizeSpawnPoints)
	{
		uFnPrioritizeSpawnPoints = UFunction::FindFunction("Function GameFramework.GameCrowdPopulationManager.PrioritizeSpawnPoints");
	}

	AGameCrowdPopulationManager_execPrioritizeSpawnPoints_Params PrioritizeSpawnPoints_Params;
	memset(&PrioritizeSpawnPoints_Params, 0, sizeof(PrioritizeSpawnPoints_Params));

	if (!uFnPrioritizeSpawnPoints)
	{
		return;
	}
	PrioritizeSpawnPoints_Params.DeltaSeconds = DeltaSeconds;

	this->ProcessEvent(uFnPrioritizeSpawnPoints, &PrioritizeSpawnPoints_Params, nullptr);
}

// Function GameFramework.GameCrowdPopulationManager.PickSpawnPoint
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class AGameCrowdDestination*   ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

class AGameCrowdDestination* AGameCrowdPopulationManager::PickSpawnPoint()
{
	static UFunction* uFnPickSpawnPoint = nullptr;

	if (!uFnPickSpawnPoint)
	{
		uFnPickSpawnPoint = UFunction::FindFunction("Function GameFramework.GameCrowdPopulationManager.PickSpawnPoint");
	}

	AGameCrowdPopulationManager_execPickSpawnPoint_Params PickSpawnPoint_Params;
	memset(&PickSpawnPoint_Params, 0, sizeof(PickSpawnPoint_Params));

	if (!uFnPickSpawnPoint)
	{
		return PickSpawnPoint_Params.ReturnValue;
	}

	this->ProcessEvent(uFnPickSpawnPoint, &PickSpawnPoint_Params, nullptr);

	return PickSpawnPoint_Params.ReturnValue;
}

// Function GameFramework.GameCrowdPopulationManager.Tick
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// float                          DeltaSeconds                   (CPF_Parm)

void AGameCrowdPopulationManager::Tick(float DeltaSeconds)
{
	static UFunction* uFnTick = nullptr;

	if (!uFnTick)
	{
		uFnTick = UFunction::FindFunction("Function GameFramework.GameCrowdPopulationManager.Tick");
	}

	AGameCrowdPopulationManager_execTick_Params Tick_Params;
	memset(&Tick_Params, 0, sizeof(Tick_Params));

	if (!uFnTick)
	{
		return;
	}
	Tick_Params.DeltaSeconds = DeltaSeconds;

	this->ProcessEvent(uFnTick, &Tick_Params, nullptr);
}

// Function GameFramework.GameCrowdPopulationManager.DisplayDebug
// [0x00C20102] (FUNC_Defined | FUNC_Simulated | FUNC_Public | FUNC_HasOutParms | FUNC_HasDefaults)
// Parameter Info:
// class AHUD*                    HUD                            (CPF_Parm)
// float                          out_YL                         (CPF_Parm | CPF_OutParm)
// float                          out_YPos                       (CPF_Parm | CPF_OutParm)

void AGameCrowdPopulationManager::DisplayDebug(class AHUD* HUD, float& outOut_YL, float& outOut_YPos)
{
	static UFunction* uFnDisplayDebug = nullptr;

	if (!uFnDisplayDebug)
	{
		uFnDisplayDebug = UFunction::FindFunction("Function GameFramework.GameCrowdPopulationManager.DisplayDebug");
	}

	AGameCrowdPopulationManager_execDisplayDebug_Params DisplayDebug_Params;
	memset(&DisplayDebug_Params, 0, sizeof(DisplayDebug_Params));

	if (!uFnDisplayDebug)
	{
		return;
	}
	DisplayDebug_Params.HUD = HUD;
	DisplayDebug_Params.out_YL = outOut_YL;
	DisplayDebug_Params.out_YPos = outOut_YPos;

	this->ProcessEvent(uFnDisplayDebug, &DisplayDebug_Params, nullptr);

	outOut_YL = DisplayDebug_Params.out_YL;
	outOut_YPos = DisplayDebug_Params.out_YPos;
}

// Function GameFramework.GameCrowdPopulationManager.AddToAgentPool
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class AGameCrowdAgent*         Agent                          (CPF_Parm)

bool AGameCrowdPopulationManager::AddToAgentPool(class AGameCrowdAgent* Agent)
{
	static UFunction* uFnAddToAgentPool = nullptr;

	if (!uFnAddToAgentPool)
	{
		uFnAddToAgentPool = UFunction::FindFunction("Function GameFramework.GameCrowdPopulationManager.AddToAgentPool");
	}

	AGameCrowdPopulationManager_execAddToAgentPool_Params AddToAgentPool_Params;
	memset(&AddToAgentPool_Params, 0, sizeof(AddToAgentPool_Params));

	if (!uFnAddToAgentPool)
	{
		return AddToAgentPool_Params.ReturnValue;
	}
	AddToAgentPool_Params.Agent = Agent;

	this->ProcessEvent(uFnAddToAgentPool, &AddToAgentPool_Params, nullptr);

	return AddToAgentPool_Params.ReturnValue;
}

// Function GameFramework.GameCrowdPopulationManager.AgentDestroyed
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class AGameCrowdAgent*         Agent                          (CPF_Parm)

void AGameCrowdPopulationManager::AgentDestroyed(class AGameCrowdAgent* Agent)
{
	static UFunction* uFnAgentDestroyed = nullptr;

	if (!uFnAgentDestroyed)
	{
		uFnAgentDestroyed = UFunction::FindFunction("Function GameFramework.GameCrowdPopulationManager.AgentDestroyed");
	}

	AGameCrowdPopulationManager_execAgentDestroyed_Params AgentDestroyed_Params;
	memset(&AgentDestroyed_Params, 0, sizeof(AgentDestroyed_Params));

	if (!uFnAgentDestroyed)
	{
		return;
	}
	AgentDestroyed_Params.Agent = Agent;

	this->ProcessEvent(uFnAgentDestroyed, &AgentDestroyed_Params, nullptr);
}

// Function GameFramework.GameCrowdPopulationManager.OnGameCrowdPopulationManagerToggle
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class USeqAct_GameCrowdPopulationManagerToggle* inAction                       (CPF_Parm)

void AGameCrowdPopulationManager::OnGameCrowdPopulationManagerToggle(class USeqAct_GameCrowdPopulationManagerToggle* inAction)
{
	static UFunction* uFnOnGameCrowdPopulationManagerToggle = nullptr;

	if (!uFnOnGameCrowdPopulationManagerToggle)
	{
		uFnOnGameCrowdPopulationManagerToggle = UFunction::FindFunction("Function GameFramework.GameCrowdPopulationManager.OnGameCrowdPopulationManagerToggle");
	}

	AGameCrowdPopulationManager_execOnGameCrowdPopulationManagerToggle_Params OnGameCrowdPopulationManagerToggle_Params;
	memset(&OnGameCrowdPopulationManagerToggle_Params, 0, sizeof(OnGameCrowdPopulationManagerToggle_Params));

	if (!uFnOnGameCrowdPopulationManagerToggle)
	{
		return;
	}
	OnGameCrowdPopulationManagerToggle_Params.inAction = inAction;

	this->ProcessEvent(uFnOnGameCrowdPopulationManagerToggle, &OnGameCrowdPopulationManagerToggle_Params, nullptr);
}

// Function GameFramework.GameCrowdPopulationManager.RemoveSpawnPoint
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class AGameCrowdDestination*   GCD                            (CPF_Parm)

void AGameCrowdPopulationManager::RemoveSpawnPoint(class AGameCrowdDestination* GCD)
{
	static UFunction* uFnRemoveSpawnPoint = nullptr;

	if (!uFnRemoveSpawnPoint)
	{
		uFnRemoveSpawnPoint = UFunction::FindFunction("Function GameFramework.GameCrowdPopulationManager.RemoveSpawnPoint");
	}

	AGameCrowdPopulationManager_execRemoveSpawnPoint_Params RemoveSpawnPoint_Params;
	memset(&RemoveSpawnPoint_Params, 0, sizeof(RemoveSpawnPoint_Params));

	if (!uFnRemoveSpawnPoint)
	{
		return;
	}
	RemoveSpawnPoint_Params.GCD = GCD;

	this->ProcessEvent(uFnRemoveSpawnPoint, &RemoveSpawnPoint_Params, nullptr);
}

// Function GameFramework.GameCrowdPopulationManager.AddSpawnPoint
// [0x00820002] (FUNC_Defined | FUNC_Public | FUNC_HasDefaults)
// Parameter Info:
// class AGameCrowdDestination*   GCD                            (CPF_Parm)

void AGameCrowdPopulationManager::AddSpawnPoint(class AGameCrowdDestination* GCD)
{
	static UFunction* uFnAddSpawnPoint = nullptr;

	if (!uFnAddSpawnPoint)
	{
		uFnAddSpawnPoint = UFunction::FindFunction("Function GameFramework.GameCrowdPopulationManager.AddSpawnPoint");
	}

	AGameCrowdPopulationManager_execAddSpawnPoint_Params AddSpawnPoint_Params;
	memset(&AddSpawnPoint_Params, 0, sizeof(AddSpawnPoint_Params));

	if (!uFnAddSpawnPoint)
	{
		return;
	}
	AddSpawnPoint_Params.GCD = GCD;

	this->ProcessEvent(uFnAddSpawnPoint, &AddSpawnPoint_Params, nullptr);
}

// Function GameFramework.GameCrowdPopulationManager.GetMaxSpawnDist
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

float AGameCrowdPopulationManager::GetMaxSpawnDist()
{
	static UFunction* uFnGetMaxSpawnDist = nullptr;

	if (!uFnGetMaxSpawnDist)
	{
		uFnGetMaxSpawnDist = UFunction::FindFunction("Function GameFramework.GameCrowdPopulationManager.GetMaxSpawnDist");
	}

	AGameCrowdPopulationManager_execGetMaxSpawnDist_Params GetMaxSpawnDist_Params;
	memset(&GetMaxSpawnDist_Params, 0, sizeof(GetMaxSpawnDist_Params));

	if (!uFnGetMaxSpawnDist)
	{
		return GetMaxSpawnDist_Params.ReturnValue;
	}

	this->ProcessEvent(uFnGetMaxSpawnDist, &GetMaxSpawnDist_Params, nullptr);

	return GetMaxSpawnDist_Params.ReturnValue;
}

// Function GameFramework.GameCrowdPopulationManager.NotifyPathChanged
// [0x00020800] (FUNC_Event | FUNC_Public)
// Parameter Info:

void AGameCrowdPopulationManager::eventNotifyPathChanged()
{
	static UFunction* uFnNotifyPathChanged = nullptr;

	if (!uFnNotifyPathChanged)
	{
		uFnNotifyPathChanged = UFunction::FindFunction("Function GameFramework.GameCrowdPopulationManager.NotifyPathChanged");
	}

	AGameCrowdPopulationManager_eventNotifyPathChanged_Params NotifyPathChanged_Params;
	memset(&NotifyPathChanged_Params, 0, sizeof(NotifyPathChanged_Params));

	if (!uFnNotifyPathChanged)
	{
		return;
	}

	this->ProcessEvent(uFnNotifyPathChanged, &NotifyPathChanged_Params, nullptr);
}

// Function GameFramework.GameCrowdPopulationManager.PostBeginPlay
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:

void AGameCrowdPopulationManager::PostBeginPlay()
{
	static UFunction* uFnPostBeginPlay = nullptr;

	if (!uFnPostBeginPlay)
	{
		uFnPostBeginPlay = UFunction::FindFunction("Function GameFramework.GameCrowdPopulationManager.PostBeginPlay");
	}

	AGameCrowdPopulationManager_execPostBeginPlay_Params PostBeginPlay_Params;
	memset(&PostBeginPlay_Params, 0, sizeof(PostBeginPlay_Params));

	if (!uFnPostBeginPlay)
	{
		return;
	}

	this->ProcessEvent(uFnPostBeginPlay, &PostBeginPlay_Params, nullptr);
}

// Function GameFramework.GameCrowdReplicationActor.ReplicatedEvent
// [0x00020902] (FUNC_Defined | FUNC_Simulated | FUNC_Event | FUNC_Public)
// Parameter Info:
// class FName                    VarName                        (CPF_Parm)

void AGameCrowdReplicationActor::eventReplicatedEvent(const class FName& VarName)
{
	static UFunction* uFnReplicatedEvent = nullptr;

	if (!uFnReplicatedEvent)
	{
		uFnReplicatedEvent = UFunction::FindFunction("Function GameFramework.GameCrowdReplicationActor.ReplicatedEvent");
	}

	AGameCrowdReplicationActor_eventReplicatedEvent_Params ReplicatedEvent_Params;
	memset(&ReplicatedEvent_Params, 0, sizeof(ReplicatedEvent_Params));

	if (!uFnReplicatedEvent)
	{
		return;
	}
	memcpy_s(&ReplicatedEvent_Params.VarName, sizeof(ReplicatedEvent_Params.VarName), &VarName, sizeof(VarName));

	this->ProcessEvent(uFnReplicatedEvent, &ReplicatedEvent_Params, nullptr);
}

// Function GameFramework.GameDamageType.HandleDamageFX
// [0x00422000] (FUNC_Static | FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// class AGamePawn*               DamagedPawn                    (CPF_Parm)
// struct FTakeHitInfo            HitInfo                        (CPF_Const | CPF_Parm | CPF_OutParm)

void UGameDamageType::HandleDamageFX(class AGamePawn* DamagedPawn, struct FTakeHitInfo& outHitInfo)
{
	static UFunction* uFnHandleDamageFX = nullptr;

	if (!uFnHandleDamageFX)
	{
		uFnHandleDamageFX = UFunction::FindFunction("Function GameFramework.GameDamageType.HandleDamageFX");
	}

	UGameDamageType_execHandleDamageFX_Params HandleDamageFX_Params;
	memset(&HandleDamageFX_Params, 0, sizeof(HandleDamageFX_Params));

	if (!uFnHandleDamageFX)
	{
		return;
	}
	HandleDamageFX_Params.DamagedPawn = DamagedPawn;
	memcpy_s(&HandleDamageFX_Params.HitInfo, sizeof(HandleDamageFX_Params.HitInfo), &outHitInfo, sizeof(outHitInfo));

	UGameDamageType::StaticClass()->ClassDefaultObject->ProcessEvent(uFnHandleDamageFX, &HandleDamageFX_Params, nullptr);

	memcpy_s(&outHitInfo, sizeof(outHitInfo), &HandleDamageFX_Params.HitInfo, sizeof(HandleDamageFX_Params.HitInfo));
}

// Function GameFramework.GameDamageType.ShouldHeadShotGib
// [0x00022002] (FUNC_Defined | FUNC_Static | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class APawn*                   TestPawn                       (CPF_Parm)
// class APawn*                   Instigator                     (CPF_Parm)

bool UGameDamageType::ShouldHeadShotGib(class APawn* TestPawn, class APawn* Instigator)
{
	static UFunction* uFnShouldHeadShotGib = nullptr;

	if (!uFnShouldHeadShotGib)
	{
		uFnShouldHeadShotGib = UFunction::FindFunction("Function GameFramework.GameDamageType.ShouldHeadShotGib");
	}

	UGameDamageType_execShouldHeadShotGib_Params ShouldHeadShotGib_Params;
	memset(&ShouldHeadShotGib_Params, 0, sizeof(ShouldHeadShotGib_Params));

	if (!uFnShouldHeadShotGib)
	{
		return ShouldHeadShotGib_Params.ReturnValue;
	}
	ShouldHeadShotGib_Params.TestPawn = TestPawn;
	ShouldHeadShotGib_Params.Instigator = Instigator;

	UGameDamageType::StaticClass()->ClassDefaultObject->ProcessEvent(uFnShouldHeadShotGib, &ShouldHeadShotGib_Params, nullptr);

	return ShouldHeadShotGib_Params.ReturnValue;
}

// Function GameFramework.GameDamageType.PlayExtraDamageSound
// [0x00022002] (FUNC_Defined | FUNC_Static | FUNC_Public)
// Parameter Info:
// class APawn*                   VictimPawn                     (CPF_Parm)

void UGameDamageType::PlayExtraDamageSound(class APawn* VictimPawn)
{
	static UFunction* uFnPlayExtraDamageSound = nullptr;

	if (!uFnPlayExtraDamageSound)
	{
		uFnPlayExtraDamageSound = UFunction::FindFunction("Function GameFramework.GameDamageType.PlayExtraDamageSound");
	}

	UGameDamageType_execPlayExtraDamageSound_Params PlayExtraDamageSound_Params;
	memset(&PlayExtraDamageSound_Params, 0, sizeof(PlayExtraDamageSound_Params));

	if (!uFnPlayExtraDamageSound)
	{
		return;
	}
	PlayExtraDamageSound_Params.VictimPawn = VictimPawn;

	UGameDamageType::StaticClass()->ClassDefaultObject->ProcessEvent(uFnPlayExtraDamageSound, &PlayExtraDamageSound_Params, nullptr);
}

// Function GameFramework.GameDamageType.IsScriptedDamageType
// [0x00022002] (FUNC_Defined | FUNC_Static | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

bool UGameDamageType::IsScriptedDamageType()
{
	static UFunction* uFnIsScriptedDamageType = nullptr;

	if (!uFnIsScriptedDamageType)
	{
		uFnIsScriptedDamageType = UFunction::FindFunction("Function GameFramework.GameDamageType.IsScriptedDamageType");
	}

	UGameDamageType_execIsScriptedDamageType_Params IsScriptedDamageType_Params;
	memset(&IsScriptedDamageType_Params, 0, sizeof(IsScriptedDamageType_Params));

	if (!uFnIsScriptedDamageType)
	{
		return IsScriptedDamageType_Params.ReturnValue;
	}

	UGameDamageType::StaticClass()->ClassDefaultObject->ProcessEvent(uFnIsScriptedDamageType, &IsScriptedDamageType_Params, nullptr);

	return IsScriptedDamageType_Params.ReturnValue;
}

// Function GameFramework.GameDamageType.ShouldPlayForceFeedback
// [0x00022002] (FUNC_Defined | FUNC_Static | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class APawn*                   DamagedPawn                    (CPF_Parm)

bool UGameDamageType::ShouldPlayForceFeedback(class APawn* DamagedPawn)
{
	static UFunction* uFnShouldPlayForceFeedback = nullptr;

	if (!uFnShouldPlayForceFeedback)
	{
		uFnShouldPlayForceFeedback = UFunction::FindFunction("Function GameFramework.GameDamageType.ShouldPlayForceFeedback");
	}

	UGameDamageType_execShouldPlayForceFeedback_Params ShouldPlayForceFeedback_Params;
	memset(&ShouldPlayForceFeedback_Params, 0, sizeof(ShouldPlayForceFeedback_Params));

	if (!uFnShouldPlayForceFeedback)
	{
		return ShouldPlayForceFeedback_Params.ReturnValue;
	}
	ShouldPlayForceFeedback_Params.DamagedPawn = DamagedPawn;

	UGameDamageType::StaticClass()->ClassDefaultObject->ProcessEvent(uFnShouldPlayForceFeedback, &ShouldPlayForceFeedback_Params, nullptr);

	return ShouldPlayForceFeedback_Params.ReturnValue;
}

// Function GameFramework.GameDamageType.HandleDeadPlayer
// [0x00022000] (FUNC_Static | FUNC_Public)
// Parameter Info:
// class AGamePlayerController*   Player                         (CPF_Parm)

void UGameDamageType::HandleDeadPlayer(class AGamePlayerController* Player)
{
	static UFunction* uFnHandleDeadPlayer = nullptr;

	if (!uFnHandleDeadPlayer)
	{
		uFnHandleDeadPlayer = UFunction::FindFunction("Function GameFramework.GameDamageType.HandleDeadPlayer");
	}

	UGameDamageType_execHandleDeadPlayer_Params HandleDeadPlayer_Params;
	memset(&HandleDeadPlayer_Params, 0, sizeof(HandleDeadPlayer_Params));

	if (!uFnHandleDeadPlayer)
	{
		return;
	}
	HandleDeadPlayer_Params.Player = Player;

	UGameDamageType::StaticClass()->ClassDefaultObject->ProcessEvent(uFnHandleDeadPlayer, &HandleDeadPlayer_Params, nullptr);
}

// Function GameFramework.GameDamageType.HandleKilledPawn
// [0x00022000] (FUNC_Static | FUNC_Public)
// Parameter Info:
// class APawn*                   KilledPawn                     (CPF_Parm)
// class APawn*                   Instigator                     (CPF_Parm)

void UGameDamageType::HandleKilledPawn(class APawn* KilledPawn, class APawn* Instigator)
{
	static UFunction* uFnHandleKilledPawn = nullptr;

	if (!uFnHandleKilledPawn)
	{
		uFnHandleKilledPawn = UFunction::FindFunction("Function GameFramework.GameDamageType.HandleKilledPawn");
	}

	UGameDamageType_execHandleKilledPawn_Params HandleKilledPawn_Params;
	memset(&HandleKilledPawn_Params, 0, sizeof(HandleKilledPawn_Params));

	if (!uFnHandleKilledPawn)
	{
		return;
	}
	HandleKilledPawn_Params.KilledPawn = KilledPawn;
	HandleKilledPawn_Params.Instigator = Instigator;

	UGameDamageType::StaticClass()->ClassDefaultObject->ProcessEvent(uFnHandleKilledPawn, &HandleKilledPawn_Params, nullptr);
}

// Function GameFramework.GameDamageType.HandleDamagedPawn
// [0x00022000] (FUNC_Static | FUNC_Public)
// Parameter Info:
// class APawn*                   DamagedPawn                    (CPF_Parm)
// class APawn*                   Instigator                     (CPF_Parm)
// int32_t                        DamageAmt                      (CPF_Parm)
// struct FVector                 Momentum                       (CPF_Parm)

void UGameDamageType::HandleDamagedPawn(class APawn* DamagedPawn, class APawn* Instigator, int32_t DamageAmt, const struct FVector& Momentum)
{
	static UFunction* uFnHandleDamagedPawn = nullptr;

	if (!uFnHandleDamagedPawn)
	{
		uFnHandleDamagedPawn = UFunction::FindFunction("Function GameFramework.GameDamageType.HandleDamagedPawn");
	}

	UGameDamageType_execHandleDamagedPawn_Params HandleDamagedPawn_Params;
	memset(&HandleDamagedPawn_Params, 0, sizeof(HandleDamagedPawn_Params));

	if (!uFnHandleDamagedPawn)
	{
		return;
	}
	HandleDamagedPawn_Params.DamagedPawn = DamagedPawn;
	HandleDamagedPawn_Params.Instigator = Instigator;
	HandleDamagedPawn_Params.DamageAmt = DamageAmt;
	memcpy_s(&HandleDamagedPawn_Params.Momentum, sizeof(HandleDamagedPawn_Params.Momentum), &Momentum, sizeof(Momentum));

	UGameDamageType::StaticClass()->ClassDefaultObject->ProcessEvent(uFnHandleDamagedPawn, &HandleDamagedPawn_Params, nullptr);
}

// Function GameFramework.GameDamageType.ModifyDamage
// [0x00422000] (FUNC_Static | FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// class APawn*                   Victim                         (CPF_Parm)
// class AController*             InstigatedBy                   (CPF_Parm)
// struct FVector                 HitLocation                    (CPF_Parm)
// struct FTraceHitInfo           HitInfo                        (CPF_Parm)
// int32_t                        out_Damage                     (CPF_Parm | CPF_OutParm)
// struct FVector                 out_Momentum                   (CPF_Parm | CPF_OutParm)

void UGameDamageType::ModifyDamage(class APawn* Victim, class AController* InstigatedBy, const struct FVector& HitLocation, const struct FTraceHitInfo& HitInfo, int32_t& outOut_Damage, struct FVector& outOut_Momentum)
{
	static UFunction* uFnModifyDamage = nullptr;

	if (!uFnModifyDamage)
	{
		uFnModifyDamage = UFunction::FindFunction("Function GameFramework.GameDamageType.ModifyDamage");
	}

	UGameDamageType_execModifyDamage_Params ModifyDamage_Params;
	memset(&ModifyDamage_Params, 0, sizeof(ModifyDamage_Params));

	if (!uFnModifyDamage)
	{
		return;
	}
	ModifyDamage_Params.Victim = Victim;
	ModifyDamage_Params.InstigatedBy = InstigatedBy;
	memcpy_s(&ModifyDamage_Params.HitLocation, sizeof(ModifyDamage_Params.HitLocation), &HitLocation, sizeof(HitLocation));
	memcpy_s(&ModifyDamage_Params.HitInfo, sizeof(ModifyDamage_Params.HitInfo), &HitInfo, sizeof(HitInfo));
	ModifyDamage_Params.out_Damage = outOut_Damage;
	memcpy_s(&ModifyDamage_Params.out_Momentum, sizeof(ModifyDamage_Params.out_Momentum), &outOut_Momentum, sizeof(outOut_Momentum));

	UGameDamageType::StaticClass()->ClassDefaultObject->ProcessEvent(uFnModifyDamage, &ModifyDamage_Params, nullptr);

	outOut_Damage = ModifyDamage_Params.out_Damage;
	memcpy_s(&outOut_Momentum, sizeof(outOut_Momentum), &ModifyDamage_Params.out_Momentum, sizeof(ModifyDamage_Params.out_Momentum));
}

// Function GameFramework.GameDamageType.ShouldGib
// [0x00022002] (FUNC_Defined | FUNC_Static | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class APawn*                   TestPawn                       (CPF_Parm)
// class APawn*                   Instigator                     (CPF_Parm)

bool UGameDamageType::ShouldGib(class APawn* TestPawn, class APawn* Instigator)
{
	static UFunction* uFnShouldGib = nullptr;

	if (!uFnShouldGib)
	{
		uFnShouldGib = UFunction::FindFunction("Function GameFramework.GameDamageType.ShouldGib");
	}

	UGameDamageType_execShouldGib_Params ShouldGib_Params;
	memset(&ShouldGib_Params, 0, sizeof(ShouldGib_Params));

	if (!uFnShouldGib)
	{
		return ShouldGib_Params.ReturnValue;
	}
	ShouldGib_Params.TestPawn = TestPawn;
	ShouldGib_Params.Instigator = Instigator;

	UGameDamageType::StaticClass()->ClassDefaultObject->ProcessEvent(uFnShouldGib, &ShouldGib_Params, nullptr);

	return ShouldGib_Params.ReturnValue;
}

// Function GameFramework.GameExplosionActor.ChooseCameraShake
// [0x00880102] (FUNC_Defined | FUNC_Simulated | FUNC_Protected | FUNC_HasDefaults)
// Parameter Info:
// class UCameraShake*            ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 Epicenter                      (CPF_Parm)
// class APlayerController*       PC                             (CPF_Parm)

class UCameraShake* AGameExplosionActor::ChooseCameraShake(const struct FVector& Epicenter, class APlayerController* PC)
{
	static UFunction* uFnChooseCameraShake = nullptr;

	if (!uFnChooseCameraShake)
	{
		uFnChooseCameraShake = UFunction::FindFunction("Function GameFramework.GameExplosionActor.ChooseCameraShake");
	}

	AGameExplosionActor_execChooseCameraShake_Params ChooseCameraShake_Params;
	memset(&ChooseCameraShake_Params, 0, sizeof(ChooseCameraShake_Params));

	if (!uFnChooseCameraShake)
	{
		return ChooseCameraShake_Params.ReturnValue;
	}
	memcpy_s(&ChooseCameraShake_Params.Epicenter, sizeof(ChooseCameraShake_Params.Epicenter), &Epicenter, sizeof(Epicenter));
	ChooseCameraShake_Params.PC = PC;

	this->ProcessEvent(uFnChooseCameraShake, &ChooseCameraShake_Params, nullptr);

	return ChooseCameraShake_Params.ReturnValue;
}

// Function GameFramework.GameExplosionActor.SpawnCameraLensEffects
// [0x00020102] (FUNC_Defined | FUNC_Simulated | FUNC_Public)
// Parameter Info:

void AGameExplosionActor::SpawnCameraLensEffects()
{
	static UFunction* uFnSpawnCameraLensEffects = nullptr;

	if (!uFnSpawnCameraLensEffects)
	{
		uFnSpawnCameraLensEffects = UFunction::FindFunction("Function GameFramework.GameExplosionActor.SpawnCameraLensEffects");
	}

	AGameExplosionActor_execSpawnCameraLensEffects_Params SpawnCameraLensEffects_Params;
	memset(&SpawnCameraLensEffects_Params, 0, sizeof(SpawnCameraLensEffects_Params));

	if (!uFnSpawnCameraLensEffects)
	{
		return;
	}

	this->ProcessEvent(uFnSpawnCameraLensEffects, &SpawnCameraLensEffects_Params, nullptr);
}

// Function GameFramework.GameExplosionActor.DoExplosionCameraEffects
// [0x00020102] (FUNC_Defined | FUNC_Simulated | FUNC_Public)
// Parameter Info:

void AGameExplosionActor::DoExplosionCameraEffects()
{
	static UFunction* uFnDoExplosionCameraEffects = nullptr;

	if (!uFnDoExplosionCameraEffects)
	{
		uFnDoExplosionCameraEffects = UFunction::FindFunction("Function GameFramework.GameExplosionActor.DoExplosionCameraEffects");
	}

	AGameExplosionActor_execDoExplosionCameraEffects_Params DoExplosionCameraEffects_Params;
	memset(&DoExplosionCameraEffects_Params, 0, sizeof(DoExplosionCameraEffects_Params));

	if (!uFnDoExplosionCameraEffects)
	{
		return;
	}

	this->ProcessEvent(uFnDoExplosionCameraEffects, &DoExplosionCameraEffects_Params, nullptr);
}

// Function GameFramework.GameExplosionActor.Tick
// [0x00020102] (FUNC_Defined | FUNC_Simulated | FUNC_Public)
// Parameter Info:
// float                          DeltaTime                      (CPF_Parm)

void AGameExplosionActor::Tick(float DeltaTime)
{
	static UFunction* uFnTick = nullptr;

	if (!uFnTick)
	{
		uFnTick = UFunction::FindFunction("Function GameFramework.GameExplosionActor.Tick");
	}

	AGameExplosionActor_execTick_Params Tick_Params;
	memset(&Tick_Params, 0, sizeof(Tick_Params));

	if (!uFnTick)
	{
		return;
	}
	Tick_Params.DeltaTime = DeltaTime;

	this->ProcessEvent(uFnTick, &Tick_Params, nullptr);
}

// Function GameFramework.GameExplosionActor.DoExplosionDamage
// [0x00020102] (FUNC_Defined | FUNC_Simulated | FUNC_Public)
// Parameter Info:

void AGameExplosionActor::DoExplosionDamage()
{
	static UFunction* uFnDoExplosionDamage = nullptr;

	if (!uFnDoExplosionDamage)
	{
		uFnDoExplosionDamage = UFunction::FindFunction("Function GameFramework.GameExplosionActor.DoExplosionDamage");
	}

	AGameExplosionActor_execDoExplosionDamage_Params DoExplosionDamage_Params;
	memset(&DoExplosionDamage_Params, 0, sizeof(DoExplosionDamage_Params));

	if (!uFnDoExplosionDamage)
	{
		return;
	}

	this->ProcessEvent(uFnDoExplosionDamage, &DoExplosionDamage_Params, nullptr);
}

// Function GameFramework.GameExplosionActor.DrawDebug
// [0x00820102] (FUNC_Defined | FUNC_Simulated | FUNC_Public | FUNC_HasDefaults)
// Parameter Info:

void AGameExplosionActor::DrawDebug()
{
	static UFunction* uFnDrawDebug = nullptr;

	if (!uFnDrawDebug)
	{
		uFnDrawDebug = UFunction::FindFunction("Function GameFramework.GameExplosionActor.DrawDebug");
	}

	AGameExplosionActor_execDrawDebug_Params DrawDebug_Params;
	memset(&DrawDebug_Params, 0, sizeof(DrawDebug_Params));

	if (!uFnDrawDebug)
	{
		return;
	}

	this->ProcessEvent(uFnDrawDebug, &DrawDebug_Params, nullptr);
}

// Function GameFramework.GameExplosionActor.Explode
// [0x00024102] (FUNC_Defined | FUNC_Simulated | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// class UGameExplosion*          NewExplosionTemplate           (CPF_Parm)
// struct FVector                 Direction                      (CPF_OptionalParm | CPF_Parm)

void AGameExplosionActor::Explode(class UGameExplosion* NewExplosionTemplate, const struct FVector& optionalDirection)
{
	static UFunction* uFnExplode = nullptr;

	if (!uFnExplode)
	{
		uFnExplode = UFunction::FindFunction("Function GameFramework.GameExplosionActor.Explode");
	}

	AGameExplosionActor_execExplode_Params Explode_Params;
	memset(&Explode_Params, 0, sizeof(Explode_Params));

	if (!uFnExplode)
	{
		return;
	}
	Explode_Params.NewExplosionTemplate = NewExplosionTemplate;
	memcpy_s(&Explode_Params.Direction, sizeof(Explode_Params.Direction), &optionalDirection, sizeof(optionalDirection));

	this->ProcessEvent(uFnExplode, &Explode_Params, nullptr);
}

// Function GameFramework.GameExplosionActor.SpawnExplosionFogVolume
// [0x00020100] (FUNC_Simulated | FUNC_Public)
// Parameter Info:

void AGameExplosionActor::SpawnExplosionFogVolume()
{
	static UFunction* uFnSpawnExplosionFogVolume = nullptr;

	if (!uFnSpawnExplosionFogVolume)
	{
		uFnSpawnExplosionFogVolume = UFunction::FindFunction("Function GameFramework.GameExplosionActor.SpawnExplosionFogVolume");
	}

	AGameExplosionActor_execSpawnExplosionFogVolume_Params SpawnExplosionFogVolume_Params;
	memset(&SpawnExplosionFogVolume_Params, 0, sizeof(SpawnExplosionFogVolume_Params));

	if (!uFnSpawnExplosionFogVolume)
	{
		return;
	}

	this->ProcessEvent(uFnSpawnExplosionFogVolume, &SpawnExplosionFogVolume_Params, nullptr);
}

// Function GameFramework.GameExplosionActor.SpawnExplosionDecal
// [0x00020100] (FUNC_Simulated | FUNC_Public)
// Parameter Info:

void AGameExplosionActor::SpawnExplosionDecal()
{
	static UFunction* uFnSpawnExplosionDecal = nullptr;

	if (!uFnSpawnExplosionDecal)
	{
		uFnSpawnExplosionDecal = UFunction::FindFunction("Function GameFramework.GameExplosionActor.SpawnExplosionDecal");
	}

	AGameExplosionActor_execSpawnExplosionDecal_Params SpawnExplosionDecal_Params;
	memset(&SpawnExplosionDecal_Params, 0, sizeof(SpawnExplosionDecal_Params));

	if (!uFnSpawnExplosionDecal)
	{
		return;
	}

	this->ProcessEvent(uFnSpawnExplosionDecal, &SpawnExplosionDecal_Params, nullptr);
}

// Function GameFramework.GameExplosionActor.SpawnExplosionParticleSystem
// [0x00020100] (FUNC_Simulated | FUNC_Public)
// Parameter Info:
// class UParticleSystem*         Template                       (CPF_Parm)

void AGameExplosionActor::SpawnExplosionParticleSystem(class UParticleSystem* Template)
{
	static UFunction* uFnSpawnExplosionParticleSystem = nullptr;

	if (!uFnSpawnExplosionParticleSystem)
	{
		uFnSpawnExplosionParticleSystem = UFunction::FindFunction("Function GameFramework.GameExplosionActor.SpawnExplosionParticleSystem");
	}

	AGameExplosionActor_execSpawnExplosionParticleSystem_Params SpawnExplosionParticleSystem_Params;
	memset(&SpawnExplosionParticleSystem_Params, 0, sizeof(SpawnExplosionParticleSystem_Params));

	if (!uFnSpawnExplosionParticleSystem)
	{
		return;
	}
	SpawnExplosionParticleSystem_Params.Template = Template;

	this->ProcessEvent(uFnSpawnExplosionParticleSystem, &SpawnExplosionParticleSystem_Params, nullptr);
}

// Function GameFramework.GameExplosionActor.UpdateExplosionTemplateWithPerMaterialFX
// [0x00080100] (FUNC_Simulated | FUNC_Protected)
// Parameter Info:
// class UPhysicalMaterial*       PhysMaterial                   (CPF_Parm)

void AGameExplosionActor::UpdateExplosionTemplateWithPerMaterialFX(class UPhysicalMaterial* PhysMaterial)
{
	static UFunction* uFnUpdateExplosionTemplateWithPerMaterialFX = nullptr;

	if (!uFnUpdateExplosionTemplateWithPerMaterialFX)
	{
		uFnUpdateExplosionTemplateWithPerMaterialFX = UFunction::FindFunction("Function GameFramework.GameExplosionActor.UpdateExplosionTemplateWithPerMaterialFX");
	}

	AGameExplosionActor_execUpdateExplosionTemplateWithPerMaterialFX_Params UpdateExplosionTemplateWithPerMaterialFX_Params;
	memset(&UpdateExplosionTemplateWithPerMaterialFX_Params, 0, sizeof(UpdateExplosionTemplateWithPerMaterialFX_Params));

	if (!uFnUpdateExplosionTemplateWithPerMaterialFX)
	{
		return;
	}
	UpdateExplosionTemplateWithPerMaterialFX_Params.PhysMaterial = PhysMaterial;

	this->ProcessEvent(uFnUpdateExplosionTemplateWithPerMaterialFX, &UpdateExplosionTemplateWithPerMaterialFX_Params, nullptr);
}

// Function GameFramework.GameExplosionActor.KnockdownPawn
// [0x00080002] (FUNC_Defined | FUNC_Protected)
// Parameter Info:
// class AGamePawn*               Victim                         (CPF_Parm)
// float                          DistFromExplosion              (CPF_Parm)

void AGameExplosionActor::KnockdownPawn(class AGamePawn* Victim, float DistFromExplosion)
{
	static UFunction* uFnKnockdownPawn = nullptr;

	if (!uFnKnockdownPawn)
	{
		uFnKnockdownPawn = UFunction::FindFunction("Function GameFramework.GameExplosionActor.KnockdownPawn");
	}

	AGameExplosionActor_execKnockdownPawn_Params KnockdownPawn_Params;
	memset(&KnockdownPawn_Params, 0, sizeof(KnockdownPawn_Params));

	if (!uFnKnockdownPawn)
	{
		return;
	}
	KnockdownPawn_Params.Victim = Victim;
	KnockdownPawn_Params.DistFromExplosion = DistFromExplosion;

	this->ProcessEvent(uFnKnockdownPawn, &KnockdownPawn_Params, nullptr);
}

// Function GameFramework.GameExplosionActor.CringePawn
// [0x00080002] (FUNC_Defined | FUNC_Protected)
// Parameter Info:
// class AGamePawn*               Victim                         (CPF_Parm)
// float                          DistFromExplosion              (CPF_Parm)

void AGameExplosionActor::CringePawn(class AGamePawn* Victim, float DistFromExplosion)
{
	static UFunction* uFnCringePawn = nullptr;

	if (!uFnCringePawn)
	{
		uFnCringePawn = UFunction::FindFunction("Function GameFramework.GameExplosionActor.CringePawn");
	}

	AGameExplosionActor_execCringePawn_Params CringePawn_Params;
	memset(&CringePawn_Params, 0, sizeof(CringePawn_Params));

	if (!uFnCringePawn)
	{
		return;
	}
	CringePawn_Params.Victim = Victim;
	CringePawn_Params.DistFromExplosion = DistFromExplosion;

	this->ProcessEvent(uFnCringePawn, &CringePawn_Params, nullptr);
}

// Function GameFramework.GameExplosionActor.DoCringesAndKnockdowns
// [0x00880002] (FUNC_Defined | FUNC_Protected | FUNC_HasDefaults)
// Parameter Info:

void AGameExplosionActor::DoCringesAndKnockdowns()
{
	static UFunction* uFnDoCringesAndKnockdowns = nullptr;

	if (!uFnDoCringesAndKnockdowns)
	{
		uFnDoCringesAndKnockdowns = UFunction::FindFunction("Function GameFramework.GameExplosionActor.DoCringesAndKnockdowns");
	}

	AGameExplosionActor_execDoCringesAndKnockdowns_Params DoCringesAndKnockdowns_Params;
	memset(&DoCringesAndKnockdowns_Params, 0, sizeof(DoCringesAndKnockdowns_Params));

	if (!uFnDoCringesAndKnockdowns)
	{
		return;
	}

	this->ProcessEvent(uFnDoCringesAndKnockdowns, &DoCringesAndKnockdowns_Params, nullptr);
}

// Function GameFramework.GameExplosionActor.ShouldDoCringeFor
// [0x00080002] (FUNC_Defined | FUNC_Protected)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class AGamePawn*               Victim                         (CPF_Parm)

bool AGameExplosionActor::ShouldDoCringeFor(class AGamePawn* Victim)
{
	static UFunction* uFnShouldDoCringeFor = nullptr;

	if (!uFnShouldDoCringeFor)
	{
		uFnShouldDoCringeFor = UFunction::FindFunction("Function GameFramework.GameExplosionActor.ShouldDoCringeFor");
	}

	AGameExplosionActor_execShouldDoCringeFor_Params ShouldDoCringeFor_Params;
	memset(&ShouldDoCringeFor_Params, 0, sizeof(ShouldDoCringeFor_Params));

	if (!uFnShouldDoCringeFor)
	{
		return ShouldDoCringeFor_Params.ReturnValue;
	}
	ShouldDoCringeFor_Params.Victim = Victim;

	this->ProcessEvent(uFnShouldDoCringeFor, &ShouldDoCringeFor_Params, nullptr);

	return ShouldDoCringeFor_Params.ReturnValue;
}

// Function GameFramework.GameExplosionActor.DoBreakFracturedMeshes
// [0x00080102] (FUNC_Defined | FUNC_Simulated | FUNC_Protected)
// Parameter Info:
// struct FVector                 ExploOrigin                    (CPF_Parm)
// float                          DamageRadius                   (CPF_Parm)
// float                          RBStrength                     (CPF_Parm)
// class UClass*                  dmgType                        (CPF_Parm)

void AGameExplosionActor::DoBreakFracturedMeshes(const struct FVector& ExploOrigin, float DamageRadius, float RBStrength, class UClass* dmgType)
{
	static UFunction* uFnDoBreakFracturedMeshes = nullptr;

	if (!uFnDoBreakFracturedMeshes)
	{
		uFnDoBreakFracturedMeshes = UFunction::FindFunction("Function GameFramework.GameExplosionActor.DoBreakFracturedMeshes");
	}

	AGameExplosionActor_execDoBreakFracturedMeshes_Params DoBreakFracturedMeshes_Params;
	memset(&DoBreakFracturedMeshes_Params, 0, sizeof(DoBreakFracturedMeshes_Params));

	if (!uFnDoBreakFracturedMeshes)
	{
		return;
	}
	memcpy_s(&DoBreakFracturedMeshes_Params.ExploOrigin, sizeof(DoBreakFracturedMeshes_Params.ExploOrigin), &ExploOrigin, sizeof(ExploOrigin));
	DoBreakFracturedMeshes_Params.DamageRadius = DamageRadius;
	DoBreakFracturedMeshes_Params.RBStrength = RBStrength;
	DoBreakFracturedMeshes_Params.dmgType = dmgType;

	this->ProcessEvent(uFnDoBreakFracturedMeshes, &DoBreakFracturedMeshes_Params, nullptr);
}

// Function GameFramework.GameExplosionActor.HurtExplosion
// [0x00880102] (FUNC_Defined | FUNC_Simulated | FUNC_Protected | FUNC_HasDefaults)
// Parameter Info:
// float                          BaseDamage                     (CPF_Parm)
// float                          DamageRadius                   (CPF_Parm)
// float                          DamageFalloffExp               (CPF_Parm)
// class UClass*                  DamageType                     (CPF_Parm)
// float                          MomentumScale                  (CPF_Parm)
// struct FVector                 ExploOrigin                    (CPF_Parm)
// class AActor*                  IgnoredActor                   (CPF_Parm)
// class UClass*                  ActorClassToIgnoreForDamage    (CPF_Parm)
// class AController*             InstigatedByController         (CPF_Parm)
// uint32_t                       bDoFullDamage                  (CPF_Parm)

void AGameExplosionActor::HurtExplosion(float BaseDamage, float DamageRadius, float DamageFalloffExp, class UClass* DamageType, float MomentumScale, const struct FVector& ExploOrigin, class AActor* IgnoredActor, class UClass* ActorClassToIgnoreForDamage, class AController* InstigatedByController, bool bDoFullDamage)
{
	static UFunction* uFnHurtExplosion = nullptr;

	if (!uFnHurtExplosion)
	{
		uFnHurtExplosion = UFunction::FindFunction("Function GameFramework.GameExplosionActor.HurtExplosion");
	}

	AGameExplosionActor_execHurtExplosion_Params HurtExplosion_Params;
	memset(&HurtExplosion_Params, 0, sizeof(HurtExplosion_Params));

	if (!uFnHurtExplosion)
	{
		return;
	}
	HurtExplosion_Params.BaseDamage = BaseDamage;
	HurtExplosion_Params.DamageRadius = DamageRadius;
	HurtExplosion_Params.DamageFalloffExp = DamageFalloffExp;
	HurtExplosion_Params.DamageType = DamageType;
	HurtExplosion_Params.MomentumScale = MomentumScale;
	memcpy_s(&HurtExplosion_Params.ExploOrigin, sizeof(HurtExplosion_Params.ExploOrigin), &ExploOrigin, sizeof(ExploOrigin));
	HurtExplosion_Params.IgnoredActor = IgnoredActor;
	HurtExplosion_Params.ActorClassToIgnoreForDamage = ActorClassToIgnoreForDamage;
	HurtExplosion_Params.InstigatedByController = InstigatedByController;
	HurtExplosion_Params.bDoFullDamage = bDoFullDamage;

	this->ProcessEvent(uFnHurtExplosion, &HurtExplosion_Params, nullptr);
}

// Function GameFramework.GameExplosionActor.IsBehindExplosion
// [0x00080102] (FUNC_Defined | FUNC_Simulated | FUNC_Protected)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class AActor*                  A                              (CPF_Parm)

bool AGameExplosionActor::IsBehindExplosion(class AActor* A)
{
	static UFunction* uFnIsBehindExplosion = nullptr;

	if (!uFnIsBehindExplosion)
	{
		uFnIsBehindExplosion = UFunction::FindFunction("Function GameFramework.GameExplosionActor.IsBehindExplosion");
	}

	AGameExplosionActor_execIsBehindExplosion_Params IsBehindExplosion_Params;
	memset(&IsBehindExplosion_Params, 0, sizeof(IsBehindExplosion_Params));

	if (!uFnIsBehindExplosion)
	{
		return IsBehindExplosion_Params.ReturnValue;
	}
	IsBehindExplosion_Params.A = A;

	this->ProcessEvent(uFnIsBehindExplosion, &IsBehindExplosion_Params, nullptr);

	return IsBehindExplosion_Params.ReturnValue;
}

// Function GameFramework.GameExplosionActor.DoFullDamageToActor
// [0x00020102] (FUNC_Defined | FUNC_Simulated | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class AActor*                  Victim                         (CPF_Parm)

bool AGameExplosionActor::DoFullDamageToActor(class AActor* Victim)
{
	static UFunction* uFnDoFullDamageToActor = nullptr;

	if (!uFnDoFullDamageToActor)
	{
		uFnDoFullDamageToActor = UFunction::FindFunction("Function GameFramework.GameExplosionActor.DoFullDamageToActor");
	}

	AGameExplosionActor_execDoFullDamageToActor_Params DoFullDamageToActor_Params;
	memset(&DoFullDamageToActor_Params, 0, sizeof(DoFullDamageToActor_Params));

	if (!uFnDoFullDamageToActor)
	{
		return DoFullDamageToActor_Params.ReturnValue;
	}
	DoFullDamageToActor_Params.Victim = Victim;

	this->ProcessEvent(uFnDoFullDamageToActor, &DoFullDamageToActor_Params, nullptr);

	return DoFullDamageToActor_Params.ReturnValue;
}

// Function GameFramework.GameExplosionActor.GetPhysicalMaterial
// [0x00880102] (FUNC_Defined | FUNC_Simulated | FUNC_Protected | FUNC_HasDefaults)
// Parameter Info:
// class UPhysicalMaterial*       ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

class UPhysicalMaterial* AGameExplosionActor::GetPhysicalMaterial()
{
	static UFunction* uFnGetPhysicalMaterial = nullptr;

	if (!uFnGetPhysicalMaterial)
	{
		uFnGetPhysicalMaterial = UFunction::FindFunction("Function GameFramework.GameExplosionActor.GetPhysicalMaterial");
	}

	AGameExplosionActor_execGetPhysicalMaterial_Params GetPhysicalMaterial_Params;
	memset(&GetPhysicalMaterial_Params, 0, sizeof(GetPhysicalMaterial_Params));

	if (!uFnGetPhysicalMaterial)
	{
		return GetPhysicalMaterial_Params.ReturnValue;
	}

	this->ProcessEvent(uFnGetPhysicalMaterial, &GetPhysicalMaterial_Params, nullptr);

	return GetPhysicalMaterial_Params.ReturnValue;
}

// Function GameFramework.GameExplosionActor.PreBeginPlay
// [0x00020802] (FUNC_Defined | FUNC_Event | FUNC_Public)
// Parameter Info:

void AGameExplosionActor::eventPreBeginPlay()
{
	static UFunction* uFnPreBeginPlay = nullptr;

	if (!uFnPreBeginPlay)
	{
		uFnPreBeginPlay = UFunction::FindFunction("Function GameFramework.GameExplosionActor.PreBeginPlay");
	}

	AGameExplosionActor_eventPreBeginPlay_Params PreBeginPlay_Params;
	memset(&PreBeginPlay_Params, 0, sizeof(PreBeginPlay_Params));

	if (!uFnPreBeginPlay)
	{
		return;
	}

	this->ProcessEvent(uFnPreBeginPlay, &PreBeginPlay_Params, nullptr);
}

// Function GameFramework.MobileHUD.ResetMobileInputConfig
// [0x00020202] (FUNC_Defined | FUNC_Exec | FUNC_Public)
// Parameter Info:

void AMobileHUD::ResetMobileInputConfig()
{
	static UFunction* uFnResetMobileInputConfig = nullptr;

	if (!uFnResetMobileInputConfig)
	{
		uFnResetMobileInputConfig = UFunction::FindFunction("Function GameFramework.MobileHUD.ResetMobileInputConfig");
	}

	AMobileHUD_execResetMobileInputConfig_Params ResetMobileInputConfig_Params;
	memset(&ResetMobileInputConfig_Params, 0, sizeof(ResetMobileInputConfig_Params));

	if (!uFnResetMobileInputConfig)
	{
		return;
	}

	this->ProcessEvent(uFnResetMobileInputConfig, &ResetMobileInputConfig_Params, nullptr);
}

// Function GameFramework.MobileHUD.NextMobileInputConfig
// [0x00020202] (FUNC_Defined | FUNC_Exec | FUNC_Public)
// Parameter Info:

void AMobileHUD::NextMobileInputConfig()
{
	static UFunction* uFnNextMobileInputConfig = nullptr;

	if (!uFnNextMobileInputConfig)
	{
		uFnNextMobileInputConfig = UFunction::FindFunction("Function GameFramework.MobileHUD.NextMobileInputConfig");
	}

	AMobileHUD_execNextMobileInputConfig_Params NextMobileInputConfig_Params;
	memset(&NextMobileInputConfig_Params, 0, sizeof(NextMobileInputConfig_Params));

	if (!uFnNextMobileInputConfig)
	{
		return;
	}

	this->ProcessEvent(uFnNextMobileInputConfig, &NextMobileInputConfig_Params, nullptr);
}

// Function GameFramework.MobileHUD.DrawInputOverlays
// [0x00820002] (FUNC_Defined | FUNC_Public | FUNC_HasDefaults)
// Parameter Info:

void AMobileHUD::DrawInputOverlays()
{
	static UFunction* uFnDrawInputOverlays = nullptr;

	if (!uFnDrawInputOverlays)
	{
		uFnDrawInputOverlays = UFunction::FindFunction("Function GameFramework.MobileHUD.DrawInputOverlays");
	}

	AMobileHUD_execDrawInputOverlays_Params DrawInputOverlays_Params;
	memset(&DrawInputOverlays_Params, 0, sizeof(DrawInputOverlays_Params));

	if (!uFnDrawInputOverlays)
	{
		return;
	}

	this->ProcessEvent(uFnDrawInputOverlays, &DrawInputOverlays_Params, nullptr);
}

// Function GameFramework.MobileHUD.PostRender
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:

void AMobileHUD::PostRender()
{
	static UFunction* uFnPostRender = nullptr;

	if (!uFnPostRender)
	{
		uFnPostRender = UFunction::FindFunction("Function GameFramework.MobileHUD.PostRender");
	}

	AMobileHUD_execPostRender_Params PostRender_Params;
	memset(&PostRender_Params, 0, sizeof(PostRender_Params));

	if (!uFnPostRender)
	{
		return;
	}

	this->ProcessEvent(uFnPostRender, &PostRender_Params, nullptr);
}

// Function GameFramework.MobileHUD.PostBeginPlay
// [0x00020102] (FUNC_Defined | FUNC_Simulated | FUNC_Public)
// Parameter Info:

void AMobileHUD::PostBeginPlay()
{
	static UFunction* uFnPostBeginPlay = nullptr;

	if (!uFnPostBeginPlay)
	{
		uFnPostBeginPlay = UFunction::FindFunction("Function GameFramework.MobileHUD.PostBeginPlay");
	}

	AMobileHUD_execPostBeginPlay_Params PostBeginPlay_Params;
	memset(&PostBeginPlay_Params, 0, sizeof(PostBeginPlay_Params));

	if (!uFnPostBeginPlay)
	{
		return;
	}

	this->ProcessEvent(uFnPostBeginPlay, &PostBeginPlay_Params, nullptr);
}

// Function GameFramework.GamePawn.SphinxNotifyDestory
// [0x00020800] (FUNC_Event | FUNC_Public)
// Parameter Info:

void AGamePawn::eventSphinxNotifyDestory()
{
	static UFunction* uFnSphinxNotifyDestory = nullptr;

	if (!uFnSphinxNotifyDestory)
	{
		uFnSphinxNotifyDestory = UFunction::FindFunction("Function GameFramework.GamePawn.SphinxNotifyDestory");
	}

	AGamePawn_eventSphinxNotifyDestory_Params SphinxNotifyDestory_Params;
	memset(&SphinxNotifyDestory_Params, 0, sizeof(SphinxNotifyDestory_Params));

	if (!uFnSphinxNotifyDestory)
	{
		return;
	}

	this->ProcessEvent(uFnSphinxNotifyDestory, &SphinxNotifyDestory_Params, nullptr);
}

// Function GameFramework.GamePawn.PlayCustomParticleOnSocket
// [0x00820802] (FUNC_Defined | FUNC_Event | FUNC_Public | FUNC_HasDefaults)
// Parameter Info:
// class UParticleSystem*         PS                             (CPF_Parm)
// class FName                    Socket                         (CPF_Parm)

void AGamePawn::eventPlayCustomParticleOnSocket(class UParticleSystem* PS, const class FName& Socket)
{
	static UFunction* uFnPlayCustomParticleOnSocket = nullptr;

	if (!uFnPlayCustomParticleOnSocket)
	{
		uFnPlayCustomParticleOnSocket = UFunction::FindFunction("Function GameFramework.GamePawn.PlayCustomParticleOnSocket");
	}

	AGamePawn_eventPlayCustomParticleOnSocket_Params PlayCustomParticleOnSocket_Params;
	memset(&PlayCustomParticleOnSocket_Params, 0, sizeof(PlayCustomParticleOnSocket_Params));

	if (!uFnPlayCustomParticleOnSocket)
	{
		return;
	}
	PlayCustomParticleOnSocket_Params.PS = PS;
	memcpy_s(&PlayCustomParticleOnSocket_Params.Socket, sizeof(PlayCustomParticleOnSocket_Params.Socket), &Socket, sizeof(Socket));

	this->ProcessEvent(uFnPlayCustomParticleOnSocket, &PlayCustomParticleOnSocket_Params, nullptr);
}

// Function GameFramework.GamePawn.ReattachMeshWithoutBeingSeen
// [0x00020102] (FUNC_Defined | FUNC_Simulated | FUNC_Public)
// Parameter Info:

void AGamePawn::ReattachMeshWithoutBeingSeen()
{
	static UFunction* uFnReattachMeshWithoutBeingSeen = nullptr;

	if (!uFnReattachMeshWithoutBeingSeen)
	{
		uFnReattachMeshWithoutBeingSeen = UFunction::FindFunction("Function GameFramework.GamePawn.ReattachMeshWithoutBeingSeen");
	}

	AGamePawn_execReattachMeshWithoutBeingSeen_Params ReattachMeshWithoutBeingSeen_Params;
	memset(&ReattachMeshWithoutBeingSeen_Params, 0, sizeof(ReattachMeshWithoutBeingSeen_Params));

	if (!uFnReattachMeshWithoutBeingSeen)
	{
		return;
	}

	this->ProcessEvent(uFnReattachMeshWithoutBeingSeen, &ReattachMeshWithoutBeingSeen_Params, nullptr);
}

// Function GameFramework.GamePawn.ReattachMesh
// [0x00020102] (FUNC_Defined | FUNC_Simulated | FUNC_Public)
// Parameter Info:

void AGamePawn::ReattachMesh()
{
	static UFunction* uFnReattachMesh = nullptr;

	if (!uFnReattachMesh)
	{
		uFnReattachMesh = UFunction::FindFunction("Function GameFramework.GamePawn.ReattachMesh");
	}

	AGamePawn_execReattachMesh_Params ReattachMesh_Params;
	memset(&ReattachMesh_Params, 0, sizeof(ReattachMesh_Params));

	if (!uFnReattachMesh)
	{
		return;
	}

	this->ProcessEvent(uFnReattachMesh, &ReattachMesh_Params, nullptr);
}

// Function GameFramework.GamePawn.UpdateShadowSettings
// [0x00020902] (FUNC_Defined | FUNC_Simulated | FUNC_Event | FUNC_Public)
// Parameter Info:
// uint32_t                       bInWantShadow                  (CPF_Parm)

void AGamePawn::eventUpdateShadowSettings(bool bInWantShadow)
{
	static UFunction* uFnUpdateShadowSettings = nullptr;

	if (!uFnUpdateShadowSettings)
	{
		uFnUpdateShadowSettings = UFunction::FindFunction("Function GameFramework.GamePawn.UpdateShadowSettings");
	}

	AGamePawn_eventUpdateShadowSettings_Params UpdateShadowSettings_Params;
	memset(&UpdateShadowSettings_Params, 0, sizeof(UpdateShadowSettings_Params));

	if (!uFnUpdateShadowSettings)
	{
		return;
	}
	UpdateShadowSettings_Params.bInWantShadow = bInWantShadow;

	this->ProcessEvent(uFnUpdateShadowSettings, &UpdateShadowSettings_Params, nullptr);
}

// Function GameFramework.GamePawn.Cringe
// [0x00024800] (FUNC_Event | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// float                          Duration                       (CPF_OptionalParm | CPF_Parm)

void AGamePawn::eventCringe(float optionalDuration)
{
	static UFunction* uFnCringe = nullptr;

	if (!uFnCringe)
	{
		uFnCringe = UFunction::FindFunction("Function GameFramework.GamePawn.Cringe");
	}

	AGamePawn_eventCringe_Params Cringe_Params;
	memset(&Cringe_Params, 0, sizeof(Cringe_Params));

	if (!uFnCringe)
	{
		return;
	}
	Cringe_Params.Duration = optionalDuration;

	this->ProcessEvent(uFnCringe, &Cringe_Params, nullptr);
}

// Function GameFramework.GamePawn.ServerKnockdown
// [0x002240C0] (FUNC_Net | FUNC_NetReliable | FUNC_OptionalParm | FUNC_Public | FUNC_NetServer)
// Parameter Info:
// struct FVector                 RBLinearVelocity               (CPF_OptionalParm | CPF_Parm)
// struct FVector                 RBAngularVelocity              (CPF_OptionalParm | CPF_Parm)
// struct FVector                 RadialOrigin                   (CPF_OptionalParm | CPF_Parm)
// float                          RadialRadius                   (CPF_OptionalParm | CPF_Parm)
// float                          RadialStrength                 (CPF_OptionalParm | CPF_Parm)
// struct FVector                 PointImpulse                   (CPF_OptionalParm | CPF_Parm)
// struct FVector                 PointImpulsePosition           (CPF_OptionalParm | CPF_Parm)
// class FName                    PointImpulseBoneName           (CPF_OptionalParm | CPF_Parm)

void AGamePawn::ServerKnockdown(const struct FVector& optionalRBLinearVelocity, const struct FVector& optionalRBAngularVelocity, const struct FVector& optionalRadialOrigin, float optionalRadialRadius, float optionalRadialStrength, const struct FVector& optionalPointImpulse, const struct FVector& optionalPointImpulsePosition, const class FName& optionalPointImpulseBoneName)
{
	static UFunction* uFnServerKnockdown = nullptr;

	if (!uFnServerKnockdown)
	{
		uFnServerKnockdown = UFunction::FindFunction("Function GameFramework.GamePawn.ServerKnockdown");
	}

	AGamePawn_execServerKnockdown_Params ServerKnockdown_Params;
	memset(&ServerKnockdown_Params, 0, sizeof(ServerKnockdown_Params));

	if (!uFnServerKnockdown)
	{
		return;
	}
	memcpy_s(&ServerKnockdown_Params.RBLinearVelocity, sizeof(ServerKnockdown_Params.RBLinearVelocity), &optionalRBLinearVelocity, sizeof(optionalRBLinearVelocity));
	memcpy_s(&ServerKnockdown_Params.RBAngularVelocity, sizeof(ServerKnockdown_Params.RBAngularVelocity), &optionalRBAngularVelocity, sizeof(optionalRBAngularVelocity));
	memcpy_s(&ServerKnockdown_Params.RadialOrigin, sizeof(ServerKnockdown_Params.RadialOrigin), &optionalRadialOrigin, sizeof(optionalRadialOrigin));
	ServerKnockdown_Params.RadialRadius = optionalRadialRadius;
	ServerKnockdown_Params.RadialStrength = optionalRadialStrength;
	memcpy_s(&ServerKnockdown_Params.PointImpulse, sizeof(ServerKnockdown_Params.PointImpulse), &optionalPointImpulse, sizeof(optionalPointImpulse));
	memcpy_s(&ServerKnockdown_Params.PointImpulsePosition, sizeof(ServerKnockdown_Params.PointImpulsePosition), &optionalPointImpulsePosition, sizeof(optionalPointImpulsePosition));
	memcpy_s(&ServerKnockdown_Params.PointImpulseBoneName, sizeof(ServerKnockdown_Params.PointImpulseBoneName), &optionalPointImpulseBoneName, sizeof(optionalPointImpulseBoneName));

	this->ProcessEvent(uFnServerKnockdown, &ServerKnockdown_Params, nullptr);
}

// Function GameFramework.GamePawn.GetTargetFrictionCylinder
// [0x00420102] (FUNC_Defined | FUNC_Simulated | FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// float                          CylinderRadius                 (CPF_Parm | CPF_OutParm)
// float                          CylinderHeight                 (CPF_Parm | CPF_OutParm)

void AGamePawn::GetTargetFrictionCylinder(float& outCylinderRadius, float& outCylinderHeight)
{
	static UFunction* uFnGetTargetFrictionCylinder = nullptr;

	if (!uFnGetTargetFrictionCylinder)
	{
		uFnGetTargetFrictionCylinder = UFunction::FindFunction("Function GameFramework.GamePawn.GetTargetFrictionCylinder");
	}

	AGamePawn_execGetTargetFrictionCylinder_Params GetTargetFrictionCylinder_Params;
	memset(&GetTargetFrictionCylinder_Params, 0, sizeof(GetTargetFrictionCylinder_Params));

	if (!uFnGetTargetFrictionCylinder)
	{
		return;
	}
	GetTargetFrictionCylinder_Params.CylinderRadius = outCylinderRadius;
	GetTargetFrictionCylinder_Params.CylinderHeight = outCylinderHeight;

	this->ProcessEvent(uFnGetTargetFrictionCylinder, &GetTargetFrictionCylinder_Params, nullptr);

	outCylinderRadius = GetTargetFrictionCylinder_Params.CylinderRadius;
	outCylinderHeight = GetTargetFrictionCylinder_Params.CylinderHeight;
}

// Function GameFramework.GamePawn.StopAllConfigAnim
// [0x00024400] (FUNC_Native | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// float                          BlendOutTime                   (CPF_Parm)
// uint32_t                       bForceStop                     (CPF_OptionalParm | CPF_Parm)
// uint32_t                       bForceAnimNotify               (CPF_OptionalParm | CPF_Parm)
// uint32_t                       bForceAnimEnd                  (CPF_OptionalParm | CPF_Parm)

void AGamePawn::StopAllConfigAnim(float BlendOutTime, bool optionalBForceStop, bool optionalBForceAnimNotify, bool optionalBForceAnimEnd)
{
	static UFunction* uFnStopAllConfigAnim = nullptr;

	if (!uFnStopAllConfigAnim)
	{
		uFnStopAllConfigAnim = UFunction::FindFunction("Function GameFramework.GamePawn.StopAllConfigAnim");
	}

	AGamePawn_execStopAllConfigAnim_Params StopAllConfigAnim_Params;
	memset(&StopAllConfigAnim_Params, 0, sizeof(StopAllConfigAnim_Params));

	if (!uFnStopAllConfigAnim)
	{
		return;
	}
	StopAllConfigAnim_Params.BlendOutTime = BlendOutTime;
	StopAllConfigAnim_Params.bForceStop = optionalBForceStop;
	StopAllConfigAnim_Params.bForceAnimNotify = optionalBForceAnimNotify;
	StopAllConfigAnim_Params.bForceAnimEnd = optionalBForceAnimEnd;

	uint16_t nativeIndex = uFnStopAllConfigAnim->iNative;
	uFnStopAllConfigAnim->iNative = 0;
	this->ProcessEvent(uFnStopAllConfigAnim, &StopAllConfigAnim_Params, nullptr);
	uFnStopAllConfigAnim->iNative = nativeIndex;
}

// Function GameFramework.GamePlayerController.ClientColorFade
// [0x010201C0] (FUNC_Net | FUNC_NetReliable | FUNC_Simulated | FUNC_Public | FUNC_NetClient)
// Parameter Info:
// struct FColor                  FadeColor                      (CPF_Parm)
// uint8_t                        FromAlpha                      (CPF_Parm)
// uint8_t                        ToAlpha                        (CPF_Parm)
// float                          FadeTime                       (CPF_Parm)

void AGamePlayerController::ClientColorFade(const struct FColor& FadeColor, uint8_t FromAlpha, uint8_t ToAlpha, float FadeTime)
{
	static UFunction* uFnClientColorFade = nullptr;

	if (!uFnClientColorFade)
	{
		uFnClientColorFade = UFunction::FindFunction("Function GameFramework.GamePlayerController.ClientColorFade");
	}

	AGamePlayerController_execClientColorFade_Params ClientColorFade_Params;
	memset(&ClientColorFade_Params, 0, sizeof(ClientColorFade_Params));

	if (!uFnClientColorFade)
	{
		return;
	}
	memcpy_s(&ClientColorFade_Params.FadeColor, sizeof(ClientColorFade_Params.FadeColor), &FadeColor, sizeof(FadeColor));
	ClientColorFade_Params.FromAlpha = static_cast<uint8_t>(FromAlpha);
	ClientColorFade_Params.ToAlpha = static_cast<uint8_t>(ToAlpha);
	ClientColorFade_Params.FadeTime = FadeTime;

	this->ProcessEvent(uFnClientColorFade, &ClientColorFade_Params, nullptr);
}

// Function GameFramework.GamePlayerController.WarmupPause
// [0x00820802] (FUNC_Defined | FUNC_Event | FUNC_Public | FUNC_HasDefaults)
// Parameter Info:
// uint32_t                       bDesiredPauseState             (CPF_Parm)

void AGamePlayerController::eventWarmupPause(bool bDesiredPauseState)
{
	static UFunction* uFnWarmupPause = nullptr;

	if (!uFnWarmupPause)
	{
		uFnWarmupPause = UFunction::FindFunction("Function GameFramework.GamePlayerController.WarmupPause");
	}

	AGamePlayerController_eventWarmupPause_Params WarmupPause_Params;
	memset(&WarmupPause_Params, 0, sizeof(WarmupPause_Params));

	if (!uFnWarmupPause)
	{
		return;
	}
	WarmupPause_Params.bDesiredPauseState = bDesiredPauseState;

	this->ProcessEvent(uFnWarmupPause, &WarmupPause_Params, nullptr);
}

// Function GameFramework.GamePlayerController.CanUnpauseWarmup
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

bool AGamePlayerController::CanUnpauseWarmup()
{
	static UFunction* uFnCanUnpauseWarmup = nullptr;

	if (!uFnCanUnpauseWarmup)
	{
		uFnCanUnpauseWarmup = UFunction::FindFunction("Function GameFramework.GamePlayerController.CanUnpauseWarmup");
	}

	AGamePlayerController_execCanUnpauseWarmup_Params CanUnpauseWarmup_Params;
	memset(&CanUnpauseWarmup_Params, 0, sizeof(CanUnpauseWarmup_Params));

	if (!uFnCanUnpauseWarmup)
	{
		return CanUnpauseWarmup_Params.ReturnValue;
	}

	this->ProcessEvent(uFnCanUnpauseWarmup, &CanUnpauseWarmup_Params, nullptr);

	return CanUnpauseWarmup_Params.ReturnValue;
}

// Function GameFramework.GamePlayerController.GetCurrentMovie
// [0x00420401] (FUNC_Final | FUNC_Native | FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// class FString                  MovieName                      (CPF_Parm | CPF_OutParm | CPF_NeedCtorLink)

void AGamePlayerController::GetCurrentMovie(class FString& outMovieName)
{
	static UFunction* uFnGetCurrentMovie = nullptr;

	if (!uFnGetCurrentMovie)
	{
		uFnGetCurrentMovie = UFunction::FindFunction("Function GameFramework.GamePlayerController.GetCurrentMovie");
	}

	AGamePlayerController_execGetCurrentMovie_Params GetCurrentMovie_Params;
	memset(&GetCurrentMovie_Params, 0, sizeof(GetCurrentMovie_Params));

	if (!uFnGetCurrentMovie)
	{
		return;
	}
	memcpy_s(&GetCurrentMovie_Params.MovieName, sizeof(GetCurrentMovie_Params.MovieName), &outMovieName, sizeof(outMovieName));

	uint16_t nativeIndex = uFnGetCurrentMovie->iNative;
	uFnGetCurrentMovie->iNative = 0;
	this->ProcessEvent(uFnGetCurrentMovie, &GetCurrentMovie_Params, nullptr);
	uFnGetCurrentMovie->iNative = nativeIndex;

	memcpy_s(&outMovieName, sizeof(outMovieName), &GetCurrentMovie_Params.MovieName, sizeof(GetCurrentMovie_Params.MovieName));
}

// Function GameFramework.GamePlayerController.ClientStopMovie
// [0x01020DC1] (FUNC_Final | FUNC_Net | FUNC_NetReliable | FUNC_Simulated | FUNC_Native | FUNC_Event | FUNC_Public | FUNC_NetClient)
// Parameter Info:
// float                          DelayInSeconds                 (CPF_Parm)
// uint32_t                       bAllowMovieToFinish            (CPF_Parm)
// uint32_t                       bForceStopNonSkippable         (CPF_Parm)
// uint32_t                       bForceStopLoadingMovie         (CPF_Parm)

void AGamePlayerController::eventClientStopMovie(float DelayInSeconds, bool bAllowMovieToFinish, bool bForceStopNonSkippable, bool bForceStopLoadingMovie)
{
	static UFunction* uFnClientStopMovie = nullptr;

	if (!uFnClientStopMovie)
	{
		uFnClientStopMovie = UFunction::FindFunction("Function GameFramework.GamePlayerController.ClientStopMovie");
	}

	AGamePlayerController_eventClientStopMovie_Params ClientStopMovie_Params;
	memset(&ClientStopMovie_Params, 0, sizeof(ClientStopMovie_Params));

	if (!uFnClientStopMovie)
	{
		return;
	}
	ClientStopMovie_Params.DelayInSeconds = DelayInSeconds;
	ClientStopMovie_Params.bAllowMovieToFinish = bAllowMovieToFinish;
	ClientStopMovie_Params.bForceStopNonSkippable = bForceStopNonSkippable;
	ClientStopMovie_Params.bForceStopLoadingMovie = bForceStopLoadingMovie;

	uint16_t nativeIndex = uFnClientStopMovie->iNative;
	uFnClientStopMovie->iNative = 0;
	this->ProcessEvent(uFnClientStopMovie, &ClientStopMovie_Params, nullptr);
	uFnClientStopMovie->iNative = nativeIndex;
}

// Function GameFramework.GamePlayerController.ClientPlayMovie
// [0x01024DC1] (FUNC_Final | FUNC_Net | FUNC_NetReliable | FUNC_Simulated | FUNC_Native | FUNC_Event | FUNC_OptionalParm | FUNC_Public | FUNC_NetClient)
// Parameter Info:
// class FString                  MovieName                      (CPF_Parm | CPF_NeedCtorLink)
// int32_t                        InStartOfRenderingMovieFrame   (CPF_OptionalParm | CPF_Parm)
// int32_t                        InEndOfRenderingMovieFrame     (CPF_OptionalParm | CPF_Parm)

void AGamePlayerController::eventClientPlayMovie(const class FString& MovieName, int32_t optionalInStartOfRenderingMovieFrame, int32_t optionalInEndOfRenderingMovieFrame)
{
	static UFunction* uFnClientPlayMovie = nullptr;

	if (!uFnClientPlayMovie)
	{
		uFnClientPlayMovie = UFunction::FindFunction("Function GameFramework.GamePlayerController.ClientPlayMovie");
	}

	AGamePlayerController_eventClientPlayMovie_Params ClientPlayMovie_Params;
	memset(&ClientPlayMovie_Params, 0, sizeof(ClientPlayMovie_Params));

	if (!uFnClientPlayMovie)
	{
		return;
	}
	memcpy_s(&ClientPlayMovie_Params.MovieName, sizeof(ClientPlayMovie_Params.MovieName), &MovieName, sizeof(MovieName));
	ClientPlayMovie_Params.InStartOfRenderingMovieFrame = optionalInStartOfRenderingMovieFrame;
	ClientPlayMovie_Params.InEndOfRenderingMovieFrame = optionalInEndOfRenderingMovieFrame;

	uint16_t nativeIndex = uFnClientPlayMovie->iNative;
	uFnClientPlayMovie->iNative = 0;
	this->ProcessEvent(uFnClientPlayMovie, &ClientPlayMovie_Params, nullptr);
	uFnClientPlayMovie->iNative = nativeIndex;
}

// Function GameFramework.GamePlayerController.KeepPlayingLoadingMovie
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:

void AGamePlayerController::KeepPlayingLoadingMovie()
{
	static UFunction* uFnKeepPlayingLoadingMovie = nullptr;

	if (!uFnKeepPlayingLoadingMovie)
	{
		uFnKeepPlayingLoadingMovie = UFunction::FindFunction("Function GameFramework.GamePlayerController.KeepPlayingLoadingMovie");
	}

	AGamePlayerController_execKeepPlayingLoadingMovie_Params KeepPlayingLoadingMovie_Params;
	memset(&KeepPlayingLoadingMovie_Params, 0, sizeof(KeepPlayingLoadingMovie_Params));

	if (!uFnKeepPlayingLoadingMovie)
	{
		return;
	}

	uint16_t nativeIndex = uFnKeepPlayingLoadingMovie->iNative;
	uFnKeepPlayingLoadingMovie->iNative = 0;
	AGamePlayerController::StaticClass()->ClassDefaultObject->ProcessEvent(uFnKeepPlayingLoadingMovie, &KeepPlayingLoadingMovie_Params, nullptr);
	uFnKeepPlayingLoadingMovie->iNative = nativeIndex;
}

// Function GameFramework.GamePlayerController.ShowLoadingMovie
// [0x00026401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// uint32_t                       bShowMovie                     (CPF_Parm)
// uint32_t                       bPauseAfterHide                (CPF_OptionalParm | CPF_Parm)
// float                          PauseDuration                  (CPF_OptionalParm | CPF_Parm)
// float                          KeepPlayingDuration            (CPF_OptionalParm | CPF_Parm)
// uint32_t                       bOverridePreviousDelays        (CPF_OptionalParm | CPF_Parm)

void AGamePlayerController::ShowLoadingMovie(bool bShowMovie, bool optionalBPauseAfterHide, float optionalPauseDuration, float optionalKeepPlayingDuration, bool optionalBOverridePreviousDelays)
{
	static UFunction* uFnShowLoadingMovie = nullptr;

	if (!uFnShowLoadingMovie)
	{
		uFnShowLoadingMovie = UFunction::FindFunction("Function GameFramework.GamePlayerController.ShowLoadingMovie");
	}

	AGamePlayerController_execShowLoadingMovie_Params ShowLoadingMovie_Params;
	memset(&ShowLoadingMovie_Params, 0, sizeof(ShowLoadingMovie_Params));

	if (!uFnShowLoadingMovie)
	{
		return;
	}
	ShowLoadingMovie_Params.bShowMovie = bShowMovie;
	ShowLoadingMovie_Params.bPauseAfterHide = optionalBPauseAfterHide;
	ShowLoadingMovie_Params.PauseDuration = optionalPauseDuration;
	ShowLoadingMovie_Params.KeepPlayingDuration = optionalKeepPlayingDuration;
	ShowLoadingMovie_Params.bOverridePreviousDelays = optionalBOverridePreviousDelays;

	uint16_t nativeIndex = uFnShowLoadingMovie->iNative;
	uFnShowLoadingMovie->iNative = 0;
	AGamePlayerController::StaticClass()->ClassDefaultObject->ProcessEvent(uFnShowLoadingMovie, &ShowLoadingMovie_Params, nullptr);
	uFnShowLoadingMovie->iNative = nativeIndex;
}

// Function GameFramework.GamePlayerController.GetCurrentSoundMode
// [0x00020103] (FUNC_Final | FUNC_Defined | FUNC_Simulated | FUNC_Public)
// Parameter Info:
// class FName                    ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

class FName AGamePlayerController::GetCurrentSoundMode()
{
	static UFunction* uFnGetCurrentSoundMode = nullptr;

	if (!uFnGetCurrentSoundMode)
	{
		uFnGetCurrentSoundMode = UFunction::FindFunction("Function GameFramework.GamePlayerController.GetCurrentSoundMode");
	}

	AGamePlayerController_execGetCurrentSoundMode_Params GetCurrentSoundMode_Params;
	memset(&GetCurrentSoundMode_Params, 0, sizeof(GetCurrentSoundMode_Params));

	if (!uFnGetCurrentSoundMode)
	{
		return GetCurrentSoundMode_Params.ReturnValue;
	}

	this->ProcessEvent(uFnGetCurrentSoundMode, &GetCurrentSoundMode_Params, nullptr);

	return GetCurrentSoundMode_Params.ReturnValue;
}

// Function GameFramework.GamePlayerController.SetSoundMode
// [0x00020102] (FUNC_Defined | FUNC_Simulated | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FName                    InSoundModeName                (CPF_Parm)

bool AGamePlayerController::SetSoundMode(const class FName& InSoundModeName)
{
	static UFunction* uFnSetSoundMode = nullptr;

	if (!uFnSetSoundMode)
	{
		uFnSetSoundMode = UFunction::FindFunction("Function GameFramework.GamePlayerController.SetSoundMode");
	}

	AGamePlayerController_execSetSoundMode_Params SetSoundMode_Params;
	memset(&SetSoundMode_Params, 0, sizeof(SetSoundMode_Params));

	if (!uFnSetSoundMode)
	{
		return SetSoundMode_Params.ReturnValue;
	}
	memcpy_s(&SetSoundMode_Params.InSoundModeName, sizeof(SetSoundMode_Params.InSoundModeName), &InSoundModeName, sizeof(InSoundModeName));

	this->ProcessEvent(uFnSetSoundMode, &SetSoundMode_Params, nullptr);

	return SetSoundMode_Params.ReturnValue;
}

// Function GameFramework.GamePlayerController.DoForceFeedbackForScreenShake
// [0x00080102] (FUNC_Defined | FUNC_Simulated | FUNC_Protected)
// Parameter Info:
// class UCameraShake*            ShakeData                      (CPF_Parm)
// float                          Scale                          (CPF_Parm)

void AGamePlayerController::DoForceFeedbackForScreenShake(class UCameraShake* ShakeData, float Scale)
{
	static UFunction* uFnDoForceFeedbackForScreenShake = nullptr;

	if (!uFnDoForceFeedbackForScreenShake)
	{
		uFnDoForceFeedbackForScreenShake = UFunction::FindFunction("Function GameFramework.GamePlayerController.DoForceFeedbackForScreenShake");
	}

	AGamePlayerController_execDoForceFeedbackForScreenShake_Params DoForceFeedbackForScreenShake_Params;
	memset(&DoForceFeedbackForScreenShake_Params, 0, sizeof(DoForceFeedbackForScreenShake_Params));

	if (!uFnDoForceFeedbackForScreenShake)
	{
		return;
	}
	DoForceFeedbackForScreenShake_Params.ShakeData = ShakeData;
	DoForceFeedbackForScreenShake_Params.Scale = Scale;

	this->ProcessEvent(uFnDoForceFeedbackForScreenShake, &DoForceFeedbackForScreenShake_Params, nullptr);
}

// Function GameFramework.GamePlayerController.NotifyCrowdAgentInRadius
// [0x00020800] (FUNC_Event | FUNC_Public)
// Parameter Info:
// class AGameCrowdAgent*         Agent                          (CPF_Parm)

void AGamePlayerController::eventNotifyCrowdAgentInRadius(class AGameCrowdAgent* Agent)
{
	static UFunction* uFnNotifyCrowdAgentInRadius = nullptr;

	if (!uFnNotifyCrowdAgentInRadius)
	{
		uFnNotifyCrowdAgentInRadius = UFunction::FindFunction("Function GameFramework.GamePlayerController.NotifyCrowdAgentInRadius");
	}

	AGamePlayerController_eventNotifyCrowdAgentInRadius_Params NotifyCrowdAgentInRadius_Params;
	memset(&NotifyCrowdAgentInRadius_Params, 0, sizeof(NotifyCrowdAgentInRadius_Params));

	if (!uFnNotifyCrowdAgentInRadius)
	{
		return;
	}
	NotifyCrowdAgentInRadius_Params.Agent = Agent;

	this->ProcessEvent(uFnNotifyCrowdAgentInRadius, &NotifyCrowdAgentInRadius_Params, nullptr);
}

// Function GameFramework.GamePlayerController.NotifyCrowdAgentRefresh
// [0x00020800] (FUNC_Event | FUNC_Public)
// Parameter Info:

void AGamePlayerController::eventNotifyCrowdAgentRefresh()
{
	static UFunction* uFnNotifyCrowdAgentRefresh = nullptr;

	if (!uFnNotifyCrowdAgentRefresh)
	{
		uFnNotifyCrowdAgentRefresh = UFunction::FindFunction("Function GameFramework.GamePlayerController.NotifyCrowdAgentRefresh");
	}

	AGamePlayerController_eventNotifyCrowdAgentRefresh_Params NotifyCrowdAgentRefresh_Params;
	memset(&NotifyCrowdAgentRefresh_Params, 0, sizeof(NotifyCrowdAgentRefresh_Params));

	if (!uFnNotifyCrowdAgentRefresh)
	{
		return;
	}

	this->ProcessEvent(uFnNotifyCrowdAgentRefresh, &NotifyCrowdAgentRefresh_Params, nullptr);
}

// Function GameFramework.GamePlayerController.CrowdDebug
// [0x00020202] (FUNC_Defined | FUNC_Exec | FUNC_Public)
// Parameter Info:
// uint32_t                       bEnabled                       (CPF_Parm)

void AGamePlayerController::CrowdDebug(bool bEnabled)
{
	static UFunction* uFnCrowdDebug = nullptr;

	if (!uFnCrowdDebug)
	{
		uFnCrowdDebug = UFunction::FindFunction("Function GameFramework.GamePlayerController.CrowdDebug");
	}

	AGamePlayerController_execCrowdDebug_Params CrowdDebug_Params;
	memset(&CrowdDebug_Params, 0, sizeof(CrowdDebug_Params));

	if (!uFnCrowdDebug)
	{
		return;
	}
	CrowdDebug_Params.bEnabled = bEnabled;

	this->ProcessEvent(uFnCrowdDebug, &CrowdDebug_Params, nullptr);
}

// Function GameFramework.GamePlayerController.CrowdToggle
// [0x00020202] (FUNC_Defined | FUNC_Exec | FUNC_Public)
// Parameter Info:

void AGamePlayerController::CrowdToggle()
{
	static UFunction* uFnCrowdToggle = nullptr;

	if (!uFnCrowdToggle)
	{
		uFnCrowdToggle = UFunction::FindFunction("Function GameFramework.GamePlayerController.CrowdToggle");
	}

	AGamePlayerController_execCrowdToggle_Params CrowdToggle_Params;
	memset(&CrowdToggle_Params, 0, sizeof(CrowdToggle_Params));

	if (!uFnCrowdToggle)
	{
		return;
	}

	this->ProcessEvent(uFnCrowdToggle, &CrowdToggle_Params, nullptr);
}

// Function GameFramework.GamePlayerController.CrowdFocus
// [0x00020202] (FUNC_Defined | FUNC_Exec | FUNC_Public)
// Parameter Info:

void AGamePlayerController::CrowdFocus()
{
	static UFunction* uFnCrowdFocus = nullptr;

	if (!uFnCrowdFocus)
	{
		uFnCrowdFocus = UFunction::FindFunction("Function GameFramework.GamePlayerController.CrowdFocus");
	}

	AGamePlayerController_execCrowdFocus_Params CrowdFocus_Params;
	memset(&CrowdFocus_Params, 0, sizeof(CrowdFocus_Params));

	if (!uFnCrowdFocus)
	{
		return;
	}

	this->ProcessEvent(uFnCrowdFocus, &CrowdFocus_Params, nullptr);
}

// Function GameFramework.GamePlayerController.GetUIPlayerIndex
// [0x00020400] (FUNC_Native | FUNC_Public)
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

int32_t AGamePlayerController::GetUIPlayerIndex()
{
	static UFunction* uFnGetUIPlayerIndex = nullptr;

	if (!uFnGetUIPlayerIndex)
	{
		uFnGetUIPlayerIndex = UFunction::FindFunction("Function GameFramework.GamePlayerController.GetUIPlayerIndex");
	}

	AGamePlayerController_execGetUIPlayerIndex_Params GetUIPlayerIndex_Params;
	memset(&GetUIPlayerIndex_Params, 0, sizeof(GetUIPlayerIndex_Params));

	if (!uFnGetUIPlayerIndex)
	{
		return GetUIPlayerIndex_Params.ReturnValue;
	}

	uint16_t nativeIndex = uFnGetUIPlayerIndex->iNative;
	uFnGetUIPlayerIndex->iNative = 0;
	this->ProcessEvent(uFnGetUIPlayerIndex, &GetUIPlayerIndex_Params, nullptr);
	uFnGetUIPlayerIndex->iNative = nativeIndex;

	return GetUIPlayerIndex_Params.ReturnValue;
}

// Function GameFramework.NavMeshGoal_OutOfViewFrom.Recycle
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:

void UNavMeshGoal_OutOfViewFrom::Recycle()
{
	static UFunction* uFnRecycle = nullptr;

	if (!uFnRecycle)
	{
		uFnRecycle = UFunction::FindFunction("Function GameFramework.NavMeshGoal_OutOfViewFrom.Recycle");
	}

	UNavMeshGoal_OutOfViewFrom_execRecycle_Params Recycle_Params;
	memset(&Recycle_Params, 0, sizeof(Recycle_Params));

	if (!uFnRecycle)
	{
		return;
	}

	this->ProcessEvent(uFnRecycle, &Recycle_Params, nullptr);
}

// Function GameFramework.NavMeshGoal_OutOfViewFrom.MustBeHiddenFromThisPoint
// [0x00022002] (FUNC_Defined | FUNC_Static | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class UNavigationHandle*       NavHandle                      (CPF_Parm)
// struct FVector                 InOutOfViewLocation            (CPF_Parm)

bool UNavMeshGoal_OutOfViewFrom::MustBeHiddenFromThisPoint(class UNavigationHandle* NavHandle, const struct FVector& InOutOfViewLocation)
{
	static UFunction* uFnMustBeHiddenFromThisPoint = nullptr;

	if (!uFnMustBeHiddenFromThisPoint)
	{
		uFnMustBeHiddenFromThisPoint = UFunction::FindFunction("Function GameFramework.NavMeshGoal_OutOfViewFrom.MustBeHiddenFromThisPoint");
	}

	UNavMeshGoal_OutOfViewFrom_execMustBeHiddenFromThisPoint_Params MustBeHiddenFromThisPoint_Params;
	memset(&MustBeHiddenFromThisPoint_Params, 0, sizeof(MustBeHiddenFromThisPoint_Params));

	if (!uFnMustBeHiddenFromThisPoint)
	{
		return MustBeHiddenFromThisPoint_Params.ReturnValue;
	}
	MustBeHiddenFromThisPoint_Params.NavHandle = NavHandle;
	memcpy_s(&MustBeHiddenFromThisPoint_Params.InOutOfViewLocation, sizeof(MustBeHiddenFromThisPoint_Params.InOutOfViewLocation), &InOutOfViewLocation, sizeof(InOutOfViewLocation));

	UNavMeshGoal_OutOfViewFrom::StaticClass()->ClassDefaultObject->ProcessEvent(uFnMustBeHiddenFromThisPoint, &MustBeHiddenFromThisPoint_Params, nullptr);

	return MustBeHiddenFromThisPoint_Params.ReturnValue;
}

// Function GameFramework.NavMeshGoal_OutOfViewFrom.RecycleNative
// [0x00020400] (FUNC_Native | FUNC_Public)
// Parameter Info:

void UNavMeshGoal_OutOfViewFrom::RecycleNative()
{
	static UFunction* uFnRecycleNative = nullptr;

	if (!uFnRecycleNative)
	{
		uFnRecycleNative = UFunction::FindFunction("Function GameFramework.NavMeshGoal_OutOfViewFrom.RecycleNative");
	}

	UNavMeshGoal_OutOfViewFrom_execRecycleNative_Params RecycleNative_Params;
	memset(&RecycleNative_Params, 0, sizeof(RecycleNative_Params));

	if (!uFnRecycleNative)
	{
		return;
	}

	uint16_t nativeIndex = uFnRecycleNative->iNative;
	uFnRecycleNative->iNative = 0;
	this->ProcessEvent(uFnRecycleNative, &RecycleNative_Params, nullptr);
	uFnRecycleNative->iNative = nativeIndex;
}

// Function GameFramework.NavMeshPath_BiasAgainstPolysWithinDistanceOfLocations.Recycle
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:

void UNavMeshPath_BiasAgainstPolysWithinDistanceOfLocations::Recycle()
{
	static UFunction* uFnRecycle = nullptr;

	if (!uFnRecycle)
	{
		uFnRecycle = UFunction::FindFunction("Function GameFramework.NavMeshPath_BiasAgainstPolysWithinDistanceOfLocations.Recycle");
	}

	UNavMeshPath_BiasAgainstPolysWithinDistanceOfLocations_execRecycle_Params Recycle_Params;
	memset(&Recycle_Params, 0, sizeof(Recycle_Params));

	if (!uFnRecycle)
	{
		return;
	}

	this->ProcessEvent(uFnRecycle, &Recycle_Params, nullptr);
}

// Function GameFramework.NavMeshPath_BiasAgainstPolysWithinDistanceOfLocations.BiasAgainstPolysWithinDistanceOfLocations
// [0x00022002] (FUNC_Defined | FUNC_Static | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class UNavigationHandle*       NavHandle                      (CPF_Parm)
// struct FVector                 InLocation                     (CPF_Const | CPF_Parm)
// struct FRotator                InRotation                     (CPF_Const | CPF_Parm)
// float                          InDistanceToCheck              (CPF_Const | CPF_Parm)
// class TArray<struct FVector>   InLocationsToCheck             (CPF_Const | CPF_Parm | CPF_NeedCtorLink)

bool UNavMeshPath_BiasAgainstPolysWithinDistanceOfLocations::BiasAgainstPolysWithinDistanceOfLocations(class UNavigationHandle* NavHandle, const struct FVector& InLocation, const struct FRotator& InRotation, float InDistanceToCheck, const class TArray<struct FVector>& InLocationsToCheck)
{
	static UFunction* uFnBiasAgainstPolysWithinDistanceOfLocations = nullptr;

	if (!uFnBiasAgainstPolysWithinDistanceOfLocations)
	{
		uFnBiasAgainstPolysWithinDistanceOfLocations = UFunction::FindFunction("Function GameFramework.NavMeshPath_BiasAgainstPolysWithinDistanceOfLocations.BiasAgainstPolysWithinDistanceOfLocations");
	}

	UNavMeshPath_BiasAgainstPolysWithinDistanceOfLocations_execBiasAgainstPolysWithinDistanceOfLocations_Params BiasAgainstPolysWithinDistanceOfLocations_Params;
	memset(&BiasAgainstPolysWithinDistanceOfLocations_Params, 0, sizeof(BiasAgainstPolysWithinDistanceOfLocations_Params));

	if (!uFnBiasAgainstPolysWithinDistanceOfLocations)
	{
		return BiasAgainstPolysWithinDistanceOfLocations_Params.ReturnValue;
	}
	BiasAgainstPolysWithinDistanceOfLocations_Params.NavHandle = NavHandle;
	memcpy_s(&BiasAgainstPolysWithinDistanceOfLocations_Params.InLocation, sizeof(BiasAgainstPolysWithinDistanceOfLocations_Params.InLocation), &InLocation, sizeof(InLocation));
	memcpy_s(&BiasAgainstPolysWithinDistanceOfLocations_Params.InRotation, sizeof(BiasAgainstPolysWithinDistanceOfLocations_Params.InRotation), &InRotation, sizeof(InRotation));
	BiasAgainstPolysWithinDistanceOfLocations_Params.InDistanceToCheck = InDistanceToCheck;
	memcpy_s(&BiasAgainstPolysWithinDistanceOfLocations_Params.InLocationsToCheck, sizeof(BiasAgainstPolysWithinDistanceOfLocations_Params.InLocationsToCheck), &InLocationsToCheck, sizeof(InLocationsToCheck));

	UNavMeshPath_BiasAgainstPolysWithinDistanceOfLocations::StaticClass()->ClassDefaultObject->ProcessEvent(uFnBiasAgainstPolysWithinDistanceOfLocations, &BiasAgainstPolysWithinDistanceOfLocations_Params, nullptr);

	return BiasAgainstPolysWithinDistanceOfLocations_Params.ReturnValue;
}

// Function GameFramework.SeqAct_GameCrowdPopulationManagerToggle.GetObjClassVersion
// [0x00022802] (FUNC_Defined | FUNC_Event | FUNC_Static | FUNC_Public)
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

int32_t USeqAct_GameCrowdPopulationManagerToggle::eventGetObjClassVersion()
{
	static UFunction* uFnGetObjClassVersion = nullptr;

	if (!uFnGetObjClassVersion)
	{
		uFnGetObjClassVersion = UFunction::FindFunction("Function GameFramework.SeqAct_GameCrowdPopulationManagerToggle.GetObjClassVersion");
	}

	USeqAct_GameCrowdPopulationManagerToggle_eventGetObjClassVersion_Params GetObjClassVersion_Params;
	memset(&GetObjClassVersion_Params, 0, sizeof(GetObjClassVersion_Params));

	if (!uFnGetObjClassVersion)
	{
		return GetObjClassVersion_Params.ReturnValue;
	}

	USeqAct_GameCrowdPopulationManagerToggle::StaticClass()->ClassDefaultObject->ProcessEvent(uFnGetObjClassVersion, &GetObjClassVersion_Params, nullptr);

	return GetObjClassVersion_Params.ReturnValue;
}

// Function GameFramework.SeqAct_GameCrowdPopulationManagerToggle.FindPopMgrTarget
// [0x00020802] (FUNC_Defined | FUNC_Event | FUNC_Public)
// Parameter Info:

void USeqAct_GameCrowdPopulationManagerToggle::eventFindPopMgrTarget()
{
	static UFunction* uFnFindPopMgrTarget = nullptr;

	if (!uFnFindPopMgrTarget)
	{
		uFnFindPopMgrTarget = UFunction::FindFunction("Function GameFramework.SeqAct_GameCrowdPopulationManagerToggle.FindPopMgrTarget");
	}

	USeqAct_GameCrowdPopulationManagerToggle_eventFindPopMgrTarget_Params FindPopMgrTarget_Params;
	memset(&FindPopMgrTarget_Params, 0, sizeof(FindPopMgrTarget_Params));

	if (!uFnFindPopMgrTarget)
	{
		return;
	}

	this->ProcessEvent(uFnFindPopMgrTarget, &FindPopMgrTarget_Params, nullptr);
}

// Function GameFramework.SeqAct_GameCrowdSpawner.GetObjClassVersion
// [0x00022802] (FUNC_Defined | FUNC_Event | FUNC_Static | FUNC_Public)
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

int32_t USeqAct_GameCrowdSpawner::eventGetObjClassVersion()
{
	static UFunction* uFnGetObjClassVersion = nullptr;

	if (!uFnGetObjClassVersion)
	{
		uFnGetObjClassVersion = UFunction::FindFunction("Function GameFramework.SeqAct_GameCrowdSpawner.GetObjClassVersion");
	}

	USeqAct_GameCrowdSpawner_eventGetObjClassVersion_Params GetObjClassVersion_Params;
	memset(&GetObjClassVersion_Params, 0, sizeof(GetObjClassVersion_Params));

	if (!uFnGetObjClassVersion)
	{
		return GetObjClassVersion_Params.ReturnValue;
	}

	USeqAct_GameCrowdSpawner::StaticClass()->ClassDefaultObject->ProcessEvent(uFnGetObjClassVersion, &GetObjClassVersion_Params, nullptr);

	return GetObjClassVersion_Params.ReturnValue;
}

// Function GameFramework.SeqAct_GameCrowdSpawner.CreateNewAgent
// [0x00820002] (FUNC_Defined | FUNC_Public | FUNC_HasDefaults)
// Parameter Info:
// class AGameCrowdAgent*         ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class AActor*                  SpawnLoc                       (CPF_Parm)
// class AGameCrowdAgent*         AgentTemplate                  (CPF_Parm)
// class UGameCrowdGroup*         NewGroup                       (CPF_Parm)

class AGameCrowdAgent* USeqAct_GameCrowdSpawner::CreateNewAgent(class AActor* SpawnLoc, class AGameCrowdAgent* AgentTemplate, class UGameCrowdGroup* NewGroup)
{
	static UFunction* uFnCreateNewAgent = nullptr;

	if (!uFnCreateNewAgent)
	{
		uFnCreateNewAgent = UFunction::FindFunction("Function GameFramework.SeqAct_GameCrowdSpawner.CreateNewAgent");
	}

	USeqAct_GameCrowdSpawner_execCreateNewAgent_Params CreateNewAgent_Params;
	memset(&CreateNewAgent_Params, 0, sizeof(CreateNewAgent_Params));

	if (!uFnCreateNewAgent)
	{
		return CreateNewAgent_Params.ReturnValue;
	}
	CreateNewAgent_Params.SpawnLoc = SpawnLoc;
	CreateNewAgent_Params.AgentTemplate = AgentTemplate;
	CreateNewAgent_Params.NewGroup = NewGroup;

	this->ProcessEvent(uFnCreateNewAgent, &CreateNewAgent_Params, nullptr);

	return CreateNewAgent_Params.ReturnValue;
}

// Function GameFramework.SeqAct_GameCrowdSpawner.SpawnAgent
// [0x00020802] (FUNC_Defined | FUNC_Event | FUNC_Public)
// Parameter Info:
// class AGameCrowdAgent*         ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class AActor*                  SpawnLoc                       (CPF_Parm)

class AGameCrowdAgent* USeqAct_GameCrowdSpawner::eventSpawnAgent(class AActor* SpawnLoc)
{
	static UFunction* uFnSpawnAgent = nullptr;

	if (!uFnSpawnAgent)
	{
		uFnSpawnAgent = UFunction::FindFunction("Function GameFramework.SeqAct_GameCrowdSpawner.SpawnAgent");
	}

	USeqAct_GameCrowdSpawner_eventSpawnAgent_Params SpawnAgent_Params;
	memset(&SpawnAgent_Params, 0, sizeof(SpawnAgent_Params));

	if (!uFnSpawnAgent)
	{
		return SpawnAgent_Params.ReturnValue;
	}
	SpawnAgent_Params.SpawnLoc = SpawnLoc;

	this->ProcessEvent(uFnSpawnAgent, &SpawnAgent_Params, nullptr);

	return SpawnAgent_Params.ReturnValue;
}

// Function GameFramework.SeqAct_GameCrowdSpawner.UpdateSpawning
// [0x00020500] (FUNC_Simulated | FUNC_Native | FUNC_Public)
// Parameter Info:
// float                          DeltaSeconds                   (CPF_Parm)

void USeqAct_GameCrowdSpawner::UpdateSpawning(float DeltaSeconds)
{
	static UFunction* uFnUpdateSpawning = nullptr;

	if (!uFnUpdateSpawning)
	{
		uFnUpdateSpawning = UFunction::FindFunction("Function GameFramework.SeqAct_GameCrowdSpawner.UpdateSpawning");
	}

	USeqAct_GameCrowdSpawner_execUpdateSpawning_Params UpdateSpawning_Params;
	memset(&UpdateSpawning_Params, 0, sizeof(UpdateSpawning_Params));

	if (!uFnUpdateSpawning)
	{
		return;
	}
	UpdateSpawning_Params.DeltaSeconds = DeltaSeconds;

	uint16_t nativeIndex = uFnUpdateSpawning->iNative;
	uFnUpdateSpawning->iNative = 0;
	this->ProcessEvent(uFnUpdateSpawning, &UpdateSpawning_Params, nullptr);
	uFnUpdateSpawning->iNative = nativeIndex;
}

// Function GameFramework.SeqAct_GameCrowdSpawner.KillAgents
// [0x00020500] (FUNC_Simulated | FUNC_Native | FUNC_Public)
// Parameter Info:

void USeqAct_GameCrowdSpawner::KillAgents()
{
	static UFunction* uFnKillAgents = nullptr;

	if (!uFnKillAgents)
	{
		uFnKillAgents = UFunction::FindFunction("Function GameFramework.SeqAct_GameCrowdSpawner.KillAgents");
	}

	USeqAct_GameCrowdSpawner_execKillAgents_Params KillAgents_Params;
	memset(&KillAgents_Params, 0, sizeof(KillAgents_Params));

	if (!uFnKillAgents)
	{
		return;
	}

	uint16_t nativeIndex = uFnKillAgents->iNative;
	uFnKillAgents->iNative = 0;
	this->ProcessEvent(uFnKillAgents, &KillAgents_Params, nullptr);
	uFnKillAgents->iNative = nativeIndex;
}

// Function GameFramework.SeqAct_GameCrowdSpawner.CacheSpawnerVars
// [0x00020500] (FUNC_Simulated | FUNC_Native | FUNC_Public)
// Parameter Info:

void USeqAct_GameCrowdSpawner::CacheSpawnerVars()
{
	static UFunction* uFnCacheSpawnerVars = nullptr;

	if (!uFnCacheSpawnerVars)
	{
		uFnCacheSpawnerVars = UFunction::FindFunction("Function GameFramework.SeqAct_GameCrowdSpawner.CacheSpawnerVars");
	}

	USeqAct_GameCrowdSpawner_execCacheSpawnerVars_Params CacheSpawnerVars_Params;
	memset(&CacheSpawnerVars_Params, 0, sizeof(CacheSpawnerVars_Params));

	if (!uFnCacheSpawnerVars)
	{
		return;
	}

	uint16_t nativeIndex = uFnCacheSpawnerVars->iNative;
	uFnCacheSpawnerVars->iNative = 0;
	this->ProcessEvent(uFnCacheSpawnerVars, &CacheSpawnerVars_Params, nullptr);
	uFnCacheSpawnerVars->iNative = nativeIndex;
}

// Function GameFramework.SeqAct_GameCrowdSpawner.SpawnedAgent
// [0x00020400] (FUNC_Native | FUNC_Public)
// Parameter Info:
// class AGameCrowdAgent*         NewAgent                       (CPF_Parm)

void USeqAct_GameCrowdSpawner::SpawnedAgent(class AGameCrowdAgent* NewAgent)
{
	static UFunction* uFnSpawnedAgent = nullptr;

	if (!uFnSpawnedAgent)
	{
		uFnSpawnedAgent = UFunction::FindFunction("Function GameFramework.SeqAct_GameCrowdSpawner.SpawnedAgent");
	}

	USeqAct_GameCrowdSpawner_execSpawnedAgent_Params SpawnedAgent_Params;
	memset(&SpawnedAgent_Params, 0, sizeof(SpawnedAgent_Params));

	if (!uFnSpawnedAgent)
	{
		return;
	}
	SpawnedAgent_Params.NewAgent = NewAgent;

	uint16_t nativeIndex = uFnSpawnedAgent->iNative;
	uFnSpawnedAgent->iNative = 0;
	this->ProcessEvent(uFnSpawnedAgent, &SpawnedAgent_Params, nullptr);
	uFnSpawnedAgent->iNative = nativeIndex;
}

// Function GameFramework.SeqAct_PlayAgentAnimation.SetCurrentAnimationActionFor
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class AGameCrowdAgentSkeletal* Agent                          (CPF_Parm)

void USeqAct_PlayAgentAnimation::SetCurrentAnimationActionFor(class AGameCrowdAgentSkeletal* Agent)
{
	static UFunction* uFnSetCurrentAnimationActionFor = nullptr;

	if (!uFnSetCurrentAnimationActionFor)
	{
		uFnSetCurrentAnimationActionFor = UFunction::FindFunction("Function GameFramework.SeqAct_PlayAgentAnimation.SetCurrentAnimationActionFor");
	}

	USeqAct_PlayAgentAnimation_execSetCurrentAnimationActionFor_Params SetCurrentAnimationActionFor_Params;
	memset(&SetCurrentAnimationActionFor_Params, 0, sizeof(SetCurrentAnimationActionFor_Params));

	if (!uFnSetCurrentAnimationActionFor)
	{
		return;
	}
	SetCurrentAnimationActionFor_Params.Agent = Agent;

	this->ProcessEvent(uFnSetCurrentAnimationActionFor, &SetCurrentAnimationActionFor_Params, nullptr);
}

// Function GameFramework.SeqAct_PlayAgentAnimation.GetObjClassVersion
// [0x00022802] (FUNC_Defined | FUNC_Event | FUNC_Static | FUNC_Public)
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

int32_t USeqAct_PlayAgentAnimation::eventGetObjClassVersion()
{
	static UFunction* uFnGetObjClassVersion = nullptr;

	if (!uFnGetObjClassVersion)
	{
		uFnGetObjClassVersion = UFunction::FindFunction("Function GameFramework.SeqAct_PlayAgentAnimation.GetObjClassVersion");
	}

	USeqAct_PlayAgentAnimation_eventGetObjClassVersion_Params GetObjClassVersion_Params;
	memset(&GetObjClassVersion_Params, 0, sizeof(GetObjClassVersion_Params));

	if (!uFnGetObjClassVersion)
	{
		return GetObjClassVersion_Params.ReturnValue;
	}

	USeqAct_PlayAgentAnimation::StaticClass()->ClassDefaultObject->ProcessEvent(uFnGetObjClassVersion, &GetObjClassVersion_Params, nullptr);

	return GetObjClassVersion_Params.ReturnValue;
}

// Function GameFramework.GameCameraBase.ModifyPostProcessSettings
// [0x00420800] (FUNC_Event | FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// struct FPostProcessSettings    PP                             (CPF_Parm | CPF_OutParm)

void UGameCameraBase::eventModifyPostProcessSettings(struct FPostProcessSettings& outPP)
{
	static UFunction* uFnModifyPostProcessSettings = nullptr;

	if (!uFnModifyPostProcessSettings)
	{
		uFnModifyPostProcessSettings = UFunction::FindFunction("Function GameFramework.GameCameraBase.ModifyPostProcessSettings");
	}

	UGameCameraBase_eventModifyPostProcessSettings_Params ModifyPostProcessSettings_Params;
	memset(&ModifyPostProcessSettings_Params, 0, sizeof(ModifyPostProcessSettings_Params));

	if (!uFnModifyPostProcessSettings)
	{
		return;
	}
	memcpy_s(&ModifyPostProcessSettings_Params.PP, sizeof(ModifyPostProcessSettings_Params.PP), &outPP, sizeof(outPP));

	this->ProcessEvent(uFnModifyPostProcessSettings, &ModifyPostProcessSettings_Params, nullptr);

	memcpy_s(&outPP, sizeof(outPP), &ModifyPostProcessSettings_Params.PP, sizeof(ModifyPostProcessSettings_Params.PP));
}

// Function GameFramework.GameCameraBase.Init
// [0x00020000] (FUNC_Public)
// Parameter Info:

void UGameCameraBase::Init()
{
	static UFunction* uFnInit = nullptr;

	if (!uFnInit)
	{
		uFnInit = UFunction::FindFunction("Function GameFramework.GameCameraBase.Init");
	}

	UGameCameraBase_execInit_Params Init_Params;
	memset(&Init_Params, 0, sizeof(Init_Params));

	if (!uFnInit)
	{
		return;
	}

	this->ProcessEvent(uFnInit, &Init_Params, nullptr);
}

// Function GameFramework.GameCameraBase.ProcessViewRotation
// [0x00420000] (FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// float                          DeltaTime                      (CPF_Parm)
// class AActor*                  ViewTarget                     (CPF_Parm)
// struct FRotator                out_ViewRotation               (CPF_Parm | CPF_OutParm)
// struct FRotator                out_DeltaRot                   (CPF_Parm | CPF_OutParm)

void UGameCameraBase::ProcessViewRotation(float DeltaTime, class AActor* ViewTarget, struct FRotator& outOut_ViewRotation, struct FRotator& outOut_DeltaRot)
{
	static UFunction* uFnProcessViewRotation = nullptr;

	if (!uFnProcessViewRotation)
	{
		uFnProcessViewRotation = UFunction::FindFunction("Function GameFramework.GameCameraBase.ProcessViewRotation");
	}

	UGameCameraBase_execProcessViewRotation_Params ProcessViewRotation_Params;
	memset(&ProcessViewRotation_Params, 0, sizeof(ProcessViewRotation_Params));

	if (!uFnProcessViewRotation)
	{
		return;
	}
	ProcessViewRotation_Params.DeltaTime = DeltaTime;
	ProcessViewRotation_Params.ViewTarget = ViewTarget;
	memcpy_s(&ProcessViewRotation_Params.out_ViewRotation, sizeof(ProcessViewRotation_Params.out_ViewRotation), &outOut_ViewRotation, sizeof(outOut_ViewRotation));
	memcpy_s(&ProcessViewRotation_Params.out_DeltaRot, sizeof(ProcessViewRotation_Params.out_DeltaRot), &outOut_DeltaRot, sizeof(outOut_DeltaRot));

	this->ProcessEvent(uFnProcessViewRotation, &ProcessViewRotation_Params, nullptr);

	memcpy_s(&outOut_ViewRotation, sizeof(outOut_ViewRotation), &ProcessViewRotation_Params.out_ViewRotation, sizeof(ProcessViewRotation_Params.out_ViewRotation));
	memcpy_s(&outOut_DeltaRot, sizeof(outOut_DeltaRot), &ProcessViewRotation_Params.out_DeltaRot, sizeof(ProcessViewRotation_Params.out_DeltaRot));
}

// Function GameFramework.GameCameraBase.UpdateCamera
// [0x00420000] (FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// class APawn*                   P                              (CPF_Parm)
// class AGamePlayerCamera*       CameraActor                    (CPF_Parm)
// float                          DeltaTime                      (CPF_Parm)
// struct FTViewTarget            OutVT                          (CPF_Parm | CPF_OutParm)

void UGameCameraBase::UpdateCamera(class APawn* P, class AGamePlayerCamera* CameraActor, float DeltaTime, struct FTViewTarget& outOutVT)
{
	static UFunction* uFnUpdateCamera = nullptr;

	if (!uFnUpdateCamera)
	{
		uFnUpdateCamera = UFunction::FindFunction("Function GameFramework.GameCameraBase.UpdateCamera");
	}

	UGameCameraBase_execUpdateCamera_Params UpdateCamera_Params;
	memset(&UpdateCamera_Params, 0, sizeof(UpdateCamera_Params));

	if (!uFnUpdateCamera)
	{
		return;
	}
	UpdateCamera_Params.P = P;
	UpdateCamera_Params.CameraActor = CameraActor;
	UpdateCamera_Params.DeltaTime = DeltaTime;
	memcpy_s(&UpdateCamera_Params.OutVT, sizeof(UpdateCamera_Params.OutVT), &outOutVT, sizeof(outOutVT));

	this->ProcessEvent(uFnUpdateCamera, &UpdateCamera_Params, nullptr);

	memcpy_s(&outOutVT, sizeof(outOutVT), &UpdateCamera_Params.OutVT, sizeof(UpdateCamera_Params.OutVT));
}

// Function GameFramework.GameCameraBase.ResetInterpolation
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:

void UGameCameraBase::ResetInterpolation()
{
	static UFunction* uFnResetInterpolation = nullptr;

	if (!uFnResetInterpolation)
	{
		uFnResetInterpolation = UFunction::FindFunction("Function GameFramework.GameCameraBase.ResetInterpolation");
	}

	UGameCameraBase_execResetInterpolation_Params ResetInterpolation_Params;
	memset(&ResetInterpolation_Params, 0, sizeof(ResetInterpolation_Params));

	if (!uFnResetInterpolation)
	{
		return;
	}

	this->ProcessEvent(uFnResetInterpolation, &ResetInterpolation_Params, nullptr);
}

// Function GameFramework.GameCameraBase.OnBecomeInActive
// [0x00020000] (FUNC_Public)
// Parameter Info:
// class UGameCameraBase*         NewCamera                      (CPF_Parm)

void UGameCameraBase::OnBecomeInActive(class UGameCameraBase* NewCamera)
{
	static UFunction* uFnOnBecomeInActive = nullptr;

	if (!uFnOnBecomeInActive)
	{
		uFnOnBecomeInActive = UFunction::FindFunction("Function GameFramework.GameCameraBase.OnBecomeInActive");
	}

	UGameCameraBase_execOnBecomeInActive_Params OnBecomeInActive_Params;
	memset(&OnBecomeInActive_Params, 0, sizeof(OnBecomeInActive_Params));

	if (!uFnOnBecomeInActive)
	{
		return;
	}
	OnBecomeInActive_Params.NewCamera = NewCamera;

	this->ProcessEvent(uFnOnBecomeInActive, &OnBecomeInActive_Params, nullptr);
}

// Function GameFramework.GameCameraBase.OnBecomeActive
// [0x00020000] (FUNC_Public)
// Parameter Info:
// class UGameCameraBase*         OldCamera                      (CPF_Parm)

void UGameCameraBase::OnBecomeActive(class UGameCameraBase* OldCamera)
{
	static UFunction* uFnOnBecomeActive = nullptr;

	if (!uFnOnBecomeActive)
	{
		uFnOnBecomeActive = UFunction::FindFunction("Function GameFramework.GameCameraBase.OnBecomeActive");
	}

	UGameCameraBase_execOnBecomeActive_Params OnBecomeActive_Params;
	memset(&OnBecomeActive_Params, 0, sizeof(OnBecomeActive_Params));

	if (!uFnOnBecomeActive)
	{
		return;
	}
	OnBecomeActive_Params.OldCamera = OldCamera;

	this->ProcessEvent(uFnOnBecomeActive, &OnBecomeActive_Params, nullptr);
}

// Function GameFramework.GameThirdPersonCamera.ResetInterpolation
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:

void UGameThirdPersonCamera::ResetInterpolation()
{
	static UFunction* uFnResetInterpolation = nullptr;

	if (!uFnResetInterpolation)
	{
		uFnResetInterpolation = UFunction::FindFunction("Function GameFramework.GameThirdPersonCamera.ResetInterpolation");
	}

	UGameThirdPersonCamera_execResetInterpolation_Params ResetInterpolation_Params;
	memset(&ResetInterpolation_Params, 0, sizeof(ResetInterpolation_Params));

	if (!uFnResetInterpolation)
	{
		return;
	}

	this->ProcessEvent(uFnResetInterpolation, &ResetInterpolation_Params, nullptr);
}

// Function GameFramework.GameThirdPersonCamera.ModifyPostProcessSettings
// [0x00420802] (FUNC_Defined | FUNC_Event | FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// struct FPostProcessSettings    PP                             (CPF_Parm | CPF_OutParm)

void UGameThirdPersonCamera::eventModifyPostProcessSettings(struct FPostProcessSettings& outPP)
{
	static UFunction* uFnModifyPostProcessSettings = nullptr;

	if (!uFnModifyPostProcessSettings)
	{
		uFnModifyPostProcessSettings = UFunction::FindFunction("Function GameFramework.GameThirdPersonCamera.ModifyPostProcessSettings");
	}

	UGameThirdPersonCamera_eventModifyPostProcessSettings_Params ModifyPostProcessSettings_Params;
	memset(&ModifyPostProcessSettings_Params, 0, sizeof(ModifyPostProcessSettings_Params));

	if (!uFnModifyPostProcessSettings)
	{
		return;
	}
	memcpy_s(&ModifyPostProcessSettings_Params.PP, sizeof(ModifyPostProcessSettings_Params.PP), &outPP, sizeof(outPP));

	this->ProcessEvent(uFnModifyPostProcessSettings, &ModifyPostProcessSettings_Params, nullptr);

	memcpy_s(&outPP, sizeof(outPP), &ModifyPostProcessSettings_Params.PP, sizeof(ModifyPostProcessSettings_Params.PP));
}

// Function GameFramework.GameThirdPersonCamera.OnBecomeActive
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class UGameCameraBase*         OldCamera                      (CPF_Parm)

void UGameThirdPersonCamera::OnBecomeActive(class UGameCameraBase* OldCamera)
{
	static UFunction* uFnOnBecomeActive = nullptr;

	if (!uFnOnBecomeActive)
	{
		uFnOnBecomeActive = UFunction::FindFunction("Function GameFramework.GameThirdPersonCamera.OnBecomeActive");
	}

	UGameThirdPersonCamera_execOnBecomeActive_Params OnBecomeActive_Params;
	memset(&OnBecomeActive_Params, 0, sizeof(OnBecomeActive_Params));

	if (!uFnOnBecomeActive)
	{
		return;
	}
	OnBecomeActive_Params.OldCamera = OldCamera;

	this->ProcessEvent(uFnOnBecomeActive, &OnBecomeActive_Params, nullptr);
}

// Function GameFramework.GameThirdPersonCamera.ProcessViewRotation
// [0x00420002] (FUNC_Defined | FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// float                          DeltaTime                      (CPF_Parm)
// class AActor*                  ViewTarget                     (CPF_Parm)
// struct FRotator                out_ViewRotation               (CPF_Parm | CPF_OutParm)
// struct FRotator                out_DeltaRot                   (CPF_Parm | CPF_OutParm)

void UGameThirdPersonCamera::ProcessViewRotation(float DeltaTime, class AActor* ViewTarget, struct FRotator& outOut_ViewRotation, struct FRotator& outOut_DeltaRot)
{
	static UFunction* uFnProcessViewRotation = nullptr;

	if (!uFnProcessViewRotation)
	{
		uFnProcessViewRotation = UFunction::FindFunction("Function GameFramework.GameThirdPersonCamera.ProcessViewRotation");
	}

	UGameThirdPersonCamera_execProcessViewRotation_Params ProcessViewRotation_Params;
	memset(&ProcessViewRotation_Params, 0, sizeof(ProcessViewRotation_Params));

	if (!uFnProcessViewRotation)
	{
		return;
	}
	ProcessViewRotation_Params.DeltaTime = DeltaTime;
	ProcessViewRotation_Params.ViewTarget = ViewTarget;
	memcpy_s(&ProcessViewRotation_Params.out_ViewRotation, sizeof(ProcessViewRotation_Params.out_ViewRotation), &outOut_ViewRotation, sizeof(outOut_ViewRotation));
	memcpy_s(&ProcessViewRotation_Params.out_DeltaRot, sizeof(ProcessViewRotation_Params.out_DeltaRot), &outOut_DeltaRot, sizeof(outOut_DeltaRot));

	this->ProcessEvent(uFnProcessViewRotation, &ProcessViewRotation_Params, nullptr);

	memcpy_s(&outOut_ViewRotation, sizeof(outOut_ViewRotation), &ProcessViewRotation_Params.out_ViewRotation, sizeof(ProcessViewRotation_Params.out_ViewRotation));
	memcpy_s(&outOut_DeltaRot, sizeof(outOut_DeltaRot), &ProcessViewRotation_Params.out_DeltaRot, sizeof(ProcessViewRotation_Params.out_DeltaRot));
}

// Function GameFramework.GameThirdPersonCamera.UpdateCameraMode
// [0x00080003] (FUNC_Final | FUNC_Defined | FUNC_Protected)
// Parameter Info:
// class APawn*                   P                              (CPF_Parm)

void UGameThirdPersonCamera::UpdateCameraMode(class APawn* P)
{
	static UFunction* uFnUpdateCameraMode = nullptr;

	if (!uFnUpdateCameraMode)
	{
		uFnUpdateCameraMode = UFunction::FindFunction("Function GameFramework.GameThirdPersonCamera.UpdateCameraMode");
	}

	UGameThirdPersonCamera_execUpdateCameraMode_Params UpdateCameraMode_Params;
	memset(&UpdateCameraMode_Params, 0, sizeof(UpdateCameraMode_Params));

	if (!uFnUpdateCameraMode)
	{
		return;
	}
	UpdateCameraMode_Params.P = P;

	this->ProcessEvent(uFnUpdateCameraMode, &UpdateCameraMode_Params, nullptr);
}

// Function GameFramework.GameThirdPersonCamera.FindBestCameraMode
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class UGameThirdPersonCameraMode* ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class APawn*                   P                              (CPF_Parm)

class UGameThirdPersonCameraMode* UGameThirdPersonCamera::FindBestCameraMode(class APawn* P)
{
	static UFunction* uFnFindBestCameraMode = nullptr;

	if (!uFnFindBestCameraMode)
	{
		uFnFindBestCameraMode = UFunction::FindFunction("Function GameFramework.GameThirdPersonCamera.FindBestCameraMode");
	}

	UGameThirdPersonCamera_execFindBestCameraMode_Params FindBestCameraMode_Params;
	memset(&FindBestCameraMode_Params, 0, sizeof(FindBestCameraMode_Params));

	if (!uFnFindBestCameraMode)
	{
		return FindBestCameraMode_Params.ReturnValue;
	}
	FindBestCameraMode_Params.P = P;

	this->ProcessEvent(uFnFindBestCameraMode, &FindBestCameraMode_Params, nullptr);

	return FindBestCameraMode_Params.ReturnValue;
}

// Function GameFramework.GameThirdPersonCamera.AdjustFocusPointInterpolation
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// struct FRotator                Delta                          (CPF_Parm)

void UGameThirdPersonCamera::AdjustFocusPointInterpolation(const struct FRotator& Delta)
{
	static UFunction* uFnAdjustFocusPointInterpolation = nullptr;

	if (!uFnAdjustFocusPointInterpolation)
	{
		uFnAdjustFocusPointInterpolation = UFunction::FindFunction("Function GameFramework.GameThirdPersonCamera.AdjustFocusPointInterpolation");
	}

	UGameThirdPersonCamera_execAdjustFocusPointInterpolation_Params AdjustFocusPointInterpolation_Params;
	memset(&AdjustFocusPointInterpolation_Params, 0, sizeof(AdjustFocusPointInterpolation_Params));

	if (!uFnAdjustFocusPointInterpolation)
	{
		return;
	}
	memcpy_s(&AdjustFocusPointInterpolation_Params.Delta, sizeof(AdjustFocusPointInterpolation_Params.Delta), &Delta, sizeof(Delta));

	this->ProcessEvent(uFnAdjustFocusPointInterpolation, &AdjustFocusPointInterpolation_Params, nullptr);
}

// Function GameFramework.GameThirdPersonCamera.GetActualFocusLocation
// [0x00820002] (FUNC_Defined | FUNC_Public | FUNC_HasDefaults)
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

struct FVector UGameThirdPersonCamera::GetActualFocusLocation()
{
	static UFunction* uFnGetActualFocusLocation = nullptr;

	if (!uFnGetActualFocusLocation)
	{
		uFnGetActualFocusLocation = UFunction::FindFunction("Function GameFramework.GameThirdPersonCamera.GetActualFocusLocation");
	}

	UGameThirdPersonCamera_execGetActualFocusLocation_Params GetActualFocusLocation_Params;
	memset(&GetActualFocusLocation_Params, 0, sizeof(GetActualFocusLocation_Params));

	if (!uFnGetActualFocusLocation)
	{
		return GetActualFocusLocation_Params.ReturnValue;
	}

	this->ProcessEvent(uFnGetActualFocusLocation, &GetActualFocusLocation_Params, nullptr);

	return GetActualFocusLocation_Params.ReturnValue;
}

// Function GameFramework.GameThirdPersonCamera.UpdateFocusPoint
// [0x00080802] (FUNC_Defined | FUNC_Event | FUNC_Protected)
// Parameter Info:
// class APawn*                   P                              (CPF_Parm)

void UGameThirdPersonCamera::eventUpdateFocusPoint(class APawn* P)
{
	static UFunction* uFnUpdateFocusPoint = nullptr;

	if (!uFnUpdateFocusPoint)
	{
		uFnUpdateFocusPoint = UFunction::FindFunction("Function GameFramework.GameThirdPersonCamera.UpdateFocusPoint");
	}

	UGameThirdPersonCamera_eventUpdateFocusPoint_Params UpdateFocusPoint_Params;
	memset(&UpdateFocusPoint_Params, 0, sizeof(UpdateFocusPoint_Params));

	if (!uFnUpdateFocusPoint)
	{
		return;
	}
	UpdateFocusPoint_Params.P = P;

	this->ProcessEvent(uFnUpdateFocusPoint, &UpdateFocusPoint_Params, nullptr);
}

// Function GameFramework.GameThirdPersonCamera.ClearFocusPoint
// [0x00024002] (FUNC_Defined | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// uint32_t                       bLeaveCameraRotation           (CPF_OptionalParm | CPF_Parm)

void UGameThirdPersonCamera::ClearFocusPoint(bool optionalBLeaveCameraRotation)
{
	static UFunction* uFnClearFocusPoint = nullptr;

	if (!uFnClearFocusPoint)
	{
		uFnClearFocusPoint = UFunction::FindFunction("Function GameFramework.GameThirdPersonCamera.ClearFocusPoint");
	}

	UGameThirdPersonCamera_execClearFocusPoint_Params ClearFocusPoint_Params;
	memset(&ClearFocusPoint_Params, 0, sizeof(ClearFocusPoint_Params));

	if (!uFnClearFocusPoint)
	{
		return;
	}
	ClearFocusPoint_Params.bLeaveCameraRotation = optionalBLeaveCameraRotation;

	this->ProcessEvent(uFnClearFocusPoint, &ClearFocusPoint_Params, nullptr);
}

// Function GameFramework.GameThirdPersonCamera.GetFocusActor
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class AActor*                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

class AActor* UGameThirdPersonCamera::GetFocusActor()
{
	static UFunction* uFnGetFocusActor = nullptr;

	if (!uFnGetFocusActor)
	{
		uFnGetFocusActor = UFunction::FindFunction("Function GameFramework.GameThirdPersonCamera.GetFocusActor");
	}

	UGameThirdPersonCamera_execGetFocusActor_Params GetFocusActor_Params;
	memset(&GetFocusActor_Params, 0, sizeof(GetFocusActor_Params));

	if (!uFnGetFocusActor)
	{
		return GetFocusActor_Params.ReturnValue;
	}

	this->ProcessEvent(uFnGetFocusActor, &GetFocusActor_Params, nullptr);

	return GetFocusActor_Params.ReturnValue;
}

// Function GameFramework.GameThirdPersonCamera.SetFocusOnActor
// [0x00024002] (FUNC_Defined | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// class AActor*                  FocusActor                     (CPF_Parm)
// class FName                    FocusBoneName                  (CPF_Parm)
// struct FVector2D               InterpSpeedRange               (CPF_Parm)
// struct FVector2D               InFocusFOV                     (CPF_Parm)
// float                          CameraFOV                      (CPF_OptionalParm | CPF_Parm)
// uint32_t                       bAlwaysFocus                   (CPF_OptionalParm | CPF_Parm)
// uint32_t                       bAdjustCamera                  (CPF_OptionalParm | CPF_Parm)
// uint32_t                       bIgnoreTrace                   (CPF_OptionalParm | CPF_Parm)
// float                          FocusPitchOffsetDeg            (CPF_OptionalParm | CPF_Parm)

void UGameThirdPersonCamera::SetFocusOnActor(class AActor* FocusActor, const class FName& FocusBoneName, const struct FVector2D& InterpSpeedRange, const struct FVector2D& InFocusFOV, float optionalCameraFOV, bool optionalBAlwaysFocus, bool optionalBAdjustCamera, bool optionalBIgnoreTrace, float optionalFocusPitchOffsetDeg)
{
	static UFunction* uFnSetFocusOnActor = nullptr;

	if (!uFnSetFocusOnActor)
	{
		uFnSetFocusOnActor = UFunction::FindFunction("Function GameFramework.GameThirdPersonCamera.SetFocusOnActor");
	}

	UGameThirdPersonCamera_execSetFocusOnActor_Params SetFocusOnActor_Params;
	memset(&SetFocusOnActor_Params, 0, sizeof(SetFocusOnActor_Params));

	if (!uFnSetFocusOnActor)
	{
		return;
	}
	SetFocusOnActor_Params.FocusActor = FocusActor;
	memcpy_s(&SetFocusOnActor_Params.FocusBoneName, sizeof(SetFocusOnActor_Params.FocusBoneName), &FocusBoneName, sizeof(FocusBoneName));
	memcpy_s(&SetFocusOnActor_Params.InterpSpeedRange, sizeof(SetFocusOnActor_Params.InterpSpeedRange), &InterpSpeedRange, sizeof(InterpSpeedRange));
	memcpy_s(&SetFocusOnActor_Params.InFocusFOV, sizeof(SetFocusOnActor_Params.InFocusFOV), &InFocusFOV, sizeof(InFocusFOV));
	SetFocusOnActor_Params.CameraFOV = optionalCameraFOV;
	SetFocusOnActor_Params.bAlwaysFocus = optionalBAlwaysFocus;
	SetFocusOnActor_Params.bAdjustCamera = optionalBAdjustCamera;
	SetFocusOnActor_Params.bIgnoreTrace = optionalBIgnoreTrace;
	SetFocusOnActor_Params.FocusPitchOffsetDeg = optionalFocusPitchOffsetDeg;

	this->ProcessEvent(uFnSetFocusOnActor, &SetFocusOnActor_Params, nullptr);
}

// Function GameFramework.GameThirdPersonCamera.SetFocusOnLoc
// [0x00024002] (FUNC_Defined | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// struct FVector                 FocusWorldLoc                  (CPF_Parm)
// struct FVector2D               InterpSpeedRange               (CPF_Parm)
// struct FVector2D               InFocusFOV                     (CPF_Parm)
// float                          CameraFOV                      (CPF_OptionalParm | CPF_Parm)
// uint32_t                       bAlwaysFocus                   (CPF_OptionalParm | CPF_Parm)
// uint32_t                       bAdjustCamera                  (CPF_OptionalParm | CPF_Parm)
// uint32_t                       bIgnoreTrace                   (CPF_OptionalParm | CPF_Parm)
// float                          FocusPitchOffsetDeg            (CPF_OptionalParm | CPF_Parm)

void UGameThirdPersonCamera::SetFocusOnLoc(const struct FVector& FocusWorldLoc, const struct FVector2D& InterpSpeedRange, const struct FVector2D& InFocusFOV, float optionalCameraFOV, bool optionalBAlwaysFocus, bool optionalBAdjustCamera, bool optionalBIgnoreTrace, float optionalFocusPitchOffsetDeg)
{
	static UFunction* uFnSetFocusOnLoc = nullptr;

	if (!uFnSetFocusOnLoc)
	{
		uFnSetFocusOnLoc = UFunction::FindFunction("Function GameFramework.GameThirdPersonCamera.SetFocusOnLoc");
	}

	UGameThirdPersonCamera_execSetFocusOnLoc_Params SetFocusOnLoc_Params;
	memset(&SetFocusOnLoc_Params, 0, sizeof(SetFocusOnLoc_Params));

	if (!uFnSetFocusOnLoc)
	{
		return;
	}
	memcpy_s(&SetFocusOnLoc_Params.FocusWorldLoc, sizeof(SetFocusOnLoc_Params.FocusWorldLoc), &FocusWorldLoc, sizeof(FocusWorldLoc));
	memcpy_s(&SetFocusOnLoc_Params.InterpSpeedRange, sizeof(SetFocusOnLoc_Params.InterpSpeedRange), &InterpSpeedRange, sizeof(InterpSpeedRange));
	memcpy_s(&SetFocusOnLoc_Params.InFocusFOV, sizeof(SetFocusOnLoc_Params.InFocusFOV), &InFocusFOV, sizeof(InFocusFOV));
	SetFocusOnLoc_Params.CameraFOV = optionalCameraFOV;
	SetFocusOnLoc_Params.bAlwaysFocus = optionalBAlwaysFocus;
	SetFocusOnLoc_Params.bAdjustCamera = optionalBAdjustCamera;
	SetFocusOnLoc_Params.bIgnoreTrace = optionalBIgnoreTrace;
	SetFocusOnLoc_Params.FocusPitchOffsetDeg = optionalFocusPitchOffsetDeg;

	this->ProcessEvent(uFnSetFocusOnLoc, &SetFocusOnLoc_Params, nullptr);
}

// Function GameFramework.GameThirdPersonCamera.AdjustTurn
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// int32_t                        AngleOffset                    (CPF_Parm)

void UGameThirdPersonCamera::AdjustTurn(int32_t AngleOffset)
{
	static UFunction* uFnAdjustTurn = nullptr;

	if (!uFnAdjustTurn)
	{
		uFnAdjustTurn = UFunction::FindFunction("Function GameFramework.GameThirdPersonCamera.AdjustTurn");
	}

	UGameThirdPersonCamera_execAdjustTurn_Params AdjustTurn_Params;
	memset(&AdjustTurn_Params, 0, sizeof(AdjustTurn_Params));

	if (!uFnAdjustTurn)
	{
		return;
	}
	AdjustTurn_Params.AngleOffset = AngleOffset;

	this->ProcessEvent(uFnAdjustTurn, &AdjustTurn_Params, nullptr);
}

// Function GameFramework.GameThirdPersonCamera.EndTurn
// [0x00020400] (FUNC_Native | FUNC_Public)
// Parameter Info:

void UGameThirdPersonCamera::EndTurn()
{
	static UFunction* uFnEndTurn = nullptr;

	if (!uFnEndTurn)
	{
		uFnEndTurn = UFunction::FindFunction("Function GameFramework.GameThirdPersonCamera.EndTurn");
	}

	UGameThirdPersonCamera_execEndTurn_Params EndTurn_Params;
	memset(&EndTurn_Params, 0, sizeof(EndTurn_Params));

	if (!uFnEndTurn)
	{
		return;
	}

	uint16_t nativeIndex = uFnEndTurn->iNative;
	uFnEndTurn->iNative = 0;
	this->ProcessEvent(uFnEndTurn, &EndTurn_Params, nullptr);
	uFnEndTurn->iNative = nativeIndex;
}

// Function GameFramework.GameThirdPersonCamera.BeginTurn
// [0x00024002] (FUNC_Defined | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// int32_t                        StartAngle                     (CPF_Parm)
// int32_t                        EndAngle                       (CPF_Parm)
// float                          TimeSec                        (CPF_Parm)
// float                          DelaySec                       (CPF_OptionalParm | CPF_Parm)
// uint32_t                       bAlignTargetWhenFinished       (CPF_OptionalParm | CPF_Parm)

void UGameThirdPersonCamera::BeginTurn(int32_t StartAngle, int32_t EndAngle, float TimeSec, float optionalDelaySec, bool optionalBAlignTargetWhenFinished)
{
	static UFunction* uFnBeginTurn = nullptr;

	if (!uFnBeginTurn)
	{
		uFnBeginTurn = UFunction::FindFunction("Function GameFramework.GameThirdPersonCamera.BeginTurn");
	}

	UGameThirdPersonCamera_execBeginTurn_Params BeginTurn_Params;
	memset(&BeginTurn_Params, 0, sizeof(BeginTurn_Params));

	if (!uFnBeginTurn)
	{
		return;
	}
	BeginTurn_Params.StartAngle = StartAngle;
	BeginTurn_Params.EndAngle = EndAngle;
	BeginTurn_Params.TimeSec = TimeSec;
	BeginTurn_Params.DelaySec = optionalDelaySec;
	BeginTurn_Params.bAlignTargetWhenFinished = optionalBAlignTargetWhenFinished;

	this->ProcessEvent(uFnBeginTurn, &BeginTurn_Params, nullptr);
}

// Function GameFramework.GameThirdPersonCamera.PlayerUpdateCamera
// [0x00480400] (FUNC_Native | FUNC_Protected | FUNC_HasOutParms)
// Parameter Info:
// class APawn*                   P                              (CPF_Parm)
// class AGamePlayerCamera*       CameraActor                    (CPF_Parm)
// float                          DeltaTime                      (CPF_Parm)
// struct FTViewTarget            OutVT                          (CPF_Parm | CPF_OutParm)

void UGameThirdPersonCamera::PlayerUpdateCamera(class APawn* P, class AGamePlayerCamera* CameraActor, float DeltaTime, struct FTViewTarget& outOutVT)
{
	static UFunction* uFnPlayerUpdateCamera = nullptr;

	if (!uFnPlayerUpdateCamera)
	{
		uFnPlayerUpdateCamera = UFunction::FindFunction("Function GameFramework.GameThirdPersonCamera.PlayerUpdateCamera");
	}

	UGameThirdPersonCamera_execPlayerUpdateCamera_Params PlayerUpdateCamera_Params;
	memset(&PlayerUpdateCamera_Params, 0, sizeof(PlayerUpdateCamera_Params));

	if (!uFnPlayerUpdateCamera)
	{
		return;
	}
	PlayerUpdateCamera_Params.P = P;
	PlayerUpdateCamera_Params.CameraActor = CameraActor;
	PlayerUpdateCamera_Params.DeltaTime = DeltaTime;
	memcpy_s(&PlayerUpdateCamera_Params.OutVT, sizeof(PlayerUpdateCamera_Params.OutVT), &outOutVT, sizeof(outOutVT));

	uint16_t nativeIndex = uFnPlayerUpdateCamera->iNative;
	uFnPlayerUpdateCamera->iNative = 0;
	this->ProcessEvent(uFnPlayerUpdateCamera, &PlayerUpdateCamera_Params, nullptr);
	uFnPlayerUpdateCamera->iNative = nativeIndex;

	memcpy_s(&outOutVT, sizeof(outOutVT), &PlayerUpdateCamera_Params.OutVT, sizeof(PlayerUpdateCamera_Params.OutVT));
}

// Function GameFramework.GameThirdPersonCamera.UpdateCamera
// [0x00420002] (FUNC_Defined | FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// class APawn*                   P                              (CPF_Parm)
// class AGamePlayerCamera*       CameraActor                    (CPF_Parm)
// float                          DeltaTime                      (CPF_Parm)
// struct FTViewTarget            OutVT                          (CPF_Parm | CPF_OutParm)

void UGameThirdPersonCamera::UpdateCamera(class APawn* P, class AGamePlayerCamera* CameraActor, float DeltaTime, struct FTViewTarget& outOutVT)
{
	static UFunction* uFnUpdateCamera = nullptr;

	if (!uFnUpdateCamera)
	{
		uFnUpdateCamera = UFunction::FindFunction("Function GameFramework.GameThirdPersonCamera.UpdateCamera");
	}

	UGameThirdPersonCamera_execUpdateCamera_Params UpdateCamera_Params;
	memset(&UpdateCamera_Params, 0, sizeof(UpdateCamera_Params));

	if (!uFnUpdateCamera)
	{
		return;
	}
	UpdateCamera_Params.P = P;
	UpdateCamera_Params.CameraActor = CameraActor;
	UpdateCamera_Params.DeltaTime = DeltaTime;
	memcpy_s(&UpdateCamera_Params.OutVT, sizeof(UpdateCamera_Params.OutVT), &outOutVT, sizeof(outOutVT));

	this->ProcessEvent(uFnUpdateCamera, &UpdateCamera_Params, nullptr);

	memcpy_s(&outOutVT, sizeof(outOutVT), &UpdateCamera_Params.OutVT, sizeof(UpdateCamera_Params.OutVT));
}

// Function GameFramework.GameThirdPersonCamera.GetDesiredFOV
// [0x00020802] (FUNC_Defined | FUNC_Event | FUNC_Public)
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class APawn*                   ViewedPawn                     (CPF_Parm)

float UGameThirdPersonCamera::eventGetDesiredFOV(class APawn* ViewedPawn)
{
	static UFunction* uFnGetDesiredFOV = nullptr;

	if (!uFnGetDesiredFOV)
	{
		uFnGetDesiredFOV = UFunction::FindFunction("Function GameFramework.GameThirdPersonCamera.GetDesiredFOV");
	}

	UGameThirdPersonCamera_eventGetDesiredFOV_Params GetDesiredFOV_Params;
	memset(&GetDesiredFOV_Params, 0, sizeof(GetDesiredFOV_Params));

	if (!uFnGetDesiredFOV)
	{
		return GetDesiredFOV_Params.ReturnValue;
	}
	GetDesiredFOV_Params.ViewedPawn = ViewedPawn;

	this->ProcessEvent(uFnGetDesiredFOV, &GetDesiredFOV_Params, nullptr);

	return GetDesiredFOV_Params.ReturnValue;
}

// Function GameFramework.GameThirdPersonCamera.Init
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:

void UGameThirdPersonCamera::Init()
{
	static UFunction* uFnInit = nullptr;

	if (!uFnInit)
	{
		uFnInit = UFunction::FindFunction("Function GameFramework.GameThirdPersonCamera.Init");
	}

	UGameThirdPersonCamera_execInit_Params Init_Params;
	memset(&Init_Params, 0, sizeof(Init_Params));

	if (!uFnInit)
	{
		return;
	}

	this->ProcessEvent(uFnInit, &Init_Params, nullptr);
}

// Function GameFramework.GameThirdPersonCamera.Reset
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:

void UGameThirdPersonCamera::Reset()
{
	static UFunction* uFnReset = nullptr;

	if (!uFnReset)
	{
		uFnReset = UFunction::FindFunction("Function GameFramework.GameThirdPersonCamera.Reset");
	}

	UGameThirdPersonCamera_execReset_Params Reset_Params;
	memset(&Reset_Params, 0, sizeof(Reset_Params));

	if (!uFnReset)
	{
		return;
	}

	this->ProcessEvent(uFnReset, &Reset_Params, nullptr);
}

// Function GameFramework.GameThirdPersonCamera.CreateCameraMode
// [0x00080002] (FUNC_Defined | FUNC_Protected)
// Parameter Info:
// class UGameThirdPersonCameraMode* ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class UClass*                  ModeClass                      (CPF_Parm)

class UGameThirdPersonCameraMode* UGameThirdPersonCamera::CreateCameraMode(class UClass* ModeClass)
{
	static UFunction* uFnCreateCameraMode = nullptr;

	if (!uFnCreateCameraMode)
	{
		uFnCreateCameraMode = UFunction::FindFunction("Function GameFramework.GameThirdPersonCamera.CreateCameraMode");
	}

	UGameThirdPersonCamera_execCreateCameraMode_Params CreateCameraMode_Params;
	memset(&CreateCameraMode_Params, 0, sizeof(CreateCameraMode_Params));

	if (!uFnCreateCameraMode)
	{
		return CreateCameraMode_Params.ReturnValue;
	}
	CreateCameraMode_Params.ModeClass = ModeClass;

	this->ProcessEvent(uFnCreateCameraMode, &CreateCameraMode_Params, nullptr);

	return CreateCameraMode_Params.ReturnValue;
}

// Function GameFramework.GamePlayerCamera.AdjustFOVForViewport
// [0x00080401] (FUNC_Final | FUNC_Native | FUNC_Protected)
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          inHorizFOV                     (CPF_Parm)
// class APawn*                   CameraTargetPawn               (CPF_Parm)

float AGamePlayerCamera::AdjustFOVForViewport(float inHorizFOV, class APawn* CameraTargetPawn)
{
	static UFunction* uFnAdjustFOVForViewport = nullptr;

	if (!uFnAdjustFOVForViewport)
	{
		uFnAdjustFOVForViewport = UFunction::FindFunction("Function GameFramework.GamePlayerCamera.AdjustFOVForViewport");
	}

	AGamePlayerCamera_execAdjustFOVForViewport_Params AdjustFOVForViewport_Params;
	memset(&AdjustFOVForViewport_Params, 0, sizeof(AdjustFOVForViewport_Params));

	if (!uFnAdjustFOVForViewport)
	{
		return AdjustFOVForViewport_Params.ReturnValue;
	}
	AdjustFOVForViewport_Params.inHorizFOV = inHorizFOV;
	AdjustFOVForViewport_Params.CameraTargetPawn = CameraTargetPawn;

	uint16_t nativeIndex = uFnAdjustFOVForViewport->iNative;
	uFnAdjustFOVForViewport->iNative = 0;
	this->ProcessEvent(uFnAdjustFOVForViewport, &AdjustFOVForViewport_Params, nullptr);
	uFnAdjustFOVForViewport->iNative = nativeIndex;

	return AdjustFOVForViewport_Params.ReturnValue;
}

// Function GameFramework.GamePlayerCamera.GetActualLookatLocation
// [0x00420000] (FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class AActor*                  FocusActor                     (CPF_Parm)
// struct FVector                 FocusLoc                       (CPF_Parm | CPF_OutParm)

bool AGamePlayerCamera::GetActualLookatLocation(class AActor* FocusActor, struct FVector& outFocusLoc)
{
	static UFunction* uFnGetActualLookatLocation = nullptr;

	if (!uFnGetActualLookatLocation)
	{
		uFnGetActualLookatLocation = UFunction::FindFunction("Function GameFramework.GamePlayerCamera.GetActualLookatLocation");
	}

	AGamePlayerCamera_execGetActualLookatLocation_Params GetActualLookatLocation_Params;
	memset(&GetActualLookatLocation_Params, 0, sizeof(GetActualLookatLocation_Params));

	if (!uFnGetActualLookatLocation)
	{
		return GetActualLookatLocation_Params.ReturnValue;
	}
	GetActualLookatLocation_Params.FocusActor = FocusActor;
	memcpy_s(&GetActualLookatLocation_Params.FocusLoc, sizeof(GetActualLookatLocation_Params.FocusLoc), &outFocusLoc, sizeof(outFocusLoc));

	this->ProcessEvent(uFnGetActualLookatLocation, &GetActualLookatLocation_Params, nullptr);

	memcpy_s(&outFocusLoc, sizeof(outFocusLoc), &GetActualLookatLocation_Params.FocusLoc, sizeof(GetActualLookatLocation_Params.FocusLoc));

	return GetActualLookatLocation_Params.ReturnValue;
}

// Function GameFramework.GamePlayerCamera.ClearFocusActor
// [0x00020000] (FUNC_Public)
// Parameter Info:

void AGamePlayerCamera::ClearFocusActor()
{
	static UFunction* uFnClearFocusActor = nullptr;

	if (!uFnClearFocusActor)
	{
		uFnClearFocusActor = UFunction::FindFunction("Function GameFramework.GamePlayerCamera.ClearFocusActor");
	}

	AGamePlayerCamera_execClearFocusActor_Params ClearFocusActor_Params;
	memset(&ClearFocusActor_Params, 0, sizeof(ClearFocusActor_Params));

	if (!uFnClearFocusActor)
	{
		return;
	}

	this->ProcessEvent(uFnClearFocusActor, &ClearFocusActor_Params, nullptr);
}

// Function GameFramework.GamePlayerCamera.ProcessViewRotation
// [0x00420002] (FUNC_Defined | FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// float                          DeltaTime                      (CPF_Parm)
// struct FRotator                out_ViewRotation               (CPF_Parm | CPF_OutParm)
// struct FRotator                out_DeltaRot                   (CPF_Parm | CPF_OutParm)

void AGamePlayerCamera::ProcessViewRotation(float DeltaTime, struct FRotator& outOut_ViewRotation, struct FRotator& outOut_DeltaRot)
{
	static UFunction* uFnProcessViewRotation = nullptr;

	if (!uFnProcessViewRotation)
	{
		uFnProcessViewRotation = UFunction::FindFunction("Function GameFramework.GamePlayerCamera.ProcessViewRotation");
	}

	AGamePlayerCamera_execProcessViewRotation_Params ProcessViewRotation_Params;
	memset(&ProcessViewRotation_Params, 0, sizeof(ProcessViewRotation_Params));

	if (!uFnProcessViewRotation)
	{
		return;
	}
	ProcessViewRotation_Params.DeltaTime = DeltaTime;
	memcpy_s(&ProcessViewRotation_Params.out_ViewRotation, sizeof(ProcessViewRotation_Params.out_ViewRotation), &outOut_ViewRotation, sizeof(outOut_ViewRotation));
	memcpy_s(&ProcessViewRotation_Params.out_DeltaRot, sizeof(ProcessViewRotation_Params.out_DeltaRot), &outOut_DeltaRot, sizeof(outOut_DeltaRot));

	this->ProcessEvent(uFnProcessViewRotation, &ProcessViewRotation_Params, nullptr);

	memcpy_s(&outOut_ViewRotation, sizeof(outOut_ViewRotation), &ProcessViewRotation_Params.out_ViewRotation, sizeof(ProcessViewRotation_Params.out_ViewRotation));
	memcpy_s(&outOut_DeltaRot, sizeof(outOut_DeltaRot), &ProcessViewRotation_Params.out_DeltaRot, sizeof(ProcessViewRotation_Params.out_DeltaRot));
}

// Function GameFramework.GamePlayerCamera.ResetInterpolation
// [0x00020102] (FUNC_Defined | FUNC_Simulated | FUNC_Public)
// Parameter Info:

void AGamePlayerCamera::ResetInterpolation()
{
	static UFunction* uFnResetInterpolation = nullptr;

	if (!uFnResetInterpolation)
	{
		uFnResetInterpolation = UFunction::FindFunction("Function GameFramework.GamePlayerCamera.ResetInterpolation");
	}

	AGamePlayerCamera_execResetInterpolation_Params ResetInterpolation_Params;
	memset(&ResetInterpolation_Params, 0, sizeof(ResetInterpolation_Params));

	if (!uFnResetInterpolation)
	{
		return;
	}

	this->ProcessEvent(uFnResetInterpolation, &ResetInterpolation_Params, nullptr);
}

// Function GameFramework.GamePlayerCamera.SetColorScale
// [0x00020102] (FUNC_Defined | FUNC_Simulated | FUNC_Public)
// Parameter Info:
// struct FVector                 NewColorScale                  (CPF_Parm)

void AGamePlayerCamera::SetColorScale(const struct FVector& NewColorScale)
{
	static UFunction* uFnSetColorScale = nullptr;

	if (!uFnSetColorScale)
	{
		uFnSetColorScale = UFunction::FindFunction("Function GameFramework.GamePlayerCamera.SetColorScale");
	}

	AGamePlayerCamera_execSetColorScale_Params SetColorScale_Params;
	memset(&SetColorScale_Params, 0, sizeof(SetColorScale_Params));

	if (!uFnSetColorScale)
	{
		return;
	}
	memcpy_s(&SetColorScale_Params.NewColorScale, sizeof(SetColorScale_Params.NewColorScale), &NewColorScale, sizeof(NewColorScale));

	this->ProcessEvent(uFnSetColorScale, &SetColorScale_Params, nullptr);
}

// Function GameFramework.GamePlayerCamera.DisplayDebug
// [0x00420102] (FUNC_Defined | FUNC_Simulated | FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// class AHUD*                    HUD                            (CPF_Parm)
// float                          out_YL                         (CPF_Parm | CPF_OutParm)
// float                          out_YPos                       (CPF_Parm | CPF_OutParm)

void AGamePlayerCamera::DisplayDebug(class AHUD* HUD, float& outOut_YL, float& outOut_YPos)
{
	static UFunction* uFnDisplayDebug = nullptr;

	if (!uFnDisplayDebug)
	{
		uFnDisplayDebug = UFunction::FindFunction("Function GameFramework.GamePlayerCamera.DisplayDebug");
	}

	AGamePlayerCamera_execDisplayDebug_Params DisplayDebug_Params;
	memset(&DisplayDebug_Params, 0, sizeof(DisplayDebug_Params));

	if (!uFnDisplayDebug)
	{
		return;
	}
	DisplayDebug_Params.HUD = HUD;
	DisplayDebug_Params.out_YL = outOut_YL;
	DisplayDebug_Params.out_YPos = outOut_YPos;

	this->ProcessEvent(uFnDisplayDebug, &DisplayDebug_Params, nullptr);

	outOut_YL = DisplayDebug_Params.out_YL;
	outOut_YPos = DisplayDebug_Params.out_YPos;
}

// Function GameFramework.GamePlayerCamera.ExecCameraLensEffects
// [0x00420102] (FUNC_Defined | FUNC_Simulated | FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// float                          CamFOVDeg                      (CPF_Parm)
// struct FVector                 CamLoc                         (CPF_Parm | CPF_OutParm)
// struct FRotator                CamRot                         (CPF_Parm | CPF_OutParm)

void AGamePlayerCamera::ExecCameraLensEffects(float CamFOVDeg, struct FVector& outCamLoc, struct FRotator& outCamRot)
{
	static UFunction* uFnExecCameraLensEffects = nullptr;

	if (!uFnExecCameraLensEffects)
	{
		uFnExecCameraLensEffects = UFunction::FindFunction("Function GameFramework.GamePlayerCamera.ExecCameraLensEffects");
	}

	AGamePlayerCamera_execExecCameraLensEffects_Params ExecCameraLensEffects_Params;
	memset(&ExecCameraLensEffects_Params, 0, sizeof(ExecCameraLensEffects_Params));

	if (!uFnExecCameraLensEffects)
	{
		return;
	}
	ExecCameraLensEffects_Params.CamFOVDeg = CamFOVDeg;
	memcpy_s(&ExecCameraLensEffects_Params.CamLoc, sizeof(ExecCameraLensEffects_Params.CamLoc), &outCamLoc, sizeof(outCamLoc));
	memcpy_s(&ExecCameraLensEffects_Params.CamRot, sizeof(ExecCameraLensEffects_Params.CamRot), &outCamRot, sizeof(outCamRot));

	this->ProcessEvent(uFnExecCameraLensEffects, &ExecCameraLensEffects_Params, nullptr);

	memcpy_s(&outCamLoc, sizeof(outCamLoc), &ExecCameraLensEffects_Params.CamLoc, sizeof(ExecCameraLensEffects_Params.CamLoc));
	memcpy_s(&outCamRot, sizeof(outCamRot), &ExecCameraLensEffects_Params.CamRot, sizeof(ExecCameraLensEffects_Params.CamRot));
}

// Function GameFramework.GamePlayerCamera.UpdateCameraLensEffects
// [0x00420102] (FUNC_Defined | FUNC_Simulated | FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// struct FTViewTarget            OutVT                          (CPF_Const | CPF_Parm | CPF_OutParm)

void AGamePlayerCamera::UpdateCameraLensEffects(struct FTViewTarget& outOutVT)
{
	static UFunction* uFnUpdateCameraLensEffects = nullptr;

	if (!uFnUpdateCameraLensEffects)
	{
		uFnUpdateCameraLensEffects = UFunction::FindFunction("Function GameFramework.GamePlayerCamera.UpdateCameraLensEffects");
	}

	AGamePlayerCamera_execUpdateCameraLensEffects_Params UpdateCameraLensEffects_Params;
	memset(&UpdateCameraLensEffects_Params, 0, sizeof(UpdateCameraLensEffects_Params));

	if (!uFnUpdateCameraLensEffects)
	{
		return;
	}
	memcpy_s(&UpdateCameraLensEffects_Params.OutVT, sizeof(UpdateCameraLensEffects_Params.OutVT), &outOutVT, sizeof(outOutVT));

	this->ProcessEvent(uFnUpdateCameraLensEffects, &UpdateCameraLensEffects_Params, nullptr);

	memcpy_s(&outOutVT, sizeof(outOutVT), &UpdateCameraLensEffects_Params.OutVT, sizeof(UpdateCameraLensEffects_Params.OutVT));
}

// Function GameFramework.GamePlayerCamera.UpdateViewTarget
// [0x00420002] (FUNC_Defined | FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// float                          DeltaTime                      (CPF_Parm)
// struct FTViewTarget            OutVT                          (CPF_Parm | CPF_OutParm)

void AGamePlayerCamera::UpdateViewTarget(float DeltaTime, struct FTViewTarget& outOutVT)
{
	static UFunction* uFnUpdateViewTarget = nullptr;

	if (!uFnUpdateViewTarget)
	{
		uFnUpdateViewTarget = UFunction::FindFunction("Function GameFramework.GamePlayerCamera.UpdateViewTarget");
	}

	AGamePlayerCamera_execUpdateViewTarget_Params UpdateViewTarget_Params;
	memset(&UpdateViewTarget_Params, 0, sizeof(UpdateViewTarget_Params));

	if (!uFnUpdateViewTarget)
	{
		return;
	}
	UpdateViewTarget_Params.DeltaTime = DeltaTime;
	memcpy_s(&UpdateViewTarget_Params.OutVT, sizeof(UpdateViewTarget_Params.OutVT), &outOutVT, sizeof(outOutVT));

	this->ProcessEvent(uFnUpdateViewTarget, &UpdateViewTarget_Params, nullptr);

	memcpy_s(&outOutVT, sizeof(outOutVT), &UpdateViewTarget_Params.OutVT, sizeof(UpdateViewTarget_Params.OutVT));
}

// Function GameFramework.GamePlayerCamera.ShouldConstrainAspectRatio
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

bool AGamePlayerCamera::ShouldConstrainAspectRatio()
{
	static UFunction* uFnShouldConstrainAspectRatio = nullptr;

	if (!uFnShouldConstrainAspectRatio)
	{
		uFnShouldConstrainAspectRatio = UFunction::FindFunction("Function GameFramework.GamePlayerCamera.ShouldConstrainAspectRatio");
	}

	AGamePlayerCamera_execShouldConstrainAspectRatio_Params ShouldConstrainAspectRatio_Params;
	memset(&ShouldConstrainAspectRatio_Params, 0, sizeof(ShouldConstrainAspectRatio_Params));

	if (!uFnShouldConstrainAspectRatio)
	{
		return ShouldConstrainAspectRatio_Params.ReturnValue;
	}

	this->ProcessEvent(uFnShouldConstrainAspectRatio, &ShouldConstrainAspectRatio_Params, nullptr);

	return ShouldConstrainAspectRatio_Params.ReturnValue;
}

// Function GameFramework.GamePlayerCamera.FindBestCameraType
// [0x00080002] (FUNC_Defined | FUNC_Protected)
// Parameter Info:
// class UGameCameraBase*         ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class AActor*                  CameraTarget                   (CPF_Parm)

class UGameCameraBase* AGamePlayerCamera::FindBestCameraType(class AActor* CameraTarget)
{
	static UFunction* uFnFindBestCameraType = nullptr;

	if (!uFnFindBestCameraType)
	{
		uFnFindBestCameraType = UFunction::FindFunction("Function GameFramework.GamePlayerCamera.FindBestCameraType");
	}

	AGamePlayerCamera_execFindBestCameraType_Params FindBestCameraType_Params;
	memset(&FindBestCameraType_Params, 0, sizeof(FindBestCameraType_Params));

	if (!uFnFindBestCameraType)
	{
		return FindBestCameraType_Params.ReturnValue;
	}
	FindBestCameraType_Params.CameraTarget = CameraTarget;

	this->ProcessEvent(uFnFindBestCameraType, &FindBestCameraType_Params, nullptr);

	return FindBestCameraType_Params.ReturnValue;
}

// Function GameFramework.GamePlayerCamera.Reset
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:

void AGamePlayerCamera::Reset()
{
	static UFunction* uFnReset = nullptr;

	if (!uFnReset)
	{
		uFnReset = UFunction::FindFunction("Function GameFramework.GamePlayerCamera.Reset");
	}

	AGamePlayerCamera_execReset_Params Reset_Params;
	memset(&Reset_Params, 0, sizeof(Reset_Params));

	if (!uFnReset)
	{
		return;
	}

	this->ProcessEvent(uFnReset, &Reset_Params, nullptr);
}

// Function GameFramework.GamePlayerCamera.PostBeginPlay
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:

void AGamePlayerCamera::PostBeginPlay()
{
	static UFunction* uFnPostBeginPlay = nullptr;

	if (!uFnPostBeginPlay)
	{
		uFnPostBeginPlay = UFunction::FindFunction("Function GameFramework.GamePlayerCamera.PostBeginPlay");
	}

	AGamePlayerCamera_execPostBeginPlay_Params PostBeginPlay_Params;
	memset(&PostBeginPlay_Params, 0, sizeof(PostBeginPlay_Params));

	if (!uFnPostBeginPlay)
	{
		return;
	}

	this->ProcessEvent(uFnPostBeginPlay, &PostBeginPlay_Params, nullptr);
}

// Function GameFramework.GamePlayerCamera.CacheLastTargetBaseInfo
// [0x00080400] (FUNC_Native | FUNC_Protected)
// Parameter Info:
// class AActor*                  TargetBase                     (CPF_Parm)

void AGamePlayerCamera::CacheLastTargetBaseInfo(class AActor* TargetBase)
{
	static UFunction* uFnCacheLastTargetBaseInfo = nullptr;

	if (!uFnCacheLastTargetBaseInfo)
	{
		uFnCacheLastTargetBaseInfo = UFunction::FindFunction("Function GameFramework.GamePlayerCamera.CacheLastTargetBaseInfo");
	}

	AGamePlayerCamera_execCacheLastTargetBaseInfo_Params CacheLastTargetBaseInfo_Params;
	memset(&CacheLastTargetBaseInfo_Params, 0, sizeof(CacheLastTargetBaseInfo_Params));

	if (!uFnCacheLastTargetBaseInfo)
	{
		return;
	}
	CacheLastTargetBaseInfo_Params.TargetBase = TargetBase;

	uint16_t nativeIndex = uFnCacheLastTargetBaseInfo->iNative;
	uFnCacheLastTargetBaseInfo->iNative = 0;
	this->ProcessEvent(uFnCacheLastTargetBaseInfo, &CacheLastTargetBaseInfo_Params, nullptr);
	uFnCacheLastTargetBaseInfo->iNative = nativeIndex;
}

// Function GameFramework.GamePlayerCamera.CreateCamera
// [0x00080002] (FUNC_Defined | FUNC_Protected)
// Parameter Info:
// class UGameCameraBase*         ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class UClass*                  CameraClass                    (CPF_Parm)

class UGameCameraBase* AGamePlayerCamera::CreateCamera(class UClass* CameraClass)
{
	static UFunction* uFnCreateCamera = nullptr;

	if (!uFnCreateCamera)
	{
		uFnCreateCamera = UFunction::FindFunction("Function GameFramework.GamePlayerCamera.CreateCamera");
	}

	AGamePlayerCamera_execCreateCamera_Params CreateCamera_Params;
	memset(&CreateCamera_Params, 0, sizeof(CreateCamera_Params));

	if (!uFnCreateCamera)
	{
		return CreateCamera_Params.ReturnValue;
	}
	CreateCamera_Params.CameraClass = CameraClass;

	this->ProcessEvent(uFnCreateCamera, &CreateCamera_Params, nullptr);

	return CreateCamera_Params.ReturnValue;
}

// Function GameFramework.GameThirdPersonCameraMode.SetViewOffset
// [0x00420401] (FUNC_Final | FUNC_Native | FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// struct FViewOffsetData         NewViewOffset                  (CPF_Const | CPF_Parm | CPF_OutParm)

void UGameThirdPersonCameraMode::SetViewOffset(struct FViewOffsetData& outNewViewOffset)
{
	static UFunction* uFnSetViewOffset = nullptr;

	if (!uFnSetViewOffset)
	{
		uFnSetViewOffset = UFunction::FindFunction("Function GameFramework.GameThirdPersonCameraMode.SetViewOffset");
	}

	UGameThirdPersonCameraMode_execSetViewOffset_Params SetViewOffset_Params;
	memset(&SetViewOffset_Params, 0, sizeof(SetViewOffset_Params));

	if (!uFnSetViewOffset)
	{
		return;
	}
	memcpy_s(&SetViewOffset_Params.NewViewOffset, sizeof(SetViewOffset_Params.NewViewOffset), &outNewViewOffset, sizeof(outNewViewOffset));

	uint16_t nativeIndex = uFnSetViewOffset->iNative;
	uFnSetViewOffset->iNative = 0;
	this->ProcessEvent(uFnSetViewOffset, &SetViewOffset_Params, nullptr);
	uFnSetViewOffset->iNative = nativeIndex;

	memcpy_s(&outNewViewOffset, sizeof(outNewViewOffset), &SetViewOffset_Params.NewViewOffset, sizeof(SetViewOffset_Params.NewViewOffset));
}

// Function GameFramework.GameThirdPersonCameraMode.ModifyPostProcessSettings
// [0x00420102] (FUNC_Defined | FUNC_Simulated | FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// struct FPostProcessSettings    PP                             (CPF_Parm | CPF_OutParm)

void UGameThirdPersonCameraMode::ModifyPostProcessSettings(struct FPostProcessSettings& outPP)
{
	static UFunction* uFnModifyPostProcessSettings = nullptr;

	if (!uFnModifyPostProcessSettings)
	{
		uFnModifyPostProcessSettings = UFunction::FindFunction("Function GameFramework.GameThirdPersonCameraMode.ModifyPostProcessSettings");
	}

	UGameThirdPersonCameraMode_execModifyPostProcessSettings_Params ModifyPostProcessSettings_Params;
	memset(&ModifyPostProcessSettings_Params, 0, sizeof(ModifyPostProcessSettings_Params));

	if (!uFnModifyPostProcessSettings)
	{
		return;
	}
	memcpy_s(&ModifyPostProcessSettings_Params.PP, sizeof(ModifyPostProcessSettings_Params.PP), &outPP, sizeof(outPP));

	this->ProcessEvent(uFnModifyPostProcessSettings, &ModifyPostProcessSettings_Params, nullptr);

	memcpy_s(&outPP, sizeof(outPP), &ModifyPostProcessSettings_Params.PP, sizeof(ModifyPostProcessSettings_Params.PP));
}

// Function GameFramework.GameThirdPersonCameraMode.UpdatePostProcess
// [0x00C20102] (FUNC_Defined | FUNC_Simulated | FUNC_Public | FUNC_HasOutParms | FUNC_HasDefaults)
// Parameter Info:
// float                          DeltaTime                      (CPF_Parm)
// struct FTViewTarget            VT                             (CPF_Const | CPF_Parm | CPF_OutParm)

void UGameThirdPersonCameraMode::UpdatePostProcess(float DeltaTime, struct FTViewTarget& outVT)
{
	static UFunction* uFnUpdatePostProcess = nullptr;

	if (!uFnUpdatePostProcess)
	{
		uFnUpdatePostProcess = UFunction::FindFunction("Function GameFramework.GameThirdPersonCameraMode.UpdatePostProcess");
	}

	UGameThirdPersonCameraMode_execUpdatePostProcess_Params UpdatePostProcess_Params;
	memset(&UpdatePostProcess_Params, 0, sizeof(UpdatePostProcess_Params));

	if (!uFnUpdatePostProcess)
	{
		return;
	}
	UpdatePostProcess_Params.DeltaTime = DeltaTime;
	memcpy_s(&UpdatePostProcess_Params.VT, sizeof(UpdatePostProcess_Params.VT), &outVT, sizeof(outVT));

	this->ProcessEvent(uFnUpdatePostProcess, &UpdatePostProcess_Params, nullptr);

	memcpy_s(&outVT, sizeof(outVT), &UpdatePostProcess_Params.VT, sizeof(UpdatePostProcess_Params.VT));
}

// Function GameFramework.GameThirdPersonCameraMode.DOFTrace
// [0x00880102] (FUNC_Defined | FUNC_Simulated | FUNC_Protected | FUNC_HasDefaults)
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class AActor*                  TraceOwner                     (CPF_Parm)
// struct FVector                 StartTrace                     (CPF_Parm)
// struct FVector                 EndTrace                       (CPF_Parm)

struct FVector UGameThirdPersonCameraMode::DOFTrace(class AActor* TraceOwner, const struct FVector& StartTrace, const struct FVector& EndTrace)
{
	static UFunction* uFnDOFTrace = nullptr;

	if (!uFnDOFTrace)
	{
		uFnDOFTrace = UFunction::FindFunction("Function GameFramework.GameThirdPersonCameraMode.DOFTrace");
	}

	UGameThirdPersonCameraMode_execDOFTrace_Params DOFTrace_Params;
	memset(&DOFTrace_Params, 0, sizeof(DOFTrace_Params));

	if (!uFnDOFTrace)
	{
		return DOFTrace_Params.ReturnValue;
	}
	DOFTrace_Params.TraceOwner = TraceOwner;
	memcpy_s(&DOFTrace_Params.StartTrace, sizeof(DOFTrace_Params.StartTrace), &StartTrace, sizeof(StartTrace));
	memcpy_s(&DOFTrace_Params.EndTrace, sizeof(DOFTrace_Params.EndTrace), &EndTrace, sizeof(EndTrace));

	this->ProcessEvent(uFnDOFTrace, &DOFTrace_Params, nullptr);

	return DOFTrace_Params.ReturnValue;
}

// Function GameFramework.GameThirdPersonCameraMode.GetDOFFocusLoc
// [0x00080102] (FUNC_Defined | FUNC_Simulated | FUNC_Protected)
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class AActor*                  TraceOwner                     (CPF_Parm)
// struct FVector                 StartTrace                     (CPF_Parm)
// struct FVector                 EndTrace                       (CPF_Parm)

struct FVector UGameThirdPersonCameraMode::GetDOFFocusLoc(class AActor* TraceOwner, const struct FVector& StartTrace, const struct FVector& EndTrace)
{
	static UFunction* uFnGetDOFFocusLoc = nullptr;

	if (!uFnGetDOFFocusLoc)
	{
		uFnGetDOFFocusLoc = UFunction::FindFunction("Function GameFramework.GameThirdPersonCameraMode.GetDOFFocusLoc");
	}

	UGameThirdPersonCameraMode_execGetDOFFocusLoc_Params GetDOFFocusLoc_Params;
	memset(&GetDOFFocusLoc_Params, 0, sizeof(GetDOFFocusLoc_Params));

	if (!uFnGetDOFFocusLoc)
	{
		return GetDOFFocusLoc_Params.ReturnValue;
	}
	GetDOFFocusLoc_Params.TraceOwner = TraceOwner;
	memcpy_s(&GetDOFFocusLoc_Params.StartTrace, sizeof(GetDOFFocusLoc_Params.StartTrace), &StartTrace, sizeof(StartTrace));
	memcpy_s(&GetDOFFocusLoc_Params.EndTrace, sizeof(GetDOFFocusLoc_Params.EndTrace), &EndTrace, sizeof(EndTrace));

	this->ProcessEvent(uFnGetDOFFocusLoc, &GetDOFFocusLoc_Params, nullptr);

	return GetDOFFocusLoc_Params.ReturnValue;
}

// Function GameFramework.GameThirdPersonCameraMode.ProcessViewRotation
// [0x00420100] (FUNC_Simulated | FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// float                          DeltaTime                      (CPF_Parm)
// class AActor*                  ViewTarget                     (CPF_Parm)
// struct FRotator                out_ViewRotation               (CPF_Parm | CPF_OutParm)
// struct FRotator                out_DeltaRot                   (CPF_Parm | CPF_OutParm)

void UGameThirdPersonCameraMode::ProcessViewRotation(float DeltaTime, class AActor* ViewTarget, struct FRotator& outOut_ViewRotation, struct FRotator& outOut_DeltaRot)
{
	static UFunction* uFnProcessViewRotation = nullptr;

	if (!uFnProcessViewRotation)
	{
		uFnProcessViewRotation = UFunction::FindFunction("Function GameFramework.GameThirdPersonCameraMode.ProcessViewRotation");
	}

	UGameThirdPersonCameraMode_execProcessViewRotation_Params ProcessViewRotation_Params;
	memset(&ProcessViewRotation_Params, 0, sizeof(ProcessViewRotation_Params));

	if (!uFnProcessViewRotation)
	{
		return;
	}
	ProcessViewRotation_Params.DeltaTime = DeltaTime;
	ProcessViewRotation_Params.ViewTarget = ViewTarget;
	memcpy_s(&ProcessViewRotation_Params.out_ViewRotation, sizeof(ProcessViewRotation_Params.out_ViewRotation), &outOut_ViewRotation, sizeof(outOut_ViewRotation));
	memcpy_s(&ProcessViewRotation_Params.out_DeltaRot, sizeof(ProcessViewRotation_Params.out_DeltaRot), &outOut_DeltaRot, sizeof(outOut_DeltaRot));

	this->ProcessEvent(uFnProcessViewRotation, &ProcessViewRotation_Params, nullptr);

	memcpy_s(&outOut_ViewRotation, sizeof(outOut_ViewRotation), &ProcessViewRotation_Params.out_ViewRotation, sizeof(ProcessViewRotation_Params.out_ViewRotation));
	memcpy_s(&outOut_DeltaRot, sizeof(outOut_DeltaRot), &ProcessViewRotation_Params.out_DeltaRot, sizeof(ProcessViewRotation_Params.out_DeltaRot));
}

// Function GameFramework.GameThirdPersonCameraMode.SetFocusPoint
// [0x00020102] (FUNC_Defined | FUNC_Simulated | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class APawn*                   ViewedPawn                     (CPF_Parm)

bool UGameThirdPersonCameraMode::SetFocusPoint(class APawn* ViewedPawn)
{
	static UFunction* uFnSetFocusPoint = nullptr;

	if (!uFnSetFocusPoint)
	{
		uFnSetFocusPoint = UFunction::FindFunction("Function GameFramework.GameThirdPersonCameraMode.SetFocusPoint");
	}

	UGameThirdPersonCameraMode_execSetFocusPoint_Params SetFocusPoint_Params;
	memset(&SetFocusPoint_Params, 0, sizeof(SetFocusPoint_Params));

	if (!uFnSetFocusPoint)
	{
		return SetFocusPoint_Params.ReturnValue;
	}
	SetFocusPoint_Params.ViewedPawn = ViewedPawn;

	this->ProcessEvent(uFnSetFocusPoint, &SetFocusPoint_Params, nullptr);

	return SetFocusPoint_Params.ReturnValue;
}

// Function GameFramework.GameThirdPersonCameraMode.GetCameraWorstCaseLoc
// [0x00020902] (FUNC_Defined | FUNC_Simulated | FUNC_Event | FUNC_Public)
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class APawn*                   TargetPawn                     (CPF_Parm)

struct FVector UGameThirdPersonCameraMode::eventGetCameraWorstCaseLoc(class APawn* TargetPawn)
{
	static UFunction* uFnGetCameraWorstCaseLoc = nullptr;

	if (!uFnGetCameraWorstCaseLoc)
	{
		uFnGetCameraWorstCaseLoc = UFunction::FindFunction("Function GameFramework.GameThirdPersonCameraMode.GetCameraWorstCaseLoc");
	}

	UGameThirdPersonCameraMode_eventGetCameraWorstCaseLoc_Params GetCameraWorstCaseLoc_Params;
	memset(&GetCameraWorstCaseLoc_Params, 0, sizeof(GetCameraWorstCaseLoc_Params));

	if (!uFnGetCameraWorstCaseLoc)
	{
		return GetCameraWorstCaseLoc_Params.ReturnValue;
	}
	GetCameraWorstCaseLoc_Params.TargetPawn = TargetPawn;

	this->ProcessEvent(uFnGetCameraWorstCaseLoc, &GetCameraWorstCaseLoc_Params, nullptr);

	return GetCameraWorstCaseLoc_Params.ReturnValue;
}

// Function GameFramework.GameThirdPersonCameraMode.GetDesiredFOV
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class APawn*                   ViewedPawn                     (CPF_Parm)

float UGameThirdPersonCameraMode::GetDesiredFOV(class APawn* ViewedPawn)
{
	static UFunction* uFnGetDesiredFOV = nullptr;

	if (!uFnGetDesiredFOV)
	{
		uFnGetDesiredFOV = UFunction::FindFunction("Function GameFramework.GameThirdPersonCameraMode.GetDesiredFOV");
	}

	UGameThirdPersonCameraMode_execGetDesiredFOV_Params GetDesiredFOV_Params;
	memset(&GetDesiredFOV_Params, 0, sizeof(GetDesiredFOV_Params));

	if (!uFnGetDesiredFOV)
	{
		return GetDesiredFOV_Params.ReturnValue;
	}
	GetDesiredFOV_Params.ViewedPawn = ViewedPawn;

	this->ProcessEvent(uFnGetDesiredFOV, &GetDesiredFOV_Params, nullptr);

	return GetDesiredFOV_Params.ReturnValue;
}

// Function GameFramework.GameThirdPersonCameraMode.AdjustViewOffset
// [0x00020802] (FUNC_Defined | FUNC_Event | FUNC_Public)
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class APawn*                   P                              (CPF_Parm)
// struct FVector                 Offset                         (CPF_Parm)

struct FVector UGameThirdPersonCameraMode::eventAdjustViewOffset(class APawn* P, const struct FVector& Offset)
{
	static UFunction* uFnAdjustViewOffset = nullptr;

	if (!uFnAdjustViewOffset)
	{
		uFnAdjustViewOffset = UFunction::FindFunction("Function GameFramework.GameThirdPersonCameraMode.AdjustViewOffset");
	}

	UGameThirdPersonCameraMode_eventAdjustViewOffset_Params AdjustViewOffset_Params;
	memset(&AdjustViewOffset_Params, 0, sizeof(AdjustViewOffset_Params));

	if (!uFnAdjustViewOffset)
	{
		return AdjustViewOffset_Params.ReturnValue;
	}
	AdjustViewOffset_Params.P = P;
	memcpy_s(&AdjustViewOffset_Params.Offset, sizeof(AdjustViewOffset_Params.Offset), &Offset, sizeof(Offset));

	this->ProcessEvent(uFnAdjustViewOffset, &AdjustViewOffset_Params, nullptr);

	return AdjustViewOffset_Params.ReturnValue;
}

// Function GameFramework.GameThirdPersonCameraMode.OnBecomeInActive
// [0x00020000] (FUNC_Public)
// Parameter Info:
// class APawn*                   TargetPawn                     (CPF_Parm)
// class UGameThirdPersonCameraMode* NewMode                        (CPF_Parm)

void UGameThirdPersonCameraMode::OnBecomeInActive(class APawn* TargetPawn, class UGameThirdPersonCameraMode* NewMode)
{
	static UFunction* uFnOnBecomeInActive = nullptr;

	if (!uFnOnBecomeInActive)
	{
		uFnOnBecomeInActive = UFunction::FindFunction("Function GameFramework.GameThirdPersonCameraMode.OnBecomeInActive");
	}

	UGameThirdPersonCameraMode_execOnBecomeInActive_Params OnBecomeInActive_Params;
	memset(&OnBecomeInActive_Params, 0, sizeof(OnBecomeInActive_Params));

	if (!uFnOnBecomeInActive)
	{
		return;
	}
	OnBecomeInActive_Params.TargetPawn = TargetPawn;
	OnBecomeInActive_Params.NewMode = NewMode;

	this->ProcessEvent(uFnOnBecomeInActive, &OnBecomeInActive_Params, nullptr);
}

// Function GameFramework.GameThirdPersonCameraMode.OnBecomeActive
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class APawn*                   TargetPawn                     (CPF_Parm)
// class UGameThirdPersonCameraMode* PrevMode                       (CPF_Parm)

void UGameThirdPersonCameraMode::OnBecomeActive(class APawn* TargetPawn, class UGameThirdPersonCameraMode* PrevMode)
{
	static UFunction* uFnOnBecomeActive = nullptr;

	if (!uFnOnBecomeActive)
	{
		uFnOnBecomeActive = UFunction::FindFunction("Function GameFramework.GameThirdPersonCameraMode.OnBecomeActive");
	}

	UGameThirdPersonCameraMode_execOnBecomeActive_Params OnBecomeActive_Params;
	memset(&OnBecomeActive_Params, 0, sizeof(OnBecomeActive_Params));

	if (!uFnOnBecomeActive)
	{
		return;
	}
	OnBecomeActive_Params.TargetPawn = TargetPawn;
	OnBecomeActive_Params.PrevMode = PrevMode;

	this->ProcessEvent(uFnOnBecomeActive, &OnBecomeActive_Params, nullptr);
}

// Function GameFramework.GameThirdPersonCameraMode.Init
// [0x00020000] (FUNC_Public)
// Parameter Info:

void UGameThirdPersonCameraMode::Init()
{
	static UFunction* uFnInit = nullptr;

	if (!uFnInit)
	{
		uFnInit = UFunction::FindFunction("Function GameFramework.GameThirdPersonCameraMode.Init");
	}

	UGameThirdPersonCameraMode_execInit_Params Init_Params;
	memset(&Init_Params, 0, sizeof(Init_Params));

	if (!uFnInit)
	{
		return;
	}

	this->ProcessEvent(uFnInit, &Init_Params, nullptr);
}

// Function GameFramework.GameDecalManager.SpawnDecalMinimal
// [0x00C20003] (FUNC_Final | FUNC_Defined | FUNC_Public | FUNC_HasOutParms | FUNC_HasDefaults)
// Parameter Info:
// class UGameDecal*              ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_EditInline)
// float                          InDecalLifeSpan                (CPF_Const | CPF_Parm)
// float                          InCanSpawnDistance             (CPF_Const | CPF_Parm)
// struct FVector                 DecalLocation                  (CPF_Const | CPF_Parm | CPF_OutParm)

class UGameDecal* AGameDecalManager::SpawnDecalMinimal(float InDecalLifeSpan, float InCanSpawnDistance, struct FVector& outDecalLocation)
{
	static UFunction* uFnSpawnDecalMinimal = nullptr;

	if (!uFnSpawnDecalMinimal)
	{
		uFnSpawnDecalMinimal = UFunction::FindFunction("Function GameFramework.GameDecalManager.SpawnDecalMinimal");
	}

	AGameDecalManager_execSpawnDecalMinimal_Params SpawnDecalMinimal_Params;
	memset(&SpawnDecalMinimal_Params, 0, sizeof(SpawnDecalMinimal_Params));

	if (!uFnSpawnDecalMinimal)
	{
		return SpawnDecalMinimal_Params.ReturnValue;
	}
	SpawnDecalMinimal_Params.InDecalLifeSpan = InDecalLifeSpan;
	SpawnDecalMinimal_Params.InCanSpawnDistance = InCanSpawnDistance;
	memcpy_s(&SpawnDecalMinimal_Params.DecalLocation, sizeof(SpawnDecalMinimal_Params.DecalLocation), &outDecalLocation, sizeof(outDecalLocation));

	this->ProcessEvent(uFnSpawnDecalMinimal, &SpawnDecalMinimal_Params, nullptr);

	memcpy_s(&outDecalLocation, sizeof(outDecalLocation), &SpawnDecalMinimal_Params.DecalLocation, sizeof(SpawnDecalMinimal_Params.DecalLocation));

	return SpawnDecalMinimal_Params.ReturnValue;
}

// Function GameFramework.GameDecalManager.IsTooCloseToActiveDecal
// [0x00420401] (FUNC_Final | FUNC_Native | FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          InCanSpawnDistance             (CPF_Const | CPF_Parm)
// struct FVector                 DecalLocation                  (CPF_Const | CPF_Parm | CPF_OutParm)

bool AGameDecalManager::IsTooCloseToActiveDecal(float InCanSpawnDistance, struct FVector& outDecalLocation)
{
	static UFunction* uFnIsTooCloseToActiveDecal = nullptr;

	if (!uFnIsTooCloseToActiveDecal)
	{
		uFnIsTooCloseToActiveDecal = UFunction::FindFunction("Function GameFramework.GameDecalManager.IsTooCloseToActiveDecal");
	}

	AGameDecalManager_execIsTooCloseToActiveDecal_Params IsTooCloseToActiveDecal_Params;
	memset(&IsTooCloseToActiveDecal_Params, 0, sizeof(IsTooCloseToActiveDecal_Params));

	if (!uFnIsTooCloseToActiveDecal)
	{
		return IsTooCloseToActiveDecal_Params.ReturnValue;
	}
	IsTooCloseToActiveDecal_Params.InCanSpawnDistance = InCanSpawnDistance;
	memcpy_s(&IsTooCloseToActiveDecal_Params.DecalLocation, sizeof(IsTooCloseToActiveDecal_Params.DecalLocation), &outDecalLocation, sizeof(outDecalLocation));

	uint16_t nativeIndex = uFnIsTooCloseToActiveDecal->iNative;
	uFnIsTooCloseToActiveDecal->iNative = 0;
	this->ProcessEvent(uFnIsTooCloseToActiveDecal, &IsTooCloseToActiveDecal_Params, nullptr);
	uFnIsTooCloseToActiveDecal->iNative = nativeIndex;

	memcpy_s(&outDecalLocation, sizeof(outDecalLocation), &IsTooCloseToActiveDecal_Params.DecalLocation, sizeof(IsTooCloseToActiveDecal_Params.DecalLocation));

	return IsTooCloseToActiveDecal_Params.ReturnValue;
}

// Function GameFramework.GameParticleEventManager.HandleParticleModuleEventSendToGame
// [0x00420802] (FUNC_Defined | FUNC_Event | FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// class UParticleModuleEventSendToGame* InEvent                        (CPF_Parm)
// struct FVector                 InCollideDirection             (CPF_Const | CPF_Parm | CPF_OutParm)
// struct FVector                 InHitLocation                  (CPF_Const | CPF_Parm | CPF_OutParm)
// struct FVector                 InHitNormal                    (CPF_Const | CPF_Parm | CPF_OutParm)
// class FName                    InBoneName                     (CPF_Const | CPF_Parm | CPF_OutParm)

void AGameParticleEventManager::eventHandleParticleModuleEventSendToGame(class UParticleModuleEventSendToGame* InEvent, struct FVector& outInCollideDirection, struct FVector& outInHitLocation, struct FVector& outInHitNormal, class FName& outInBoneName)
{
	static UFunction* uFnHandleParticleModuleEventSendToGame = nullptr;

	if (!uFnHandleParticleModuleEventSendToGame)
	{
		uFnHandleParticleModuleEventSendToGame = UFunction::FindFunction("Function GameFramework.GameParticleEventManager.HandleParticleModuleEventSendToGame");
	}

	AGameParticleEventManager_eventHandleParticleModuleEventSendToGame_Params HandleParticleModuleEventSendToGame_Params;
	memset(&HandleParticleModuleEventSendToGame_Params, 0, sizeof(HandleParticleModuleEventSendToGame_Params));

	if (!uFnHandleParticleModuleEventSendToGame)
	{
		return;
	}
	HandleParticleModuleEventSendToGame_Params.InEvent = InEvent;
	memcpy_s(&HandleParticleModuleEventSendToGame_Params.InCollideDirection, sizeof(HandleParticleModuleEventSendToGame_Params.InCollideDirection), &outInCollideDirection, sizeof(outInCollideDirection));
	memcpy_s(&HandleParticleModuleEventSendToGame_Params.InHitLocation, sizeof(HandleParticleModuleEventSendToGame_Params.InHitLocation), &outInHitLocation, sizeof(outInHitLocation));
	memcpy_s(&HandleParticleModuleEventSendToGame_Params.InHitNormal, sizeof(HandleParticleModuleEventSendToGame_Params.InHitNormal), &outInHitNormal, sizeof(outInHitNormal));
	memcpy_s(&HandleParticleModuleEventSendToGame_Params.InBoneName, sizeof(HandleParticleModuleEventSendToGame_Params.InBoneName), &outInBoneName, sizeof(outInBoneName));

	this->ProcessEvent(uFnHandleParticleModuleEventSendToGame, &HandleParticleModuleEventSendToGame_Params, nullptr);

	memcpy_s(&outInCollideDirection, sizeof(outInCollideDirection), &HandleParticleModuleEventSendToGame_Params.InCollideDirection, sizeof(HandleParticleModuleEventSendToGame_Params.InCollideDirection));
	memcpy_s(&outInHitLocation, sizeof(outInHitLocation), &HandleParticleModuleEventSendToGame_Params.InHitLocation, sizeof(HandleParticleModuleEventSendToGame_Params.InHitLocation));
	memcpy_s(&outInHitNormal, sizeof(outInHitNormal), &HandleParticleModuleEventSendToGame_Params.InHitNormal, sizeof(HandleParticleModuleEventSendToGame_Params.InHitNormal));
	memcpy_s(&outInBoneName, sizeof(outInBoneName), &HandleParticleModuleEventSendToGame_Params.InBoneName, sizeof(HandleParticleModuleEventSendToGame_Params.InBoneName));
}

// Function GameFramework.GameSpecialMove.RelativeToWorldOffset
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FRotator                InRotation                     (CPF_Parm)
// struct FVector                 RelativeSpaceOffset            (CPF_Parm)

struct FVector UGameSpecialMove::RelativeToWorldOffset(const struct FRotator& InRotation, const struct FVector& RelativeSpaceOffset)
{
	static UFunction* uFnRelativeToWorldOffset = nullptr;

	if (!uFnRelativeToWorldOffset)
	{
		uFnRelativeToWorldOffset = UFunction::FindFunction("Function GameFramework.GameSpecialMove.RelativeToWorldOffset");
	}

	UGameSpecialMove_execRelativeToWorldOffset_Params RelativeToWorldOffset_Params;
	memset(&RelativeToWorldOffset_Params, 0, sizeof(RelativeToWorldOffset_Params));

	if (!uFnRelativeToWorldOffset)
	{
		return RelativeToWorldOffset_Params.ReturnValue;
	}
	memcpy_s(&RelativeToWorldOffset_Params.InRotation, sizeof(RelativeToWorldOffset_Params.InRotation), &InRotation, sizeof(InRotation));
	memcpy_s(&RelativeToWorldOffset_Params.RelativeSpaceOffset, sizeof(RelativeToWorldOffset_Params.RelativeSpaceOffset), &RelativeSpaceOffset, sizeof(RelativeSpaceOffset));

	uint16_t nativeIndex = uFnRelativeToWorldOffset->iNative;
	uFnRelativeToWorldOffset->iNative = 0;
	this->ProcessEvent(uFnRelativeToWorldOffset, &RelativeToWorldOffset_Params, nullptr);
	uFnRelativeToWorldOffset->iNative = nativeIndex;

	return RelativeToWorldOffset_Params.ReturnValue;
}

// Function GameFramework.GameSpecialMove.WorldToRelativeOffset
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FRotator                InRotation                     (CPF_Parm)
// struct FVector                 WorldSpaceOffset               (CPF_Parm)

struct FVector UGameSpecialMove::WorldToRelativeOffset(const struct FRotator& InRotation, const struct FVector& WorldSpaceOffset)
{
	static UFunction* uFnWorldToRelativeOffset = nullptr;

	if (!uFnWorldToRelativeOffset)
	{
		uFnWorldToRelativeOffset = UFunction::FindFunction("Function GameFramework.GameSpecialMove.WorldToRelativeOffset");
	}

	UGameSpecialMove_execWorldToRelativeOffset_Params WorldToRelativeOffset_Params;
	memset(&WorldToRelativeOffset_Params, 0, sizeof(WorldToRelativeOffset_Params));

	if (!uFnWorldToRelativeOffset)
	{
		return WorldToRelativeOffset_Params.ReturnValue;
	}
	memcpy_s(&WorldToRelativeOffset_Params.InRotation, sizeof(WorldToRelativeOffset_Params.InRotation), &InRotation, sizeof(InRotation));
	memcpy_s(&WorldToRelativeOffset_Params.WorldSpaceOffset, sizeof(WorldToRelativeOffset_Params.WorldSpaceOffset), &WorldSpaceOffset, sizeof(WorldSpaceOffset));

	uint16_t nativeIndex = uFnWorldToRelativeOffset->iNative;
	uFnWorldToRelativeOffset->iNative = 0;
	this->ProcessEvent(uFnWorldToRelativeOffset, &WorldToRelativeOffset_Params, nullptr);
	uFnWorldToRelativeOffset->iNative = nativeIndex;

	return WorldToRelativeOffset_Params.ReturnValue;
}

// Function GameFramework.GameSpecialMove.ForcePawnRotation
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// class APawn*                   P                              (CPF_Parm)
// struct FRotator                NewRotation                    (CPF_Parm)

void UGameSpecialMove::ForcePawnRotation(class APawn* P, const struct FRotator& NewRotation)
{
	static UFunction* uFnForcePawnRotation = nullptr;

	if (!uFnForcePawnRotation)
	{
		uFnForcePawnRotation = UFunction::FindFunction("Function GameFramework.GameSpecialMove.ForcePawnRotation");
	}

	UGameSpecialMove_execForcePawnRotation_Params ForcePawnRotation_Params;
	memset(&ForcePawnRotation_Params, 0, sizeof(ForcePawnRotation_Params));

	if (!uFnForcePawnRotation)
	{
		return;
	}
	ForcePawnRotation_Params.P = P;
	memcpy_s(&ForcePawnRotation_Params.NewRotation, sizeof(ForcePawnRotation_Params.NewRotation), &NewRotation, sizeof(NewRotation));

	uint16_t nativeIndex = uFnForcePawnRotation->iNative;
	uFnForcePawnRotation->iNative = 0;
	this->ProcessEvent(uFnForcePawnRotation, &ForcePawnRotation_Params, nullptr);
	uFnForcePawnRotation->iNative = nativeIndex;
}

// Function GameFramework.GameSpecialMove.MessageEvent
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FName                    EventName                      (CPF_Parm)
// class UObject*                 Sender                         (CPF_Parm)

bool UGameSpecialMove::MessageEvent(const class FName& EventName, class UObject* Sender)
{
	static UFunction* uFnMessageEvent = nullptr;

	if (!uFnMessageEvent)
	{
		uFnMessageEvent = UFunction::FindFunction("Function GameFramework.GameSpecialMove.MessageEvent");
	}

	UGameSpecialMove_execMessageEvent_Params MessageEvent_Params;
	memset(&MessageEvent_Params, 0, sizeof(MessageEvent_Params));

	if (!uFnMessageEvent)
	{
		return MessageEvent_Params.ReturnValue;
	}
	memcpy_s(&MessageEvent_Params.EventName, sizeof(MessageEvent_Params.EventName), &EventName, sizeof(EventName));
	MessageEvent_Params.Sender = Sender;

	this->ProcessEvent(uFnMessageEvent, &MessageEvent_Params, nullptr);

	return MessageEvent_Params.ReturnValue;
}

// Function GameFramework.GameSpecialMove.ResetFacePreciseRotation
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:

void UGameSpecialMove::ResetFacePreciseRotation()
{
	static UFunction* uFnResetFacePreciseRotation = nullptr;

	if (!uFnResetFacePreciseRotation)
	{
		uFnResetFacePreciseRotation = UFunction::FindFunction("Function GameFramework.GameSpecialMove.ResetFacePreciseRotation");
	}

	UGameSpecialMove_execResetFacePreciseRotation_Params ResetFacePreciseRotation_Params;
	memset(&ResetFacePreciseRotation_Params, 0, sizeof(ResetFacePreciseRotation_Params));

	if (!uFnResetFacePreciseRotation)
	{
		return;
	}

	uint16_t nativeIndex = uFnResetFacePreciseRotation->iNative;
	uFnResetFacePreciseRotation->iNative = 0;
	this->ProcessEvent(uFnResetFacePreciseRotation, &ResetFacePreciseRotation_Params, nullptr);
	uFnResetFacePreciseRotation->iNative = nativeIndex;
}

// Function GameFramework.GameSpecialMove.ReachedPrecisePosition
// [0x00020800] (FUNC_Event | FUNC_Public)
// Parameter Info:

void UGameSpecialMove::eventReachedPrecisePosition()
{
	static UFunction* uFnReachedPrecisePosition = nullptr;

	if (!uFnReachedPrecisePosition)
	{
		uFnReachedPrecisePosition = UFunction::FindFunction("Function GameFramework.GameSpecialMove.ReachedPrecisePosition");
	}

	UGameSpecialMove_eventReachedPrecisePosition_Params ReachedPrecisePosition_Params;
	memset(&ReachedPrecisePosition_Params, 0, sizeof(ReachedPrecisePosition_Params));

	if (!uFnReachedPrecisePosition)
	{
		return;
	}

	this->ProcessEvent(uFnReachedPrecisePosition, &ReachedPrecisePosition_Params, nullptr);
}

// Function GameFramework.GameSpecialMove.SetFacePreciseRotation
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// struct FRotator                RotationToFace                 (CPF_Parm)
// float                          InterpolationTime              (CPF_Parm)

void UGameSpecialMove::SetFacePreciseRotation(const struct FRotator& RotationToFace, float InterpolationTime)
{
	static UFunction* uFnSetFacePreciseRotation = nullptr;

	if (!uFnSetFacePreciseRotation)
	{
		uFnSetFacePreciseRotation = UFunction::FindFunction("Function GameFramework.GameSpecialMove.SetFacePreciseRotation");
	}

	UGameSpecialMove_execSetFacePreciseRotation_Params SetFacePreciseRotation_Params;
	memset(&SetFacePreciseRotation_Params, 0, sizeof(SetFacePreciseRotation_Params));

	if (!uFnSetFacePreciseRotation)
	{
		return;
	}
	memcpy_s(&SetFacePreciseRotation_Params.RotationToFace, sizeof(SetFacePreciseRotation_Params.RotationToFace), &RotationToFace, sizeof(RotationToFace));
	SetFacePreciseRotation_Params.InterpolationTime = InterpolationTime;

	uint16_t nativeIndex = uFnSetFacePreciseRotation->iNative;
	uFnSetFacePreciseRotation->iNative = 0;
	this->ProcessEvent(uFnSetFacePreciseRotation, &SetFacePreciseRotation_Params, nullptr);
	uFnSetFacePreciseRotation->iNative = nativeIndex;
}

// Function GameFramework.GameSpecialMove.SetReachPreciseDestination
// [0x00024401] (FUNC_Final | FUNC_Native | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// struct FVector                 DestinationToReach             (CPF_Parm)
// uint32_t                       bCancel                        (CPF_OptionalParm | CPF_Parm)

void UGameSpecialMove::SetReachPreciseDestination(const struct FVector& DestinationToReach, bool optionalBCancel)
{
	static UFunction* uFnSetReachPreciseDestination = nullptr;

	if (!uFnSetReachPreciseDestination)
	{
		uFnSetReachPreciseDestination = UFunction::FindFunction("Function GameFramework.GameSpecialMove.SetReachPreciseDestination");
	}

	UGameSpecialMove_execSetReachPreciseDestination_Params SetReachPreciseDestination_Params;
	memset(&SetReachPreciseDestination_Params, 0, sizeof(SetReachPreciseDestination_Params));

	if (!uFnSetReachPreciseDestination)
	{
		return;
	}
	memcpy_s(&SetReachPreciseDestination_Params.DestinationToReach, sizeof(SetReachPreciseDestination_Params.DestinationToReach), &DestinationToReach, sizeof(DestinationToReach));
	SetReachPreciseDestination_Params.bCancel = optionalBCancel;

	uint16_t nativeIndex = uFnSetReachPreciseDestination->iNative;
	uFnSetReachPreciseDestination->iNative = 0;
	this->ProcessEvent(uFnSetReachPreciseDestination, &SetReachPreciseDestination_Params, nullptr);
	uFnSetReachPreciseDestination->iNative = nativeIndex;
}

// Function GameFramework.GameSpecialMove.ShouldReplicate
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

bool UGameSpecialMove::ShouldReplicate()
{
	static UFunction* uFnShouldReplicate = nullptr;

	if (!uFnShouldReplicate)
	{
		uFnShouldReplicate = UFunction::FindFunction("Function GameFramework.GameSpecialMove.ShouldReplicate");
	}

	UGameSpecialMove_execShouldReplicate_Params ShouldReplicate_Params;
	memset(&ShouldReplicate_Params, 0, sizeof(ShouldReplicate_Params));

	if (!uFnShouldReplicate)
	{
		return ShouldReplicate_Params.ReturnValue;
	}

	this->ProcessEvent(uFnShouldReplicate, &ShouldReplicate_Params, nullptr);

	return ShouldReplicate_Params.ReturnValue;
}

// Function GameFramework.GameSpecialMove.SpecialMoveFlagsUpdated
// [0x00020000] (FUNC_Public)
// Parameter Info:

void UGameSpecialMove::SpecialMoveFlagsUpdated()
{
	static UFunction* uFnSpecialMoveFlagsUpdated = nullptr;

	if (!uFnSpecialMoveFlagsUpdated)
	{
		uFnSpecialMoveFlagsUpdated = UFunction::FindFunction("Function GameFramework.GameSpecialMove.SpecialMoveFlagsUpdated");
	}

	UGameSpecialMove_execSpecialMoveFlagsUpdated_Params SpecialMoveFlagsUpdated_Params;
	memset(&SpecialMoveFlagsUpdated_Params, 0, sizeof(SpecialMoveFlagsUpdated_Params));

	if (!uFnSpecialMoveFlagsUpdated)
	{
		return;
	}

	this->ProcessEvent(uFnSpecialMoveFlagsUpdated, &SpecialMoveFlagsUpdated_Params, nullptr);
}

// Function GameFramework.GameSpecialMove.Tick
// [0x00020000] (FUNC_Public)
// Parameter Info:
// float                          DeltaTime                      (CPF_Parm)

void UGameSpecialMove::Tick(float DeltaTime)
{
	static UFunction* uFnTick = nullptr;

	if (!uFnTick)
	{
		uFnTick = UFunction::FindFunction("Function GameFramework.GameSpecialMove.Tick");
	}

	UGameSpecialMove_execTick_Params Tick_Params;
	memset(&Tick_Params, 0, sizeof(Tick_Params));

	if (!uFnTick)
	{
		return;
	}
	Tick_Params.DeltaTime = DeltaTime;

	this->ProcessEvent(uFnTick, &Tick_Params, nullptr);
}

// Function GameFramework.GameSpecialMove.SpecialMoveEnded
// [0x00020000] (FUNC_Public)
// Parameter Info:
// class FName                    PrevMove                       (CPF_Parm)
// class FName                    NextMove                       (CPF_Parm)

void UGameSpecialMove::SpecialMoveEnded(const class FName& PrevMove, const class FName& NextMove)
{
	static UFunction* uFnSpecialMoveEnded = nullptr;

	if (!uFnSpecialMoveEnded)
	{
		uFnSpecialMoveEnded = UFunction::FindFunction("Function GameFramework.GameSpecialMove.SpecialMoveEnded");
	}

	UGameSpecialMove_execSpecialMoveEnded_Params SpecialMoveEnded_Params;
	memset(&SpecialMoveEnded_Params, 0, sizeof(SpecialMoveEnded_Params));

	if (!uFnSpecialMoveEnded)
	{
		return;
	}
	memcpy_s(&SpecialMoveEnded_Params.PrevMove, sizeof(SpecialMoveEnded_Params.PrevMove), &PrevMove, sizeof(PrevMove));
	memcpy_s(&SpecialMoveEnded_Params.NextMove, sizeof(SpecialMoveEnded_Params.NextMove), &NextMove, sizeof(NextMove));

	this->ProcessEvent(uFnSpecialMoveEnded, &SpecialMoveEnded_Params, nullptr);
}

// Function GameFramework.GameSpecialMove.SpecialMoveStarted
// [0x00020000] (FUNC_Public)
// Parameter Info:
// uint32_t                       bForced                        (CPF_Parm)
// class FName                    PrevMove                       (CPF_Parm)

void UGameSpecialMove::SpecialMoveStarted(bool bForced, const class FName& PrevMove)
{
	static UFunction* uFnSpecialMoveStarted = nullptr;

	if (!uFnSpecialMoveStarted)
	{
		uFnSpecialMoveStarted = UFunction::FindFunction("Function GameFramework.GameSpecialMove.SpecialMoveStarted");
	}

	UGameSpecialMove_execSpecialMoveStarted_Params SpecialMoveStarted_Params;
	memset(&SpecialMoveStarted_Params, 0, sizeof(SpecialMoveStarted_Params));

	if (!uFnSpecialMoveStarted)
	{
		return;
	}
	SpecialMoveStarted_Params.bForced = bForced;
	memcpy_s(&SpecialMoveStarted_Params.PrevMove, sizeof(SpecialMoveStarted_Params.PrevMove), &PrevMove, sizeof(PrevMove));

	this->ProcessEvent(uFnSpecialMoveStarted, &SpecialMoveStarted_Params, nullptr);
}

// Function GameFramework.GameSpecialMove.InternalCanDoSpecialMove
// [0x00080002] (FUNC_Defined | FUNC_Protected)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

bool UGameSpecialMove::InternalCanDoSpecialMove()
{
	static UFunction* uFnInternalCanDoSpecialMove = nullptr;

	if (!uFnInternalCanDoSpecialMove)
	{
		uFnInternalCanDoSpecialMove = UFunction::FindFunction("Function GameFramework.GameSpecialMove.InternalCanDoSpecialMove");
	}

	UGameSpecialMove_execInternalCanDoSpecialMove_Params InternalCanDoSpecialMove_Params;
	memset(&InternalCanDoSpecialMove_Params, 0, sizeof(InternalCanDoSpecialMove_Params));

	if (!uFnInternalCanDoSpecialMove)
	{
		return InternalCanDoSpecialMove_Params.ReturnValue;
	}

	this->ProcessEvent(uFnInternalCanDoSpecialMove, &InternalCanDoSpecialMove_Params, nullptr);

	return InternalCanDoSpecialMove_Params.ReturnValue;
}

// Function GameFramework.GameSpecialMove.CanDoSpecialMove
// [0x00024003] (FUNC_Final | FUNC_Defined | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// uint32_t                       bForceCheck                    (CPF_OptionalParm | CPF_Parm)

bool UGameSpecialMove::CanDoSpecialMove(bool optionalBForceCheck)
{
	static UFunction* uFnCanDoSpecialMove = nullptr;

	if (!uFnCanDoSpecialMove)
	{
		uFnCanDoSpecialMove = UFunction::FindFunction("Function GameFramework.GameSpecialMove.CanDoSpecialMove");
	}

	UGameSpecialMove_execCanDoSpecialMove_Params CanDoSpecialMove_Params;
	memset(&CanDoSpecialMove_Params, 0, sizeof(CanDoSpecialMove_Params));

	if (!uFnCanDoSpecialMove)
	{
		return CanDoSpecialMove_Params.ReturnValue;
	}
	CanDoSpecialMove_Params.bForceCheck = optionalBForceCheck;

	this->ProcessEvent(uFnCanDoSpecialMove, &CanDoSpecialMove_Params, nullptr);

	return CanDoSpecialMove_Params.ReturnValue;
}

// Function GameFramework.GameSpecialMove.CanOverrideSpecialMove
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FName                    InMove                         (CPF_Parm)

bool UGameSpecialMove::CanOverrideSpecialMove(const class FName& InMove)
{
	static UFunction* uFnCanOverrideSpecialMove = nullptr;

	if (!uFnCanOverrideSpecialMove)
	{
		uFnCanOverrideSpecialMove = UFunction::FindFunction("Function GameFramework.GameSpecialMove.CanOverrideSpecialMove");
	}

	UGameSpecialMove_execCanOverrideSpecialMove_Params CanOverrideSpecialMove_Params;
	memset(&CanOverrideSpecialMove_Params, 0, sizeof(CanOverrideSpecialMove_Params));

	if (!uFnCanOverrideSpecialMove)
	{
		return CanOverrideSpecialMove_Params.ReturnValue;
	}
	memcpy_s(&CanOverrideSpecialMove_Params.InMove, sizeof(CanOverrideSpecialMove_Params.InMove), &InMove, sizeof(InMove));

	this->ProcessEvent(uFnCanOverrideSpecialMove, &CanOverrideSpecialMove_Params, nullptr);

	return CanOverrideSpecialMove_Params.ReturnValue;
}

// Function GameFramework.GameSpecialMove.CanOverrideMoveWith
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FName                    NewMove                        (CPF_Parm)

bool UGameSpecialMove::CanOverrideMoveWith(const class FName& NewMove)
{
	static UFunction* uFnCanOverrideMoveWith = nullptr;

	if (!uFnCanOverrideMoveWith)
	{
		uFnCanOverrideMoveWith = UFunction::FindFunction("Function GameFramework.GameSpecialMove.CanOverrideMoveWith");
	}

	UGameSpecialMove_execCanOverrideMoveWith_Params CanOverrideMoveWith_Params;
	memset(&CanOverrideMoveWith_Params, 0, sizeof(CanOverrideMoveWith_Params));

	if (!uFnCanOverrideMoveWith)
	{
		return CanOverrideMoveWith_Params.ReturnValue;
	}
	memcpy_s(&CanOverrideMoveWith_Params.NewMove, sizeof(CanOverrideMoveWith_Params.NewMove), &NewMove, sizeof(NewMove));

	this->ProcessEvent(uFnCanOverrideMoveWith, &CanOverrideMoveWith_Params, nullptr);

	return CanOverrideMoveWith_Params.ReturnValue;
}

// Function GameFramework.GameSpecialMove.CanChainMove
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FName                    NextMove                       (CPF_Parm)

bool UGameSpecialMove::CanChainMove(const class FName& NextMove)
{
	static UFunction* uFnCanChainMove = nullptr;

	if (!uFnCanChainMove)
	{
		uFnCanChainMove = UFunction::FindFunction("Function GameFramework.GameSpecialMove.CanChainMove");
	}

	UGameSpecialMove_execCanChainMove_Params CanChainMove_Params;
	memset(&CanChainMove_Params, 0, sizeof(CanChainMove_Params));

	if (!uFnCanChainMove)
	{
		return CanChainMove_Params.ReturnValue;
	}
	memcpy_s(&CanChainMove_Params.NextMove, sizeof(CanChainMove_Params.NextMove), &NextMove, sizeof(NextMove));

	this->ProcessEvent(uFnCanChainMove, &CanChainMove_Params, nullptr);

	return CanChainMove_Params.ReturnValue;
}

// Function GameFramework.GameSpecialMove.ExtractSpecialMoveFlags
// [0x00020000] (FUNC_Public)
// Parameter Info:
// int32_t                        Flags                          (CPF_Parm)

void UGameSpecialMove::ExtractSpecialMoveFlags(int32_t Flags)
{
	static UFunction* uFnExtractSpecialMoveFlags = nullptr;

	if (!uFnExtractSpecialMoveFlags)
	{
		uFnExtractSpecialMoveFlags = UFunction::FindFunction("Function GameFramework.GameSpecialMove.ExtractSpecialMoveFlags");
	}

	UGameSpecialMove_execExtractSpecialMoveFlags_Params ExtractSpecialMoveFlags_Params;
	memset(&ExtractSpecialMoveFlags_Params, 0, sizeof(ExtractSpecialMoveFlags_Params));

	if (!uFnExtractSpecialMoveFlags)
	{
		return;
	}
	ExtractSpecialMoveFlags_Params.Flags = Flags;

	this->ProcessEvent(uFnExtractSpecialMoveFlags, &ExtractSpecialMoveFlags_Params, nullptr);
}

// Function GameFramework.GameSpecialMove.InitSpecialMoveFlags
// [0x00420000] (FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// int32_t                        out_Flags                      (CPF_Parm | CPF_OutParm)

void UGameSpecialMove::InitSpecialMoveFlags(int32_t& outOut_Flags)
{
	static UFunction* uFnInitSpecialMoveFlags = nullptr;

	if (!uFnInitSpecialMoveFlags)
	{
		uFnInitSpecialMoveFlags = UFunction::FindFunction("Function GameFramework.GameSpecialMove.InitSpecialMoveFlags");
	}

	UGameSpecialMove_execInitSpecialMoveFlags_Params InitSpecialMoveFlags_Params;
	memset(&InitSpecialMoveFlags_Params, 0, sizeof(InitSpecialMoveFlags_Params));

	if (!uFnInitSpecialMoveFlags)
	{
		return;
	}
	InitSpecialMoveFlags_Params.out_Flags = outOut_Flags;

	this->ProcessEvent(uFnInitSpecialMoveFlags, &InitSpecialMoveFlags_Params, nullptr);

	outOut_Flags = InitSpecialMoveFlags_Params.out_Flags;
}

// Function GameFramework.GameSpecialMove.InitSpecialMove
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class AGamePawn*               inPawn                         (CPF_Parm)
// class FName                    InHandle                       (CPF_Parm)

void UGameSpecialMove::InitSpecialMove(class AGamePawn* inPawn, const class FName& InHandle)
{
	static UFunction* uFnInitSpecialMove = nullptr;

	if (!uFnInitSpecialMove)
	{
		uFnInitSpecialMove = UFunction::FindFunction("Function GameFramework.GameSpecialMove.InitSpecialMove");
	}

	UGameSpecialMove_execInitSpecialMove_Params InitSpecialMove_Params;
	memset(&InitSpecialMove_Params, 0, sizeof(InitSpecialMove_Params));

	if (!uFnInitSpecialMove)
	{
		return;
	}
	InitSpecialMove_Params.inPawn = inPawn;
	memcpy_s(&InitSpecialMove_Params.InHandle, sizeof(InitSpecialMove_Params.InHandle), &InHandle, sizeof(InHandle));

	this->ProcessEvent(uFnInitSpecialMove, &InitSpecialMove_Params, nullptr);
}

// Function GameFramework.GameCrowdSpawnerInterface.GetMaxSpawnDist
// [0x00020000] (FUNC_Public)
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

float UGameCrowdSpawnerInterface::GetMaxSpawnDist()
{
	static UFunction* uFnGetMaxSpawnDist = nullptr;

	if (!uFnGetMaxSpawnDist)
	{
		uFnGetMaxSpawnDist = UFunction::FindFunction("Function GameFramework.GameCrowdSpawnerInterface.GetMaxSpawnDist");
	}

	UGameCrowdSpawnerInterface_execGetMaxSpawnDist_Params GetMaxSpawnDist_Params;
	memset(&GetMaxSpawnDist_Params, 0, sizeof(GetMaxSpawnDist_Params));

	if (!uFnGetMaxSpawnDist)
	{
		return GetMaxSpawnDist_Params.ReturnValue;
	}

	this->ProcessEvent(uFnGetMaxSpawnDist, &GetMaxSpawnDist_Params, nullptr);

	return GetMaxSpawnDist_Params.ReturnValue;
}

// Function GameFramework.GameCrowdSpawnerInterface.AddToAgentPool
// [0x00020000] (FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class AGameCrowdAgent*         Agent                          (CPF_Parm)

bool UGameCrowdSpawnerInterface::AddToAgentPool(class AGameCrowdAgent* Agent)
{
	static UFunction* uFnAddToAgentPool = nullptr;

	if (!uFnAddToAgentPool)
	{
		uFnAddToAgentPool = UFunction::FindFunction("Function GameFramework.GameCrowdSpawnerInterface.AddToAgentPool");
	}

	UGameCrowdSpawnerInterface_execAddToAgentPool_Params AddToAgentPool_Params;
	memset(&AddToAgentPool_Params, 0, sizeof(AddToAgentPool_Params));

	if (!uFnAddToAgentPool)
	{
		return AddToAgentPool_Params.ReturnValue;
	}
	AddToAgentPool_Params.Agent = Agent;

	this->ProcessEvent(uFnAddToAgentPool, &AddToAgentPool_Params, nullptr);

	return AddToAgentPool_Params.ReturnValue;
}

// Function GameFramework.GameCrowdSpawnerInterface.AgentDestroyed
// [0x00020000] (FUNC_Public)
// Parameter Info:
// class AGameCrowdAgent*         Agent                          (CPF_Parm)

void UGameCrowdSpawnerInterface::AgentDestroyed(class AGameCrowdAgent* Agent)
{
	static UFunction* uFnAgentDestroyed = nullptr;

	if (!uFnAgentDestroyed)
	{
		uFnAgentDestroyed = UFunction::FindFunction("Function GameFramework.GameCrowdSpawnerInterface.AgentDestroyed");
	}

	UGameCrowdSpawnerInterface_execAgentDestroyed_Params AgentDestroyed_Params;
	memset(&AgentDestroyed_Params, 0, sizeof(AgentDestroyed_Params));

	if (!uFnAgentDestroyed)
	{
		return;
	}
	AgentDestroyed_Params.Agent = Agent;

	this->ProcessEvent(uFnAgentDestroyed, &AgentDestroyed_Params, nullptr);
}

// Function GameFramework.GameCrowdSpawnInterface.GetSpawnPosition
// [0x00420000] (FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// class USeqAct_GameCrowdSpawner* Spawner                        (CPF_Parm)
// struct FVector                 SpawnPos                       (CPF_Parm | CPF_OutParm)
// struct FRotator                SpawnRot                       (CPF_Parm | CPF_OutParm)

void UGameCrowdSpawnInterface::GetSpawnPosition(class USeqAct_GameCrowdSpawner* Spawner, struct FVector& outSpawnPos, struct FRotator& outSpawnRot)
{
	static UFunction* uFnGetSpawnPosition = nullptr;

	if (!uFnGetSpawnPosition)
	{
		uFnGetSpawnPosition = UFunction::FindFunction("Function GameFramework.GameCrowdSpawnInterface.GetSpawnPosition");
	}

	UGameCrowdSpawnInterface_execGetSpawnPosition_Params GetSpawnPosition_Params;
	memset(&GetSpawnPosition_Params, 0, sizeof(GetSpawnPosition_Params));

	if (!uFnGetSpawnPosition)
	{
		return;
	}
	GetSpawnPosition_Params.Spawner = Spawner;
	memcpy_s(&GetSpawnPosition_Params.SpawnPos, sizeof(GetSpawnPosition_Params.SpawnPos), &outSpawnPos, sizeof(outSpawnPos));
	memcpy_s(&GetSpawnPosition_Params.SpawnRot, sizeof(GetSpawnPosition_Params.SpawnRot), &outSpawnRot, sizeof(outSpawnRot));

	this->ProcessEvent(uFnGetSpawnPosition, &GetSpawnPosition_Params, nullptr);

	memcpy_s(&outSpawnPos, sizeof(outSpawnPos), &GetSpawnPosition_Params.SpawnPos, sizeof(GetSpawnPosition_Params.SpawnPos));
	memcpy_s(&outSpawnRot, sizeof(outSpawnRot), &GetSpawnPosition_Params.SpawnRot, sizeof(GetSpawnPosition_Params.SpawnRot));
}

// Function GameFramework.GameFixedCamera.OnBecomeActive
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class UGameCameraBase*         OldCamera                      (CPF_Parm)

void UGameFixedCamera::OnBecomeActive(class UGameCameraBase* OldCamera)
{
	static UFunction* uFnOnBecomeActive = nullptr;

	if (!uFnOnBecomeActive)
	{
		uFnOnBecomeActive = UFunction::FindFunction("Function GameFramework.GameFixedCamera.OnBecomeActive");
	}

	UGameFixedCamera_execOnBecomeActive_Params OnBecomeActive_Params;
	memset(&OnBecomeActive_Params, 0, sizeof(OnBecomeActive_Params));

	if (!uFnOnBecomeActive)
	{
		return;
	}
	OnBecomeActive_Params.OldCamera = OldCamera;

	this->ProcessEvent(uFnOnBecomeActive, &OnBecomeActive_Params, nullptr);
}

// Function GameFramework.GameFixedCamera.UpdateCamera
// [0x00420102] (FUNC_Defined | FUNC_Simulated | FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// class APawn*                   P                              (CPF_Parm)
// class AGamePlayerCamera*       CameraActor                    (CPF_Parm)
// float                          DeltaTime                      (CPF_Parm)
// struct FTViewTarget            OutVT                          (CPF_Parm | CPF_OutParm)

void UGameFixedCamera::UpdateCamera(class APawn* P, class AGamePlayerCamera* CameraActor, float DeltaTime, struct FTViewTarget& outOutVT)
{
	static UFunction* uFnUpdateCamera = nullptr;

	if (!uFnUpdateCamera)
	{
		uFnUpdateCamera = UFunction::FindFunction("Function GameFramework.GameFixedCamera.UpdateCamera");
	}

	UGameFixedCamera_execUpdateCamera_Params UpdateCamera_Params;
	memset(&UpdateCamera_Params, 0, sizeof(UpdateCamera_Params));

	if (!uFnUpdateCamera)
	{
		return;
	}
	UpdateCamera_Params.P = P;
	UpdateCamera_Params.CameraActor = CameraActor;
	UpdateCamera_Params.DeltaTime = DeltaTime;
	memcpy_s(&UpdateCamera_Params.OutVT, sizeof(UpdateCamera_Params.OutVT), &outOutVT, sizeof(outOutVT));

	this->ProcessEvent(uFnUpdateCamera, &UpdateCamera_Params, nullptr);

	memcpy_s(&outOutVT, sizeof(outOutVT), &UpdateCamera_Params.OutVT, sizeof(UpdateCamera_Params.OutVT));
}

// Function GameFramework.GameFreeCamera.LimitViewRotation
// [0x00020102] (FUNC_Defined | FUNC_Simulated | FUNC_Public)
// Parameter Info:
// struct FRotator                ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FRotator                ViewRotation                   (CPF_Parm)
// float                          ViewPitchMin                   (CPF_Parm)
// float                          ViewPitchMax                   (CPF_Parm)

struct FRotator UGameFreeCamera::LimitViewRotation(const struct FRotator& ViewRotation, float ViewPitchMin, float ViewPitchMax)
{
	static UFunction* uFnLimitViewRotation = nullptr;

	if (!uFnLimitViewRotation)
	{
		uFnLimitViewRotation = UFunction::FindFunction("Function GameFramework.GameFreeCamera.LimitViewRotation");
	}

	UGameFreeCamera_execLimitViewRotation_Params LimitViewRotation_Params;
	memset(&LimitViewRotation_Params, 0, sizeof(LimitViewRotation_Params));

	if (!uFnLimitViewRotation)
	{
		return LimitViewRotation_Params.ReturnValue;
	}
	memcpy_s(&LimitViewRotation_Params.ViewRotation, sizeof(LimitViewRotation_Params.ViewRotation), &ViewRotation, sizeof(ViewRotation));
	LimitViewRotation_Params.ViewPitchMin = ViewPitchMin;
	LimitViewRotation_Params.ViewPitchMax = ViewPitchMax;

	this->ProcessEvent(uFnLimitViewRotation, &LimitViewRotation_Params, nullptr);

	return LimitViewRotation_Params.ReturnValue;
}

// Function GameFramework.GameFreeCamera.ClearMoveFlags
// [0x00020102] (FUNC_Defined | FUNC_Simulated | FUNC_Public)
// Parameter Info:

void UGameFreeCamera::ClearMoveFlags()
{
	static UFunction* uFnClearMoveFlags = nullptr;

	if (!uFnClearMoveFlags)
	{
		uFnClearMoveFlags = UFunction::FindFunction("Function GameFramework.GameFreeCamera.ClearMoveFlags");
	}

	UGameFreeCamera_execClearMoveFlags_Params ClearMoveFlags_Params;
	memset(&ClearMoveFlags_Params, 0, sizeof(ClearMoveFlags_Params));

	if (!uFnClearMoveFlags)
	{
		return;
	}

	this->ProcessEvent(uFnClearMoveFlags, &ClearMoveFlags_Params, nullptr);
}

// Function GameFramework.GameFreeCamera.ProcessInputInfo
// [0x00C20102] (FUNC_Defined | FUNC_Simulated | FUNC_Public | FUNC_HasOutParms | FUNC_HasDefaults)
// Parameter Info:
// float                          DeltaTime                      (CPF_Parm)
// struct FTViewTarget            OutVT                          (CPF_Parm | CPF_OutParm)

void UGameFreeCamera::ProcessInputInfo(float DeltaTime, struct FTViewTarget& outOutVT)
{
	static UFunction* uFnProcessInputInfo = nullptr;

	if (!uFnProcessInputInfo)
	{
		uFnProcessInputInfo = UFunction::FindFunction("Function GameFramework.GameFreeCamera.ProcessInputInfo");
	}

	UGameFreeCamera_execProcessInputInfo_Params ProcessInputInfo_Params;
	memset(&ProcessInputInfo_Params, 0, sizeof(ProcessInputInfo_Params));

	if (!uFnProcessInputInfo)
	{
		return;
	}
	ProcessInputInfo_Params.DeltaTime = DeltaTime;
	memcpy_s(&ProcessInputInfo_Params.OutVT, sizeof(ProcessInputInfo_Params.OutVT), &outOutVT, sizeof(outOutVT));

	this->ProcessEvent(uFnProcessInputInfo, &ProcessInputInfo_Params, nullptr);

	memcpy_s(&outOutVT, sizeof(outOutVT), &ProcessInputInfo_Params.OutVT, sizeof(ProcessInputInfo_Params.OutVT));
}

// Function GameFramework.GameFreeCamera.GetInputInfo
// [0x00020102] (FUNC_Defined | FUNC_Simulated | FUNC_Public)
// Parameter Info:

void UGameFreeCamera::GetInputInfo()
{
	static UFunction* uFnGetInputInfo = nullptr;

	if (!uFnGetInputInfo)
	{
		uFnGetInputInfo = UFunction::FindFunction("Function GameFramework.GameFreeCamera.GetInputInfo");
	}

	UGameFreeCamera_execGetInputInfo_Params GetInputInfo_Params;
	memset(&GetInputInfo_Params, 0, sizeof(GetInputInfo_Params));

	if (!uFnGetInputInfo)
	{
		return;
	}

	this->ProcessEvent(uFnGetInputInfo, &GetInputInfo_Params, nullptr);
}

// Function GameFramework.GameFreeCamera.IsKeyPressed
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class UPlayerInput*            InputInfo                      (CPF_Parm)
// class FName                    KeyName                        (CPF_Parm)

bool UGameFreeCamera::IsKeyPressed(class UPlayerInput* InputInfo, const class FName& KeyName)
{
	static UFunction* uFnIsKeyPressed = nullptr;

	if (!uFnIsKeyPressed)
	{
		uFnIsKeyPressed = UFunction::FindFunction("Function GameFramework.GameFreeCamera.IsKeyPressed");
	}

	UGameFreeCamera_execIsKeyPressed_Params IsKeyPressed_Params;
	memset(&IsKeyPressed_Params, 0, sizeof(IsKeyPressed_Params));

	if (!uFnIsKeyPressed)
	{
		return IsKeyPressed_Params.ReturnValue;
	}
	IsKeyPressed_Params.InputInfo = InputInfo;
	memcpy_s(&IsKeyPressed_Params.KeyName, sizeof(IsKeyPressed_Params.KeyName), &KeyName, sizeof(KeyName));

	this->ProcessEvent(uFnIsKeyPressed, &IsKeyPressed_Params, nullptr);

	return IsKeyPressed_Params.ReturnValue;
}

// Function GameFramework.GameFreeCamera.GetDeflection
// [0x00024102] (FUNC_Defined | FUNC_Simulated | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          F                              (CPF_Parm)
// float                          Epsilon                        (CPF_OptionalParm | CPF_Parm)

float UGameFreeCamera::GetDeflection(float F, float optionalEpsilon)
{
	static UFunction* uFnGetDeflection = nullptr;

	if (!uFnGetDeflection)
	{
		uFnGetDeflection = UFunction::FindFunction("Function GameFramework.GameFreeCamera.GetDeflection");
	}

	UGameFreeCamera_execGetDeflection_Params GetDeflection_Params;
	memset(&GetDeflection_Params, 0, sizeof(GetDeflection_Params));

	if (!uFnGetDeflection)
	{
		return GetDeflection_Params.ReturnValue;
	}
	GetDeflection_Params.F = F;
	GetDeflection_Params.Epsilon = optionalEpsilon;

	this->ProcessEvent(uFnGetDeflection, &GetDeflection_Params, nullptr);

	return GetDeflection_Params.ReturnValue;
}

// Function GameFramework.GameFreeCamera.GetSign
// [0x00024102] (FUNC_Defined | FUNC_Simulated | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          F                              (CPF_Parm)
// float                          Epsilon                        (CPF_OptionalParm | CPF_Parm)

float UGameFreeCamera::GetSign(float F, float optionalEpsilon)
{
	static UFunction* uFnGetSign = nullptr;

	if (!uFnGetSign)
	{
		uFnGetSign = UFunction::FindFunction("Function GameFramework.GameFreeCamera.GetSign");
	}

	UGameFreeCamera_execGetSign_Params GetSign_Params;
	memset(&GetSign_Params, 0, sizeof(GetSign_Params));

	if (!uFnGetSign)
	{
		return GetSign_Params.ReturnValue;
	}
	GetSign_Params.F = F;
	GetSign_Params.Epsilon = optionalEpsilon;

	this->ProcessEvent(uFnGetSign, &GetSign_Params, nullptr);

	return GetSign_Params.ReturnValue;
}

// Function GameFramework.GameFreeCamera.ProcessViewRotation
// [0x00420000] (FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// float                          DeltaTime                      (CPF_Parm)
// class AActor*                  ViewTarget                     (CPF_Parm)
// struct FRotator                out_ViewRotation               (CPF_Parm | CPF_OutParm)
// struct FRotator                out_DeltaRot                   (CPF_Parm | CPF_OutParm)

void UGameFreeCamera::ProcessViewRotation(float DeltaTime, class AActor* ViewTarget, struct FRotator& outOut_ViewRotation, struct FRotator& outOut_DeltaRot)
{
	static UFunction* uFnProcessViewRotation = nullptr;

	if (!uFnProcessViewRotation)
	{
		uFnProcessViewRotation = UFunction::FindFunction("Function GameFramework.GameFreeCamera.ProcessViewRotation");
	}

	UGameFreeCamera_execProcessViewRotation_Params ProcessViewRotation_Params;
	memset(&ProcessViewRotation_Params, 0, sizeof(ProcessViewRotation_Params));

	if (!uFnProcessViewRotation)
	{
		return;
	}
	ProcessViewRotation_Params.DeltaTime = DeltaTime;
	ProcessViewRotation_Params.ViewTarget = ViewTarget;
	memcpy_s(&ProcessViewRotation_Params.out_ViewRotation, sizeof(ProcessViewRotation_Params.out_ViewRotation), &outOut_ViewRotation, sizeof(outOut_ViewRotation));
	memcpy_s(&ProcessViewRotation_Params.out_DeltaRot, sizeof(ProcessViewRotation_Params.out_DeltaRot), &outOut_DeltaRot, sizeof(outOut_DeltaRot));

	this->ProcessEvent(uFnProcessViewRotation, &ProcessViewRotation_Params, nullptr);

	memcpy_s(&outOut_ViewRotation, sizeof(outOut_ViewRotation), &ProcessViewRotation_Params.out_ViewRotation, sizeof(ProcessViewRotation_Params.out_ViewRotation));
	memcpy_s(&outOut_DeltaRot, sizeof(outOut_DeltaRot), &ProcessViewRotation_Params.out_DeltaRot, sizeof(ProcessViewRotation_Params.out_DeltaRot));
}

// Function GameFramework.GameFreeCamera.OnBecomeActive
// [0x00020002] (FUNC_Defined | FUNC_Public)
// Parameter Info:
// class UGameCameraBase*         OldCamera                      (CPF_Parm)

void UGameFreeCamera::OnBecomeActive(class UGameCameraBase* OldCamera)
{
	static UFunction* uFnOnBecomeActive = nullptr;

	if (!uFnOnBecomeActive)
	{
		uFnOnBecomeActive = UFunction::FindFunction("Function GameFramework.GameFreeCamera.OnBecomeActive");
	}

	UGameFreeCamera_execOnBecomeActive_Params OnBecomeActive_Params;
	memset(&OnBecomeActive_Params, 0, sizeof(OnBecomeActive_Params));

	if (!uFnOnBecomeActive)
	{
		return;
	}
	OnBecomeActive_Params.OldCamera = OldCamera;

	this->ProcessEvent(uFnOnBecomeActive, &OnBecomeActive_Params, nullptr);
}

// Function GameFramework.GameFreeCamera.UpdateCamera
// [0x00420002] (FUNC_Defined | FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// class APawn*                   P                              (CPF_Parm)
// class AGamePlayerCamera*       CameraActor                    (CPF_Parm)
// float                          DeltaTime                      (CPF_Parm)
// struct FTViewTarget            OutVT                          (CPF_Parm | CPF_OutParm)

void UGameFreeCamera::UpdateCamera(class APawn* P, class AGamePlayerCamera* CameraActor, float DeltaTime, struct FTViewTarget& outOutVT)
{
	static UFunction* uFnUpdateCamera = nullptr;

	if (!uFnUpdateCamera)
	{
		uFnUpdateCamera = UFunction::FindFunction("Function GameFramework.GameFreeCamera.UpdateCamera");
	}

	UGameFreeCamera_execUpdateCamera_Params UpdateCamera_Params;
	memset(&UpdateCamera_Params, 0, sizeof(UpdateCamera_Params));

	if (!uFnUpdateCamera)
	{
		return;
	}
	UpdateCamera_Params.P = P;
	UpdateCamera_Params.CameraActor = CameraActor;
	UpdateCamera_Params.DeltaTime = DeltaTime;
	memcpy_s(&UpdateCamera_Params.OutVT, sizeof(UpdateCamera_Params.OutVT), &outOutVT, sizeof(outOutVT));

	this->ProcessEvent(uFnUpdateCamera, &UpdateCamera_Params, nullptr);

	memcpy_s(&outOutVT, sizeof(outOutVT), &UpdateCamera_Params.OutVT, sizeof(UpdateCamera_Params.OutVT));
}

// Function GameFramework.GameKActorSpawnableEffect.Tick
// [0x00020902] (FUNC_Defined | FUNC_Simulated | FUNC_Event | FUNC_Public)
// Parameter Info:
// float                          DeltaTime                      (CPF_Parm)

void AGameKActorSpawnableEffect::eventTick(float DeltaTime)
{
	static UFunction* uFnTick = nullptr;

	if (!uFnTick)
	{
		uFnTick = UFunction::FindFunction("Function GameFramework.GameKActorSpawnableEffect.Tick");
	}

	AGameKActorSpawnableEffect_eventTick_Params Tick_Params;
	memset(&Tick_Params, 0, sizeof(Tick_Params));

	if (!uFnTick)
	{
		return;
	}
	Tick_Params.DeltaTime = DeltaTime;

	this->ProcessEvent(uFnTick, &Tick_Params, nullptr);
}

// Function GameFramework.GameKActorSpawnableEffect.FellOutOfWorld
// [0x00020902] (FUNC_Defined | FUNC_Simulated | FUNC_Event | FUNC_Public)
// Parameter Info:
// class UClass*                  dmgType                        (CPF_Parm)

void AGameKActorSpawnableEffect::eventFellOutOfWorld(class UClass* dmgType)
{
	static UFunction* uFnFellOutOfWorld = nullptr;

	if (!uFnFellOutOfWorld)
	{
		uFnFellOutOfWorld = UFunction::FindFunction("Function GameFramework.GameKActorSpawnableEffect.FellOutOfWorld");
	}

	AGameKActorSpawnableEffect_eventFellOutOfWorld_Params FellOutOfWorld_Params;
	memset(&FellOutOfWorld_Params, 0, sizeof(FellOutOfWorld_Params));

	if (!uFnFellOutOfWorld)
	{
		return;
	}
	FellOutOfWorld_Params.dmgType = dmgType;

	this->ProcessEvent(uFnFellOutOfWorld, &FellOutOfWorld_Params, nullptr);
}

// Function GameFramework.GameKActorSpawnableEffect.PostBeginPlay
// [0x00020900] (FUNC_Simulated | FUNC_Event | FUNC_Public)
// Parameter Info:

void AGameKActorSpawnableEffect::eventPostBeginPlay()
{
	static UFunction* uFnPostBeginPlay = nullptr;

	if (!uFnPostBeginPlay)
	{
		uFnPostBeginPlay = UFunction::FindFunction("Function GameFramework.GameKActorSpawnableEffect.PostBeginPlay");
	}

	AGameKActorSpawnableEffect_eventPostBeginPlay_Params PostBeginPlay_Params;
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
