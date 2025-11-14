#define MINI_CASE_SENSITIVE
#define _USE_MATH_DEFINES

#include <Windows.h>

#include <stacktrace>

#include "ini.hpp"
#include "dllmain.hpp"
#include "helper.hpp"
#include <shlwapi.h>
#pragma comment(lib, "shlwapi.lib")

struct GlobalState
{
	// System initialization
	bool isInit = false;
	HMODULE GameModule = NULL;

	// Display configuration
	float screenHeight = 0.0f;
	float screenWidth = 0.0f;
	float subtitlesScaleFactor = 0.0f;
	float scaleFactor = 0.0f;

	// Physics
	float frameTimeScale = 0.0f;
	float savedClothDeltaTime = 0.0f;
	float savedHairDeltaTime = 0.0f;

	// FOV
	DWORD pFOV = 0;
	DWORD pFOVCut = 0;
	DWORD pGEngine = 0;
	float FOVScale = 0.0f;
	bool updateFOV = false;
	bool isCutscene = false;

	// Input
	DWORD pInput = 0;
	bool isUsingGamepad = false;

	// Misc
	bool set40fps = false;
	bool prev_set40fps = false;
	float original_fps = 0.0f;
	bool shouldSkipMovie = false;
};

// Global instance
GlobalState g_State;

// Ini Settings override
static std::vector<std::unique_ptr<wchar_t[]>> g_tempConfigStrings;
static const wchar_t* g_replacementString = nullptr;

// Ini Input override
struct PendingRestore
{
	uintptr_t structAddr;
	wchar_t* originalPtr;
	int originalLength;
	int originalCapacity;
	bool needsRestore;
};

static PendingRestore g_pendingRestore = { 0, nullptr, 0, 0, false };
static std::vector<std::unique_ptr<wchar_t[]>> g_tempFixedStrings;

static constexpr float TARGET_FRAME_TIME = 1.0f / 30.0f;
static constexpr float ASPECT_RATIO_16_9 = 16.0f / 9.0f;

// =============================
// Ini Variables
// =============================

// Fixes
bool FixHighFPSHairPhysics = false;
bool FixHighFPSClothPhysics = false;
bool FixHighFPSProjectileCollisionCheck = false;
bool FixHighFPSRagdollDeath = false;
bool FixHashTableRaceCondition = false;
bool FixInputBinding = false;
bool FixWindowHandling = false;

// General
bool UnlockCompleteEditionDLC = false;
bool DisableLegacyDriverHacks = false;
bool CheckAlice1InstallFolder = false;
bool SkipEAIntro = false;
bool SkipSHIntro = false;
bool SkipUEIntro = false;

// Display
bool FontScaling = false;
float FontScalingFactor = 0;
bool UseWindowed = false;

// Input
bool DisableMouseAcceleration = false;
bool DisableControllerAcceleration = false;
bool DisableMouseSmoothing = false;
bool SkipCutscenesWithEnter = false;

// Graphics
int MaxFPS = 0;
bool EnableMaxSmoothedFrameRate = false;
bool ImprovedTextureStreaming = false;
bool ForceHighResTextures = false;
bool FixUltraWideScreenFOV = false;
bool ReducedMipMapBias = false;
bool FixBinkVideoBT709 = false;

struct ConfigOverride
{
	std::wstring value;
	bool* isEnabled;
};

static std::unordered_map<std::wstring, ConfigOverride> g_configOverrides = 
{
	// [Engine.Engine]
	{L"MaxSmoothedFrameRate", {L"120", &EnableMaxSmoothedFrameRate}},
	{L"MipLevelFadingInRate", {L"0.0", &ImprovedTextureStreaming}},
	{L"MipLevelFadingOutRate", {L"0.0", &ImprovedTextureStreaming}},

	// [Engine.ISVHacks]
	{L"DisableATITextureFilterOptimizationChecks", {L"False", &DisableLegacyDriverHacks}},
	{L"UseMinimalNVIDIADriverShaderOptimization", {L"False", &DisableLegacyDriverHacks}},

	// [TextureStreaming]
	{L"MinTimeToGuaranteeMinMipCount", {L"0", &ImprovedTextureStreaming}},
	{L"MaxTimeToGuaranteeMinMipCount", {L"0", &ImprovedTextureStreaming}},
	{L"HysteresisLimit", {L"30", &ImprovedTextureStreaming}},
	{L"DropMipLevelsLimit", {L"20", &ImprovedTextureStreaming}},
	{L"StopIncreasingLimit", {L"20", &ImprovedTextureStreaming}},
	{L"StopStreamingLimit", {L"12", &ImprovedTextureStreaming}},
	{L"MinEvictSize", {L"10", &ImprovedTextureStreaming}},
	{L"MipLevelFadingInRate", {L"0.0", &ImprovedTextureStreaming}},
	{L"MipLevelFadingOutRate", {L"0.0", &ImprovedTextureStreaming}},

	// [SystemSettings]
	{L"Fullscreen", {L"False", &UseWindowed}},

	// [AliceGame.AliceGameEngine]
	{L"GIsSpecialPCEdition", {L"True", &UnlockCompleteEditionDLC}},

	// [Engine.PlayerInput]
	{L"bEnableMouseSmoothing", {L"False", &DisableMouseSmoothing}}
};

static void UpdateConfigInt(const wchar_t* key, int value)
{
	auto it = g_configOverrides.find(key);
	if (it != g_configOverrides.end())
	{
		it->second.value = std::to_wstring(value);
	}
}

static void UpdateConfigBool(const wchar_t* key, bool value)
{
	auto it = g_configOverrides.find(key);
	if (it != g_configOverrides.end())
	{
		it->second.value = value ? L"True" : L"False";
	}
}

