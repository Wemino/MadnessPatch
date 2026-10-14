/*
#############################################################################################
# Alice2 (ASDK) SDK 1.0.0.0
# Generated with the CodeRedGenerator v1.2.0
# ========================================================================================= #
# File: Core_classes.hpp
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

#define CONST_InvAspectRatio16x9                                    0.56249
#define CONST_InvAspectRatio5x4                                     0.8
#define CONST_InvAspectRatio4x3                                     0.75
#define CONST_AspectRatio16x9                                       1.77778
#define CONST_AspectRatio5x4                                        1.25
#define CONST_AspectRatio4x3                                        1.33333
#define CONST_INDEX_NONE                                            -1
#define CONST_RadToUnrRot                                           10430.3783504704527
#define CONST_UnrRotToRad                                           0.00009587379924285
#define CONST_DegToRad                                              0.017453292519943296
#define CONST_RadToDeg                                              57.295779513082321600
#define CONST_Pi                                                    3.1415926535897932
#define CONST_MaxInt                                                0x7fffffff

/*
# ========================================================================================= #
# Enums
# ========================================================================================= #
*/

// Enum Core.Object.EDebugBreakType
enum class EDebugBreakType : uint8_t
{
	DEBUGGER_NativeOnly                                = 0,
	DEBUGGER_ScriptOnly                                = 1,
	DEBUGGER_Both                                      = 2,
	DEBUGGER_END                                       = 3
};

// Enum Core.Object.EAutomatedRunResult
enum class EAutomatedRunResult : uint8_t
{
	ARR_Unknown                                        = 0,
	ARR_OOM                                            = 1,
	ARR_Passed                                         = 2,
	ARR_END                                            = 3
};

// Enum Core.Object.EInputEvent
enum class EInputEvent : uint8_t
{
	IE_Pressed                                         = 0,
	IE_Released                                        = 1,
	IE_Repeat                                          = 2,
	IE_DoubleClick                                     = 3,
	IE_Axis                                            = 4,
	IE_END                                             = 5
};

// Enum Core.Object.EInterpCurveMode
enum class EInterpCurveMode : uint8_t
{
	CIM_Linear                                         = 0,
	CIM_CurveAuto                                      = 1,
	CIM_Constant                                       = 2,
	CIM_CurveUser                                      = 3,
	CIM_CurveBreak                                     = 4,
	CIM_CurveAutoClamped                               = 5,
	CIM_END                                            = 6
};

// Enum Core.Object.EInterpMethodType
enum class EInterpMethodType : uint8_t
{
	IMT_UseFixedTangentEvalAndNewAutoTangents          = 0,
	IMT_UseFixedTangentEval                            = 1,
	IMT_UseBrokenTangentEval                           = 2,
	IMT_END                                            = 3
};

// Enum Core.Object.EAxis
enum class EAxis : uint8_t
{
	AXIS_NONE                                          = 0,
	AXIS_X                                             = 1,
	AXIS_Y                                             = 2,
	AXIS_BLANK                                         = 3,
	AXIS_Z                                             = 4,
	AXIS_END                                           = 5
};

// Enum Core.Object.ETickingGroup
enum class ETickingGroup : uint8_t
{
	TG_PreAsyncWork                                    = 0,
	TG_DuringAsyncWork                                 = 1,
	TG_PostAsyncWork                                   = 2,
	TG_PostUpdateWork                                  = 3,
	TG_END                                             = 4
};

// Enum Core.Object.AlphaBlendType
enum class EAlphaBlendType : uint8_t
{
	ABT_Linear                                         = 0,
	ABT_Cubic                                          = 1,
	ABT_Sinusoidal                                     = 2,
	ABT_EaseInOutExponent2                             = 3,
	ABT_EaseInOutExponent3                             = 4,
	ABT_EaseInOutExponent4                             = 5,
	ABT_EaseInOutExponent5                             = 6,
	ABT_END                                            = 7
};

// Enum Core.DistributionVector.EDistributionVectorLockFlags
enum class EDistributionVectorLockFlags : uint8_t
{
	EDVLF_None                                         = 0,
	EDVLF_XY                                           = 1,
	EDVLF_XZ                                           = 2,
	EDVLF_YZ                                           = 3,
	EDVLF_XYZ                                          = 4,
	EDVLF_END                                          = 5
};

// Enum Core.DistributionVector.EDistributionVectorMirrorFlags
enum class EDistributionVectorMirrorFlags : uint8_t
{
	EDVMF_Same                                         = 0,
	EDVMF_Different                                    = 1,
	EDVMF_Mirror                                       = 2,
	EDVMF_END                                          = 3
};


/*
# ========================================================================================= #
# Classes
# ========================================================================================= #
*/

// Class Core.Object
// (Custom Override)
// Class Core.Object
// 0x003C
class UObject
{
public:
    struct FPointer                     VfTableObject;          // 0x0000 (0x04)
    int32_t                             ObjectInternalInteger;  // 0x0004 (0x04)
    uint64_t                            ObjectFlags;            // 0x0008 (0x08)
    struct FPointer                     HashNext;               // 0x0010 (0x04)
    struct FPointer                     HashOuterNext;          // 0x0014 (0x04)
    struct FPointer                     StateFrame;             // 0x0018 (0x04)
    class UObject*                      Linker;                 // 0x001C (0x04)
    struct FPointer                     LinkerIndex;            // 0x0020 (0x04)
    int32_t                             NetIndex;               // 0x0024 (0x04)
    class UObject*                      Outer;                  // 0x0028 (0x04)
    class FName                         Name;                   // 0x002C (0x08)
    class UClass*                       Class;                  // 0x0034 (0x04)
    class UObject*                      ObjectArchetype;        // 0x0038 (0x04)

public:
    static UClass* StaticClass()
    {
        static UClass* uClassPointer = nullptr;
        if (!uClassPointer)
        {
            uClassPointer = UObject::FindClass("Class Core.Object");
        }
        return uClassPointer;
    };

    static TArray<UObject*>* GObjObjects();
    static UClass* FindClass(const std::string& classFullName);

    template<typename T>
    static T* FindObject(const std::string& objectFullName)
    {
        for (UObject* uObject : *UObject::GObjObjects())
        {
            if (uObject && uObject->IsA<T>())
            {
                if (uObject->GetFullName() == objectFullName)
                {
                    return static_cast<T*>(uObject);
                }
            }
        }
        return nullptr;
    }

    bool IsA(class UClass* uClass);
    bool IsA(int32_t objInternalInteger);

    template<typename T>
    bool IsA()
    {
        return IsA(T::StaticClass());
    }

    std::string GetName();
    std::string GetNameCPP();
    std::string GetFullName();
    class UObject* GetPackageObj();

    // Returns true for a class default object (the "Default__" template instances).
    bool IsDefaultObject();

