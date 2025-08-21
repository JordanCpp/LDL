#include <LDLC/LDL_FixedLinear.h>
#include <LDL/Allocators/FixedLinear.hpp>

using namespace LDL::Allocators;

struct LDL_FixedLinear
{
	FixedLinear _fixedLinear;
	LDL_FixedLinear(size_t bytes, void * allocator);
};

LDL_FixedLinear::LDL_FixedLinear(size_t bytes, void* allocator) :
	_fixedLinear(bytes, (Allocator*)allocator)
{
}

LDL_FixedLinear* LDL_FixedLinearNew(size_t bytes, void* allocator)
{
	LDL_FixedLinear* p = new LDL_FixedLinear(bytes, allocator);

	return p;
}

void LDL_FixedLinearFree(LDL_FixedLinear* ptr)
{
	delete ptr;
}

void* LDL_FixedLinearAllocate(LDL_FixedLinear* fixedLinear, size_t bytes)
{
	return fixedLinear->_fixedLinear.Allocate(bytes);
}

void LDL_FixedLinearDeallocate(LDL_FixedLinear* fixedLinear, void* ptr)
{
	fixedLinear->_fixedLinear.Deallocate(ptr);
}

void LDL_FixedLinearReset(LDL_FixedLinear* fixedLinear)
{
	fixedLinear->_fixedLinear.Reset();
}

size_t LDL_FixedLinearUsedBytes(LDL_FixedLinear* fixedLinear)
{
	return fixedLinear->_fixedLinear.UsedBytes();
}
