#include <LDL/Core/TestEqual.hpp>
#include <LDL/Allocators/FixedLinear.hpp>

void Init()
{
	const size_t bytes = LDL::Allocators::Allocator::Mb * 1;

	LDL::Allocators::FixedLinear allocator(bytes);

	LDL_TEST_EQUAL(allocator.UsedBytes() == 0);
}

void Allocate()
{
	const size_t bytes = LDL::Allocators::Allocator::Mb * 1;

	LDL::Allocators::FixedLinear allocator(bytes);

	for (size_t i = 0; i < bytes; i++)
	{
		void* p = allocator.Allocate(1);

		LDL_TEST_EQUAL(p != NULL);
		LDL_TEST_EQUAL(allocator.UsedBytes() == i + 1);
	}
}

void Reallocate()
{
	const size_t bytes = LDL::Allocators::Allocator::Mb * 1;

	LDL::Allocators::FixedLinear allocator(bytes);

	void* ptr = allocator.Allocate(128);

	LDL_TEST_EQUAL(ptr != NULL);
	LDL_TEST_EQUAL(allocator.UsedBytes() == 128);

	ptr = allocator.Reallocate(ptr, 256);

	LDL_TEST_EQUAL(ptr != NULL);
	LDL_TEST_EQUAL(allocator.UsedBytes() == 128 + 256);
}

void Reset()
{
	const size_t bytes = LDL::Allocators::Allocator::Mb * 1;

	LDL::Allocators::FixedLinear allocator(bytes);

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
	Reallocate();
	Reset();

	return 0;
}