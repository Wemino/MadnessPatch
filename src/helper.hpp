#include "safetyhook/safetyhook.hpp"

namespace MemoryHelper
{
	__forceinline static bool IsReadable(const void* ptr, size_t size)
	{
		MEMORY_BASIC_INFORMATION mbi;
		if (!VirtualQuery(ptr, &mbi, sizeof(mbi)))
			return false;

		return (mbi.State == MEM_COMMIT) && (mbi.Protect & (PAGE_READONLY | PAGE_READWRITE | PAGE_EXECUTE_READ | PAGE_EXECUTE_READWRITE)) && ((reinterpret_cast<uintptr_t>(ptr) + size) <= (reinterpret_cast<uintptr_t>(mbi.BaseAddress) + mbi.RegionSize));
	}

	__forceinline static bool IsWritable(const void* ptr, size_t size)
	{
		MEMORY_BASIC_INFORMATION mbi;
		if (!VirtualQuery(ptr, &mbi, sizeof(mbi)))
			return false;

		return (mbi.State == MEM_COMMIT) && (mbi.Protect & (PAGE_READWRITE | PAGE_WRITECOPY | PAGE_EXECUTE_READWRITE | PAGE_EXECUTE_WRITECOPY)) && ((reinterpret_cast<uintptr_t>(ptr) + size) <= (reinterpret_cast<uintptr_t>(mbi.BaseAddress) + mbi.RegionSize));
	}

	template <typename T> static bool WriteMemory(uintptr_t address, T value, bool disableProtection = true)
	{
		DWORD oldProtect;
		if (disableProtection)
		{
			if (!VirtualProtect(reinterpret_cast <LPVOID> (address), sizeof(T), PAGE_EXECUTE_READWRITE, &oldProtect)) return false;
		}
		*reinterpret_cast <T*> (address) = value;
		if (disableProtection)
		{
			VirtualProtect(reinterpret_cast <LPVOID> (address), sizeof(T), oldProtect, &oldProtect);
		}
		return true;
	}

	static bool WriteMemoryRaw(uintptr_t address, const void* data, size_t size, bool disableProtection = true)
	{
		DWORD oldProtect;
		if (disableProtection)
		{
			if (!VirtualProtect(reinterpret_cast <LPVOID> (address), size, PAGE_EXECUTE_READWRITE, &oldProtect)) return false;
		}
		std::memcpy(reinterpret_cast <void*> (address), data, size);
		if (disableProtection)
		{
			VirtualProtect(reinterpret_cast <LPVOID> (address), size, oldProtect, &oldProtect);
		}
		return true;
	}

	static bool MakeNOP(uintptr_t address, size_t count, bool disableProtection = true)
	{
		DWORD oldProtect;
		if (disableProtection)
		{
			if (!VirtualProtect(reinterpret_cast <LPVOID> (address), count, PAGE_EXECUTE_READWRITE, &oldProtect)) return false;
		}
		std::memset(reinterpret_cast <void*> (address), 0x90, count);
		if (disableProtection)
		{
			VirtualProtect(reinterpret_cast <LPVOID> (address), count, oldProtect, &oldProtect);
		}
		return true;
	}

	static bool MakeCALL(uintptr_t srcAddress, uintptr_t destAddress, bool disableProtection = true)
	{
		DWORD oldProtect;
		if (disableProtection)
		{
			if (!VirtualProtect(reinterpret_cast <LPVOID> (srcAddress), 5, PAGE_EXECUTE_READWRITE, &oldProtect)) return false;
		}
		uintptr_t relativeAddress = destAddress - srcAddress - 5; *reinterpret_cast <uint8_t*> (srcAddress) = 0xE8; // CALL opcode
		*reinterpret_cast <uintptr_t*> (srcAddress + 1) = relativeAddress;
		if (disableProtection)
		{
			VirtualProtect(reinterpret_cast <LPVOID> (srcAddress), 5, oldProtect, &oldProtect);
		}
		return true;
	}

