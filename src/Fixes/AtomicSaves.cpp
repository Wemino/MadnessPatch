#include "Common.hpp"
#include "Features.hpp"

#include <cwctype>

safetyhook::InlineHook FileWriterOpen;
safetyhook::InlineHook FileWriterDtor;

struct SavePaths { std::wstring real, tmp, bak; };

static CRITICAL_SECTION g_saveCs;
static std::unordered_map<void*, SavePaths> g_pendingSaves;

static bool IsSaveFile(const wchar_t* n)
{
	// the checkpoint .sav and the persistent .PSD both live under the CheckPoint folder
	return StrStrIW(n, L"alice2checkpoint") || StrStrIW(n, L".psd");
}

static std::wstring ToAbs(const wchar_t* p)
{
	wchar_t buf[1024];
	DWORD len = GetFullPathNameW(p, 1024, buf, nullptr);
	return (len > 0 && len < 1024) ? std::wstring(buf) : std::wstring(p);
}

// FArchiveFileWriterWindows: ArIsError +0x34, Handle +0x80, Flush is vtable slot 18.
static bool FinishWrite(void* writer)
{
	uint8_t* ar = reinterpret_cast<uint8_t*>(writer);
	int32_t& arIsError = *reinterpret_cast<int32_t*>(ar + 0x34);
	HANDLE& handle = *reinterpret_cast<HANDLE*>(ar + 0x80);

	if (handle)
	{
		reinterpret_cast<void(__thiscall*)(void*)>((*reinterpret_cast<uintptr_t**>(writer))[18])(writer);
		if (!CloseHandle(handle)) arIsError = 1;
		handle = nullptr;
	}

	return arIsError == 0;
}

// Make sure the new save is on disk before it takes the old one's place
static bool FlushToDisk(const std::wstring& path)
{
	HANDLE h = CreateFileW(path.c_str(), GENERIC_WRITE, 0, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
	if (h == INVALID_HANDLE_VALUE) return false;

	bool ok = FlushFileBuffers(h) != 0;
	CloseHandle(h);
	return ok;
}

static void Commit(const SavePaths& p, bool ok)
{
	if (!ok || !FlushToDisk(p.tmp))
	{
		DeleteFileW(p.tmp.c_str()); // failed write: keep the existing good save
		return;
	}

	if (GetFileAttributesW(p.real.c_str()) != INVALID_FILE_ATTRIBUTES)
	{
		// atomic replace, old save rolls into .bak (fall back to a plain atomic move if ReplaceFile refuses)
		if (!ReplaceFileW(p.real.c_str(), p.tmp.c_str(), p.bak.c_str(), 0, nullptr, nullptr))
		{
			MoveFileExW(p.tmp.c_str(), p.real.c_str(), MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH);
		}
	}
	else
	{
		// first save ever for this slot: nothing to back up
		MoveFileExW(p.tmp.c_str(), p.real.c_str(), MOVEFILE_WRITE_THROUGH);
	}
}

// FArchiveFileWriter*
static void* __fastcall FileWriterOpen_Hook(void* thisp, int, wchar_t* name, uint32_t flags, void* errDev)
{
	// appending to an empty temp file would replace the save with only the appended part
	if (name && !(flags & 0x08) && IsSaveFile(name))
	{
		std::wstring tmpName = std::wstring(name) + L".tmp";
		void* writer = FileWriterOpen.unsafe_thiscall<void*>(thisp, tmpName.c_str(), flags, errDev);
		if (writer)
		{
			SavePaths p;
			p.real = ToAbs(name); // exact absolute path vanilla would have written
			p.tmp = p.real + L".tmp"; // == absolute of the file we just opened
			p.bak = p.real + L".bak";
			EnterCriticalSection(&g_saveCs);
			g_pendingSaves[writer] = p;
			LeaveCriticalSection(&g_saveCs);
		}
		return writer;
	}

	return FileWriterOpen.unsafe_thiscall<void*>(thisp, name, flags, errDev);
}

// the original frees the object, so read state first
static void* __fastcall FileWriterDtor_Hook(void* thisp, int, char flag)
{
	SavePaths p;
	bool pending = false;

	EnterCriticalSection(&g_saveCs);
	auto it = g_pendingSaves.find(thisp);
	if (it != g_pendingSaves.end())
	{
		p = it->second;
		g_pendingSaves.erase(it);
		pending = true;
	}
	LeaveCriticalSection(&g_saveCs);

	bool ok = pending && FinishWrite(thisp);
	void* result = FileWriterDtor.unsafe_thiscall<void*>(thisp, flag); // handle is closed, the real dtor won't touch the file

	if (pending) Commit(p, ok);
	return result;
}

void ApplyAtomicSaves()
{
	if (!AtomicSaves) return;

	InitializeCriticalSection(&g_saveCs);
	FileWriterOpen = HookHelper::CreateHook((void*)GetAddress(Addr::FileWriterOpen), &FileWriterOpen_Hook);
	FileWriterDtor = HookHelper::CreateHook((void*)GetAddress(Addr::FileWriterDtor), &FileWriterDtor_Hook);
}