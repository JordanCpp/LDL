// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Core_Library_hpp
#define LDL_Core_Library_hpp

#include <LDL/Config.hpp>
#include <LDL/std/stdint.hpp>

namespace LDL
{
	typedef void(*VoidFuncPtr)(void);

	class LibraryImpl;

	class LDL_LIBRARY Library
	{
	public:
		enum
		{
			SizeOf = 512
		};
		Library(const char* path);
		~Library();
		VoidFuncPtr Function(const char* name);
	private:
		LibraryImpl* _impl;
		uint8_t      _memory[SizeOf];
	};
}

#endif    
