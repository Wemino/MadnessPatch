#include "Common.hpp"
#include "Features.hpp"

using namespace ScriptHelper;

static safetyhook::InlineHook ScriptProcessInternal{};

// ---- Script functions ----

template <typename T>
static T& ScriptParm(Frame* stack, UProperty* parm)
{
	return *reinterpret_cast<T*>(stack->Locals + parm->Offset);
}

template <typename T>
static T* ScriptOutParm(Frame* stack, UProperty* parm)
{
	for (OutParmRec* out = stack->OutParms; out; out = out->Next)
	{
		if (out->Property == parm)
			return reinterpret_cast<T*>(out->PropAddr);
	}

	return nullptr;
}

struct CallSite
{
	const uint8_t* call = nullptr;
	const uint8_t* outerCall = nullptr;

	CallSite() = default;

	explicit CallSite(const Frame* stack)
	{
		const Frame* caller = stack ? stack->PreviousFrame : nullptr;
		call = caller ? caller->Code : nullptr;
		outerCall = caller && caller->PreviousFrame ? caller->PreviousFrame->Code : nullptr;
	}

	bool operator==(const CallSite& other) const { return call == other.call && outerCall == other.outerCall; }
};

using ScriptOverride = bool(*)(UObject* self, Frame* stack, void* result);

constexpr int MaxScriptOverrides = 16;
static UFunction* overriddenFunctions[MaxScriptOverrides] = {};
static ScriptOverride scriptOverrides[MaxScriptOverrides] = {};
static int scriptOverrideCount = 0;

static void RunScriptFunction(UObject* self, Frame* stack, void* result)
{
	const UStruct* node = stack->Node;
	for (int i = 0; i < scriptOverrideCount; i++)
	{
		if (overriddenFunctions[i] == node)
		{
			if (scriptOverrides[i](self, stack, result))
				return;

			break;
		}
	}

	ScriptProcessInternal.unsafe_thiscall<void>(self, stack, result);
}

static void __fastcall ScriptProcessInternal_Hook(UObject* self, void*, Frame* stack, void* result)
{
	RunScriptFunction(self, stack, result);
}

static bool OverrideScriptFunction(UFunction* fn, ScriptOverride handler)
{
	if (!fn)
		return false;

	for (int i = 0; i < scriptOverrideCount; i++)
	{
		if (overriddenFunctions[i] == fn)
			return scriptOverrides[i] == handler;
	}

	if (scriptOverrideCount >= MaxScriptOverrides)
		return false;

	overriddenFunctions[scriptOverrideCount] = fn;
	scriptOverrides[scriptOverrideCount] = handler;
	scriptOverrideCount++;
	return true;
}

// ---- Frames ----

constexpr int MaxFrameParts = 16; // a longer frame is split into this many 30fps frames at most
constexpr float StickEpsilon = 1.0f;
constexpr float PoiTurn = 600.0f;
constexpr float Unbounded = 3.0e38f; // a threshold every value passes, or none
constexpr float LookThreshold = 1.0f;
constexpr int LookSamples = 256;
constexpr int MaxSites = 64;
constexpr uint32_t SiteForgetFrames = 300;
constexpr float BlendEndTolerance = 1.0e-4f; // of a blend's weight
constexpr float MaxTurnUnits = 1.0e9f;
constexpr float UnsetCameraFloat = -998.0f;

struct FramePart
{
	float share = 1.0f; // of the frame's time and input
	float from = 0.0f;
	float to = 1.0f;
	bool ends = true; // the 30fps frame ends with the share
	float length = TARGET_FRAME_TIME; // the 30fps frame's real time
	float frameGameTime = 0.0f; // its game time up to the end of the share
	float expectedGameTime = 0.0f; // and as it is expected to end
};

struct FrameSplit
{
	bool own = false; // about 1/30s: a 30fps frame of its own
	uint32_t first30 = 0; // the 30fps frame of its first part
	int partCount = 0;
	FramePart parts[MaxFrameParts];
};

struct CameraFrame : FrameSplit
{
	float deltaTime = 0.0f; // game time, as the camera code gets it
	float realTime = 0.0f;
	uint32_t index = 0;
	bool valid = false;
};

struct FrameGrid
{
	bool active = false;
	double clock = 0.0; // real time, at the end of the last frame
	double start = 0.0;
	double end = 0.0;
	float gameTime = 0.0f; // its game time so far
	int frames = 0; // the frames in it
	uint32_t ended = 0; // 30fps frames ended
	bool lastSteady = false; // the last frame was of 1/30s, steadily
};

constexpr double GridEpsilon = 1.0e-9;
constexpr float SteadyFrameWindow = 0.0005f;

static CameraFrame frame;
static FrameGrid grid;

static void StartGrid(FrameGrid& g, double at)
{
	g.active = true;
	g.start = at;
	g.end = at + TARGET_FRAME_TIME;
	g.gameTime = 0.0f;
	g.frames = 0;
}

static void AddFramePart(FrameGrid& g, FrameSplit& split, double from, double to, bool ends, float share, float deltaTime, float gameRate)
{
	FramePart& part = split.parts[split.partCount++];
	const double length = g.end - g.start;
	g.gameTime += deltaTime * share;
	g.frames++;

	part.share = share;
	part.from = static_cast<float>((from - g.start) / length);
	part.to = ends ? 1.0f : static_cast<float>((to - g.start) / length);
	part.ends = ends;
	part.length = static_cast<float>(length);
	part.frameGameTime = g.gameTime;
	part.expectedGameTime = ends ? g.gameTime : std::max(g.gameTime, static_cast<float>(length) * gameRate);

	if (ends)
	{
		g.ended++;
		g.start = to;
		g.end += TARGET_FRAME_TIME;
		g.gameTime = 0.0f;
		g.frames = 0;
	}
}

static void SplitFrame(FrameGrid& g, FrameSplit& split, float realTime, float deltaTime)
{
	const float gameRate = deltaTime / realTime;
	const double start = g.clock;
	const double end = start + realTime;
	g.clock = end;

	split.own = false;
	split.partCount = 0;
	split.first30 = g.ended;

	const bool about30 = fabsf(realTime - TARGET_FRAME_TIME) <= TARGET_FRAME_WINDOW;
	const bool steadyFrame = fabsf(realTime - TARGET_FRAME_TIME) <= SteadyFrameWindow;
	const bool steady = steadyFrame && g.lastSteady;
	g.lastSteady = steadyFrame;

	const double snap = realTime >= TARGET_FRAME_TIME - TARGET_FRAME_WINDOW ? static_cast<double>(TARGET_FRAME_WINDOW) : GridEpsilon;
	if (g.active && g.frames > 0)
	{
		if (steady && start - g.start < 0.5 * (g.end - g.start))
		{
			AddFramePart(g, split, start, end, true, 1.0f, deltaTime, gameRate);
			g.active = false;
			return;
		}

		if (steady || g.end <= start + snap)
		{
			AddFramePart(g, split, start, start, true, 0.0f, deltaTime, gameRate); // the one under way ends where this frame starts
		}
	}

	if (!g.active || g.frames == 0)
	{
		if (about30)
		{
			split.own = true;
			g.start = start;
			g.end = end;
			g.gameTime = 0.0f;
			g.frames = 0;
			AddFramePart(g, split, start, end, true, 1.0f, deltaTime, gameRate);
			g.active = false;
			return;
		}

		if (!g.active)
		{
			StartGrid(g, start);
		}
	}

	double at = start;
	while (at < end - GridEpsilon)
	{
		const bool last = split.partCount == MaxFrameParts - 1; // a long hitch: the last one takes the rest
		const double boundary = g.end;
		const bool inside = !last && boundary <= end - snap;
		const double to = inside ? boundary : end;
		AddFramePart(g, split, at, to, inside || last || boundary <= end + snap, static_cast<float>((to - at) / realTime), deltaTime, gameRate);
		at = to;
		if (last)
		{
			StartGrid(g, end); // and the grid starts over after it
		}
	}
}