	static bool MakeJMP(uintptr_t srcAddress, uintptr_t destAddress, bool disableProtection = true)
	{
		DWORD oldProtect;
		if (disableProtection)
		{
			if (!VirtualProtect(reinterpret_cast <LPVOID> (srcAddress), 5, PAGE_EXECUTE_READWRITE, &oldProtect)) return false;
		}
		uintptr_t relativeAddress = destAddress - srcAddress - 5; *reinterpret_cast <uint8_t*> (srcAddress) = 0xE9; // JMP opcode
		*reinterpret_cast <uintptr_t*> (srcAddress + 1) = relativeAddress;
		if (disableProtection)
		{
			VirtualProtect(reinterpret_cast <LPVOID> (srcAddress), 5, oldProtect, &oldProtect);
		}
		return true;
	}

	template <typename T> static T ReadMemory(uintptr_t address, bool disableProtection = false)
	{
		DWORD oldProtect;
		if (disableProtection)
		{
			if (!VirtualProtect(reinterpret_cast <LPVOID> (address), sizeof(T), PAGE_EXECUTE_READ, &oldProtect)) return T();
		}
		T value = *reinterpret_cast <T*> (address);
		if (disableProtection)
		{
			VirtualProtect(reinterpret_cast <LPVOID> (address), sizeof(T), oldProtect, &oldProtect);
		}
		return value;
	}

	inline void ComputeCodeRange()
	{
		uint8_t* base = reinterpret_cast<uint8_t*>(GetModuleHandleW(nullptr));
		if (!base) return;
		IMAGE_DOS_HEADER* dos = reinterpret_cast<IMAGE_DOS_HEADER*>(base);
		IMAGE_NT_HEADERS* nt = reinterpret_cast<IMAGE_NT_HEADERS*>(base + dos->e_lfanew);
		IMAGE_SECTION_HEADER* sec = IMAGE_FIRST_SECTION(nt);
		uintptr_t lo = ~uintptr_t(0), hi = 0;

		for (UINT i = 0; i < nt->FileHeader.NumberOfSections; i++)
		{
			if (sec[i].Characteristics & IMAGE_SCN_MEM_EXECUTE)
			{
				uintptr_t s = reinterpret_cast<uintptr_t>(base) + sec[i].VirtualAddress;
				uintptr_t e = s + sec[i].Misc.VirtualSize;
				if (s < lo) lo = s;
				if (e > hi) hi = e;
			}
		}

		if (hi > lo)
		{
			g_State.CodeLo = lo;
			g_State.CodeHi = hi;
		}
	}

	inline bool IsExeCode(uint32_t addr)
	{
		return addr >= g_State.CodeLo && addr < g_State.CodeHi;
	}
};

namespace HookHelper
{
	static void LogHookError(void* addr, const safetyhook::InlineHook::Error& err)
	{
		char errorMsg[0x200];
		const char* errorType = "Unknown error";

		switch (err.type) 
		{
			case safetyhook::InlineHook::Error::BAD_ALLOCATION:
				errorType = "BAD_ALLOCATION";
				break;
			case safetyhook::InlineHook::Error::FAILED_TO_DECODE_INSTRUCTION:
				errorType = "FAILED_TO_DECODE_INSTRUCTION";
				break;
			case safetyhook::InlineHook::Error::SHORT_JUMP_IN_TRAMPOLINE:
				errorType = "SHORT_JUMP_IN_TRAMPOLINE";
				break;
			case safetyhook::InlineHook::Error::IP_RELATIVE_INSTRUCTION_OUT_OF_RANGE:
				errorType = "IP_RELATIVE_INSTRUCTION_OUT_OF_RANGE";
				break;
			case safetyhook::InlineHook::Error::UNSUPPORTED_INSTRUCTION_IN_TRAMPOLINE:
				errorType = "UNSUPPORTED_INSTRUCTION_IN_TRAMPOLINE";
				break;
			case safetyhook::InlineHook::Error::FAILED_TO_UNPROTECT:
				errorType = "FAILED_TO_UNPROTECT";
				break;
			case safetyhook::InlineHook::Error::NOT_ENOUGH_SPACE:
				errorType = "NOT_ENOUGH_SPACE";
				break;
		}

		sprintf_s(errorMsg, "Failed to create hook at %p\nError: %s", addr, errorType);
		MessageBoxA(NULL, errorMsg, "SafetyHook Error", MB_ICONERROR | MB_OK);
	}