    // Returns the first live instance of T (skips class default objects by default).
    template<typename T>
    static T* FindFirstOf(bool skipDefaultObjects = true)
    {
        for (int32_t i = 0; i < UObject::GObjObjects()->size(); i++)
        {
            UObject* uObject = UObject::GObjObjects()->at(i);

            if (uObject && uObject->IsA<T>() && (!skipDefaultObjects || !uObject->IsDefaultObject()))
            {
                return static_cast<T*>(uObject);
            }
        }

        return nullptr;
    }

    // Returns every live instance of T (skips class default objects by default).
    template<typename T>
    static std::vector<T*> FindAllOf(bool skipDefaultObjects = true)
    {
        std::vector<T*> foundInstances;

        for (int32_t i = 0; i < UObject::GObjObjects()->size(); i++)
        {
            UObject* uObject = UObject::GObjObjects()->at(i);

            if (uObject && uObject->IsA<T>() && (!skipDefaultObjects || !uObject->IsDefaultObject()))
            {
                foundInstances.push_back(static_cast<T*>(uObject));
            }
        }

        return foundInstances;
    }

	int32_t GetBuildChangelistNumber();
	int32_t GetEngineVersion();
	void GetSystemTime(int32_t& outYear, int32_t& outMonth, int32_t& outDayOfWeek, int32_t& outDay, int32_t& outHour, int32_t& outMin, int32_t& outSec, int32_t& outMSec);
	class FString TimeStamp();
	struct FVector TransformVectorByRotation(const struct FRotator& SourceRotation, const struct FVector& SourceVector, bool optionalBInverse);
	class FName GetPackageName();
	bool IsPendingKill();
	float ByteToFloat(uint8_t inputByte, bool optionalBSigned);
	uint8_t FloatToByte(float inputFloat, bool optionalBSigned);
	static float UnwindHeading(float A);
	static float FindDeltaAngle(float A1, float A2);
	static float GetHeadingAngle(const struct FVector& Dir);
	static void GetAngularDegreesFromRadians(struct FVector2D& outOutFOV);
	static void GetAngularFromDotDist(const struct FVector2D& DotDist, struct FVector2D& outOutAngDist);
	static bool GetAngularDistance(const struct FVector& Direction, const struct FVector& AxisX, const struct FVector& AxisY, const struct FVector& AxisZ, struct FVector2D& outOutAngularDist);
	static bool GetDotDistance(const struct FVector& Direction, const struct FVector& AxisX, const struct FVector& AxisY, const struct FVector& AxisZ, struct FVector2D& outOutDotDist);
	static struct FVector PointProjectToPlane(const struct FVector& Point, const struct FVector& A, const struct FVector& B, const struct FVector& C);
	float PointDistToPlane(const struct FVector& Point, const struct FRotator& Orientation, const struct FVector& Origin, struct FVector& optionalOutOut_ClosestPoint);
	float PointDistToSegment(const struct FVector& Point, const struct FVector& StartPoint, const struct FVector& EndPoint, struct FVector& optionalOutOutClosestPoint);
	float PointDistToLine(const struct FVector& Point, const struct FVector& Line, const struct FVector& Origin, struct FVector& optionalOutOutClosestPoint);
	static bool GetPerObjectConfigSections(class UClass* SearchClass, class UObject* optionalObjectOuter, int32_t optionalMaxResults, class TArray<class FString>& outOut_SectionNames);
	static void StaticSaveConfig();
	void SaveConfig();
	static class UObject* FindObject(const class FString& ObjectName, class UClass* ObjectClass);
	static class UObject* DynamicLoadObject(const class FString& ObjectName, class UClass* ObjectClass, bool optionalMayFail);
	static class FName GetEnum(class UObject* E, int32_t I);
	void Disable(const class FName& ProbeFunc);
	void Enable(const class FName& ProbeFunc);
	void eventContinuedState();
	void eventPausedState();
	void eventPoppedState();
	void eventPushedState();
	void eventEndState(const class FName& NextStateName);
	void eventBeginState(const class FName& PreviousStateName);
	void DumpStateStack();
	void PopState(bool optionalBPopAll);
	void PushState(const class FName& NewState, const class FName& optionalNewLabel);
	class FName GetStateName();
	bool IsChildState(const class FName& TestState, const class FName& TestParentState);
	bool IsInState(const class FName& TestState, bool optionalBTestStateStack);
	void GotoState(const class FName& optionalNewState, const class FName& optionalLabel, bool optionalBForceEvents, bool optionalBKeepStack);
	static bool IsUTracing();
	static void SetUTracing(bool bShouldUTrace);
	static class FName GetFuncName();
	static void DebugBreak(int32_t optionalUserFlags, EDebugBreakType optionalDebuggerType);
	static void ScriptTrace();
	static class FString ParseLocalizedPropertyPath(const class FString& PathName);
	static class FString Localize(const class FString& SectionName, const class FString& KeyName, const class FString& PackageName);
	static void WarnInternal(const class FString& S);
	static void LogInternal(const class FString& S, const class FName& optionalTag);
	static struct FLinearColor Subtract_LinearColorLinearColor(const struct FLinearColor& A, const struct FLinearColor& B);
	static struct FLinearColor Multiply_LinearColorFloat(const struct FLinearColor& LC, float Mult);
	static struct FLinearColor ColorToLinearColor(const struct FColor& OldColor);
	static struct FLinearColor MakeLinearColor(float R, float G, float B, float A);
	static struct FColor LerpColor(const struct FColor& A, const struct FColor& B, float Alpha);
	static struct FColor MakeColor(uint8_t R, uint8_t G, uint8_t B, uint8_t optionalA);
	static struct FColor Add_ColorColor(const struct FColor& A, const struct FColor& B);
	static struct FColor Multiply_ColorFloat(const struct FColor& A, float B);
	static struct FColor Multiply_FloatColor(float A, const struct FColor& B);
	static struct FColor Subtract_ColorColor(const struct FColor& A, const struct FColor& B);
	struct FVector2D EvalInterpCurveVector2D(const struct FInterpCurveVector2D& Vector2DCurve, float InVal);
	struct FVector EvalInterpCurveVector(const struct FInterpCurveVector& VectorCurve, float InVal);
	float EvalInterpCurveFloat(const struct FInterpCurveFloat& FloatCurve, float InVal);
	static struct FVector2D vect2d(float InX, float InY);
	static float GetMappedRangeValue(const struct FVector2D& InputRange, const struct FVector2D& OutputRange, float Value);
	static float GetRangePctByValue(const struct FVector2D& Range, float Value);
	static float GetRangeValueByPct(const struct FVector2D& Range, float Pct);
	static struct FVector2D Subtract_Vector2DVector2D(const struct FVector2D& A, const struct FVector2D& B);
	static struct FVector2D Add_Vector2DVector2D(const struct FVector2D& A, const struct FVector2D& B);
	static struct FQuat Subtract_QuatQuat(const struct FQuat& A, const struct FQuat& B);
	static struct FQuat Add_QuatQuat(const struct FQuat& A, const struct FQuat& B);
	static struct FQuat QuatSlerp(const struct FQuat& A, const struct FQuat& B, float Alpha, bool optionalBShortestPath);
	static struct FRotator QuatToRotator(const struct FQuat& A);
	static struct FQuat QuatFromRotator(const struct FRotator& A);
	static struct FQuat QuatFromAxisAndAngle(const struct FVector& Axis, float Angle);
	static struct FQuat QuatFindBetween(const struct FVector& A, const struct FVector& B);
	static struct FVector QuatRotateVector(const struct FQuat& A, const struct FVector& B);
	static struct FQuat QuatInvert(const struct FQuat& A);
	static float QuatDot(const struct FQuat& A, const struct FQuat& B);
	static struct FQuat QuatProduct(const struct FQuat& A, const struct FQuat& B);
	static struct FVector MatrixGetAxis(const struct FMatrix& TM, EAxis Axis);
	static struct FVector MatrixGetOrigin(const struct FMatrix& TM);
	static struct FRotator MatrixGetRotator(const struct FMatrix& TM);
	static struct FMatrix MakeRotationMatrix(const struct FRotator& Rotation);
	static struct FMatrix MakeRotationTranslationMatrix(const struct FVector& Translation, const struct FRotator& Rotation);
	static struct FVector InverseTransformNormal(const struct FMatrix& TM, const struct FVector& A);
	static struct FVector TransformNormal(const struct FMatrix& TM, const struct FVector& A);
	static struct FVector InverseTransformVector(const struct FMatrix& TM, const struct FVector& A);
	static struct FVector TransformVector(const struct FMatrix& TM, const struct FVector& A);
	static struct FMatrix Multiply_MatrixMatrix(const struct FMatrix& A, const struct FMatrix& B);
	static bool NotEqual_NameName(const class FName& A, const class FName& B);
	static bool EqualEqual_NameName(const class FName& A, const class FName& B);
	bool IsA(const class FName& ClassName);
	static bool ClassIsChildOf(class UClass* TestClass, class UClass* ParentClass);
	static bool NotEqual_InterfaceInterface(class UInterface* A, class UInterface* B);
	static bool EqualEqual_InterfaceInterface(class UInterface* A, class UInterface* B);
	static bool NotEqual_ObjectObject(class UObject* A, class UObject* B);
	static bool EqualEqual_ObjectObject(class UObject* A, class UObject* B);
	static class FString PathName(class UObject* CheckObject);
	static class TArray<class FString> SplitString(const class FString& Source, const class FString& optionalDelimiter, bool optionalBCullEmpty);
	static void ParseStringIntoArray(const class FString& BaseString, const class FString& delim, bool bCullEmpty, class TArray<class FString>& outPieces);
	static void JoinArray(const class TArray<class FString>& StringArray, const class FString& optionalDelim, bool optionalBIgnoreBlanks, class FString& outOut_Result);
	static class FString GetRightMost(const class FString& Text);
	static class FString Split(const class FString& Text, const class FString& SplitStr, bool optionalBOmitSplitStr);
	static class FString Repl(const class FString& Src, const class FString& Match, const class FString& With, bool optionalBCaseSensitive);
	static int32_t Asc(const class FString& S);
	static class FString Chr(int32_t I);
	static class FString Locs(const class FString& S);
	static class FString Caps(const class FString& S);
	static class FString Right(const class FString& S, int32_t I);
	static class FString Left(const class FString& S, int32_t I);
	static class FString Mid(const class FString& S, int32_t I, int32_t optionalJ);
	static int32_t InStr(const class FString& S, const class FString& T, bool optionalBSearchFromRight, bool optionalBIgnoreCase, int32_t optionalStartPos);
	static int32_t Len(const class FString& S);
	static class FString SubtractEqual_StrStr(const class FString& B, class FString& outA);
	static class FString AtEqual_StrStr(const class FString& B, class FString& outA);
	static class FString ConcatEqual_StrStr(const class FString& B, class FString& outA);
	static bool ComplementEqual_StrStr(const class FString& A, const class FString& B);
	static bool NotEqual_StrStr(const class FString& A, const class FString& B);
	static bool EqualEqual_StrStr(const class FString& A, const class FString& B);
	static bool GreaterEqual_StrStr(const class FString& A, const class FString& B);
	static bool LessEqual_StrStr(const class FString& A, const class FString& B);
	static bool Greater_StrStr(const class FString& A, const class FString& B);
	static bool Less_StrStr(const class FString& A, const class FString& B);
	static class FString At_StrStr(const class FString& A, const class FString& B);
	static class FString Concat_StrStr(const class FString& A, const class FString& B);
	static struct FRotator MakeRotator(int32_t Pitch, int32_t Yaw, int32_t Roll);
	static bool SClampRotAxis(float DeltaTime, int32_t ViewAxis, int32_t MaxLimit, int32_t MinLimit, float InterpolationSpeed, int32_t& outOut_DeltaViewAxis);
	static int32_t ClampRotAxisFromRange(int32_t Current, int32_t Min, int32_t Max);
	static int32_t ClampRotAxisFromBase(int32_t Current, int32_t Center, int32_t MaxDelta);
	static void ClampRotAxis(int32_t ViewAxis, int32_t MaxLimit, int32_t MinLimit, int32_t& outOut_DeltaViewAxis);
	static float RSize(const struct FRotator& R);
	static float RDiff(const struct FRotator& A, const struct FRotator& B);
	static int32_t NormalizeRotAxis(int32_t Angle);
	static struct FRotator RInterpTo(const struct FRotator& Current, const struct FRotator& Target, float DeltaTime, float InterpSpeed, bool optionalBConstantInterpSpeed);
	static struct FRotator RTransform(const struct FRotator& R, const struct FRotator& RBasis);
	static struct FRotator RSmerp(const struct FRotator& A, const struct FRotator& B, float Alpha, bool optionalBShortestPath);
	static struct FRotator RLerp(const struct FRotator& A, const struct FRotator& B, float Alpha, bool optionalBShortestPath);
	static struct FRotator Normalize(const struct FRotator& Rot);
	static struct FRotator OrthoRotation(const struct FVector& X, const struct FVector& Y, const struct FVector& Z);
	static struct FRotator RotRand(bool optionalBRoll);
	static void GetUnAxes(const struct FRotator& A, struct FVector& outX, struct FVector& outY, struct FVector& outZ);
	static void GetAxes(const struct FRotator& A, struct FVector& outX, struct FVector& outY, struct FVector& outZ);
	static bool ClockwiseFrom_IntInt(int32_t A, int32_t B);
	static struct FRotator SubtractEqual_RotatorRotator(const struct FRotator& B, struct FRotator& outA);
	static struct FRotator AddEqual_RotatorRotator(const struct FRotator& B, struct FRotator& outA);
	static struct FRotator Subtract_RotatorRotator(const struct FRotator& A, const struct FRotator& B);
	static struct FRotator Add_RotatorRotator(const struct FRotator& A, const struct FRotator& B);
	static struct FRotator DivideEqual_RotatorFloat(float B, struct FRotator& outA);
	static struct FRotator MultiplyEqual_RotatorFloat(float B, struct FRotator& outA);
	static struct FRotator Divide_RotatorFloat(const struct FRotator& A, float B);
	static struct FRotator Multiply_FloatRotator(float A, const struct FRotator& B);
	static struct FRotator Multiply_RotatorFloat(const struct FRotator& A, float B);
	static bool NotEqual_RotatorRotator(const struct FRotator& A, const struct FRotator& B);
	static bool EqualEqual_RotatorRotator(const struct FRotator& A, const struct FRotator& B);
	bool InCylinder(const struct FVector& Origin, const struct FRotator& Dir, float Width, const struct FVector& A, bool optionalBIgnoreZ);
	float NoZDot(const struct FVector& A, const struct FVector& B);
	static struct FVector ClampLength(const struct FVector& V, float MaxLength);
	static struct FVector VInterpTo(const struct FVector& Current, const struct FVector& Target, float DeltaTime, float InterpSpeed);
	static bool IsZero(const struct FVector& A);
	static struct FVector ProjectOnTo(const struct FVector& X, const struct FVector& Y);
	static struct FVector MirrorVectorByNormal(const struct FVector& InVect, const struct FVector& InNormal);
	static struct FVector VRandCone2(const struct FVector& Dir, float HorizontalConeHalfAngleRadians, float VerticalConeHalfAngleRadians);
	static struct FVector VRandCone(const struct FVector& Dir, float ConeHalfAngleRadians);
	static struct FVector VRand();
	static struct FVector VSmerp(const struct FVector& A, const struct FVector& B, float Alpha);
	static struct FVector VLerp(const struct FVector& A, const struct FVector& B, float Alpha);
	static struct FVector Normal(const struct FVector& A);
	static float VSizeSq2D(const struct FVector& A);
	static float VSizeSq(const struct FVector& A);
	static float VSize2D(const struct FVector& A);
	static float VSize(const struct FVector& A);
	static struct FVector SubtractEqual_VectorVector(const struct FVector& B, struct FVector& outA);
	static struct FVector AddEqual_VectorVector(const struct FVector& B, struct FVector& outA);
	static struct FVector DivideEqual_VectorFloat(float B, struct FVector& outA);
	static struct FVector MultiplyEqual_VectorVector(const struct FVector& B, struct FVector& outA);
	static struct FVector MultiplyEqual_VectorFloat(float B, struct FVector& outA);
	static struct FVector Cross_VectorVector(const struct FVector& A, const struct FVector& B);
	static float Dot_VectorVector(const struct FVector& A, const struct FVector& B);
	static bool NotEqual_VectorVector(const struct FVector& A, const struct FVector& B);
	static bool EqualEqual_VectorVector(const struct FVector& A, const struct FVector& B);
	static struct FVector GreaterGreater_VectorRotator(const struct FVector& A, const struct FRotator& B);
	static struct FVector LessLess_VectorRotator(const struct FVector& A, const struct FRotator& B);
	static struct FVector Subtract_VectorVector(const struct FVector& A, const struct FVector& B);
	static struct FVector Add_VectorVector(const struct FVector& A, const struct FVector& B);
	static struct FVector Divide_VectorFloat(const struct FVector& A, float B);
	static struct FVector Multiply_VectorVector(const struct FVector& A, const struct FVector& B);
	static struct FVector Multiply_FloatVector(float A, const struct FVector& B);
	static struct FVector Multiply_VectorFloat(const struct FVector& A, float B);
	static struct FVector Subtract_PreVector(const struct FVector& A);
	static float FInterpConstantTo(float Current, float Target, float DeltaTime, float InterpSpeed);
	static float FInterpTo(float Current, float Target, float DeltaTime, float InterpSpeed);
	static float FPctByRange(float Value, float InMin, float InMax);
	static float RandRange(float InMin, float InMax);
	static float FInterpEaseInOut(float A, float B, float Alpha, float Exp);
	static float FInterpEaseOut(float A, float B, float Alpha, float Exp);
	static float FInterpEaseIn(float A, float B, float Alpha, float Exp);
	static float FCubicInterp(float P0, float T0, float P1, float T1, float A);
	static int32_t FCeil(float A);
	static int32_t FFloor(float A);
	static int32_t Round(float A);
	static float Lerp(float A, float B, float Alpha);
	static float FClamp(float V, float A, float B);
	static float FMax(float A, float B);
	static float FMin(float A, float B);
	static float FRand();
	static float Square(float A);
	static float Sqrt(float A);
	static float Loge(float A);
	static float Exp(float A);
	static float Atan2(float A, float B);
	static float Atan(float A);
	static float Tan(float A);
	static float Acos(float A);
	static float Cos(float A);
	static float Asin(float A);
	static float Sin(float A);
	static float Abs(float A);
	static float SubtractEqual_FloatFloat(float B, float& outA);
	static float AddEqual_FloatFloat(float B, float& outA);
	static float DivideEqual_FloatFloat(float B, float& outA);
	static float MultiplyEqual_FloatFloat(float B, float& outA);
	static bool NotEqual_FloatFloat(float A, float B);
	static bool ComplementEqual_FloatFloat(float A, float B);
	static bool EqualEqual_FloatFloat(float A, float B);
	static bool GreaterEqual_FloatFloat(float A, float B);
	static bool LessEqual_FloatFloat(float A, float B);
	static bool Greater_FloatFloat(float A, float B);
	static bool Less_FloatFloat(float A, float B);
	static float Subtract_FloatFloat(float A, float B);
	static float Add_FloatFloat(float A, float B);
	static float Percent_FloatFloat(float A, float B);
	static float Divide_FloatFloat(float A, float B);
	static float Multiply_FloatFloat(float A, float B);
	static float MultiplyMultiply_FloatFloat(float Base, float Exp);
	static float Subtract_PreFloat(float A);
	static class FString ToHex(int32_t A);
	static int32_t Clamp(int32_t V, int32_t A, int32_t B);
	static int32_t Max(int32_t A, int32_t B);
	static int32_t Min(int32_t A, int32_t B);
	static int32_t Rand(int32_t Max);
	static int32_t SubtractSubtract_Int(int32_t& outA);
	static int32_t AddAdd_Int(int32_t& outA);
	static int32_t SubtractSubtract_PreInt(int32_t& outA);
	static int32_t AddAdd_PreInt(int32_t& outA);
	static int32_t SubtractEqual_IntInt(int32_t B, int32_t& outA);
	static int32_t AddEqual_IntInt(int32_t B, int32_t& outA);
	static int32_t DivideEqual_IntFloat(float B, int32_t& outA);
	static int32_t MultiplyEqual_IntFloat(float B, int32_t& outA);
	static int32_t Or_IntInt(int32_t A, int32_t B);
	static int32_t Xor_IntInt(int32_t A, int32_t B);
	static int32_t And_IntInt(int32_t A, int32_t B);
	static bool NotEqual_IntInt(int32_t A, int32_t B);
	static bool EqualEqual_IntInt(int32_t A, int32_t B);
	static bool GreaterEqual_IntInt(int32_t A, int32_t B);
	static bool LessEqual_IntInt(int32_t A, int32_t B);
	static bool Greater_IntInt(int32_t A, int32_t B);
	static bool Less_IntInt(int32_t A, int32_t B);
	static int32_t GreaterGreaterGreater_IntInt(int32_t A, int32_t B);
	static int32_t GreaterGreater_IntInt(int32_t A, int32_t B);
	static int32_t LessLess_IntInt(int32_t A, int32_t B);
	static int32_t Subtract_IntInt(int32_t A, int32_t B);
	static int32_t Add_IntInt(int32_t A, int32_t B);
	static int32_t Percent_IntInt(int32_t A, int32_t B);
	static int32_t Divide_IntInt(int32_t A, int32_t B);
	static int32_t Multiply_IntInt(int32_t A, int32_t B);
	static int32_t Subtract_PreInt(int32_t A);
	static int32_t Complement_PreInt(int32_t A);
	static uint8_t SubtractSubtract_Byte(uint8_t& outA);
	static uint8_t AddAdd_Byte(uint8_t& outA);
	static uint8_t SubtractSubtract_PreByte(uint8_t& outA);
	static uint8_t AddAdd_PreByte(uint8_t& outA);
	static uint8_t SubtractEqual_ByteByte(uint8_t B, uint8_t& outA);
	static uint8_t AddEqual_ByteByte(uint8_t B, uint8_t& outA);
	static uint8_t DivideEqual_ByteByte(uint8_t B, uint8_t& outA);
	static uint8_t MultiplyEqual_ByteFloat(float B, uint8_t& outA);
	static uint8_t MultiplyEqual_ByteByte(uint8_t B, uint8_t& outA);
	static bool OrOr_BoolBool(bool A, bool B);
	static bool XorXor_BoolBool(bool A, bool B);
	static bool AndAnd_BoolBool(bool A, bool B);
	static bool NotEqual_BoolBool(bool A, bool B);
	static bool EqualEqual_BoolBool(bool A, bool B);
	static bool Not_PreBool(bool A);
	void ProcessEvent(class UFunction* uFunction, void* uParams, void* uResult = nullptr);
};

