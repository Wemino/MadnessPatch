#include "Common.hpp"
#include "Features.hpp"

safetyhook::InlineHook Localize;

static uintptr_t FxActorLoopExit = 0;
static uintptr_t FxActorInstanceSetActor = 0;
static uintptr_t ParticleMaterialContinue = 0;
static uintptr_t ParticleMaterialSkip = 0;
static uintptr_t HashChainEntryResume = 0;
static uintptr_t HashChainLoopHead = 0;
static uintptr_t HashChainNotFound = 0;
static safetyhook::MidHook FxActorLoopGuard{};

static __declspec(thread) int t_hashChainBudget = 0;

void __cdecl HashChainBudgetReset(int numElements)
{
	t_hashChainBudget = numElements > 0 ? numElements : 1;
}

int __cdecl HashChainBudgetStep()
{
	return t_hashChainBudget-- > 0;
}

__declspec(naked) static void HashChainEntryStub()
{
	__asm
	{
		// Re-run the six bytes replaced by the JMP, budget = Elements.ArrayNum
		mov edi, [edx + ecx * 4]
		push dword ptr[ebx + 4]
		call HashChainBudgetReset
		add esp, 4
		cmp edi, 0FFFFFFFFh
		jmp dword ptr[HashChainEntryResume]
	}
}

__declspec(naked) static void HashChainBackEdgeStub()
{
	__asm
	{
		call HashChainBudgetStep
		test eax, eax
		jz out_of_budget

		// Re-run the five bytes replaced by the JMP
		cmp edi, 0FFFFFFFFh
		jne keep_walking

		out_of_budget:
		jmp dword ptr[HashChainNotFound]

		keep_walking:
		jmp dword ptr[HashChainLoopHead]
	}
}

__declspec(naked) static void ParticleMaterialDeadFlagStub()
{
	__asm
	{
		// UObject::ObjectFlags is at +0x08, RF_BeginDestroyed is bit 0x8000
		test dword ptr[ecx + 8], 8000h
		jnz dead_material

		// Re-run the five bytes replaced by the JMP
		mov edx, [esi + 4]
		mov eax, [ecx]
		jmp dword ptr[ParticleMaterialContinue]

		dead_material:
		// EDX is FLODInfo::Elements.ArrayData
		mov dword ptr[edx + ebx * 4], 0
		jmp dword ptr[ParticleMaterialSkip]
	}
}

static DWORD __cdecl Localize_Hook(DWORD* a1, void* a2, const wchar_t* a3, int a4, wchar_t* String1, int a6)
{
	const bool wantCannon = FixPinballCannonPrompt && a3 && _wcsicmp(a3, L"ACT_OWHH_CANNON_FIRE") == 0;
	const bool wantMatinee = SkipCutscenesWithEnter && a3 && _wcsicmp(a3, L"SKIP_CANCELMATINEE") == 0;
	const bool pcIcons = (wantCannon || wantMatinee) && QueryCalloutPlatform() == 1;

	if (a3 && _wcsicmp(a3, L"FlashUI_Chalkboard_Gryphon_2") == 0 && QueryCalloutPlatform() != 1)
	{
		a3 = L"FlashUI_Chalkboard_Gryphon_2_xbox";
	}

	// Fix a race condition
	static std::mutex locMutex;
	std::lock_guard<std::mutex> lock(locMutex);
	DWORD ret = Localize.unsafe_ccall<DWORD>(a1, a2, a3, a4, String1, a6);

	if (wantCannon && a1[0] && pcIcons)
	{
		std::wstring string(reinterpret_cast<const wchar_t*>(a1[0]));
		size_t pos = string.find(L"%MELEEICON%");

		if (pos != std::wstring::npos)
		{
			string.replace(pos, 11, L"%OBJECTIVEICON%");
			int n = (int)string.size() + 1;

			reinterpret_cast<void(__cdecl*)(void*, int)>(GetAddress(Addr::FStringFree))((void*)a1[0], 1); // free old
			a1[0] = a1[1] = a1[2] = 0;
			reinterpret_cast<void(__thiscall*)(DWORD*, int)>(GetAddress(Addr::FStringAlloc))(a1, n); // alloc
			memcpy((void*)a1[0], string.c_str(), n * sizeof(wchar_t));
			a1[1] = n;
		}
	}
	if (wantMatinee && a1[0] && pcIcons)
	{
		std::wstring string(reinterpret_cast<const wchar_t*>(a1[0]));
		size_t pos = string.find(L"%OBJECTIVEICON%");

		if (pos != std::wstring::npos)
		{
			string.replace(pos, 15, L"%CLICKLSICON%");
			int n = (int)string.size() + 1;
			memcpy((void*)a1[0], string.c_str(), n * sizeof(wchar_t));
			a1[1] = n;
		}
	}

	return ret;
}