	static safetyhook::InlineHook CreateHook(void* addr, void* hookFunc)
	{
		auto hook = safetyhook::create_inline(addr, hookFunc);

		if (!hook) 
		{
			auto result = safetyhook::InlineHook::create(addr, hookFunc);
			if (!result) 
			{
				LogHookError(addr, result.error());
			}
		}

		return hook;
	}

	static safetyhook::InlineHook CreateHookAPI(LPCWSTR moduleName, LPCSTR apiName, void* hookFunc)
	{
		HMODULE module = GetModuleHandleW(moduleName);
		if (!module) 
		{
			char errorMsg[0x100];
			sprintf_s(errorMsg, "Failed to get module: %ls", moduleName);
			MessageBoxA(NULL, errorMsg, "SafetyHook Error", MB_ICONERROR | MB_OK);
			return safetyhook::InlineHook{};
		}

		void* targetFunc = GetProcAddress(module, apiName);
		if (!targetFunc) 
		{
			char errorMsg[0x100];
			sprintf_s(errorMsg, "Failed to get API address: %s", apiName);
			MessageBoxA(NULL, errorMsg, "SafetyHook Error", MB_ICONERROR | MB_OK);
			return safetyhook::InlineHook{};
		}

		return CreateHook(targetFunc, hookFunc);
	}
}

namespace SystemHelper
{
	static std::string GetModulePath()
	{
		HMODULE hModule = nullptr;

		// Get the module handle for the DLL containing this code
		GetModuleHandleExW(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, (LPCWSTR)&GetModulePath, &hModule);

		wchar_t path[FILENAME_MAX] = { 0 };
		GetModuleFileNameW(hModule, path, FILENAME_MAX);
		return std::filesystem::path(path).parent_path().string();
	}

	static bool ResolveDirectory(const wchar_t* pathStr, wchar_t* outFullPath = nullptr)
	{
		if (!pathStr)
			return false;

		wchar_t scratch[MAX_PATH];
		wchar_t* fullPath = outFullPath ? outFullPath : scratch;

		wchar_t currentDir[MAX_PATH];
		GetCurrentDirectoryW(MAX_PATH, currentDir);

		if (PathIsRelativeW(pathStr))
		{
			PathCombineW(fullPath, currentDir, pathStr);
		}
		else
		{
			wcscpy_s(fullPath, MAX_PATH, pathStr);
		}

		wchar_t canonicalPath[MAX_PATH];
		if (PathCanonicalizeW(canonicalPath, fullPath))
		{
			wcscpy_s(fullPath, MAX_PATH, canonicalPath);
		}

		DWORD attribs = GetFileAttributesW(fullPath);
		return attribs != INVALID_FILE_ATTRIBUTES && (attribs & FILE_ATTRIBUTE_DIRECTORY);
	}