static void ReadConfig()
{
	IniHelper::Init();

	// Fixes
	FixHighFPSHairPhysics = IniHelper::ReadInteger("Fixes", "FixHighFPSHairPhysics", 1) == 1;
	FixHighFPSClothPhysics = IniHelper::ReadInteger("Fixes", "FixHighFPSClothPhysics", 1) == 1;
	FixHighFPSProjectileCollisionCheck = IniHelper::ReadInteger("Fixes", "FixHighFPSProjectileCollisionCheck", 1) == 1;
	FixHighFPSRagdollDeath = IniHelper::ReadInteger("Fixes", "FixHighFPSRagdollDeath", 1) == 1;
	FixHashTableRaceCondition = IniHelper::ReadInteger("Fixes", "FixHashTableRaceCondition", 1) == 1;
	FixInputBinding = IniHelper::ReadInteger("Fixes", "FixInputBinding", 1) == 1;
	FixWindowHandling = IniHelper::ReadInteger("Fixes", "FixWindowHandling", 1) == 1;

	// General
	UnlockCompleteEditionDLC = IniHelper::ReadInteger("General", "UnlockCompleteEditionDLC", 1) == 1;
	DisableLegacyDriverHacks = IniHelper::ReadInteger("General", "DisableLegacyDriverHacks", 1) == 1;
	CheckAlice1InstallFolder = IniHelper::ReadInteger("General", "CheckAlice1InstallFolder", 1) == 1;
	SkipEAIntro = IniHelper::ReadInteger("General", "SkipEAIntro", 0) == 1;
	SkipSHIntro = IniHelper::ReadInteger("General", "SkipSHIntro", 1) == 1;
	SkipUEIntro = IniHelper::ReadInteger("General", "SkipUEIntro", 1) == 1;

	// Display
	FontScaling = IniHelper::ReadInteger("Display", "FontScaling", 1) == 1;
	FontScalingFactor = IniHelper::ReadFloat("Display", "FontScalingFactor", 1.0f);
	UseWindowed = IniHelper::ReadInteger("Display", "UseWindowed", 0) == 1;

	// Input
	DisableMouseAcceleration = IniHelper::ReadInteger("Input", "DisableMouseAcceleration", 1) == 1;
	DisableControllerAcceleration = IniHelper::ReadInteger("Input", "DisableControllerAcceleration", 0) == 1;
	DisableMouseSmoothing = IniHelper::ReadInteger("Input", "DisableMouseSmoothing", 0) == 1;
	SkipCutscenesWithEnter = IniHelper::ReadInteger("Input", "SkipCutscenesWithEnter", 0) == 1;

	// Graphics
	MaxFPS = IniHelper::ReadInteger("Graphics", "MaxFPS", 120);
	ForceHighResTextures = IniHelper::ReadInteger("Graphics", "ForceHighResTextures", 1) == 1;
	ImprovedTextureStreaming = IniHelper::ReadInteger("Graphics", "ImprovedTextureStreaming", 1) == 1;
	FixUltraWideScreenFOV = IniHelper::ReadInteger("Graphics", "FixUltraWideScreenFOV", 1) == 1;
	ReducedMipMapBias = IniHelper::ReadInteger("Graphics", "ReducedMipMapBias", 1) == 1;
	FixBinkVideoBT709 = IniHelper::ReadInteger("Graphics", "FixBinkVideoBT709", 1) == 1;

	// MaxSmoothedFrameRate
	EnableMaxSmoothedFrameRate = MaxFPS != 0;
	UpdateConfigInt(L"MaxSmoothedFrameRate", MaxFPS);

	// Windowed
	UpdateConfigBool(L"Fullscreen", !UseWindowed);
	UseWindowed = true; // Can default to windowed if set to AliceEngine.ini

	// DisableMouseSmoothing
	UpdateConfigBool(L"bEnableMouseSmoothing", !DisableMouseSmoothing);
	DisableMouseSmoothing = true;

	// DisableLegacyDriverHacks
	UpdateConfigBool(L"DisableATITextureFilterOptimizationChecks", !DisableLegacyDriverHacks);
	UpdateConfigBool(L"UseMinimalNVIDIADriverShaderOptimization", !DisableLegacyDriverHacks);
	DisableLegacyDriverHacks = true;

	// GIsSpecialPCEdition
	UpdateConfigBool(L"GIsSpecialPCEdition", UnlockCompleteEditionDLC);
	UnlockCompleteEditionDLC = true;
}

#pragma region Helper

static DWORD ScanModuleSignature(HMODULE Module, std::string_view Signature, const char* PatchName, int FunctionStartCheckCount = -1, bool ShowError = true)
{
	DWORD Address = MemoryHelper::FindSignatureAddress(Module, Signature, FunctionStartCheckCount);

	if (Address == 0 && ShowError)
	{
		std::string ErrorMessage = "Error: Unable to find signature for patch: ";
		ErrorMessage += PatchName;
		MessageBoxA(NULL, ErrorMessage.c_str(), "MadnessPatch", MB_ICONERROR);
	}

	return Address;
}

static std::wstring FixPipeSpacing(const std::wstring& input)
{
	std::wstring result;
	result.reserve(input.length() * 2);
	size_t i = 0;

	// Skip leading pipes and spaces
	while (i < input.length() && (input[i] == L'|' || input[i] == L' ' || input[i] == L'\t'))
	{
		i++;
	}

	for (; i < input.length(); i++)
	{
		if (input[i] == L'|')
		{
			// Remove trailing spaces
			while (!result.empty() && result.back() == L' ')
			{
				result.pop_back();
			}

			result += L' ';
			result += L'|';

			// Skip spaces after pipe
			while (i + 1 < input.length() && (input[i + 1] == L' ' || input[i + 1] == L'\t'))
			{
				i++;
			}

			result += L' ';
		}
		else
		{
			result += input[i];
		}
	}

	// Remove trailing spaces
	while (!result.empty() && result.back() == L' ')
	{
		result.pop_back();
	}

	return result;
}

static void ReplaceConfigString(safetyhook::Context& ctx, const wchar_t* newString)
{
	std::wstring str(newString);
	bool wasModified = false;

	// Workaround for automatic movement 
	if (str == L"(Name=\"MoveForward\",Command=\"Axis aBaseY Speed=1.0\")")
	{
		str = L"(Name=\"MoveForward\",Command=\"Axis aBaseY Speed=1.0 | OnRelease Axis aBaseY Speed=0.0\")";
		wasModified = true;
	}

	// Check if this is a config line that needs pipe spacing fixes or command modifications
	if (str.find(L"(Name=") != std::wstring::npos && str.find(L",Command=") != std::wstring::npos)
	{
		// Find the Command=" part
		size_t commandPos = str.find(L",Command=\"");
		if (commandPos != std::wstring::npos)
		{
			commandPos += 10; // Move past ',Command="'

			// Find the closing quote
			size_t endQuotePos = str.find(L'"', commandPos);
			if (endQuotePos != std::wstring::npos)
			{
				// Extract the command value
				std::wstring commandValue = str.substr(commandPos, endQuotePos - commandPos);
				std::wstring originalCommandValue = commandValue;

				// Handle SkipCutscenesWithEnter
				if (SkipCutscenesWithEnter)
				{
					// Check if this is the SpaceBar binding
					if (str.find(L"(Name=\"SpaceBar\"") != std::wstring::npos)
					{
						// Remove "TryToCancelMatinee" from the command
						size_t pos = commandValue.find(L"TryToCancelMatinee");
						if (pos != std::wstring::npos)
						{
							size_t startPos = pos;
							size_t endPos = pos + wcslen(L"TryToCancelMatinee");

							// Remove trailing " | "
							if (endPos + 3 <= commandValue.length() && commandValue.substr(endPos, 3) == L" | ")
							{
								endPos += 3;
							}
							// Or remove leading " | "
							else if (startPos >= 3 && commandValue.substr(startPos - 3, 3) == L" | ")
							{
								startPos -= 3;
							}

							commandValue = commandValue.substr(0, startPos) + commandValue.substr(endPos);
						}
					}
					// Check if this is the Enter binding
					else if (str.find(L"(Name=\"Enter\"") != std::wstring::npos)
					{
						// Add "TryToCancelMatinee" if not already present
						if (commandValue.find(L"TryToCancelMatinee") == std::wstring::npos)
						{
							// Add to the beginning
							commandValue = L"TryToCancelMatinee | " + commandValue;
						}
					}
				}

				// Fix pipe spacing
				std::wstring fixedCommand = FixPipeSpacing(commandValue);

				// Check if anything changed
				if (fixedCommand != originalCommandValue)
				{
					str = str.substr(0, commandPos) + fixedCommand + str.substr(endQuotePos);
					wasModified = true;
				}
			}
		}
	}

	// Only allocate and update if the string was modified
	if (wasModified)
	{
		// Save original values for restoration
		g_pendingRestore.structAddr = ctx.ebx;
		g_pendingRestore.originalPtr = *(wchar_t**)(ctx.ebx + 0xC);
		g_pendingRestore.originalLength = *(int*)(ctx.ebx + 0x10);
		g_pendingRestore.originalCapacity = *(int*)(ctx.ebx + 0x14);
		g_pendingRestore.needsRestore = true;

		// Create our fixed string
		int newLength = str.length();
		auto fixedString = std::make_unique<wchar_t[]>(newLength + 1);
		wcscpy_s(fixedString.get(), newLength + 1, str.c_str());

		// Temporarily replace with our pointer
		*(wchar_t**)(ctx.ebx + 0xC) = fixedString.get();
		*(int*)(ctx.ebx + 0x10) = newLength;
		*(int*)(ctx.ebx + 0x14) = newLength;

		// Store to keep alive during memcpy
		g_tempFixedStrings.push_back(std::move(fixedString));
	}
	else
	{
		g_pendingRestore.needsRestore = false;
	}
}

