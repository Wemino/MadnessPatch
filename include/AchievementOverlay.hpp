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
#include <cwctype>
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

    inline FLinearColor WithAlpha(FLinearColor c, float a)
    {
        c.A = a;
        return c;
    }

    // WithAlpha replaces the alpha, Faded scales it
    inline FColor Faded(FColor c, float a)
    {
        c.A = (uint8_t)(Clamp(a, 0.0f, 1.0f) * c.A + 0.5f);
        return c;
    }

    inline FLinearColor Faded(FLinearColor c, float a)
    {
        c.A *= Clamp(a, 0.0f, 1.0f);
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

    inline UTexture2D* CreateEngineTexture(const std::vector<uint8_t>& bgra, int w, int h, bool clampX = false, bool clampY = false)
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

        // Shapes clamp so their edges do not pick up the opposite side, the chessboard wraps to tile
        tex->AddressX = clampX ? ETextureAddress::TA_Clamp : ETextureAddress::TA_Wrap;
        tex->AddressY = clampY ? ETextureAddress::TA_Clamp : ETextureAddress::TA_Wrap;

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

    namespace Shapes
    {
        enum Id
        {
            Soft,       // radial falloff: shadows, glows, gradients and faded rule ends
            Spear,      // right end of a spear rule: a lozenge and a barbed tip on a 1px line (row 8)
            Corner,     // filigree for the top-left corner of a frame, mirrored for the others
            Checker,    // two columns of chessboard squares fading out downwards, tiled sideways
            Spindle,    // slider handle with a black dot in the middle
            BadgeRim,   // the three layers of a diamond badge
            BadgeFace,
            BadgeCore,
            Pip,        // footer separators, scrollbar ends
            Count
        };

        // Size, address modes and the texel the shape is centered on. A texel center lands on a pixel center at 1080p
        struct Spec
        {
            int w, h;
            bool clampX, clampY;
            float ax, ay;
        };

        inline constexpr Spec kSpec[Count] =
        {
            { 64, 64, true, true, 32.0f, 32.0f },   // Soft
            { 64, 16, true, true, 0.0f, 8.5f },     // Spear
            { 64, 64, true, true, 8.5f, 8.5f },     // Corner
            { 64, 256, false, true, 0.0f, 0.0f },   // Checker
            { 16, 32, true, true, 8.5f, 16.5f },    // Spindle
            { 32, 32, true, true, 16.5f, 16.5f },   // BadgeRim
            { 32, 32, true, true, 16.5f, 16.5f },   // BadgeFace
            { 32, 32, true, true, 16.5f, 16.5f },   // BadgeCore
            { 16, 16, true, true, 8.5f, 8.5f },     // Pip
        };

        inline Texture g_tex[Count];
        inline bool g_built = false;

        inline const Texture& Get(Id id) { return g_tex[id]; }

        inline bool InDiamond(int id, float x, float y, float halfW, float halfH)
        {
            return fabsf(x - kSpec[id].ax) / halfW + fabsf(y - kSpec[id].ay) / halfH <= 1.0f;
        }

        // Hard-edged shapes, in texels
        inline bool Inside(int id, float x, float y)
        {
            constexpr float kCorner = 8.5f;

            switch (id)
            {
                case Spindle: return InDiamond(id, x, y, 3.8f, 8.9f);
                case BadgeRim: return InDiamond(id, x, y, 8.9f, 8.9f);
                case BadgeFace: return InDiamond(id, x, y, 6.8f, 6.8f);
                case BadgeCore: return InDiamond(id, x, y, 4.1f, 4.1f);
                case Pip: return InDiamond(id, x, y, 3.3f, 3.3f);

                case Spear:
                {
                    const float dy = fabsf(y - 8.5f);
                    if (y >= 8.0f && y <= 9.0f && x <= 62.0f) return true; // line
                    if (fabsf(x - 30.0f) / 9.0f + dy / 2.6f <= 1.0f) return true; // lozenge
                    return x <= 63.0f && dy <= 4.5f * (63.0f - x) / 14.0f && x >= 53.0f - 4.0f * dy / 4.5f; // barbed tip
                }

                case Corner:
                {
                    // Diamond on the corner point, slim lozenge pointing into the panel along the diagonal
                    if (fabsf(x - kCorner) + fabsf(y - kCorner) <= 5.0f) return true;
                    const float u = ((x - kCorner - 5.0f) + (y - kCorner - 5.0f)) * 0.70710678f / 19.8f;
                    const float dist = fabsf(x - y) * 0.70710678f;
                    return u >= 0.0f && u <= 1.0f && dist <= 2.1f * (1.0f - fabsf(2.0f * u - 1.0f));
                }

                default: return false;
            }
        }

        // Tapered segment, the filigree is drawn from its distance field
        struct Seg
        {
            float x0, y0, x1, y1;
            float w0, w1;
        };

        inline void AddSpiral(std::vector<Seg>& v, float cx, float cy, float r0, float r1, float a0, float a1, float w0, float w1)
        {
            constexpr int kSteps = 72;

            float px = cx + r0 * cosf(a0), py = cy + r0 * sinf(a0);
            for (int i = 1; i <= kSteps; i++)
            {
                const float t = (float)i / kSteps;
                const float a = a0 + (a1 - a0) * t;
                const float r = r0 + (r1 - r0) * t;
                const float nx = cx + r * cosf(a), ny = cy + r * sinf(a);
                v.push_back({ px, py, nx, ny, w0 + (w1 - w0) * (t - 1.0f / kSteps), w0 + (w1 - w0) * t });
                px = nx;
                py = ny;
            }
        }

        inline float StrokeCoverage(const std::vector<Seg>& segs, float x, float y)
        {
            float best = 1.0e9f;
            for (const Seg& sg : segs)
            {
                const float ax = sg.x1 - sg.x0, ay = sg.y1 - sg.y0;
                const float t = Clamp(((x - sg.x0) * ax + (y - sg.y0) * ay) / (ax * ax + ay * ay + 1.0e-6f), 0.0f, 1.0f);
                const float dx = x - (sg.x0 + ax * t), dy = y - (sg.y0 + ay * t);
                const float dist = sqrtf(dx * dx + dy * dy) - (sg.w0 + (sg.w1 - sg.w0) * t) * 0.5f;
                if (dist < best) best = dist;
            }
            return Clamp(0.5f - best, 0.0f, 1.0f);
        }

        // Arms along both edges from the corner point, each rolling into a curl
        inline std::vector<Seg> CornerStrokes()
        {
            constexpr float kCorner = 8.5f;
            constexpr float kPi = 3.14159265f;

            std::vector<Seg> v;
            v.push_back({ kCorner + 5.0f, kCorner, kCorner + 30.0f, kCorner, 1.9f, 1.3f });
            AddSpiral(v, kCorner + 30.0f, kCorner + 5.5f, 5.5f, 1.3f, -kPi * 0.5f, kPi * 1.7f, 1.3f, 0.8f);
            v.push_back({ kCorner, kCorner + 5.0f, kCorner, kCorner + 30.0f, 1.9f, 1.3f });
            AddSpiral(v, kCorner + 5.5f, kCorner + 30.0f, 5.5f, 1.3f, kPi, -kPi * 1.2f, 1.3f, 0.8f);
            return v;
        }

        inline void Build()
        {
            if (g_built)
                return;

            g_built = true;

            const std::vector<Seg> corner = CornerStrokes();

            for (int id = 0; id < Count; id++)
            {
                const int w = kSpec[id].w, h = kSpec[id].h;
                std::vector<uint8_t> px((size_t)w * h * 4);

                for (int y = 0; y < h; y++)
                {
                    for (int x = 0; x < w; x++)
                    {
                        float a = 0.0f;
                        float dark = 0.0f; // the spindle's dot is baked in black

                        if (id == Soft)
                        {
                            const float dx = (x + 0.5f - w * 0.5f) / (w * 0.5f);
                            const float dy = (y + 0.5f - h * 0.5f) / (h * 0.5f);
                            a = Clamp(1.0f - sqrtf(dx * dx + dy * dy), 0.0f, 1.0f);
                            a = a * a * (3.0f - 2.0f * a);
                        }
                        else if (id == Checker)
                        {
                            // 32 texel squares, strongest at the top
                            const bool on = (((x / 32) + (y / 32)) & 1) == 0;
                            a = on ? powf(1.0f - (y + 0.5f) / h, 1.6f) : 0.0f;
                        }
                        else
                        {
                            // 8x8 supersampling
                            int hits = 0, dots = 0;
                            for (int sy = 0; sy < 8; sy++)
                            {
                                for (int sx = 0; sx < 8; sx++)
                                {
                                    const float fx = x + (sx + 0.5f) / 8.0f, fy = y + (sy + 0.5f) / 8.0f;
                                    if (Inside(id, fx, fy)) hits++;

                                    const float dx = fx - kSpec[id].ax, dy = fy - kSpec[id].ay;
                                    if (id == Spindle && dx * dx + dy * dy <= 1.45f * 1.45f) dots++;
                                }
                            }
                            a = hits / 64.0f;
                            dark = dots / 64.0f;

                            if (id == Corner)
                            {
                                const float stroke = StrokeCoverage(corner, x + 0.5f, y + 0.5f);
                                if (stroke > a) a = stroke;
                            }
                        }

                        uint8_t* o = &px[((size_t)y * w + x) * 4];
                        o[0] = o[1] = o[2] = (uint8_t)(255.0f * (1.0f - dark) + 0.5f);
                        o[3] = (uint8_t)(a * 255.0f + 0.5f);
                    }
                }

                if (UTexture2D* tex = CreateEngineTexture(px, w, h, kSpec[id].clampX, kSpec[id].clampY))
                {
                    g_tex[id].tex = tex;
                    g_tex[id].w = w;
                    g_tex[id].h = h;
                }
            }
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
        float clipTop = -1.0e9f; // manual clipping, UCanvas only clips right/bottom
        float clipBottom = 1.0e9f;
        float clipLeft = -1.0e9f;
        float clipRight = 1.0e9f;
        float coverTop = -1.0e9f;
        float coverBottom = 1.0e9f;
    };

    inline void FillRect(DrawCtx& d, float x, float y, float w, float h, const FLinearColor& color)
    {
        if (!d.white || w <= 0.0f || h <= 0.0f)
            return;

        float y0 = y > d.clipTop ? y : d.clipTop;
        float y1 = (y + h) < d.clipBottom ? (y + h) : d.clipBottom;
        float x0 = x > d.clipLeft ? x : d.clipLeft;
        float x1 = (x + w) < d.clipRight ? (x + w) : d.clipRight;
        if (y1 <= y0 || x1 <= x0)
            return;

        Native::SetPos(d.canvas, x0, y0);
        Native::DrawTile(d.canvas, d.white, x1 - x0, y1 - y0, 0.0f, 0.0f, d.whiteU, d.whiteV, color);
    }

    // Draws a texture region (in texels) trimmed to the clip window, a negative ul/vl mirrors it
    inline void DrawTex(DrawCtx& d, const Texture& t, float x, float y, float w, float h, float u, float v, float ul, float vl, const FLinearColor& color)
    {
        if (!t.tex || w <= 0.0f || h <= 0.0f || color.A <= 0.0f)
            return;

        float y0 = y > d.clipTop ? y : d.clipTop;
        float y1 = (y + h) < d.clipBottom ? (y + h) : d.clipBottom;
        float x0 = x > d.clipLeft ? x : d.clipLeft;
        float x1 = (x + w) < d.clipRight ? (x + w) : d.clipRight;
        if (y1 <= y0 || x1 <= x0)
            return;

        // Trim the texture window to match the clipped area
        const float v0 = v + (y0 - y) / h * vl;
        const float v1 = v + (y1 - y) / h * vl;
        const bool trimX = x0 != x || x1 != x + w;
        const float u0 = trimX ? u + (x0 - x) / w * ul : u;
        const float u1 = trimX ? u + (x1 - x) / w * ul : u + ul;

        Native::SetPos(d.canvas, x0, y0);
        Native::DrawTile(d.canvas, t.tex, x1 - x0, y1 - y0, u0, v0, u1 - u0, v1 - v0, color);
    }

    inline void DrawTex(DrawCtx& d, const Texture& t, float x, float y, float w, float h, const FLinearColor& color)
    {
        DrawTex(d, t, x, y, w, h, 0.0f, 0.0f, (float)t.w, (float)t.h, color);
    }

    inline void DrawIcon(DrawCtx& d, const Texture& t, float x, float y, float size, const FLinearColor& tint)
    {
        DrawTex(d, t, x, y, size, size, tint);
    }

    // Soft edged box: quarter dots in the corners and the dot's middle row/column stretched along the sides
    inline void DrawSoftBox(DrawCtx& d, float x, float y, float w, float h, float r, const FLinearColor& color)
    {
        const Texture& t = Shapes::Get(Shapes::Soft);
        if (!t.tex || color.A <= 0.0f)
            return;

        const float half = t.w * 0.5f;
        const float mid = half - 0.5f;

        DrawTex(d, t, x - r, y - r, r, r, 0.0f, 0.0f, half, half, color);
        DrawTex(d, t, x + w, y - r, r, r, half, 0.0f, half, half, color);
        DrawTex(d, t, x - r, y + h, r, r, 0.0f, half, half, half, color);
        DrawTex(d, t, x + w, y + h, r, r, half, half, half, half, color);

        DrawTex(d, t, x, y - r, w, r, mid, 0.0f, 1.0f, half, color);
        DrawTex(d, t, x, y + h, w, r, mid, half, 1.0f, half, color);
        DrawTex(d, t, x - r, y, r, h, 0.0f, mid, half, 1.0f, color);
        DrawTex(d, t, x + w, y, r, h, half, mid, half, 1.0f, color);

        FillRect(d, x, y, w, h, color);
    }

    // Rule whose ends fade out over 'fade' pixels, snapped to whole pixels so every row gets the same weight
    inline void DrawFadedRule(DrawCtx& d, float x, float y, float w, float thickness, float fade, const FLinearColor& color)
    {
        const float top = floorf(y);
        const float th = thickness > 1.0f ? floorf(thickness + 0.5f) : 1.0f;
        if (fade * 2.0f > w) fade = w * 0.5f;

        // Each end is one row of the soft dot, from its rim to its center
        const Texture& t = Shapes::Get(Shapes::Soft);
        const float half = t.w * 0.5f;
        const float row = t.h * 0.5f - 0.5f;
        DrawTex(d, t, x, top, fade, th, 0.0f, row, half, 1.0f, color);
        FillRect(d, x + fade, top, w - fade * 2.0f, th, color);
        DrawTex(d, t, x + w - fade, top, fade, th, half, row, half, 1.0f, color);
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
        if (!text || !text[0] || color.A == 0)
            return;

        float lineH = d.fontUnitHeight * scale;
        if (y + lineH <= d.clipTop || y >= d.clipBottom || y < d.coverTop || y + lineH > d.coverBottom)
            return;

        // Whole pixels keep the glyphs sharp
        d.canvas->DrawColor = color;
        Native::SetPos(d.canvas, floorf(x + 0.5f), floorf(y + 0.5f));
        Native::DrawText(d.canvas, text, scale, scale, false);
    }

    inline float TextWidth(DrawCtx& d, const wchar_t* text, float scale)
    {
        float w = 0.0f, h = 0.0f;
        MeasureText(d, text, scale, w, h);
        return w;
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

    // Palette (sRGB), converted once at load
    inline const FLinearColor kPanel = Srgb(14, 11, 12);
    inline const FLinearColor kGlow = Srgb(110, 16, 22, 0.30f);
    inline const FLinearColor kChecker = Srgb(200, 186, 160, 0.045f);
    inline const FLinearColor kShade = Srgb(0, 0, 0, 0.55f);
    inline const FLinearColor kBoneLine = Srgb(200, 186, 160, 0.42f);
    inline const FLinearColor kOrnament = Srgb(200, 186, 160, 0.85f);
    inline const FLinearColor kRowRule = Srgb(200, 186, 160, 0.13f);
    inline const FLinearColor kTrack = Srgb(200, 186, 160, 0.22f);
    inline const FLinearColor kRed = Srgb(158, 22, 28);
    inline const FLinearColor kBadgeFace = Srgb(5, 4, 4);
    inline const FLinearColor kBackdrop = Srgb(4, 3, 3, 0.6f);
    inline const FLinearColor kLockedTint(0.32f, 0.32f, 0.32f, 1.0f);
    inline const FLinearColor kWhite(1.0f, 1.0f, 1.0f, 1.0f);
    inline const FLinearColor kBlack(0.0f, 0.0f, 0.0f, 1.0f);
    inline const FColor kTitleColor(228, 216, 192);
    inline const FColor kRedTextColor(186, 40, 44);
    inline const FColor kNameColor(228, 216, 192);
    inline const FColor kNameLockedColor(128, 120, 110);
    inline const FColor kDescColor(160, 150, 136);
    inline const FColor kDescLockedColor(100, 94, 88);
    inline const FColor kTextHintColor(130, 122, 112);
    inline const FColor kTextMutedColor(110, 102, 94);

    // Lines built from rectangles so they follow the clip like everything else
    inline void HLine(DrawCtx& d, float x, float y, float w, float t, const FLinearColor& c) { FillRect(d, floorf(x), floorf(y), floorf(w), t, c); }
    inline void VLine(DrawCtx& d, float x, float y, float h, float t, const FLinearColor& c) { FillRect(d, floorf(x), floorf(y), t, floorf(h), c); }

    inline void FrameRect(DrawCtx& d, float x, float y, float w, float h, float t, const FLinearColor& c)
    {
        HLine(d, x, y, w, t, c);
        HLine(d, x, y + h - t, w, t, c);
        VLine(d, x, y + t, h - t * 2.0f, t, c);
        VLine(d, x + w - t, y + t, h - t * 2.0f, t, c);
    }

    // Centered on (cx, cy). Give it a pixel center so it maps texel for pixel at 1080p
    inline void DrawShape(DrawCtx& d, Shapes::Id id, float cx, float cy, const FLinearColor& c)
    {
        const Texture& t = Shapes::Get(id);
        const Shapes::Spec& spec = Shapes::kSpec[id];
        DrawTex(d, t, cx - spec.ax * d.s, cy - spec.ay * d.s, t.w * d.s, t.h * d.s, c);
    }

    // Darkens the inside of a rectangle along its edges, from the soft dot's rim-to-center rows and columns
    inline void DrawInnerShade(DrawCtx& d, float x, float y, float w, float h, float r, const FLinearColor& c)
    {
        const Texture& t = Shapes::Get(Shapes::Soft);
        if (!t.tex || c.A <= 0.0f)
            return;

        const float half = t.w * 0.5f, mid = half - 0.5f;
        DrawTex(d, t, x, y, w, r, mid, half, 1.0f, half, c);
        DrawTex(d, t, x, y + h - r, w, r, mid, 0.0f, 1.0f, half, c);
        DrawTex(d, t, x, y, r, h, half, mid, half, 1.0f, c);
        DrawTex(d, t, x + w - r, y, r, h, 0.0f, mid, half, 1.0f, c);
    }

    // Eight rows of squares fading out downwards, a square corner on the center line
    inline void DrawChecker(DrawCtx& d, float x, float y, float w, float cell, const FLinearColor& c)
    {
        const Texture& t = Shapes::Get(Shapes::Checker);
        if (!t.tex || c.A <= 0.0f || cell <= 0.0f)
            return;

        const float ul = w / cell * 32.0f;
        DrawTex(d, t, x, y, w, cell * 8.0f, 64.0f - fmodf(ul * 0.5f, 64.0f), 0.0f, ul, 256.0f, c);
    }

    // Baseline as a fraction of the line height, to put two text sizes on one baseline
    inline constexpr float kBaseline = 0.76f;

    // Letter-spaced small capitals: each word's first letter at full size, the rest smaller. Returns the width
    inline float DrawSmallCaps(DrawCtx& d, const wchar_t* text, float x, float y, float scale, float ratio, float tracking, const FColor& color, bool centered = false)
    {
        struct Glyph
        {
            wchar_t ch;
            float scale;
            float w;
        };

        Glyph glyphs[96];
        size_t n = 0;
        bool wordStart = true;
        for (const wchar_t* p = text; *p && n < 96; p++)
        {
            if (*p == L' ')
            {
                glyphs[n++] = { L' ', scale * ratio, 0.0f };
                wordStart = true;
                continue;
            }

            glyphs[n++] = { (wchar_t)towupper(*p), wordStart ? scale : scale * ratio, 0.0f };
            wordStart = false;
        }

        float total = 0.0f;
        for (size_t i = 0; i < n; i++)
        {
            const wchar_t ch[2] = { glyphs[i].ch, 0 };
            glyphs[i].w = TextWidth(d, ch, glyphs[i].scale);
            total += glyphs[i].w;
        }
        if (n > 1) total += tracking * (float)(n - 1);

        float cx = centered ? x - total * 0.5f : x;
        for (size_t i = 0; i < n; i++)
        {
            if (glyphs[i].ch != L' ')
            {
                const wchar_t ch[2] = { glyphs[i].ch, 0 };
                DrawTextLine(d, ch, cx, y + kBaseline * d.fontUnitHeight * (scale - glyphs[i].scale), glyphs[i].scale, color);
            }
            cx += glyphs[i].w + tracking;
        }
        return total;
    }

    // Hairline ending in a lozenge and a barbed tip, y is the line's pixel row
    inline void DrawSpearRule(DrawCtx& d, float x, float y, float w, const FLinearColor& c, bool leftTip = true, bool rightTip = true)
    {
        const float s = d.s;
        const float row = floorf(y);
        const float t = floorf(s + 0.5f);
        x = floorf(x);
        w = floorf(w);

        const Texture& spear = Shapes::Get(Shapes::Spear);
        const float pw = 64.0f * s, ph = 16.0f * s;
        if (!spear.tex || w < pw * ((leftTip ? 1.0f : 0.0f) + (rightTip ? 1.0f : 0.0f)) + 2.0f)
        {
            HLine(d, x, row, w, t, c);
            return;
        }

        const float py = row + t * 0.5f - 8.5f * s; // texel row 8 on the line
        float l = x, r = x + w;
        if (leftTip)
        {
            DrawTex(d, spear, x, py, pw, ph, 64.0f, 0.0f, -64.0f, 16.0f, c);
            l += pw;
        }
        if (rightTip)
        {
            DrawTex(d, spear, x + w - pw, py, pw, ph, 0.0f, 0.0f, 64.0f, 16.0f, c);
            r -= pw;
        }
        HLine(d, l, row, r - l, t, c);
    }

    // Just the barbed tip, its point at x
    inline void DrawSpearTip(DrawCtx& d, float x, float y, bool pointRight, const FLinearColor& c)
    {
        const float s = d.s;
        const float row = floorf(y);
        const float t = floorf(s + 0.5f);
        const float py = row + t * 0.5f - 8.5f * s;
        const float tw = 16.0f * s;

        const Texture& spear = Shapes::Get(Shapes::Spear);
        if (pointRight) DrawTex(d, spear, x - tw, py, tw, 16.0f * s, 48.0f, 0.0f, 16.0f, 16.0f, c);
        else DrawTex(d, spear, x, py, tw, 16.0f * s, 64.0f, 0.0f, -16.0f, 16.0f, c);
    }

    // Hairline frame with filigree corners, k scales the corners
    inline void DrawFiligreeFrame(DrawCtx& d, float x, float y, float w, float h, float k, const FLinearColor& line, const FLinearColor& ornament)
    {
        const float s = d.s;
        const float t = floorf(s + 0.5f);
        x = floorf(x);
        y = floorf(y);
        w = floorf(w);
        h = floorf(h);

        // The lines carry on from the curls at the end of the corner arms
        const float arm = floorf(30.0f * s * k);
        HLine(d, x + arm, y, w - arm * 2.0f, t, line);
        HLine(d, x + arm, y + h - t, w - arm * 2.0f, t, line);
        VLine(d, x, y + arm, h - arm * 2.0f, t, line);
        VLine(d, x + w - t, y + arm, h - arm * 2.0f, t, line);

        const Texture& corner = Shapes::Get(Shapes::Corner);
        const float size = 64.0f * s * k, off = 8.5f * s * k;
        const float l = x + t * 0.5f, r = x + w - t * 0.5f, top = y + t * 0.5f, bottom = y + h - t * 0.5f;
        DrawTex(d, corner, l - off, top - off, size, size, 0.0f, 0.0f, 64.0f, 64.0f, ornament);
        DrawTex(d, corner, r - (size - off), top - off, size, size, 64.0f, 0.0f, -64.0f, 64.0f, ornament);
        DrawTex(d, corner, l - off, bottom - (size - off), size, size, 0.0f, 64.0f, 64.0f, -64.0f, ornament);
        DrawTex(d, corner, r - (size - off), bottom - (size - off), size, size, 64.0f, 64.0f, -64.0f, -64.0f, ornament);
    }

    // Outlined diamond, filled red once unlocked
    inline void DrawBadge(DrawCtx& d, float cx, float cy, bool unlocked, float alpha)
    {
        cx = floorf(cx) + 0.5f;
        cy = floorf(cy) + 0.5f;
        DrawShape(d, Shapes::BadgeRim, cx, cy, Faded(kOrnament, (unlocked ? 1.0f : 0.5f) * alpha));
        DrawShape(d, Shapes::BadgeFace, cx, cy, Faded(kBadgeFace, alpha));
        if (unlocked)
        {
            DrawShape(d, Shapes::BadgeCore, cx, cy, Faded(kRed, alpha));
        }
    }

    // Progress bar: hairline track between two tips, filled up to the handle
    inline void DrawSlider(DrawCtx& d, float x, float y, float w, float frac)
    {
        const float s = d.s;
        const float t = floorf(s + 0.5f);
        const float row = floorf(y);
        frac = Clamp(frac, 0.0f, 1.0f);

        const float tip = 13.0f * s;
        const float x0 = floorf(x + tip), x1 = floorf(x + w - tip);
        const float xf = floorf(x0 + (x1 - x0) * frac);

        DrawSpearTip(d, x, row, false, frac > 0.0f ? kRed : kTrack);
        DrawSpearTip(d, x + w, row, true, frac >= 1.0f ? kRed : kTrack);
        HLine(d, x0, row, x1 - x0, t, kTrack);

        if (frac > 0.0f)
        {
            FillRect(d, x0, row - t, xf - x0, 3.0f * t, kRed);
            DrawShape(d, Shapes::Spindle, xf + 0.5f, row + 0.5f * t, kRed);
        }
    }

    // Fill, chessboard and glow from the top, darkened rim
    inline void DrawPanelBackdrop(DrawCtx& d, float x, float y, float w, float h, float alpha, bool card)
    {
        const float s = d.s;
        FillRect(d, x, y, w, h, WithAlpha(kPanel, alpha));

        const float o = (card ? 7.0f : 12.0f) * s;
        DrawChecker(d, x + o, y + o, w - o * 2.0f, (card ? 12.0f : 30.0f) * s, Faded(kChecker, alpha));

        // The lower half of the soft dot, brightest at the top edge
        const Texture& soft = Shapes::Get(Shapes::Soft);
        const float gw = w * 0.9f;
        const float gh = card ? h * 0.9f : 240.0f * s;
        DrawTex(d, soft, x + (w - gw) * 0.5f, y, gw, gh, 0.0f, soft.h * 0.5f, (float)soft.w, soft.h * 0.5f, Faded(kGlow, alpha));

        DrawInnerShade(d, x, y, w, h, (card ? 26.0f : 70.0f) * s, Faded(kShade, alpha));
    }

    // Only clip-aware primitives, the list repaints the header and footer with it
    inline void DrawPanel(DrawCtx& d, float x, float y, float w, float h, float alpha, bool card)
    {
        DrawPanelBackdrop(d, x, y, w, h, alpha, card);

        const float o = (card ? 7.0f : 12.0f) * d.s;
        DrawFiligreeFrame(d, x + o, y + o, w - o * 2.0f, h - o * 2.0f, card ? 0.72f : 1.0f, Faded(kBoneLine, alpha), Faded(kOrnament, alpha));
    }

    // Fades the list out over [y, y + h] by laying the backdrop back over it in 2px strips, opaque at the list's edge.
    // A flat gradient would not match the glow and chessboard behind the header. Stays inside the frame lines
    inline void DrawListFade(DrawCtx& d, float winX, float winY, float winW, float winH, float y, float h, bool fromTop, float strength)
    {
        if (strength <= 0.0f || h <= 0.0f)
            return;

        const DrawCtx saved = d;
        const float inset = 12.0f * d.s + floorf(d.s + 0.5f);
        d.clipLeft = winX + inset;
        d.clipRight = winX + winW - inset;

        const int strips = (int)ceilf(h / 2.0f);
        for (int i = 0; i < strips; i++)
        {
            float k = 1.0f - ((float)i + 0.5f) / (float)strips;
            if (!fromTop) k = 1.0f - k;
            k = k * k * (3.0f - 2.0f * k);

            d.clipTop = y + h * (float)i / (float)strips;
            d.clipBottom = y + h * (float)(i + 1) / (float)strips;
            DrawPanelBackdrop(d, winX, winY, winW, winH, k * strength, false);
        }

        d = saved;
    }

    inline void DrawAchievementsWindow(DrawCtx& d, float deltaSeconds)
    {
        UCanvas* c = d.canvas;
        const float s = d.s;
        const float dispW = (float)c->SizeX;
        const float dispH = (float)c->SizeY;

        const float maxW = dispW - 40.0f * s;
        const float maxH = dispH - 40.0f * s;
        float winW = Clamp(dispW * 0.6f, 700.0f * s < maxW ? 700.0f * s : maxW, maxW);
        if (winW > 1180.0f * s) winW = 1180.0f * s; // keeps its proportions on ultrawide screens
        const float winH = Clamp(dispH * 0.8f, 500.0f * s < maxH ? 500.0f * s : maxH, maxH);
        const float winX = floorf((dispW - winW) * 0.5f);
        const float winY = floorf((dispH - winH) * 0.5f);

        // Pixel sizes at 1080p
        const float pad = 34.0f * s;
        const float titleScale = (30.0f * s) / d.fontUnitHeight;
        const float nameScale = (20.0f * s) / d.fontUnitHeight;
        const float bodyScale = (16.0f * s) / d.fontUnitHeight;
        const float smallScale = (14.0f * s) / d.fontUnitHeight;
        const float counterScale = (18.0f * s) / d.fontUnitHeight;
        const float titleH = d.fontUnitHeight * titleScale;
        const float bodyH = d.fontUnitHeight * bodyScale;
        const float nameH = d.fontUnitHeight * nameScale;
        const float smallH = d.fontUnitHeight * smallScale;
        const float counterH = d.fontUnitHeight * counterScale;
        const float hairline = floorf(s + 0.5f);

        // Controller: A toggles secrets
        static bool s_aPrev = false;
        bool aNow = g_padConnected && (g_padState.Gamepad.wButtons & XINPUT_GAMEPAD_A);
        if (aNow && !s_aPrev) g_showSecrets = !g_showSecrets;
        s_aPrev = aNow;

        // Dim the game behind the window, drop shadow under it
        FillRect(d, 0.0f, 0.0f, dispW, dispH, kBackdrop);
        DrawSoftBox(d, winX + 6.0f * s, winY + 12.0f * s, winW - 12.0f * s, winH - 12.0f * s, 30.0f * s, WithAlpha(kBlack, 0.7f));
        DrawPanel(d, winX, winY, winW, winH, 1.0f, false);

        // Header layout
        const float centerX = winX + winW * 0.5f;
        const float titleY = winY + 32.0f * s;
        const float ruleY = floorf(titleY + titleH + 10.0f * s);
        const float counterY = ruleY + 12.0f * s;
        const float headerBottom = counterY + counterH + 14.0f * s;

        // List region, between the header and the help line
        const float helpH = smallH + 28.0f * s;
        const float listTop = headerBottom + 8.0f * s;
        const float listBottom = winY + winH - helpH - 6.0f * s;
        const float listH = listBottom - listTop;
        const float listX = winX + pad;
        const float listR = winX + winW - pad - 12.0f * s;
        const float listW = listR - listX;

        const float iconSize = 60.0f * s;
        const float badgeSize = 19.0f * s;
        const float textX = listX + iconSize + 20.0f * s;
        const float textW = listR - badgeSize - 22.0f * s - textX;
        const float barGap = 9.0f * s;
        const float rowPad = 11.0f * s;

        std::lock_guard<std::recursive_mutex> lock(g_stateMutex);

        const size_t count = g_achievements.size();
        if (g_nameWrap.size() < count) g_nameWrap.resize(count);
        if (g_descWrap.size() < count) g_descWrap.resize(count);

        // First pass: wrap text and measure row heights
        static std::vector<float> rowH;
        static std::vector<float> rowTextH;
        rowH.assign(count, 0.0f);
        rowTextH.assign(count, 0.0f);
        float contentH = 0.0f;
        float countW = 0.0f; // widest count, so every slider gets the same length
        for (size_t i = 0; i < count; i++)
        {
            bool unlocked = (i < g_unlocked.size()) ? g_unlocked[i] : false;
            bool reveal = !IsSecret((int)i) || g_showSecrets || unlocked;
            int maxv = AchievementMaxFrom(g_maxOverride, (int)i);

            if (maxv > 1)
            {
                int cur = (i < g_current.size()) ? g_current[i] : 0;
                wchar_t widest[32];
                swprintf_s(widest, L"%d / %d", cur > maxv ? cur : maxv, maxv);
                float w = TextWidth(d, widest, smallScale);
                if (w > countW) countW = w;
            }

            WrapText(d, reveal ? NameOf(i) : g_hiddenName, textW, nameScale, g_nameWrap[i]);
            WrapText(d, reveal ? DescOf(i) : g_hiddenDesc, textW, bodyScale, g_descWrap[i]);

            float textH = g_nameWrap[i].lines.size() * nameH + g_descWrap[i].lines.size() * bodyH;
            if (reveal && maxv > 1) textH += barGap + smallH;
            rowTextH[i] = textH;
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

            bool closeCombo = (g_padState.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_THUMB) != 0;
            bool up = !closeCombo && (g_padState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP) != 0;
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

        // Second pass: draw rows inside the list window, text may spill into the header and help line
        d.clipTop = listTop;
        d.clipBottom = listBottom;
        d.coverTop = winY + 2.0f;
        d.coverBottom = winY + winH - 2.0f;

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

                float iy = floorf(rowY + rowPad);
                const Texture& t = g_achievements[i];
                if (reveal && t.tex)
                {
                    DrawIcon(d, t, listX, iy, iconSize, unlocked ? kWhite : kLockedTint);
                }
                else
                {
                    // Hidden or unavailable icon: empty slot with a centered "?"
                    FillRect(d, listX, iy, iconSize, iconSize, Srgb(255, 255, 255, 0.035f));
                    FrameRect(d, listX, iy, iconSize, iconSize, hairline, WithAlpha(kOrnament, 0.3f));
                    float qw = 0.0f, qh = 0.0f;
                    MeasureText(d, L"?", nameScale, qw, qh);
                    DrawTextLine(d, L"?", listX + (iconSize - qw) * 0.5f, iy + (iconSize - qh) * 0.5f, nameScale, kRedTextColor);
                }

                // Centered on the icon when shorter than it
                float ty = iy + (rowTextH[i] < iconSize ? floorf((iconSize - rowTextH[i]) * 0.5f) : 0.0f);
                FColor nameCol = (reveal && unlocked) ? kNameColor : kNameLockedColor;
                FColor descCol = (reveal && unlocked) ? kDescColor : kDescLockedColor;
                for (const std::wstring& line : g_nameWrap[i].lines)
                {
                    DrawTextLine(d, line.c_str(), textX, ty, nameScale, nameCol);
                    ty += nameH;
                }
                for (const std::wstring& line : g_descWrap[i].lines)
                {
                    DrawTextLine(d, line.c_str(), textX, ty, bodyScale, descCol);
                    ty += bodyH;
                }

                if (reveal && maxv > 1)
                {
                    ty += barGap;
                    wchar_t overlay[32];
                    swprintf_s(overlay, L"%d / %d", cur, maxv);
                    float barW = textW - countW - 14.0f * s;
                    if (barW < 40.0f * s) barW = 40.0f * s;
                    DrawSlider(d, textX, ty + smallH * 0.5f, barW, (float)cur / (float)maxv);
                    DrawTextLine(d, overlay, textX + textW - TextWidth(d, overlay, smallScale), ty, smallScale, unlocked ? kRedTextColor : kTextHintColor);
                }

                DrawBadge(d, listR - badgeSize * 0.5f, rowY + h * 0.5f, unlocked, reveal ? 1.0f : 0.6f);

                if (i + 1 < count)
                {
                    DrawFadedRule(d, listX, rowY + h, listW, 1.0f * s, 160.0f * s, kRowRule);
                }
            }

            rowY += h;
        }

        d.coverTop = -1.0e9f;
        d.coverBottom = 1.0e9f;

        // Rows fade out at either edge once something is scrolled past it
        const float fadeH = 30.0f * s;
        DrawListFade(d, winX, winY, winW, winH, listTop, fadeH, true, Clamp(g_scrollY / fadeH, 0.0f, 1.0f));
        DrawListFade(d, winX, winY, winW, winH, listBottom - fadeH, fadeH, false, Clamp((maxScroll - g_scrollY) / fadeH, 0.0f, 1.0f));

        // Header and help line, repainted over whatever spilled out of the list
        d.clipTop = winY;
        d.clipBottom = listTop;
        DrawPanel(d, winX, winY, winW, winH, 1.0f, false);
        d.clipTop = listBottom;
        d.clipBottom = winY + winH;
        DrawPanel(d, winX, winY, winW, winH, 1.0f, false);
        d.clipTop = -1.0e9f;
        d.clipBottom = 1.0e9f;

        DrawSmallCaps(d, L"Achievements", centerX, titleY, titleScale, 0.78f, 3.5f * s, kTitleColor, true);

        const float ruleW = 250.0f * s, gap = 17.0f * s;
        const FLinearColor rule = WithAlpha(kOrnament, kOrnament.A * 0.85f);
        DrawSpearRule(d, centerX - ruleW, ruleY, ruleW - gap, rule, true, false);
        DrawSpearRule(d, centerX + gap, ruleY, ruleW - gap, rule, false, true);
        DrawBadge(d, centerX, ruleY + 0.5f * hairline, true, 1.0f);

        int unlockedCount = 0;
        for (size_t i = 0; i < g_achievements.size() && i < g_unlocked.size(); i++)
        {
            if (g_unlocked[i]) unlockedCount++;
        }

        wchar_t unlockedText[16], totalText[32];
        swprintf_s(unlockedText, L"%d", unlockedCount);
        swprintf_s(totalText, L"  /  %d", (int)g_achievements.size());
        const float uw = TextWidth(d, unlockedText, counterScale);
        const float counterX = floorf(centerX - (uw + TextWidth(d, totalText, counterScale)) * 0.5f);
        DrawTextLine(d, unlockedText, counterX, counterY, counterScale, kRedTextColor);
        DrawTextLine(d, totalText, counterX + uw, counterY, counterScale, kTextMutedColor);

        // Help line, shrunk to fit narrow windows
        struct Hint
        {
            const wchar_t* key;
            const wchar_t* label;
        };

        const Hint hints[] =
        {
            { L"Space / A", g_showSecrets ? L"Hide secret achievements" : L"Show secret achievements" },
            { L"Wheel / Stick", L"Scroll" },
            { L"Home / L3 + D-Pad Up", L"Close" },
        };

        float helpScale = smallScale;
        const float keyGap = 7.0f * s, hintGap = 30.0f * s;
        float helpW = hintGap * 2.0f;
        for (const Hint& hint : hints)
        {
            helpW += TextWidth(d, hint.key, helpScale) + keyGap + TextWidth(d, hint.label, helpScale);
        }

        float shrink = 1.0f;
        if (helpW > winW - 120.0f * s)
        {
            shrink = (winW - 120.0f * s) / helpW;
            helpScale *= shrink;
            helpW *= shrink;
        }

        const float helpY = winY + winH - helpH + 6.0f * s;
        float hx = floorf(centerX - helpW * 0.5f);
        for (int i = 0; i < 3; i++)
        {
            DrawTextLine(d, hints[i].key, hx, helpY, helpScale, kRedTextColor);
            hx += TextWidth(d, hints[i].key, helpScale) + keyGap * shrink;
            DrawTextLine(d, hints[i].label, hx, helpY, helpScale, kTextHintColor);
            hx += TextWidth(d, hints[i].label, helpScale);

            if (i < 2)
            {
                const float px = floorf(hx + hintGap * shrink * 0.5f) + 0.5f;
                const float py = floorf(helpY + d.fontUnitHeight * helpScale * 0.5f) + 0.5f;
                DrawShape(d, Shapes::Pip, px, py, WithAlpha(kOrnament, 0.8f));
                hx += hintGap * shrink;
            }
        }

        // Scrollbar
        if (maxScroll > 0.0f)
        {
            const float trackX = floorf(listR + 11.0f * s);
            FillRect(d, trackX, listTop, hairline, listH, WithAlpha(kOrnament, 0.12f));

            float thumbH = listH * (listH / contentH);
            if (thumbH < 30.0f * s) thumbH = 30.0f * s;
            const float thumbY = floorf(listTop + (listH - thumbH) * (g_scrollY / maxScroll));
            const FLinearColor thumb = WithAlpha(kOrnament, 0.55f);
            FillRect(d, trackX - hairline, thumbY + 4.0f * s, 3.0f * hairline, thumbH - 8.0f * s, thumb);
            DrawShape(d, Shapes::Pip, trackX + hairline * 0.5f, floorf(thumbY + 4.0f * s) + 0.5f, thumb);
            DrawShape(d, Shapes::Pip, trackX + hairline * 0.5f, floorf(thumbY + thumbH - 4.0f * s) + 0.5f, thumb);
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

        const float toastW = 440.0f * s;
        const float margin = 22.0f * s;
        const float spacing = 10.0f * s;
        const float pad = 24.0f * s;
        const float iconSize = 60.0f * s;
        const float onX = dispW - toastW - margin;
        const float offX = dispW + 10.0f;

        const float headScale = (15.0f * s) / d.fontUnitHeight;
        const float nameScale = (18.0f * s) / d.fontUnitHeight;
        const float descScale = (15.0f * s) / d.fontUnitHeight;
        const float headH = d.fontUnitHeight * headScale;
        const float nameH = d.fontUnitHeight * nameScale;
        const float descH = d.fontUnitHeight * descScale;

        const float textX = pad + iconSize + 16.0f * s;
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
            x = floorf(x);

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

            float headBlock = headH + 5.0f * s;
            float textH = headBlock + g_toastNameWrap[ti].lines.size() * nameH + g_toastDescWrap[ti].lines.size() * descH;
            float bodyH = textH > iconSize ? textH : iconSize;
            float toastH = floorf(bodyH + pad * 2.0f);
            float y = floorf(it.animY);

            DrawSoftBox(d, x + 4.0f * s, y + 8.0f * s, toastW - 8.0f * s, toastH - 8.0f * s, 14.0f * s, WithAlpha(kBlack, 0.55f * alpha));
            DrawPanel(d, x, y, toastW, toastH, alpha, true);

            if (id >= 0 && id < (int)g_achievements.size() && g_achievements[id].tex)
            {
                DrawIcon(d, g_achievements[id], x + pad, y + pad + floorf((bodyH - iconSize) * 0.5f), iconSize, WithAlpha(kWhite, alpha));
            }

            float ty = y + pad + floorf((bodyH - textH) * 0.5f);
            float headW = DrawSmallCaps(d, L"Achievement Unlocked", x + textX, ty, headScale, 0.8f, 1.8f * s, Faded(kRedTextColor, alpha));

            // The rule grows out of the heading once the toast has slid in
            float land = Clamp((t - 300.0f) / 380.0f, 0.0f, 1.0f);
            land = 1.0f - (1.0f - land) * (1.0f - land) * (1.0f - land);
            float ruleX = x + textX + headW + 12.0f * s;
            float ruleW = (x + toastW - pad + 6.0f * s - ruleX) * land;
            if (ruleW > 66.0f * s)
            {
                DrawSpearRule(d, ruleX, ty + floorf(headH * 0.55f), ruleW, Faded(kRed, alpha), false, true);
            }
            ty += headBlock;

            for (const std::wstring& line : g_toastNameWrap[ti].lines)
            {
                DrawTextLine(d, line.c_str(), x + textX, ty, nameScale, Faded(kNameColor, alpha));
                ty += nameH;
            }
            for (const std::wstring& line : g_toastDescWrap[ti].lines)
            {
                DrawTextLine(d, line.c_str(), x + textX, ty, descScale, Faded(kDescColor, alpha));
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
        Shapes::Build();

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

        if (GetAsyncKeyState(AchievementOverlayKey) & 1)
        {
            Toggle();
        }

        // Controller
        static bool s_comboPrev = false;
        bool comboNow = g_padConnected && (g_padState.Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_THUMB) && (g_padState.Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP);
        if (comboNow && !s_comboPrev)
        {
            Toggle();
        }
        s_comboPrev = comboNow;
    }
}