#pragma once

struct GlobalState
{
	// System initialization
	bool isInit = false;
	HMODULE GameModule = NULL;

	// Display configuration
	float screenHeight = 0.0f;
	float screenWidth = 0.0f;
	float subtitlesScaleFactor = 0.0f;
	float currentAspectRatio = 0.0f;

	// Engine Pointers
	AAlicePlayerController* AlicePlayerController = nullptr;
	AAlicePawn* AlicePawn = nullptr;
	UAliceGameEngine* AliceEngine = nullptr;

	// FOV
	bool isWideScreen = false;

	// Input
	bool isUsingGamepad = false;

	// Misc
	bool shouldBlockBlackBar = false;
	bool isAlice1Missing = false;
	bool loadEndPending = false;
	ULONGLONG loadEndTick = 0;
	bool bRealGameplay = false;

	// Crashfix sanity check
	uintptr_t CodeLo = 0;
	uintptr_t CodeHi = 0;
};

inline GlobalState g_State;

inline std::wstring g_docPath;

static constexpr float TARGET_FRAME_TIME = 1.0f / 30.0f;
static constexpr float ASPECT_RATIO_16_9 = 16.0f / 9.0f;

inline float ScaleFOV(float fovDeg, float sourceAspect, float targetAspect)
{
	float baseTan = tanf((float)((fovDeg * 0.5f) * (M_PI / 180.0f)));
	return (float)(2.0f * atanf((targetAspect / sourceAspect) * baseTan) * (180.0f / M_PI));
}