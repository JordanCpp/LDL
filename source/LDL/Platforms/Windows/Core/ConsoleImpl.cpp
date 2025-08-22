// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Platforms/Windows/Core/ConsoleImpl.hpp>

using namespace LDL::Core;

ConsoleImpl::ConsoleImpl()
{
	_output = GetStdHandle(STD_OUTPUT_HANDLE);
}

void ConsoleImpl::Write(const std::string& text)
{
	DWORD count = 0;

	WriteConsole(_output, text.c_str(), text.size(), &count, NULL);
}
