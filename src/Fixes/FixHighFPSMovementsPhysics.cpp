#include "Common.hpp"
#include "Features.hpp"

#include <cfloat>

using namespace ScriptHelper;

// ---- Pawns ----

static safetyhook::InlineHook PawnPerformPhysics{};
static safetyhook::InlineHook TickActorComponents{};
static safetyhook::MidHook PawnFootIKWalkingHook{};
static safetyhook::MidHook PawnFootIKFallingHook{};
static uintptr_t PawnFootIKBlend = 0; // APawn::Tick: the mesh height blended to the feet
static uintptr_t PawnFootIKEnd = 0; // the end of the foot IK (its per-frame reset)
static uintptr_t PawnFootIKMeshReset = 0; // the mesh height put back, with no feet to follow
static safetyhook::MidHook PawnTickFootIKDoneHook{};
static uintptr_t GWorldAddress = 0;

constexpr float PawnTeleportDistance = 64.0f;
constexpr float PawnForgetTime = 5.0f; // game time
constexpr int PawnMaxStepsAhead = 2;
constexpr int AttachedMaxDepth = 4;

constexpr uintptr_t World_InTick = 0x144;
constexpr uintptr_t World_bPostTickComponentUpdate = 0x150;
constexpr size_t Actor_ForceUpdateComponentsSlot = 0x138 / sizeof(void*);

constexpr uintptr_t PawnTick_DeltaSeconds = 0x8; // [ebx+8]
constexpr uintptr_t PawnTick_TickType = 0xC; // [ebx+0Ch]
constexpr uintptr_t PawnTick_NoFootOnFloor = 0x1C; // [ebp-1Ch]: no foot found the floor
constexpr int32_t LevelTick_ViewportsOnly = 1; // paused: the actors tick without their physics

struct PawnModes
{
	EPhysics physics = EPhysics::PHYS_None;
	int32_t specialMove = -1;
	uintptr_t controllerState = 0;

	bool operator==(const PawnModes& other) const { return physics == other.physics && specialMove == other.specialMove && controllerState == other.controllerState; }
	bool operator!=(const PawnModes& other) const { return !(*this == other); }
};

constexpr uintptr_t StateFrame_StateNode = 0x28;

struct PawnStepState
{
	int32_t objectIndex = -1;
	float creationTime = 0.0f;
	float lastTime = 0.0f;
	float accumulator = 0.0f;
	float lastStepTime = TARGET_FRAME_TIME; // real time between the two simulated poses
	FVector simLocation, prevLocation, shownLocation;
	FRotator simRotation, prevRotation, shownRotation;
	FVector aheadLocations[PawnMaxStepsAhead];
	FRotator aheadRotations[PawnMaxStepsAhead];
	int ahead = 0;
	FVector stepVelocity; // the speed the last step left
	FVector scriptVelocity;
	bool velocityShown = false;
	PawnModes modes; // as the last frame left them
	bool gamePawn = false; // has a special move
	bool valid = false;
	float simulatedAt = -1.0f; // the game time of the last frame that ran its physics
	float teleportedAt = -1.0f; // the game time of the last frame whose foot IK found the pawn teleported
};

static std::unordered_map<APawn*, PawnStepState> pawnStates;
static std::vector<APawn*> velocityShownPawns;
static int pawnStepDepth = 0;

namespace RollingPhysics { static void BeforeBallPhysics(APawn* pawn); } // the rolling mode, below

static bool IsSteppedPhysics(EPhysics physics)
{
	switch (physics)
	{
		case EPhysics::PHYS_Walking:
		case EPhysics::PHYS_Falling:
		case EPhysics::PHYS_Flying:
		case EPhysics::PHYS_Spider:
		case EPhysics::PHYS_Ladder:
		case EPhysics::PHYS_NavMeshWalking:
		case EPhysics::PHYS_Custom:
		case EPhysics::PHYS_Slide:
		case EPhysics::PHYS_TrackSlide:
		case EPhysics::PHYS_Float:
		case EPhysics::PHYS_SteamVent:
			return true;
		default:
			return false;
	}
}

static void RefreshComponents(AActor* actor)
{
	uint8_t* world = GWorldAddress ? *reinterpret_cast<uint8_t**>(GWorldAddress) : nullptr;
	BOOL collisionOnly = world && *reinterpret_cast<BOOL*>(world + World_InTick) && !*reinterpret_cast<BOOL*>(world + World_bPostTickComponentUpdate);

	using ForceUpdateComponentsFn = void(__thiscall*)(AActor*, BOOL, BOOL);
	auto forceUpdateComponents = reinterpret_cast<ForceUpdateComponentsFn>((*reinterpret_cast<void***>(actor))[Actor_ForceUpdateComponentsSlot]);
	forceUpdateComponents(actor, collisionOnly, TRUE);
}

static FRotator AddRotators(const FRotator& a, const FRotator& b)
{
	auto axis = [](int32_t x, int32_t y) { return static_cast<int32_t>(static_cast<uint32_t>(x) + static_cast<uint32_t>(y)); };
	return FRotator(axis(a.Pitch, b.Pitch), axis(a.Yaw, b.Yaw), axis(a.Roll, b.Roll));
}

static FRotator SubtractRotators(const FRotator& a, const FRotator& b)
{
	auto axis = [](int32_t x, int32_t y) { return static_cast<int32_t>(static_cast<uint32_t>(x) - static_cast<uint32_t>(y)); };
	return FRotator(axis(a.Pitch, b.Pitch), axis(a.Yaw, b.Yaw), axis(a.Roll, b.Roll));
}

struct RotationAxes
{
	FVector x, y, z;

	explicit RotationAxes(const FRotator& rotation)
	{
		constexpr float toRadians = 3.14159265358979f / 32768.0f;
		const float pitch = FRotator::NormalizeAxis(rotation.Pitch) * toRadians;
		const float yaw = FRotator::NormalizeAxis(rotation.Yaw) * toRadians;
		const float roll = FRotator::NormalizeAxis(rotation.Roll) * toRadians;
		const float sp = sinf(pitch), cp = cosf(pitch), sy = sinf(yaw), cy = cosf(yaw), sr = sinf(roll), cr = cosf(roll);

		x = FVector(cp * cy, cp * sy, sp);
		y = FVector(sr * sp * cy - cr * sy, sr * sp * sy + cr * cy, -sr * cp);
		z = FVector(-(cr * sp * cy + sr * sy), cy * sr - cr * sp * sy, cr * cp);
	}

	FVector ToWorld(const FVector& v) const { return x * v.X + y * v.Y + z * v.Z; }
	FVector ToLocal(const FVector& v) const { return FVector(v | x, v | y, v | z); }

	FRotator ToRotator() const
	{
		constexpr float toUnits = 32768.0f / 3.14159265358979f;
		FRotator rotation(lroundf(atan2f(x.Z, sqrtf(x.X * x.X + x.Y * x.Y)) * toUnits), lroundf(atan2f(x.Y, x.X) * toUnits), 0);
		const FVector rolledY = RotationAxes(rotation).y;
		rotation.Roll = lroundf(atan2f(z | rolledY, y | rolledY) * toUnits);
		return rotation;
	}
};

static void MoveAttached(AActor* actor, const FVector& fromLocation, const FRotator& fromRotation, int depth = 0)
{
	TArray<AActor*>& attached = actor->Attached;
	if (depth >= AttachedMaxDepth || attached.size() == 0)
		return;

	const FVector moved = actor->Location - fromLocation;
	const FRotator turn(
		FRotator::NormalizeAxis(SubtractRotators(actor->Rotation, fromRotation).Pitch),
		FRotator::NormalizeAxis(SubtractRotators(actor->Rotation, fromRotation).Yaw),
		FRotator::NormalizeAxis(SubtractRotators(actor->Rotation, fromRotation).Roll));
	const bool turned = turn != FRotator();
	const RotationAxes fromAxes(turned ? fromRotation : FRotator());
	const RotationAxes toAxes(turned ? actor->Rotation : FRotator());

	for (int32_t i = 0; i < attached.size(); i++)
	{
		AActor* other = attached[i];
		if (!other || other == actor || other->bDeleteMe || other->BaseSkelComponent)
			continue;

		const FVector otherLocation = other->Location;
		const FRotator otherRotation = other->Rotation;
		const bool hardAttached = other->Physics == EPhysics::PHYS_Interpolating || (other->bHardAttach && !other->bBlockActors);

		if (turned && (hardAttached || !other->bIgnoreBaseRotation))
		{
			other->Location = actor->Location + toAxes.ToWorld(fromAxes.ToLocal(other->Location - fromLocation));
			if (hardAttached && !other->bIgnoreBaseRotation)
			{
				RotationAxes axes(other->Rotation);
				axes.x = toAxes.ToWorld(fromAxes.ToLocal(axes.x));
				axes.y = toAxes.ToWorld(fromAxes.ToLocal(axes.y));
				axes.z = toAxes.ToWorld(fromAxes.ToLocal(axes.z));
				other->Rotation = axes.ToRotator();
			}
			else if (!other->bIgnoreBaseRotation)
			{
				other->Rotation = AddRotators(other->Rotation, turn);
			}
		}
		else
		{
			other->Location += moved;
		}

		MoveAttached(other, otherLocation, otherRotation, depth + 1);
		RefreshComponents(other);
	}
}

