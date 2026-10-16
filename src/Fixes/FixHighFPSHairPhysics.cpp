#include "Common.hpp"
#include "Features.hpp"

#include <emmintrin.h>

struct ParticleSimLayout
{
	int numParticles;
	int particles;
	int numColliders;
	int colliders;
	int particleStride;
	int lengthScale;
	int force;
	int windAmp;
	int radialCenter;
	int radialStrength;
	int strands;
	int numStrands;
	int drivenNormal;
};

constexpr ParticleSimLayout HAIR_LAYOUT = { 0xAC, 0xC0, 0xB8, 0xC8, 0x50, 0x9C, 0x40, 0x50, -1, -1, 0xC4, 0xB0, -1 };
constexpr ParticleSimLayout CLOTH_LAYOUT = { 0xB8, 0xC4, 0xC0, 0xCC, 0x70, -1, 0x40, 0x60, 0x50, 0xA0, -1, -1, 0x40 };
constexpr float SIM_STEP_DT = 0.033f;
constexpr int SIM_MAX_INSTANCES = 64;
constexpr int SIM_MAX_PARTICLES = 4096; // Alice's hair is 2565
constexpr int SIM_MAX_COLLIDERS = 64;
constexpr float SIM_CUT_SPEED = 12000.0f;
constexpr float SIM_CUT_MIN_DIST = 32.0f;
constexpr float SIM_CUT_TURN_COS = 0.5f;
constexpr uint64_t SIM_INPUT_STALE_MS = 250;
constexpr uint64_t SIM_SLOT_BUSY_MS = 1000;
constexpr uint64_t SIM_PURGE_AFTER_MS = 30000;
constexpr uint64_t SIM_PURGE_PERIOD_MS = 5000;

struct ParticleSimState
{
	uintptr_t key = 0;
	uint64_t lastSeen = 0;
	uint64_t lastCall = 0;
	const ParticleSimLayout* layout = nullptr;
	int numParticles = 0;
	int numColliders = 0;
	float accumulator = 0.0f;
	bool primed = false;
	bool hasPrevInputs = false;
	bool theirs = false;
	float prevMatrix[16] = {};
	float prevLengthScale = 1.0f;
	float prevForceWind[6] = {};

	float tickMatrix[16] = {};
	float blastLocal[3] = {};
	float blastStrength = 0.0f;
	bool hasTickMatrix = false;
	bool blastLocalValid = false;
	bool blastAttached = false;
	bool blastStrengthPending = false;
	bool blastStrengthValid = false;

	// One block per instance, sized to fit: trueP1 | offPrev | offCurr | applied | prevColliders | liveColliders | restPrev | restLive
	std::unique_ptr<float[]> buffer;
	size_t capacity = 0;
	float* trueP1 = nullptr;
	float* offPrev = nullptr;
	float* offCurr = nullptr;
	float* applied = nullptr;
	float* prevColliders = nullptr;
	float* liveColliders = nullptr;
	float* restPrev = nullptr;
	float* restLive = nullptr;

	// hair only
	std::unique_ptr<int32_t[]> rootOf;
	std::unique_ptr<uint64_t[]> strandRecords;
	int numStrands = 0;
	bool rootsBuilt = false;
};

static ParticleSimState simStates[SIM_MAX_INSTANCES];

static uint64_t SimActivityClock(uint64_t now)
{
	static uint64_t lastNow = 0, clock = 0;

	uint64_t elapsed = lastNow ? now - lastNow : 0;
	clock += elapsed < 100 ? elapsed : 100;
	lastNow = now;
	return clock;
}

static void PurgeSimStates(uint64_t clock)
{
	static uint64_t lastPurge = 0;
	if (clock - lastPurge < SIM_PURGE_PERIOD_MS)
		return;

	lastPurge = clock;
	for (ParticleSimState& s : simStates)
	{
		if (s.key && clock - s.lastSeen > SIM_PURGE_AFTER_MS)
		{
			s = ParticleSimState{};
		}
	}
}

