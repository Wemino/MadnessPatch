#include "Common.hpp"
#include "Features.hpp"

namespace
{
	using CacheDownloadedPackage_t = int(__thiscall*)(void* self, const wchar_t* path, int userIndex);

	safetyhook::InlineHook CachePaths;

	std::vector<std::wstring> g_packages;

	bool IsPackage(const std::filesystem::path& path)
	{
		const std::wstring extension = path.extension().wstring();

		return _wcsicmp(extension.c_str(), L".upk") == 0
			|| _wcsicmp(extension.c_str(), L".umap") == 0
			|| _wcsicmp(extension.c_str(), L".u") == 0;
	}

	std::wstring ToLower(std::wstring value)
	{
		for (wchar_t& character : value)
		{
			character = static_cast<wchar_t>(::towlower(character));
		}

		return value;
	}

	void __fastcall CachePaths_Hook(void* self, int)
	{
		CachePaths.thiscall<void>(self);

		const auto CacheDownloadedPackage = reinterpret_cast<CacheDownloadedPackage_t>(GetAddress(Addr::CacheDownloadedPackage));

		if (CacheDownloadedPackage == nullptr) return;

		// FindPackageFile checks the downloaded table before the path cache
		for (const std::wstring& package : g_packages)
		{
			CacheDownloadedPackage(self, package.c_str(), -1);
		}
	}
}

void ApplyModFiles()
{
	if (!LoadModFiles) return;

	const uintptr_t addr_CachePaths = GetAddress(Addr::CachePaths);

	if (addr_CachePaths == 0 || GetAddress(Addr::CacheDownloadedPackage) == 0) return;

	const std::filesystem::path directory = std::filesystem::path(SystemHelper::GetModulePath()) / "mods";

	std::error_code error;

	if (!std::filesystem::is_directory(directory, error)) return;

	std::vector<std::filesystem::path> modFolders;

	for (const auto& entry : std::filesystem::directory_iterator(directory, error))
	{
		if (entry.is_directory(error)) modFolders.push_back(entry.path());
	}

	// Name order
	std::sort(modFolders.begin(), modFolders.end());

	std::unordered_map<std::wstring, std::string> claimed; // package name -> mod that owns it
	std::unordered_map<std::string, std::pair<std::string, int>> ignoredMods; // mod -> (mod used instead, package count)

	for (const std::filesystem::path& folder : modFolders)
	{
		const std::string modName = folder.filename().string();

		try
		{
			for (const auto& entry : std::filesystem::recursive_directory_iterator(folder, std::filesystem::directory_options::skip_permission_denied, error))
			{
				if (!entry.is_regular_file(error) || !IsPackage(entry.path())) continue;

				// The engine looks packages up by name, so the stem is the key
				const std::wstring packageName = ToLower(entry.path().stem().wstring());
				const auto inserted = claimed.emplace(packageName, modName);

				if (!inserted.second)
				{
					std::pair<std::string, int>& ignored = ignoredMods[modName];

					if (ignored.second == 0)
					{
						ignored.first = inserted.first->second;
					}

					ignored.second++;
					continue;
				}

				g_packages.push_back(entry.path().wstring());
			}
		}
		catch (...) {}
	}

	if (!ignoredMods.empty())
	{
		std::string message = "More than one mod provides the same packages.\n" "The first mod in alphabetical order is used:\n";

		for (const auto& entry : ignoredMods)
		{
			message += "\n    \"" + entry.first + "\": " + std::to_string(entry.second.second) + " package(s) ignored, \"" + entry.second.first + "\" used instead";
		}

		MessageBoxA(NULL, message.c_str(), "MadnessPatch", MB_ICONWARNING);
	}

	if (g_packages.empty()) return;

	CachePaths = HookHelper::CreateHook(reinterpret_cast<void*>(addr_CachePaths), &CachePaths_Hook);
}