static bool IsUALPresent()
{
	for (const auto& entry : std::stacktrace::current()) 
	{
		HMODULE hModule = NULL;
		if (GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, (LPCSTR)entry.native_handle(), &hModule)) 
		{
			if (GetProcAddress(hModule, "IsUltimateASILoader") != NULL)
				return true;
		}
	}

	return false;
}

#pragma endregion

#pragma region Hooks

// =========================
// FixHighFPSHairPhysics
// =========================

safetyhook::InlineHook HairSimulator;

static void __fastcall HairSimulator_Hook(void* thisPtr, int, float delta)
{
	g_State.frameTimeScale = TARGET_FRAME_TIME / delta;
	HairSimulator.unsafe_thiscall<void>(thisPtr, delta);
}

// ======================================
// FixHighFPSProjectileCollisionCheck
// ======================================

static SafetyHookInline RangeAttackPawnCollisionCheck{};

static void __fastcall RangeAttackPawnCollisionCheck_Hook(int thisPtr, float DeltaTime)
{
	DeltaTime = TARGET_FRAME_TIME;
	RangeAttackPawnCollisionCheck.unsafe_fastcall<void>(thisPtr, DeltaTime);
}

// =============================
// FixHashTableRaceCondition
// =============================

safetyhook::InlineHook Localize;

static DWORD __cdecl Localize_Hook(DWORD* a1, void* a2, const wchar_t* a3, int a4, wchar_t* String1, int a6)
{
	// Fix a race condition
	static std::mutex locMutex;
	std::lock_guard<std::mutex> lock(locMutex);
	return Localize.unsafe_ccall<DWORD>(a1, a2, a3, a4, String1, a6);
}

static SafetyHookInline SetRenderingState{};

static void __cdecl SetRenderingState_Hook(int a1, int a2)
{
	if (a1 == 0)
	{
		// Rendering is paused
		g_State.set40fps = true;
	}
	else
	{
		// Rendering is resumed
		g_State.set40fps = false;
	}

	SetRenderingState.unsafe_ccall<void>(a1, a2);
}

static SafetyHookInline GetMaxTickRate{};

static double __fastcall GetMaxTickRate_Hook(int thisp, int, float a2, int a3)
{
	if (g_State.set40fps != g_State.prev_set40fps)
	{
		if (g_State.set40fps)
		{
			// Save original FPS before setting to 40 (slow down loading at high fps)
			g_State.original_fps = *(float*)(thisp + 0x4A8);
			*(float*)(thisp + 0x4A8) = 40.0f;
		}
		else
		{
			// Restore original FPS
			*(float*)(thisp + 0x4A8) = g_State.original_fps;
		}
		g_State.prev_set40fps = g_State.set40fps;
	}

	return GetMaxTickRate.unsafe_thiscall<double>(thisp, a2, a3);
}

// ======================
// FixInputBinding
// ======================

safetyhook::InlineHook LoadStartupPackages;

static void __fastcall LoadStartupPackages_Hook()
{
	DWORD addr_InputFix = ScanModuleSignature(g_State.GameModule, "8B FB 8B 47 10 50 8B CE E8", "InputFix");

	if (addr_InputFix == 0)
	{
		LoadStartupPackages.fastcall<void>();
		return;
	}

	// Before memcpy, hijack the string if needed
	static SafetyHookMid iniInputFix{};
	iniInputFix = safetyhook::create_mid(addr_InputFix,
		[](safetyhook::Context& ctx)
		{
			const wchar_t* keyName = *(const wchar_t**)(ctx.ebx + 0xC);

			if (keyName)
			{
				ReplaceConfigString(ctx, keyName);
			}
		}
	);

	// After memcpy, restore the original data
	static SafetyHookMid iniInputFixPtrRestore{};
	iniInputFixPtrRestore = safetyhook::create_mid(addr_InputFix + 0x24,
		[](safetyhook::Context& ctx)
		{
			// Check if we need to restore anything
			if (g_pendingRestore.needsRestore)
			{
				// Restore the original pointer and values
				uintptr_t structAddr = g_pendingRestore.structAddr;
				*(wchar_t**)(structAddr + 0xC) = g_pendingRestore.originalPtr;
				*(int*)(structAddr + 0x10) = g_pendingRestore.originalLength;
				*(int*)(structAddr + 0x14) = g_pendingRestore.originalCapacity;
				g_pendingRestore.needsRestore = false;
			}
		}
	);

	// Only called at startup
	LoadStartupPackages.fastcall<void>();

	(void)iniInputFix.disable();
	(void)iniInputFixPtrRestore.disable();
}

// =======================
// FixWindowHandling
// =======================

safetyhook::InlineHook ProcessDeferredMessage;

static void __fastcall ProcessDeferredMessage_Hook(int thisPtr, int, int deferredMessage)
{
	DWORD* msg = (DWORD*)deferredMessage;
	UINT& messageType = ((UINT*)msg)[1];
	DWORD wParam = msg[2];

	// Alt+F4 change to WM_CLOSE
	if (messageType == WM_SYSKEYDOWN && wParam == VK_F4)
	{
		messageType = WM_CLOSE;
	}

	ProcessDeferredMessage.unsafe_thiscall<void>(thisPtr, deferredMessage);
}

safetyhook::InlineHook UpdateMouseLock;

static LONG __fastcall UpdateMouseLock_Hook(int thisPtr, int)
{
	HWND gameWindow = *(HWND*)(thisPtr + 0x68);  // Get window handle
	HWND foregroundWindow = GetForegroundWindow();

	// Only call original if window has focus
	if (gameWindow == foregroundWindow)
	{
		return UpdateMouseLock.unsafe_thiscall<LONG>(thisPtr);
	}

	// Not focused, release clip instead
	ClipCursor(nullptr);
	return 0;
}

// =======================
// Ini settings override
// =======================

safetyhook::InlineHook GetStringHook;

static unsigned int __fastcall FConfigCacheIni_GetString_Hook(int* thisp, int, const wchar_t* Section, const wchar_t* Key, int* Value, const wchar_t* Filename)
{
	if (Key)
	{
		auto it = g_configOverrides.find(Key);
		if (it != g_configOverrides.end() && *it->second.isEnabled)
		{
			// Prepare replacement string
			const wchar_t* newValue = it->second.value.c_str();
			size_t newLen = wcslen(newValue);
			auto newString = std::make_unique<wchar_t[]>(newLen + 1);
			wcscpy_s(newString.get(), newLen + 1, newValue);

			g_replacementString = newString.get();
			g_tempConfigStrings.push_back(std::move(newString));
		}
		else
		{
			g_replacementString = nullptr;
		}
	}

	int result = GetStringHook.thiscall<unsigned int>(thisp, Section, Key, Value, Filename);

	// Clear after use
	g_replacementString = nullptr;
	return result;
}

static SafetyHookMid ConfigStringReplace{};
static SafetyHookInline UpdateD3DDeviceFromViewports{};

static void __fastcall UpdateD3DDeviceFromViewports_Hook(int thisp, int)
{
	UpdateD3DDeviceFromViewports.thiscall<void>(thisp);

	// Permanent ini settings overriden, we don't need those hooks anymore
	(void)GetStringHook.disable();
	(void)ConfigStringReplace.disable();
	(void)UpdateD3DDeviceFromViewports.disable();
}

// ==================
// SkipIntro
// ==================

