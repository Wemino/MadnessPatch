#include "Common.hpp"
#include "Features.hpp"

safetyhook::InlineHook GFx_LoadRootMovie;
static safetyhook::MidHook MenuScriptMid{};

static uint8_t* g_letterboxBuf = nullptr;
static uint8_t* g_memoryBuf = nullptr;

static void ApplyLetterbox(uint8_t* buf)
{
	// Reposition the top/bottom letterbox bars for the current aspect (Scaleform stage is 1280x720)
	double stageH = 1280.0 * (double)g_State.screenHeight / (double)g_State.screenWidth;
	double half = (stageH - 720.0) / 2.0;
	if (half < 0.0) half = 0.0; // 16:9 or wider -> no change

	int bottom = (int)(720.0 + half + 0.5);
	double top = -half;

	uint32_t halves[2];
	std::memcpy(halves, &top, 8);
	uint32_t swapped[2] = { halves[1], halves[0] };

	MemoryHelper::WriteMemory<int>((uintptr_t)(buf + 0x121), bottom, false);
	MemoryHelper::WriteMemoryRaw((uintptr_t)(buf + 0xF1), swapped, 8, false);
}

static void ApplyMemoryPosition(uint8_t* buf)
{
	double stageH = 1280.0 * (double)g_State.screenHeight / (double)g_State.screenWidth;
	double half = (stageH - 720.0) / 2.0;
	if (half < 0.0) half = 0.0; // 16:9 or wider -> no change

	int bottom = (int)(720.0 + half + 0.5);

	MemoryHelper::WriteMemory<int>((uintptr_t)(buf + 0x5116), bottom, false);
}

// Re-apply the letterbox geometry after a resolution change
void ReapplyMenuLetterbox()
{
	uint8_t* buf = g_letterboxBuf;
	if (!g_letterboxBuf)
		return;

	if (!MemoryHelper::IsWritable(buf, 0x125))
		return;
	if (MemoryHelper::ReadMemory<uint32_t>((uintptr_t)buf) != 0x0D009688)
		return;

	ApplyLetterbox(buf);
}

void ReapplyMemoryPosition()
{
	uint8_t* buf = g_memoryBuf;
	if (!g_memoryBuf)
		return;

	if (!MemoryHelper::IsWritable(buf, 0x511A))
		return;
	if (MemoryHelper::ReadMemory<uint32_t>((uintptr_t)buf) != 0x18159B88)
		return;

	ApplyMemoryPosition(buf);
}

struct BytePatch
{
	uint32_t header;
	uint32_t offset;
	uint8_t  from;
};

static const BytePatch kBytePatches[] =
{
	// Patch the menu to show the PC version of "video" settings inside the controller menu
	{ 0x1F017788, 0x308, 0x1B },
	{ 0x1F017788, 0x366, 0x1B },
	{ 0x1F017788, 0x444, 0x1B },
	{ 0x1F017788, 0x4A3, 0x1B },
	{ 0x1F017788, 0x3C0, 0x2E },
	{ 0xA2076888, 0x7AD, 0x10 },
	{ 0xA2076888, 0x858, 0x10 },
	{ 0xA409AC88, 0xD2D, 0x14 },

	// Apply the difficulty change directly instead of raising the unlocalized confirm popup
	{ 0x5B03C188, 0xC76, 0x6C },
};

static const BytePatch kCursorBytePatches[] =
{
	{ 0x50030788, 0x880, 0xC1 },
	{ 0x50030788, 0x8B5, 0xC1 },
	{ 0xA6069A88, 0x302B, 0xC1 },
	{ 0xA3066288, 0x2E5B, 0xC1 },
	{ 0x4C024C88, 0xA97, 0xC1 },
	{ 0x18159B88, 0x694D, 0x8A },
};

