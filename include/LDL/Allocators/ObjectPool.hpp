#ifndef LDL_Allocators_ObjectPool_hpp
#define LDL_Allocators_ObjectPool_hpp

#include <LDL/Core/Types.hpp>
#include <assert.h>
#include <vector>

namespace LDL
{
	namespace Allocators
	{
		template <typename T, size_t limit>
		class ObjectPool
		{
		public:

			ObjectPool()
			{
				_Objects.resize(limit);
				_Pointers.resize(limit);
			}

			T* New()
			{
				size_t i = 0;

				for (i = 0; i < _Pointers.size(); i++)
				{
					if (_Pointers[i] == NULL)
					{
						_Pointers[i] = &_Objects[i];

						return &_Objects[i];
					}
				}

				assert(i == _Pointers.size());

				return NULL;
			}

			void Delete(T* ptr)
			{
				size_t i = 0;

				while (i < _Pointers.size() && _Pointers[i] != ptr)
				{
					i++;
				}

				assert(i < _Pointers.size());

				_Pointers[i] = NULL;
			}
		private:
			std::vector<T> _Objects;
			std::vector<T*> _Pointers;
		};
	}
}

#endif  