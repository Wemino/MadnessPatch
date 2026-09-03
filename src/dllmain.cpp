#include "Common.hpp"

#include "MFortress/Patches_EA.hpp"
#include "MFortress/Patches_Steam.hpp"
#include "CrashHandler.hpp"
#include "FixIniBindings.hpp"

#include "Features.hpp"

safetyhook::InlineHook hkCreateMutexW;

struct dinput8 dinput8;

__declspec(naked) void Hook_DirectInput8Create() { _asm { jmp[dinput8.DirectInput8Create] } }
__declspec(naked) void Hook_DllCanUnloadNow() { _asm { jmp[dinput8.DllCanUnloadNow] } }
__declspec(naked) void Hook_DllGetClassObject() { _asm { jmp[dinput8.DllGetClassObject] } }
__declspec(naked) void Hook_DllRegisterServer() { _asm { jmp[dinput8.DllRegisterServer] } }
__declspec(naked) void Hook_DllUnregisterServer() { _asm { jmp[dinput8.DllUnregisterServer] } }
__declspec(naked) void Hook_GetdfDIJoystick() { _asm { jmp[dinput8.GetdfDIJoystick] } }

static bool IsUALPresent()
{
	for (const auto& entry : std::stacktrace::current()) 
	{
		HMODULE hModule = NULL;
		if (GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, (LPCSTR)entry.native_handle(), &hModule)) 
		{
			if (GetProcAddress(hModule, "IsUltimateASILoader") != NULL)
				return true;
		}
	}

	return false;
}

static void Init()
{
	ReadConfig();

	if (FixInputBinding)
	{
		FixIniBindings::FixAll();
	}

	if (EnableCrashHandler)
	{
		CrashHandler::Install();
	}

	// Fixes
	ApplyFixHighFPSHairPhysics();
	ApplyFixHighFPSClothPhysics();
	ApplyFixHighFPSProjectileCollisionCheck();
	ApplyFixHighFPSPhysX();
	ApplyFixHighFPSWalkingPhysics();
	ApplyCrashFixes();
	ApplyFixMissingMusic();
	ApplyFixCPUPhysX();
	ApplyFixInputBinding();
	ApplyFixWindowHandling();
	ApplyThreadPoolClamp();
	ApplyAtomicSaves();
	ApplyXAudio2Upgrade();

	// General
	ApplyIntroSkip();
	ApplyWarnAlice1InstallFolder();
	ApplyAchievementSupport();

	// Modding
	ApplyExportFiles();
	ApplyModFiles();

	// Display
	ApplyFontScaling();
	ApplyAutoResolution();
	ApplyUseWindowed();

	// Input
	ApplyUseSDLControllerInput();

	// Graphics
	ApplyImprovedTextureStreaming();
	ApplyReducedMipMapBias();
	ApplyDisableBackgroundLevelStreaming();
	ApplyFixBinkVideoBT709();
	ApplyFixAspectRatio();
	ApplyMenuScripts();
	ApplyAdaptivePhysXMemory();

	// Misc
	ApplyResolutionHook();
	ApplyGetPointerHook();
	ApplyProcessEventHook();
	ApplyMainLoopHooks();
}

static HANDLE WINAPI CreateMutexW_Hook(LPSECURITY_ATTRIBUTES lpMutexAttributes, BOOL bInitialOwner, LPCWSTR lpName)
{
	if (!g_State.isInit && lpName != nullptr)
	{
		if (_wcsicmp(lpName, L"UnrealEngine3_3") == 0)
		{
			g_State.isInit = true; // Make sure to never enter this condition again
			g_State.GameModule = GetModuleHandleA(NULL);
			(void)hkCreateMutexW.disable();
			Init(); // Once when Steam/EA DRM is decrypted
		}
	}

	return hkCreateMutexW.stdcall<HANDLE, LPSECURITY_ATTRIBUTES, BOOL, LPCWSTR>(lpMutexAttributes, bInitialOwner, lpName);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
		{
			// Prevents DLL from receiving thread notifications
			DisableThreadLibraryCalls(hModule);

			// Verify timestamp
			uintptr_t base = (uintptr_t)GetModuleHandleA(NULL);
			IMAGE_DOS_HEADER* dos = (IMAGE_DOS_HEADER*)(base);
			IMAGE_NT_HEADERS* nt = (IMAGE_NT_HEADERS*)(base + dos->e_lfanew);
			DWORD timestamp = nt->FileHeader.TimeDateStamp;
			DWORD entrypoint = base + nt->OptionalHeader.AddressOfEntryPoint + (0x400000 - base);

			GameBuild build = GameBuild::Unknown;

			if (timestamp == 0x4D9DA4C5)
			{
				MessageBoxA(NULL, "The CD version is not supported.", "MadnessPatch", MB_ICONERROR);
				return FALSE;
			}
			else if (timestamp == 0x4DC8887C)
			{
				build = GameBuild::Steam;

				if (entrypoint != 0x1021EFF)
				{
					MFortress_Steam::ApplyPatches();
				}
			}
			else if (timestamp == 0x4DC89913)
			{
				build = GameBuild::EA;

				if (entrypoint != 0x102255F)
				{
					MFortress_EA::ApplyPatches();
				}

				// RELOADED has fixed headers, skip dll loading
				if (entrypoint == 0x111BFBF)
				{
					MemoryHelper::MakeJMP(entrypoint, 0x102255F);
				}
			}
			else if (timestamp == 0x4DAC7482) // Current Steam/EA App version
			{
				build = GameBuild::Current;
			}
			else
			{
				MessageBoxA(NULL, "This .exe is not supported.", "MadnessPatch", MB_ICONERROR);
				return FALSE;
			}

			Addresses::SetBuild(build, base);

			// Cache the executable-code span used by the render-dispatch crash fix
			MemoryHelper::ComputeCodeRange();

			// Skip wrapper initialization when loaded as .asi
			if (!IsUALPresent())
			{
				SystemHelper::LoadProxyLibrary();
			}

			hkCreateMutexW = HookHelper::CreateHookAPI(L"kernel32.dll", "CreateMutexW", &CreateMutexW_Hook);
			break;
		}
		case DLL_PROCESS_DETACH:
		{
			break;
		}
	}
	return TRUE;
}
