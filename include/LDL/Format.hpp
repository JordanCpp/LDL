// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Format_hpp
#define LDL_Format_hpp

#include <LDL/Config.hpp>

class LDL_LIBRARY LDL_Formatter
{
public:
	enum
	{
		Max = 512
	};

	LDL_Formatter();
	void Clear();
	char* Data();
	const char* Data() const;
	const char* Format(const char* format, ...);
private:
	void LDL_Reverse(char* s, int len);
	int LDL_itoa(int num, char* str);
	char _buffer[Max];
};

#endif    