static void ApplyPatchTable(uint8_t* buf, uint32_t size, uint32_t sig, const BytePatch* table, size_t count)
{
	for (size_t i = 0; i < count; i++)
	{
		const BytePatch& patch = table[i];
		if (sig != patch.header || patch.offset >= size) continue;

		uintptr_t address = (uintptr_t)(buf + patch.offset);
		if (MemoryHelper::ReadMemory<uint8_t>(address) == patch.from)
		{
			MemoryHelper::WriteMemory<uint8_t>(address, 0x00, false);
		}
	}
}

static void ApplyMenuBytePatches(uint8_t* buf, uint32_t size, uint32_t sig)
{
	if (!EnableControllerIcons) return;
	if (!ControllerHelper::IsConnected()) return;

	ApplyPatchTable(buf, size, sig, kBytePatches, std::size(kBytePatches));

	if (RestoreMenuMouseCursor)
	{
		ApplyPatchTable(buf, size, sig, kCursorBytePatches, std::size(kCursorBytePatches));
	}
}

// Older extraContentMc gives the Chapter 6 Theatricals entries the Chapter 3 title keys
namespace TheatricalsTitles
{
	constexpr uint32_t BlobSize = 0x218AA; // GFX file length of the affected build
	constexpr uint32_t SpriteHdr = 0x929D; // DefineSprite (id 91) tag header
	constexpr uint32_t SpriteLen = 0x74AB;
	constexpr uint32_t ActionHdr = 0x92A7; // DoAction tag header
	constexpr uint32_t ActionLen = 0x749D;
	constexpr uint32_t ActionBody = 0x92AD; // ActionConstantPool starts here
	constexpr uint32_t PoolSig = 0xA0383A88; // 0x88, payload 0x383A, 672 strings
	constexpr uint32_t PoolEnd = 0xCAEA; // one past the last pooled string

	// Appended after the last pooled string, so no existing index shifts
	static const char NewStrings[] =
		"FlashUI_ExtraContent_TheatricalsCH6_3\0"
		"FlashUI_ExtraContent_TheatricalsCH6_2\0"
		"FlashUI_ExtraContent_TheatricalsCH6_1";

	constexpr uint32_t Growth = sizeof(NewStrings);

	struct TitleRef
	{
		uint32_t stringOffset;
		uint32_t operandOffset;
		uint16_t index;
		const char* expected;
	};

	static const TitleRef Titles[3] =
	{
		{ 0xC3AF, 0x10144, 581, "FlashUI_ExtraContent_TheatricalsCH3_3" }, // plays C6_6111
		{ 0xC3DD, 0x10161, 583, "FlashUI_ExtraContent_TheatricalsCH3_2" }, // plays C6_617
		{ 0xC40A, 0x1017E, 585, "FlashUI_ExtraContent_TheatricalsCH3_1" }, // plays C6_614
	};

	// Strict on purpose: a build that already has the fix differs from the first check onwards
	static bool NeedsFix(const uint8_t* blob, uint32_t size)
	{
		if (size != BlobSize) return false;
		if (*(const uint32_t*)(blob + 0x04) != BlobSize) return false;
		if (*(const uint16_t*)(blob + SpriteHdr) != ((39 << 6) | 0x3F)) return false;
		if (*(const uint32_t*)(blob + SpriteHdr + 2) != SpriteLen) return false;
		if (*(const uint16_t*)(blob + ActionHdr) != ((12 << 6) | 0x3F)) return false;
		if (*(const uint32_t*)(blob + ActionHdr + 2) != ActionLen) return false;
		if (*(const uint32_t*)(blob + ActionBody) != PoolSig) return false;

		for (const TitleRef& title : Titles)
		{
			if (*(const uint16_t*)(blob + title.operandOffset) != title.index) return false;
			if (std::memcmp(blob + title.stringOffset, title.expected, std::strlen(title.expected) + 1) != 0) return false;
		}

		return true;
	}

