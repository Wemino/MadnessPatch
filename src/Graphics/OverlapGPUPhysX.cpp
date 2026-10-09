#include "Common.hpp"
#include "Features.hpp"

static safetyhook::MidHook DrawQueuedHook{};
static safetyhook::MidHook DrawQueuedWrapHook{};
static safetyhook::InlineHook BeginDrawingHook{};
static safetyhook::InlineHook WaitPhysCompartmentsHook{};
static safetyhook::InlineHook FrameEndSyncHook{};
static safetyhook::InlineHook RenderFenceWaitHook{};
static safetyhook::InlineHook RingBufferAllocateHook{};
static safetyhook::InlineHook AppSleepHook{};

constexpr double TimeoutSeconds = 0.03;

// Drawings queued by the game thread, allowed to start and started by the rendering thread, numbered alike
static std::atomic<LONG> QueuedDraws{ 0 };
static std::atomic<LONG> ReleasedDraws{ 0 };
static LONG StartedDraws = 0;
static LONG DrawsAtLastSync = 0;
static bool bFetchedSinceDraw = false;
static HANDLE ReleaseEvent = nullptr;
static uintptr_t RenderCommandBuffer = 0;
static uintptr_t PhysXSDK = 0;
static double TicksPerSecond = 0.0;
static DWORD GameThreadId = 0;

static void Release(LONG Draw)
{
	LONG Released = ReleasedDraws.load();
	while (Draw > Released && !ReleasedDraws.compare_exchange_weak(Released, Draw)) {}
	if (Draw > Released) SetEvent(ReleaseEvent);
}

// FViewport::Draw queued a BeginDrawingCommand (two paths, the second when the buffer wraps around).
// It's held if PhysX results were fetched in this frame, the next frame will fetch them too
static void OnDrawQueued(safetyhook::Context&)
{
	GameThreadId = GetCurrentThreadId();
	const LONG Draw = ++QueuedDraws;
	if (!bFetchedSinceDraw) Release(Draw);
	bFetchedSinceDraw = false;
}

// Rendering thread
static UINT __fastcall BeginDrawing_Hook(void* Command)
{
	const LONG Draw = ++StartedDraws;
	if (ReleasedDraws < Draw)
	{
		LARGE_INTEGER Start, Now;
		QueryPerformanceCounter(&Start);
		for (;;)
		{
			QueryPerformanceCounter(&Now);
			const double Left = TimeoutSeconds - double(Now.QuadPart - Start.QuadPart) / TicksPerSecond;
			if (ReleasedDraws >= Draw || Left <= 0.0) break;
			WaitForSingleObject(ReleaseEvent, static_cast<DWORD>(Left * 1000.0) + 1);
		}
	}

	return BeginDrawingHook.unsafe_thiscall<UINT>(Command);
}

// NxPhysicsSDK::getHWVersion, what the game checks for hardware PhysX (0 = none, PhysX on the CPU)
static bool IsGPUPhysX()
{
	void* SDK = *reinterpret_cast<void**>(PhysXSDK);
	if (!SDK) return false;
	using GetHWVersion_t = int(__thiscall*)(void*);
	return reinterpret_cast<GetHWVersion_t>((*reinterpret_cast<void***>(SDK))[0x7C / 4])(SDK) != 0;
}

static int __cdecl WaitPhysCompartments_Hook(void* Scene)
{
	const int Result = WaitPhysCompartmentsHook.unsafe_ccall<int>(Scene);
	Release(QueuedDraws);
	bFetchedSinceDraw = IsGPUPhysX();
	return Result;
}

// FFrameEndSync::Sync waits for the rendering thread to reach its previous call (or this one, without the one frame lag)
static BOOL __fastcall FrameEndSync_Hook(void* Sync, void*, int bAllowOneFrameThreadLag)
{
	const LONG Queued = QueuedDraws;
	Release(bAllowOneFrameThreadLag ? DrawsAtLastSync : Queued);
	DrawsAtLastSync = Queued;
	return FrameEndSyncHook.unsafe_thiscall<BOOL>(Sync, bAllowOneFrameThreadLag);
}

// FRenderCommandFence::Wait, also behind FlushRenderingCommands
static DWORD __fastcall RenderFenceWait_Hook(void* Fence, void*, unsigned int NumPending)
{
	Release(QueuedDraws);
	return RenderFenceWaitHook.unsafe_thiscall<DWORD>(Fence, NumPending);
}

// FRingBuffer::AllocationContext spins while the buffer is full, a quarter of it is kept free while a drawing is held
static void* __fastcall RingBufferAllocate_Hook(void* Context, void*, uintptr_t* RingBuffer, int AllocationSize)
{
	if (reinterpret_cast<uintptr_t>(RingBuffer) == RenderCommandBuffer && ReleasedDraws < QueuedDraws)
	{
		// Data, DataEnd, WritePointer, bIsWriting, ReadPointer
		const uintptr_t Data = RingBuffer[0], DataEnd = RingBuffer[1], WritePointer = RingBuffer[2], ReadPointer = RingBuffer[4];
		const uintptr_t Free = ReadPointer > WritePointer ? ReadPointer - WritePointer : (DataEnd - WritePointer) + (ReadPointer - Data);
		if (Free < (DataEnd - Data) / 4) Release(QueuedDraws);
	}
	return RingBufferAllocateHook.unsafe_thiscall<void*>(Context, RingBuffer, AllocationSize);
}

// appSleep, on the game thread mostly the frame limiter waiting for the rest of the frame
static void __cdecl AppSleep_Hook(float Seconds)
{
	if (GetCurrentThreadId() == GameThreadId) Release(QueuedDraws);
	AppSleepHook.unsafe_ccall<void>(Seconds);
}

void ApplyOverlapGPUPhysX()
{
	if (!OverlapGPUPhysX) return;

	LARGE_INTEGER Frequency;
	QueryPerformanceFrequency(&Frequency);
	TicksPerSecond = double(Frequency.QuadPart);
	ReleaseEvent = CreateEventA(nullptr, FALSE, FALSE, nullptr);
	RenderCommandBuffer = GetAddress(Addr::RenderCommandBuffer);
	PhysXSDK = GetAddress(Addr::PhysXSDK);

	DrawQueuedHook = safetyhook::create_mid(GetAddress(Addr::DrawQueued), OnDrawQueued);
	DrawQueuedWrapHook = safetyhook::create_mid(GetAddress(Addr::DrawQueuedWrap), OnDrawQueued);
	BeginDrawingHook = HookHelper::CreateHook((void*)GetAddress(Addr::BeginDrawingCommand), &BeginDrawing_Hook);
	WaitPhysCompartmentsHook = HookHelper::CreateHook((void*)GetAddress(Addr::WaitPhysCompartments), &WaitPhysCompartments_Hook);
	FrameEndSyncHook = HookHelper::CreateHook((void*)GetAddress(Addr::FrameEndSync), &FrameEndSync_Hook);
	RenderFenceWaitHook = HookHelper::CreateHook((void*)GetAddress(Addr::RenderFenceWait), &RenderFenceWait_Hook);
	RingBufferAllocateHook = HookHelper::CreateHook((void*)GetAddress(Addr::RingBufferAllocate), &RingBufferAllocate_Hook);
	AppSleepHook = HookHelper::CreateHook((void*)GetAddress(Addr::AppSleep), &AppSleep_Hook);
}
