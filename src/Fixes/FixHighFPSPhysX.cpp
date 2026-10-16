#include "Common.hpp"
#include "Features.hpp"

safetyhook::InlineHook GetUnrealWorldTM;
safetyhook::InlineHook ApexBoneWrite;
safetyhook::InlineHook ApexClothWrite;
static safetyhook::InlineHook TickWorldRBPhys{};
static safetyhook::InlineHook AddRBGravAndDamping{};
static safetyhook::InlineHook PhysXParticleSync{};
static safetyhook::InlineHook PhysXParticleTick{};
static safetyhook::InlineHook PhysXEmitterStepSize{};
static safetyhook::MidHook ragdollInterpInvalidate{};

constexpr float InterpSnapDistSq = 250.0f * 250.0f;
constexpr float RollingSnapDistSq = 2000.0f * 2000.0f; // a rolling step moves the ball up to 60000 units/s without a snap
constexpr double InterpStaleFactor = 4.0;
constexpr double PoseForgetTime = 1.0; // game time
constexpr size_t InterpMaxBodies = 4096;
constexpr size_t InterpMaxChunks = 16384;
constexpr size_t InterpMaxCloth = 256;
constexpr size_t InterpMaxParticleSystems = 256;
constexpr uint32_t PhysXParticleMaxId = 0xFFFF;
constexpr float PhysXScale = 50.0f; // Unreal units per PhysX unit
constexpr size_t MaxGravityActors = 256;

// ---- Scene ----

struct GravityActor
{
	AActor* actor = nullptr;
	int32_t index = 0;
	UClass* cls = nullptr;
};

static std::vector<GravityActor> gravityActors;
static bool applyingGravity = false;
static float sceneAccumulator = TARGET_FRAME_TIME;
static float sceneLastStepTime = TARGET_FRAME_TIME;
static uint32_t particleStep = 0;
static float particleAlpha = 1.0f;

static bool StillThere(const GravityActor& g)
{
	TArray<UObject*>* objects = UObject::GObjObjects();
	return objects && g.index >= 0 && g.index < objects->size() && objects->at(g.index) == g.actor && g.actor->Class == g.cls && !g.actor->bDeleteMe && g.actor->Physics == EPhysics::PHYS_RigidBody;
}

static void ApplyGravity()
{
	applyingGravity = true;
	for (const GravityActor& g : gravityActors)
	{
		if (StillThere(g))
		{
			AddRBGravAndDamping.unsafe_thiscall<void>(g.actor);
		}
	}
	applyingGravity = false;
	gravityActors.clear();
}

static void __fastcall AddRBGravAndDamping_Hook(AActor* actor, void*)
{
	if (!g_State.physSceneStepped || applyingGravity || !actor)
	{
		AddRBGravAndDamping.unsafe_thiscall<void>(actor);
		return;
	}

	for (const GravityActor& g : gravityActors)
	{
		if (g.actor == actor)
			return;
	}

	if (gravityActors.size() >= MaxGravityActors)
	{
		AddRBGravAndDamping.unsafe_thiscall<void>(actor);
		return;
	}

	gravityActors.push_back({ actor, actor->ObjectInternalInteger, actor->Class });
}