struct FrameTurn
{
	float total = 0.0f;
	int32_t passed = 0;

	int32_t To(float newTotal)
	{
		if (!(fabsf(newTotal) < MaxTurnUnits)) // not a number, or past any turn
			return 0;

		total = newTotal;
		const int32_t whole = static_cast<int32_t>(newTotal);
		const int32_t step = whole - passed;
		passed = whole;
		return step;
	}

	int32_t Add(float turn) { return To(total + turn); }
};

// ---- Look ----

static UFunction* fnModifyRotationSpeed = nullptr;
static UFunction* fnUpdateRotation = nullptr;
static UProperty* parmLookDeltaTime = nullptr;
static UProperty* parmLookUp = nullptr;
static UProperty* parmTurn = nullptr;
static UProperty* parmInterpDeltaAngle = nullptr;
static UProperty* parmInterpDeltaTime = nullptr;
static UProperty* parmInterpRotSpeed = nullptr;
static UProperty* parmInterpOut = nullptr;
static UProperty* parmInertiaOld = nullptr;
static UProperty* parmInertiaTarget = nullptr;
static UProperty* parmInertiaRate = nullptr;
static UProperty* parmInertiaDeltaTime = nullptr;
static UProperty* parmBlendDeltaAngle = nullptr;
static UProperty* parmBlendWeight = nullptr;
static UProperty* parmBlendOut = nullptr;
static UProperty* parmLockOnDeltaAngle = nullptr;
static UProperty* parmLockOnElapsed = nullptr;
static UProperty* parmLockOnBlendTime = nullptr;
static UProperty* parmLockOnOut = nullptr;
static UProperty* parmFPSDeltaTime = nullptr;
static UProperty* parmFPSEnter = nullptr;
static UProperty* parmShrinkDeltaTime = nullptr;
static UProperty* parmShrinkShrinking = nullptr;
static UProperty* parmShrinkForceSet = nullptr;
static UProperty* parmSmoothMouse = nullptr;
static UProperty* parmSmoothDeltaTime = nullptr;
static UProperty* parmSmoothCount = nullptr;
static UProperty* parmSmoothIndex = nullptr;
static bool smoothMouseFixed = false;

static float* stickEpsilon = nullptr; // StickEpsilon = 1.0
static float* poiTurnRight = nullptr; // aTurn > 0.5 * 600.0
static float* poiTurnLeft = nullptr; // aTurn < 0.5 * -600.0

static UFunction* fnPlayerTick = nullptr;
static bool resolved = false;

struct SetLiteral
{
	float* address;
	uint32_t original;
	uint32_t written;
};

static std::vector<SetLiteral> setLiterals;

static void SetFloat(float* literal, float value)
{
	SetLiteral set{ literal, 0, 0 };
	memcpy(&set.original, literal, sizeof(set.original));
	memcpy(&set.written, &value, sizeof(set.written));
	setLiterals.push_back(set);
	memcpy(literal, &value, sizeof(value));
}

struct LookSample
{
	double end; // real time
	float duration;
	float seen; // what the camera modifier compares, after the speed-up
};

struct LookAxis
{
	LookSample samples[LookSamples];
	int count = 0;
	int next = 0;
	const float* channel = nullptr; // aTurn, or aTurnInFPS while aiming

	float input = 0.0f;
	float heldBack = 0.0f;
	float passed = 0.0f;
	float gameTime = 0.0f;
	FrameTurn turn;

	float leftElapsed = 0.0f;
	bool changedElapsed = false;
	bool externalElapsed = false;
	float externalValue = 0.0f;
	float lastValue = 0.0f; // the input of the last frame
	bool hasInput = false; // the open 30fps frame has had input

	void Reset(const float* newChannel)
	{
		count = 0;
		next = 0;
		channel = newChannel;
		input = 0.0f;
		heldBack = 0.0f;
		passed = 0.0f;
		gameTime = 0.0f;
		turn = FrameTurn{};
		lastValue = 0.0f;
		hasInput = false;
	}

	void Push(const LookSample& sample)
	{
		samples[next] = sample;
		next = (next + 1) % LookSamples;
		if (count < LookSamples) count++;
	}

	float Window(double now, float duration, float current) const
	{
		float sum = current * std::min(1.0f, TARGET_FRAME_TIME / duration);
		const double start = now - TARGET_FRAME_TIME;
		for (int i = 1; i <= count; i++)
		{
			const LookSample& s = samples[(next - i + LookSamples) % LookSamples];
			if (s.end <= start)
				break;

			const double overlap = s.end - std::max(s.end - static_cast<double>(s.duration), start);
			sum += s.seen * static_cast<float>(overlap / s.duration);
		}

		return sum;
	}
};

static LookAxis turnAxis, lookUpAxis;
static double lookClock = 0.0;
static uint32_t lookFrame = 0;

static float LookSpeed(float elapsed, float accelTime, float accelExponent)
{
	float scale = elapsed / accelTime;
	scale = scale > 1.0f ? 1.0f : scale;
	return powf(scale, accelExponent);
}

static float EndLookFrame(LookAxis& axis, float& old, float& elapsed, float accelTime, float accelExponent)
{
	const float input = axis.input;
	float turn;
	if (fabsf(input) > LookThreshold && input * old >= 0.0f)
	{
		old = input;
		elapsed += axis.gameTime;
		turn = input * LookSpeed(elapsed, accelTime, accelExponent);
	}
	else
	{
		turn = input * old < 0.0f ? 0.0f : input;
		elapsed = 0.0f;
		old = 0.0f;
	}

	axis.input = 0.0f;
	axis.heldBack = 0.0f;
	axis.passed = 0.0f;
	axis.hasInput = false;
	return turn;
}

struct LookTurn
{
	float shaped = 0.0f; // the look input after the speed-up, passed on in this frame
	int32_t units = 0; // and the whole rotator units it turns
};

