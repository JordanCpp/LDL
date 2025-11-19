// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Core_Convert_hpp
#define LDL_Core_Convert_hpp

#include <LDL/Config.hpp>
#include <LDL/Types.hpp>

class LDL_LIBRARY LDL_Convert
{
public:
	LDL_Convert();
	const char* ToString(intmax_t num, uint8_t base = 10);
private:
	void Swap(char& t1, char& t2);
	void Reverse(char* str, size_t length);
	char _buffer[66]; // 64 bits + '-' + '\0'
};

#endif    
