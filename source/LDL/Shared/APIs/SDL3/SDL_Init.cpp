// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Config.hpp>
#include <SDL3/SDL_init.h>

bool SDL_Init(SDL_InitFlags flags)
{
	LDL_UNUSED(flags);

	return true;
}