static void __fastcall TickWorldRBPhys_Hook(UWorld* world, void*, float DeltaSeconds)
{
	bool rolling = BeforeRBPhysTick();
	particleStep = g_State.physSceneStep;
	particleAlpha = g_State.physSceneAlpha;

	double frameClock = g_State.physClock;
	if (DeltaSeconds > 0.0f)
	{
		g_State.physClock += DeltaSeconds;
	}

	AAlicePlayerController* pc = g_State.AlicePlayerController;
	float timeDilation = pc && pc->WorldInfo ? pc->WorldInfo->TimeDilation : 0.0f;
	bool stepped = (rolling ? FixHighFPSMovementsPhysics : FixHighFPSPhysX) && AddRBGravAndDamping && timeDilation * TARGET_FRAME_TIME >= MIN_WORLD_FRAME_TIME;
	if (!stepped)
	{
		HoldRollingPushes(false, false);
		if (g_State.physSceneStepped)
		{
			g_State.physSceneStepped = false;
			g_State.physSceneAlpha = 1.0f;
			ApplyGravity();
		}

		TickWorldRBPhys.unsafe_thiscall<void>(world, DeltaSeconds);
		return;
	}

	if (!g_State.physSceneStepped)
	{
		g_State.physSceneStepped = true;
		sceneAccumulator = TARGET_FRAME_TIME;
		sceneLastStepTime = TARGET_FRAME_TIME;
	}

	float gameTime = 0.0f;
	int steps = 0;
	if (DeltaSeconds > 0.0f) // zero while the world only ticks the players
	{
		float frameTime = DeltaSeconds / timeDilation;
		bool inStep = sceneAccumulator == TARGET_FRAME_TIME;
		sceneAccumulator += frameTime;

		bool fullFrame = fabsf(frameTime - TARGET_FRAME_TIME) <= TARGET_FRAME_WINDOW;
		float due = TARGET_FRAME_TIME + (fullFrame ? TARGET_FRAME_WINDOW : TARGET_STEP_SLACK);
		while (sceneAccumulator > due && steps < MAX_TARGET_STEPS)
		{
			TargetStep step = NextTargetStep(sceneAccumulator, fullFrame, inStep, frameTime, DeltaSeconds, timeDilation);
			sceneAccumulator = step.landed ? TARGET_FRAME_TIME : sceneAccumulator - step.realTime;
			sceneLastStepTime = step.realTime;
			gameTime += step.gameTime;
			steps++;
		}

		if (sceneAccumulator > due)
		{
			sceneAccumulator = fmodf(sceneAccumulator, TARGET_FRAME_TIME);
		}
	}

	if (steps > 0)
	{
		g_State.physSceneReleaseSince = frameClock;
		g_State.physSceneReleasing = true;
	}

	HoldRollingPushes(true, steps > 0);
	g_State.physSceneReleasing = false;

	if (steps > 0)
	{
		ApplyGravity();
		g_State.physSceneStep++;
		g_State.physSceneStepClock = g_State.physClock;
	}

	gravityActors.clear(); // a frame without a step makes none
	TickWorldRBPhys.unsafe_thiscall<void>(world, gameTime);
	g_State.physSceneAlpha = std::clamp(1.0f - (TARGET_FRAME_TIME - sceneAccumulator) / sceneLastStepTime, 0.0f, 1.0f);
}

// ---- Poses ----

struct BodyPoseState
{
	FVector prevPos, currPos;
	FQuat prevQuat, currQuat;
	double lastSeen = 0.0;
	float lastMoveSq = 0.0f;
	uint32_t step = 0; // the scene step that moved it last
	bool primed = false;
};
static std::unordered_map<uintptr_t, BodyPoseState> bodyPoses;
static std::unordered_map<uintptr_t, BodyPoseState> chunkPoses;
static double bodyPurge = 0.0, chunkPurge = 0.0;

struct ClothPoseState
{
	std::vector<float> prev, curr, scratch[2];
	int flip = 0;
	double lastSeen = 0.0;
	uint32_t step = 0;
	bool primed = false;
};
static std::unordered_map<uintptr_t, ClothPoseState> clothPoses;
static double clothPurge = 0.0;

template <typename Map>
static void PurgePoses(Map& poses, double& lastPurge, size_t maxPoses)
{
	double now = g_State.physClock;
	if (now >= lastPurge && now - lastPurge < PoseForgetTime && poses.size() <= maxPoses)
		return;

	lastPurge = now;
	for (auto it = poses.begin(); it != poses.end();)
	{
		if (now < it->second.lastSeen || now - it->second.lastSeen > PoseForgetTime)
		{
			it = poses.erase(it);
		}
		else
		{
			++it;
		}
	}

	if (poses.size() > maxPoses)
	{
		poses.clear();
	}
}

