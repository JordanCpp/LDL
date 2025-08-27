// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/TestEqual.hpp>
#include <LDL/Input/Mouse.hpp>

using namespace LDL;

void GetPos()
{
	Mouse mouse;
	
	LDL_TEST_EQUAL(mouse.Pos().x > 0);
	LDL_TEST_EQUAL(mouse.Pos().y > 0);
}

int main()
{
	GetPos();

	return 0;
}
