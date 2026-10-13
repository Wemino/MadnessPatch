#include "Common.hpp"
#include "Features.hpp"

static safetyhook::InlineHook AddToWorld;

struct SetAnimParams { FName Sequence; };
struct PlayAnimParams { uint32_t bLoop; float InRate; float StartTime; };
struct SetHiddenParams { uint32_t bNewHidden; };
struct SetEnabledParams { uint32_t bSetEnabled; };
struct ForceUpdateParams { uint32_t bTransformOnly; };

static UFunction* SetAnimFn = nullptr;
static UFunction* PlayAnimFn = nullptr;
static UFunction* SetHiddenFn = nullptr;
static UFunction* SetEnabledFn = nullptr;
static UFunction* ForceUpdateFn = nullptr;

static const char* BaseName(const FName& name)
{
	return name.IsValid() ? FName::Names()->at(name.GetDisplayIndex())->Name : "";
}

static bool NameIs(const FName& name, const char* base, int suffix = -1)
{
	return name.GetInstance() == suffix + 1 && strcmp(BaseName(name), base) == 0;
}

static TArray<AActor*>& LevelActors(ULevel* level)
{
	return *reinterpret_cast<TArray<AActor*>*>(reinterpret_cast<uint8_t*>(level) + 0x3C);
}

static USequence* LevelMainSequence(ULevel* level)
{
	TArray<USequence*>& sequences = *reinterpret_cast<TArray<USequence*>*>(reinterpret_cast<uint8_t*>(level) + 0xA0);
	return sequences.size() > 0 ? sequences[0] : nullptr;
}

static void CallScript(UObject* target, UFunction*& fn, const char* name, void* params)
{
	if (!target) return;

	if (!fn) fn = UFunction::FindFunction(name);
	if (!fn) return;

	reinterpret_cast<void(__thiscall*)(void*, UFunction*, void*, void*)>(GetAddress(Addr::ProcessEvent))(target, fn, params, nullptr);
}

static void ForceUpdate(UActorComponent* comp, bool transformOnly)
{
	ForceUpdateParams params{};
	params.bTransformOnly = transformOnly;
	CallScript(comp, ForceUpdateFn, "Function Engine.ActorComponent.ForceUpdate", &params);
}

// ---- Chapter 5 fort ----

constexpr const char* FortAnimated = "SK_InsaneKidC";
constexpr const char* FortSequence = "CH_Insanekid_Idle01_Long03";

static const char* FortHidden[] =
{
	"SK_InsaneKidA_Leader",
	"SK_InsaneKidB",
	"SK_InsaneKidD",
	"SK_InsaneKidE",
};

struct RawArray { void* Data; int32_t Count; int32_t Max; };
static UAnimSet* AnimSetSlot[1] = { nullptr };

static USkeletalMeshComponent* KidComponent(AActor* actor)
{
	if (!actor || !actor->IsA<ASkeletalMeshActor>())
		return nullptr;

	USkeletalMeshComponent* comp = static_cast<ASkeletalMeshActor*>(actor)->SkeletalMeshComponent;
	return (comp && comp->SkeletalMesh) ? comp : nullptr;
}

static void AnimateKid(ASkeletalMeshActor* actor, USkeletalMeshComponent* comp, UAnimSet* set)
{
	UAnimSequence* wanted = nullptr;
	for (int32_t i = 0; i < set->Sequences.size(); i++)
	{
		UAnimSequence* seq = set->Sequences[i];
		if (seq && NameIs(seq->SequenceName, FortSequence))
		{
			wanted = seq;
			break;
		}
	}

	UAnimNodeSequence* node = comp->Animations && comp->Animations->IsA<UAnimNodeSequence>() ? reinterpret_cast<UAnimNodeSequence*>(comp->Animations) : nullptr;
	if (!wanted || !node)
		return;

	bool present = false;
	for (int32_t i = 0; i < comp->AnimSets.size(); i++)
	{
		if (comp->AnimSets[i] == set)
		{
			present = true;
			break;
		}
	}

	RawArray* raw = reinterpret_cast<RawArray*>(&comp->AnimSets);
	RawArray saved = *raw;

	if (!present)
	{
		AnimSetSlot[0] = set;
		raw->Data = AnimSetSlot;
		raw->Count = 1;
		raw->Max = 1;
	}

	SetAnimParams setAnim{};
	setAnim.Sequence = wanted->SequenceName;
	CallScript(node, SetAnimFn, "Function Engine.AnimNodeSequence.SetAnim", &setAnim);

	if (!present)
	{
		*raw = saved;
	}

	PlayAnimParams playAnim{};
	playAnim.bLoop = 1;
	playAnim.InRate = 1.0f;
	playAnim.StartTime = 0.0f;
	CallScript(node, PlayAnimFn, "Function Engine.AnimNodeSequence.PlayAnim", &playAnim);

	comp->CastShadow = 0;
	comp->bCastDynamicShadow = 0;

	if (actor->LightEnvironment && actor->LightEnvironment->IsA<UDynamicLightEnvironmentComponent>())
	{
		reinterpret_cast<UDynamicLightEnvironmentComponent*>(actor->LightEnvironment)->bCastShadows = 0;
	}

	ForceUpdate(comp, false);
}