static inline FQuat QuatFromAxes(const FVector& x, const FVector& y, const FVector& z)
{
	FQuat q;
	float trace = x.X + y.Y + z.Z;
	if (trace > 0.0f)
	{
		float s = sqrtf(trace + 1.0f) * 2.0f;
		q.W = 0.25f * s;
		q.X = (y.Z - z.Y) / s;
		q.Y = (z.X - x.Z) / s;
		q.Z = (x.Y - y.X) / s;
	}
	else if (x.X > y.Y && x.X > z.Z)
	{
		float s = sqrtf(1.0f + x.X - y.Y - z.Z) * 2.0f;
		q.W = (y.Z - z.Y) / s;
		q.X = 0.25f * s;
		q.Y = (y.X + x.Y) / s;
		q.Z = (z.X + x.Z) / s;
	}
	else if (y.Y > z.Z)
	{
		float s = sqrtf(1.0f + y.Y - x.X - z.Z) * 2.0f;
		q.W = (z.X - x.Z) / s;
		q.X = (y.X + x.Y) / s;
		q.Y = 0.25f * s;
		q.Z = (z.Y + y.Z) / s;
	}
	else
	{
		float s = sqrtf(1.0f + z.Z - x.X - y.Y) * 2.0f;
		q.W = (x.Y - y.X) / s;
		q.X = (z.X + x.Z) / s;
		q.Y = (z.Y + y.Z) / s;
		q.Z = 0.25f * s;
	}

	return q;
}

static inline void QuatToAxes(const FQuat& q, FVector& x, FVector& y, FVector& z)
{
	x = FVector(1.0f - 2.0f * (q.Y * q.Y + q.Z * q.Z), 2.0f * (q.X * q.Y + q.W * q.Z), 2.0f * (q.X * q.Z - q.W * q.Y));
	y = FVector(2.0f * (q.X * q.Y - q.W * q.Z), 1.0f - 2.0f * (q.X * q.X + q.Z * q.Z), 2.0f * (q.Y * q.Z + q.W * q.X));
	z = FVector(2.0f * (q.X * q.Z + q.W * q.Y), 2.0f * (q.Y * q.Z - q.W * q.X), 1.0f - 2.0f * (q.X * q.X + q.Y * q.Y));
}

static inline FQuat QuatNlerp(const FQuat& a, const FQuat& b, float t)
{
	float dot = a.X * b.X + a.Y * b.Y + a.Z * b.Z + a.W * b.W;
	float s = dot < 0.0f ? -t : t;
	FQuat q(a.X * (1.0f - t) + b.X * s, a.Y * (1.0f - t) + b.Y * s, a.Z * (1.0f - t) + b.Z * s, a.W * (1.0f - t) + b.W * s);

	if (!q.Normalize())
	{
		q = FQuat();
	}

	return q;
}

static inline FQuat QuatSlerp(const FQuat& a, const FQuat& b, float t)
{
	float dot = a.X * b.X + a.Y * b.Y + a.Z * b.Z + a.W * b.W;
	const float sign = dot < 0.0f ? -1.0f : 1.0f;
	dot = fabsf(dot);
	if (dot > 0.9995f)
		return QuatNlerp(a, b, t);

	const float angle = acosf(dot);
	const float inv = 1.0f / sinf(angle);
	const float wa = sinf((1.0f - t) * angle) * inv;
	const float wb = sinf(t * angle) * inv * sign;
	FQuat q(a.X * wa + b.X * wb, a.Y * wa + b.Y * wb, a.Z * wa + b.Z * wb, a.W * wa + b.W * wb);

	if (!q.Normalize())
	{
		q = FQuat();
	}

	return q;
}

static bool TrackPose(BodyPoseState& st, const FVector& pos, const FQuat& quat, float snapDistSq)
{
	double now = g_State.physClock;
	bool stale = st.primed && (now - st.lastSeen) > TARGET_FRAME_TIME * InterpStaleFactor;
	st.lastSeen = now;

	if (!st.primed || stale)
	{
		st.prevPos = pos;
		st.currPos = pos;
		st.prevQuat = quat;
		st.currQuat = quat;
		st.step = g_State.physSceneStep - 1;
		st.lastMoveSq = 0.0f;
		st.primed = true;
		return false;
	}

	if (st.currPos == pos && st.currQuat == quat)
		return false;

	float moveSq = FVector::DistSquared(st.currPos, pos);
	bool snap = moveSq > snapDistSq && moveSq > 4.0f * st.lastMoveSq; 
	st.lastMoveSq = moveSq;
	if (snap)
	{
		st.prevPos = pos;
		st.prevQuat = quat;
	}
	else
	{
		st.prevPos = st.currPos;
		st.prevQuat = st.currQuat;
	}

	st.currPos = pos;
	st.currQuat = quat;
	return true;
}

