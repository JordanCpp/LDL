// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/StdFuncs.hpp>
#include <LDL/SDL2/stdinc.h>

void* SDL_malloc(size_t size)
{
	return LDL_malloc(size);
}

void SDL_free(void* mem)
{
	LDL_free(mem);
}
