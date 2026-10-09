#include "Common.hpp"
#include "Features.hpp"

#include <mmreg.h>
#include <mmdeviceapi.h>
#include <audioclient.h>
#include <propsys.h>

#pragma comment(lib, "ole32.lib")

// xaudio2.h declares all of this under pack(1), mirror it or the offsets are wrong
#pragma pack(push, 1)

struct XA_SEND_DESCRIPTOR // XAUDIO2_SEND_DESCRIPTOR
{
	UINT32 Flags;
	struct XA26_IXAudio2Voice* pOutputVoice;
};

struct XA_VOICE_SENDS // XAUDIO2_VOICE_SENDS
{
	UINT32 SendCount;
	XA_SEND_DESCRIPTOR* pSends;
};

struct XA_EFFECT_DESCRIPTOR // XAUDIO2_EFFECT_DESCRIPTOR
{
	IUnknown* pEffect;
	BOOL InitialState;
	UINT32 OutputChannels;
};

struct XA_EFFECT_CHAIN // XAUDIO2_EFFECT_CHAIN
{
	UINT32 EffectCount;
	XA_EFFECT_DESCRIPTOR* pEffectDescriptors;
};

struct XA_FILTER_PARAMETERS // XAUDIO2_FILTER_PARAMETERS
{
	int Type;
	float Frequency;
	float OneOverQ;
};

struct XA_BUFFER // XAUDIO2_BUFFER
{
	UINT32 Flags;
	UINT32 AudioBytes;
	const BYTE* pAudioData;
	UINT32 PlayBegin;
	UINT32 PlayLength;
	UINT32 LoopBegin;
	UINT32 LoopLength;
	UINT32 LoopCount;
	void* pContext;
};

struct XA_BUFFER_WMA // XAUDIO2_BUFFER_WMA
{
	const UINT32* pDecodedPacketCumulativeBytes;
	UINT32 PacketCount;
};

struct XA_VOICE_STATE // XAUDIO2_VOICE_STATE
{
	void* pCurrentBufferContext;
	UINT32 BuffersQueued;
	UINT64 SamplesPlayed;
};

struct XA_VOICE_DETAILS_26 // XAUDIO2_VOICE_DETAILS before 2.8
{
	UINT32 CreationFlags;
	UINT32 InputChannels;
	UINT32 InputSampleRate;
};

struct XA_VOICE_DETAILS_29 // 2.8 inserted ActiveFlags
{
	UINT32 CreationFlags;
	UINT32 ActiveFlags;
	UINT32 InputChannels;
	UINT32 InputSampleRate;
};

struct XA_DEBUG_CONFIGURATION // XAUDIO2_DEBUG_CONFIGURATION
{
	UINT32 TraceMask;
	UINT32 BreakMask;
	BOOL LogThreadID;
	BOOL LogFileline;
	BOOL LogFunctionName;
	BOOL LogTiming;
};

struct XA_DEVICE_DETAILS // XAUDIO2_DEVICE_DETAILS, gone in 2.9
{
	WCHAR DeviceID[256];
	WCHAR DisplayName[256];
	UINT32 Role;
	WAVEFORMATEXTENSIBLE OutputFormat;
};

#pragma pack(pop)

static_assert(sizeof(XA_DEVICE_DETAILS) == 0x42C, "XA_DEVICE_DETAILS layout mismatch");
static_assert(offsetof(XA_DEVICE_DETAILS, OutputFormat) == 0x404, "OutputFormat offset mismatch");
static_assert(offsetof(XA_DEVICE_DETAILS, OutputFormat.Format.nChannels) == 0x406, "nChannels offset mismatch");
static_assert(offsetof(XA_DEVICE_DETAILS, OutputFormat.Format.nSamplesPerSec) == 0x408, "nSamplesPerSec offset mismatch");
static_assert(offsetof(XA_DEVICE_DETAILS, OutputFormat.dwChannelMask) == 0x418, "dwChannelMask offset mismatch");
static_assert(sizeof(XA_VOICE_STATE) == 16, "XA_VOICE_STATE layout mismatch");

struct XA_IXAudio2EngineCallback
{
	virtual void STDMETHODCALLTYPE OnProcessingPassStart() = 0;
	virtual void STDMETHODCALLTYPE OnProcessingPassEnd() = 0;
	virtual void STDMETHODCALLTYPE OnCriticalError(HRESULT Error) = 0;
};

struct XA_IXAudio2VoiceCallback
{
	virtual void STDMETHODCALLTYPE OnVoiceProcessingPassStart(UINT32 BytesRequired) = 0;
	virtual void STDMETHODCALLTYPE OnVoiceProcessingPassEnd() = 0;
	virtual void STDMETHODCALLTYPE OnStreamEnd() = 0;
	virtual void STDMETHODCALLTYPE OnBufferStart(void* pBufferContext) = 0;
	virtual void STDMETHODCALLTYPE OnBufferEnd(void* pBufferContext) = 0;
	virtual void STDMETHODCALLTYPE OnLoopEnd(void* pBufferContext) = 0;
	virtual void STDMETHODCALLTYPE OnVoiceError(void* pBufferContext, HRESULT Error) = 0;
};

struct XA29_IXAudio2Voice
{
	virtual void STDMETHODCALLTYPE GetVoiceDetails(XA_VOICE_DETAILS_29* pVoiceDetails) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetOutputVoices(const XA_VOICE_SENDS* pSendList) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetEffectChain(const XA_EFFECT_CHAIN* pEffectChain) = 0;
	virtual HRESULT STDMETHODCALLTYPE EnableEffect(UINT32 EffectIndex, UINT32 OperationSet) = 0;
	virtual HRESULT STDMETHODCALLTYPE DisableEffect(UINT32 EffectIndex, UINT32 OperationSet) = 0;
	virtual void STDMETHODCALLTYPE GetEffectState(UINT32 EffectIndex, BOOL* pEnabled) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetEffectParameters(UINT32 EffectIndex, const void* pParameters, UINT32 ParametersByteSize, UINT32 OperationSet) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetEffectParameters(UINT32 EffectIndex, void* pParameters, UINT32 ParametersByteSize) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetFilterParameters(const XA_FILTER_PARAMETERS* pParameters, UINT32 OperationSet) = 0;
	virtual void STDMETHODCALLTYPE GetFilterParameters(XA_FILTER_PARAMETERS* pParameters) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetOutputFilterParameters(XA29_IXAudio2Voice* pDestinationVoice, const XA_FILTER_PARAMETERS* pParameters, UINT32 OperationSet) = 0;
	virtual void STDMETHODCALLTYPE GetOutputFilterParameters(XA29_IXAudio2Voice* pDestinationVoice, XA_FILTER_PARAMETERS* pParameters) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetVolume(float Volume, UINT32 OperationSet) = 0;
	virtual void STDMETHODCALLTYPE GetVolume(float* pVolume) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetChannelVolumes(UINT32 Channels, const float* pVolumes, UINT32 OperationSet) = 0;
	virtual void STDMETHODCALLTYPE GetChannelVolumes(UINT32 Channels, float* pVolumes) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetOutputMatrix(XA29_IXAudio2Voice* pDestinationVoice, UINT32 SourceChannels, UINT32 DestinationChannels, const float* pLevelMatrix, UINT32 OperationSet) = 0;
	virtual void STDMETHODCALLTYPE GetOutputMatrix(XA29_IXAudio2Voice* pDestinationVoice, UINT32 SourceChannels, UINT32 DestinationChannels, float* pLevelMatrix) = 0;
	virtual void STDMETHODCALLTYPE DestroyVoice() = 0;
};