	static std::pair<DWORD, DWORD> GetScreenResolution()
	{
		DEVMODE devMode = {};
		devMode.dmSize = sizeof(DEVMODE);

		if (EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &devMode))
		{
			return { devMode.dmPelsWidth, devMode.dmPelsHeight };
		}
		return { 0, 0 };
	}

	static bool GetTargetSize(int& outWidth, int& outHeight)
	{
		auto [screenWidth, screenHeight] = SystemHelper::GetScreenResolution();

		outWidth = (int)screenWidth;
		outHeight = (int)screenHeight;

		return outWidth > 0 && outHeight > 0;
	}

	static void LoadProxyLibrary()
	{
		// Attempt to load the chain-load DLL from the game's directory
		wchar_t modulePath[MAX_PATH];
		if (GetModuleFileNameW(NULL, modulePath, MAX_PATH))
		{
			wchar_t* lastBackslash = wcsrchr(modulePath, L'\\');
			if (lastBackslash != NULL)
			{
				*lastBackslash = L'\0';
				lstrcatW(modulePath, L"\\dinput8_hook.dll");

				HINSTANCE hChain = LoadLibraryExW(modulePath, NULL, LOAD_WITH_ALTERED_SEARCH_PATH);
				if (hChain)
				{
					// Set up proxies to use the chain-loaded DLL
					if (dinput8.ProxySetup(hChain))
					{
						return; // Successfully chained
					}
					else
					{
						// Handle missing exports in chain DLL
						FreeLibrary(hChain);
						// Fall through to system DLL
					}
				}
			}
		}

		// Fallback to system dinput8.dll
		wchar_t systemPath[MAX_PATH];
		GetSystemDirectoryW(systemPath, MAX_PATH);
		lstrcatW(systemPath, L"\\dinput8.dll");

		HINSTANCE hOriginal = LoadLibraryExW(systemPath, 0, LOAD_WITH_ALTERED_SEARCH_PATH);
		if (!hOriginal)
		{
			DWORD errorCode = GetLastError();
			wchar_t errorMessage[512];

			FormatMessageW(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, NULL, errorCode, MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US), errorMessage, sizeof(errorMessage) / sizeof(wchar_t), NULL);
			MessageBoxW(NULL, errorMessage, L"Error Loading dinput8.dll", MB_ICONERROR);
			return;
		}

		// Set up proxies to system DLL
		dinput8.ProxySetup(hOriginal);
	}
};

namespace IniHelper
{
	inline mINI::INIFile iniFile(SystemHelper::GetModulePath() + "\\MadnessPatch.ini");
	inline mINI::INIStructure iniReader;

	inline void Init()
	{
		iniFile.read(iniReader);
	}

	inline void Save()
	{
		iniFile.write(iniReader);
	}

	inline char* ReadString(const char* sectionName, const char* valueName, const char* defaultValue)
	{
		char* result = new char[255];
		try
		{
			if (iniReader.has(sectionName) && iniReader.get(sectionName).has(valueName))
			{
				std::string value = iniReader.get(sectionName).get(valueName);

				if (!value.empty() && (value.front() == '\"' || value.front() == '\''))
					value.erase(0, 1);
				if (!value.empty() && (value.back() == '\"' || value.back() == '\''))
					value.erase(value.size() - 1);

				strncpy_s(result, 255, value.c_str(), _TRUNCATE);
				result[254] = '\0';
				return result;
			}
		}
		catch (...) {}

		strncpy_s(result, 255, defaultValue, _TRUNCATE);
		result[254] = '\0';
		return result;
	}

	inline float ReadFloat(const char* sectionName, const char* valueName, float defaultValue)
	{
		try
		{
			if (iniReader.has(sectionName) && iniReader.get(sectionName).has(valueName))
			{
				const std::string& s = iniReader.get(sectionName).get(valueName);
				if (!s.empty())
					return std::stof(s);
			}
		}
		catch (...) {}
		return defaultValue;
	}

	inline int ReadInteger(const char* sectionName, const char* valueName, int defaultValue)
	{
		try
		{
			if (iniReader.has(sectionName) && iniReader.get(sectionName).has(valueName))
			{
				const std::string& s = iniReader.get(sectionName).get(valueName);
				if (!s.empty())
					return std::stoi(s);
			}
		}
		catch (...) {}
		return defaultValue;
	}
};