	// Re-read the rebuilt movie; on failure the caller drops it and the original is loaded untouched
	static bool Verify(const std::vector<uint8_t>& fixed)
	{
		const uint8_t* out = fixed.data();
		uint32_t size = (uint32_t)fixed.size();

		if (size != BlobSize + Growth) return false;
		if (*(const uint32_t*)(out + 0x04) != size) return false;
		if (*(const uint32_t*)(out + SpriteHdr + 2) != SpriteLen + Growth) return false;
		if (*(const uint32_t*)(out + ActionHdr + 2) != ActionLen + Growth) return false;

		const uint8_t* body = out + ActionBody;
		uint32_t bodyLen = ActionLen + Growth;

		if (*(const uint16_t*)(body + 3) != 675) return false;
		if (3u + *(const uint16_t*)(body + 1) > bodyLen) return false;

		// Where a pool length that disagrees with the code block shows up
		if (body[bodyLen - 1] != 0x00) return false;

		// Walk the tag stream to the End tag, past the 8 byte header, the frame RECT, and the rate/count
		uint32_t at = 8 + (5u + (out[8] >> 3) * 4u + 7u) / 8u + 4;
		while (at + 2 <= size)
		{
			uint16_t header = *(const uint16_t*)(out + at);
			uint32_t code = header >> 6;
			uint32_t length = header & 0x3F;
			uint32_t headerSize = 2;
			if (length == 0x3F)
			{
				length = *(const uint32_t*)(out + at + 2); headerSize = 6;
			}
			if (code == 0) return at + headerSize + length == size;
			at += headerSize + length;
		}

		return false;
	}

	// Built once and kept: GFx copies the script out during the load and never writes back
	static const std::vector<uint8_t>& Build(const uint8_t* blob, uint32_t size)
	{
		static std::vector<uint8_t> fixed;
		static bool built = false;

		if (built) return fixed;
		built = true;

		fixed.reserve(size + Growth);
		fixed.assign(blob, blob + PoolEnd);
		fixed.insert(fixed.end(), NewStrings, NewStrings + Growth);
		fixed.insert(fixed.end(), blob + PoolEnd, blob + size);

		uint8_t* out = fixed.data();

		*(uint32_t*)(out + 0x04) += Growth; // GFX file length
		*(uint32_t*)(out + SpriteHdr + 2) += Growth; // DefineSprite (id 91)
		*(uint32_t*)(out + ActionHdr + 2) += Growth; // DoAction
		*(uint16_t*)(out + ActionBody + 1) += Growth; // ActionConstantPool payload
		*(uint16_t*)(out + ActionBody + 3) += 3; // ActionConstantPool string count

		// Operands sit after the insertion, and every jump is relative, so shifting the code block is harmless
		uint16_t next = *(const uint16_t*)(blob + ActionBody + 3);
		for (const TitleRef& title : Titles)
		{
			*(uint16_t*)(out + title.operandOffset + Growth) = next++;
		}

		if (!Verify(fixed))
		{
			fixed.clear();
		}

		return fixed;
	}
}