static ParticleSimState* AcquireSimState(uintptr_t key, uint64_t now, uint64_t clock, const ParticleSimLayout* layout, int numParticles, int numColliders)
{
	ParticleSimState* state = nullptr;
	ParticleSimState* victim = nullptr;

	for (ParticleSimState& s : simStates)
	{
		if (s.key == key)
		{
			state = &s;
			break;
		}

		// a free slot first, the least recently stepped one otherwise
		if (!victim || (victim->key && (!s.key || s.lastSeen < victim->lastSeen)))
		{
			victim = &s;
		}
	}

	if (!state)
	{
		// Every slot was stepped within the last second: leave this instance to the vanilla path instead of evicting one that is mid-interpolation
		if (victim->key && clock - victim->lastSeen < SIM_SLOT_BUSY_MS)
			return nullptr;

		*victim = ParticleSimState{};
		state = victim;
		state->key = key;
	}

	// New instance, or the game built a different sim at an address it had just freed
	if (state->layout != layout || state->numParticles != numParticles || state->numColliders != numColliders)
	{
		size_t n = static_cast<size_t>(numParticles) * 4;
		size_t m = static_cast<size_t>(numColliders) * 3;
		size_t rest = layout->drivenNormal >= 0 ? n * 2 : 0;
		size_t needed = n * 4 + m * 2 + rest * 2;

		if (state->capacity < needed)
		{
			float* block = new (std::nothrow) float[needed]();
			if (!block)
			{
				*state = ParticleSimState{};
				return nullptr;
			}

			state->buffer.reset(block);
			state->capacity = needed;
		}

		float* base = state->buffer.get();
		state->trueP1 = base;
		state->offPrev = base + n;
		state->offCurr = base + n * 2;
		state->applied = base + n * 3;
		state->prevColliders = base + n * 4;
		state->liveColliders = base + n * 4 + m;
		state->restPrev = rest ? base + n * 4 + m * 2 : nullptr;
		state->restLive = rest ? base + n * 4 + m * 2 + rest : nullptr;
		state->rootOf.reset(layout->strands >= 0 ? new (std::nothrow) int32_t[numParticles] : nullptr);
		state->strandRecords.reset(layout->strands >= 0 ? new (std::nothrow) uint64_t[numParticles]() : nullptr);
		state->rootsBuilt = false;
		if (layout->strands >= 0 && !state->rootOf)
		{
			*state = ParticleSimState{};
			return nullptr;
		}

		state->layout = layout;
		state->numParticles = numParticles;
		state->numColliders = numColliders;
		state->accumulator = 0.0f;
		state->primed = false;
		state->hasPrevInputs = false;
		state->theirs = false;
		state->hasTickMatrix = false;
		state->blastLocalValid = state->blastAttached = state->blastStrengthPending = state->blastStrengthValid = false;
	}

	if (now - state->lastCall > SIM_INPUT_STALE_MS)
	{
		state->hasPrevInputs = false;
	}

	state->lastCall = now;
	state->lastSeen = clock;
	return state;
}

// Inverse of the rotation / scale part, so that local = world * inverse (row vectors, like the game)
static void SimInverseBasis(const float* m, float* inv)
{
	float a = m[0], b = m[1], c = m[2], d = m[4], e = m[5], f = m[6], g = m[8], h = m[9], i = m[10];
	float det = a * (e * i - f * h) - b * (d * i - f * g) + c * (d * h - e * g);

	if (!(fabsf(det) > 1e-12f))
	{
		static const float identity[9] = { 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f };
		memcpy(inv, identity, sizeof(identity));
		return;
	}

	float r = 1.0f / det;
	inv[0] = (e * i - f * h) * r; inv[1] = (c * h - b * i) * r; inv[2] = (b * f - c * e) * r;
	inv[3] = (f * g - d * i) * r; inv[4] = (a * i - c * g) * r; inv[5] = (c * d - a * f) * r;
	inv[6] = (d * h - e * g) * r; inv[7] = (b * g - a * h) * r; inv[8] = (a * e - b * d) * r;
}

static inline void SimToBodyFrame(const float* world, const float* inv, float* local)
{
	for (int j = 0; j < 3; j++)
	{
		local[j] = world[0] * inv[j] + world[1] * inv[3 + j] + world[2] * inv[6 + j];
	}
}

static inline void SimLocalPoint(const float* world, const float* matrix, const float* inv, float* local)
{
	float offset[3] = { world[0] - matrix[12], world[1] - matrix[13], world[2] - matrix[14] };
	SimToBodyFrame(offset, inv, local);
}

static inline void SimWorldPoint(const float* local, const float* matrix, float* world)
{
	for (int j = 0; j < 3; j++)
	{
		world[j] = local[0] * matrix[j] + local[1] * matrix[4 + j] + local[2] * matrix[8 + j] + matrix[12 + j];
	}
}

static bool UpdateSimRoots(const ParticleSimLayout& layout, const uint8_t* sim, ParticleSimState& state)
{
	int numStrands = *(const int*)(sim + layout.numStrands);
	const uint8_t* strands = *(const uint8_t* const*)(sim + layout.strands);
	int numParticles = state.numParticles;
	if (!strands || numStrands < 0) numStrands = 0;
	if (numStrands > numParticles) numStrands = numParticles;

	uint64_t* kept = state.strandRecords.get();
	bool changed = !state.rootsBuilt || numStrands != state.numStrands;
	for (int c = 0; c < numStrands; c++)
	{
		uint64_t record;
		memcpy(&record, strands + c * 0x20 + 0x10, sizeof(record));
		if (record != kept[c])
		{
			kept[c] = record;
			changed = true;
		}
	}

	if (!changed)
		return false;

	int32_t* rootOf = state.rootOf.get();

	for (int i = 0; i < numParticles; i++)
	{
		rootOf[i] = i;
	}

	for (int c = 0; c < numStrands; c++)
	{
		int first = *(const int*)(strands + c * 0x20 + 0x10);
		int count = *(const int*)(strands + c * 0x20 + 0x14);
		if (first < 0 || count <= 0 || first >= numParticles) continue;
		if (count > numParticles - first) count = numParticles - first;

		for (int q = first; q < first + count; q++)
		{
			rootOf[q] = first;
		}
	}

	state.numStrands = numStrands;
	state.rootsBuilt = true;
	return true;
}