// Class Core.TextBuffer
// 0x0024 (0x003C - 0x0060)
class UTextBuffer : public UObject
{
public:
	uint8_t                                            UnknownData00[0x24];                            // 0x003C (0x0024) MISSED OFFSET

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Core.TextBuffer");
		}

		return uClassPointer;
	};

};
// Class Core.Subsystem
// 0x0004 (0x003C - 0x0040)
class USubsystem : public UObject
{
public:
	struct FPointer                                    VfTable_FExec;                                 // 0x003C (0x0004) [0x0000000000801002] (CPF_Const | CPF_Native | CPF_NoExport)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Core.Subsystem");
		}

		return uClassPointer;
	};

};
// Class Core.System
// 0x00BC (0x0040 - 0x00FC)
class USystem : public USubsystem
{
public:
	int32_t                                            StaleCacheDays;                                // 0x0040 (0x0004) [0x0000000000004000] (CPF_Config)  
	int32_t                                            MaxStaleCacheSize;                             // 0x0044 (0x0004) [0x0000000000004000] (CPF_Config)  
	int32_t                                            MaxOverallCacheSize;                           // 0x0048 (0x0004) [0x0000000000004000] (CPF_Config)  
	int32_t                                            PackageSizeSoftLimit;                          // 0x004C (0x0004) [0x0000000000004000] (CPF_Config)  
	float                                              AsyncIOBandwidthLimit;                         // 0x0050 (0x0004) [0x0000000000004000] (CPF_Config)  
	class FString                                      SavePath;                                      // 0x0054 (0x000C) [0x0000000000404000] (CPF_Config | CPF_NeedCtorLink)
	class FString                                      CachePath;                                     // 0x0060 (0x000C) [0x0000000000404000] (CPF_Config | CPF_NeedCtorLink)
	class FString                                      CacheExt;                                      // 0x006C (0x000C) [0x0000000000404000] (CPF_Config | CPF_NeedCtorLink)
	class FString                                      ScreenShotPath;                                // 0x0078 (0x000C) [0x0000000000404000] (CPF_Config | CPF_NeedCtorLink)
	class TArray<class FString>                        Paths;                                         // 0x0084 (0x000C) [0x0000000000404000] (CPF_Config | CPF_NeedCtorLink)
	class TArray<class FString>                        SeekFreePCPaths;                               // 0x0090 (0x000C) [0x0000000000404000] (CPF_Config | CPF_NeedCtorLink)
	class TArray<class FString>                        ScriptPaths;                                   // 0x009C (0x000C) [0x0000000000404000] (CPF_Config | CPF_NeedCtorLink)
	class TArray<class FString>                        FRScriptPaths;                                 // 0x00A8 (0x000C) [0x0000000000404000] (CPF_Config | CPF_NeedCtorLink)
	class TArray<class FString>                        CutdownPaths;                                  // 0x00B4 (0x000C) [0x0000000000404000] (CPF_Config | CPF_NeedCtorLink)
	class TArray<class FName>                          Suppress;                                      // 0x00C0 (0x000C) [0x0000000000404000] (CPF_Config | CPF_NeedCtorLink)
	class TArray<class FString>                        Extensions;                                    // 0x00CC (0x000C) [0x0000000000404000] (CPF_Config | CPF_NeedCtorLink)
	class TArray<class FString>                        SeekFreePCExtensions;                          // 0x00D8 (0x000C) [0x0000000000404000] (CPF_Config | CPF_NeedCtorLink)
	class TArray<class FString>                        LocalizationPaths;                             // 0x00E4 (0x000C) [0x0000000000404000] (CPF_Config | CPF_NeedCtorLink)
	class FString                                      TextureFileCacheExtension;                     // 0x00F0 (0x000C) [0x0000000000404000] (CPF_Config | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Core.System");
		}

		return uClassPointer;
	};

};
// Class Core.PackageMap
// 0x0084 (0x003C - 0x00C0)
class UPackageMap : public UObject
{
public:
	uint8_t                                            UnknownData00[0x84];                            // 0x003C (0x0084) MISSED OFFSET

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Core.PackageMap");
		}

		return uClassPointer;
	};

};
// Class Core.ObjectSerializer
// 0x000C (0x003C - 0x0048)
class UObjectSerializer : public UObject
{
public:
	uint8_t                                            UnknownData00[0xC];                              // 0x003C (0x000C) MISSED OFFSET

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Core.ObjectSerializer");
		}

		return uClassPointer;
	};

};
// Class Core.ObjectRedirector
// 0x0004 (0x003C - 0x0040)
class UObjectRedirector : public UObject
{
public:
	uint8_t                                            UnknownData00[0x4];                              // 0x003C (0x0004) MISSED OFFSET

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Core.ObjectRedirector");
		}

		return uClassPointer;
	};

};
// Class Core.MetaData
// 0x003C (0x003C - 0x0078)
class UMetaData : public UObject
{
public:
	uint8_t                                            UnknownData00[0x3C];                            // 0x003C (0x003C) MISSED OFFSET

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Core.MetaData");
		}

		return uClassPointer;
	};

};
// Class Core.Linker
// 0x0110 (0x003C - 0x014C)
class ULinker : public UObject
{
public:
	uint8_t                                            UnknownData00[0x110];                          // 0x003C (0x0110) MISSED OFFSET

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Core.Linker");
		}

		return uClassPointer;
	};

};
// Class Core.LinkerSave
// 0x00A0 (0x014C - 0x01EC)
class ULinkerSave : public ULinker
{
public:
	uint8_t                                            UnknownData00[0xA0];                            // 0x014C (0x00A0) MISSED OFFSET

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Core.LinkerSave");
		}

		return uClassPointer;
	};

};
// Class Core.LinkerLoad
// 0x05B8 (0x014C - 0x0704)
class ULinkerLoad : public ULinker
{
public:
	uint8_t                                            UnknownData00[0x5B8];                          // 0x014C (0x05B8) MISSED OFFSET

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Core.LinkerLoad");
		}

		return uClassPointer;
	};

};
// Class Core.Interface
// 0x0000 (0x003C - 0x003C)
class UInterface : public UObject
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Core.Interface");
		}

		return uClassPointer;
	};

};
// Class Core.Field
// (Custom Override)
// Class Core.Field
// 0x0008 (0x003C - 0x0044)
class UField : public UObject
{
public:
    class UField*                       SuperField;             // 0x003C (0x04)
    class UField*                       Next;                   // 0x0040 (0x04)

public:
    static UClass* StaticClass()
    {
        static UClass* uClassPointer = nullptr;
        if (!uClassPointer)
        {
            uClassPointer = UObject::FindClass("Class Core.Field");
        }
        return uClassPointer;
    };
};

