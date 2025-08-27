// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/TestEqual.hpp>
#include <LDL/Core/Convert.hpp>
#include <string.h>

using namespace LDL;

int main()
{
	Convert convert;

	LDL_TEST_EQUAL(strcmp(convert.ToString(100500), "100500") == 0);

	return 0;
}
