#include "Common.hpp"
#include "Features.hpp"
#include <cstdlib>

namespace MenuMouseCursor
{
	namespace
	{
		constexpr SHORT kStickDeadzone = 12000;
		constexpr BYTE kTriggerDeadzone = 62;
		constexpr LONG kMouseThreshold = 2;
		constexpr ULONGLONG kMousePollIntervalMs = 33;
		constexpr ULONGLONG kSelfMoveIgnoreMs = 250;

		struct CachedMovie
		{
			UGFxMovie* movie;
			int32_t index;
			bool isHud;
		};

		bool s_visible = true;
		bool s_applied = false;
		bool s_haveMousePos = false;
		POINT s_lastMousePos{};
		ULONGLONG s_nextMousePoll = 0;

		bool s_parked = false;
		POINT s_parkReturn{};
		ULONGLONG s_ignoreMouseUntil = 0;

		std::vector<CachedMovie> s_movies;
		uint32_t s_moviesBuiltAt = UINT32_MAX;

		// ---- Engine helpers ----

		const char* BaseName(const FName& name)
		{
			return name.IsValid() ? FName::Names()->at(name.GetDisplayIndex())->Name : "";
		}

		void CallNative(UObject* object, UFunction* function, void* params)
		{
			if (!object || !function) return;

			uint16_t savedNative = function->iNative;
			function->iNative = 0;
			object->ProcessEvent(function, params, nullptr);
			function->iNative = savedNative;
		}

		void MovieSetVariableBool(UGFxMovie* movie, const wchar_t* path, bool value)
		{
			static UFunction* function = nullptr;
			if (!function) function = UFunction::FindFunction("Function GFxUI.GFxMovie.SetVariableBool");
			if (!function) return;

			UGFxMovie_execSetVariableBool_Params params{};
			params.Path = FString(path);
			params.B = value ? 1 : 0;
			CallNative(movie, function, &params);
		}

		void RefreshMovies()
		{
			s_movies.clear();
			TArray<UObject*>* objects = UObject::GObjObjects();
			for (int32_t i = 0; i < objects->size(); i++)
			{
				UObject* object = objects->at(i);
				if (!object || !object->IsA<UGFxMovie>() || object->IsDefaultObject())
					continue;

				bool isHud = object->Class && object->Class->Name.GetInstance() == 0 && strcmp(BaseName(object->Class->Name), "AliceGFxMovie_HUD") == 0;
				s_movies.push_back({ static_cast<UGFxMovie*>(object), i, isHud });
			}

			s_moviesBuiltAt = g_State.gfxMovieLoads;
		}

		bool IsAlive(const CachedMovie& cached)
		{
			TArray<UObject*>* objects = UObject::GObjObjects();
			return cached.index < objects->size() && objects->at(cached.index) == cached.movie;
		}

		// ---- OS pointer ----

		void WarpPointer(POINT screenPos)
		{
			int originX = GetSystemMetrics(SM_XVIRTUALSCREEN);
			int originY = GetSystemMetrics(SM_YVIRTUALSCREEN);
			int width = GetSystemMetrics(SM_CXVIRTUALSCREEN);
			int height = GetSystemMetrics(SM_CYVIRTUALSCREEN);
			if (width < 2 || height < 2) return;

			INPUT input{};
			input.type = INPUT_MOUSE;
			input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_VIRTUALDESK;
			input.mi.dx = ((screenPos.x - originX) * 65535 + (width - 1) / 2) / (width - 1);
			input.mi.dy = ((screenPos.y - originY) * 65535 + (height - 1) / 2) / (height - 1);
			SendInput(1, &input, sizeof(INPUT));

			s_ignoreMouseUntil = GetTickCount64() + kSelfMoveIgnoreMs;
		}

		HWND FocusedGameWindow()
		{
			HWND window = GetForegroundWindow();
			if (!window) return nullptr;

			DWORD pid = 0;
			GetWindowThreadProcessId(window, &pid);
			return (pid == GetCurrentProcessId()) ? window : nullptr;
		}

