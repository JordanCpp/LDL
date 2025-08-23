// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Allocators_ObjectPool_hpp
#define LDL_Allocators_ObjectPool_hpp

#include <LDL/Core/Types.hpp>
#include <assert.h>

namespace LDL
{
	namespace Allocators
	{
        template <typename T, size_t limit>
        class ObjectPool
        {
        private:
            T       _objects[limit];
            T*      _freeList[limit];
            size_t  _freeCount;

        public:
            ObjectPool() : _freeCount(0)
            {
                for (size_t i = 0; i < limit; i++)
                {
                    _freeList[i] = &_objects[i];
                    _freeCount++;
                }
            }

            T* New()
            {
                assert(_freeCount > 0);
                
                if (_freeCount == 0)
                {
                    return NULL;
                }

                return _freeList[--_freeCount];
            }

            void Delete(T* ptr)
            {
                assert(ptr != NULL);
                assert(_freeCount < limit);

                _freeList[_freeCount++] = ptr;
            }
        };
	}
}

#endif  