static void PlacePawn(APawn* pawn, const FVector& location, const FRotator& rotation)
{
	if (pawn->Location == location && pawn->Rotation == rotation)
		return;

	const FVector fromLocation = pawn->Location;
	const FRotator fromRotation = pawn->Rotation;
	pawn->Location = location;
	pawn->Rotation = rotation;

	MoveAttached(pawn, fromLocation, fromRotation);
	RefreshComponents(pawn);
}

// The last pose simulated ahead, or the simulated one
static void PlaceAhead(APawn* pawn, const PawnStepState& st)
{
	const int last = st.ahead - 1;
	if (last >= 0 && last < PawnMaxStepsAhead)
	{
		PlacePawn(pawn, st.aheadLocations[last], st.aheadRotations[last]);
	}
	else
	{
		PlacePawn(pawn, st.simLocation, st.simRotation);
	}
}

static FVector LerpVector(const FVector& from, const FVector& to, float alpha)
{
	if (alpha <= 0.0f) return from;
	if (alpha >= 1.0f) return to;
	return from + (to - from) * alpha;
}

static FRotator LerpRotator(const FRotator& from, const FRotator& to, float alpha)
{
	if (alpha <= 0.0f) return from;
	if (alpha >= 1.0f) return to;

	auto axis = [alpha](int32_t a, int32_t b)
	{
		int32_t delta = FRotator::NormalizeAxis(static_cast<int32_t>(static_cast<uint32_t>(b) - static_cast<uint32_t>(a))); // shortest way round
		return static_cast<int32_t>(static_cast<uint32_t>(a) + static_cast<uint32_t>(lroundf(static_cast<float>(delta) * alpha)));
	};

	return FRotator(axis(from.Pitch, to.Pitch), axis(from.Yaw, to.Yaw), axis(from.Roll, to.Roll));
}

static PawnModes ModesOf(APawn* pawn, bool gamePawn)
{
	PawnModes modes;
	modes.physics = pawn->Physics;
	if (gamePawn)
	{
		modes.specialMove = static_cast<int32_t>(static_cast<AAliceGamePawn*>(pawn)->SpecialMove);
	}
	if (AController* controller = pawn->Controller)
	{
		const uintptr_t frame = controller->StateFrame.Dummy;
		modes.controllerState = frame ? *reinterpret_cast<const uintptr_t*>(frame + StateFrame_StateNode) : 0;
	}
	return modes;
}

enum class PawnStepEnd { Simulated, Teleported, Left };

static PawnStepEnd RunPawnStep(APawn* pawn, float gameTime)
{
	const FVector from = pawn->Location;
	const bool wasTeleported = pawn->bJustTeleported;
	const float speedBefore = pawn->Velocity.Size();

	PawnPerformPhysics.unsafe_thiscall<void>(pawn, gameTime);

	if (pawn->bDeleteMe || !IsSteppedPhysics(pawn->Physics))
	{
		return PawnStepEnd::Left;
	}

	const float distSquared = FVector::DistSquared(from, pawn->Location);
	const float reach = 128.0f + 2.0f * std::max(speedBefore, pawn->Velocity.Size()) * gameTime;
	if ((!wasTeleported && pawn->bJustTeleported && distSquared > PawnTeleportDistance * PawnTeleportDistance) || distSquared > reach * reach)
	{
		return PawnStepEnd::Teleported;
	}

	return PawnStepEnd::Simulated;
}

static void PurgePawnStates(float now)
{
	static float lastPurge = 0.0f;
	if (now >= lastPurge && now - lastPurge < 1.0f)
		return;

	lastPurge = now;
	for (auto it = pawnStates.begin(); it != pawnStates.end();)
	{
		if (it->second.lastTime > now || now - it->second.lastTime > PawnForgetTime)
		{
			it = pawnStates.erase(it);
		}
		else
		{
			++it;
		}
	}
}

static bool PawnStartsOver(const PawnStepState& st, APawn* pawn, AWorldInfo* world, float DeltaSeconds)
{
	const float now = world->TimeSeconds;
	float tickGap = DeltaSeconds / pawn->CustomTimeDilation;
	if (tickGap < world->DeltaSeconds) tickGap = world->DeltaSeconds;

	return !st.valid
		|| st.objectIndex != pawn->ObjectInternalInteger
		|| st.creationTime != pawn->CreationTime
		|| now < st.lastTime
		|| now - st.lastTime > tickGap + TARGET_FRAME_TIME * world->TimeDilation + 0.001f;
}

enum class PawnFrameStep
{
	None, // not stepped
	Waits,
	Step, // a step of a 30fps frame's time
	Frame // a frame of about 1/30s, run with its own time
};

struct PawnFramePlan
{
	PawnFrameStep step = PawnFrameStep::None;
	float gameTime = 0.0f; // of a Step
};

static PawnFramePlan PlanPawnFrame(APawn* pawn, float DeltaSeconds)
{
	PawnFramePlan plan;
	if (pawnStepDepth > 0 || !pawn->WorldInfo || !IsSteppedPhysics(pawn->Physics) || pawn->bDeleteMe || !(DeltaSeconds >= 0.0f))
		return plan;

	AWorldInfo* world = pawn->WorldInfo;
	const float customDilation = pawn->CustomTimeDilation;
	const float dilation = world->TimeDilation * customDilation;
	if (!(customDilation > 0.0f && world->TimeDilation * TARGET_FRAME_TIME >= MIN_WORLD_FRAME_TIME))
		return plan;

	const float frameTime = DeltaSeconds / dilation;
	const bool fullFrame = fabsf(frameTime - TARGET_FRAME_TIME) <= TARGET_FRAME_WINDOW;
	const float due = TARGET_FRAME_TIME + (fullFrame ? TARGET_FRAME_WINDOW : TARGET_STEP_SLACK);
	const PawnFrameStep stepped = fullFrame ? PawnFrameStep::Frame : PawnFrameStep::Step;
	plan.gameTime = TARGET_FRAME_TIME * dilation;

	auto it = pawnStates.find(pawn);
	if (it == pawnStates.end() || PawnStartsOver(it->second, pawn, world, DeltaSeconds))
	{
		plan.step = TARGET_FRAME_TIME + frameTime > due ? stepped : PawnFrameStep::None;
		return plan;
	}

	const PawnStepState& st = it->second;
	float accumulator = st.accumulator + frameTime;
	int ahead = st.ahead;
	for (int steps = 0; accumulator > due && steps < MAX_TARGET_STEPS; steps++)
	{
		if (!ahead)
		{
			plan.step = stepped;
			return plan;
		}
		ahead--;
		accumulator -= TARGET_FRAME_TIME;
	}

	plan.step = ModesOf(pawn, st.gamePawn) != st.modes && ahead < PawnMaxStepsAhead && !fullFrame ? PawnFrameStep::Step : PawnFrameStep::Waits;
	return plan;
}

// Whether the pawn's physics runs in this frame: 1 it does (or did), 0 it waits for its next 1/30s, -1 it isn't stepped
static int PawnFrameSteps(APawn* pawn)
{
	if (!FixHighFPSMovementsPhysics || !pawn || !pawn->WorldInfo)
		return -1;

	const float now = pawn->WorldInfo->TimeSeconds;
	auto it = pawnStates.find(pawn);
	if (it != pawnStates.end() && it->second.valid && it->second.lastTime == now)
		return it->second.simulatedAt == now ? 1 : 0;

	const PawnFramePlan plan = PlanPawnFrame(pawn, pawn->WorldInfo->DeltaSeconds * pawn->CustomTimeDilation);
	return plan.step == PawnFrameStep::None ? -1 : plan.step == PawnFrameStep::Waits ? 0 : 1;
}

static PawnFramePlan PlanFootIK(APawn* pawn, const safetyhook::Context& ctx)
{
	const float deltaSeconds = *reinterpret_cast<const float*>(ctx.ebx + PawnTick_DeltaSeconds);
	const int32_t tickType = *reinterpret_cast<const int32_t*>(ctx.ebx + PawnTick_TickType);
	if (tickType == LevelTick_ViewportsOnly || pawn->TickFrequency != 0.0f || pawn->TickFrequencyAtEndDistance > 0.0f)
		return {};

	return PlanPawnFrame(pawn, deltaSeconds);
}

