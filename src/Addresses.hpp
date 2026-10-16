#pragma once

enum class GameBuild
{
	Unknown = 0,
	Steam,
	EA,
	Current
};

enum class Addr
{
	// FixInputBinding
	InputFix,
	LoadStartupPackages,
	KeyCommandsLoad,
	KeyCommandsTable,

	// FixHighFPSHairPhysics
	HairSimulator,

	// FixHighFPSClothPhysics
	ClothSimulator,

	// FixHighFPSProjectileCollisionCheck
	RangeAttackPawnCollisionCheck,
	RangeAttackOverlapResult,

	// FixHighFPSPhysX
	TickWorldRBPhys,
	AddRBGravAndDamping,
	GetUnrealWorldTM,
	RagdollTransition,
	ApexBoneBufferWrite,
	ApexClothVertexWrite,
	PhysXParticleSync,
	PhysXParticleTick,
	PhysXEmitterStepSize,

	// FixHighFPSMovementsPhysics
	PawnPerformPhysics,
	GWorld,
	PawnFootIKWalking,
	PawnFootIKBlend,
	PawnFootIKEnd,
	PawnFootIKFalling,
	PawnFootIKMeshReset,
	PawnTickFootIKDone,
	TickActorComponents,
	CrowdAgentPerformPhysics,
	CrowdAgentTickSpecial,

	// FixHighFPSCamera
	ScriptProcessInternal,

	// Hash-table race condition
	Localize,
	HashLoop,
	HashLoopEntry,
	FStringFree,
	FStringAlloc,

	// Unattached-collision panic
	FixUnattachedCollisionPanic,

	// Hair-curve over-read
	FixHairCurveOverRead,

	// MMX over-read + spline-prefetch overrun
	MmxOverRead,
	SplinePrefetchOverrun,

	// FaceFX actor teardown
	FaceFxActorLoopGuard,
	FaceFxActorLoopExit,

	// Particle material destruction race
	ParticleMaterialDispatchSite,

	// PhysX fluid emptied before its release
	FluidRemoveAllParticles,

	// Present error treated as a lost device
	PresentResultCheck,

	// Trail index overflow
	Trail2FillIndexData,
	TrailOfBladeFillIndexData,

	// FixMorphTargets
	UpdateActiveMorphs,
	ChildFaceFXCall,
	UpdateMorphVertexBuffer,

	// MaxPoolThreads
	ThreadPoolCount,

	// FixWindowHandling
	UpdateMouseLock,
	ProcessDeferredMessage,
	BlockHook,
	BlockMessages_1,
	BlockMessages_2,
	GameWindowClassRegister,
	StartupShowWindowCmd,

	// IntroSkip
	PlayMovie,
	SkipMovie,

	// WarnAlice1InstallFolder
	WarnAlice1InstallFolder,

	// FontScaling
	FontScaling_HeightFactor,
	FontScaling_Size,
	FontScaling_LayoutMetrics,
	FontScaling_LineSpacing,

	// AutoResolution
	DocPath,
	ApplyAutoResolution,
	Width,
	Height,

	// FixAspectRatio
	GFxDrawIndexedTriList,

	// MenuScripts
	MenuScripts,

	// GFxLoadRootMovie
	GFxLoadRootMovie,

	// ImprovedTextureStreaming / ForceHighResTextures
	ShouldMipLevelsBeForcedResident,
	GetWantedMips,

	// TrilinearFiltering
	AnisotropicPointMipFilter,

	// DisableBackgroundLevelStreaming
	BackgroundLevelStreaming,

	// ImprovedBinkVideo
	Gyuvtorgb,
	DrawBinkTextures,
	BinkDrawCall,
	UpdateD3DDeviceBink,

	// FixCharacterLighting
	LightEnvStaticUpdate,

	// FixMSAAFog
	FogDrawCall,
	UpdateD3DDevice,

	// FixSlowLoading
	AsyncIOCacheHandles,
	AsyncIOCacheHandlesEnd,