static LookTurn ShapeLook(LookAxis& axis, float value, bool fresh, bool oneByOne, float& old, float& elapsed, float accelTime, float accelExponent, float units)
{
	if (!fresh)
	{
		if (elapsed != axis.leftElapsed)
		{
			axis.externalElapsed = true;
			axis.externalValue = elapsed;
		}
		else if (axis.changedElapsed)
		{
			axis.externalElapsed = false;
		}
	}

	axis.changedElapsed = false;

	int wholePart = -1;
	const bool moveAfterNone = oneByOne && axis.lastValue == 0.0f;
	const bool twoParts = value != 0.0f && frame.partCount == 2 && frame.parts[0].share > 0.0f;
	if (oneByOne && twoParts && (!frame.parts[1].ends || moveAfterNone) && frame.realTime < 2.0f * TARGET_FRAME_TIME)
	{
		if (!axis.hasInput)
			wholePart = 0;
		else if (moveAfterNone)
			wholePart = 1;
		else
			wholePart = frame.parts[0].share >= 0.5f ? 0 : 1;
	}
	else if (!oneByOne && twoParts && !fresh && axis.lastValue == 0.0f && frame.realTime < 2.0f * TARGET_FRAME_TIME)
	{
		const bool first = frame.parts[0].share > 0.501f;
		wholePart = !first ? 1 : frame.realTime <= TARGET_FRAME_TIME + TARGET_FRAME_WINDOW ? 0 : -1;
	}

	axis.lastValue = value;

	LookTurn result;
	float rest = value;
	bool ended = false;
	float ruleElapsed = elapsed;
	for (int i = 0; i < frame.partCount; i++)
	{
		const FramePart& part = frame.parts[i];
		const bool last = i + 1 == frame.partCount;
		const float piece = wholePart >= 0 ? (i == wholePart ? value : 0.0f) : last ? rest : value * part.share;
		rest -= piece;
		axis.gameTime = part.frameGameTime;
		axis.input += piece;
		if (piece != 0.0f)
		{
			axis.hasInput = true;
		}

		if (piece * old < 0.0f)
		{
			axis.heldBack += piece;
		}
		else if (piece != 0.0f)
		{
			const float passed = piece * LookSpeed(elapsed + part.expectedGameTime, accelTime, accelExponent);
			axis.passed += passed;
			result.shaped += passed;
			result.units += axis.turn.To(axis.passed * units);
		}

		if (part.ends)
		{
			const float passed = axis.passed;
			const float turn = EndLookFrame(axis, old, elapsed, accelTime, accelExponent);
			result.shaped += turn - passed;
			result.units += axis.turn.To(turn * units);
			axis.turn = FrameTurn{};
			ended = true;
			ruleElapsed = elapsed;
			if (!last && axis.externalElapsed)
			{
				elapsed = axis.externalValue;
			}
		}
	}

	if (ended)
	{
		elapsed = ruleElapsed;
		axis.changedElapsed = true;
	}

	axis.leftElapsed = elapsed;
	return result;
}

static float TurnValue(const LookAxis& axis, int32_t units, float unitsPerValue)
{
	const float whole = static_cast<float>(units);
	const float rest = axis.turn.total - static_cast<float>(axis.turn.passed);
	return (units != 0 ? whole + copysignf(0.5f, whole) : rest * 0.5f) / unitsPerValue;
}

static void SetLookDecisions(float turnWindow, float lookUpWindow, bool poi)
{
	const bool stickFree = fabsf(turnWindow) <= StickEpsilon && fabsf(lookUpWindow) <= StickEpsilon;
	if (stickEpsilon)
	{
		SetFloat(stickEpsilon, stickFree ? Unbounded : -1.0f);
	}

	if (poi && poiTurnRight && poiTurnLeft)
	{
		SetFloat(poiTurnRight, turnWindow > 0.5f * PoiTurn ? -Unbounded : Unbounded);
		SetFloat(poiTurnLeft, turnWindow < -0.5f * PoiTurn ? Unbounded : -Unbounded);
	}
}

static bool ModifyRotationSpeed(UObject* self, Frame* stack, void*)
{
	AAlicePlayerController* pc = static_cast<AAlicePlayerController*>(self);
	float* aLookUp = ScriptOutParm<float>(stack, parmLookUp);
	float* aTurn = ScriptOutParm<float>(stack, parmTurn);
	UPlayerInput* input = pc->PlayerInput;
	if (!frame.valid || !aLookUp || !aTurn || !input || ScriptParm<float>(stack, parmLookDeltaTime) != frame.deltaTime)
		return false;

	const bool fresh = lookFrame + 1 != frame.index || turnAxis.channel != aTurn || lookUpAxis.channel != aLookUp;
	if (fresh)
	{
		turnAxis.Reset(aTurn);
		lookUpAxis.Reset(aLookUp);
	}

	lookFrame = frame.index;
	lookClock += frame.realTime;

	AAlicePawn* pawn = pc->MyAlicePawn;
	const float accelTime = pawn ? pawn->AliceCameraRevolAccelTime : 0.0f; // what the script reads through None
	const float accelExponent = pawn ? pawn->AliceCameraRevolAccelExponent : 0.0f;

	const bool fromUpdateRotation = stack->PreviousFrame && stack->PreviousFrame->Node == fnUpdateRotation;
	const float cameraSpeed = pawn ? pawn->CameraRotationSpeed : 1.0f;
	const float units = fromUpdateRotation ? cameraSpeed : 1.0f;
	const bool truncated = units > 0.0f && units < MaxTurnUnits;

	const bool wholeMoves = !input->bUsingGamepad && (!input->bEnableMouseSmoothing || smoothMouseFixed); // the game's smoothing spreads them
	const LookTurn turn = ShapeLook(turnAxis, *aTurn, fresh, wholeMoves, pc->aOldTurn, pc->aTurnElapsedTime, accelTime, accelExponent, truncated ? units : 1.0f);
	const LookTurn lookUp = ShapeLook(lookUpAxis, *aLookUp, fresh, wholeMoves, pc->aOldLookUp, pc->aLookUpElapsedTime, accelTime, accelExponent, truncated ? units : 1.0f);

	const float seenTurn = aTurn == &input->aTurn ? turn.shaped : input->aTurn;
	const float seenLookUp = aLookUp == &input->aLookUp ? lookUp.shaped : input->aLookUp;
	if (frame.own)
	{
		SetLookDecisions(seenTurn, seenLookUp, fromUpdateRotation);
	}
	else
	{
		SetLookDecisions(turnAxis.Window(lookClock, frame.realTime, seenTurn), lookUpAxis.Window(lookClock, frame.realTime, seenLookUp), fromUpdateRotation);
	}

	turnAxis.Push({ lookClock, frame.realTime, seenTurn });
	lookUpAxis.Push({ lookClock, frame.realTime, seenLookUp });

	if (truncated)
	{
		*aTurn = TurnValue(turnAxis, turn.units, units);
		*aLookUp = TurnValue(lookUpAxis, lookUp.units, units);
	}
	else
	{
		*aTurn = turn.shaped;
		*aLookUp = lookUp.shaped;
	}

	return true;
}

// ---- Rotations ----

struct SiteState
{
	CallSite site;
	uint32_t frameIndex = 0; // the frame it was last called in
	uint32_t frame30 = 0; // the 30fps frame its turns are in
	FrameTurn turn[3];
	int track = -1; // the blend it goes along with
	bool lagging = false; // it blends by a weight that lags by a frame
};

