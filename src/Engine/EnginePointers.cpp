#include "Common.hpp"
#include "Features.hpp"

safetyhook::InlineHook AlicePlayerController_SetPlayer;
static safetyhook::MidHook CapturePlayActorPtr{};
static safetyhook::MidHook GetGEnginePtr{};
static safetyhook::MidHook EngineInit{};
static safetyhook::MidHook SetConsole{};

static int __fastcall AlicePlayerController_SetPlayer_Hook(int thisp, int, int a2)
{
	g_State.AlicePlayerController = (AAlicePlayerController*)thisp;
	return AlicePlayerController_SetPlayer.unsafe_thiscall<int>(thisp, a2);
}

static void OnSetConsole(safetyhook::Context& ctx)
{
	if (!g_State.AliceEngine) return;
	UConsole* console = g_State.AliceEngine->GameViewport->ViewportConsole;
	if (!console) return;

	FName f2("F2");
	if (f2.GetDisplayIndex() != -1)
	{
		console->ConsoleKey = f2;
	}
}

static void OnCapturePlayActorPtr(safetyhook::Context& ctx)
{
	g_State.AlicePawn = (AAlicePawn*)ctx.eax;	
}

static void OnGetGEnginePtr(safetyhook::Context& ctx)
{
	g_State.AliceEngine = (UAliceGameEngine*)ctx.eax;
}

static void OnEngineInit(safetyhook::Context& ctx)
{
	SDKLoader::Initialize();
	ApplyScriptPatches();
	ResolveProcessEventFunctions();
	ResolveFixHighFPSMovementsPhysics();
	ResolveFixHighFPSCamera();
	ResolveScriptFixes();

	if (UnlockCompleteEditionDLC)
	{
		g_State.AliceEngine->GIsSpecialPCEdition = 1;
	}

	g_State.AliceEngine->MaxSmoothedFrameRate = MaxFPS;

	const wchar_t* pathStr = g_State.AliceEngine->Alice1Path.c_str();
	if (pathStr)
	{
		if (!SystemHelper::ResolveDirectory(pathStr))
		{
			g_State.isAlice1Missing = true;
		}
	}
}

void ApplyGetPointerHook()
{
	AlicePlayerController_SetPlayer = HookHelper::CreateHook((void*)GetAddress(Addr::SetAlicePlayerController), &AlicePlayerController_SetPlayer_Hook);
	if (EnableConsole)
	{
		SetConsole = safetyhook::create_mid(GetAddress(Addr::SetConsole), OnSetConsole);
	}

	CapturePlayActorPtr = safetyhook::create_mid(GetAddress(Addr::PlayActorPtr), OnCapturePlayActorPtr);
	GetGEnginePtr = safetyhook::create_mid(GetAddress(Addr::GetGEnginePtr), OnGetGEnginePtr);
	EngineInit = safetyhook::create_mid(GetAddress(Addr::EnginePostInit), OnEngineInit);
}
