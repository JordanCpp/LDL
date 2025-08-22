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
				_objects.resize(limit);
				_pointers.resize(limit);
			}

			T* New()
			{
				size_t i = 0;

				for (i = 0; i < _pointers.size(); i++)
				{
					if (_pointers[i] == NULL)
					{
						_pointers[i] = &_objects[i];

						return &_objects[i];
					}
				}

				assert(i == _pointers.size());

				return NULL;
			}

			void Delete(T* ptr)
			{
				size_t i = 0;

				while (i < _pointers.size() && _pointers[i] != ptr)
				{
					i++;
				}

				assert(i < _pointers.size());

				_pointers[i] = NULL;
			}
		private:
			std::vector<T>  _objects;
			std::vector<T*> _pointers;
		};
	}
}

#endif  