// Class Core.Struct
// (Custom Override)
// Class Core.Struct
// 0x004C (0x0044 - 0x0090)
class UStruct : public UField
{
public:
    class UTextBuffer*                  ScriptText;             // 0x0044 (0x04)
    class UTextBuffer*                  CppText;                // 0x0048 (0x04)
    class UField*                       Children;               // 0x004C (0x04)
    int32_t                             PropertySize;           // 0x0050 (0x04)
    TArray<uint8_t>                     Script;                 // 0x0054 (0x0C)
    int32_t                             TextPos;                // 0x0060 (0x04)
    int32_t                             Line;                   // 0x0064 (0x04)
    int32_t                             MinAlignment;           // 0x0068 (0x04)
    class UProperty*                    RefLink;                // 0x006C (0x04)
    class UProperty*                    PropertyLink;           // 0x0070 (0x04)
    class UProperty*                    ConfigLink;             // 0x0074 (0x04)
    class UProperty*                    ConstructorLink;        // 0x0078 (0x04)
    class UProperty*                    ComponentPropertyLink;  // 0x007C (0x04)
    class UProperty*                    TransientPropertyLink;  // 0x0080 (0x04)
    TArray<UObject*>                    ScriptObjectReferences; // 0x0084 (0x0C)

public:
    static UClass* StaticClass()
    {
        static UClass* uClassPointer = nullptr;
        if (!uClassPointer)
        {
            uClassPointer = UObject::FindClass("Class Core.Struct");
        }
        return uClassPointer;
    };
};

