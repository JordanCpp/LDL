// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/TestEqual.hpp>
#include <LDL/Core/Convert.hpp>
#include <LDL/Core/Console.hpp>

void LDL::TestEqual(bool condition, const std::string& description, const std::string& function, const std::string& file, size_t line)
{
	if (!condition)
	{
		Convert conv;

		std::string message = '\n' + "Test failed: " + description + ", function " + function + ", file " + file + ", line " + conv.ToString(line) + '\n';

		Console console;
		console.Write(message);
	}
}