struct XA29_IXAudio2SourceVoice : XA29_IXAudio2Voice
{
	virtual HRESULT STDMETHODCALLTYPE Start(UINT32 Flags, UINT32 OperationSet) = 0;
	virtual HRESULT STDMETHODCALLTYPE Stop(UINT32 Flags, UINT32 OperationSet) = 0;
	virtual HRESULT STDMETHODCALLTYPE SubmitSourceBuffer(const XA_BUFFER* pBuffer, const XA_BUFFER_WMA* pBufferWMA) = 0;
	virtual HRESULT STDMETHODCALLTYPE FlushSourceBuffers() = 0;
	virtual HRESULT STDMETHODCALLTYPE Discontinuity() = 0;
	virtual HRESULT STDMETHODCALLTYPE ExitLoop(UINT32 OperationSet) = 0;
	virtual void STDMETHODCALLTYPE GetState(XA_VOICE_STATE* pVoiceState, UINT32 Flags) = 0; // Flags added in 2.8
	virtual HRESULT STDMETHODCALLTYPE SetFrequencyRatio(float Ratio, UINT32 OperationSet) = 0;
	virtual void STDMETHODCALLTYPE GetFrequencyRatio(float* pRatio) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetSourceSampleRate(UINT32 NewSourceSampleRate) = 0;
};

struct XA29_IXAudio2SubmixVoice : XA29_IXAudio2Voice
{
};

struct XA29_IXAudio2MasteringVoice : XA29_IXAudio2Voice
{
	virtual HRESULT STDMETHODCALLTYPE GetChannelMask(DWORD* pChannelmask) = 0; // 2.8+, never called
};

struct XA29_IXAudio2 : IUnknown
{
	virtual HRESULT STDMETHODCALLTYPE RegisterForCallbacks(XA_IXAudio2EngineCallback* pCallback) = 0;
	virtual void STDMETHODCALLTYPE UnregisterForCallbacks(XA_IXAudio2EngineCallback* pCallback) = 0;
	virtual HRESULT STDMETHODCALLTYPE CreateSourceVoice(XA29_IXAudio2SourceVoice** ppSourceVoice, const WAVEFORMATEX* pSourceFormat, UINT32 Flags, float MaxFrequencyRatio, XA_IXAudio2VoiceCallback* pCallback, const XA_VOICE_SENDS* pSendList, const XA_EFFECT_CHAIN* pEffectChain) = 0;
	virtual HRESULT STDMETHODCALLTYPE CreateSubmixVoice(XA29_IXAudio2SubmixVoice** ppSubmixVoice, UINT32 InputChannels, UINT32 InputSampleRate, UINT32 Flags, UINT32 ProcessingStage, const XA_VOICE_SENDS* pSendList, const XA_EFFECT_CHAIN* pEffectChain) = 0;
	virtual HRESULT STDMETHODCALLTYPE CreateMasteringVoice(XA29_IXAudio2MasteringVoice** ppMasteringVoice, UINT32 InputChannels, UINT32 InputSampleRate, UINT32 Flags, LPCWSTR szDeviceId, const XA_EFFECT_CHAIN* pEffectChain, int StreamCategory) = 0;
	virtual HRESULT STDMETHODCALLTYPE StartEngine() = 0;
	virtual void STDMETHODCALLTYPE StopEngine() = 0;
	virtual HRESULT STDMETHODCALLTYPE CommitChanges(UINT32 OperationSet) = 0;
	virtual void STDMETHODCALLTYPE GetPerformanceData(void* pPerfData) = 0;
	virtual void STDMETHODCALLTYPE SetDebugConfiguration(const XA_DEBUG_CONFIGURATION* pDebugConfiguration, void* pReserved) = 0;
};

struct XA26_IXAudio2Voice
{
	virtual void STDMETHODCALLTYPE GetVoiceDetails(XA_VOICE_DETAILS_26* pVoiceDetails) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetOutputVoices(const XA_VOICE_SENDS* pSendList) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetEffectChain(const XA_EFFECT_CHAIN* pEffectChain) = 0;
	virtual HRESULT STDMETHODCALLTYPE EnableEffect(UINT32 EffectIndex, UINT32 OperationSet) = 0;
	virtual HRESULT STDMETHODCALLTYPE DisableEffect(UINT32 EffectIndex, UINT32 OperationSet) = 0;
	virtual void STDMETHODCALLTYPE GetEffectState(UINT32 EffectIndex, BOOL* pEnabled) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetEffectParameters(UINT32 EffectIndex, const void* pParameters, UINT32 ParametersByteSize, UINT32 OperationSet) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetEffectParameters(UINT32 EffectIndex, void* pParameters, UINT32 ParametersByteSize) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetFilterParameters(const XA_FILTER_PARAMETERS* pParameters, UINT32 OperationSet) = 0;
	virtual void STDMETHODCALLTYPE GetFilterParameters(XA_FILTER_PARAMETERS* pParameters) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetOutputFilterParameters(XA26_IXAudio2Voice* pDestinationVoice, const XA_FILTER_PARAMETERS* pParameters, UINT32 OperationSet) = 0;
	virtual void STDMETHODCALLTYPE GetOutputFilterParameters(XA26_IXAudio2Voice* pDestinationVoice, XA_FILTER_PARAMETERS* pParameters) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetVolume(float Volume, UINT32 OperationSet) = 0;
	virtual void STDMETHODCALLTYPE GetVolume(float* pVolume) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetChannelVolumes(UINT32 Channels, const float* pVolumes, UINT32 OperationSet) = 0;
	virtual void STDMETHODCALLTYPE GetChannelVolumes(UINT32 Channels, float* pVolumes) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetOutputMatrix(XA26_IXAudio2Voice* pDestinationVoice, UINT32 SourceChannels, UINT32 DestinationChannels, const float* pLevelMatrix, UINT32 OperationSet) = 0;
	virtual void STDMETHODCALLTYPE GetOutputMatrix(XA26_IXAudio2Voice* pDestinationVoice, UINT32 SourceChannels, UINT32 DestinationChannels, float* pLevelMatrix) = 0;
	virtual void STDMETHODCALLTYPE DestroyVoice() = 0;
};

struct XA26_IXAudio2SourceVoice : XA26_IXAudio2Voice
{
	virtual HRESULT STDMETHODCALLTYPE Start(UINT32 Flags, UINT32 OperationSet) = 0;
	virtual HRESULT STDMETHODCALLTYPE Stop(UINT32 Flags, UINT32 OperationSet) = 0;
	virtual HRESULT STDMETHODCALLTYPE SubmitSourceBuffer(const XA_BUFFER* pBuffer, const XA_BUFFER_WMA* pBufferWMA) = 0;
	virtual HRESULT STDMETHODCALLTYPE FlushSourceBuffers() = 0;
	virtual HRESULT STDMETHODCALLTYPE Discontinuity() = 0;
	virtual HRESULT STDMETHODCALLTYPE ExitLoop(UINT32 OperationSet) = 0;
	virtual void STDMETHODCALLTYPE GetState(XA_VOICE_STATE* pVoiceState) = 0; // no Flags in 2.6
	virtual HRESULT STDMETHODCALLTYPE SetFrequencyRatio(float Ratio, UINT32 OperationSet) = 0;
	virtual void STDMETHODCALLTYPE GetFrequencyRatio(float* pRatio) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetSourceSampleRate(UINT32 NewSourceSampleRate) = 0;
};