// Class Core.ScriptStruct
// (Custom Override)
// Class Core.ScriptStruct
// 0x001C (0x0090 - 0x00AC)
class UScriptStruct : public UStruct
{
public:
    class FString                       DefaultStructPropText;  // 0x0090 (0x0C)
    uint32_t                            StructFlags;            // 0x009C (0x04)
    TArray<uint8_t>                     StructDefaults;         // 0x00A0 (0x0C)

public:
    static UClass* StaticClass()
    {
        static UClass* uClassPointer = nullptr;
        if (!uClassPointer)
        {
            uClassPointer = UObject::FindClass("Class Core.ScriptStruct");
        }
        return uClassPointer;
    };
};

// Class Core.Function
// (Custom Override)
// Class Core.Function
// 0x0020 (0x0090 - 0x00B0)
class UFunction : public UStruct
{
public:
    uint32_t                            FunctionFlags;          // 0x0090 (0x04)
    uint16_t                            iNative;                // 0x0094 (0x02)
    uint16_t                            RepOffset;              // 0x0096 (0x02)
    class FName                         FriendlyName;           // 0x0098 (0x08)
    uint8_t                             OperPrecedence;         // 0x00A0 (0x01)
    uint8_t                             NumParms;               // 0x00A1 (0x01)
    uint16_t                            ParmsSize;              // 0x00A2 (0x02)
    uint16_t                            ReturnValueOffset;      // 0x00A4 (0x02)
    uint8_t                             UnknownData00[0x02];    // 0x00A6 (0x02)
    class UStructProperty*              FirstStructWithDefaults;// 0x00A8 (0x04)
    struct FPointer                     Func;                   // 0x00AC (0x04)

public:
    static UClass* StaticClass()
    {
        static UClass* uClassPointer = nullptr;
        if (!uClassPointer)
        {
            uClassPointer = UObject::FindClass("Class Core.Function");
        }
        return uClassPointer;
    };

