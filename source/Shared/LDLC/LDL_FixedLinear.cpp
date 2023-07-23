#include <LDLC/LDL_FixedLinear.h>
#include <LDL/Allocators/FixedLinear.hpp>

using namespace LDL::Allocators;

struct LDL_FixedLinear
{
	FixedLinear _FixedLinear;
	LDL_FixedLinear(size_t bytes, void * allocator);
};

LDL_FixedLinear::LDL_FixedLinear(size_t bytes, void* allocator) :
	_FixedLinear(bytes, (Allocator*)allocator)
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
	return fixedLinear->_FixedLinear.Allocate(bytes);
}

void LDL_FixedLinearDeallocate(LDL_FixedLinear* fixedLinear, void* ptr)
{
	fixedLinear->_FixedLinear.Deallocate(ptr);
}

void LDL_FixedLinearReset(LDL_FixedLinear* fixedLinear)
{
	fixedLinear->_FixedLinear.Reset();
}

size_t LDL_FixedLinearUsedBytes(LDL_FixedLinear* fixedLinear)
{
	return fixedLinear->_FixedLinear.UsedBytes();
}
