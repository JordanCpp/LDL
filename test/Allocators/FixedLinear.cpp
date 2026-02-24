// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/TestEqual.hpp>
#include <LDL/Allocators/FixedLinear.hpp>

using namespace LDL;

void Init()
{
	const size_t bytes = Allocator::Mb * 1;

	FixedLinear allocator(bytes);

	LDL_TEST_EQUAL(allocator.UsedBytes() == 0);
}

void Allocate()
{
	const size_t bytes = Allocator::Mb * 1;

	FixedLinear allocator(bytes);

	for (size_t i = 0; i < bytes; i++)
	{
		void* p = allocator.Allocate(1);

		LDL_TEST_EQUAL(p != NULL);
		LDL_TEST_EQUAL(allocator.UsedBytes() == i + 1);
	}
}

void Reset()
{
	const size_t bytes = Allocator::Mb * 1;

	FixedLinear allocator(bytes);

	void* ptr = allocator.Allocate(1024);

	LDL_TEST_EQUAL(ptr != NULL);
	LDL_TEST_EQUAL(allocator.UsedBytes() == 1024);

	allocator.Reset();

	LDL_TEST_EQUAL(allocator.UsedBytes() == 0);
}

int main()
{
	Init();
	Allocate();
	Reset();

	return 0;
}
