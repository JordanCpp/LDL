// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Allocators_SmallAllocator_hpp
#define LDL_Allocators_SmallAllocator_hpp

#include <LDL/Allocators/Allocator.hpp>

namespace LDL
{
	class LDL_LIBRARY SmallAllocator
	{
	public:
		enum
		{
			Buckets = 6,
			Overflow = UINT_MAX
		};

		class Node
		{
		public:
			Node* Next;
			Node* Prev;
			size_t Size;
			void* Data;
		};

		class List
		{
		public:
			Node* Head;
			Node* Tail;
		};

		SmallAllocator(Allocator* allocator);
		size_t CalcBucket(size_t bytes);
		void* Allocate(size_t bytes);
		void Deallocate(void* ptr);
		Node* ToNode(void* ptr);
		size_t CalkSize(size_t bytes);
	private:
		void Append(List* list, Node* node);
		void Remove(List* list, Node* node);
		Allocator* _Allocator;
		List       _Table[Buckets];
	};
}

#endif  
