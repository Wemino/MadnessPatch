/*
#############################################################################################
# Alice2 (ASDK) SDK 1.0.0.0
# Generated with the CodeRedGenerator v1.2.0
# ========================================================================================= #
# File: GFxUI_classes.hpp
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


/*
# ========================================================================================= #
# Enums
# ========================================================================================= #
*/

// Enum GFxUI.GFxMovie.ASType
enum class EASType : uint8_t
{
	AS_Undefined                                       = 0,
	AS_Null                                            = 1,
	AS_Number                                          = 2,
	AS_String                                          = 3,
	AS_Boolean                                         = 4,
	AS_END                                             = 5
};

// Enum GFxUI.GFxMovie.GFxTimingMode
enum class EGFxTimingMode : uint8_t
{
	TM_Game                                            = 0,
	TM_Real                                            = 1,
	TM_END                                             = 2
};

// Enum GFxUI.GFxMovie.GFxAlign
enum class EGFxAlign : uint8_t
{
	Align_Center                                       = 0,
	Align_TopCenter                                    = 1,
	Align_BottomCenter                                 = 2,
	Align_CenterLeft                                   = 3,
	Align_CenterRight                                  = 4,
	Align_TopLeft                                      = 5,
	Align_TopRight                                     = 6,
	Align_BottomLeft                                   = 7,
	Align_BottomRight                                  = 8,
	Align_END                                          = 9
};

// Enum GFxUI.GFxMovie.GFxScaleMode
enum class EGFxScaleMode : uint8_t
{
	GSM_NoScale                                        = 0,
	GSM_ShowAll                                        = 1,
	GSM_ExactFit                                       = 2,
	GSM_NoBorder                                       = 3,
	GSM_END                                            = 4
};

// Enum GFxUI.GFxMovie.GFxRenderTextureMode
enum class EGFxRenderTextureMode : uint8_t
{
	RTM_Opaque                                         = 0,
	RTM_Alpha                                          = 1,
	RTM_AlphaComposite                                 = 2,
	RTM_END                                            = 3
};


/*
# ========================================================================================= #
# Classes
# ========================================================================================= #
*/

