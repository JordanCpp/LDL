#ifndef LDL_Allocators_ObjectPool_hpp
#define LDL_Allocators_ObjectPool_hpp

#include <assert.h>
#include <LDL/Allocators/Allocator.hpp>
#include <LDL/Containers/List.hpp>

namespace LDL
{
	namespace Allocators
	{
		template <typename T>
		class ObjectPool
		{
		public:

			ObjectPool(LDL::Allocators::Allocator* allocator) :
				_Allocator(allocator)
			{
			}

			LDL::Containers::ListNode<T>* Make()
			{
				LDL::Containers::ListNode<T>* result = NULL;

				result = (LDL::Containers::ListNode<T>*)_Allocator->Allocate(sizeof(LDL::Containers::ListNode<T>));

				return result;
			}

			T* New()
			{
				LDL::Containers::ListNode<T>* result = _Free.Tail;

				if (result != NULL)
					_Free.Remove(result);
				else
					result = Make();

				_Used.Append(result);

				return (T*)result;
			}

			void Free(T* ptr)
			{
				assert(ptr != NULL);

				_Used.Remove((LDL::Containers::ListNode<T>*)ptr);

				_Free.Append((LDL::Containers::ListNode<T>*)ptr);
			}
		private:
			LDL::Allocators::Allocator* _Allocator;
			LDL::Containers::List<T> _Used;
			LDL::Containers::List<T> _Free;
		};
	}
}

#endif  