static SafetyHookMid SkipMovie{};
safetyhook::InlineHook FFullScreenMovieBink_PlayMovie;

static unsigned int __fastcall FFullScreenMovieBink_PlayMovie_Hook(int* thisp, int, int a2, const wchar_t* MovieFilename, int a4, int a5, int a6, int a7, unsigned int a8, int a9, WORD* Src)
{
	if (MovieFilename)
	{
		if (_wcsicmp(MovieFilename, L"LoadingMovie.bik\x00") == 0)
		{
			(void)FFullScreenMovieBink_PlayMovie.disable();
			(void)SkipMovie.disable();
		}
		else if (SkipEAIntro && _wcsicmp(MovieFilename, L"Intro_EA.bik\x00") == 0)
		{
			g_State.shouldSkipMovie = true;
		}
		else if (SkipSHIntro && _wcsicmp(MovieFilename, L"Intro_SH.bik\x00") == 0)
		{
			g_State.shouldSkipMovie = true;
		}
		else if (SkipUEIntro && _wcsicmp(MovieFilename, L"TechLogo_Short.bik\x00") == 0)
		{
			g_State.shouldSkipMovie = true;
		}
	}

	return FFullScreenMovieBink_PlayMovie.unsafe_thiscall<unsigned int>(thisp, a2, MovieFilename, a4, a5, a6, a7, a8, a9, Src);
}

// ===========================
// DisableMouseAcceleration
// ===========================

safetyhook::InlineHook UpdateAxisValue;

static int __fastcall UpdateAxisValue_Hook(DWORD thisp, int, float* a2, float a3)
{
	// Update 'isUsingGamepad' flag
	if (a3 != 0.0f)
	{
		uint32_t flags = *(uint32_t*)(thisp + 0xE4);
		g_State.isUsingGamepad = (flags & 0x1) != 0;
	}

	return UpdateAxisValue.unsafe_thiscall<int>(thisp, a2, a3);
}

// ===========================
// FixUltraWideScreenFOV
// ===========================

safetyhook::InlineHook PlayAnimation;

static void __fastcall PlayAnimation_Hook(int thisp, int, int a2)
{
	DWORD currentValue = *(DWORD*)(thisp + 0x238);
	g_State.isCutscene = ((currentValue & 0x20) != 0) && ((currentValue & 0x04) != 0);

	PlayAnimation.unsafe_thiscall<void>(thisp, a2);
}

// ============================
// ImprovedTextureStreaming
// ============================

safetyhook::InlineHook GetWantedMips;

static int __stdcall GetWantedMips_Hook(int a1, int a2, int a3, int a4)
{
	// Skip the timer
	return a4;
}

// ==========================
// ForceHighResTextures
// ==========================

static SafetyHookInline ShouldMipLevelsBeForcedResident{};

static bool __fastcall ShouldMipLevelsBeForcedResident_Hook(int thisp, int)
{
	return true;
}

// =====================================
// FixUltraWideScreenFOV & FontScaling
// =====================================

safetyhook::InlineHook SetBufferSize;

static void __fastcall SetBufferSize_Hook(int thisp, int, int InBufferSizeX, int InBufferSizeY)
{
	g_State.screenWidth = InBufferSizeX;
	g_State.screenHeight = InBufferSizeY;

	// baseHeight for subtitles = 768
	g_State.subtitlesScaleFactor = g_State.screenHeight / 768.0f;

	// Minimum 1.0x (768p and below)
	if (g_State.subtitlesScaleFactor < 1.0f) g_State.subtitlesScaleFactor = 1.0f;
	g_State.subtitlesScaleFactor *= FontScalingFactor;

	g_State.scaleFactor = g_State.screenWidth / g_State.screenHeight;

	if (FixUltraWideScreenFOV)
	{
		if (g_State.scaleFactor > ASPECT_RATIO_16_9)
		{
			// Update FOV/Viewport for Ultrawide
			MemoryHelper::WriteMemory<float>(g_State.pGEngine + 0x4A4, g_State.scaleFactor, false);
			g_State.updateFOV = true;

			float baseTan = tanf((90.0f * 0.5f) * (M_PI / 180.0f));
			g_State.FOVScale = 2.0f * atanf((g_State.scaleFactor / ASPECT_RATIO_16_9) * baseTan) * (180.0f / M_PI);
		}
		else
		{
			MemoryHelper::WriteMemory<float>(g_State.pGEngine + 0x4A4, ASPECT_RATIO_16_9, false);
			g_State.updateFOV = false;
		}
	}

	SetBufferSize.thiscall<void>(thisp, InBufferSizeX, InBufferSizeY);
}

#pragma endregion

#pragma region Init

static void ApplyFixHighFPSHairPhysics()
{
	if (!FixHighFPSHairPhysics) return;

	DWORD addr_HairSimulator = ScanModuleSignature(g_State.GameModule, "53 8B DC 51 83 E4 F0 83 C4 04 55 8B EC 81 EC E8 00 00 00 A1 ?? ?? ?? ?? 33 C5 89 45 FC 56 8B F1 57 8D 8D 20 FF FF FF", "HairSimulator");
	DWORD addr_DampingScaler = ScanModuleSignature(g_State.GameModule, "D9 EE D9 5D AC F3 0F 10 75 AC", "HairSimulator_DampingScaler");
	DWORD addr_DeltaTimeOverride = ScanModuleSignature(g_State.GameModule, "D9 43 08 B9 30 00 00 00 8D BD 20 FF FF FF", "HairSimulator_DeltaTimeOverride");

	if (addr_HairSimulator == 0 ||
		addr_DampingScaler == 0 ||
		addr_DeltaTimeOverride == 0) {
		return;
	}

	HairSimulator = HookHelper::CreateHook((void*)addr_HairSimulator, &HairSimulator_Hook);

	static SafetyHookMid hairDampingScaler{};
	hairDampingScaler = safetyhook::create_mid(addr_DampingScaler,
		[](safetyhook::Context& ctx)
		{
			// Scale damping factors
			ctx.xmm3.f32[0] = ctx.xmm3.f32[0] / g_State.frameTimeScale;
			ctx.xmm1.f32[0] = ctx.xmm1.f32[0] / g_State.frameTimeScale;
			ctx.xmm4.f32[0] = ctx.xmm4.f32[0] / g_State.frameTimeScale;
		}
	);

	static SafetyHookMid hairDeltaTimeOverride{};
	hairDeltaTimeOverride = safetyhook::create_mid(addr_DeltaTimeOverride,
		[](safetyhook::Context& ctx)
		{
			uint32_t ebx = ctx.ebx;

			float* deltaTime = (float*)(ebx + 0x8);
			g_State.savedHairDeltaTime = *deltaTime;
			*deltaTime = *deltaTime * g_State.frameTimeScale;
		}
	);

	static SafetyHookMid hairDeltaTimeRestore{};
	hairDeltaTimeRestore = safetyhook::create_mid(addr_DeltaTimeOverride + 0x8,
		[](safetyhook::Context& ctx)
		{
			uint32_t ebx = ctx.ebx;

			float* deltaTime = (float*)(ebx + 0x8);
			*deltaTime = g_State.savedHairDeltaTime;
		}
	);
}

