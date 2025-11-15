// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Platforms_Windows_Core_ConsoleImpl_hpp
#define LDL_Platforms_Windows_Core_ConsoleImpl_hpp

#include <LDL/Platforms/Win9X/Windows.hpp>

namespace LDL
{
	class ConsoleImpl
	{
	public:
		ConsoleImpl();
		void Write(const char* text);
	private:
		HANDLE _output;
	};
}

#endif    