static float SceneBlend(uint32_t& step, bool changed, double lastSeen)
{
	if (!changed)
		return step == g_State.physSceneStep ? g_State.physSceneAlpha : 1.0f;

	if (step == g_State.physSceneStep || lastSeen > g_State.physSceneStepClock)
		return -1.0f;

	step = g_State.physSceneStep;
	return g_State.physSceneAlpha;
}

constexpr float RollingHiddenTurnCos = 0.9238795f; // cos(22.5 deg)

static float BodyPoseAlpha(BodyPoseState& st, const FVector& pos, const FQuat& quat)
{
	if (g_State.physSceneReleasing && st.primed && st.lastSeen >= g_State.physSceneReleaseSince && FVector::DistSquared(st.currPos, pos) <= InterpSnapDistSq && fabsf(st.currQuat.X * quat.X + st.currQuat.Y * quat.Y + st.currQuat.Z * quat.Z + st.currQuat.W * quat.W) >= RollingHiddenTurnCos)
	{
		// set by the step's own calls before it simulates (a head switch holding the ball): never shown at 30fps
		return SceneBlend(st.step, false, st.lastSeen);
	}

	double lastSeen = st.lastSeen;
	bool changed = TrackPose(st, pos, quat, g_State.rollingMode ? RollingSnapDistSq : InterpSnapDistSq);
	float alpha = SceneBlend(st.step, changed, lastSeen);
	if (alpha >= 0.0f)
		return alpha;

	st.prevPos = st.currPos;
	st.prevQuat = st.currQuat;
	return 1.0f;
}

static FMatrix* __fastcall GetUnrealWorldTM_Hook(URB_BodyInstance* thisPtr, int, FMatrix* outM)
{
	GetUnrealWorldTM.unsafe_thiscall<FMatrix*>(thisPtr, outM);

	uintptr_t key = thisPtr->BodyData.Dummy; // NxActor*
	if (!key || !g_State.physSceneStepped)
		return outM;

	FVector pos(outM->WPlane.X, outM->WPlane.Y, outM->WPlane.Z);
	FQuat quat = QuatFromAxes(outM->XPlane, outM->YPlane, outM->ZPlane);

	PurgePoses(bodyPoses, bodyPurge, InterpMaxBodies);
	BodyPoseState& st = bodyPoses[key];
	const float alpha = BodyPoseAlpha(st, pos, quat);

	FVector p = st.prevPos + (st.currPos - st.prevPos) * alpha;
	outM->WPlane.X = p.X;
	outM->WPlane.Y = p.Y;
	outM->WPlane.Z = p.Z;

	FVector ax, ay, az;
	QuatToAxes(QuatSlerp(st.prevQuat, st.currQuat, alpha), ax, ay, az);
	static_cast<FVector&>(outM->XPlane) = ax;
	static_cast<FVector&>(outM->YPlane) = ay;
	static_cast<FVector&>(outM->ZPlane) = az;

	return outM;
}

static void OnRagdollTransition(safetyhook::Context& ctx)
{
	const uintptr_t actorAddr = (Addresses::GetBuild() == GameBuild::Current) ? ctx.esi : ctx.edi;

	auto* dropActor = reinterpret_cast<AAliceGameDropActor*>(actorAddr);
	if (!dropActor) return;

	USkeletalMeshComponent* skelComp = dropActor->SkelComp;
	if (!skelComp) return;

	UPhysicsAssetInstance* inst = skelComp->PhysicsAssetInstance;
	if (!inst) return;

	const TArray<URB_BodyInstance*>& bodies = inst->Bodies;
	const int32_t numBodies = bodies.size();
	if (!bodies.data() || numBodies <= 0 || numBodies > 512) return;

	for (int32_t i = 0; i < numBodies; i++)
	{
		URB_BodyInstance* body = bodies[i];
		if (body && body->BodyData.Dummy)
		{
			bodyPoses.erase(body->BodyData.Dummy);
		}
	}
}

