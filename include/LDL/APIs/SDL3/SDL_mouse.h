// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_APIs_SDL3_SDL_mouse_h
#define LDL_APIs_SDL3_SDL_mouse_h

#include <LDL/APIs/SDL3/SDL_stdinc.h>

#ifdef __cplusplus
extern "C" {
#endif 

typedef Uint32 SDL_MouseID;

typedef Uint32 SDL_MouseButtonFlags;

#define SDL_BUTTON_LEFT     (1)
#define SDL_BUTTON_MIDDLE   (2)
#define SDL_BUTTON_RIGHT    (3)
#define SDL_BUTTON_X1       (4)
#define SDL_BUTTON_X2       (5)

#define SDL_BUTTON_MASK(X)  (1u << ((X)-1))
#define SDL_BUTTON_LMASK    SDL_BUTTON_MASK(SDL_BUTTON_LEFT)
#define SDL_BUTTON_MMASK    SDL_BUTTON_MASK(SDL_BUTTON_MIDDLE)
#define SDL_BUTTON_RMASK    SDL_BUTTON_MASK(SDL_BUTTON_RIGHT)
#define SDL_BUTTON_X1MASK   SDL_BUTTON_MASK(SDL_BUTTON_X1)
#define SDL_BUTTON_X2MASK   SDL_BUTTON_MASK(SDL_BUTTON_X2)

#ifdef __cplusplus
}
#endif

#endif