static void ApplyFixHighFPSClothPhysics()
{
	if (!FixHighFPSClothPhysics) return;

	DWORD addr_ClothSimulator = ScanModuleSignature(g_State.GameModule, "F3 0F 10 4A 20 D9 43 08 F3 0F 10 52 28", "ClothSimulator_DeltaTimeOverride");

	if (addr_ClothSimulator == 0) return;

	static SafetyHookMid clothDeltaTimeOverride{};
	clothDeltaTimeOverride = safetyhook::create_mid(addr_ClothSimulator,
		[](safetyhook::Context& ctx)
		{
			uint32_t ebx = ctx.ebx;
			uint32_t edx = ctx.edx;

			float* deltaTime = (float*)(ebx + 0x8);
			g_State.savedClothDeltaTime = *deltaTime;

			if (*(float*)(edx + 0xAC) != 32.0f) // skip london dress
				*deltaTime = TARGET_FRAME_TIME;
		}
	);

	static SafetyHookMid clothDeltaTimeRestore{};
	clothDeltaTimeRestore = safetyhook::create_mid(addr_ClothSimulator + 0x14,
		[](safetyhook::Context& ctx)
		{
			uint32_t ebx = ctx.ebx;

			float* deltaTime = (float*)(ebx + 0x8);
			*deltaTime = g_State.savedClothDeltaTime;
		}
	);
}

static void ApplyFixHighFPSProjectileCollisionCheck()
{
	if (!FixHighFPSProjectileCollisionCheck) return;

	DWORD addr_RangeAttackPawnCollisionCheck = ScanModuleSignature(g_State.GameModule, "53 8B DC 83 EC 08 83 E4 F0 83 C4 04 55 8B 6B 04 89 6C 24 04 8B EC 6A FF 68 ?? ?? ?? ?? 64 A1 00 00 00 00 50 53 81 EC C8 01 00 00 56 57 A1 ?? ?? ?? ?? 33 C5 50 8D 45 F4 64 A3 00 00 00 00 A1", "RangeAttackPawnCollisionCheck");

	if (addr_RangeAttackPawnCollisionCheck == 0) return;

	RangeAttackPawnCollisionCheck = HookHelper::CreateHook((void*)addr_RangeAttackPawnCollisionCheck, &RangeAttackPawnCollisionCheck_Hook);
}

static void ApplyFixHighFPSRagdollDeath()
{
	if (!FixHighFPSRagdollDeath) return;

	DWORD addr_RagdollDeath = ScanModuleSignature(g_State.GameModule, "8B ?? 28 02 00 00 8B ?? 14 02 00 00 6A 01 50 6A 01 6A 01", "RagdollDeath");

	if (addr_RagdollDeath == 0) return;

	MemoryHelper::MakeNOP(addr_RagdollDeath, 0x18);
}

static void ApplyFixHashTableRaceCondition()
{
	if (!FixHashTableRaceCondition) return;

	DWORD addr_Localize = ScanModuleSignature(g_State.GameModule, "55 8B EC 6A FF 68 ?? ?? ?? ?? 64 A1 00 00 00 00 50 83 EC 2C 53 56 57 A1 ?? ?? ?? ?? 33 C5 50 8D 45 F4 64 A3 00 00 00 00 33 DB 89 5D EC 39 1D", "Localize");
	DWORD addr_hashLoop = ScanModuleSignature(g_State.GameModule, "83 C4 08 85 C0 74 1B 8B 03 8B 7C 06 54 83 FF FF 75 BC 8B 45 08 5F 5E C7 00 FF FF FF FF 5B 5D C2 08 00 8B 45 08 89 38 5F 5E 5B 5D C2 08", "HashLoop");
	DWORD addr_SetRenderingState = ScanModuleSignature(g_State.GameModule, "6A 02 6A 01 E8 ?? ?? ?? ?? 83 C4 08 C3", "SetRenderingState");
	addr_SetRenderingState = MemoryHelper::ResolveRelativeAddress(addr_SetRenderingState, 0x5);
	DWORD addr_SetFPSRate = ScanModuleSignature(g_State.GameModule, "55 8B EC 6A FF 68 ?? ?? ?? ?? 64 A1 00 00 00 00 50 83 EC 14 56 A1 ?? ?? ?? ?? 33 C5 50 8D 45 F4 64 A3 00 00 00 00 8B F1 C7 45 EC 00 00 00 00 F7", "GetMaxTickRate");

	if (addr_hashLoop == 0 ||
		addr_SetRenderingState == 0 ||
		addr_SetFPSRate == 0) {
		return;
	}

	Localize = HookHelper::CreateHook((void*)addr_Localize, &Localize_Hook);
	SetRenderingState = HookHelper::CreateHook((void*)addr_SetRenderingState, &SetRenderingState_Hook);
	GetMaxTickRate = HookHelper::CreateHook((void*)addr_SetFPSRate, &GetMaxTickRate_Hook);
	MemoryHelper::MakeNOP(addr_hashLoop + 0x10, 2);
}

static void ApplyFixInputBinding()
{
	if (!FixInputBinding) return;

	DWORD addr_LoadStartupPackages = ScanModuleSignature(g_State.GameModule, "55 8B EC 6A FF 68 ?? ?? ?? ?? 64 A1 00 00 00 00 50 83 EC ?? 53 56 57 A1 ?? ?? ?? ?? 33 C5 50 8D 45 F4 64 A3 00 00 00 00 8D 45 ?? 50 FF 15", "LoadStartupPackages");

	if (addr_LoadStartupPackages != 0)
	{
		LoadStartupPackages = HookHelper::CreateHook((void*)addr_LoadStartupPackages, &LoadStartupPackages_Hook);
	}
}

static void ApplyFixWindowHandling()
{
	if (!FixWindowHandling) return;

	DWORD addr_UpdateMouseLock = ScanModuleSignature(g_State.GameModule, "55 8B EC 83 EC 24 53 56 57 8B F1 FF 15", "UpdateMouseLock");
	DWORD addr_ProcessDeferredMessage = ScanModuleSignature(g_State.GameModule, "8B 11 8D 46 04 50 8B 42 5C FF D0", "ProcessDeferredMessage", 3);

	// Different patterns for different builds
	DWORD addr_BlockHookV1 = ScanModuleSignature(g_State.GameModule, "68 ?? ?? ?? ?? 53 53 68 ?? ?? ?? ?? 53 53 FF 15", "BlockHookV1", -1, false);
	DWORD addr_BlockHookV2 = ScanModuleSignature(g_State.GameModule, "68 ?? ?? ?? ?? 33 F6 56 56 68 ?? ?? ?? ?? 56 56 FF 15", "BlockHookV2", -1, false);

	DWORD addr_BlockMessages_1V1 = ScanModuleSignature(g_State.GameModule, "8B 15 ?? ?? ?? ?? 53 53 68 00 04 00 00 52 FF 15", "BlockMessages_1V1", -1, false);
	DWORD addr_BlockMessages_1V2 = ScanModuleSignature(g_State.GameModule, "A1 ?? ?? ?? ?? 6A 00 6A 00 68 00 04 00 00 50 FF 15", "BlockMessages_1V2", -1, false);
	DWORD addr_BlockMessages_2V1 = ScanModuleSignature(g_State.GameModule, "A1 ?? ?? ?? ?? 6A 00 6A 01 68 00 04 00 00 50 FF 15", "BlockMessages_2V1", -1, false);
	DWORD addr_BlockMessages_2V2 = ScanModuleSignature(g_State.GameModule, "A1 ?? ?? ?? ?? 52 6A 01 68 00 04 00 00 50 FF 15", "BlockMessages_2V2", -1, false);

	if (addr_UpdateMouseLock == 0 ||
		addr_ProcessDeferredMessage == 0) {
		return;
	}

	UpdateMouseLock = HookHelper::CreateHook((void*)addr_UpdateMouseLock, &UpdateMouseLock_Hook);
	ProcessDeferredMessage = HookHelper::CreateHook((void*)addr_ProcessDeferredMessage, &ProcessDeferredMessage_Hook);

	// Block hook creation
	if (addr_BlockHookV1)
	{
		MemoryHelper::MakeNOP(addr_BlockHookV1, 0x14);
		MemoryHelper::MakeNOP(addr_BlockHookV1 + 0x2B, 0x5);
	}
	else if (addr_BlockHookV2)
	{
		MemoryHelper::MakeNOP(addr_BlockHookV2, 0x16);
		MemoryHelper::MakeNOP(addr_BlockHookV2 + 0x2D, 0x5);
	}
	else
	{
		MessageBoxA(NULL, "Error: Unable to find signature for patch: BlockHook", "", MB_ICONERROR);
	}

	// Block thread messages
	if (addr_BlockMessages_1V1)
	{
		MemoryHelper::MakeNOP(addr_BlockMessages_1V1, 0x14);
	}
	else if (addr_BlockMessages_1V2)
	{
		MemoryHelper::MakeNOP(addr_BlockMessages_1V2, 0x15);
	}
	else
	{
		MessageBoxA(NULL, "Error: Unable to find signature for patch: BlockMessages_1", "", MB_ICONERROR);
	}

	if (addr_BlockMessages_2V1)
	{
		MemoryHelper::MakeNOP(addr_BlockMessages_2V1, 0x15);
		MemoryHelper::MakeNOP(addr_BlockMessages_2V1 + 0x23, 0x16);
	}
	else if (addr_BlockMessages_2V2)
	{
		MemoryHelper::MakeNOP(addr_BlockMessages_2V2, 0x14);
		MemoryHelper::MakeNOP(addr_BlockMessages_2V2 + 0x22, 0x16);
	}
	else
	{
		MessageBoxA(NULL, "Error: Unable to find signature for patch: BlockMessages_2", "", MB_ICONERROR);
	}
}