static SiteState sites[MaxSites];
static int siteCount = 0;

static SiteState& SiteOf(const Frame* stack)
{
	const CallSite site(stack);
	const int count = siteCount < MaxSites ? siteCount : MaxSites;
	SiteState* oldest = &sites[0];
	for (int i = 0; i < count; i++)
	{
		if (sites[i].site == site)
			return sites[i];

		if (sites[i].frameIndex < oldest->frameIndex) oldest = &sites[i];
	}

	SiteState& slot = count < MaxSites ? sites[count] : *oldest;
	siteCount = count < MaxSites ? count + 1 : count;
	slot = SiteState{};
	slot.site = site;
	slot.frameIndex = frame.index - SiteForgetFrames;
	slot.frame30 = frame.first30;
	return slot;
}

static SiteState& TurnSite(const Frame* stack)
{
	SiteState& state = SiteOf(stack);
	if (state.frame30 != frame.first30)
	{
		state.turn[0] = FrameTurn{};
		state.turn[1] = FrameTurn{};
		state.turn[2] = FrameTurn{};
		state.frame30 = frame.first30;
	}

	state.frameIndex = frame.index;
	return state;
}

static bool InterpolateRotation(UObject*, Frame* stack, void*)
{
	int32_t* out = ScriptOutParm<int32_t>(stack, parmInterpOut);
	const float deltaTime = ScriptParm<float>(stack, parmInterpDeltaTime);
	const int32_t rotSpeed = ScriptParm<int32_t>(stack, parmInterpRotSpeed);
	const int32_t deltaAngle = ScriptParm<int32_t>(stack, parmInterpDeltaAngle);
	if (!frame.valid || !out || rotSpeed < 0 || deltaAngle == 0 || deltaAngle == INT32_MIN)
		return false;

	SiteState& state = TurnSite(stack);
	const float angle = static_cast<float>(deltaAngle);
	const float turn = static_cast<float>(rotSpeed) * deltaTime * angle / fabsf(angle);
	int32_t total = 0;
	for (int i = 0; i < frame.partCount; i++)
	{
		total += state.turn[0].Add(turn * frame.parts[i].share);
		if (frame.parts[i].ends)
		{
			state.turn[0] = FrameTurn{};
		}
	}

	state.frame30 = grid.ended;

	if (abs(total) > abs(deltaAngle))
	{
		total = deltaAngle;
		state.turn[0] = FrameTurn{};
	}

	*out = total;
	return true;
}

static bool CameraRotInertia(UObject*, Frame* stack, void* result)
{
	const float rate = ScriptParm<float>(stack, parmInertiaRate);
	const float deltaTime = ScriptParm<float>(stack, parmInertiaDeltaTime);
	if (!frame.valid || !result || !(rate > 0.0f) || !(fabsf(deltaTime) < MaxTurnUnits))
		return false;

	SiteState& state = TurnSite(stack);
	FRotator rotation = ScriptParm<FRotator>(stack, parmInertiaOld);
	const FRotator target = ScriptParm<FRotator>(stack, parmInertiaTarget);
	for (int i = 0; i < frame.partCount; i++)
	{
		const FramePart& part = frame.parts[i];
		const float alpha = 1.0f - powf(0.98f, (50.0f / rate) * (deltaTime * part.share));
		auto axis = [alpha](FrameTurn& turn, int32_t& value, int32_t to)
		{
			const int32_t delta = FRotator::NormalizeAxis(static_cast<int32_t>(static_cast<uint32_t>(to) - static_cast<uint32_t>(value)));
			value = static_cast<int32_t>(static_cast<uint32_t>(value) + static_cast<uint32_t>(turn.Add(static_cast<float>(delta) * alpha)));
		};

		axis(state.turn[0], rotation.Pitch, target.Pitch);
		axis(state.turn[1], rotation.Yaw, target.Yaw);
		axis(state.turn[2], rotation.Roll, target.Roll);
		if (part.ends)
		{
			state.turn[0] = FrameTurn{};
			state.turn[1] = FrameTurn{};
			state.turn[2] = FrameTurn{};
		}
	}

	state.frame30 = grid.ended;
	*static_cast<FRotator*>(result) = rotation;
	return true;
}

// ---- Blends ----

struct BlendTrack
{
	int kind = 0; // the function blending (BlendKind), 0 for none
	bool lagging = false; // its weight lags by a frame: the time is added after the call
	uint32_t frameIndex = 0;
	float weight = 0.0f;
	float rate = 0.0f;
	uint32_t frames = 0; // the frames it moved in
	float frameWeight = 0.0f; // a lagging blend's weight in its open 30fps frame
	float left = 1.0f;
	FrameGrid grid;
	bool script = false;
	uint32_t first30 = 0;
	int partCount = 0;
	float shares[MaxFrameParts] = {};
	bool ends[MaxFrameParts] = {};
};

enum BlendKind { BlendBackOfPlayer = 1, BlendLockOn, BlendFPSSettings, BlendShrinkSettings, BlendAim };

constexpr int MaxTracks = 8;
constexpr float MaxStartWeight = 0.34f;

static BlendTrack tracks[MaxTracks];

static int FindTrack(int kind, bool lagging, float weight, const SiteState& site)
{
	auto fits = [=](const BlendTrack& t) { return t.kind == kind && t.lagging == lagging && t.weight <= weight && t.frameIndex != frame.index; };
	if (site.track >= 0 && fits(tracks[site.track]) && tracks[site.track].frameIndex + 1 == frame.index)
		return site.track;

	int going = -1, back = -1;
	for (int i = 0; i < MaxTracks; i++)
	{
		const BlendTrack& t = tracks[i];
		if (t.kind == kind && t.lagging == lagging && t.frameIndex == frame.index && t.weight == weight)
			return i;

		if (!fits(t))
			continue;

		int& best = t.frameIndex + 1 == frame.index ? going : back;
		if (best < 0 || t.weight > tracks[best].weight)
			best = i;
	}

	if (going >= 0)
		return going;

	if (site.track >= 0 && fits(tracks[site.track]))
		return site.track;

	return back;
}

static int NewTrack(int kind, bool lagging, float weight)
{
	int slot = 0;
	for (int i = 1; i < MaxTracks; i++)
	{
		if (frame.index - tracks[i].frameIndex > frame.index - tracks[slot].frameIndex) slot = i;
	}

	tracks[slot] = BlendTrack{};
	tracks[slot].kind = kind;
	tracks[slot].lagging = lagging;
	tracks[slot].frameWeight = weight;
	return slot;
}

static float BlendShare(float left, float leftAfter, float weight, bool whole)
{
	if (whole)
		return weight; // the 30fps frame in one: Lerp by its weight, as the script

	return left > 0.0f ? std::clamp(1.0f - leftAfter / left, -1.0f, 1.0f) : 0.0f;
}

