// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <stdio.h>
#include <stdlib.h>
#include <LDL/Assert.hpp>

void LDL_Assert(bool condition, const char* description, const char* detail, const char* file, int line)
{
	if (!condition)
	{
		printf("%s, detail: %s, file: %s, line: %d\n", description, detail, file, line);
		abort();
	}
}
