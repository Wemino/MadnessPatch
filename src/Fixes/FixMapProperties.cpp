#include "Common.hpp"
#include "Features.hpp"

static safetyhook::InlineHook AddToWorld;
static safetyhook::InlineHook ActorSetHidden;

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

static bool FullNameIs(const FName& name, const char* full)
{
	const char* base = BaseName(name);
	size_t length = strlen(base);
	if (strncmp(full, base, length) != 0)
		return false;

	if (name.GetInstance() == 0)
		return full[length] == '\0';

	char suffix[16];
	snprintf(suffix, sizeof(suffix), "_%d", name.GetInstance() - 1);
	return strcmp(full + length, suffix) == 0;
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

static USequenceObject* FindSequenceObject(ULevel* level, const char* name)
{
	USequence* sequence = LevelMainSequence(level);
	if (!sequence)
		return nullptr;

	for (USequenceObject* obj : sequence->SequenceObjects)
	{
		if (obj && FullNameIs(obj->Name, name))
			return obj;
	}

	return nullptr;
}

static AActor* FindLevelActor(ULevel* level, const char* name)
{
	for (AActor* actor : LevelActors(level))
	{
		if (actor && FullNameIs(actor->Name, name))
			return actor;
	}

	return nullptr;
}

static AWorldInfo* LevelWorldInfo(ULevel* level)
{
	for (AActor* actor : LevelActors(level))
	{
		if (actor && actor->WorldInfo)
			return actor->WorldInfo;
	}

	return nullptr;
}

static ULevelStreaming* FindStreaming(AWorldInfo* worldInfo, const char* name)
{
	for (ULevelStreaming* streaming : worldInfo->StreamingLevels)
	{
		if (streaming && FullNameIs(streaming->PackageName, name))
			return streaming;
	}

	return nullptr;
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

// ---- Chapter 5 cellar door ----

constexpr float CellarDoorMaxGap = 100.0f;

static void ApplyCellarDoor(ULevel* level)
{
	AActor* door = FindLevelActor(level, "InterpActor_58");
	AActor* wall = FindLevelActor(level, "DynamicBlockingVolume_5");
	if (!door || !wall || !door->IsA<AInterpActor>() || !wall->IsA<ADynamicBlockingVolume>() || wall->Base)
		return;

	float dx = door->Location.X - wall->Location.X;
	float dy = door->Location.Y - wall->Location.Y;
	float dz = door->Location.Z - wall->Location.Z;

	if ((dx * dx + dy * dy + dz * dz) > (CellarDoorMaxGap * CellarDoorMaxGap))
	{
		wall->SetCollisionType(ECollisionType::COLLIDE_NoCollision);
		return;
	}

	wall->SetHardAttach(true);
	wall->SetBase(door, FVector(0.0f, 0.0f, 1.0f), nullptr, FName(0));
}

// ---- Chapter 5 Dollmaker goo ----

constexpr const char* GooTemplate = "DoomDripping01_P";

static void ApplyDollmakerGoo(ULevel* level)
{
	for (AActor* actor : LevelActors(level))
	{
		if (!actor || !actor->IsA<AEmitter>())
			continue;

		UParticleSystemComponent* comp = static_cast<AEmitter*>(actor)->ParticleSystemComponent;
		UParticleSystem* system = comp ? comp->Template : nullptr;
		if (!system || !FullNameIs(system->Name, GooTemplate))
			continue;

		for (UParticleEmitter* emitter : system->Emitters)
		{
			if (!emitter || emitter->LODLevels.size() < 2)
				continue;

			UParticleLODLevel* top = emitter->LODLevels[0];
			UParticleLODLevel* distant = emitter->LODLevels[1];

			if (top && distant && !top->bEnabled)
				distant->bEnabled = 0;
		}

		return;
	}
}

// ---- Chapter 5 Fort Resistance draw range ----

constexpr const char* FortWorldLevel = "Chapter5_W2_World_01";
constexpr const char* FortGeometryLevel = "Chapter5_W2_Dfort2_DH";

static void ApplyFortRange(ULevel* level)
{
	AWorldInfo* worldInfo = LevelWorldInfo(level);
	if (!worldInfo)
		return;

	ULevelStreaming* world = FindStreaming(worldInfo, FortWorldLevel);
	ULevelStreaming* fort = FindStreaming(worldInfo, FortGeometryLevel);
	if (!world || !fort || world->EditorStreamingVolumes.size() != 1 || fort->EditorStreamingVolumes.size() != 1)
		return;

	// Volume streaming reads each level's EditorStreamingVolumes every frame, the slot is replaced in place
	if (ALevelStreamingVolume* volume = world->EditorStreamingVolumes[0])
		fort->EditorStreamingVolumes[0] = volume;
}

struct MapFix
{
	const char* level;
	void (*apply)(ULevel*);
};

static const MapFix MapFixes[] =
{
	{ "Chapter5_W1_Dfort1_DH",  ApplyFort       },
	{ "CC_Rolling",             ApplyRadula     },
	{ "Chapter6_Station_01",    ApplyLamps      },
	{ "Chapter4_W2_West_09_S",  ApplyTrain      },
	{ "Chapter5_W1_BoysL_04_S", ApplyCellarDoor },
	{ "Chapter5_W3_Cin_5121",   ApplyDollmakerGoo },
	{ FortWorldLevel,           ApplyFortRange  },
};

// ---- Cutscene fades ----

struct PersistFade
{
	const char* level;
	const char* matinee;
};

static const PersistFade PersistFades[] =
{
	{ "Chapter1_W1_Cin_Car",     "SeqAct_Interp_0"  },
	{ "Chapter3_W1_Pool_02_S",   "SeqAct_Interp_4"  },
	{ "Chapter4_L1_Cin_411",     "SeqAct_Interp_1"  },
	{ "Chapter5_L1_Cin_522",     "SeqAct_Interp_2"  },
	{ "Chapter5_W1_BoysL_07_S",  "SeqAct_Interp_10" },
	{ "Chapter5_W3_Girls2_02_S", "SeqAct_Interp_0"  },
	{ "Chapter6_Asylum_01_S",    "SeqAct_Interp_13" },
	{ "Chapter6_Cin_619",        "SeqAct_Interp_5"  },
	{ "Chapter6_Cin_6113",       "SeqAct_Interp_5"  },
};

static void PersistEndingFades(UInterpData* data)
{
	for (UInterpGroup* group : data->InterpGroups)
	{
		if (!group)
			continue;

		for (UInterpTrack* track : group->InterpTracks)
		{
			if (!track || !track->IsA<UInterpTrackFade>())
				continue;

			UInterpTrackFade* fade = static_cast<UInterpTrackFade*>(track);
			TArray<FInterpCurvePointFloat>& points = fade->FloatTrack.Points;
			if (points.size() > 0 && points[points.size() - 1].OutVal >= 0.99f)
				fade->bPersistFade = 1;
		}
	}
}

static void ApplyPersistFade(ULevel* level, const char* matinee)
{
	USequenceObject* obj = FindSequenceObject(level, matinee);
	if (!obj || !obj->IsA<USeqAct_Interp>())
		return;

	for (FSeqVarLink& link : static_cast<USeqAct_Interp*>(obj)->VariableLinks)
	{
		for (USequenceVariable* var : link.LinkedVariables)
		{
			if (var && var->IsA<UInterpData>())
				PersistEndingFades(static_cast<UInterpData*>(var));
		}
	}
}

// ---- Enemy kill volumes ----

struct KillVolume
{
	const char* level;
	const char* touch;
};

static const KillVolume KillVolumes[] =
{
	{ "Chapter5_W1_BoysL_01-b_S",     "SeqEvent_Touch_10" },
	{ "Chapter5_W3_Girls_Ambush_NPC", "SeqEvent_Touch_3"  },
};

static void ApplyKillVolume(ULevel* level, const char* touch)
{
	USequenceObject* obj = FindSequenceObject(level, touch);
	if (!obj || !obj->IsA<USeqEvent_Touch>())
		return;

	USeqEvent_Touch* kill = static_cast<USeqEvent_Touch*>(obj);
	kill->bPlayerOnly = 0;
	kill->MaxTriggerCount = 0;
}

// ---- Chapter 1 hub backdrop ----

constexpr const char* HubLevel = "Chapter1_W2_HUB_01";
constexpr const char* HubScriptLevel = "Chapter1_W2_HUB_01_S";
constexpr const char* AssemblyLevel = "Chapter1_W2_ASSEM_03";

static void ApplyHubBackdrop(ULevel* level)
{
	AWorldInfo* worldInfo = LevelWorldInfo(level);
	if (!worldInfo)
		return;

	ULevelStreaming* hub = FindStreaming(worldInfo, HubLevel);
	ULevelStreaming* hubScript = FindStreaming(worldInfo, HubScriptLevel);
	ULevelStreaming* assembly = FindStreaming(worldInfo, AssemblyLevel);
	if (!hub || !hubScript || !assembly)
		return;

	if (!hub->bIsVisible || !assembly->bIsVisible || hubScript->bShouldBeLoaded || hubScript->bIsVisible)
		return;

	hub->bShouldBeLoaded = 0;
	hub->bShouldBeVisible = 0;
}

// ---- Chapter 1 Infernal Train carriages ----

constexpr const char* TrainCinematicLevel = "Chapter1_W2_Cin_1102";

static bool IsTrainEngine(AActor* actor)
{
	if (!NameIs(actor->Name, "InterpActor", 5))
		return false;

	// Actor -> PersistentLevel -> TheWorld -> map package
	UObject* level = actor->Outer;
	UObject* world = level ? level->Outer : nullptr;
	UObject* package = world ? world->Outer : nullptr;
	return package && FullNameIs(package->Name, TrainCinematicLevel);
}

static int __fastcall ActorSetHidden_Hook(AActor* actor, void*, uint32_t bNewHidden)
{
	int result = ActorSetHidden.unsafe_thiscall<int>(actor, bNewHidden);

	if (!IsTrainEngine(actor))
		return result;

	for (AActor* attached : actor->Attached)
	{
		if (attached)
			ActorSetHidden.unsafe_thiscall<int>(attached, bNewHidden);
	}

	return result;
}

static int __fastcall AddToWorld_Hook(UWorld* world, int, ULevelStreaming* streaming, FVector* offset)
{
	bool wasVisible = streaming->bIsVisible;
	int result = AddToWorld.unsafe_thiscall<int>(world, streaming, offset);

	if (wasVisible || !streaming->bIsVisible || !streaming->LoadedLevel)
		return result;

	ULevel* level = streaming->LoadedLevel;

	for (const MapFix& fix : MapFixes)
	{
		if (FullNameIs(streaming->PackageName, fix.level))
		{
			fix.apply(level);
			break;
		}
	}

	for (const PersistFade& fade : PersistFades)
	{
		if (FullNameIs(streaming->PackageName, fade.level))
			ApplyPersistFade(level, fade.matinee);
	}

	for (const KillVolume& volume : KillVolumes)
	{
		if (FullNameIs(streaming->PackageName, volume.level))
			ApplyKillVolume(level, volume.touch);
	}

	if (FullNameIs(streaming->PackageName, HubLevel) || FullNameIs(streaming->PackageName, AssemblyLevel))
		ApplyHubBackdrop(level);

	return result;
}

void ApplyFixMapProperties()
{
	if (!FixMapProperties) return;

	AddToWorld = HookHelper::CreateHook((void*)GetAddress(Addr::AddToWorld), &AddToWorld_Hook);
	ActorSetHidden = HookHelper::CreateHook((void*)GetAddress(Addr::ActorSetHidden), &ActorSetHidden_Hook);
}