		void ParkCursor()
		{
			HWND window = FocusedGameWindow();
			if (!window) return;

			POINT corner{ 0, 0 };
			if (!ClientToScreen(window, &corner)) return;

			POINT current{};
			if (!GetCursorPos(&current)) return;
			if (current.x == corner.x && current.y == corner.y) return; // already there

			// Only the first park records where to put the pointer back
			if (!s_parked)
			{
				s_parkReturn = current;
				s_parked = true;
			}

			WarpPointer(corner);
			if (GetCursorPos(&s_lastMousePos)) s_haveMousePos = true;
		}

		void UnparkCursor()
		{
			if (!s_parked) return;
			s_parked = false;

			WarpPointer(s_parkReturn);
			if (GetCursorPos(&s_lastMousePos)) s_haveMousePos = true;
		}

		// ---- Input activity ----

		// Last state the game polled through the SDL XInput hook, no SDL calls here
		bool IsGamepadActive()
		{
			const XINPUT_GAMEPAD& pad = g_State.padState;
			return pad.wButtons != 0
				|| pad.bLeftTrigger > kTriggerDeadzone || pad.bRightTrigger > kTriggerDeadzone
				|| std::abs(pad.sThumbLX) > kStickDeadzone || std::abs(pad.sThumbLY) > kStickDeadzone
				|| std::abs(pad.sThumbRX) > kStickDeadzone || std::abs(pad.sThumbRY) > kStickDeadzone;
		}

		bool IsMouseActive()
		{
			ULONGLONG now = GetTickCount64();
			if (now < s_nextMousePoll) return false;
			s_nextMousePoll = now + kMousePollIntervalMs;

			POINT pos{};
			if (!GetCursorPos(&pos)) return false;

			bool moved = s_haveMousePos && (std::abs(pos.x - s_lastMousePos.x) >= kMouseThreshold || std::abs(pos.y - s_lastMousePos.y) >= kMouseThreshold);

			s_lastMousePos = pos;
			s_haveMousePos = true;

			if (now < s_ignoreMouseUntil) return false;
			if (moved) return true;

			return ((GetAsyncKeyState(VK_LBUTTON) | GetAsyncKeyState(VK_RBUTTON) | GetAsyncKeyState(VK_MBUTTON)) & 0x8000) != 0;
		}

		// ---- Apply ----

		void PushVisibility(bool visible)
		{
			bool menuMovieRunning = false;

			for (const CachedMovie& cached : s_movies)
			{
				if (!IsAlive(cached) || !cached.movie->pMovie.Dummy) continue;

				MovieSetVariableBool(cached.movie, L"_root.cmc._visible", visible);
				menuMovieRunning |= !cached.isHud;
			}

			if (visible)
			{
				UnparkCursor();
			}
			else if (menuMovieRunning)
			{
				ParkCursor();
			}
		}

		void Deactivate()
		{
			if (!s_visible)
			{
				s_visible = true;
				PushVisibility(true);
			}

			UnparkCursor();
			s_applied = false;
			s_haveMousePos = false;
		}
	}

	void Tick()
	{
		if (!g_State.padConnected)
		{
			if (s_applied) Deactivate();
			return;
		}

		bool visible = s_applied && s_visible;

		if (IsGamepadActive())
		{
			visible = false;
			s_haveMousePos = false;
		}
		else if (!visible && IsMouseActive())
		{
			visible = true;
		}

		const bool moviesLoaded = s_moviesBuiltAt != g_State.gfxMovieLoads;
		if (moviesLoaded) RefreshMovies();

		if (s_applied && visible == s_visible)
		{
			// New movies start with their cursor shown, only a hidden cursor has to reach them
			if (moviesLoaded && !visible) PushVisibility(false);
			return;
		}

		s_visible = visible;
		s_applied = true;
		if (!visible) s_haveMousePos = false;
		PushVisibility(visible);
	}
}
