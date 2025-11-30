// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <stdio.h>
#include <stdarg.h>
#include <LDL/StdFuncs.hpp>
#include <LDL/Format.hpp>

LDL_Formatter::LDL_Formatter()
{
	Clear();
}

void LDL_Formatter::Clear()
{
	LDL_memset(&_buffer, 0, sizeof(_buffer));
}

char* LDL_Formatter::Data()
{
	return _buffer;
}

const char* LDL_Formatter::Data() const
{
	return _buffer;
}

const char* LDL_Formatter::Format(const char* format, ...)
{
	va_list args;
	va_start(args, format);
	vsprintf(_buffer, format, args);
	va_end(args);

	return _buffer;
}
