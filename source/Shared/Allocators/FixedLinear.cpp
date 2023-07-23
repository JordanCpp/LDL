#include <LDL/Allocators/FixedLinear.hpp>
#include <assert.h>

using namespace LDL::Allocators;

FixedLinear::FixedLinear(size_t bytes, Allocator* allocator):
	_Capacity(bytes),
	_Position(0),
	_Content(NULL),
	_Allocator(allocator)
{
	if (_Allocator)
		_Content = (uint8_t*)_Allocator->Allocate(_Capacity);
	else
		_Content = new uint8_t[_Capacity];
}

FixedLinear::~FixedLinear()
{
	if (_Allocator)
		_Allocator->Deallocate(_Content);
	else
		delete[] _Content;
}

void* FixedLinear::Allocate(size_t bytes)
{
	assert(bytes > 0);

	assert(_Position + bytes <= _Capacity);

	void* result = _Content + _Position;

	_Position += bytes;

	return result;
}

void FixedLinear::Deallocate(void* ptr)
{
}

size_t FixedLinear::UsedBytes()
{
	return _Position;
}

void FixedLinear::Reset()
{
	_Position = 0;
}
