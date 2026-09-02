#include "Common.hpp"
#include "Features.hpp"

namespace FixMapProperties
{
	constexpr uint64_t scanIntervalMs = 800;

	struct SetAnimParams { FName Sequence; };
	struct PlayAnimParams { uint32_t bLoop; float InRate; float StartTime; };
	struct SetHiddenParams { uint32_t bNewHidden; };
	struct SetEnabledParams { uint32_t bSetEnabled; };
	struct ForceUpdateParams { uint32_t bTransformOnly; };

	static void CallScript(UObject* target, const char* function, void* params)
	{
		if (!target) return;

		UFunction* fn = UFunction::FindFunction(function);
		if (!fn) return;

		using tProcessEvent = void(__thiscall*)(void*, UFunction*, void*, void*);
		auto processEvent = reinterpret_cast<tProcessEvent>(GetAddress(Addr::ProcessEvent));

		if (processEvent)
		{
			processEvent(target, fn, params, nullptr);
		}
	}

	static bool InLevel(UObject* object, const char* level)
	{
		return object && object->GetFullName().find(level) != std::string::npos;
	}

	// Chapter 5 fort
	constexpr const char* kFortLevel = "Chapter5_W1_Dfort1_DH";

	constexpr const char* kFortAnimated = "SK_InsaneKidC";
	constexpr const char* kFortSequence = "CH_Insanekid_Idle01_Long03";

	static const char* kFortHidden[] =
	{
		"SK_InsaneKidA_Leader",
		"SK_InsaneKidB",
		"SK_InsaneKidD",
		"SK_InsaneKidE",
	};

	struct RawArray { void* Data; int32_t Count; int32_t Max; };
	static UAnimSet* s_animSetSlot[1] = { nullptr };

	static bool ApplyFort()
	{
		UAnimSet* set = nullptr;
		std::vector<ASkeletalMeshActor*> children;

		for (ASkeletalMeshActor* actor : UObject::FindAllOf<ASkeletalMeshActor>())
		{
			if (!actor || !actor->SkeletalMeshComponent || !actor->SkeletalMeshComponent->SkeletalMesh)
				continue;

			if (!InLevel(actor, kFortLevel))
				continue;

			children.push_back(actor);

			if (!set && actor->SkeletalMeshComponent->AnimSets.size() > 0)
			{
				set = actor->SkeletalMeshComponent->AnimSets[0];
			}
		}

		if (children.empty() || !set)
			return false;

		for (ASkeletalMeshActor* actor : children)
		{
			USkeletalMeshComponent* comp = actor->SkeletalMeshComponent;
			std::string mesh = comp->SkeletalMesh->GetName();

			if (mesh == kFortAnimated)
			{
				UAnimSequence* wanted = nullptr;
				for (int32_t i = 0; i < set->Sequences.size(); i++)
				{
					UAnimSequence* seq = set->Sequences[i];
					if (seq && seq->SequenceName.ToString() == kFortSequence)
					{
						wanted = seq;
						break;
					}
				}

				UAnimNodeSequence* node = comp->Animations && comp->Animations->IsA<UAnimNodeSequence>() ? reinterpret_cast<UAnimNodeSequence*>(comp->Animations) : nullptr;

				if (!wanted || !node)
					continue;

				bool present = false;
				for (int32_t i = 0; i < comp->AnimSets.size(); i++)
				{
					if (comp->AnimSets[i] == set)
					{
						present = true;
					}
				}

				RawArray* raw = reinterpret_cast<RawArray*>(&comp->AnimSets);
				RawArray saved = *raw;

				if (!present)
				{
					s_animSetSlot[0] = set;
					raw->Data = s_animSetSlot;
					raw->Count = 1;
					raw->Max = 1;
				}

				SetAnimParams setAnim{};
				setAnim.Sequence = wanted->SequenceName;
				CallScript(node, "Function Engine.AnimNodeSequence.SetAnim", &setAnim);

				if (!present)
				{
					*raw = saved;
				}

				PlayAnimParams playAnim{};
				playAnim.bLoop = 1;
				playAnim.InRate = 1.0f;
				playAnim.StartTime = 0.0f;
				CallScript(node, "Function Engine.AnimNodeSequence.PlayAnim", &playAnim);

				comp->CastShadow = 0;
				comp->bCastDynamicShadow = 0;

				if (actor->LightEnvironment && actor->LightEnvironment->IsA<UDynamicLightEnvironmentComponent>())
				{
					reinterpret_cast<UDynamicLightEnvironmentComponent*>(actor->LightEnvironment)->bCastShadows = 0;
				}

				ForceUpdateParams refresh{};
				refresh.bTransformOnly = 0;
				CallScript(comp, "Function Engine.ActorComponent.ForceUpdate", &refresh);
				continue;
			}

			for (const char* hidden : kFortHidden)
			{
				if (mesh != hidden)
				{
					continue;
				}

				SetHiddenParams hide{};
				hide.bNewHidden = 1;
				CallScript(actor, "Function Engine.Actor.SetHidden", &hide);
				break;
			}
		}

		return true;
	}

