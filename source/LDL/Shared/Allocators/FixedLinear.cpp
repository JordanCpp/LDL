// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Allocators/FixedLinear.hpp>
#include <assert.h>

using namespace LDL::Allocators;

FixedLinear::FixedLinear(size_t bytes, Allocator* allocator):
	_capacity(bytes),
	_position(0),
	_content(NULL),
	_allocator(allocator)
{
	if (_allocator)
		_content = (uint8_t*)_allocator->Allocate(_capacity);
	else
		_content = new uint8_t[_capacity];
}

FixedLinear::~FixedLinear()
{
	if (_allocator)
		_allocator->Deallocate(_content);
	else
		delete[] _content;
}

void* FixedLinear::Allocate(size_t bytes)
{
	assert(bytes > 0);

	assert(_position + bytes <= _capacity);

	void* result = _content + _position;

	_position += bytes;

	return result;
}

void* FixedLinear::AllocateAligned(size_t bytes, size_t alignment)
{
	return NULL;
}

void FixedLinear::Deallocate(void* ptr)
{
}

size_t FixedLinear::UsedBytes()
{
	return _position;
}

size_t FixedLinear::Capacity() const
{
	return _capacity;
}

void FixedLinear::Reset()
{
	_position = 0;
}