    static UFunction* FindFunction(const std::string& functionFullName);
};

// Class Core.Property
// (Custom Override)
// Class Core.Property
// 0x0040 (0x0044 - 0x0084)
class UProperty : public UField
{
public:
    int32_t                             ArrayDim;               // 0x0044 (0x04)
    uint64_t                            PropertyFlags;          // 0x0048 (0x08)
    int32_t                             ElementSize;            // 0x0050 (0x04)
    uint16_t                            RepOffset;              // 0x0054 (0x02)
    uint16_t                            RepIndex;               // 0x0056 (0x02)
    class FName                         Category;               // 0x0058 (0x08)
    class UEnum*                        ArraySizeEnum;          // 0x0060 (0x04)
    int32_t                             Offset;                 // 0x0064 (0x04)
    class UProperty*                    PropertyLinkNext;       // 0x0068 (0x04)
    class UProperty*                    ConfigLinkNext;         // 0x006C (0x04)
    class UProperty*                    ConstructorLinkNext;    // 0x0070 (0x04)
    class UProperty*                    NextRef;                // 0x0074 (0x04)
    class UProperty*                    RepOwner;               // 0x0078 (0x04)
    class UProperty*                    ComponentPropertyLinkNext; // 0x007C (0x04)
    class UProperty*                    TransientPropertyLinkNext; // 0x0080 (0x04)

public:
    static UClass* StaticClass()
    {
        static UClass* uClassPointer = nullptr;
        if (!uClassPointer)
        {
            uClassPointer = UObject::FindClass("Class Core.Property");
        }
        return uClassPointer;
    };
};