static void __fastcall ApexBoneWrite_Hook(uint32_t* thisPtr, int, int* data, uint32_t firstBone, uint32_t numBones)
{
	ApexBoneWrite.unsafe_thiscall<void>(thisPtr, data, firstBone, numBones);

	float* poses = reinterpret_cast<float*>(thisPtr[1]);
	uint32_t maxBones = thisPtr[2];
	if (!poses || numBones > maxBones || firstBone > maxBones - numBones || !g_State.physSceneStepped)
		return;

	PurgePoses(chunkPoses, chunkPurge, InterpMaxChunks);

	for (uint32_t i = 0; i < numBones; i++)
	{
		float* f = poses + (firstBone + i) * 12;

		FVector pos(f[3], f[7], f[11]);

		FVector ax(f[0], f[4], f[8]);
		FVector ay(f[1], f[5], f[9]);
		FVector az(f[2], f[6], f[10]);
		float sx = ax.Size(), sy = ay.Size(), sz = az.Size();
		if (sx < 1e-4f || sy < 1e-4f || sz < 1e-4f)
			continue;

		ax /= sx;
		ay /= sy;
		az /= sz;

		float det = ax | (ay ^ az);
		bool rotOk = det > 0.5f;

		FQuat quat = rotOk ? QuatFromAxes(ax, ay, az) : FQuat();

		BodyPoseState& st = chunkPoses[reinterpret_cast<uintptr_t>(f)];
		const float alpha = BodyPoseAlpha(st, pos, quat);

		FVector p = st.prevPos + (st.currPos - st.prevPos) * alpha;
		f[3] = p.X;
		f[7] = p.Y;
		f[11] = p.Z;

		if (!rotOk)
			continue;

		QuatToAxes(QuatSlerp(st.prevQuat, st.currQuat, alpha), ax, ay, az);

		// rebuild the 3x3 with each column's original scale restored
		f[0] = ax.X * sx;
		f[4] = ax.Y * sx;
		f[8] = ax.Z * sx;
		f[1] = ay.X * sy;
		f[5] = ay.Y * sy;
		f[9] = ay.Z * sy;
		f[2] = az.X * sz;
		f[6] = az.Y * sz;
		f[10] = az.Z * sz;
	}
}

static void __fastcall ApexClothWrite_Hook(uint32_t* thisPtr, int, uint8_t* data, uint32_t firstVertex, uint32_t numVerts)
{
	float* srcPos = *reinterpret_cast<float**>(data);
	uint32_t srcStride = *reinterpret_cast<uint32_t*>(data + 4);
	uint32_t maxVerts = thisPtr[8];

	if (!srcPos || srcStride < 12 || firstVertex != 0 || !numVerts || numVerts > maxVerts || maxVerts > 4096 || !g_State.physSceneStepped)
	{
		ApexClothWrite.unsafe_thiscall<void>(thisPtr, data, firstVertex, numVerts);
		return;
	}

	PurgePoses(clothPoses, clothPurge, InterpMaxCloth);

	ClothPoseState& st = clothPoses[reinterpret_cast<uintptr_t>(thisPtr)];
	double now = g_State.physClock;

	if (st.curr.size() != numVerts * 3)
	{
		st.prev.assign(numVerts * 3, 0.0f);
		st.curr.assign(numVerts * 3, 0.0f);
		st.scratch[0].assign(numVerts * 3, 0.0f);
		st.scratch[1].assign(numVerts * 3, 0.0f);
		st.primed = false;
	}

	const uint8_t* src = reinterpret_cast<const uint8_t*>(srcPos);

	bool changed = false;
	for (uint32_t i = 0; i < numVerts; i++)
	{
		const float* v = reinterpret_cast<const float*>(src + i * srcStride);
		const float* c = &st.curr[i * 3];

		if (c[0] != v[0] || c[1] != v[1] || c[2] != v[2]) // bit-identical until a sim step ran
		{
			changed = true;
			break;
		}
	}

	bool stale = st.primed && (now - st.lastSeen) > TARGET_FRAME_TIME * InterpStaleFactor;
	const double lastSeen = st.lastSeen;
	st.lastSeen = now;

	if (!st.primed || stale)
	{
		for (uint32_t i = 0; i < numVerts; i++)
		{
			memcpy(&st.curr[i * 3], src + i * srcStride, 12);
		}

		st.prev = st.curr;
		st.step = g_State.physSceneStep - 1;
		st.primed = true;

		ApexClothWrite.unsafe_thiscall<void>(thisPtr, data, firstVertex, numVerts);
		return;
	}

	if (changed)
	{
		const float* v0 = reinterpret_cast<const float*>(src);
		float dx = st.curr[0] - v0[0], dy = st.curr[1] - v0[1], dz = st.curr[2] - v0[2];
		bool snap = dx * dx + dy * dy + dz * dz > 25.0f;

		if (!snap)
		{
			st.prev = st.curr;
		}

		for (uint32_t i = 0; i < numVerts; i++)
		{
			memcpy(&st.curr[i * 3], src + i * srcStride, 12);
		}

		if (snap)
		{
			st.prev = st.curr;
		}
	}

	float alpha = SceneBlend(st.step, changed, lastSeen);
	if (alpha < 0.0f)
	{
		st.prev = st.curr;
		alpha = 1.0f;
	}

	std::vector<float>& out = st.scratch[st.flip];
	st.flip ^= 1;

	for (uint32_t i = 0; i < numVerts * 3; i++)
	{
		out[i] = st.prev[i] + (st.curr[i] - st.prev[i]) * alpha;
	}

	*reinterpret_cast<float**>(data) = out.data();
	*reinterpret_cast<uint32_t*>(data + 4) = 12;

	ApexClothWrite.unsafe_thiscall<void>(thisPtr, data, firstVertex, numVerts);

	*reinterpret_cast<float**>(data) = srcPos;
	*reinterpret_cast<uint32_t*>(data + 4) = srcStride;
}

