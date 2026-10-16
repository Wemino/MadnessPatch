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
	bool padConnected = false;
	XINPUT_GAMEPAD padState{};
	uint32_t gfxMovieLoads = 0;

	// Misc
	bool shouldBlockBlackBar = false;
	bool isAlice1Missing = false;
	bool loadEndPending = false;
	ULONGLONG loadEndTick = 0;
	bool bRealGameplay = false;

	// Crashfix sanity check
	uintptr_t CodeLo = 0;
	uintptr_t CodeHi = 0;

	// High FPS physics
	double physClock = 0.0;
	bool physSceneStepped = false;
	float physSceneAlpha = 1.0f;
	uint32_t physSceneStep = 0;
	double physSceneStepClock = 0.0;
	bool physSceneReleasing = false;
	double physSceneReleaseSince = 0.0;
	bool rollingMode = false;
};

inline GlobalState g_State;

inline std::wstring g_docPath;

static constexpr float TARGET_FRAME_TIME = 1.0f / 30.0f;
static constexpr float TARGET_FRAME_WINDOW = 0.002f; // frames this close to 1/30s run as the 30fps game runs them
static constexpr float MIN_WORLD_FRAME_TIME = 0.0005f; // UWorld::Tick never makes a frame shorter than this
static constexpr float TARGET_STEP_SLACK = 1.0e-6f; // rounding of the frame times
static constexpr int MAX_TARGET_STEPS = 30;
static constexpr float ASPECT_RATIO_16_9 = 16.0f / 9.0f;

inline float ScaleFOV(float fovDeg, float sourceAspect, float targetAspect)
{
	float baseTan = tanf((float)((fovDeg * 0.5f) * (M_PI / 180.0f)));
	return (float)(2.0f * atanf((targetAspect / sourceAspect) * baseTan) * (180.0f / M_PI));
}

inline bool GetRealFrameTime(AActor* actor, float deltaTime, float& realTime)
{
	if (!(deltaTime > 0.0f) || !actor->WorldInfo)
		return false;

	float timeDilation = actor->WorldInfo->TimeDilation;
	if (!(actor->CustomTimeDilation > 0.0f) || !(timeDilation * TARGET_FRAME_TIME >= MIN_WORLD_FRAME_TIME))
		return false;

	realTime = deltaTime / (timeDilation * actor->CustomTimeDilation);
	return true;
}

inline int CountTargetFrames(float realTime, float& carry, bool& own)
{
	own = realTime >= TARGET_FRAME_TIME - TARGET_FRAME_WINDOW;
	if (own)
	{
		carry = std::clamp(carry + realTime - TARGET_FRAME_TIME, -TARGET_FRAME_TIME, TARGET_FRAME_TIME);
		return 1;
	}

	carry += realTime;
	int frames = 0;
	while (carry >= TARGET_FRAME_TIME - 1e-5f)
	{
		carry -= TARGET_FRAME_TIME;
		frames++;
	}

	return frames;
}

struct TargetStep
{
	float realTime;
	float gameTime;
	bool landed;
};

inline TargetStep NextTargetStep(float accumulator, bool fullFrame, bool inStep, float frameTime, float deltaSeconds, float dilation)
{
	if (!fullFrame)
		return { TARGET_FRAME_TIME, TARGET_FRAME_TIME * dilation, false };

	if (inStep)
		return { frameTime, deltaSeconds, true };

	float wanted = accumulator - TARGET_FRAME_TIME;
	float stepTime = std::clamp(wanted, TARGET_FRAME_TIME - TARGET_FRAME_WINDOW, TARGET_FRAME_TIME + TARGET_FRAME_WINDOW);
	return { stepTime, stepTime * dilation, stepTime == wanted };
}