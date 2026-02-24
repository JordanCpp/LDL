// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Loaders_FontLoader_hpp
#define LDL_Loaders_FontLoader_hpp

#include <LDL/Allocators/Allocator.hpp>
#include <LDL/STL/InplaceStrings.hpp>

namespace LDL
{
	class LDL_LIBRARY FontLoader
	{
	public:
		FontLoader(Allocator* allocator);
		~FontLoader();
		void Clear();
		void Load(const char* path);
		uint8_t* Font();
		size_t Size();
	private:
		AssertString  _assert;
		Allocator* _allocator;
		uint8_t* _buffer;
	};
}

#endif     
