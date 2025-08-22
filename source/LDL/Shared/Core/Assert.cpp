// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/Assert.hpp>
#include <LDL/Core/Console.hpp>
#include <LDL/Core/Terminate.hpp>
#include <LDL/Core/Convert.hpp>

using namespace LDL::Core;

void LDL::Core::Assert(bool condition, const std::string& description, const std::string& detail, const char* file, size_t line)
{
	if (!condition)
	{
		Convert conv;

		std::string message = '\n' + "Assert: " + description + ", detail " + detail + ", file " + file + ", line " + conv.ToString(line) + '\n';

		Console console;
		console.Write(message);

		Terminate();
	}
}