static void ApplyFort(ULevel* level)
{
	TArray<AActor*>& actors = LevelActors(level);

	UAnimSet* set = nullptr;
	for (AActor* actor : actors)
	{
		USkeletalMeshComponent* comp = KidComponent(actor);
		if (comp && comp->AnimSets.size() > 0)
		{
			set = comp->AnimSets[0];
			break;
		}
	}

	if (!set)
		return;

	for (AActor* actor : actors)
	{
		USkeletalMeshComponent* comp = KidComponent(actor);
		if (!comp || comp->SkeletalMesh->Name.GetInstance() != 0)
			continue;

		const char* mesh = BaseName(comp->SkeletalMesh->Name);

		if (strcmp(mesh, FortAnimated) == 0)
		{
			AnimateKid(static_cast<ASkeletalMeshActor*>(actor), comp, set);
			continue;
		}

		for (const char* hidden : FortHidden)
		{
			if (strcmp(mesh, hidden) == 0)
			{
				SetHiddenParams hide{};
				hide.bNewHidden = 1;
				CallScript(actor, SetHiddenFn, "Function Engine.Actor.SetHidden", &hide);
				break;
			}
		}
	}
}

// ---- CC_Rolling radula room ----

static void EnableLightEnvironments(TArray<UActorComponent*>& components)
{
	for (UActorComponent* comp : components)
	{
		if (!comp || !comp->IsA<UStaticMeshComponent>())
			continue;

		ULightEnvironmentComponent* env = static_cast<UStaticMeshComponent*>(comp)->LightEnvironment;
		if (!env || env->bEnabled)
			continue;

		SetEnabledParams params{};
		params.bSetEnabled = 1;
		CallScript(env, SetEnabledFn, "Function Engine.LightEnvironmentComponent.SetEnabled", &params);
	}
}

static void ApplyRadula(ULevel* level)
{
	for (AActor* actor : LevelActors(level))
	{
		if (!actor)
			continue;

		EnableLightEnvironments(actor->Components);
		EnableLightEnvironments(actor->AllComponents);
	}
}

// ---- Chapter 6 station lamps ----

constexpr float LampMatchRadius = 8.0f;

struct LampEdit
{
	float from[3];
	float offset[3];
};

static const LampEdit LampEdits[] =
{
	{ { 210105.891f, 181367.094f, 210640.875f }, { 0.0f,   0.0f, -100000.0f } },
	{ { 212002.391f, 179507.531f, 211036.594f }, { 0.0f,   0.0f, -100000.0f } },
	{ { 210105.422f, 181381.234f, 210638.875f }, { 0.0f, +25.0f,      0.0f } },
};

static void ApplyLamps(ULevel* level)
{
	for (AActor* actor : LevelActors(level))
	{
		if (!actor || !actor->IsA<AStaticMeshActor>())
			continue;

		AStaticMeshActor* lamp = static_cast<AStaticMeshActor*>(actor);
		if (!lamp->StaticMeshComponent)
			continue;

		for (const LampEdit& edit : LampEdits)
		{
			float dx = lamp->Location.X - edit.from[0];
			float dy = lamp->Location.Y - edit.from[1];
			float dz = lamp->Location.Z - edit.from[2];

			if ((dx * dx + dy * dy + dz * dz) > (LampMatchRadius * LampMatchRadius))
				continue;

			lamp->Location.X += edit.offset[0];
			lamp->Location.Y += edit.offset[1];
			lamp->Location.Z += edit.offset[2];
			ForceUpdate(lamp->StaticMeshComponent, true);
			break;
		}
	}
}

// ---- Chapter 4 infernal train flyby ----

static void ApplyTrain(ULevel* level)
{
	USequence* sequence = LevelMainSequence(level);
	if (!sequence)
		return;

	for (USequenceObject* obj : sequence->SequenceObjects)
	{
		if (!obj || !NameIs(obj->Name, "SeqEvent_Touch", 0) || !obj->IsA<USeqEvent_Touch>())
			continue;

		USeqEvent_Touch* touch = static_cast<USeqEvent_Touch*>(obj);
		if (touch->Originator && NameIs(touch->Originator->Name, "Trigger", 5))
		{
			touch->MaxTriggerCount = 1;
			return;
		}
	}
}

struct MapFix
{
	const char* level;
	void (*apply)(ULevel*);
};

static const MapFix MapFixes[] =
{
	{ "Chapter5_W1_Dfort1_DH", ApplyFort   },
	{ "CC_Rolling",            ApplyRadula },
	{ "Chapter6_Station_01",   ApplyLamps  },
	{ "Chapter4_W2_West_09_S", ApplyTrain  },
};

static int __fastcall AddToWorld_Hook(UWorld* world, int, ULevelStreaming* streaming, FVector* offset)
{
	bool wasVisible = streaming->bIsVisible;
	int result = AddToWorld.unsafe_thiscall<int>(world, streaming, offset);

	if (wasVisible || !streaming->bIsVisible || !streaming->LoadedLevel)
		return result;

	for (const MapFix& fix : MapFixes)
	{
		if (NameIs(streaming->PackageName, fix.level))
		{
			fix.apply(streaming->LoadedLevel);
			break;
		}
	}

	return result;
}

void ApplyFixMapProperties()
{
	if (!FixMapProperties) return;

	AddToWorld = HookHelper::CreateHook((void*)GetAddress(Addr::AddToWorld), &AddToWorld_Hook);
}
