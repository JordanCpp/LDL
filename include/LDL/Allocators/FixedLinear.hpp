// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Allocators_FixedLinear_hpp
#define LDL_Allocators_FixedLinear_hpp

#include <LDL/Core/Config.hpp>
#include <LDL/std/stdint.hpp>
#include <LDL/Allocators/Allocator.hpp>

namespace LDL
{
	namespace Allocators
	{
		class LDL_LIBRARY FixedLinear : public Allocator
		{
		public:
			FixedLinear(size_t bytes, Allocator* allocator = NULL);
			~FixedLinear();
			void* Allocate(size_t bytes);
			void* AllocateAligned(size_t bytes, size_t alignment);
			void Deallocate(void* ptr);
			void Reset();
			size_t UsedBytes();
			size_t Capacity() const;
		private:
			size_t     _capacity;
			size_t     _position;
			uint8_t*   _content;
			Allocator* _allocator;
		};
	}
}

#endif  
