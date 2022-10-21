#include <LDL/Core/TestEqual.hpp>
#include <LDL/Allocators/Allocator.hpp>

void CheckSize()
{
	LDL_TEST_EQUAL(LDL::Allocators::Allocator::Kb == 1024);
	LDL_TEST_EQUAL(LDL::Allocators::Allocator::Mb == 1024 * 1024);
	LDL_TEST_EQUAL(LDL::Allocators::Allocator::Gb == 1024 * 1024 * 1024);
}

int main()
{
	CheckSize();

	return 0;
}