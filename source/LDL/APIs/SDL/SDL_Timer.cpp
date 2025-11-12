// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/APIs/SDL/SDL_timer.h>
#include <LDL/Time/Ticks.hpp>

using namespace LDL;

Uint32 SDL_GetTicks(void)
{
	return (Uint32)Ticks();
}

void SDL_Delay(Uint32 ms)
{
	Delay(ms);
}
