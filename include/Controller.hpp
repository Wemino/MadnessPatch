#pragma once

#include <SDL3/SDL.h>
#include <Windows.h>
#include <Xinput.h>

namespace ControllerHelper
{
	// ==========================================================
	// Types and Enums
	// ==========================================================

	enum class GamepadStyle
	{
		Xbox,
		PlayStation,
		Nintendo,
		Unknown
	};

	struct GamepadCapabilities
	{
		GamepadStyle style = GamepadStyle::Unknown;
		bool hasTouchpad = false;
		const char* name = nullptr;
		Uint16 vendorId = 0;
		Uint16 productId = 0;
	};

	struct TouchpadConfig
	{
		bool isEnabled = true;
		int currentWidth = 0;
		int currentHeight = 0;
	};

	struct TouchpadState
	{
		bool wasDown = false;
		float lastX = 0.0f;
		float lastY = 0.0f;
	};

	// ==========================================================
	// Static State
	// ==========================================================

	inline SDL_Gamepad* s_pGamepad = nullptr;
	inline GamepadCapabilities s_capabilities;

	inline TouchpadConfig s_touchpadConfig;
	static constexpr int MAX_TOUCHPADS = 2;
	static constexpr int MAX_FINGERS = 2;

	inline TouchpadState s_touchpadFinger[MAX_TOUCHPADS][MAX_FINGERS];
	inline bool s_wasTouchpadPressed[MAX_TOUCHPADS] = {};

	// ==========================================================
	// Controller Database
	// ==========================================================

	inline bool LoadGamepadMappings()
	{
		const char* paths[] =
		{
			"gamecontrollerdb.txt",
			"../gamecontrollerdb.txt",
		};

		for (const char* path : paths)
		{
			int result = SDL_AddGamepadMappingsFromFile(path);
			if (result >= 0)
			{
				return true;
			}
		}

		return false;
	}

	// ==========================================================
	// Capability Detection
	// ==========================================================

	inline GamepadStyle DetectGamepadStyle(SDL_Gamepad* pGamepad)
	{
		if (!pGamepad)
			return GamepadStyle::Unknown;

		SDL_GamepadType type = SDL_GetGamepadType(pGamepad);

		switch (type)
		{
			case SDL_GAMEPAD_TYPE_PS3:
			case SDL_GAMEPAD_TYPE_PS4:
			case SDL_GAMEPAD_TYPE_PS5:
				return GamepadStyle::PlayStation;

			default:
				break;
		}

		if (SDL_GetGamepadButtonLabel(pGamepad, SDL_GAMEPAD_BUTTON_SOUTH) == SDL_GAMEPAD_BUTTON_LABEL_B)
			return GamepadStyle::Nintendo;

		return GamepadStyle::Xbox;
	}

	inline void LoadGamepadCapabilities(SDL_Gamepad* pGamepad)
	{
		s_capabilities = GamepadCapabilities();

		if (!pGamepad)
			return;

		s_capabilities.style = DetectGamepadStyle(pGamepad);
		s_capabilities.hasTouchpad = SDL_GetNumGamepadTouchpads(pGamepad) > 0;
		s_capabilities.name = SDL_GetGamepadName(pGamepad);
		s_capabilities.vendorId = SDL_GetGamepadVendor(pGamepad);
		s_capabilities.productId = SDL_GetGamepadProduct(pGamepad);
	}

	inline void ResetControllerState()
	{
		s_capabilities = GamepadCapabilities();

		for (int tp = 0; tp < MAX_TOUCHPADS; tp++)
		{
			for (int f = 0; f < MAX_FINGERS; f++)
			{
				s_touchpadFinger[tp][f] = TouchpadState();
			}
			s_wasTouchpadPressed[tp] = false;
		}
	}

	// ==========================================================
	// Initialization / Shutdown
	// ==========================================================

	inline bool InitializeSDLGamepad()
	{
		if (!SDL_InitSubSystem(SDL_INIT_GAMEPAD))
		{
			SDL_Quit();
			return false;
		}

		LoadGamepadMappings();

		const SDL_EventType unusedEvents[] =
		{
			SDL_EVENT_JOYSTICK_AXIS_MOTION, SDL_EVENT_JOYSTICK_BALL_MOTION, SDL_EVENT_JOYSTICK_HAT_MOTION,
			SDL_EVENT_JOYSTICK_BUTTON_DOWN, SDL_EVENT_JOYSTICK_BUTTON_UP,
			SDL_EVENT_GAMEPAD_AXIS_MOTION, SDL_EVENT_GAMEPAD_BUTTON_DOWN, SDL_EVENT_GAMEPAD_BUTTON_UP,
			SDL_EVENT_GAMEPAD_TOUCHPAD_DOWN, SDL_EVENT_GAMEPAD_TOUCHPAD_MOTION, SDL_EVENT_GAMEPAD_TOUCHPAD_UP,
			SDL_EVENT_GAMEPAD_SENSOR_UPDATE,
		};
		for (SDL_EventType eventType : unusedEvents)
		{
			SDL_SetEventEnabled(eventType, false);
		}

		return true;
	}

