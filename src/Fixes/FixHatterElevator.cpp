#include "Common.hpp"
#include "Features.hpp"

static safetyhook::InlineHook SequenceBeginPlay;
static safetyhook::InlineHook CheckpointLoadData;
static uintptr_t GWorldAddress = 0;

constexpr uintptr_t World_PersistentLevel = 0x50;
constexpr uintptr_t Level_Actors = 0x3C;
constexpr uintptr_t Level_GameSequences = 0xA0;

constexpr const char* RoomLevel = "Chapter1_W2_RR_03_S";

// Gate defaults, indexed by name suffix
struct GateDefault { int index; bool open; int autoCloseCount; };
static constexpr GateDefault Gates[] =
{
	{ 0,  true,  1 },
	{ 1,  true,  1 },
	{ 2,  false, 0 },
	{ 3,  false, 0 },
	{ 4,  false, 0 },
	{ 7,  true,  0 },
	{ 8,  false, 0 },
	{ 10, true,  0 },
	{ 11, true,  1 },
	{ 12, true,  1 },
};

// One-shot touches, Touch_3 is the exit to the HUB
static constexpr int Touches[] = { 1, 2, 3 };
constexpr int ExitTouch = 3;

// Camera matinees move relative to the camera start, so the cameras go back to their map placement
struct CameraDefault { int interp; FVector location; FRotator rotation; };
static const CameraDefault Cameras[] =
{
	{ 0, FVector(-94429.828f, 6545.762f, -1796.483f), FRotator(-548, 16548, 0) },   // CameraActor_1
	{ 3, FVector(-94334.109f, 6443.745f, -1408.625f), FRotator(-3104, 282610, 0) }, // CameraActor_0
};

constexpr int MaxIndex = 13;

struct RoomOps
{
	USeqEvent_LevelLoaded* startup = nullptr;
	USeqAct_Gate* gates[MaxIndex] = {};
	USeqEvent_Touch* touches[MaxIndex] = {};
	USeqAct_Interp* interps[MaxIndex] = {};
};

static const char* BaseName(const FName& name)
{
	return name.IsValid() ? FName::Names()->at(name.GetDisplayIndex())->Name : "";
}

static bool NameIs(const FName& name, const char* base)
{
	return name.GetInstance() == 0 && strcmp(BaseName(name), base) == 0;
}

static USequence* LevelMainSequence(ULevel* level)
{
	TArray<USequence*>& sequences = *reinterpret_cast<TArray<USequence*>*>(reinterpret_cast<uint8_t*>(level) + Level_GameSequences);
	return sequences.size() > 0 ? sequences[0] : nullptr;
}

// GWorld->PersistentLevel->Actors[0]
static AWorldInfo* CurrentWorldInfo()
{
	uint8_t* world = GWorldAddress ? *reinterpret_cast<uint8_t**>(GWorldAddress) : nullptr;
	uint8_t* level = world ? *reinterpret_cast<uint8_t**>(world + World_PersistentLevel) : nullptr;
	if (!level)
		return nullptr;

	TArray<AActor*>& actors = *reinterpret_cast<TArray<AActor*>*>(level + Level_Actors);
	AActor* first = actors.size() > 0 ? actors[0] : nullptr;
	return (first && first->IsA<AWorldInfo>()) ? static_cast<AWorldInfo*>(first) : nullptr;
}

// Main_Sequence -> PersistentLevel -> TheWorld -> map package
static bool IsRoomSequence(USequence* sequence)
{
	if (!sequence || !NameIs(sequence->Name, "Main_Sequence"))
		return false;

	UObject* level = sequence->Outer;
	UObject* world = level ? level->Outer : nullptr;
	UObject* package = world ? world->Outer : nullptr;
	return package && NameIs(package->Name, RoomLevel);
}

static ULevelStreaming* FindRoomStreaming(AWorldInfo* worldInfo)
{
	for (ULevelStreaming* streaming : worldInfo->StreamingLevels)
	{
		if (streaming && streaming->LoadedLevel && streaming->bIsVisible && NameIs(streaming->PackageName, RoomLevel))
			return streaming;
	}

	return nullptr;
}

static void CollectRoomOps(USequence* sequence, RoomOps& ops)
{
	for (USequenceObject* obj : sequence->SequenceObjects)
	{
		if (!obj || !obj->Class)
			continue;

		const char* cls = BaseName(obj->Class->Name);
		if (strcmp(BaseName(obj->Name), cls) != 0)
			continue;

		int index = obj->Name.GetInstance() - 1;
		if (index < 0 || index >= MaxIndex)
			continue;

		if (strcmp(cls, "SeqAct_Gate") == 0)
			ops.gates[index] = static_cast<USeqAct_Gate*>(obj);
		else if (strcmp(cls, "SeqEvent_Touch") == 0)
			ops.touches[index] = static_cast<USeqEvent_Touch*>(obj);
		else if (strcmp(cls, "SeqAct_Interp") == 0)
			ops.interps[index] = static_cast<USeqAct_Interp*>(obj);
		else if (index == 0 && strcmp(cls, "SeqEvent_LevelLoaded") == 0)
			ops.startup = static_cast<USeqEvent_LevelLoaded*>(obj);
	}
}

