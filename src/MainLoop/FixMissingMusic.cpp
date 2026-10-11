#include "Common.hpp"
#include "Features.hpp"

static safetyhook::MidHook LoadingBinkIsFinished{};

static void OnLoadingBinkIsFinished(safetyhook::Context& ctx)
{
	g_State.loadEndPending = true;
	g_State.loadEndTick = GetTickCount64();
}

void ApplyFixMissingMusic()
{
	if (!FixMissingMusicEnabled && !FixHatterElevatorEnabled) return;

	LoadingBinkIsFinished = safetyhook::create_mid(GetAddress(Addr::LoadingBinkIsFinished), OnLoadingBinkIsFinished);
}

// Area music is fired by a Kismet node wired to a walk-over trigger, so spawning past it (checkpoint load) leaves the area silent. 
// After a load resolves we identify the area from its visible streaming sublevel and, if the right cue isn't already playing, fire that cue's music node directly
namespace FixMissingMusic
{
	constexpr uint64_t kLoadGraceMs = 3000;
	constexpr uint64_t kRescanMs = 250;

	struct AreaMusic { const char* level; const char* cue; };
	static const AreaMusic kAreaMusic[] =
	{
		{ "Chapter1_W1_TMaker_01",  "Teamaker_Intro_Cue"    },
		{ "Chapter2_W1_Ice1_01",    "Chap2_Tundra_Cue"      },
		{ "Chapter1_W2_SMELT_01",   "Hatter_Pipes_Mood_Cue" },
		{ "Chapter2_W2_Town_01",    "Chap2_Tundra_Cue"      },
		{ "Chapter2_W3_Kelp_01",    "Ch2_Surreal_Lite_Cue"  },
		{ "Chapter5_W1_World_01",   "Ch5_Dollhouse_Cue"     },
		{ "Chapter5_W2_World_01",   "Ch5_Dollhouse_02_Cue"  },
		{ "Chapter5_W3_Girls2_02",  "Ch5_Dollhouse_02_Cue"  },
		{ "Chapter5_W3_DMExt_01",   "Ch5_Dollhouse_02_Cue"  },
		{ "Chapter6_DMHouse",       "Ch6_Amb_Cue"           },
	};

	static uint64_t nextScan = 0;

	static bool NameIs(const FName& name, const char* text)
	{
		return name.IsValid() && name.GetInstance() == 0 && strcmp(FName::Names()->at(name.GetDisplayIndex())->Name, text) == 0;
	}

	static void FireMusicTrack(AWorldInfo* wi, const FMusicTrackStruct& track)
	{
		reinterpret_cast<void(__thiscall*)(AWorldInfo*, FMusicTrackStruct)>(GetAddress(Addr::UpdateMusicTrack))(wi, track);
	}

	// The cue this area should be playing, from the one visible streaming sublevel in our table
	static const char* WantedCueForArea(AWorldInfo* wi)
	{
		for (ULevelStreaming* ls : wi->StreamingLevels)
		{
			if (!ls || !ls->bIsVisible)
				continue;

			for (const AreaMusic& area : kAreaMusic)
			{
				if (NameIs(ls->PackageName, area.level))
					return area.cue;
			}
		}

		return nullptr;
	}

	static bool CueAlreadyPlaying(AWorldInfo* wi, const char* cue)
	{
		if (!wi->MusicComp)
			return false;

		USoundCue* cur = wi->CurrentMusicTrack.TheSoundCue;
		return cur && NameIs(cur->Name, cue);
	}

	// Start the area's music by firing its own Kismet node
	static bool PlayCue(AWorldInfo* wi, const char* cue)
	{
		TArray<UObject*>* objects = UObject::GObjObjects();
		for (int32_t i = 0; i < objects->size(); i++)
		{
			UObject* object = objects->at(i);
			if (!object || !object->IsA<USeqAct_PlayMusicTrack>() || object->IsDefaultObject())
				continue;

			const FMusicTrackStruct& track = static_cast<USeqAct_PlayMusicTrack*>(object)->MusicTrack;
			if (track.TheSoundCue && NameIs(track.TheSoundCue->Name, cue))
			{
				FireMusicTrack(wi, track);
				return true;
			}
		}

		return false;
	}

	void Tick()
	{
		if (!g_State.loadEndPending)
			return;

		uint64_t now = GetTickCount64();
		if (now - g_State.loadEndTick > kLoadGraceMs)
		{
			g_State.loadEndPending = false;
			nextScan = 0;
			return;
		}

		AAlicePlayerController* pc = g_State.AlicePlayerController;
		if (!pc || !pc->Pawn || !pc->WorldInfo)
			return;

		AWorldInfo* wi = pc->WorldInfo;
		const char* cue = WantedCueForArea(wi);
		if (!cue)
			return;

		if (CueAlreadyPlaying(wi, cue))
		{
			g_State.loadEndPending = false;
			nextScan = 0;
			return;
		}

		if (now < nextScan)
			return;

		nextScan = now + kRescanMs;
		if (PlayCue(wi, cue))
		{
			g_State.loadEndPending = false;
			nextScan = 0;
		}
	}
}