	inline void ShutdownSDLGamepad()
	{
		if (s_pGamepad)
		{
			SDL_CloseGamepad(s_pGamepad);
			s_pGamepad = nullptr;
		}

		ResetControllerState();

		SDL_Quit();
	}

	// ==========================================================
	// Accessors - Controller
	// ==========================================================

	inline SDL_Gamepad* GetGamepad()
	{
		return s_pGamepad;
	}

	inline const GamepadCapabilities& GetCapabilities()
	{
		return s_capabilities;
	}

	inline GamepadStyle GetGamepadStyle()
	{
		return s_capabilities.style;
	}

	inline bool IsConnected()
	{
		return s_pGamepad && SDL_GamepadConnected(s_pGamepad);
	}

	// ==========================================================
	// Accessors - Touchpad
	// ==========================================================

	inline bool HasTouchpad()
	{
		return s_capabilities.hasTouchpad;
	}

	// ==========================================================
	// Configuration - Touchpad
	// ==========================================================

	inline void SetTouchpadEnabled(bool enabled)
	{
		s_touchpadConfig.isEnabled = enabled;
	}

	inline void SetTouchpadDimensions(int width, int height)
	{
		s_touchpadConfig.currentWidth = width;
		s_touchpadConfig.currentHeight = height;
	}

	// ==========================================================
	// Processing - Touchpad (Internal)
	// ==========================================================

	inline void ProcessTouchpadMouse()
	{
		if (!s_pGamepad || !s_capabilities.hasTouchpad || !s_touchpadConfig.isEnabled)
			return;

		int numTouchpads = SDL_GetNumGamepadTouchpads(s_pGamepad);

		for (int tp = 0; tp < numTouchpads && tp < MAX_TOUCHPADS; tp++)
		{
			int numFingers = SDL_GetNumGamepadTouchpadFingers(s_pGamepad, tp);

			for (int finger = 0; finger < numFingers && finger < MAX_FINGERS; finger++)
			{
				bool fingerDown = false;
				float x = 0.0f, y = 0.0f, pressure = 0.0f;

				if (SDL_GetGamepadTouchpadFinger(s_pGamepad, tp, finger, &fingerDown, &x, &y, &pressure))
				{
					auto& state = s_touchpadFinger[tp][finger];

					if (fingerDown)
					{
						if (state.wasDown)
						{
							float deltaX = (x - state.lastX) * s_touchpadConfig.currentWidth;
							float deltaY = (y - state.lastY) * s_touchpadConfig.currentHeight;

							if (deltaX != 0.0f || deltaY != 0.0f)
							{
								INPUT input = {};
								input.type = INPUT_MOUSE;
								input.mi.dwFlags = MOUSEEVENTF_MOVE;
								input.mi.dx = static_cast<LONG>(deltaX);
								input.mi.dy = static_cast<LONG>(deltaY);
								SendInput(1, &input, sizeof(INPUT));
							}
						}

						state.lastX = x;
						state.lastY = y;
						state.wasDown = true;
					}
					else
					{
						state.wasDown = false;
					}
				}
			}
		}
	}

	inline void ProcessTouchpadClick()
	{
		if (!s_pGamepad || !s_capabilities.hasTouchpad || !s_touchpadConfig.isEnabled)
			return;

		bool isPressed = SDL_GetGamepadButton(s_pGamepad, SDL_GAMEPAD_BUTTON_TOUCHPAD);

		if (isPressed && !s_wasTouchpadPressed[0])
		{
			INPUT input = {};
			input.type = INPUT_MOUSE;
			input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
			SendInput(1, &input, sizeof(INPUT));
		}
		else if (!isPressed && s_wasTouchpadPressed[0])
		{
			INPUT input = {};
			input.type = INPUT_MOUSE;
			input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
			SendInput(1, &input, sizeof(INPUT));
		}

		s_wasTouchpadPressed[0] = isPressed;
	}

