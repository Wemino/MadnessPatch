#pragma once

#include <Windows.h>
#include <wincodec.h>
#include <Xinput.h>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cerrno>
#include <filesystem>
#include <fstream>
#include <mutex>
#include "Common.hpp"
#include "Features.hpp"

namespace AchievementOverlay
{
    // Config
    inline constexpr bool kBlockGameInputWhileVisible = true;
    inline constexpr int kIconTextureSize = 128;

    // State
    inline HWND g_hWnd = nullptr;
    inline WNDPROC g_oWndProc = nullptr;
    inline bool g_wndProcInstalled = false;
    inline bool g_visible = false;

    inline float g_uiScale = 1.0f;
    inline float g_scrollY = 0.0f;
    inline float g_pendingWheelScroll = 0.0f;
    inline unsigned long long g_lastDrawTick = 0;
    inline int g_lastCanvasW = 0;
    inline int g_lastCanvasH = 0;

    inline XINPUT_STATE g_padState{};
    inline bool g_padConnected = false;

    struct ToastItem
    {
        int achvId;
        unsigned long long start;
        float animY;
        bool placed;
    };
    inline std::vector<ToastItem> g_toasts;
    inline std::mutex g_toastMutex;

    // Achievement data
    struct Texture
    {
        class UTexture2D* tex = nullptr;
        int w = 0;
        int h = 0;
    };

    struct AchievementText
    {
        std::wstring name;
        std::wstring desc;
    };

    inline std::vector<Texture> g_achievements;
    inline std::vector<bool> g_unlocked;
    inline std::vector<int> g_current;
    inline std::vector<AchievementText> g_text;

    inline bool g_achievementsLoaded = false;
    inline bool g_textLoaded = false;
    inline bool g_iconsUnavailable = false;
    inline std::string g_language = "en";

    inline std::filesystem::path g_achievementFolder;
    inline std::filesystem::path g_achievementFilePath;
    inline uint64_t g_unlockedBits = 0; // persistent unlock bitflags
    inline std::unordered_map<int, int> g_maxOverride; // runtime max overrides read from the game
    inline std::recursive_mutex g_stateMutex;
    inline bool g_achievementFileLoaded = false;

    inline constexpr int kAchievementCount = 45;
    inline float g_ventDuration = 0.0f; // persisted steam-vent timer
    inline bool g_ventNeedsApply = false; // game-side writes g_ventDuration back into the engine once on load

    inline bool g_showSecrets = false;

    // Secret achievements hidden until unlocked:
    inline constexpr uint64_t kSecretMask = (0x7Full << 1) | (0x7Full << 13) | (1ull << 31) | (1ull << 33) | (1ull << 35);

    inline bool IsSecret(int index)
    {
        return index >= 0 && index < 64 && ((kSecretMask >> index) & 1ull) != 0;
    }

    // Target count per achievement, anything not listed is a plain on/off unlock (max 1)
    inline const std::unordered_map<int, int> kAchievementMax =
    {
        { 19, 4 }, { 20, 4 }, { 21, 16 }, { 22, 34 }, { 23, 94 }, { 34, 10 },
        { 35, 420 }, { 38, 10 }, { 39, 30 }, { 42, 100 }, { 43, 52 },
    };

    inline int AchievementMaxFrom(const std::unordered_map<int, int>& overrides, int index)
    {
        auto ov = overrides.find(index);
        if (ov != overrides.end())
        {
            return ov->second;
        }

        auto it = kAchievementMax.find(index);
        return it != kAchievementMax.end() ? it->second : 1;
    }

    inline int AchievementMax(int index)
    {
        std::lock_guard<std::recursive_mutex> lock(g_stateMutex);
        return AchievementMaxFrom(g_maxOverride, index);
    }

    // Bink cutscenes and loading movies bypass PostRender, the list must not block input while it cannot be drawn
    inline constexpr unsigned long long kRenderStaleMs = 500;
    inline bool IsRendering() { return g_lastDrawTick != 0 && GetTickCount64() - g_lastDrawTick < kRenderStaleMs; }

    inline bool IsVisible() { return g_visible && IsRendering(); }

    inline void SetAchievementUnlocked(int index, bool unlocked)
    {
        if (index < 0) return;

        std::lock_guard<std::recursive_mutex> lock(g_stateMutex);

        if ((int)g_unlocked.size() <= index)
        {
            g_unlocked.resize(index + 1, false);
        }

        g_unlocked[index] = unlocked;
    }

    // Marks the achievement unlocked with no toast or save, used by the save-load sync
    inline bool MarkUnlockedSilent(int achvId)
    {
        if (achvId < 0 || achvId >= 64)
            return false;

        std::lock_guard<std::recursive_mutex> lock(g_stateMutex);

        const uint64_t bit = 1ull << achvId;
        if (g_unlockedBits & bit)
            return false;

        g_unlockedBits |= bit;
        SetAchievementUnlocked(achvId, true);
        return true;
    }

    // Queue an unlock toast
    inline void PushToast(int achvId)
    {
        ToastItem it{};
        it.achvId = achvId;
        it.start = GetTickCount64();

        std::lock_guard<std::mutex> lock(g_toastMutex);
        g_toasts.push_back(it);
    }

    // Persist the unlock flags and steam-vent timer to Achievements.txt
    inline void SaveAchievementBits()
    {
        std::lock_guard<std::recursive_mutex> lock(g_stateMutex);

        if (g_achievementFilePath.empty())
            return;

        const std::wstring realPath = g_achievementFilePath.native();
        const std::wstring tmpPath = realPath + L".tmp";

        {
            std::ofstream f(tmpPath.c_str(), std::ios::trunc | std::ios::binary);
            if (!f)
                return;

            f << "UnlockFlag=" << g_unlockedBits << "\n" << "TotalVentDuration=" << g_ventDuration << "\n";
            f.flush();

            if (!f)
            {
                f.close();
                DeleteFileW(tmpPath.c_str());
                return;
            }
        }

        if (!MoveFileExW(tmpPath.c_str(), realPath.c_str(), MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH))
        {
            DeleteFileW(tmpPath.c_str());
            return;
        }

        g_achievementFileLoaded = true;
    }

    // Index 0 is the platinum, award it once every other trophy is unlocked
    inline void AwardPlatinumIfComplete()
    {
        std::lock_guard<std::recursive_mutex> lock(g_stateMutex);

        if (g_unlockedBits & 1ull)
            return;

        uint64_t allOthers = 0;
        for (int i = 1; i < kAchievementCount; i++)
        {
            allOthers |= (1ull << i);
        }

        if ((g_unlockedBits & allOthers) == allOthers)
        {
            g_unlockedBits |= 1ull;
            SetAchievementUnlocked(0, true);
            PushToast(0);

            SaveAchievementBits();
        }
    }