// ---- Particles ----

struct PhysXParticle
{
	FVector Pos;
	FVector Vel;
	float Density;
	uint32_t Id;
	uint32_t Flags;
};
static_assert(sizeof(PhysXParticle) == 36);

struct ParticlePose
{
	FVector prev, curr;
	uint32_t step = 0;
	bool added = false;
};

struct ParticleSystemPoses
{
	std::vector<ParticlePose> poses; // by particle id
	uint32_t fluid = 0;
	uint32_t step = 0;
	int32_t stepped = 0; // the particles of the last data, ahead of the ones added since
	double lastSeen = 0.0;
};
static std::unordered_map<uintptr_t, ParticleSystemPoses> particlePoses;
static double particlePurge = 0.0;
static std::vector<int32_t> blendedParticles;

static ParticlePose* ParticlePoseOf(ParticleSystemPoses& st, uint32_t id)
{
	if (id > PhysXParticleMaxId)
		return nullptr;

	if (id >= st.poses.size())
	{
		st.poses.resize(id + 1);
	}

	return &st.poses[id];
}

static void __fastcall PhysXParticleSync_Hook(uint32_t* psys, void*)
{
	const int32_t fetched = static_cast<int32_t>(psys[11]);
	PhysXParticleSync.unsafe_thiscall<void>(psys);

	auto* particles = reinterpret_cast<PhysXParticle*>(psys[3]);
	if (!g_State.physSceneStepped || !particles)
		return;

	PurgePoses(particlePoses, particlePurge, InterpMaxParticleSystems);
	ParticleSystemPoses& st = particlePoses[reinterpret_cast<uintptr_t>(psys)];
	st.lastSeen = g_State.physClock;
	if (st.fluid != psys[1]) // released with its last particle
	{
		st.fluid = psys[1];
		st.poses.clear();
		st.stepped = 0;
	}

	if (psys[25])
	{
		const uint32_t lastStep = st.step;
		const bool again = lastStep == particleStep;
		st.step = particleStep;
		st.stepped = fetched;
		for (int32_t i = 0; i < fetched; i++)
		{
			const PhysXParticle& p = particles[i];
			ParticlePose* pose = ParticlePoseOf(st, p.Id);
			if (!pose)
				continue;

			if (again && (pose->step == st.step || pose->added))
			{
				if (pose->curr != p.Pos)
				{
					pose->prev = pose->curr = p.Pos;
				}

				pose->step = st.step;
				pose->added = false;
				continue;
			}

			bool known = pose->added || (pose->step == lastStep && lastStep + 1 == st.step);
			pose->prev = known && FVector::DistSquared(pose->curr, p.Pos) * PhysXScale * PhysXScale <= InterpSnapDistSq ? pose->curr : p.Pos;
			pose->curr = p.Pos;
			pose->step = st.step;
			pose->added = false;
		}
	}

	const int32_t count = static_cast<int32_t>(psys[11]);
	for (int32_t i = std::max(fetched, 0); i < count; i++)
	{
		ParticlePose* pose = ParticlePoseOf(st, particles[i].Id);
		if (pose)
		{
			pose->prev = pose->curr = particles[i].Pos;
			pose->added = true;
		}
	}
}

