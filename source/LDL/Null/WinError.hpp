// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Platforms_WinNT_WinError_hpp
#define LDL_Platforms_WinNT_WinError_hpp

#include <LDL/InPlaceStrings.hpp>

namespace LDL
{
	class WindowError
	{
	public:
		WindowError();
		void Clear();
		const char* GetErrorMessage();
	private:
		ErrorString _buffer;
	};
}

#endif    
