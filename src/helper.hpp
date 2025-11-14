#include "safetyhook/safetyhook.hpp"

namespace MemoryHelper
{
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

	DWORD64 PatternScan(HMODULE hModule, std::string_view signature)
	{
		auto dosHeader = reinterpret_cast<PIMAGE_DOS_HEADER>(hModule);
		if (dosHeader->e_magic != IMAGE_DOS_SIGNATURE)
			return 0;

		auto ntHeaders = reinterpret_cast<PIMAGE_NT_HEADERS>(reinterpret_cast<BYTE*>(hModule) + dosHeader->e_lfanew);

		if (ntHeaders->Signature != IMAGE_NT_SIGNATURE)
			return 0;

		DWORD sizeOfImage = ntHeaders->OptionalHeader.SizeOfImage;
		DWORD64 baseAddress = reinterpret_cast<DWORD64>(hModule);

		// Convert pattern to byte array and mask
		std::vector<uint8_t> patternBytes;
		std::vector<bool> mask;
		patternBytes.reserve(signature.size() / 2);
		mask.reserve(signature.size() / 2);

		for (size_t i = 0; i < signature.length(); ++i)
		{
			if (signature[i] == ' ')
				continue;

			if (signature[i] == '?')
			{
				patternBytes.push_back(0);
				mask.push_back(true);
				if (i + 1 < signature.length() && signature[i + 1] == '?')
				{
					i++;
				}
			}
			else
			{
				// fast hex parse
				auto hexChar = [](char c) noexcept -> uint8_t {
					if (c >= '0' && c <= '9') return c - '0';
					if (c >= 'A' && c <= 'F') return c - 'A' + 10;
					if (c >= 'a' && c <= 'f') return c - 'a' + 10;
					return 0;
					};
				uint8_t byte = (hexChar(signature[i]) << 4) | hexChar(signature[i + 1]);
				patternBytes.push_back(byte);
				mask.push_back(false);
				i++;
			}
		}

		size_t patternSize = patternBytes.size();
		BYTE* data = reinterpret_cast<BYTE*>(baseAddress);

		// Find first non-wildcard byte for quick scans
		size_t firstCheck = 0;
		while (firstCheck < patternSize && mask[firstCheck])
			firstCheck++;

		if (firstCheck == patternSize)
			return baseAddress; // all wildcards -> match at start

		uint8_t firstByte = patternBytes[firstCheck];
		BYTE* scanEnd = data + sizeOfImage - patternSize;
		BYTE* cur = data;

		while (cur <= scanEnd)
		{
			// find next occurrence of first significant byte
			cur = reinterpret_cast<BYTE*>(std::memchr(cur + firstCheck, firstByte, (scanEnd + firstCheck) - cur));
			if (!cur) break;
			cur -= firstCheck;

			// verify full pattern
			bool found = true;
			for (size_t j = 0; j < patternSize; ++j)
			{
				if (!mask[j] && data[(cur - data) + j] != patternBytes[j])
				{
					found = false;
					break;
				}
			}

			if (found)
				return reinterpret_cast<DWORD64>(cur);

			cur++;
		}

		return 0;
	}

	DWORD FindSignatureAddress(HMODULE Module, std::string_view Signature, int FunctionStartCheckCount = -1)
	{
		DWORD Address = static_cast<DWORD>(PatternScan(Module, Signature));
		if (Address == 0) 
			return 0;

		if (FunctionStartCheckCount >= 0)
		{
			// After a RET, compilers pad with INT3 (0xCC) to align the next function (often on a 16-byte boundary).
			// This padding also acts as a breakpoint if execution runs off the end of a function.
			// We backtrack past any 0xCC bytes to find the real function start.
			for (DWORD ScanAddress = Address; ScanAddress > Address - 0x1000; ScanAddress--)
			{
				bool IsValid = true;
				for (int OffsetIndex = 1; OffsetIndex <= FunctionStartCheckCount; OffsetIndex++)
				{
					if (ReadMemory<uint8_t>(ScanAddress - OffsetIndex) != 0xCC)
					{
						IsValid = false;
						break;
					}
				}
				if (IsValid)
					return ScanAddress;
			}
		}

		return Address;
	}

	DWORD ResolveRelativeAddress(uintptr_t BaseAddress, std::size_t InstructionOffset)
	{
		int RelativeOffset = ReadMemory<int>(BaseAddress + InstructionOffset);
		return BaseAddress + InstructionOffset + sizeof(RelativeOffset) + RelativeOffset;
	}
};

namespace HookHelper
{
	static void LogHookError(void* addr, const safetyhook::InlineHook::Error& err)
	{
		char errorMsg[0x200];
		const char* errorType = "Unknown error";

		switch (err.type) {
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

	static DWORD GetCurrentDisplayFrequency()
	{
		DEVMODE devMode = {};
		devMode.dmSize = sizeof(DEVMODE);

		if (EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &devMode))
		{
			return devMode.dmDisplayFrequency;
		}
		return 60;
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
	mINI::INIFile iniFile(SystemHelper::GetModulePath() + "\\MadnessPatch.ini");
	mINI::INIStructure iniReader;

	void Init()
	{
		iniFile.read(iniReader);
	}

	void Save()
	{
		iniFile.write(iniReader);
	}

	char* ReadString(const char* sectionName, const char* valueName, const char* defaultValue)
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

				strncpy(result, value.c_str(), 254);
				result[254] = '\0';
				return result;
			}
		}
		catch (...) {}

		strncpy(result, defaultValue, 254);
		result[254] = '\0';
		return result;
	}

	float ReadFloat(const char* sectionName, const char* valueName, float defaultValue)
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

	int ReadInteger(const char* sectionName, const char* valueName, int defaultValue)
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