// Largest axis length of the transform: what the game itself uses as the scale of the body
static inline float SimScale(const float* m)
{
	float best = 0.0f;

	for (int r = 0; r < 3; r++)
	{
		float length = m[r * 4] * m[r * 4] + m[r * 4 + 1] * m[r * 4 + 1] + m[r * 4 + 2] * m[r * 4 + 2];
		if (length > best) best = length;
	}

	return sqrtf(best);
}

static inline void SimAnchor(const uint8_t* particle, const float* matrix, float* out)
{
	const float* local = reinterpret_cast<const float*>(particle + 0x20);

	for (int j = 0; j < 3; j++)
	{
		out[j] = local[0] * matrix[j] + local[1] * matrix[4 + j] + local[2] * matrix[8 + j] + matrix[12 + j];
	}
}

static bool SimInputsCut(const float* prev, const float* live, float delta)
{
	float dx = live[12] - prev[12], dy = live[13] - prev[13], dz = live[14] - prev[14];
	float limit = SIM_CUT_SPEED * delta;
	if (limit < SIM_CUT_MIN_DIST) limit = SIM_CUT_MIN_DIST;

	if (!(dx * dx + dy * dy + dz * dz <= limit * limit))
		return true;

	for (int r = 0; r < 3; r++)
	{
		const float* a = prev + r * 4;
		const float* b = live + r * 4;
		float ab = a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
		float aa = a[0] * a[0] + a[1] * a[1] + a[2] * a[2];
		float bb = b[0] * b[0] + b[1] * b[1] + b[2] * b[2];

		// written so that NaN counts as a cut
		if (!(ab > 0.0f) || !(ab * ab >= SIM_CUT_TURN_COS * SIM_CUT_TURN_COS * aa * bb))
			return true;
	}

	return false;
}

static void InterpolateSimMatrix(const float* a, const float* b, float s, float* out)
{
	float t = 1.0f - s;
	float lenA[3]{}, lenB[3]{}, ra[9]{}, rb[9]{};
	bool rigid = true;

	for (int r = 0; r < 3; r++)
	{
		const float* pa = a + r * 4;
		const float* pb = b + r * 4;
		lenA[r] = sqrtf(pa[0] * pa[0] + pa[1] * pa[1] + pa[2] * pa[2]);
		lenB[r] = sqrtf(pb[0] * pb[0] + pb[1] * pb[1] + pb[2] * pb[2]);

		if (!(lenA[r] > 1e-12f) || !(lenB[r] > 1e-12f))
		{
			rigid = false;
			break;
		}

		for (int j = 0; j < 3; j++)
		{
			ra[r * 3 + j] = pa[j] / lenA[r];
			rb[r * 3 + j] = pb[j] / lenB[r];
		}
	}

	float sine = 0.0f, cosine = 1.0f, axis[3] = {};

	if (rigid)
	{
		// the turn that takes a to b (row vectors: rb = ra * d), as sin(angle) * axis and cos(angle)
		float d[9]{};
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				d[i * 3 + j] = ra[i] * rb[j] + ra[3 + i] * rb[3 + j] + ra[6 + i] * rb[6 + j];
			}
		}

		axis[0] = (d[5] - d[7]) * 0.5f;
		axis[1] = (d[6] - d[2]) * 0.5f;
		axis[2] = (d[1] - d[3]) * 0.5f;
		sine = sqrtf(axis[0] * axis[0] + axis[1] * axis[1] + axis[2] * axis[2]);
		cosine = (d[0] + d[4] + d[8] - 1.0f) * 0.5f;
	}

	for (int j = 0; j < 3; j++)
	{
		out[12 + j] = a[12 + j] * t + b[12 + j] * s;
	}

	if (!rigid || !(sine > 1e-6f) || !(cosine > 0.0f))
	{
		for (int r = 0; r < 3; r++)
		{
			const float* pa = a + r * 4;
			const float* pb = b + r * 4;
			float v[3] = { pa[0] * t + pb[0] * s, pa[1] * t + pb[1] * s, pa[2] * t + pb[2] * s };

			float la = sqrtf(pa[0] * pa[0] + pa[1] * pa[1] + pa[2] * pa[2]);
			float lb = sqrtf(pb[0] * pb[0] + pb[1] * pb[1] + pb[2] * pb[2]);
			float lv = sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
			float k = lv > 1e-12f ? (la * t + lb * s) / lv : 1.0f;

			out[r * 4] = v[0] * k;
			out[r * 4 + 1] = v[1] * k;
			out[r * 4 + 2] = v[2] * k;
		}

		return;
	}

	float angle = atan2f(sine, cosine) * s;
	float c = cosf(angle), sn = sinf(angle), k = 1.0f - c;
	float x = axis[0] / sine, y = axis[1] / sine, z = axis[2] / sine;

	// the same turn by s * angle, row-vector form
	float p[9] = {
		c + k * x * x,      k * x * y + sn * z, k * x * z - sn * y,
		k * x * y - sn * z, c + k * y * y,      k * y * z + sn * x,
		k * x * z + sn * y, k * y * z - sn * x, c + k * z * z };

	for (int r = 0; r < 3; r++)
	{
		float length = lenA[r] * t + lenB[r] * s;

		for (int j = 0; j < 3; j++)
		{
			out[r * 4 + j] = (ra[r * 3] * p[j] + ra[r * 3 + 1] * p[3 + j] + ra[r * 3 + 2] * p[6 + j]) * length;
		}
	}
}