	// FixStuckKeys
	PlayerInputInputKey,
	UInputInputKey,
	PlayerInputDisabled,

	// FixFadeToBlack
	GammaColorScale,

	// FixMapProperties
	AddToWorld,

	// FixBlurScaling
	GaussianBlurFilterBuffer,

	// ForceMSAA
	ActivateSystemSettings,

	// Supersampling
	ScaleScreenCoords,
	UnScaleScreenCoords,
	NeedsUpscale,
	ViewRectClamp,
	AllocateSceneTargets,
	AllocateSceneTargetsCommand,
	ResetSceneTargets,
	ViewTargetQuad,
	UpdateD3DDeviceRHI,

	// ResolutionHook
	UpdateViewportRHI,

	// EnginePointers
	PlayActorPtr,
	GetGEnginePtr,
	SetAlicePlayerController,
	SetConsole,
	EnginePostInit,

	// MainLoop
	EngineTick,
	ProcessEvent,

	// ScriptPatches
	GNatives,

	// FixMissingMusic
	LoadingBinkIsFinished,
	UpdateMusicTrack,

	// UseWindowed
	WindowedMode,
	Fullscreen,

	// BorderlessFullscreen
	ViewportForceBorderless,
	ViewportLayoutDone,

	// AchievementSupport
	PlayerControllerConsoleCommand,
	GameConsoleCommand,
	ActorConsoleCommand,
	MenuCursorRead,
	ProfileNameRead,
	PersistentLoaded,
	GameLanguageSet,
	GameLanguageName,

	// AtomicSaves
	FileWriterOpen,
	FileWriterDtor,

	// AdaptivePhysXMemory
	PhysXCreateSDK,
	GetSystemVRAM,

	// OverlapGPUPhysX
	DrawQueued,
	DrawQueuedWrap,
	BeginDrawingCommand,
	WaitPhysCompartments,
	FrameEndSync,
	RenderFenceWait,
	RingBufferAllocate,
	RenderCommandBuffer,
	PhysXSDK,
	AppSleep,

	// XAudio2Upgrade
	XAudio2CreateEngine,

	// Modding
	CachePaths,
	CacheDownloadedPackage,
	FindPackageFile,
	LinkerPreload,

	Count
};

namespace Addresses
{
	inline GameBuild g_build = GameBuild::Unknown;
	inline uintptr_t g_moduleBase = 0;