namespace ScriptHelper
{
	struct OutParmRec
	{
		UProperty* Property;
		uint8_t* PropAddr;
		OutParmRec* Next;
	};

	// FFrame
	struct Frame
	{
		void* VfTable;
		uint32_t Flags[3];
		UStruct* Node;
		UObject* Object;
		uint8_t* Code;
		uint8_t* Locals;
		Frame* PreviousFrame;
		OutParmRec* OutParms;
	};

	using Native = void(__thiscall*)(UObject*, Frame*, void*);

	inline Native* GNatives = nullptr;

	constexpr uint8_t EX_DebugInfo = 0x41;

	// P_GET_*
	inline void StepParm(Frame* stack, void* value)
	{
		uint8_t token = *stack->Code++;
		GNatives[token](stack->Object, stack, value);
	}

	// P_FINISH
	inline void FinishParms(Frame* stack)
	{
		stack->Code++; // EX_EndFunctionParms
		if (*stack->Code == EX_DebugInfo)
		{
			stack->Code++;
			GNatives[EX_DebugInfo](stack->Object, stack, nullptr);
		}
	}

	namespace Token
	{
		constexpr uint8_t LocalVariable = 0x00;
		constexpr uint8_t InstanceVariable = 0x01;
		constexpr uint8_t Return = 0x04;
		constexpr uint8_t Jump = 0x06;
		constexpr uint8_t JumpIfNot = 0x07;
		constexpr uint8_t Nothing = 0x0B;
		constexpr uint8_t Let = 0x0F;
		constexpr uint8_t EndFunctionParms = 0x16;
		constexpr uint8_t Context = 0x19;
		constexpr uint8_t VirtualFunction = 0x1B;
		constexpr uint8_t FloatConst = 0x1E;
		constexpr uint8_t PrimitiveCast = 0x38;
		constexpr uint8_t FloatToIntCast = 0x44;
		constexpr uint8_t EndOfScript = 0x53;
		constexpr uint8_t AddEqual_IntInt = 161;
		constexpr uint8_t Multiply_FloatFloat = 171;
		constexpr uint8_t Divide_FloatFloat = 172;
		constexpr uint8_t Less_FloatFloat = 176;
		constexpr uint8_t AddEqual_FloatFloat = 184;
		constexpr uint8_t SubtractEqual_FloatFloat = 185;
		constexpr uint8_t Abs = 186;
		constexpr uint8_t Subtract_VectorVector = 216;
		constexpr uint8_t VSize = 225;
	}

	// A token expected at an offset from a place in a function's bytecode, and its operand
	struct Expect
	{
		enum Operand : uint8_t { None, Local, Member, Name, Float };

		int16_t offset;
		uint8_t token;
		Operand operand = None;
		const char* name = nullptr;
		UClass* (*owner)() = nullptr;
		float value = 0.0f;
	};

	struct Site;

	using SiteDone = void(*)(Site& site, Frame* stack, void* result);

	// A token replaced by one that runs it, then hands its value to done
	struct SiteSpec
	{
		const char* function;
		const Expect* expects;
		int expectCount;
		SiteDone done;
		const char* timeFunction = nullptr;
		const char* timeParm = "DeltaTime";
	};

	struct Site
	{
		const SiteSpec* spec = nullptr;
		uint8_t* code = nullptr;
		uint8_t original = 0;
		UStruct* timeFunction = nullptr;
		UProperty* timeParm = nullptr;
		float carry = 0.0f;
	};

	// Engine/ScriptPatches.cpp
	UProperty* FindProperty(UStruct* scope, const char* name, bool inherited);
	uint8_t* FindConstant(UFunction* fn, const uint8_t* pattern, size_t size);
	uint8_t* FindPlace(const char* function, const Expect* expects, int count);
	bool InstallSite(const SiteSpec& spec);
	bool SiteDeltaTime(const Site& site, Frame* stack, float& deltaTime);
}