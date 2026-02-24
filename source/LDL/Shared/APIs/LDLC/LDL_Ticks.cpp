// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDLC/LDL_Ticks.h>
#include <LDL/Time/Ticks.hpp>

using namespace LDL;

size_t LDL_Ticks()
{
	return Ticks();
}

void LDL_Delay(size_t count)
{
	Delay(count);
}
