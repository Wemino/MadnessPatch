#pragma once

// =============================
// Ini Variables
// =============================

// Fixes
inline bool FixHighFPSHairPhysics = false;
inline bool FixHighFPSClothPhysics = false;
inline bool FixHighFPSProjectileCollisionCheck = false;
inline bool FixHighFPSPhysX = false;
inline bool FixHighFPSWalkingPhysics = false;
inline bool CrashFixes = false;
inline bool FixCPUPhysX = false;
inline bool FixInputBinding = false;
inline bool FixWindowHandling = false;
inline bool HysteriaLockOnGuardEnabled = false;
inline bool FixStuckKeysEnabled = false;
inline bool FixMissingMusicEnabled = false;
inline bool FixMapPropertiesEnabled = false;
inline bool FixHatterElevatorEnabled = false;
inline bool FixFadeToBlackEnabled = false;
inline bool FixWeaponSwitchFadeInEnabled = false;
inline bool CutsceneFPSCapEnabled = false;
inline bool FixUpgradeCursorLeak = false;
inline bool FixPinballCannonPrompt = false;
inline bool AtomicSaves = false;
inline bool UpgradeToXAudio29 = false;
inline int MaxPoolThreads = 0;

// General
inline bool UnlockCompleteEditionDLC = false;
inline bool WarnAlice1InstallFolder = false;
inline bool HideAlice1WhenMissing = false;
inline bool SkipEAIntro = false;
inline bool SkipSHIntro = false;
inline bool SkipUEIntro = false;
inline bool EnableCrashHandler = false;
inline bool ShowProfileCreation = false;
inline bool AchievementSupport = false;
inline bool EnableConsole = false;

// Modding
inline bool DumpArchiveAssets = false;
inline bool LoadModFiles = false;

// Display
inline bool FontScaling = false;
inline float FontScalingFactor = 0;
inline bool AutoResolution = false;
inline bool UseWindowed = false;

// Input
inline bool UseSDLControllerInput = false;
inline bool EnableControllerIcons = false;
inline int UsePS3ControllerIcons = 0;
inline bool DisableMouseAcceleration = false;
inline bool DisableControllerAcceleration = false;
inline bool TouchpadEnabled = false;
inline bool InvertABXYButtons = false;
inline bool InvertShoulderTriggers = false;
inline bool DisableMouseSmoothing = false;
inline bool SkipCutscenesWithEnter = false;

// Graphics
inline int MaxFPS = 0;
inline bool ImprovedTextureStreaming = false;
inline bool ForceHighResTextures = false;
inline bool DisableBackgroundLevelStreaming = false;
inline bool FixAspectRatio = false;
inline bool ReducedMipMapBias = false;
inline bool FixBinkVideoBT709 = false;
inline bool AdaptivePhysXMemory = false;

