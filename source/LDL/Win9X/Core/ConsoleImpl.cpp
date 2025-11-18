// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/StdFuncs.hpp>
#include <LDL/Platforms/Win9X/Core/ConsoleImpl.hpp>

using namespace LDL;

ConsoleImpl::ConsoleImpl()
{
	_output = GetStdHandle(STD_OUTPUT_HANDLE);
}

void ConsoleImpl::Write(const char* text)
{
	DWORD count = 0;

	WriteConsoleA(_output, text, (DWORD)LDL::strlen(text), &count, NULL);
}
