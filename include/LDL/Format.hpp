// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Core_Formatter_hpp
#define LDL_Core_Formatter_hpp

#include <LDL/Config.hpp>

class LDL_LIBRARY LDL_Formatter
{
public:
	enum
	{
		Max = 512
	};
	LDL_Formatter();
	char* Format(const char* format, ...);
private:
	char _buffer[Max];
};

#endif    