static void __fastcall PhysXParticleTick_Hook(uint32_t* psys, void*, float DeltaTime)
{
	auto it = particlePoses.end();
	if (g_State.physSceneStepped && particleAlpha < 1.0f)
	{
		it = particlePoses.find(reinterpret_cast<uintptr_t>(psys));
	}

	auto* particles = reinterpret_cast<PhysXParticle*>(psys[3]);
	if (it == particlePoses.end() || it->second.step != particleStep || it->second.fluid != psys[1] || !particles)
	{
		PhysXParticleTick.unsafe_thiscall<void>(psys, DeltaTime);
		return;
	}

	ParticleSystemPoses& st = it->second;
	const int32_t count = std::min(st.stepped, static_cast<int32_t>(psys[11]));
	blendedParticles.clear();
	for (int32_t i = 0; i < count; i++)
	{
		PhysXParticle& p = particles[i];
		if (p.Id >= st.poses.size())
			continue;

		const ParticlePose& pose = st.poses[p.Id];
		if (pose.step != st.step || pose.curr != p.Pos || pose.prev == pose.curr)
			continue;

		p.Pos = pose.prev + (pose.curr - pose.prev) * particleAlpha;
		blendedParticles.push_back(i);
	}

	PhysXParticleTick.unsafe_thiscall<void>(psys, DeltaTime);

	for (int32_t i : blendedParticles)
	{
		particles[i].Pos = st.poses[particles[i].Id].curr;
	}
}

static void __fastcall PhysXEmitterStepSize_Hook(uint8_t* emitter, void*, float DeltaTime)
{
	PhysXEmitterStepSize.unsafe_thiscall<void>(emitter, DeltaTime);

	AAlicePlayerController* pc = g_State.AlicePlayerController;
	if (g_State.physSceneStepped && pc && pc->WorldInfo)
	{
		*reinterpret_cast<float*>(emitter + 0x48) = std::min(DeltaTime, pc->WorldInfo->MaxPhysicsDeltaTime);
	}
}

void InstallPhysXStepping()
{
	static bool installed = false;
	if (installed) return;
	installed = true;

	TickWorldRBPhys = HookHelper::CreateHook((void*)GetAddress(Addr::TickWorldRBPhys), &TickWorldRBPhys_Hook);
	AddRBGravAndDamping = HookHelper::CreateHook((void*)GetAddress(Addr::AddRBGravAndDamping), &AddRBGravAndDamping_Hook);
	GetUnrealWorldTM = HookHelper::CreateHook((void*)GetAddress(Addr::GetUnrealWorldTM), &GetUnrealWorldTM_Hook);
	ApexBoneWrite = HookHelper::CreateHook((void*)GetAddress(Addr::ApexBoneBufferWrite), &ApexBoneWrite_Hook);
	ApexClothWrite = HookHelper::CreateHook((void*)GetAddress(Addr::ApexClothVertexWrite), &ApexClothWrite_Hook);
	PhysXParticleSync = HookHelper::CreateHook((void*)GetAddress(Addr::PhysXParticleSync), &PhysXParticleSync_Hook);
	PhysXParticleTick = HookHelper::CreateHook((void*)GetAddress(Addr::PhysXParticleTick), &PhysXParticleTick_Hook);
	PhysXEmitterStepSize = HookHelper::CreateHook((void*)GetAddress(Addr::PhysXEmitterStepSize), &PhysXEmitterStepSize_Hook);
}

void ApplyFixHighFPSPhysX()
{
	if (!FixHighFPSPhysX) return;

	InstallPhysXStepping();
	ragdollInterpInvalidate = safetyhook::create_mid(GetAddress(Addr::RagdollTransition), OnRagdollTransition);
}