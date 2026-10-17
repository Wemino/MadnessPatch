<p align="center">
  <img src="assets/MadnessPatch_Logo.png" width="575" />
</p>

<p align="center">
A patch that fixes various issues in the PC port of Alice: Madness Returns.
</p>

## How to Install

> [!NOTE]  
> Compatible with the Steam and EA App versions of Alice: Madness Returns.
>
> **Download**: [MadnessPatch.zip](https://github.com/Wemino/MadnessPatch/releases/latest/download/MadnessPatch.zip)  
> Extract the contents of the zip file into the game's `Win32` folder, which contains the `AliceMadnessReturns.exe` file.
>
> <img src="https://raw.githubusercontent.com/Wemino/MadnessPatch/main/assets/install.png">
>
> Directory path for Steam:  
> `SteamLibrary\steamapps\common\Alice Madness Returns\Binaries\Win32`
>
> Directory path for EA App:  
> `EA\Alice Madness Returns\Game\Alice2\Binaries\Win32`

> [!WARNING]
If the game doesn't start on Windows after installing the patch, try updating the latest Microsoft Visual C++ Redistributable (x86).  
You can download it here: https://aka.ms/vs/17/release/vc_redist.x86.exe

> [!TIP]  
> If you own the remastered version of *American McGee's Alice*, check out [VorpalFix](https://github.com/Wemino/VorpalFix)! 

# Features

## Subtitle Font Scaling

Scales subtitles properly on high-resolution displays. The game was originally designed for consoles and limits subtitle size above 720p, making text harder to read on 1080p or higher. This fix removes that limit so subtitles scale correctly with your resolution.

If you want a different size, you can fine-tune it with `FontScalingFactor` in `MadnessPatch.ini`.

<div align="center">
  <table>
    <tr>
      <td width="50%"><img style="width:100%" src="https://raw.githubusercontent.com/Wemino/MadnessPatch/main/assets/FontScaling_Off.jpg"></td>
      <td width="50%"><img style="width:100%" src="https://raw.githubusercontent.com/Wemino/MadnessPatch/main/assets/FontScaling_On.jpg"></td>
    </tr>
    <tr>
      <td align="center">4K Vanilla</td>
      <td align="center">4K MadnessPatch</td>
    </tr>
  </table>
</div>

## Achievement Support

Adds an in-game achievement overlay that tracks your progress and shows a notification when one is unlocked, using the same achievements as the Xbox 360 and PlayStation 3 versions. Press **HOME**, or **L3 + D-Pad Up** on a controller, to open the list at any time.

The key can be changed with `AchievementOverlayKey` in `MadnessPatch.ini`, using its decimal [virtual-key code](https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes) (36 = HOME).

<div align="center">
  <table>
    <tr>
      <td><img style="width:100%" src="https://raw.githubusercontent.com/Wemino/MadnessPatch/main/assets/AchievementSupport.jpg"></td>
    </tr>
    <tr>
      <td align="center">Achievement List</td>
    </tr>
  </table>
</div>

> **Note**: Achievements that unlock automatically are the ones whose progress is stored in your save data. Any achievement obtained while MadnessPatch isn't running isn't recorded anywhere.

> **Note**: Can be disabled by setting `AchievementSupport = 0` in `MadnessPatch.ini` if wanted.

## High FPS Fixes

Alice's and the enemies' movement, the camera and PhysX objects now behave exactly as they do at 30 FPS at any framerate. Hair and dress physics also stay stable at high framerates, and projectiles like the Pepper Grinder's keep a consistent hitbox.

## Crashes and Infinite Loading Fix

Prevents crashes and infinite loading screens caused by race conditions that occur more frequently at higher framerates during map transitions. It also fixes a crash that can occur when the game runs PhysX in CPU mode instead of on the GPU.

## Save Protection

Writes save files more safely to help prevent corruption, and keeps a backup (`.bak`) of your save just in case.

Disable with `AtomicSaves = 0` in `MadnessPatch.ini`.

## Input Binding Fix

Fixes issues where certain input mappings fail to respond correctly. This particularly affects the umbrella key and other special action bindings that may not register during the input initialization process.

## Stuck Keys Fix

Stops Alice from moving on her own after a loading screen, a streaming hitch or a movie, when a key released during it stayed pressed in the game.

## Force High Resolution Textures

The game normally loads blurry textures first and then sharpens them as you get closer, which was meant for consoles but looks distracting on PC. This patch forces the highest texture resolution from the start and improves texture streaming, so you don't see textures popping into clarity as you move around.

<div align="center">
  <table>
    <tr>
      <td width="50%"><img style="width:100%" src="https://raw.githubusercontent.com/Wemino/MadnessPatch/main/assets/ForceHighResTextures_Off.jpg"></td>
      <td width="50%"><img style="width:100%" src="https://raw.githubusercontent.com/Wemino/MadnessPatch/main/assets/ForceHighResTextures_On.jpg"></td>
    </tr>
    <tr>
      <td align="center">Vanilla</td>
      <td align="center">Force High Res</td>
    </tr>
  </table>
</div>

> **Note**: May increase VRAM usage and impact performance on systems with limited graphics memory.

## Disable Background Level Streaming

Disables the engine's background level streaming during gameplay, which can cause stuttering as levels are loaded in the background while playing. This makes loading screens longer, so they are also sped up to bring them back to about their original length.

Disable with `DisableBackgroundLevelStreaming = 0` in `MadnessPatch.ini`.

## Missing Music Fix

Area music is triggered by in-game scripts, so loading a checkpoint or missing a trigger can leave an area silent. This fixes it so the music still plays.

## Hatter Elevator Fix

Fixes the Chapter 1 softlock where the Hatter elevator's pressure pad stops responding when returning to pick the second section. Saves already affected are repaired when loaded.

## Input Improvements

### SDL Controller Support

Adds support for PlayStation and Nintendo Switch controllers via SDL3.

PlayStation button icons are automatically displayed in the UI when a PlayStation controller is detected.

### Controller Button Icons

Replaces the keyboard and mouse button prompts with matching controller button icons while a controller is connected, using PlayStation or Xbox icons to match your controller. Disconnecting the controller switches the prompts back automatically.

<div align="center">
  <table>
    <tr>
      <td width="50%"><img style="width:100%" src="https://raw.githubusercontent.com/Wemino/MadnessPatch/main/assets/ControllerIcons_PlayStation.jpg"></td>
      <td width="50%"><img style="width:100%" src="https://raw.githubusercontent.com/Wemino/MadnessPatch/main/assets/ControllerIcons_Xbox.jpg"></td>
    </tr>
    <tr>
      <td align="center">PlayStation</td>
      <td align="center">Xbox</td>
    </tr>
  </table>
</div>

Disable with `EnableControllerIcons = 0` in `MadnessPatch.ini`.

### Disable Mouse and Controller Acceleration

Stops the game from ramping up the camera speed when you start moving the mouse or the stick, so it responds more consistently.

Controller acceleration can be kept with `DisableControllerAcceleration = 0` in `MadnessPatch.ini`.

### Disable Mouse Smoothing

Turns off camera smoothing so the view responds instantly to your mouse movements.

Enable with `DisableMouseSmoothing = 1` in `MadnessPatch.ini`.

## Profile Creation Screen

Adds an option to skip the profile creation and selection screen and go straight to the main menu. Useful for controller-only players, as profile names can't be typed with a controller.

> **Note**: A save created while the screen is skipped won't be selectable in it if it's shown again later.

Skip it with `ShowProfileCreation = 0` in `MadnessPatch.ini`.

## Aspect Ratio Fix

Removes pillarboxing and adjusts the field of view for ultrawide monitors, and also removes the letterboxing that appears on 16:10 and narrower aspect ratios during gameplay.

<div align="center">
  <table>
    <tr>
      <td><img style="width:100%" src="https://raw.githubusercontent.com/Wemino/MadnessPatch/main/assets/FixUltraWideScreenFOV_Off.jpg"></td>
    </tr>
    <tr>
      <td align="center">Vanilla 21:9 (Cropped Viewport)</td>
    </tr>
    <tr>
      <td><img style="width:100%" src="https://raw.githubusercontent.com/Wemino/MadnessPatch/main/assets/FixUltraWideScreenFOV_On.jpg"></td>
    </tr>
    <tr>
      <td align="center">MadnessPatch 21:9</td>
    </tr>
  </table>
</div>

## Improved Bink Video

The pre-rendered cutscenes are upscaled with AMD FidelityFX Super Resolution (EASU) instead of a plain bilinear stretch, so they stay sharp above their native resolution, and the banding in dark gradients is smoothed out.

<div align="center">
  <table>
    <tr>
      <td width="50%"><img style="width:100%" src="https://raw.githubusercontent.com/Wemino/MadnessPatch/main/assets/ImprovedBinkVideo_Off.png"></td>
      <td width="50%"><img style="width:100%" src="https://raw.githubusercontent.com/Wemino/MadnessPatch/main/assets/ImprovedBinkVideo_On.png"></td>
    </tr>
    <tr>
      <td align="center">Vanilla</td>
      <td align="center">MadnessPatch</td>
    </tr>
  </table>
</div>

## MSAA Level

The in-game anti-aliasing option only switches between off and 4x MSAA. `ForceMSAA` sets the level instead, to 2x, 4x, 8x or 16x, or turns it off. If the GPU doesn't support the chosen level, the highest level below it is used.

Set `ForceMSAA` in `MadnessPatch.ini` (0 = off, 2, 4, 8 or 16, -1 = use the in-game option).

## MSAA Fog Fix

With anti-aliasing enabled, fog wasn’t working properly around the edges of characters and objects, making them appear to have a bright outline in foggy areas. A thin bright line also appeared along the top and left edges of the screen. Both issues have been fixed, so fog now looks more natural and covers the entire screen.

`FixMSAAFog = 2` is a higher quality mode that's more demanding on the GPU.

<div align="center">
  <table>
    <tr>
      <td width="50%"><img style="width:100%" src="https://raw.githubusercontent.com/Wemino/MadnessPatch/main/assets/FixMSAAFog_Off.png"></td>
      <td width="50%"><img style="width:100%" src="https://raw.githubusercontent.com/Wemino/MadnessPatch/main/assets/FixMSAAFog_On.png"></td>
    </tr>
    <tr>
      <td align="center">Vanilla (MSAA)</td>
      <td align="center">MadnessPatch (MSAA)</td>
    </tr>
  </table>
</div>

Disable with `FixMSAAFog = 0` in `MadnessPatch.ini`.

## Supersampling

Renders the 3D scene at a multiple of the screen resolution and averages it back down, which smooths every edge. For example, `SSAAScale = 2.0` at 1080p renders the scene at 4K.

> **Note**: Very demanding on the GPU. MSAA can usually be turned off when using it.

Set `SSAAScale` in `MadnessPatch.ini` (1.0 = disabled, up to 4.0).

## GPU PhysX Performance

With PhysX on the GPU, the GPU can now draw a frame while the game works on the next one instead of the game waiting for it, which raises the framerate where PhysX is busy. The memory PhysX uses on the GPU is also sized to your graphics card.

## Skip Cutscenes with Enter

Prevents accidental cutscene skips by moving the skip key from Space (jump) to Enter.

Disable with `SkipCutscenesWithEnter = 0` in `MadnessPatch.ini`.

## Framerate Limiter

Allows setting a framerate limit without editing the game's files.

Set `MaxFPS` in `MadnessPatch.ini` (0 = disable, recommended maximum: 120).

## Complete Edition DLC Unlock

Unlocks all Complete Edition costumes, weapons, and adds a menu option to launch the original Alice game without editing the game's files.

## Improved Window Management

Fixes window management to allow standard Windows functionality:
- Close the game using ALT+F4.
- Use the Windows key to access the Start Menu or switch applications at any time. (previously blocked after clicking back into the game window)
- Free mouse cursor when the game loses focus in windowed mode. (cursor is no longer trapped when alt-tabbing or clicking outside the window)

## Audio Device Switching Fix

Upgrades the game's legacy XAudio 2.6 audio system to XAudio 2.9, fixes cases where in-game audio is missing while cutscenes still have sound, and restores audio after switching, disconnecting, or reconnecting the default output device, such as a headset, monitor, or TV.

## Windowed Mode & Borderless Fullscreen

Adds windowed and borderless fullscreen modes.

Enable with `UseWindowed = 1` for windowed mode and `BorderlessFullscreen = 1` for borderless fullscreen in `MadnessPatch.ini`.

## Auto Resolution

Automatically sets the game to your screen resolution on first launch instead of defaulting to 1280×720.

## Force Game Language

Runs the game in a specific language regardless of what the launcher or your system locale selects.

| Value | Language | Value | Language |
| --- | --- | --- | --- |
| `0` | English | `3` | Italian |
| `1` | French | `4` | Spanish |
| `2` | German | `5` | Japanese |

Set `ForceLanguage = 5` in `MadnessPatch.ini` for Japanese. `-1` (the default) keeps the game's own selection.

## Alice 1 Installation Check

The Complete Edition menu adds an option to launch the original *American McGee's Alice*. Two settings control what happens when Alice 1 isn't installed:
- **WarnAlice1InstallFolder**: shows a warning prompt if Alice 1 can't be found in its expected installation directory when you try to launch it.
- **HideAlice1WhenMissing**: removes the Alice 1 entry from the in-game menus entirely when it isn't installed.

Both are enabled by default and can be turned off individually in `MadnessPatch.ini`.

## Developer Console

Enables the game's built-in developer console, bound to the **F2** key.

## Crash Handler

Installs a crash handler that writes a detailed report (`crash_YYYYMMDD.txt`) whenever the game crashes. Each report captures what the game was doing at the moment it failed, which makes problems much easier to track down. If you run into a crash, these reports can be shared to help diagnose the issue and improve the patch in future updates.

Disable with `EnableCrashHandler = 0` in `MadnessPatch.ini`.

## Script Fixes

Fixes bugs in the game's own scripts around the lock-on and the ranged weapons, such as the lock-on staying on a dead enemy or the Pepper Grinder getting stuck after Alice is hit while firing.

## Map Fixes

Fixes mistakes left in several levels, such as cutscenes briefly showing the game camera before the next one and leftover scenery at the end of Chapter 1.

## Additional Fixes

Fixes a few small UI issues, such as a leftover HUD cursor sprite from the first weapon-upgrade popup and an incorrect Pinball Cannon button prompt on PC. Activating Hysteria while locked on to an enemy above 30 FPS no longer makes the camera rotate around Alice, facial animations no longer pile up on characters while they're off screen, and full screen fades reach true black instead of leaving the scene faintly visible, especially at the beginning of Chapter 2.

## Skip Intro Videos

Bypasses intro videos on game launch:
- **SkipEAIntro**: Skips the EA logo video
- **SkipSHIntro**: Skips the Spicy Horse studio logo video  
- **SkipUEIntro**: Skips the Unreal Engine logo video

Each can be toggled individually in `MadnessPatch.ini`.

## Archive Asset Dump

Writes the game's assets into an `archive_dump` folder as they are loaded, using the same paths they have inside the archives.

Enable with `DumpArchiveAssets = 1` in `MadnessPatch.ini`.

## Mod File Loading

Replaces game assets with loose files from `mods\<mod name>`, laid out the same way as the dump.

## Configuration

All features can be customized via the `MadnessPatch.ini` file.

# Credits
- [SDL3](https://www.libsdl.org/) for improved controller support.
- [safetyhook](https://github.com/cursey/safetyhook) for hooking.  
- [mINI](https://github.com/metayeti/mINI) for INI file handling.  
- [CRASHARKI](https://github.com/CRASHARKI) for the logo.