// Class Core.StructProperty
// 0x0004 (0x0084 - 0x0088)
class UStructProperty : public UProperty
{
public:
	class UStruct* Struct; // 0x0084 (0x0004)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Core.StructProperty");
		}

		return uClassPointer;
	};

};
// Class Core.StrProperty
// 0x0000 (0x0084 - 0x0084)
class UStrProperty : public UProperty
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Core.StrProperty");
		}

		return uClassPointer;
	};

};
// Class Core.ObjectProperty
// 0x0004 (0x0084 - 0x0088)
class UObjectProperty : public UProperty
{
public:
	class UClass* PropertyClass; // 0x0084 (0x0004)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Core.ObjectProperty");
		}

		return uClassPointer;
	};

};
// Class Core.ComponentProperty
// 0x0000 (0x0088 - 0x0088)
class UComponentProperty : public UObjectProperty
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Core.ComponentProperty");
		}

		return uClassPointer;
	};

};
// Class Core.ClassProperty
// 0x0004 (0x0088 - 0x008C)
class UClassProperty : public UObjectProperty
{
public:
	class UClass* MetaClass; // 0x0088 (0x0004)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Core.ClassProperty");
		}

		return uClassPointer;
	};

};
// Class Core.NameProperty
// 0x0000 (0x0084 - 0x0084)
class UNameProperty : public UProperty
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Core.NameProperty");
		}

		return uClassPointer;
	};

};
// Class Core.MapProperty
// 0x0008 (0x0084 - 0x008C)
class UMapProperty : public UProperty
{
public:
	class UProperty* Key; // 0x0084 (0x0004)
	class UProperty* Value; // 0x0088 (0x0004)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Core.MapProperty");
		}

		return uClassPointer;
	};

};
// Class Core.IntProperty
// 0x0000 (0x0084 - 0x0084)
class UIntProperty : public UProperty
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Core.IntProperty");
		}

		return uClassPointer;
	};

};
// Class Core.InterfaceProperty
// 0x0004 (0x0084 - 0x0088)
class UInterfaceProperty : public UProperty
{
public:
	class UClass* InterfaceClass; // 0x0084 (0x0004)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Core.InterfaceProperty");
		}

		return uClassPointer;
	};

};
// Class Core.FloatProperty
// 0x0000 (0x0084 - 0x0084)
class UFloatProperty : public UProperty
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Core.FloatProperty");
		}

		return uClassPointer;
	};

};
// Class Core.DelegateProperty
// (Custom Override)
// Class Core.DelegateProperty
// 0x0008 (0x0084 - 0x008C)
class UDelegateProperty : public UProperty
{
public:
    class UFunction*                    Function;               // 0x0084 (0x04)
    class UFunction*                    SourceDelegate;         // 0x0088 (0x04)

public:
    static UClass* StaticClass()
    {
        static UClass* uClassPointer = nullptr;
        if (!uClassPointer)
        {
            uClassPointer = UObject::FindClass("Class Core.DelegateProperty");
        }
        return uClassPointer;
    };
};

