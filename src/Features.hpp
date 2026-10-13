#pragma once

// Fixes
void ApplyFixHighFPSHairPhysics();
void ApplyFixHighFPSClothPhysics();
void ApplyFixHighFPSProjectileCollisionCheck();
void ApplyFixHighFPSPhysX();
void ApplyFixHighFPSWalkingPhysics();
void ApplyCrashFixes();
void ApplyFixMissingMusic();
void ApplyFixInputBinding();
void ApplyFixKeyCommands();
void ApplyFixWindowHandling();
void ApplyThreadPoolClamp();
void ApplyAtomicSaves();
void ApplyXAudio2Upgrade();
void ApplyFixMorphTargets();
void ApplyFixCharacterLighting();
void ApplyFixMSAAFog();
void ApplyFixSlowLoading();
void ApplyFixStuckKeys();
void ApplyFixFadeToBlack();
void ApplyFixMapProperties();

// General
void ApplyIntroSkip();
void ApplyWarnAlice1InstallFolder();
void ApplyAchievementSupport();
void UpdateAchievementProgress();
void ApplyGameLanguage();

// Modding
void ApplyExportFiles();
void ApplyModFiles();

// Display
void ApplyFontScaling();
void ApplyAutoResolution();
void ApplyUseWindowed();
void ApplyBorderlessFullscreen();
void ApplyDPIAware();

// Input
void ApplyUseSDLControllerInput();

// Graphics
void ApplyImprovedTextureStreaming();
void ApplyTrilinearFiltering();
void ApplyDisableBackgroundLevelStreaming();
void ApplyImprovedBinkVideo();
void ApplyForceMSAA();
void ApplySupersampling();
void ApplyFixAspectRatio();
void ApplyMenuScripts();
void ApplyAdaptivePhysXMemory();
void ApplyOverlapGPUPhysX();
void ReapplyMenuLetterbox();
void ReapplyMemoryPosition();

// Engine
void ApplyResolutionHook();
void ApplyGetPointerHook();
void ApplyProcessEventHook();
void ResolveProcessEventFunctions();
void RefreshDLCWeapon();
int QueryCalloutPlatform();

// MainLoop
void ApplyMainLoopHooks();

namespace HysteriaLockOnGuard { void Tick(); }
namespace FixMissingMusic { void Tick(); }
namespace FixHatterElevator { void Tick(); }
namespace InputResponsiveness { void Tick(); }
namespace BlackBarGuard { void Tick(); }
namespace BlockCameraInMenu { void Tick(); }
namespace MenuMouseCursor { void Tick(); }