	inline void ReleaseTouchpadClick()
	{
		for (int i = 0; i < MAX_TOUCHPADS; i++)
		{
			if (s_wasTouchpadPressed[i])
			{
				INPUT input = {};
				input.type = INPUT_MOUSE;
				input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
				SendInput(1, &input, sizeof(INPUT));
				s_wasTouchpadPressed[i] = false;
			}
		}
	}

	// ==========================================================
	// Event Processing
	// ==========================================================

	inline void OnGamepadConnected(SDL_JoystickID deviceId)
	{
		if (s_pGamepad)
			return;

		s_pGamepad = SDL_OpenGamepad(deviceId);
		if (s_pGamepad)
		{
			LoadGamepadCapabilities(s_pGamepad);
		}
	}

	inline void OnGamepadDisconnected(SDL_JoystickID deviceId)
	{
		if (!s_pGamepad)
			return;

		if (deviceId == SDL_GetGamepadID(s_pGamepad))
		{
			SDL_CloseGamepad(s_pGamepad);
			s_pGamepad = nullptr;
			ReleaseTouchpadClick();
			ResetControllerState();

			// Try to connect to another available gamepad
			int count = 0;
			SDL_JoystickID* gamepads = SDL_GetGamepads(&count);
			if (gamepads)
			{
				for (int i = 0; i < count; i++)
				{
					s_pGamepad = SDL_OpenGamepad(gamepads[i]);
					if (s_pGamepad)
					{
						LoadGamepadCapabilities(s_pGamepad);
						break;
					}
				}

				SDL_free(gamepads);
			}
		}
	}

	inline void ProcessSDLEvents()
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				case SDL_EVENT_GAMEPAD_ADDED:
					OnGamepadConnected(event.gdevice.which);
					break;

