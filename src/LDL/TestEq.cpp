// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <stdio.h>
#include <LDL/TestEq.hpp>

void LDL_TestEqual(bool condition, const char* description, const char* function, const char* file, int line)
{
	if (!condition)
	{
		printf("Test failed: %s, function: %s, file: %s, line: %d\n", description, function, file, line);
	}
}
