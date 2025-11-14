// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/APIs/SDL/SDL_init.h>

int SDL_Init(Uint32 flags)
{
	LDL_UNUSED(flags);

	return 1;
}

void SDL_Quit(void)
{
}
