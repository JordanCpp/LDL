// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <stdio.h>
#include <stdarg.h>
#include <LDL/std/string.hpp>
#include <LDL/Core/Formatter.hpp>

using namespace LDL;

Formatter::Formatter()
{
	LDL_memset(&_buffer, 0, sizeof(_buffer));
}

char* Formatter::Format(const char* format, ...)
{
	va_list args;
	va_start(args, format);
	vsprintf(_buffer, format, args);
	va_end(args);

	return _buffer;
}
