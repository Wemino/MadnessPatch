/*
#############################################################################################
# Alice2 (ASDK) SDK 1.0.0.0
# Generated with the CodeRedGenerator v1.2.0
# ========================================================================================= #
# File: Core_classes.cpp
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

class TArray<class UObject*>* UObject::GObjObjects()
{
	return reinterpret_cast<TArray<UObject*>*>(GObjects);
}

std::string UObject::GetName()
{
	return this->Name.ToString();
}

std::string UObject::GetNameCPP()
{
	std::string nameCPP;

	if (this->IsA<UClass>())
	{
		UClass* uClass = reinterpret_cast<UClass*>(this);

		while (uClass)
		{
			std::string className = uClass->GetName();

			if (className == "Actor")
			{
				nameCPP += "A";
				break;
			}
			else if (className == "Object")
			{
				nameCPP += "U";
				break;
			}

			uClass = reinterpret_cast<UClass*>(uClass->SuperField);
		}
	}
	else
	{
		nameCPP += "F";
	}

	nameCPP += this->GetName();

	return nameCPP;
}

std::string UObject::GetFullName()
{
	std::string fullName = this->GetName();

	for (UObject* uOuter = this->Outer; uOuter; uOuter = uOuter->Outer)
	{
		fullName = (uOuter->GetName() + "." + fullName);
	}

	fullName = ((this->Class ? this->Class->GetName() : std::string("UnknownClass")) + " " + fullName);
	return fullName;
}

class UObject* UObject::GetPackageObj()
{
	UObject* uPackage = nullptr;

	for (UObject* uOuter = this->Outer; uOuter; uOuter = uOuter->Outer)
	{
		uPackage = uOuter;
	}

	return uPackage;
}

class UClass* UObject::FindClass(const std::string& classFullName)
{
	static std::unordered_map<std::string, UClass*> classCache;

	auto cachedClass = classCache.find(classFullName);

	if (cachedClass != classCache.end())
	{
		return cachedClass->second;
	}

	bool fillCache = classCache.empty();
	UClass* foundClass = nullptr;

	for (int32_t i = 0; i < UObject::GObjObjects()->size(); i++)
	{
		UObject* uObject = UObject::GObjObjects()->at(i);

		if (uObject && uObject->Class && (uObject->Class == uObject->Class->Class))
		{
			std::string objectFullName = uObject->GetFullName();

			if (fillCache)
			{
				classCache.try_emplace(objectFullName, reinterpret_cast<UClass*>(uObject));
			}

			if (!foundClass && (objectFullName == classFullName))
			{
				foundClass = reinterpret_cast<UClass*>(uObject);

				if (!fillCache)
				{
					break;
				}
			}
		}
	}

	if (foundClass)
	{
		classCache[classFullName] = foundClass;
	}

	return foundClass;
}

bool UObject::IsA(class UClass* uClass)
{
	for (UClass* uSuperClass = reinterpret_cast<UClass*>(this->Class); uSuperClass; uSuperClass = reinterpret_cast<UClass*>(uSuperClass->SuperField))
	{
		if (uSuperClass == uClass)
		{
			return true;
		}
	}

	return false;
}

bool UObject::IsA(int32_t objInternalInteger)
{
	if (!UObject::GObjObjects()->IsValidIndex(objInternalInteger))
	{
		return false;
	}

	UObject* uObject = UObject::GObjObjects()->at(objInternalInteger);

	if (uObject && uObject->Class)
	{
		return this->IsA(reinterpret_cast<UClass*>(uObject->Class));
	}

	return false;
}

bool UObject::IsDefaultObject()
{
	// RF_ClassDefaultObject in this UE3 build (UnObjBas.h): 0x0000000000000200.
	return ((this->ObjectFlags & 0x0000000000000200ULL) != 0);
}

template<typename T> T GetVirtualFunction(const void* instance, size_t index)
{
	auto vtable = *static_cast<const void***>(const_cast<void*>(instance));
	return reinterpret_cast<T>(vtable[index]);
}

void UObject::ProcessEvent(class UFunction* uFunction, void* uParams, void* uResult)
{
	using tProcessEvent = void(__thiscall*)(class UObject*, class UFunction*, void*, void*);
	GetVirtualFunction<tProcessEvent>(this, 67)(this, uFunction, uParams, uResult);
}

// Function Core.Object.GetBuildChangelistNumber
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

int32_t UObject::GetBuildChangelistNumber()
{
	static UFunction* uFnGetBuildChangelistNumber = nullptr;

	if (!uFnGetBuildChangelistNumber)
	{
		uFnGetBuildChangelistNumber = UFunction::FindFunction("Function Core.Object.GetBuildChangelistNumber");
	}

	UObject_execGetBuildChangelistNumber_Params GetBuildChangelistNumber_Params;
	memset(&GetBuildChangelistNumber_Params, 0, sizeof(GetBuildChangelistNumber_Params));

	if (!uFnGetBuildChangelistNumber)
	{
		return GetBuildChangelistNumber_Params.ReturnValue;
	}

	uint16_t nativeIndex = uFnGetBuildChangelistNumber->iNative;
	uFnGetBuildChangelistNumber->iNative = 0;
	this->ProcessEvent(uFnGetBuildChangelistNumber, &GetBuildChangelistNumber_Params, nullptr);
	uFnGetBuildChangelistNumber->iNative = nativeIndex;

	return GetBuildChangelistNumber_Params.ReturnValue;
}

// Function Core.Object.GetEngineVersion
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

int32_t UObject::GetEngineVersion()
{
	static UFunction* uFnGetEngineVersion = nullptr;

	if (!uFnGetEngineVersion)
	{
		uFnGetEngineVersion = UFunction::FindFunction("Function Core.Object.GetEngineVersion");
	}

	UObject_execGetEngineVersion_Params GetEngineVersion_Params;
	memset(&GetEngineVersion_Params, 0, sizeof(GetEngineVersion_Params));

	if (!uFnGetEngineVersion)
	{
		return GetEngineVersion_Params.ReturnValue;
	}

	uint16_t nativeIndex = uFnGetEngineVersion->iNative;
	uFnGetEngineVersion->iNative = 0;
	this->ProcessEvent(uFnGetEngineVersion, &GetEngineVersion_Params, nullptr);
	uFnGetEngineVersion->iNative = nativeIndex;

	return GetEngineVersion_Params.ReturnValue;
}

// Function Core.Object.GetSystemTime
// [0x00420401] (FUNC_Final | FUNC_Native | FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// int32_t                        Year                           (CPF_Parm | CPF_OutParm)
// int32_t                        Month                          (CPF_Parm | CPF_OutParm)
// int32_t                        DayOfWeek                      (CPF_Parm | CPF_OutParm)
// int32_t                        Day                            (CPF_Parm | CPF_OutParm)
// int32_t                        Hour                           (CPF_Parm | CPF_OutParm)
// int32_t                        Min                            (CPF_Parm | CPF_OutParm)
// int32_t                        Sec                            (CPF_Parm | CPF_OutParm)
// int32_t                        MSec                           (CPF_Parm | CPF_OutParm)

void UObject::GetSystemTime(int32_t& outYear, int32_t& outMonth, int32_t& outDayOfWeek, int32_t& outDay, int32_t& outHour, int32_t& outMin, int32_t& outSec, int32_t& outMSec)
{
	static UFunction* uFnGetSystemTime = nullptr;

	if (!uFnGetSystemTime)
	{
		uFnGetSystemTime = UFunction::FindFunction("Function Core.Object.GetSystemTime");
	}

	UObject_execGetSystemTime_Params GetSystemTime_Params;
	memset(&GetSystemTime_Params, 0, sizeof(GetSystemTime_Params));

	if (!uFnGetSystemTime)
	{
		return;
	}
	GetSystemTime_Params.Year = outYear;
	GetSystemTime_Params.Month = outMonth;
	GetSystemTime_Params.DayOfWeek = outDayOfWeek;
	GetSystemTime_Params.Day = outDay;
	GetSystemTime_Params.Hour = outHour;
	GetSystemTime_Params.Min = outMin;
	GetSystemTime_Params.Sec = outSec;
	GetSystemTime_Params.MSec = outMSec;

	uint16_t nativeIndex = uFnGetSystemTime->iNative;
	uFnGetSystemTime->iNative = 0;
	this->ProcessEvent(uFnGetSystemTime, &GetSystemTime_Params, nullptr);
	uFnGetSystemTime->iNative = nativeIndex;

	outYear = GetSystemTime_Params.Year;
	outMonth = GetSystemTime_Params.Month;
	outDayOfWeek = GetSystemTime_Params.DayOfWeek;
	outDay = GetSystemTime_Params.Day;
	outHour = GetSystemTime_Params.Hour;
	outMin = GetSystemTime_Params.Min;
	outSec = GetSystemTime_Params.Sec;
	outMSec = GetSystemTime_Params.MSec;
}

// Function Core.Object.TimeStamp
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// class FString                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)

class FString UObject::TimeStamp()
{
	static UFunction* uFnTimeStamp = nullptr;

	if (!uFnTimeStamp)
	{
		uFnTimeStamp = UFunction::FindFunction("Function Core.Object.TimeStamp");
	}

	UObject_execTimeStamp_Params TimeStamp_Params;
	memset(&TimeStamp_Params, 0, sizeof(TimeStamp_Params));

	if (!uFnTimeStamp)
	{
		return TimeStamp_Params.ReturnValue;
	}

	uint16_t nativeIndex = uFnTimeStamp->iNative;
	uFnTimeStamp->iNative = 0;
	this->ProcessEvent(uFnTimeStamp, &TimeStamp_Params, nullptr);
	uFnTimeStamp->iNative = nativeIndex;

	return TimeStamp_Params.ReturnValue;
}

// Function Core.Object.TransformVectorByRotation
// [0x00024401] (FUNC_Final | FUNC_Native | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FRotator                SourceRotation                 (CPF_Parm)
// struct FVector                 SourceVector                   (CPF_Parm)
// uint32_t                       bInverse                       (CPF_OptionalParm | CPF_Parm)

struct FVector UObject::TransformVectorByRotation(const struct FRotator& SourceRotation, const struct FVector& SourceVector, bool optionalBInverse)
{
	static UFunction* uFnTransformVectorByRotation = nullptr;

	if (!uFnTransformVectorByRotation)
	{
		uFnTransformVectorByRotation = UFunction::FindFunction("Function Core.Object.TransformVectorByRotation");
	}

	UObject_execTransformVectorByRotation_Params TransformVectorByRotation_Params;
	memset(&TransformVectorByRotation_Params, 0, sizeof(TransformVectorByRotation_Params));

	if (!uFnTransformVectorByRotation)
	{
		return TransformVectorByRotation_Params.ReturnValue;
	}
	memcpy_s(&TransformVectorByRotation_Params.SourceRotation, sizeof(TransformVectorByRotation_Params.SourceRotation), &SourceRotation, sizeof(SourceRotation));
	memcpy_s(&TransformVectorByRotation_Params.SourceVector, sizeof(TransformVectorByRotation_Params.SourceVector), &SourceVector, sizeof(SourceVector));
	TransformVectorByRotation_Params.bInverse = optionalBInverse;

	uint16_t nativeIndex = uFnTransformVectorByRotation->iNative;
	uFnTransformVectorByRotation->iNative = 0;
	this->ProcessEvent(uFnTransformVectorByRotation, &TransformVectorByRotation_Params, nullptr);
	uFnTransformVectorByRotation->iNative = nativeIndex;

	return TransformVectorByRotation_Params.ReturnValue;
}

// Function Core.Object.GetPackageName
// [0x00020003] (FUNC_Final | FUNC_Defined | FUNC_Public)
// Parameter Info:
// class FName                    ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

class FName UObject::GetPackageName()
{
	static UFunction* uFnGetPackageName = nullptr;

	if (!uFnGetPackageName)
	{
		uFnGetPackageName = UFunction::FindFunction("Function Core.Object.GetPackageName");
	}

	UObject_execGetPackageName_Params GetPackageName_Params;
	memset(&GetPackageName_Params, 0, sizeof(GetPackageName_Params));

	if (!uFnGetPackageName)
	{
		return GetPackageName_Params.ReturnValue;
	}

	this->ProcessEvent(uFnGetPackageName, &GetPackageName_Params, nullptr);

	return GetPackageName_Params.ReturnValue;
}

// Function Core.Object.IsPendingKill
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

bool UObject::IsPendingKill()
{
	static UFunction* uFnIsPendingKill = nullptr;

	if (!uFnIsPendingKill)
	{
		uFnIsPendingKill = UFunction::FindFunction("Function Core.Object.IsPendingKill");
	}

	UObject_execIsPendingKill_Params IsPendingKill_Params;
	memset(&IsPendingKill_Params, 0, sizeof(IsPendingKill_Params));

	if (!uFnIsPendingKill)
	{
		return IsPendingKill_Params.ReturnValue;
	}

	uint16_t nativeIndex = uFnIsPendingKill->iNative;
	uFnIsPendingKill->iNative = 0;
	this->ProcessEvent(uFnIsPendingKill, &IsPendingKill_Params, nullptr);
	uFnIsPendingKill->iNative = nativeIndex;

	return IsPendingKill_Params.ReturnValue;
}

// Function Core.Object.ByteToFloat
// [0x00024103] (FUNC_Final | FUNC_Defined | FUNC_Simulated | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// uint8_t                        inputByte                      (CPF_Parm)
// uint32_t                       bSigned                        (CPF_OptionalParm | CPF_Parm)

float UObject::ByteToFloat(uint8_t inputByte, bool optionalBSigned)
{
	static UFunction* uFnByteToFloat = nullptr;

	if (!uFnByteToFloat)
	{
		uFnByteToFloat = UFunction::FindFunction("Function Core.Object.ByteToFloat");
	}

	UObject_execByteToFloat_Params ByteToFloat_Params;
	memset(&ByteToFloat_Params, 0, sizeof(ByteToFloat_Params));

	if (!uFnByteToFloat)
	{
		return ByteToFloat_Params.ReturnValue;
	}
	ByteToFloat_Params.inputByte = static_cast<uint8_t>(inputByte);
	ByteToFloat_Params.bSigned = optionalBSigned;

	this->ProcessEvent(uFnByteToFloat, &ByteToFloat_Params, nullptr);

	return ByteToFloat_Params.ReturnValue;
}

// Function Core.Object.FloatToByte
// [0x00024103] (FUNC_Final | FUNC_Defined | FUNC_Simulated | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// uint8_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          inputFloat                     (CPF_Parm)
// uint32_t                       bSigned                        (CPF_OptionalParm | CPF_Parm)

uint8_t UObject::FloatToByte(float inputFloat, bool optionalBSigned)
{
	static UFunction* uFnFloatToByte = nullptr;

	if (!uFnFloatToByte)
	{
		uFnFloatToByte = UFunction::FindFunction("Function Core.Object.FloatToByte");
	}

	UObject_execFloatToByte_Params FloatToByte_Params;
	memset(&FloatToByte_Params, 0, sizeof(FloatToByte_Params));

	if (!uFnFloatToByte)
	{
		return static_cast<uint8_t>(FloatToByte_Params.ReturnValue);
	}
	FloatToByte_Params.inputFloat = inputFloat;
	FloatToByte_Params.bSigned = optionalBSigned;

	this->ProcessEvent(uFnFloatToByte, &FloatToByte_Params, nullptr);

	return static_cast<uint8_t>(FloatToByte_Params.ReturnValue);
}

// Function Core.Object.UnwindHeading
// [0x00022103] (FUNC_Final | FUNC_Defined | FUNC_Simulated | FUNC_Static | FUNC_Public)
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          A                              (CPF_Parm)

float UObject::UnwindHeading(float A)
{
	static UFunction* uFnUnwindHeading = nullptr;

	if (!uFnUnwindHeading)
	{
		uFnUnwindHeading = UFunction::FindFunction("Function Core.Object.UnwindHeading");
	}

	UObject_execUnwindHeading_Params UnwindHeading_Params;
	memset(&UnwindHeading_Params, 0, sizeof(UnwindHeading_Params));

	if (!uFnUnwindHeading)
	{
		return UnwindHeading_Params.ReturnValue;
	}
	UnwindHeading_Params.A = A;

	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnUnwindHeading, &UnwindHeading_Params, nullptr);

	return UnwindHeading_Params.ReturnValue;
}

// Function Core.Object.FindDeltaAngle
// [0x00022103] (FUNC_Final | FUNC_Defined | FUNC_Simulated | FUNC_Static | FUNC_Public)
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          A1                             (CPF_Parm)
// float                          A2                             (CPF_Parm)

float UObject::FindDeltaAngle(float A1, float A2)
{
	static UFunction* uFnFindDeltaAngle = nullptr;

	if (!uFnFindDeltaAngle)
	{
		uFnFindDeltaAngle = UFunction::FindFunction("Function Core.Object.FindDeltaAngle");
	}

	UObject_execFindDeltaAngle_Params FindDeltaAngle_Params;
	memset(&FindDeltaAngle_Params, 0, sizeof(FindDeltaAngle_Params));

	if (!uFnFindDeltaAngle)
	{
		return FindDeltaAngle_Params.ReturnValue;
	}
	FindDeltaAngle_Params.A1 = A1;
	FindDeltaAngle_Params.A2 = A2;

	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnFindDeltaAngle, &FindDeltaAngle_Params, nullptr);

	return FindDeltaAngle_Params.ReturnValue;
}

// Function Core.Object.GetHeadingAngle
// [0x00022103] (FUNC_Final | FUNC_Defined | FUNC_Simulated | FUNC_Static | FUNC_Public)
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 Dir                            (CPF_Parm)

float UObject::GetHeadingAngle(const struct FVector& Dir)
{
	static UFunction* uFnGetHeadingAngle = nullptr;

	if (!uFnGetHeadingAngle)
	{
		uFnGetHeadingAngle = UFunction::FindFunction("Function Core.Object.GetHeadingAngle");
	}

	UObject_execGetHeadingAngle_Params GetHeadingAngle_Params;
	memset(&GetHeadingAngle_Params, 0, sizeof(GetHeadingAngle_Params));

	if (!uFnGetHeadingAngle)
	{
		return GetHeadingAngle_Params.ReturnValue;
	}
	memcpy_s(&GetHeadingAngle_Params.Dir, sizeof(GetHeadingAngle_Params.Dir), &Dir, sizeof(Dir));

	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnGetHeadingAngle, &GetHeadingAngle_Params, nullptr);

	return GetHeadingAngle_Params.ReturnValue;
}

// Function Core.Object.GetAngularDegreesFromRadians
// [0x00422103] (FUNC_Final | FUNC_Defined | FUNC_Simulated | FUNC_Static | FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// struct FVector2D               OutFOV                         (CPF_Parm | CPF_OutParm)

void UObject::GetAngularDegreesFromRadians(struct FVector2D& outOutFOV)
{
	static UFunction* uFnGetAngularDegreesFromRadians = nullptr;

	if (!uFnGetAngularDegreesFromRadians)
	{
		uFnGetAngularDegreesFromRadians = UFunction::FindFunction("Function Core.Object.GetAngularDegreesFromRadians");
	}

	UObject_execGetAngularDegreesFromRadians_Params GetAngularDegreesFromRadians_Params;
	memset(&GetAngularDegreesFromRadians_Params, 0, sizeof(GetAngularDegreesFromRadians_Params));

	if (!uFnGetAngularDegreesFromRadians)
	{
		return;
	}
	memcpy_s(&GetAngularDegreesFromRadians_Params.OutFOV, sizeof(GetAngularDegreesFromRadians_Params.OutFOV), &outOutFOV, sizeof(outOutFOV));

	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnGetAngularDegreesFromRadians, &GetAngularDegreesFromRadians_Params, nullptr);

	memcpy_s(&outOutFOV, sizeof(outOutFOV), &GetAngularDegreesFromRadians_Params.OutFOV, sizeof(GetAngularDegreesFromRadians_Params.OutFOV));
}

// Function Core.Object.GetAngularFromDotDist
// [0x00422401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// struct FVector2D               DotDist                        (CPF_Parm)
// struct FVector2D               OutAngDist                     (CPF_Parm | CPF_OutParm)

void UObject::GetAngularFromDotDist(const struct FVector2D& DotDist, struct FVector2D& outOutAngDist)
{
	static UFunction* uFnGetAngularFromDotDist = nullptr;

	if (!uFnGetAngularFromDotDist)
	{
		uFnGetAngularFromDotDist = UFunction::FindFunction("Function Core.Object.GetAngularFromDotDist");
	}

	UObject_execGetAngularFromDotDist_Params GetAngularFromDotDist_Params;
	memset(&GetAngularFromDotDist_Params, 0, sizeof(GetAngularFromDotDist_Params));

	if (!uFnGetAngularFromDotDist)
	{
		return;
	}
	memcpy_s(&GetAngularFromDotDist_Params.DotDist, sizeof(GetAngularFromDotDist_Params.DotDist), &DotDist, sizeof(DotDist));
	memcpy_s(&GetAngularFromDotDist_Params.OutAngDist, sizeof(GetAngularFromDotDist_Params.OutAngDist), &outOutAngDist, sizeof(outOutAngDist));

	uint16_t nativeIndex = uFnGetAngularFromDotDist->iNative;
	uFnGetAngularFromDotDist->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnGetAngularFromDotDist, &GetAngularFromDotDist_Params, nullptr);
	uFnGetAngularFromDotDist->iNative = nativeIndex;

	memcpy_s(&outOutAngDist, sizeof(outOutAngDist), &GetAngularFromDotDist_Params.OutAngDist, sizeof(GetAngularFromDotDist_Params.OutAngDist));
}

// Function Core.Object.GetAngularDistance
// [0x00422401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 Direction                      (CPF_Parm)
// struct FVector                 AxisX                          (CPF_Parm)
// struct FVector                 AxisY                          (CPF_Parm)
// struct FVector                 AxisZ                          (CPF_Parm)
// struct FVector2D               OutAngularDist                 (CPF_Parm | CPF_OutParm)

bool UObject::GetAngularDistance(const struct FVector& Direction, const struct FVector& AxisX, const struct FVector& AxisY, const struct FVector& AxisZ, struct FVector2D& outOutAngularDist)
{
	static UFunction* uFnGetAngularDistance = nullptr;

	if (!uFnGetAngularDistance)
	{
		uFnGetAngularDistance = UFunction::FindFunction("Function Core.Object.GetAngularDistance");
	}

	UObject_execGetAngularDistance_Params GetAngularDistance_Params;
	memset(&GetAngularDistance_Params, 0, sizeof(GetAngularDistance_Params));

	if (!uFnGetAngularDistance)
	{
		return GetAngularDistance_Params.ReturnValue;
	}
	memcpy_s(&GetAngularDistance_Params.Direction, sizeof(GetAngularDistance_Params.Direction), &Direction, sizeof(Direction));
	memcpy_s(&GetAngularDistance_Params.AxisX, sizeof(GetAngularDistance_Params.AxisX), &AxisX, sizeof(AxisX));
	memcpy_s(&GetAngularDistance_Params.AxisY, sizeof(GetAngularDistance_Params.AxisY), &AxisY, sizeof(AxisY));
	memcpy_s(&GetAngularDistance_Params.AxisZ, sizeof(GetAngularDistance_Params.AxisZ), &AxisZ, sizeof(AxisZ));
	memcpy_s(&GetAngularDistance_Params.OutAngularDist, sizeof(GetAngularDistance_Params.OutAngularDist), &outOutAngularDist, sizeof(outOutAngularDist));

	uint16_t nativeIndex = uFnGetAngularDistance->iNative;
	uFnGetAngularDistance->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnGetAngularDistance, &GetAngularDistance_Params, nullptr);
	uFnGetAngularDistance->iNative = nativeIndex;

	memcpy_s(&outOutAngularDist, sizeof(outOutAngularDist), &GetAngularDistance_Params.OutAngularDist, sizeof(GetAngularDistance_Params.OutAngularDist));

	return GetAngularDistance_Params.ReturnValue;
}

// Function Core.Object.GetDotDistance
// [0x00422401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 Direction                      (CPF_Parm)
// struct FVector                 AxisX                          (CPF_Parm)
// struct FVector                 AxisY                          (CPF_Parm)
// struct FVector                 AxisZ                          (CPF_Parm)
// struct FVector2D               OutDotDist                     (CPF_Parm | CPF_OutParm)

bool UObject::GetDotDistance(const struct FVector& Direction, const struct FVector& AxisX, const struct FVector& AxisY, const struct FVector& AxisZ, struct FVector2D& outOutDotDist)
{
	static UFunction* uFnGetDotDistance = nullptr;

	if (!uFnGetDotDistance)
	{
		uFnGetDotDistance = UFunction::FindFunction("Function Core.Object.GetDotDistance");
	}

	UObject_execGetDotDistance_Params GetDotDistance_Params;
	memset(&GetDotDistance_Params, 0, sizeof(GetDotDistance_Params));

	if (!uFnGetDotDistance)
	{
		return GetDotDistance_Params.ReturnValue;
	}
	memcpy_s(&GetDotDistance_Params.Direction, sizeof(GetDotDistance_Params.Direction), &Direction, sizeof(Direction));
	memcpy_s(&GetDotDistance_Params.AxisX, sizeof(GetDotDistance_Params.AxisX), &AxisX, sizeof(AxisX));
	memcpy_s(&GetDotDistance_Params.AxisY, sizeof(GetDotDistance_Params.AxisY), &AxisY, sizeof(AxisY));
	memcpy_s(&GetDotDistance_Params.AxisZ, sizeof(GetDotDistance_Params.AxisZ), &AxisZ, sizeof(AxisZ));
	memcpy_s(&GetDotDistance_Params.OutDotDist, sizeof(GetDotDistance_Params.OutDotDist), &outOutDotDist, sizeof(outOutDotDist));

	uint16_t nativeIndex = uFnGetDotDistance->iNative;
	uFnGetDotDistance->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnGetDotDistance, &GetDotDistance_Params, nullptr);
	uFnGetDotDistance->iNative = nativeIndex;

	memcpy_s(&outOutDotDist, sizeof(outOutDotDist), &GetDotDistance_Params.OutDotDist, sizeof(GetDotDistance_Params.OutDotDist));

	return GetDotDistance_Params.ReturnValue;
}

// Function Core.Object.PointProjectToPlane
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 Point                          (CPF_Parm)
// struct FVector                 A                              (CPF_Parm)
// struct FVector                 B                              (CPF_Parm)
// struct FVector                 C                              (CPF_Parm)

struct FVector UObject::PointProjectToPlane(const struct FVector& Point, const struct FVector& A, const struct FVector& B, const struct FVector& C)
{
	static UFunction* uFnPointProjectToPlane = nullptr;

	if (!uFnPointProjectToPlane)
	{
		uFnPointProjectToPlane = UFunction::FindFunction("Function Core.Object.PointProjectToPlane");
	}

	UObject_execPointProjectToPlane_Params PointProjectToPlane_Params;
	memset(&PointProjectToPlane_Params, 0, sizeof(PointProjectToPlane_Params));

	if (!uFnPointProjectToPlane)
	{
		return PointProjectToPlane_Params.ReturnValue;
	}
	memcpy_s(&PointProjectToPlane_Params.Point, sizeof(PointProjectToPlane_Params.Point), &Point, sizeof(Point));
	memcpy_s(&PointProjectToPlane_Params.A, sizeof(PointProjectToPlane_Params.A), &A, sizeof(A));
	memcpy_s(&PointProjectToPlane_Params.B, sizeof(PointProjectToPlane_Params.B), &B, sizeof(B));
	memcpy_s(&PointProjectToPlane_Params.C, sizeof(PointProjectToPlane_Params.C), &C, sizeof(C));

	uint16_t nativeIndex = uFnPointProjectToPlane->iNative;
	uFnPointProjectToPlane->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnPointProjectToPlane, &PointProjectToPlane_Params, nullptr);
	uFnPointProjectToPlane->iNative = nativeIndex;

	return PointProjectToPlane_Params.ReturnValue;
}

// Function Core.Object.PointDistToPlane
// [0x00C24103] (FUNC_Final | FUNC_Defined | FUNC_Simulated | FUNC_OptionalParm | FUNC_Public | FUNC_HasOutParms | FUNC_HasDefaults)
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 Point                          (CPF_Parm)
// struct FRotator                Orientation                    (CPF_Parm)
// struct FVector                 Origin                         (CPF_Parm)
// struct FVector                 out_ClosestPoint               (CPF_OptionalParm | CPF_Parm | CPF_OutParm)

float UObject::PointDistToPlane(const struct FVector& Point, const struct FRotator& Orientation, const struct FVector& Origin, struct FVector& optionalOutOut_ClosestPoint)
{
	static UFunction* uFnPointDistToPlane = nullptr;

	if (!uFnPointDistToPlane)
	{
		uFnPointDistToPlane = UFunction::FindFunction("Function Core.Object.PointDistToPlane");
	}

	UObject_execPointDistToPlane_Params PointDistToPlane_Params;
	memset(&PointDistToPlane_Params, 0, sizeof(PointDistToPlane_Params));

	if (!uFnPointDistToPlane)
	{
		return PointDistToPlane_Params.ReturnValue;
	}
	memcpy_s(&PointDistToPlane_Params.Point, sizeof(PointDistToPlane_Params.Point), &Point, sizeof(Point));
	memcpy_s(&PointDistToPlane_Params.Orientation, sizeof(PointDistToPlane_Params.Orientation), &Orientation, sizeof(Orientation));
	memcpy_s(&PointDistToPlane_Params.Origin, sizeof(PointDistToPlane_Params.Origin), &Origin, sizeof(Origin));
	memcpy_s(&PointDistToPlane_Params.out_ClosestPoint, sizeof(PointDistToPlane_Params.out_ClosestPoint), &optionalOutOut_ClosestPoint, sizeof(optionalOutOut_ClosestPoint));

	this->ProcessEvent(uFnPointDistToPlane, &PointDistToPlane_Params, nullptr);

	memcpy_s(&optionalOutOut_ClosestPoint, sizeof(optionalOutOut_ClosestPoint), &PointDistToPlane_Params.out_ClosestPoint, sizeof(PointDistToPlane_Params.out_ClosestPoint));

	return PointDistToPlane_Params.ReturnValue;
}

// Function Core.Object.PointDistToSegment
// [0x00424401] (FUNC_Final | FUNC_Native | FUNC_OptionalParm | FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 Point                          (CPF_Parm)
// struct FVector                 StartPoint                     (CPF_Parm)
// struct FVector                 EndPoint                       (CPF_Parm)
// struct FVector                 OutClosestPoint                (CPF_OptionalParm | CPF_Parm | CPF_OutParm)

float UObject::PointDistToSegment(const struct FVector& Point, const struct FVector& StartPoint, const struct FVector& EndPoint, struct FVector& optionalOutOutClosestPoint)
{
	static UFunction* uFnPointDistToSegment = nullptr;

	if (!uFnPointDistToSegment)
	{
		uFnPointDistToSegment = UFunction::FindFunction("Function Core.Object.PointDistToSegment");
	}

	UObject_execPointDistToSegment_Params PointDistToSegment_Params;
	memset(&PointDistToSegment_Params, 0, sizeof(PointDistToSegment_Params));

	if (!uFnPointDistToSegment)
	{
		return PointDistToSegment_Params.ReturnValue;
	}
	memcpy_s(&PointDistToSegment_Params.Point, sizeof(PointDistToSegment_Params.Point), &Point, sizeof(Point));
	memcpy_s(&PointDistToSegment_Params.StartPoint, sizeof(PointDistToSegment_Params.StartPoint), &StartPoint, sizeof(StartPoint));
	memcpy_s(&PointDistToSegment_Params.EndPoint, sizeof(PointDistToSegment_Params.EndPoint), &EndPoint, sizeof(EndPoint));
	memcpy_s(&PointDistToSegment_Params.OutClosestPoint, sizeof(PointDistToSegment_Params.OutClosestPoint), &optionalOutOutClosestPoint, sizeof(optionalOutOutClosestPoint));

	uint16_t nativeIndex = uFnPointDistToSegment->iNative;
	uFnPointDistToSegment->iNative = 0;
	this->ProcessEvent(uFnPointDistToSegment, &PointDistToSegment_Params, nullptr);
	uFnPointDistToSegment->iNative = nativeIndex;

	memcpy_s(&optionalOutOutClosestPoint, sizeof(optionalOutOutClosestPoint), &PointDistToSegment_Params.OutClosestPoint, sizeof(PointDistToSegment_Params.OutClosestPoint));

	return PointDistToSegment_Params.ReturnValue;
}

// Function Core.Object.PointDistToLine
// [0x00424401] (FUNC_Final | FUNC_Native | FUNC_OptionalParm | FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 Point                          (CPF_Parm)
// struct FVector                 Line                           (CPF_Parm)
// struct FVector                 Origin                         (CPF_Parm)
// struct FVector                 OutClosestPoint                (CPF_OptionalParm | CPF_Parm | CPF_OutParm)

float UObject::PointDistToLine(const struct FVector& Point, const struct FVector& Line, const struct FVector& Origin, struct FVector& optionalOutOutClosestPoint)
{
	static UFunction* uFnPointDistToLine = nullptr;

	if (!uFnPointDistToLine)
	{
		uFnPointDistToLine = UFunction::FindFunction("Function Core.Object.PointDistToLine");
	}

	UObject_execPointDistToLine_Params PointDistToLine_Params;
	memset(&PointDistToLine_Params, 0, sizeof(PointDistToLine_Params));

	if (!uFnPointDistToLine)
	{
		return PointDistToLine_Params.ReturnValue;
	}
	memcpy_s(&PointDistToLine_Params.Point, sizeof(PointDistToLine_Params.Point), &Point, sizeof(Point));
	memcpy_s(&PointDistToLine_Params.Line, sizeof(PointDistToLine_Params.Line), &Line, sizeof(Line));
	memcpy_s(&PointDistToLine_Params.Origin, sizeof(PointDistToLine_Params.Origin), &Origin, sizeof(Origin));
	memcpy_s(&PointDistToLine_Params.OutClosestPoint, sizeof(PointDistToLine_Params.OutClosestPoint), &optionalOutOutClosestPoint, sizeof(optionalOutOutClosestPoint));

	uint16_t nativeIndex = uFnPointDistToLine->iNative;
	uFnPointDistToLine->iNative = 0;
	this->ProcessEvent(uFnPointDistToLine, &PointDistToLine_Params, nullptr);
	uFnPointDistToLine->iNative = nativeIndex;

	memcpy_s(&optionalOutOutClosestPoint, sizeof(optionalOutOutClosestPoint), &PointDistToLine_Params.OutClosestPoint, sizeof(PointDistToLine_Params.OutClosestPoint));

	return PointDistToLine_Params.ReturnValue;
}

// Function Core.Object.GetPerObjectConfigSections
// [0x00426401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_OptionalParm | FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class UClass*                  SearchClass                    (CPF_Parm)
// class UObject*                 ObjectOuter                    (CPF_OptionalParm | CPF_Parm)
// int32_t                        MaxResults                     (CPF_OptionalParm | CPF_Parm)
// class TArray<class FString>    out_SectionNames               (CPF_Parm | CPF_OutParm | CPF_NeedCtorLink)

bool UObject::GetPerObjectConfigSections(class UClass* SearchClass, class UObject* optionalObjectOuter, int32_t optionalMaxResults, class TArray<class FString>& outOut_SectionNames)
{
	static UFunction* uFnGetPerObjectConfigSections = nullptr;

	if (!uFnGetPerObjectConfigSections)
	{
		uFnGetPerObjectConfigSections = UFunction::FindFunction("Function Core.Object.GetPerObjectConfigSections");
	}

	UObject_execGetPerObjectConfigSections_Params GetPerObjectConfigSections_Params;
	memset(&GetPerObjectConfigSections_Params, 0, sizeof(GetPerObjectConfigSections_Params));

	if (!uFnGetPerObjectConfigSections)
	{
		return GetPerObjectConfigSections_Params.ReturnValue;
	}
	GetPerObjectConfigSections_Params.SearchClass = SearchClass;
	GetPerObjectConfigSections_Params.ObjectOuter = optionalObjectOuter;
	GetPerObjectConfigSections_Params.MaxResults = optionalMaxResults;
	memcpy_s(&GetPerObjectConfigSections_Params.out_SectionNames, sizeof(GetPerObjectConfigSections_Params.out_SectionNames), &outOut_SectionNames, sizeof(outOut_SectionNames));

	uint16_t nativeIndex = uFnGetPerObjectConfigSections->iNative;
	uFnGetPerObjectConfigSections->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnGetPerObjectConfigSections, &GetPerObjectConfigSections_Params, nullptr);
	uFnGetPerObjectConfigSections->iNative = nativeIndex;

	memcpy_s(&outOut_SectionNames, sizeof(outOut_SectionNames), &GetPerObjectConfigSections_Params.out_SectionNames, sizeof(GetPerObjectConfigSections_Params.out_SectionNames));

	return GetPerObjectConfigSections_Params.ReturnValue;
}

// Function Core.Object.StaticSaveConfig
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:

void UObject::StaticSaveConfig()
{
	static UFunction* uFnStaticSaveConfig = nullptr;

	if (!uFnStaticSaveConfig)
	{
		uFnStaticSaveConfig = UFunction::FindFunction("Function Core.Object.StaticSaveConfig");
	}

	UObject_execStaticSaveConfig_Params StaticSaveConfig_Params;
	memset(&StaticSaveConfig_Params, 0, sizeof(StaticSaveConfig_Params));

	if (!uFnStaticSaveConfig)
	{
		return;
	}

	uint16_t nativeIndex = uFnStaticSaveConfig->iNative;
	uFnStaticSaveConfig->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnStaticSaveConfig, &StaticSaveConfig_Params, nullptr);
	uFnStaticSaveConfig->iNative = nativeIndex;
}

// Function Core.Object.SaveConfig
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public) (iNative[536])
// Parameter Info:

void UObject::SaveConfig()
{
	static UFunction* uFnSaveConfig = nullptr;

	if (!uFnSaveConfig)
	{
		uFnSaveConfig = UFunction::FindFunction("Function Core.Object.SaveConfig");
	}

	UObject_execSaveConfig_Params SaveConfig_Params;
	memset(&SaveConfig_Params, 0, sizeof(SaveConfig_Params));

	if (!uFnSaveConfig)
	{
		return;
	}

	uint16_t nativeIndex = uFnSaveConfig->iNative;
	uFnSaveConfig->iNative = 0;
	this->ProcessEvent(uFnSaveConfig, &SaveConfig_Params, nullptr);
	uFnSaveConfig->iNative = nativeIndex;
}

// Function Core.Object.FindObject
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// class UObject*                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FString                  ObjectName                     (CPF_Parm | CPF_NeedCtorLink)
// class UClass*                  ObjectClass                    (CPF_Parm)

class UObject* UObject::FindObject(const class FString& ObjectName, class UClass* ObjectClass)
{
	static UFunction* uFnFindObject = nullptr;

	if (!uFnFindObject)
	{
		uFnFindObject = UFunction::FindFunction("Function Core.Object.FindObject");
	}

	UObject_execFindObject_Params FindObject_Params;
	memset(&FindObject_Params, 0, sizeof(FindObject_Params));

	if (!uFnFindObject)
	{
		return FindObject_Params.ReturnValue;
	}
	memcpy_s(&FindObject_Params.ObjectName, sizeof(FindObject_Params.ObjectName), &ObjectName, sizeof(ObjectName));
	FindObject_Params.ObjectClass = ObjectClass;

	uint16_t nativeIndex = uFnFindObject->iNative;
	uFnFindObject->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnFindObject, &FindObject_Params, nullptr);
	uFnFindObject->iNative = nativeIndex;

	return FindObject_Params.ReturnValue;
}

// Function Core.Object.DynamicLoadObject
// [0x00026401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// class UObject*                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FString                  ObjectName                     (CPF_Parm | CPF_NeedCtorLink)
// class UClass*                  ObjectClass                    (CPF_Parm)
// uint32_t                       MayFail                        (CPF_OptionalParm | CPF_Parm)

class UObject* UObject::DynamicLoadObject(const class FString& ObjectName, class UClass* ObjectClass, bool optionalMayFail)
{
	static UFunction* uFnDynamicLoadObject = nullptr;

	if (!uFnDynamicLoadObject)
	{
		uFnDynamicLoadObject = UFunction::FindFunction("Function Core.Object.DynamicLoadObject");
	}

	UObject_execDynamicLoadObject_Params DynamicLoadObject_Params;
	memset(&DynamicLoadObject_Params, 0, sizeof(DynamicLoadObject_Params));

	if (!uFnDynamicLoadObject)
	{
		return DynamicLoadObject_Params.ReturnValue;
	}
	memcpy_s(&DynamicLoadObject_Params.ObjectName, sizeof(DynamicLoadObject_Params.ObjectName), &ObjectName, sizeof(ObjectName));
	DynamicLoadObject_Params.ObjectClass = ObjectClass;
	DynamicLoadObject_Params.MayFail = optionalMayFail;

	uint16_t nativeIndex = uFnDynamicLoadObject->iNative;
	uFnDynamicLoadObject->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnDynamicLoadObject, &DynamicLoadObject_Params, nullptr);
	uFnDynamicLoadObject->iNative = nativeIndex;

	return DynamicLoadObject_Params.ReturnValue;
}

// Function Core.Object.GetEnum
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// class FName                    ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class UObject*                 E                              (CPF_Parm)
// int32_t                        I                              (CPF_Parm | CPF_CoerceParm)

class FName UObject::GetEnum(class UObject* E, int32_t I)
{
	static UFunction* uFnGetEnum = nullptr;

	if (!uFnGetEnum)
	{
		uFnGetEnum = UFunction::FindFunction("Function Core.Object.GetEnum");
	}

	UObject_execGetEnum_Params GetEnum_Params;
	memset(&GetEnum_Params, 0, sizeof(GetEnum_Params));

	if (!uFnGetEnum)
	{
		return GetEnum_Params.ReturnValue;
	}
	GetEnum_Params.E = E;
	GetEnum_Params.I = I;

	uint16_t nativeIndex = uFnGetEnum->iNative;
	uFnGetEnum->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnGetEnum, &GetEnum_Params, nullptr);
	uFnGetEnum->iNative = nativeIndex;

	return GetEnum_Params.ReturnValue;
}

// Function Core.Object.Disable
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public) (iNative[118])
// Parameter Info:
// class FName                    ProbeFunc                      (CPF_Parm)

void UObject::Disable(const class FName& ProbeFunc)
{
	static UFunction* uFnDisable = nullptr;

	if (!uFnDisable)
	{
		uFnDisable = UFunction::FindFunction("Function Core.Object.Disable");
	}

	UObject_execDisable_Params Disable_Params;
	memset(&Disable_Params, 0, sizeof(Disable_Params));

	if (!uFnDisable)
	{
		return;
	}
	memcpy_s(&Disable_Params.ProbeFunc, sizeof(Disable_Params.ProbeFunc), &ProbeFunc, sizeof(ProbeFunc));

	uint16_t nativeIndex = uFnDisable->iNative;
	uFnDisable->iNative = 0;
	this->ProcessEvent(uFnDisable, &Disable_Params, nullptr);
	uFnDisable->iNative = nativeIndex;
}

// Function Core.Object.Enable
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public) (iNative[117])
// Parameter Info:
// class FName                    ProbeFunc                      (CPF_Parm)

void UObject::Enable(const class FName& ProbeFunc)
{
	static UFunction* uFnEnable = nullptr;

	if (!uFnEnable)
	{
		uFnEnable = UFunction::FindFunction("Function Core.Object.Enable");
	}

	UObject_execEnable_Params Enable_Params;
	memset(&Enable_Params, 0, sizeof(Enable_Params));

	if (!uFnEnable)
	{
		return;
	}
	memcpy_s(&Enable_Params.ProbeFunc, sizeof(Enable_Params.ProbeFunc), &ProbeFunc, sizeof(ProbeFunc));

	uint16_t nativeIndex = uFnEnable->iNative;
	uFnEnable->iNative = 0;
	this->ProcessEvent(uFnEnable, &Enable_Params, nullptr);
	uFnEnable->iNative = nativeIndex;
}

// Function Core.Object.ContinuedState
// [0x00020800] (FUNC_Event | FUNC_Public)
// Parameter Info:

void UObject::eventContinuedState()
{
	static UFunction* uFnContinuedState = nullptr;

	if (!uFnContinuedState)
	{
		uFnContinuedState = UFunction::FindFunction("Function Core.Object.ContinuedState");
	}

	UObject_eventContinuedState_Params ContinuedState_Params;
	memset(&ContinuedState_Params, 0, sizeof(ContinuedState_Params));

	if (!uFnContinuedState)
	{
		return;
	}

	this->ProcessEvent(uFnContinuedState, &ContinuedState_Params, nullptr);
}

// Function Core.Object.PausedState
// [0x00020800] (FUNC_Event | FUNC_Public)
// Parameter Info:

void UObject::eventPausedState()
{
	static UFunction* uFnPausedState = nullptr;

	if (!uFnPausedState)
	{
		uFnPausedState = UFunction::FindFunction("Function Core.Object.PausedState");
	}

	UObject_eventPausedState_Params PausedState_Params;
	memset(&PausedState_Params, 0, sizeof(PausedState_Params));

	if (!uFnPausedState)
	{
		return;
	}

	this->ProcessEvent(uFnPausedState, &PausedState_Params, nullptr);
}

// Function Core.Object.PoppedState
// [0x00020800] (FUNC_Event | FUNC_Public)
// Parameter Info:

void UObject::eventPoppedState()
{
	static UFunction* uFnPoppedState = nullptr;

	if (!uFnPoppedState)
	{
		uFnPoppedState = UFunction::FindFunction("Function Core.Object.PoppedState");
	}

	UObject_eventPoppedState_Params PoppedState_Params;
	memset(&PoppedState_Params, 0, sizeof(PoppedState_Params));

	if (!uFnPoppedState)
	{
		return;
	}

	this->ProcessEvent(uFnPoppedState, &PoppedState_Params, nullptr);
}

// Function Core.Object.PushedState
// [0x00020800] (FUNC_Event | FUNC_Public)
// Parameter Info:

void UObject::eventPushedState()
{
	static UFunction* uFnPushedState = nullptr;

	if (!uFnPushedState)
	{
		uFnPushedState = UFunction::FindFunction("Function Core.Object.PushedState");
	}

	UObject_eventPushedState_Params PushedState_Params;
	memset(&PushedState_Params, 0, sizeof(PushedState_Params));

	if (!uFnPushedState)
	{
		return;
	}

	this->ProcessEvent(uFnPushedState, &PushedState_Params, nullptr);
}

// Function Core.Object.EndState
// [0x00020800] (FUNC_Event | FUNC_Public)
// Parameter Info:
// class FName                    NextStateName                  (CPF_Parm)

void UObject::eventEndState(const class FName& NextStateName)
{
	static UFunction* uFnEndState = nullptr;

	if (!uFnEndState)
	{
		uFnEndState = UFunction::FindFunction("Function Core.Object.EndState");
	}

	UObject_eventEndState_Params EndState_Params;
	memset(&EndState_Params, 0, sizeof(EndState_Params));

	if (!uFnEndState)
	{
		return;
	}
	memcpy_s(&EndState_Params.NextStateName, sizeof(EndState_Params.NextStateName), &NextStateName, sizeof(NextStateName));

	this->ProcessEvent(uFnEndState, &EndState_Params, nullptr);
}

// Function Core.Object.BeginState
// [0x00020800] (FUNC_Event | FUNC_Public)
// Parameter Info:
// class FName                    PreviousStateName              (CPF_Parm)

void UObject::eventBeginState(const class FName& PreviousStateName)
{
	static UFunction* uFnBeginState = nullptr;

	if (!uFnBeginState)
	{
		uFnBeginState = UFunction::FindFunction("Function Core.Object.BeginState");
	}

	UObject_eventBeginState_Params BeginState_Params;
	memset(&BeginState_Params, 0, sizeof(BeginState_Params));

	if (!uFnBeginState)
	{
		return;
	}
	memcpy_s(&BeginState_Params.PreviousStateName, sizeof(BeginState_Params.PreviousStateName), &PreviousStateName, sizeof(PreviousStateName));

	this->ProcessEvent(uFnBeginState, &BeginState_Params, nullptr);
}

// Function Core.Object.DumpStateStack
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:

void UObject::DumpStateStack()
{
	static UFunction* uFnDumpStateStack = nullptr;

	if (!uFnDumpStateStack)
	{
		uFnDumpStateStack = UFunction::FindFunction("Function Core.Object.DumpStateStack");
	}

	UObject_execDumpStateStack_Params DumpStateStack_Params;
	memset(&DumpStateStack_Params, 0, sizeof(DumpStateStack_Params));

	if (!uFnDumpStateStack)
	{
		return;
	}

	uint16_t nativeIndex = uFnDumpStateStack->iNative;
	uFnDumpStateStack->iNative = 0;
	this->ProcessEvent(uFnDumpStateStack, &DumpStateStack_Params, nullptr);
	uFnDumpStateStack->iNative = nativeIndex;
}

// Function Core.Object.PopState
// [0x00024401] (FUNC_Final | FUNC_Native | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// uint32_t                       bPopAll                        (CPF_OptionalParm | CPF_Parm)

void UObject::PopState(bool optionalBPopAll)
{
	static UFunction* uFnPopState = nullptr;

	if (!uFnPopState)
	{
		uFnPopState = UFunction::FindFunction("Function Core.Object.PopState");
	}

	UObject_execPopState_Params PopState_Params;
	memset(&PopState_Params, 0, sizeof(PopState_Params));

	if (!uFnPopState)
	{
		return;
	}
	PopState_Params.bPopAll = optionalBPopAll;

	uint16_t nativeIndex = uFnPopState->iNative;
	uFnPopState->iNative = 0;
	this->ProcessEvent(uFnPopState, &PopState_Params, nullptr);
	uFnPopState->iNative = nativeIndex;
}

// Function Core.Object.PushState
// [0x00024401] (FUNC_Final | FUNC_Native | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// class FName                    NewState                       (CPF_Parm)
// class FName                    NewLabel                       (CPF_OptionalParm | CPF_Parm)

void UObject::PushState(const class FName& NewState, const class FName& optionalNewLabel)
{
	static UFunction* uFnPushState = nullptr;

	if (!uFnPushState)
	{
		uFnPushState = UFunction::FindFunction("Function Core.Object.PushState");
	}

	UObject_execPushState_Params PushState_Params;
	memset(&PushState_Params, 0, sizeof(PushState_Params));

	if (!uFnPushState)
	{
		return;
	}
	memcpy_s(&PushState_Params.NewState, sizeof(PushState_Params.NewState), &NewState, sizeof(NewState));
	memcpy_s(&PushState_Params.NewLabel, sizeof(PushState_Params.NewLabel), &optionalNewLabel, sizeof(optionalNewLabel));

	uint16_t nativeIndex = uFnPushState->iNative;
	uFnPushState->iNative = 0;
	this->ProcessEvent(uFnPushState, &PushState_Params, nullptr);
	uFnPushState->iNative = nativeIndex;
}

// Function Core.Object.GetStateName
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public) (iNative[284])
// Parameter Info:
// class FName                    ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

class FName UObject::GetStateName()
{
	static UFunction* uFnGetStateName = nullptr;

	if (!uFnGetStateName)
	{
		uFnGetStateName = UFunction::FindFunction("Function Core.Object.GetStateName");
	}

	UObject_execGetStateName_Params GetStateName_Params;
	memset(&GetStateName_Params, 0, sizeof(GetStateName_Params));

	if (!uFnGetStateName)
	{
		return GetStateName_Params.ReturnValue;
	}

	uint16_t nativeIndex = uFnGetStateName->iNative;
	uFnGetStateName->iNative = 0;
	this->ProcessEvent(uFnGetStateName, &GetStateName_Params, nullptr);
	uFnGetStateName->iNative = nativeIndex;

	return GetStateName_Params.ReturnValue;
}

// Function Core.Object.IsChildState
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FName                    TestState                      (CPF_Parm)
// class FName                    TestParentState                (CPF_Parm)

bool UObject::IsChildState(const class FName& TestState, const class FName& TestParentState)
{
	static UFunction* uFnIsChildState = nullptr;

	if (!uFnIsChildState)
	{
		uFnIsChildState = UFunction::FindFunction("Function Core.Object.IsChildState");
	}

	UObject_execIsChildState_Params IsChildState_Params;
	memset(&IsChildState_Params, 0, sizeof(IsChildState_Params));

	if (!uFnIsChildState)
	{
		return IsChildState_Params.ReturnValue;
	}
	memcpy_s(&IsChildState_Params.TestState, sizeof(IsChildState_Params.TestState), &TestState, sizeof(TestState));
	memcpy_s(&IsChildState_Params.TestParentState, sizeof(IsChildState_Params.TestParentState), &TestParentState, sizeof(TestParentState));

	uint16_t nativeIndex = uFnIsChildState->iNative;
	uFnIsChildState->iNative = 0;
	this->ProcessEvent(uFnIsChildState, &IsChildState_Params, nullptr);
	uFnIsChildState->iNative = nativeIndex;

	return IsChildState_Params.ReturnValue;
}

// Function Core.Object.IsInState
// [0x00024401] (FUNC_Final | FUNC_Native | FUNC_OptionalParm | FUNC_Public) (iNative[281])
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FName                    TestState                      (CPF_Parm)
// uint32_t                       bTestStateStack                (CPF_OptionalParm | CPF_Parm)

bool UObject::IsInState(const class FName& TestState, bool optionalBTestStateStack)
{
	static UFunction* uFnIsInState = nullptr;

	if (!uFnIsInState)
	{
		uFnIsInState = UFunction::FindFunction("Function Core.Object.IsInState");
	}

	UObject_execIsInState_Params IsInState_Params;
	memset(&IsInState_Params, 0, sizeof(IsInState_Params));

	if (!uFnIsInState)
	{
		return IsInState_Params.ReturnValue;
	}
	memcpy_s(&IsInState_Params.TestState, sizeof(IsInState_Params.TestState), &TestState, sizeof(TestState));
	IsInState_Params.bTestStateStack = optionalBTestStateStack;

	uint16_t nativeIndex = uFnIsInState->iNative;
	uFnIsInState->iNative = 0;
	this->ProcessEvent(uFnIsInState, &IsInState_Params, nullptr);
	uFnIsInState->iNative = nativeIndex;

	return IsInState_Params.ReturnValue;
}

// Function Core.Object.GotoState
// [0x00024401] (FUNC_Final | FUNC_Native | FUNC_OptionalParm | FUNC_Public) (iNative[113])
// Parameter Info:
// class FName                    NewState                       (CPF_OptionalParm | CPF_Parm)
// class FName                    Label                          (CPF_OptionalParm | CPF_Parm)
// uint32_t                       bForceEvents                   (CPF_OptionalParm | CPF_Parm)
// uint32_t                       bKeepStack                     (CPF_OptionalParm | CPF_Parm)

void UObject::GotoState(const class FName& optionalNewState, const class FName& optionalLabel, bool optionalBForceEvents, bool optionalBKeepStack)
{
	static UFunction* uFnGotoState = nullptr;

	if (!uFnGotoState)
	{
		uFnGotoState = UFunction::FindFunction("Function Core.Object.GotoState");
	}

	UObject_execGotoState_Params GotoState_Params;
	memset(&GotoState_Params, 0, sizeof(GotoState_Params));

	if (!uFnGotoState)
	{
		return;
	}
	memcpy_s(&GotoState_Params.NewState, sizeof(GotoState_Params.NewState), &optionalNewState, sizeof(optionalNewState));
	memcpy_s(&GotoState_Params.Label, sizeof(GotoState_Params.Label), &optionalLabel, sizeof(optionalLabel));
	GotoState_Params.bForceEvents = optionalBForceEvents;
	GotoState_Params.bKeepStack = optionalBKeepStack;

	uint16_t nativeIndex = uFnGotoState->iNative;
	uFnGotoState->iNative = 0;
	this->ProcessEvent(uFnGotoState, &GotoState_Params, nullptr);
	uFnGotoState->iNative = nativeIndex;
}

// Function Core.Object.IsUTracing
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

bool UObject::IsUTracing()
{
	static UFunction* uFnIsUTracing = nullptr;

	if (!uFnIsUTracing)
	{
		uFnIsUTracing = UFunction::FindFunction("Function Core.Object.IsUTracing");
	}

	UObject_execIsUTracing_Params IsUTracing_Params;
	memset(&IsUTracing_Params, 0, sizeof(IsUTracing_Params));

	if (!uFnIsUTracing)
	{
		return IsUTracing_Params.ReturnValue;
	}

	uint16_t nativeIndex = uFnIsUTracing->iNative;
	uFnIsUTracing->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnIsUTracing, &IsUTracing_Params, nullptr);
	uFnIsUTracing->iNative = nativeIndex;

	return IsUTracing_Params.ReturnValue;
}

// Function Core.Object.SetUTracing
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// uint32_t                       bShouldUTrace                  (CPF_Parm)

void UObject::SetUTracing(bool bShouldUTrace)
{
	static UFunction* uFnSetUTracing = nullptr;

	if (!uFnSetUTracing)
	{
		uFnSetUTracing = UFunction::FindFunction("Function Core.Object.SetUTracing");
	}

	UObject_execSetUTracing_Params SetUTracing_Params;
	memset(&SetUTracing_Params, 0, sizeof(SetUTracing_Params));

	if (!uFnSetUTracing)
	{
		return;
	}
	SetUTracing_Params.bShouldUTrace = bShouldUTrace;

	uint16_t nativeIndex = uFnSetUTracing->iNative;
	uFnSetUTracing->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnSetUTracing, &SetUTracing_Params, nullptr);
	uFnSetUTracing->iNative = nativeIndex;
}

// Function Core.Object.GetFuncName
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// class FName                    ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

class FName UObject::GetFuncName()
{
	static UFunction* uFnGetFuncName = nullptr;

	if (!uFnGetFuncName)
	{
		uFnGetFuncName = UFunction::FindFunction("Function Core.Object.GetFuncName");
	}

	UObject_execGetFuncName_Params GetFuncName_Params;
	memset(&GetFuncName_Params, 0, sizeof(GetFuncName_Params));

	if (!uFnGetFuncName)
	{
		return GetFuncName_Params.ReturnValue;
	}

	uint16_t nativeIndex = uFnGetFuncName->iNative;
	uFnGetFuncName->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnGetFuncName, &GetFuncName_Params, nullptr);
	uFnGetFuncName->iNative = nativeIndex;

	return GetFuncName_Params.ReturnValue;
}

// Function Core.Object.DebugBreak
// [0x00026401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// int32_t                        UserFlags                      (CPF_OptionalParm | CPF_Parm)
// EDebugBreakType                DebuggerType                   (CPF_OptionalParm | CPF_Parm)

void UObject::DebugBreak(int32_t optionalUserFlags, EDebugBreakType optionalDebuggerType)
{
	static UFunction* uFnDebugBreak = nullptr;

	if (!uFnDebugBreak)
	{
		uFnDebugBreak = UFunction::FindFunction("Function Core.Object.DebugBreak");
	}

	UObject_execDebugBreak_Params DebugBreak_Params;
	memset(&DebugBreak_Params, 0, sizeof(DebugBreak_Params));

	if (!uFnDebugBreak)
	{
		return;
	}
	DebugBreak_Params.UserFlags = optionalUserFlags;
	DebugBreak_Params.DebuggerType = static_cast<uint8_t>(optionalDebuggerType);

	uint16_t nativeIndex = uFnDebugBreak->iNative;
	uFnDebugBreak->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnDebugBreak, &DebugBreak_Params, nullptr);
	uFnDebugBreak->iNative = nativeIndex;
}

// Function Core.Object.ScriptTrace
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:

void UObject::ScriptTrace()
{
	static UFunction* uFnScriptTrace = nullptr;

	if (!uFnScriptTrace)
	{
		uFnScriptTrace = UFunction::FindFunction("Function Core.Object.ScriptTrace");
	}

	UObject_execScriptTrace_Params ScriptTrace_Params;
	memset(&ScriptTrace_Params, 0, sizeof(ScriptTrace_Params));

	if (!uFnScriptTrace)
	{
		return;
	}

	uint16_t nativeIndex = uFnScriptTrace->iNative;
	uFnScriptTrace->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnScriptTrace, &ScriptTrace_Params, nullptr);
	uFnScriptTrace->iNative = nativeIndex;
}

// Function Core.Object.ParseLocalizedPropertyPath
// [0x00022003] (FUNC_Final | FUNC_Defined | FUNC_Static | FUNC_Public)
// Parameter Info:
// class FString                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
// class FString                  PathName                       (CPF_Parm | CPF_NeedCtorLink)

class FString UObject::ParseLocalizedPropertyPath(const class FString& PathName)
{
	static UFunction* uFnParseLocalizedPropertyPath = nullptr;

	if (!uFnParseLocalizedPropertyPath)
	{
		uFnParseLocalizedPropertyPath = UFunction::FindFunction("Function Core.Object.ParseLocalizedPropertyPath");
	}

	UObject_execParseLocalizedPropertyPath_Params ParseLocalizedPropertyPath_Params;
	memset(&ParseLocalizedPropertyPath_Params, 0, sizeof(ParseLocalizedPropertyPath_Params));

	if (!uFnParseLocalizedPropertyPath)
	{
		return ParseLocalizedPropertyPath_Params.ReturnValue;
	}
	memcpy_s(&ParseLocalizedPropertyPath_Params.PathName, sizeof(ParseLocalizedPropertyPath_Params.PathName), &PathName, sizeof(PathName));

	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnParseLocalizedPropertyPath, &ParseLocalizedPropertyPath_Params, nullptr);

	return ParseLocalizedPropertyPath_Params.ReturnValue;
}

// Function Core.Object.Localize
// [0x00022400] (FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// class FString                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
// class FString                  SectionName                    (CPF_Parm | CPF_NeedCtorLink)
// class FString                  KeyName                        (CPF_Parm | CPF_NeedCtorLink)
// class FString                  PackageName                    (CPF_Parm | CPF_NeedCtorLink)

class FString UObject::Localize(const class FString& SectionName, const class FString& KeyName, const class FString& PackageName)
{
	static UFunction* uFnLocalize = nullptr;

	if (!uFnLocalize)
	{
		uFnLocalize = UFunction::FindFunction("Function Core.Object.Localize");
	}

	UObject_execLocalize_Params Localize_Params;
	memset(&Localize_Params, 0, sizeof(Localize_Params));

	if (!uFnLocalize)
	{
		return Localize_Params.ReturnValue;
	}
	memcpy_s(&Localize_Params.SectionName, sizeof(Localize_Params.SectionName), &SectionName, sizeof(SectionName));
	memcpy_s(&Localize_Params.KeyName, sizeof(Localize_Params.KeyName), &KeyName, sizeof(KeyName));
	memcpy_s(&Localize_Params.PackageName, sizeof(Localize_Params.PackageName), &PackageName, sizeof(PackageName));

	uint16_t nativeIndex = uFnLocalize->iNative;
	uFnLocalize->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnLocalize, &Localize_Params, nullptr);
	uFnLocalize->iNative = nativeIndex;

	return Localize_Params.ReturnValue;
}

// Function Core.Object.WarnInternal
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public) (iNative[232])
// Parameter Info:
// class FString                  S                              (CPF_Parm | CPF_CoerceParm | CPF_NeedCtorLink)

void UObject::WarnInternal(const class FString& S)
{
	static UFunction* uFnWarnInternal = nullptr;

	if (!uFnWarnInternal)
	{
		uFnWarnInternal = UFunction::FindFunction("Function Core.Object.WarnInternal");
	}

	UObject_execWarnInternal_Params WarnInternal_Params;
	memset(&WarnInternal_Params, 0, sizeof(WarnInternal_Params));

	if (!uFnWarnInternal)
	{
		return;
	}
	memcpy_s(&WarnInternal_Params.S, sizeof(WarnInternal_Params.S), &S, sizeof(S));

	uint16_t nativeIndex = uFnWarnInternal->iNative;
	uFnWarnInternal->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnWarnInternal, &WarnInternal_Params, nullptr);
	uFnWarnInternal->iNative = nativeIndex;
}

// Function Core.Object.LogInternal
// [0x00026401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_OptionalParm | FUNC_Public) (iNative[231])
// Parameter Info:
// class FString                  S                              (CPF_Parm | CPF_CoerceParm | CPF_NeedCtorLink)
// class FName                    Tag                            (CPF_OptionalParm | CPF_Parm)

void UObject::LogInternal(const class FString& S, const class FName& optionalTag)
{
	static UFunction* uFnLogInternal = nullptr;

	if (!uFnLogInternal)
	{
		uFnLogInternal = UFunction::FindFunction("Function Core.Object.LogInternal");
	}

	UObject_execLogInternal_Params LogInternal_Params;
	memset(&LogInternal_Params, 0, sizeof(LogInternal_Params));

	if (!uFnLogInternal)
	{
		return;
	}
	memcpy_s(&LogInternal_Params.S, sizeof(LogInternal_Params.S), &S, sizeof(S));
	memcpy_s(&LogInternal_Params.Tag, sizeof(LogInternal_Params.Tag), &optionalTag, sizeof(optionalTag));

	uint16_t nativeIndex = uFnLogInternal->iNative;
	uFnLogInternal->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnLogInternal, &LogInternal_Params, nullptr);
	uFnLogInternal->iNative = nativeIndex;
}

// Function Core.Object.Subtract_LinearColorLinearColor
// [0x00023003] (FUNC_Final | FUNC_Defined | FUNC_Operator | FUNC_Static | FUNC_Public)
// Parameter Info:
// struct FLinearColor            ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FLinearColor            A                              (CPF_Parm)
// struct FLinearColor            B                              (CPF_Parm)

struct FLinearColor UObject::Subtract_LinearColorLinearColor(const struct FLinearColor& A, const struct FLinearColor& B)
{
	static UFunction* uFnSubtract_LinearColorLinearColor = nullptr;

	if (!uFnSubtract_LinearColorLinearColor)
	{
		uFnSubtract_LinearColorLinearColor = UFunction::FindFunction("Function Core.Object.Subtract_LinearColorLinearColor");
	}

	UObject_execSubtract_LinearColorLinearColor_Params Subtract_LinearColorLinearColor_Params;
	memset(&Subtract_LinearColorLinearColor_Params, 0, sizeof(Subtract_LinearColorLinearColor_Params));

	if (!uFnSubtract_LinearColorLinearColor)
	{
		return Subtract_LinearColorLinearColor_Params.ReturnValue;
	}
	memcpy_s(&Subtract_LinearColorLinearColor_Params.A, sizeof(Subtract_LinearColorLinearColor_Params.A), &A, sizeof(A));
	memcpy_s(&Subtract_LinearColorLinearColor_Params.B, sizeof(Subtract_LinearColorLinearColor_Params.B), &B, sizeof(B));

	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnSubtract_LinearColorLinearColor, &Subtract_LinearColorLinearColor_Params, nullptr);

	return Subtract_LinearColorLinearColor_Params.ReturnValue;
}

// Function Core.Object.Multiply_LinearColorFloat
// [0x00023003] (FUNC_Final | FUNC_Defined | FUNC_Operator | FUNC_Static | FUNC_Public)
// Parameter Info:
// struct FLinearColor            ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FLinearColor            LC                             (CPF_Parm)
// float                          Mult                           (CPF_Parm)

struct FLinearColor UObject::Multiply_LinearColorFloat(const struct FLinearColor& LC, float Mult)
{
	static UFunction* uFnMultiply_LinearColorFloat = nullptr;

	if (!uFnMultiply_LinearColorFloat)
	{
		uFnMultiply_LinearColorFloat = UFunction::FindFunction("Function Core.Object.Multiply_LinearColorFloat");
	}

	UObject_execMultiply_LinearColorFloat_Params Multiply_LinearColorFloat_Params;
	memset(&Multiply_LinearColorFloat_Params, 0, sizeof(Multiply_LinearColorFloat_Params));

	if (!uFnMultiply_LinearColorFloat)
	{
		return Multiply_LinearColorFloat_Params.ReturnValue;
	}
	memcpy_s(&Multiply_LinearColorFloat_Params.LC, sizeof(Multiply_LinearColorFloat_Params.LC), &LC, sizeof(LC));
	Multiply_LinearColorFloat_Params.Mult = Mult;

	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnMultiply_LinearColorFloat, &Multiply_LinearColorFloat_Params, nullptr);

	return Multiply_LinearColorFloat_Params.ReturnValue;
}

// Function Core.Object.ColorToLinearColor
// [0x00022003] (FUNC_Final | FUNC_Defined | FUNC_Static | FUNC_Public)
// Parameter Info:
// struct FLinearColor            ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FColor                  OldColor                       (CPF_Parm)

struct FLinearColor UObject::ColorToLinearColor(const struct FColor& OldColor)
{
	static UFunction* uFnColorToLinearColor = nullptr;

	if (!uFnColorToLinearColor)
	{
		uFnColorToLinearColor = UFunction::FindFunction("Function Core.Object.ColorToLinearColor");
	}

	UObject_execColorToLinearColor_Params ColorToLinearColor_Params;
	memset(&ColorToLinearColor_Params, 0, sizeof(ColorToLinearColor_Params));

	if (!uFnColorToLinearColor)
	{
		return ColorToLinearColor_Params.ReturnValue;
	}
	memcpy_s(&ColorToLinearColor_Params.OldColor, sizeof(ColorToLinearColor_Params.OldColor), &OldColor, sizeof(OldColor));

	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnColorToLinearColor, &ColorToLinearColor_Params, nullptr);

	return ColorToLinearColor_Params.ReturnValue;
}

// Function Core.Object.MakeLinearColor
// [0x00822003] (FUNC_Final | FUNC_Defined | FUNC_Static | FUNC_Public | FUNC_HasDefaults)
// Parameter Info:
// struct FLinearColor            ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          R                              (CPF_Parm)
// float                          G                              (CPF_Parm)
// float                          B                              (CPF_Parm)
// float                          A                              (CPF_Parm)

struct FLinearColor UObject::MakeLinearColor(float R, float G, float B, float A)
{
	static UFunction* uFnMakeLinearColor = nullptr;

	if (!uFnMakeLinearColor)
	{
		uFnMakeLinearColor = UFunction::FindFunction("Function Core.Object.MakeLinearColor");
	}

	UObject_execMakeLinearColor_Params MakeLinearColor_Params;
	memset(&MakeLinearColor_Params, 0, sizeof(MakeLinearColor_Params));

	if (!uFnMakeLinearColor)
	{
		return MakeLinearColor_Params.ReturnValue;
	}
	MakeLinearColor_Params.R = R;
	MakeLinearColor_Params.G = G;
	MakeLinearColor_Params.B = B;
	MakeLinearColor_Params.A = A;

	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnMakeLinearColor, &MakeLinearColor_Params, nullptr);

	return MakeLinearColor_Params.ReturnValue;
}

// Function Core.Object.LerpColor
// [0x00822003] (FUNC_Final | FUNC_Defined | FUNC_Static | FUNC_Public | FUNC_HasDefaults)
// Parameter Info:
// struct FColor                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FColor                  A                              (CPF_Parm)
// struct FColor                  B                              (CPF_Parm)
// float                          Alpha                          (CPF_Parm)

struct FColor UObject::LerpColor(const struct FColor& A, const struct FColor& B, float Alpha)
{
	static UFunction* uFnLerpColor = nullptr;

	if (!uFnLerpColor)
	{
		uFnLerpColor = UFunction::FindFunction("Function Core.Object.LerpColor");
	}

	UObject_execLerpColor_Params LerpColor_Params;
	memset(&LerpColor_Params, 0, sizeof(LerpColor_Params));

	if (!uFnLerpColor)
	{
		return LerpColor_Params.ReturnValue;
	}
	memcpy_s(&LerpColor_Params.A, sizeof(LerpColor_Params.A), &A, sizeof(A));
	memcpy_s(&LerpColor_Params.B, sizeof(LerpColor_Params.B), &B, sizeof(B));
	LerpColor_Params.Alpha = Alpha;

	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnLerpColor, &LerpColor_Params, nullptr);

	return LerpColor_Params.ReturnValue;
}

// Function Core.Object.MakeColor
// [0x00826003] (FUNC_Final | FUNC_Defined | FUNC_Static | FUNC_OptionalParm | FUNC_Public | FUNC_HasDefaults)
// Parameter Info:
// struct FColor                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// uint8_t                        R                              (CPF_Parm)
// uint8_t                        G                              (CPF_Parm)
// uint8_t                        B                              (CPF_Parm)
// uint8_t                        A                              (CPF_OptionalParm | CPF_Parm)

struct FColor UObject::MakeColor(uint8_t R, uint8_t G, uint8_t B, uint8_t optionalA)
{
	static UFunction* uFnMakeColor = nullptr;

	if (!uFnMakeColor)
	{
		uFnMakeColor = UFunction::FindFunction("Function Core.Object.MakeColor");
	}

	UObject_execMakeColor_Params MakeColor_Params;
	memset(&MakeColor_Params, 0, sizeof(MakeColor_Params));

	if (!uFnMakeColor)
	{
		return MakeColor_Params.ReturnValue;
	}
	MakeColor_Params.R = static_cast<uint8_t>(R);
	MakeColor_Params.G = static_cast<uint8_t>(G);
	MakeColor_Params.B = static_cast<uint8_t>(B);
	MakeColor_Params.A = static_cast<uint8_t>(optionalA);

	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnMakeColor, &MakeColor_Params, nullptr);

	return MakeColor_Params.ReturnValue;
}

// Function Core.Object.Add_ColorColor
// [0x00023003] (FUNC_Final | FUNC_Defined | FUNC_Operator | FUNC_Static | FUNC_Public)
// Parameter Info:
// struct FColor                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FColor                  A                              (CPF_Parm)
// struct FColor                  B                              (CPF_Parm)

struct FColor UObject::Add_ColorColor(const struct FColor& A, const struct FColor& B)
{
	static UFunction* uFnAdd_ColorColor = nullptr;

	if (!uFnAdd_ColorColor)
	{
		uFnAdd_ColorColor = UFunction::FindFunction("Function Core.Object.Add_ColorColor");
	}

	UObject_execAdd_ColorColor_Params Add_ColorColor_Params;
	memset(&Add_ColorColor_Params, 0, sizeof(Add_ColorColor_Params));

	if (!uFnAdd_ColorColor)
	{
		return Add_ColorColor_Params.ReturnValue;
	}
	memcpy_s(&Add_ColorColor_Params.A, sizeof(Add_ColorColor_Params.A), &A, sizeof(A));
	memcpy_s(&Add_ColorColor_Params.B, sizeof(Add_ColorColor_Params.B), &B, sizeof(B));

	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnAdd_ColorColor, &Add_ColorColor_Params, nullptr);

	return Add_ColorColor_Params.ReturnValue;
}

// Function Core.Object.Multiply_ColorFloat
// [0x00023003] (FUNC_Final | FUNC_Defined | FUNC_Operator | FUNC_Static | FUNC_Public)
// Parameter Info:
// struct FColor                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FColor                  A                              (CPF_Parm)
// float                          B                              (CPF_Parm)

struct FColor UObject::Multiply_ColorFloat(const struct FColor& A, float B)
{
	static UFunction* uFnMultiply_ColorFloat = nullptr;

	if (!uFnMultiply_ColorFloat)
	{
		uFnMultiply_ColorFloat = UFunction::FindFunction("Function Core.Object.Multiply_ColorFloat");
	}

	UObject_execMultiply_ColorFloat_Params Multiply_ColorFloat_Params;
	memset(&Multiply_ColorFloat_Params, 0, sizeof(Multiply_ColorFloat_Params));

	if (!uFnMultiply_ColorFloat)
	{
		return Multiply_ColorFloat_Params.ReturnValue;
	}
	memcpy_s(&Multiply_ColorFloat_Params.A, sizeof(Multiply_ColorFloat_Params.A), &A, sizeof(A));
	Multiply_ColorFloat_Params.B = B;

	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnMultiply_ColorFloat, &Multiply_ColorFloat_Params, nullptr);

	return Multiply_ColorFloat_Params.ReturnValue;
}

// Function Core.Object.Multiply_FloatColor
// [0x00023003] (FUNC_Final | FUNC_Defined | FUNC_Operator | FUNC_Static | FUNC_Public)
// Parameter Info:
// struct FColor                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          A                              (CPF_Parm)
// struct FColor                  B                              (CPF_Parm)

struct FColor UObject::Multiply_FloatColor(float A, const struct FColor& B)
{
	static UFunction* uFnMultiply_FloatColor = nullptr;

	if (!uFnMultiply_FloatColor)
	{
		uFnMultiply_FloatColor = UFunction::FindFunction("Function Core.Object.Multiply_FloatColor");
	}

	UObject_execMultiply_FloatColor_Params Multiply_FloatColor_Params;
	memset(&Multiply_FloatColor_Params, 0, sizeof(Multiply_FloatColor_Params));

	if (!uFnMultiply_FloatColor)
	{
		return Multiply_FloatColor_Params.ReturnValue;
	}
	Multiply_FloatColor_Params.A = A;
	memcpy_s(&Multiply_FloatColor_Params.B, sizeof(Multiply_FloatColor_Params.B), &B, sizeof(B));

	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnMultiply_FloatColor, &Multiply_FloatColor_Params, nullptr);

	return Multiply_FloatColor_Params.ReturnValue;
}

// Function Core.Object.Subtract_ColorColor
// [0x00023003] (FUNC_Final | FUNC_Defined | FUNC_Operator | FUNC_Static | FUNC_Public)
// Parameter Info:
// struct FColor                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FColor                  A                              (CPF_Parm)
// struct FColor                  B                              (CPF_Parm)

struct FColor UObject::Subtract_ColorColor(const struct FColor& A, const struct FColor& B)
{
	static UFunction* uFnSubtract_ColorColor = nullptr;

	if (!uFnSubtract_ColorColor)
	{
		uFnSubtract_ColorColor = UFunction::FindFunction("Function Core.Object.Subtract_ColorColor");
	}

	UObject_execSubtract_ColorColor_Params Subtract_ColorColor_Params;
	memset(&Subtract_ColorColor_Params, 0, sizeof(Subtract_ColorColor_Params));

	if (!uFnSubtract_ColorColor)
	{
		return Subtract_ColorColor_Params.ReturnValue;
	}
	memcpy_s(&Subtract_ColorColor_Params.A, sizeof(Subtract_ColorColor_Params.A), &A, sizeof(A));
	memcpy_s(&Subtract_ColorColor_Params.B, sizeof(Subtract_ColorColor_Params.B), &B, sizeof(B));

	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnSubtract_ColorColor, &Subtract_ColorColor_Params, nullptr);

	return Subtract_ColorColor_Params.ReturnValue;
}

// Function Core.Object.EvalInterpCurveVector2D
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// struct FVector2D               ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FInterpCurveVector2D    Vector2DCurve                  (CPF_Parm | CPF_NeedCtorLink)
// float                          InVal                          (CPF_Parm)

struct FVector2D UObject::EvalInterpCurveVector2D(const struct FInterpCurveVector2D& Vector2DCurve, float InVal)
{
	static UFunction* uFnEvalInterpCurveVector2D = nullptr;

	if (!uFnEvalInterpCurveVector2D)
	{
		uFnEvalInterpCurveVector2D = UFunction::FindFunction("Function Core.Object.EvalInterpCurveVector2D");
	}

	UObject_execEvalInterpCurveVector2D_Params EvalInterpCurveVector2D_Params;
	memset(&EvalInterpCurveVector2D_Params, 0, sizeof(EvalInterpCurveVector2D_Params));

	if (!uFnEvalInterpCurveVector2D)
	{
		return EvalInterpCurveVector2D_Params.ReturnValue;
	}
	memcpy_s(&EvalInterpCurveVector2D_Params.Vector2DCurve, sizeof(EvalInterpCurveVector2D_Params.Vector2DCurve), &Vector2DCurve, sizeof(Vector2DCurve));
	EvalInterpCurveVector2D_Params.InVal = InVal;

	uint16_t nativeIndex = uFnEvalInterpCurveVector2D->iNative;
	uFnEvalInterpCurveVector2D->iNative = 0;
	this->ProcessEvent(uFnEvalInterpCurveVector2D, &EvalInterpCurveVector2D_Params, nullptr);
	uFnEvalInterpCurveVector2D->iNative = nativeIndex;

	return EvalInterpCurveVector2D_Params.ReturnValue;
}

// Function Core.Object.EvalInterpCurveVector
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FInterpCurveVector      VectorCurve                    (CPF_Parm | CPF_NeedCtorLink)
// float                          InVal                          (CPF_Parm)

struct FVector UObject::EvalInterpCurveVector(const struct FInterpCurveVector& VectorCurve, float InVal)
{
	static UFunction* uFnEvalInterpCurveVector = nullptr;

	if (!uFnEvalInterpCurveVector)
	{
		uFnEvalInterpCurveVector = UFunction::FindFunction("Function Core.Object.EvalInterpCurveVector");
	}

	UObject_execEvalInterpCurveVector_Params EvalInterpCurveVector_Params;
	memset(&EvalInterpCurveVector_Params, 0, sizeof(EvalInterpCurveVector_Params));

	if (!uFnEvalInterpCurveVector)
	{
		return EvalInterpCurveVector_Params.ReturnValue;
	}
	memcpy_s(&EvalInterpCurveVector_Params.VectorCurve, sizeof(EvalInterpCurveVector_Params.VectorCurve), &VectorCurve, sizeof(VectorCurve));
	EvalInterpCurveVector_Params.InVal = InVal;

	uint16_t nativeIndex = uFnEvalInterpCurveVector->iNative;
	uFnEvalInterpCurveVector->iNative = 0;
	this->ProcessEvent(uFnEvalInterpCurveVector, &EvalInterpCurveVector_Params, nullptr);
	uFnEvalInterpCurveVector->iNative = nativeIndex;

	return EvalInterpCurveVector_Params.ReturnValue;
}

// Function Core.Object.EvalInterpCurveFloat
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public)
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FInterpCurveFloat       FloatCurve                     (CPF_Parm | CPF_NeedCtorLink)
// float                          InVal                          (CPF_Parm)

float UObject::EvalInterpCurveFloat(const struct FInterpCurveFloat& FloatCurve, float InVal)
{
	static UFunction* uFnEvalInterpCurveFloat = nullptr;

	if (!uFnEvalInterpCurveFloat)
	{
		uFnEvalInterpCurveFloat = UFunction::FindFunction("Function Core.Object.EvalInterpCurveFloat");
	}

	UObject_execEvalInterpCurveFloat_Params EvalInterpCurveFloat_Params;
	memset(&EvalInterpCurveFloat_Params, 0, sizeof(EvalInterpCurveFloat_Params));

	if (!uFnEvalInterpCurveFloat)
	{
		return EvalInterpCurveFloat_Params.ReturnValue;
	}
	memcpy_s(&EvalInterpCurveFloat_Params.FloatCurve, sizeof(EvalInterpCurveFloat_Params.FloatCurve), &FloatCurve, sizeof(FloatCurve));
	EvalInterpCurveFloat_Params.InVal = InVal;

	uint16_t nativeIndex = uFnEvalInterpCurveFloat->iNative;
	uFnEvalInterpCurveFloat->iNative = 0;
	this->ProcessEvent(uFnEvalInterpCurveFloat, &EvalInterpCurveFloat_Params, nullptr);
	uFnEvalInterpCurveFloat->iNative = nativeIndex;

	return EvalInterpCurveFloat_Params.ReturnValue;
}

// Function Core.Object.vect2d
// [0x00822003] (FUNC_Final | FUNC_Defined | FUNC_Static | FUNC_Public | FUNC_HasDefaults)
// Parameter Info:
// struct FVector2D               ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          InX                            (CPF_Parm)
// float                          InY                            (CPF_Parm)

struct FVector2D UObject::vect2d(float InX, float InY)
{
	static UFunction* uFnvect2d = nullptr;

	if (!uFnvect2d)
	{
		uFnvect2d = UFunction::FindFunction("Function Core.Object.vect2d");
	}

	UObject_execvect2d_Params vect2d_Params;
	memset(&vect2d_Params, 0, sizeof(vect2d_Params));

	if (!uFnvect2d)
	{
		return vect2d_Params.ReturnValue;
	}
	vect2d_Params.InX = InX;
	vect2d_Params.InY = InY;

	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnvect2d, &vect2d_Params, nullptr);

	return vect2d_Params.ReturnValue;
}

// Function Core.Object.GetMappedRangeValue
// [0x00022501] (FUNC_Final | FUNC_Simulated | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector2D               InputRange                     (CPF_Parm)
// struct FVector2D               OutputRange                    (CPF_Parm)
// float                          Value                          (CPF_Parm)

float UObject::GetMappedRangeValue(const struct FVector2D& InputRange, const struct FVector2D& OutputRange, float Value)
{
	static UFunction* uFnGetMappedRangeValue = nullptr;

	if (!uFnGetMappedRangeValue)
	{
		uFnGetMappedRangeValue = UFunction::FindFunction("Function Core.Object.GetMappedRangeValue");
	}

	UObject_execGetMappedRangeValue_Params GetMappedRangeValue_Params;
	memset(&GetMappedRangeValue_Params, 0, sizeof(GetMappedRangeValue_Params));

	if (!uFnGetMappedRangeValue)
	{
		return GetMappedRangeValue_Params.ReturnValue;
	}
	memcpy_s(&GetMappedRangeValue_Params.InputRange, sizeof(GetMappedRangeValue_Params.InputRange), &InputRange, sizeof(InputRange));
	memcpy_s(&GetMappedRangeValue_Params.OutputRange, sizeof(GetMappedRangeValue_Params.OutputRange), &OutputRange, sizeof(OutputRange));
	GetMappedRangeValue_Params.Value = Value;

	uint16_t nativeIndex = uFnGetMappedRangeValue->iNative;
	uFnGetMappedRangeValue->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnGetMappedRangeValue, &GetMappedRangeValue_Params, nullptr);
	uFnGetMappedRangeValue->iNative = nativeIndex;

	return GetMappedRangeValue_Params.ReturnValue;
}

// Function Core.Object.GetRangePctByValue
// [0x00022103] (FUNC_Final | FUNC_Defined | FUNC_Simulated | FUNC_Static | FUNC_Public)
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector2D               Range                          (CPF_Parm)
// float                          Value                          (CPF_Parm)

float UObject::GetRangePctByValue(const struct FVector2D& Range, float Value)
{
	static UFunction* uFnGetRangePctByValue = nullptr;

	if (!uFnGetRangePctByValue)
	{
		uFnGetRangePctByValue = UFunction::FindFunction("Function Core.Object.GetRangePctByValue");
	}

	UObject_execGetRangePctByValue_Params GetRangePctByValue_Params;
	memset(&GetRangePctByValue_Params, 0, sizeof(GetRangePctByValue_Params));

	if (!uFnGetRangePctByValue)
	{
		return GetRangePctByValue_Params.ReturnValue;
	}
	memcpy_s(&GetRangePctByValue_Params.Range, sizeof(GetRangePctByValue_Params.Range), &Range, sizeof(Range));
	GetRangePctByValue_Params.Value = Value;

	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnGetRangePctByValue, &GetRangePctByValue_Params, nullptr);

	return GetRangePctByValue_Params.ReturnValue;
}

// Function Core.Object.GetRangeValueByPct
// [0x00022103] (FUNC_Final | FUNC_Defined | FUNC_Simulated | FUNC_Static | FUNC_Public)
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector2D               Range                          (CPF_Parm)
// float                          Pct                            (CPF_Parm)

float UObject::GetRangeValueByPct(const struct FVector2D& Range, float Pct)
{
	static UFunction* uFnGetRangeValueByPct = nullptr;

	if (!uFnGetRangeValueByPct)
	{
		uFnGetRangeValueByPct = UFunction::FindFunction("Function Core.Object.GetRangeValueByPct");
	}

	UObject_execGetRangeValueByPct_Params GetRangeValueByPct_Params;
	memset(&GetRangeValueByPct_Params, 0, sizeof(GetRangeValueByPct_Params));

	if (!uFnGetRangeValueByPct)
	{
		return GetRangeValueByPct_Params.ReturnValue;
	}
	memcpy_s(&GetRangeValueByPct_Params.Range, sizeof(GetRangeValueByPct_Params.Range), &Range, sizeof(Range));
	GetRangeValueByPct_Params.Pct = Pct;

	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnGetRangeValueByPct, &GetRangeValueByPct_Params, nullptr);

	return GetRangeValueByPct_Params.ReturnValue;
}

// Function Core.Object.Subtract_Vector2DVector2D
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public)
// Parameter Info:
// struct FVector2D               ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector2D               A                              (CPF_Parm)
// struct FVector2D               B                              (CPF_Parm)

struct FVector2D UObject::Subtract_Vector2DVector2D(const struct FVector2D& A, const struct FVector2D& B)
{
	static UFunction* uFnSubtract_Vector2DVector2D = nullptr;

	if (!uFnSubtract_Vector2DVector2D)
	{
		uFnSubtract_Vector2DVector2D = UFunction::FindFunction("Function Core.Object.Subtract_Vector2DVector2D");
	}

	UObject_execSubtract_Vector2DVector2D_Params Subtract_Vector2DVector2D_Params;
	memset(&Subtract_Vector2DVector2D_Params, 0, sizeof(Subtract_Vector2DVector2D_Params));

	if (!uFnSubtract_Vector2DVector2D)
	{
		return Subtract_Vector2DVector2D_Params.ReturnValue;
	}
	memcpy_s(&Subtract_Vector2DVector2D_Params.A, sizeof(Subtract_Vector2DVector2D_Params.A), &A, sizeof(A));
	memcpy_s(&Subtract_Vector2DVector2D_Params.B, sizeof(Subtract_Vector2DVector2D_Params.B), &B, sizeof(B));

	uint16_t nativeIndex = uFnSubtract_Vector2DVector2D->iNative;
	uFnSubtract_Vector2DVector2D->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnSubtract_Vector2DVector2D, &Subtract_Vector2DVector2D_Params, nullptr);
	uFnSubtract_Vector2DVector2D->iNative = nativeIndex;

	return Subtract_Vector2DVector2D_Params.ReturnValue;
}

// Function Core.Object.Add_Vector2DVector2D
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public)
// Parameter Info:
// struct FVector2D               ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector2D               A                              (CPF_Parm)
// struct FVector2D               B                              (CPF_Parm)

struct FVector2D UObject::Add_Vector2DVector2D(const struct FVector2D& A, const struct FVector2D& B)
{
	static UFunction* uFnAdd_Vector2DVector2D = nullptr;

	if (!uFnAdd_Vector2DVector2D)
	{
		uFnAdd_Vector2DVector2D = UFunction::FindFunction("Function Core.Object.Add_Vector2DVector2D");
	}

	UObject_execAdd_Vector2DVector2D_Params Add_Vector2DVector2D_Params;
	memset(&Add_Vector2DVector2D_Params, 0, sizeof(Add_Vector2DVector2D_Params));

	if (!uFnAdd_Vector2DVector2D)
	{
		return Add_Vector2DVector2D_Params.ReturnValue;
	}
	memcpy_s(&Add_Vector2DVector2D_Params.A, sizeof(Add_Vector2DVector2D_Params.A), &A, sizeof(A));
	memcpy_s(&Add_Vector2DVector2D_Params.B, sizeof(Add_Vector2DVector2D_Params.B), &B, sizeof(B));

	uint16_t nativeIndex = uFnAdd_Vector2DVector2D->iNative;
	uFnAdd_Vector2DVector2D->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnAdd_Vector2DVector2D, &Add_Vector2DVector2D_Params, nullptr);
	uFnAdd_Vector2DVector2D->iNative = nativeIndex;

	return Add_Vector2DVector2D_Params.ReturnValue;
}

// Function Core.Object.Subtract_QuatQuat
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[271])
// Parameter Info:
// struct FQuat                   ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FQuat                   A                              (CPF_Parm)
// struct FQuat                   B                              (CPF_Parm)

struct FQuat UObject::Subtract_QuatQuat(const struct FQuat& A, const struct FQuat& B)
{
	static UFunction* uFnSubtract_QuatQuat = nullptr;

	if (!uFnSubtract_QuatQuat)
	{
		uFnSubtract_QuatQuat = UFunction::FindFunction("Function Core.Object.Subtract_QuatQuat");
	}

	UObject_execSubtract_QuatQuat_Params Subtract_QuatQuat_Params;
	memset(&Subtract_QuatQuat_Params, 0, sizeof(Subtract_QuatQuat_Params));

	if (!uFnSubtract_QuatQuat)
	{
		return Subtract_QuatQuat_Params.ReturnValue;
	}
	memcpy_s(&Subtract_QuatQuat_Params.A, sizeof(Subtract_QuatQuat_Params.A), &A, sizeof(A));
	memcpy_s(&Subtract_QuatQuat_Params.B, sizeof(Subtract_QuatQuat_Params.B), &B, sizeof(B));

	uint16_t nativeIndex = uFnSubtract_QuatQuat->iNative;
	uFnSubtract_QuatQuat->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnSubtract_QuatQuat, &Subtract_QuatQuat_Params, nullptr);
	uFnSubtract_QuatQuat->iNative = nativeIndex;

	return Subtract_QuatQuat_Params.ReturnValue;
}

// Function Core.Object.Add_QuatQuat
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[270])
// Parameter Info:
// struct FQuat                   ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FQuat                   A                              (CPF_Parm)
// struct FQuat                   B                              (CPF_Parm)

struct FQuat UObject::Add_QuatQuat(const struct FQuat& A, const struct FQuat& B)
{
	static UFunction* uFnAdd_QuatQuat = nullptr;

	if (!uFnAdd_QuatQuat)
	{
		uFnAdd_QuatQuat = UFunction::FindFunction("Function Core.Object.Add_QuatQuat");
	}

	UObject_execAdd_QuatQuat_Params Add_QuatQuat_Params;
	memset(&Add_QuatQuat_Params, 0, sizeof(Add_QuatQuat_Params));

	if (!uFnAdd_QuatQuat)
	{
		return Add_QuatQuat_Params.ReturnValue;
	}
	memcpy_s(&Add_QuatQuat_Params.A, sizeof(Add_QuatQuat_Params.A), &A, sizeof(A));
	memcpy_s(&Add_QuatQuat_Params.B, sizeof(Add_QuatQuat_Params.B), &B, sizeof(B));

	uint16_t nativeIndex = uFnAdd_QuatQuat->iNative;
	uFnAdd_QuatQuat->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnAdd_QuatQuat, &Add_QuatQuat_Params, nullptr);
	uFnAdd_QuatQuat->iNative = nativeIndex;

	return Add_QuatQuat_Params.ReturnValue;
}

// Function Core.Object.QuatSlerp
// [0x00026401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// struct FQuat                   ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FQuat                   A                              (CPF_Parm)
// struct FQuat                   B                              (CPF_Parm)
// float                          Alpha                          (CPF_Parm)
// uint32_t                       bShortestPath                  (CPF_OptionalParm | CPF_Parm)

struct FQuat UObject::QuatSlerp(const struct FQuat& A, const struct FQuat& B, float Alpha, bool optionalBShortestPath)
{
	static UFunction* uFnQuatSlerp = nullptr;

	if (!uFnQuatSlerp)
	{
		uFnQuatSlerp = UFunction::FindFunction("Function Core.Object.QuatSlerp");
	}

	UObject_execQuatSlerp_Params QuatSlerp_Params;
	memset(&QuatSlerp_Params, 0, sizeof(QuatSlerp_Params));

	if (!uFnQuatSlerp)
	{
		return QuatSlerp_Params.ReturnValue;
	}
	memcpy_s(&QuatSlerp_Params.A, sizeof(QuatSlerp_Params.A), &A, sizeof(A));
	memcpy_s(&QuatSlerp_Params.B, sizeof(QuatSlerp_Params.B), &B, sizeof(B));
	QuatSlerp_Params.Alpha = Alpha;
	QuatSlerp_Params.bShortestPath = optionalBShortestPath;

	uint16_t nativeIndex = uFnQuatSlerp->iNative;
	uFnQuatSlerp->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnQuatSlerp, &QuatSlerp_Params, nullptr);
	uFnQuatSlerp->iNative = nativeIndex;

	return QuatSlerp_Params.ReturnValue;
}

// Function Core.Object.QuatToRotator
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// struct FRotator                ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FQuat                   A                              (CPF_Parm)

struct FRotator UObject::QuatToRotator(const struct FQuat& A)
{
	static UFunction* uFnQuatToRotator = nullptr;

	if (!uFnQuatToRotator)
	{
		uFnQuatToRotator = UFunction::FindFunction("Function Core.Object.QuatToRotator");
	}

	UObject_execQuatToRotator_Params QuatToRotator_Params;
	memset(&QuatToRotator_Params, 0, sizeof(QuatToRotator_Params));

	if (!uFnQuatToRotator)
	{
		return QuatToRotator_Params.ReturnValue;
	}
	memcpy_s(&QuatToRotator_Params.A, sizeof(QuatToRotator_Params.A), &A, sizeof(A));

	uint16_t nativeIndex = uFnQuatToRotator->iNative;
	uFnQuatToRotator->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnQuatToRotator, &QuatToRotator_Params, nullptr);
	uFnQuatToRotator->iNative = nativeIndex;

	return QuatToRotator_Params.ReturnValue;
}

// Function Core.Object.QuatFromRotator
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// struct FQuat                   ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FRotator                A                              (CPF_Parm)

struct FQuat UObject::QuatFromRotator(const struct FRotator& A)
{
	static UFunction* uFnQuatFromRotator = nullptr;

	if (!uFnQuatFromRotator)
	{
		uFnQuatFromRotator = UFunction::FindFunction("Function Core.Object.QuatFromRotator");
	}

	UObject_execQuatFromRotator_Params QuatFromRotator_Params;
	memset(&QuatFromRotator_Params, 0, sizeof(QuatFromRotator_Params));

	if (!uFnQuatFromRotator)
	{
		return QuatFromRotator_Params.ReturnValue;
	}
	memcpy_s(&QuatFromRotator_Params.A, sizeof(QuatFromRotator_Params.A), &A, sizeof(A));

	uint16_t nativeIndex = uFnQuatFromRotator->iNative;
	uFnQuatFromRotator->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnQuatFromRotator, &QuatFromRotator_Params, nullptr);
	uFnQuatFromRotator->iNative = nativeIndex;

	return QuatFromRotator_Params.ReturnValue;
}

// Function Core.Object.QuatFromAxisAndAngle
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// struct FQuat                   ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 Axis                           (CPF_Parm)
// float                          Angle                          (CPF_Parm)

struct FQuat UObject::QuatFromAxisAndAngle(const struct FVector& Axis, float Angle)
{
	static UFunction* uFnQuatFromAxisAndAngle = nullptr;

	if (!uFnQuatFromAxisAndAngle)
	{
		uFnQuatFromAxisAndAngle = UFunction::FindFunction("Function Core.Object.QuatFromAxisAndAngle");
	}

	UObject_execQuatFromAxisAndAngle_Params QuatFromAxisAndAngle_Params;
	memset(&QuatFromAxisAndAngle_Params, 0, sizeof(QuatFromAxisAndAngle_Params));

	if (!uFnQuatFromAxisAndAngle)
	{
		return QuatFromAxisAndAngle_Params.ReturnValue;
	}
	memcpy_s(&QuatFromAxisAndAngle_Params.Axis, sizeof(QuatFromAxisAndAngle_Params.Axis), &Axis, sizeof(Axis));
	QuatFromAxisAndAngle_Params.Angle = Angle;

	uint16_t nativeIndex = uFnQuatFromAxisAndAngle->iNative;
	uFnQuatFromAxisAndAngle->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnQuatFromAxisAndAngle, &QuatFromAxisAndAngle_Params, nullptr);
	uFnQuatFromAxisAndAngle->iNative = nativeIndex;

	return QuatFromAxisAndAngle_Params.ReturnValue;
}

// Function Core.Object.QuatFindBetween
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// struct FQuat                   ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 A                              (CPF_Parm)
// struct FVector                 B                              (CPF_Parm)

struct FQuat UObject::QuatFindBetween(const struct FVector& A, const struct FVector& B)
{
	static UFunction* uFnQuatFindBetween = nullptr;

	if (!uFnQuatFindBetween)
	{
		uFnQuatFindBetween = UFunction::FindFunction("Function Core.Object.QuatFindBetween");
	}

	UObject_execQuatFindBetween_Params QuatFindBetween_Params;
	memset(&QuatFindBetween_Params, 0, sizeof(QuatFindBetween_Params));

	if (!uFnQuatFindBetween)
	{
		return QuatFindBetween_Params.ReturnValue;
	}
	memcpy_s(&QuatFindBetween_Params.A, sizeof(QuatFindBetween_Params.A), &A, sizeof(A));
	memcpy_s(&QuatFindBetween_Params.B, sizeof(QuatFindBetween_Params.B), &B, sizeof(B));

	uint16_t nativeIndex = uFnQuatFindBetween->iNative;
	uFnQuatFindBetween->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnQuatFindBetween, &QuatFindBetween_Params, nullptr);
	uFnQuatFindBetween->iNative = nativeIndex;

	return QuatFindBetween_Params.ReturnValue;
}

// Function Core.Object.QuatRotateVector
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FQuat                   A                              (CPF_Parm)
// struct FVector                 B                              (CPF_Parm)

struct FVector UObject::QuatRotateVector(const struct FQuat& A, const struct FVector& B)
{
	static UFunction* uFnQuatRotateVector = nullptr;

	if (!uFnQuatRotateVector)
	{
		uFnQuatRotateVector = UFunction::FindFunction("Function Core.Object.QuatRotateVector");
	}

	UObject_execQuatRotateVector_Params QuatRotateVector_Params;
	memset(&QuatRotateVector_Params, 0, sizeof(QuatRotateVector_Params));

	if (!uFnQuatRotateVector)
	{
		return QuatRotateVector_Params.ReturnValue;
	}
	memcpy_s(&QuatRotateVector_Params.A, sizeof(QuatRotateVector_Params.A), &A, sizeof(A));
	memcpy_s(&QuatRotateVector_Params.B, sizeof(QuatRotateVector_Params.B), &B, sizeof(B));

	uint16_t nativeIndex = uFnQuatRotateVector->iNative;
	uFnQuatRotateVector->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnQuatRotateVector, &QuatRotateVector_Params, nullptr);
	uFnQuatRotateVector->iNative = nativeIndex;

	return QuatRotateVector_Params.ReturnValue;
}

// Function Core.Object.QuatInvert
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// struct FQuat                   ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FQuat                   A                              (CPF_Parm)

struct FQuat UObject::QuatInvert(const struct FQuat& A)
{
	static UFunction* uFnQuatInvert = nullptr;

	if (!uFnQuatInvert)
	{
		uFnQuatInvert = UFunction::FindFunction("Function Core.Object.QuatInvert");
	}

	UObject_execQuatInvert_Params QuatInvert_Params;
	memset(&QuatInvert_Params, 0, sizeof(QuatInvert_Params));

	if (!uFnQuatInvert)
	{
		return QuatInvert_Params.ReturnValue;
	}
	memcpy_s(&QuatInvert_Params.A, sizeof(QuatInvert_Params.A), &A, sizeof(A));

	uint16_t nativeIndex = uFnQuatInvert->iNative;
	uFnQuatInvert->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnQuatInvert, &QuatInvert_Params, nullptr);
	uFnQuatInvert->iNative = nativeIndex;

	return QuatInvert_Params.ReturnValue;
}

// Function Core.Object.QuatDot
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FQuat                   A                              (CPF_Parm)
// struct FQuat                   B                              (CPF_Parm)

float UObject::QuatDot(const struct FQuat& A, const struct FQuat& B)
{
	static UFunction* uFnQuatDot = nullptr;

	if (!uFnQuatDot)
	{
		uFnQuatDot = UFunction::FindFunction("Function Core.Object.QuatDot");
	}

	UObject_execQuatDot_Params QuatDot_Params;
	memset(&QuatDot_Params, 0, sizeof(QuatDot_Params));

	if (!uFnQuatDot)
	{
		return QuatDot_Params.ReturnValue;
	}
	memcpy_s(&QuatDot_Params.A, sizeof(QuatDot_Params.A), &A, sizeof(A));
	memcpy_s(&QuatDot_Params.B, sizeof(QuatDot_Params.B), &B, sizeof(B));

	uint16_t nativeIndex = uFnQuatDot->iNative;
	uFnQuatDot->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnQuatDot, &QuatDot_Params, nullptr);
	uFnQuatDot->iNative = nativeIndex;

	return QuatDot_Params.ReturnValue;
}

// Function Core.Object.QuatProduct
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// struct FQuat                   ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FQuat                   A                              (CPF_Parm)
// struct FQuat                   B                              (CPF_Parm)

struct FQuat UObject::QuatProduct(const struct FQuat& A, const struct FQuat& B)
{
	static UFunction* uFnQuatProduct = nullptr;

	if (!uFnQuatProduct)
	{
		uFnQuatProduct = UFunction::FindFunction("Function Core.Object.QuatProduct");
	}

	UObject_execQuatProduct_Params QuatProduct_Params;
	memset(&QuatProduct_Params, 0, sizeof(QuatProduct_Params));

	if (!uFnQuatProduct)
	{
		return QuatProduct_Params.ReturnValue;
	}
	memcpy_s(&QuatProduct_Params.A, sizeof(QuatProduct_Params.A), &A, sizeof(A));
	memcpy_s(&QuatProduct_Params.B, sizeof(QuatProduct_Params.B), &B, sizeof(B));

	uint16_t nativeIndex = uFnQuatProduct->iNative;
	uFnQuatProduct->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnQuatProduct, &QuatProduct_Params, nullptr);
	uFnQuatProduct->iNative = nativeIndex;

	return QuatProduct_Params.ReturnValue;
}

// Function Core.Object.MatrixGetAxis
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FMatrix                 TM                             (CPF_Parm)
// EAxis                          Axis                           (CPF_Parm)

struct FVector UObject::MatrixGetAxis(const struct FMatrix& TM, EAxis Axis)
{
	static UFunction* uFnMatrixGetAxis = nullptr;

	if (!uFnMatrixGetAxis)
	{
		uFnMatrixGetAxis = UFunction::FindFunction("Function Core.Object.MatrixGetAxis");
	}

	UObject_execMatrixGetAxis_Params MatrixGetAxis_Params;
	memset(&MatrixGetAxis_Params, 0, sizeof(MatrixGetAxis_Params));

	if (!uFnMatrixGetAxis)
	{
		return MatrixGetAxis_Params.ReturnValue;
	}
	memcpy_s(&MatrixGetAxis_Params.TM, sizeof(MatrixGetAxis_Params.TM), &TM, sizeof(TM));
	MatrixGetAxis_Params.Axis = static_cast<uint8_t>(Axis);

	uint16_t nativeIndex = uFnMatrixGetAxis->iNative;
	uFnMatrixGetAxis->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnMatrixGetAxis, &MatrixGetAxis_Params, nullptr);
	uFnMatrixGetAxis->iNative = nativeIndex;

	return MatrixGetAxis_Params.ReturnValue;
}

// Function Core.Object.MatrixGetOrigin
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FMatrix                 TM                             (CPF_Parm)

struct FVector UObject::MatrixGetOrigin(const struct FMatrix& TM)
{
	static UFunction* uFnMatrixGetOrigin = nullptr;

	if (!uFnMatrixGetOrigin)
	{
		uFnMatrixGetOrigin = UFunction::FindFunction("Function Core.Object.MatrixGetOrigin");
	}

	UObject_execMatrixGetOrigin_Params MatrixGetOrigin_Params;
	memset(&MatrixGetOrigin_Params, 0, sizeof(MatrixGetOrigin_Params));

	if (!uFnMatrixGetOrigin)
	{
		return MatrixGetOrigin_Params.ReturnValue;
	}
	memcpy_s(&MatrixGetOrigin_Params.TM, sizeof(MatrixGetOrigin_Params.TM), &TM, sizeof(TM));

	uint16_t nativeIndex = uFnMatrixGetOrigin->iNative;
	uFnMatrixGetOrigin->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnMatrixGetOrigin, &MatrixGetOrigin_Params, nullptr);
	uFnMatrixGetOrigin->iNative = nativeIndex;

	return MatrixGetOrigin_Params.ReturnValue;
}

// Function Core.Object.MatrixGetRotator
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// struct FRotator                ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FMatrix                 TM                             (CPF_Parm)

struct FRotator UObject::MatrixGetRotator(const struct FMatrix& TM)
{
	static UFunction* uFnMatrixGetRotator = nullptr;

	if (!uFnMatrixGetRotator)
	{
		uFnMatrixGetRotator = UFunction::FindFunction("Function Core.Object.MatrixGetRotator");
	}

	UObject_execMatrixGetRotator_Params MatrixGetRotator_Params;
	memset(&MatrixGetRotator_Params, 0, sizeof(MatrixGetRotator_Params));

	if (!uFnMatrixGetRotator)
	{
		return MatrixGetRotator_Params.ReturnValue;
	}
	memcpy_s(&MatrixGetRotator_Params.TM, sizeof(MatrixGetRotator_Params.TM), &TM, sizeof(TM));

	uint16_t nativeIndex = uFnMatrixGetRotator->iNative;
	uFnMatrixGetRotator->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnMatrixGetRotator, &MatrixGetRotator_Params, nullptr);
	uFnMatrixGetRotator->iNative = nativeIndex;

	return MatrixGetRotator_Params.ReturnValue;
}

// Function Core.Object.MakeRotationMatrix
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// struct FMatrix                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FRotator                Rotation                       (CPF_Parm)

struct FMatrix UObject::MakeRotationMatrix(const struct FRotator& Rotation)
{
	static UFunction* uFnMakeRotationMatrix = nullptr;

	if (!uFnMakeRotationMatrix)
	{
		uFnMakeRotationMatrix = UFunction::FindFunction("Function Core.Object.MakeRotationMatrix");
	}

	UObject_execMakeRotationMatrix_Params MakeRotationMatrix_Params;
	memset(&MakeRotationMatrix_Params, 0, sizeof(MakeRotationMatrix_Params));

	if (!uFnMakeRotationMatrix)
	{
		return MakeRotationMatrix_Params.ReturnValue;
	}
	memcpy_s(&MakeRotationMatrix_Params.Rotation, sizeof(MakeRotationMatrix_Params.Rotation), &Rotation, sizeof(Rotation));

	uint16_t nativeIndex = uFnMakeRotationMatrix->iNative;
	uFnMakeRotationMatrix->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnMakeRotationMatrix, &MakeRotationMatrix_Params, nullptr);
	uFnMakeRotationMatrix->iNative = nativeIndex;

	return MakeRotationMatrix_Params.ReturnValue;
}

// Function Core.Object.MakeRotationTranslationMatrix
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// struct FMatrix                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 Translation                    (CPF_Parm)
// struct FRotator                Rotation                       (CPF_Parm)

struct FMatrix UObject::MakeRotationTranslationMatrix(const struct FVector& Translation, const struct FRotator& Rotation)
{
	static UFunction* uFnMakeRotationTranslationMatrix = nullptr;

	if (!uFnMakeRotationTranslationMatrix)
	{
		uFnMakeRotationTranslationMatrix = UFunction::FindFunction("Function Core.Object.MakeRotationTranslationMatrix");
	}

	UObject_execMakeRotationTranslationMatrix_Params MakeRotationTranslationMatrix_Params;
	memset(&MakeRotationTranslationMatrix_Params, 0, sizeof(MakeRotationTranslationMatrix_Params));

	if (!uFnMakeRotationTranslationMatrix)
	{
		return MakeRotationTranslationMatrix_Params.ReturnValue;
	}
	memcpy_s(&MakeRotationTranslationMatrix_Params.Translation, sizeof(MakeRotationTranslationMatrix_Params.Translation), &Translation, sizeof(Translation));
	memcpy_s(&MakeRotationTranslationMatrix_Params.Rotation, sizeof(MakeRotationTranslationMatrix_Params.Rotation), &Rotation, sizeof(Rotation));

	uint16_t nativeIndex = uFnMakeRotationTranslationMatrix->iNative;
	uFnMakeRotationTranslationMatrix->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnMakeRotationTranslationMatrix, &MakeRotationTranslationMatrix_Params, nullptr);
	uFnMakeRotationTranslationMatrix->iNative = nativeIndex;

	return MakeRotationTranslationMatrix_Params.ReturnValue;
}

// Function Core.Object.InverseTransformNormal
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FMatrix                 TM                             (CPF_Parm)
// struct FVector                 A                              (CPF_Parm)

struct FVector UObject::InverseTransformNormal(const struct FMatrix& TM, const struct FVector& A)
{
	static UFunction* uFnInverseTransformNormal = nullptr;

	if (!uFnInverseTransformNormal)
	{
		uFnInverseTransformNormal = UFunction::FindFunction("Function Core.Object.InverseTransformNormal");
	}

	UObject_execInverseTransformNormal_Params InverseTransformNormal_Params;
	memset(&InverseTransformNormal_Params, 0, sizeof(InverseTransformNormal_Params));

	if (!uFnInverseTransformNormal)
	{
		return InverseTransformNormal_Params.ReturnValue;
	}
	memcpy_s(&InverseTransformNormal_Params.TM, sizeof(InverseTransformNormal_Params.TM), &TM, sizeof(TM));
	memcpy_s(&InverseTransformNormal_Params.A, sizeof(InverseTransformNormal_Params.A), &A, sizeof(A));

	uint16_t nativeIndex = uFnInverseTransformNormal->iNative;
	uFnInverseTransformNormal->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnInverseTransformNormal, &InverseTransformNormal_Params, nullptr);
	uFnInverseTransformNormal->iNative = nativeIndex;

	return InverseTransformNormal_Params.ReturnValue;
}

// Function Core.Object.TransformNormal
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FMatrix                 TM                             (CPF_Parm)
// struct FVector                 A                              (CPF_Parm)

struct FVector UObject::TransformNormal(const struct FMatrix& TM, const struct FVector& A)
{
	static UFunction* uFnTransformNormal = nullptr;

	if (!uFnTransformNormal)
	{
		uFnTransformNormal = UFunction::FindFunction("Function Core.Object.TransformNormal");
	}

	UObject_execTransformNormal_Params TransformNormal_Params;
	memset(&TransformNormal_Params, 0, sizeof(TransformNormal_Params));

	if (!uFnTransformNormal)
	{
		return TransformNormal_Params.ReturnValue;
	}
	memcpy_s(&TransformNormal_Params.TM, sizeof(TransformNormal_Params.TM), &TM, sizeof(TM));
	memcpy_s(&TransformNormal_Params.A, sizeof(TransformNormal_Params.A), &A, sizeof(A));

	uint16_t nativeIndex = uFnTransformNormal->iNative;
	uFnTransformNormal->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnTransformNormal, &TransformNormal_Params, nullptr);
	uFnTransformNormal->iNative = nativeIndex;

	return TransformNormal_Params.ReturnValue;
}

// Function Core.Object.InverseTransformVector
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FMatrix                 TM                             (CPF_Parm)
// struct FVector                 A                              (CPF_Parm)

struct FVector UObject::InverseTransformVector(const struct FMatrix& TM, const struct FVector& A)
{
	static UFunction* uFnInverseTransformVector = nullptr;

	if (!uFnInverseTransformVector)
	{
		uFnInverseTransformVector = UFunction::FindFunction("Function Core.Object.InverseTransformVector");
	}

	UObject_execInverseTransformVector_Params InverseTransformVector_Params;
	memset(&InverseTransformVector_Params, 0, sizeof(InverseTransformVector_Params));

	if (!uFnInverseTransformVector)
	{
		return InverseTransformVector_Params.ReturnValue;
	}
	memcpy_s(&InverseTransformVector_Params.TM, sizeof(InverseTransformVector_Params.TM), &TM, sizeof(TM));
	memcpy_s(&InverseTransformVector_Params.A, sizeof(InverseTransformVector_Params.A), &A, sizeof(A));

	uint16_t nativeIndex = uFnInverseTransformVector->iNative;
	uFnInverseTransformVector->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnInverseTransformVector, &InverseTransformVector_Params, nullptr);
	uFnInverseTransformVector->iNative = nativeIndex;

	return InverseTransformVector_Params.ReturnValue;
}

// Function Core.Object.TransformVector
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FMatrix                 TM                             (CPF_Parm)
// struct FVector                 A                              (CPF_Parm)

struct FVector UObject::TransformVector(const struct FMatrix& TM, const struct FVector& A)
{
	static UFunction* uFnTransformVector = nullptr;

	if (!uFnTransformVector)
	{
		uFnTransformVector = UFunction::FindFunction("Function Core.Object.TransformVector");
	}

	UObject_execTransformVector_Params TransformVector_Params;
	memset(&TransformVector_Params, 0, sizeof(TransformVector_Params));

	if (!uFnTransformVector)
	{
		return TransformVector_Params.ReturnValue;
	}
	memcpy_s(&TransformVector_Params.TM, sizeof(TransformVector_Params.TM), &TM, sizeof(TM));
	memcpy_s(&TransformVector_Params.A, sizeof(TransformVector_Params.A), &A, sizeof(A));

	uint16_t nativeIndex = uFnTransformVector->iNative;
	uFnTransformVector->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnTransformVector, &TransformVector_Params, nullptr);
	uFnTransformVector->iNative = nativeIndex;

	return TransformVector_Params.ReturnValue;
}

// Function Core.Object.Multiply_MatrixMatrix
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public)
// Parameter Info:
// struct FMatrix                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FMatrix                 A                              (CPF_Parm)
// struct FMatrix                 B                              (CPF_Parm)

struct FMatrix UObject::Multiply_MatrixMatrix(const struct FMatrix& A, const struct FMatrix& B)
{
	static UFunction* uFnMultiply_MatrixMatrix = nullptr;

	if (!uFnMultiply_MatrixMatrix)
	{
		uFnMultiply_MatrixMatrix = UFunction::FindFunction("Function Core.Object.Multiply_MatrixMatrix");
	}

	UObject_execMultiply_MatrixMatrix_Params Multiply_MatrixMatrix_Params;
	memset(&Multiply_MatrixMatrix_Params, 0, sizeof(Multiply_MatrixMatrix_Params));

	if (!uFnMultiply_MatrixMatrix)
	{
		return Multiply_MatrixMatrix_Params.ReturnValue;
	}
	memcpy_s(&Multiply_MatrixMatrix_Params.A, sizeof(Multiply_MatrixMatrix_Params.A), &A, sizeof(A));
	memcpy_s(&Multiply_MatrixMatrix_Params.B, sizeof(Multiply_MatrixMatrix_Params.B), &B, sizeof(B));

	uint16_t nativeIndex = uFnMultiply_MatrixMatrix->iNative;
	uFnMultiply_MatrixMatrix->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnMultiply_MatrixMatrix, &Multiply_MatrixMatrix_Params, nullptr);
	uFnMultiply_MatrixMatrix->iNative = nativeIndex;

	return Multiply_MatrixMatrix_Params.ReturnValue;
}

// Function Core.Object.NotEqual_NameName
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[255])
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FName                    A                              (CPF_Parm)
// class FName                    B                              (CPF_Parm)

bool UObject::NotEqual_NameName(const class FName& A, const class FName& B)
{
	static UFunction* uFnNotEqual_NameName = nullptr;

	if (!uFnNotEqual_NameName)
	{
		uFnNotEqual_NameName = UFunction::FindFunction("Function Core.Object.NotEqual_NameName");
	}

	UObject_execNotEqual_NameName_Params NotEqual_NameName_Params;
	memset(&NotEqual_NameName_Params, 0, sizeof(NotEqual_NameName_Params));

	if (!uFnNotEqual_NameName)
	{
		return NotEqual_NameName_Params.ReturnValue;
	}
	memcpy_s(&NotEqual_NameName_Params.A, sizeof(NotEqual_NameName_Params.A), &A, sizeof(A));
	memcpy_s(&NotEqual_NameName_Params.B, sizeof(NotEqual_NameName_Params.B), &B, sizeof(B));

	uint16_t nativeIndex = uFnNotEqual_NameName->iNative;
	uFnNotEqual_NameName->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnNotEqual_NameName, &NotEqual_NameName_Params, nullptr);
	uFnNotEqual_NameName->iNative = nativeIndex;

	return NotEqual_NameName_Params.ReturnValue;
}

// Function Core.Object.EqualEqual_NameName
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[254])
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FName                    A                              (CPF_Parm)
// class FName                    B                              (CPF_Parm)

bool UObject::EqualEqual_NameName(const class FName& A, const class FName& B)
{
	static UFunction* uFnEqualEqual_NameName = nullptr;

	if (!uFnEqualEqual_NameName)
	{
		uFnEqualEqual_NameName = UFunction::FindFunction("Function Core.Object.EqualEqual_NameName");
	}

	UObject_execEqualEqual_NameName_Params EqualEqual_NameName_Params;
	memset(&EqualEqual_NameName_Params, 0, sizeof(EqualEqual_NameName_Params));

	if (!uFnEqualEqual_NameName)
	{
		return EqualEqual_NameName_Params.ReturnValue;
	}
	memcpy_s(&EqualEqual_NameName_Params.A, sizeof(EqualEqual_NameName_Params.A), &A, sizeof(A));
	memcpy_s(&EqualEqual_NameName_Params.B, sizeof(EqualEqual_NameName_Params.B), &B, sizeof(B));

	uint16_t nativeIndex = uFnEqualEqual_NameName->iNative;
	uFnEqualEqual_NameName->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnEqualEqual_NameName, &EqualEqual_NameName_Params, nullptr);
	uFnEqualEqual_NameName->iNative = nativeIndex;

	return EqualEqual_NameName_Params.ReturnValue;
}

// Function Core.Object.IsA
// [0x00020401] (FUNC_Final | FUNC_Native | FUNC_Public) (iNative[197])
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FName                    ClassName                      (CPF_Parm)

bool UObject::IsA(const class FName& ClassName)
{
	static UFunction* uFnIsA = nullptr;

	if (!uFnIsA)
	{
		uFnIsA = UFunction::FindFunction("Function Core.Object.IsA");
	}

	UObject_execIsA_Params IsA_Params;
	memset(&IsA_Params, 0, sizeof(IsA_Params));

	if (!uFnIsA)
	{
		return IsA_Params.ReturnValue;
	}
	memcpy_s(&IsA_Params.ClassName, sizeof(IsA_Params.ClassName), &ClassName, sizeof(ClassName));

	uint16_t nativeIndex = uFnIsA->iNative;
	uFnIsA->iNative = 0;
	this->ProcessEvent(uFnIsA, &IsA_Params, nullptr);
	uFnIsA->iNative = nativeIndex;

	return IsA_Params.ReturnValue;
}

// Function Core.Object.ClassIsChildOf
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public) (iNative[258])
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class UClass*                  TestClass                      (CPF_Parm)
// class UClass*                  ParentClass                    (CPF_Parm)

bool UObject::ClassIsChildOf(class UClass* TestClass, class UClass* ParentClass)
{
	static UFunction* uFnClassIsChildOf = nullptr;

	if (!uFnClassIsChildOf)
	{
		uFnClassIsChildOf = UFunction::FindFunction("Function Core.Object.ClassIsChildOf");
	}

	UObject_execClassIsChildOf_Params ClassIsChildOf_Params;
	memset(&ClassIsChildOf_Params, 0, sizeof(ClassIsChildOf_Params));

	if (!uFnClassIsChildOf)
	{
		return ClassIsChildOf_Params.ReturnValue;
	}
	ClassIsChildOf_Params.TestClass = TestClass;
	ClassIsChildOf_Params.ParentClass = ParentClass;

	uint16_t nativeIndex = uFnClassIsChildOf->iNative;
	uFnClassIsChildOf->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnClassIsChildOf, &ClassIsChildOf_Params, nullptr);
	uFnClassIsChildOf->iNative = nativeIndex;

	return ClassIsChildOf_Params.ReturnValue;
}

// Function Core.Object.NotEqual_InterfaceInterface
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class UInterface*              A                              (CPF_Parm)
// class UInterface*              B                              (CPF_Parm)

bool UObject::NotEqual_InterfaceInterface(class UInterface* A, class UInterface* B)
{
	static UFunction* uFnNotEqual_InterfaceInterface = nullptr;

	if (!uFnNotEqual_InterfaceInterface)
	{
		uFnNotEqual_InterfaceInterface = UFunction::FindFunction("Function Core.Object.NotEqual_InterfaceInterface");
	}

	UObject_execNotEqual_InterfaceInterface_Params NotEqual_InterfaceInterface_Params;
	memset(&NotEqual_InterfaceInterface_Params, 0, sizeof(NotEqual_InterfaceInterface_Params));

	if (!uFnNotEqual_InterfaceInterface)
	{
		return NotEqual_InterfaceInterface_Params.ReturnValue;
	}
	NotEqual_InterfaceInterface_Params.A = A;
	NotEqual_InterfaceInterface_Params.B = B;

	uint16_t nativeIndex = uFnNotEqual_InterfaceInterface->iNative;
	uFnNotEqual_InterfaceInterface->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnNotEqual_InterfaceInterface, &NotEqual_InterfaceInterface_Params, nullptr);
	uFnNotEqual_InterfaceInterface->iNative = nativeIndex;

	return NotEqual_InterfaceInterface_Params.ReturnValue;
}

// Function Core.Object.EqualEqual_InterfaceInterface
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class UInterface*              A                              (CPF_Parm)
// class UInterface*              B                              (CPF_Parm)

bool UObject::EqualEqual_InterfaceInterface(class UInterface* A, class UInterface* B)
{
	static UFunction* uFnEqualEqual_InterfaceInterface = nullptr;

	if (!uFnEqualEqual_InterfaceInterface)
	{
		uFnEqualEqual_InterfaceInterface = UFunction::FindFunction("Function Core.Object.EqualEqual_InterfaceInterface");
	}

	UObject_execEqualEqual_InterfaceInterface_Params EqualEqual_InterfaceInterface_Params;
	memset(&EqualEqual_InterfaceInterface_Params, 0, sizeof(EqualEqual_InterfaceInterface_Params));

	if (!uFnEqualEqual_InterfaceInterface)
	{
		return EqualEqual_InterfaceInterface_Params.ReturnValue;
	}
	EqualEqual_InterfaceInterface_Params.A = A;
	EqualEqual_InterfaceInterface_Params.B = B;

	uint16_t nativeIndex = uFnEqualEqual_InterfaceInterface->iNative;
	uFnEqualEqual_InterfaceInterface->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnEqualEqual_InterfaceInterface, &EqualEqual_InterfaceInterface_Params, nullptr);
	uFnEqualEqual_InterfaceInterface->iNative = nativeIndex;

	return EqualEqual_InterfaceInterface_Params.ReturnValue;
}

// Function Core.Object.NotEqual_ObjectObject
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[119])
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class UObject*                 A                              (CPF_Parm)
// class UObject*                 B                              (CPF_Parm)

bool UObject::NotEqual_ObjectObject(class UObject* A, class UObject* B)
{
	static UFunction* uFnNotEqual_ObjectObject = nullptr;

	if (!uFnNotEqual_ObjectObject)
	{
		uFnNotEqual_ObjectObject = UFunction::FindFunction("Function Core.Object.NotEqual_ObjectObject");
	}

	UObject_execNotEqual_ObjectObject_Params NotEqual_ObjectObject_Params;
	memset(&NotEqual_ObjectObject_Params, 0, sizeof(NotEqual_ObjectObject_Params));

	if (!uFnNotEqual_ObjectObject)
	{
		return NotEqual_ObjectObject_Params.ReturnValue;
	}
	NotEqual_ObjectObject_Params.A = A;
	NotEqual_ObjectObject_Params.B = B;

	uint16_t nativeIndex = uFnNotEqual_ObjectObject->iNative;
	uFnNotEqual_ObjectObject->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnNotEqual_ObjectObject, &NotEqual_ObjectObject_Params, nullptr);
	uFnNotEqual_ObjectObject->iNative = nativeIndex;

	return NotEqual_ObjectObject_Params.ReturnValue;
}

// Function Core.Object.EqualEqual_ObjectObject
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[114])
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class UObject*                 A                              (CPF_Parm)
// class UObject*                 B                              (CPF_Parm)

bool UObject::EqualEqual_ObjectObject(class UObject* A, class UObject* B)
{
	static UFunction* uFnEqualEqual_ObjectObject = nullptr;

	if (!uFnEqualEqual_ObjectObject)
	{
		uFnEqualEqual_ObjectObject = UFunction::FindFunction("Function Core.Object.EqualEqual_ObjectObject");
	}

	UObject_execEqualEqual_ObjectObject_Params EqualEqual_ObjectObject_Params;
	memset(&EqualEqual_ObjectObject_Params, 0, sizeof(EqualEqual_ObjectObject_Params));

	if (!uFnEqualEqual_ObjectObject)
	{
		return EqualEqual_ObjectObject_Params.ReturnValue;
	}
	EqualEqual_ObjectObject_Params.A = A;
	EqualEqual_ObjectObject_Params.B = B;

	uint16_t nativeIndex = uFnEqualEqual_ObjectObject->iNative;
	uFnEqualEqual_ObjectObject->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnEqualEqual_ObjectObject, &EqualEqual_ObjectObject_Params, nullptr);
	uFnEqualEqual_ObjectObject->iNative = nativeIndex;

	return EqualEqual_ObjectObject_Params.ReturnValue;
}

// Function Core.Object.PathName
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// class FString                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
// class UObject*                 CheckObject                    (CPF_Parm)

class FString UObject::PathName(class UObject* CheckObject)
{
	static UFunction* uFnPathName = nullptr;

	if (!uFnPathName)
	{
		uFnPathName = UFunction::FindFunction("Function Core.Object.PathName");
	}

	UObject_execPathName_Params PathName_Params;
	memset(&PathName_Params, 0, sizeof(PathName_Params));

	if (!uFnPathName)
	{
		return PathName_Params.ReturnValue;
	}
	PathName_Params.CheckObject = CheckObject;

	uint16_t nativeIndex = uFnPathName->iNative;
	uFnPathName->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnPathName, &PathName_Params, nullptr);
	uFnPathName->iNative = nativeIndex;

	return PathName_Params.ReturnValue;
}

// Function Core.Object.SplitString
// [0x00026003] (FUNC_Final | FUNC_Defined | FUNC_Static | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// class TArray<class FString>    ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
// class FString                  Source                         (CPF_Parm | CPF_NeedCtorLink)
// class FString                  Delimiter                      (CPF_OptionalParm | CPF_Parm | CPF_NeedCtorLink)
// uint32_t                       bCullEmpty                     (CPF_OptionalParm | CPF_Parm)

class TArray<class FString> UObject::SplitString(const class FString& Source, const class FString& optionalDelimiter, bool optionalBCullEmpty)
{
	static UFunction* uFnSplitString = nullptr;

	if (!uFnSplitString)
	{
		uFnSplitString = UFunction::FindFunction("Function Core.Object.SplitString");
	}

	UObject_execSplitString_Params SplitString_Params;
	memset(&SplitString_Params, 0, sizeof(SplitString_Params));

	if (!uFnSplitString)
	{
		return SplitString_Params.ReturnValue;
	}
	memcpy_s(&SplitString_Params.Source, sizeof(SplitString_Params.Source), &Source, sizeof(Source));
	memcpy_s(&SplitString_Params.Delimiter, sizeof(SplitString_Params.Delimiter), &optionalDelimiter, sizeof(optionalDelimiter));
	SplitString_Params.bCullEmpty = optionalBCullEmpty;

	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnSplitString, &SplitString_Params, nullptr);

	return SplitString_Params.ReturnValue;
}

// Function Core.Object.ParseStringIntoArray
// [0x00422401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// class FString                  BaseString                     (CPF_Parm | CPF_NeedCtorLink)
// class FString                  delim                          (CPF_Parm | CPF_NeedCtorLink)
// uint32_t                       bCullEmpty                     (CPF_Parm)
// class TArray<class FString>    Pieces                         (CPF_Parm | CPF_OutParm | CPF_NeedCtorLink)

void UObject::ParseStringIntoArray(const class FString& BaseString, const class FString& delim, bool bCullEmpty, class TArray<class FString>& outPieces)
{
	static UFunction* uFnParseStringIntoArray = nullptr;

	if (!uFnParseStringIntoArray)
	{
		uFnParseStringIntoArray = UFunction::FindFunction("Function Core.Object.ParseStringIntoArray");
	}

	UObject_execParseStringIntoArray_Params ParseStringIntoArray_Params;
	memset(&ParseStringIntoArray_Params, 0, sizeof(ParseStringIntoArray_Params));

	if (!uFnParseStringIntoArray)
	{
		return;
	}
	memcpy_s(&ParseStringIntoArray_Params.BaseString, sizeof(ParseStringIntoArray_Params.BaseString), &BaseString, sizeof(BaseString));
	memcpy_s(&ParseStringIntoArray_Params.delim, sizeof(ParseStringIntoArray_Params.delim), &delim, sizeof(delim));
	ParseStringIntoArray_Params.bCullEmpty = bCullEmpty;
	memcpy_s(&ParseStringIntoArray_Params.Pieces, sizeof(ParseStringIntoArray_Params.Pieces), &outPieces, sizeof(outPieces));

	uint16_t nativeIndex = uFnParseStringIntoArray->iNative;
	uFnParseStringIntoArray->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnParseStringIntoArray, &ParseStringIntoArray_Params, nullptr);
	uFnParseStringIntoArray->iNative = nativeIndex;

	memcpy_s(&outPieces, sizeof(outPieces), &ParseStringIntoArray_Params.Pieces, sizeof(ParseStringIntoArray_Params.Pieces));
}

// Function Core.Object.JoinArray
// [0x00426003] (FUNC_Final | FUNC_Defined | FUNC_Static | FUNC_OptionalParm | FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// class TArray<class FString>    StringArray                    (CPF_Parm | CPF_NeedCtorLink)
// class FString                  delim                          (CPF_OptionalParm | CPF_Parm | CPF_NeedCtorLink)
// uint32_t                       bIgnoreBlanks                  (CPF_OptionalParm | CPF_Parm)
// class FString                  out_Result                     (CPF_Parm | CPF_OutParm | CPF_NeedCtorLink)

void UObject::JoinArray(const class TArray<class FString>& StringArray, const class FString& optionalDelim, bool optionalBIgnoreBlanks, class FString& outOut_Result)
{
	static UFunction* uFnJoinArray = nullptr;

	if (!uFnJoinArray)
	{
		uFnJoinArray = UFunction::FindFunction("Function Core.Object.JoinArray");
	}

	UObject_execJoinArray_Params JoinArray_Params;
	memset(&JoinArray_Params, 0, sizeof(JoinArray_Params));

	if (!uFnJoinArray)
	{
		return;
	}
	memcpy_s(&JoinArray_Params.StringArray, sizeof(JoinArray_Params.StringArray), &StringArray, sizeof(StringArray));
	memcpy_s(&JoinArray_Params.delim, sizeof(JoinArray_Params.delim), &optionalDelim, sizeof(optionalDelim));
	JoinArray_Params.bIgnoreBlanks = optionalBIgnoreBlanks;
	memcpy_s(&JoinArray_Params.out_Result, sizeof(JoinArray_Params.out_Result), &outOut_Result, sizeof(outOut_Result));

	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnJoinArray, &JoinArray_Params, nullptr);

	memcpy_s(&outOut_Result, sizeof(outOut_Result), &JoinArray_Params.out_Result, sizeof(JoinArray_Params.out_Result));
}

// Function Core.Object.GetRightMost
// [0x00022003] (FUNC_Final | FUNC_Defined | FUNC_Static | FUNC_Public)
// Parameter Info:
// class FString                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
// class FString                  Text                           (CPF_Parm | CPF_CoerceParm | CPF_NeedCtorLink)

class FString UObject::GetRightMost(const class FString& Text)
{
	static UFunction* uFnGetRightMost = nullptr;

	if (!uFnGetRightMost)
	{
		uFnGetRightMost = UFunction::FindFunction("Function Core.Object.GetRightMost");
	}

	UObject_execGetRightMost_Params GetRightMost_Params;
	memset(&GetRightMost_Params, 0, sizeof(GetRightMost_Params));

	if (!uFnGetRightMost)
	{
		return GetRightMost_Params.ReturnValue;
	}
	memcpy_s(&GetRightMost_Params.Text, sizeof(GetRightMost_Params.Text), &Text, sizeof(Text));

	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnGetRightMost, &GetRightMost_Params, nullptr);

	return GetRightMost_Params.ReturnValue;
}

// Function Core.Object.Split
// [0x00026003] (FUNC_Final | FUNC_Defined | FUNC_Static | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// class FString                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
// class FString                  Text                           (CPF_Parm | CPF_CoerceParm | CPF_NeedCtorLink)
// class FString                  SplitStr                       (CPF_Parm | CPF_CoerceParm | CPF_NeedCtorLink)
// uint32_t                       bOmitSplitStr                  (CPF_OptionalParm | CPF_Parm)

class FString UObject::Split(const class FString& Text, const class FString& SplitStr, bool optionalBOmitSplitStr)
{
	static UFunction* uFnSplit = nullptr;

	if (!uFnSplit)
	{
		uFnSplit = UFunction::FindFunction("Function Core.Object.Split");
	}

	UObject_execSplit_Params Split_Params;
	memset(&Split_Params, 0, sizeof(Split_Params));

	if (!uFnSplit)
	{
		return Split_Params.ReturnValue;
	}
	memcpy_s(&Split_Params.Text, sizeof(Split_Params.Text), &Text, sizeof(Text));
	memcpy_s(&Split_Params.SplitStr, sizeof(Split_Params.SplitStr), &SplitStr, sizeof(SplitStr));
	Split_Params.bOmitSplitStr = optionalBOmitSplitStr;

	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnSplit, &Split_Params, nullptr);

	return Split_Params.ReturnValue;
}

// Function Core.Object.Repl
// [0x00026401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_OptionalParm | FUNC_Public) (iNative[201])
// Parameter Info:
// class FString                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
// class FString                  Src                            (CPF_Parm | CPF_CoerceParm | CPF_NeedCtorLink)
// class FString                  Match                          (CPF_Parm | CPF_CoerceParm | CPF_NeedCtorLink)
// class FString                  With                           (CPF_Parm | CPF_CoerceParm | CPF_NeedCtorLink)
// uint32_t                       bCaseSensitive                 (CPF_OptionalParm | CPF_Parm)

class FString UObject::Repl(const class FString& Src, const class FString& Match, const class FString& With, bool optionalBCaseSensitive)
{
	static UFunction* uFnRepl = nullptr;

	if (!uFnRepl)
	{
		uFnRepl = UFunction::FindFunction("Function Core.Object.Repl");
	}

	UObject_execRepl_Params Repl_Params;
	memset(&Repl_Params, 0, sizeof(Repl_Params));

	if (!uFnRepl)
	{
		return Repl_Params.ReturnValue;
	}
	memcpy_s(&Repl_Params.Src, sizeof(Repl_Params.Src), &Src, sizeof(Src));
	memcpy_s(&Repl_Params.Match, sizeof(Repl_Params.Match), &Match, sizeof(Match));
	memcpy_s(&Repl_Params.With, sizeof(Repl_Params.With), &With, sizeof(With));
	Repl_Params.bCaseSensitive = optionalBCaseSensitive;

	uint16_t nativeIndex = uFnRepl->iNative;
	uFnRepl->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnRepl, &Repl_Params, nullptr);
	uFnRepl->iNative = nativeIndex;

	return Repl_Params.ReturnValue;
}

// Function Core.Object.Asc
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public) (iNative[237])
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FString                  S                              (CPF_Parm | CPF_NeedCtorLink)

int32_t UObject::Asc(const class FString& S)
{
	static UFunction* uFnAsc = nullptr;

	if (!uFnAsc)
	{
		uFnAsc = UFunction::FindFunction("Function Core.Object.Asc");
	}

	UObject_execAsc_Params Asc_Params;
	memset(&Asc_Params, 0, sizeof(Asc_Params));

	if (!uFnAsc)
	{
		return Asc_Params.ReturnValue;
	}
	memcpy_s(&Asc_Params.S, sizeof(Asc_Params.S), &S, sizeof(S));

	uint16_t nativeIndex = uFnAsc->iNative;
	uFnAsc->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnAsc, &Asc_Params, nullptr);
	uFnAsc->iNative = nativeIndex;

	return Asc_Params.ReturnValue;
}

// Function Core.Object.Chr
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public) (iNative[236])
// Parameter Info:
// class FString                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
// int32_t                        I                              (CPF_Parm)

class FString UObject::Chr(int32_t I)
{
	static UFunction* uFnChr = nullptr;

	if (!uFnChr)
	{
		uFnChr = UFunction::FindFunction("Function Core.Object.Chr");
	}

	UObject_execChr_Params Chr_Params;
	memset(&Chr_Params, 0, sizeof(Chr_Params));

	if (!uFnChr)
	{
		return Chr_Params.ReturnValue;
	}
	Chr_Params.I = I;

	uint16_t nativeIndex = uFnChr->iNative;
	uFnChr->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnChr, &Chr_Params, nullptr);
	uFnChr->iNative = nativeIndex;

	return Chr_Params.ReturnValue;
}

// Function Core.Object.Locs
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public) (iNative[238])
// Parameter Info:
// class FString                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
// class FString                  S                              (CPF_Parm | CPF_CoerceParm | CPF_NeedCtorLink)

class FString UObject::Locs(const class FString& S)
{
	static UFunction* uFnLocs = nullptr;

	if (!uFnLocs)
	{
		uFnLocs = UFunction::FindFunction("Function Core.Object.Locs");
	}

	UObject_execLocs_Params Locs_Params;
	memset(&Locs_Params, 0, sizeof(Locs_Params));

	if (!uFnLocs)
	{
		return Locs_Params.ReturnValue;
	}
	memcpy_s(&Locs_Params.S, sizeof(Locs_Params.S), &S, sizeof(S));

	uint16_t nativeIndex = uFnLocs->iNative;
	uFnLocs->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnLocs, &Locs_Params, nullptr);
	uFnLocs->iNative = nativeIndex;

	return Locs_Params.ReturnValue;
}

// Function Core.Object.Caps
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public) (iNative[235])
// Parameter Info:
// class FString                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
// class FString                  S                              (CPF_Parm | CPF_CoerceParm | CPF_NeedCtorLink)

class FString UObject::Caps(const class FString& S)
{
	static UFunction* uFnCaps = nullptr;

	if (!uFnCaps)
	{
		uFnCaps = UFunction::FindFunction("Function Core.Object.Caps");
	}

	UObject_execCaps_Params Caps_Params;
	memset(&Caps_Params, 0, sizeof(Caps_Params));

	if (!uFnCaps)
	{
		return Caps_Params.ReturnValue;
	}
	memcpy_s(&Caps_Params.S, sizeof(Caps_Params.S), &S, sizeof(S));

	uint16_t nativeIndex = uFnCaps->iNative;
	uFnCaps->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnCaps, &Caps_Params, nullptr);
	uFnCaps->iNative = nativeIndex;

	return Caps_Params.ReturnValue;
}

// Function Core.Object.Right
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public) (iNative[234])
// Parameter Info:
// class FString                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
// class FString                  S                              (CPF_Parm | CPF_CoerceParm | CPF_NeedCtorLink)
// int32_t                        I                              (CPF_Parm)

class FString UObject::Right(const class FString& S, int32_t I)
{
	static UFunction* uFnRight = nullptr;

	if (!uFnRight)
	{
		uFnRight = UFunction::FindFunction("Function Core.Object.Right");
	}

	UObject_execRight_Params Right_Params;
	memset(&Right_Params, 0, sizeof(Right_Params));

	if (!uFnRight)
	{
		return Right_Params.ReturnValue;
	}
	memcpy_s(&Right_Params.S, sizeof(Right_Params.S), &S, sizeof(S));
	Right_Params.I = I;

	uint16_t nativeIndex = uFnRight->iNative;
	uFnRight->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnRight, &Right_Params, nullptr);
	uFnRight->iNative = nativeIndex;

	return Right_Params.ReturnValue;
}

// Function Core.Object.Left
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public) (iNative[128])
// Parameter Info:
// class FString                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
// class FString                  S                              (CPF_Parm | CPF_CoerceParm | CPF_NeedCtorLink)
// int32_t                        I                              (CPF_Parm)

class FString UObject::Left(const class FString& S, int32_t I)
{
	static UFunction* uFnLeft = nullptr;

	if (!uFnLeft)
	{
		uFnLeft = UFunction::FindFunction("Function Core.Object.Left");
	}

	UObject_execLeft_Params Left_Params;
	memset(&Left_Params, 0, sizeof(Left_Params));

	if (!uFnLeft)
	{
		return Left_Params.ReturnValue;
	}
	memcpy_s(&Left_Params.S, sizeof(Left_Params.S), &S, sizeof(S));
	Left_Params.I = I;

	uint16_t nativeIndex = uFnLeft->iNative;
	uFnLeft->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnLeft, &Left_Params, nullptr);
	uFnLeft->iNative = nativeIndex;

	return Left_Params.ReturnValue;
}

// Function Core.Object.Mid
// [0x00026401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_OptionalParm | FUNC_Public) (iNative[127])
// Parameter Info:
// class FString                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
// class FString                  S                              (CPF_Parm | CPF_CoerceParm | CPF_NeedCtorLink)
// int32_t                        I                              (CPF_Parm)
// int32_t                        J                              (CPF_OptionalParm | CPF_Parm)

class FString UObject::Mid(const class FString& S, int32_t I, int32_t optionalJ)
{
	static UFunction* uFnMid = nullptr;

	if (!uFnMid)
	{
		uFnMid = UFunction::FindFunction("Function Core.Object.Mid");
	}

	UObject_execMid_Params Mid_Params;
	memset(&Mid_Params, 0, sizeof(Mid_Params));

	if (!uFnMid)
	{
		return Mid_Params.ReturnValue;
	}
	memcpy_s(&Mid_Params.S, sizeof(Mid_Params.S), &S, sizeof(S));
	Mid_Params.I = I;
	Mid_Params.J = optionalJ;

	uint16_t nativeIndex = uFnMid->iNative;
	uFnMid->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnMid, &Mid_Params, nullptr);
	uFnMid->iNative = nativeIndex;

	return Mid_Params.ReturnValue;
}

// Function Core.Object.InStr
// [0x00026401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_OptionalParm | FUNC_Public) (iNative[126])
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FString                  S                              (CPF_Parm | CPF_CoerceParm | CPF_NeedCtorLink)
// class FString                  T                              (CPF_Parm | CPF_CoerceParm | CPF_NeedCtorLink)
// uint32_t                       bSearchFromRight               (CPF_OptionalParm | CPF_Parm)
// uint32_t                       bIgnoreCase                    (CPF_OptionalParm | CPF_Parm)
// int32_t                        StartPos                       (CPF_OptionalParm | CPF_Parm)

int32_t UObject::InStr(const class FString& S, const class FString& T, bool optionalBSearchFromRight, bool optionalBIgnoreCase, int32_t optionalStartPos)
{
	static UFunction* uFnInStr = nullptr;

	if (!uFnInStr)
	{
		uFnInStr = UFunction::FindFunction("Function Core.Object.InStr");
	}

	UObject_execInStr_Params InStr_Params;
	memset(&InStr_Params, 0, sizeof(InStr_Params));

	if (!uFnInStr)
	{
		return InStr_Params.ReturnValue;
	}
	memcpy_s(&InStr_Params.S, sizeof(InStr_Params.S), &S, sizeof(S));
	memcpy_s(&InStr_Params.T, sizeof(InStr_Params.T), &T, sizeof(T));
	InStr_Params.bSearchFromRight = optionalBSearchFromRight;
	InStr_Params.bIgnoreCase = optionalBIgnoreCase;
	InStr_Params.StartPos = optionalStartPos;

	uint16_t nativeIndex = uFnInStr->iNative;
	uFnInStr->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnInStr, &InStr_Params, nullptr);
	uFnInStr->iNative = nativeIndex;

	return InStr_Params.ReturnValue;
}

// Function Core.Object.Len
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public) (iNative[125])
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FString                  S                              (CPF_Parm | CPF_CoerceParm | CPF_NeedCtorLink)

int32_t UObject::Len(const class FString& S)
{
	static UFunction* uFnLen = nullptr;

	if (!uFnLen)
	{
		uFnLen = UFunction::FindFunction("Function Core.Object.Len");
	}

	UObject_execLen_Params Len_Params;
	memset(&Len_Params, 0, sizeof(Len_Params));

	if (!uFnLen)
	{
		return Len_Params.ReturnValue;
	}
	memcpy_s(&Len_Params.S, sizeof(Len_Params.S), &S, sizeof(S));

	uint16_t nativeIndex = uFnLen->iNative;
	uFnLen->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnLen, &Len_Params, nullptr);
	uFnLen->iNative = nativeIndex;

	return Len_Params.ReturnValue;
}

// Function Core.Object.SubtractEqual_StrStr
// [0x00423401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public | FUNC_HasOutParms) (iNative[324])
// Parameter Info:
// class FString                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
// class FString                  B                              (CPF_Parm | CPF_CoerceParm | CPF_NeedCtorLink)
// class FString                  A                              (CPF_Parm | CPF_OutParm | CPF_NeedCtorLink)

class FString UObject::SubtractEqual_StrStr(const class FString& B, class FString& outA)
{
	static UFunction* uFnSubtractEqual_StrStr = nullptr;

	if (!uFnSubtractEqual_StrStr)
	{
		uFnSubtractEqual_StrStr = UFunction::FindFunction("Function Core.Object.SubtractEqual_StrStr");
	}

	UObject_execSubtractEqual_StrStr_Params SubtractEqual_StrStr_Params;
	memset(&SubtractEqual_StrStr_Params, 0, sizeof(SubtractEqual_StrStr_Params));

	if (!uFnSubtractEqual_StrStr)
	{
		return SubtractEqual_StrStr_Params.ReturnValue;
	}
	memcpy_s(&SubtractEqual_StrStr_Params.B, sizeof(SubtractEqual_StrStr_Params.B), &B, sizeof(B));
	memcpy_s(&SubtractEqual_StrStr_Params.A, sizeof(SubtractEqual_StrStr_Params.A), &outA, sizeof(outA));

	uint16_t nativeIndex = uFnSubtractEqual_StrStr->iNative;
	uFnSubtractEqual_StrStr->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnSubtractEqual_StrStr, &SubtractEqual_StrStr_Params, nullptr);
	uFnSubtractEqual_StrStr->iNative = nativeIndex;

	memcpy_s(&outA, sizeof(outA), &SubtractEqual_StrStr_Params.A, sizeof(SubtractEqual_StrStr_Params.A));

	return SubtractEqual_StrStr_Params.ReturnValue;
}

// Function Core.Object.AtEqual_StrStr
// [0x00423401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public | FUNC_HasOutParms) (iNative[323])
// Parameter Info:
// class FString                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
// class FString                  B                              (CPF_Parm | CPF_CoerceParm | CPF_NeedCtorLink)
// class FString                  A                              (CPF_Parm | CPF_OutParm | CPF_NeedCtorLink)

class FString UObject::AtEqual_StrStr(const class FString& B, class FString& outA)
{
	static UFunction* uFnAtEqual_StrStr = nullptr;

	if (!uFnAtEqual_StrStr)
	{
		uFnAtEqual_StrStr = UFunction::FindFunction("Function Core.Object.AtEqual_StrStr");
	}

	UObject_execAtEqual_StrStr_Params AtEqual_StrStr_Params;
	memset(&AtEqual_StrStr_Params, 0, sizeof(AtEqual_StrStr_Params));

	if (!uFnAtEqual_StrStr)
	{
		return AtEqual_StrStr_Params.ReturnValue;
	}
	memcpy_s(&AtEqual_StrStr_Params.B, sizeof(AtEqual_StrStr_Params.B), &B, sizeof(B));
	memcpy_s(&AtEqual_StrStr_Params.A, sizeof(AtEqual_StrStr_Params.A), &outA, sizeof(outA));

	uint16_t nativeIndex = uFnAtEqual_StrStr->iNative;
	uFnAtEqual_StrStr->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnAtEqual_StrStr, &AtEqual_StrStr_Params, nullptr);
	uFnAtEqual_StrStr->iNative = nativeIndex;

	memcpy_s(&outA, sizeof(outA), &AtEqual_StrStr_Params.A, sizeof(AtEqual_StrStr_Params.A));

	return AtEqual_StrStr_Params.ReturnValue;
}

// Function Core.Object.ConcatEqual_StrStr
// [0x00423401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public | FUNC_HasOutParms) (iNative[322])
// Parameter Info:
// class FString                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
// class FString                  B                              (CPF_Parm | CPF_CoerceParm | CPF_NeedCtorLink)
// class FString                  A                              (CPF_Parm | CPF_OutParm | CPF_NeedCtorLink)

class FString UObject::ConcatEqual_StrStr(const class FString& B, class FString& outA)
{
	static UFunction* uFnConcatEqual_StrStr = nullptr;

	if (!uFnConcatEqual_StrStr)
	{
		uFnConcatEqual_StrStr = UFunction::FindFunction("Function Core.Object.ConcatEqual_StrStr");
	}

	UObject_execConcatEqual_StrStr_Params ConcatEqual_StrStr_Params;
	memset(&ConcatEqual_StrStr_Params, 0, sizeof(ConcatEqual_StrStr_Params));

	if (!uFnConcatEqual_StrStr)
	{
		return ConcatEqual_StrStr_Params.ReturnValue;
	}
	memcpy_s(&ConcatEqual_StrStr_Params.B, sizeof(ConcatEqual_StrStr_Params.B), &B, sizeof(B));
	memcpy_s(&ConcatEqual_StrStr_Params.A, sizeof(ConcatEqual_StrStr_Params.A), &outA, sizeof(outA));

	uint16_t nativeIndex = uFnConcatEqual_StrStr->iNative;
	uFnConcatEqual_StrStr->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnConcatEqual_StrStr, &ConcatEqual_StrStr_Params, nullptr);
	uFnConcatEqual_StrStr->iNative = nativeIndex;

	memcpy_s(&outA, sizeof(outA), &ConcatEqual_StrStr_Params.A, sizeof(ConcatEqual_StrStr_Params.A));

	return ConcatEqual_StrStr_Params.ReturnValue;
}

// Function Core.Object.ComplementEqual_StrStr
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[124])
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FString                  A                              (CPF_Parm | CPF_NeedCtorLink)
// class FString                  B                              (CPF_Parm | CPF_NeedCtorLink)

bool UObject::ComplementEqual_StrStr(const class FString& A, const class FString& B)
{
	static UFunction* uFnComplementEqual_StrStr = nullptr;

	if (!uFnComplementEqual_StrStr)
	{
		uFnComplementEqual_StrStr = UFunction::FindFunction("Function Core.Object.ComplementEqual_StrStr");
	}

	UObject_execComplementEqual_StrStr_Params ComplementEqual_StrStr_Params;
	memset(&ComplementEqual_StrStr_Params, 0, sizeof(ComplementEqual_StrStr_Params));

	if (!uFnComplementEqual_StrStr)
	{
		return ComplementEqual_StrStr_Params.ReturnValue;
	}
	memcpy_s(&ComplementEqual_StrStr_Params.A, sizeof(ComplementEqual_StrStr_Params.A), &A, sizeof(A));
	memcpy_s(&ComplementEqual_StrStr_Params.B, sizeof(ComplementEqual_StrStr_Params.B), &B, sizeof(B));

	uint16_t nativeIndex = uFnComplementEqual_StrStr->iNative;
	uFnComplementEqual_StrStr->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnComplementEqual_StrStr, &ComplementEqual_StrStr_Params, nullptr);
	uFnComplementEqual_StrStr->iNative = nativeIndex;

	return ComplementEqual_StrStr_Params.ReturnValue;
}

// Function Core.Object.NotEqual_StrStr
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[123])
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FString                  A                              (CPF_Parm | CPF_NeedCtorLink)
// class FString                  B                              (CPF_Parm | CPF_NeedCtorLink)

bool UObject::NotEqual_StrStr(const class FString& A, const class FString& B)
{
	static UFunction* uFnNotEqual_StrStr = nullptr;

	if (!uFnNotEqual_StrStr)
	{
		uFnNotEqual_StrStr = UFunction::FindFunction("Function Core.Object.NotEqual_StrStr");
	}

	UObject_execNotEqual_StrStr_Params NotEqual_StrStr_Params;
	memset(&NotEqual_StrStr_Params, 0, sizeof(NotEqual_StrStr_Params));

	if (!uFnNotEqual_StrStr)
	{
		return NotEqual_StrStr_Params.ReturnValue;
	}
	memcpy_s(&NotEqual_StrStr_Params.A, sizeof(NotEqual_StrStr_Params.A), &A, sizeof(A));
	memcpy_s(&NotEqual_StrStr_Params.B, sizeof(NotEqual_StrStr_Params.B), &B, sizeof(B));

	uint16_t nativeIndex = uFnNotEqual_StrStr->iNative;
	uFnNotEqual_StrStr->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnNotEqual_StrStr, &NotEqual_StrStr_Params, nullptr);
	uFnNotEqual_StrStr->iNative = nativeIndex;

	return NotEqual_StrStr_Params.ReturnValue;
}

// Function Core.Object.EqualEqual_StrStr
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[122])
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FString                  A                              (CPF_Parm | CPF_NeedCtorLink)
// class FString                  B                              (CPF_Parm | CPF_NeedCtorLink)

bool UObject::EqualEqual_StrStr(const class FString& A, const class FString& B)
{
	static UFunction* uFnEqualEqual_StrStr = nullptr;

	if (!uFnEqualEqual_StrStr)
	{
		uFnEqualEqual_StrStr = UFunction::FindFunction("Function Core.Object.EqualEqual_StrStr");
	}

	UObject_execEqualEqual_StrStr_Params EqualEqual_StrStr_Params;
	memset(&EqualEqual_StrStr_Params, 0, sizeof(EqualEqual_StrStr_Params));

	if (!uFnEqualEqual_StrStr)
	{
		return EqualEqual_StrStr_Params.ReturnValue;
	}
	memcpy_s(&EqualEqual_StrStr_Params.A, sizeof(EqualEqual_StrStr_Params.A), &A, sizeof(A));
	memcpy_s(&EqualEqual_StrStr_Params.B, sizeof(EqualEqual_StrStr_Params.B), &B, sizeof(B));

	uint16_t nativeIndex = uFnEqualEqual_StrStr->iNative;
	uFnEqualEqual_StrStr->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnEqualEqual_StrStr, &EqualEqual_StrStr_Params, nullptr);
	uFnEqualEqual_StrStr->iNative = nativeIndex;

	return EqualEqual_StrStr_Params.ReturnValue;
}

// Function Core.Object.GreaterEqual_StrStr
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[121])
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FString                  A                              (CPF_Parm | CPF_NeedCtorLink)
// class FString                  B                              (CPF_Parm | CPF_NeedCtorLink)

bool UObject::GreaterEqual_StrStr(const class FString& A, const class FString& B)
{
	static UFunction* uFnGreaterEqual_StrStr = nullptr;

	if (!uFnGreaterEqual_StrStr)
	{
		uFnGreaterEqual_StrStr = UFunction::FindFunction("Function Core.Object.GreaterEqual_StrStr");
	}

	UObject_execGreaterEqual_StrStr_Params GreaterEqual_StrStr_Params;
	memset(&GreaterEqual_StrStr_Params, 0, sizeof(GreaterEqual_StrStr_Params));

	if (!uFnGreaterEqual_StrStr)
	{
		return GreaterEqual_StrStr_Params.ReturnValue;
	}
	memcpy_s(&GreaterEqual_StrStr_Params.A, sizeof(GreaterEqual_StrStr_Params.A), &A, sizeof(A));
	memcpy_s(&GreaterEqual_StrStr_Params.B, sizeof(GreaterEqual_StrStr_Params.B), &B, sizeof(B));

	uint16_t nativeIndex = uFnGreaterEqual_StrStr->iNative;
	uFnGreaterEqual_StrStr->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnGreaterEqual_StrStr, &GreaterEqual_StrStr_Params, nullptr);
	uFnGreaterEqual_StrStr->iNative = nativeIndex;

	return GreaterEqual_StrStr_Params.ReturnValue;
}

// Function Core.Object.LessEqual_StrStr
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[120])
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FString                  A                              (CPF_Parm | CPF_NeedCtorLink)
// class FString                  B                              (CPF_Parm | CPF_NeedCtorLink)

bool UObject::LessEqual_StrStr(const class FString& A, const class FString& B)
{
	static UFunction* uFnLessEqual_StrStr = nullptr;

	if (!uFnLessEqual_StrStr)
	{
		uFnLessEqual_StrStr = UFunction::FindFunction("Function Core.Object.LessEqual_StrStr");
	}

	UObject_execLessEqual_StrStr_Params LessEqual_StrStr_Params;
	memset(&LessEqual_StrStr_Params, 0, sizeof(LessEqual_StrStr_Params));

	if (!uFnLessEqual_StrStr)
	{
		return LessEqual_StrStr_Params.ReturnValue;
	}
	memcpy_s(&LessEqual_StrStr_Params.A, sizeof(LessEqual_StrStr_Params.A), &A, sizeof(A));
	memcpy_s(&LessEqual_StrStr_Params.B, sizeof(LessEqual_StrStr_Params.B), &B, sizeof(B));

	uint16_t nativeIndex = uFnLessEqual_StrStr->iNative;
	uFnLessEqual_StrStr->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnLessEqual_StrStr, &LessEqual_StrStr_Params, nullptr);
	uFnLessEqual_StrStr->iNative = nativeIndex;

	return LessEqual_StrStr_Params.ReturnValue;
}

// Function Core.Object.Greater_StrStr
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[116])
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FString                  A                              (CPF_Parm | CPF_NeedCtorLink)
// class FString                  B                              (CPF_Parm | CPF_NeedCtorLink)

bool UObject::Greater_StrStr(const class FString& A, const class FString& B)
{
	static UFunction* uFnGreater_StrStr = nullptr;

	if (!uFnGreater_StrStr)
	{
		uFnGreater_StrStr = UFunction::FindFunction("Function Core.Object.Greater_StrStr");
	}

	UObject_execGreater_StrStr_Params Greater_StrStr_Params;
	memset(&Greater_StrStr_Params, 0, sizeof(Greater_StrStr_Params));

	if (!uFnGreater_StrStr)
	{
		return Greater_StrStr_Params.ReturnValue;
	}
	memcpy_s(&Greater_StrStr_Params.A, sizeof(Greater_StrStr_Params.A), &A, sizeof(A));
	memcpy_s(&Greater_StrStr_Params.B, sizeof(Greater_StrStr_Params.B), &B, sizeof(B));

	uint16_t nativeIndex = uFnGreater_StrStr->iNative;
	uFnGreater_StrStr->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnGreater_StrStr, &Greater_StrStr_Params, nullptr);
	uFnGreater_StrStr->iNative = nativeIndex;

	return Greater_StrStr_Params.ReturnValue;
}

// Function Core.Object.Less_StrStr
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[115])
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FString                  A                              (CPF_Parm | CPF_NeedCtorLink)
// class FString                  B                              (CPF_Parm | CPF_NeedCtorLink)

bool UObject::Less_StrStr(const class FString& A, const class FString& B)
{
	static UFunction* uFnLess_StrStr = nullptr;

	if (!uFnLess_StrStr)
	{
		uFnLess_StrStr = UFunction::FindFunction("Function Core.Object.Less_StrStr");
	}

	UObject_execLess_StrStr_Params Less_StrStr_Params;
	memset(&Less_StrStr_Params, 0, sizeof(Less_StrStr_Params));

	if (!uFnLess_StrStr)
	{
		return Less_StrStr_Params.ReturnValue;
	}
	memcpy_s(&Less_StrStr_Params.A, sizeof(Less_StrStr_Params.A), &A, sizeof(A));
	memcpy_s(&Less_StrStr_Params.B, sizeof(Less_StrStr_Params.B), &B, sizeof(B));

	uint16_t nativeIndex = uFnLess_StrStr->iNative;
	uFnLess_StrStr->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnLess_StrStr, &Less_StrStr_Params, nullptr);
	uFnLess_StrStr->iNative = nativeIndex;

	return Less_StrStr_Params.ReturnValue;
}

// Function Core.Object.At_StrStr
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[168])
// Parameter Info:
// class FString                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
// class FString                  A                              (CPF_Parm | CPF_CoerceParm | CPF_NeedCtorLink)
// class FString                  B                              (CPF_Parm | CPF_CoerceParm | CPF_NeedCtorLink)

class FString UObject::At_StrStr(const class FString& A, const class FString& B)
{
	static UFunction* uFnAt_StrStr = nullptr;

	if (!uFnAt_StrStr)
	{
		uFnAt_StrStr = UFunction::FindFunction("Function Core.Object.At_StrStr");
	}

	UObject_execAt_StrStr_Params At_StrStr_Params;
	memset(&At_StrStr_Params, 0, sizeof(At_StrStr_Params));

	if (!uFnAt_StrStr)
	{
		return At_StrStr_Params.ReturnValue;
	}
	memcpy_s(&At_StrStr_Params.A, sizeof(At_StrStr_Params.A), &A, sizeof(A));
	memcpy_s(&At_StrStr_Params.B, sizeof(At_StrStr_Params.B), &B, sizeof(B));

	uint16_t nativeIndex = uFnAt_StrStr->iNative;
	uFnAt_StrStr->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnAt_StrStr, &At_StrStr_Params, nullptr);
	uFnAt_StrStr->iNative = nativeIndex;

	return At_StrStr_Params.ReturnValue;
}

// Function Core.Object.Concat_StrStr
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[112])
// Parameter Info:
// class FString                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
// class FString                  A                              (CPF_Parm | CPF_CoerceParm | CPF_NeedCtorLink)
// class FString                  B                              (CPF_Parm | CPF_CoerceParm | CPF_NeedCtorLink)

class FString UObject::Concat_StrStr(const class FString& A, const class FString& B)
{
	static UFunction* uFnConcat_StrStr = nullptr;

	if (!uFnConcat_StrStr)
	{
		uFnConcat_StrStr = UFunction::FindFunction("Function Core.Object.Concat_StrStr");
	}

	UObject_execConcat_StrStr_Params Concat_StrStr_Params;
	memset(&Concat_StrStr_Params, 0, sizeof(Concat_StrStr_Params));

	if (!uFnConcat_StrStr)
	{
		return Concat_StrStr_Params.ReturnValue;
	}
	memcpy_s(&Concat_StrStr_Params.A, sizeof(Concat_StrStr_Params.A), &A, sizeof(A));
	memcpy_s(&Concat_StrStr_Params.B, sizeof(Concat_StrStr_Params.B), &B, sizeof(B));

	uint16_t nativeIndex = uFnConcat_StrStr->iNative;
	uFnConcat_StrStr->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnConcat_StrStr, &Concat_StrStr_Params, nullptr);
	uFnConcat_StrStr->iNative = nativeIndex;

	return Concat_StrStr_Params.ReturnValue;
}

// Function Core.Object.MakeRotator
// [0x00822003] (FUNC_Final | FUNC_Defined | FUNC_Static | FUNC_Public | FUNC_HasDefaults)
// Parameter Info:
// struct FRotator                ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        Pitch                          (CPF_Parm)
// int32_t                        Yaw                            (CPF_Parm)
// int32_t                        Roll                           (CPF_Parm)

struct FRotator UObject::MakeRotator(int32_t Pitch, int32_t Yaw, int32_t Roll)
{
	static UFunction* uFnMakeRotator = nullptr;

	if (!uFnMakeRotator)
	{
		uFnMakeRotator = UFunction::FindFunction("Function Core.Object.MakeRotator");
	}

	UObject_execMakeRotator_Params MakeRotator_Params;
	memset(&MakeRotator_Params, 0, sizeof(MakeRotator_Params));

	if (!uFnMakeRotator)
	{
		return MakeRotator_Params.ReturnValue;
	}
	MakeRotator_Params.Pitch = Pitch;
	MakeRotator_Params.Yaw = Yaw;
	MakeRotator_Params.Roll = Roll;

	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnMakeRotator, &MakeRotator_Params, nullptr);

	return MakeRotator_Params.ReturnValue;
}

// Function Core.Object.SClampRotAxis
// [0x00422103] (FUNC_Final | FUNC_Defined | FUNC_Simulated | FUNC_Static | FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          DeltaTime                      (CPF_Parm)
// int32_t                        ViewAxis                       (CPF_Parm)
// int32_t                        MaxLimit                       (CPF_Parm)
// int32_t                        MinLimit                       (CPF_Parm)
// float                          InterpolationSpeed             (CPF_Parm)
// int32_t                        out_DeltaViewAxis              (CPF_Parm | CPF_OutParm)

bool UObject::SClampRotAxis(float DeltaTime, int32_t ViewAxis, int32_t MaxLimit, int32_t MinLimit, float InterpolationSpeed, int32_t& outOut_DeltaViewAxis)
{
	static UFunction* uFnSClampRotAxis = nullptr;

	if (!uFnSClampRotAxis)
	{
		uFnSClampRotAxis = UFunction::FindFunction("Function Core.Object.SClampRotAxis");
	}

	UObject_execSClampRotAxis_Params SClampRotAxis_Params;
	memset(&SClampRotAxis_Params, 0, sizeof(SClampRotAxis_Params));

	if (!uFnSClampRotAxis)
	{
		return SClampRotAxis_Params.ReturnValue;
	}
	SClampRotAxis_Params.DeltaTime = DeltaTime;
	SClampRotAxis_Params.ViewAxis = ViewAxis;
	SClampRotAxis_Params.MaxLimit = MaxLimit;
	SClampRotAxis_Params.MinLimit = MinLimit;
	SClampRotAxis_Params.InterpolationSpeed = InterpolationSpeed;
	SClampRotAxis_Params.out_DeltaViewAxis = outOut_DeltaViewAxis;

	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnSClampRotAxis, &SClampRotAxis_Params, nullptr);

	outOut_DeltaViewAxis = SClampRotAxis_Params.out_DeltaViewAxis;

	return SClampRotAxis_Params.ReturnValue;
}

// Function Core.Object.ClampRotAxisFromRange
// [0x00022103] (FUNC_Final | FUNC_Defined | FUNC_Simulated | FUNC_Static | FUNC_Public)
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        Current                        (CPF_Parm)
// int32_t                        Min                            (CPF_Parm)
// int32_t                        Max                            (CPF_Parm)

int32_t UObject::ClampRotAxisFromRange(int32_t Current, int32_t Min, int32_t Max)
{
	static UFunction* uFnClampRotAxisFromRange = nullptr;

	if (!uFnClampRotAxisFromRange)
	{
		uFnClampRotAxisFromRange = UFunction::FindFunction("Function Core.Object.ClampRotAxisFromRange");
	}

	UObject_execClampRotAxisFromRange_Params ClampRotAxisFromRange_Params;
	memset(&ClampRotAxisFromRange_Params, 0, sizeof(ClampRotAxisFromRange_Params));

	if (!uFnClampRotAxisFromRange)
	{
		return ClampRotAxisFromRange_Params.ReturnValue;
	}
	ClampRotAxisFromRange_Params.Current = Current;
	ClampRotAxisFromRange_Params.Min = Min;
	ClampRotAxisFromRange_Params.Max = Max;

	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnClampRotAxisFromRange, &ClampRotAxisFromRange_Params, nullptr);

	return ClampRotAxisFromRange_Params.ReturnValue;
}

// Function Core.Object.ClampRotAxisFromBase
// [0x00022103] (FUNC_Final | FUNC_Defined | FUNC_Simulated | FUNC_Static | FUNC_Public)
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        Current                        (CPF_Parm)
// int32_t                        Center                         (CPF_Parm)
// int32_t                        MaxDelta                       (CPF_Parm)

int32_t UObject::ClampRotAxisFromBase(int32_t Current, int32_t Center, int32_t MaxDelta)
{
	static UFunction* uFnClampRotAxisFromBase = nullptr;

	if (!uFnClampRotAxisFromBase)
	{
		uFnClampRotAxisFromBase = UFunction::FindFunction("Function Core.Object.ClampRotAxisFromBase");
	}

	UObject_execClampRotAxisFromBase_Params ClampRotAxisFromBase_Params;
	memset(&ClampRotAxisFromBase_Params, 0, sizeof(ClampRotAxisFromBase_Params));

	if (!uFnClampRotAxisFromBase)
	{
		return ClampRotAxisFromBase_Params.ReturnValue;
	}
	ClampRotAxisFromBase_Params.Current = Current;
	ClampRotAxisFromBase_Params.Center = Center;
	ClampRotAxisFromBase_Params.MaxDelta = MaxDelta;

	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnClampRotAxisFromBase, &ClampRotAxisFromBase_Params, nullptr);

	return ClampRotAxisFromBase_Params.ReturnValue;
}

// Function Core.Object.ClampRotAxis
// [0x00422103] (FUNC_Final | FUNC_Defined | FUNC_Simulated | FUNC_Static | FUNC_Public | FUNC_HasOutParms)
// Parameter Info:
// int32_t                        ViewAxis                       (CPF_Parm)
// int32_t                        MaxLimit                       (CPF_Parm)
// int32_t                        MinLimit                       (CPF_Parm)
// int32_t                        out_DeltaViewAxis              (CPF_Parm | CPF_OutParm)

void UObject::ClampRotAxis(int32_t ViewAxis, int32_t MaxLimit, int32_t MinLimit, int32_t& outOut_DeltaViewAxis)
{
	static UFunction* uFnClampRotAxis = nullptr;

	if (!uFnClampRotAxis)
	{
		uFnClampRotAxis = UFunction::FindFunction("Function Core.Object.ClampRotAxis");
	}

	UObject_execClampRotAxis_Params ClampRotAxis_Params;
	memset(&ClampRotAxis_Params, 0, sizeof(ClampRotAxis_Params));

	if (!uFnClampRotAxis)
	{
		return;
	}
	ClampRotAxis_Params.ViewAxis = ViewAxis;
	ClampRotAxis_Params.MaxLimit = MaxLimit;
	ClampRotAxis_Params.MinLimit = MinLimit;
	ClampRotAxis_Params.out_DeltaViewAxis = outOut_DeltaViewAxis;

	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnClampRotAxis, &ClampRotAxis_Params, nullptr);

	outOut_DeltaViewAxis = ClampRotAxis_Params.out_DeltaViewAxis;
}

// Function Core.Object.RSize
// [0x00022003] (FUNC_Final | FUNC_Defined | FUNC_Static | FUNC_Public)
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FRotator                R                              (CPF_Parm)

float UObject::RSize(const struct FRotator& R)
{
	static UFunction* uFnRSize = nullptr;

	if (!uFnRSize)
	{
		uFnRSize = UFunction::FindFunction("Function Core.Object.RSize");
	}

	UObject_execRSize_Params RSize_Params;
	memset(&RSize_Params, 0, sizeof(RSize_Params));

	if (!uFnRSize)
	{
		return RSize_Params.ReturnValue;
	}
	memcpy_s(&RSize_Params.R, sizeof(RSize_Params.R), &R, sizeof(R));

	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnRSize, &RSize_Params, nullptr);

	return RSize_Params.ReturnValue;
}

// Function Core.Object.RDiff
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FRotator                A                              (CPF_Parm)
// struct FRotator                B                              (CPF_Parm)

float UObject::RDiff(const struct FRotator& A, const struct FRotator& B)
{
	static UFunction* uFnRDiff = nullptr;

	if (!uFnRDiff)
	{
		uFnRDiff = UFunction::FindFunction("Function Core.Object.RDiff");
	}

	UObject_execRDiff_Params RDiff_Params;
	memset(&RDiff_Params, 0, sizeof(RDiff_Params));

	if (!uFnRDiff)
	{
		return RDiff_Params.ReturnValue;
	}
	memcpy_s(&RDiff_Params.A, sizeof(RDiff_Params.A), &A, sizeof(A));
	memcpy_s(&RDiff_Params.B, sizeof(RDiff_Params.B), &B, sizeof(B));

	uint16_t nativeIndex = uFnRDiff->iNative;
	uFnRDiff->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnRDiff, &RDiff_Params, nullptr);
	uFnRDiff->iNative = nativeIndex;

	return RDiff_Params.ReturnValue;
}

// Function Core.Object.NormalizeRotAxis
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        Angle                          (CPF_Parm)

int32_t UObject::NormalizeRotAxis(int32_t Angle)
{
	static UFunction* uFnNormalizeRotAxis = nullptr;

	if (!uFnNormalizeRotAxis)
	{
		uFnNormalizeRotAxis = UFunction::FindFunction("Function Core.Object.NormalizeRotAxis");
	}

	UObject_execNormalizeRotAxis_Params NormalizeRotAxis_Params;
	memset(&NormalizeRotAxis_Params, 0, sizeof(NormalizeRotAxis_Params));

	if (!uFnNormalizeRotAxis)
	{
		return NormalizeRotAxis_Params.ReturnValue;
	}
	NormalizeRotAxis_Params.Angle = Angle;

	uint16_t nativeIndex = uFnNormalizeRotAxis->iNative;
	uFnNormalizeRotAxis->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnNormalizeRotAxis, &NormalizeRotAxis_Params, nullptr);
	uFnNormalizeRotAxis->iNative = nativeIndex;

	return NormalizeRotAxis_Params.ReturnValue;
}

// Function Core.Object.RInterpTo
// [0x00026401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// struct FRotator                ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FRotator                Current                        (CPF_Parm)
// struct FRotator                Target                         (CPF_Parm)
// float                          DeltaTime                      (CPF_Parm)
// float                          InterpSpeed                    (CPF_Parm)
// uint32_t                       bConstantInterpSpeed           (CPF_OptionalParm | CPF_Parm)

struct FRotator UObject::RInterpTo(const struct FRotator& Current, const struct FRotator& Target, float DeltaTime, float InterpSpeed, bool optionalBConstantInterpSpeed)
{
	static UFunction* uFnRInterpTo = nullptr;

	if (!uFnRInterpTo)
	{
		uFnRInterpTo = UFunction::FindFunction("Function Core.Object.RInterpTo");
	}

	UObject_execRInterpTo_Params RInterpTo_Params;
	memset(&RInterpTo_Params, 0, sizeof(RInterpTo_Params));

	if (!uFnRInterpTo)
	{
		return RInterpTo_Params.ReturnValue;
	}
	memcpy_s(&RInterpTo_Params.Current, sizeof(RInterpTo_Params.Current), &Current, sizeof(Current));
	memcpy_s(&RInterpTo_Params.Target, sizeof(RInterpTo_Params.Target), &Target, sizeof(Target));
	RInterpTo_Params.DeltaTime = DeltaTime;
	RInterpTo_Params.InterpSpeed = InterpSpeed;
	RInterpTo_Params.bConstantInterpSpeed = optionalBConstantInterpSpeed;

	uint16_t nativeIndex = uFnRInterpTo->iNative;
	uFnRInterpTo->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnRInterpTo, &RInterpTo_Params, nullptr);
	uFnRInterpTo->iNative = nativeIndex;

	return RInterpTo_Params.ReturnValue;
}

// Function Core.Object.RTransform
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// struct FRotator                ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FRotator                R                              (CPF_Parm)
// struct FRotator                RBasis                         (CPF_Parm)

struct FRotator UObject::RTransform(const struct FRotator& R, const struct FRotator& RBasis)
{
	static UFunction* uFnRTransform = nullptr;

	if (!uFnRTransform)
	{
		uFnRTransform = UFunction::FindFunction("Function Core.Object.RTransform");
	}

	UObject_execRTransform_Params RTransform_Params;
	memset(&RTransform_Params, 0, sizeof(RTransform_Params));

	if (!uFnRTransform)
	{
		return RTransform_Params.ReturnValue;
	}
	memcpy_s(&RTransform_Params.R, sizeof(RTransform_Params.R), &R, sizeof(R));
	memcpy_s(&RTransform_Params.RBasis, sizeof(RTransform_Params.RBasis), &RBasis, sizeof(RBasis));

	uint16_t nativeIndex = uFnRTransform->iNative;
	uFnRTransform->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnRTransform, &RTransform_Params, nullptr);
	uFnRTransform->iNative = nativeIndex;

	return RTransform_Params.ReturnValue;
}

// Function Core.Object.RSmerp
// [0x00026401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// struct FRotator                ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FRotator                A                              (CPF_Parm)
// struct FRotator                B                              (CPF_Parm)
// float                          Alpha                          (CPF_Parm)
// uint32_t                       bShortestPath                  (CPF_OptionalParm | CPF_Parm)

struct FRotator UObject::RSmerp(const struct FRotator& A, const struct FRotator& B, float Alpha, bool optionalBShortestPath)
{
	static UFunction* uFnRSmerp = nullptr;

	if (!uFnRSmerp)
	{
		uFnRSmerp = UFunction::FindFunction("Function Core.Object.RSmerp");
	}

	UObject_execRSmerp_Params RSmerp_Params;
	memset(&RSmerp_Params, 0, sizeof(RSmerp_Params));

	if (!uFnRSmerp)
	{
		return RSmerp_Params.ReturnValue;
	}
	memcpy_s(&RSmerp_Params.A, sizeof(RSmerp_Params.A), &A, sizeof(A));
	memcpy_s(&RSmerp_Params.B, sizeof(RSmerp_Params.B), &B, sizeof(B));
	RSmerp_Params.Alpha = Alpha;
	RSmerp_Params.bShortestPath = optionalBShortestPath;

	uint16_t nativeIndex = uFnRSmerp->iNative;
	uFnRSmerp->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnRSmerp, &RSmerp_Params, nullptr);
	uFnRSmerp->iNative = nativeIndex;

	return RSmerp_Params.ReturnValue;
}

// Function Core.Object.RLerp
// [0x00026401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// struct FRotator                ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FRotator                A                              (CPF_Parm)
// struct FRotator                B                              (CPF_Parm)
// float                          Alpha                          (CPF_Parm)
// uint32_t                       bShortestPath                  (CPF_OptionalParm | CPF_Parm)

struct FRotator UObject::RLerp(const struct FRotator& A, const struct FRotator& B, float Alpha, bool optionalBShortestPath)
{
	static UFunction* uFnRLerp = nullptr;

	if (!uFnRLerp)
	{
		uFnRLerp = UFunction::FindFunction("Function Core.Object.RLerp");
	}

	UObject_execRLerp_Params RLerp_Params;
	memset(&RLerp_Params, 0, sizeof(RLerp_Params));

	if (!uFnRLerp)
	{
		return RLerp_Params.ReturnValue;
	}
	memcpy_s(&RLerp_Params.A, sizeof(RLerp_Params.A), &A, sizeof(A));
	memcpy_s(&RLerp_Params.B, sizeof(RLerp_Params.B), &B, sizeof(B));
	RLerp_Params.Alpha = Alpha;
	RLerp_Params.bShortestPath = optionalBShortestPath;

	uint16_t nativeIndex = uFnRLerp->iNative;
	uFnRLerp->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnRLerp, &RLerp_Params, nullptr);
	uFnRLerp->iNative = nativeIndex;

	return RLerp_Params.ReturnValue;
}

// Function Core.Object.Normalize
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// struct FRotator                ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FRotator                Rot                            (CPF_Parm)

struct FRotator UObject::Normalize(const struct FRotator& Rot)
{
	static UFunction* uFnNormalize = nullptr;

	if (!uFnNormalize)
	{
		uFnNormalize = UFunction::FindFunction("Function Core.Object.Normalize");
	}

	UObject_execNormalize_Params Normalize_Params;
	memset(&Normalize_Params, 0, sizeof(Normalize_Params));

	if (!uFnNormalize)
	{
		return Normalize_Params.ReturnValue;
	}
	memcpy_s(&Normalize_Params.Rot, sizeof(Normalize_Params.Rot), &Rot, sizeof(Rot));

	uint16_t nativeIndex = uFnNormalize->iNative;
	uFnNormalize->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnNormalize, &Normalize_Params, nullptr);
	uFnNormalize->iNative = nativeIndex;

	return Normalize_Params.ReturnValue;
}

// Function Core.Object.OrthoRotation
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// struct FRotator                ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 X                              (CPF_Parm)
// struct FVector                 Y                              (CPF_Parm)
// struct FVector                 Z                              (CPF_Parm)

struct FRotator UObject::OrthoRotation(const struct FVector& X, const struct FVector& Y, const struct FVector& Z)
{
	static UFunction* uFnOrthoRotation = nullptr;

	if (!uFnOrthoRotation)
	{
		uFnOrthoRotation = UFunction::FindFunction("Function Core.Object.OrthoRotation");
	}

	UObject_execOrthoRotation_Params OrthoRotation_Params;
	memset(&OrthoRotation_Params, 0, sizeof(OrthoRotation_Params));

	if (!uFnOrthoRotation)
	{
		return OrthoRotation_Params.ReturnValue;
	}
	memcpy_s(&OrthoRotation_Params.X, sizeof(OrthoRotation_Params.X), &X, sizeof(X));
	memcpy_s(&OrthoRotation_Params.Y, sizeof(OrthoRotation_Params.Y), &Y, sizeof(Y));
	memcpy_s(&OrthoRotation_Params.Z, sizeof(OrthoRotation_Params.Z), &Z, sizeof(Z));

	uint16_t nativeIndex = uFnOrthoRotation->iNative;
	uFnOrthoRotation->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnOrthoRotation, &OrthoRotation_Params, nullptr);
	uFnOrthoRotation->iNative = nativeIndex;

	return OrthoRotation_Params.ReturnValue;
}

// Function Core.Object.RotRand
// [0x00026401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_OptionalParm | FUNC_Public) (iNative[320])
// Parameter Info:
// struct FRotator                ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// uint32_t                       bRoll                          (CPF_OptionalParm | CPF_Parm)

struct FRotator UObject::RotRand(bool optionalBRoll)
{
	static UFunction* uFnRotRand = nullptr;

	if (!uFnRotRand)
	{
		uFnRotRand = UFunction::FindFunction("Function Core.Object.RotRand");
	}

	UObject_execRotRand_Params RotRand_Params;
	memset(&RotRand_Params, 0, sizeof(RotRand_Params));

	if (!uFnRotRand)
	{
		return RotRand_Params.ReturnValue;
	}
	RotRand_Params.bRoll = optionalBRoll;

	uint16_t nativeIndex = uFnRotRand->iNative;
	uFnRotRand->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnRotRand, &RotRand_Params, nullptr);
	uFnRotRand->iNative = nativeIndex;

	return RotRand_Params.ReturnValue;
}

// Function Core.Object.GetUnAxes
// [0x00422401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public | FUNC_HasOutParms) (iNative[230])
// Parameter Info:
// struct FRotator                A                              (CPF_Parm)
// struct FVector                 X                              (CPF_Parm | CPF_OutParm)
// struct FVector                 Y                              (CPF_Parm | CPF_OutParm)
// struct FVector                 Z                              (CPF_Parm | CPF_OutParm)

void UObject::GetUnAxes(const struct FRotator& A, struct FVector& outX, struct FVector& outY, struct FVector& outZ)
{
	static UFunction* uFnGetUnAxes = nullptr;

	if (!uFnGetUnAxes)
	{
		uFnGetUnAxes = UFunction::FindFunction("Function Core.Object.GetUnAxes");
	}

	UObject_execGetUnAxes_Params GetUnAxes_Params;
	memset(&GetUnAxes_Params, 0, sizeof(GetUnAxes_Params));

	if (!uFnGetUnAxes)
	{
		return;
	}
	memcpy_s(&GetUnAxes_Params.A, sizeof(GetUnAxes_Params.A), &A, sizeof(A));
	memcpy_s(&GetUnAxes_Params.X, sizeof(GetUnAxes_Params.X), &outX, sizeof(outX));
	memcpy_s(&GetUnAxes_Params.Y, sizeof(GetUnAxes_Params.Y), &outY, sizeof(outY));
	memcpy_s(&GetUnAxes_Params.Z, sizeof(GetUnAxes_Params.Z), &outZ, sizeof(outZ));

	uint16_t nativeIndex = uFnGetUnAxes->iNative;
	uFnGetUnAxes->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnGetUnAxes, &GetUnAxes_Params, nullptr);
	uFnGetUnAxes->iNative = nativeIndex;

	memcpy_s(&outX, sizeof(outX), &GetUnAxes_Params.X, sizeof(GetUnAxes_Params.X));
	memcpy_s(&outY, sizeof(outY), &GetUnAxes_Params.Y, sizeof(GetUnAxes_Params.Y));
	memcpy_s(&outZ, sizeof(outZ), &GetUnAxes_Params.Z, sizeof(GetUnAxes_Params.Z));
}

// Function Core.Object.GetAxes
// [0x00422401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public | FUNC_HasOutParms) (iNative[229])
// Parameter Info:
// struct FRotator                A                              (CPF_Parm)
// struct FVector                 X                              (CPF_Parm | CPF_OutParm)
// struct FVector                 Y                              (CPF_Parm | CPF_OutParm)
// struct FVector                 Z                              (CPF_Parm | CPF_OutParm)

void UObject::GetAxes(const struct FRotator& A, struct FVector& outX, struct FVector& outY, struct FVector& outZ)
{
	static UFunction* uFnGetAxes = nullptr;

	if (!uFnGetAxes)
	{
		uFnGetAxes = UFunction::FindFunction("Function Core.Object.GetAxes");
	}

	UObject_execGetAxes_Params GetAxes_Params;
	memset(&GetAxes_Params, 0, sizeof(GetAxes_Params));

	if (!uFnGetAxes)
	{
		return;
	}
	memcpy_s(&GetAxes_Params.A, sizeof(GetAxes_Params.A), &A, sizeof(A));
	memcpy_s(&GetAxes_Params.X, sizeof(GetAxes_Params.X), &outX, sizeof(outX));
	memcpy_s(&GetAxes_Params.Y, sizeof(GetAxes_Params.Y), &outY, sizeof(outY));
	memcpy_s(&GetAxes_Params.Z, sizeof(GetAxes_Params.Z), &outZ, sizeof(outZ));

	uint16_t nativeIndex = uFnGetAxes->iNative;
	uFnGetAxes->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnGetAxes, &GetAxes_Params, nullptr);
	uFnGetAxes->iNative = nativeIndex;

	memcpy_s(&outX, sizeof(outX), &GetAxes_Params.X, sizeof(GetAxes_Params.X));
	memcpy_s(&outY, sizeof(outY), &GetAxes_Params.Y, sizeof(GetAxes_Params.Y));
	memcpy_s(&outZ, sizeof(outZ), &GetAxes_Params.Z, sizeof(GetAxes_Params.Z));
}

// Function Core.Object.ClockwiseFrom_IntInt
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        A                              (CPF_Parm)
// int32_t                        B                              (CPF_Parm)

bool UObject::ClockwiseFrom_IntInt(int32_t A, int32_t B)
{
	static UFunction* uFnClockwiseFrom_IntInt = nullptr;

	if (!uFnClockwiseFrom_IntInt)
	{
		uFnClockwiseFrom_IntInt = UFunction::FindFunction("Function Core.Object.ClockwiseFrom_IntInt");
	}

	UObject_execClockwiseFrom_IntInt_Params ClockwiseFrom_IntInt_Params;
	memset(&ClockwiseFrom_IntInt_Params, 0, sizeof(ClockwiseFrom_IntInt_Params));

	if (!uFnClockwiseFrom_IntInt)
	{
		return ClockwiseFrom_IntInt_Params.ReturnValue;
	}
	ClockwiseFrom_IntInt_Params.A = A;
	ClockwiseFrom_IntInt_Params.B = B;

	uint16_t nativeIndex = uFnClockwiseFrom_IntInt->iNative;
	uFnClockwiseFrom_IntInt->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnClockwiseFrom_IntInt, &ClockwiseFrom_IntInt_Params, nullptr);
	uFnClockwiseFrom_IntInt->iNative = nativeIndex;

	return ClockwiseFrom_IntInt_Params.ReturnValue;
}

// Function Core.Object.SubtractEqual_RotatorRotator
// [0x00423401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public | FUNC_HasOutParms) (iNative[319])
// Parameter Info:
// struct FRotator                ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FRotator                B                              (CPF_Parm)
// struct FRotator                A                              (CPF_Parm | CPF_OutParm)

struct FRotator UObject::SubtractEqual_RotatorRotator(const struct FRotator& B, struct FRotator& outA)
{
	static UFunction* uFnSubtractEqual_RotatorRotator = nullptr;

	if (!uFnSubtractEqual_RotatorRotator)
	{
		uFnSubtractEqual_RotatorRotator = UFunction::FindFunction("Function Core.Object.SubtractEqual_RotatorRotator");
	}

	UObject_execSubtractEqual_RotatorRotator_Params SubtractEqual_RotatorRotator_Params;
	memset(&SubtractEqual_RotatorRotator_Params, 0, sizeof(SubtractEqual_RotatorRotator_Params));

	if (!uFnSubtractEqual_RotatorRotator)
	{
		return SubtractEqual_RotatorRotator_Params.ReturnValue;
	}
	memcpy_s(&SubtractEqual_RotatorRotator_Params.B, sizeof(SubtractEqual_RotatorRotator_Params.B), &B, sizeof(B));
	memcpy_s(&SubtractEqual_RotatorRotator_Params.A, sizeof(SubtractEqual_RotatorRotator_Params.A), &outA, sizeof(outA));

	uint16_t nativeIndex = uFnSubtractEqual_RotatorRotator->iNative;
	uFnSubtractEqual_RotatorRotator->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnSubtractEqual_RotatorRotator, &SubtractEqual_RotatorRotator_Params, nullptr);
	uFnSubtractEqual_RotatorRotator->iNative = nativeIndex;

	memcpy_s(&outA, sizeof(outA), &SubtractEqual_RotatorRotator_Params.A, sizeof(SubtractEqual_RotatorRotator_Params.A));

	return SubtractEqual_RotatorRotator_Params.ReturnValue;
}

// Function Core.Object.AddEqual_RotatorRotator
// [0x00423401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public | FUNC_HasOutParms) (iNative[318])
// Parameter Info:
// struct FRotator                ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FRotator                B                              (CPF_Parm)
// struct FRotator                A                              (CPF_Parm | CPF_OutParm)

struct FRotator UObject::AddEqual_RotatorRotator(const struct FRotator& B, struct FRotator& outA)
{
	static UFunction* uFnAddEqual_RotatorRotator = nullptr;

	if (!uFnAddEqual_RotatorRotator)
	{
		uFnAddEqual_RotatorRotator = UFunction::FindFunction("Function Core.Object.AddEqual_RotatorRotator");
	}

	UObject_execAddEqual_RotatorRotator_Params AddEqual_RotatorRotator_Params;
	memset(&AddEqual_RotatorRotator_Params, 0, sizeof(AddEqual_RotatorRotator_Params));

	if (!uFnAddEqual_RotatorRotator)
	{
		return AddEqual_RotatorRotator_Params.ReturnValue;
	}
	memcpy_s(&AddEqual_RotatorRotator_Params.B, sizeof(AddEqual_RotatorRotator_Params.B), &B, sizeof(B));
	memcpy_s(&AddEqual_RotatorRotator_Params.A, sizeof(AddEqual_RotatorRotator_Params.A), &outA, sizeof(outA));

	uint16_t nativeIndex = uFnAddEqual_RotatorRotator->iNative;
	uFnAddEqual_RotatorRotator->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnAddEqual_RotatorRotator, &AddEqual_RotatorRotator_Params, nullptr);
	uFnAddEqual_RotatorRotator->iNative = nativeIndex;

	memcpy_s(&outA, sizeof(outA), &AddEqual_RotatorRotator_Params.A, sizeof(AddEqual_RotatorRotator_Params.A));

	return AddEqual_RotatorRotator_Params.ReturnValue;
}

// Function Core.Object.Subtract_RotatorRotator
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[317])
// Parameter Info:
// struct FRotator                ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FRotator                A                              (CPF_Parm)
// struct FRotator                B                              (CPF_Parm)

struct FRotator UObject::Subtract_RotatorRotator(const struct FRotator& A, const struct FRotator& B)
{
	static UFunction* uFnSubtract_RotatorRotator = nullptr;

	if (!uFnSubtract_RotatorRotator)
	{
		uFnSubtract_RotatorRotator = UFunction::FindFunction("Function Core.Object.Subtract_RotatorRotator");
	}

	UObject_execSubtract_RotatorRotator_Params Subtract_RotatorRotator_Params;
	memset(&Subtract_RotatorRotator_Params, 0, sizeof(Subtract_RotatorRotator_Params));

	if (!uFnSubtract_RotatorRotator)
	{
		return Subtract_RotatorRotator_Params.ReturnValue;
	}
	memcpy_s(&Subtract_RotatorRotator_Params.A, sizeof(Subtract_RotatorRotator_Params.A), &A, sizeof(A));
	memcpy_s(&Subtract_RotatorRotator_Params.B, sizeof(Subtract_RotatorRotator_Params.B), &B, sizeof(B));

	uint16_t nativeIndex = uFnSubtract_RotatorRotator->iNative;
	uFnSubtract_RotatorRotator->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnSubtract_RotatorRotator, &Subtract_RotatorRotator_Params, nullptr);
	uFnSubtract_RotatorRotator->iNative = nativeIndex;

	return Subtract_RotatorRotator_Params.ReturnValue;
}

// Function Core.Object.Add_RotatorRotator
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[316])
// Parameter Info:
// struct FRotator                ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FRotator                A                              (CPF_Parm)
// struct FRotator                B                              (CPF_Parm)

struct FRotator UObject::Add_RotatorRotator(const struct FRotator& A, const struct FRotator& B)
{
	static UFunction* uFnAdd_RotatorRotator = nullptr;

	if (!uFnAdd_RotatorRotator)
	{
		uFnAdd_RotatorRotator = UFunction::FindFunction("Function Core.Object.Add_RotatorRotator");
	}

	UObject_execAdd_RotatorRotator_Params Add_RotatorRotator_Params;
	memset(&Add_RotatorRotator_Params, 0, sizeof(Add_RotatorRotator_Params));

	if (!uFnAdd_RotatorRotator)
	{
		return Add_RotatorRotator_Params.ReturnValue;
	}
	memcpy_s(&Add_RotatorRotator_Params.A, sizeof(Add_RotatorRotator_Params.A), &A, sizeof(A));
	memcpy_s(&Add_RotatorRotator_Params.B, sizeof(Add_RotatorRotator_Params.B), &B, sizeof(B));

	uint16_t nativeIndex = uFnAdd_RotatorRotator->iNative;
	uFnAdd_RotatorRotator->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnAdd_RotatorRotator, &Add_RotatorRotator_Params, nullptr);
	uFnAdd_RotatorRotator->iNative = nativeIndex;

	return Add_RotatorRotator_Params.ReturnValue;
}

// Function Core.Object.DivideEqual_RotatorFloat
// [0x00423401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public | FUNC_HasOutParms) (iNative[291])
// Parameter Info:
// struct FRotator                ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          B                              (CPF_Parm)
// struct FRotator                A                              (CPF_Parm | CPF_OutParm)

struct FRotator UObject::DivideEqual_RotatorFloat(float B, struct FRotator& outA)
{
	static UFunction* uFnDivideEqual_RotatorFloat = nullptr;

	if (!uFnDivideEqual_RotatorFloat)
	{
		uFnDivideEqual_RotatorFloat = UFunction::FindFunction("Function Core.Object.DivideEqual_RotatorFloat");
	}

	UObject_execDivideEqual_RotatorFloat_Params DivideEqual_RotatorFloat_Params;
	memset(&DivideEqual_RotatorFloat_Params, 0, sizeof(DivideEqual_RotatorFloat_Params));

	if (!uFnDivideEqual_RotatorFloat)
	{
		return DivideEqual_RotatorFloat_Params.ReturnValue;
	}
	DivideEqual_RotatorFloat_Params.B = B;
	memcpy_s(&DivideEqual_RotatorFloat_Params.A, sizeof(DivideEqual_RotatorFloat_Params.A), &outA, sizeof(outA));

	uint16_t nativeIndex = uFnDivideEqual_RotatorFloat->iNative;
	uFnDivideEqual_RotatorFloat->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnDivideEqual_RotatorFloat, &DivideEqual_RotatorFloat_Params, nullptr);
	uFnDivideEqual_RotatorFloat->iNative = nativeIndex;

	memcpy_s(&outA, sizeof(outA), &DivideEqual_RotatorFloat_Params.A, sizeof(DivideEqual_RotatorFloat_Params.A));

	return DivideEqual_RotatorFloat_Params.ReturnValue;
}

// Function Core.Object.MultiplyEqual_RotatorFloat
// [0x00423401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public | FUNC_HasOutParms) (iNative[290])
// Parameter Info:
// struct FRotator                ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          B                              (CPF_Parm)
// struct FRotator                A                              (CPF_Parm | CPF_OutParm)

struct FRotator UObject::MultiplyEqual_RotatorFloat(float B, struct FRotator& outA)
{
	static UFunction* uFnMultiplyEqual_RotatorFloat = nullptr;

	if (!uFnMultiplyEqual_RotatorFloat)
	{
		uFnMultiplyEqual_RotatorFloat = UFunction::FindFunction("Function Core.Object.MultiplyEqual_RotatorFloat");
	}

	UObject_execMultiplyEqual_RotatorFloat_Params MultiplyEqual_RotatorFloat_Params;
	memset(&MultiplyEqual_RotatorFloat_Params, 0, sizeof(MultiplyEqual_RotatorFloat_Params));

	if (!uFnMultiplyEqual_RotatorFloat)
	{
		return MultiplyEqual_RotatorFloat_Params.ReturnValue;
	}
	MultiplyEqual_RotatorFloat_Params.B = B;
	memcpy_s(&MultiplyEqual_RotatorFloat_Params.A, sizeof(MultiplyEqual_RotatorFloat_Params.A), &outA, sizeof(outA));

	uint16_t nativeIndex = uFnMultiplyEqual_RotatorFloat->iNative;
	uFnMultiplyEqual_RotatorFloat->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnMultiplyEqual_RotatorFloat, &MultiplyEqual_RotatorFloat_Params, nullptr);
	uFnMultiplyEqual_RotatorFloat->iNative = nativeIndex;

	memcpy_s(&outA, sizeof(outA), &MultiplyEqual_RotatorFloat_Params.A, sizeof(MultiplyEqual_RotatorFloat_Params.A));

	return MultiplyEqual_RotatorFloat_Params.ReturnValue;
}

// Function Core.Object.Divide_RotatorFloat
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[289])
// Parameter Info:
// struct FRotator                ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FRotator                A                              (CPF_Parm)
// float                          B                              (CPF_Parm)

struct FRotator UObject::Divide_RotatorFloat(const struct FRotator& A, float B)
{
	static UFunction* uFnDivide_RotatorFloat = nullptr;

	if (!uFnDivide_RotatorFloat)
	{
		uFnDivide_RotatorFloat = UFunction::FindFunction("Function Core.Object.Divide_RotatorFloat");
	}

	UObject_execDivide_RotatorFloat_Params Divide_RotatorFloat_Params;
	memset(&Divide_RotatorFloat_Params, 0, sizeof(Divide_RotatorFloat_Params));

	if (!uFnDivide_RotatorFloat)
	{
		return Divide_RotatorFloat_Params.ReturnValue;
	}
	memcpy_s(&Divide_RotatorFloat_Params.A, sizeof(Divide_RotatorFloat_Params.A), &A, sizeof(A));
	Divide_RotatorFloat_Params.B = B;

	uint16_t nativeIndex = uFnDivide_RotatorFloat->iNative;
	uFnDivide_RotatorFloat->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnDivide_RotatorFloat, &Divide_RotatorFloat_Params, nullptr);
	uFnDivide_RotatorFloat->iNative = nativeIndex;

	return Divide_RotatorFloat_Params.ReturnValue;
}

// Function Core.Object.Multiply_FloatRotator
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[288])
// Parameter Info:
// struct FRotator                ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          A                              (CPF_Parm)
// struct FRotator                B                              (CPF_Parm)

struct FRotator UObject::Multiply_FloatRotator(float A, const struct FRotator& B)
{
	static UFunction* uFnMultiply_FloatRotator = nullptr;

	if (!uFnMultiply_FloatRotator)
	{
		uFnMultiply_FloatRotator = UFunction::FindFunction("Function Core.Object.Multiply_FloatRotator");
	}

	UObject_execMultiply_FloatRotator_Params Multiply_FloatRotator_Params;
	memset(&Multiply_FloatRotator_Params, 0, sizeof(Multiply_FloatRotator_Params));

	if (!uFnMultiply_FloatRotator)
	{
		return Multiply_FloatRotator_Params.ReturnValue;
	}
	Multiply_FloatRotator_Params.A = A;
	memcpy_s(&Multiply_FloatRotator_Params.B, sizeof(Multiply_FloatRotator_Params.B), &B, sizeof(B));

	uint16_t nativeIndex = uFnMultiply_FloatRotator->iNative;
	uFnMultiply_FloatRotator->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnMultiply_FloatRotator, &Multiply_FloatRotator_Params, nullptr);
	uFnMultiply_FloatRotator->iNative = nativeIndex;

	return Multiply_FloatRotator_Params.ReturnValue;
}

// Function Core.Object.Multiply_RotatorFloat
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[287])
// Parameter Info:
// struct FRotator                ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FRotator                A                              (CPF_Parm)
// float                          B                              (CPF_Parm)

struct FRotator UObject::Multiply_RotatorFloat(const struct FRotator& A, float B)
{
	static UFunction* uFnMultiply_RotatorFloat = nullptr;

	if (!uFnMultiply_RotatorFloat)
	{
		uFnMultiply_RotatorFloat = UFunction::FindFunction("Function Core.Object.Multiply_RotatorFloat");
	}

	UObject_execMultiply_RotatorFloat_Params Multiply_RotatorFloat_Params;
	memset(&Multiply_RotatorFloat_Params, 0, sizeof(Multiply_RotatorFloat_Params));

	if (!uFnMultiply_RotatorFloat)
	{
		return Multiply_RotatorFloat_Params.ReturnValue;
	}
	memcpy_s(&Multiply_RotatorFloat_Params.A, sizeof(Multiply_RotatorFloat_Params.A), &A, sizeof(A));
	Multiply_RotatorFloat_Params.B = B;

	uint16_t nativeIndex = uFnMultiply_RotatorFloat->iNative;
	uFnMultiply_RotatorFloat->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnMultiply_RotatorFloat, &Multiply_RotatorFloat_Params, nullptr);
	uFnMultiply_RotatorFloat->iNative = nativeIndex;

	return Multiply_RotatorFloat_Params.ReturnValue;
}

// Function Core.Object.NotEqual_RotatorRotator
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[203])
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FRotator                A                              (CPF_Parm)
// struct FRotator                B                              (CPF_Parm)

bool UObject::NotEqual_RotatorRotator(const struct FRotator& A, const struct FRotator& B)
{
	static UFunction* uFnNotEqual_RotatorRotator = nullptr;

	if (!uFnNotEqual_RotatorRotator)
	{
		uFnNotEqual_RotatorRotator = UFunction::FindFunction("Function Core.Object.NotEqual_RotatorRotator");
	}

	UObject_execNotEqual_RotatorRotator_Params NotEqual_RotatorRotator_Params;
	memset(&NotEqual_RotatorRotator_Params, 0, sizeof(NotEqual_RotatorRotator_Params));

	if (!uFnNotEqual_RotatorRotator)
	{
		return NotEqual_RotatorRotator_Params.ReturnValue;
	}
	memcpy_s(&NotEqual_RotatorRotator_Params.A, sizeof(NotEqual_RotatorRotator_Params.A), &A, sizeof(A));
	memcpy_s(&NotEqual_RotatorRotator_Params.B, sizeof(NotEqual_RotatorRotator_Params.B), &B, sizeof(B));

	uint16_t nativeIndex = uFnNotEqual_RotatorRotator->iNative;
	uFnNotEqual_RotatorRotator->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnNotEqual_RotatorRotator, &NotEqual_RotatorRotator_Params, nullptr);
	uFnNotEqual_RotatorRotator->iNative = nativeIndex;

	return NotEqual_RotatorRotator_Params.ReturnValue;
}

// Function Core.Object.EqualEqual_RotatorRotator
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[142])
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FRotator                A                              (CPF_Parm)
// struct FRotator                B                              (CPF_Parm)

bool UObject::EqualEqual_RotatorRotator(const struct FRotator& A, const struct FRotator& B)
{
	static UFunction* uFnEqualEqual_RotatorRotator = nullptr;

	if (!uFnEqualEqual_RotatorRotator)
	{
		uFnEqualEqual_RotatorRotator = UFunction::FindFunction("Function Core.Object.EqualEqual_RotatorRotator");
	}

	UObject_execEqualEqual_RotatorRotator_Params EqualEqual_RotatorRotator_Params;
	memset(&EqualEqual_RotatorRotator_Params, 0, sizeof(EqualEqual_RotatorRotator_Params));

	if (!uFnEqualEqual_RotatorRotator)
	{
		return EqualEqual_RotatorRotator_Params.ReturnValue;
	}
	memcpy_s(&EqualEqual_RotatorRotator_Params.A, sizeof(EqualEqual_RotatorRotator_Params.A), &A, sizeof(A));
	memcpy_s(&EqualEqual_RotatorRotator_Params.B, sizeof(EqualEqual_RotatorRotator_Params.B), &B, sizeof(B));

	uint16_t nativeIndex = uFnEqualEqual_RotatorRotator->iNative;
	uFnEqualEqual_RotatorRotator->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnEqualEqual_RotatorRotator, &EqualEqual_RotatorRotator_Params, nullptr);
	uFnEqualEqual_RotatorRotator->iNative = nativeIndex;

	return EqualEqual_RotatorRotator_Params.ReturnValue;
}

// Function Core.Object.InCylinder
// [0x00824103] (FUNC_Final | FUNC_Defined | FUNC_Simulated | FUNC_OptionalParm | FUNC_Public | FUNC_HasDefaults)
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 Origin                         (CPF_Parm)
// struct FRotator                Dir                            (CPF_Parm)
// float                          Width                          (CPF_Parm)
// struct FVector                 A                              (CPF_Parm)
// uint32_t                       bIgnoreZ                       (CPF_OptionalParm | CPF_Parm)

bool UObject::InCylinder(const struct FVector& Origin, const struct FRotator& Dir, float Width, const struct FVector& A, bool optionalBIgnoreZ)
{
	static UFunction* uFnInCylinder = nullptr;

	if (!uFnInCylinder)
	{
		uFnInCylinder = UFunction::FindFunction("Function Core.Object.InCylinder");
	}

	UObject_execInCylinder_Params InCylinder_Params;
	memset(&InCylinder_Params, 0, sizeof(InCylinder_Params));

	if (!uFnInCylinder)
	{
		return InCylinder_Params.ReturnValue;
	}
	memcpy_s(&InCylinder_Params.Origin, sizeof(InCylinder_Params.Origin), &Origin, sizeof(Origin));
	memcpy_s(&InCylinder_Params.Dir, sizeof(InCylinder_Params.Dir), &Dir, sizeof(Dir));
	InCylinder_Params.Width = Width;
	memcpy_s(&InCylinder_Params.A, sizeof(InCylinder_Params.A), &A, sizeof(A));
	InCylinder_Params.bIgnoreZ = optionalBIgnoreZ;

	this->ProcessEvent(uFnInCylinder, &InCylinder_Params, nullptr);

	return InCylinder_Params.ReturnValue;
}

// Function Core.Object.NoZDot
// [0x00020103] (FUNC_Final | FUNC_Defined | FUNC_Simulated | FUNC_Public)
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 A                              (CPF_Parm)
// struct FVector                 B                              (CPF_Parm)

float UObject::NoZDot(const struct FVector& A, const struct FVector& B)
{
	static UFunction* uFnNoZDot = nullptr;

	if (!uFnNoZDot)
	{
		uFnNoZDot = UFunction::FindFunction("Function Core.Object.NoZDot");
	}

	UObject_execNoZDot_Params NoZDot_Params;
	memset(&NoZDot_Params, 0, sizeof(NoZDot_Params));

	if (!uFnNoZDot)
	{
		return NoZDot_Params.ReturnValue;
	}
	memcpy_s(&NoZDot_Params.A, sizeof(NoZDot_Params.A), &A, sizeof(A));
	memcpy_s(&NoZDot_Params.B, sizeof(NoZDot_Params.B), &B, sizeof(B));

	this->ProcessEvent(uFnNoZDot, &NoZDot_Params, nullptr);

	return NoZDot_Params.ReturnValue;
}

// Function Core.Object.ClampLength
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 V                              (CPF_Parm)
// float                          MaxLength                      (CPF_Parm)

struct FVector UObject::ClampLength(const struct FVector& V, float MaxLength)
{
	static UFunction* uFnClampLength = nullptr;

	if (!uFnClampLength)
	{
		uFnClampLength = UFunction::FindFunction("Function Core.Object.ClampLength");
	}

	UObject_execClampLength_Params ClampLength_Params;
	memset(&ClampLength_Params, 0, sizeof(ClampLength_Params));

	if (!uFnClampLength)
	{
		return ClampLength_Params.ReturnValue;
	}
	memcpy_s(&ClampLength_Params.V, sizeof(ClampLength_Params.V), &V, sizeof(V));
	ClampLength_Params.MaxLength = MaxLength;

	uint16_t nativeIndex = uFnClampLength->iNative;
	uFnClampLength->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnClampLength, &ClampLength_Params, nullptr);
	uFnClampLength->iNative = nativeIndex;

	return ClampLength_Params.ReturnValue;
}

// Function Core.Object.VInterpTo
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 Current                        (CPF_Parm)
// struct FVector                 Target                         (CPF_Parm)
// float                          DeltaTime                      (CPF_Parm)
// float                          InterpSpeed                    (CPF_Parm)

struct FVector UObject::VInterpTo(const struct FVector& Current, const struct FVector& Target, float DeltaTime, float InterpSpeed)
{
	static UFunction* uFnVInterpTo = nullptr;

	if (!uFnVInterpTo)
	{
		uFnVInterpTo = UFunction::FindFunction("Function Core.Object.VInterpTo");
	}

	UObject_execVInterpTo_Params VInterpTo_Params;
	memset(&VInterpTo_Params, 0, sizeof(VInterpTo_Params));

	if (!uFnVInterpTo)
	{
		return VInterpTo_Params.ReturnValue;
	}
	memcpy_s(&VInterpTo_Params.Current, sizeof(VInterpTo_Params.Current), &Current, sizeof(Current));
	memcpy_s(&VInterpTo_Params.Target, sizeof(VInterpTo_Params.Target), &Target, sizeof(Target));
	VInterpTo_Params.DeltaTime = DeltaTime;
	VInterpTo_Params.InterpSpeed = InterpSpeed;

	uint16_t nativeIndex = uFnVInterpTo->iNative;
	uFnVInterpTo->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnVInterpTo, &VInterpTo_Params, nullptr);
	uFnVInterpTo->iNative = nativeIndex;

	return VInterpTo_Params.ReturnValue;
}

// Function Core.Object.IsZero
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public) (iNative[1501])
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 A                              (CPF_Parm)

bool UObject::IsZero(const struct FVector& A)
{
	static UFunction* uFnIsZero = nullptr;

	if (!uFnIsZero)
	{
		uFnIsZero = UFunction::FindFunction("Function Core.Object.IsZero");
	}

	UObject_execIsZero_Params IsZero_Params;
	memset(&IsZero_Params, 0, sizeof(IsZero_Params));

	if (!uFnIsZero)
	{
		return IsZero_Params.ReturnValue;
	}
	memcpy_s(&IsZero_Params.A, sizeof(IsZero_Params.A), &A, sizeof(A));

	uint16_t nativeIndex = uFnIsZero->iNative;
	uFnIsZero->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnIsZero, &IsZero_Params, nullptr);
	uFnIsZero->iNative = nativeIndex;

	return IsZero_Params.ReturnValue;
}

// Function Core.Object.ProjectOnTo
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public) (iNative[1500])
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 X                              (CPF_Parm)
// struct FVector                 Y                              (CPF_Parm)

struct FVector UObject::ProjectOnTo(const struct FVector& X, const struct FVector& Y)
{
	static UFunction* uFnProjectOnTo = nullptr;

	if (!uFnProjectOnTo)
	{
		uFnProjectOnTo = UFunction::FindFunction("Function Core.Object.ProjectOnTo");
	}

	UObject_execProjectOnTo_Params ProjectOnTo_Params;
	memset(&ProjectOnTo_Params, 0, sizeof(ProjectOnTo_Params));

	if (!uFnProjectOnTo)
	{
		return ProjectOnTo_Params.ReturnValue;
	}
	memcpy_s(&ProjectOnTo_Params.X, sizeof(ProjectOnTo_Params.X), &X, sizeof(X));
	memcpy_s(&ProjectOnTo_Params.Y, sizeof(ProjectOnTo_Params.Y), &Y, sizeof(Y));

	uint16_t nativeIndex = uFnProjectOnTo->iNative;
	uFnProjectOnTo->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnProjectOnTo, &ProjectOnTo_Params, nullptr);
	uFnProjectOnTo->iNative = nativeIndex;

	return ProjectOnTo_Params.ReturnValue;
}

// Function Core.Object.MirrorVectorByNormal
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public) (iNative[300])
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 InVect                         (CPF_Parm)
// struct FVector                 InNormal                       (CPF_Parm)

struct FVector UObject::MirrorVectorByNormal(const struct FVector& InVect, const struct FVector& InNormal)
{
	static UFunction* uFnMirrorVectorByNormal = nullptr;

	if (!uFnMirrorVectorByNormal)
	{
		uFnMirrorVectorByNormal = UFunction::FindFunction("Function Core.Object.MirrorVectorByNormal");
	}

	UObject_execMirrorVectorByNormal_Params MirrorVectorByNormal_Params;
	memset(&MirrorVectorByNormal_Params, 0, sizeof(MirrorVectorByNormal_Params));

	if (!uFnMirrorVectorByNormal)
	{
		return MirrorVectorByNormal_Params.ReturnValue;
	}
	memcpy_s(&MirrorVectorByNormal_Params.InVect, sizeof(MirrorVectorByNormal_Params.InVect), &InVect, sizeof(InVect));
	memcpy_s(&MirrorVectorByNormal_Params.InNormal, sizeof(MirrorVectorByNormal_Params.InNormal), &InNormal, sizeof(InNormal));

	uint16_t nativeIndex = uFnMirrorVectorByNormal->iNative;
	uFnMirrorVectorByNormal->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnMirrorVectorByNormal, &MirrorVectorByNormal_Params, nullptr);
	uFnMirrorVectorByNormal->iNative = nativeIndex;

	return MirrorVectorByNormal_Params.ReturnValue;
}

// Function Core.Object.VRandCone2
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 Dir                            (CPF_Parm)
// float                          HorizontalConeHalfAngleRadians (CPF_Parm)
// float                          VerticalConeHalfAngleRadians   (CPF_Parm)

struct FVector UObject::VRandCone2(const struct FVector& Dir, float HorizontalConeHalfAngleRadians, float VerticalConeHalfAngleRadians)
{
	static UFunction* uFnVRandCone2 = nullptr;

	if (!uFnVRandCone2)
	{
		uFnVRandCone2 = UFunction::FindFunction("Function Core.Object.VRandCone2");
	}

	UObject_execVRandCone2_Params VRandCone2_Params;
	memset(&VRandCone2_Params, 0, sizeof(VRandCone2_Params));

	if (!uFnVRandCone2)
	{
		return VRandCone2_Params.ReturnValue;
	}
	memcpy_s(&VRandCone2_Params.Dir, sizeof(VRandCone2_Params.Dir), &Dir, sizeof(Dir));
	VRandCone2_Params.HorizontalConeHalfAngleRadians = HorizontalConeHalfAngleRadians;
	VRandCone2_Params.VerticalConeHalfAngleRadians = VerticalConeHalfAngleRadians;

	uint16_t nativeIndex = uFnVRandCone2->iNative;
	uFnVRandCone2->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnVRandCone2, &VRandCone2_Params, nullptr);
	uFnVRandCone2->iNative = nativeIndex;

	return VRandCone2_Params.ReturnValue;
}

// Function Core.Object.VRandCone
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 Dir                            (CPF_Parm)
// float                          ConeHalfAngleRadians           (CPF_Parm)

struct FVector UObject::VRandCone(const struct FVector& Dir, float ConeHalfAngleRadians)
{
	static UFunction* uFnVRandCone = nullptr;

	if (!uFnVRandCone)
	{
		uFnVRandCone = UFunction::FindFunction("Function Core.Object.VRandCone");
	}

	UObject_execVRandCone_Params VRandCone_Params;
	memset(&VRandCone_Params, 0, sizeof(VRandCone_Params));

	if (!uFnVRandCone)
	{
		return VRandCone_Params.ReturnValue;
	}
	memcpy_s(&VRandCone_Params.Dir, sizeof(VRandCone_Params.Dir), &Dir, sizeof(Dir));
	VRandCone_Params.ConeHalfAngleRadians = ConeHalfAngleRadians;

	uint16_t nativeIndex = uFnVRandCone->iNative;
	uFnVRandCone->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnVRandCone, &VRandCone_Params, nullptr);
	uFnVRandCone->iNative = nativeIndex;

	return VRandCone_Params.ReturnValue;
}

// Function Core.Object.VRand
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public) (iNative[252])
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

struct FVector UObject::VRand()
{
	static UFunction* uFnVRand = nullptr;

	if (!uFnVRand)
	{
		uFnVRand = UFunction::FindFunction("Function Core.Object.VRand");
	}

	UObject_execVRand_Params VRand_Params;
	memset(&VRand_Params, 0, sizeof(VRand_Params));

	if (!uFnVRand)
	{
		return VRand_Params.ReturnValue;
	}

	uint16_t nativeIndex = uFnVRand->iNative;
	uFnVRand->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnVRand, &VRand_Params, nullptr);
	uFnVRand->iNative = nativeIndex;

	return VRand_Params.ReturnValue;
}

// Function Core.Object.VSmerp
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 A                              (CPF_Parm)
// struct FVector                 B                              (CPF_Parm)
// float                          Alpha                          (CPF_Parm)

struct FVector UObject::VSmerp(const struct FVector& A, const struct FVector& B, float Alpha)
{
	static UFunction* uFnVSmerp = nullptr;

	if (!uFnVSmerp)
	{
		uFnVSmerp = UFunction::FindFunction("Function Core.Object.VSmerp");
	}

	UObject_execVSmerp_Params VSmerp_Params;
	memset(&VSmerp_Params, 0, sizeof(VSmerp_Params));

	if (!uFnVSmerp)
	{
		return VSmerp_Params.ReturnValue;
	}
	memcpy_s(&VSmerp_Params.A, sizeof(VSmerp_Params.A), &A, sizeof(A));
	memcpy_s(&VSmerp_Params.B, sizeof(VSmerp_Params.B), &B, sizeof(B));
	VSmerp_Params.Alpha = Alpha;

	uint16_t nativeIndex = uFnVSmerp->iNative;
	uFnVSmerp->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnVSmerp, &VSmerp_Params, nullptr);
	uFnVSmerp->iNative = nativeIndex;

	return VSmerp_Params.ReturnValue;
}

// Function Core.Object.VLerp
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 A                              (CPF_Parm)
// struct FVector                 B                              (CPF_Parm)
// float                          Alpha                          (CPF_Parm)

struct FVector UObject::VLerp(const struct FVector& A, const struct FVector& B, float Alpha)
{
	static UFunction* uFnVLerp = nullptr;

	if (!uFnVLerp)
	{
		uFnVLerp = UFunction::FindFunction("Function Core.Object.VLerp");
	}

	UObject_execVLerp_Params VLerp_Params;
	memset(&VLerp_Params, 0, sizeof(VLerp_Params));

	if (!uFnVLerp)
	{
		return VLerp_Params.ReturnValue;
	}
	memcpy_s(&VLerp_Params.A, sizeof(VLerp_Params.A), &A, sizeof(A));
	memcpy_s(&VLerp_Params.B, sizeof(VLerp_Params.B), &B, sizeof(B));
	VLerp_Params.Alpha = Alpha;

	uint16_t nativeIndex = uFnVLerp->iNative;
	uFnVLerp->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnVLerp, &VLerp_Params, nullptr);
	uFnVLerp->iNative = nativeIndex;

	return VLerp_Params.ReturnValue;
}

// Function Core.Object.Normal
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public) (iNative[226])
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 A                              (CPF_Parm)

struct FVector UObject::Normal(const struct FVector& A)
{
	static UFunction* uFnNormal = nullptr;

	if (!uFnNormal)
	{
		uFnNormal = UFunction::FindFunction("Function Core.Object.Normal");
	}

	UObject_execNormal_Params Normal_Params;
	memset(&Normal_Params, 0, sizeof(Normal_Params));

	if (!uFnNormal)
	{
		return Normal_Params.ReturnValue;
	}
	memcpy_s(&Normal_Params.A, sizeof(Normal_Params.A), &A, sizeof(A));

	uint16_t nativeIndex = uFnNormal->iNative;
	uFnNormal->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnNormal, &Normal_Params, nullptr);
	uFnNormal->iNative = nativeIndex;

	return Normal_Params.ReturnValue;
}

// Function Core.Object.VSizeSq2D
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 A                              (CPF_Parm)

float UObject::VSizeSq2D(const struct FVector& A)
{
	static UFunction* uFnVSizeSq2D = nullptr;

	if (!uFnVSizeSq2D)
	{
		uFnVSizeSq2D = UFunction::FindFunction("Function Core.Object.VSizeSq2D");
	}

	UObject_execVSizeSq2D_Params VSizeSq2D_Params;
	memset(&VSizeSq2D_Params, 0, sizeof(VSizeSq2D_Params));

	if (!uFnVSizeSq2D)
	{
		return VSizeSq2D_Params.ReturnValue;
	}
	memcpy_s(&VSizeSq2D_Params.A, sizeof(VSizeSq2D_Params.A), &A, sizeof(A));

	uint16_t nativeIndex = uFnVSizeSq2D->iNative;
	uFnVSizeSq2D->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnVSizeSq2D, &VSizeSq2D_Params, nullptr);
	uFnVSizeSq2D->iNative = nativeIndex;

	return VSizeSq2D_Params.ReturnValue;
}

// Function Core.Object.VSizeSq
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public) (iNative[228])
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 A                              (CPF_Parm)

float UObject::VSizeSq(const struct FVector& A)
{
	static UFunction* uFnVSizeSq = nullptr;

	if (!uFnVSizeSq)
	{
		uFnVSizeSq = UFunction::FindFunction("Function Core.Object.VSizeSq");
	}

	UObject_execVSizeSq_Params VSizeSq_Params;
	memset(&VSizeSq_Params, 0, sizeof(VSizeSq_Params));

	if (!uFnVSizeSq)
	{
		return VSizeSq_Params.ReturnValue;
	}
	memcpy_s(&VSizeSq_Params.A, sizeof(VSizeSq_Params.A), &A, sizeof(A));

	uint16_t nativeIndex = uFnVSizeSq->iNative;
	uFnVSizeSq->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnVSizeSq, &VSizeSq_Params, nullptr);
	uFnVSizeSq->iNative = nativeIndex;

	return VSizeSq_Params.ReturnValue;
}

// Function Core.Object.VSize2D
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 A                              (CPF_Parm)

float UObject::VSize2D(const struct FVector& A)
{
	static UFunction* uFnVSize2D = nullptr;

	if (!uFnVSize2D)
	{
		uFnVSize2D = UFunction::FindFunction("Function Core.Object.VSize2D");
	}

	UObject_execVSize2D_Params VSize2D_Params;
	memset(&VSize2D_Params, 0, sizeof(VSize2D_Params));

	if (!uFnVSize2D)
	{
		return VSize2D_Params.ReturnValue;
	}
	memcpy_s(&VSize2D_Params.A, sizeof(VSize2D_Params.A), &A, sizeof(A));

	uint16_t nativeIndex = uFnVSize2D->iNative;
	uFnVSize2D->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnVSize2D, &VSize2D_Params, nullptr);
	uFnVSize2D->iNative = nativeIndex;

	return VSize2D_Params.ReturnValue;
}

// Function Core.Object.VSize
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public) (iNative[225])
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 A                              (CPF_Parm)

float UObject::VSize(const struct FVector& A)
{
	static UFunction* uFnVSize = nullptr;

	if (!uFnVSize)
	{
		uFnVSize = UFunction::FindFunction("Function Core.Object.VSize");
	}

	UObject_execVSize_Params VSize_Params;
	memset(&VSize_Params, 0, sizeof(VSize_Params));

	if (!uFnVSize)
	{
		return VSize_Params.ReturnValue;
	}
	memcpy_s(&VSize_Params.A, sizeof(VSize_Params.A), &A, sizeof(A));

	uint16_t nativeIndex = uFnVSize->iNative;
	uFnVSize->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnVSize, &VSize_Params, nullptr);
	uFnVSize->iNative = nativeIndex;

	return VSize_Params.ReturnValue;
}

// Function Core.Object.SubtractEqual_VectorVector
// [0x00423401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public | FUNC_HasOutParms) (iNative[224])
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 B                              (CPF_Parm)
// struct FVector                 A                              (CPF_Parm | CPF_OutParm)

struct FVector UObject::SubtractEqual_VectorVector(const struct FVector& B, struct FVector& outA)
{
	static UFunction* uFnSubtractEqual_VectorVector = nullptr;

	if (!uFnSubtractEqual_VectorVector)
	{
		uFnSubtractEqual_VectorVector = UFunction::FindFunction("Function Core.Object.SubtractEqual_VectorVector");
	}

	UObject_execSubtractEqual_VectorVector_Params SubtractEqual_VectorVector_Params;
	memset(&SubtractEqual_VectorVector_Params, 0, sizeof(SubtractEqual_VectorVector_Params));

	if (!uFnSubtractEqual_VectorVector)
	{
		return SubtractEqual_VectorVector_Params.ReturnValue;
	}
	memcpy_s(&SubtractEqual_VectorVector_Params.B, sizeof(SubtractEqual_VectorVector_Params.B), &B, sizeof(B));
	memcpy_s(&SubtractEqual_VectorVector_Params.A, sizeof(SubtractEqual_VectorVector_Params.A), &outA, sizeof(outA));

	uint16_t nativeIndex = uFnSubtractEqual_VectorVector->iNative;
	uFnSubtractEqual_VectorVector->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnSubtractEqual_VectorVector, &SubtractEqual_VectorVector_Params, nullptr);
	uFnSubtractEqual_VectorVector->iNative = nativeIndex;

	memcpy_s(&outA, sizeof(outA), &SubtractEqual_VectorVector_Params.A, sizeof(SubtractEqual_VectorVector_Params.A));

	return SubtractEqual_VectorVector_Params.ReturnValue;
}

// Function Core.Object.AddEqual_VectorVector
// [0x00423401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public | FUNC_HasOutParms) (iNative[223])
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 B                              (CPF_Parm)
// struct FVector                 A                              (CPF_Parm | CPF_OutParm)

struct FVector UObject::AddEqual_VectorVector(const struct FVector& B, struct FVector& outA)
{
	static UFunction* uFnAddEqual_VectorVector = nullptr;

	if (!uFnAddEqual_VectorVector)
	{
		uFnAddEqual_VectorVector = UFunction::FindFunction("Function Core.Object.AddEqual_VectorVector");
	}

	UObject_execAddEqual_VectorVector_Params AddEqual_VectorVector_Params;
	memset(&AddEqual_VectorVector_Params, 0, sizeof(AddEqual_VectorVector_Params));

	if (!uFnAddEqual_VectorVector)
	{
		return AddEqual_VectorVector_Params.ReturnValue;
	}
	memcpy_s(&AddEqual_VectorVector_Params.B, sizeof(AddEqual_VectorVector_Params.B), &B, sizeof(B));
	memcpy_s(&AddEqual_VectorVector_Params.A, sizeof(AddEqual_VectorVector_Params.A), &outA, sizeof(outA));

	uint16_t nativeIndex = uFnAddEqual_VectorVector->iNative;
	uFnAddEqual_VectorVector->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnAddEqual_VectorVector, &AddEqual_VectorVector_Params, nullptr);
	uFnAddEqual_VectorVector->iNative = nativeIndex;

	memcpy_s(&outA, sizeof(outA), &AddEqual_VectorVector_Params.A, sizeof(AddEqual_VectorVector_Params.A));

	return AddEqual_VectorVector_Params.ReturnValue;
}

// Function Core.Object.DivideEqual_VectorFloat
// [0x00423401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public | FUNC_HasOutParms) (iNative[222])
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          B                              (CPF_Parm)
// struct FVector                 A                              (CPF_Parm | CPF_OutParm)

struct FVector UObject::DivideEqual_VectorFloat(float B, struct FVector& outA)
{
	static UFunction* uFnDivideEqual_VectorFloat = nullptr;

	if (!uFnDivideEqual_VectorFloat)
	{
		uFnDivideEqual_VectorFloat = UFunction::FindFunction("Function Core.Object.DivideEqual_VectorFloat");
	}

	UObject_execDivideEqual_VectorFloat_Params DivideEqual_VectorFloat_Params;
	memset(&DivideEqual_VectorFloat_Params, 0, sizeof(DivideEqual_VectorFloat_Params));

	if (!uFnDivideEqual_VectorFloat)
	{
		return DivideEqual_VectorFloat_Params.ReturnValue;
	}
	DivideEqual_VectorFloat_Params.B = B;
	memcpy_s(&DivideEqual_VectorFloat_Params.A, sizeof(DivideEqual_VectorFloat_Params.A), &outA, sizeof(outA));

	uint16_t nativeIndex = uFnDivideEqual_VectorFloat->iNative;
	uFnDivideEqual_VectorFloat->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnDivideEqual_VectorFloat, &DivideEqual_VectorFloat_Params, nullptr);
	uFnDivideEqual_VectorFloat->iNative = nativeIndex;

	memcpy_s(&outA, sizeof(outA), &DivideEqual_VectorFloat_Params.A, sizeof(DivideEqual_VectorFloat_Params.A));

	return DivideEqual_VectorFloat_Params.ReturnValue;
}

// Function Core.Object.MultiplyEqual_VectorVector
// [0x00423401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public | FUNC_HasOutParms) (iNative[297])
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 B                              (CPF_Parm)
// struct FVector                 A                              (CPF_Parm | CPF_OutParm)

struct FVector UObject::MultiplyEqual_VectorVector(const struct FVector& B, struct FVector& outA)
{
	static UFunction* uFnMultiplyEqual_VectorVector = nullptr;

	if (!uFnMultiplyEqual_VectorVector)
	{
		uFnMultiplyEqual_VectorVector = UFunction::FindFunction("Function Core.Object.MultiplyEqual_VectorVector");
	}

	UObject_execMultiplyEqual_VectorVector_Params MultiplyEqual_VectorVector_Params;
	memset(&MultiplyEqual_VectorVector_Params, 0, sizeof(MultiplyEqual_VectorVector_Params));

	if (!uFnMultiplyEqual_VectorVector)
	{
		return MultiplyEqual_VectorVector_Params.ReturnValue;
	}
	memcpy_s(&MultiplyEqual_VectorVector_Params.B, sizeof(MultiplyEqual_VectorVector_Params.B), &B, sizeof(B));
	memcpy_s(&MultiplyEqual_VectorVector_Params.A, sizeof(MultiplyEqual_VectorVector_Params.A), &outA, sizeof(outA));

	uint16_t nativeIndex = uFnMultiplyEqual_VectorVector->iNative;
	uFnMultiplyEqual_VectorVector->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnMultiplyEqual_VectorVector, &MultiplyEqual_VectorVector_Params, nullptr);
	uFnMultiplyEqual_VectorVector->iNative = nativeIndex;

	memcpy_s(&outA, sizeof(outA), &MultiplyEqual_VectorVector_Params.A, sizeof(MultiplyEqual_VectorVector_Params.A));

	return MultiplyEqual_VectorVector_Params.ReturnValue;
}

// Function Core.Object.MultiplyEqual_VectorFloat
// [0x00423401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public | FUNC_HasOutParms) (iNative[221])
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          B                              (CPF_Parm)
// struct FVector                 A                              (CPF_Parm | CPF_OutParm)

struct FVector UObject::MultiplyEqual_VectorFloat(float B, struct FVector& outA)
{
	static UFunction* uFnMultiplyEqual_VectorFloat = nullptr;

	if (!uFnMultiplyEqual_VectorFloat)
	{
		uFnMultiplyEqual_VectorFloat = UFunction::FindFunction("Function Core.Object.MultiplyEqual_VectorFloat");
	}

	UObject_execMultiplyEqual_VectorFloat_Params MultiplyEqual_VectorFloat_Params;
	memset(&MultiplyEqual_VectorFloat_Params, 0, sizeof(MultiplyEqual_VectorFloat_Params));

	if (!uFnMultiplyEqual_VectorFloat)
	{
		return MultiplyEqual_VectorFloat_Params.ReturnValue;
	}
	MultiplyEqual_VectorFloat_Params.B = B;
	memcpy_s(&MultiplyEqual_VectorFloat_Params.A, sizeof(MultiplyEqual_VectorFloat_Params.A), &outA, sizeof(outA));

	uint16_t nativeIndex = uFnMultiplyEqual_VectorFloat->iNative;
	uFnMultiplyEqual_VectorFloat->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnMultiplyEqual_VectorFloat, &MultiplyEqual_VectorFloat_Params, nullptr);
	uFnMultiplyEqual_VectorFloat->iNative = nativeIndex;

	memcpy_s(&outA, sizeof(outA), &MultiplyEqual_VectorFloat_Params.A, sizeof(MultiplyEqual_VectorFloat_Params.A));

	return MultiplyEqual_VectorFloat_Params.ReturnValue;
}

// Function Core.Object.Cross_VectorVector
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[220])
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 A                              (CPF_Parm)
// struct FVector                 B                              (CPF_Parm)

struct FVector UObject::Cross_VectorVector(const struct FVector& A, const struct FVector& B)
{
	static UFunction* uFnCross_VectorVector = nullptr;

	if (!uFnCross_VectorVector)
	{
		uFnCross_VectorVector = UFunction::FindFunction("Function Core.Object.Cross_VectorVector");
	}

	UObject_execCross_VectorVector_Params Cross_VectorVector_Params;
	memset(&Cross_VectorVector_Params, 0, sizeof(Cross_VectorVector_Params));

	if (!uFnCross_VectorVector)
	{
		return Cross_VectorVector_Params.ReturnValue;
	}
	memcpy_s(&Cross_VectorVector_Params.A, sizeof(Cross_VectorVector_Params.A), &A, sizeof(A));
	memcpy_s(&Cross_VectorVector_Params.B, sizeof(Cross_VectorVector_Params.B), &B, sizeof(B));

	uint16_t nativeIndex = uFnCross_VectorVector->iNative;
	uFnCross_VectorVector->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnCross_VectorVector, &Cross_VectorVector_Params, nullptr);
	uFnCross_VectorVector->iNative = nativeIndex;

	return Cross_VectorVector_Params.ReturnValue;
}

// Function Core.Object.Dot_VectorVector
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[219])
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 A                              (CPF_Parm)
// struct FVector                 B                              (CPF_Parm)

float UObject::Dot_VectorVector(const struct FVector& A, const struct FVector& B)
{
	static UFunction* uFnDot_VectorVector = nullptr;

	if (!uFnDot_VectorVector)
	{
		uFnDot_VectorVector = UFunction::FindFunction("Function Core.Object.Dot_VectorVector");
	}

	UObject_execDot_VectorVector_Params Dot_VectorVector_Params;
	memset(&Dot_VectorVector_Params, 0, sizeof(Dot_VectorVector_Params));

	if (!uFnDot_VectorVector)
	{
		return Dot_VectorVector_Params.ReturnValue;
	}
	memcpy_s(&Dot_VectorVector_Params.A, sizeof(Dot_VectorVector_Params.A), &A, sizeof(A));
	memcpy_s(&Dot_VectorVector_Params.B, sizeof(Dot_VectorVector_Params.B), &B, sizeof(B));

	uint16_t nativeIndex = uFnDot_VectorVector->iNative;
	uFnDot_VectorVector->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnDot_VectorVector, &Dot_VectorVector_Params, nullptr);
	uFnDot_VectorVector->iNative = nativeIndex;

	return Dot_VectorVector_Params.ReturnValue;
}

// Function Core.Object.NotEqual_VectorVector
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[218])
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 A                              (CPF_Parm)
// struct FVector                 B                              (CPF_Parm)

bool UObject::NotEqual_VectorVector(const struct FVector& A, const struct FVector& B)
{
	static UFunction* uFnNotEqual_VectorVector = nullptr;

	if (!uFnNotEqual_VectorVector)
	{
		uFnNotEqual_VectorVector = UFunction::FindFunction("Function Core.Object.NotEqual_VectorVector");
	}

	UObject_execNotEqual_VectorVector_Params NotEqual_VectorVector_Params;
	memset(&NotEqual_VectorVector_Params, 0, sizeof(NotEqual_VectorVector_Params));

	if (!uFnNotEqual_VectorVector)
	{
		return NotEqual_VectorVector_Params.ReturnValue;
	}
	memcpy_s(&NotEqual_VectorVector_Params.A, sizeof(NotEqual_VectorVector_Params.A), &A, sizeof(A));
	memcpy_s(&NotEqual_VectorVector_Params.B, sizeof(NotEqual_VectorVector_Params.B), &B, sizeof(B));

	uint16_t nativeIndex = uFnNotEqual_VectorVector->iNative;
	uFnNotEqual_VectorVector->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnNotEqual_VectorVector, &NotEqual_VectorVector_Params, nullptr);
	uFnNotEqual_VectorVector->iNative = nativeIndex;

	return NotEqual_VectorVector_Params.ReturnValue;
}

// Function Core.Object.EqualEqual_VectorVector
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[217])
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 A                              (CPF_Parm)
// struct FVector                 B                              (CPF_Parm)

bool UObject::EqualEqual_VectorVector(const struct FVector& A, const struct FVector& B)
{
	static UFunction* uFnEqualEqual_VectorVector = nullptr;

	if (!uFnEqualEqual_VectorVector)
	{
		uFnEqualEqual_VectorVector = UFunction::FindFunction("Function Core.Object.EqualEqual_VectorVector");
	}

	UObject_execEqualEqual_VectorVector_Params EqualEqual_VectorVector_Params;
	memset(&EqualEqual_VectorVector_Params, 0, sizeof(EqualEqual_VectorVector_Params));

	if (!uFnEqualEqual_VectorVector)
	{
		return EqualEqual_VectorVector_Params.ReturnValue;
	}
	memcpy_s(&EqualEqual_VectorVector_Params.A, sizeof(EqualEqual_VectorVector_Params.A), &A, sizeof(A));
	memcpy_s(&EqualEqual_VectorVector_Params.B, sizeof(EqualEqual_VectorVector_Params.B), &B, sizeof(B));

	uint16_t nativeIndex = uFnEqualEqual_VectorVector->iNative;
	uFnEqualEqual_VectorVector->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnEqualEqual_VectorVector, &EqualEqual_VectorVector_Params, nullptr);
	uFnEqualEqual_VectorVector->iNative = nativeIndex;

	return EqualEqual_VectorVector_Params.ReturnValue;
}

// Function Core.Object.GreaterGreater_VectorRotator
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[276])
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 A                              (CPF_Parm)
// struct FRotator                B                              (CPF_Parm)

struct FVector UObject::GreaterGreater_VectorRotator(const struct FVector& A, const struct FRotator& B)
{
	static UFunction* uFnGreaterGreater_VectorRotator = nullptr;

	if (!uFnGreaterGreater_VectorRotator)
	{
		uFnGreaterGreater_VectorRotator = UFunction::FindFunction("Function Core.Object.GreaterGreater_VectorRotator");
	}

	UObject_execGreaterGreater_VectorRotator_Params GreaterGreater_VectorRotator_Params;
	memset(&GreaterGreater_VectorRotator_Params, 0, sizeof(GreaterGreater_VectorRotator_Params));

	if (!uFnGreaterGreater_VectorRotator)
	{
		return GreaterGreater_VectorRotator_Params.ReturnValue;
	}
	memcpy_s(&GreaterGreater_VectorRotator_Params.A, sizeof(GreaterGreater_VectorRotator_Params.A), &A, sizeof(A));
	memcpy_s(&GreaterGreater_VectorRotator_Params.B, sizeof(GreaterGreater_VectorRotator_Params.B), &B, sizeof(B));

	uint16_t nativeIndex = uFnGreaterGreater_VectorRotator->iNative;
	uFnGreaterGreater_VectorRotator->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnGreaterGreater_VectorRotator, &GreaterGreater_VectorRotator_Params, nullptr);
	uFnGreaterGreater_VectorRotator->iNative = nativeIndex;

	return GreaterGreater_VectorRotator_Params.ReturnValue;
}

// Function Core.Object.LessLess_VectorRotator
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[275])
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 A                              (CPF_Parm)
// struct FRotator                B                              (CPF_Parm)

struct FVector UObject::LessLess_VectorRotator(const struct FVector& A, const struct FRotator& B)
{
	static UFunction* uFnLessLess_VectorRotator = nullptr;

	if (!uFnLessLess_VectorRotator)
	{
		uFnLessLess_VectorRotator = UFunction::FindFunction("Function Core.Object.LessLess_VectorRotator");
	}

	UObject_execLessLess_VectorRotator_Params LessLess_VectorRotator_Params;
	memset(&LessLess_VectorRotator_Params, 0, sizeof(LessLess_VectorRotator_Params));

	if (!uFnLessLess_VectorRotator)
	{
		return LessLess_VectorRotator_Params.ReturnValue;
	}
	memcpy_s(&LessLess_VectorRotator_Params.A, sizeof(LessLess_VectorRotator_Params.A), &A, sizeof(A));
	memcpy_s(&LessLess_VectorRotator_Params.B, sizeof(LessLess_VectorRotator_Params.B), &B, sizeof(B));

	uint16_t nativeIndex = uFnLessLess_VectorRotator->iNative;
	uFnLessLess_VectorRotator->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnLessLess_VectorRotator, &LessLess_VectorRotator_Params, nullptr);
	uFnLessLess_VectorRotator->iNative = nativeIndex;

	return LessLess_VectorRotator_Params.ReturnValue;
}

// Function Core.Object.Subtract_VectorVector
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[216])
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 A                              (CPF_Parm)
// struct FVector                 B                              (CPF_Parm)

struct FVector UObject::Subtract_VectorVector(const struct FVector& A, const struct FVector& B)
{
	static UFunction* uFnSubtract_VectorVector = nullptr;

	if (!uFnSubtract_VectorVector)
	{
		uFnSubtract_VectorVector = UFunction::FindFunction("Function Core.Object.Subtract_VectorVector");
	}

	UObject_execSubtract_VectorVector_Params Subtract_VectorVector_Params;
	memset(&Subtract_VectorVector_Params, 0, sizeof(Subtract_VectorVector_Params));

	if (!uFnSubtract_VectorVector)
	{
		return Subtract_VectorVector_Params.ReturnValue;
	}
	memcpy_s(&Subtract_VectorVector_Params.A, sizeof(Subtract_VectorVector_Params.A), &A, sizeof(A));
	memcpy_s(&Subtract_VectorVector_Params.B, sizeof(Subtract_VectorVector_Params.B), &B, sizeof(B));

	uint16_t nativeIndex = uFnSubtract_VectorVector->iNative;
	uFnSubtract_VectorVector->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnSubtract_VectorVector, &Subtract_VectorVector_Params, nullptr);
	uFnSubtract_VectorVector->iNative = nativeIndex;

	return Subtract_VectorVector_Params.ReturnValue;
}

// Function Core.Object.Add_VectorVector
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[215])
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 A                              (CPF_Parm)
// struct FVector                 B                              (CPF_Parm)

struct FVector UObject::Add_VectorVector(const struct FVector& A, const struct FVector& B)
{
	static UFunction* uFnAdd_VectorVector = nullptr;

	if (!uFnAdd_VectorVector)
	{
		uFnAdd_VectorVector = UFunction::FindFunction("Function Core.Object.Add_VectorVector");
	}

	UObject_execAdd_VectorVector_Params Add_VectorVector_Params;
	memset(&Add_VectorVector_Params, 0, sizeof(Add_VectorVector_Params));

	if (!uFnAdd_VectorVector)
	{
		return Add_VectorVector_Params.ReturnValue;
	}
	memcpy_s(&Add_VectorVector_Params.A, sizeof(Add_VectorVector_Params.A), &A, sizeof(A));
	memcpy_s(&Add_VectorVector_Params.B, sizeof(Add_VectorVector_Params.B), &B, sizeof(B));

	uint16_t nativeIndex = uFnAdd_VectorVector->iNative;
	uFnAdd_VectorVector->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnAdd_VectorVector, &Add_VectorVector_Params, nullptr);
	uFnAdd_VectorVector->iNative = nativeIndex;

	return Add_VectorVector_Params.ReturnValue;
}

// Function Core.Object.Divide_VectorFloat
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[214])
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 A                              (CPF_Parm)
// float                          B                              (CPF_Parm)

struct FVector UObject::Divide_VectorFloat(const struct FVector& A, float B)
{
	static UFunction* uFnDivide_VectorFloat = nullptr;

	if (!uFnDivide_VectorFloat)
	{
		uFnDivide_VectorFloat = UFunction::FindFunction("Function Core.Object.Divide_VectorFloat");
	}

	UObject_execDivide_VectorFloat_Params Divide_VectorFloat_Params;
	memset(&Divide_VectorFloat_Params, 0, sizeof(Divide_VectorFloat_Params));

	if (!uFnDivide_VectorFloat)
	{
		return Divide_VectorFloat_Params.ReturnValue;
	}
	memcpy_s(&Divide_VectorFloat_Params.A, sizeof(Divide_VectorFloat_Params.A), &A, sizeof(A));
	Divide_VectorFloat_Params.B = B;

	uint16_t nativeIndex = uFnDivide_VectorFloat->iNative;
	uFnDivide_VectorFloat->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnDivide_VectorFloat, &Divide_VectorFloat_Params, nullptr);
	uFnDivide_VectorFloat->iNative = nativeIndex;

	return Divide_VectorFloat_Params.ReturnValue;
}

// Function Core.Object.Multiply_VectorVector
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[296])
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 A                              (CPF_Parm)
// struct FVector                 B                              (CPF_Parm)

struct FVector UObject::Multiply_VectorVector(const struct FVector& A, const struct FVector& B)
{
	static UFunction* uFnMultiply_VectorVector = nullptr;

	if (!uFnMultiply_VectorVector)
	{
		uFnMultiply_VectorVector = UFunction::FindFunction("Function Core.Object.Multiply_VectorVector");
	}

	UObject_execMultiply_VectorVector_Params Multiply_VectorVector_Params;
	memset(&Multiply_VectorVector_Params, 0, sizeof(Multiply_VectorVector_Params));

	if (!uFnMultiply_VectorVector)
	{
		return Multiply_VectorVector_Params.ReturnValue;
	}
	memcpy_s(&Multiply_VectorVector_Params.A, sizeof(Multiply_VectorVector_Params.A), &A, sizeof(A));
	memcpy_s(&Multiply_VectorVector_Params.B, sizeof(Multiply_VectorVector_Params.B), &B, sizeof(B));

	uint16_t nativeIndex = uFnMultiply_VectorVector->iNative;
	uFnMultiply_VectorVector->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnMultiply_VectorVector, &Multiply_VectorVector_Params, nullptr);
	uFnMultiply_VectorVector->iNative = nativeIndex;

	return Multiply_VectorVector_Params.ReturnValue;
}

// Function Core.Object.Multiply_FloatVector
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[213])
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          A                              (CPF_Parm)
// struct FVector                 B                              (CPF_Parm)

struct FVector UObject::Multiply_FloatVector(float A, const struct FVector& B)
{
	static UFunction* uFnMultiply_FloatVector = nullptr;

	if (!uFnMultiply_FloatVector)
	{
		uFnMultiply_FloatVector = UFunction::FindFunction("Function Core.Object.Multiply_FloatVector");
	}

	UObject_execMultiply_FloatVector_Params Multiply_FloatVector_Params;
	memset(&Multiply_FloatVector_Params, 0, sizeof(Multiply_FloatVector_Params));

	if (!uFnMultiply_FloatVector)
	{
		return Multiply_FloatVector_Params.ReturnValue;
	}
	Multiply_FloatVector_Params.A = A;
	memcpy_s(&Multiply_FloatVector_Params.B, sizeof(Multiply_FloatVector_Params.B), &B, sizeof(B));

	uint16_t nativeIndex = uFnMultiply_FloatVector->iNative;
	uFnMultiply_FloatVector->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnMultiply_FloatVector, &Multiply_FloatVector_Params, nullptr);
	uFnMultiply_FloatVector->iNative = nativeIndex;

	return Multiply_FloatVector_Params.ReturnValue;
}

// Function Core.Object.Multiply_VectorFloat
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[212])
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 A                              (CPF_Parm)
// float                          B                              (CPF_Parm)

struct FVector UObject::Multiply_VectorFloat(const struct FVector& A, float B)
{
	static UFunction* uFnMultiply_VectorFloat = nullptr;

	if (!uFnMultiply_VectorFloat)
	{
		uFnMultiply_VectorFloat = UFunction::FindFunction("Function Core.Object.Multiply_VectorFloat");
	}

	UObject_execMultiply_VectorFloat_Params Multiply_VectorFloat_Params;
	memset(&Multiply_VectorFloat_Params, 0, sizeof(Multiply_VectorFloat_Params));

	if (!uFnMultiply_VectorFloat)
	{
		return Multiply_VectorFloat_Params.ReturnValue;
	}
	memcpy_s(&Multiply_VectorFloat_Params.A, sizeof(Multiply_VectorFloat_Params.A), &A, sizeof(A));
	Multiply_VectorFloat_Params.B = B;

	uint16_t nativeIndex = uFnMultiply_VectorFloat->iNative;
	uFnMultiply_VectorFloat->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnMultiply_VectorFloat, &Multiply_VectorFloat_Params, nullptr);
	uFnMultiply_VectorFloat->iNative = nativeIndex;

	return Multiply_VectorFloat_Params.ReturnValue;
}

// Function Core.Object.Subtract_PreVector
// [0x00023411] (FUNC_Final | FUNC_PreOperator | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[211])
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// struct FVector                 A                              (CPF_Parm)

struct FVector UObject::Subtract_PreVector(const struct FVector& A)
{
	static UFunction* uFnSubtract_PreVector = nullptr;

	if (!uFnSubtract_PreVector)
	{
		uFnSubtract_PreVector = UFunction::FindFunction("Function Core.Object.Subtract_PreVector");
	}

	UObject_execSubtract_PreVector_Params Subtract_PreVector_Params;
	memset(&Subtract_PreVector_Params, 0, sizeof(Subtract_PreVector_Params));

	if (!uFnSubtract_PreVector)
	{
		return Subtract_PreVector_Params.ReturnValue;
	}
	memcpy_s(&Subtract_PreVector_Params.A, sizeof(Subtract_PreVector_Params.A), &A, sizeof(A));

	uint16_t nativeIndex = uFnSubtract_PreVector->iNative;
	uFnSubtract_PreVector->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnSubtract_PreVector, &Subtract_PreVector_Params, nullptr);
	uFnSubtract_PreVector->iNative = nativeIndex;

	return Subtract_PreVector_Params.ReturnValue;
}

// Function Core.Object.FInterpConstantTo
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          Current                        (CPF_Parm)
// float                          Target                         (CPF_Parm)
// float                          DeltaTime                      (CPF_Parm)
// float                          InterpSpeed                    (CPF_Parm)

float UObject::FInterpConstantTo(float Current, float Target, float DeltaTime, float InterpSpeed)
{
	static UFunction* uFnFInterpConstantTo = nullptr;

	if (!uFnFInterpConstantTo)
	{
		uFnFInterpConstantTo = UFunction::FindFunction("Function Core.Object.FInterpConstantTo");
	}

	UObject_execFInterpConstantTo_Params FInterpConstantTo_Params;
	memset(&FInterpConstantTo_Params, 0, sizeof(FInterpConstantTo_Params));

	if (!uFnFInterpConstantTo)
	{
		return FInterpConstantTo_Params.ReturnValue;
	}
	FInterpConstantTo_Params.Current = Current;
	FInterpConstantTo_Params.Target = Target;
	FInterpConstantTo_Params.DeltaTime = DeltaTime;
	FInterpConstantTo_Params.InterpSpeed = InterpSpeed;

	uint16_t nativeIndex = uFnFInterpConstantTo->iNative;
	uFnFInterpConstantTo->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnFInterpConstantTo, &FInterpConstantTo_Params, nullptr);
	uFnFInterpConstantTo->iNative = nativeIndex;

	return FInterpConstantTo_Params.ReturnValue;
}

// Function Core.Object.FInterpTo
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          Current                        (CPF_Parm)
// float                          Target                         (CPF_Parm)
// float                          DeltaTime                      (CPF_Parm)
// float                          InterpSpeed                    (CPF_Parm)

float UObject::FInterpTo(float Current, float Target, float DeltaTime, float InterpSpeed)
{
	static UFunction* uFnFInterpTo = nullptr;

	if (!uFnFInterpTo)
	{
		uFnFInterpTo = UFunction::FindFunction("Function Core.Object.FInterpTo");
	}

	UObject_execFInterpTo_Params FInterpTo_Params;
	memset(&FInterpTo_Params, 0, sizeof(FInterpTo_Params));

	if (!uFnFInterpTo)
	{
		return FInterpTo_Params.ReturnValue;
	}
	FInterpTo_Params.Current = Current;
	FInterpTo_Params.Target = Target;
	FInterpTo_Params.DeltaTime = DeltaTime;
	FInterpTo_Params.InterpSpeed = InterpSpeed;

	uint16_t nativeIndex = uFnFInterpTo->iNative;
	uFnFInterpTo->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnFInterpTo, &FInterpTo_Params, nullptr);
	uFnFInterpTo->iNative = nativeIndex;

	return FInterpTo_Params.ReturnValue;
}

// Function Core.Object.FPctByRange
// [0x00022103] (FUNC_Final | FUNC_Defined | FUNC_Simulated | FUNC_Static | FUNC_Public)
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          Value                          (CPF_Parm)
// float                          InMin                          (CPF_Parm)
// float                          InMax                          (CPF_Parm)

float UObject::FPctByRange(float Value, float InMin, float InMax)
{
	static UFunction* uFnFPctByRange = nullptr;

	if (!uFnFPctByRange)
	{
		uFnFPctByRange = UFunction::FindFunction("Function Core.Object.FPctByRange");
	}

	UObject_execFPctByRange_Params FPctByRange_Params;
	memset(&FPctByRange_Params, 0, sizeof(FPctByRange_Params));

	if (!uFnFPctByRange)
	{
		return FPctByRange_Params.ReturnValue;
	}
	FPctByRange_Params.Value = Value;
	FPctByRange_Params.InMin = InMin;
	FPctByRange_Params.InMax = InMax;

	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnFPctByRange, &FPctByRange_Params, nullptr);

	return FPctByRange_Params.ReturnValue;
}

// Function Core.Object.RandRange
// [0x00022103] (FUNC_Final | FUNC_Defined | FUNC_Simulated | FUNC_Static | FUNC_Public)
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          InMin                          (CPF_Parm)
// float                          InMax                          (CPF_Parm)

float UObject::RandRange(float InMin, float InMax)
{
	static UFunction* uFnRandRange = nullptr;

	if (!uFnRandRange)
	{
		uFnRandRange = UFunction::FindFunction("Function Core.Object.RandRange");
	}

	UObject_execRandRange_Params RandRange_Params;
	memset(&RandRange_Params, 0, sizeof(RandRange_Params));

	if (!uFnRandRange)
	{
		return RandRange_Params.ReturnValue;
	}
	RandRange_Params.InMin = InMin;
	RandRange_Params.InMax = InMax;

	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnRandRange, &RandRange_Params, nullptr);

	return RandRange_Params.ReturnValue;
}

// Function Core.Object.FInterpEaseInOut
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          A                              (CPF_Parm)
// float                          B                              (CPF_Parm)
// float                          Alpha                          (CPF_Parm)
// float                          Exp                            (CPF_Parm)

float UObject::FInterpEaseInOut(float A, float B, float Alpha, float Exp)
{
	static UFunction* uFnFInterpEaseInOut = nullptr;

	if (!uFnFInterpEaseInOut)
	{
		uFnFInterpEaseInOut = UFunction::FindFunction("Function Core.Object.FInterpEaseInOut");
	}

	UObject_execFInterpEaseInOut_Params FInterpEaseInOut_Params;
	memset(&FInterpEaseInOut_Params, 0, sizeof(FInterpEaseInOut_Params));

	if (!uFnFInterpEaseInOut)
	{
		return FInterpEaseInOut_Params.ReturnValue;
	}
	FInterpEaseInOut_Params.A = A;
	FInterpEaseInOut_Params.B = B;
	FInterpEaseInOut_Params.Alpha = Alpha;
	FInterpEaseInOut_Params.Exp = Exp;

	uint16_t nativeIndex = uFnFInterpEaseInOut->iNative;
	uFnFInterpEaseInOut->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnFInterpEaseInOut, &FInterpEaseInOut_Params, nullptr);
	uFnFInterpEaseInOut->iNative = nativeIndex;

	return FInterpEaseInOut_Params.ReturnValue;
}

// Function Core.Object.FInterpEaseOut
// [0x00022003] (FUNC_Final | FUNC_Defined | FUNC_Static | FUNC_Public)
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          A                              (CPF_Parm)
// float                          B                              (CPF_Parm)
// float                          Alpha                          (CPF_Parm)
// float                          Exp                            (CPF_Parm)

float UObject::FInterpEaseOut(float A, float B, float Alpha, float Exp)
{
	static UFunction* uFnFInterpEaseOut = nullptr;

	if (!uFnFInterpEaseOut)
	{
		uFnFInterpEaseOut = UFunction::FindFunction("Function Core.Object.FInterpEaseOut");
	}

	UObject_execFInterpEaseOut_Params FInterpEaseOut_Params;
	memset(&FInterpEaseOut_Params, 0, sizeof(FInterpEaseOut_Params));

	if (!uFnFInterpEaseOut)
	{
		return FInterpEaseOut_Params.ReturnValue;
	}
	FInterpEaseOut_Params.A = A;
	FInterpEaseOut_Params.B = B;
	FInterpEaseOut_Params.Alpha = Alpha;
	FInterpEaseOut_Params.Exp = Exp;

	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnFInterpEaseOut, &FInterpEaseOut_Params, nullptr);

	return FInterpEaseOut_Params.ReturnValue;
}

// Function Core.Object.FInterpEaseIn
// [0x00022003] (FUNC_Final | FUNC_Defined | FUNC_Static | FUNC_Public)
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          A                              (CPF_Parm)
// float                          B                              (CPF_Parm)
// float                          Alpha                          (CPF_Parm)
// float                          Exp                            (CPF_Parm)

float UObject::FInterpEaseIn(float A, float B, float Alpha, float Exp)
{
	static UFunction* uFnFInterpEaseIn = nullptr;

	if (!uFnFInterpEaseIn)
	{
		uFnFInterpEaseIn = UFunction::FindFunction("Function Core.Object.FInterpEaseIn");
	}

	UObject_execFInterpEaseIn_Params FInterpEaseIn_Params;
	memset(&FInterpEaseIn_Params, 0, sizeof(FInterpEaseIn_Params));

	if (!uFnFInterpEaseIn)
	{
		return FInterpEaseIn_Params.ReturnValue;
	}
	FInterpEaseIn_Params.A = A;
	FInterpEaseIn_Params.B = B;
	FInterpEaseIn_Params.Alpha = Alpha;
	FInterpEaseIn_Params.Exp = Exp;

	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnFInterpEaseIn, &FInterpEaseIn_Params, nullptr);

	return FInterpEaseIn_Params.ReturnValue;
}

// Function Core.Object.FCubicInterp
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          P0                             (CPF_Parm)
// float                          T0                             (CPF_Parm)
// float                          P1                             (CPF_Parm)
// float                          T1                             (CPF_Parm)
// float                          A                              (CPF_Parm)

float UObject::FCubicInterp(float P0, float T0, float P1, float T1, float A)
{
	static UFunction* uFnFCubicInterp = nullptr;

	if (!uFnFCubicInterp)
	{
		uFnFCubicInterp = UFunction::FindFunction("Function Core.Object.FCubicInterp");
	}

	UObject_execFCubicInterp_Params FCubicInterp_Params;
	memset(&FCubicInterp_Params, 0, sizeof(FCubicInterp_Params));

	if (!uFnFCubicInterp)
	{
		return FCubicInterp_Params.ReturnValue;
	}
	FCubicInterp_Params.P0 = P0;
	FCubicInterp_Params.T0 = T0;
	FCubicInterp_Params.P1 = P1;
	FCubicInterp_Params.T1 = T1;
	FCubicInterp_Params.A = A;

	uint16_t nativeIndex = uFnFCubicInterp->iNative;
	uFnFCubicInterp->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnFCubicInterp, &FCubicInterp_Params, nullptr);
	uFnFCubicInterp->iNative = nativeIndex;

	return FCubicInterp_Params.ReturnValue;
}

// Function Core.Object.FCeil
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          A                              (CPF_Parm)

int32_t UObject::FCeil(float A)
{
	static UFunction* uFnFCeil = nullptr;

	if (!uFnFCeil)
	{
		uFnFCeil = UFunction::FindFunction("Function Core.Object.FCeil");
	}

	UObject_execFCeil_Params FCeil_Params;
	memset(&FCeil_Params, 0, sizeof(FCeil_Params));

	if (!uFnFCeil)
	{
		return FCeil_Params.ReturnValue;
	}
	FCeil_Params.A = A;

	uint16_t nativeIndex = uFnFCeil->iNative;
	uFnFCeil->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnFCeil, &FCeil_Params, nullptr);
	uFnFCeil->iNative = nativeIndex;

	return FCeil_Params.ReturnValue;
}

// Function Core.Object.FFloor
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          A                              (CPF_Parm)

int32_t UObject::FFloor(float A)
{
	static UFunction* uFnFFloor = nullptr;

	if (!uFnFFloor)
	{
		uFnFFloor = UFunction::FindFunction("Function Core.Object.FFloor");
	}

	UObject_execFFloor_Params FFloor_Params;
	memset(&FFloor_Params, 0, sizeof(FFloor_Params));

	if (!uFnFFloor)
	{
		return FFloor_Params.ReturnValue;
	}
	FFloor_Params.A = A;

	uint16_t nativeIndex = uFnFFloor->iNative;
	uFnFFloor->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnFFloor, &FFloor_Params, nullptr);
	uFnFFloor->iNative = nativeIndex;

	return FFloor_Params.ReturnValue;
}

// Function Core.Object.Round
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public) (iNative[199])
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          A                              (CPF_Parm)

int32_t UObject::Round(float A)
{
	static UFunction* uFnRound = nullptr;

	if (!uFnRound)
	{
		uFnRound = UFunction::FindFunction("Function Core.Object.Round");
	}

	UObject_execRound_Params Round_Params;
	memset(&Round_Params, 0, sizeof(Round_Params));

	if (!uFnRound)
	{
		return Round_Params.ReturnValue;
	}
	Round_Params.A = A;

	uint16_t nativeIndex = uFnRound->iNative;
	uFnRound->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnRound, &Round_Params, nullptr);
	uFnRound->iNative = nativeIndex;

	return Round_Params.ReturnValue;
}

// Function Core.Object.Lerp
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public) (iNative[247])
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          A                              (CPF_Parm)
// float                          B                              (CPF_Parm)
// float                          Alpha                          (CPF_Parm)

float UObject::Lerp(float A, float B, float Alpha)
{
	static UFunction* uFnLerp = nullptr;

	if (!uFnLerp)
	{
		uFnLerp = UFunction::FindFunction("Function Core.Object.Lerp");
	}

	UObject_execLerp_Params Lerp_Params;
	memset(&Lerp_Params, 0, sizeof(Lerp_Params));

	if (!uFnLerp)
	{
		return Lerp_Params.ReturnValue;
	}
	Lerp_Params.A = A;
	Lerp_Params.B = B;
	Lerp_Params.Alpha = Alpha;

	uint16_t nativeIndex = uFnLerp->iNative;
	uFnLerp->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnLerp, &Lerp_Params, nullptr);
	uFnLerp->iNative = nativeIndex;

	return Lerp_Params.ReturnValue;
}

// Function Core.Object.FClamp
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public) (iNative[246])
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          V                              (CPF_Parm)
// float                          A                              (CPF_Parm)
// float                          B                              (CPF_Parm)

float UObject::FClamp(float V, float A, float B)
{
	static UFunction* uFnFClamp = nullptr;

	if (!uFnFClamp)
	{
		uFnFClamp = UFunction::FindFunction("Function Core.Object.FClamp");
	}

	UObject_execFClamp_Params FClamp_Params;
	memset(&FClamp_Params, 0, sizeof(FClamp_Params));

	if (!uFnFClamp)
	{
		return FClamp_Params.ReturnValue;
	}
	FClamp_Params.V = V;
	FClamp_Params.A = A;
	FClamp_Params.B = B;

	uint16_t nativeIndex = uFnFClamp->iNative;
	uFnFClamp->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnFClamp, &FClamp_Params, nullptr);
	uFnFClamp->iNative = nativeIndex;

	return FClamp_Params.ReturnValue;
}

// Function Core.Object.FMax
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public) (iNative[245])
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          A                              (CPF_Parm)
// float                          B                              (CPF_Parm)

float UObject::FMax(float A, float B)
{
	static UFunction* uFnFMax = nullptr;

	if (!uFnFMax)
	{
		uFnFMax = UFunction::FindFunction("Function Core.Object.FMax");
	}

	UObject_execFMax_Params FMax_Params;
	memset(&FMax_Params, 0, sizeof(FMax_Params));

	if (!uFnFMax)
	{
		return FMax_Params.ReturnValue;
	}
	FMax_Params.A = A;
	FMax_Params.B = B;

	uint16_t nativeIndex = uFnFMax->iNative;
	uFnFMax->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnFMax, &FMax_Params, nullptr);
	uFnFMax->iNative = nativeIndex;

	return FMax_Params.ReturnValue;
}

// Function Core.Object.FMin
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public) (iNative[244])
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          A                              (CPF_Parm)
// float                          B                              (CPF_Parm)

float UObject::FMin(float A, float B)
{
	static UFunction* uFnFMin = nullptr;

	if (!uFnFMin)
	{
		uFnFMin = UFunction::FindFunction("Function Core.Object.FMin");
	}

	UObject_execFMin_Params FMin_Params;
	memset(&FMin_Params, 0, sizeof(FMin_Params));

	if (!uFnFMin)
	{
		return FMin_Params.ReturnValue;
	}
	FMin_Params.A = A;
	FMin_Params.B = B;

	uint16_t nativeIndex = uFnFMin->iNative;
	uFnFMin->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnFMin, &FMin_Params, nullptr);
	uFnFMin->iNative = nativeIndex;

	return FMin_Params.ReturnValue;
}

// Function Core.Object.FRand
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public) (iNative[195])
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)

float UObject::FRand()
{
	static UFunction* uFnFRand = nullptr;

	if (!uFnFRand)
	{
		uFnFRand = UFunction::FindFunction("Function Core.Object.FRand");
	}

	UObject_execFRand_Params FRand_Params;
	memset(&FRand_Params, 0, sizeof(FRand_Params));

	if (!uFnFRand)
	{
		return FRand_Params.ReturnValue;
	}

	uint16_t nativeIndex = uFnFRand->iNative;
	uFnFRand->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnFRand, &FRand_Params, nullptr);
	uFnFRand->iNative = nativeIndex;

	return FRand_Params.ReturnValue;
}

// Function Core.Object.Square
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public) (iNative[194])
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          A                              (CPF_Parm)

float UObject::Square(float A)
{
	static UFunction* uFnSquare = nullptr;

	if (!uFnSquare)
	{
		uFnSquare = UFunction::FindFunction("Function Core.Object.Square");
	}

	UObject_execSquare_Params Square_Params;
	memset(&Square_Params, 0, sizeof(Square_Params));

	if (!uFnSquare)
	{
		return Square_Params.ReturnValue;
	}
	Square_Params.A = A;

	uint16_t nativeIndex = uFnSquare->iNative;
	uFnSquare->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnSquare, &Square_Params, nullptr);
	uFnSquare->iNative = nativeIndex;

	return Square_Params.ReturnValue;
}

// Function Core.Object.Sqrt
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public) (iNative[193])
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          A                              (CPF_Parm)

float UObject::Sqrt(float A)
{
	static UFunction* uFnSqrt = nullptr;

	if (!uFnSqrt)
	{
		uFnSqrt = UFunction::FindFunction("Function Core.Object.Sqrt");
	}

	UObject_execSqrt_Params Sqrt_Params;
	memset(&Sqrt_Params, 0, sizeof(Sqrt_Params));

	if (!uFnSqrt)
	{
		return Sqrt_Params.ReturnValue;
	}
	Sqrt_Params.A = A;

	uint16_t nativeIndex = uFnSqrt->iNative;
	uFnSqrt->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnSqrt, &Sqrt_Params, nullptr);
	uFnSqrt->iNative = nativeIndex;

	return Sqrt_Params.ReturnValue;
}

// Function Core.Object.Loge
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public) (iNative[192])
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          A                              (CPF_Parm)

float UObject::Loge(float A)
{
	static UFunction* uFnLoge = nullptr;

	if (!uFnLoge)
	{
		uFnLoge = UFunction::FindFunction("Function Core.Object.Loge");
	}

	UObject_execLoge_Params Loge_Params;
	memset(&Loge_Params, 0, sizeof(Loge_Params));

	if (!uFnLoge)
	{
		return Loge_Params.ReturnValue;
	}
	Loge_Params.A = A;

	uint16_t nativeIndex = uFnLoge->iNative;
	uFnLoge->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnLoge, &Loge_Params, nullptr);
	uFnLoge->iNative = nativeIndex;

	return Loge_Params.ReturnValue;
}

// Function Core.Object.Exp
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public) (iNative[191])
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          A                              (CPF_Parm)

float UObject::Exp(float A)
{
	static UFunction* uFnExp = nullptr;

	if (!uFnExp)
	{
		uFnExp = UFunction::FindFunction("Function Core.Object.Exp");
	}

	UObject_execExp_Params Exp_Params;
	memset(&Exp_Params, 0, sizeof(Exp_Params));

	if (!uFnExp)
	{
		return Exp_Params.ReturnValue;
	}
	Exp_Params.A = A;

	uint16_t nativeIndex = uFnExp->iNative;
	uFnExp->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnExp, &Exp_Params, nullptr);
	uFnExp->iNative = nativeIndex;

	return Exp_Params.ReturnValue;
}

// Function Core.Object.Atan2
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          A                              (CPF_Parm)
// float                          B                              (CPF_Parm)

float UObject::Atan2(float A, float B)
{
	static UFunction* uFnAtan2 = nullptr;

	if (!uFnAtan2)
	{
		uFnAtan2 = UFunction::FindFunction("Function Core.Object.Atan2");
	}

	UObject_execAtan2_Params Atan2_Params;
	memset(&Atan2_Params, 0, sizeof(Atan2_Params));

	if (!uFnAtan2)
	{
		return Atan2_Params.ReturnValue;
	}
	Atan2_Params.A = A;
	Atan2_Params.B = B;

	uint16_t nativeIndex = uFnAtan2->iNative;
	uFnAtan2->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnAtan2, &Atan2_Params, nullptr);
	uFnAtan2->iNative = nativeIndex;

	return Atan2_Params.ReturnValue;
}

// Function Core.Object.Atan
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public) (iNative[190])
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          A                              (CPF_Parm)

float UObject::Atan(float A)
{
	static UFunction* uFnAtan = nullptr;

	if (!uFnAtan)
	{
		uFnAtan = UFunction::FindFunction("Function Core.Object.Atan");
	}

	UObject_execAtan_Params Atan_Params;
	memset(&Atan_Params, 0, sizeof(Atan_Params));

	if (!uFnAtan)
	{
		return Atan_Params.ReturnValue;
	}
	Atan_Params.A = A;

	uint16_t nativeIndex = uFnAtan->iNative;
	uFnAtan->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnAtan, &Atan_Params, nullptr);
	uFnAtan->iNative = nativeIndex;

	return Atan_Params.ReturnValue;
}

// Function Core.Object.Tan
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public) (iNative[189])
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          A                              (CPF_Parm)

float UObject::Tan(float A)
{
	static UFunction* uFnTan = nullptr;

	if (!uFnTan)
	{
		uFnTan = UFunction::FindFunction("Function Core.Object.Tan");
	}

	UObject_execTan_Params Tan_Params;
	memset(&Tan_Params, 0, sizeof(Tan_Params));

	if (!uFnTan)
	{
		return Tan_Params.ReturnValue;
	}
	Tan_Params.A = A;

	uint16_t nativeIndex = uFnTan->iNative;
	uFnTan->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnTan, &Tan_Params, nullptr);
	uFnTan->iNative = nativeIndex;

	return Tan_Params.ReturnValue;
}

// Function Core.Object.Acos
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          A                              (CPF_Parm)

float UObject::Acos(float A)
{
	static UFunction* uFnAcos = nullptr;

	if (!uFnAcos)
	{
		uFnAcos = UFunction::FindFunction("Function Core.Object.Acos");
	}

	UObject_execAcos_Params Acos_Params;
	memset(&Acos_Params, 0, sizeof(Acos_Params));

	if (!uFnAcos)
	{
		return Acos_Params.ReturnValue;
	}
	Acos_Params.A = A;

	uint16_t nativeIndex = uFnAcos->iNative;
	uFnAcos->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnAcos, &Acos_Params, nullptr);
	uFnAcos->iNative = nativeIndex;

	return Acos_Params.ReturnValue;
}

// Function Core.Object.Cos
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public) (iNative[188])
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          A                              (CPF_Parm)

float UObject::Cos(float A)
{
	static UFunction* uFnCos = nullptr;

	if (!uFnCos)
	{
		uFnCos = UFunction::FindFunction("Function Core.Object.Cos");
	}

	UObject_execCos_Params Cos_Params;
	memset(&Cos_Params, 0, sizeof(Cos_Params));

	if (!uFnCos)
	{
		return Cos_Params.ReturnValue;
	}
	Cos_Params.A = A;

	uint16_t nativeIndex = uFnCos->iNative;
	uFnCos->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnCos, &Cos_Params, nullptr);
	uFnCos->iNative = nativeIndex;

	return Cos_Params.ReturnValue;
}

// Function Core.Object.Asin
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          A                              (CPF_Parm)

float UObject::Asin(float A)
{
	static UFunction* uFnAsin = nullptr;

	if (!uFnAsin)
	{
		uFnAsin = UFunction::FindFunction("Function Core.Object.Asin");
	}

	UObject_execAsin_Params Asin_Params;
	memset(&Asin_Params, 0, sizeof(Asin_Params));

	if (!uFnAsin)
	{
		return Asin_Params.ReturnValue;
	}
	Asin_Params.A = A;

	uint16_t nativeIndex = uFnAsin->iNative;
	uFnAsin->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnAsin, &Asin_Params, nullptr);
	uFnAsin->iNative = nativeIndex;

	return Asin_Params.ReturnValue;
}

// Function Core.Object.Sin
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public) (iNative[187])
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          A                              (CPF_Parm)

float UObject::Sin(float A)
{
	static UFunction* uFnSin = nullptr;

	if (!uFnSin)
	{
		uFnSin = UFunction::FindFunction("Function Core.Object.Sin");
	}

	UObject_execSin_Params Sin_Params;
	memset(&Sin_Params, 0, sizeof(Sin_Params));

	if (!uFnSin)
	{
		return Sin_Params.ReturnValue;
	}
	Sin_Params.A = A;

	uint16_t nativeIndex = uFnSin->iNative;
	uFnSin->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnSin, &Sin_Params, nullptr);
	uFnSin->iNative = nativeIndex;

	return Sin_Params.ReturnValue;
}

// Function Core.Object.Abs
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public) (iNative[186])
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          A                              (CPF_Parm)

float UObject::Abs(float A)
{
	static UFunction* uFnAbs = nullptr;

	if (!uFnAbs)
	{
		uFnAbs = UFunction::FindFunction("Function Core.Object.Abs");
	}

	UObject_execAbs_Params Abs_Params;
	memset(&Abs_Params, 0, sizeof(Abs_Params));

	if (!uFnAbs)
	{
		return Abs_Params.ReturnValue;
	}
	Abs_Params.A = A;

	uint16_t nativeIndex = uFnAbs->iNative;
	uFnAbs->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnAbs, &Abs_Params, nullptr);
	uFnAbs->iNative = nativeIndex;

	return Abs_Params.ReturnValue;
}

// Function Core.Object.SubtractEqual_FloatFloat
// [0x00423401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public | FUNC_HasOutParms) (iNative[185])
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          B                              (CPF_Parm)
// float                          A                              (CPF_Parm | CPF_OutParm)

float UObject::SubtractEqual_FloatFloat(float B, float& outA)
{
	static UFunction* uFnSubtractEqual_FloatFloat = nullptr;

	if (!uFnSubtractEqual_FloatFloat)
	{
		uFnSubtractEqual_FloatFloat = UFunction::FindFunction("Function Core.Object.SubtractEqual_FloatFloat");
	}

	UObject_execSubtractEqual_FloatFloat_Params SubtractEqual_FloatFloat_Params;
	memset(&SubtractEqual_FloatFloat_Params, 0, sizeof(SubtractEqual_FloatFloat_Params));

	if (!uFnSubtractEqual_FloatFloat)
	{
		return SubtractEqual_FloatFloat_Params.ReturnValue;
	}
	SubtractEqual_FloatFloat_Params.B = B;
	SubtractEqual_FloatFloat_Params.A = outA;

	uint16_t nativeIndex = uFnSubtractEqual_FloatFloat->iNative;
	uFnSubtractEqual_FloatFloat->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnSubtractEqual_FloatFloat, &SubtractEqual_FloatFloat_Params, nullptr);
	uFnSubtractEqual_FloatFloat->iNative = nativeIndex;

	outA = SubtractEqual_FloatFloat_Params.A;

	return SubtractEqual_FloatFloat_Params.ReturnValue;
}

// Function Core.Object.AddEqual_FloatFloat
// [0x00423401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public | FUNC_HasOutParms) (iNative[184])
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          B                              (CPF_Parm)
// float                          A                              (CPF_Parm | CPF_OutParm)

float UObject::AddEqual_FloatFloat(float B, float& outA)
{
	static UFunction* uFnAddEqual_FloatFloat = nullptr;

	if (!uFnAddEqual_FloatFloat)
	{
		uFnAddEqual_FloatFloat = UFunction::FindFunction("Function Core.Object.AddEqual_FloatFloat");
	}

	UObject_execAddEqual_FloatFloat_Params AddEqual_FloatFloat_Params;
	memset(&AddEqual_FloatFloat_Params, 0, sizeof(AddEqual_FloatFloat_Params));

	if (!uFnAddEqual_FloatFloat)
	{
		return AddEqual_FloatFloat_Params.ReturnValue;
	}
	AddEqual_FloatFloat_Params.B = B;
	AddEqual_FloatFloat_Params.A = outA;

	uint16_t nativeIndex = uFnAddEqual_FloatFloat->iNative;
	uFnAddEqual_FloatFloat->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnAddEqual_FloatFloat, &AddEqual_FloatFloat_Params, nullptr);
	uFnAddEqual_FloatFloat->iNative = nativeIndex;

	outA = AddEqual_FloatFloat_Params.A;

	return AddEqual_FloatFloat_Params.ReturnValue;
}

// Function Core.Object.DivideEqual_FloatFloat
// [0x00423401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public | FUNC_HasOutParms) (iNative[183])
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          B                              (CPF_Parm)
// float                          A                              (CPF_Parm | CPF_OutParm)

float UObject::DivideEqual_FloatFloat(float B, float& outA)
{
	static UFunction* uFnDivideEqual_FloatFloat = nullptr;

	if (!uFnDivideEqual_FloatFloat)
	{
		uFnDivideEqual_FloatFloat = UFunction::FindFunction("Function Core.Object.DivideEqual_FloatFloat");
	}

	UObject_execDivideEqual_FloatFloat_Params DivideEqual_FloatFloat_Params;
	memset(&DivideEqual_FloatFloat_Params, 0, sizeof(DivideEqual_FloatFloat_Params));

	if (!uFnDivideEqual_FloatFloat)
	{
		return DivideEqual_FloatFloat_Params.ReturnValue;
	}
	DivideEqual_FloatFloat_Params.B = B;
	DivideEqual_FloatFloat_Params.A = outA;

	uint16_t nativeIndex = uFnDivideEqual_FloatFloat->iNative;
	uFnDivideEqual_FloatFloat->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnDivideEqual_FloatFloat, &DivideEqual_FloatFloat_Params, nullptr);
	uFnDivideEqual_FloatFloat->iNative = nativeIndex;

	outA = DivideEqual_FloatFloat_Params.A;

	return DivideEqual_FloatFloat_Params.ReturnValue;
}

// Function Core.Object.MultiplyEqual_FloatFloat
// [0x00423401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public | FUNC_HasOutParms) (iNative[182])
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          B                              (CPF_Parm)
// float                          A                              (CPF_Parm | CPF_OutParm)

float UObject::MultiplyEqual_FloatFloat(float B, float& outA)
{
	static UFunction* uFnMultiplyEqual_FloatFloat = nullptr;

	if (!uFnMultiplyEqual_FloatFloat)
	{
		uFnMultiplyEqual_FloatFloat = UFunction::FindFunction("Function Core.Object.MultiplyEqual_FloatFloat");
	}

	UObject_execMultiplyEqual_FloatFloat_Params MultiplyEqual_FloatFloat_Params;
	memset(&MultiplyEqual_FloatFloat_Params, 0, sizeof(MultiplyEqual_FloatFloat_Params));

	if (!uFnMultiplyEqual_FloatFloat)
	{
		return MultiplyEqual_FloatFloat_Params.ReturnValue;
	}
	MultiplyEqual_FloatFloat_Params.B = B;
	MultiplyEqual_FloatFloat_Params.A = outA;

	uint16_t nativeIndex = uFnMultiplyEqual_FloatFloat->iNative;
	uFnMultiplyEqual_FloatFloat->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnMultiplyEqual_FloatFloat, &MultiplyEqual_FloatFloat_Params, nullptr);
	uFnMultiplyEqual_FloatFloat->iNative = nativeIndex;

	outA = MultiplyEqual_FloatFloat_Params.A;

	return MultiplyEqual_FloatFloat_Params.ReturnValue;
}

// Function Core.Object.NotEqual_FloatFloat
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[181])
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          A                              (CPF_Parm)
// float                          B                              (CPF_Parm)

bool UObject::NotEqual_FloatFloat(float A, float B)
{
	static UFunction* uFnNotEqual_FloatFloat = nullptr;

	if (!uFnNotEqual_FloatFloat)
	{
		uFnNotEqual_FloatFloat = UFunction::FindFunction("Function Core.Object.NotEqual_FloatFloat");
	}

	UObject_execNotEqual_FloatFloat_Params NotEqual_FloatFloat_Params;
	memset(&NotEqual_FloatFloat_Params, 0, sizeof(NotEqual_FloatFloat_Params));

	if (!uFnNotEqual_FloatFloat)
	{
		return NotEqual_FloatFloat_Params.ReturnValue;
	}
	NotEqual_FloatFloat_Params.A = A;
	NotEqual_FloatFloat_Params.B = B;

	uint16_t nativeIndex = uFnNotEqual_FloatFloat->iNative;
	uFnNotEqual_FloatFloat->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnNotEqual_FloatFloat, &NotEqual_FloatFloat_Params, nullptr);
	uFnNotEqual_FloatFloat->iNative = nativeIndex;

	return NotEqual_FloatFloat_Params.ReturnValue;
}

// Function Core.Object.ComplementEqual_FloatFloat
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[210])
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          A                              (CPF_Parm)
// float                          B                              (CPF_Parm)

bool UObject::ComplementEqual_FloatFloat(float A, float B)
{
	static UFunction* uFnComplementEqual_FloatFloat = nullptr;

	if (!uFnComplementEqual_FloatFloat)
	{
		uFnComplementEqual_FloatFloat = UFunction::FindFunction("Function Core.Object.ComplementEqual_FloatFloat");
	}

	UObject_execComplementEqual_FloatFloat_Params ComplementEqual_FloatFloat_Params;
	memset(&ComplementEqual_FloatFloat_Params, 0, sizeof(ComplementEqual_FloatFloat_Params));

	if (!uFnComplementEqual_FloatFloat)
	{
		return ComplementEqual_FloatFloat_Params.ReturnValue;
	}
	ComplementEqual_FloatFloat_Params.A = A;
	ComplementEqual_FloatFloat_Params.B = B;

	uint16_t nativeIndex = uFnComplementEqual_FloatFloat->iNative;
	uFnComplementEqual_FloatFloat->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnComplementEqual_FloatFloat, &ComplementEqual_FloatFloat_Params, nullptr);
	uFnComplementEqual_FloatFloat->iNative = nativeIndex;

	return ComplementEqual_FloatFloat_Params.ReturnValue;
}

// Function Core.Object.EqualEqual_FloatFloat
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[180])
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          A                              (CPF_Parm)
// float                          B                              (CPF_Parm)

bool UObject::EqualEqual_FloatFloat(float A, float B)
{
	static UFunction* uFnEqualEqual_FloatFloat = nullptr;

	if (!uFnEqualEqual_FloatFloat)
	{
		uFnEqualEqual_FloatFloat = UFunction::FindFunction("Function Core.Object.EqualEqual_FloatFloat");
	}

	UObject_execEqualEqual_FloatFloat_Params EqualEqual_FloatFloat_Params;
	memset(&EqualEqual_FloatFloat_Params, 0, sizeof(EqualEqual_FloatFloat_Params));

	if (!uFnEqualEqual_FloatFloat)
	{
		return EqualEqual_FloatFloat_Params.ReturnValue;
	}
	EqualEqual_FloatFloat_Params.A = A;
	EqualEqual_FloatFloat_Params.B = B;

	uint16_t nativeIndex = uFnEqualEqual_FloatFloat->iNative;
	uFnEqualEqual_FloatFloat->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnEqualEqual_FloatFloat, &EqualEqual_FloatFloat_Params, nullptr);
	uFnEqualEqual_FloatFloat->iNative = nativeIndex;

	return EqualEqual_FloatFloat_Params.ReturnValue;
}

// Function Core.Object.GreaterEqual_FloatFloat
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[179])
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          A                              (CPF_Parm)
// float                          B                              (CPF_Parm)

bool UObject::GreaterEqual_FloatFloat(float A, float B)
{
	static UFunction* uFnGreaterEqual_FloatFloat = nullptr;

	if (!uFnGreaterEqual_FloatFloat)
	{
		uFnGreaterEqual_FloatFloat = UFunction::FindFunction("Function Core.Object.GreaterEqual_FloatFloat");
	}

	UObject_execGreaterEqual_FloatFloat_Params GreaterEqual_FloatFloat_Params;
	memset(&GreaterEqual_FloatFloat_Params, 0, sizeof(GreaterEqual_FloatFloat_Params));

	if (!uFnGreaterEqual_FloatFloat)
	{
		return GreaterEqual_FloatFloat_Params.ReturnValue;
	}
	GreaterEqual_FloatFloat_Params.A = A;
	GreaterEqual_FloatFloat_Params.B = B;

	uint16_t nativeIndex = uFnGreaterEqual_FloatFloat->iNative;
	uFnGreaterEqual_FloatFloat->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnGreaterEqual_FloatFloat, &GreaterEqual_FloatFloat_Params, nullptr);
	uFnGreaterEqual_FloatFloat->iNative = nativeIndex;

	return GreaterEqual_FloatFloat_Params.ReturnValue;
}

// Function Core.Object.LessEqual_FloatFloat
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[178])
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          A                              (CPF_Parm)
// float                          B                              (CPF_Parm)

bool UObject::LessEqual_FloatFloat(float A, float B)
{
	static UFunction* uFnLessEqual_FloatFloat = nullptr;

	if (!uFnLessEqual_FloatFloat)
	{
		uFnLessEqual_FloatFloat = UFunction::FindFunction("Function Core.Object.LessEqual_FloatFloat");
	}

	UObject_execLessEqual_FloatFloat_Params LessEqual_FloatFloat_Params;
	memset(&LessEqual_FloatFloat_Params, 0, sizeof(LessEqual_FloatFloat_Params));

	if (!uFnLessEqual_FloatFloat)
	{
		return LessEqual_FloatFloat_Params.ReturnValue;
	}
	LessEqual_FloatFloat_Params.A = A;
	LessEqual_FloatFloat_Params.B = B;

	uint16_t nativeIndex = uFnLessEqual_FloatFloat->iNative;
	uFnLessEqual_FloatFloat->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnLessEqual_FloatFloat, &LessEqual_FloatFloat_Params, nullptr);
	uFnLessEqual_FloatFloat->iNative = nativeIndex;

	return LessEqual_FloatFloat_Params.ReturnValue;
}

// Function Core.Object.Greater_FloatFloat
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[177])
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          A                              (CPF_Parm)
// float                          B                              (CPF_Parm)

bool UObject::Greater_FloatFloat(float A, float B)
{
	static UFunction* uFnGreater_FloatFloat = nullptr;

	if (!uFnGreater_FloatFloat)
	{
		uFnGreater_FloatFloat = UFunction::FindFunction("Function Core.Object.Greater_FloatFloat");
	}

	UObject_execGreater_FloatFloat_Params Greater_FloatFloat_Params;
	memset(&Greater_FloatFloat_Params, 0, sizeof(Greater_FloatFloat_Params));

	if (!uFnGreater_FloatFloat)
	{
		return Greater_FloatFloat_Params.ReturnValue;
	}
	Greater_FloatFloat_Params.A = A;
	Greater_FloatFloat_Params.B = B;

	uint16_t nativeIndex = uFnGreater_FloatFloat->iNative;
	uFnGreater_FloatFloat->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnGreater_FloatFloat, &Greater_FloatFloat_Params, nullptr);
	uFnGreater_FloatFloat->iNative = nativeIndex;

	return Greater_FloatFloat_Params.ReturnValue;
}

// Function Core.Object.Less_FloatFloat
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[176])
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          A                              (CPF_Parm)
// float                          B                              (CPF_Parm)

bool UObject::Less_FloatFloat(float A, float B)
{
	static UFunction* uFnLess_FloatFloat = nullptr;

	if (!uFnLess_FloatFloat)
	{
		uFnLess_FloatFloat = UFunction::FindFunction("Function Core.Object.Less_FloatFloat");
	}

	UObject_execLess_FloatFloat_Params Less_FloatFloat_Params;
	memset(&Less_FloatFloat_Params, 0, sizeof(Less_FloatFloat_Params));

	if (!uFnLess_FloatFloat)
	{
		return Less_FloatFloat_Params.ReturnValue;
	}
	Less_FloatFloat_Params.A = A;
	Less_FloatFloat_Params.B = B;

	uint16_t nativeIndex = uFnLess_FloatFloat->iNative;
	uFnLess_FloatFloat->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnLess_FloatFloat, &Less_FloatFloat_Params, nullptr);
	uFnLess_FloatFloat->iNative = nativeIndex;

	return Less_FloatFloat_Params.ReturnValue;
}

// Function Core.Object.Subtract_FloatFloat
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[175])
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          A                              (CPF_Parm)
// float                          B                              (CPF_Parm)

float UObject::Subtract_FloatFloat(float A, float B)
{
	static UFunction* uFnSubtract_FloatFloat = nullptr;

	if (!uFnSubtract_FloatFloat)
	{
		uFnSubtract_FloatFloat = UFunction::FindFunction("Function Core.Object.Subtract_FloatFloat");
	}

	UObject_execSubtract_FloatFloat_Params Subtract_FloatFloat_Params;
	memset(&Subtract_FloatFloat_Params, 0, sizeof(Subtract_FloatFloat_Params));

	if (!uFnSubtract_FloatFloat)
	{
		return Subtract_FloatFloat_Params.ReturnValue;
	}
	Subtract_FloatFloat_Params.A = A;
	Subtract_FloatFloat_Params.B = B;

	uint16_t nativeIndex = uFnSubtract_FloatFloat->iNative;
	uFnSubtract_FloatFloat->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnSubtract_FloatFloat, &Subtract_FloatFloat_Params, nullptr);
	uFnSubtract_FloatFloat->iNative = nativeIndex;

	return Subtract_FloatFloat_Params.ReturnValue;
}

// Function Core.Object.Add_FloatFloat
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[174])
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          A                              (CPF_Parm)
// float                          B                              (CPF_Parm)

float UObject::Add_FloatFloat(float A, float B)
{
	static UFunction* uFnAdd_FloatFloat = nullptr;

	if (!uFnAdd_FloatFloat)
	{
		uFnAdd_FloatFloat = UFunction::FindFunction("Function Core.Object.Add_FloatFloat");
	}

	UObject_execAdd_FloatFloat_Params Add_FloatFloat_Params;
	memset(&Add_FloatFloat_Params, 0, sizeof(Add_FloatFloat_Params));

	if (!uFnAdd_FloatFloat)
	{
		return Add_FloatFloat_Params.ReturnValue;
	}
	Add_FloatFloat_Params.A = A;
	Add_FloatFloat_Params.B = B;

	uint16_t nativeIndex = uFnAdd_FloatFloat->iNative;
	uFnAdd_FloatFloat->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnAdd_FloatFloat, &Add_FloatFloat_Params, nullptr);
	uFnAdd_FloatFloat->iNative = nativeIndex;

	return Add_FloatFloat_Params.ReturnValue;
}

// Function Core.Object.Percent_FloatFloat
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[173])
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          A                              (CPF_Parm)
// float                          B                              (CPF_Parm)

float UObject::Percent_FloatFloat(float A, float B)
{
	static UFunction* uFnPercent_FloatFloat = nullptr;

	if (!uFnPercent_FloatFloat)
	{
		uFnPercent_FloatFloat = UFunction::FindFunction("Function Core.Object.Percent_FloatFloat");
	}

	UObject_execPercent_FloatFloat_Params Percent_FloatFloat_Params;
	memset(&Percent_FloatFloat_Params, 0, sizeof(Percent_FloatFloat_Params));

	if (!uFnPercent_FloatFloat)
	{
		return Percent_FloatFloat_Params.ReturnValue;
	}
	Percent_FloatFloat_Params.A = A;
	Percent_FloatFloat_Params.B = B;

	uint16_t nativeIndex = uFnPercent_FloatFloat->iNative;
	uFnPercent_FloatFloat->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnPercent_FloatFloat, &Percent_FloatFloat_Params, nullptr);
	uFnPercent_FloatFloat->iNative = nativeIndex;

	return Percent_FloatFloat_Params.ReturnValue;
}

// Function Core.Object.Divide_FloatFloat
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[172])
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          A                              (CPF_Parm)
// float                          B                              (CPF_Parm)

float UObject::Divide_FloatFloat(float A, float B)
{
	static UFunction* uFnDivide_FloatFloat = nullptr;

	if (!uFnDivide_FloatFloat)
	{
		uFnDivide_FloatFloat = UFunction::FindFunction("Function Core.Object.Divide_FloatFloat");
	}

	UObject_execDivide_FloatFloat_Params Divide_FloatFloat_Params;
	memset(&Divide_FloatFloat_Params, 0, sizeof(Divide_FloatFloat_Params));

	if (!uFnDivide_FloatFloat)
	{
		return Divide_FloatFloat_Params.ReturnValue;
	}
	Divide_FloatFloat_Params.A = A;
	Divide_FloatFloat_Params.B = B;

	uint16_t nativeIndex = uFnDivide_FloatFloat->iNative;
	uFnDivide_FloatFloat->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnDivide_FloatFloat, &Divide_FloatFloat_Params, nullptr);
	uFnDivide_FloatFloat->iNative = nativeIndex;

	return Divide_FloatFloat_Params.ReturnValue;
}

// Function Core.Object.Multiply_FloatFloat
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[171])
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          A                              (CPF_Parm)
// float                          B                              (CPF_Parm)

float UObject::Multiply_FloatFloat(float A, float B)
{
	static UFunction* uFnMultiply_FloatFloat = nullptr;

	if (!uFnMultiply_FloatFloat)
	{
		uFnMultiply_FloatFloat = UFunction::FindFunction("Function Core.Object.Multiply_FloatFloat");
	}

	UObject_execMultiply_FloatFloat_Params Multiply_FloatFloat_Params;
	memset(&Multiply_FloatFloat_Params, 0, sizeof(Multiply_FloatFloat_Params));

	if (!uFnMultiply_FloatFloat)
	{
		return Multiply_FloatFloat_Params.ReturnValue;
	}
	Multiply_FloatFloat_Params.A = A;
	Multiply_FloatFloat_Params.B = B;

	uint16_t nativeIndex = uFnMultiply_FloatFloat->iNative;
	uFnMultiply_FloatFloat->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnMultiply_FloatFloat, &Multiply_FloatFloat_Params, nullptr);
	uFnMultiply_FloatFloat->iNative = nativeIndex;

	return Multiply_FloatFloat_Params.ReturnValue;
}

// Function Core.Object.MultiplyMultiply_FloatFloat
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[170])
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          Base                           (CPF_Parm)
// float                          Exp                            (CPF_Parm)

float UObject::MultiplyMultiply_FloatFloat(float Base, float Exp)
{
	static UFunction* uFnMultiplyMultiply_FloatFloat = nullptr;

	if (!uFnMultiplyMultiply_FloatFloat)
	{
		uFnMultiplyMultiply_FloatFloat = UFunction::FindFunction("Function Core.Object.MultiplyMultiply_FloatFloat");
	}

	UObject_execMultiplyMultiply_FloatFloat_Params MultiplyMultiply_FloatFloat_Params;
	memset(&MultiplyMultiply_FloatFloat_Params, 0, sizeof(MultiplyMultiply_FloatFloat_Params));

	if (!uFnMultiplyMultiply_FloatFloat)
	{
		return MultiplyMultiply_FloatFloat_Params.ReturnValue;
	}
	MultiplyMultiply_FloatFloat_Params.Base = Base;
	MultiplyMultiply_FloatFloat_Params.Exp = Exp;

	uint16_t nativeIndex = uFnMultiplyMultiply_FloatFloat->iNative;
	uFnMultiplyMultiply_FloatFloat->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnMultiplyMultiply_FloatFloat, &MultiplyMultiply_FloatFloat_Params, nullptr);
	uFnMultiplyMultiply_FloatFloat->iNative = nativeIndex;

	return MultiplyMultiply_FloatFloat_Params.ReturnValue;
}

// Function Core.Object.Subtract_PreFloat
// [0x00023411] (FUNC_Final | FUNC_PreOperator | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[169])
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          A                              (CPF_Parm)

float UObject::Subtract_PreFloat(float A)
{
	static UFunction* uFnSubtract_PreFloat = nullptr;

	if (!uFnSubtract_PreFloat)
	{
		uFnSubtract_PreFloat = UFunction::FindFunction("Function Core.Object.Subtract_PreFloat");
	}

	UObject_execSubtract_PreFloat_Params Subtract_PreFloat_Params;
	memset(&Subtract_PreFloat_Params, 0, sizeof(Subtract_PreFloat_Params));

	if (!uFnSubtract_PreFloat)
	{
		return Subtract_PreFloat_Params.ReturnValue;
	}
	Subtract_PreFloat_Params.A = A;

	uint16_t nativeIndex = uFnSubtract_PreFloat->iNative;
	uFnSubtract_PreFloat->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnSubtract_PreFloat, &Subtract_PreFloat_Params, nullptr);
	uFnSubtract_PreFloat->iNative = nativeIndex;

	return Subtract_PreFloat_Params.ReturnValue;
}

// Function Core.Object.ToHex
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public)
// Parameter Info:
// class FString                  ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm | CPF_NeedCtorLink)
// int32_t                        A                              (CPF_Parm)

class FString UObject::ToHex(int32_t A)
{
	static UFunction* uFnToHex = nullptr;

	if (!uFnToHex)
	{
		uFnToHex = UFunction::FindFunction("Function Core.Object.ToHex");
	}

	UObject_execToHex_Params ToHex_Params;
	memset(&ToHex_Params, 0, sizeof(ToHex_Params));

	if (!uFnToHex)
	{
		return ToHex_Params.ReturnValue;
	}
	ToHex_Params.A = A;

	uint16_t nativeIndex = uFnToHex->iNative;
	uFnToHex->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnToHex, &ToHex_Params, nullptr);
	uFnToHex->iNative = nativeIndex;

	return ToHex_Params.ReturnValue;
}

// Function Core.Object.Clamp
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public) (iNative[251])
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        V                              (CPF_Parm)
// int32_t                        A                              (CPF_Parm)
// int32_t                        B                              (CPF_Parm)

int32_t UObject::Clamp(int32_t V, int32_t A, int32_t B)
{
	static UFunction* uFnClamp = nullptr;

	if (!uFnClamp)
	{
		uFnClamp = UFunction::FindFunction("Function Core.Object.Clamp");
	}

	UObject_execClamp_Params Clamp_Params;
	memset(&Clamp_Params, 0, sizeof(Clamp_Params));

	if (!uFnClamp)
	{
		return Clamp_Params.ReturnValue;
	}
	Clamp_Params.V = V;
	Clamp_Params.A = A;
	Clamp_Params.B = B;

	uint16_t nativeIndex = uFnClamp->iNative;
	uFnClamp->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnClamp, &Clamp_Params, nullptr);
	uFnClamp->iNative = nativeIndex;

	return Clamp_Params.ReturnValue;
}

// Function Core.Object.Max
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public) (iNative[250])
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        A                              (CPF_Parm)
// int32_t                        B                              (CPF_Parm)

int32_t UObject::Max(int32_t A, int32_t B)
{
	static UFunction* uFnMax = nullptr;

	if (!uFnMax)
	{
		uFnMax = UFunction::FindFunction("Function Core.Object.Max");
	}

	UObject_execMax_Params Max_Params;
	memset(&Max_Params, 0, sizeof(Max_Params));

	if (!uFnMax)
	{
		return Max_Params.ReturnValue;
	}
	Max_Params.A = A;
	Max_Params.B = B;

	uint16_t nativeIndex = uFnMax->iNative;
	uFnMax->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnMax, &Max_Params, nullptr);
	uFnMax->iNative = nativeIndex;

	return Max_Params.ReturnValue;
}

// Function Core.Object.Min
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public) (iNative[249])
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        A                              (CPF_Parm)
// int32_t                        B                              (CPF_Parm)

int32_t UObject::Min(int32_t A, int32_t B)
{
	static UFunction* uFnMin = nullptr;

	if (!uFnMin)
	{
		uFnMin = UFunction::FindFunction("Function Core.Object.Min");
	}

	UObject_execMin_Params Min_Params;
	memset(&Min_Params, 0, sizeof(Min_Params));

	if (!uFnMin)
	{
		return Min_Params.ReturnValue;
	}
	Min_Params.A = A;
	Min_Params.B = B;

	uint16_t nativeIndex = uFnMin->iNative;
	uFnMin->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnMin, &Min_Params, nullptr);
	uFnMin->iNative = nativeIndex;

	return Min_Params.ReturnValue;
}

// Function Core.Object.Rand
// [0x00022401] (FUNC_Final | FUNC_Native | FUNC_Static | FUNC_Public) (iNative[167])
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        Max                            (CPF_Parm)

int32_t UObject::Rand(int32_t Max)
{
	static UFunction* uFnRand = nullptr;

	if (!uFnRand)
	{
		uFnRand = UFunction::FindFunction("Function Core.Object.Rand");
	}

	UObject_execRand_Params Rand_Params;
	memset(&Rand_Params, 0, sizeof(Rand_Params));

	if (!uFnRand)
	{
		return Rand_Params.ReturnValue;
	}
	Rand_Params.Max = Max;

	uint16_t nativeIndex = uFnRand->iNative;
	uFnRand->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnRand, &Rand_Params, nullptr);
	uFnRand->iNative = nativeIndex;

	return Rand_Params.ReturnValue;
}

// Function Core.Object.SubtractSubtract_Int
// [0x00423401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public | FUNC_HasOutParms) (iNative[166])
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        A                              (CPF_Parm | CPF_OutParm)

int32_t UObject::SubtractSubtract_Int(int32_t& outA)
{
	static UFunction* uFnSubtractSubtract_Int = nullptr;

	if (!uFnSubtractSubtract_Int)
	{
		uFnSubtractSubtract_Int = UFunction::FindFunction("Function Core.Object.SubtractSubtract_Int");
	}

	UObject_execSubtractSubtract_Int_Params SubtractSubtract_Int_Params;
	memset(&SubtractSubtract_Int_Params, 0, sizeof(SubtractSubtract_Int_Params));

	if (!uFnSubtractSubtract_Int)
	{
		return SubtractSubtract_Int_Params.ReturnValue;
	}
	SubtractSubtract_Int_Params.A = outA;

	uint16_t nativeIndex = uFnSubtractSubtract_Int->iNative;
	uFnSubtractSubtract_Int->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnSubtractSubtract_Int, &SubtractSubtract_Int_Params, nullptr);
	uFnSubtractSubtract_Int->iNative = nativeIndex;

	outA = SubtractSubtract_Int_Params.A;

	return SubtractSubtract_Int_Params.ReturnValue;
}

// Function Core.Object.AddAdd_Int
// [0x00423401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public | FUNC_HasOutParms) (iNative[165])
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        A                              (CPF_Parm | CPF_OutParm)

int32_t UObject::AddAdd_Int(int32_t& outA)
{
	static UFunction* uFnAddAdd_Int = nullptr;

	if (!uFnAddAdd_Int)
	{
		uFnAddAdd_Int = UFunction::FindFunction("Function Core.Object.AddAdd_Int");
	}

	UObject_execAddAdd_Int_Params AddAdd_Int_Params;
	memset(&AddAdd_Int_Params, 0, sizeof(AddAdd_Int_Params));

	if (!uFnAddAdd_Int)
	{
		return AddAdd_Int_Params.ReturnValue;
	}
	AddAdd_Int_Params.A = outA;

	uint16_t nativeIndex = uFnAddAdd_Int->iNative;
	uFnAddAdd_Int->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnAddAdd_Int, &AddAdd_Int_Params, nullptr);
	uFnAddAdd_Int->iNative = nativeIndex;

	outA = AddAdd_Int_Params.A;

	return AddAdd_Int_Params.ReturnValue;
}

// Function Core.Object.SubtractSubtract_PreInt
// [0x00423411] (FUNC_Final | FUNC_PreOperator | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public | FUNC_HasOutParms) (iNative[164])
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        A                              (CPF_Parm | CPF_OutParm)

int32_t UObject::SubtractSubtract_PreInt(int32_t& outA)
{
	static UFunction* uFnSubtractSubtract_PreInt = nullptr;

	if (!uFnSubtractSubtract_PreInt)
	{
		uFnSubtractSubtract_PreInt = UFunction::FindFunction("Function Core.Object.SubtractSubtract_PreInt");
	}

	UObject_execSubtractSubtract_PreInt_Params SubtractSubtract_PreInt_Params;
	memset(&SubtractSubtract_PreInt_Params, 0, sizeof(SubtractSubtract_PreInt_Params));

	if (!uFnSubtractSubtract_PreInt)
	{
		return SubtractSubtract_PreInt_Params.ReturnValue;
	}
	SubtractSubtract_PreInt_Params.A = outA;

	uint16_t nativeIndex = uFnSubtractSubtract_PreInt->iNative;
	uFnSubtractSubtract_PreInt->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnSubtractSubtract_PreInt, &SubtractSubtract_PreInt_Params, nullptr);
	uFnSubtractSubtract_PreInt->iNative = nativeIndex;

	outA = SubtractSubtract_PreInt_Params.A;

	return SubtractSubtract_PreInt_Params.ReturnValue;
}

// Function Core.Object.AddAdd_PreInt
// [0x00423411] (FUNC_Final | FUNC_PreOperator | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public | FUNC_HasOutParms) (iNative[163])
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        A                              (CPF_Parm | CPF_OutParm)

int32_t UObject::AddAdd_PreInt(int32_t& outA)
{
	static UFunction* uFnAddAdd_PreInt = nullptr;

	if (!uFnAddAdd_PreInt)
	{
		uFnAddAdd_PreInt = UFunction::FindFunction("Function Core.Object.AddAdd_PreInt");
	}

	UObject_execAddAdd_PreInt_Params AddAdd_PreInt_Params;
	memset(&AddAdd_PreInt_Params, 0, sizeof(AddAdd_PreInt_Params));

	if (!uFnAddAdd_PreInt)
	{
		return AddAdd_PreInt_Params.ReturnValue;
	}
	AddAdd_PreInt_Params.A = outA;

	uint16_t nativeIndex = uFnAddAdd_PreInt->iNative;
	uFnAddAdd_PreInt->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnAddAdd_PreInt, &AddAdd_PreInt_Params, nullptr);
	uFnAddAdd_PreInt->iNative = nativeIndex;

	outA = AddAdd_PreInt_Params.A;

	return AddAdd_PreInt_Params.ReturnValue;
}

// Function Core.Object.SubtractEqual_IntInt
// [0x00423401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public | FUNC_HasOutParms) (iNative[162])
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        B                              (CPF_Parm)
// int32_t                        A                              (CPF_Parm | CPF_OutParm)

int32_t UObject::SubtractEqual_IntInt(int32_t B, int32_t& outA)
{
	static UFunction* uFnSubtractEqual_IntInt = nullptr;

	if (!uFnSubtractEqual_IntInt)
	{
		uFnSubtractEqual_IntInt = UFunction::FindFunction("Function Core.Object.SubtractEqual_IntInt");
	}

	UObject_execSubtractEqual_IntInt_Params SubtractEqual_IntInt_Params;
	memset(&SubtractEqual_IntInt_Params, 0, sizeof(SubtractEqual_IntInt_Params));

	if (!uFnSubtractEqual_IntInt)
	{
		return SubtractEqual_IntInt_Params.ReturnValue;
	}
	SubtractEqual_IntInt_Params.B = B;
	SubtractEqual_IntInt_Params.A = outA;

	uint16_t nativeIndex = uFnSubtractEqual_IntInt->iNative;
	uFnSubtractEqual_IntInt->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnSubtractEqual_IntInt, &SubtractEqual_IntInt_Params, nullptr);
	uFnSubtractEqual_IntInt->iNative = nativeIndex;

	outA = SubtractEqual_IntInt_Params.A;

	return SubtractEqual_IntInt_Params.ReturnValue;
}

// Function Core.Object.AddEqual_IntInt
// [0x00423401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public | FUNC_HasOutParms) (iNative[161])
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        B                              (CPF_Parm)
// int32_t                        A                              (CPF_Parm | CPF_OutParm)

int32_t UObject::AddEqual_IntInt(int32_t B, int32_t& outA)
{
	static UFunction* uFnAddEqual_IntInt = nullptr;

	if (!uFnAddEqual_IntInt)
	{
		uFnAddEqual_IntInt = UFunction::FindFunction("Function Core.Object.AddEqual_IntInt");
	}

	UObject_execAddEqual_IntInt_Params AddEqual_IntInt_Params;
	memset(&AddEqual_IntInt_Params, 0, sizeof(AddEqual_IntInt_Params));

	if (!uFnAddEqual_IntInt)
	{
		return AddEqual_IntInt_Params.ReturnValue;
	}
	AddEqual_IntInt_Params.B = B;
	AddEqual_IntInt_Params.A = outA;

	uint16_t nativeIndex = uFnAddEqual_IntInt->iNative;
	uFnAddEqual_IntInt->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnAddEqual_IntInt, &AddEqual_IntInt_Params, nullptr);
	uFnAddEqual_IntInt->iNative = nativeIndex;

	outA = AddEqual_IntInt_Params.A;

	return AddEqual_IntInt_Params.ReturnValue;
}

// Function Core.Object.DivideEqual_IntFloat
// [0x00423401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public | FUNC_HasOutParms) (iNative[160])
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          B                              (CPF_Parm)
// int32_t                        A                              (CPF_Parm | CPF_OutParm)

int32_t UObject::DivideEqual_IntFloat(float B, int32_t& outA)
{
	static UFunction* uFnDivideEqual_IntFloat = nullptr;

	if (!uFnDivideEqual_IntFloat)
	{
		uFnDivideEqual_IntFloat = UFunction::FindFunction("Function Core.Object.DivideEqual_IntFloat");
	}

	UObject_execDivideEqual_IntFloat_Params DivideEqual_IntFloat_Params;
	memset(&DivideEqual_IntFloat_Params, 0, sizeof(DivideEqual_IntFloat_Params));

	if (!uFnDivideEqual_IntFloat)
	{
		return DivideEqual_IntFloat_Params.ReturnValue;
	}
	DivideEqual_IntFloat_Params.B = B;
	DivideEqual_IntFloat_Params.A = outA;

	uint16_t nativeIndex = uFnDivideEqual_IntFloat->iNative;
	uFnDivideEqual_IntFloat->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnDivideEqual_IntFloat, &DivideEqual_IntFloat_Params, nullptr);
	uFnDivideEqual_IntFloat->iNative = nativeIndex;

	outA = DivideEqual_IntFloat_Params.A;

	return DivideEqual_IntFloat_Params.ReturnValue;
}

// Function Core.Object.MultiplyEqual_IntFloat
// [0x00423401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public | FUNC_HasOutParms) (iNative[159])
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          B                              (CPF_Parm)
// int32_t                        A                              (CPF_Parm | CPF_OutParm)

int32_t UObject::MultiplyEqual_IntFloat(float B, int32_t& outA)
{
	static UFunction* uFnMultiplyEqual_IntFloat = nullptr;

	if (!uFnMultiplyEqual_IntFloat)
	{
		uFnMultiplyEqual_IntFloat = UFunction::FindFunction("Function Core.Object.MultiplyEqual_IntFloat");
	}

	UObject_execMultiplyEqual_IntFloat_Params MultiplyEqual_IntFloat_Params;
	memset(&MultiplyEqual_IntFloat_Params, 0, sizeof(MultiplyEqual_IntFloat_Params));

	if (!uFnMultiplyEqual_IntFloat)
	{
		return MultiplyEqual_IntFloat_Params.ReturnValue;
	}
	MultiplyEqual_IntFloat_Params.B = B;
	MultiplyEqual_IntFloat_Params.A = outA;

	uint16_t nativeIndex = uFnMultiplyEqual_IntFloat->iNative;
	uFnMultiplyEqual_IntFloat->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnMultiplyEqual_IntFloat, &MultiplyEqual_IntFloat_Params, nullptr);
	uFnMultiplyEqual_IntFloat->iNative = nativeIndex;

	outA = MultiplyEqual_IntFloat_Params.A;

	return MultiplyEqual_IntFloat_Params.ReturnValue;
}

// Function Core.Object.Or_IntInt
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[158])
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        A                              (CPF_Parm)
// int32_t                        B                              (CPF_Parm)

int32_t UObject::Or_IntInt(int32_t A, int32_t B)
{
	static UFunction* uFnOr_IntInt = nullptr;

	if (!uFnOr_IntInt)
	{
		uFnOr_IntInt = UFunction::FindFunction("Function Core.Object.Or_IntInt");
	}

	UObject_execOr_IntInt_Params Or_IntInt_Params;
	memset(&Or_IntInt_Params, 0, sizeof(Or_IntInt_Params));

	if (!uFnOr_IntInt)
	{
		return Or_IntInt_Params.ReturnValue;
	}
	Or_IntInt_Params.A = A;
	Or_IntInt_Params.B = B;

	uint16_t nativeIndex = uFnOr_IntInt->iNative;
	uFnOr_IntInt->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnOr_IntInt, &Or_IntInt_Params, nullptr);
	uFnOr_IntInt->iNative = nativeIndex;

	return Or_IntInt_Params.ReturnValue;
}

// Function Core.Object.Xor_IntInt
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[157])
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        A                              (CPF_Parm)
// int32_t                        B                              (CPF_Parm)

int32_t UObject::Xor_IntInt(int32_t A, int32_t B)
{
	static UFunction* uFnXor_IntInt = nullptr;

	if (!uFnXor_IntInt)
	{
		uFnXor_IntInt = UFunction::FindFunction("Function Core.Object.Xor_IntInt");
	}

	UObject_execXor_IntInt_Params Xor_IntInt_Params;
	memset(&Xor_IntInt_Params, 0, sizeof(Xor_IntInt_Params));

	if (!uFnXor_IntInt)
	{
		return Xor_IntInt_Params.ReturnValue;
	}
	Xor_IntInt_Params.A = A;
	Xor_IntInt_Params.B = B;

	uint16_t nativeIndex = uFnXor_IntInt->iNative;
	uFnXor_IntInt->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnXor_IntInt, &Xor_IntInt_Params, nullptr);
	uFnXor_IntInt->iNative = nativeIndex;

	return Xor_IntInt_Params.ReturnValue;
}

// Function Core.Object.And_IntInt
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[156])
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        A                              (CPF_Parm)
// int32_t                        B                              (CPF_Parm)

int32_t UObject::And_IntInt(int32_t A, int32_t B)
{
	static UFunction* uFnAnd_IntInt = nullptr;

	if (!uFnAnd_IntInt)
	{
		uFnAnd_IntInt = UFunction::FindFunction("Function Core.Object.And_IntInt");
	}

	UObject_execAnd_IntInt_Params And_IntInt_Params;
	memset(&And_IntInt_Params, 0, sizeof(And_IntInt_Params));

	if (!uFnAnd_IntInt)
	{
		return And_IntInt_Params.ReturnValue;
	}
	And_IntInt_Params.A = A;
	And_IntInt_Params.B = B;

	uint16_t nativeIndex = uFnAnd_IntInt->iNative;
	uFnAnd_IntInt->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnAnd_IntInt, &And_IntInt_Params, nullptr);
	uFnAnd_IntInt->iNative = nativeIndex;

	return And_IntInt_Params.ReturnValue;
}

// Function Core.Object.NotEqual_IntInt
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[155])
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        A                              (CPF_Parm)
// int32_t                        B                              (CPF_Parm)

bool UObject::NotEqual_IntInt(int32_t A, int32_t B)
{
	static UFunction* uFnNotEqual_IntInt = nullptr;

	if (!uFnNotEqual_IntInt)
	{
		uFnNotEqual_IntInt = UFunction::FindFunction("Function Core.Object.NotEqual_IntInt");
	}

	UObject_execNotEqual_IntInt_Params NotEqual_IntInt_Params;
	memset(&NotEqual_IntInt_Params, 0, sizeof(NotEqual_IntInt_Params));

	if (!uFnNotEqual_IntInt)
	{
		return NotEqual_IntInt_Params.ReturnValue;
	}
	NotEqual_IntInt_Params.A = A;
	NotEqual_IntInt_Params.B = B;

	uint16_t nativeIndex = uFnNotEqual_IntInt->iNative;
	uFnNotEqual_IntInt->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnNotEqual_IntInt, &NotEqual_IntInt_Params, nullptr);
	uFnNotEqual_IntInt->iNative = nativeIndex;

	return NotEqual_IntInt_Params.ReturnValue;
}

// Function Core.Object.EqualEqual_IntInt
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[154])
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        A                              (CPF_Parm)
// int32_t                        B                              (CPF_Parm)

bool UObject::EqualEqual_IntInt(int32_t A, int32_t B)
{
	static UFunction* uFnEqualEqual_IntInt = nullptr;

	if (!uFnEqualEqual_IntInt)
	{
		uFnEqualEqual_IntInt = UFunction::FindFunction("Function Core.Object.EqualEqual_IntInt");
	}

	UObject_execEqualEqual_IntInt_Params EqualEqual_IntInt_Params;
	memset(&EqualEqual_IntInt_Params, 0, sizeof(EqualEqual_IntInt_Params));

	if (!uFnEqualEqual_IntInt)
	{
		return EqualEqual_IntInt_Params.ReturnValue;
	}
	EqualEqual_IntInt_Params.A = A;
	EqualEqual_IntInt_Params.B = B;

	uint16_t nativeIndex = uFnEqualEqual_IntInt->iNative;
	uFnEqualEqual_IntInt->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnEqualEqual_IntInt, &EqualEqual_IntInt_Params, nullptr);
	uFnEqualEqual_IntInt->iNative = nativeIndex;

	return EqualEqual_IntInt_Params.ReturnValue;
}

// Function Core.Object.GreaterEqual_IntInt
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[153])
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        A                              (CPF_Parm)
// int32_t                        B                              (CPF_Parm)

bool UObject::GreaterEqual_IntInt(int32_t A, int32_t B)
{
	static UFunction* uFnGreaterEqual_IntInt = nullptr;

	if (!uFnGreaterEqual_IntInt)
	{
		uFnGreaterEqual_IntInt = UFunction::FindFunction("Function Core.Object.GreaterEqual_IntInt");
	}

	UObject_execGreaterEqual_IntInt_Params GreaterEqual_IntInt_Params;
	memset(&GreaterEqual_IntInt_Params, 0, sizeof(GreaterEqual_IntInt_Params));

	if (!uFnGreaterEqual_IntInt)
	{
		return GreaterEqual_IntInt_Params.ReturnValue;
	}
	GreaterEqual_IntInt_Params.A = A;
	GreaterEqual_IntInt_Params.B = B;

	uint16_t nativeIndex = uFnGreaterEqual_IntInt->iNative;
	uFnGreaterEqual_IntInt->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnGreaterEqual_IntInt, &GreaterEqual_IntInt_Params, nullptr);
	uFnGreaterEqual_IntInt->iNative = nativeIndex;

	return GreaterEqual_IntInt_Params.ReturnValue;
}

// Function Core.Object.LessEqual_IntInt
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[152])
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        A                              (CPF_Parm)
// int32_t                        B                              (CPF_Parm)

bool UObject::LessEqual_IntInt(int32_t A, int32_t B)
{
	static UFunction* uFnLessEqual_IntInt = nullptr;

	if (!uFnLessEqual_IntInt)
	{
		uFnLessEqual_IntInt = UFunction::FindFunction("Function Core.Object.LessEqual_IntInt");
	}

	UObject_execLessEqual_IntInt_Params LessEqual_IntInt_Params;
	memset(&LessEqual_IntInt_Params, 0, sizeof(LessEqual_IntInt_Params));

	if (!uFnLessEqual_IntInt)
	{
		return LessEqual_IntInt_Params.ReturnValue;
	}
	LessEqual_IntInt_Params.A = A;
	LessEqual_IntInt_Params.B = B;

	uint16_t nativeIndex = uFnLessEqual_IntInt->iNative;
	uFnLessEqual_IntInt->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnLessEqual_IntInt, &LessEqual_IntInt_Params, nullptr);
	uFnLessEqual_IntInt->iNative = nativeIndex;

	return LessEqual_IntInt_Params.ReturnValue;
}

// Function Core.Object.Greater_IntInt
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[151])
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        A                              (CPF_Parm)
// int32_t                        B                              (CPF_Parm)

bool UObject::Greater_IntInt(int32_t A, int32_t B)
{
	static UFunction* uFnGreater_IntInt = nullptr;

	if (!uFnGreater_IntInt)
	{
		uFnGreater_IntInt = UFunction::FindFunction("Function Core.Object.Greater_IntInt");
	}

	UObject_execGreater_IntInt_Params Greater_IntInt_Params;
	memset(&Greater_IntInt_Params, 0, sizeof(Greater_IntInt_Params));

	if (!uFnGreater_IntInt)
	{
		return Greater_IntInt_Params.ReturnValue;
	}
	Greater_IntInt_Params.A = A;
	Greater_IntInt_Params.B = B;

	uint16_t nativeIndex = uFnGreater_IntInt->iNative;
	uFnGreater_IntInt->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnGreater_IntInt, &Greater_IntInt_Params, nullptr);
	uFnGreater_IntInt->iNative = nativeIndex;

	return Greater_IntInt_Params.ReturnValue;
}

// Function Core.Object.Less_IntInt
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[150])
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        A                              (CPF_Parm)
// int32_t                        B                              (CPF_Parm)

bool UObject::Less_IntInt(int32_t A, int32_t B)
{
	static UFunction* uFnLess_IntInt = nullptr;

	if (!uFnLess_IntInt)
	{
		uFnLess_IntInt = UFunction::FindFunction("Function Core.Object.Less_IntInt");
	}

	UObject_execLess_IntInt_Params Less_IntInt_Params;
	memset(&Less_IntInt_Params, 0, sizeof(Less_IntInt_Params));

	if (!uFnLess_IntInt)
	{
		return Less_IntInt_Params.ReturnValue;
	}
	Less_IntInt_Params.A = A;
	Less_IntInt_Params.B = B;

	uint16_t nativeIndex = uFnLess_IntInt->iNative;
	uFnLess_IntInt->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnLess_IntInt, &Less_IntInt_Params, nullptr);
	uFnLess_IntInt->iNative = nativeIndex;

	return Less_IntInt_Params.ReturnValue;
}

// Function Core.Object.GreaterGreaterGreater_IntInt
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[196])
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        A                              (CPF_Parm)
// int32_t                        B                              (CPF_Parm)

int32_t UObject::GreaterGreaterGreater_IntInt(int32_t A, int32_t B)
{
	static UFunction* uFnGreaterGreaterGreater_IntInt = nullptr;

	if (!uFnGreaterGreaterGreater_IntInt)
	{
		uFnGreaterGreaterGreater_IntInt = UFunction::FindFunction("Function Core.Object.GreaterGreaterGreater_IntInt");
	}

	UObject_execGreaterGreaterGreater_IntInt_Params GreaterGreaterGreater_IntInt_Params;
	memset(&GreaterGreaterGreater_IntInt_Params, 0, sizeof(GreaterGreaterGreater_IntInt_Params));

	if (!uFnGreaterGreaterGreater_IntInt)
	{
		return GreaterGreaterGreater_IntInt_Params.ReturnValue;
	}
	GreaterGreaterGreater_IntInt_Params.A = A;
	GreaterGreaterGreater_IntInt_Params.B = B;

	uint16_t nativeIndex = uFnGreaterGreaterGreater_IntInt->iNative;
	uFnGreaterGreaterGreater_IntInt->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnGreaterGreaterGreater_IntInt, &GreaterGreaterGreater_IntInt_Params, nullptr);
	uFnGreaterGreaterGreater_IntInt->iNative = nativeIndex;

	return GreaterGreaterGreater_IntInt_Params.ReturnValue;
}

// Function Core.Object.GreaterGreater_IntInt
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[149])
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        A                              (CPF_Parm)
// int32_t                        B                              (CPF_Parm)

int32_t UObject::GreaterGreater_IntInt(int32_t A, int32_t B)
{
	static UFunction* uFnGreaterGreater_IntInt = nullptr;

	if (!uFnGreaterGreater_IntInt)
	{
		uFnGreaterGreater_IntInt = UFunction::FindFunction("Function Core.Object.GreaterGreater_IntInt");
	}

	UObject_execGreaterGreater_IntInt_Params GreaterGreater_IntInt_Params;
	memset(&GreaterGreater_IntInt_Params, 0, sizeof(GreaterGreater_IntInt_Params));

	if (!uFnGreaterGreater_IntInt)
	{
		return GreaterGreater_IntInt_Params.ReturnValue;
	}
	GreaterGreater_IntInt_Params.A = A;
	GreaterGreater_IntInt_Params.B = B;

	uint16_t nativeIndex = uFnGreaterGreater_IntInt->iNative;
	uFnGreaterGreater_IntInt->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnGreaterGreater_IntInt, &GreaterGreater_IntInt_Params, nullptr);
	uFnGreaterGreater_IntInt->iNative = nativeIndex;

	return GreaterGreater_IntInt_Params.ReturnValue;
}

// Function Core.Object.LessLess_IntInt
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[148])
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        A                              (CPF_Parm)
// int32_t                        B                              (CPF_Parm)

int32_t UObject::LessLess_IntInt(int32_t A, int32_t B)
{
	static UFunction* uFnLessLess_IntInt = nullptr;

	if (!uFnLessLess_IntInt)
	{
		uFnLessLess_IntInt = UFunction::FindFunction("Function Core.Object.LessLess_IntInt");
	}

	UObject_execLessLess_IntInt_Params LessLess_IntInt_Params;
	memset(&LessLess_IntInt_Params, 0, sizeof(LessLess_IntInt_Params));

	if (!uFnLessLess_IntInt)
	{
		return LessLess_IntInt_Params.ReturnValue;
	}
	LessLess_IntInt_Params.A = A;
	LessLess_IntInt_Params.B = B;

	uint16_t nativeIndex = uFnLessLess_IntInt->iNative;
	uFnLessLess_IntInt->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnLessLess_IntInt, &LessLess_IntInt_Params, nullptr);
	uFnLessLess_IntInt->iNative = nativeIndex;

	return LessLess_IntInt_Params.ReturnValue;
}

// Function Core.Object.Subtract_IntInt
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[147])
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        A                              (CPF_Parm)
// int32_t                        B                              (CPF_Parm)

int32_t UObject::Subtract_IntInt(int32_t A, int32_t B)
{
	static UFunction* uFnSubtract_IntInt = nullptr;

	if (!uFnSubtract_IntInt)
	{
		uFnSubtract_IntInt = UFunction::FindFunction("Function Core.Object.Subtract_IntInt");
	}

	UObject_execSubtract_IntInt_Params Subtract_IntInt_Params;
	memset(&Subtract_IntInt_Params, 0, sizeof(Subtract_IntInt_Params));

	if (!uFnSubtract_IntInt)
	{
		return Subtract_IntInt_Params.ReturnValue;
	}
	Subtract_IntInt_Params.A = A;
	Subtract_IntInt_Params.B = B;

	uint16_t nativeIndex = uFnSubtract_IntInt->iNative;
	uFnSubtract_IntInt->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnSubtract_IntInt, &Subtract_IntInt_Params, nullptr);
	uFnSubtract_IntInt->iNative = nativeIndex;

	return Subtract_IntInt_Params.ReturnValue;
}

// Function Core.Object.Add_IntInt
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[146])
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        A                              (CPF_Parm)
// int32_t                        B                              (CPF_Parm)

int32_t UObject::Add_IntInt(int32_t A, int32_t B)
{
	static UFunction* uFnAdd_IntInt = nullptr;

	if (!uFnAdd_IntInt)
	{
		uFnAdd_IntInt = UFunction::FindFunction("Function Core.Object.Add_IntInt");
	}

	UObject_execAdd_IntInt_Params Add_IntInt_Params;
	memset(&Add_IntInt_Params, 0, sizeof(Add_IntInt_Params));

	if (!uFnAdd_IntInt)
	{
		return Add_IntInt_Params.ReturnValue;
	}
	Add_IntInt_Params.A = A;
	Add_IntInt_Params.B = B;

	uint16_t nativeIndex = uFnAdd_IntInt->iNative;
	uFnAdd_IntInt->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnAdd_IntInt, &Add_IntInt_Params, nullptr);
	uFnAdd_IntInt->iNative = nativeIndex;

	return Add_IntInt_Params.ReturnValue;
}

// Function Core.Object.Percent_IntInt
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[253])
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        A                              (CPF_Parm)
// int32_t                        B                              (CPF_Parm)

int32_t UObject::Percent_IntInt(int32_t A, int32_t B)
{
	static UFunction* uFnPercent_IntInt = nullptr;

	if (!uFnPercent_IntInt)
	{
		uFnPercent_IntInt = UFunction::FindFunction("Function Core.Object.Percent_IntInt");
	}

	UObject_execPercent_IntInt_Params Percent_IntInt_Params;
	memset(&Percent_IntInt_Params, 0, sizeof(Percent_IntInt_Params));

	if (!uFnPercent_IntInt)
	{
		return Percent_IntInt_Params.ReturnValue;
	}
	Percent_IntInt_Params.A = A;
	Percent_IntInt_Params.B = B;

	uint16_t nativeIndex = uFnPercent_IntInt->iNative;
	uFnPercent_IntInt->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnPercent_IntInt, &Percent_IntInt_Params, nullptr);
	uFnPercent_IntInt->iNative = nativeIndex;

	return Percent_IntInt_Params.ReturnValue;
}

// Function Core.Object.Divide_IntInt
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[145])
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        A                              (CPF_Parm)
// int32_t                        B                              (CPF_Parm)

int32_t UObject::Divide_IntInt(int32_t A, int32_t B)
{
	static UFunction* uFnDivide_IntInt = nullptr;

	if (!uFnDivide_IntInt)
	{
		uFnDivide_IntInt = UFunction::FindFunction("Function Core.Object.Divide_IntInt");
	}

	UObject_execDivide_IntInt_Params Divide_IntInt_Params;
	memset(&Divide_IntInt_Params, 0, sizeof(Divide_IntInt_Params));

	if (!uFnDivide_IntInt)
	{
		return Divide_IntInt_Params.ReturnValue;
	}
	Divide_IntInt_Params.A = A;
	Divide_IntInt_Params.B = B;

	uint16_t nativeIndex = uFnDivide_IntInt->iNative;
	uFnDivide_IntInt->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnDivide_IntInt, &Divide_IntInt_Params, nullptr);
	uFnDivide_IntInt->iNative = nativeIndex;

	return Divide_IntInt_Params.ReturnValue;
}

// Function Core.Object.Multiply_IntInt
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[144])
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        A                              (CPF_Parm)
// int32_t                        B                              (CPF_Parm)

int32_t UObject::Multiply_IntInt(int32_t A, int32_t B)
{
	static UFunction* uFnMultiply_IntInt = nullptr;

	if (!uFnMultiply_IntInt)
	{
		uFnMultiply_IntInt = UFunction::FindFunction("Function Core.Object.Multiply_IntInt");
	}

	UObject_execMultiply_IntInt_Params Multiply_IntInt_Params;
	memset(&Multiply_IntInt_Params, 0, sizeof(Multiply_IntInt_Params));

	if (!uFnMultiply_IntInt)
	{
		return Multiply_IntInt_Params.ReturnValue;
	}
	Multiply_IntInt_Params.A = A;
	Multiply_IntInt_Params.B = B;

	uint16_t nativeIndex = uFnMultiply_IntInt->iNative;
	uFnMultiply_IntInt->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnMultiply_IntInt, &Multiply_IntInt_Params, nullptr);
	uFnMultiply_IntInt->iNative = nativeIndex;

	return Multiply_IntInt_Params.ReturnValue;
}

// Function Core.Object.Subtract_PreInt
// [0x00023411] (FUNC_Final | FUNC_PreOperator | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[143])
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        A                              (CPF_Parm)

int32_t UObject::Subtract_PreInt(int32_t A)
{
	static UFunction* uFnSubtract_PreInt = nullptr;

	if (!uFnSubtract_PreInt)
	{
		uFnSubtract_PreInt = UFunction::FindFunction("Function Core.Object.Subtract_PreInt");
	}

	UObject_execSubtract_PreInt_Params Subtract_PreInt_Params;
	memset(&Subtract_PreInt_Params, 0, sizeof(Subtract_PreInt_Params));

	if (!uFnSubtract_PreInt)
	{
		return Subtract_PreInt_Params.ReturnValue;
	}
	Subtract_PreInt_Params.A = A;

	uint16_t nativeIndex = uFnSubtract_PreInt->iNative;
	uFnSubtract_PreInt->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnSubtract_PreInt, &Subtract_PreInt_Params, nullptr);
	uFnSubtract_PreInt->iNative = nativeIndex;

	return Subtract_PreInt_Params.ReturnValue;
}

// Function Core.Object.Complement_PreInt
// [0x00023411] (FUNC_Final | FUNC_PreOperator | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[141])
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// int32_t                        A                              (CPF_Parm)

int32_t UObject::Complement_PreInt(int32_t A)
{
	static UFunction* uFnComplement_PreInt = nullptr;

	if (!uFnComplement_PreInt)
	{
		uFnComplement_PreInt = UFunction::FindFunction("Function Core.Object.Complement_PreInt");
	}

	UObject_execComplement_PreInt_Params Complement_PreInt_Params;
	memset(&Complement_PreInt_Params, 0, sizeof(Complement_PreInt_Params));

	if (!uFnComplement_PreInt)
	{
		return Complement_PreInt_Params.ReturnValue;
	}
	Complement_PreInt_Params.A = A;

	uint16_t nativeIndex = uFnComplement_PreInt->iNative;
	uFnComplement_PreInt->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnComplement_PreInt, &Complement_PreInt_Params, nullptr);
	uFnComplement_PreInt->iNative = nativeIndex;

	return Complement_PreInt_Params.ReturnValue;
}

// Function Core.Object.SubtractSubtract_Byte
// [0x00423401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public | FUNC_HasOutParms) (iNative[140])
// Parameter Info:
// uint8_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// uint8_t                        A                              (CPF_Parm | CPF_OutParm)

uint8_t UObject::SubtractSubtract_Byte(uint8_t& outA)
{
	static UFunction* uFnSubtractSubtract_Byte = nullptr;

	if (!uFnSubtractSubtract_Byte)
	{
		uFnSubtractSubtract_Byte = UFunction::FindFunction("Function Core.Object.SubtractSubtract_Byte");
	}

	UObject_execSubtractSubtract_Byte_Params SubtractSubtract_Byte_Params;
	memset(&SubtractSubtract_Byte_Params, 0, sizeof(SubtractSubtract_Byte_Params));

	if (!uFnSubtractSubtract_Byte)
	{
		return static_cast<uint8_t>(SubtractSubtract_Byte_Params.ReturnValue);
	}
	SubtractSubtract_Byte_Params.A = static_cast<uint8_t>(outA);

	uint16_t nativeIndex = uFnSubtractSubtract_Byte->iNative;
	uFnSubtractSubtract_Byte->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnSubtractSubtract_Byte, &SubtractSubtract_Byte_Params, nullptr);
	uFnSubtractSubtract_Byte->iNative = nativeIndex;

	outA = static_cast<uint8_t>(SubtractSubtract_Byte_Params.A);

	return static_cast<uint8_t>(SubtractSubtract_Byte_Params.ReturnValue);
}

// Function Core.Object.AddAdd_Byte
// [0x00423401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public | FUNC_HasOutParms) (iNative[139])
// Parameter Info:
// uint8_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// uint8_t                        A                              (CPF_Parm | CPF_OutParm)

uint8_t UObject::AddAdd_Byte(uint8_t& outA)
{
	static UFunction* uFnAddAdd_Byte = nullptr;

	if (!uFnAddAdd_Byte)
	{
		uFnAddAdd_Byte = UFunction::FindFunction("Function Core.Object.AddAdd_Byte");
	}

	UObject_execAddAdd_Byte_Params AddAdd_Byte_Params;
	memset(&AddAdd_Byte_Params, 0, sizeof(AddAdd_Byte_Params));

	if (!uFnAddAdd_Byte)
	{
		return static_cast<uint8_t>(AddAdd_Byte_Params.ReturnValue);
	}
	AddAdd_Byte_Params.A = static_cast<uint8_t>(outA);

	uint16_t nativeIndex = uFnAddAdd_Byte->iNative;
	uFnAddAdd_Byte->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnAddAdd_Byte, &AddAdd_Byte_Params, nullptr);
	uFnAddAdd_Byte->iNative = nativeIndex;

	outA = static_cast<uint8_t>(AddAdd_Byte_Params.A);

	return static_cast<uint8_t>(AddAdd_Byte_Params.ReturnValue);
}

// Function Core.Object.SubtractSubtract_PreByte
// [0x00423411] (FUNC_Final | FUNC_PreOperator | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public | FUNC_HasOutParms) (iNative[138])
// Parameter Info:
// uint8_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// uint8_t                        A                              (CPF_Parm | CPF_OutParm)

uint8_t UObject::SubtractSubtract_PreByte(uint8_t& outA)
{
	static UFunction* uFnSubtractSubtract_PreByte = nullptr;

	if (!uFnSubtractSubtract_PreByte)
	{
		uFnSubtractSubtract_PreByte = UFunction::FindFunction("Function Core.Object.SubtractSubtract_PreByte");
	}

	UObject_execSubtractSubtract_PreByte_Params SubtractSubtract_PreByte_Params;
	memset(&SubtractSubtract_PreByte_Params, 0, sizeof(SubtractSubtract_PreByte_Params));

	if (!uFnSubtractSubtract_PreByte)
	{
		return static_cast<uint8_t>(SubtractSubtract_PreByte_Params.ReturnValue);
	}
	SubtractSubtract_PreByte_Params.A = static_cast<uint8_t>(outA);

	uint16_t nativeIndex = uFnSubtractSubtract_PreByte->iNative;
	uFnSubtractSubtract_PreByte->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnSubtractSubtract_PreByte, &SubtractSubtract_PreByte_Params, nullptr);
	uFnSubtractSubtract_PreByte->iNative = nativeIndex;

	outA = static_cast<uint8_t>(SubtractSubtract_PreByte_Params.A);

	return static_cast<uint8_t>(SubtractSubtract_PreByte_Params.ReturnValue);
}

// Function Core.Object.AddAdd_PreByte
// [0x00423411] (FUNC_Final | FUNC_PreOperator | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public | FUNC_HasOutParms) (iNative[137])
// Parameter Info:
// uint8_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// uint8_t                        A                              (CPF_Parm | CPF_OutParm)

uint8_t UObject::AddAdd_PreByte(uint8_t& outA)
{
	static UFunction* uFnAddAdd_PreByte = nullptr;

	if (!uFnAddAdd_PreByte)
	{
		uFnAddAdd_PreByte = UFunction::FindFunction("Function Core.Object.AddAdd_PreByte");
	}

	UObject_execAddAdd_PreByte_Params AddAdd_PreByte_Params;
	memset(&AddAdd_PreByte_Params, 0, sizeof(AddAdd_PreByte_Params));

	if (!uFnAddAdd_PreByte)
	{
		return static_cast<uint8_t>(AddAdd_PreByte_Params.ReturnValue);
	}
	AddAdd_PreByte_Params.A = static_cast<uint8_t>(outA);

	uint16_t nativeIndex = uFnAddAdd_PreByte->iNative;
	uFnAddAdd_PreByte->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnAddAdd_PreByte, &AddAdd_PreByte_Params, nullptr);
	uFnAddAdd_PreByte->iNative = nativeIndex;

	outA = static_cast<uint8_t>(AddAdd_PreByte_Params.A);

	return static_cast<uint8_t>(AddAdd_PreByte_Params.ReturnValue);
}

// Function Core.Object.SubtractEqual_ByteByte
// [0x00423401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public | FUNC_HasOutParms) (iNative[136])
// Parameter Info:
// uint8_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// uint8_t                        B                              (CPF_Parm)
// uint8_t                        A                              (CPF_Parm | CPF_OutParm)

uint8_t UObject::SubtractEqual_ByteByte(uint8_t B, uint8_t& outA)
{
	static UFunction* uFnSubtractEqual_ByteByte = nullptr;

	if (!uFnSubtractEqual_ByteByte)
	{
		uFnSubtractEqual_ByteByte = UFunction::FindFunction("Function Core.Object.SubtractEqual_ByteByte");
	}

	UObject_execSubtractEqual_ByteByte_Params SubtractEqual_ByteByte_Params;
	memset(&SubtractEqual_ByteByte_Params, 0, sizeof(SubtractEqual_ByteByte_Params));

	if (!uFnSubtractEqual_ByteByte)
	{
		return static_cast<uint8_t>(SubtractEqual_ByteByte_Params.ReturnValue);
	}
	SubtractEqual_ByteByte_Params.B = static_cast<uint8_t>(B);
	SubtractEqual_ByteByte_Params.A = static_cast<uint8_t>(outA);

	uint16_t nativeIndex = uFnSubtractEqual_ByteByte->iNative;
	uFnSubtractEqual_ByteByte->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnSubtractEqual_ByteByte, &SubtractEqual_ByteByte_Params, nullptr);
	uFnSubtractEqual_ByteByte->iNative = nativeIndex;

	outA = static_cast<uint8_t>(SubtractEqual_ByteByte_Params.A);

	return static_cast<uint8_t>(SubtractEqual_ByteByte_Params.ReturnValue);
}

// Function Core.Object.AddEqual_ByteByte
// [0x00423401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public | FUNC_HasOutParms) (iNative[135])
// Parameter Info:
// uint8_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// uint8_t                        B                              (CPF_Parm)
// uint8_t                        A                              (CPF_Parm | CPF_OutParm)

uint8_t UObject::AddEqual_ByteByte(uint8_t B, uint8_t& outA)
{
	static UFunction* uFnAddEqual_ByteByte = nullptr;

	if (!uFnAddEqual_ByteByte)
	{
		uFnAddEqual_ByteByte = UFunction::FindFunction("Function Core.Object.AddEqual_ByteByte");
	}

	UObject_execAddEqual_ByteByte_Params AddEqual_ByteByte_Params;
	memset(&AddEqual_ByteByte_Params, 0, sizeof(AddEqual_ByteByte_Params));

	if (!uFnAddEqual_ByteByte)
	{
		return static_cast<uint8_t>(AddEqual_ByteByte_Params.ReturnValue);
	}
	AddEqual_ByteByte_Params.B = static_cast<uint8_t>(B);
	AddEqual_ByteByte_Params.A = static_cast<uint8_t>(outA);

	uint16_t nativeIndex = uFnAddEqual_ByteByte->iNative;
	uFnAddEqual_ByteByte->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnAddEqual_ByteByte, &AddEqual_ByteByte_Params, nullptr);
	uFnAddEqual_ByteByte->iNative = nativeIndex;

	outA = static_cast<uint8_t>(AddEqual_ByteByte_Params.A);

	return static_cast<uint8_t>(AddEqual_ByteByte_Params.ReturnValue);
}

// Function Core.Object.DivideEqual_ByteByte
// [0x00423401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public | FUNC_HasOutParms) (iNative[134])
// Parameter Info:
// uint8_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// uint8_t                        B                              (CPF_Parm)
// uint8_t                        A                              (CPF_Parm | CPF_OutParm)

uint8_t UObject::DivideEqual_ByteByte(uint8_t B, uint8_t& outA)
{
	static UFunction* uFnDivideEqual_ByteByte = nullptr;

	if (!uFnDivideEqual_ByteByte)
	{
		uFnDivideEqual_ByteByte = UFunction::FindFunction("Function Core.Object.DivideEqual_ByteByte");
	}

	UObject_execDivideEqual_ByteByte_Params DivideEqual_ByteByte_Params;
	memset(&DivideEqual_ByteByte_Params, 0, sizeof(DivideEqual_ByteByte_Params));

	if (!uFnDivideEqual_ByteByte)
	{
		return static_cast<uint8_t>(DivideEqual_ByteByte_Params.ReturnValue);
	}
	DivideEqual_ByteByte_Params.B = static_cast<uint8_t>(B);
	DivideEqual_ByteByte_Params.A = static_cast<uint8_t>(outA);

	uint16_t nativeIndex = uFnDivideEqual_ByteByte->iNative;
	uFnDivideEqual_ByteByte->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnDivideEqual_ByteByte, &DivideEqual_ByteByte_Params, nullptr);
	uFnDivideEqual_ByteByte->iNative = nativeIndex;

	outA = static_cast<uint8_t>(DivideEqual_ByteByte_Params.A);

	return static_cast<uint8_t>(DivideEqual_ByteByte_Params.ReturnValue);
}

// Function Core.Object.MultiplyEqual_ByteFloat
// [0x00423401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public | FUNC_HasOutParms) (iNative[198])
// Parameter Info:
// uint8_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          B                              (CPF_Parm)
// uint8_t                        A                              (CPF_Parm | CPF_OutParm)

uint8_t UObject::MultiplyEqual_ByteFloat(float B, uint8_t& outA)
{
	static UFunction* uFnMultiplyEqual_ByteFloat = nullptr;

	if (!uFnMultiplyEqual_ByteFloat)
	{
		uFnMultiplyEqual_ByteFloat = UFunction::FindFunction("Function Core.Object.MultiplyEqual_ByteFloat");
	}

	UObject_execMultiplyEqual_ByteFloat_Params MultiplyEqual_ByteFloat_Params;
	memset(&MultiplyEqual_ByteFloat_Params, 0, sizeof(MultiplyEqual_ByteFloat_Params));

	if (!uFnMultiplyEqual_ByteFloat)
	{
		return static_cast<uint8_t>(MultiplyEqual_ByteFloat_Params.ReturnValue);
	}
	MultiplyEqual_ByteFloat_Params.B = B;
	MultiplyEqual_ByteFloat_Params.A = static_cast<uint8_t>(outA);

	uint16_t nativeIndex = uFnMultiplyEqual_ByteFloat->iNative;
	uFnMultiplyEqual_ByteFloat->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnMultiplyEqual_ByteFloat, &MultiplyEqual_ByteFloat_Params, nullptr);
	uFnMultiplyEqual_ByteFloat->iNative = nativeIndex;

	outA = static_cast<uint8_t>(MultiplyEqual_ByteFloat_Params.A);

	return static_cast<uint8_t>(MultiplyEqual_ByteFloat_Params.ReturnValue);
}

// Function Core.Object.MultiplyEqual_ByteByte
// [0x00423401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public | FUNC_HasOutParms) (iNative[133])
// Parameter Info:
// uint8_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// uint8_t                        B                              (CPF_Parm)
// uint8_t                        A                              (CPF_Parm | CPF_OutParm)

uint8_t UObject::MultiplyEqual_ByteByte(uint8_t B, uint8_t& outA)
{
	static UFunction* uFnMultiplyEqual_ByteByte = nullptr;

	if (!uFnMultiplyEqual_ByteByte)
	{
		uFnMultiplyEqual_ByteByte = UFunction::FindFunction("Function Core.Object.MultiplyEqual_ByteByte");
	}

	UObject_execMultiplyEqual_ByteByte_Params MultiplyEqual_ByteByte_Params;
	memset(&MultiplyEqual_ByteByte_Params, 0, sizeof(MultiplyEqual_ByteByte_Params));

	if (!uFnMultiplyEqual_ByteByte)
	{
		return static_cast<uint8_t>(MultiplyEqual_ByteByte_Params.ReturnValue);
	}
	MultiplyEqual_ByteByte_Params.B = static_cast<uint8_t>(B);
	MultiplyEqual_ByteByte_Params.A = static_cast<uint8_t>(outA);

	uint16_t nativeIndex = uFnMultiplyEqual_ByteByte->iNative;
	uFnMultiplyEqual_ByteByte->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnMultiplyEqual_ByteByte, &MultiplyEqual_ByteByte_Params, nullptr);
	uFnMultiplyEqual_ByteByte->iNative = nativeIndex;

	outA = static_cast<uint8_t>(MultiplyEqual_ByteByte_Params.A);

	return static_cast<uint8_t>(MultiplyEqual_ByteByte_Params.ReturnValue);
}

// Function Core.Object.OrOr_BoolBool
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[132])
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// uint32_t                       A                              (CPF_Parm)
// uint32_t                       B                              (CPF_Parm | CPF_SkipParm)

bool UObject::OrOr_BoolBool(bool A, bool B)
{
	static UFunction* uFnOrOr_BoolBool = nullptr;

	if (!uFnOrOr_BoolBool)
	{
		uFnOrOr_BoolBool = UFunction::FindFunction("Function Core.Object.OrOr_BoolBool");
	}

	UObject_execOrOr_BoolBool_Params OrOr_BoolBool_Params;
	memset(&OrOr_BoolBool_Params, 0, sizeof(OrOr_BoolBool_Params));

	if (!uFnOrOr_BoolBool)
	{
		return OrOr_BoolBool_Params.ReturnValue;
	}
	OrOr_BoolBool_Params.A = A;
	OrOr_BoolBool_Params.B = B;

	uint16_t nativeIndex = uFnOrOr_BoolBool->iNative;
	uFnOrOr_BoolBool->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnOrOr_BoolBool, &OrOr_BoolBool_Params, nullptr);
	uFnOrOr_BoolBool->iNative = nativeIndex;

	return OrOr_BoolBool_Params.ReturnValue;
}

// Function Core.Object.XorXor_BoolBool
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[131])
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// uint32_t                       A                              (CPF_Parm)
// uint32_t                       B                              (CPF_Parm)

bool UObject::XorXor_BoolBool(bool A, bool B)
{
	static UFunction* uFnXorXor_BoolBool = nullptr;

	if (!uFnXorXor_BoolBool)
	{
		uFnXorXor_BoolBool = UFunction::FindFunction("Function Core.Object.XorXor_BoolBool");
	}

	UObject_execXorXor_BoolBool_Params XorXor_BoolBool_Params;
	memset(&XorXor_BoolBool_Params, 0, sizeof(XorXor_BoolBool_Params));

	if (!uFnXorXor_BoolBool)
	{
		return XorXor_BoolBool_Params.ReturnValue;
	}
	XorXor_BoolBool_Params.A = A;
	XorXor_BoolBool_Params.B = B;

	uint16_t nativeIndex = uFnXorXor_BoolBool->iNative;
	uFnXorXor_BoolBool->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnXorXor_BoolBool, &XorXor_BoolBool_Params, nullptr);
	uFnXorXor_BoolBool->iNative = nativeIndex;

	return XorXor_BoolBool_Params.ReturnValue;
}

// Function Core.Object.AndAnd_BoolBool
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[130])
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// uint32_t                       A                              (CPF_Parm)
// uint32_t                       B                              (CPF_Parm | CPF_SkipParm)

bool UObject::AndAnd_BoolBool(bool A, bool B)
{
	static UFunction* uFnAndAnd_BoolBool = nullptr;

	if (!uFnAndAnd_BoolBool)
	{
		uFnAndAnd_BoolBool = UFunction::FindFunction("Function Core.Object.AndAnd_BoolBool");
	}

	UObject_execAndAnd_BoolBool_Params AndAnd_BoolBool_Params;
	memset(&AndAnd_BoolBool_Params, 0, sizeof(AndAnd_BoolBool_Params));

	if (!uFnAndAnd_BoolBool)
	{
		return AndAnd_BoolBool_Params.ReturnValue;
	}
	AndAnd_BoolBool_Params.A = A;
	AndAnd_BoolBool_Params.B = B;

	uint16_t nativeIndex = uFnAndAnd_BoolBool->iNative;
	uFnAndAnd_BoolBool->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnAndAnd_BoolBool, &AndAnd_BoolBool_Params, nullptr);
	uFnAndAnd_BoolBool->iNative = nativeIndex;

	return AndAnd_BoolBool_Params.ReturnValue;
}

// Function Core.Object.NotEqual_BoolBool
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[243])
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// uint32_t                       A                              (CPF_Parm)
// uint32_t                       B                              (CPF_Parm)

bool UObject::NotEqual_BoolBool(bool A, bool B)
{
	static UFunction* uFnNotEqual_BoolBool = nullptr;

	if (!uFnNotEqual_BoolBool)
	{
		uFnNotEqual_BoolBool = UFunction::FindFunction("Function Core.Object.NotEqual_BoolBool");
	}

	UObject_execNotEqual_BoolBool_Params NotEqual_BoolBool_Params;
	memset(&NotEqual_BoolBool_Params, 0, sizeof(NotEqual_BoolBool_Params));

	if (!uFnNotEqual_BoolBool)
	{
		return NotEqual_BoolBool_Params.ReturnValue;
	}
	NotEqual_BoolBool_Params.A = A;
	NotEqual_BoolBool_Params.B = B;

	uint16_t nativeIndex = uFnNotEqual_BoolBool->iNative;
	uFnNotEqual_BoolBool->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnNotEqual_BoolBool, &NotEqual_BoolBool_Params, nullptr);
	uFnNotEqual_BoolBool->iNative = nativeIndex;

	return NotEqual_BoolBool_Params.ReturnValue;
}

// Function Core.Object.EqualEqual_BoolBool
// [0x00023401] (FUNC_Final | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[242])
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// uint32_t                       A                              (CPF_Parm)
// uint32_t                       B                              (CPF_Parm)

bool UObject::EqualEqual_BoolBool(bool A, bool B)
{
	static UFunction* uFnEqualEqual_BoolBool = nullptr;

	if (!uFnEqualEqual_BoolBool)
	{
		uFnEqualEqual_BoolBool = UFunction::FindFunction("Function Core.Object.EqualEqual_BoolBool");
	}

	UObject_execEqualEqual_BoolBool_Params EqualEqual_BoolBool_Params;
	memset(&EqualEqual_BoolBool_Params, 0, sizeof(EqualEqual_BoolBool_Params));

	if (!uFnEqualEqual_BoolBool)
	{
		return EqualEqual_BoolBool_Params.ReturnValue;
	}
	EqualEqual_BoolBool_Params.A = A;
	EqualEqual_BoolBool_Params.B = B;

	uint16_t nativeIndex = uFnEqualEqual_BoolBool->iNative;
	uFnEqualEqual_BoolBool->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnEqualEqual_BoolBool, &EqualEqual_BoolBool_Params, nullptr);
	uFnEqualEqual_BoolBool->iNative = nativeIndex;

	return EqualEqual_BoolBool_Params.ReturnValue;
}

// Function Core.Object.Not_PreBool
// [0x00023411] (FUNC_Final | FUNC_PreOperator | FUNC_Native | FUNC_Operator | FUNC_Static | FUNC_Public) (iNative[129])
// Parameter Info:
// bool                           ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// uint32_t                       A                              (CPF_Parm)

bool UObject::Not_PreBool(bool A)
{
	static UFunction* uFnNot_PreBool = nullptr;

	if (!uFnNot_PreBool)
	{
		uFnNot_PreBool = UFunction::FindFunction("Function Core.Object.Not_PreBool");
	}

	UObject_execNot_PreBool_Params Not_PreBool_Params;
	memset(&Not_PreBool_Params, 0, sizeof(Not_PreBool_Params));

	if (!uFnNot_PreBool)
	{
		return Not_PreBool_Params.ReturnValue;
	}
	Not_PreBool_Params.A = A;

	uint16_t nativeIndex = uFnNot_PreBool->iNative;
	uFnNot_PreBool->iNative = 0;
	UObject::StaticClass()->ClassDefaultObject->ProcessEvent(uFnNot_PreBool, &Not_PreBool_Params, nullptr);
	uFnNot_PreBool->iNative = nativeIndex;

	return Not_PreBool_Params.ReturnValue;
}

class UFunction* UFunction::FindFunction(const std::string& functionFullName)
{
	static std::unordered_map<std::string, UFunction*> functionCache;

	auto cachedFunction = functionCache.find(functionFullName);

	if (cachedFunction != functionCache.end())
	{
		return cachedFunction->second;
	}

	UClass* functionClass = UFunction::StaticClass();

	if (!functionClass)
	{
		return nullptr;
	}

	bool fillCache = functionCache.empty();
	UFunction* foundFunction = nullptr;

	for (int32_t i = 0; i < UObject::GObjObjects()->size(); i++)
	{
		UObject* uObject = UObject::GObjObjects()->at(i);

		if (uObject && (uObject->Class == functionClass))
		{
			std::string objectFullName = uObject->GetFullName();

			if (fillCache)
			{
				functionCache.try_emplace(objectFullName, reinterpret_cast<UFunction*>(uObject));
			}

			if (!foundFunction && (objectFullName == functionFullName))
			{
				foundFunction = reinterpret_cast<UFunction*>(uObject);

				if (!fillCache)
				{
					break;
				}
			}
		}
	}

	if (foundFunction)
	{
		functionCache[functionFullName] = foundFunction;
	}

	return foundFunction;
}

// Function Core.DistributionVector.GetVectorValue
// [0x00024400] (FUNC_Native | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// struct FVector                 ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          F                              (CPF_OptionalParm | CPF_Parm)
// int32_t                        LastExtreme                    (CPF_OptionalParm | CPF_Parm)

struct FVector UDistributionVector::GetVectorValue(float optionalF, int32_t optionalLastExtreme)
{
	static UFunction* uFnGetVectorValue = nullptr;

	if (!uFnGetVectorValue)
	{
		uFnGetVectorValue = UFunction::FindFunction("Function Core.DistributionVector.GetVectorValue");
	}

	UDistributionVector_execGetVectorValue_Params GetVectorValue_Params;
	memset(&GetVectorValue_Params, 0, sizeof(GetVectorValue_Params));

	if (!uFnGetVectorValue)
	{
		return GetVectorValue_Params.ReturnValue;
	}
	GetVectorValue_Params.F = optionalF;
	GetVectorValue_Params.LastExtreme = optionalLastExtreme;

	uint16_t nativeIndex = uFnGetVectorValue->iNative;
	uFnGetVectorValue->iNative = 0;
	this->ProcessEvent(uFnGetVectorValue, &GetVectorValue_Params, nullptr);
	uFnGetVectorValue->iNative = nativeIndex;

	return GetVectorValue_Params.ReturnValue;
}

// Function Core.DistributionFloat.GetFloatValue
// [0x00024400] (FUNC_Native | FUNC_OptionalParm | FUNC_Public)
// Parameter Info:
// float                          ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// float                          F                              (CPF_OptionalParm | CPF_Parm)

float UDistributionFloat::GetFloatValue(float optionalF)
{
	static UFunction* uFnGetFloatValue = nullptr;

	if (!uFnGetFloatValue)
	{
		uFnGetFloatValue = UFunction::FindFunction("Function Core.DistributionFloat.GetFloatValue");
	}

	UDistributionFloat_execGetFloatValue_Params GetFloatValue_Params;
	memset(&GetFloatValue_Params, 0, sizeof(GetFloatValue_Params));

	if (!uFnGetFloatValue)
	{
		return GetFloatValue_Params.ReturnValue;
	}
	GetFloatValue_Params.F = optionalF;

	uint16_t nativeIndex = uFnGetFloatValue->iNative;
	uFnGetFloatValue->iNative = 0;
	this->ProcessEvent(uFnGetFloatValue, &GetFloatValue_Params, nullptr);
	uFnGetFloatValue->iNative = nativeIndex;

	return GetFloatValue_Params.ReturnValue;
}

// Function Core.HelpCommandlet.Main
// [0x00020C00] (FUNC_Native | FUNC_Event | FUNC_Public)
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FString                  Params                         (CPF_Parm | CPF_NeedCtorLink)

int32_t UHelpCommandlet::eventMain(const class FString& Params)
{
	static UFunction* uFnMain = nullptr;

	if (!uFnMain)
	{
		uFnMain = UFunction::FindFunction("Function Core.HelpCommandlet.Main");
	}

	UHelpCommandlet_eventMain_Params Main_Params;
	memset(&Main_Params, 0, sizeof(Main_Params));

	if (!uFnMain)
	{
		return Main_Params.ReturnValue;
	}
	memcpy_s(&Main_Params.Params, sizeof(Main_Params.Params), &Params, sizeof(Params));

	uint16_t nativeIndex = uFnMain->iNative;
	uFnMain->iNative = 0;
	this->ProcessEvent(uFnMain, &Main_Params, nullptr);
	uFnMain->iNative = nativeIndex;

	return Main_Params.ReturnValue;
}

// Function Core.Commandlet.Main
// [0x00020C00] (FUNC_Native | FUNC_Event | FUNC_Public)
// Parameter Info:
// int32_t                        ReturnValue                    (CPF_Parm | CPF_OutParm | CPF_ReturnParm)
// class FString                  Params                         (CPF_Parm | CPF_NeedCtorLink)

int32_t UCommandlet::eventMain(const class FString& Params)
{
	static UFunction* uFnMain = nullptr;

	if (!uFnMain)
	{
		uFnMain = UFunction::FindFunction("Function Core.Commandlet.Main");
	}

	UCommandlet_eventMain_Params Main_Params;
	memset(&Main_Params, 0, sizeof(Main_Params));

	if (!uFnMain)
	{
		return Main_Params.ReturnValue;
	}
	memcpy_s(&Main_Params.Params, sizeof(Main_Params.Params), &Params, sizeof(Params));

	uint16_t nativeIndex = uFnMain->iNative;
	uFnMain->iNative = 0;
	this->ProcessEvent(uFnMain, &Main_Params, nullptr);
	uFnMain->iNative = nativeIndex;

	return Main_Params.ReturnValue;
}

/*
# ========================================================================================= #
#
# ========================================================================================= #
*/

#ifdef _MSC_VER
#pragma pack(pop)
#endif
