#pragma once

#define MINI_CASE_SENSITIVE
#define _USE_MATH_DEFINES
#define NOMINMAX

#include <Windows.h>
#include <shlwapi.h>
#include <Xinput.h>

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <string_view>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <atomic>
#include <mutex>
#include <utility>
#include <filesystem>
#include <algorithm>
#include <stacktrace>

#pragma comment(lib, "shlwapi.lib")
#pragma comment(lib, "SDL3-static.lib")

#include "safetyhook/safetyhook.hpp"
#include "ini.hpp"
#include "SDK/SdkHeaders.hpp"
#include "Controller.hpp"
#include "dllmain.hpp"
#include "Globals.hpp"
#include "helper.hpp"

#include "Config.hpp"
#include "Addresses.hpp"

#include "AchievementOverlay.hpp"