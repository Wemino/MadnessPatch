#include "Common.hpp"
#include "Features.hpp"

static SafetyHookInline RangeAttackPawnCollisionCheck{};
static safetyhook::MidHook RangeAttackOverlapResult{};

constexpr float ProjectileForgetTime = 5.0f;

// FCheckResult: FIteratorList::Next, FIteratorActorList::Actor
struct CheckResultNode
{
	CheckResultNode* next;
	AActor* actor;
};

struct ProjectileState
{
	int32_t index = -1;
	float creationTime = 0.0f;
	float lastSeen = 0.0f;
	float carry = 0.0f;
	FVector checkedTo;
};

static std::unordered_map<AAliceGameProjectile*, ProjectileState> projectileStates;
static AAliceGameProjectile* pawnsOnlyCheck = nullptr;

static void PurgeProjectileStates(float now)
{
	static float lastPurge = 0.0f;
	if (now >= lastPurge && now - lastPurge < 1.0f)
		return;

	lastPurge = now;
	for (auto it = projectileStates.begin(); it != projectileStates.end();)
	{
		if (now < it->second.lastSeen || now - it->second.lastSeen > ProjectileForgetTime)
		{
			it = projectileStates.erase(it);
		}
		else
		{
			++it;
		}
	}
}

static void __fastcall RangeAttackPawnCollisionCheck_Hook(AAliceGameProjectile* projectile, void*, float DeltaSeconds)
{
	float realTime;
	if (!projectile || !projectile->WorldInfo || !GetRealFrameTime(projectile, DeltaSeconds, realTime))
	{
		if (projectile)
		{
			projectileStates.erase(projectile);
		}

		RangeAttackPawnCollisionCheck.unsafe_thiscall<void>(projectile, DeltaSeconds);
		return;
	}

	float now = projectile->WorldInfo->TimeSeconds;
	PurgeProjectileStates(now);

	ProjectileState& st = projectileStates[projectile];
	float tickTime = DeltaSeconds / projectile->CustomTimeDilation;
	if (st.index != projectile->ObjectInternalInteger || st.creationTime != projectile->CreationTime || now < st.lastSeen || now - st.lastSeen > 1.5f * tickTime + now * 4e-7f + 1e-4f)
	{
		st = ProjectileState{ projectile->ObjectInternalInteger, projectile->CreationTime, now, 0.0f, projectile->LastLocation };
	}

	st.lastSeen = now;

	bool own;
	int frames = CountTargetFrames(realTime, st.carry, own);
	if (frames == 0 && !projectile->bInExplodeDamage)
	{
		AAliceGameProjectile* outer = pawnsOnlyCheck;
		pawnsOnlyCheck = projectile;
		RangeAttackPawnCollisionCheck.unsafe_thiscall<void>(projectile, DeltaSeconds);
		pawnsOnlyCheck = outer;
		return;
	}

	float frameTime = own ? DeltaSeconds : (frames > 1 ? frames : 1) * TARGET_FRAME_TIME * (DeltaSeconds / realTime);
	projectile->LastLocation = st.checkedTo;
	RangeAttackPawnCollisionCheck.unsafe_thiscall<void>(projectile, frameTime);
	st.checkedTo = projectile->Location;
}

static void OnRangeAttackOverlapResult(safetyhook::Context& ctx)
{
	AAliceGameProjectile* projectile = reinterpret_cast<AAliceGameProjectile*>(ctx.edi);
	CheckResultNode* head = reinterpret_cast<CheckResultNode*>(ctx.eax);
	if (!head || !projectile || projectile != pawnsOnlyCheck)
		return;

	CheckResultNode** link = &head;
	for (CheckResultNode* node = head; node; node = node->next)
	{
		if (!node->actor || node->actor->IsA(APawn::StaticClass()))
		{
			link = &node->next;
			continue;
		}

		*link = node->next;
	}

	ctx.eax = reinterpret_cast<uintptr_t>(head);
}

void ApplyFixHighFPSProjectileCollisionCheck()
{
	if (!FixHighFPSProjectileCollisionCheck) return;

	RangeAttackPawnCollisionCheck = HookHelper::CreateHook((void*)GetAddress(Addr::RangeAttackPawnCollisionCheck), &RangeAttackPawnCollisionCheck_Hook);
	RangeAttackOverlapResult = safetyhook::create_mid(GetAddress(Addr::RangeAttackOverlapResult), OnRangeAttackOverlapResult);
}