				case SDL_EVENT_GAMEPAD_REMOVED:
					OnGamepadDisconnected(event.gdevice.which);
					break;
			}
		}
	}

	// ==========================================================
	// Button Mapping
	// ==========================================================

	struct ButtonMapping
	{
		SDL_GamepadButton sdlButton;
		WORD xinputMask;
	};

	// Buttons that don't change based on controller style
	inline constexpr ButtonMapping s_commonButtons[] =
	{
		{ SDL_GAMEPAD_BUTTON_DPAD_UP,        XINPUT_GAMEPAD_DPAD_UP },
		{ SDL_GAMEPAD_BUTTON_DPAD_DOWN,      XINPUT_GAMEPAD_DPAD_DOWN },
		{ SDL_GAMEPAD_BUTTON_DPAD_LEFT,      XINPUT_GAMEPAD_DPAD_LEFT },
		{ SDL_GAMEPAD_BUTTON_DPAD_RIGHT,     XINPUT_GAMEPAD_DPAD_RIGHT },
		{ SDL_GAMEPAD_BUTTON_START,          XINPUT_GAMEPAD_START },
		{ SDL_GAMEPAD_BUTTON_BACK,           XINPUT_GAMEPAD_BACK },
		{ SDL_GAMEPAD_BUTTON_LEFT_STICK,     XINPUT_GAMEPAD_LEFT_THUMB },
		{ SDL_GAMEPAD_BUTTON_RIGHT_STICK,    XINPUT_GAMEPAD_RIGHT_THUMB },
	};

	// Face buttons for standard layout (Xbox/PlayStation)
	inline constexpr ButtonMapping s_standardFaceButtons[] =
	{
		{ SDL_GAMEPAD_BUTTON_SOUTH, XINPUT_GAMEPAD_A },
		{ SDL_GAMEPAD_BUTTON_EAST,  XINPUT_GAMEPAD_B },
		{ SDL_GAMEPAD_BUTTON_WEST,  XINPUT_GAMEPAD_X },
		{ SDL_GAMEPAD_BUTTON_NORTH, XINPUT_GAMEPAD_Y },
	};

	// Face buttons for Nintendo layout (A/B and X/Y swapped)
	inline constexpr ButtonMapping s_nintendoFaceButtons[] =
	{
		{ SDL_GAMEPAD_BUTTON_EAST,  XINPUT_GAMEPAD_A },
		{ SDL_GAMEPAD_BUTTON_SOUTH, XINPUT_GAMEPAD_B },
		{ SDL_GAMEPAD_BUTTON_NORTH, XINPUT_GAMEPAD_X },
		{ SDL_GAMEPAD_BUTTON_WEST,  XINPUT_GAMEPAD_Y },
	};

	inline constexpr Sint16 TRIGGER_TO_BUTTON_THRESHOLD = 8192;

	// ==========================================================
	// Main Poll Function
	// ==========================================================

	inline DWORD PollController(XINPUT_STATE* pState, bool InvertABXYButtons, bool InvertShoulderTriggers)
	{
		ProcessSDLEvents();

		if (!s_pGamepad || !SDL_GamepadConnected(s_pGamepad))
		{
			return ERROR_DEVICE_NOT_CONNECTED;
		}

		ProcessTouchpadMouse();
		ProcessTouchpadClick();

		// ==========================================================
		// Buttons
		// ==========================================================

		WORD buttons = 0;

		for (const auto& mapping : s_commonButtons)
		{
			if (SDL_GetGamepadButton(s_pGamepad, mapping.sdlButton))
				buttons |= mapping.xinputMask;
		}

		const auto& faceButtons = (s_capabilities.style == GamepadStyle::Nintendo && InvertABXYButtons) ? s_nintendoFaceButtons : s_standardFaceButtons;
		for (const auto& mapping : faceButtons)
		{
			if (SDL_GetGamepadButton(s_pGamepad, mapping.sdlButton))
				buttons |= mapping.xinputMask;
		}

		// ==========================================================
		// Triggers (SDL: 0-32767 -> XInput: 0-255)
		// ==========================================================

		Sint16 leftTrigger = SDL_GetGamepadAxis(s_pGamepad, SDL_GAMEPAD_AXIS_LEFT_TRIGGER);
		Sint16 rightTrigger = SDL_GetGamepadAxis(s_pGamepad, SDL_GAMEPAD_AXIS_RIGHT_TRIGGER);

		bool leftBumper = SDL_GetGamepadButton(s_pGamepad, SDL_GAMEPAD_BUTTON_LEFT_SHOULDER);
		bool rightBumper = SDL_GetGamepadButton(s_pGamepad, SDL_GAMEPAD_BUTTON_RIGHT_SHOULDER);

		if (s_capabilities.style == GamepadStyle::PlayStation && InvertShoulderTriggers)
		{
			if (leftTrigger > TRIGGER_TO_BUTTON_THRESHOLD)
				buttons |= XINPUT_GAMEPAD_LEFT_SHOULDER;
			if (rightTrigger > TRIGGER_TO_BUTTON_THRESHOLD)
				buttons |= XINPUT_GAMEPAD_RIGHT_SHOULDER;

			pState->Gamepad.bLeftTrigger = leftBumper ? 255 : 0;
			pState->Gamepad.bRightTrigger = rightBumper ? 255 : 0;
		}
		else
		{
			if (leftBumper)
				buttons |= XINPUT_GAMEPAD_LEFT_SHOULDER;
			if (rightBumper)
				buttons |= XINPUT_GAMEPAD_RIGHT_SHOULDER;

			pState->Gamepad.bLeftTrigger = static_cast<BYTE>((leftTrigger * 255) / 32767);
			pState->Gamepad.bRightTrigger = static_cast<BYTE>((rightTrigger * 255) / 32767);
		}

		pState->Gamepad.wButtons = buttons;

		// ==========================================================
		// Thumbsticks (SDL Y-axis is inverted compared to XInput)
		// ==========================================================

		auto SafeNegate = [](Sint16 value) -> SHORT
		{
			if (value == -32768)
				return 32767;
			return -value;
		};

		pState->Gamepad.sThumbLX = SDL_GetGamepadAxis(s_pGamepad, SDL_GAMEPAD_AXIS_LEFTX);
		pState->Gamepad.sThumbLY = SafeNegate(SDL_GetGamepadAxis(s_pGamepad, SDL_GAMEPAD_AXIS_LEFTY));
		pState->Gamepad.sThumbRX = SDL_GetGamepadAxis(s_pGamepad, SDL_GAMEPAD_AXIS_RIGHTX);
		pState->Gamepad.sThumbRY = SafeNegate(SDL_GetGamepadAxis(s_pGamepad, SDL_GAMEPAD_AXIS_RIGHTY));

		return ERROR_SUCCESS;
	}

	// ==========================================================
	// Vibration
	// ==========================================================

	inline DWORD SetVibration(XINPUT_VIBRATION* pVibration)
	{
		if (!s_pGamepad || !SDL_GamepadConnected(s_pGamepad))
		{
			return ERROR_DEVICE_NOT_CONNECTED;
		}

		if (!pVibration)
		{
			return ERROR_SUCCESS;
		}

		SDL_RumbleGamepad(s_pGamepad, pVibration->wLeftMotorSpeed, pVibration->wRightMotorSpeed, 100);

		return ERROR_SUCCESS;
	}
};