static struct { uintptr_t frame = 0; float deltaSeconds = 0.0f; } footIKTickTime;

static void OnPawnFootIKWalking(safetyhook::Context& ctx)
{
	APawn* pawn = reinterpret_cast<APawn*>(ctx.esi);
	const PawnFramePlan plan = PlanFootIK(pawn, ctx);

	bool teleportFrames = false;
	AWorldInfo* world = pawn->WorldInfo;
	auto it = pawnStates.find(pawn);
	if (world && it != pawnStates.end() && it->second.valid)
	{
		PawnStepState& st = it->second;
		const bool teleported = FVector::DistSquared(pawn->Location, st.shownLocation) > PawnTeleportDistance * PawnTeleportDistance;
		teleportFrames = teleported || st.teleportedAt == st.lastTime;
		if (teleported)
		{
			st.teleportedAt = world->TimeSeconds;
		}
	}

	if (plan.step == PawnFrameStep::Waits && !teleportFrames)
	{
		const bool noFootOnFloor = *reinterpret_cast<const int32_t*>(ctx.ebp - PawnTick_NoFootOnFloor) != 0;
		ctx.eip = noFootOnFloor ? PawnFootIKEnd : PawnFootIKBlend;
	}
	else if ((plan.step == PawnFrameStep::Step || plan.step == PawnFrameStep::Waits) && !footIKTickTime.frame)
	{
		float& deltaSeconds = *reinterpret_cast<float*>(ctx.ebx + PawnTick_DeltaSeconds);
		footIKTickTime = { ctx.ebx, deltaSeconds };
		deltaSeconds = plan.gameTime;
	}
}

static void OnPawnTickFootIKDone(safetyhook::Context& ctx)
{
	if (footIKTickTime.frame && footIKTickTime.frame == ctx.ebx)
	{
		*reinterpret_cast<float*>(ctx.ebx + PawnTick_DeltaSeconds) = footIKTickTime.deltaSeconds;
		footIKTickTime.frame = 0;
	}
}

static void OnPawnFootIKFalling(safetyhook::Context& ctx)
{
	APawn* pawn = reinterpret_cast<APawn*>(ctx.esi);
	if (!pawn->bJustPushDownByIK || pawn->Physics != EPhysics::PHYS_Falling)
		return;

	if (PlanFootIK(pawn, ctx).step == PawnFrameStep::Waits)
	{
		ctx.eip = PawnFootIKMeshReset;
	}
}

static void __fastcall PawnPerformPhysics_Hook(APawn* pawn, void*, float DeltaSeconds)
{
	if (pawnStepDepth > 0 || !pawn || !pawn->WorldInfo)
	{
		PawnPerformPhysics.unsafe_thiscall<void>(pawn, DeltaSeconds);
		return;
	}

	AWorldInfo* world = pawn->WorldInfo;
	const float now = world->TimeSeconds;

	PurgePawnStates(now);

	const float customDilation = pawn->CustomTimeDilation;
	const float dilation = world->TimeDilation * customDilation;
	const bool steppable = customDilation > 0.0f && world->TimeDilation * TARGET_FRAME_TIME >= MIN_WORLD_FRAME_TIME;

	if (!IsSteppedPhysics(pawn->Physics) || pawn->bDeleteMe || !(DeltaSeconds >= 0.0f) || !steppable)
	{
		auto it = pawnStates.find(pawn);
		if (it != pawnStates.end())
		{
			it->second.valid = false; // it stays where it is shown
		}

		if (pawn->Physics == EPhysics::PHYS_RigidBody)
		{
			RollingPhysics::BeforeBallPhysics(pawn);
		}

		PawnPerformPhysics.unsafe_thiscall<void>(pawn, DeltaSeconds);
		return;
	}

	PawnStepState& st = pawnStates[pawn];

	if (st.velocityShown)
	{
		st.velocityShown = false;
		if (pawn->Velocity == st.stepVelocity)
		{
			pawn->Velocity = st.scriptVelocity;
		}
	}

	if (PawnStartsOver(st, pawn, world, DeltaSeconds))
	{
		st.objectIndex = pawn->ObjectInternalInteger;
		st.creationTime = pawn->CreationTime;
		st.simLocation = st.prevLocation = st.shownLocation = pawn->Location;
		st.simRotation = st.prevRotation = st.shownRotation = pawn->Rotation;
		st.accumulator = TARGET_FRAME_TIME;
		st.lastStepTime = TARGET_FRAME_TIME;
		st.ahead = 0;
		st.stepVelocity = pawn->Velocity;
		st.gamePawn = pawn->IsA(AAliceGamePawn::StaticClass());
		st.modes = ModesOf(pawn, st.gamePawn);
		st.valid = true;
	}
	else
	{
		FVector moved = pawn->Location - st.shownLocation;
		if (pawn->bJustTeleported && moved.SizeSquared() > PawnTeleportDistance * PawnTeleportDistance)
		{
			st.simLocation = st.prevLocation = pawn->Location;
			st.simRotation = st.prevRotation = pawn->Rotation;
			for (int i = 0; i < st.ahead; i++)
			{
				st.aheadLocations[i] = pawn->Location;
				st.aheadRotations[i] = pawn->Rotation;
			}
		}
		else
		{
			if (!moved.IsZero())
			{
				st.simLocation += moved;
				st.prevLocation += moved;
				for (int i = 0; i < st.ahead; i++)
				{
					st.aheadLocations[i] += moved;
				}
			}

			if (pawn->Rotation != st.shownRotation)
			{
				FRotator delta = SubtractRotators(pawn->Rotation, st.shownRotation);
				st.simRotation = AddRotators(st.simRotation, delta);
				st.prevRotation = AddRotators(st.prevRotation, delta);
				for (int i = 0; i < st.ahead; i++)
				{
					st.aheadRotations[i] = AddRotators(st.aheadRotations[i], delta);
				}
			}
		}
	}

	st.lastTime = now;

	const float frameTime = DeltaSeconds / dilation; // real time
	const bool inStep = st.accumulator == TARGET_FRAME_TIME; // the last frame ended exactly on its simulated pose
	st.accumulator += frameTime;

	const bool fullFrame = fabsf(frameTime - TARGET_FRAME_TIME) <= TARGET_FRAME_WINDOW;
	const float due = TARGET_FRAME_TIME + (fullFrame ? TARGET_FRAME_WINDOW : TARGET_STEP_SLACK);
	const bool modeChanged = ModesOf(pawn, st.gamePawn) != st.modes;

	pawnStepDepth++;
	bool stepped = true;
	bool simulated = false; // this frame ran the physics

	if (st.accumulator > due)
	{
		PlaceAhead(pawn, st);

		int steps = 0;
		while (st.accumulator > due && steps < MAX_TARGET_STEPS)
		{
			TargetStep step;
			if (st.ahead)
			{
				step = { TARGET_FRAME_TIME, TARGET_FRAME_TIME * dilation, false };
				st.prevLocation = st.simLocation;
				st.prevRotation = st.simRotation;
				st.simLocation = st.aheadLocations[0];
				st.simRotation = st.aheadRotations[0];
				st.ahead--;
				for (int i = 0; i < st.ahead && i + 1 < PawnMaxStepsAhead; i++)
				{
					st.aheadLocations[i] = st.aheadLocations[i + 1];
					st.aheadRotations[i] = st.aheadRotations[i + 1];
				}
			}
			else
			{
				step = NextTargetStep(st.accumulator, fullFrame, inStep, frameTime, DeltaSeconds, dilation);
				st.prevLocation = pawn->Location;
				st.prevRotation = pawn->Rotation;
				simulated = true;
				const PawnStepEnd end = RunPawnStep(pawn, step.gameTime);
				if (end == PawnStepEnd::Left)
				{
					stepped = false;
					break;
				}

				if (end == PawnStepEnd::Teleported)
				{
					st.prevLocation = pawn->Location;
					st.prevRotation = pawn->Rotation;
				}

				st.simLocation = pawn->Location;
				st.simRotation = pawn->Rotation;
				st.stepVelocity = pawn->Velocity;
			}

			st.accumulator = step.landed ? TARGET_FRAME_TIME : st.accumulator - step.realTime;
			st.lastStepTime = step.realTime;
			steps++;
		}

		if (stepped && st.accumulator > due)
		{
			st.accumulator = fmodf(st.accumulator, TARGET_FRAME_TIME); // a hitch longer than the step budget, the rest is dropped
		}
	}

	if (stepped && !simulated && modeChanged && st.ahead < PawnMaxStepsAhead && !fullFrame)
	{
		PlaceAhead(pawn, st);
		simulated = true;
		const PawnStepEnd end = RunPawnStep(pawn, TARGET_FRAME_TIME * dilation);
		if (end == PawnStepEnd::Left)
		{
			stepped = false;
		}
		else
		{
			st.stepVelocity = pawn->Velocity;
			if (st.ahead >= 0 && st.ahead < PawnMaxStepsAhead)
			{
				st.aheadLocations[st.ahead] = pawn->Location;
				st.aheadRotations[st.ahead] = pawn->Rotation;
				st.ahead++;
			}
			if (end == PawnStepEnd::Teleported)
			{
				st.prevLocation = st.simLocation = pawn->Location;
				st.prevRotation = st.simRotation = pawn->Rotation;
				for (int i = 0; i < st.ahead; i++)
				{
					st.aheadLocations[i] = pawn->Location;
					st.aheadRotations[i] = pawn->Rotation;
				}
			}
		}
	}

	if (simulated)
	{
		st.simulatedAt = now;
	}

	if (stepped)
	{
		float alpha = 1.0f - (TARGET_FRAME_TIME - st.accumulator) / st.lastStepTime;
		PlacePawn(pawn, LerpVector(st.prevLocation, st.simLocation, alpha), LerpRotator(st.prevRotation, st.simRotation, alpha));

		st.shownLocation = pawn->Location;
		st.shownRotation = pawn->Rotation;
		st.modes = ModesOf(pawn, st.gamePawn);

		if (!simulated && pawn->Velocity != st.stepVelocity)
		{
			st.scriptVelocity = pawn->Velocity;
			pawn->Velocity = st.stepVelocity;
			if (!st.velocityShown)
			{
				st.velocityShown = true;
				velocityShownPawns.push_back(pawn);
			}
		}
	}
	else
	{
		st.valid = false;
	}

	pawnStepDepth--;
}

