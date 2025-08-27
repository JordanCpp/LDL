// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/std/string.hpp>
#include <LDL/Platforms/Windows/Core/ConsoleImpl.hpp>

using namespace LDL;

ConsoleImpl::ConsoleImpl()
{
	_output = GetStdHandle(STD_OUTPUT_HANDLE);
}

void ConsoleImpl::Write(const char* text)
{
	DWORD count = 0;

	WriteConsole(_output, text, (DWORD)LDL::strlen(text), &count, NULL);
}
