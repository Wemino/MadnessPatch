#include "Common.hpp"
#include "Features.hpp"

static safetyhook::InlineHook KeyCommandsLoad{};

struct EngineString
{
	wchar_t* Data;
	int32_t Num;
	int32_t Max;
};

constexpr int NumAliceKeys = 33;

struct KeyCommandFix
{
	const wchar_t* Shipped;
	const wchar_t* Fixed;
};

static constexpr KeyCommandFix kKeyCommandFixes[] =
{
	{ L"TriggerBlock", L"TriggerBlock true | OnRelease TriggerBlock false" },
	{ L"VorpalBladeFirePress | OnRelease VorpalBladeFirePress", L"VorpalBladeFirePress | OnRelease VorpalBladeFireRelease" },
	{ L"TeapotCannonFirePress | OnRelease TeapotCannonFirePress", L"TeapotCannonFirePress | OnRelease TeapotCannonFireRelease" },
};

static std::wstring_view Trim(std::wstring_view s)
{
	const size_t first = s.find_first_not_of(L" \t");
	if (first == std::wstring_view::npos) return {};
	const size_t last = s.find_last_not_of(L" \t");
	return s.substr(first, last - first + 1);
}

static void ReplaceEngineString(EngineString& str, const wchar_t* value)
{
	const int n = (int)wcslen(value) + 1;

	if (str.Data)
	{
		reinterpret_cast<void(__cdecl*)(void*, int)>(GetAddress(Addr::FStringFree))(str.Data, 1);
	}
	str = {};

	reinterpret_cast<void(__thiscall*)(EngineString*, int)>(GetAddress(Addr::FStringAlloc))(&str, n);
	if (!str.Data)
	{
		str = {};
		return;
	}

	memcpy(str.Data, value, n * sizeof(wchar_t));
	str.Num = n;
}

static void FixKeyCommandTable()
{
	auto* table = reinterpret_cast<EngineString*>(GetAddress(Addr::KeyCommandsTable));

	for (int i = 0; i < NumAliceKeys; i++)
	{
		EngineString& entry = table[i];
		if (!entry.Data || entry.Num <= 1) continue;

		const std::wstring_view value = Trim(std::wstring_view(entry.Data, entry.Num - 1));

		for (const KeyCommandFix& fix : kKeyCommandFixes)
		{
			if (value == fix.Shipped)
			{
				ReplaceEngineString(entry, fix.Fixed);
				break;
			}
		}
	}
}

static void* __fastcall KeyCommandsLoad_Hook(void* thisp, void*)
{
	void* result = KeyCommandsLoad.thiscall<void*>(thisp);
	FixKeyCommandTable();
	return result;
}

void ApplyFixKeyCommands()
{
	if (!FixInputBinding) return;

	KeyCommandsLoad = HookHelper::CreateHook((void*)GetAddress(Addr::KeyCommandsLoad), &KeyCommandsLoad_Hook);
}