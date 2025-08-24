// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/Assert.hpp>
#include <LDL/Core/Console.hpp>
#include <LDL/Core/Terminate.hpp>
#include <LDL/Core/Convert.hpp>
#include <LDL/STL/inplace_strings.hpp>

using namespace LDL::Core;

void LDL::Core::Assert(bool condition, const char* description, const char* detail, const char* file, size_t line)
{
	if (!condition)
	{
		Convert conv;

		AssertString message;

		message += description;
		message += ", detail ";
		message += detail;
		message += ", file ";
		message += file;
		message += ", line ";
		message += conv.ToString(line);
		message += '\n';

		Console console;
		console.Write(message.c_str());

		Terminate();
	}
}