static void ApplyIniSettingsHook()
{
	DWORD addr_GetStringHook = ScanModuleSignature(g_State.GameModule, "55 8B EC 8B 45 14 83 EC 18 56 57 33 FF 57 50 E8", "GetStringHook");
	DWORD addr_UpdateD3DDeviceFromViewports = ScanModuleSignature(g_State.GameModule, "55 8B EC 6A FF 68 ?? ?? ?? ?? 64 A1 00 00 00 00 50 81 EC ?? 00 00 00 53 56 57 A1 ?? ?? ?? ?? 33 C5 50 8D 45 F4 64 A3 00 00 00 00 8B F1 6A 01 8D 4D", "UpdateD3DDeviceFromViewports");
	DWORD addr_ConfigStringReplace = ScanModuleSignature(g_State.GameModule, "56 E8 ?? ?? ?? ?? 5F B8 01 00 00 00 5E 8B E5 5D C2 10 00", "ConfigStringReplace");

	if (addr_GetStringHook == 0 ||
		addr_UpdateD3DDeviceFromViewports == 0 ||
		addr_ConfigStringReplace == 0) {
		return;
	}

	GetStringHook = HookHelper::CreateHook((void*)addr_GetStringHook, &FConfigCacheIni_GetString_Hook);
	UpdateD3DDeviceFromViewports = HookHelper::CreateHook((void*)addr_UpdateD3DDeviceFromViewports, &UpdateD3DDeviceFromViewports_Hook);

	ConfigStringReplace = safetyhook::create_mid(addr_ConfigStringReplace,
		[](safetyhook::Context& ctx)
		{
			if (g_replacementString)
			{
				ctx.esi = (uintptr_t)g_replacementString;
			}
		}
	);
}

static void ApplyIntroSkip()
{
	if (!SkipEAIntro && !SkipSHIntro && !SkipUEIntro) return;

	DWORD addr_PlayMovie = ScanModuleSignature(g_State.GameModule, "55 8B EC 6A FF 68 ?? ?? ?? ?? 64 A1 00 00 00 00 50 81 EC 2C 01 00 00 53 56 57 A1 ?? ?? ?? ?? 33 C5 50 8D 45 F4 64 A3 00 00 00 00 8B F1 89 75 E4 8B 8E C0 00 00 00", "PlayMovie");
	DWORD addr_SkipMovie = ScanModuleSignature(g_State.GameModule, "3B C7 0F 85 D0 00 00 00 6A 01 8B CB E8", "SkipMovie");

	if (addr_PlayMovie == 0 ||
		addr_SkipMovie == 0) {
		return;
	}

	FFullScreenMovieBink_PlayMovie = HookHelper::CreateHook((void*)addr_PlayMovie, &FFullScreenMovieBink_PlayMovie_Hook);

	SkipMovie = safetyhook::create_mid(addr_SkipMovie,
		[](safetyhook::Context& ctx)
		{
			if (g_State.shouldSkipMovie)
			{
				ctx.eax = 0;
				g_State.shouldSkipMovie = false;
			}
		}
	);
}

static void ApplyCheckAlice1InstallFolder()
{
	if (!CheckAlice1InstallFolder) return;

	DWORD addr_CheckAlice1InstallFolder1 = ScanModuleSignature(g_State.GameModule, "A1 ?? ?? ?? ?? 75 ?? B8 ?? ?? ?? ?? 50 FF 15", "CheckAlice1InstallFolder_1", -1, false);
	if (!addr_CheckAlice1InstallFolder1)
	{
		// DRM Builds
		addr_CheckAlice1InstallFolder1 = ScanModuleSignature(g_State.GameModule, "75 05 B8 ?? ?? ?? ?? 50 68 ?? ?? ?? ?? E8 ?? ?? ?? FF 83 C4 08", "CheckAlice1InstallFolder_2");

		if (addr_CheckAlice1InstallFolder1)
		{
			addr_CheckAlice1InstallFolder1 -= 0x12;
		}
	}
	else
	{
		addr_CheckAlice1InstallFolder1 += 0xC;
	}

	if (addr_CheckAlice1InstallFolder1 == 0) return;

	static SafetyHookMid checkAlice1{};
	checkAlice1 = safetyhook::create_mid(addr_CheckAlice1InstallFolder1,
		[](safetyhook::Context& ctx)
		{
			const wchar_t* pathStr = (const wchar_t*)ctx.eax;

			if (pathStr)
			{
				wchar_t currentDir[MAX_PATH];
				GetCurrentDirectoryW(MAX_PATH, currentDir);

				wchar_t fullPath[MAX_PATH];
				if (PathIsRelativeW(pathStr))
				{
					PathCombineW(fullPath, currentDir, pathStr);
				}
				else
				{
					wcscpy_s(fullPath, MAX_PATH, pathStr);
				}

				wchar_t canonicalPath[MAX_PATH];
				if (PathCanonicalizeW(canonicalPath, fullPath))
				{
					wcscpy_s(fullPath, MAX_PATH, canonicalPath);
				}

				DWORD attribs = GetFileAttributesW(fullPath);
				if (attribs == INVALID_FILE_ATTRIBUTES || !(attribs & FILE_ATTRIBUTE_DIRECTORY))
				{
					std::wstring errorMsg = L"Alice1 Directory Not Found!\n\n";
					errorMsg += L"The game is trying to set the working directory to a folder that doesn't exist.\n\n";
					errorMsg += L"Alice1Path Configuration ([AliceGame.AliceGameEngine]):\n";
					errorMsg += pathStr;
					errorMsg += L"\n\n";
					errorMsg += L"Resolved Full Path:\n";
					errorMsg += fullPath;
					errorMsg += L"\n\n";
					errorMsg += L"Please verify your Alice1 installation path in the configuration.";

					MessageBoxW(NULL, errorMsg.c_str(), L"Alice1 Directory Error", MB_OK | MB_ICONWARNING | MB_TOPMOST);
				}
			}
		}
	);
}

