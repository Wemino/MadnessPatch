#include "Common.hpp"
#include "Features.hpp"

void ApplyASILoader()
{
	if (!LoadASIPlugins || g_State.isUALPresent) return;

	const std::filesystem::path directory = std::filesystem::path(SystemHelper::GetModulePath()) / "plugins";

	std::error_code error;

	if (!std::filesystem::is_directory(directory, error)) return;

	const std::wstring directoryPath = directory.wstring();

	wchar_t previousDirectory[MAX_PATH] = {};
	const bool restoreDirectory = GetCurrentDirectoryW(MAX_PATH, previousDirectory) != 0;

	try
	{
		for (const auto& entry : std::filesystem::directory_iterator(directory, error))
		{
			if (!entry.is_regular_file(error)) continue;
			if (_wcsicmp(entry.path().extension().c_str(), L".asi") != 0) continue;

			const std::wstring fullPath = entry.path().wstring();

			if (GetModuleHandleW(fullPath.c_str()) != NULL) continue;

			// Plugins expect their own folder as the working directory
			SetCurrentDirectoryW(directoryPath.c_str());

			if (LoadLibraryW(fullPath.c_str()) != NULL) continue;

			const DWORD lastError = GetLastError();

			// The plugin refused to start or was built for another architecture
			if (lastError == ERROR_DLL_INIT_FAILED || lastError == ERROR_BAD_EXE_FORMAT) continue;

			const std::string message = "Unable to load " + entry.path().filename().string() + "\nError: " + std::to_string(lastError);

			MessageBoxA(NULL, message.c_str(), "MadnessPatch", MB_ICONERROR);
		}
	}
	catch (...) {}

	if (restoreDirectory) SetCurrentDirectoryW(previousDirectory);
}
