#include <LDL/Core/TestEqual.hpp>
#include <LDL/Allocators/Allocator.hpp>

using namespace LDL::Allocators;

void CheckSize()
{
	LDL_TEST_EQUAL(Allocator::Kb == 1024);
	LDL_TEST_EQUAL(Allocator::Mb == 1024 * 1024);
	LDL_TEST_EQUAL(Allocator::Gb == 1024 * 1024 * 1024);
}

int main()
{
	CheckSize();

	return 0;
}
