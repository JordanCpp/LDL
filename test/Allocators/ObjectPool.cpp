#include <LDL/Core/TestEqual.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <LDL/Allocators/ObjectPool.hpp>

using namespace LDL::Allocators;

void ObjectPoolTest()
{
	const size_t bytes = Allocator::Mb * 1;

	FixedLinear allocator(bytes);

	ObjectPool<size_t> objectPool(&allocator);

	size_t* p1 = objectPool.New();

	LDL_TEST_EQUAL(p1 != NULL);

	objectPool.Free(p1);

	size_t* p2 = objectPool.New();

	LDL_TEST_EQUAL(p2 != NULL);
	LDL_TEST_EQUAL(p2 == p1);

	objectPool.Free(p2);
}

int main()
{
	ObjectPoolTest();

	return 0;
}