static bool SimParticlesRewritten(const uint8_t* particles, int numParticles, int stride, const float* applied)
{
	int i = 0;
	for (; i + 4 <= numParticles; i += 4)
	{
		const uint8_t* p = particles + i * stride + 0x10;
		const float* a = applied + i * 4;
		__m128i e0 = _mm_cmpeq_epi32(_mm_loadu_si128((const __m128i*)p), _mm_loadu_si128((const __m128i*)a));
		__m128i e1 = _mm_cmpeq_epi32(_mm_loadu_si128((const __m128i*)(p + stride)), _mm_loadu_si128((const __m128i*)(a + 4)));
		__m128i e2 = _mm_cmpeq_epi32(_mm_loadu_si128((const __m128i*)(p + 2 * stride)), _mm_loadu_si128((const __m128i*)(a + 8)));
		__m128i e3 = _mm_cmpeq_epi32(_mm_loadu_si128((const __m128i*)(p + 3 * stride)), _mm_loadu_si128((const __m128i*)(a + 12)));
		__m128i all = _mm_and_si128(_mm_and_si128(e0, e1), _mm_and_si128(e2, e3));
		if ((_mm_movemask_epi8(all) & 0x0FFF) != 0x0FFF) return true;
	}

	for (; i < numParticles; i++)
	{
		__m128i found = _mm_loadu_si128((const __m128i*)(particles + i * stride + 0x10));
		__m128i drawn = _mm_loadu_si128((const __m128i*)(applied + i * 4));
		if ((_mm_movemask_epi8(_mm_cmpeq_epi32(found, drawn)) & 0x0FFF) != 0x0FFF) return true;
	}

	return false;
}

static inline void SimStoreXyz(float* out, __m128 v)
{
	_mm_storel_epi64((__m128i*)out, _mm_castps_si128(v));
	_mm_store_ss(out + 2, _mm_movehl_ps(v, v));
}

static bool CheckAndRestoreSimParticles(uint8_t* particles, int numParticles, int stride, const float* applied, const float* trueP1)
{
	constexpr int BLOCK = 8;
	for (int first = 0; first < numParticles; first += BLOCK)
	{
		const int last = first + BLOCK < numParticles ? first + BLOCK : numParticles;
		__m128i same = _mm_set1_epi32(-1);

		for (int i = first; i < last; i++)
		{
			const uint8_t* p = particles + i * stride + 0x10;
			_mm_prefetch((const char*)p + 8 * stride, _MM_HINT_T0);
			same = _mm_and_si128(same, _mm_cmpeq_epi32(_mm_loadu_si128((const __m128i*)p), _mm_loadu_si128((const __m128i*)(applied + i * 4))));
		}

		if ((_mm_movemask_epi8(same) & 0x0FFF) != 0x0FFF) return false;

		for (int i = first; i < last; i++)
		{
			SimStoreXyz((float*)(particles + i * stride + 0x10), _mm_loadu_ps(trueP1 + i * 4));
		}
	}

	return true;
}

template <bool Roots>
static void DrawSimParticles(uint8_t* particles, int numParticles, int stride, const int32_t* rootOf, const float* matrix, float alpha, const float* offPrev, const float* offCurr, float* applied)
{
	const __m128 row0 = _mm_loadu_ps(matrix), row1 = _mm_loadu_ps(matrix + 4), row2 = _mm_loadu_ps(matrix + 8), row3 = _mm_loadu_ps(matrix + 12);
	const __m128 blend = _mm_set1_ps(alpha);
	const __m128 size = _mm_set1_ps(SimScale(matrix));

	int32_t anchorIndex = -1;
	__m128 base = _mm_setzero_ps();

	for (int i = 0; i < numParticles; i++)
	{
		int32_t index = Roots ? rootOf[i] : i;
		if (index != anchorIndex)
		{
			anchorIndex = index;
			__m128 local = _mm_loadu_ps((const float*)(particles + index * stride + 0x20));
			base = _mm_add_ps(_mm_add_ps(_mm_add_ps(
				_mm_mul_ps(_mm_shuffle_ps(local, local, 0x00), row0),
				_mm_mul_ps(_mm_shuffle_ps(local, local, 0x55), row1)),
				_mm_mul_ps(_mm_shuffle_ps(local, local, 0xAA), row2)), row3);
		}

		float* p1 = (float*)(particles + i * stride + 0x10);
		int k = i * 4;

		_mm_prefetch((const char*)p1 + 8 * stride, _MM_HINT_T0);

		__m128 prev = _mm_loadu_ps(offPrev + k);
		__m128 drawn = _mm_add_ps(base, _mm_mul_ps(_mm_add_ps(prev, _mm_mul_ps(_mm_sub_ps(_mm_loadu_ps(offCurr + k), prev), blend)), size));
		SimStoreXyz(p1, drawn);
		_mm_storeu_ps(applied + k, drawn);
	}
}