struct XA26_IXAudio2SubmixVoice : XA26_IXAudio2Voice
{
};

struct XA26_IXAudio2MasteringVoice : XA26_IXAudio2Voice
{
};

struct XA26_IXAudio2 : IUnknown
{
	virtual HRESULT STDMETHODCALLTYPE GetDeviceCount(UINT32* pCount) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetDeviceDetails(UINT32 Index, XA_DEVICE_DETAILS* pDeviceDetails) = 0;
	virtual HRESULT STDMETHODCALLTYPE Initialize(UINT32 Flags, UINT32 XAudio2Processor) = 0;
	virtual HRESULT STDMETHODCALLTYPE RegisterForCallbacks(XA_IXAudio2EngineCallback* pCallback) = 0;
	virtual void STDMETHODCALLTYPE UnregisterForCallbacks(XA_IXAudio2EngineCallback* pCallback) = 0;
	virtual HRESULT STDMETHODCALLTYPE CreateSourceVoice(XA26_IXAudio2SourceVoice** ppSourceVoice, const WAVEFORMATEX* pSourceFormat, UINT32 Flags, float MaxFrequencyRatio, XA_IXAudio2VoiceCallback* pCallback, const XA_VOICE_SENDS* pSendList, const XA_EFFECT_CHAIN* pEffectChain) = 0;
	virtual HRESULT STDMETHODCALLTYPE CreateSubmixVoice(XA26_IXAudio2SubmixVoice** ppSubmixVoice, UINT32 InputChannels, UINT32 InputSampleRate, UINT32 Flags, UINT32 ProcessingStage, const XA_VOICE_SENDS* pSendList, const XA_EFFECT_CHAIN* pEffectChain) = 0;
	virtual HRESULT STDMETHODCALLTYPE CreateMasteringVoice(XA26_IXAudio2MasteringVoice** ppMasteringVoice, UINT32 InputChannels, UINT32 InputSampleRate, UINT32 Flags, UINT32 DeviceIndex, const XA_EFFECT_CHAIN* pEffectChain) = 0;
	virtual HRESULT STDMETHODCALLTYPE StartEngine() = 0;
	virtual void STDMETHODCALLTYPE StopEngine() = 0;
	virtual HRESULT STDMETHODCALLTYPE CommitChanges(UINT32 OperationSet) = 0;
	virtual void STDMETHODCALLTYPE GetPerformanceData(void* pPerfData) = 0;
	virtual void STDMETHODCALLTYPE SetDebugConfiguration(const XA_DEBUG_CONFIGURATION* pDebugConfiguration, void* pReserved) = 0;
};

// the IID the game QIs for after CoCreateInstance, pulled from its .rdata
static const GUID XA_IID_IXAudio2_26 = { 0x8BCF1F58, 0x9FE7, 0x4583, { 0x8A, 0xC6, 0xE2, 0xAD, 0xC4, 0x65, 0xC8, 0xBB } };
static const GUID XA_IID_IUnknown_Local = { 0x00000000, 0x0000, 0x0000, { 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46 } };

using PFN_XAudio2Create = HRESULT(__stdcall*)(XA29_IXAudio2** ppXAudio2, UINT32 Flags, UINT32 XAudio2Processor);
using PFN_CreateAudioReverb = HRESULT(__stdcall*)(IUnknown** ppApo);
using PFN_CreateFX = HRESULT(__cdecl*)(REFCLSID clsid, IUnknown** pEffect, const void* pInitData, UINT32 InitDataByteSize);

constexpr UINT32 XA29_PROCESSOR_DEFAULT = 0x00000001;
constexpr int XA29_AudioCategory_GameEffects = 6;
constexpr HRESULT XA_E_INVALID_CALL = 0x88960001; // XAUDIO2_E_INVALID_CALL

namespace
{
	HMODULE g_hXAudio29 = nullptr;
	PFN_XAudio2Create g_pfnXAudio2Create = nullptr;
	PFN_CreateAudioReverb g_pfnCreateAudioReverb = nullptr;
	PFN_CreateFX g_pfnCreateFX = nullptr;
	bool g_loadAttempted = false;

	bool LoadXAudio29()
	{
		if (g_loadAttempted)
		{
			return g_pfnXAudio2Create != nullptr;
		}

		g_loadAttempted = true;

		g_hXAudio29 = LoadLibraryW(L"xaudio2_9redist.dll");

		if (!g_hXAudio29)
		{
			g_hXAudio29 = LoadLibraryW(L"XAudio2_9.dll");
		}
		if (!g_hXAudio29)
		{
			return false;
		}

		g_pfnXAudio2Create = reinterpret_cast<PFN_XAudio2Create>(GetProcAddress(g_hXAudio29, "XAudio2Create"));
		if (!g_pfnXAudio2Create)
		{
			FreeLibrary(g_hXAudio29);
			g_hXAudio29 = nullptr;
			return false;
		}

		g_pfnCreateAudioReverb = reinterpret_cast<PFN_CreateAudioReverb>(GetProcAddress(g_hXAudio29, "CreateAudioReverb"));
		g_pfnCreateFX = reinterpret_cast<PFN_CreateFX>(GetProcAddress(g_hXAudio29, "CreateFX"));
		return true;
	}
}

namespace
{
	std::mutex g_voiceMapLock;
	std::unordered_map<void*, XA29_IXAudio2Voice*> g_voiceMap;

	void RegisterVoice(void* wrapper, XA29_IXAudio2Voice* real)
	{
		std::lock_guard<std::mutex> lock(g_voiceMapLock);
		g_voiceMap[wrapper] = real;
	}

	void UnregisterVoice(void* wrapper)
	{
		std::lock_guard<std::mutex> lock(g_voiceMapLock);
		g_voiceMap.erase(wrapper);
	}

	XA29_IXAudio2Voice* UnwrapVoice(XA26_IXAudio2Voice* v)
	{
		if (!v) return nullptr;

		std::lock_guard<std::mutex> lock(g_voiceMapLock);
		auto it = g_voiceMap.find(v);
		if (it != g_voiceMap.end())
		{
			return it->second;
		}

		return nullptr;
	}

	struct TranslatedSends
	{
		XA_VOICE_SENDS Sends;
		XA_SEND_DESCRIPTOR Inline[32];
		std::vector<XA_SEND_DESCRIPTOR> Heap;
		bool InvalidDest = false; // non-NULL destination failed to unwrap (stale/foreign)
		bool Malformed = false; // SendCount > 0 with pSends == NULL