static void ApplyFontScaling()
{
	if (!FontScaling) return;

	DWORD addr_HeightFactor = ScanModuleSignature(g_State.GameModule, "D9 45 08 51 8D 45 E0 D9 1C 24 50 8D 4D 08", "FontScaling_HeightFactor");
	DWORD addr_Size = ScanModuleSignature(g_State.GameModule, "33 FF F6 86 20 01 00 00 01 89 55 AC", "FontScaling_Size");
	DWORD addr_LayoutMetrics = ScanModuleSignature(g_State.GameModule, "D9 45 E8 8B 77 1C 51 F3 0F 59 C1", "FontScaling_LayoutMetrics");
	DWORD addr_LineSpacing = ScanModuleSignature(g_State.GameModule, "0F 88 BC 01 00 00", "FontScaling_LineSpacing");

	if (addr_HeightFactor == 0 ||
		addr_Size == 0 ||
		addr_LayoutMetrics == 0 ||
		addr_LineSpacing == 0) {
		return;
	}

	static SafetyHookMid scaleHeightFactor{};
	scaleHeightFactor = safetyhook::create_mid(addr_HeightFactor,
		[](safetyhook::Context& ctx)
		{
			uint32_t ebp = ctx.ebp;
			float* scaling = (float*)(ebp - 0x1C);

			*scaling = g_State.subtitlesScaleFactor;
		}
	);

	static SafetyHookMid scaleSize{};
	scaleSize = safetyhook::create_mid(addr_Size,
		[](safetyhook::Context& ctx)
		{
			uint32_t ebx = ctx.ebx;
			float* scaling1 = (float*)(ebx + 0x24);
			float* scaling2 = (float*)(ebx + 0x28);

			*scaling1 = *scaling1 * g_State.subtitlesScaleFactor;
			*scaling2 = *scaling2 * g_State.subtitlesScaleFactor;
		}
	);

	static SafetyHookMid scaleLayoutMetrics{};
	scaleLayoutMetrics = safetyhook::create_mid(addr_LayoutMetrics,
		[](safetyhook::Context& ctx)
		{
			ctx.xmm1.f32[0] = g_State.subtitlesScaleFactor;
		}
	);

	static SafetyHookMid scaleLineSpacing{};
	scaleLineSpacing = safetyhook::create_mid(addr_LineSpacing,
		[](safetyhook::Context& ctx)
		{
			uint32_t ebp = ctx.ebp;
			float* scaling = (float*)(ebp - 0x14);

			*scaling = *scaling * g_State.subtitlesScaleFactor;
		}
	);
}

static void ApplyDisableMouseAcceleration()
{
	if (!DisableMouseAcceleration && !DisableControllerAcceleration) return;

	DWORD addr_UpdateAxisValue = ScanModuleSignature(g_State.GameModule, "55 8B EC F3 0F 10 45 0C 0F 2E 05", "UpdateAxisValue");
	DWORD addr_EngineVMOutput = ScanModuleSignature(g_State.GameModule, "F3 0F 58 45 08 8B 45 0C F3 0F 11 07 5F", "EngineVMOutput");

	if (addr_UpdateAxisValue == 0 ||
		addr_EngineVMOutput == 0) {
		return;
	}

	if (!DisableControllerAcceleration)
	{
		UpdateAxisValue = HookHelper::CreateHook((void*)addr_UpdateAxisValue, &UpdateAxisValue_Hook);
	}

	static SafetyHookMid scriptEngineVMOutput{};
	scriptEngineVMOutput = safetyhook::create_mid(addr_EngineVMOutput + 0xC,
		[](safetyhook::Context& ctx)
		{
			uint32_t edi = ctx.edi;

			if (!g_State.isUsingGamepad && g_State.pInput != 0 && ((g_State.pInput + 0x69C) == edi || (g_State.pInput + 0x6A0) == edi))
			{
				// Make the game think the camera has already moved
				*(float*)(edi) = 10.0f;
			}
		}
	);
}

static void ApplyFixUltraWideScreenFOV()
{
	if (!FixUltraWideScreenFOV) return;

	DWORD addr_PlayAnimation = ScanModuleSignature(g_State.GameModule, "55 8B EC 53 8B 5D 08 56 57 8B F9 8B 87 28 02 00 00", "PlayAnimation");
	DWORD addr_fovFix = ScanModuleSignature(g_State.GameModule, "D9 00 8B 4D 08 D9 19 5D C2 14 00 8B 51 50", "fovFix");

	if (addr_PlayAnimation == 0 ||
		addr_fovFix == 0) {
		return;
	}

	PlayAnimation = HookHelper::CreateHook((void*)addr_PlayAnimation, &PlayAnimation_Hook);

	static SafetyHookMid fovFix{};
	fovFix = safetyhook::create_mid(addr_fovFix,
		[](safetyhook::Context& ctx)
		{
			static float lastFOV = 0.0f;
			static float lastFOVCut = 0.0f;
			uint32_t eax = ctx.eax;

			if (g_State.updateFOV && g_State.pFOV != 0 && eax == g_State.pFOV)
			{
				float currentFOV = MemoryHelper::ReadMemory<float>(g_State.pFOV, false);

				if (currentFOV != lastFOV)
				{
					// London FOV
					if (currentFOV == 70.0f)
					{
						float scaledFOV = currentFOV * g_State.scaleFactor / ASPECT_RATIO_16_9;
						MemoryHelper::WriteMemory<float>(g_State.pFOV, scaledFOV, false);
						lastFOV = scaledFOV;
					}
					else
					{
						MemoryHelper::WriteMemory<float>(g_State.pFOV, g_State.FOVScale, false);
						lastFOV = g_State.FOVScale;
					}
				}
			}

			if (g_State.isCutscene && g_State.updateFOV && g_State.pFOVCut != 0 && eax == g_State.pFOVCut)
			{
				// Scale FOV with cutscene
				MemoryHelper::WriteMemory<float>(g_State.pFOVCut, g_State.FOVScale, false);
			}
		}
	);
}

static void ApplyImprovedTextureStreaming()
{
	if (ForceHighResTextures)
	{
		DWORD addr_ShouldMipLevelsBeForcedResident = ScanModuleSignature(g_State.GameModule, "55 8B EC 83 EC 08 56 8B F1 F6 86 18 01 00 00 18", "ShouldMipLevelsBeForcedResident");

		if (addr_ShouldMipLevelsBeForcedResident != 0)
		{
			ShouldMipLevelsBeForcedResident = HookHelper::CreateHook((void*)addr_ShouldMipLevelsBeForcedResident, &ShouldMipLevelsBeForcedResident_Hook);
		}
	}
	else if (ImprovedTextureStreaming)
	{
		// This is never called when 'ShouldMipLevelsBeForcedResident' is forced to true
		DWORD addr_GetWantedMips = ScanModuleSignature(g_State.GameModule, "55 8B EC 8B 45 08 DD 05", "GetWantedMips");

		if (addr_GetWantedMips != 0)
		{
			GetWantedMips = HookHelper::CreateHook((void*)addr_GetWantedMips, &GetWantedMips_Hook);
		}
	}
}

static void ApplyReducedMipMapBias()
{
	if (!ReducedMipMapBias) return;

	DWORD addr_MipMapBias = ScanModuleSignature(g_State.GameModule, "50 8B 82 14 01 00 00 6A 08 56 51 FF D0 0F 57 C9", "MipMapBias");

	if (addr_MipMapBias == 0) return;

	static SafetyHookMid mipmapbias{};
	mipmapbias = safetyhook::create_mid(addr_MipMapBias,
		[](safetyhook::Context& ctx)
		{
			ctx.eax = (float)-0.5f;
		}
	);
}

