// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/SDL/timer.h>
#include <LDL/Ticks.hpp>

Uint32 SDL_GetTicks(void)
{
	return (Uint32)LDL_Ticks();
}

void SDL_Delay(Uint32 ms)
{
	LDL_Delay(ms);
}