		const XA_VOICE_SENDS* Translate(const XA_VOICE_SENDS* in)
		{
			if (!in) return nullptr;

			if (in->SendCount != 0 && !in->pSends)
			{
				// 2.6 rejects this shape too, fail it, never reinterpret it
				Malformed = true;
				return nullptr;
			}

			XA_SEND_DESCRIPTOR* dst = Inline;
			if (in->SendCount > 32)
			{
				Heap.resize(in->SendCount);
				dst = Heap.data();
			}

			UINT32 outCount = 0;
			for (UINT32 i = 0; i < in->SendCount; i++)
			{
				XA29_IXAudio2Voice* dest = UnwrapVoice(in->pSends[i].pOutputVoice);
				if (!dest)
				{
					if (in->pSends[i].pOutputVoice)
					{
						InvalidDest = true;
					}

					continue;
				}

				dst[outCount].Flags = in->pSends[i].Flags;
				dst[outCount].pOutputVoice = reinterpret_cast<XA26_IXAudio2Voice*>(dest);
				outCount++;
			}

			Sends.SendCount = outCount;
			Sends.pSends = outCount != 0 ? dst : nullptr;
			return &Sends;
		}
	};

	const GUID XA_CLSID_FXEQ_29 = { 0xF5E01117, 0xD6C4, 0x485A, { 0xA3, 0xF5, 0x69, 0x51, 0x96, 0xF3, 0xDB, 0xFA } };

	enum class TranslatedEffectKind : unsigned char
	{
		Passthrough,
		BuiltinReverb29,
		FXEQ29,
	};

	TranslatedEffectKind ClassifyLegacyEffect(IUnknown* pEffect)
	{
		if (!pEffect)
		{
			return TranslatedEffectKind::Passthrough;
		}

		void* vtbl = *reinterpret_cast<void* const*>(pEffect);
		HMODULE mod = nullptr;
		if (!GetModuleHandleExW(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, reinterpret_cast<LPCWSTR>(vtbl), &mod) || !mod)
		{
			return TranslatedEffectKind::Passthrough;
		}

		if (mod == g_hXAudio29)
		{
			return TranslatedEffectKind::Passthrough;
		}

		wchar_t path[MAX_PATH];
		if (!GetModuleFileNameW(mod, path, MAX_PATH))
		{
			return TranslatedEffectKind::Passthrough;
		}

		const wchar_t* base = wcsrchr(path, L'\\');
		base = base ? base + 1 : path;

		const uintptr_t rva = reinterpret_cast<uintptr_t>(vtbl) - reinterpret_cast<uintptr_t>(mod);

		// CFXEQ's CXAPOBase vtable (what CreateFX hands out), then CAudioReverb's CMemoryManagedXAPOBase and IXAPOParameters ones
		if (_wcsicmp(base, L"XAPOFX1_4.dll") == 0 && rva == 0x1100)
		{
			return TranslatedEffectKind::FXEQ29;
		}
		if (_wcsicmp(base, L"XAudio2_6.dll") == 0 && (rva == 0x2380 || rva == 0x236C))
		{
			return TranslatedEffectKind::BuiltinReverb29;
		}
		return TranslatedEffectKind::Passthrough;
	}

	IUnknown* CreateReverbEffect29()
	{
		IUnknown* effect = nullptr;
		if (g_pfnCreateAudioReverb && SUCCEEDED(g_pfnCreateAudioReverb(&effect)) && effect)
		{
			return effect;
		}
		return nullptr;
	}

	IUnknown* CreateEQEffect29()
	{
		IUnknown* effect = nullptr;
		if (g_pfnCreateFX && SUCCEEDED(g_pfnCreateFX(XA_CLSID_FXEQ_29, &effect, nullptr, 0)) && effect)
		{
			return effect;
		}
		return nullptr;
	}

	struct TranslatedChain
	{
		XA_EFFECT_CHAIN Chain = {};
		XA_EFFECT_DESCRIPTOR Inline[8] = {};
		std::vector<XA_EFFECT_DESCRIPTOR> HeapDescs;
		XA_EFFECT_DESCRIPTOR* Descs = Inline;
		std::vector<unsigned char> Kinds;
		std::vector<IUnknown*> OwnedEffects;
		bool HasReverb = false; // the legacy reverb was in the chain, translated or not

		TranslatedChain() = default;
		TranslatedChain(const TranslatedChain&) = delete;
		TranslatedChain& operator=(const TranslatedChain&) = delete;

		~TranslatedChain()
		{
			for (IUnknown* effect : OwnedEffects)
			{
				effect->Release();
			}
		}

		const XA_EFFECT_CHAIN* Translate(const XA_EFFECT_CHAIN* in)
		{
			Kinds.clear();
			HasReverb = false;
			if (!in || in->EffectCount == 0 || !in->pEffectDescriptors)
			{
				return in;
			}

			UINT32 count = in->EffectCount;
			if (count > 8)
			{
				HeapDescs.resize(count);
				Descs = HeapDescs.data();
			}
			for (UINT32 i = 0; i < count; i++)
			{
				Descs[i] = in->pEffectDescriptors[i];
			}

			Kinds.assign(count, static_cast<unsigned char>(TranslatedEffectKind::Passthrough));

			for (UINT32 i = 0; i < count; i++)
			{
				TranslatedEffectKind kind = ClassifyLegacyEffect(Descs[i].pEffect);
				if (kind == TranslatedEffectKind::BuiltinReverb29)
				{
					HasReverb = true;
					if (IUnknown* repl = CreateReverbEffect29())
					{
						OwnedEffects.push_back(repl);
						Descs[i].pEffect = repl;
						Kinds[i] = static_cast<unsigned char>(TranslatedEffectKind::BuiltinReverb29);
					}
				}
				else if (kind == TranslatedEffectKind::FXEQ29)
				{
					if (IUnknown* repl = CreateEQEffect29())
					{
						OwnedEffects.push_back(repl);
						Descs[i].pEffect = repl;
						Kinds[i] = static_cast<unsigned char>(TranslatedEffectKind::FXEQ29);
					}
				}
			}

			Chain.EffectCount = count;
			Chain.pEffectDescriptors = Descs;
			return &Chain;
		}

		void ForceOutputChannels(UINT32 ch)
		{
			for (UINT32 i = 0; i < Chain.EffectCount && i < Kinds.size(); i++)
			{
				if (Kinds[i] == static_cast<unsigned char>(TranslatedEffectKind::FXEQ29))
				{
					Descs[i].OutputChannels = ch;
				}
			}
		}
	};
}

// CRTP so DestroyVoice can delete the concrete type
template <class TSelf, class TIface26, class TIface29>
class XAVoiceWrapBase : public TIface26
{
public:
	TIface29* real = nullptr;
	std::mutex kindsLock;
	std::vector<unsigned char> effectKinds;

	TranslatedEffectKind KindAt(UINT32 i)
	{
		std::lock_guard<std::mutex> lock(kindsLock);
		return i < effectKinds.size() ? static_cast<TranslatedEffectKind>(effectKinds[i]) : TranslatedEffectKind::Passthrough;
	}

	void SetKinds(std::vector<unsigned char>&& kinds)
	{
		std::lock_guard<std::mutex> lock(kindsLock);
		effectKinds = std::move(kinds);
	}