// Startup already ran and the exit was used
static bool IsSpent(const RoomOps& ops)
{
	USeqEvent_Touch* exit = ops.touches[ExitTouch];
	return ops.startup->TriggerCount > 0 && exit && exit->TriggerCount > 0;
}

static ACameraActor* InterpCamera(USeqAct_Interp* interp)
{
	for (FSeqVarLink& link : interp->VariableLinks)
	{
		for (USequenceVariable* var : link.LinkedVariables)
		{
			if (!var || !var->IsA<USeqVar_Object>())
				continue;

			UObject* value = static_cast<USeqVar_Object*>(var)->ObjValue;
			if (value && value->IsA<ACameraActor>())
				return static_cast<ACameraActor*>(value);
		}
	}

	return nullptr;
}

static void ResetRoom(const RoomOps& ops)
{
	for (int index : Touches)
	{
		if (USeqEvent_Touch* touch = ops.touches[index])
		{
			touch->TriggerCount = 0;
			touch->ActivationTime = 0.0f;
		}
	}

	for (const GateDefault& gd : Gates)
	{
		if (USeqAct_Gate* gate = ops.gates[gd.index])
		{
			gate->bOpen = gd.open;
			gate->AutoCloseCount = gd.autoCloseCount;
			gate->CurrentCloseCount = 0;
		}
	}

	for (const CameraDefault& cd : Cameras)
	{
		USeqAct_Interp* interp = ops.interps[cd.interp];
		if (!interp || interp->bIsPlaying)
			continue;

		interp->Position = 0.0f;

		if (ACameraActor* camera = InterpCamera(interp))
		{
			camera->SetLocation(cd.location);
			camera->SetRotation(cd.rotation);
		}
	}

	ops.startup->TriggerCount = 0;
	ops.startup->ActivationTime = 0.0f;
}

static UFunction* CheckActivateFunction()
{
	static UFunction* fn = nullptr;
	if (!fn)
	{
		fn = UFunction::FindFunction("Function Engine.SequenceEvent.CheckActivate");
	}
	return fn;
}

// No indices fires every output, only "Loaded and Visible" is linked
static void FireStartup(USeqEvent_LevelLoaded* startup, AWorldInfo* worldInfo)
{
	UFunction* checkActivate = CheckActivateFunction();
	if (!checkActivate)
		return;

	USequenceEvent_execCheckActivate_Params params{};
	params.InOriginator = worldInfo;
	startup->ProcessEvent(checkActivate, &params, nullptr);
}

// ---- Room shown again ----

static void __fastcall SequenceBeginPlay_Hook(USequence* sequence, void*)
{
	if (IsRoomSequence(sequence))
	{
		RoomOps ops;
		CollectRoomOps(sequence, ops);

		if (ops.startup && IsSpent(ops))
		{
			ResetRoom(ops);
		}
	}

	SequenceBeginPlay.unsafe_thiscall<void>(sequence);
}

// ---- Checkpoint restored ----

static bool IsInsideRoom(ULevelStreaming* streaming, const FVector& location)
{
	bool hasVolume = false;
	for (ALevelStreamingVolume* volume : streaming->EditorStreamingVolumes)
	{
		if (!volume)
			continue;

		hasVolume = true;
		if (volume->EncompassesPoint(location))
			return true;
	}

	return !hasVolume;
}

// The saved Kismet state is applied after the room is shown
static void RepairRestoredRoom(UAliceCheckpoint* checkpoint)
{
	AWorldInfo* worldInfo = CurrentWorldInfo();
	if (!checkpoint || !worldInfo)
		return;

	ULevelStreaming* streaming = FindRoomStreaming(worldInfo);
	if (!streaming)
		return;

	USequence* sequence = LevelMainSequence(streaming->LoadedLevel);
	if (!sequence)
		return;

	RoomOps ops;
	CollectRoomOps(sequence, ops);
	if (!ops.startup || !IsSpent(ops) || !IsInsideRoom(streaming, checkpoint->CheckpointLocation))
		return;

	ResetRoom(ops);
	FireStartup(ops.startup, worldInfo);
}

static int __fastcall CheckpointLoadData_Hook(UAliceCheckpoint* checkpoint, void*)
{
	int result = CheckpointLoadData.unsafe_thiscall<int>(checkpoint);
	RepairRestoredRoom(checkpoint);
	return result;
}

void ApplyFixHatterElevator()
{
	if (!FixHatterElevatorEnabled) return;

	GWorldAddress = GetAddress(Addr::GWorld);
	SequenceBeginPlay = HookHelper::CreateHook((void*)GetAddress(Addr::SequenceBeginPlay), &SequenceBeginPlay_Hook);
	CheckpointLoadData = HookHelper::CreateHook((void*)GetAddress(Addr::CheckpointLoadData), &CheckpointLoadData_Hook);
}