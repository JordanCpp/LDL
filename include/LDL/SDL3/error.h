// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_SDL3_error_h
#define LDL_SDL3_error_h

#include <LDL/SDL3/config.h>
#include <LDL/SDL3/stdinc.h>

#ifdef __cplusplus
extern "C" {
#endif 

extern SDL_DECLSPEC const char* SDLCALL SDL_GetError(void);

#ifdef __cplusplus
}
#endif

#endif