	void STDMETHODCALLTYPE GetVoiceDetails(XA_VOICE_DETAILS_26* pVoiceDetails) override
	{
		XA_VOICE_DETAILS_29 d29 = {};
		real->GetVoiceDetails(&d29);
		if (pVoiceDetails)
		{
			pVoiceDetails->CreationFlags = d29.CreationFlags;
			pVoiceDetails->InputChannels = d29.InputChannels;
			pVoiceDetails->InputSampleRate = d29.InputSampleRate;
		}
	}

	HRESULT STDMETHODCALLTYPE SetOutputVoices(const XA_VOICE_SENDS* pSendList) override
	{
		TranslatedSends t;
		const XA_VOICE_SENDS* sends = t.Translate(pSendList);
		if (t.Malformed || t.InvalidDest)
		{
			return XA_E_INVALID_CALL;
		}
		return real->SetOutputVoices(sends);
	}

	HRESULT STDMETHODCALLTYPE SetEffectChain(const XA_EFFECT_CHAIN* pEffectChain) override
	{
		TranslatedChain c;
		HRESULT hr = real->SetEffectChain(c.Translate(pEffectChain));
		if (SUCCEEDED(hr))
		{
			SetKinds(std::move(c.Kinds));
		}
		return hr;
	}

	HRESULT STDMETHODCALLTYPE EnableEffect(UINT32 EffectIndex, UINT32 OperationSet) override
	{
		return real->EnableEffect(EffectIndex, OperationSet);
	}

	HRESULT STDMETHODCALLTYPE DisableEffect(UINT32 EffectIndex, UINT32 OperationSet) override
	{
		return real->DisableEffect(EffectIndex, OperationSet);
	}

	void STDMETHODCALLTYPE GetEffectState(UINT32 EffectIndex, BOOL* pEnabled) override
	{
		real->GetEffectState(EffectIndex, pEnabled);
	}

	HRESULT STDMETHODCALLTYPE SetEffectParameters(UINT32 EffectIndex, const void* pParameters, UINT32 ParametersByteSize, UINT32 OperationSet) override
	{
		// 2.9 inserted SideDelay mid-struct (2.8 only appended DisableLateField), so the game's 52-byte reverb blob has to be re-packed or everything past offset 10 lands one byte off
		// and 2.9 copies its 57 bytes whatever size it's given
		if (KindAt(EffectIndex) == TranslatedEffectKind::BuiltinReverb29 && ParametersByteSize == 52 && pParameters)
		{
			BYTE p29[57] = {};
			memcpy(p29, pParameters, 10); // up to and including RearDelay
			p29[10] = 5; // SideDelay, the 7.1 default
			memcpy(p29 + 11, static_cast<const BYTE*>(pParameters) + 10, 42); // PositionLeft .. RoomSize

			auto clampF = [&](int off, float lo, float hi)
			{
				float f;
				memcpy(&f, p29 + off, 4);
				if (!(f >= lo)) f = lo;
				else if (f > hi) f = hi;
				memcpy(p29 + off, &f, 4);
			};
			auto clampB = [&](int off, BYTE hi)
			{
				if (p29[off] > hi) p29[off] = hi;
			};

			UINT32 refl;
			memcpy(&refl, p29 + 4, 4);
			if (refl > 300)
			{ 
				refl = 300; 
				memcpy(p29 + 4, &refl, 4); 
			}

			clampF(0, 0.0f, 100.0f);        // WetDryMix
			clampB(8, 85);                  // ReverbDelay
			clampB(9, 5);                   // RearDelay
			clampB(11, 30); clampB(12, 30); // PositionLeft/Right
			clampB(13, 30); clampB(14, 30); // PositionMatrixLeft/Right
			clampB(15, 15); clampB(16, 15); // Early/LateDiffusion
			clampB(17, 12);                 // LowEQGain
			clampB(18, 9);                  // LowEQCutoff
			clampB(19, 8);                  // HighEQGain
			clampB(20, 14);                 // HighEQCutoff
			clampF(21, 20.0f, 20000.0f);    // RoomFilterFreq
			clampF(25, -100.0f, 0.0f);      // RoomFilterMain
			clampF(29, -100.0f, 0.0f);      // RoomFilterHF
			clampF(33, -100.0f, 20.0f);     // ReflectionsGain
			clampF(37, -100.0f, 20.0f);     // ReverbGain
			clampF(41, 0.1f, 1.0e30f);      // DecayTime
			clampF(45, 0.0f, 100.0f);       // Density
			clampF(49, 0.0f, 100.0f);       // RoomSize

			return real->SetEffectParameters(EffectIndex, p29, 57, OperationSet);
		}

		if (KindAt(EffectIndex) == TranslatedEffectKind::FXEQ29 && ParametersByteSize == 48 && pParameters)
		{
			BYTE eq[48];
			memcpy(eq, pParameters, 48);

			auto clampF = [&](int off, float lo, float hi)
			{
				float f;
				memcpy(&f, eq + off, 4);
				if (!(f >= lo)) f = lo;
				else if (f > hi) f = hi;
				memcpy(eq + off, &f, 4);
			};
			for (int band = 0; band < 4; band++)
			{
				clampF(band * 12 + 0, 20.0f, 20000.0f); // FrequencyCenter
				clampF(band * 12 + 4, 0.126f, 7.94f);   // Gain
				clampF(band * 12 + 8, 0.1f, 2.0f);      // Bandwidth
			}

			return real->SetEffectParameters(EffectIndex, eq, 48, OperationSet);
		}

		return real->SetEffectParameters(EffectIndex, pParameters, ParametersByteSize, OperationSet);
	}

	HRESULT STDMETHODCALLTYPE GetEffectParameters(UINT32 EffectIndex, void* pParameters, UINT32 ParametersByteSize) override
	{
		if (KindAt(EffectIndex) == TranslatedEffectKind::BuiltinReverb29 && ParametersByteSize == 52 && pParameters)
		{
			BYTE p29[64] = {};
			HRESULT hr = real->GetEffectParameters(EffectIndex, p29, 57);
			if (SUCCEEDED(hr))
			{
				BYTE* out = static_cast<BYTE*>(pParameters);
				memcpy(out, p29, 10);
				memcpy(out + 10, p29 + 11, 42); // skip SideDelay
			}
			return hr;
		}

		return real->GetEffectParameters(EffectIndex, pParameters, ParametersByteSize);
	}

	HRESULT STDMETHODCALLTYPE SetFilterParameters(const XA_FILTER_PARAMETERS* pParameters, UINT32 OperationSet) override
	{
		return real->SetFilterParameters(pParameters, OperationSet);
	}

	void STDMETHODCALLTYPE GetFilterParameters(XA_FILTER_PARAMETERS* pParameters) override
	{
		real->GetFilterParameters(pParameters);
	}

	HRESULT STDMETHODCALLTYPE SetOutputFilterParameters(XA26_IXAudio2Voice* pDestinationVoice, const XA_FILTER_PARAMETERS* pParameters, UINT32 OperationSet) override
	{
		XA29_IXAudio2Voice* dest = UnwrapVoice(pDestinationVoice);
		if (pDestinationVoice && !dest)
		{
			return XA_E_INVALID_CALL;
		}
		return real->SetOutputFilterParameters(dest, pParameters, OperationSet);
	}

