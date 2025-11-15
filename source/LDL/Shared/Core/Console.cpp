// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/Console.hpp>

#if defined(LDL_WINDOWS_NT)
    #include <LDL/Platforms/WinNT/Core/ConsoleImpl.hpp>
#elif defined(LDL_WINDOWS_9X)
    #include <LDL/Platforms/Win9X/Core/ConsoleImpl.hpp>
#elif defined(__unix__)
    #include <LDL/Platforms/Linux/Core/ConsoleImpl.hpp>
#endif

using namespace LDL;

Console::Console() :
	_impl(new ConsoleImpl())
{
}

Console::~Console()
{
	delete _impl;
}

void Console::Write(const char* text)
{
	_impl->Write(text);
}
