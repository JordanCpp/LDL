#include <LDL/Core/TestEqual.hpp>
#include <LDL/Allocators/ObjectPool.hpp>

using namespace LDL::Allocators;

const size_t Count = 1024;

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