	void STDMETHODCALLTYPE GetOutputFilterParameters(XA26_IXAudio2Voice* pDestinationVoice, XA_FILTER_PARAMETERS* pParameters) override
	{
		XA29_IXAudio2Voice* dest = UnwrapVoice(pDestinationVoice);
		if (pDestinationVoice && !dest)
		{
			if (pParameters)
			{
				pParameters->Type = 0;
				pParameters->Frequency = 1.0f;
				pParameters->OneOverQ = 1.0f;
			}
			return;
		}
		real->GetOutputFilterParameters(dest, pParameters);
	}

	HRESULT STDMETHODCALLTYPE SetVolume(float Volume, UINT32 OperationSet) override
	{
		return real->SetVolume(Volume, OperationSet);
	}

	void STDMETHODCALLTYPE GetVolume(float* pVolume) override
	{
		real->GetVolume(pVolume);
	}

	HRESULT STDMETHODCALLTYPE SetChannelVolumes(UINT32 Channels, const float* pVolumes, UINT32 OperationSet) override
	{
		return real->SetChannelVolumes(Channels, pVolumes, OperationSet);
	}

	void STDMETHODCALLTYPE GetChannelVolumes(UINT32 Channels, float* pVolumes) override
	{
		real->GetChannelVolumes(Channels, pVolumes);
	}

	HRESULT STDMETHODCALLTYPE SetOutputMatrix(XA26_IXAudio2Voice* pDestinationVoice, UINT32 SourceChannels, UINT32 DestinationChannels, const float* pLevelMatrix, UINT32 OperationSet) override
	{
		XA29_IXAudio2Voice* dest = UnwrapVoice(pDestinationVoice);
		if (pDestinationVoice && !dest)
		{
			return XA_E_INVALID_CALL;
		}
		return real->SetOutputMatrix(dest, SourceChannels, DestinationChannels, pLevelMatrix, OperationSet);
	}

	void STDMETHODCALLTYPE GetOutputMatrix(XA26_IXAudio2Voice* pDestinationVoice, UINT32 SourceChannels, UINT32 DestinationChannels, float* pLevelMatrix) override
	{
		XA29_IXAudio2Voice* dest = UnwrapVoice(pDestinationVoice);
		if (pDestinationVoice && !dest)
		{
			if (pLevelMatrix && SourceChannels != 0 && DestinationChannels != 0 && SourceChannels <= 64 && DestinationChannels <= 64)
			{
				// don't leave the caller's buffer as stack garbage
				memset(pLevelMatrix, 0, sizeof(float) * SourceChannels * DestinationChannels);
			}
			return;
		}
		real->GetOutputMatrix(dest, SourceChannels, DestinationChannels, pLevelMatrix);
	}

	void STDMETHODCALLTYPE DestroyVoice() override
	{
		UnregisterVoice(static_cast<XA26_IXAudio2Voice*>(this));
		if (real)
		{
			real->DestroyVoice(); // blocks until any in-flight callbacks return
		}
		delete static_cast<TSelf*>(this);
	}
};

class XA26SourceVoiceWrap final : public XAVoiceWrapBase<XA26SourceVoiceWrap, XA26_IXAudio2SourceVoice, XA29_IXAudio2SourceVoice>
{
public:
	HRESULT STDMETHODCALLTYPE Start(UINT32 Flags, UINT32 OperationSet) override
	{
		return real->Start(Flags, OperationSet);
	}

	HRESULT STDMETHODCALLTYPE Stop(UINT32 Flags, UINT32 OperationSet) override
	{
		return real->Stop(Flags, OperationSet);
	}

	HRESULT STDMETHODCALLTYPE SubmitSourceBuffer(const XA_BUFFER* pBuffer, const XA_BUFFER_WMA* pBufferWMA) override
	{
		return real->SubmitSourceBuffer(pBuffer, pBufferWMA);
	}

	HRESULT STDMETHODCALLTYPE FlushSourceBuffers() override
	{
		return real->FlushSourceBuffers();
	}

	HRESULT STDMETHODCALLTYPE Discontinuity() override
	{
		return real->Discontinuity();
	}

	HRESULT STDMETHODCALLTYPE ExitLoop(UINT32 OperationSet) override
	{
		return real->ExitLoop(OperationSet);
	}

	void STDMETHODCALLTYPE GetState(XA_VOICE_STATE* pVoiceState) override
	{
		real->GetState(pVoiceState, 0);
	}

	HRESULT STDMETHODCALLTYPE SetFrequencyRatio(float Ratio, UINT32 OperationSet) override
	{
		return real->SetFrequencyRatio(Ratio, OperationSet);
	}

	void STDMETHODCALLTYPE GetFrequencyRatio(float* pRatio) override
	{
		real->GetFrequencyRatio(pRatio);
	}

	HRESULT STDMETHODCALLTYPE SetSourceSampleRate(UINT32 NewSourceSampleRate) override
	{
		return real->SetSourceSampleRate(NewSourceSampleRate);
	}
};

class XA26SubmixVoiceWrap final : public XAVoiceWrapBase<XA26SubmixVoiceWrap, XA26_IXAudio2SubmixVoice, XA29_IXAudio2SubmixVoice>
{
};

class XA26MasteringVoiceWrap final : public XAVoiceWrapBase<XA26MasteringVoiceWrap, XA26_IXAudio2MasteringVoice, XA29_IXAudio2MasteringVoice>
{
};

namespace
{
	struct GameOutputMapping
	{
		UINT32 Channels;
		DWORD Mask;
	};

	constexpr GameOutputMapping kGameOutputMappings[] =
	{
		{ 2, 0x003 }, { 3, 0x00B }, { 4, 0x107 }, { 4, 0x033 },
		{ 5, 0x03B }, { 5, 0x607 }, { 6, 0x03F }, { 6, 0x60F },
		{ 7, 0x70F }, { 8, 0x0FF }, { 8, 0x63F },
	};

	bool GameAcceptsSpeakerConfig(UINT32 channels, DWORD mask)
	{
		for (const GameOutputMapping& m : kGameOutputMappings)
		{
			if (channels == m.Channels && (mask & m.Mask) == mask)
			{
				return true;
			}
		}
		return false;
	}

	void NormalizeSpeakerConfig(UINT32& channels, DWORD& mask)
	{
		if (GameAcceptsSpeakerConfig(channels, mask))
		{
			return;
		}

		if (channels >= 6) { channels = 6; mask = 0x3F; } // SPEAKER_5POINT1
		else if (channels >= 4) { channels = 4; mask = 0x33; } // SPEAKER_QUAD
		else { channels = 2; mask = 0x03; } // SPEAKER_STEREO
	}

	struct EndpointInfo
	{
		std::wstring Id = L"XAudio29.Default";
		std::wstring Name = L"Default audio device";
		UINT32 Channels = 2;
		UINT32 SampleRate = 48000;
		DWORD ChannelMask = 0x03;
	};

	// PKEY_Device_FriendlyName
	const PROPERTYKEY XA_PKEY_Device_FriendlyName =
	{ { 0xA45C254E, 0xDF1C, 0x4EFD, { 0x80, 0x20, 0x67, 0xD1, 0x46, 0xA8, 0x50, 0xE0 } }, 14 };

