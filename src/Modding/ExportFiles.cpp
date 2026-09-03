#include "Common.hpp"
#include "Features.hpp"

namespace
{
	// UObject. ObjectFlags is 64 bit at +0x08, RF_NeedLoad is bit 41
	constexpr uintptr_t OFF_OBJ_FLAGS_HIGH = 0x0C;
	constexpr uint32_t RF_NEED_LOAD_HIGH = 0x200;
	constexpr uintptr_t OFF_OBJ_LINKER = 0x1C;
	constexpr uintptr_t OFF_OBJ_LINKER_INDEX = 0x20;

	// ULinkerLoad, relative to its FArchive subobject, which is what Preload gets
	constexpr uintptr_t OFF_ARCHIVE_TO_OBJECT = 0x14C;
	constexpr intptr_t OFF_EXPORT_MAP = -0x68;
	constexpr uintptr_t OFF_LOADER = 0x494;
	// Copied over Loader for script-patcher exports only, swapped too so it cannot matter
	constexpr uintptr_t OFF_ORIGINAL_LOADER = 0x4F8;

	// FObjectExport
	constexpr uintptr_t EXPORT_STRIDE = 0x5C;
	constexpr uintptr_t OFF_SERIAL_SIZE = 0x20;
	constexpr uintptr_t OFF_SERIAL_OFFSET = 0x24;

	// UTexture2D, from the SDK: NeverStream is bit 0x100 of the dword at +0x3C
	constexpr uintptr_t OFF_TEX_STREAM_FLAGS = 0x3C;
	constexpr uint32_t TEX_NEVER_STREAM = 0x100;

	// FArchive vtable, 28 slots in declaration order; Tell, Seek, Precache and AttachBulkData
	constexpr uintptr_t VF_SERIALIZE = 0x04;
	constexpr uintptr_t VF_TELL = 0x28;
	constexpr uintptr_t VF_TOTAL_SIZE = 0x2C;
	constexpr uintptr_t VF_AT_END = 0x30;
	constexpr uintptr_t VF_SEEK = 0x34;
	constexpr uintptr_t VF_PRECACHE = 0x40;
	constexpr uintptr_t VF_GET_ERROR = 0x54;
	constexpr size_t ARCHIVE_SLOTS = 28;
	constexpr size_t ARCHIVE_HEADER = 0x100; // the flags ULinkerLoad reads off its Loader directly

	constexpr int32_t MAX_EXPORT = 128 * 1024 * 1024;

	using Serialize_t = void(__thiscall*)(void*, void*, int32_t);
	using Tell_t = int32_t(__thiscall*)(void*);
	using Seek_t = void(__thiscall*)(void*, int32_t);
	using Precache_t = int(__thiscall*)(void*, int32_t, int32_t);

	safetyhook::InlineHook Preload;

	std::atomic<bool> g_globalsReady{ false };

	bool GlobalsReady()
	{
		if (g_globalsReady.load(std::memory_order_relaxed)) return true;

		if (!SDKLoader::AreGlobalsValid() && !SDKLoader::Initialize(EGameBuild::AutoDetect, 0)) return false;

		g_globalsReady.store(true, std::memory_order_relaxed);
		return true;
	}

	std::mutex g_lock;
	std::unordered_map<std::string, std::wstring> g_index; // relative path, lower case -> mod file
	std::unordered_set<std::string> g_leafNames; // last name component, lower case
	std::unordered_set<std::string> g_dumped;
	std::unordered_set<std::wstring> g_dumpFolders;
	std::wstring g_dumpDirectory;
	bool g_replaceReady = false;

	struct MemoryArchive
	{
		void* vtable;
		uint8_t header[ARCHIVE_HEADER];
		void* real;
		const uint8_t* data;
		int32_t base;
		int32_t size;
		int32_t position;

		bool Inside(int32_t at) const { return at >= base && at < base + size; }
	};

	void* g_archiveVtable[ARCHIVE_SLOTS];

	template <typename R, typename... A>
	R Forward(void* target, uintptr_t slot, A... arguments)
	{
		void** vtable = *static_cast<void***>(target);
		return reinterpret_cast<R(__thiscall*)(void*, A...)>(vtable[slot / sizeof(void*)])(target, arguments...);
	}

	void __fastcall Memory_Serialize(MemoryArchive* self, int, void* destination, int32_t length)
	{
		if (length <= 0) return;

		if (!self->Inside(self->position))
		{
			Forward<void>(self->real, VF_SEEK, self->position);
			Forward<void>(self->real, VF_SERIALIZE, destination, length);
			self->position += length;
			return;
		}

		const int32_t offset = self->position - self->base;
		const int32_t take = (length < self->size - offset) ? length : self->size - offset;

		memcpy(destination, self->data + offset, take);

		// Past the end the file does not match the object; hand over zeros rather than stale memory
		if (take < length) memset(static_cast<uint8_t*>(destination) + take, 0, length - take);

		self->position += length;
	}

