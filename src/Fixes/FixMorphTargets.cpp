#include "Common.hpp"
#include "Features.hpp"

#include <emmintrin.h>

safetyhook::InlineHook UpdateMorphVertexBuffer;

struct FMorphGPUSkinVertex
{
	float DeltaPosition[3];
	uint32_t DeltaTangentZ;
};

struct FMorphTargetVertex
{
	float PositionDelta[3];
	uint32_t TangentZDelta;
	uint16_t SourceIdx;
	uint16_t Pad;
};

struct FMorphTargetLODModel
{
	FMorphTargetVertex* Vertices;
	int32_t NumVertices;
	int32_t MaxVertices;
	int32_t NumBaseMeshVerts;
};

static uintptr_t UpdateActiveMorphs = 0;
static uintptr_t UpdateFaceFX = 0;
static uintptr_t* GDynamicRHI = nullptr;

static std::vector<FMorphGPUSkinVertex> morphScratch;

// ---- Child FaceFX morphs ----

static void __fastcall UpdateChildFaceFX(USkeletalMeshComponent* child, int, void* localTransforms, BOOL bTickFaceFX)
{
	reinterpret_cast<void(__thiscall*)(USkeletalMeshComponent*)>(UpdateActiveMorphs)(child);
	reinterpret_cast<void(__thiscall*)(USkeletalMeshComponent*, void*, BOOL)>(UpdateFaceFX)(child, localTransforms, bTickFaceFX);
}

// ---- Morph vertex buffer ----

// FPackedNormal -> FVector, byte / 127.5 - 1
static inline __m128 UnpackNormal(uint32_t packed)
{
	__m128i v = _mm_cvtsi32_si128((int)packed);
	v = _mm_unpacklo_epi16(_mm_unpacklo_epi8(v, _mm_setzero_si128()), _mm_setzero_si128());
	return _mm_add_ps(_mm_mul_ps(_mm_cvtepi32_ps(v), _mm_castsi128_ps(_mm_set1_epi32(0x3C008081))), _mm_set1_ps(-1.0f));
}

// FVector -> FPackedNormal, W = 127
static inline uint32_t PackNormal(__m128 v)
{
	v = _mm_add_ps(_mm_mul_ps(v, _mm_set1_ps(127.5f)), _mm_set1_ps(128.0f));
	__m128i i = _mm_cvttps_epi32(v);
	i = _mm_packus_epi16(_mm_packs_epi32(i, i), i);
	return ((uint32_t)_mm_cvtsi128_si32(i) & 0x00FFFFFF) | 0x7F000000;
}

static void BlendMorphs(FMorphGPUSkinVertex* out, uint32_t numVerts, const TArray<FActiveMorph>* morphs, int32_t lodIdx)
{
	for (uint32_t i = 0; i < numVerts; i++)
	{
		out[i] = { { 0.0f, 0.0f, 0.0f }, 0x7F808080 };
	}

	for (int32_t m = 0; m < morphs->size(); m++)
	{
		UMorphTarget* target = (*morphs)[m].Target;
		if (!target || lodIdx >= target->MorphLODModels.size())
			continue;

		const FMorphTargetLODModel& lod = reinterpret_cast<const FMorphTargetLODModel*>(target->MorphLODModels.data())[lodIdx];

		float weight = (*morphs)[m].Weight;
		__m128 posWeight = _mm_set1_ps(weight);
		__m128 normalWeight = _mm_set1_ps(weight <= 1.0f ? weight : 1.0f);

		for (int32_t v = 0; v < lod.NumVertices; v++)
		{
			const FMorphTargetVertex& src = lod.Vertices[v];
			if (src.SourceIdx >= numVerts)
				continue;

			FMorphGPUSkinVertex& dst = out[src.SourceIdx];

			__m128 pos = _mm_setr_ps(dst.DeltaPosition[0], dst.DeltaPosition[1], dst.DeltaPosition[2], 0.0f);
			__m128 delta = _mm_setr_ps(src.PositionDelta[0], src.PositionDelta[1], src.PositionDelta[2], 0.0f);
			pos = _mm_add_ps(pos, _mm_mul_ps(delta, posWeight));
			dst.DeltaPosition[0] = _mm_cvtss_f32(pos);
			dst.DeltaPosition[1] = _mm_cvtss_f32(_mm_shuffle_ps(pos, pos, _MM_SHUFFLE(1, 1, 1, 1)));
			dst.DeltaPosition[2] = _mm_cvtss_f32(_mm_shuffle_ps(pos, pos, _MM_SHUFFLE(2, 2, 2, 2)));

			dst.DeltaTangentZ = PackNormal(_mm_add_ps(UnpackNormal(dst.DeltaTangentZ), _mm_mul_ps(UnpackNormal(src.TangentZDelta), normalWeight)));
		}
	}
}

static void __fastcall UpdateMorphVertexBuffer_Hook(uintptr_t thisp, int, TArray<FActiveMorph>* activeMorphs)
{
	void* vertexBuffer = *reinterpret_cast<void**>(thisp + 0x24);
	if (!vertexBuffer)
		return;

	uintptr_t skelMesh = *reinterpret_cast<uintptr_t*>(thisp);
	int32_t lodIdx = *reinterpret_cast<int32_t*>(thisp + 0x4);
	uintptr_t lodModel = (*reinterpret_cast<uintptr_t**>(skelMesh + 0xD4))[lodIdx];
	uint32_t numVerts = *reinterpret_cast<uint32_t*>(lodModel + 0x68);
	uint32_t size = numVerts * sizeof(FMorphGPUSkinVertex);

	if (morphScratch.size() < numVerts)
	{
		morphScratch.resize(numVerts);
	}

	BlendMorphs(morphScratch.data(), numVerts, activeMorphs, lodIdx);

	uintptr_t rhi = *GDynamicRHI;
	uintptr_t* vtable = *reinterpret_cast<uintptr_t**>(rhi);

	void* data = reinterpret_cast<void* (__thiscall*)(uintptr_t, void*, uint32_t, uint32_t, BOOL)>(vtable[0x40 / 4])(rhi, vertexBuffer, 0, size, FALSE);
	if (data && size)
	{
		std::memcpy(data, morphScratch.data(), size);
	}
	reinterpret_cast<void(__thiscall*)(uintptr_t, void*)>(vtable[0x44 / 4])(rhi, vertexBuffer);

	*reinterpret_cast<uint32_t*>(thisp + 0x28) = 1; // bHasBeenUpdated
}

void ApplyFixMorphTargets()
{
	if (!FixMorphTargets) return;

	// Morphs piling up on off-screen heads
	DWORD addr_ChildFaceFXCall = GetAddress(Addr::ChildFaceFXCall);
	UpdateActiveMorphs = GetAddress(Addr::UpdateActiveMorphs);
	UpdateFaceFX = addr_ChildFaceFXCall + 0x5 + *reinterpret_cast<int32_t*>(addr_ChildFaceFXCall + 0x1);
	MemoryHelper::MakeCALL(addr_ChildFaceFXCall, reinterpret_cast<uintptr_t>(&UpdateChildFaceFX));

	// Morph blending in system memory
	DWORD addr_UpdateMorphVertexBuffer = GetAddress(Addr::UpdateMorphVertexBuffer);
	GDynamicRHI = *reinterpret_cast<uintptr_t**>(addr_UpdateMorphVertexBuffer + 0x39);
	UpdateMorphVertexBuffer = HookHelper::CreateHook((void*)addr_UpdateMorphVertexBuffer, &UpdateMorphVertexBuffer_Hook);
}