// Class GFxUI.GFxEngine
// 0x0010 (0x003C - 0x004C)
class UGFxEngine : public UObject
{
public:
	class TArray<struct FGCReference>                  GCReferences;                                  // 0x003C (0x000C) [0x0000000000402000] (CPF_Transient | CPF_NeedCtorLink)
	int32_t                                            RefCount;                                      // 0x0048 (0x0004) [0x0000000000002000] (CPF_Transient)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GFxUI.GFxEngine");
		}

		return uClassPointer;
	};

};
// Class GFxUI.GFxFSCmdHandler
// 0x0000 (0x003C - 0x003C)
class UGFxFSCmdHandler : public UObject
{
public:

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GFxUI.GFxFSCmdHandler");
		}

		return uClassPointer;
	};


	bool eventFSCommand(class UGFxMovie* Movie, const class FString& Cmd, const class FString& Arg);
};
// Class GFxUI.GFxGameViewportClient
// 0x0008 (0x011C - 0x0124)
class UGFxGameViewportClient : public UGameViewportClient
{
public:
	class UClass*                                      GFxUIControllerClass;                          // 0x011C (0x0004) [0x0000000000000000]               
	class UGFxInteraction*                             GFxUIController;                               // 0x0120 (0x0004) [0x0000000000000000]               

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GFxUI.GFxGameViewportClient");
		}

		return uClassPointer;
	};


	bool eventInit(class FString& outOutError);
};
// Class GFxUI.GFxInteraction
// 0x0004 (0x006C - 0x0070)
class UGFxInteraction : public UInteraction
{
public:
	struct FPointer                                    VfTable_FCallbackEventDevice;                  // 0x006C (0x0004) [0x0000000000801002] (CPF_Const | CPF_Native | CPF_NoExport)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GFxUI.GFxInteraction");
		}

		return uClassPointer;
	};


	void NotifyGameSessionEnded();
	class UGFxMovie* GetFocusMovie();
	bool SetFocusMovie(const class FString& MovieName, bool captureInput);
};
// Class GFxUI.GFxMovie
// 0x00E4 (0x003C - 0x0120)
class UGFxMovie : public UObject
{
public:
	class UGFxMovieInfo*                               MovieInfo;                                     // 0x003C (0x0004) [0x0000000000000001] (CPF_Edit)    
	class UTextureRenderTarget2D*                      RenderTexture;                                 // 0x0040 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class APlayerController*                           PlayerOwner;                                   // 0x0044 (0x0004) [0x0000000000002000] (CPF_Transient)
	struct FPointer                                    pMovie;                                        // 0x0048 (0x0004) [0x0000000000003002] (CPF_Const | CPF_Native | CPF_Transient)
	struct FPointer                                    pCaptureKeys;                                  // 0x004C (0x0004) [0x0000000000003002] (CPF_Const | CPF_Native | CPF_Transient)
	struct FPointer                                    pFocusIgnoreKeys;                              // 0x0050 (0x0004) [0x0000000000003002] (CPF_Const | CPF_Native | CPF_Transient)
	class UGFxFSCmdHandler*                            FSCmdHandler;                                  // 0x0054 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class UObject*                                     ExternalInterface;                             // 0x0058 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class TArray<class FName>                          CaptureKeys;                                   // 0x005C (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class TArray<class FName>                          FocusIgnoreKeys;                               // 0x0068 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	ESceneDepthPriorityGroup                           SceneDPG;                                      // 0x0074 (0x0001) [0x0000000000000001] (CPF_Edit)    
	EGFxTimingMode                                     TimingMode;                                    // 0x0075 (0x0001) [0x0000000000000001] (CPF_Edit)    
	EGFxRenderTextureMode                              RenderTextureMode;                             // 0x0076 (0x0001) [0x0000000000000001] (CPF_Edit)    
	uint8_t                                            UnknownData00[0x1];                              // 0x0077 (0x0001) MISSED OFFSET
	uint32_t                                           bDisplayWithHudOff : 1;                        // 0x0078 (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bGammaCorrection : 1;                          // 0x0078 (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	struct FMap_Mirror                                 ASUClasses;                                    // 0x007C (0x003C) [0x0000000000003002] (CPF_Const | CPF_Native | CPF_Transient)
	struct FMap_Mirror                                 ASUObjects;                                    // 0x00B8 (0x003C) [0x0000000000003002] (CPF_Const | CPF_Native | CPF_Transient)
	int32_t                                            NextASUObject;                                 // 0x00F4 (0x0004) [0x0000000000002002] (CPF_Const | CPF_Transient)
	class TArray<struct FExternalTexture>              ExternalTextures;                              // 0x00F8 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class TArray<struct FGFxDataStoreBinding>          DataStoreBindings;                             // 0x0104 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class UGFxDataStoreSubscriber*                     DataStoreSubscriber;                           // 0x0110 (0x0004) [0x0000000000002000] (CPF_Transient)
	struct FScriptDelegate                             __HandleInputKey__Delegate;                    // 0x0114 (0x000C) [0x0000000000400000] (CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GFxUI.GFxMovie");
		}

		return uClassPointer;
	};


	void ActionScriptSetFunction(class UGFxValue* Obj, const class FString& member);
	class UGFxValue* ActionScriptObject(const class FString& Path);
	class FString ActionScriptString(const class FString& Path);
	float ActionScriptFloat(const class FString& Path);
	int32_t ActionScriptInt(const class FString& Path);
	void ActionScriptVoid(const class FString& Path);
	void eventUserTick();
	void SetExternalInterface(class UObject* H);
	void SetFsCmdHandler(class UGFxFSCmdHandler* H);
	void SetVariableObject(const class FString& Path, class UGFxValue* Value);
	class UGFxValue* GetVariableObject(const class FString& Path, class UClass* optionalType);
	class UGFxValue* CreateArray();
	class UGFxValue* CreateObject(const class FString& ASClass, class UClass* optionalType);
	bool SetVariableStringArray(const class FString& Path, int32_t Index, const class TArray<class FString>& Arg);
	bool SetVariableFloatArray(const class FString& Path, int32_t Index, const class TArray<float>& Arg);
	bool SetVariableIntArray(const class FString& Path, int32_t Index, const class TArray<int32_t>& Arg);
	bool SetVariableArray(const class FString& Path, int32_t Index, const class TArray<struct FASValue>& Arg);
	bool GetVariableStringArray(const class FString& Path, int32_t Index, class TArray<class FString>& outArg);
	bool GetVariableFloatArray(const class FString& Path, int32_t Index, class TArray<float>& outArg);
	bool GetVariableIntArray(const class FString& Path, int32_t Index, class TArray<int32_t>& outArg);
	bool GetVariableArray(const class FString& Path, int32_t Index, class TArray<struct FASValue>& outArg);
	void SetVariableString(const class FString& Path, const class FString& S);
	void SetVariableNumber(const class FString& Path, float F);
	void SetVariableBool(const class FString& Path, bool B);
	void SetVariable(const class FString& Path, const struct FASValue& Arg);
	class FString GetVariableString(const class FString& Path);
	float GetVariableNumber(const class FString& Path);
	bool GetVariableBool(const class FString& Path);
	struct FASValue GetVariable(const class FString& Path);
	void PublishDataStoreValues();
	void RefreshDataStoreBindings();
	struct FASValue Invoke(const class FString& method, const class TArray<struct FASValue>& args);
	void SetTimingMode(EGFxTimingMode Mode);
	void Pause(bool optionalPauseplay);
	void Advance(float Time);
	bool SetExternalTexture(const class FString& Resource, class UTexture* Texture);
	void FlushPlayerInput(bool capturekeysonly);
	void ClearFocusIgnoreKeys();
	void AddFocusIgnoreKey(const class FName& Key);
	void ClearCaptureKeys();
	void AddCaptureKey(const class FName& Key);
	void SetFocus(bool captureInput, bool optionalFocus);
	void SetSceneDPG(ESceneDepthPriorityGroup NewDPG);
	void SetPerspective3D(struct FMatrix& outMatPersp);
	void SetView3D(struct FMatrix& outMatView);
	void GetVisibleFrameRect(float& outX0, float& outY0, float& outX1, float& outY1);
	void SetAlignment(EGFxAlign A);
	void SetViewScaleMode(EGFxScaleMode sm);
	void SetViewport(int32_t X, int32_t Y, int32_t Width, int32_t Height);
	class UGameViewportClient* GetGameViewportClient();
	void SetMovieInfo(class UGFxMovieInfo* Data);
	void eventOnClose();
	void Close(bool optionalUnload);
	bool eventStart(bool optionalStartPaused);
	bool HandleInputKey(int32_t ControllerId, const class FName& Key, EInputEvent EventType, float AmountDepressed, bool optionalBGamepad);
};
// Class GFxUI.GFxMovieInfo
// 0x0048 (0x003C - 0x0084)
class UGFxMovieInfo : public UObject
{
public:
	class TArray<uint8_t>                              RawData;                                       // 0x003C (0x000C) [0x0000000000400002] (CPF_Const | CPF_NeedCtorLink)
	class TArray<class UObject*>                       References;                                    // 0x0048 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class TArray<class UObject*>                       UserReferences;                                // 0x0054 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	uint32_t                                           bUsesFontlib : 1;                              // 0x0060 (0x0004) [0x0000000000020001] [0x00000001] (CPF_Edit | CPF_EditConst)
	uint32_t                                           bUseGFxExport : 1;                             // 0x0060 (0x0004) [0x0000000800000001] [0x00000002] (CPF_Edit | CPF_EditorOnly)
	uint32_t                                           bGFxExportSRGBTextures : 1;                    // 0x0060 (0x0004) [0x0000000800000001] [0x00000004] (CPF_Edit | CPF_EditorOnly)
	int32_t                                            RTTextures;                                    // 0x0064 (0x0004) [0x0000000000000001] (CPF_Edit)    
	int32_t                                            RTVideoTextures;                               // 0x0068 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class FString                                      SourceFile;                                    // 0x006C (0x000C) [0x0000000800400001] (CPF_Edit | CPF_NeedCtorLink | CPF_EditorOnly)
	class FString                                      GFxExportCmdLine;                              // 0x0078 (0x000C) [0x0000000800400001] (CPF_Edit | CPF_NeedCtorLink | CPF_EditorOnly)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GFxUI.GFxMovieInfo");
		}

		return uClassPointer;
	};

};
// Class GFxUI.GFxValue
// 0x0030 (0x003C - 0x006C)
class UGFxValue : public UObject
{
public:
	int32_t                                            Value[12];                                     // 0x003C (0x0030) [0x0000000000001002] (CPF_Const | CPF_Native)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GFxUI.GFxValue");
		}

		return uClassPointer;
	};


	void ActionScriptSetFunctionOn(class UGFxValue* Target, const class FString& member);
	void ActionScriptSetFunction(const class FString& member);
	class TArray<class UGFxValue*> ActionScriptArray(const class FString& Path);
	class UGFxValue* ActionScriptObject(const class FString& Path);
	class FString ActionScriptString(const class FString& method);
	float ActionScriptFloat(const class FString& method);
	int32_t ActionScriptInt(const class FString& method);
	void ActionScriptVoid(const class FString& method);
	void SetElementMemberString(int32_t Index, const class FString& member, const class FString& S);
	void SetElementMemberNumber(int32_t Index, const class FString& member, float F);
	void SetElementMemberBool(int32_t Index, const class FString& member, bool B);
	void SetElementMemberObject(int32_t Index, const class FString& member, class UGFxValue* val);
	void SetElementMember(int32_t Index, const class FString& member, const struct FASValue& Arg);
	class FString GetElementMemberString(int32_t Index, const class FString& member);
	float GetElementMemberNumber(int32_t Index, const class FString& member);
	bool GetElementMemberBool(int32_t Index, const class FString& member);
	class UGFxValue* GetElementMemberObject(int32_t Index, const class FString& member, class UClass* optionalType);
	struct FASValue GetElementMember(int32_t Index, const class FString& member);
	void SetElementColorTransform(int32_t Index, const struct FASColorTransform& cxform);
	void SetElementPosition(int32_t Index, float X, float Y);
	void SetElementVisible(int32_t Index, bool Visible);
	void SetElementDisplayMatrix(int32_t Index, const struct FMatrix& M);
	void SetElementDisplayInfo(int32_t Index, const struct FASDisplayInfo& D);
	void SetElementString(int32_t Index, const class FString& S);
	void SetElementNumber(int32_t Index, float F);
	void SetElementBool(int32_t Index, bool B);
	void SetElementObject(int32_t Index, class UGFxValue* val);
	void SetElement(int32_t Index, const struct FASValue& Arg);
	struct FMatrix GetElementDisplayMatrix(int32_t Index);
	struct FASDisplayInfo GetElementDisplayInfo(int32_t Index);
	class FString GetElementString(int32_t Index);
	float GetElementNumber(int32_t Index);
	bool GetElementBool(int32_t Index);
	class UGFxValue* GetElementObject(int32_t Index, class UClass* optionalType);
	struct FASValue GetElement(int32_t Index);
	void SetText(const class FString& Text);
	class FString GetText();
	class UGFxValue* AttachMovie(const class FString& symbolname, const class FString& instancename, int32_t optionalDepth, class UClass* optionalType);
	class UGFxValue* CreateEmptyMovieClip(const class FString& instancename, int32_t optionalDepth, class UClass* optionalType);
	void GotoAndStopI(int32_t frame);
	void GotoAndStop(const class FString& frame);
	void GotoAndPlayI(int32_t frame);
	void GotoAndPlay(const class FString& frame);
	void SetColorTransform(const struct FASColorTransform& cxform);
	void SetPosition(float X, float Y);
	void SetVisible(bool Visible);
	void SetDisplayMatrix3D(const struct FMatrix& M);
	void SetDisplayMatrix(const struct FMatrix& M);
	void SetDisplayInfo(const struct FASDisplayInfo& D);
	bool GetPosition(float& outX, float& outY);
	struct FASColorTransform GetColorTransform();
	struct FMatrix GetDisplayMatrix();
	struct FASDisplayInfo GetDisplayInfo();
	void SetString(const class FString& member, const class FString& S);
	void SetNumber(const class FString& member, float F);
	void SetBool(const class FString& member, bool B);
	void SetFunction(const class FString& member, class UObject* context, const class FName& fname);
	void SetObject(const class FString& member, class UGFxValue* val);
	void Set(const class FString& member, const struct FASValue& Arg);
	class FString GetString(const class FString& member);
	float GetNumber(const class FString& member);
	bool GetBool(const class FString& member);
	class UGFxValue* GetObjectWin(const class FString& member, class UClass* optionalType);
	struct FASValue Get(const class FString& member);
	struct FASValue Invoke(const class FString& member, const class TArray<struct FASValue>& args);
};
// Class GFxUI.GFxAction_CloseMovie
// 0x0008 (0x00E8 - 0x00F0)
class UGFxAction_CloseMovie : public USequenceAction
{
public:
	class UGFxMovie*                                   Movie;                                         // 0x00E8 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bUnload : 1;                                   // 0x00EC (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GFxUI.GFxAction_CloseMovie");
		}

		return uClassPointer;
	};


	bool eventIsValidLevelSequenceObject();
};
// Class GFxUI.GFxAction_GetVariable
// 0x0010 (0x00E8 - 0x00F8)
class UGFxAction_GetVariable : public USequenceAction
{
public:
	class UGFxMovie*                                   Movie;                                         // 0x00E8 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class FString                                      Variable;                                      // 0x00EC (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GFxUI.GFxAction_GetVariable");
		}

		return uClassPointer;
	};


	bool eventIsValidLevelSequenceObject();
};
// Class GFxUI.GFxAction_Invoke
// 0x001C (0x00E8 - 0x0104)
class UGFxAction_Invoke : public USequenceAction
{
public:
	class UGFxMovie*                                   Movie;                                         // 0x00E8 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class FString                                      MethodName;                                    // 0x00EC (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)
	class TArray<struct FASValue>                      Arguments;                                     // 0x00F8 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GFxUI.GFxAction_Invoke");
		}

		return uClassPointer;
	};


	bool eventIsValidLevelSequenceObject();
};
// Class GFxUI.GFxAction_OpenMovie
// 0x0008 (0x00E8 - 0x00F0)
class UGFxAction_OpenMovie : public USequenceAction
{
public:
	class UGFxMovie*                                   Movie;                                         // 0x00E8 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bTakeFocus : 1;                                // 0x00EC (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)
	uint32_t                                           bCaptureInput : 1;                             // 0x00EC (0x0004) [0x0000000000000001] [0x00000002] (CPF_Edit)
	uint32_t                                           bStartPaused : 1;                              // 0x00EC (0x0004) [0x0000000000000001] [0x00000004] (CPF_Edit)
	uint32_t                                           bShouldNotPause : 1;                           // 0x00EC (0x0004) [0x0000000000000001] [0x00000008] (CPF_Edit)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GFxUI.GFxAction_OpenMovie");
		}

		return uClassPointer;
	};


	bool eventIsValidLevelSequenceObject();
};
// Class GFxUI.GFxAction_SetCaptureKeys
// 0x0010 (0x00E8 - 0x00F8)
class UGFxAction_SetCaptureKeys : public USequenceAction
{
public:
	class UGFxMovie*                                   Movie;                                         // 0x00E8 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class TArray<class FName>                          CaptureKeys;                                   // 0x00EC (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GFxUI.GFxAction_SetCaptureKeys");
		}

		return uClassPointer;
	};

};
// Class GFxUI.GFxAction_SetFocus
// 0x0008 (0x00E8 - 0x00F0)
class UGFxAction_SetFocus : public USequenceAction
{
public:
	class UGFxMovie*                                   Movie;                                         // 0x00E8 (0x0004) [0x0000000000000001] (CPF_Edit)    
	uint32_t                                           bCaptureInput : 1;                             // 0x00EC (0x0004) [0x0000000000000001] [0x00000001] (CPF_Edit)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GFxUI.GFxAction_SetFocus");
		}

		return uClassPointer;
	};

};
// Class GFxUI.GFxAction_SetVariable
// 0x0010 (0x00E8 - 0x00F8)
class UGFxAction_SetVariable : public USequenceAction
{
public:
	class UGFxMovie*                                   Movie;                                         // 0x00E8 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class FString                                      Variable;                                      // 0x00EC (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GFxUI.GFxAction_SetVariable");
		}

		return uClassPointer;
	};


	bool eventIsValidLevelSequenceObject();
};
// Class GFxUI.GFxEvent_FsCommand
// 0x0010 (0x0100 - 0x0110)
class UGFxEvent_FsCommand : public USequenceEvent
{
public:
	class UGFxMovie*                                   Movie;                                         // 0x0100 (0x0004) [0x0000000000000001] (CPF_Edit)    
	class FString                                      FSCommand;                                     // 0x0104 (0x000C) [0x0000000000400001] (CPF_Edit | CPF_NeedCtorLink)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GFxUI.GFxEvent_FsCommand");
		}

		return uClassPointer;
	};

};
// Class GFxUI.GFxFSCmdHandler_Kismet
// 0x003C (0x003C - 0x0078)
class UGFxFSCmdHandler_Kismet : public UGFxFSCmdHandler
{
public:
	struct FMap_Mirror                                 Events;                                        // 0x003C (0x003C) [0x0000000000001002] (CPF_Const | CPF_Native)

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GFxUI.GFxFSCmdHandler_Kismet");
		}

		return uClassPointer;
	};


	bool eventFSCommand(class UGFxMovie* Movie, const class FString& Cmd, const class FString& Arg);
};
// Class GFxUI.GFxDataStoreSubscriber
// 0x0008 (0x003C - 0x0044)
class UGFxDataStoreSubscriber : public UObject
{
public:
	struct FPointer                                    VfTable_IUIDataStorePublisher;                 // 0x003C (0x0004) [0x0000000000801002] (CPF_Const | CPF_Native | CPF_NoExport)
	class UGFxMovie*                                   Movie;                                         // 0x0040 (0x0004) [0x0000000000000000]               

public:
	static UClass* StaticClass()
	{
		static UClass* uClassPointer = nullptr;

		if (!uClassPointer)
		{
			uClassPointer = UObject::FindClass("Class GFxUI.GFxDataStoreSubscriber");
		}

		return uClassPointer;
	};


	bool SaveSubscriberValue(int32_t optionalBindingIndex, class TArray<class UUIDataStore*>& outOut_BoundDataStores);
	void ClearBoundDataStores();
	void GetBoundDataStores(class TArray<class UUIDataStore*>& outOut_BoundDataStores);
	void NotifyDataStoreValueUpdated(class UUIDataStore* SourceDataStore, bool bValuesInvalidated, const class FName& PropertyTag, class UUIDataProvider* SourceProvider, int32_t ArrayIndex);
	bool RefreshSubscriberValue(int32_t optionalBindingIndex);
	class FString GetDataStoreBinding(int32_t optionalBindingIndex);
	void SetDataStoreBinding(const class FString& MarkupText, int32_t optionalBindingIndex);
	void PublishValues();
};
/*
# ========================================================================================= #
#
# ========================================================================================= #
*/

#ifdef _MSC_VER
#pragma pack(pop)
#endif
