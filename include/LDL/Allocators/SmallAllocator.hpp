#ifndef LDL_Allocators_SmallAllocator_hpp
#define LDL_Allocators_SmallAllocator_hpp

#include <LDL/Allocators/Allocator.hpp>

namespace LDL
{
	namespace Allocators
	{
		class SmallAllocator
		{
		public:
			enum
			{
				Buckets = 16
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

			SmallAllocator(LDL::Allocators::Allocator* allocator);
			size_t CalcBucket(size_t bytes);
			void* Allocate(size_t bytes);
			void Deallocate(void* ptr);
			Node* ToNode(void* ptr);
		private:
			void Append(List* list, Node* node);
			void Remove(List* list, Node* node);
			LDL::Allocators::Allocator* _Allocator;
			List _Table[Buckets];
		};
	}
}

#endif  