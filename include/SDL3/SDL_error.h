// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef SDL3_SDL_error_h
#define SDL3_SDL_error_h

#include <SDL3/SDL_config.h>
#include <SDL3/SDL_stdinc.h>

#ifdef __cplusplus
extern "C" {
#endif 

extern SDL_DECLSPEC const char* SDLCALL SDL_GetError(void);

#ifdef __cplusplus
}
#endif

#endif
