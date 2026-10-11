#include "Common.hpp"
#include "Features.hpp"

// The Hatter elevator room (Chapter1_W2_RR_03_S) configures its pad and gates from a startup Kismet event
// that only fires once per level instance. If the room survives a section round trip, or a checkpoint
// restore brings it back, it stays wired for the first visit: the pad leads nowhere and the next checkpoint
// saves that dead state for good. Keep the event reentrant and rerun the startup routing whenever a load
// brings the room back stale. This also repairs saves that are already broken
namespace FixHatterElevator
{
	constexpr uint64_t ScanIntervalMs = 1500;
	constexpr uint64_t RepairWindowMs = 12000;
	constexpr float FreshActivationSeconds = 30.0f;

	// The room's gates at map defaults (class default is open, the map closes 2/3/4/8), indexed by name suffix
	struct GateDefault { int index; bool open; int autoCloseCount; };
	static constexpr GateDefault kGates[] =
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

	// Walk triggers that only fire once (SeqEvent_Touch_1/2/3)
	static constexpr int kTouches[] = { 1, 2, 3 };

	// Camera matinees behind the one-shot gates reopened above: Gate_0 -> Interp_0 (elevator ride), Gate_12 -> Interp_3 (exit to the HUB)
	static constexpr int kCameraInterps[] = { 0, 3 };

	constexpr int MaxIndex = 13;

	struct RoomOps
	{
		USeqEvent_LevelLoaded* startup = nullptr;
		USeqAct_Gate* gates[MaxIndex] = {};
		USeqEvent_Touch* touches[MaxIndex] = {};
		USeqAct_Interp* interps[MaxIndex] = {};
	};

	// FName base string without building a std::string ("SeqAct_Gate_8" = "SeqAct_Gate" + instance 9)
	static const char* BaseName(const FName& name)
	{
		return name.IsValid() ? FName::Names()->at(name.GetDisplayIndex())->Name : "";
	}

	static bool NameIs(const FName& name, const char* base)
	{
		return name.GetInstance() == 0 && strcmp(BaseName(name), base) == 0;
	}

	// RR_03_S's level, null while it isn't loaded
	static ULevel* FindRoomLevel(AWorldInfo* worldInfo)
	{
		for (ULevelStreaming* ls : worldInfo->StreamingLevels)
		{
			if (ls && ls->LoadedLevel && NameIs(ls->PackageName, "Chapter1_W2_RR_03_S"))
				return ls->LoadedLevel;
		}

		return nullptr;
	}

	// The level's Main_Sequence, pointer and name compares only
	static USequence* FindMainSequence(ULevel* level)
	{
		for (UObject* obj : *UObject::GObjObjects())
		{
			if (obj && obj->Outer == level && NameIs(obj->Name, "Main_Sequence"))
				return static_cast<USequence*>(obj);
		}

		return nullptr;
	}

	// Sort the sequence's ops by class and name suffix in one pass over its ~60 objects
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

	static UFunction* CheckActivateFunction()
	{
		static UFunction* fn = nullptr;
		if (!fn)
		{
			fn = UFunction::FindFunction("Function Engine.SequenceEvent.CheckActivate");
		}
		return fn;
	}

	// A restored event still carries the ActivationTime it was saved with, one that fired during this load is seconds old
	static bool IsStaleActivation(USeqEvent_LevelLoaded* startup, AWorldInfo* worldInfo)
	{
		if (startup->TriggerCount == 0)
			return false;

		float worldTime = worldInfo->TimeSeconds;
		float firedAt = startup->ActivationTime;
		return firedAt > worldTime + 1.0f || (worldTime - firedAt) > FreshActivationSeconds;
	}

	// Back to map defaults, then fire the startup routing again so the room reconfigures from the
	// live progress values, exactly what happens when the level streams in fresh
	static void RepairRoom(const RoomOps& ops, AWorldInfo* worldInfo)
	{
		for (int index : kTouches)
		{
			if (USeqEvent_Touch* touch = ops.touches[index])
			{
				touch->TriggerCount = 0;
				touch->ActivationTime = 0.0f;
			}
		}

		for (const GateDefault& gd : kGates)
		{
			if (USeqAct_Gate* gate = ops.gates[gd.index])
			{
				gate->bOpen = gd.open;
				gate->AutoCloseCount = gd.autoCloseCount;
				gate->CurrentCloseCount = 0;
			}
		}

		for (int index : kCameraInterps)
		{
			USeqAct_Interp* interp = ops.interps[index];
			if (interp && !interp->bIsPlaying)
			{
				interp->Position = 0.0f;
			}
		}

		USeqEvent_LevelLoaded* startup = ops.startup;
		startup->TriggerCount = 0;
		startup->MaxTriggerCount = 0;

		UFunction* checkActivate = CheckActivateFunction();
		if (!checkActivate)
			return;

		USequenceEvent_execCheckActivate_Params params{};
		params.InOriginator = startup->Originator ? startup->Originator : worldInfo;
		startup->ProcessEvent(checkActivate, &params, nullptr);
	}

	// True once the room has been handled for this load, false to try again on the next scan
	static bool TryRepair()
	{
		AAlicePlayerController* pc = g_State.AlicePlayerController;
		if (!pc || !pc->WorldInfo)
			return false;

		ULevel* level = FindRoomLevel(pc->WorldInfo);
		if (!level)
			return false;

		USequence* sequence = FindMainSequence(level);
		if (!sequence)
			return false;

		RoomOps ops;
		CollectRoomOps(sequence, ops);
		if (!ops.startup)
			return false;

		// The actual bug: MaxTriggerCount=1 means the room only ever gets to configure itself once.
		// Zero it so its own routing runs again on every visibility change
		ops.startup->MaxTriggerCount = 0;

		// Consumed + old = the room came back with stale state (save restore, or it stayed resident
		// across the round trip). A fresh instance already ran its own routing and needs nothing
		if (IsStaleActivation(ops.startup, pc->WorldInfo))
		{
			RepairRoom(ops, pc->WorldInfo);
		}

		return true;
	}

	void Tick()
	{
		static uint64_t handledLoad = 0;
		const uint64_t loadEnd = g_State.loadEndTick;
		if (loadEnd == handledLoad)
			return;

		static uint64_t nextScan = 0;
		const uint64_t now = GetTickCount64();
		if (now < nextScan)
			return;
		nextScan = now + ScanIntervalMs;

		if (TryRepair() || now - loadEnd > RepairWindowMs)
		{
			handledLoad = loadEnd;
		}
	}
}