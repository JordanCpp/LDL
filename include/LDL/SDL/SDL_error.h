// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_APIs_SDL_SDL_error_h
#define LDL_APIs_SDL_SDL_error_h

#include <LDL/SDL/SDL_config.h>
#include <LDL/SDL/SDL_stdinc.h>

#ifdef __cplusplus
extern "C" {
#endif 

extern SDL_DECLSPEC void  SDLCALL SDL_SetError(const char* fmt, ...);
extern SDL_DECLSPEC char* SDLCALL SDL_GetError(void);
extern SDL_DECLSPEC void  SDLCALL SDL_ClearError(void);

#ifdef __cplusplus
}
#endif

#endif
