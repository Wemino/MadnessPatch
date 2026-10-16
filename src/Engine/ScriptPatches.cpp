#include "Common.hpp"
#include "Features.hpp"

using namespace ScriptHelper;

// ---- Sites ----

constexpr int32_t ObjectOperandSize = 8;
constexpr int32_t NameOperandSize = 8;
constexpr int32_t FloatOperandSize = 4;
constexpr int MaxExpects = 8;
constexpr int MaxSites = 64;
constexpr int GNativesCount = 0x1000;
constexpr uint8_t UnusedTokens[] = { 0x5F, 0x5E, 0x5D, 0x5C, 0x5B, 0x5A, 0x50, 0x4F, 0x4E, 0x4D, 0x4C };

struct Check
{
	const Expect* expect;
	const void* property;
};

static Site sites[MaxSites];
static int siteCount = 0;
static int siteToken = -1;
static Native undefinedToken = nullptr;

UProperty* ScriptHelper::FindProperty(UStruct* scope, const char* name, bool inherited)
{
	for (; scope; scope = inherited ? static_cast<UStruct*>(scope->SuperField) : nullptr)
	{
		for (UField* field = scope->Children; field; field = field->Next)
		{
			if (_stricmp(field->GetName().c_str(), name) == 0)
				return static_cast<UProperty*>(field);
		}
	}

	return nullptr;
}

static bool NameIs(const uint8_t* at, const char* name)
{
	int32_t index;
	int32_t number;
	memcpy(&index, at, sizeof(index));
	memcpy(&number, at + sizeof(index), sizeof(number));

	TArray<FNameEntry*>* names = FName::Names();
	if (number != 0 || !names || index < 0 || index >= names->size())
		return false;

	FNameEntry* entry = names->at(index);
	return entry && _stricmp(entry->ToString().c_str(), name) == 0;
}

static int32_t OperandSize(Expect::Operand operand)
{
	switch (operand)
	{
		case Expect::Local:
		case Expect::Member:
			return ObjectOperandSize;
		case Expect::Name:
			return NameOperandSize;
		case Expect::Float:
			return FloatOperandSize;
		default:
			return 0;
	}
}

// The token the game's bytecode has there, also under a site
static uint8_t GameToken(const uint8_t* at)
{
	if (siteToken >= 0 && *at == siteToken)
	{
		for (int i = 0; i < siteCount; i++)
		{
			if (sites[i].code == at)
				return sites[i].original;
		}
	}

	return *at;
}

static bool Matches(const uint8_t* code, int32_t size, int32_t place, const Check* checks, int count)
{
	for (int i = 0; i < count; i++)
	{
		const Expect& e = *checks[i].expect;
		int32_t at = place + e.offset;
		if (at < 0 || at + 1 + OperandSize(e.operand) > size || GameToken(code + at) != e.token)
			return false;

		const uint8_t* operand = code + at + 1;
		switch (e.operand)
		{
			case Expect::Local:
			case Expect::Member:
				if (memcmp(operand, &checks[i].property, sizeof(void*)) != 0)
					return false;
				break;
			case Expect::Name:
				if (!NameIs(operand, e.name))
					return false;
				break;
			case Expect::Float:
				if (memcmp(operand, &e.value, sizeof(e.value)) != 0)
					return false;
				break;
			default:
				break;
		}
	}

	return true;
}

uint8_t* ScriptHelper::FindConstant(UFunction* fn, const uint8_t* pattern, size_t size)
{
	if (!fn)
		return nullptr;

	TArray<uint8_t>& code = fn->Script;
	uint8_t* found = nullptr;
	for (int32_t i = 0; i + static_cast<int32_t>(size) <= code.size(); i++)
	{
		if (memcmp(&code[i], pattern, size) != 0)
			continue;

		if (found)
			return nullptr; // ambiguous

		found = &code[i + 1];
	}

	return found;
}

// The one place of the function where every expected token is
uint8_t* ScriptHelper::FindPlace(const char* function, const Expect* expects, int count)
{
	UFunction* fn = UFunction::FindFunction(function);
	if (!fn || count > MaxExpects)
		return nullptr;

	Check checks[MaxExpects];
	for (int i = 0; i < count; i++)
	{
		const Expect& e = expects[i];
		checks[i] = { &e, nullptr };
		if (e.operand == Expect::Local)
		{
			checks[i].property = FindProperty(fn, e.name, false);
		}
		else if (e.operand == Expect::Member)
		{
			checks[i].property = FindProperty(e.owner ? e.owner() : nullptr, e.name, true);
		}
		else
		{
			continue;
		}

		if (!checks[i].property)
			return nullptr;
	}

	TArray<uint8_t>& script = fn->Script;
	int32_t size = script.size();
	int32_t place = -1;
	int places = 0;
	for (int32_t i = 0; i < size; i++)
	{
		if (Matches(&script[0], size, i, checks, count))
		{
			place = i;
			places++;
		}
	}

	return places == 1 ? &script[place] : nullptr;
}

