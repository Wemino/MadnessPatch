#pragma once

// Fixes
void ApplyFixHighFPSHairPhysics();
void ApplyFixHighFPSClothPhysics();
void ApplyFixHighFPSProjectileCollisionCheck();
void ApplyFixHighFPSPhysX();
void ApplyFixHighFPSMovementsPhysics();
void ResolveFixHighFPSMovementsPhysics();
void ApplyFixHighFPSCamera();
void ResolveFixHighFPSCamera();
uint32_t StepClothAtFixedRate(safetyhook::InlineHook& original, void* thisPtr, float delta);
void InstallPhysXStepping();
bool BeforeRBPhysTick();
void HoldRollingPushes(bool stepped, bool step);
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
void ApplyFixHatterElevator();
void ResolveScriptFixes();

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
void ResolveInputResponsiveness();
bool LookAccelerationDisabled(AAlicePlayerController* pc);
bool MouseSmoothingDisabled();

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
void ApplyScriptPatches();
void RefreshDLCWeapon();
int QueryCalloutPlatform();

// MainLoop
void ApplyMainLoopHooks();

namespace FixMissingMusic { void Tick(); }
namespace BlackBarGuard { void Tick(); }
namespace BlockCameraInMenu { void Tick(); }
namespace MenuMouseCursor { void Tick(); }
namespace HighFPSCamera { size_t BeforeEvent(UObject* object, UFunction* fn, void* params); void AfterEvent(size_t mark); }