static void MoveTrack(BlendTrack& track, float before, float weight, float lagGrowth, bool holdsAtEnd, float scale = 1.0f)
{
	FrameSplit split;
	SplitFrame(track.grid, split, frame.realTime, frame.deltaTime);
	track.script = false;
	track.first30 = split.first30;
	track.partCount = split.partCount;

	const float rate = (weight - before) / frame.realTime; // per second of real time
	float done = 0.0f; // of this frame
	for (int i = 0; i < split.partCount; i++)
	{
		const FramePart& part = split.parts[i];
		done += part.share;
		const bool last = i + 1 == split.partCount;

		float frameWeight;
		if (track.lagging)
			frameWeight = track.frameWeight;
		else if (part.ends)
			frameWeight = last ? weight : before + (weight - before) * done;
		else
			frameWeight = weight + rate * (1.0f - part.to) * part.length;

		frameWeight = std::clamp(frameWeight, 0.0f, 1.0f);
		if (holdsAtEnd && !(frameWeight < 1.0f - BlendEndTolerance))
			frameWeight = 0.0f;

		frameWeight *= scale;
		const float leftAfter = 1.0f - frameWeight * part.to;
		track.shares[i] = BlendShare(track.left, leftAfter, frameWeight, track.left == 1.0f && part.to == 1.0f);
		track.ends[i] = part.ends;
		track.left = leftAfter;
		if (part.ends)
		{
			track.left = 1.0f;
			track.frameWeight = weight + lagGrowth * done;
		}
	}

	track.frameIndex = frame.index;
	track.weight = weight;
	track.rate = rate;
	track.frames++;
}

static bool BlendRotation(const Frame* stack, int kind, int32_t deltaAngle, float weight, float startWeight, float lagGrowth, int32_t* out)
{
	SiteState& site = SiteOf(stack);
	site.frameIndex = frame.index;
	if (weight == 0.0f && lagGrowth > 0.0f)
	{
		site.lagging = true; // the lock-on yaw offset's blend starts at no weight
	}

	if (!(weight < 1.0f) || !(weight >= 0.0f) || !frame.valid)
	{
		site.track = -1;
		return false;
	}

	int index = FindTrack(kind, site.lagging, weight, site);
	if (index < 0 || tracks[index].frameIndex != frame.index)
	{
		float before;
		bool script = false;
		if (index >= 0 && tracks[index].frameIndex + 1 != frame.index && (tracks[index].frames < 2 || weight <= 1.5f * tracks[index].rate * frame.realTime))
		{
			index = -1;
		}

		if (index >= 0)
		{
			const BlendTrack& track = tracks[index];
			before = track.frameIndex + 1 == frame.index ? track.weight : std::max(track.weight, weight - track.rate * frame.realTime);
		}
		else
		{
			index = NewTrack(kind, site.lagging, weight);
			before = startWeight >= 0.0f ? std::min(startWeight, weight) : 0.0f;

			script = startWeight < 0.0f && !site.lagging && weight * TARGET_FRAME_TIME > MaxStartWeight * frame.realTime;
		}

		BlendTrack& track = tracks[index];
		if (script)
		{
			track.script = true;
			track.frameIndex = frame.index;
			track.weight = weight;
			track.rate = 0.0f;
		}
		else
		{
			MoveTrack(track, before, weight, lagGrowth, false);
		}
	}

	const BlendTrack& track = tracks[index];
	if (track.script)
	{
		site.track = index;
		site.frame30 = track.grid.ended - 1; // its turns start over with the next frame
		return false;
	}

	if (site.track != index || site.frame30 != track.first30)
	{
		site.turn[0] = FrameTurn{};
	}

	int32_t total = 0;
	for (int i = 0; i < track.partCount; i++)
	{
		total += site.turn[0].Add(static_cast<float>(deltaAngle - total) * track.shares[i]);
		if (track.ends[i])
		{
			site.turn[0] = FrameTurn{};
		}
	}

	site.track = index;
	site.frame30 = track.grid.ended;

	if (deltaAngle >= 0 ? total > deltaAngle : total < deltaAngle)
	{
		total = deltaAngle;
	}

	*out = total;
	return true;
}

static bool BlendCameraRotation(UObject*, Frame* stack, void*)
{
	int32_t* out = ScriptOutParm<int32_t>(stack, parmBlendOut);
	if (!out)
		return false;

	return BlendRotation(stack, BlendBackOfPlayer, ScriptParm<int32_t>(stack, parmBlendDeltaAngle), ScriptParm<float>(stack, parmBlendWeight), -1.0f, 0.0f, out);
}

static bool BlendLockOnRotation(UObject*, Frame* stack, void*)
{
	int32_t* out = ScriptOutParm<int32_t>(stack, parmLockOnOut);
	const float blendTime = ScriptParm<float>(stack, parmLockOnBlendTime);
	if (!out || !(blendTime > 0.0f))
		return false;

	const float elapsed = ScriptParm<float>(stack, parmLockOnElapsed);
	return BlendRotation(stack, BlendLockOn, ScriptParm<int32_t>(stack, parmLockOnDeltaAngle), elapsed / blendTime, std::max(elapsed - frame.deltaTime, 0.0f) / blendTime, frame.deltaTime / blendTime, out);
}

static BlendTrack fpsTrack;
static AAlicePawn* fpsPawn = nullptr;
static float fpsElapsed = 0.0f;

static bool BlendFPSCameraSettings(UObject* self, Frame* stack, void*)
{
	AAlicePawn* pawn = static_cast<AAlicePawn*>(self);
	const float fDeltaTime = ScriptParm<float>(stack, parmFPSDeltaTime);
	const bool bEnter = ScriptParm<uint32_t>(stack, parmFPSEnter) != 0;
	const float blendTime = pawn->FPSCamera.BlendTime;
	if (!frame.valid || !(fDeltaTime > 0.0f) || !(blendTime > 0.0f))
		return false;

	const float from = pawn->CameraElapsedBlendTime;
	const bool continued = fpsPawn == pawn && fpsTrack.frameIndex + 1 == frame.index && fpsElapsed <= from;
	const float before = continued ? fpsElapsed : from;
	const float elapsed = from + fDeltaTime; // as the script adds it
	fpsPawn = pawn;
	fpsElapsed = elapsed;
	if (!continued)
	{
		fpsTrack = BlendTrack{};
		fpsTrack.kind = BlendFPSSettings;
	}

	pawn->CameraElapsedBlendTime = elapsed;
	MoveTrack(fpsTrack, before / blendTime, elapsed / blendTime, 0.0f, true);

	const FAliceCameraProperties& target = bEnter ? pawn->FPSCamera : pawn->DefaultCamera;
	for (int i = 0; i < fpsTrack.partCount; i++)
	{
		const float share = fpsTrack.shares[i];
		pawn->AliceCameraDistance += share * (target.Distance - pawn->AliceCameraDistance);
		pawn->AliceCameraMaxDistance += share * (target.MaxDistance - pawn->AliceCameraMaxDistance);
		pawn->AliceCameraMinDistance += share * (target.MinDistance - pawn->AliceCameraMinDistance);
		pawn->AliceCameraOffset.X += share * (target.Offset.X - pawn->AliceCameraOffset.X);
		pawn->AliceCameraOffset.Y += share * (target.Offset.Y - pawn->AliceCameraOffset.Y);
		pawn->AliceCameraOffset.Z += share * (target.Offset.Z - pawn->AliceCameraOffset.Z);
	}

	if (!(elapsed < blendTime) && pawn->bCameraPreset && bEnter)
	{
		pawn->AliceCameraDistance = pawn->FPSCamera.Distance;
		pawn->AliceCameraMaxDistance = pawn->FPSCamera.MaxDistance;
		pawn->AliceCameraMinDistance = pawn->FPSCamera.MinDistance;
		pawn->AliceCameraFOV = pawn->AliceFPSCameraFOV;
	}

	if (pawn->bCameraPreset)
	{
		pawn->AliceCameraFOV = pawn->AliceFPSCameraFOV;
		pawn->AliceCameraOffset = pawn->FPSCamera.Offset;
	}

	return true;
}

