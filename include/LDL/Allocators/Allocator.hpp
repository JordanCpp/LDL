// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Allocators_Allocator_hpp
#define LDL_Allocators_Allocator_hpp

#include <LDL/Core/Types.hpp>

namespace LDL
{
	namespace Allocators
	{
		class Allocator
		{
		public:
			enum
			{
				Kb = 1024,
				Mb = Kb * 1024,
				Gb = Mb * 1024
			};
			virtual ~Allocator() {}
			virtual void* Allocate(size_t bytes) = 0;
			virtual void* AllocateAligned(size_t bytes, size_t alignment) = 0;
			virtual void Deallocate(void* ptr) = 0;
			virtual size_t UsedBytes() = 0;
			virtual size_t Capacity() const = 0;
			virtual void Reset() = 0;
		};
	}
}

#endif    