	// CC_Rolling radula room
	constexpr const char* kRadulaLevel = "CC_Rolling";

	static bool ApplyRadula()
	{
		int32_t enabled = 0;

		for (UStaticMeshComponent* comp : UObject::FindAllOf<UStaticMeshComponent>())
		{
			if (!comp || !InLevel(comp, kRadulaLevel))
				continue;

			ULightEnvironmentComponent* env = comp->LightEnvironment;
			if (!env || env->bEnabled)
				continue;

			SetEnabledParams params{};
			params.bSetEnabled = 1;
			CallScript(env, "Function Engine.LightEnvironmentComponent.SetEnabled", &params);
			enabled++;
		}

		return enabled > 0;
	}

	// Chapter 6 station lamps
	constexpr const char* kLampLevel = "Chapter6_Station_01";
	constexpr float kLampMatchRadius = 8.0f;

	struct LampEdit
	{
		float from[3];
		float offset[3];
	};

	static const LampEdit kLampEdits[] =
	{
		{ { 210105.891f, 181367.094f, 210640.875f }, { 0.0f,   0.0f, -100000.0f } },
		{ { 212002.391f, 179507.531f, 211036.594f }, { 0.0f,   0.0f, -100000.0f } },
		{ { 210105.422f, 181381.234f, 210638.875f }, { 0.0f, +25.0f,      0.0f } },
	};

	static bool ApplyLamps()
	{
		int32_t moved = 0;

		for (AStaticMeshActor* actor : UObject::FindAllOf<AStaticMeshActor>())
		{
			if (!actor || !actor->StaticMeshComponent || !InLevel(actor, kLampLevel))
				continue;

			for (const LampEdit& edit : kLampEdits)
			{
				float dx = actor->Location.X - edit.from[0];
				float dy = actor->Location.Y - edit.from[1];
				float dz = actor->Location.Z - edit.from[2];

				if ((dx * dx + dy * dy + dz * dz) > (kLampMatchRadius * kLampMatchRadius))
					continue;

				actor->Location.X += edit.offset[0];
				actor->Location.Y += edit.offset[1];
				actor->Location.Z += edit.offset[2];

				ForceUpdateParams refresh{};
				refresh.bTransformOnly = 1;
				CallScript(actor->StaticMeshComponent, "Function Engine.ActorComponent.ForceUpdate", &refresh);

				moved++;
				break;
			}
		}

		return moved > 0;
	}

	// Chapter 4 infernal train flyby
	constexpr const char* kTrainLevel = "Chapter4_W2_West_09_S";
	constexpr const char* kTrainTrigger = "Trigger_5";
	constexpr const char* kTrainTouch = ".Main_Sequence.SeqEvent_Touch_0";

	static bool ApplyTrain()
	{
		for (USeqEvent_Touch* ev : UObject::FindAllOf<USeqEvent_Touch>())
		{
			if (!ev)
				continue;

			if (!ev->Originator || ev->Originator->GetName() != kTrainTrigger)
				continue;

			std::string fullName = ev->GetFullName();
			if (fullName.find(kTrainLevel) == std::string::npos)
				continue;

			size_t length = strlen(kTrainTouch);
			if (fullName.size() < length || memcmp(fullName.data() + fullName.size() - length, kTrainTouch, length) != 0)
				continue;

			ev->MaxTriggerCount = 1;
			return true;
		}

		return false;
	}

	struct MapFix
	{
		const char* level;
		bool (*apply)();
		bool applied;
	};

	static MapFix kMapFixes[] =
	{
		{ kFortLevel,   ApplyFort,   false },
		{ kRadulaLevel, ApplyRadula, false },
		{ kLampLevel,   ApplyLamps,  false },
		{ kTrainLevel,  ApplyTrain,  false },
	};

	static uint64_t s_nextScan = 0;

	// Is that sublevel the active (visible) one?
	static bool LevelVisible(AWorldInfo* wi, const char* level)
	{
		for (ULevelStreaming* ls : wi->StreamingLevels)
		{
			if (!ls || !ls->bIsVisible)
				continue;

			if (ls->PackageName.ToString().find(level) != std::string::npos)
				return true;
		}

		return false;
	}

	void Tick()
	{
		uint64_t now = GetTickCount64();
		if (now < s_nextScan)
			return;

		s_nextScan = now + scanIntervalMs;

		AAlicePlayerController* pc = g_State.AlicePlayerController;
		if (!pc || !pc->WorldInfo)
			return;

		AWorldInfo* wi = pc->WorldInfo;

		for (MapFix& fix : kMapFixes)
		{
			if (!LevelVisible(wi, fix.level)) // re-arm once the area streams back out
			{
				fix.applied = false;
				continue;
			}

			if (!fix.applied)
			{
				fix.applied = fix.apply();
			}
		}
	}
}