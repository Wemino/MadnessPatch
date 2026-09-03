#pragma once

// Fixes
void ApplyFixHighFPSHairPhysics();
void ApplyFixHighFPSClothPhysics();
void ApplyFixHighFPSProjectileCollisionCheck();
void ApplyFixHighFPSPhysX();
void ApplyFixHighFPSWalkingPhysics();
void ApplyCrashFixes();
void ApplyFixMissingMusic();
void ApplyFixCPUPhysX();
void ApplyFixInputBinding();
void ApplyFixWindowHandling();
void ApplyThreadPoolClamp();
void ApplyAtomicSaves();
void ApplyXAudio2Upgrade();

// General
void ApplyIntroSkip();
void ApplyWarnAlice1InstallFolder();
void ApplyAchievementSupport();
void UpdateAchievementProgress();

// Modding
void ApplyExportFiles();
void ApplyModFiles();

// Display
void ApplyFontScaling();
void ApplyAutoResolution();
void ApplyUseWindowed();

// Input
void ApplyUseSDLControllerInput();

// Graphics
void ApplyImprovedTextureStreaming();
void ApplyReducedMipMapBias();
void ApplyDisableBackgroundLevelStreaming();
void ApplyFixBinkVideoBT709();
void ApplyFixAspectRatio();
void ApplyMenuScripts();
void ApplyAdaptivePhysXMemory();
void ReapplyMenuLetterbox();

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
namespace FixStuckKeys { void Tick(); }
namespace FixMissingMusic { void Tick(); }
namespace FixMapProperties { void Tick(); }
namespace FixHatterElevator { void Tick(); }
namespace FixFadeToBlack { void Tick(); }
namespace CutsceneFPSCap
{
    void OnInterpStarted(USeqAct_Interp* mat);
    void OnInterpFinished(USeqAct_Interp* mat);
    void Tick();
}
namespace InputResponsiveness { void Tick(); }
namespace BlackBarGuard { void Tick(); }
namespace BlockCameraInMenu { void Tick(); }