static bool CheckAndDrawSimParticles(uint8_t* particles, int numParticles, int stride, const int32_t* rootOf, const float* matrix, float alpha, const float* offPrev, const float* offCurr, float* applied, int* drawn)
{
	constexpr int BLOCK = 8;
	const __m128 row0 = _mm_loadu_ps(matrix), row1 = _mm_loadu_ps(matrix + 4), row2 = _mm_loadu_ps(matrix + 8), row3 = _mm_loadu_ps(matrix + 12);
	const __m128 blend = _mm_set1_ps(alpha);
	const __m128 size = _mm_set1_ps(SimScale(matrix));

	int32_t anchorIndex = -1;
	__m128 base = _mm_setzero_ps();

	for (int first = 0; first < numParticles; first += BLOCK)
	{
		const int last = first + BLOCK < numParticles ? first + BLOCK : numParticles;
		__m128i same = _mm_set1_epi32(-1);

		for (int i = first; i < last; i++)
		{
			const uint8_t* p = particles + i * stride + 0x10;
			_mm_prefetch((const char*)p + 8 * stride, _MM_HINT_T0);
			same = _mm_and_si128(same, _mm_cmpeq_epi32(_mm_loadu_si128((const __m128i*)p), _mm_loadu_si128((const __m128i*)(applied + i * 4))));
		}

		if ((_mm_movemask_epi8(same) & 0x0FFF) != 0x0FFF)
		{
			*drawn = first;
			return false;
		}

		for (int i = first; i < last; i++)
		{
			int32_t index = rootOf[i];
			if (index != anchorIndex)
			{
				anchorIndex = index;
				__m128 local = _mm_loadu_ps((const float*)(particles + index * stride + 0x20));
				base = _mm_add_ps(_mm_add_ps(_mm_add_ps(
					_mm_mul_ps(_mm_shuffle_ps(local, local, 0x00), row0),
					_mm_mul_ps(_mm_shuffle_ps(local, local, 0x55), row1)),
					_mm_mul_ps(_mm_shuffle_ps(local, local, 0xAA), row2)), row3);
			}

			int k = i * 4;
			__m128 prev = _mm_loadu_ps(offPrev + k);
			__m128 out = _mm_add_ps(base, _mm_mul_ps(_mm_add_ps(prev, _mm_mul_ps(_mm_sub_ps(_mm_loadu_ps(offCurr + k), prev), blend)), size));
			SimStoreXyz((float*)(particles + i * stride + 0x10), out);
			_mm_storeu_ps(applied + k, out);
		}
	}

	*drawn = numParticles;
	return true;
}

template <bool Roots>
static void CaptureAndDrawSimParticles(uint8_t* particles, int numParticles, int stride, const int32_t* rootOf, const float* matrix, float unscale, float alpha, float* trueP1, const float* offPrev, float* offCurr, float* applied)
{
	const __m128 row0 = _mm_loadu_ps(matrix), row1 = _mm_loadu_ps(matrix + 4), row2 = _mm_loadu_ps(matrix + 8), row3 = _mm_loadu_ps(matrix + 12);
	const __m128 blend = _mm_set1_ps(alpha);
	const __m128 size = _mm_set1_ps(SimScale(matrix));
	const __m128 scale = _mm_set1_ps(unscale);

	int32_t anchorIndex = -1;
	__m128 anchor = _mm_setzero_ps(), base = _mm_setzero_ps();

	for (int i = 0; i < numParticles; i++)
	{
		int32_t index = Roots ? rootOf[i] : i;
		if (index != anchorIndex)
		{
			anchorIndex = index;
			anchor = _mm_loadu_ps((const float*)(particles + index * stride + 0x30));
			__m128 local = _mm_loadu_ps((const float*)(particles + index * stride + 0x20));
			base = _mm_add_ps(_mm_add_ps(_mm_add_ps(
				_mm_mul_ps(_mm_shuffle_ps(local, local, 0x00), row0),
				_mm_mul_ps(_mm_shuffle_ps(local, local, 0x55), row1)),
				_mm_mul_ps(_mm_shuffle_ps(local, local, 0xAA), row2)), row3);
		}

		float* p1 = (float*)(particles + i * stride + 0x10);
		int k = i * 4;
		_mm_prefetch((const char*)p1 + 8 * stride, _MM_HINT_T0);

		__m128 current = _mm_loadu_ps(p1);
		__m128 off = _mm_mul_ps(_mm_sub_ps(current, anchor), scale);
		_mm_storeu_ps(trueP1 + k, current);
		_mm_storeu_ps(offCurr + k, off);

		__m128 prev = _mm_loadu_ps(offPrev + k);
		__m128 drawn = _mm_add_ps(base, _mm_mul_ps(_mm_add_ps(prev, _mm_mul_ps(_mm_sub_ps(off, prev), blend)), size));
		SimStoreXyz(p1, drawn);
		_mm_storeu_ps(applied + k, drawn);
	}
}