static void RestoreScriptVelocity(APawn* pawn, PawnStepState& st)
{
	st.velocityShown = false;
	if (pawn->Velocity == st.stepVelocity)
	{
		pawn->Velocity = st.scriptVelocity;
	}
}

static void __cdecl TickActorComponents_Hook(AActor* actor, float DeltaSeconds, int32_t TickType, void* deferredList)
{
	TickActorComponents.unsafe_ccall<void>(actor, DeltaSeconds, TickType, deferredList);

	if (velocityShownPawns.empty())
		return;

	APawn* pawn = reinterpret_cast<APawn*>(actor);
	auto it = pawnStates.find(pawn);
	if (it != pawnStates.end() && it->second.velocityShown)
	{
		RestoreScriptVelocity(pawn, it->second);
	}
}

static void RestoreScriptVelocities()
{
	for (APawn* pawn : velocityShownPawns)
	{
		auto it = pawnStates.find(pawn);
		if (it == pawnStates.end() || !it->second.velocityShown)
			continue;

		PawnStepState& st = it->second;
		TArray<UObject*>* objects = UObject::GObjObjects();
		const bool there = objects && st.objectIndex >= 0 && st.objectIndex < objects->size() && objects->at(st.objectIndex) == pawn;
		if (there)
		{
			RestoreScriptVelocity(pawn, st);
		}
		else
		{
			st.velocityShown = false;
		}
	}
	velocityShownPawns.clear();
}

// ---- Rolling ----

namespace RollingPhysics
{
	enum PushKind { Force, Impulse, Torque, LinearVelocity, AngularVelocity, Position, Rotation, PushKindCount };

	struct HeldPush
	{
		const uint8_t* site = nullptr; // the call in the script
		PushKind kind = Force;
		FVector value;
		FVector position;
		FRotator rotation;
		FName boneName = FName(0); // NAME_None, when the script leaves it out
		uint32_t flag = 0; // bVelChange, bAddToCurrent
		bool event = false; // not made by PlayerMove
		uint32_t frame = 0; // the frame it was made in
	};

	static bool IsSetter(const HeldPush& push)
	{
		return push.kind == Position || push.kind == Rotation || ((push.kind == LinearVelocity || push.kind == AngularVelocity) && !push.flag);
	}

	struct PushSite
	{
		const uint8_t* site = nullptr;
		PushKind kind = Force;
		bool setter = false;
		bool move = true; // made by PlayerMove
		uint32_t lastFrame = 0;
		uint32_t run = 0;
	};

	constexpr size_t MaxHeldPushes = 64;
	constexpr size_t MaxPushSites = 64;

	static UFunction* pushFunctions[PushKindCount] = {};
	static Native pushNatives[PushKindCount] = {};
	static UFunction* rollingMove = nullptr; // PlayerRoll.PlayerMove, run every frame
	static std::vector<HeldPush> held; // the calls of each site's last frame, and the events
	static std::vector<HeldPush> releasing;
	static std::vector<uint8_t> fates; // what ReleaseHeld does with each released call
	static std::vector<PushSite> pushSites;
	static UPrimitiveComponent* ball = nullptr; // its pushes are held
	static AAlicePawn* ballPawn = nullptr;
	static int32_t ballPawnIndex = -1;
	static uint32_t frame = 0;
	static uint32_t stepFrame = 0; // the frame of the last step
	static uint32_t ballPhysicsStep = 0; // the step the ball's physics last ran after

	static PushSite* SiteOf(const HeldPush& push)
	{
		const bool setter = IsSetter(push);
		for (PushSite& s : pushSites)
		{
			if (s.site == push.site && s.kind == push.kind && s.setter == setter)
				return &s;
		}

		return nullptr;
	}

	static void DropHeld(const PushSite& site)
	{
		held.erase(std::remove_if(held.begin(), held.end(), [&site](const HeldPush& h) { return h.site == site.site && h.kind == site.kind && IsSetter(h) == site.setter; }), held.end());
	}

	static void ApplyPush(UPrimitiveComponent* mesh, const HeldPush& push)
	{
		switch (push.kind)
		{
			case Force: mesh->AddForce(push.value, push.position, push.boneName); break;
			case Impulse: mesh->AddImpulse(push.value, push.position, push.boneName, push.flag != 0); break;
			case Torque: mesh->AddTorque(push.value, push.boneName); break;
			case LinearVelocity: mesh->SetRBLinearVelocity(push.value, push.flag != 0); break;
			case AngularVelocity: mesh->SetRBAngularVelocity(push.value, push.flag != 0); break;
			case Position: mesh->SetRBPosition(push.value, push.boneName); break;
			case Rotation: mesh->SetRBRotation(push.rotation, push.boneName); break;
			default: break;
		}
	}

	static uint32_t Track(const HeldPush& push)
	{
		PushSite* site = SiteOf(push);
		if (!site)
		{
			if (pushSites.size() >= MaxPushSites)
				return 0;

			pushSites.push_back({ push.site, push.kind, IsSetter(push), !push.event, frame, 1 });
			return 1;
		}

		if (site->lastFrame != frame)
		{
			site->run = site->lastFrame + 1 == frame ? site->run + 1 : 1;
			site->lastFrame = frame;
			site->move = !push.event;
			DropHeld(*site);
		}

		return site->run;
	}

	static bool Hold(const HeldPush& push)
	{
		if (held.size() >= MaxHeldPushes)
			return false;

		if (!push.event || IsSetter(push))
		{
			const uint32_t run = Track(push);
			if (run == 0 || (push.event && run == 1))
				return false;
		}

		held.push_back(push);
		return true;
	}

	template <typename Apply>
	static void ReleaseHeld(Apply apply)
	{
		bool single = false;
		uint32_t singleFrame = 0;
		for (const PushSite& s : pushSites)
		{
			if (s.move && s.run == 1 && s.lastFrame != frame && frame - s.lastFrame < frame - stepFrame && (!single || frame - s.lastFrame < frame - singleFrame))
			{
				single = true;
				singleFrame = s.lastFrame;
			}
		}

		const uint32_t own = single ? singleFrame : frame; // the frame the step runs as

		releasing.clear();
		releasing.swap(held);
		stepFrame = frame;

		enum : uint8_t { Drop, Now, Next };
		fates.clear();
		for (const HeldPush& h : releasing)
		{
			const bool push = h.event && !IsSetter(h);
			const PushSite* site = push ? nullptr : SiteOf(h);
			uint8_t fate = Drop;
			if (push)
			{
				fate = Now;
			}
			else if (site && site->run == 1)
			{
				fate = site->lastFrame == frame && own != frame ? Next : Now;
			}
			else if (site && frame - site->lastFrame <= frame - own && frame - (site->lastFrame - site->run + 1) >= frame - own)
			{
				fate = Now;
			}
			fates.push_back(fate);
		}

		frame++;
		for (size_t i = 0; i < releasing.size(); i++)
		{
			if (fates[i] == Now)
			{
				apply(releasing[i]);
			}
		}
		frame--;

		size_t kept = 0;
		for (size_t i = 0; i < releasing.size(); i++)
		{
			const PushSite* site = fates[i] == Next ? SiteOf(releasing[i]) : nullptr;
			if (site && site->lastFrame == releasing[i].frame && held.size() < MaxHeldPushes)
			{
				held.insert(held.begin() + kept++, releasing[i]);
			}
		}

		releasing.clear();

		pushSites.erase(std::remove_if(pushSites.begin(), pushSites.end(), [](const PushSite& s) { return static_cast<int32_t>(frame - s.lastFrame) > 300; }), pushSites.end());
	}