	EndpointInfo QueryDefaultRenderEndpoint()
	{
		EndpointInfo info;

		IMMDeviceEnumerator* enumerator = nullptr;
		if (FAILED(CoCreateInstance(__uuidof(MMDeviceEnumerator), nullptr, CLSCTX_INPROC_SERVER, __uuidof(IMMDeviceEnumerator), reinterpret_cast<void**>(&enumerator))) || !enumerator)
		{
			return info;
		}

		IMMDevice* device = nullptr;
		if (SUCCEEDED(enumerator->GetDefaultAudioEndpoint(eRender, eConsole, &device)) && device)
		{
			LPWSTR id = nullptr;
			if (SUCCEEDED(device->GetId(&id)) && id)
			{
				info.Id = id;
				CoTaskMemFree(id);
			}

			IPropertyStore* store = nullptr;
			if (SUCCEEDED(device->OpenPropertyStore(STGM_READ, &store)) && store)
			{
				PROPVARIANT var;
				PropVariantInit(&var);
				if (SUCCEEDED(store->GetValue(XA_PKEY_Device_FriendlyName, &var)) && var.vt == VT_LPWSTR && var.pwszVal)
				{
					info.Name = var.pwszVal;
				}
				PropVariantClear(&var);
				store->Release();
			}

			IAudioClient* client = nullptr;
			if (SUCCEEDED(device->Activate(__uuidof(IAudioClient), CLSCTX_ALL, nullptr, reinterpret_cast<void**>(&client))) && client)
			{
				WAVEFORMATEX* mix = nullptr;
				if (SUCCEEDED(client->GetMixFormat(&mix)) && mix)
				{
					info.Channels = mix->nChannels;
					info.SampleRate = mix->nSamplesPerSec;
					if (mix->wFormatTag == WAVE_FORMAT_EXTENSIBLE && mix->cbSize >= 22)
					{
						info.ChannelMask = reinterpret_cast<WAVEFORMATEXTENSIBLE*>(mix)->dwChannelMask;
					}
					else
					{
						info.ChannelMask = (mix->nChannels == 1) ? 0x04 : 0x03;
					}
					CoTaskMemFree(mix);
				}
				client->Release();
			}
			device->Release();
		}

		enumerator->Release();

		if (info.SampleRate == 0)
		{
			info.SampleRate = 48000;
		}

		return info;
	}

	const GUID XA_KSDATAFORMAT_SUBTYPE_PCM =
	{ 0x00000001, 0x0000, 0x0010, { 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71 } };

	void FillDeviceDetails(XA_DEVICE_DETAILS* out)
	{
		memset(out, 0, sizeof(*out));

		EndpointInfo info = QueryDefaultRenderEndpoint();
		NormalizeSpeakerConfig(info.Channels, info.ChannelMask);

		wcsncpy_s(out->DeviceID, info.Id.c_str(), _TRUNCATE);
		wcsncpy_s(out->DisplayName, info.Name.c_str(), _TRUNCATE);
		out->Role = 0xF; // GlobalDefaultDevice

		WAVEFORMATEXTENSIBLE& fmt = out->OutputFormat;
		fmt.Format.wFormatTag = WAVE_FORMAT_EXTENSIBLE;
		fmt.Format.nChannels = static_cast<WORD>(info.Channels);
		fmt.Format.nSamplesPerSec = info.SampleRate;
		fmt.Format.wBitsPerSample = 16;
		fmt.Format.nBlockAlign = static_cast<WORD>(info.Channels * 2);
		fmt.Format.nAvgBytesPerSec = fmt.Format.nSamplesPerSec * fmt.Format.nBlockAlign;
		fmt.Format.cbSize = 22;
		fmt.Samples.wValidBitsPerSample = 16;
		fmt.dwChannelMask = info.ChannelMask;
		fmt.SubFormat = XA_KSDATAFORMAT_SUBTYPE_PCM;
	}
}

class XA26EngineWrap final : public XA26_IXAudio2
{
public:
	XA29_IXAudio2* real = nullptr;
	LONG refCount = 1;

	explicit XA26EngineWrap(XA29_IXAudio2* realEngine) : real(realEngine) {}

	HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppv) override
	{
		if (!ppv) return E_POINTER;
		if (IsEqualGUID(riid, XA_IID_IUnknown_Local) || IsEqualGUID(riid, XA_IID_IXAudio2_26))
		{
			AddRef();
			*ppv = this;
			return S_OK;
		}

		*ppv = nullptr;
		return E_NOINTERFACE;
	}

	ULONG STDMETHODCALLTYPE AddRef() override
	{
		return static_cast<ULONG>(InterlockedIncrement(&refCount));
	}

	ULONG STDMETHODCALLTYPE Release() override
	{
		LONG rc = InterlockedDecrement(&refCount);
		if (rc == 0)
		{
			if (real)
			{
				real->Release();
			}
			delete this;
		}

		return static_cast<ULONG>(rc < 0 ? 0 : rc);
	}

	HRESULT STDMETHODCALLTYPE GetDeviceCount(UINT32* pCount) override
	{
		if (!pCount) return E_POINTER;
		*pCount = 1;
		return S_OK;
	}

	HRESULT STDMETHODCALLTYPE GetDeviceDetails(UINT32 Index, XA_DEVICE_DETAILS* pDeviceDetails) override
	{
		if (!pDeviceDetails) return E_POINTER;
		if (Index != 0) return XA_E_INVALID_CALL; // what 2.6 returns, not E_INVALIDARG
		FillDeviceDetails(pDeviceDetails);
		return S_OK;
	}

	HRESULT STDMETHODCALLTYPE Initialize(UINT32 Flags, UINT32 XAudio2Processor) override
	{
		return S_OK; // 2.9 initializes inside XAudio2Create
	}

	HRESULT STDMETHODCALLTYPE RegisterForCallbacks(XA_IXAudio2EngineCallback* pCallback) override
	{
		return real->RegisterForCallbacks(pCallback);
	}

	void STDMETHODCALLTYPE UnregisterForCallbacks(XA_IXAudio2EngineCallback* pCallback) override
	{
		real->UnregisterForCallbacks(pCallback);
	}

	HRESULT STDMETHODCALLTYPE CreateSourceVoice(XA26_IXAudio2SourceVoice** ppSourceVoice, const WAVEFORMATEX* pSourceFormat, UINT32 Flags, float MaxFrequencyRatio, XA_IXAudio2VoiceCallback* pCallback, const XA_VOICE_SENDS* pSendList, const XA_EFFECT_CHAIN* pEffectChain) override
	{
		if (!ppSourceVoice) return E_POINTER;
		*ppSourceVoice = nullptr;

		// music voices come tagged XAUDIO2_VOICE_MUSIC, gone in 2.8+ where unknown bits fail the call, keep NOPITCH | NOSRC | USEFILTER, drop the rest
		const UINT32 flags29 = Flags & 0x0E;

		TranslatedSends t;
		TranslatedChain c;
		const XA_VOICE_SENDS* sends = t.Translate(pSendList);
		if (t.Malformed || t.InvalidDest)
		{
			return XA_E_INVALID_CALL;
		}

		const XA_EFFECT_CHAIN* chain = c.Translate(pEffectChain);
		bool chainApplied = true;

		XA29_IXAudio2SourceVoice* realVoice = nullptr;
		HRESULT hr = real->CreateSourceVoice(&realVoice, pSourceFormat, flags29, MaxFrequencyRatio, pCallback, sends, chain);

		if (FAILED(hr) && chain)
		{
			hr = real->CreateSourceVoice(&realVoice, pSourceFormat, flags29, MaxFrequencyRatio, pCallback, sends, nullptr);
			chainApplied = false;
		}

		std::vector<unsigned char> kinds;
		if (chainApplied)
		{
			kinds = std::move(c.Kinds);
		}

		if (SUCCEEDED(hr) && realVoice)
		{
			XA26SourceVoiceWrap* wrap = new XA26SourceVoiceWrap();
			wrap->real = realVoice;
			wrap->SetKinds(std::move(kinds));
			RegisterVoice(static_cast<XA26_IXAudio2Voice*>(wrap), realVoice);
			*ppSourceVoice = wrap;
		}
		return hr;
	}

	HRESULT STDMETHODCALLTYPE CreateSubmixVoice(XA26_IXAudio2SubmixVoice** ppSubmixVoice, UINT32 InputChannels, UINT32 InputSampleRate, UINT32 Flags, UINT32 ProcessingStage, const XA_VOICE_SENDS* pSendList, const XA_EFFECT_CHAIN* pEffectChain) override
	{
		if (!ppSubmixVoice) return E_POINTER;
		*ppSubmixVoice = nullptr;

		const UINT32 safeChannels = (InputChannels >= 1 && InputChannels <= 64) ? InputChannels : 6;
		const UINT32 safeRate = (InputSampleRate >= 1000 && InputSampleRate <= 200000) ? InputSampleRate : 48000;

		TranslatedSends t;
		TranslatedChain c;
		const XA_VOICE_SENDS* sends = t.Translate(pSendList);
		if (t.Malformed || t.InvalidDest)
		{
			return XA_E_INVALID_CALL;
		}

		const XA_EFFECT_CHAIN* chain = c.Translate(pEffectChain);
		bool chainApplied = true;

		XA29_IXAudio2SubmixVoice* realVoice = nullptr;
		HRESULT hr = real->CreateSubmixVoice(&realVoice, safeChannels, safeRate, Flags, ProcessingStage, sends, chain);

		if (FAILED(hr) && chain == &c.Chain)
		{
			c.ForceOutputChannels(safeChannels);
			hr = real->CreateSubmixVoice(&realVoice, safeChannels, safeRate, Flags, ProcessingStage, sends, chain);
		}

		if (FAILED(hr) && chain)
		{
			hr = real->CreateSubmixVoice(&realVoice, safeChannels, safeRate, Flags, ProcessingStage, sends, nullptr);
			chainApplied = false;
		}

		if (FAILED(hr) && sends)
		{
			hr = real->CreateSubmixVoice(&realVoice, safeChannels, safeRate, Flags, ProcessingStage, nullptr, nullptr);
			chainApplied = false;
		}

		if (FAILED(hr))
		{
			hr = real->CreateSubmixVoice(&realVoice, safeChannels, safeRate, 0, ProcessingStage, nullptr, nullptr);
			chainApplied = false;
		}

		std::vector<unsigned char> kinds;
		if (chainApplied)
		{
			kinds = std::move(c.Kinds);
		}

		if (SUCCEEDED(hr) && realVoice)
		{
			// the game runs its reverb fully wet, left without it this submix would play every reverb send a second time, dry
			if (!chainApplied && c.HasReverb)
			{
				realVoice->SetVolume(0.0f, 0);
			}

			XA26SubmixVoiceWrap* wrap = new XA26SubmixVoiceWrap();
			wrap->real = realVoice;
			wrap->SetKinds(std::move(kinds));
			RegisterVoice(static_cast<XA26_IXAudio2Voice*>(wrap), realVoice);
			*ppSubmixVoice = wrap;
		}
		return hr;
	}

	HRESULT STDMETHODCALLTYPE CreateMasteringVoice(XA26_IXAudio2MasteringVoice** ppMasteringVoice, UINT32 InputChannels, UINT32 InputSampleRate, UINT32 Flags, UINT32 DeviceIndex, const XA_EFFECT_CHAIN* pEffectChain) override
	{
		if (!ppMasteringVoice) return E_POINTER;
		*ppMasteringVoice = nullptr;

		TranslatedChain c;
		const XA_EFFECT_CHAIN* chain = c.Translate(pEffectChain);
		bool chainApplied = true;

		XA29_IXAudio2MasteringVoice* realVoice = nullptr;
		HRESULT hr = real->CreateMasteringVoice(&realVoice, InputChannels, InputSampleRate, Flags, nullptr, chain, XA29_AudioCategory_GameEffects);

		if (FAILED(hr) && chain)
		{
			hr = real->CreateMasteringVoice(&realVoice, InputChannels, InputSampleRate, Flags, nullptr, nullptr, XA29_AudioCategory_GameEffects);
			chainApplied = false;
		}

		std::vector<unsigned char> kinds;
		if (chainApplied)
		{
			kinds = std::move(c.Kinds);
		}

		if (SUCCEEDED(hr) && realVoice)
		{
			XA26MasteringVoiceWrap* wrap = new XA26MasteringVoiceWrap();
			wrap->real = realVoice;
			wrap->SetKinds(std::move(kinds));
			RegisterVoice(static_cast<XA26_IXAudio2Voice*>(wrap), realVoice);
			*ppMasteringVoice = wrap;
		}
		return hr;
	}

	HRESULT STDMETHODCALLTYPE StartEngine() override
	{
		return real->StartEngine();
	}

	void STDMETHODCALLTYPE StopEngine() override
	{
		real->StopEngine();
	}

	HRESULT STDMETHODCALLTYPE CommitChanges(UINT32 OperationSet) override
	{
		return real->CommitChanges(OperationSet);
	}

	void STDMETHODCALLTYPE GetPerformanceData(void* pPerfData) override
	{
		if (!pPerfData) return;
		real->GetPerformanceData(pPerfData);
	}

	void STDMETHODCALLTYPE SetDebugConfiguration(const XA_DEBUG_CONFIGURATION* /*pDebugConfiguration*/, void* /*pReserved*/) override
	{

	}
};

static safetyhook::InlineHook XAudio2CreateEngine;

static HRESULT __cdecl XAudio2CreateEngine_Hook(void** ppOut, uint32_t flags, uint32_t processor)
{
	if (ppOut && LoadXAudio29())
	{
		XA29_IXAudio2* realEngine = nullptr;
		if (SUCCEEDED(g_pfnXAudio2Create(&realEngine, 0, XA29_PROCESSOR_DEFAULT)) && realEngine)
		{
			*ppOut = static_cast<XA26_IXAudio2*>(new XA26EngineWrap(realEngine));
			return S_OK;
		}
	}

	return XAudio2CreateEngine.ccall<HRESULT, void**, uint32_t, uint32_t>(ppOut, flags, processor);
}

void ApplyXAudio2Upgrade()
{
	if (!UpgradeToXAudio29) return;

	XAudio2CreateEngine = HookHelper::CreateHook((void*)GetAddress(Addr::XAudio2CreateEngine), &XAudio2CreateEngine_Hook);
}