#include <LDL/Allocators/SmallAllocator.hpp>
#include <assert.h>

LDL::Allocators::SmallAllocator::SmallAllocator(LDL::Allocators::Allocator* allocator) :
	_Allocator(allocator)
{
}

size_t LDL::Allocators::SmallAllocator::CalcBucket(size_t bytes)
{
	return size_t();
}

void* LDL::Allocators::SmallAllocator::Allocate(size_t bytes)
{
	size_t bucket = CalcBucket(bytes);

	assert(bucket < Buckets);

	Node* result = _Table[bucket].Tail;

	if (result != NULL)
	{
		Remove(&_Table[bucket], result);
	}
	else
	{
		result = (Node*)_Allocator->Allocate(sizeof(Node));
		result->Size = bytes;
		result->Data = _Allocator->Allocate(sizeof(bytes));
	}

	Append(&_Table[bucket], result);

	return result->Data;
}

void LDL::Allocators::SmallAllocator::Deallocate(void* ptr)
{
	assert(ptr != NULL);

	Node* node = (Node*)(size_t)ptr - sizeof(Node) + sizeof(void*);

	size_t bucket = CalcBucket(node->Size);

	assert(bucket < Buckets);

	Remove(&_Table[bucket], node);
	Append(&_Table[bucket], node);
}

LDL::Allocators::SmallAllocator::Node* LDL::Allocators::SmallAllocator::ToNode(void* ptr)
{
	assert(ptr != NULL);

	return (Node*)(size_t)ptr - sizeof(Node) + sizeof(void*);
}

void LDL::Allocators::SmallAllocator::Append(List* list, Node* node)
{
	node->Next = NULL;
	node->Prev = list->Tail;

	if (list->Tail)
	{
		list->Tail->Next = node;
	}

	list->Tail = node;

	if (list->Head == NULL)
	{
		list->Head = node;
	}
}

void LDL::Allocators::SmallAllocator::Remove(List* list, Node* node)
{
	if (node->Prev)
	{
		node->Prev->Next = node->Next;
	}

	if (node->Next)
	{
		node->Next->Prev = node->Prev;
	}

	if (!node->Prev)
	{
		list->Head = node->Next;
	}

	if (!node->Next)
	{
		list->Tail = node->Prev;
	}
}