#ifndef LDL_Allocators_SmallAllocator_hpp
#define LDL_Allocators_SmallAllocator_hpp

#include <LDL/Config.hpp>
#include <LDL/Allocators/Allocator.hpp>

namespace LDL
{
	namespace Allocators
	{
		class LDL_EXPORT SmallAllocator
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

			SmallAllocator(LDL::Allocators::Allocator* allocator);
			size_t CalcBucket(size_t bytes);
			void* Allocate(size_t bytes);
			void Deallocate(void* ptr);
			Node* ToNode(void* ptr);
			size_t CalckSize(size_t bytes);
		private:
			void Append(List* list, Node* node);
			void Remove(List* list, Node* node);
			LDL::Allocators::Allocator* _Allocator;
			List _Table[Buckets];
		};
	}
}

#endif  