	int32_t __fastcall Memory_Tell(MemoryArchive* self, int)
	{
		return self->position;
	}

	void __fastcall Memory_Seek(MemoryArchive* self, int, int32_t position)
	{
		self->position = position;
	}

	int __fastcall Memory_Precache(MemoryArchive* self, int, int32_t offset, int32_t length)
	{
		if (self->Inside(offset)) return 1;

		return Forward<int>(self->real, VF_PRECACHE, offset, length);
	}

	int32_t __fastcall Memory_TotalSize(MemoryArchive* self, int)
	{
		return Forward<int32_t>(self->real, VF_TOTAL_SIZE);
	}

	int __fastcall Memory_AtEnd(MemoryArchive* self, int)
	{
		return self->position >= Forward<int32_t>(self->real, VF_TOTAL_SIZE);
	}

	void* __fastcall Memory_Destructor(MemoryArchive* self, int, unsigned) { return self; }
	void __fastcall Memory_SerializeBits(MemoryArchive* self, int, void* a, int32_t b) { Forward<void>(self->real, 0x08, a, b); }
	void __fastcall Memory_SerializeInt(MemoryArchive* self, int, void* a, uint32_t b) { Forward<void>(self->real, 0x0C, a, b); }
	void __fastcall Memory_Preload(MemoryArchive* self, int, void* a) { Forward<void>(self->real, 0x10, a); }
	void __fastcall Memory_CountBytes(MemoryArchive* self, int, size_t a, size_t b) { Forward<void>(self->real, 0x14, a, b); }
	void* __fastcall Memory_SerializeName(MemoryArchive* self, int, void* a) { Forward<void*>(self->real, 0x18, a); return self; }
	void* __fastcall Memory_SerializeObject(MemoryArchive* self, int, void* a) { Forward<void*>(self->real, 0x1C, a); return self; }
	void* __fastcall Memory_GetArchiveName(MemoryArchive* self, int, void* result) { return Forward<void*>(self->real, 0x20, result); }
	void* __fastcall Memory_GetLinker(MemoryArchive* self, int) { return Forward<void*>(self->real, 0x24); }
	void __fastcall Memory_AttachBulkData(MemoryArchive* self, int, void* a, void* b) { Forward<void>(self->real, 0x38, a, b); }
	void __fastcall Memory_DetachBulkData(MemoryArchive* self, int, void* a, int b) { Forward<void>(self->real, 0x3C, a, b); }
	void __fastcall Memory_FlushCache(MemoryArchive* self, int) { Forward<void>(self->real, 0x44); }
	int __fastcall Memory_SetCompressionMap(MemoryArchive* self, int, void* a, int b) { return Forward<int>(self->real, 0x48, a, b); }
	void __fastcall Memory_Flush(MemoryArchive* self, int) { Forward<void>(self->real, 0x4C); }
	int __fastcall Memory_Close(MemoryArchive* self, int) { return Forward<int>(self->real, 0x50); }
	int __fastcall Memory_GetError(MemoryArchive* self, int) { return Forward<int>(self->real, VF_GET_ERROR); }
	void __fastcall Memory_MarkStart(MemoryArchive* self, int, void* a) { Forward<void>(self->real, 0x58, a); }
	void __fastcall Memory_MarkEnd(MemoryArchive* self, int, void* a) { Forward<void>(self->real, 0x5C, a); }
	void __fastcall Memory_WillSerialize(MemoryArchive* self, int, void* a, void* b) { Forward<void>(self->real, 0x60, a, b); }
	int __fastcall Memory_IsCloseComplete(MemoryArchive* self, int, void* a) { return Forward<int>(self->real, 0x64, a); }
	int __fastcall Memory_IsFilterEditorOnly(MemoryArchive* self, int) { return Forward<int>(self->real, 0x68); }
	void __fastcall Memory_SetFilterEditorOnly(MemoryArchive* self, int, int a) { Forward<void>(self->real, 0x6C, a); }

	void BuildArchiveVtable()
	{
#define F(fn) reinterpret_cast<void*>(&fn)
		void* table[ARCHIVE_SLOTS] = {
			F(Memory_Destructor), F(Memory_Serialize), F(Memory_SerializeBits), F(Memory_SerializeInt),
			F(Memory_Preload), F(Memory_CountBytes), F(Memory_SerializeName), F(Memory_SerializeObject),
			F(Memory_GetArchiveName), F(Memory_GetLinker), F(Memory_Tell), F(Memory_TotalSize),
			F(Memory_AtEnd), F(Memory_Seek), F(Memory_AttachBulkData), F(Memory_DetachBulkData),
			F(Memory_Precache), F(Memory_FlushCache), F(Memory_SetCompressionMap), F(Memory_Flush),
			F(Memory_Close), F(Memory_GetError), F(Memory_MarkStart), F(Memory_MarkEnd),
			F(Memory_WillSerialize), F(Memory_IsCloseComplete), F(Memory_IsFilterEditorOnly), F(Memory_SetFilterEditorOnly),
		};
#undef F
		memcpy(g_archiveVtable, table, sizeof(table));
	}