// Class Core.ByteProperty
// 0x0004 (0x0084 - 0x0088)
class UByteProperty : public UProperty
{
public:
	class UEnum* Enum; // 0x0084 (0x0004)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Core.ByteProperty");
		}

		return uClassPointer;
	};

};
// Class Core.BoolProperty
// 0x0004 (0x0084 - 0x0088)
class UBoolProperty : public UProperty
{
public:
	uint32_t BitMask; // 0x0084 (0x0004)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Core.BoolProperty");
		}

		return uClassPointer;
	};

};
// Class Core.ArrayProperty
// 0x0004 (0x0084 - 0x0088)
class UArrayProperty : public UProperty
{
public:
	class UProperty* Inner; // 0x0084 (0x0004)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Core.ArrayProperty");
		}

		return uClassPointer;
	};

};
// Class Core.Enum
// 0x000C (0x0044 - 0x0050)
class UEnum : public UField
{
public:
	class TArray<class FName> Names; // 0x0044 (0x000C)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Core.Enum");
		}

		return uClassPointer;
	};

};
// Class Core.Const
// 0x000C (0x0044 - 0x0050)
class UConst : public UField
{
public:
	class FString Value; // 0x0044 (0x000C)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Core.Const");
		}

		return uClassPointer;
	};

};
// Class Core.Factory
// 0x0040 (0x003C - 0x007C)
class UFactory : public UObject
{
public:
	uint8_t                                            UnknownData00[0x8];                              // 0x003C (0x0008) MISSED OFFSET
	class FString                                      Description;                                   // 0x0044 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	uint8_t                                            UnknownData01[0xC];                              // 0x0050 (0x000C) MISSED OFFSET
	class TArray<class FString>                        Formats;                                       // 0x005C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	uint8_t                                            UnknownData02[0x14];                            // 0x0068 (0x0014) MISSED OFFSET

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Core.Factory");
		}

		return uClassPointer;
	};

};
// Class Core.TextBufferFactory
// 0x0000 (0x007C - 0x007C)
class UTextBufferFactory : public UFactory
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Core.TextBufferFactory");
		}

		return uClassPointer;
	};

};
// Class Core.Exporter
// 0x0028 (0x003C - 0x0064)
class UExporter : public UObject
{
public:
	uint8_t                                            UnknownData00[0x4];                              // 0x003C (0x0004) MISSED OFFSET
	class TArray<class FString>                        FormatExtension;                               // 0x0040 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	class TArray<class FString>                        FormatDescription;                             // 0x004C (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)
	uint8_t                                            UnknownData01[0xC];                              // 0x0058 (0x000C) MISSED OFFSET

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Core.Exporter");
		}

		return uClassPointer;
	};

};
// Class Core.Component
// 0x000C (0x003C - 0x0048)
class UComponent : public UObject
{
public:
	class UClass*                                      TemplateOwnerClass;                            // 0x003C (0x0004) [0x0000000000001002] (CPF_Const | CPF_Native)
	class FName                                        TemplateName;                                  // 0x0040 (0x0008) [0x0000000000001002] (CPF_Const | CPF_Native)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Core.Component");
		}

		return uClassPointer;
	};

};
// Class Core.DistributionVector
// 0x0008 (0x0048 - 0x0050)
class UDistributionVector : public UComponent
{
public:
	struct FPointer                                    VfTable_FCurveEdInterface;                     // 0x0048 (0x0004) [0x0000000000801002] (CPF_Const | CPF_Native | CPF_NoExport)
	uint32_t                                           bCanBeBaked : 1;                               // 0x004C (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bIsDirty : 1;                                  // 0x004C (0x0004) [0x0000000000000000] [0x00000002] 

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Core.DistributionVector");
		}

		return uClassPointer;
	};


	struct FVector GetVectorValue(float optionalF, int32_t optionalLastExtreme);
};
// Class Core.DistributionFloat
// 0x0008 (0x0048 - 0x0050)
class UDistributionFloat : public UComponent
{
public:
	struct FPointer                                    VfTable_FCurveEdInterface;                     // 0x0048 (0x0004) [0x0000000000801002] (CPF_Const | CPF_Native | CPF_NoExport)
	uint32_t                                           bCanBeBaked : 1;                               // 0x004C (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bIsDirty : 1;                                  // 0x004C (0x0004) [0x0000000000000000] [0x00000002] 

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Core.DistributionFloat");
		}

		return uClassPointer;
	};


	float GetFloatValue(float optionalF);
};
// Class Core.Commandlet
// 0x0040 (0x003C - 0x007C)
class UCommandlet : public UObject
{
public:
	class FString                                      HelpDescription;                               // 0x003C (0x000C) [0x0000000000408002] (CPF_Const | CPF_Localized | CPF_NeedCtorLink)
	class FString                                      HelpUsage;                                     // 0x0048 (0x000C) [0x0000000000408002] (CPF_Const | CPF_Localized | CPF_NeedCtorLink)
	class FString                                      HelpWebLink;                                   // 0x0054 (0x000C) [0x0000000000408002] (CPF_Const | CPF_Localized | CPF_NeedCtorLink)
	class TArray<class FString>                        HelpParamNames;                                // 0x0060 (0x000C) [0x0000000000408002] (CPF_Const | CPF_Localized | CPF_NeedCtorLink)
	class TArray<class FString>                        HelpParamDescriptions;                         // 0x006C (0x000C) [0x0000000000408002] (CPF_Const | CPF_Localized | CPF_NeedCtorLink)
	uint32_t                                           IsServer : 1;                                  // 0x0078 (0x0004) [0x0000000000000000] [0x00000001] 
	uint32_t                                           IsClient : 1;                                  // 0x0078 (0x0004) [0x0000000000000000] [0x00000002] 
	uint32_t                                           IsEditor : 1;                                  // 0x0078 (0x0004) [0x0000000000000000] [0x00000004] 
	uint32_t                                           LogToConsole : 1;                              // 0x0078 (0x0004) [0x0000000000000000] [0x00000008] 
	uint32_t                                           ShowErrorCount : 1;                            // 0x0078 (0x0004) [0x0000000000000000] [0x00000010] 

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Core.Commandlet");
		}

		return uClassPointer;
	};


	int32_t eventMain(const class FString& Params);
};
// Class Core.HelpCommandlet
// 0x0000 (0x007C - 0x007C)
class UHelpCommandlet : public UCommandlet
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Core.HelpCommandlet");
		}

		return uClassPointer;
	};


	int32_t eventMain(const class FString& Params);
};
// Class Core.Package
// 0x00AC (0x003C - 0x00E8)
class UPackage : public UObject
{
public:
	uint8_t                                            UnknownData00[0xAC];                            // 0x003C (0x00AC) MISSED OFFSET

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class Core.Package");
		}

		return uClassPointer;
	};

};
// Class Core.State
// (Custom Override)
// Class Core.State
// 0x0054 (0x0090 - 0x00E4)
class UState : public UStruct
{
public:
    uint64_t                            ProbeMask;              // 0x0090 (0x08)
    uint64_t                            IgnoreMask;             // 0x0098 (0x08)
    uint32_t                            StateFlags;             // 0x00A0 (0x04)
    uint16_t                            LabelTableOffset;       // 0x00A4 (0x02)
    uint8_t                             UnknownData00[0x02];    // 0x00A6 (0x02)
    struct FMap_Mirror                  FuncMap;                // 0x00A8 (0x3C)

public:
    static UClass* StaticClass()
    {
        static UClass* uClassPointer = nullptr;
        if (!uClassPointer)
        {
            uClassPointer = UObject::FindClass("Class Core.State");
        }
        return uClassPointer;
    };
};

// Class Core.Class
// (Custom Override)
// Class Core.Class
// 0x00EC (0x00E4 - 0x01D0)
class UClass : public UState
{
public:
    struct FRepRecord
    {
        class UProperty*                Property;               // 0x0000 (0x04)
        int32_t                         Index;                  // 0x0004 (0x04)
    };

    struct FImplementedInterface
    {
        class UClass*                   Class;                  // 0x0000 (0x04)
        class UProperty*                PointerProperty;        // 0x0004 (0x04)
    };

    uint32_t                            ClassFlags;             // 0x00E4 (0x04)
    uint32_t                            ClassCastFlags;         // 0x00E8 (0x04)
    int32_t                             ClassUnique;            // 0x00EC (0x04)
    class UClass*                       ClassWithin;            // 0x00F0 (0x04)
    class FName                         ClassConfigName;        // 0x00F4 (0x08)
    TArray<FRepRecord>                  ClassReps;              // 0x00FC (0x0C)
    TArray<class UField*>               NetFields;              // 0x0108 (0x0C)
    TArray<class FName>                 HideCategories;         // 0x0114 (0x0C)
    TArray<class FName>                 AutoExpandCategories;   // 0x0120 (0x0C)
    TArray<class FName>                 AutoCollapseCategories; // 0x012C (0x0C)
    TArray<class FName>                 DontSortCategories;     // 0x0138 (0x0C)
    TArray<class FName>                 DependentOn;            // 0x0144 (0x0C)
    class FString                       ClassHeaderFilename;    // 0x0150 (0x0C)
    class UObject*                      ClassDefaultObject;     // 0x015C (0x04)
    struct FPointer                     ClassConstructor;       // 0x0160 (0x04)
    struct FPointer                     ClassStaticConstructor; // 0x0164 (0x04)
    struct FPointer                     ClassStaticInitializer; // 0x0168 (0x04)
    struct FMap_Mirror                  ComponentNameToDefaultObjectMap; // 0x016C (0x3C)
    TArray<FImplementedInterface>       Interfaces;             // 0x01A8 (0x0C)
    class FString                       DefaultPropText;        // 0x01B4 (0x0C)
    uint32_t                            bNeedsPropertiesLinked; // 0x01C0 (0x04)
    TArray<uint32_t>                    ReferenceTokenStream;   // 0x01C4 (0x0C)

public:
    static UClass* StaticClass()
    {
        static UClass* uClassPointer = nullptr;
        if (!uClassPointer)
        {
            uClassPointer = UObject::FindClass("Class Core.Class");
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
