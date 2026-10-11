#include "Common.hpp"
#include "Features.hpp"

#include <ShellScalingAPI.h>

void ApplyDPIAware()
{
	if (!DPIAware) return;

	// Try Windows 10 1607+ (DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2)
	HMODULE user32 = GetModuleHandleW(L"user32.dll");
	if (user32)
	{
		auto setDpiAwarenessContext = reinterpret_cast<decltype(&SetProcessDpiAwarenessContext)>(GetProcAddress(user32, "SetProcessDpiAwarenessContext"));
		if (setDpiAwarenessContext && setDpiAwarenessContext(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2))
		{
			return;
		}
	}

	// Try Windows 8.1+ (PROCESS_PER_MONITOR_DPI_AWARE)
	HMODULE shcore = LoadLibraryW(L"shcore.dll");
	if (shcore)
	{
		auto setDpiAwareness = reinterpret_cast<decltype(&SetProcessDpiAwareness)>(GetProcAddress(shcore, "SetProcessDpiAwareness"));
		if (setDpiAwareness && SUCCEEDED(setDpiAwareness(PROCESS_PER_MONITOR_DPI_AWARE)))
		{
			FreeLibrary(shcore);
			return;
		}
		FreeLibrary(shcore);
	}

	// Fallback to Windows Vista+ (System DPI aware)
	if (user32)
	{
		auto setDPIAware = reinterpret_cast<decltype(&SetProcessDPIAware)>(GetProcAddress(user32, "SetProcessDPIAware"));
		if (setDPIAware)
		{
			setDPIAware();
		}
	}
}
