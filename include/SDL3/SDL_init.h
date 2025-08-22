// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef SDL3_SDL_init_h
#define SDL3_SDL_init_h

#include <SDL3/SDL_stdinc.h>

typedef Uint32 SDL_InitFlags;

bool SDL_Init(SDL_InitFlags flags);
void SDL_Quit(void);

#endif