static void __fastcall RunSite(UObject* context, void*, Frame* stack, void* result)
{
	const uint8_t* at = stack->Code - 1;
	for (int i = 0; i < siteCount; i++)
	{
		Site& site = sites[i];
		if (site.code != at)
			continue;

		GNatives[site.original](context, stack, result);
		site.spec->done(site, stack, result);
		return;
	}

	undefinedToken(context, stack, result);
}

// The sites run as a token nothing registered: the most common handler of GNatives is execUndefined
static bool InstallSiteToken()
{
	std::unordered_map<uintptr_t, int> counts;
	uintptr_t undefined = 0;
	int undefinedCount = 0;
	for (int i = 0; i < GNativesCount; i++)
	{
		uintptr_t handler = reinterpret_cast<uintptr_t>(GNatives[i]);
		int count = ++counts[handler];
		if (count > undefinedCount)
		{
			undefinedCount = count;
			undefined = handler;
		}
	}

	if (undefinedCount < GNativesCount / 4)
		return false;

	undefinedToken = reinterpret_cast<Native>(undefined);
	for (uint8_t token : UnusedTokens)
	{
		if (GNatives[token] == undefinedToken)
		{
			siteToken = token;
			break;
		}
	}

	if (siteToken < 0)
		return false;

	Native handler = reinterpret_cast<Native>(reinterpret_cast<void*>(&RunSite));
	MemoryHelper::WriteMemory<Native>(reinterpret_cast<uintptr_t>(&GNatives[siteToken]), handler);

	if (GNatives[siteToken] != handler)
	{
		siteToken = -1;
		return false;
	}

	return true;
}

bool ScriptHelper::InstallSite(const SiteSpec& spec)
{
	if (siteToken < 0 || siteCount >= MaxSites)
		return false;

	Site site;
	site.spec = &spec;
	if (spec.timeFunction)
	{
		UFunction* timeFunction = UFunction::FindFunction(spec.timeFunction);
		site.timeFunction = timeFunction;
		site.timeParm = timeFunction ? FindProperty(timeFunction, spec.timeParm, false) : nullptr;
		if (!site.timeParm)
			return false;
	}

	uint8_t* code = FindPlace(spec.function, spec.expects, spec.expectCount);
	if (!code || GameToken(code) != *code)
		return false;

	site.code = code;
	site.original = *code;
	sites[siteCount++] = site;
	*code = static_cast<uint8_t>(siteToken);
	return true;
}

// DeltaTime of the site's time function, when it is on the way to the site
bool ScriptHelper::SiteDeltaTime(const Site& site, Frame* stack, float& deltaTime)
{
	int depth = 0;
	for (Frame* frame = stack; frame && site.timeFunction && depth < 4; frame = frame->PreviousFrame, depth++)
	{
		if (frame->Node == site.timeFunction && frame->Locals)
		{
			memcpy(&deltaTime, frame->Locals + site.timeParm->Offset, sizeof(deltaTime));
			return true;
		}
	}

	return false;
}

// ---- Menus ----

static int32_t DesiredControllerIconSet()
{
	if (UsePS3ControllerIcons == 1) return 2; // Xbox 360 icons
	if (UsePS3ControllerIcons == 2) return 3; // PS3 icons
	return (ControllerHelper::GetGamepadStyle() == ControllerHelper::GamepadStyle::PlayStation) ? 3 : 2;
}

static void UnlockDLCStatus(Site&, Frame*, void* result)
{
	if (result)
	{
		*reinterpret_cast<int32_t*>(result) = 2; // DLC_AUTHENTICATED
	}
}

static void CalloutIcons(Site&, Frame*, void* result)
{
	if (result && g_State.isUsingGamepad && *reinterpret_cast<int32_t*>(result) == 2 && DesiredControllerIconSet() == 3)
	{
		*reinterpret_cast<int32_t*>(result) = 3;
	}
}

static void MenuIcons(Site&, Frame*, void* result)
{
	if (result && ControllerHelper::IsConnected())
	{
		*reinterpret_cast<int32_t*>(result) = DesiredControllerIconSet();
	}
}

