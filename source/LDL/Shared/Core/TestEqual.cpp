// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/TestEqual.hpp>
#include <LDL/Core/Convert.hpp>
#include <LDL/Core/Console.hpp>
#include <LDL/STL/inplace_strings.hpp>
#include <LDL/Core/Formatter.hpp>

using namespace LDL;

void LDL::TestEqual(bool condition, const char* description, const char* function, const char* file, size_t line)
{
	if (!condition)
	{
		Formatter formatter;

		Console console;
		console.Write(formatter.Format("Test failed: %s, function: %s, file: %s, line: %d\n", description, function, file, line));
	}
}
