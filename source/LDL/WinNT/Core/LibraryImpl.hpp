// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Platforms_WinNT_Core_LibraryImpl_hpp
#define LDL_Platforms_WinNT_Core_LibraryImpl_hpp

#include <LDL/Core/Library.hpp>
#include <LDL/Core/InPlaceStrings.hpp>
#include <LDL/WinNT/Windows.hpp>

namespace LDL
{
	class LibraryImpl
	{
	public:
		LibraryImpl(const char* path);
		~LibraryImpl();
		LDL::VoidFuncPtr Function(const char* name);
	private:
		AssertString _assert;
		HMODULE      _module;
	};
}

#endif    