inline void ReadConfig()
{
	IniHelper::Init();

	// Fixes
	FixHighFPSHairPhysics = IniHelper::ReadInteger("Fixes", "FixHighFPSHairPhysics", 1) == 1;
	FixHighFPSClothPhysics = IniHelper::ReadInteger("Fixes", "FixHighFPSClothPhysics", 1) == 1;
	FixHighFPSProjectileCollisionCheck = IniHelper::ReadInteger("Fixes", "FixHighFPSProjectileCollisionCheck", 1) == 1;
	FixHighFPSPhysX = IniHelper::ReadInteger("Fixes", "FixHighFPSPhysX", 1) == 1;
	FixHighFPSWalkingPhysics = IniHelper::ReadInteger("Fixes", "FixHighFPSWalkingPhysics", 1) == 1;
	CrashFixes = IniHelper::ReadInteger("Fixes", "CrashFixes", 1) == 1;
	FixCPUPhysX = IniHelper::ReadInteger("Fixes", "FixCPUPhysX", 1) == 1;
	FixInputBinding = IniHelper::ReadInteger("Fixes", "FixInputBinding", 1) == 1;
	FixWindowHandling = IniHelper::ReadInteger("Fixes", "FixWindowHandling", 1) == 1;
	HysteriaLockOnGuardEnabled = IniHelper::ReadInteger("Fixes", "HysteriaLockOnGuard", 1) == 1;
	FixStuckKeysEnabled = IniHelper::ReadInteger("Fixes", "FixStuckKeys", 1) == 1;
	FixMissingMusicEnabled = IniHelper::ReadInteger("Fixes", "FixMissingMusic", 1) == 1;
	FixMapPropertiesEnabled = IniHelper::ReadInteger("Fixes", "FixMapProperties", 1) == 1;
	FixHatterElevatorEnabled = IniHelper::ReadInteger("Fixes", "FixHatterElevator", 1) == 1;
	FixFadeToBlackEnabled = IniHelper::ReadInteger("Fixes", "FixFadeToBlack", 1) == 1;
	FixWeaponSwitchFadeInEnabled = IniHelper::ReadInteger("Fixes", "FixWeaponSwitchFadeIn", 1) == 1;
	CutsceneFPSCapEnabled = IniHelper::ReadInteger("Fixes", "CutsceneFPSCap", 1) == 1;
	FixUpgradeCursorLeak = IniHelper::ReadInteger("Fixes", "FixUpgradeCursorLeak", 1) == 1;
	FixPinballCannonPrompt = IniHelper::ReadInteger("Fixes", "FixPinballCannonPrompt", 1) == 1;
	AtomicSaves = IniHelper::ReadInteger("Fixes", "AtomicSaves", 1) == 1;
	UpgradeToXAudio29 = IniHelper::ReadInteger("Fixes", "UpgradeToXAudio29", 1) == 1;
	MaxPoolThreads = IniHelper::ReadInteger("Fixes", "MaxPoolThreads", 8);
	
	// General
	AchievementSupport = IniHelper::ReadInteger("General", "AchievementSupport", 1) == 1;
	UnlockCompleteEditionDLC = IniHelper::ReadInteger("General", "UnlockCompleteEditionDLC", 1) == 1;
	ShowProfileCreation = IniHelper::ReadInteger("General", "ShowProfileCreation", 1) == 1;
	WarnAlice1InstallFolder = IniHelper::ReadInteger("General", "WarnAlice1InstallFolder", 1) == 1;
	HideAlice1WhenMissing = IniHelper::ReadInteger("General", "HideAlice1WhenMissing", 1) == 1;
	EnableConsole = IniHelper::ReadInteger("General", "EnableConsole", 1) == 1;
	EnableCrashHandler = IniHelper::ReadInteger("General", "EnableCrashHandler", 1) == 1;
	SkipEAIntro = IniHelper::ReadInteger("General", "SkipEAIntro", 0) == 1;
	SkipSHIntro = IniHelper::ReadInteger("General", "SkipSHIntro", 1) == 1;
	SkipUEIntro = IniHelper::ReadInteger("General", "SkipUEIntro", 1) == 1;

	// Modding
	DumpArchiveAssets = IniHelper::ReadInteger("Modding", "DumpArchiveAssets", 0) == 1;
	LoadModFiles = IniHelper::ReadInteger("Modding", "LoadModFiles", 1) == 1;

	// Display
	FontScaling = IniHelper::ReadInteger("Display", "FontScaling", 1) == 1;
	FontScalingFactor = IniHelper::ReadFloat("Display", "FontScalingFactor", 1.0f);
	AutoResolution = IniHelper::ReadInteger("Display", "AutoResolution", 1) == 1;
	UseWindowed = IniHelper::ReadInteger("Display", "UseWindowed", 0) == 1;

	// Input
	UseSDLControllerInput = IniHelper::ReadInteger("Input", "UseSDLControllerInput", 1) == 1;
	EnableControllerIcons = IniHelper::ReadInteger("Input", "EnableControllerIcons", 1) == 1;
	UsePS3ControllerIcons = IniHelper::ReadInteger("Input", "UsePS3ControllerIcons", 0);
	DisableMouseAcceleration = IniHelper::ReadInteger("Input", "DisableMouseAcceleration", 1) == 1;
	DisableControllerAcceleration = IniHelper::ReadInteger("Input", "DisableControllerAcceleration", 1) == 1;
	TouchpadEnabled = IniHelper::ReadInteger("Input", "TouchpadEnabled", 0) == 1;
	InvertABXYButtons = IniHelper::ReadInteger("Input", "InvertABXYButtons", 1) == 1;
	InvertShoulderTriggers = IniHelper::ReadInteger("Input", "InvertShoulderTriggers", 1) == 1;
	DisableMouseSmoothing = IniHelper::ReadInteger("Input", "DisableMouseSmoothing", 0) == 1;
	SkipCutscenesWithEnter = IniHelper::ReadInteger("Input", "SkipCutscenesWithEnter", 1) == 1;

	// Graphics
	MaxFPS = IniHelper::ReadInteger("Graphics", "MaxFPS", 120);
	ForceHighResTextures = IniHelper::ReadInteger("Graphics", "ForceHighResTextures", 1) == 1;
	ImprovedTextureStreaming = IniHelper::ReadInteger("Graphics", "ImprovedTextureStreaming", 1) == 1;
	DisableBackgroundLevelStreaming = IniHelper::ReadInteger("Graphics", "DisableBackgroundLevelStreaming", 1) == 1;
	FixAspectRatio = IniHelper::ReadInteger("Graphics", "FixAspectRatio", 1) == 1;
	ReducedMipMapBias = IniHelper::ReadInteger("Graphics", "ReducedMipMapBias", 1) == 1;
	FixBinkVideoBT709 = IniHelper::ReadInteger("Graphics", "FixBinkVideoBT709", 1) == 1;
	AdaptivePhysXMemory = IniHelper::ReadInteger("Graphics", "AdaptivePhysXMemory", 1) == 1;

	if (UseSDLControllerInput)
	{
		auto [screenWidth, screenHeight] = SystemHelper::GetScreenResolution();
		ControllerHelper::SetTouchpadDimensions(screenWidth, screenHeight);
	}

	if (MaxPoolThreads < 1)
	{
		MaxPoolThreads = -1;
	}

	ControllerHelper::SetTouchpadEnabled(TouchpadEnabled);
}
