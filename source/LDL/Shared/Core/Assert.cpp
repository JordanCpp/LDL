// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/Assert.hpp>
#include <LDL/Core/Console.hpp>
#include <LDL/Core/Terminate.hpp>
#include <LDL/Core/Formatter.hpp>
#include <LDL/Core/InPlaceStrings.hpp>

using namespace LDL;

void LDL::Assert(bool condition, const char* description, const char* detail, const char* file, size_t line)
{
	if (!condition)
	{
		Console console;
		Formatter formatter;

		console.Write(formatter.Format("%s, detail: %s, file: %s, line: %d\n", description, detail, file, line));

		Terminate();
	}
}