static int __fastcall GFx_LoadRootMovie_Hook(uint32_t thisp, uint32_t, uint32_t a2, uint32_t a3)
{
	uint32_t tr = *(uint32_t*)(a2 + 0x314);
	if (!tr) tr = a2 + 0x28;

	uint8_t** swappedData = nullptr;
	uint32_t* swappedSize = nullptr;
	uint8_t* originalData = nullptr;
	uint32_t originalSize = 0;

	uint32_t src = *(uint32_t*)(tr + 0x10);
	if (src)
	{
		uint8_t* blob = *(uint8_t**)(src + 0x08);
		uint32_t size = blob ? *(uint32_t*)(src + 0x0C) : 0;

		if (blob && blob[0] == 'G' && blob[1] == 'F' && blob[2] == 'X')
		{
			if (EnableControllerIcons && ControllerHelper::IsConnected() && size == 0x1764F && blob[0x10998] == 0xC2)
			{
				static const uint8_t act[66] =
				{
					0x96, 0x05, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00,                               // Push 0  (arg count)
					0x96, 0x0A, 0x00, 0x00, 0x67, 0x65, 0x74, 0x44, 0x65, 0x70, 0x74, 0x68, 0x00, // Push "getDepth"
					0x3D,                                                                         // CallFunction
					0x96, 0x05, 0x00, 0x07, 0x20, 0x00, 0x00, 0x00,                               // Push 0x20
					0x60,                                                                         // BitAnd
					0x9D, 0x02, 0x00, 0x0B, 0x00,                                                 // If +11 -> console
					0x8C, 0x03, 0x00, 0x70, 0x63, 0x00,                                           // GoToLabel "pc"
					0x99, 0x02, 0x00, 0x0B, 0x00,                                                 // Jump +11 -> End
					0x8C, 0x08, 0x00, 0x63, 0x6F, 0x6E, 0x73, 0x6F, 0x6C, 0x65, 0x00,             // GoToLabel "console"
					0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00                                      // End + pad
				};
				memcpy(blob + 0x109A2, act, 66);
			}

			if (size > 0x24000 && blob[0x80E0] == 0x96 && blob[0x80EE] == 0x49 && blob[0x80EF] == 0x12 && blob[0x80F0] == 0x9D && blob[0x80F3] == 0x28)
			{
				if (ShowProfileCreation)
				{
					blob[0x80F3] = 0x00; // always show profile
				}
				else
				{
					blob[0x80EA] = 0x09; // never show profile
				}
			}

			if (FixTheatricalsTitles && TheatricalsTitles::NeedsFix(blob, size))
			{
				const std::vector<uint8_t>& fixed = TheatricalsTitles::Build(blob, size);

				uint32_t* fileEnd = (uint32_t*)(a2 + 0x270);
				if (!fixed.empty() && *fileEnd == size)
				{
					swappedData = (uint8_t**)(src + 0x08);
					swappedSize = (uint32_t*)(src + 0x0C);
					originalData = blob;
					originalSize = size;

					*swappedData = const_cast<uint8_t*>(fixed.data());
					*swappedSize = (uint32_t)fixed.size();
					*fileEnd = (uint32_t)fixed.size();
				}
			}
		}
	}

	int result = GFx_LoadRootMovie.unsafe_thiscall<int>(thisp, a2, a3);

	// Hand the engine its own allocation back
	if (swappedData)
	{
		*swappedData = originalData;
		*swappedSize = originalSize;
	}

	return result;
}


static void OnMenuScript(safetyhook::Context& ctx)
{
	uint8_t* buf = *(uint8_t**)(ctx.esi + 8);
	if (!buf) return;

	uint32_t size = *(uint32_t*)(ctx.esi + 0xC);
	uint32_t sig = MemoryHelper::ReadMemory<uint32_t>((uintptr_t)buf);

	if (FixAspectRatio && sig == 0x0D009688)
	{
		g_letterboxBuf = buf;
		ApplyLetterbox(buf);
	}
	else if (FixAspectRatio && sig == 0x18159B88)
	{
		g_memoryBuf = buf;
		ApplyMemoryPosition(buf);
	}
	else if (HideAlice1WhenMissing && g_State.isAlice1Missing && sig == 0xA409AC88)
	{
		// Remove the Alice 1 menu entry.
		if (MemoryHelper::ReadMemory<uint8_t>((uintptr_t)(buf + 0xC39)) == 0x5)
		{
			MemoryHelper::WriteMemory<uint8_t>((uintptr_t)(buf + 0xC39), 0xD7, false);
		}
	}

	ApplyMenuBytePatches(buf, size, sig);
}

void ApplyMenuScripts()
{
	GFx_LoadRootMovie = HookHelper::CreateHook((void*)GetAddress(Addr::GFxLoadRootMovie), &GFx_LoadRootMovie_Hook);
	MenuScriptMid = safetyhook::create_mid(GetAddress(Addr::MenuScripts), OnMenuScript);
}