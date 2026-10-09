#include "Common.hpp"
#include "Features.hpp"

void ApplyFixSlowLoading()
{
	if (!FixSlowLoading) return;

	MemoryHelper::MakeJMP(GetAddress(Addr::AsyncIOCacheHandles), GetAddress(Addr::AsyncIOCacheHandlesEnd));
}
