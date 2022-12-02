#include <LDL/Core/TestEqual.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <LDL/Allocators/SmallAllocator.hpp>

int main()
{
	const size_t bytes = LDL::Allocators::Allocator::Mb * 1;

	LDL::Allocators::FixedLinear allocator(bytes);

	LDL::Allocators::SmallAllocator smallAllocator(&allocator);

	size_t* p1 = (size_t*)smallAllocator.Allocate(sizeof(size_t));
	LDL_TEST_EQUAL(p1 != NULL);
	LDL::Allocators::SmallAllocator::Node* node1 = smallAllocator.ToNode(p1);
	LDL_TEST_EQUAL(node1->Size == 8);
	LDL_TEST_EQUAL(node1->Data == p1);
	smallAllocator.Deallocate(p1);
	LDL_TEST_EQUAL(p1 != NULL);

	size_t* p2 = (size_t*)smallAllocator.Allocate(sizeof(size_t));
	LDL::Allocators::SmallAllocator::Node* node2 = smallAllocator.ToNode(p2);

	LDL_TEST_EQUAL(node2->Size == 8);
	LDL_TEST_EQUAL(node2 == node1);

	return 0;
}