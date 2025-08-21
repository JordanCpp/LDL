#include <LDL/Allocators/SmallAllocator.hpp>
#include <assert.h>
#include <math.h>

using namespace LDL::Allocators;

SmallAllocator::SmallAllocator(Allocator* allocator) :
	_Allocator(allocator)
{
	for (size_t i = 0; i < Buckets; i++)
	{
		_Table[i].Head = NULL;
		_Table[i].Tail = NULL;
	}
}

size_t SmallAllocator::CalcBucket(size_t bytes)
{
	assert(bytes <= 1024);

	if (bytes > 0 && bytes <= 16)
		return 0;
	else if (bytes > 16 && bytes <= 32)
		return 1;
	else if (bytes > 32 && bytes <= 64)
		return 2;
	else if (bytes > 64 && bytes <= 128)
		return 3;
	else if (bytes > 128 && bytes <= 256)
		return 4;
	else if (bytes > 256 && bytes <= 512)
		return 5;
	else if (bytes > 512 && bytes <= 1024)
		return 6;
	else
		return Overflow;
}

void* SmallAllocator::Allocate(size_t bytes)
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
		result->Size = CalckSize(bucket);
		result->Data = _Allocator->Allocate(result->Size);
	}

	Append(&_Table[bucket], result);

	return result->Data;
}

void SmallAllocator::Deallocate(void* ptr)
{
	assert(ptr != NULL);

	Node* node = (Node*)(size_t)ptr - sizeof(Node) + sizeof(void*);

	size_t bucket = CalcBucket(node->Size);

	assert(bucket < Buckets);

	Remove(&_Table[bucket], node);
	Append(&_Table[bucket], node);
}

SmallAllocator::Node* LDL::Allocators::SmallAllocator::ToNode(void* ptr)
{
	assert(ptr != NULL);

	return (Node*)(size_t)ptr - sizeof(Node) + sizeof(void*);
}

size_t SmallAllocator::CalckSize(size_t bucket)
{
	assert(bucket <= Buckets);

	if (bucket == 0)
		return 16;
	else if (bucket == 1)
		return 32;
	else if (bucket == 2)
		return 64;
	else if (bucket == 3)
		return 128;
	else if (bucket == 4)
		return 256;
	else if (bucket == 5)
		return 512;
	else if (bucket == 6)
		return 1024;
	else
		return Overflow;
}

void SmallAllocator::Append(List* list, Node* node)
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

void SmallAllocator::Remove(List* list, Node* node)
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