    inline bool ParseAchievementFile(const std::filesystem::path& path, uint64_t& bitsOut, float& ventOut)
    {
        std::error_code ec;
        if (!std::filesystem::exists(path, ec))
            return false;

        std::ifstream f(path);
        if (!f)
            return false;

        bool found = false;
        uint64_t bits = 0;
        float vent = 0.0f;

        std::string line;
        while (std::getline(f, line))
        {
            const size_t eq = line.find('=');
            if (eq == std::string::npos)
                continue;

            const std::string key = line.substr(0, eq);
            const char* val = line.c_str() + eq + 1;
            if (key == "UnlockFlag")
            {
                errno = 0;
                char* end = nullptr;
                const uint64_t parsed = std::strtoull(val, &end, 10);
                if (end == val || errno == ERANGE)
                    return false;

                bits = parsed;
                found = true;
            }
            else if (key == "TotalVentDuration")
            {
                vent = std::strtof(val, nullptr);
            }
        }

        if (!found)
            return false;

        bitsOut = bits;
        ventOut = (vent >= 0.0f && vent < 1.0e9f) ? vent : 0.0f;
        return true;
    }

    // Point the overlay at a profile's Achievements.txt and load it.
    // Returns true when the file is not there yet, meaning the caller should import from the save
    inline bool InitAchievementFile(const std::filesystem::path& folder)
    {
        std::lock_guard<std::recursive_mutex> lock(g_stateMutex);

        if (folder.empty() || (folder == g_achievementFolder && g_achievementFileLoaded))
            return false;

        g_achievementFolder = folder;
        g_achievementFilePath = folder / L"Achievements.txt";

        std::error_code ec;
        std::filesystem::create_directories(folder, ec);

        uint64_t bits = 0;
        float vent = 0.0f;
        const bool loaded = ParseAchievementFile(g_achievementFilePath, bits, vent);

        g_unlockedBits = bits;
        g_ventDuration = vent;
        g_ventNeedsApply = true; // game-side restores g_ventDuration into the engine on the next tick
        g_achievementFileLoaded = loaded;

        if ((int)g_unlocked.size() < 64)
        {
            g_unlocked.resize(64, false);
        }
        for (int i = 0; i < 64; i++)
        {
            g_unlocked[i] = ((g_unlockedBits >> i) & 1ull) != 0;
        }

        g_current.assign(g_current.size(), 0);
        g_maxOverride.clear();

        if (!loaded)
            return true;

        AwardPlatinumIfComplete(); // a save that already holds every non-platinum trophy
        return false;
    }

    // Marks the achievement unlocked, saves, and shows a toast only if it wasn't already unlocked
    inline bool NotifyUnlock(int achvId)
    {
        if (achvId < 0 || achvId >= 64)
            return false;

        std::lock_guard<std::recursive_mutex> lock(g_stateMutex);

        const uint64_t bit = 1ull << achvId;
        if (g_unlockedBits & bit)
            return false;

        g_unlockedBits |= bit;
        SetAchievementUnlocked(achvId, true);
        PushToast(achvId);
        SaveAchievementBits();

        if (achvId != 0)
        {
            AwardPlatinumIfComplete();
        }

        return true;
    }

    // Persist the current steam-vent timer (called when Alice leaves a vent).
    inline void SaveVentDuration(float seconds)
    {
        std::lock_guard<std::recursive_mutex> lock(g_stateMutex);

        g_ventDuration = seconds;
        SaveAchievementBits();
    }

    // Runtime max for counters whose total is read from the game
    inline void SetAchievementMax(int index, int maxValue)
    {
        if (index < 0) return;

        std::lock_guard<std::recursive_mutex> lock(g_stateMutex);
        g_maxOverride[index] = maxValue;
    }

    // Current progress for an achievement
    inline void SetAchievementProgress(int index, int current)
    {
        if (index < 0) return;

        std::lock_guard<std::recursive_mutex> lock(g_stateMutex);

        if ((int)g_current.size() <= index)
        {
            g_current.resize(index + 1, 0);
        }
        if (current < 0)
        {
            current = 0;
        }

        g_current[index] = current;
    }

    // Clear all unlock/progress state so everything shows as locked again, not called automatically
    inline void ResetProgress()
    {
        std::lock_guard<std::recursive_mutex> lock(g_stateMutex);

        g_unlockedBits = 0;
        g_unlocked.assign(g_unlocked.size(), false);
        g_current.assign(g_current.size(), 0);
    }

    // Reloads achievements\txt\<lang>.txt on the next frame
    inline void SetLanguage(const char* langCode)
    {
        if (!langCode || !langCode[0])
            return;

        g_language = langCode;
        g_textLoaded = false;
    }

    // Helpers
    inline std::wstring Utf8ToWide(const std::string& s)
    {
        if (s.empty()) return {};

        int n = MultiByteToWideChar(CP_UTF8, 0, s.data(), (int)s.size(), nullptr, 0);
        if (n <= 0) return {};

        std::wstring out((size_t)n, L'\0');
        MultiByteToWideChar(CP_UTF8, 0, s.data(), (int)s.size(), out.data(), n);
        return out;
    }

    inline float Clamp(float v, float lo, float hi)
    {
        return v < lo ? lo : (v > hi ? hi : v);
    }

    // Canvas tiles take linear colors and the output is gamma corrected, so 8-bit sRGB values have to be linearized
    inline float SrgbToLinear(uint8_t v)
    {
        float c = v / 255.0f;
        return c <= 0.04045f ? c / 12.92f : powf((c + 0.055f) / 1.055f, 2.4f);
    }

    inline FLinearColor Srgb(uint8_t r, uint8_t g, uint8_t b, float a = 1.0f)
    {
        return FLinearColor(SrgbToLinear(r), SrgbToLinear(g), SrgbToLinear(b), a);
    }

    // Palette (sRGB), converted once at load
    inline const FLinearColor kWindowBg = Srgb(15, 15, 15, 0.94f);
    inline const FLinearColor kTitleBg = Srgb(41, 74, 122, 1.0f);
    inline const FLinearColor kFrameBg = Srgb(41, 74, 122, 0.54f);
    inline const FLinearColor kBarFill = Srgb(66, 150, 250, 1.0f);
    inline const FLinearColor kScrollBg = Srgb(5, 5, 5, 0.53f);
    inline const FLinearColor kScrollGrab = Srgb(79, 79, 79, 1.0f);
    inline const FLinearColor kHiddenBox = Srgb(90, 90, 90, 1.0f);
    inline const FLinearColor kHiddenBoxInner = Srgb(35, 35, 35, 1.0f);
    inline const FLinearColor kLockedTint(0.35f, 0.35f, 0.35f, 1.0f);
    inline const FColor kBorderColor(110, 110, 128, 200);
    inline const FColor kSeparatorColor(110, 110, 128, 128);
    inline const FColor kTextColor(255, 255, 255, 255);
    inline const FColor kTextDimColor(200, 200, 200, 255);
    inline const FColor kTextHintColor(160, 160, 160, 255);
    inline const FColor kGoldColor(255, 214, 102, 255);
    inline const FColor kNameLockedColor(217, 217, 217, 255);