static void AdoptSimParticles(ParticleSimState* state, const uint8_t* particles, int numParticles, int stride, const int32_t* rootOf, const float* frame)
{
	float scale = SimScale(frame);
	float unscale = scale > 1e-6f ? 1.0f / scale : 1.0f;

	for (int i = 0; i < numParticles; i++)
	{
		const float* p1 = (const float*)(particles + i * stride + 0x10);
		int k = i * 4;

		float anchor[3];
		SimAnchor(particles + rootOf[i] * stride, frame, anchor);

		for (int j = 0; j < 3; j++) state->offCurr[k + j] = (p1[j] - anchor[j]) * unscale;
		memcpy(state->offPrev + k, state->offCurr + k, sizeof(float) * 3);
	}
}

static uint32_t StepTheirs(safetyhook::InlineHook& original, void* thisPtr, float delta, ParticleSimState* state, const uint8_t* particles, int numParticles, int stride)
{
	uint32_t result = 0;
	if (delta > 0.0f) result = original.unsafe_thiscall<uint32_t>(thisPtr, delta < SIM_STEP_DT ? delta : SIM_STEP_DT);

	for (int i = 0; i < numParticles; i++)
	{
		memcpy(state->applied + i * 4, particles + i * stride + 0x10, sizeof(float) * 3);
	}

	state->theirs = true;
	state->primed = false;
	return result;
}