	template <PushKind Kind>
	static void __fastcall PushExec(UPrimitiveComponent* self, void*, Frame* stack, void* result)
	{
		if (self != ball || !ball || stack->Node == pushFunctions[Kind])
		{
			pushNatives[Kind](self, stack, result);
			return;
		}

		HeldPush push;
		push.site = stack->Code;
		push.kind = Kind;
		push.event = rollingMove && stack->Node != rollingMove;
		push.frame = frame;
		if (Kind == Rotation)
		{
			StepParm(stack, &push.rotation);
		}
		else
		{
			StepParm(stack, &push.value);
		}
		if (Kind == Force || Kind == Impulse)
		{
			StepParm(stack, &push.position);
		}
		if (Kind != LinearVelocity && Kind != AngularVelocity)
		{
			StepParm(stack, &push.boneName);
		}
		if (Kind == Impulse || Kind == LinearVelocity || Kind == AngularVelocity)
		{
			StepParm(stack, &push.flag);
		}
		FinishParms(stack);

		if (!Hold(push))
		{
			ApplyPush(self, push);
		}
	}

	static bool InObjectTable(const UObject* object, int32_t index)
	{
		TArray<UObject*>* objects = UObject::GObjObjects();
		return objects && index >= 0 && index < objects->size() && objects->at(index) == object;
	}

	static bool BallStillThere()
	{
		return ball && ballPawn && InObjectTable(ballPawn, ballPawnIndex) && !ballPawn->bDeleteMe && ballPawn->Mesh == ball && ballPawn->Physics == EPhysics::PHYS_RigidBody;
	}

	static URB_BodyInstance* RootBody(AAlicePawn* pawn)
	{
		UPrimitiveComponent* collision = pawn->CollisionComponent;
		auto* mesh = pawn->Mesh;
		if (!collision)
			return nullptr;

		if (collision != mesh || mesh->bUseSingleBodyPhysics)
			return collision->BodyInstance;

		auto* instance = mesh->PhysicsAssetInstance;
		if (!instance)
			return nullptr;

		const int32_t root = instance->RootBodyIndex;
		return root >= 0 && root < instance->Bodies.size() ? instance->Bodies[root] : nullptr;
	}

	static void BeforeBallPhysics(APawn* pawn)
	{
		if (!g_State.rollingMode || !ballPawn || pawn != ballPawn)
			return;

		URB_BodyInstance* body = RootBody(ballPawn);
		if (!body)
			return;

		if (ballPhysicsStep == g_State.physSceneStep)
		{
			body->Velocity = body->PreviousVelocity; // what the sync moves into PreviousVelocity
		}
		ballPhysicsStep = g_State.physSceneStep;
	}

	static void Flush()
	{
		UPrimitiveComponent* mesh = ball;
		ball = nullptr;
		ReleaseHeld([mesh](const HeldPush& push) { ApplyPush(mesh, push); });
		releasing.swap(held);
		for (const HeldPush& push : releasing)
		{
			ApplyPush(mesh, push);
		}
		releasing.clear();
	}

	static AAlicePawn* RollingPawn()
	{
		AAlicePlayerController* pc = g_State.AlicePlayerController;
		AAlicePawn* pawn = pc ? pc->MyAlicePawn : nullptr;
		if (!pawn || !pawn->bInRollingMode || pawn->bDeleteMe || pawn->Physics != EPhysics::PHYS_RigidBody || !pawn->Mesh || !pawn->WorldInfo)
			return nullptr;

		return pawn;
	}

	static void Stop()
	{
		ball = nullptr;
		ballPawn = nullptr;
		ballPawnIndex = -1;
		held.clear();
		pushSites.clear();
		g_State.rollingMode = false;
	}

	static void Resolve()
	{
		static const char* const names[PushKindCount] =
		{
			"Function Engine.PrimitiveComponent.AddForce",
			"Function Engine.PrimitiveComponent.AddImpulse",
			"Function Engine.PrimitiveComponent.AddTorque",
			"Function Engine.PrimitiveComponent.SetRBLinearVelocity",
			"Function Engine.PrimitiveComponent.SetRBAngularVelocity",
			"Function Engine.PrimitiveComponent.SetRBPosition",
			"Function Engine.PrimitiveComponent.SetRBRotation",
		};
		static void* const execs[PushKindCount] =
		{
			reinterpret_cast<void*>(&PushExec<Force>),
			reinterpret_cast<void*>(&PushExec<Impulse>),
			reinterpret_cast<void*>(&PushExec<Torque>),
			reinterpret_cast<void*>(&PushExec<LinearVelocity>),
			reinterpret_cast<void*>(&PushExec<AngularVelocity>),
			reinterpret_cast<void*>(&PushExec<Position>),
			reinterpret_cast<void*>(&PushExec<Rotation>),
		};

		if (!GNatives)
			return;

		for (int i = 0; i < PushKindCount; i++)
		{
			UFunction* fn = UFunction::FindFunction(names[i]);
			if (!fn || pushFunctions[i] || !fn->Func.Dummy)
				continue;

			pushNatives[i] = reinterpret_cast<Native>(fn->Func.Dummy);
			pushFunctions[i] = fn;
			fn->Func.Dummy = reinterpret_cast<uintptr_t>(execs[i]);
		}

		rollingMove = UFunction::FindFunction("Function AliceGame.AlicePlayerController.PlayerRoll.PlayerMove");
		held.reserve(MaxHeldPushes);
		releasing.reserve(MaxHeldPushes);
		fates.reserve(MaxHeldPushes);
		pushSites.reserve(MaxPushSites);
	}
}

// Before the world's physics tick (FixHighFPSPhysX.cpp): the scripts' velocities back, and whether the ball rolls
bool BeforeRBPhysTick()
{
	RestoreScriptVelocities();
	return RollingPhysics::RollingPawn() != nullptr;
}

// The ball's pushes go with the scene's steps (step: one runs in this frame), and are made as they come when it isn't stepped
void HoldRollingPushes(bool stepped, bool step)
{
	using namespace RollingPhysics;

	AAlicePawn* pawn = stepped && FixHighFPSMovementsPhysics ? RollingPawn() : nullptr;
	if (!pawn)
	{
		if (g_State.rollingMode)
		{
			if (BallStillThere())
			{
				Flush();
			}
			Stop();
		}
	}
	else
	{
		if (!g_State.rollingMode || pawn != ballPawn)
		{
			Stop();
			ballPawn = pawn;
			ballPawnIndex = pawn->ObjectInternalInteger;
			g_State.rollingMode = true;
		}

		ball = pawn->Mesh;
		if (step)
		{
			UPrimitiveComponent* mesh = pawn->Mesh;
			ReleaseHeld([mesh](const HeldPush& push) { ApplyPush(mesh, push); });
		}
	}

	frame++;
}

// ---- Crowds ----

static safetyhook::InlineHook CrowdAgentPerformPhysics{};
static safetyhook::InlineHook CrowdAgentTickSpecial{};

constexpr float CrowdStepSlack = 1.0e-5f;
constexpr float CrowdStateGap = 0.25f; // real time
constexpr float CrowdForgetTime = 5.0f; // real time

struct CrowdState
{
	int32_t objectIndex = -1;
	float creationTime = 0.0f;
	float lastSeen = 0.0f;
	float accumulator = 0.0f;
	FVector simLocation, prevLocation, shownLocation;
	FRotator simRotation, prevRotation, shownRotation;
	bool valid = false;
	bool physicsRan = false;
	bool tick = false;
	float tickTime = 0.0f;
	bool show = false;
};

static std::unordered_map<AActor*, CrowdState> crowdStates;

static void PurgeCrowdStates(float now)
{
	static float lastPurge = 0.0f;
	if (now >= lastPurge && now - lastPurge < 1.0f)
		return;

	lastPurge = now;
	for (auto it = crowdStates.begin(); it != crowdStates.end();)
	{
		if (now < it->second.lastSeen || now - it->second.lastSeen > CrowdForgetTime)
		{
			it = crowdStates.erase(it);
		}
		else
		{
			++it;
		}
	}
}

