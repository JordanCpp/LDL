// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/TestEqual.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <LDL/Allocators/SmallAllocator.hpp>

using namespace LDL;

const size_t bytes = Allocator::Mb * 1;

void CalcBucket()
{
	FixedLinear allocator(bytes);

	SmallAllocator smallAllocator(&allocator);
}

int main()
{
	CalcBucket();

	FixedLinear allocator(bytes);

	SmallAllocator smallAllocator(&allocator);

	size_t* p1 = (size_t*)smallAllocator.Allocate(sizeof(size_t));
	LDL_TEST_EQUAL(p1 != NULL);
	SmallAllocator::Node* node1 = smallAllocator.ToNode(p1);
	LDL_TEST_EQUAL(node1->Size == 8);
	LDL_TEST_EQUAL(node1->Data == p1);
	smallAllocator.Deallocate(p1);
	LDL_TEST_EQUAL(p1 != NULL);

	size_t* p2 = (size_t*)smallAllocator.Allocate(sizeof(size_t));
	SmallAllocator::Node* node2 = smallAllocator.ToNode(p2);

	LDL_TEST_EQUAL(node2->Size == 8);
	LDL_TEST_EQUAL(node2 == node1);

	return 0;
}