static uint32_t StepAtFixedRate(safetyhook::InlineHook& original, const ParticleSimLayout& layout, void* thisPtr, float delta)
{
	uint8_t* sim = (uint8_t*)thisPtr;
	int numParticles = *(int*)(sim + layout.numParticles);
	int numColliders = *(int*)(sim + layout.numColliders);
	uint8_t* particles = *(uint8_t**)(sim + layout.particles);
	uint8_t* colliders = *(uint8_t**)(sim + layout.colliders);
	const int stride = layout.particleStride;

	if (!particles || numParticles <= 0 || numParticles > SIM_MAX_PARTICLES)
		return original.unsafe_thiscall<uint32_t>(thisPtr, delta);

	uint64_t now = GetTickCount64();
	uint64_t clock = SimActivityClock(now);
	PurgeSimStates(clock);

	// Too many colliders to track: they stay live, the transform is still resampled
	int trackedColliders = (colliders && numColliders > 0 && numColliders <= SIM_MAX_COLLIDERS) ? numColliders : 0;

	ParticleSimState* state = AcquireSimState((uintptr_t)thisPtr, now, clock, &layout, numParticles, trackedColliders);
	if (!state)
		return original.unsafe_thiscall<uint32_t>(thisPtr, delta);

	float* matrix = (float*)sim;
	float* center = layout.radialCenter >= 0 ? (float*)(sim + layout.radialCenter) : nullptr;
	int32_t* rootOf = state->rootOf.get();

	uint32_t result = 0;
	bool tick = !state->primed;
	const float span = delta < SIM_STEP_DT ? delta : TARGET_FRAME_TIME;
	float lastAlpha = state->accumulator / TARGET_FRAME_TIME;
	if (lastAlpha < 0.0f) lastAlpha = 0.0f;
	if (lastAlpha > 1.0f) lastAlpha = 1.0f;

	if (state->primed && delta > 0.0f)
	{
		state->accumulator += span;
		tick = state->accumulator >= TARGET_FRAME_TIME;
	}

	bool rootsChanged = rootOf && UpdateSimRoots(layout, sim, *state);
	if (state->primed && rootsChanged)
	{
		AdoptSimParticles(state, particles, numParticles, stride, rootOf, state->hasPrevInputs ? state->prevMatrix : matrix);
	}

	const bool restoreNow = state->primed && tick;
	const bool checkFirst = restoreNow || ((state->primed || state->theirs) && (rootsChanged || state->theirs || !rootOf));
	const bool rewritten = restoreNow ? !CheckAndRestoreSimParticles(particles, numParticles, stride, state->applied, state->trueP1) : checkFirst && SimParticlesRewritten(particles, numParticles, stride, state->applied);
	if (rewritten)
		return StepTheirs(original, thisPtr, delta, state, particles, numParticles, stride);

	state->theirs = false;

	for (int c = 0; c < trackedColliders; c++)
	{
		memcpy(state->liveColliders + c * 3, colliders + c * 0x30, sizeof(float) * 3);
	}

	// cloth: the rest pose as the callers posed it for this frame
	if (state->restLive)
	{
		for (int i = 0; i < numParticles; i++)
		{
			memcpy(state->restLive + i * 6, particles + i * stride + 0x20, sizeof(float) * 3);
			memcpy(state->restLive + i * 6 + 3, particles + i * stride + layout.drivenNormal, sizeof(float) * 3);
		}
	}

	float liveCenter[3] = {};
	float liveStrength = 0.0f;

	if (center)
	{
		memcpy(liveCenter, center, sizeof(liveCenter));
		liveStrength = *(float*)(sim + layout.radialStrength);

		if (state->blastStrengthPending)
		{
			state->blastStrength = liveStrength;
			state->blastStrengthValid = true;
			state->blastStrengthPending = false;
		}

		if (state->hasPrevInputs)
		{
			float local[3], inv[9];
			SimInverseBasis(state->prevMatrix, inv);
			SimLocalPoint(liveCenter, state->prevMatrix, inv, local);

			if (state->blastLocalValid)
			{
				float dx = local[0] - state->blastLocal[0], dy = local[1] - state->blastLocal[1], dz = local[2] - state->blastLocal[2];
				float reach = fabsf(local[0]) + fabsf(local[1]) + fabsf(local[2]);
				state->blastAttached = dx * dx + dy * dy + dz * dz <= (0.5f + 0.001f * reach) * (0.5f + 0.001f * reach);
			}

			memcpy(state->blastLocal, local, sizeof(local));
			state->blastLocalValid = true;
		}
	}

	if (tick)
	{
		float liveMatrix[16];
		float liveLengthScale = 1.0f;
		float liveForceWind[6];
		memcpy(liveMatrix, matrix, sizeof(liveMatrix));

		float s = 1.0f;
		if (state->primed)
		{
			s = 1.0f - (state->accumulator - TARGET_FRAME_TIME) / span;
			if (s < 0.0f) s = 0.0f;
			if (s > 1.0f) s = 1.0f;
		}

		const bool resample = state->primed && s < 1.0f && state->hasPrevInputs && !SimInputsCut(state->prevMatrix, liveMatrix, span);

		if (resample)
		{
			InterpolateSimMatrix(state->prevMatrix, liveMatrix, s, matrix);

			if (layout.lengthScale >= 0)
			{
				float* lengthScale = (float*)(sim + layout.lengthScale);
				liveLengthScale = *lengthScale;
				*lengthScale = state->prevLengthScale + (liveLengthScale - state->prevLengthScale) * s;
			}

			float* force = (float*)(sim + layout.force);
			float* windAmp = (float*)(sim + layout.windAmp);
			memcpy(liveForceWind, force, sizeof(float) * 3);
			memcpy(liveForceWind + 3, windAmp, sizeof(float) * 3);
			for (int j = 0; j < 3; j++)
			{
				force[j] = state->prevForceWind[j] + (liveForceWind[j] - state->prevForceWind[j]) * s;
				windAmp[j] = state->prevForceWind[3 + j] + (liveForceWind[3 + j] - state->prevForceWind[3 + j]) * s;
			}

			// Colliders hang on bones of the same body: interpolated in the body's frame they follow its turn exactly
			float invPrev[9], invLive[9];
			SimInverseBasis(state->prevMatrix, invPrev);
			SimInverseBasis(liveMatrix, invLive);

			for (int c = 0; c < trackedColliders; c++)
			{
				float a[3], b[3];
				SimLocalPoint(state->prevColliders + c * 3, state->prevMatrix, invPrev, a);
				SimLocalPoint(state->liveColliders + c * 3, liveMatrix, invLive, b);

				float local[3] = { a[0] + (b[0] - a[0]) * s, a[1] + (b[1] - a[1]) * s, a[2] + (b[2] - a[2]) * s };
				SimWorldPoint(local, matrix, (float*)(colliders + c * 0x30));
			}

			if (state->restLive)
			{
				for (int i = 0; i < numParticles; i++)
				{
					const float* a = state->restPrev + i * 6;
					const float* b = state->restLive + i * 6;
					float* rest = (float*)(particles + i * stride + 0x20);
					float* normal = (float*)(particles + i * stride + layout.drivenNormal);

					for (int j = 0; j < 3; j++)
					{
						rest[j] = a[j] + (b[j] - a[j]) * s;
						normal[j] = a[3 + j] + (b[3 + j] - a[3 + j]) * s;
					}
				}
			}
		}

		const bool lagBlast = center && state->blastAttached && state->hasTickMatrix;
		if (lagBlast)
		{
			SimWorldPoint(state->blastLocal, state->tickMatrix, center);
			if (liveStrength != 0.0f && state->blastStrengthValid) *(float*)(sim + layout.radialStrength) = state->blastStrength;
		}

		if (state->primed)
		{
			std::swap(state->offPrev, state->offCurr);
		}

		result = original.unsafe_thiscall<uint32_t>(thisPtr, state->primed || !(delta > 0.0f && delta < SIM_STEP_DT) ? SIM_STEP_DT : delta);

		memcpy(state->tickMatrix, matrix, sizeof(state->tickMatrix));
		state->hasTickMatrix = true;
		state->blastStrengthPending = center != nullptr;

		// Everything back the way the callers left it: they and the bone pass that follows read it
		if (resample)
		{
			memcpy(matrix, liveMatrix, sizeof(liveMatrix));
			if (layout.lengthScale >= 0) *(float*)(sim + layout.lengthScale) = liveLengthScale;
			memcpy(sim + layout.force, liveForceWind, sizeof(float) * 3);
			memcpy(sim + layout.windAmp, liveForceWind + 3, sizeof(float) * 3);

			for (int c = 0; c < trackedColliders; c++)
			{
				memcpy(colliders + c * 0x30, state->liveColliders + c * 3, sizeof(float) * 3);
			}

			if (state->restLive)
			{
				for (int i = 0; i < numParticles; i++)
				{
					memcpy(particles + i * stride + 0x20, state->restLive + i * 6, sizeof(float) * 3);
					memcpy(particles + i * stride + layout.drivenNormal, state->restLive + i * 6 + 3, sizeof(float) * 3);
				}
			}
		}

		if (lagBlast)
		{
			memcpy(center, liveCenter, sizeof(liveCenter));
			*(float*)(sim + layout.radialStrength) = liveStrength;
		}

		float scale = SimScale(state->tickMatrix);
		float unscale = scale > 1e-6f ? 1.0f / scale : 1.0f;
		float alpha = state->primed ? (state->accumulator - TARGET_FRAME_TIME) / TARGET_FRAME_TIME : 0.0f;
		if (alpha < 0.0f) alpha = 0.0f;
		if (alpha > 1.0f) alpha = 1.0f;
		const float* offPrev = state->primed ? state->offPrev : state->offCurr;
		if (rootOf) CaptureAndDrawSimParticles<true>(particles, numParticles, stride, rootOf, matrix, unscale, alpha, state->trueP1, offPrev, state->offCurr, state->applied);
		else CaptureAndDrawSimParticles<false>(particles, numParticles, stride, rootOf, matrix, unscale, alpha, state->trueP1, offPrev, state->offCurr, state->applied);

		if (state->primed)
		{
			state->accumulator -= TARGET_FRAME_TIME;
		}
		else
		{
			memcpy(state->offPrev, state->offCurr, numParticles * 4 * sizeof(float));
			state->accumulator = 0.0f;
			state->primed = true;
		}
	}

	float lastMatrix[16];
	memcpy(lastMatrix, state->prevMatrix, sizeof(lastMatrix));
	memcpy(state->prevMatrix, matrix, sizeof(state->prevMatrix));
	if (layout.lengthScale >= 0) state->prevLengthScale = *(float*)(sim + layout.lengthScale);
	memcpy(state->prevForceWind, sim + layout.force, sizeof(float) * 3);
	memcpy(state->prevForceWind + 3, sim + layout.windAmp, sizeof(float) * 3);
	std::swap(state->prevColliders, state->liveColliders);
	if (state->restLive) std::swap(state->restPrev, state->restLive);
	state->hasPrevInputs = true;

	if (tick)
		return result;

	float alpha = state->accumulator / TARGET_FRAME_TIME;
	if (alpha < 0.0f) alpha = 0.0f;
	if (alpha > 1.0f) alpha = 1.0f;

	if (checkFirst)
	{
		if (rootOf) DrawSimParticles<true>(particles, numParticles, stride, rootOf, matrix, alpha, state->offPrev, state->offCurr, state->applied);
		else DrawSimParticles<false>(particles, numParticles, stride, rootOf, matrix, alpha, state->offPrev, state->offCurr, state->applied);
		return result;
	}

	int drawn = 0;
	if (CheckAndDrawSimParticles(particles, numParticles, stride, rootOf, matrix, alpha, state->offPrev, state->offCurr, state->applied, &drawn))
		return result;

	DrawSimParticles<true>(particles, drawn, stride, rootOf, lastMatrix, lastAlpha, state->offPrev, state->offCurr, state->applied);
	return StepTheirs(original, thisPtr, delta, state, particles, numParticles, stride);

	return result;
}

safetyhook::InlineHook HairSimulator;

static void __fastcall HairSimulator_Hook(void* thisPtr, int, float delta)
{
	StepAtFixedRate(HairSimulator, HAIR_LAYOUT, thisPtr, delta);
}

uint32_t StepClothAtFixedRate(safetyhook::InlineHook& original, void* thisPtr, float delta)
{
	return StepAtFixedRate(original, CLOTH_LAYOUT, thisPtr, delta);
}

void ApplyFixHighFPSHairPhysics()
{
	if (!FixHighFPSHairPhysics) return;

	HairSimulator = HookHelper::CreateHook((void*)GetAddress(Addr::HairSimulator), &HairSimulator_Hook);
}