	std::string ToLower(std::string value)
	{
		for (char& character : value)
		{
			character = static_cast<char>(::tolower(static_cast<unsigned char>(character)));
		}

		return value;
	}

	// "Class Package.Group.Name" -> "Package\Class\Group.Name.bin", the layout the tools write and mods are read as
	std::string BuildRelativePath(const std::string& fullName)
	{
		const size_t space = fullName.find(' ');

		if (space == std::string::npos || space + 1 >= fullName.size()) return "";

		const std::string className = fullName.substr(0, space);
		const std::string path = fullName.substr(space + 1);
		const size_t dot = path.find('.');

		if (dot == std::string::npos) return "";

		std::string result = path.substr(0, dot) + "\\" + className + "\\" + path.substr(dot + 1) + ".bin";

		for (char& character : result)
		{
			if (character == '/' || character == ':' || character == '*' || character == '?'
				|| character == '"' || character == '<' || character == '>' || character == '|'
				|| static_cast<unsigned char>(character) < 0x20)
			{
				character = '_';
			}
		}

		return result;
	}

	static int32_t Lzo1xDecompress(const uint8_t* source, int32_t sourceSize, uint8_t* destination, int32_t destinationSize)
	{
		const uint8_t* in = source;
		const uint8_t* inEnd = source + sourceSize;
		uint8_t* out = destination;
		uint8_t* outEnd = destination + destinationSize;

		auto inLeft = [&](int32_t n) { return inEnd - in >= n; };
		auto outLeft = [&](int32_t n) { return outEnd - out >= n; };

		auto copyLiterals = [&](int32_t n) -> bool
		{
			if (!inLeft(n) || !outLeft(n)) return false;
			memcpy(out, in, n);
			in += n; out += n;
			return true;
		};

		auto copyMatch = [&](int32_t distance, int32_t length) -> bool
		{
			if (distance <= 0 || distance > out - destination || !outLeft(length)) return false;
			const uint8_t* from = out - distance;
			for (int32_t i = 0; i < length; ++i) *out++ = *from++;
			return true;
		};

		auto readExtended = [&](int32_t& t, int32_t base) -> bool
		{
			while (true)
			{
				if (!inLeft(1)) return false;
				if (*in != 0) break;
				t += 255; ++in;
			}
			t += base + *in++;
			return true;
		};

		enum { TOP, FIRST_LITERAL_RUN, MATCH, MATCH_DONE, MATCH_NEXT } state;
		int32_t t = 0;
		int32_t trailing = 0;

		if (!inLeft(1)) return -1;

		if (*in > 17)
		{
			t = *in++ - 17;
			if (t < 4) 
			{ 
				trailing = t; state = MATCH_NEXT; 
			}
			else 
			{ 
				if (!copyLiterals(t))
				{
					return -1;
				}
				state = FIRST_LITERAL_RUN; 
			}
		}
		else state = TOP;

		while (true)
		{
			switch (state)
			{
				case TOP:
					if (!inLeft(1)) return -1;
					t = *in++;
					if (t >= 16) { state = MATCH; break; }
					if (t == 0 && !readExtended(t, 15)) return -1;
					if (!copyLiterals(t + 3)) return -1;
					state = FIRST_LITERAL_RUN;
					break;

				case FIRST_LITERAL_RUN:
					if (!inLeft(1)) return -1;
					t = *in++;
					if (t >= 16) { state = MATCH; break; }
					if (!inLeft(1)) return -1;
					if (!copyMatch(1 + 0x0800 + (t >> 2) + (*in++ << 2), 3)) return -1;
					state = MATCH_DONE;
					break;

				case MATCH:
					if (t >= 64)
					{
						if (!inLeft(1)) return -1;
						const int32_t distance = 1 + ((t >> 2) & 7) + (*in++ << 3);
						if (!copyMatch(distance, (t >> 5) + 1)) return -1;
					}
					else if (t >= 32)
					{
						int32_t length = t & 31;
						if (length == 0 && !readExtended(length, 31)) return -1;
						if (!inLeft(2)) return -1;
						const int32_t distance = 1 + (in[0] >> 2) + (in[1] << 6);
						in += 2;
						if (!copyMatch(distance, length + 2)) return -1;
					}
					else if (t >= 16)
					{
						const int32_t base = (t & 8) << 11;
						int32_t length = t & 7;
						if (length == 0 && !readExtended(length, 7)) return -1;
						if (!inLeft(2)) return -1;
						const int32_t d = (in[0] >> 2) + (in[1] << 6);
						in += 2;
						if (base == 0 && d == 0) return static_cast<int32_t>(out - destination); // end of stream
						if (!copyMatch(base + d + 0x4000, length + 2)) return -1;
					}
					else
					{
						if (!inLeft(1)) return -1;
						if (!copyMatch(1 + (t >> 2) + (*in++ << 2), 2)) return -1;
					}
					state = MATCH_DONE;
					break;

				case MATCH_DONE:
					trailing = in[-2] & 3;
					state = trailing ? MATCH_NEXT : TOP;
					break;

				case MATCH_NEXT:
					if (!copyLiterals(trailing)) return -1;
					if (!inLeft(1)) return -1;
					t = *in++;
					state = MATCH;
					break;
				}
		}
	}