static BlendTrack shrinkTrack;
static AAlicePawn* shrinkPawn = nullptr;
static float shrinkElapsed = 0.0f;
static bool shrinkShrinking = false;

static bool BlendShrinkCameraDistance(UObject* self, Frame* stack, void*)
{
	AAlicePawn* pawn = static_cast<AAlicePawn*>(self);
	const float fDeltaTime = ScriptParm<float>(stack, parmShrinkDeltaTime);
	const bool bShrinking = ScriptParm<uint32_t>(stack, parmShrinkShrinking) != 0;
	const bool bForceSet = ScriptParm<uint32_t>(stack, parmShrinkForceSet) != 0;
	const float speed = bShrinking ? pawn->ShrinkSpeed : pawn->UnShrinkSpeed;
	if (bForceSet || !frame.valid || !(fDeltaTime > 0.0f) || !(speed > 0.0f))
	{
		shrinkPawn = nullptr;
		return false;
	}

	const float from = pawn->CameraElapsedBlendTime;
	const bool continued = shrinkPawn == pawn && shrinkShrinking == bShrinking && shrinkTrack.frameIndex + 1 == frame.index && shrinkElapsed <= from;
	const float before = continued ? shrinkElapsed : from;
	const float elapsed = from + fDeltaTime; // as the script adds it
	shrinkPawn = pawn;
	shrinkElapsed = elapsed;
	shrinkShrinking = bShrinking;
	if (!continued)
	{
		shrinkTrack = BlendTrack{};
		shrinkTrack.kind = BlendShrinkSettings;
	}

	pawn->CameraElapsedBlendTime = elapsed;
	const float weight = std::clamp(elapsed / speed, 0.0f, 1.0f);
	MoveTrack(shrinkTrack, std::clamp(before / speed, 0.0f, 1.0f), weight, 0.0f, false);

	const FAliceCameraProperties& target = bShrinking ? pawn->ShrinkCamera : pawn->DefaultCamera;
	const float eyeHeight = bShrinking ? pawn->ShrinkBaseEyeHeight : static_cast<AAlicePawn*>(pawn->Class->ClassDefaultObject)->BaseEyeHeight;
	pawn->BaseEyeHeight += weight * (eyeHeight - pawn->BaseEyeHeight);

	const bool distance = !bShrinking || pawn->ShrinkCamera.Distance > UnsetCameraFloat;
	const bool maxDistance = !bShrinking || pawn->ShrinkCamera.MaxDistance > UnsetCameraFloat;
	const bool minDistance = !bShrinking || pawn->ShrinkCamera.MinDistance > UnsetCameraFloat;
	for (int i = 0; i < shrinkTrack.partCount; i++)
	{
		const float share = shrinkTrack.shares[i];
		if (distance) pawn->AliceCameraDistance += share * (target.Distance - pawn->AliceCameraDistance);
		if (maxDistance) pawn->AliceCameraMaxDistance += share * (target.MaxDistance - pawn->AliceCameraMaxDistance);
		if (minDistance) pawn->AliceCameraMinDistance += share * (target.MinDistance - pawn->AliceCameraMinDistance);
	}

	return true;
}

static struct
{
	BlendTrack track;
	AAlicePawn* pawn = nullptr;
	float weight = 0.0f;
	float alpha = 0.0f; // the frame's, for another call in the same frame
} aimBlend;

static void LockOnAimBlend(Site& site, Frame* stack, void* result)
{
	float deltaTime;
	AAlicePawn* pawn = static_cast<AAlicePawn*>(stack->Object);
	if (!result || !pawn || !SiteDeltaTime(site, stack, deltaTime))
		return;

	float& alpha = *reinterpret_cast<float*>(result);
	const float blendTime = pawn->CameraBlendTime;
	const float weight = alpha;
	if (!frame.valid || !(blendTime > 0.0f) || !(weight >= 0.0f) || !(weight < 1.0f) || pawn->bMiddleModeBlend)
	{
		aimBlend.pawn = nullptr;
		return;
	}

	if (aimBlend.pawn == pawn && aimBlend.track.frameIndex == frame.index)
	{
		alpha = aimBlend.alpha;
		return;
	}

	float frameShare = 1.0f, share30 = 1.0f;
	if (pawn->CamLocDelay > 0.0f)
	{
		const float rate = 50.0f / pawn->CamLocDelay;
		frameShare = 1.0f - powf(0.98f, rate * deltaTime);
		share30 = 1.0f - powf(0.98f, rate * TARGET_FRAME_TIME * frame.deltaTime / frame.realTime);
		if (!(frameShare > 1.0e-6f))
		{
			aimBlend.pawn = nullptr;
			return;
		}
	}

	const bool continued = aimBlend.pawn == pawn && aimBlend.track.frameIndex + 1 == frame.index && aimBlend.weight <= weight;
	const float before = continued ? aimBlend.weight : std::max(weight - frame.deltaTime / blendTime, 0.0f);
	if (!continued)
	{
		aimBlend.track = BlendTrack{};
		aimBlend.track.kind = BlendAim;
	}

	MoveTrack(aimBlend.track, before, weight, 0.0f, false, share30);

	float left = 1.0f;
	for (int i = 0; i < aimBlend.track.partCount; i++)
	{
		left *= 1.0f - aimBlend.track.shares[i];
	}

	aimBlend.pawn = pawn;
	aimBlend.weight = weight;
	aimBlend.alpha = frame.own ? weight : (1.0f - left) / frameShare;
	alpha = aimBlend.alpha;
}

// Middle = VLerp(OldLockOnAimTarget, Middle, CameraElapsedBlendTime / CameraBlendTime)
static const Expect lockOnAim[] =
{
	{ 0, Token::Divide_FloatFloat },
	{ 1, Token::InstanceVariable, Expect::Member, "CameraElapsedBlendTime", &AAlicePawn::StaticClass },
	{ 10, Token::InstanceVariable, Expect::Member, "CameraBlendTime", &AAlicePawn::StaticClass },
	{ -9, Token::LocalVariable, Expect::Local, "Middle" },
	{ -18, Token::InstanceVariable, Expect::Member, "OldLockOnAimTarget", &AAlicePawn::StaticClass },
};

