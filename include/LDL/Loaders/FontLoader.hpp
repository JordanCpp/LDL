// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Loaders_FontLoader_hpp
#define LDL_Loaders_FontLoader_hpp

#include <LDL/Allocators/Allocator.hpp>
#include <LDL/Containers/inplace_strings.hpp>

namespace LDL
{
	namespace Loaders
	{
		class LDL_LIBRARY FontLoader
		{
		public:
			FontLoader(Allocators::Allocator* allocator);
			~FontLoader();
			void Clear();
			void Load(const char* path);
			uint8_t* Font();
			size_t Size();
		private:
			AssertString _assert;
			Allocators::Allocator* _allocator;
			uint8_t*               _buffer;
		};
	}
}

#endif     