static void RemoveUpgradeCursor(Site&, Frame*, void*)
{
	UGFxMovie* hud = reinterpret_cast<UGFxMovie*>(UObject::FindFirstOf<UAliceGFxMovie_HUD>());
	static UFunction* asVoid = UFunction::FindFunction("Function GFxUI.GFxMovie.ActionScriptVoid");
	if (!hud || !asVoid)
		return;

	struct { FString Path; } p;
	p.Path = FString(L"_root.cmc.removeMovieClip");
	hud->ProcessEvent(asVoid, &p, nullptr);
}

// return GetAlicePlayerController().DLCGetStatus(item)
static const Expect dlcStatus[] =
{
	{ 0, Token::Context },
	{ -1, Token::Return },
	{ 1, Token::VirtualFunction, Expect::Name, "GetAlicePlayerController" },
	{ 22, Token::VirtualFunction, Expect::Name, "DLCGetStatus" },
};

// return GetAlicePlayerController().GetCalloutPlatform()
static const Expect calloutPlatform[] =
{
	{ 0, Token::Context },
	{ -1, Token::Return },
	{ 1, Token::VirtualFunction, Expect::Name, "GetAlicePlayerController" },
	{ 22, Token::VirtualFunction, Expect::Name, "GetCalloutPlatform" },
};

// return platform
static const Expect menuPlatform[] =
{
	{ 0, Token::LocalVariable, Expect::Local, "platform" },
	{ -1, Token::Return },
};

// the final return
static const Expect upgradeDone[] =
{
	{ 0, Token::Nothing },
	{ -1, Token::Return },
	{ 1, Token::EndOfScript },
};

static const SiteSpec dlcStatusSite = { "Function AliceGame.AliceGFXMovie.DLCGetStatus", dlcStatus, std::size(dlcStatus), &UnlockDLCStatus };
static const SiteSpec calloutSite = { "Function AliceGame.AliceGFXMovie.GetCalloutPlatform", calloutPlatform, std::size(calloutPlatform), &CalloutIcons };
static const SiteSpec menuPlatformSite = { "Function AliceGame.AliceGFXMovie.GetPlatform", menuPlatform, std::size(menuPlatform), &MenuIcons };
static const SiteSpec upgradeDoneSite = { "Function AliceGame.AliceGFXMovie.finishFirstWeaponUpgrade", upgradeDone, std::size(upgradeDone), &RemoveUpgradeCursor };

static void PatchMenus()
{
	if (UnlockCompleteEditionDLC)
	{
		InstallSite(dlcStatusSite);
	}

	InstallSite(calloutSite);

	if (EnableControllerIcons)
	{
		InstallSite(menuPlatformSite);
	}

	if (FixUpgradeCursorLeak)
	{
		InstallSite(upgradeDoneSite);
	}
}

// ---- Pinball cannon ----

// ShowPOIUIHint(0.0, UIText_Fire)
static const Expect pinballShow[] =
{
	{ 0, Token::VirtualFunction, Expect::Name, "ShowPOIUIHint" },
	{ 9, Token::FloatConst, Expect::Float, nullptr, nullptr, 0.0f },
};

// ShowPOIUIHint(-1.0, UIText_Fire)
static const Expect pinballHide[] =
{
	{ 0, Token::VirtualFunction, Expect::Name, "ShowPOIUIHint" },
	{ 9, Token::FloatConst, Expect::Float, nullptr, nullptr, -1.0f },
};

// The PC version doesn't show POI hints: the calls go to ShowContextActionUIHint, whose first parameter is an int
static void PatchPinballCannonPrompt()
{
	UFunction* showContext = UFunction::FindFunction("Function AliceGame.AlicePlayerController.ShowContextActionUIHint");
	if (!showContext)
		return;

	FName contextName = showContext->Name;
	if (uint8_t* call = FindPlace("Function AliceGame.PinballCannon.Touch", pinballShow, std::size(pinballShow)))
	{
		memcpy(call + 1, &contextName, sizeof(contextName)); // 0.0 reads as 0 (show)
	}

	if (uint8_t* call = FindPlace("Function AliceGame.PinballCannon.ShootOut", pinballHide, std::size(pinballHide)))
	{
		int32_t hide = -2;
		memcpy(call + 1, &contextName, sizeof(contextName));
		memcpy(call + 10, &hide, sizeof(hide));
	}
}

void ApplyScriptPatches()
{
	static bool applied = false;
	if (applied) return;
	applied = true;

	GNatives = reinterpret_cast<Native*>(GetAddress(Addr::GNatives));
	if (GNatives)
	{
		InstallSiteToken();
	}

	PatchMenus();

	if (FixPinballCannonPrompt)
	{
		PatchPinballCannonPrompt();
	}
}