static const SiteSpec lockOnAimSite = { "Function AliceGame.AlicePawn.AdjustCombatCameraRotation", lockOnAim, std::size(lockOnAim), &LockOnAimBlend, "Function AliceGame.AlicePawn.AdjustCombatCameraRotation", "fDeltaTime" };

// ---- Mouse smoothing ----

constexpr float SmoothResetTime = 0.25f;
constexpr int MaxSmoothCatchUp = 8;

struct SmoothAxis
{
	uint32_t frame30 = 0;
	bool moved = false;
	float moves = 0.0f;
	float smoothed = 0.0f;
	float zeroTime = 0.0f;
};

static UPlayerInput* smoothInput = nullptr;
static SmoothAxis smoothAxes[2];
static float samplingTotal = 0.0f;
static int32_t samplingCount = 1;

static float SamplingTime()
{
	return samplingCount > 0 ? samplingTotal / static_cast<float>(samplingCount) : samplingTotal;
}

static void EndSmoothFrames(SmoothAxis& axis, uint32_t at30)
{
	for (int n = 0; axis.frame30 != at30; n++)
	{
		if (n == MaxSmoothCatchUp)
		{
			axis.smoothed = 0.0f;
			axis.zeroTime = SmoothResetTime;
			axis.frame30 = at30;
			break;
		}

		const float sampling = SamplingTime();
		if (axis.moved)
		{
			const bool longFrame = axis.smoothed != 0.0f && !(TARGET_FRAME_TIME < sampling * 2.0f);
			axis.smoothed = axis.moves / (longFrame ? static_cast<float>(static_cast<uint8_t>(TARGET_FRAME_TIME / sampling)) : 1.0f);
			axis.zeroTime = 0.0f;
		}
		else
		{
			axis.zeroTime += TARGET_FRAME_TIME;
			if (!(axis.zeroTime < sampling))
			{
				axis.smoothed = 0.0f;
			}
		}

		axis.moved = false;
		axis.moves = 0.0f;
		axis.frame30++;
	}
}

static bool SmoothMouse(UObject* self, Frame* stack, void* result)
{
	uint8_t* count = ScriptOutParm<uint8_t>(stack, parmSmoothCount);
	const int32_t index = ScriptParm<int32_t>(stack, parmSmoothIndex);
	if (!result || !count || index < 0 || index > 1)
		return false;

	UPlayerInput* input = static_cast<UPlayerInput*>(self);
	if (input != smoothInput || input->MouseSamplingTotal != samplingTotal || input->MouseSamples != samplingCount)
	{
		smoothInput = input;
		for (int i = 0; i < 2; i++)
		{
			smoothAxes[i] = SmoothAxis{};
			smoothAxes[i].frame30 = grid.ended;
			smoothAxes[i].smoothed = input->SmoothedMouse[i];
			smoothAxes[i].zeroTime = input->ZeroTime[i];
		}

		samplingTotal = input->MouseSamplingTotal;
		samplingCount = input->MouseSamples;
	}

	const float move = ScriptParm<float>(stack, parmSmoothMouse);
	const float deltaTime = ScriptParm<float>(stack, parmSmoothDeltaTime);
	SmoothAxis& axis = smoothAxes[index];

	if (!frame.valid || frame.own || !(deltaTime < SmoothResetTime))
	{
		EndSmoothFrames(axis, frame.valid && frame.own ? grid.ended - 1 : grid.ended);
		if (index == 0 && move != 0.0f && axis.smoothed > 0.0f)
		{
			samplingTotal += deltaTime;
			samplingCount++;
		}

		input->SmoothedMouse[index] = axis.smoothed;
		input->ZeroTime[index] = axis.zeroTime;
		input->MouseSamplingTotal = samplingTotal;
		input->MouseSamples = samplingCount;
		ScriptProcessInternal.unsafe_thiscall<void>(self, stack, result);

		if (!(deltaTime < SmoothResetTime))
		{
			smoothAxes[1 - index].smoothed = 0.0f; // ClearSmoothing
			smoothAxes[1 - index].zeroTime = 0.0f;
		}

		axis.smoothed = input->SmoothedMouse[index];
		axis.zeroTime = input->ZeroTime[index];
		axis.frame30 = grid.ended;
		axis.moved = false;
		axis.moves = 0.0f;
		samplingTotal = input->MouseSamplingTotal;
		samplingCount = input->MouseSamples;
		input->SmoothedMouse[index] = 0.0f; // the engine measures nothing itself
		return true;
	}

	int most = 0;
	for (int i = 1; i < frame.partCount; i++)
	{
		if (frame.parts[i].share > frame.parts[most].share) most = i;
	}

	uint32_t at30 = frame.first30;
	for (int i = 0; i < most; i++)
	{
		if (frame.parts[i].ends) at30++;
	}

	EndSmoothFrames(axis, at30);

	float out = move;
	if (move != 0.0f)
	{
		if (!axis.moved && index == 0 && axis.smoothed > 0.0f)
		{
			samplingTotal += TARGET_FRAME_TIME; // the engine's measuring, of the 30fps frame's move
			samplingCount++;
		}

		const float sampling = SamplingTime();
		if (axis.smoothed != 0.0f && TARGET_FRAME_TIME < sampling * 2.0f)
		{
			out = move * TARGET_FRAME_TIME / sampling;
		}

		axis.moved = true;
		axis.moves += out;
	}

	input->SmoothedMouse[index] = 0.0f;
	input->ZeroTime[index] = axis.zeroTime;
	input->MouseSamplingTotal = samplingTotal;
	input->MouseSamples = samplingCount;
	*count = 0;
	*static_cast<float*>(result) = out;
	return true;
}

// ---- Player tick ----

static void BeforePlayerTick(AAlicePlayerController* pc, float deltaTime)
{
	frame.index++;
	frame.valid = false;
	frame.partCount = 0;

	float realTime;
	if (!GetRealFrameTime(pc, deltaTime, realTime))
	{
		if (grid.active && grid.frames > 0)
		{
			grid.ended++;
		}

		grid.active = false;
		grid.lastSteady = false;
		return;
	}

	frame.deltaTime = deltaTime;
	frame.realTime = realTime;
	frame.valid = true;
	SplitFrame(grid, frame, realTime, deltaTime);

	if (frame.own)
		return;

	const float scale = realTime / TARGET_FRAME_TIME;
	if (stickEpsilon) SetFloat(stickEpsilon, StickEpsilon * scale);
	if (poiTurnRight) SetFloat(poiTurnRight, PoiTurn * scale);
	if (poiTurnLeft) SetFloat(poiTurnLeft, -PoiTurn * scale);
}

size_t HighFPSCamera::BeforeEvent(UObject* object, UFunction* fn, void* params)
{
	const size_t mark = setLiterals.size();
	if (resolved && fn == fnPlayerTick && object && params)
	{
		BeforePlayerTick(static_cast<AAlicePlayerController*>(object), *static_cast<float*>(params));
	}

	return mark;
}

void HighFPSCamera::AfterEvent(size_t mark)
{
	while (setLiterals.size() > mark)
	{
		const SetLiteral set = setLiterals.back();
		setLiterals.pop_back();

		uint32_t now;
		memcpy(&now, set.address, sizeof(now));
		if (now == set.written)
		{
			memcpy(set.address, &set.original, sizeof(set.original));
		}
	}
}