static void PlaceAgent(AActor* agent, const FVector& location, const FRotator& rotation)
{
	if (agent->Location == location && agent->Rotation == rotation)
		return;

	agent->Location = location;
	agent->Rotation = rotation;
	RefreshComponents(agent);
}

static void ShowAgent(AActor* agent, CrowdState& st)
{
	float alpha = std::clamp(1.0f - (TARGET_FRAME_TIME - st.accumulator) / TARGET_FRAME_TIME, 0.0f, 1.0f);
	PlaceAgent(agent, LerpVector(st.prevLocation, st.simLocation, alpha), LerpRotator(st.prevRotation, st.simRotation, alpha));
	st.shownLocation = agent->Location;
	st.shownRotation = agent->Rotation;
}

static void AdoptMoves(AActor* agent, CrowdState& st)
{
	FVector moved = agent->Location - st.shownLocation;
	st.simLocation += moved;
	st.prevLocation += moved;
	if (agent->Rotation != st.shownRotation)
	{
		FRotator turn = SubtractRotators(agent->Rotation, st.shownRotation);
		st.simRotation = AddRotators(st.simRotation, turn);
		st.prevRotation = AddRotators(st.prevRotation, turn);
	}

	st.shownLocation = agent->Location;
	st.shownRotation = agent->Rotation;
}

// Like the pawns: performPhysics every 1/30s, TickSpecial in the frames that took a step
static void __fastcall CrowdAgentPerformPhysics_Hook(AActor* agent, void*, float DeltaSeconds)
{
	if (!agent || !agent->WorldInfo || agent->bDeleteMe)
	{
		CrowdAgentPerformPhysics.unsafe_thiscall<void>(agent, DeltaSeconds);
		return;
	}

	float now = agent->WorldInfo->RealTimeSeconds;
	PurgeCrowdStates(now);

	CrowdState& st = crowdStates[agent];
	st.physicsRan = true;
	st.show = false;

	float realTime;
	if (!GetRealFrameTime(agent, DeltaSeconds, realTime) || realTime >= TARGET_FRAME_TIME - TARGET_FRAME_WINDOW)
	{
		st.valid = false;
		st.tick = true;
		st.tickTime = DeltaSeconds;
		CrowdAgentPerformPhysics.unsafe_thiscall<void>(agent, DeltaSeconds);
		return;
	}

	float dilation = DeltaSeconds / realTime;
	if (!st.valid || st.objectIndex != agent->ObjectInternalInteger || st.creationTime != agent->CreationTime || now < st.lastSeen || now - st.lastSeen > CrowdStateGap)
	{
		st.objectIndex = agent->ObjectInternalInteger;
		st.creationTime = agent->CreationTime;
		st.simLocation = st.prevLocation = st.shownLocation = agent->Location;
		st.simRotation = st.prevRotation = st.shownRotation = agent->Rotation;
		st.accumulator = TARGET_FRAME_TIME;
		st.valid = true;
	}
	else
	{
		AdoptMoves(agent, st);
	}

	st.lastSeen = now;
	st.accumulator += realTime;
	st.tick = false;
	st.tickTime = 0.0f;

	float due = TARGET_FRAME_TIME + CrowdStepSlack;
	int steps = 0;
	if (st.accumulator > due)
	{
		PlaceAgent(agent, st.simLocation, st.simRotation);
		while (st.accumulator > due && steps < MAX_TARGET_STEPS)
		{
			st.prevLocation = agent->Location;
			st.prevRotation = agent->Rotation;
			CrowdAgentPerformPhysics.unsafe_thiscall<void>(agent, TARGET_FRAME_TIME * dilation);
			if (agent->bDeleteMe)
			{
				st.valid = false;
				return;
			}

			st.simLocation = agent->Location;
			st.simRotation = agent->Rotation;
			st.accumulator -= TARGET_FRAME_TIME;
			st.tick = true;
			st.tickTime += TARGET_FRAME_TIME * dilation;
			steps++;
		}

		if (st.accumulator > due)
		{
			st.accumulator = fmodf(st.accumulator, TARGET_FRAME_TIME);
		}
	}

	st.show = true;
	if (steps == 0)
	{
		ShowAgent(agent, st);
	}
	else
	{
		st.shownLocation = agent->Location;
		st.shownRotation = agent->Rotation;
	}
}

static void __fastcall CrowdAgentTickSpecial_Hook(AActor* agent, void*, float DeltaSeconds)
{
	auto it = agent ? crowdStates.find(agent) : crowdStates.end();
	if (it == crowdStates.end() || !it->second.physicsRan)
	{
		CrowdAgentTickSpecial.unsafe_thiscall<void>(agent, DeltaSeconds);
		return;
	}

	CrowdState& st = it->second;
	st.physicsRan = false;
	if (st.tick)
	{
		CrowdAgentTickSpecial.unsafe_thiscall<void>(agent, st.tickTime);
	}

	if (st.valid && st.show && !agent->bDeleteMe)
	{
		AdoptMoves(agent, st);
		ShowAgent(agent, st);
	}
}

// ---- Scripts ----

constexpr float MaxFrameScale = 8.0f;
constexpr float ObjectClockGap = 0.25f; // game time
constexpr int MaxObjectClocks = 64;
constexpr float InputGridGap = 0.25f; // game time
constexpr float PickupReach = 50.0f; // LineTrail gives a pickup this close to Alice
constexpr float PickupTrailGap = 0.25f; // game time
constexpr int MaxPickupTrails = 64;

static bool FrameScale(const Site& site, Frame* stack, float& scale)
{
	AActor* actor = static_cast<AActor*>(stack->Object);
	if (!actor || !actor->WorldInfo)
		return false;

	float deltaTime = actor->WorldInfo->DeltaSeconds * actor->CustomTimeDilation;
	SiteDeltaTime(site, stack, deltaTime);

	float realTime;
	if (!GetRealFrameTime(actor, deltaTime, realTime))
		return false;

	scale = std::min(realTime / TARGET_FRAME_TIME, MaxFrameScale);
	return true;
}

static void ScaleAmount(Site& site, Frame* stack, void* result)
{
	float scale;
	if (!result || !FrameScale(site, stack, scale))
		return;

	*reinterpret_cast<float*>(result) *= scale;
}

static void ScaleFactor(Site& site, Frame* stack, void* result)
{
	float scale;
	if (!result || !FrameScale(site, stack, scale))
		return;

	float* value = reinterpret_cast<float*>(result);
	*value = powf(*value, scale);
}

static void ScaleCount(Site& site, Frame* stack, void* result)
{
	float scale;
	if (!result || !FrameScale(site, stack, scale))
		return;

	int32_t* count = reinterpret_cast<int32_t*>(result);
	float scaled = static_cast<float>(*count) * scale + site.carry;
	*count = static_cast<int32_t>(floorf(scaled));
	site.carry = scaled - static_cast<float>(*count);
}

// The rotation is cast to int every frame: the fraction is carried over instead of dropped
static void WholeUnits(Site& site, Frame* stack, void* result)
{
	float scale;
	if (!result || !FrameScale(site, stack, scale) || fabsf(scale * TARGET_FRAME_TIME - TARGET_FRAME_TIME) <= TARGET_FRAME_WINDOW)
	{
		site.carry = 0.0f;
		return;
	}

	float* value = reinterpret_cast<float*>(result);
	if (*value == 0.0f)
	{
		site.carry = 0.0f;
		return;
	}

	float total = *value + site.carry;
	site.carry = total - truncf(total);
	*value = total;
}

struct ObjectClock
{
	UObject* object = nullptr;
	float carry = 0.0f;
	float lastSeen = 0.0f;
};

static ObjectClock objectClocks[MaxObjectClocks];

static ObjectClock& ClockOf(UObject* object, float now)
{
	ObjectClock* oldest = &objectClocks[0];
	for (ObjectClock& clock : objectClocks)
	{
		if (clock.object == object)
		{
			if (now < clock.lastSeen || now - clock.lastSeen > ObjectClockGap)
			{
				clock.carry = 0.0f;
			}

			clock.lastSeen = now;
			return clock;
		}

		if (!clock.object || clock.lastSeen < oldest->lastSeen) oldest = &clock;
	}

	*oldest = ObjectClock{ object, 0.0f, now };
	return *oldest;
}

// DeltaTime given as the 30fps frames that ended in this frame
static void ThirtyFPSTime(Site& site, Frame* stack, void* result)
{
	AActor* actor = static_cast<AActor*>(stack->Object);
	if (!result || !actor || !actor->WorldInfo)
		return;

	float* deltaTime = reinterpret_cast<float*>(result);
	ObjectClock& clock = ClockOf(actor, actor->WorldInfo->TimeSeconds);

	float realTime;
	if (!GetRealFrameTime(actor, *deltaTime, realTime))
	{
		clock.carry = 0.0f;
		return;
	}

	bool own;
	int frames = CountTargetFrames(realTime, clock.carry, own);
	if (own)
		return;

	*deltaTime = static_cast<float>(frames) * TARGET_FRAME_TIME * (*deltaTime / realTime);
}