static void ApplyFixBinkVideoBT709()
{
	if (!FixBinkVideoBT709) return;

	DWORD addr_Gyuvtorgb = ScanModuleSignature(g_State.GameModule, "00 02 95 3F 00 43 CC 3F 00 00 00 00 40 E3 5E BF", "Gyuvtorgb");

	if (addr_Gyuvtorgb == 0) return;

	uint8_t BT709_Matrix[] =
	{
		// tor
		0x00, 0x02, 0x95, 0x3F,
		0xE1, 0x7A, 0xE5, 0x3F,
		0x00, 0x00, 0x00, 0x00,
		0x85, 0xEB, 0x78, 0xBF,

		// tog
		0x00, 0x02, 0x95, 0x3F,
		0x0A, 0xD7, 0x08, 0xBF,
		0xB6, 0xF3, 0x59, 0xBE,
		0x48, 0xE1, 0x9A, 0x3E,

		// tob
		0x00, 0x02, 0x95, 0x3F,
		0x00, 0x00, 0x00, 0x00,
		0x3D, 0x0A, 0x07, 0x40,
		0xDF, 0x4F, 0x91, 0xBF,

		// consts
		0x00, 0x00, 0x80, 0x3F,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00
	};

	// BT.601 -> BT.709
	MemoryHelper::WriteMemoryRaw(addr_Gyuvtorgb, BT709_Matrix, sizeof(BT709_Matrix));
}

static void ApplyResolutionHook()
{
	if (!FontScaling && !FixUltraWideScreenFOV) return;

	DWORD addr_GetGEnginePtr = ScanModuleSignature(g_State.GameModule, "E8 ?? ?? ?? ?? 83 C4 40 A3 ?? ?? ?? ?? 68", "GetGEnginePtr");
	DWORD addr_SetBufferSize = ScanModuleSignature(g_State.GameModule, "50 56 B9 ?? ?? ?? ?? E8 ?? ?? ?? ?? B9 ?? ?? ?? ?? E8 ?? ?? ?? ?? 8B 4D F4 64 89 0D 00 00 00 00 59 5F 5E 8B E5 5D C2 08 00", "SetBufferSize");
	addr_SetBufferSize = MemoryHelper::ResolveRelativeAddress(addr_SetBufferSize, 0x8);

	if (addr_GetGEnginePtr == 0 ||
		addr_SetBufferSize == 0) {
		return;
	}

	static SafetyHookMid GetGEnginePtr{};
	GetGEnginePtr = safetyhook::create_mid(addr_GetGEnginePtr + 0x8,
		[](safetyhook::Context& ctx)
		{
			g_State.pGEngine = ctx.eax;
		}
	);

	SetBufferSize = HookHelper::CreateHook((void*)addr_SetBufferSize, &SetBufferSize_Hook);
}

static void ApplyGetPointerHook()
{
	if (!DisableMouseAcceleration && !FixUltraWideScreenFOV) return;

	DWORD addr_PlayActorPtr = ScanModuleSignature(g_State.GameModule, "89 47 40 8B 45 ?? 88 5D FC 89 5D ?? 89 5D ?? 3B C3 74 0E 6A 01 50 E8 ?? ?? ?? ?? 83 C4 08 89 5D", "PlayActorPtr");
	DWORD addr_UpdatePlayActorPtr = ScanModuleSignature(g_State.GameModule, "?? ?? 2C 02 00 00 ?? ?? 14 06 00 00", "UpdatePlayActorPtr");

	if (addr_PlayActorPtr == 0 ||
		addr_UpdatePlayActorPtr == 0) {
		return;
	}

	static SafetyHookMid capturePlayActorPtr{};
	capturePlayActorPtr = safetyhook::create_mid(addr_PlayActorPtr,
		[](safetyhook::Context& ctx)
		{
			uint32_t eax = ctx.eax;
			if (g_State.pInput != eax)
			{
				g_State.pInput = eax;
				g_State.pFOV = MemoryHelper::ReadMemory<int>(g_State.pInput + 0x22C) + 0xA44;
				g_State.pFOVCut = MemoryHelper::ReadMemory<int>(g_State.pInput + 0x3C8) + 0x384;
			}
		}
	);

	static SafetyHookMid updateActorFOVPtr{};
	updateActorFOVPtr = safetyhook::create_mid(addr_UpdatePlayActorPtr,
		[](safetyhook::Context& ctx)
		{
			uint32_t esi = ctx.esi;
			if (g_State.pFOV != esi + 0xA44)
			{
				g_State.pFOV = esi + 0xA44;
			}
		}
	);
}

static void Init()
{
	ReadConfig();

	// Fixes
	ApplyFixHighFPSHairPhysics();
	ApplyFixHighFPSClothPhysics();
	ApplyFixHighFPSProjectileCollisionCheck();
	ApplyFixHighFPSRagdollDeath();
	ApplyFixHashTableRaceCondition();
	ApplyFixInputBinding();
	ApplyFixWindowHandling();

	// General
	ApplyIniSettingsHook();
	ApplyIntroSkip();
	ApplyCheckAlice1InstallFolder();

	// Display
	ApplyFontScaling();

	// Input
	ApplyDisableMouseAcceleration();

	// Graphics
	ApplyFixUltraWideScreenFOV();
	ApplyImprovedTextureStreaming();
	ApplyReducedMipMapBias();
	ApplyFixBinkVideoBT709();

	// Misc
	ApplyResolutionHook();
	ApplyGetPointerHook();
}

safetyhook::InlineHook hkCreateMutexW;
static HANDLE WINAPI CreateMutexW_Hook(LPSECURITY_ATTRIBUTES lpMutexAttributes, BOOL bInitialOwner, LPCWSTR lpName)
{
	if (!g_State.isInit && lpName != nullptr)
	{
		if (_wcsicmp(lpName, L"UnrealEngine3_3") == 0)
		{
			g_State.isInit = true; // Make sure to never enter this condition again
			g_State.GameModule = GetModuleHandleA(NULL);
			(void)hkCreateMutexW.disable();
			Init(); // Once when Steam/EA DRM is decrypted
		}
	}

	return hkCreateMutexW.stdcall<HANDLE, LPSECURITY_ATTRIBUTES, BOOL, LPCWSTR>(lpMutexAttributes, bInitialOwner, lpName);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
		{
			// Prevents DLL from receiving thread notifications
			DisableThreadLibraryCalls(hModule);

			// Verify timestamp
			uintptr_t base = (uintptr_t)GetModuleHandleA(NULL);
			IMAGE_DOS_HEADER* dos = (IMAGE_DOS_HEADER*)(base);
			IMAGE_NT_HEADERS* nt = (IMAGE_NT_HEADERS*)(base + dos->e_lfanew);
			DWORD timestamp = nt->FileHeader.TimeDateStamp;

			if (timestamp == 0x4D9DA4C5 || timestamp == 0x4DC8887C || timestamp == 0x4DC89913) // DRM Builds
			{
				MessageBoxA(NULL, "The DRM versions of the game is not currently supported.", "MadnessPatch", MB_ICONERROR);
			}
			else if (timestamp != 0x4DAC7482) // Current Steam/EA App version
			{
				MessageBoxA(NULL, "This .exe is not supported.", "MadnessPatch", MB_ICONERROR);
				return FALSE;
			}

			// Skip wrapper initialization when loaded as .asi
			if (!IsUALPresent())
			{
				SystemHelper::LoadProxyLibrary();
			}

			hkCreateMutexW = HookHelper::CreateHookAPI(L"kernel32.dll", "CreateMutexW", &CreateMutexW_Hook);
			break;
		}
		case DLL_PROCESS_DETACH:
		{
			break;
		}
	}
	return TRUE;
}

#pragma endregion