	namespace Texture
	{
		constexpr uint32_t PACKAGE_FILE_TAG = 0x9E2A83C1;
		constexpr uint32_t LOADING_CHUNK = 131072;
		constexpr uint32_t FLAG_SEPARATE_FILE = 1 << 0;
		constexpr uint32_t FLAG_LZO = 1 << 4;
		constexpr uint32_t FLAG_UNUSED = 1 << 5;
		constexpr uint32_t FLAG_OTHER_COMPRESSION = (1 << 1) | (1 << 7);
		constexpr size_t DESCRIPTOR = 16;
		constexpr size_t DIMENSIONS = 8;
		constexpr uint32_t MAX_MIP = 64 * 1024 * 1024;

		struct Mip
		{
			size_t position;
			uint32_t flags, count, sizeOnDisk, offset, sizeX, sizeY;
		};

		uint32_t Read32(const uint8_t* at) { uint32_t v; memcpy(&v, at, 4); return v; }
		void Write32(uint8_t* at, uint32_t v) { memcpy(at, &v, 4); }

		bool ReadMip(const uint8_t* blob, size_t size, size_t position, Mip& mip)
		{
			if (position + DESCRIPTOR + DIMENSIONS > size) return false;
			mip.position = position;
			mip.flags = Read32(blob + position);
			mip.count = Read32(blob + position + 4);
			mip.sizeOnDisk = Read32(blob + position + 8);
			mip.offset = Read32(blob + position + 12);
			return true;
		}

		bool Parse(const uint8_t* blob, size_t size, int32_t serialOffset, size_t& tableStart, std::vector<Mip>& mips)
		{
			size_t firstInline = 0;
			bool found = false;

			for (size_t p = 0; p + DESCRIPTOR + DIMENSIONS <= size && !found; ++p)
			{
				Mip m;
				if (!ReadMip(blob, size, p, m)) break;
				if (m.flags != 0 || m.count == 0 || m.count != m.sizeOnDisk) continue;
				if (m.offset != static_cast<uint32_t>(serialOffset) + p + DESCRIPTOR) continue;
				if (p + DESCRIPTOR + m.sizeOnDisk + DIMENSIONS > size) continue;
				firstInline = p;
				found = true;
			}

			if (!found) return false;

			size_t start = firstInline;
			while (start >= 24)
			{
				Mip m;
				if (!ReadMip(blob, size, start - 24, m) || !(m.flags & FLAG_SEPARATE_FILE)) break;
				start -= 24;
			}

			if (start < 4) return false;

			const uint32_t declared = Read32(blob + start - 4);

			mips.clear();
			size_t p = start;

			while (p < firstInline)
			{
				Mip m;
				if (!ReadMip(blob, size, p, m)) return false;
				m.sizeX = Read32(blob + p + DESCRIPTOR);
				m.sizeY = Read32(blob + p + DESCRIPTOR + 4);
				mips.push_back(m);
				p += 24;
			}

			while (p + DESCRIPTOR + DIMENSIONS <= size)
			{
				Mip m;
				if (!ReadMip(blob, size, p, m)) break;
				if (m.flags != 0 || m.count != m.sizeOnDisk || m.offset != static_cast<uint32_t>(serialOffset) + p + DESCRIPTOR) break;
				if (p + DESCRIPTOR + m.sizeOnDisk + DIMENSIONS > size) break;
				m.sizeX = Read32(blob + p + DESCRIPTOR + m.sizeOnDisk);
				m.sizeY = Read32(blob + p + DESCRIPTOR + m.sizeOnDisk + 4);
				mips.push_back(m);
				p += DESCRIPTOR + m.sizeOnDisk + DIMENSIONS;
			}

			if (declared != mips.size()) return false;

			tableStart = start;
			return true;
		}

		bool NeedsCache(const std::vector<Mip>& mips)
		{
			for (const Mip& m : mips)
			{
				if ((m.flags & FLAG_SEPARATE_FILE) && !(m.flags & FLAG_UNUSED)) return true;
			}
			return false;
		}