static struct
{
	UObject* object = nullptr;
	float lastSeen = 0.0f;
	float carry = 0.0f;
	FVector last30; // the stick as the last 30fps frame left it
	FVector lastPushed;
	FVector given;
} inputGrid;

// oldPawnAccel is the stick of the last 30fps frame: a quick turn is a flick within one, as the game was tuned for
static void InputOnThirtyFPSFrames(Site& site, Frame* stack, void* result)
{
	auto* state = static_cast<UAlicePlayer_MovementStateBase*>(stack->Object);
	APawn* pawn = state ? reinterpret_cast<APawn*>(state->Pawn) : nullptr;
	float deltaTime, realTime;
	if (!result || !pawn || !pawn->WorldInfo || !state->Input || !SiteDeltaTime(site, stack, deltaTime) || !GetRealFrameTime(pawn, deltaTime, realTime))
	{
		inputGrid.object = nullptr;
		return;
	}

	FVector* oldAccel = reinterpret_cast<FVector*>(result);
	float now = pawn->WorldInfo->TimeSeconds;
	if (inputGrid.object == state && now == inputGrid.lastSeen)
	{
		*oldAccel = inputGrid.given;
		return;
	}

	FVector stick = state->Input->InputVector;
	auto* stand = state->IsA(UAlicePlayer_StandMovementState::StaticClass()) ? static_cast<UAlicePlayer_StandMovementState*>(state) : nullptr;
	bool due = stand && stand->bPossibleTurningWhileRunning;

	bool frame30;
	int pawnSteps = PawnFrameSteps(pawn);
	if (inputGrid.object != state || now < inputGrid.lastSeen || now - inputGrid.lastSeen > InputGridGap)
	{
		inputGrid.object = state;
		inputGrid.carry = 0.0f;
		inputGrid.last30 = *oldAccel;
		inputGrid.lastPushed = *oldAccel;
		frame30 = true;
	}
	else if (pawnSteps >= 0)
	{
		frame30 = pawnSteps > 0;
		inputGrid.carry = 0.0f;
	}
	else
	{
		bool own;
		frame30 = CountTargetFrames(realTime, inputGrid.carry, own) > 0;
	}

	inputGrid.lastSeen = now;
	FVector old;
	if (frame30)
	{
		old = inputGrid.last30;
		inputGrid.last30 = stick;
	}
	else
	{
		// a stick let go while a quick turn is due still turns on the next 30fps frame
		bool held = due && (stick | stick) == 0.0f && (inputGrid.lastPushed | inputGrid.lastPushed) != 0.0f;
		old = held ? inputGrid.lastPushed : stick;
	}

	if ((stick | stick) != 0.0f)
	{
		inputGrid.lastPushed = stick;
	}

	*oldAccel = old;
	inputGrid.given = old;
}

// Once flying to Alice, a pickup keeps going when she leaves its PickupRadius: she can outrun it while it speeds up
static void KeepFlyingToAlice(Site&, Frame* stack, void* result)
{
	auto* pickup = static_cast<AAliceItemPickupFactory*>(stack->Object);
	if (result && pickup && pickup->flyTime > 0.0f)
	{
		*reinterpret_cast<float*>(result) = FLT_MAX;
	}
}

struct PickupTrail
{
	UObject* pickup = nullptr;
	FVector from;
	FVector alice;
	float lastSeen = 0.0f;
};

static PickupTrail pickupTrails[MaxPickupTrails];

static bool WentThrough(const FVector& from, const FVector& to, const FVector& alice)
{
	constexpr float reachSq = PickupReach * PickupReach;
	FVector move = to - from;
	float lengthSq = move | move;
	if (lengthSq <= 0.0f || FVector::DistSquared(from, alice) < reachSq || FVector::DistSquared(to, alice) < reachSq)
		return false;

	float along = std::clamp(((alice - from) | move) / lengthSq, 0.0f, 1.0f);
	return FVector::DistSquared(from + move * along, alice) < reachSq;
}

static void GiveWhenThrough(Site&, Frame* stack, void* result)
{
	static UProperty* aliceLocal = nullptr;
	AActor* pickup = static_cast<AActor*>(stack->Object);
	if (!aliceLocal) aliceLocal = FindProperty(stack->Node, "Aliceloc", false);
	if (!result || !pickup || !pickup->WorldInfo || !aliceLocal || !stack->Locals)
		return;

	FVector alice;
	memcpy(&alice, stack->Locals + aliceLocal->Offset, sizeof(alice));
	float now = pickup->WorldInfo->TimeSeconds;

	PickupTrail* trail = nullptr;
	PickupTrail* oldest = &pickupTrails[0];
	for (PickupTrail& t : pickupTrails)
	{
		if (t.pickup == pickup)
		{
			trail = &t;
			break;
		}

		if (oldest->pickup && (!t.pickup || t.lastSeen < oldest->lastSeen)) oldest = &t;
	}

	bool through = trail && now > trail->lastSeen && now - trail->lastSeen <= PickupTrailGap && WentThrough(trail->from, pickup->Location, trail->alice);
	*(trail ? trail : oldest) = PickupTrail{ pickup, pickup->Location, alice, now };
	if (through)
	{
		*reinterpret_cast<int32_t*>(result) = 1;
	}
}

// NewRotation.Yaw += int(RawJoyRight * YawSpeed)
static const Expect jumpPadTurn[] =
{
	{ 0, Token::LocalVariable, Expect::Local, "YawSpeed" },
	{ -9, Token::LocalVariable, Expect::Local, "RawJoyRight" },
	{ -10, Token::Multiply_FloatFloat },
};

// The same, its int cast
static const Expect jumpPadWholeUnits[] =
{
	{ 0, Token::Multiply_FloatFloat },
	{ -2, Token::PrimitiveCast },
	{ -1, Token::FloatToIntCast },
	{ 1, Token::LocalVariable, Expect::Local, "RawJoyRight" },
	{ 10, Token::LocalVariable, Expect::Local, "YawSpeed" },
	{ 19, Token::EndFunctionParms },
};

// DeltaYaw = PlayerInput.RawJoyLookRight * getSteamVentRotationSpeed()
static const Expect steamVentTurn[] =
{
	{ 0, Token::VirtualFunction, Expect::Name, "getSteamVentRotationSpeed" },
	{ 9, Token::EndFunctionParms },
	{ -9, Token::InstanceVariable, Expect::Member, "RawJoyLookRight", &UPlayerInput::StaticClass },
};

// DeltaYaw = RawJoyRight * getSteamVentRotationSpeed(), in 2D
static const Expect steamVentTurn2D[] =
{
	{ 0, Token::VirtualFunction, Expect::Name, "getSteamVentRotationSpeed" },
	{ 9, Token::EndFunctionParms },
	{ -9, Token::LocalVariable, Expect::Local, "RawJoyRight" },
	{ -10, Token::Multiply_FloatFloat },
};

// NewRotation.Yaw += int(DeltaYaw)
static const Expect steamVentWholeUnits[] =
{
	{ 0, Token::LocalVariable, Expect::Local, "DeltaYaw" },
	{ -2, Token::PrimitiveCast },
	{ -1, Token::FloatToIntCast },
	{ 9, Token::EndFunctionParms },
	{ 10, Token::Jump },
};

// The same in 2D
static const Expect steamVentWholeUnits2D[] =
{
	{ 0, Token::LocalVariable, Expect::Local, "DeltaYaw" },
	{ -2, Token::PrimitiveCast },
	{ -1, Token::FloatToIntCast },
	{ 9, Token::EndFunctionParms },
	{ 10, Token::JumpIfNot },
};

// Pawn.Velocity *= 0.95
static const Expect floatDamping[] =
{
	{ 0, Token::FloatConst, Expect::Float, nullptr, nullptr, 0.95f },
	{ 5, Token::EndFunctionParms },
	{ -9, Token::InstanceVariable, Expect::Member, "Velocity", &AActor::StaticClass },
};

// GiantAliceTakeDamageCount += CrowdNum
static const Expect crowdCount[] =
{
	{ 0, Token::LocalVariable, Expect::Local, "CrowdNum" },
	{ -9, Token::InstanceVariable, Expect::Member, "GiantAliceTakeDamageCount", &AAlicePlayerController::StaticClass },
	{ -10, Token::AddEqual_IntInt },
};