static void OnFxActorLoop(safetyhook::Context& ctx)
{
	uintptr_t node = *reinterpret_cast<uintptr_t*>(ctx.ebp - 0x10);
	uintptr_t end = *reinterpret_cast<uintptr_t*>(ctx.ebp - 0x14);

	while (node != end)
	{
		uintptr_t next = *reinterpret_cast<uintptr_t*>(node + 0x4);
		reinterpret_cast<void(__thiscall*)(uintptr_t, void*)>(FxActorInstanceSetActor)(*reinterpret_cast<uintptr_t*>(node), nullptr);
		node = next;
	}

	ctx.eip = FxActorLoopExit;
}

void ApplyCrashFixes()
{
	if (!CrashFixes) return;

	// Hash-table race condition (Localize)
	Localize = HookHelper::CreateHook((void*)GetAddress(Addr::Localize), &Localize_Hook);

	// Fix infinite loading screen
	DWORD addr_HashLoopEntry = GetAddress(Addr::HashLoopEntry);
	DWORD addr_HashLoop = GetAddress(Addr::HashLoop);

	HashChainEntryResume = addr_HashLoopEntry + 0x6;
	HashChainLoopHead = addr_HashLoopEntry + 0x8;
	HashChainNotFound = addr_HashLoop + 0x2;

	MemoryHelper::MakeJMP(addr_HashLoopEntry, reinterpret_cast<uintptr_t>(&HashChainEntryStub));
	MemoryHelper::MakeNOP(addr_HashLoopEntry + 0x5, 1);

	// Guard sits on "cmp edi,-1", three bytes before the back-edge
	MemoryHelper::MakeJMP(addr_HashLoop - 0x3, reinterpret_cast<uintptr_t>(&HashChainBackEdgeStub));

	// Unattached-collision panic
	DWORD addr_FixUnattachedCollisionPanic = GetAddress(Addr::FixUnattachedCollisionPanic);
	MemoryHelper::MakeJMP(addr_FixUnattachedCollisionPanic + 0x6, addr_FixUnattachedCollisionPanic + 0xB9);

	// Hair-curve over-read
	MemoryHelper::WriteMemory<uint8_t>(GetAddress(Addr::FixHairCurveOverRead), 0x73);

	// MMX over-read + spline-prefetch overrun
	MemoryHelper::WriteMemory<uint8_t>(GetAddress(Addr::MmxOverRead), 0x6E);
	MemoryHelper::WriteMemory<uint8_t>(GetAddress(Addr::SplinePrefetchOverrun), 0x73);

	// FaceFX actor teardown: walk the instance list without reading freed nodes
	DWORD addr_FaceFxActorLoopGuard = GetAddress(Addr::FaceFxActorLoopGuard);
	FxActorInstanceSetActor = addr_FaceFxActorLoopGuard + 0x24 + *reinterpret_cast<int32_t*>(addr_FaceFxActorLoopGuard + 0x20);
	FxActorLoopExit = GetAddress(Addr::FaceFxActorLoopExit);
	FxActorLoopGuard = safetyhook::create_mid(addr_FaceFxActorLoopGuard, OnFxActorLoop);

	// Particle mesh-emitter material destruction race
	DWORD addr_ParticleMaterialDispatchSite = GetAddress(Addr::ParticleMaterialDispatchSite);
	ParticleMaterialContinue = addr_ParticleMaterialDispatchSite + 0x5;
	ParticleMaterialSkip = addr_ParticleMaterialDispatchSite + 0x14;
	MemoryHelper::MakeJMP(addr_ParticleMaterialDispatchSite, reinterpret_cast<uintptr_t>(&ParticleMaterialDeadFlagStub));

	// PhysX fluid emptied before its release, a force field touching it in the step in between crashes with PhysX on the CPU
	MemoryHelper::WriteMemory<uint8_t>(GetAddress(Addr::FluidRemoveAllParticles), 0xEB);
}