		size_t InlinedSize(size_t original, const std::vector<Mip>& mips)
		{
			size_t total = original;
			for (const Mip& m : mips)
			{
				if ((m.flags & FLAG_SEPARATE_FILE) && !(m.flags & FLAG_UNUSED)) total += m.count;
			}
			return total;
		}

		bool Decompress(const uint8_t* source, size_t sourceSize, uint32_t expected, std::vector<uint8_t>& out)
		{
			if (sourceSize < 16 || Read32(source) != PACKAGE_FILE_TAG) return false;

			uint32_t chunkSize = Read32(source + 4);
			if (chunkSize == PACKAGE_FILE_TAG) chunkSize = LOADING_CHUNK;

			const uint32_t totalCompressed = Read32(source + 8);
			const uint32_t totalUncompressed = Read32(source + 12);

			if (chunkSize == 0 || totalUncompressed != expected || totalUncompressed > MAX_MIP) return false;

			const uint32_t chunks = (totalUncompressed + chunkSize - 1) / chunkSize;
			size_t table = 16;
			size_t data = table + static_cast<size_t>(chunks) * 8;

			if (data > sourceSize || data + totalCompressed > sourceSize) return false;

			out.resize(totalUncompressed);
			size_t produced = 0;

			for (uint32_t i = 0; i < chunks; ++i)
			{
				const uint32_t compressed = Read32(source + table + i * 8);
				const uint32_t uncompressed = Read32(source + table + i * 8 + 4);

				if (data + compressed > sourceSize || produced + uncompressed > totalUncompressed) return false;

				const int32_t got = Lzo1xDecompress(source + data, static_cast<int32_t>(compressed), out.data() + produced, static_cast<int32_t>(uncompressed));

				if (got != static_cast<int32_t>(uncompressed)) return false;

				data += compressed;
				produced += uncompressed;
			}

			return produced == totalUncompressed;
		}

		bool ReadCached(HANDLE cache, const Mip& mip, std::vector<uint8_t>& out)
		{
			if (mip.sizeOnDisk == 0 || mip.sizeOnDisk > MAX_MIP || mip.count == 0 || mip.count > MAX_MIP) return false;
			if (mip.flags & FLAG_OTHER_COMPRESSION) return false;

			std::vector<uint8_t> raw(mip.sizeOnDisk);

			LARGE_INTEGER at;
			at.QuadPart = mip.offset;

			DWORD read = 0;
			if (!SetFilePointerEx(cache, at, NULL, FILE_BEGIN)) return false;
			if (!ReadFile(cache, raw.data(), mip.sizeOnDisk, &read, NULL) || read != mip.sizeOnDisk) return false;

			if (mip.flags & FLAG_LZO) return Decompress(raw.data(), raw.size(), mip.count, out);

			if (raw.size() != mip.count) return false;
			out.swap(raw);
			return true;
		}

		void Inline(const std::vector<uint8_t>& blob, int32_t serialOffset, size_t tableStart, const std::vector<Mip>& mips, const std::vector<std::vector<uint8_t>>& payloads, std::vector<uint8_t>& out)
		{
			out.clear();
			out.reserve(InlinedSize(blob.size(), mips));
			out.insert(out.end(), blob.begin(), blob.begin() + tableStart);

			for (size_t i = 0; i < mips.size(); ++i)
			{
				const Mip& m = mips[i];
				const bool cached = (m.flags & FLAG_SEPARATE_FILE) && !(m.flags & FLAG_UNUSED);

				if (m.flags & FLAG_UNUSED)
				{
					out.insert(out.end(), blob.begin() + m.position, blob.begin() + m.position + 24);
					continue;
				}

				const uint8_t* payload = cached ? payloads[i].data() : blob.data() + m.position + DESCRIPTOR;
				const uint32_t length = cached ? static_cast<uint32_t>(payloads[i].size()) : m.sizeOnDisk;

				uint8_t descriptor[DESCRIPTOR];
				Write32(descriptor, 0);
				Write32(descriptor + 4, length);
				Write32(descriptor + 8, length);
				Write32(descriptor + 12, static_cast<uint32_t>(serialOffset) + static_cast<uint32_t>(out.size()) + DESCRIPTOR);
				out.insert(out.end(), descriptor, descriptor + DESCRIPTOR);
				out.insert(out.end(), payload, payload + length);

				uint8_t dims[DIMENSIONS];
				Write32(dims, m.sizeX);
				Write32(dims + 4, m.sizeY);
				out.insert(out.end(), dims, dims + DIMENSIONS);
			}

			const Mip& last = mips.back();
			const size_t tail = (last.flags & FLAG_UNUSED) ? last.position + 24 : last.position + DESCRIPTOR + last.sizeOnDisk + DIMENSIONS;
			out.insert(out.end(), blob.begin() + tail, blob.end());
		}
	}

	namespace Texture
	{
		std::vector<std::pair<std::string, HANDLE>> g_caches;
		bool g_scanned = false;