	// { Steam, EA, Current }
	inline constexpr uintptr_t kAddressTable[static_cast<size_t>(Addr::Count)][3] =
	{
		// FixInputBinding
		/* InputFix                        */ { 0x4815E1, 0x481371, 0x472D91 },
		/* LoadStartupPackages             */ { 0xC90080, 0xC90690, 0xC36AE0 },
		/* KeyCommandsLoad                 */ { 0xCFB9E0, 0xCFC050, 0xC95B20 },
		/* KeyCommandsTable                */ { 0x151E530, 0x151E530, 0x1497460 },

		// FixHighFPSHairPhysics
		/* HairSimulator                   */ { 0xBE4860, 0xBE4A70, 0xB99320 },

		// FixHighFPSClothPhysics
		/* ClothSimulator                  */ { 0xBE4DE0, 0xBE4FF0, 0xB99660 },

		// FixHighFPSProjectileCollisionCheck
		/* RangeAttackPawnCollisionCheck   */ { 0xD42A50, 0xD43030, 0xCD5A40 },
		/* RangeAttackOverlapResult        */ { 0xD42C49, 0xD43229, 0xCD5C39 },

		// FixHighFPSPhysX
		/* TickWorldRBPhys                 */ { 0x9E9700, 0x9E9D90, 0x9A7050 },
		/* AddRBGravAndDamping             */ { 0x9AC500, 0x9ACB80, 0x96A570 },
		/* GetUnrealWorldTM                */ { 0x99D270, 0x99D930, 0x95D830 },
		/* RagdollTransition               */ { 0xCA6A20, 0xCA6FC0, 0xC4BCD1 },
		/* ApexBoneBufferWrite             */ { 0xC11F90, 0xC12440, 0xBC30B0 },
		/* ApexClothVertexWrite            */ { 0xC1A700, 0xC1AA70, 0xBCAC70 },
		/* PhysXParticleSync               */ { 0xB732E0, 0xB734E0, 0xB28E40 },
		/* PhysXParticleTick               */ { 0xB69220, 0xB69360, 0xB1F6B0 },
		/* PhysXEmitterStepSize            */ { 0xB656F0, 0xB657B0, 0xB1B2C0 },

		// FixHighFPSMovementsPhysics
		/* PawnPerformPhysics              */ { 0x84D920, 0x84DC60, 0x81D890 },
		/* GWorld                          */ { 0x1509864, 0x1509864, 0x14835BC },
		/* PawnFootIKWalking               */ { 0x848AD4, 0x848E14, 0x8155A4 },
		/* PawnFootIKBlend                 */ { 0x848E63, 0x8491A3, 0x815933 },
		/* PawnFootIKEnd                   */ { 0x848FDA, 0x84931A, 0x815AAA },
		/* PawnFootIKFalling               */ { 0x848EFA, 0x84923A, 0x8159CA },
		/* PawnFootIKMeshReset             */ { 0x848FA8, 0x8492E8, 0x815A78 },
		/* PawnTickFootIKDone              */ { 0x84901E, 0x84935E, 0x815AEE },
		/* TickActorComponents             */ { 0x7BC550, 0x7BD1C0, 0x78C1D0 },
		/* CrowdAgentPerformPhysics        */ { 0xC32860, 0xC32B80, 0xBE2560 },
		/* CrowdAgentTickSpecial           */ { 0xC360C0, 0xC36540, 0xBE5D80 },

		// FixHighFPSCamera
		/* ScriptProcessInternal           */ { 0x4C36B0, 0x4C37E0, 0x4B1820 },

		// Hash-table race condition
		/* Localize                        */ { 0x4E9E80, 0x4EA250, 0x4D3ED0 },
		/* HashLoop                        */ { 0x47C093, 0x47C003, 0x46DE63 },
		/* HashLoopEntry                   */ { 0x47C049, 0x47BFB9, 0x46DE19 },
		/* FStringFree                     */ { 0x48C930, 0x48C6C0, 0x47B950 },
		/* FStringAlloc                    */ { 0x4116F0, 0x4115C0, 0x4107C0 },

		// Unattached-collision panic
		/* FixUnattachedCollisionPanic     */ { 0x7AF324, 0x7AFBC4, 0x77E824 },

		// Hair-curve over-read
		/* FixHairCurveOverRead            */ { 0xBE1514, 0xBE1734, 0xB95924 },

		// MMX over-read + spline-prefetch overrun
		/* MmxOverRead                     */ { 0x875DFE, 0x87613E, 0x83D2FE },
		/* SplinePrefetchOverrun           */ { 0xBE151E, 0xBE173E, 0xB9592E },

		// FaceFX actor teardown
		/* FaceFxActorLoopGuard            */ { 0x1053CF6, 0x10547B6, 0xFE0F46 },
		/* FaceFxActorLoopExit             */ { 0x1053D1C, 0x10547DC, 0xFE0F6C },

		// Particle material destruction race
		/* ParticleMaterialDispatchSite    */ { 0xBA65FD, 0xBA660D, 0xB583ED },

		// PhysX fluid emptied before its release
		/* FluidRemoveAllParticles         */ { 0xB76413, 0xB76613, 0xB2AA33 },

		// Present error treated as a lost device
		/* PresentResultCheck              */ { 0xC7B6A9, 0xC7BCF9, 0xC25149 },

		// Trail index overflow
		/* Trail2FillIndexData             */ { 0xBA9A80, 0xBA9AF0, 0xB5E200 },
		/* TrailOfBladeFillIndexData       */ { 0xBA9FC0, 0xBAA030, 0xB5E740 },

		// FixMorphTargets
		/* UpdateActiveMorphs              */ { 0x90F490, 0x90FB20, 0x8D54A0 },
		/* ChildFaceFXCall                 */ { 0x92257A, 0x922A1A, 0x8E68FA },
		/* UpdateMorphVertexBuffer         */ { 0x929480, 0x9298A0, 0x8ECEE0 },

		// MaxPoolThreads
		/* ThreadPoolCount                 */ { 0xC9107F, 0xC9169F, 0xC37B3A },

		// FixWindowHandling
		/* UpdateMouseLock                 */ { 0xC7E370, 0xC7E9B0, 0xC278C0 },
		/* ProcessDeferredMessage          */ { 0xC84370, 0xC848D0, 0xC2C800 },
		/* BlockHook                       */ { 0xC86A09, 0xC86F69, 0xC2EBD6 },
		/* BlockMessages_1                 */ { 0xC8019B, 0xC8073B, 0xC28E51 },
		/* BlockMessages_2                 */ { 0xC810AE, 0xC8164E, 0xC29BDE },
		/* GameWindowClassRegister         */ { 0x51EF34, 0x51F374, 0x501D22 },
		/* StartupShowWindowCmd            */ { 0x51F015, 0x51F455, 0x501E03 },

		// IntroSkip
		/* PlayMovie                       */ { 0x5942E0, 0x5949F0, 0x574380 },
		/* SkipMovie                       */ { 0x594A50, 0x595160, 0x574AF0 },

		// WarnAlice1InstallFolder
		/* WarnAlice1InstallFolder         */ { 0xC93019, 0xC936BD, 0xC397A5 },

		// FontScaling
		/* FontScaling_HeightFactor        */ { 0xA89213, 0xA89AB3, 0xA43BF3 },
		/* FontScaling_Size                */ { 0xA0B703, 0xA0C093, 0x9C7463 },
		/* FontScaling_LayoutMetrics       */ { 0xA899B1, 0xA8A251, 0xA44391 },
		/* FontScaling_LineSpacing         */ { 0x96A64B, 0x96ADBB, 0x92D48B },

		// AutoResolution
		/* DocPath                         */ { 0x480004, 0x47FE64, 0x470DB4 },
		/* ApplyAutoResolution             */ { 0x773EC6, 0x774BAF, 0x745E8D },
		/* Width                           */ { 0x14FE25C, 0x14FE25C, 0x1479884 },
		/* Height                          */ { 0x14FE260, 0x14FE260, 0x1479888 },

		// FixAspectRatio
		/* GFxDrawIndexedTriList           */ { 0xC5AE70, 0xC5B360, 0xC07FC0 },

		// MenuScripts
		/* MenuScripts                     */ { 0xF11D99, 0xF121A9, 0xE9EA29 },

		// GFxLoadRootMovie
		/* GFxLoadRootMovie                */ { 0xF429C0, 0xF42ED0, 0xECF8C0 },

		// ImprovedTextureStreaming / ForceHighResTextures
		/* ShouldMipLevelsBeForcedResident */ { 0x646220, 0x6469F0, 0x620FE0 },
		/* GetWantedMips                   */ { 0x6CC5E0, 0x6CCD60, 0x6A2110 },

		// TrilinearFiltering
		/* AnisotropicPointMipFilter       */ { 0xC72E9E, 0xC7353E, 0xC1DDCE },

		// DisableBackgroundLevelStreaming
		/* BackgroundLevelStreaming        */ { 0x9918DE, 0x991F4E, 0x95288E },

		// ImprovedBinkVideo
		/* Gyuvtorgb                       */ { 0x1421DC0, 0x1421DC0, 0x139ECE0 },
		/* DrawBinkTextures                */ { 0x6E1320, 0x6E1BF0, 0x6B5B30 },
		/* BinkDrawCall                    */ { 0x6E1792, 0x6E2062, 0x6B5FA2 },
		/* UpdateD3DDeviceBink             */ { 0xC782A8, 0xC788F8, 0xC220D1 },

		// FixCharacterLighting
		/* LightEnvStaticUpdate            */ { 0x593B59, 0x594269, 0x573B39 },

		// FixMSAAFog
		/* FogDrawCall                     */ { 0xAD1614, 0xAD1844, 0xA8A544 },
		/* UpdateD3DDevice                 */ { 0xC781F7, 0xC78847, 0xC220C7 },

		// FixSlowLoading
		/* AsyncIOCacheHandles             */ { 0x4AF3FE, 0x4AF51E, 0x49D4DE },
		/* AsyncIOCacheHandlesEnd          */ { 0x4AF477, 0x4AF597, 0x49D554 },

		// FixStuckKeys
		/* PlayerInputInputKey             */ { 0xA01890, 0xA01D40, 0x9BDBF0 },
		/* UInputInputKey                  */ { 0xA01670, 0xA01B20, 0x9BD9D0 },
		/* PlayerInputDisabled             */ { 0x150A020, 0x150A020, 0x1483B10 },

		// FixFadeToBlack
		/* GammaColorScale                 */ { 0x64BAE4, 0x64C1D4, 0x6290D4 },

		// FixMapProperties
		/* AddToWorld                      */ { 0x98F0D0, 0x98F740, 0x950400 },

		// FixBlurScaling
		/* GaussianBlurFilterBuffer        */ { 0xAECCD0, 0xAEC690, 0xAA4E00 },

		// ForceMSAA
		/* ActivateSystemSettings          */ { 0x621BB0, 0x621BF0, 0x5FE060 },

		// Supersampling
		/* ScaleScreenCoords               */ { 0x6258E0, 0x625A20, 0x600470 },
		/* UnScaleScreenCoords             */ { 0x625A00, 0x625B40, 0x600590 },
		/* NeedsUpscale                    */ { 0x621B80, 0x621BC0, 0x5FE030 },
		/* ViewRectClamp                   */ { 0xAFA565, 0xAF9E85, 0xAB1405 },
		/* AllocateSceneTargets            */ { 0xB0AB00, 0xB0A710, 0xAC5750 },
		/* AllocateSceneTargetsCommand     */ { 0xB0E490, 0xB0E280, 0xAC7160 },
		/* ResetSceneTargets               */ { 0xC784BF, 0xC78B0F, 0xC222DE },
		/* ViewTargetQuad                  */ { 0xAEDCAD, 0xAED66D, 0xAA5DDD },
		/* UpdateD3DDeviceRHI              */ { 0xC782A3, 0xC788F3, 0xC220CC },

		// ResolutionHook
		/* UpdateViewportRHI               */ { 0x6D73C0, 0x6D7B60, 0x6AD6E0 },

		// EnginePointers
		/* PlayActorPtr                    */ { 0x86497A, 0x864C2A, 0x8304B2 },
		/* GetGEnginePtr                   */ { 0xC9060F, 0xC90C1F, 0xC3712C },
		/* SetAlicePlayerController        */ { 0x65F7B0, 0x65FFB0, 0x63B330 },
		/* SetConsole                      */ { 0xC92CCE, 0xC932DE, 0xC39502 },
		/* EnginePostInit                  */ { 0xC90751, 0xC90D61, 0xC37267 },

		// MainLoop
		/* EngineTick                      */ { 0xC8F6C0, 0xC8FCD0, 0xC361F0 },
		/* ProcessEvent                    */ { 0x4C7840, 0x4C78F0, 0x4B5270 },

		// ScriptPatches
		/* GNatives                        */ { 0x1497D50, 0x1497D50, 0x1413520 },

		// FixMissingMusic
		/* LoadingBinkIsFinished           */ { 0x991CA5, 0x992315, 0x952C55 },
		/* UpdateMusicTrack                */ { 0x9759F0, 0x976180, 0x9372D0 },

		// UseWindowed
		/* WindowedMode                    */ { 0x773EB1, 0x774B9A, 0x745E78 },
		/* Fullscreen                      */ { 0x14FE264, 0x14FE264, 0x147988C },

		// BorderlessFullscreen
		/* ViewportForceBorderless         */ { 0xC80D39, 0xC812D9, 0xC29893 },
		/* ViewportLayoutDone              */ { 0xC80F96, 0xC81536, 0xC29ADF },

		// AchievementSupport
		/* PlayerControllerConsoleCommand  */ { 0x6DDE70, 0x6DE600, 0x6B32E0 },
		/* GameConsoleCommand              */ { 0x89AA50, 0x89AC70, 0x8610C0 },
		/* ActorConsoleCommand             */ { 0x728416, 0x728D36, 0x7021C6 },
		/* MenuCursorRead                  */ { 0xC7EAE0, 0xC7F120, 0xC27D80 },
		/* ProfileNameRead                 */ { 0xD00EB9, 0xD01509, 0xC9A8D8 },
		/* PersistentLoaded                */ { 0xD01190, 0xD017E0, 0xC9ABCA },
		/* GameLanguageSet                 */ { 0x51F613, 0x51FA53, 0x50233D },
		/* GameLanguageName                */ { 0x14F78C0, 0x14F78C0, 0x1472DE0 },

		// AtomicSaves
		/* FileWriterOpen                  */ { 0x47B520, 0x47B490, 0x46D3D0 },
		/* FileWriterDtor                  */ { 0x47E520, 0x47E5C0, 0x470880 },

		// AdaptivePhysXMemory
		/* PhysXCreateSDK                  */ { 0x9E80FF, 0x9E878F, 0x9A5607 },
		/* GetSystemVRAM                   */ { 0xC77592, 0xC77BE2, 0xC21576 },

		// OverlapGPUPhysX
		/* DrawQueued                      */ { 0x6DF968, 0x6E0118, 0x6B5298 },
		/* DrawQueuedWrap                  */ { 0x6DF994, 0x6E0144, 0x6B52C4 },
		/* BeginDrawingCommand             */ { 0x6CB3F0, 0x6CBB70, 0x6A1500 },
		/* WaitPhysCompartments            */ { 0x9D63C0, 0x9D6C10, 0x9941C0 },
		/* FrameEndSync                    */ { 0xC8D4F0, 0xC8DB00, 0xC34300 },
		/* RenderFenceWait                 */ { 0x60C6A0, 0x60CAB0, 0x5EA5E0 },
		/* RingBufferAllocate              */ { 0x48D510, 0x48D260, 0x47C900 },
		/* RenderCommandBuffer             */ { 0x14FD720, 0x14FD720, 0x1478AF8 },
		/* PhysXSDK                        */ { 0x1509A50, 0x1509A50, 0x14836E0 },
		/* AppSleep                        */ { 0x51A9B0, 0x51AEE0, 0x4FEF30 },

		// XAudio2Upgrade
		/* XAudio2CreateEngine             */ { 0xC87050, 0xC875B0, 0xC2F100 },

		// Modding
		/* CachePaths                      */ { 0x4F0110, 0x4F0390, 0x4D93B0 },
		/* CacheDownloadedPackage          */ { 0x4F02E0, 0x4F0560, 0x4D97D0 },
		/* FindPackageFile                 */ { 0x4EE4E0, 0x4EE760, 0x4D7EF0 },
		/* LinkerPreload                   */ { 0x4CE030, 0x4CE0E0, 0x4B6020 },
	};

	inline void SetBuild(GameBuild build, uintptr_t moduleBase)
	{
		g_build = build;
		g_moduleBase = moduleBase;
	}

	inline GameBuild GetBuild()
	{
		return g_build;
	}
}

inline uintptr_t GetAddress(Addr id)
{
	if (Addresses::g_build == GameBuild::Unknown)
		return 0;

	uintptr_t raw = Addresses::kAddressTable[static_cast<size_t>(id)][static_cast<int>(Addresses::g_build) - 1];
	if (raw == 0) return 0;

	return Addresses::g_moduleBase + (raw - 0x400000);
}