    inline FLinearColor WithAlpha(FLinearColor c, float a)
    {
        c.A = a;
        return c;
    }

    // Icon loading: PNG -> BGRA pixels (WIC) -> engine Texture2D
    inline bool DecodePngToBgra(const char* path, int targetSize, std::vector<uint8_t>& outPixels, int& outW, int& outH)
    {
        static bool s_comInit = false;
        if (!s_comInit)
        {
            HRESULT hr = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);
            if (FAILED(hr) && hr != RPC_E_CHANGED_MODE) return false;
            s_comInit = true;
        }

        wchar_t wpath[MAX_PATH];
        if (MultiByteToWideChar(CP_UTF8, 0, path, -1, wpath, MAX_PATH) == 0)
        {
            return false;
        }

        static IWICImagingFactory* factory = nullptr;
        if (!factory && FAILED(CoCreateInstance(CLSID_WICImagingFactory, nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&factory))))
        {
            return false;
        }

        bool ok = false;
        IWICBitmapDecoder* decoder = nullptr;
        IWICBitmapFrameDecode* frame = nullptr;
        IWICBitmapScaler* scaler = nullptr;
        IWICFormatConverter* conv = nullptr;

        if (SUCCEEDED(factory->CreateDecoderFromFilename(wpath, nullptr, GENERIC_READ, WICDecodeMetadataCacheOnLoad, &decoder)) && SUCCEEDED(decoder->GetFrame(0, &frame)) && SUCCEEDED(factory->CreateFormatConverter(&conv)))
        {
            IWICBitmapSource* src = frame;
            if (targetSize > 0 && SUCCEEDED(factory->CreateBitmapScaler(&scaler)) && SUCCEEDED(scaler->Initialize(frame, targetSize, targetSize, WICBitmapInterpolationModeFant)))
            {
                src = scaler;
            }

            // PF_A8R8G8B8 is stored B,G,R,A in memory, which is exactly WIC's 32bppBGRA
            if (SUCCEEDED(conv->Initialize(src, GUID_WICPixelFormat32bppBGRA, WICBitmapDitherTypeNone, nullptr, 0.0, WICBitmapPaletteTypeCustom)))
            {
                UINT w = 0, h = 0;
                conv->GetSize(&w, &h);
                if (w > 0 && h > 0)
                {
                    outPixels.resize((size_t)w * h * 4);
                    if (SUCCEEDED(conv->CopyPixels(nullptr, w * 4, (UINT)outPixels.size(), outPixels.data())))
                    {
                        outW = (int)w;
                        outH = (int)h;
                        ok = true;
                    }
                }
            }
        }

        if (conv) conv->Release();
        if (scaler) scaler->Release();
        if (frame) frame->Release();
        if (decoder) decoder->Release();
        return ok;
    }

    namespace Native
    {
        inline UFunction* Resolve(UFunction*& cache, bool& searched, const char* fullName)
        {
            if (!searched)
            {
                cache = UFunction::FindFunction(fullName);
                searched = true;
            }
            return cache;
        }

        inline void SetPos(UCanvas* c, float x, float y)
        {
            static UFunction* fn = nullptr;
            static bool searched = false;
            if (!c || !Resolve(fn, searched, "Function Engine.Canvas.SetPos")) return;

            UCanvas_execSetPos_Params p{};
            p.PosX = x;
            p.PosY = y;
            p.PosZ = 1.0f;
            c->ProcessEvent(fn, &p, nullptr);
        }

        inline void DrawTile(UCanvas* c, UTexture* tex, float xl, float yl, float u, float v, float ul, float vl, const FLinearColor& color)
        {
            static UFunction* fn = nullptr;
            static bool searched = false;
            if (!c || !tex || !Resolve(fn, searched, "Function Engine.Canvas.DrawTile")) return;

            UCanvas_execDrawTile_Params p{};
            p.Tex = tex;
            p.XL = xl;
            p.YL = yl;
            p.U = u;
            p.V = v;
            p.UL = ul;
            p.VL = vl;
            p.LColor = color;
            p.ClipTile = 0;
            c->ProcessEvent(fn, &p, nullptr);
        }

        inline void Draw2DLine(UCanvas* c, float x1, float y1, float x2, float y2, const FColor& color)
        {
            static UFunction* fn = nullptr;
            static bool searched = false;
            if (!c || !Resolve(fn, searched, "Function Engine.Canvas.Draw2DLine")) return;

            UCanvas_execDraw2DLine_Params p{};
            p.X1 = x1;
            p.Y1 = y1;
            p.X2 = x2;
            p.Y2 = y2;
            p.LineColor = color;
            c->ProcessEvent(fn, &p, nullptr);
        }

        inline void DrawText(UCanvas* c, const wchar_t* text, float xScale, float yScale, bool shadow)
        {
            static UFunction* fn = nullptr;
            static bool searched = false;
            if (!c || !text || !Resolve(fn, searched, "Function Engine.Canvas.DrawText")) return;

            UCanvas_execDrawTextWin_Params p{};
            p.Text = FString(text);
            p.CR = 0;
            p.XScale = xScale;
            p.YScale = yScale;
            p.RenderInfo.bEnableShadow = shadow ? 1 : 0;
            c->ProcessEvent(fn, &p, nullptr);
        }

        inline void TextSize(UCanvas* c, const wchar_t* text, float& xl, float& yl)
        {
            static UFunction* fn = nullptr;
            static bool searched = false;
            xl = 0.0f;
            yl = 0.0f;
            if (!c || !text || !Resolve(fn, searched, "Function Engine.Canvas.TextSize")) return;

            UCanvas_execTextSize_Params p{};
            p.String = FString(text);
            c->ProcessEvent(fn, &p, nullptr);
            xl = p.XL;
            yl = p.YL;
        }

        inline UTexture2D* Texture2DCreate(int w, int h)
        {
            static UFunction* fn = nullptr;
            static bool searched = false;
            static UObject* cdo = nullptr;
            static bool cdoSearched = false;
            if (!Resolve(fn, searched, "Function Engine.Texture2D.Create")) return nullptr;

            if (!cdoSearched)
            {
                cdoSearched = true;
                UClass* cls = UTexture2D::StaticClass();
                for (UObject* obj : *UObject::GObjObjects())
                {
                    if (obj && obj->Class == cls && obj->IsDefaultObject())
                    {
                        cdo = obj;
                        break;
                    }
                }
            }
            if (!cdo) return nullptr;

            UTexture2D_execCreate_Params p{};
            p.InSizeX = w;
            p.InSizeY = h;
            p.InFormat = static_cast<uint8_t>(EPixelFormat::PF_A8R8G8B8);
            cdo->ProcessEvent(fn, &p, nullptr);
            return p.ReturnValue;
        }

        inline constexpr int kUpdateResourceSlot = 80;

        inline bool UpdateResource(UTexture* tex)
        {
            if (!tex || !tex->VfTableObject.Dummy) return false;

            uintptr_t* vtable = reinterpret_cast<uintptr_t*>(tex->VfTableObject.Dummy);
            uintptr_t target = vtable[kUpdateResourceSlot];

            if (g_State.CodeLo && g_State.CodeHi && (target < g_State.CodeLo || target >= g_State.CodeHi))
                return false;

            using tUpdateResource = void(__thiscall*)(UTexture*);
            reinterpret_cast<tUpdateResource>(target)(tex);
            return true;
        }
    }

    inline UTexture2D* CreateEngineTexture(const std::vector<uint8_t>& bgra, int w, int h)
    {
        if (w <= 0 || h <= 0 || (w & (w - 1)) || (h & (h - 1)))
            return nullptr;

        UTexture2D* tex = Native::Texture2DCreate(w, h);
        if (!tex || tex->SizeX != w || tex->SizeY != h || tex->Format != EPixelFormat::PF_A8R8G8B8 || tex->Mips.ArrayNum < 1 || !tex->Mips.Data.Dummy)
            return nullptr;

        // TIndirectArray stores pointers to its elements
        FTexture2DMipMap* mip = reinterpret_cast<FTexture2DMipMap**>(tex->Mips.Data.Dummy)[0];
        if (!mip || mip->SizeX != w || mip->SizeY != h)
            return nullptr;

        FUntypedBulkData_Mirror& bulk = mip->Data;
        const int expectedBytes = w * h * 4;
        if (bulk.ElementCount != expectedBytes || !bulk.BulkData.Dummy || bulk.LockStatus != 0)
            return nullptr;

        memcpy(reinterpret_cast<void*>(bulk.BulkData.Dummy), bgra.data(), (size_t)expectedBytes);

        tex->ObjectFlags |= RF_RootSet; // keep it alive across level loads
        tex->NeverStream = 1;
        tex->LODGroup = ETextureGroup::TEXTUREGROUP_UI;
        tex->SRGB = 1;

        // Init only allocates the mip, the render resource is created here once the pixels are in
        if (!Native::UpdateResource(tex) || !tex->Resource.Dummy)
            return nullptr;

        return tex;
    }

    inline void LoadAchievements()
    {
        if (g_achievementsLoaded)
            return;

        g_achievementsLoaded = true;

        std::string dir = SystemHelper::GetModulePath() + "\\achievements\\img\\";
        for (int i = 0; ; i++)
        {
            std::string p = dir + std::to_string(i) + ".png";
            if (GetFileAttributesA(p.c_str()) == INVALID_FILE_ATTRIBUTES)
            {
                break;
            }

            Texture t;
            if (!g_iconsUnavailable)
            {
                std::vector<uint8_t> pixels;
                int w = 0, h = 0;
                if (DecodePngToBgra(p.c_str(), kIconTextureSize, pixels, w, h))
                {
                    t.tex = CreateEngineTexture(pixels, w, h);
                    if (t.tex)
                    {
                        t.w = w;
                        t.h = h;
                    }
                    else
                    {
                        g_iconsUnavailable = true;
                    }
                }
            }

            g_achievements.push_back(t);
        }

        {
            std::lock_guard<std::recursive_mutex> lock(g_stateMutex);

            if (g_unlocked.size() < g_achievements.size())
            {
                g_unlocked.resize(g_achievements.size(), false);
            }
            if (g_current.size() < g_achievements.size())
            {
                g_current.resize(g_achievements.size(), 0);
            }
        }
    }

    inline void LoadText()
    {
        if (g_textLoaded) return;

        g_textLoaded = true;
        g_text.clear();

        std::string path = SystemHelper::GetModulePath() + "\\achievements\\txt\\" + g_language + ".txt";

        FILE* f = nullptr;
        if (fopen_s(&f, path.c_str(), "rb") != 0 || !f)
        {
            return;
        }

        fseek(f, 0, SEEK_END);
        long size = ftell(f);
        fseek(f, 0, SEEK_SET);

        std::string buf;
        if (size > 0)
        {
            buf.resize(size);
            fread(&buf[0], 1, size, f);
        }

        fclose(f);

        size_t pos = 0;
        if (buf.size() >= 3 && (unsigned char)buf[0] == 0xEF && (unsigned char)buf[1] == 0xBB && (unsigned char)buf[2] == 0xBF)
        {
            pos = 3; // skip UTF-8 BOM
        }

        while (pos < buf.size())
        {
            size_t eol = buf.find('\n', pos);
            std::string line = (eol == std::string::npos) ? buf.substr(pos) : buf.substr(pos, eol - pos);
            pos = (eol == std::string::npos) ? buf.size() : eol + 1;

            if (!line.empty() && line.back() == '\r')
            {
                line.pop_back();
            }
            if (line.empty())
            {
                continue;
            }

            AchievementText at;
            size_t bar = line.find('|');
            if (bar == std::string::npos)
            {
                at.name = Utf8ToWide(line);
            }
            else
            {
                at.name = Utf8ToWide(line.substr(0, bar));
                at.desc = Utf8ToWide(line.substr(bar + 1));
            }

            g_text.push_back(at);
        }
    }

    struct DrawCtx
    {
        UCanvas* canvas = nullptr;
        UTexture* white = nullptr;
        float whiteU = 1.0f;
        float whiteV = 1.0f;
        float s = 1.0f;

        float fontUnitHeight = 1.0f; // height of one unscaled line in the current font
        float clipTop = -1.0e9f; // manual vertical clipping, UCanvas only clips right/bottom
        float clipBottom = 1.0e9f;
        float coverTop = -1.0e9f;
        float coverBottom = 1.0e9f;
    };

    inline void FillRect(DrawCtx& d, float x, float y, float w, float h, const FLinearColor& color)
    {
        if (!d.white || w <= 0.0f || h <= 0.0f)
            return;

        float y0 = y > d.clipTop ? y : d.clipTop;
        float y1 = (y + h) < d.clipBottom ? (y + h) : d.clipBottom;
        if (y1 <= y0)
            return;

        Native::SetPos(d.canvas, x, y0);
        Native::DrawTile(d.canvas, d.white, w, y1 - y0, 0.0f, 0.0f, d.whiteU, d.whiteV, color);
    }

    inline void OutlineRect(DrawCtx& d, float x, float y, float w, float h, const FColor& color)
    {
        float y0 = y > d.clipTop ? y : d.clipTop;
        float y1 = (y + h) < d.clipBottom ? (y + h) : d.clipBottom;
        if (y1 <= y0)
            return;

        if (y >= d.clipTop) Native::Draw2DLine(d.canvas, x, y, x + w, y, color);
        if (y + h <= d.clipBottom) Native::Draw2DLine(d.canvas, x, y + h, x + w, y + h, color);
        Native::Draw2DLine(d.canvas, x, y0, x, y1, color);
        Native::Draw2DLine(d.canvas, x + w, y0, x + w, y1, color);
    }

    inline void DrawIcon(DrawCtx& d, const Texture& t, float x, float y, float size, const FLinearColor& tint)
    {
        if (!t.tex)
            return;

        float y0 = y > d.clipTop ? y : d.clipTop;
        float y1 = (y + size) < d.clipBottom ? (y + size) : d.clipBottom;
        if (y1 <= y0)
            return;

        // Trim the texture window to match the clipped rows
        float v0 = (y0 - y) / size * (float)t.h;
        float v1 = (y1 - y) / size * (float)t.h;

        Native::SetPos(d.canvas, x, y0);
        Native::DrawTile(d.canvas, t.tex, size, y1 - y0, 0.0f, v0, (float)t.w, v1 - v0, tint);
    }

    inline void MeasureText(DrawCtx& d, const wchar_t* text, float scale, float& outW, float& outH)
    {
        float xl = 0.0f, yl = 0.0f;
        Native::TextSize(d.canvas, text, xl, yl);
        outW = xl * scale;
        outH = yl * scale;
    }

    // Draws one line, either fully inside the vertical window or skipped
    inline void DrawTextLine(DrawCtx& d, const wchar_t* text, float x, float y, float scale, const FColor& color)
    {
        if (!text || !text[0])
            return;

        float lineH = d.fontUnitHeight * scale;
        if (y + lineH <= d.clipTop || y >= d.clipBottom || y < d.coverTop || y + lineH > d.coverBottom)
            return;

        d.canvas->DrawColor = color;
        Native::SetPos(d.canvas, x, y);
        Native::DrawText(d.canvas, text, scale, scale, true);
    }

    // Word-wrap cache, re-measured only when the width, scale, font or text changes
    struct WrappedText
    {
        std::vector<std::wstring> lines;
        float width = -1.0f;
        float scale = -1.0f;
        UFont* font = nullptr;
        std::wstring source;
    };

    inline void WrapText(DrawCtx& d, const std::wstring& text, float maxWidth, float scale, WrappedText& cache)
    {
        if (cache.width == maxWidth && cache.scale == scale && cache.font == d.canvas->Font && cache.source == text)
            return;

        cache.lines.clear();
        cache.source = text;
        cache.font = d.canvas->Font;
        cache.width = maxWidth;
        cache.scale = scale;

        if (text.empty())
            return;

        std::wstring line;
        size_t pos = 0;
        while (pos <= text.size())
        {
            size_t sp = text.find(L' ', pos);
            std::wstring word = (sp == std::wstring::npos) ? text.substr(pos) : text.substr(pos, sp - pos);
            pos = (sp == std::wstring::npos) ? text.size() + 1 : sp + 1;

            if (word.empty())
                continue;

            std::wstring candidate = line.empty() ? word : line + L" " + word;
            float w = 0.0f, h = 0.0f;
            MeasureText(d, candidate.c_str(), scale, w, h);

            if (w <= maxWidth || line.empty())
            {
                line = candidate;
            }
            else
            {
                cache.lines.push_back(line);
                line = word;
            }
        }

        if (!line.empty())
        {
            cache.lines.push_back(line);
        }
    }

    inline constexpr const char* kPreferredFontName = "Font WarfareFonts.Fonts.WarfareFonts_Euro20";

    inline UFont* PickFont()
    {
        static UFont* s_preferred = nullptr;
        static bool s_preferredSearched = false;
        if (!s_preferredSearched)
        {
            s_preferred = UObject::FindObject<UFont>(kPreferredFontName);
            s_preferredSearched = true;
        }
        if (s_preferred)
            return s_preferred;

        UEngine* engine = g_State.AliceEngine;
        if (!engine)
            return nullptr;

        UFont* candidates[] = { engine->SubtitleFont, engine->MediumFont, engine->SmallFont, engine->LargeFont, engine->TinyFont, engine->LoadingTextFont };
        for (UFont* f : candidates)
        {
            if (f) return f;
        }
        return nullptr;
    }

    inline std::unordered_map<UFont*, float> g_fontUnitH;

    inline void UseFont(DrawCtx& d, UFont* f)
    {
        if (!f) return;

        d.canvas->Font = f;
        auto it = g_fontUnitH.find(f);
        if (it == g_fontUnitH.end())
        {
            float w = 0.0f, h = 0.0f;
            MeasureText(d, L"Ag", 1.0f, w, h);
            h = h > 1.0f ? h : 16.0f;
            g_fontUnitH[f] = h;
            d.fontUnitHeight = h;
        }
        else
        {
            d.fontUnitHeight = it->second;
        }
    }

    // Layout state shared between the list and the toasts
    inline std::vector<WrappedText> g_nameWrap;
    inline std::vector<WrappedText> g_descWrap;
    inline std::vector<WrappedText> g_toastNameWrap;
    inline std::vector<WrappedText> g_toastDescWrap;

    inline const std::wstring g_emptyText;
    inline const std::wstring g_hiddenName = L"???";
    inline const std::wstring g_hiddenDesc = L"Hidden achievement";

    inline const std::wstring& NameOf(size_t i) { return i < g_text.size() ? g_text[i].name : g_emptyText; }
    inline const std::wstring& DescOf(size_t i) { return i < g_text.size() ? g_text[i].desc : g_emptyText; }

    // Input
    inline float GetControllerScrollAxis()
    {
        if (!g_padConnected) return 0.0f;

        const short dz = XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE;
        short ly = g_padState.Gamepad.sThumbLY;

        if (ly > dz)
            return (float)(ly - dz) / (float)(32767 - dz);
        if (ly < -dz)
            return (float)(ly + dz) / (float)(32768 - dz);

        return 0.0f;
    }

    inline void Toggle()
    {
        g_visible = !g_visible;
    }

    // Rendering
    inline void DrawAchievementsWindow(DrawCtx& d, float deltaSeconds)
    {
        UCanvas* c = d.canvas;
        const float s = d.s;
        const float dispW = (float)c->SizeX;
        const float dispH = (float)c->SizeY;

        const float maxW = dispW - 40.0f * s;
        const float maxH = dispH - 40.0f * s;
        const float winW = Clamp(dispW * 0.6f, 700.0f * s < maxW ? 700.0f * s : maxW, maxW);
        const float winH = Clamp(dispH * 0.8f, 500.0f * s < maxH ? 500.0f * s : maxH, maxH);
        const float winX = (dispW - winW) * 0.5f;
        const float winY = (dispH - winH) * 0.5f;

        // Pixel sizes at 1080p
        const float pad = 12.0f * s;
        const float titleScale = (26.0f * s) / d.fontUnitHeight;
        const float nameScale = (20.0f * s) / d.fontUnitHeight;
        const float bodyScale = (17.0f * s) / d.fontUnitHeight;
        const float smallScale = (15.0f * s) / d.fontUnitHeight;
        const float titleH = d.fontUnitHeight * titleScale;
        const float bodyH = d.fontUnitHeight * bodyScale;
        const float nameH = d.fontUnitHeight * nameScale;
        const float smallH = d.fontUnitHeight * smallScale;

        // Controller: A toggles secrets
        static bool s_aPrev = false;
        bool aNow = g_padConnected && (g_padState.Gamepad.wButtons & XINPUT_GAMEPAD_A);
        if (aNow && !s_aPrev) g_showSecrets = !g_showSecrets;
        s_aPrev = aNow;

        FillRect(d, winX, winY, winW, winH, kWindowBg);

        // Header and list layout. The bottom strip is at least one name line tall so cut text never leaves the window
        const float titleBarH = titleH + pad;
        const float helpY = winY + titleBarH + pad * 0.5f;
        const float separatorY = helpY + smallH + 8.0f * s;
        const float bottomPad = nameH + 4.0f * s;

        // List region
        const float listTop = separatorY + 6.0f * s;
        const float listBottom = winY + winH - bottomPad;
        const float listH = listBottom - listTop;
        const float scrollbarW = 8.0f * s;
        const float listX = winX + pad;
        const float listW = winW - pad * 2.0f - scrollbarW - 6.0f * s;

        const float iconSize = 64.0f * s;
        const float textX = listX + iconSize + 10.0f * s;
        const float textW = listX + listW - textX;
        const float barH = smallH + 4.0f * s;
        const float rowPad = 8.0f * s;

        std::lock_guard<std::recursive_mutex> lock(g_stateMutex);

        const size_t count = g_achievements.size();
        if (g_nameWrap.size() < count) g_nameWrap.resize(count);
        if (g_descWrap.size() < count) g_descWrap.resize(count);

        // First pass: wrap text and measure row heights
        static std::vector<float> rowH;
        rowH.assign(count, 0.0f);
        float contentH = 0.0f;
        for (size_t i = 0; i < count; i++)
        {
            bool unlocked = (i < g_unlocked.size()) ? g_unlocked[i] : false;
            bool reveal = !IsSecret((int)i) || g_showSecrets || unlocked;

            WrapText(d, reveal ? NameOf(i) : g_hiddenName, textW, nameScale, g_nameWrap[i]);
            WrapText(d, reveal ? DescOf(i) : g_hiddenDesc, textW, bodyScale, g_descWrap[i]);

            float textH = g_nameWrap[i].lines.size() * nameH + g_descWrap[i].lines.size() * bodyH + 4.0f * s + barH;
            rowH[i] = (textH > iconSize ? textH : iconSize) + rowPad * 2.0f;
            contentH += rowH[i];
        }
        // Scrolling
        float maxScroll = contentH - listH;
        if (maxScroll < 0.0f) maxScroll = 0.0f;

        float axis = GetControllerScrollAxis();
        if (axis != 0.0f)
        {
            g_scrollY -= axis * 1500.0f * s * deltaSeconds;
        }
        if (g_padConnected)
        {
            static unsigned long long s_lastDpadTick = 0;
            unsigned long long now = GetTickCount64();
            bool up = (g_padState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP) != 0;
            bool down = (g_padState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN) != 0;
            if ((up || down) && now - s_lastDpadTick > 120)
            {
                g_scrollY += (down ? 1.0f : -1.0f) * 60.0f * s;
                s_lastDpadTick = now;
            }
        }
        g_scrollY += g_pendingWheelScroll * 60.0f * s;
        g_pendingWheelScroll = 0.0f;
        g_scrollY = Clamp(g_scrollY, 0.0f, maxScroll);

        // Second pass: draw rows inside the list window, text may spill into the header and bottom strip
        d.clipTop = listTop;
        d.clipBottom = listBottom;
        d.coverTop = winY;
        d.coverBottom = winY + winH;

        float rowY = listTop - g_scrollY;
        for (size_t i = 0; i < count; i++)
        {
            float h = rowH[i];
            if (rowY + h >= listTop && rowY <= listBottom)
            {
                bool unlocked = (i < g_unlocked.size()) ? g_unlocked[i] : false;
                int maxv = AchievementMaxFrom(g_maxOverride, (int)i);
                int cur = (i < g_current.size()) ? g_current[i] : 0;
                bool reveal = !IsSecret((int)i) || g_showSecrets || unlocked;

                float iy = rowY + rowPad;
                const Texture& t = g_achievements[i];
                if (reveal && t.tex)
                {
                    FLinearColor tint = unlocked ? FLinearColor(1, 1, 1, 1) : kLockedTint;
                    DrawIcon(d, t, listX, iy, iconSize, tint);
                }
                else
                {
                    // Hidden or unavailable icon: placeholder box with a centered "?"
                    FillRect(d, listX, iy, iconSize, iconSize, kHiddenBox);
                    FillRect(d, listX + 1.0f, iy + 1.0f, iconSize - 2.0f, iconSize - 2.0f, kHiddenBoxInner);
                    float qw = 0.0f, qh = 0.0f;
                    MeasureText(d, L"?", nameScale, qw, qh);
                    DrawTextLine(d, L"?", listX + (iconSize - qw) * 0.5f, iy + (iconSize - qh) * 0.5f, nameScale, kTextHintColor);
                }

                float ty = iy;
                FColor nameCol = unlocked ? kGoldColor : kNameLockedColor;
                for (const std::wstring& line : g_nameWrap[i].lines)
                {
                    DrawTextLine(d, line.c_str(), textX, ty, nameScale, nameCol);
                    ty += nameH;
                }
                for (const std::wstring& line : g_descWrap[i].lines)
                {
                    DrawTextLine(d, line.c_str(), textX, ty, bodyScale, kTextDimColor);
                    ty += bodyH;
                }
                ty += 4.0f * s;

                wchar_t overlay[32];
                float barFrac;
                if (!reveal)
                {
                    barFrac = 0.0f;
                    swprintf_s(overlay, L"???");
                }
                else
                {
                    bool hasCounter = maxv > 1;
                    int displayCur = hasCounter ? cur : (unlocked ? 1 : 0);
                    barFrac = maxv > 0 ? (float)displayCur / (float)maxv : (unlocked ? 1.0f : 0.0f);
                    if (barFrac > 1.0f) barFrac = 1.0f;
                    swprintf_s(overlay, L"%d/%d", displayCur, maxv);
                }

                FillRect(d, textX, ty, textW, barH, kFrameBg);
                FillRect(d, textX, ty, textW * barFrac, barH, kBarFill);
                DrawTextLine(d, overlay, textX + 6.0f * s, ty + (barH - smallH) * 0.5f, smallScale, kTextColor);

                float sepY = rowY + h - 1.0f;
                if (sepY >= listTop && sepY <= listBottom)
                {
                    Native::Draw2DLine(c, listX, sepY, listX + listW, sepY, kSeparatorColor);
                }
            }

            rowY += h;
        }

        d.clipTop = -1.0e9f;
        d.clipBottom = 1.0e9f;
        d.coverTop = -1.0e9f;
        d.coverBottom = 1.0e9f;

        // Header and bottom strip, drawn opaque over whatever spilled out of the list
        FillRect(d, winX, winY, winW, titleBarH, kTitleBg);
        FillRect(d, winX, winY + titleBarH, winW, listTop - winY - titleBarH, WithAlpha(kWindowBg, 1.0f));
        FillRect(d, winX, listBottom, winW, bottomPad, WithAlpha(kWindowBg, 1.0f));

        float y = winY + pad * 0.5f;
        DrawTextLine(d, L"Achievements", winX + pad, y, titleScale, kTextColor);

        int unlockedCount = 0;
        for (size_t i = 0; i < g_achievements.size() && i < g_unlocked.size(); i++)
        {
            if (g_unlocked[i]) unlockedCount++;
        }

        wchar_t counter[64];
        swprintf_s(counter, L"%d / %d", unlockedCount, (int)g_achievements.size());
        float cw = 0.0f, ch = 0.0f;
        MeasureText(d, counter, nameScale, cw, ch);
        DrawTextLine(d, counter, winX + winW - pad - cw, y + (titleH - nameH) * 0.5f, nameScale, kGoldColor);

        // Help line
        const wchar_t* help = g_showSecrets
            ? L"[Space / A]  Hide secret achievements      [Wheel / Stick]  Scroll      [Home]  Close"
            : L"[Space / A]  Show secret achievements      [Wheel / Stick]  Scroll      [Home]  Close";
        DrawTextLine(d, help, winX + pad, helpY, smallScale, kTextHintColor);
        Native::Draw2DLine(c, winX + pad, separatorY, winX + winW - pad, separatorY, kSeparatorColor);

        OutlineRect(d, winX, winY, winW, winH, kBorderColor);

        // Scrollbar
        if (maxScroll > 0.0f)
        {
            float trackX = winX + winW - pad - scrollbarW;
            FillRect(d, trackX, listTop, scrollbarW, listH, kScrollBg);

            float thumbH = listH * (listH / contentH);
            if (thumbH < 20.0f * s) thumbH = 20.0f * s;
            float thumbY = listTop + (listH - thumbH) * (g_scrollY / maxScroll);
            FillRect(d, trackX, thumbY, scrollbarW, thumbH, kScrollGrab);
        }
    }

    inline void DrawUnlockToast(DrawCtx& d)
    {
        std::lock_guard<std::mutex> lock(g_toastMutex);

        if (g_toasts.empty()) return;

        const float kSlideMs = 350.0f;
        const float kHoldMs = 5500.0f;
        const float kTotalMs = 6200.0f;

        unsigned long long now = GetTickCount64();

        for (size_t i = 0; i < g_toasts.size(); )
        {
            if ((float)(now - g_toasts[i].start) >= kTotalMs)
            {
                g_toasts.erase(g_toasts.begin() + i);
            }
            else
            {
                i++;
            }
        }

        if (g_toasts.empty()) return;

        UCanvas* c = d.canvas;
        const float s = d.s;
        const float dispW = (float)c->SizeX;

        const float toastW = 420.0f * s;
        const float margin = 20.0f * s;
        const float spacing = 8.0f * s;
        const float pad = 10.0f * s;
        const float iconSize = 64.0f * s;
        const float onX = dispW - toastW - margin;
        const float offX = dispW + 10.0f;

        const float headScale = (18.0f * s) / d.fontUnitHeight;
        const float nameScale = (17.0f * s) / d.fontUnitHeight;
        const float descScale = (15.0f * s) / d.fontUnitHeight;
        const float headH = d.fontUnitHeight * headScale;
        const float nameH = d.fontUnitHeight * nameScale;
        const float descH = d.fontUnitHeight * descScale;

        const float textX = pad + iconSize + 10.0f * s;
        const float textW = toastW - textX - pad;

        if (g_toastNameWrap.size() < g_toasts.size()) g_toastNameWrap.resize(g_toasts.size());
        if (g_toastDescWrap.size() < g_toasts.size()) g_toastDescWrap.resize(g_toasts.size());

        float targetY = margin;
        for (size_t ti = 0; ti < g_toasts.size(); ti++)
        {
            ToastItem& it = g_toasts[ti];
            float t = (float)(now - it.start);

            float x, alpha;
            if (t < kSlideMs)
            {
                float k = t / kSlideMs;
                k = 1.0f - (1.0f - k) * (1.0f - k); // ease-out
                x = offX + (onX - offX) * k;
                alpha = k;
            }
            else if (t < kHoldMs)
            {
                x = onX;
                alpha = 1.0f;
            }
            else
            {
                float k = (t - kHoldMs) / (kTotalMs - kHoldMs);
                x = onX + (offX - onX) * (k * k); // ease-in
                alpha = 1.0f - k;
            }

            // Ease the vertical slot so cards slide up when one above expires
            if (!it.placed)
            {
                it.animY = targetY; it.placed = true;
            }
            else
            {
                it.animY += (targetY - it.animY) * 0.25f;
            }

            int id = it.achvId;
            const std::wstring& name = (id >= 0) ? NameOf((size_t)id) : g_emptyText;
            const std::wstring& desc = (id >= 0) ? DescOf((size_t)id) : g_emptyText;

            WrapText(d, name, textW, nameScale, g_toastNameWrap[ti]);
            WrapText(d, desc, textW, descScale, g_toastDescWrap[ti]);

            float textH = headH + g_toastNameWrap[ti].lines.size() * nameH + g_toastDescWrap[ti].lines.size() * descH;
            float toastH = (textH > iconSize ? textH : iconSize) + pad * 2.0f;

            uint8_t a8 = (uint8_t)(alpha * 255.0f + 0.5f);
            float y = it.animY;

            FillRect(d, x, y, toastW, toastH, WithAlpha(kWindowBg, 0.95f * alpha));
            OutlineRect(d, x, y, toastW, toastH, FColor(110, 110, 128, (uint8_t)(a8 * 200 / 255)));

            if (id >= 0 && id < (int)g_achievements.size() && g_achievements[id].tex)
            {
                DrawIcon(d, g_achievements[id], x + pad, y + pad, iconSize, FLinearColor(1, 1, 1, alpha));
            }

            float ty = y + pad;
            DrawTextLine(d, L"Achievement Unlocked", x + textX, ty, headScale, FColor(255, 214, 102, a8));
            ty += headH;
            for (const std::wstring& line : g_toastNameWrap[ti].lines)
            {
                DrawTextLine(d, line.c_str(), x + textX, ty, nameScale, FColor(255, 255, 255, a8));
                ty += nameH;
            }
            for (const std::wstring& line : g_toastDescWrap[ti].lines)
            {
                DrawTextLine(d, line.c_str(), x + textX, ty, descScale, FColor(200, 200, 200, a8));
                ty += descH;
            }

            targetY += toastH + spacing;
        }
    }

    // Keeps keyboard/mouse away from the game while the list is open and turns the wheel/keys into scrolling
    inline LRESULT CALLBACK WndProc_Hook(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
    {
        if (g_visible && kBlockGameInputWhileVisible && IsRendering())
        {
            switch (msg)
            {
            case WM_MOUSEWHEEL:
                g_pendingWheelScroll -= (float)GET_WHEEL_DELTA_WPARAM(wParam) / (float)WHEEL_DELTA;
                return TRUE;

            case WM_KEYDOWN:
                if (wParam == VK_SPACE) { g_showSecrets = !g_showSecrets; }
                else if (wParam == VK_UP) { g_pendingWheelScroll -= 1.0f; }
                else if (wParam == VK_DOWN) { g_pendingWheelScroll += 1.0f; }
                else if (wParam == VK_PRIOR) { g_pendingWheelScroll -= 8.0f; }
                else if (wParam == VK_NEXT) { g_pendingWheelScroll += 8.0f; }
                return TRUE;

            case WM_SYSKEYDOWN:
                if (wParam == VK_F4) break;
                return TRUE;

            case WM_KEYUP: case WM_SYSKEYUP:
            case WM_LBUTTONUP: case WM_RBUTTONUP: case WM_MBUTTONUP:
                break;

            case WM_MOUSEMOVE:
            case WM_LBUTTONDOWN: case WM_LBUTTONDBLCLK:
            case WM_RBUTTONDOWN: case WM_RBUTTONDBLCLK:
            case WM_MBUTTONDOWN: case WM_MBUTTONDBLCLK:
            case WM_MOUSEHWHEEL:
            case WM_CHAR:
                return TRUE;

            default: break;
            }
        }

        return CallWindowProc(g_oWndProc, hWnd, msg, wParam, lParam);
    }

    inline BOOL CALLBACK FindGameWindowProc(HWND hWnd, LPARAM lParam)
    {
        DWORD pid = 0;
        GetWindowThreadProcessId(hWnd, &pid);
        if (pid != GetCurrentProcessId() || !IsWindowVisible(hWnd) || GetWindow(hWnd, GW_OWNER) != nullptr)
            return TRUE;

        *reinterpret_cast<HWND*>(lParam) = hWnd;
        return FALSE;
    }

    inline void InstallWndProc()
    {
        if (g_wndProcInstalled)
            return;

        HWND hWnd = nullptr;
        EnumWindows(FindGameWindowProc, reinterpret_cast<LPARAM>(&hWnd));
        if (!hWnd)
            return;

        g_hWnd = hWnd;
        g_oWndProc = reinterpret_cast<WNDPROC>(SetWindowLongPtr(g_hWnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&WndProc_Hook)));
        g_wndProcInstalled = g_oWndProc != nullptr;
    }

    // Public API
    inline void FeedControllerState(const XINPUT_STATE& state, bool connected)
    {
        g_padState = state;
        g_padConnected = connected;
    }

    inline bool WantCaptureController()
    {
        return kBlockGameInputWhileVisible && g_visible && IsRendering();
    }

    // Called from the GameViewportClient.PostRender hook, after the HUD and the Scaleform movies
    inline void OnPostRender(UCanvas* canvas)
    {
        if (!canvas || canvas->SizeX <= 0 || canvas->SizeY <= 0)
            return;

        InstallWndProc();
        LoadAchievements();
        LoadText();

        unsigned long long now = GetTickCount64();
        float deltaSeconds = g_lastDrawTick ? (float)(now - g_lastDrawTick) / 1000.0f : 0.0f;
        if (deltaSeconds > 0.1f) deltaSeconds = 0.1f;
        g_lastDrawTick = now;

        // Canvas fonts scale with the viewport height, cached measurements are stale after a resolution change
        if (canvas->SizeX != g_lastCanvasW || canvas->SizeY != g_lastCanvasH)
        {
            g_lastCanvasW = canvas->SizeX;
            g_lastCanvasH = canvas->SizeY;
            g_fontUnitH.clear();
            g_nameWrap.clear();
            g_descWrap.clear();
            g_toastNameWrap.clear();
            g_toastDescWrap.clear();
        }

        if (!g_visible && g_toasts.empty())
            return;

        UFont* font = PickFont();
        if (!font)
            return;

        g_uiScale = canvas->SizeY > 1080 ? (float)canvas->SizeY / 1080.0f : 1.0f; // scale up above 1080p only

        DrawCtx d;
        d.canvas = canvas;
        d.s = g_uiScale;
        d.white = canvas->DefaultTexture;
        if (canvas->DefaultTexture)
        {
            d.whiteU = (float)canvas->DefaultTexture->SizeX;
            d.whiteV = (float)canvas->DefaultTexture->SizeY;
        }

        // Save the canvas state we touch and reset it for full-viewport drawing
        UFont* prevFont = canvas->Font;
        FColor prevColor = canvas->DrawColor;
        float prevOrgX = canvas->OrgX, prevOrgY = canvas->OrgY, prevClipX = canvas->ClipX, prevClipY = canvas->ClipY;

        // DrawText wraps at ClipX, push the clip out since the wrapping is done here
        canvas->OrgX = 0.0f;
        canvas->OrgY = 0.0f;
        canvas->ClipX = (float)canvas->SizeX * 4.0f;
        canvas->ClipY = (float)canvas->SizeY * 4.0f;

        UseFont(d, font);

        if (g_visible)
        {
            DrawAchievementsWindow(d, deltaSeconds);
        }

        DrawUnlockToast(d);

        canvas->Font = prevFont;
        canvas->DrawColor = prevColor;
        canvas->OrgX = prevOrgX;
        canvas->OrgY = prevOrgY;
        canvas->ClipX = prevClipX;
        canvas->ClipY = prevClipY;
    }

    // Called every engine tick from the main loop hook
    inline void Update()
    {
        // A cutscene or loading movie stopped PostRender while the list was open, close it so it does not come back over gameplay
        if (g_visible && !IsRendering())
        {
            g_visible = false;
        }

        if (GetAsyncKeyState(VK_HOME) & 1)
        {
            Toggle();
        }
    }
}