		bool Probe(HANDLE cache, const Mip& mip)
		{
			LARGE_INTEGER at;
			at.QuadPart = mip.offset;
			uint8_t head[16];
			DWORD read = 0;
			if (!SetFilePointerEx(cache, at, NULL, FILE_BEGIN)) return false;
			if (!ReadFile(cache, head, sizeof(head), &read, NULL) || read != sizeof(head)) return false;
			return Read32(head) == PACKAGE_FILE_TAG && Read32(head + 12) == mip.count;
		}

		void ScanForCaches()
		{
			if (g_scanned) return;
			g_scanned = true;

			std::error_code error;
			const std::filesystem::path root = std::filesystem::path(SystemHelper::GetModulePath()).parent_path().parent_path();

			try
			{
				for (auto it = std::filesystem::recursive_directory_iterator(root, std::filesystem::directory_options::skip_permission_denied, error); it != std::filesystem::recursive_directory_iterator(); it.increment(error))
				{
					const auto& entry = *it;

					if (entry.is_directory(error))
					{
						const std::string folder = ToLower(entry.path().filename().string());
						if (folder == "archive_dump" || folder == "mods") it.disable_recursion_pending();
						continue;
					}

					if (!entry.is_regular_file(error)) continue;

					const std::string extension = ToLower(entry.path().extension().string());
					if (extension == ".upk" || extension == ".umap" || extension == ".u" || extension == ".exe" || extension == ".dll"
						|| extension == ".ini" || extension == ".log" || extension == ".txt" || extension == ".bin" || extension == ".int")
					{
						continue;
					}

					if (entry.file_size(error) < 4 * 1024 * 1024) continue;

					const std::wstring full = L"\\\\?\\" + entry.path().wstring();
					HANDLE handle = CreateFileW(full.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_RANDOM_ACCESS, NULL);

					if (handle == INVALID_HANDLE_VALUE) continue;

					g_caches.emplace_back(ToLower(entry.path().stem().string()), handle);
				}
			}
			catch (...) {}
		}

		HANDLE ResolveCache(const std::string& name, const Mip& mip)
		{
			std::lock_guard<std::mutex> guard(g_lock);

			ScanForCaches();

			const std::string key = ToLower(name);

			for (const auto& cache : g_caches)
			{
				if (cache.first == key && Probe(cache.second, mip)) return cache.second;
			}

			for (const auto& cache : g_caches)
			{
				if (cache.first != key && Probe(cache.second, mip))
				{
					return cache.second;
				}
			}

			return INVALID_HANDLE_VALUE;
		}
	}