// Move(Speed * flyTime * Dir)
static const Expect pickupTrail[] =
{
	{ 0, Token::InstanceVariable, Expect::Member, "Speed", &AAliceItemPickupFactory::StaticClass },
	{ -1, Token::Multiply_FloatFloat },
	{ 9, Token::InstanceVariable, Expect::Member, "flyTime", &AAliceItemPickupFactory::StaticClass },
};

// if (VSize(aliceLoc - Location) < 50)
static const Expect pickupReached[] =
{
	{ 0, Token::Less_FloatFloat },
	{ -3, Token::JumpIfNot },
	{ 1, Token::VSize },
	{ 2, Token::Subtract_VectorVector },
	{ 3, Token::LocalVariable, Expect::Local, "Aliceloc" },
	{ 12, Token::InstanceVariable, Expect::Member, "Location", &AActor::StaticClass },
};

// distance < abs(PickupRadius)
static const Expect pickupFollow[] =
{
	{ 0, Token::InstanceVariable, Expect::Member, "PickupRadius", &AAliceItemPickupFactory::StaticClass },
	{ -1, Token::Abs },
	{ -10, Token::LocalVariable, Expect::Local, "Distance" },
	{ -11, Token::Less_FloatFloat },
};

// ReliefTime += DeltaTime
static const Expect snoutRelief[] =
{
	{ 0, Token::LocalVariable, Expect::Local, "DeltaTime" },
	{ -10, Token::AddEqual_FloatFloat },
	{ -9, Token::InstanceVariable, Expect::Member, "ReliefTime", &ANoseActorBase::StaticClass },
	{ 10, Token::JumpIfNot },
};

// NewWeight += MorphOnSpeed
static const Expect morphOn[] =
{
	{ 0, Token::InstanceVariable, Expect::Member, "MorphOnSpeed", &AMorphSkeletalMeshActor::StaticClass },
	{ -10, Token::AddEqual_FloatFloat },
	{ -9, Token::InstanceVariable, Expect::Member, "NewWeight", &AMorphSkeletalMeshActor::StaticClass },
};

// NewWeight -= MorphOffSpeed
static const Expect morphOff[] =
{
	{ 0, Token::InstanceVariable, Expect::Member, "MorphOffSpeed", &AMorphSkeletalMeshActor::StaticClass },
	{ -10, Token::SubtractEqual_FloatFloat },
	{ -9, Token::InstanceVariable, Expect::Member, "NewWeight", &AMorphSkeletalMeshActor::StaticClass },
};

// oldPawnAccel = PawnAccel, then PawnAccel = Input.InputVector
static const Expect quickTurn[] =
{
	{ 0, Token::InstanceVariable, Expect::Member, "PawnAccel", &UAlicePlayer_MovementStateBase::StaticClass },
	{ -10, Token::Let },
	{ -9, Token::InstanceVariable, Expect::Member, "oldPawnAccel", &UAlicePlayer_MovementStateBase::StaticClass },
	{ 9, Token::Let },
	{ 10, Token::InstanceVariable, Expect::Member, "PawnAccel", &UAlicePlayer_MovementStateBase::StaticClass },
};

static const SiteSpec scriptSites[] =
{
	{ "Function AliceGame.AlicePlayerController.PlayerJumpPad.UpdateDeltaRotation", jumpPadTurn, std::size(jumpPadTurn), &ScaleAmount, "Function AliceGame.AlicePlayerController.PlayerJumpPad.UpdateDeltaRotation" },
	{ "Function AliceGame.AlicePlayerController.PlayerJumpPad.UpdateDeltaRotation", jumpPadWholeUnits, std::size(jumpPadWholeUnits), &WholeUnits, "Function AliceGame.AlicePlayerController.PlayerJumpPad.UpdateDeltaRotation" },
	{ "Function AliceGame.AlicePlayerController.PlayerSteamVent.UpdateDeltaRotation", steamVentTurn, std::size(steamVentTurn), &ScaleAmount, "Function AliceGame.AlicePlayerController.PlayerSteamVent.UpdateDeltaRotation" },
	{ "Function AliceGame.AlicePlayerController.PlayerSteamVent.UpdateDeltaRotation", steamVentTurn2D, std::size(steamVentTurn2D), &ScaleAmount, "Function AliceGame.AlicePlayerController.PlayerSteamVent.UpdateDeltaRotation" },
	{ "Function AliceGame.AlicePlayerController.PlayerSteamVent.UpdateDeltaRotation", steamVentWholeUnits, std::size(steamVentWholeUnits), &WholeUnits, "Function AliceGame.AlicePlayerController.PlayerSteamVent.UpdateDeltaRotation" },
	{ "Function AliceGame.AlicePlayerController.PlayerSteamVent.UpdateDeltaRotation", steamVentWholeUnits2D, std::size(steamVentWholeUnits2D), &WholeUnits, "Function AliceGame.AlicePlayerController.PlayerSteamVent.UpdateDeltaRotation" },
	{ "Function AliceGame.AlicePlayerController.PlayerFloat.UpdateRightAccel", floatDamping, std::size(floatDamping), &ScaleFactor, "Function AliceGame.AlicePlayerController.PlayerFloat.UpdateAccel" },
	{ "Function AliceGame.AlicePlayerController.PlayerTick", crowdCount, std::size(crowdCount), &ScaleCount, "Function AliceGame.AlicePlayerController.PlayerTick" },
	{ "Function AliceGame.AliceItemPickupFactory.LineTrail", pickupTrail, std::size(pickupTrail), &ScaleAmount, "Function AliceGame.AliceItemPickupFactory.LineTrail" },
	{ "Function AliceGame.AliceItemPickupFactory.LineTrail", pickupReached, std::size(pickupReached), &GiveWhenThrough },
	{ "Function AliceGame.AliceXPPickupFactory.IsValidPick", pickupFollow, std::size(pickupFollow), &KeepFlyingToAlice },
	{ "Function AliceGame.AliceHealthPickupFactory.IsValidPick", pickupFollow, std::size(pickupFollow), &KeepFlyingToAlice },
	{ "Function AliceGame.NoseActorBase.ReliefState.Tick", snoutRelief, std::size(snoutRelief), &ThirtyFPSTime },
	{ "Function AliceGame.MorphSkeletalMeshActor.DoMorph", morphOn, std::size(morphOn), &ScaleAmount, "Function AliceGame.MorphSkeletalMeshActor.Tick" },
	{ "Function AliceGame.MorphSkeletalMeshActor.DoMorph", morphOff, std::size(morphOff), &ScaleAmount, "Function AliceGame.MorphSkeletalMeshActor.Tick" },
	{ "Function AliceGame.AlicePlayer_MovementStateBase.CalculateMovementParameters", quickTurn, std::size(quickTurn), &InputOnThirtyFPSFrames, "Function AliceGame.AlicePlayer_MovementStateBase.CalculateMovementParameters" },
};

void ApplyFixHighFPSMovementsPhysics()
{
	if (!FixHighFPSMovementsPhysics) return;

	// Pawns
	GWorldAddress = GetAddress(Addr::GWorld);
	PawnPerformPhysics = HookHelper::CreateHook((void*)GetAddress(Addr::PawnPerformPhysics), &PawnPerformPhysics_Hook);
	PawnFootIKBlend = GetAddress(Addr::PawnFootIKBlend);
	PawnFootIKEnd = GetAddress(Addr::PawnFootIKEnd);
	PawnFootIKMeshReset = GetAddress(Addr::PawnFootIKMeshReset);
	PawnFootIKWalkingHook = safetyhook::create_mid(GetAddress(Addr::PawnFootIKWalking), OnPawnFootIKWalking);
	PawnFootIKFallingHook = safetyhook::create_mid(GetAddress(Addr::PawnFootIKFalling), OnPawnFootIKFalling);
	PawnTickFootIKDoneHook = safetyhook::create_mid(GetAddress(Addr::PawnTickFootIKDone), OnPawnTickFootIKDone);
	TickActorComponents = HookHelper::CreateHook((void*)GetAddress(Addr::TickActorComponents), &TickActorComponents_Hook);

	// Rolling
	InstallPhysXStepping();

	// Crowds
	CrowdAgentPerformPhysics = HookHelper::CreateHook((void*)GetAddress(Addr::CrowdAgentPerformPhysics), &CrowdAgentPerformPhysics_Hook);
	CrowdAgentTickSpecial = HookHelper::CreateHook((void*)GetAddress(Addr::CrowdAgentTickSpecial), &CrowdAgentTickSpecial_Hook);

	if (!CrowdAgentTickSpecial)
	{
		CrowdAgentPerformPhysics = {};
	}
}

void ResolveFixHighFPSMovementsPhysics()
{
	if (!FixHighFPSMovementsPhysics) return;

	RollingPhysics::Resolve();

	// Scripts
	for (const SiteSpec& spec : scriptSites)
	{
		InstallSite(spec);
	}
}