// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/TestEqual.hpp>
#include <LDL/Allocators/ObjectPool.hpp>

using namespace LDL::Allocators;

const size_t Count = 128;

void ObjectPoolTest()
{
	ObjectPool<size_t, Count> objectPool;

	size_t* p1 = objectPool.New();

	LDL_TEST_EQUAL(p1 != NULL);

	objectPool.Delete(p1);

	size_t* p2 = objectPool.New();

	LDL_TEST_EQUAL(p2 != NULL);
	LDL_TEST_EQUAL(p2 == p1);

	objectPool.Delete(p2);
}

int main()
{
	ObjectPoolTest();

	return 0;
}