	void DumpExport(const std::string& relativePath, UObject* object, void* loader, int32_t offset, int32_t size)
	{
		if (size <= 0 || size > MAX_EXPORT) return;

		{
			std::lock_guard<std::mutex> guard(g_lock);

			if (!g_dumped.insert(relativePath).second) return;
		}

		void** vtable = *static_cast<void***>(loader);
		const auto Tell = reinterpret_cast<Tell_t>(vtable[VF_TELL / sizeof(void*)]);
		const auto Seek = reinterpret_cast<Seek_t>(vtable[VF_SEEK / sizeof(void*)]);
		const auto Precache = reinterpret_cast<Precache_t>(vtable[VF_PRECACHE / sizeof(void*)]);
		const auto SerializeBytes = reinterpret_cast<Serialize_t>(vtable[VF_SERIALIZE / sizeof(void*)]);

		std::vector<uint8_t> bytes;

		const auto readExport = [&]()
		{
			if (!bytes.empty()) return;
			bytes.resize(static_cast<size_t>(size));
			const int32_t saved = Tell(loader);
			Seek(loader, offset);
			Precache(loader, offset, size);
			SerializeBytes(loader, bytes.data(), size);
			Seek(loader, saved);
		};

		size_t expected = static_cast<size_t>(size);
		size_t tableStart = 0;
		std::vector<Texture::Mip> mips;
		bool texture = false;

		if (relativePath.find("Texture") != std::string::npos && object->IsA<UTexture2D>())
		{
			readExport();
			texture = Texture::Parse(bytes.data(), bytes.size(), offset, tableStart, mips) && Texture::NeedsCache(mips);
			if (texture) expected = Texture::InlinedSize(bytes.size(), mips);
		}

		const std::wstring fullPath = g_dumpDirectory + L"\\" + std::wstring(relativePath.begin(), relativePath.end());

		WIN32_FILE_ATTRIBUTE_DATA attributes{};
		const bool exists = GetFileAttributesExW(fullPath.c_str(), GetFileExInfoStandard, &attributes) != FALSE;

		if (exists && attributes.nFileSizeHigh == 0 && attributes.nFileSizeLow == static_cast<DWORD>(expected))
		{
			return;
		}

		const std::wstring folder = fullPath.substr(0, fullPath.find_last_of(L'\\'));
		bool createFolder = false;

		{
			std::lock_guard<std::mutex> guard(g_lock);
			createFolder = g_dumpFolders.insert(folder).second;
		}

		if (createFolder)
		{
			std::error_code error;
			std::filesystem::create_directories(folder, error);

			if (error) return;
		}

		readExport();

		const uint8_t* data = bytes.data();
		size_t length = bytes.size();
		std::vector<uint8_t> inlined;

		if (texture)
		{
			const std::string cacheName = reinterpret_cast<UTexture2D*>(object)->TextureFileCacheName.ToString();
			HANDLE cache = INVALID_HANDLE_VALUE;

			for (const Texture::Mip& m : mips)
			{
				if ((m.flags & Texture::FLAG_SEPARATE_FILE) && !(m.flags & Texture::FLAG_UNUSED))
				{
					cache = Texture::ResolveCache(cacheName, m);
					break;
				}
			}

			std::vector<std::vector<uint8_t>> payloads(mips.size());
			bool complete = cache != INVALID_HANDLE_VALUE;

			for (size_t i = 0; i < mips.size() && complete; ++i)
			{
				const Texture::Mip& m = mips[i];
				if ((m.flags & Texture::FLAG_SEPARATE_FILE) && !(m.flags & Texture::FLAG_UNUSED))
				{
					complete = Texture::ReadCached(cache, m, payloads[i]);
				}
			}

			if (complete)
			{
				Texture::Inline(bytes, offset, tableStart, mips, payloads, inlined);
				data = inlined.data();
				length = inlined.size();
			}
		}

		HANDLE file = CreateFileW(fullPath.c_str(), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

		if (file == INVALID_HANDLE_VALUE) return;

		DWORD written = 0;
		WriteFile(file, data, static_cast<DWORD>(length), &written, NULL);
		CloseHandle(file);

		if (written != static_cast<DWORD>(length)) return;
	}

	void __fastcall Preload_Hook(uintptr_t archive, int, UObject* object)
	{
		const auto passthrough = [&]()
		{
			Preload.thiscall<void>(reinterpret_cast<void*>(archive), object);
		};

		if (object == nullptr) return passthrough();

		if (!GlobalsReady()) return passthrough();

		const uintptr_t raw = reinterpret_cast<uintptr_t>(object);

		if ((*reinterpret_cast<uint32_t*>(raw + OFF_OBJ_FLAGS_HIGH) & RF_NEED_LOAD_HIGH) == 0) return passthrough();

		if (*reinterpret_cast<uintptr_t*>(raw + OFF_OBJ_LINKER) != archive - OFF_ARCHIVE_TO_OBJECT) return passthrough();

		const uintptr_t exportMap = *reinterpret_cast<uintptr_t*>(archive + OFF_EXPORT_MAP);
		const int32_t linkerIndex = *reinterpret_cast<int32_t*>(raw + OFF_OBJ_LINKER_INDEX);
		void* realLoader = *reinterpret_cast<void**>(archive + OFF_LOADER);
		void* realOriginalLoader = *reinterpret_cast<void**>(archive + OFF_ORIGINAL_LOADER);

		if (exportMap == 0 || linkerIndex < 0 || realLoader == nullptr) return passthrough();

		if (g_replaceReady && !DumpArchiveAssets)
		{
			const bool candidate = g_leafNames.count(ToLower(object->GetName())) != 0;

			if (!candidate) return passthrough();
		}

		const uintptr_t record = exportMap + static_cast<uintptr_t>(linkerIndex) * EXPORT_STRIDE;
		int32_t* serialSize = reinterpret_cast<int32_t*>(record + OFF_SERIAL_SIZE);
		const int32_t serialOffset = *reinterpret_cast<int32_t*>(record + OFF_SERIAL_OFFSET);

		const std::string relativePath = BuildRelativePath(object->GetFullName());

		if (relativePath.empty()) return passthrough();

		std::wstring modFile;

		// A material's shader map holds absolute file offsets, so it only works where it was cooked
		if (g_replaceReady && !object->IsA<UMaterialInterface>())
		{
			const auto entry = g_index.find(ToLower(relativePath));	// read only after startup, no lock needed
			if (entry != g_index.end()) modFile = entry->second;
		}

		if (modFile.empty())
		{
			passthrough();

			if (DumpArchiveAssets) DumpExport(relativePath, object, realLoader, serialOffset, *serialSize);

			return;
		}

		std::vector<uint8_t> blob;

		HANDLE file = CreateFileW(modFile.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, NULL);

		LARGE_INTEGER length{};

		if (file == INVALID_HANDLE_VALUE) return passthrough();

		const bool sized = GetFileSizeEx(file, &length) && length.QuadPart > 0 && length.QuadPart <= MAX_EXPORT;

		if (sized) blob.resize(static_cast<size_t>(length.QuadPart));

		DWORD read = 0;
		const bool loaded = sized && ReadFile(file, blob.data(), static_cast<DWORD>(blob.size()), &read, NULL) != FALSE && read == blob.size();
		CloseHandle(file);

		if (!loaded) return passthrough();

		MemoryArchive memory{};
		memcpy(memory.header, static_cast<uint8_t*>(realLoader) + sizeof(void*), ARCHIVE_HEADER);
		memory.vtable = g_archiveVtable;
		memory.real = realLoader;
		memory.data = blob.data();
		memory.size = static_cast<int32_t>(blob.size());
		memory.base = serialOffset;
		memory.position = serialOffset;

		const int32_t savedSize = *serialSize;
		*serialSize = memory.size;
		*reinterpret_cast<void**>(archive + OFF_LOADER) = &memory;
		*reinterpret_cast<void**>(archive + OFF_ORIGINAL_LOADER) = &memory;

		passthrough();

		*reinterpret_cast<void**>(archive + OFF_LOADER) = realLoader;
		*reinterpret_cast<void**>(archive + OFF_ORIGINAL_LOADER) = realOriginalLoader;
		*serialSize = savedSize;

		if (relativePath.find("Texture") != std::string::npos && object->IsA<UTexture2D>())
		{
			size_t table = 0;
			std::vector<Texture::Mip> mips;

			if (Texture::Parse(blob.data(), blob.size(), serialOffset, table, mips) && !Texture::NeedsCache(mips))
			{
				*reinterpret_cast<uint32_t*>(raw + OFF_TEX_STREAM_FLAGS) |= TEX_NEVER_STREAM;
			}
		}
	}

	void IndexMods()
	{
		const std::filesystem::path directory = std::filesystem::path(SystemHelper::GetModulePath()) / "mods";

		std::error_code error;

		if (!std::filesystem::is_directory(directory, error))
		{
			return;
		}

		std::vector<std::filesystem::path> modFolders;

		for (const auto& entry : std::filesystem::directory_iterator(directory, error))
		{
			if (entry.is_directory(error)) modFolders.push_back(entry.path());
		}

		// Name order, so the winner of a conflict never changes between runs
		std::sort(modFolders.begin(), modFolders.end());

		std::unordered_map<std::string, std::pair<std::string, int>> ignoredMods;

		for (const std::filesystem::path& folder : modFolders)
		{
			const std::string modName = folder.filename().string();
			int count = 0;

			try
			{
				for (const auto& entry : std::filesystem::recursive_directory_iterator(
					folder, std::filesystem::directory_options::skip_permission_denied, error))
				{
					if (!entry.is_regular_file(error) || entry.path().extension() != ".bin") continue;

					std::string relativePath = std::filesystem::relative(entry.path(), folder, error).string();

					if (error || relativePath.empty()) continue;

					for (char& character : relativePath)
					{
						if (character == '/') character = '\\';
					}

					const std::string key = ToLower(relativePath);
					const auto inserted = g_index.emplace(key, L"\\\\?\\" + entry.path().wstring());

					if (!inserted.second)
					{
						++ignoredMods[modName].second;
						continue;
					}

					// "Package\Class\Outer.Name.bin" -> "name"
					const std::string stem = ToLower(entry.path().stem().string());
					const size_t dot = stem.find_last_of('.');
					g_leafNames.insert(dot == std::string::npos ? stem : stem.substr(dot + 1));
					++count;
				}
			}
			catch (...) {}
		}

		if (!ignoredMods.empty())
		{
			std::string message = "More than one mod provides the same objects.\n" "The first mod in alphabetical order is used:\n";

			for (const auto& entry : ignoredMods)
			{
				message += "\n    \"" + entry.first + "\": " + std::to_string(entry.second.second) + " object(s) ignored";
			}

			MessageBoxA(NULL, message.c_str(), "MadnessPatch", MB_ICONWARNING);
		}

		g_replaceReady = !g_index.empty();
	}
}

void ApplyExportFiles()
{
	if (!DumpArchiveAssets && !LoadModFiles) return;

	const uintptr_t addr_Preload = GetAddress(Addr::LinkerPreload);

	if (addr_Preload == 0) return;

	if (DumpArchiveAssets)
	{
		const std::filesystem::path directory = std::filesystem::path(SystemHelper::GetModulePath()) / "archive_dump";

		std::error_code error;
		std::filesystem::create_directories(directory, error);

		if (error)
		{
			return;
		}

		g_dumpDirectory = L"\\\\?\\" + directory.wstring();
	}

	if (LoadModFiles) IndexMods();

	if (!DumpArchiveAssets && !g_replaceReady) return;

	BuildArchiveVtable();

	Preload = HookHelper::CreateHook(reinterpret_cast<void*>(addr_Preload), &Preload_Hook);
}
