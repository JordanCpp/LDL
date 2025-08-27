// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/TestEqual.hpp>
#include <LDL/Math/Vec2.hpp>

using namespace LDL;

void Default()
{
	Vec2f vec;

	LDL_TEST_EQUAL(vec.x == 0.0f);
	LDL_TEST_EQUAL(vec.y == 0.0f);
}

void InitValues()
{
	Vec2f vec(1.0f, 2.0f);

	LDL_TEST_EQUAL(vec.x == 1.0f);
	LDL_TEST_EQUAL(vec.y == 2.0f);
}

int main()
{
	Default();
	InitValues();

	return 0;
}