void ApplyFixHighFPSCamera()
{
	if (!FixHighFPSCamera) return;

	ScriptProcessInternal = HookHelper::CreateHook((void*)GetAddress(Addr::ScriptProcessInternal), &ScriptProcessInternal_Hook);
}

void ResolveFixHighFPSCamera()
{
	if (!FixHighFPSCamera) return;

	fnModifyRotationSpeed = UFunction::FindFunction("Function AliceGame.AlicePlayerController.ModifyRotationSpeed");
	fnUpdateRotation = UFunction::FindFunction("Function AliceGame.AlicePlayerController.UpdateRotation");
	UFunction* fnInterpolateRotation = UFunction::FindFunction("Function AliceGame.AlicePlayerCamera.InterpolateRotation");
	UFunction* fnRotInertia = UFunction::FindFunction("Function AliceGame.AlicePlayerCamera.CameraRotInertiaFunction");
	UFunction* fnBlend = UFunction::FindFunction("Function AliceGame.AliceCamMod_BackOfPlayer.BlendCameraRotation");
	UFunction* fnLockOnBlend = UFunction::FindFunction("Function AliceGame.AliceCamMod_Targeting.BlendCameraRotation");
	UFunction* fnFPSSettings = UFunction::FindFunction("Function AliceGame.AlicePawn.BlendFPSCameraSettings");
	UFunction* fnSmoothMouse = UFunction::FindFunction("Function Engine.PlayerInput.SmoothMouse");

	parmLookDeltaTime = FindProperty(fnModifyRotationSpeed, "DeltaTime", false);
	parmLookUp = FindProperty(fnModifyRotationSpeed, "aLookUp", false);
	parmTurn = FindProperty(fnModifyRotationSpeed, "aTurn", false);
	if (parmLookDeltaTime && parmLookUp && parmTurn)
	{
		OverrideScriptFunction(fnModifyRotationSpeed, &ModifyRotationSpeed);
	}

	parmInterpDeltaAngle = FindProperty(fnInterpolateRotation, "DeltaAngle", false);
	parmInterpDeltaTime = FindProperty(fnInterpolateRotation, "DeltaTime", false);
	parmInterpRotSpeed = FindProperty(fnInterpolateRotation, "RotSpeed", false);
	parmInterpOut = FindProperty(fnInterpolateRotation, "out_DeltaRot", false);
	if (parmInterpDeltaAngle && parmInterpDeltaTime && parmInterpRotSpeed && parmInterpOut)
	{
		OverrideScriptFunction(fnInterpolateRotation, &InterpolateRotation);
	}

	parmInertiaOld = FindProperty(fnRotInertia, "OldRotator", false);
	parmInertiaTarget = FindProperty(fnRotInertia, "TargetRotator", false);
	parmInertiaRate = FindProperty(fnRotInertia, "InertiaRate", false);
	parmInertiaDeltaTime = FindProperty(fnRotInertia, "DeltaTime", false);
	if (parmInertiaOld && parmInertiaTarget && parmInertiaRate && parmInertiaDeltaTime)
	{
		OverrideScriptFunction(fnRotInertia, &CameraRotInertia);
	}

	parmBlendDeltaAngle = FindProperty(fnBlend, "DeltaAngle", false);
	parmBlendWeight = FindProperty(fnBlend, "BlendWeight", false);
	parmBlendOut = FindProperty(fnBlend, "out_DeltaRot", false);
	if (parmBlendDeltaAngle && parmBlendWeight && parmBlendOut)
	{
		OverrideScriptFunction(fnBlend, &BlendCameraRotation);
	}

	parmLockOnDeltaAngle = FindProperty(fnLockOnBlend, "DeltaAngle", false);
	parmLockOnElapsed = FindProperty(fnLockOnBlend, "ElapsedTime", false);
	parmLockOnBlendTime = FindProperty(fnLockOnBlend, "BlendTime", false);
	parmLockOnOut = FindProperty(fnLockOnBlend, "out_DeltaRot", false);
	if (parmLockOnDeltaAngle && parmLockOnElapsed && parmLockOnBlendTime && parmLockOnOut)
	{
		OverrideScriptFunction(fnLockOnBlend, &BlendLockOnRotation);
	}

	parmFPSDeltaTime = FindProperty(fnFPSSettings, "fDeltaTime", false);
	parmFPSEnter = FindProperty(fnFPSSettings, "bEnter", false);
	if (parmFPSDeltaTime && parmFPSEnter)
	{
		OverrideScriptFunction(fnFPSSettings, &BlendFPSCameraSettings);
	}

	UFunction* fnShrink = UFunction::FindFunction("Function AliceGame.AlicePawn.BlendShrinkCameraDistance");
	parmShrinkDeltaTime = FindProperty(fnShrink, "fDeltaTime", false);
	parmShrinkShrinking = FindProperty(fnShrink, "bShrinking", false);
	parmShrinkForceSet = FindProperty(fnShrink, "bForceSet", false);
	if (parmShrinkDeltaTime && parmShrinkShrinking && parmShrinkForceSet)
	{
		OverrideScriptFunction(fnShrink, &BlendShrinkCameraDistance);
	}

	parmSmoothMouse = FindProperty(fnSmoothMouse, "aMouse", false);
	parmSmoothDeltaTime = FindProperty(fnSmoothMouse, "DeltaTime", false);
	parmSmoothCount = FindProperty(fnSmoothMouse, "SampleCount", false);
	parmSmoothIndex = FindProperty(fnSmoothMouse, "Index", false);
	if (parmSmoothMouse && parmSmoothDeltaTime && parmSmoothCount && parmSmoothIndex)
	{
		smoothMouseFixed = OverrideScriptFunction(fnSmoothMouse, &SmoothMouse);
	}

	UFunction* fnViewRotation = UFunction::FindFunction("Function AliceGame.AliceCamMod_BackOfPlayer.ProcessViewRotation");
	if (fnViewRotation && fnViewRotation->Script.size() >= 15)
	{
		uint8_t* code = &fnViewRotation->Script[0];
		float value;
		memcpy(&value, code + 11, sizeof(value));
		if (code[0] == 0x0F && code[1] == 0x00 && code[10] == 0x1E && value == StickEpsilon)
		{
			stickEpsilon = reinterpret_cast<float*>(code + 11);
		}
	}

	static const uint8_t right[] = { 0x1E, 0x00, 0x00, 0x16, 0x44 };
	static const uint8_t left[] = { 0x1E, 0x00, 0x00, 0x16, 0xC4 };
	poiTurnRight = reinterpret_cast<float*>(FindConstant(fnUpdateRotation, right, sizeof(right)));
	poiTurnLeft = reinterpret_cast<float*>(FindConstant(fnUpdateRotation, left, sizeof(left)));

	InstallSite(lockOnAimSite);

	fnPlayerTick = UFunction::FindFunction("Function AliceGame.AlicePlayerController.PlayerTick");
	resolved = fnPlayerTick != nullptr;
}
