// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_APIs_SDL2_SDL_video_h
#define LDL_APIs_SDL2_SDL_video_h

#include <LDL/SDL2/SDL_config.h>
#include <LDL/SDL2/SDL_stdinc.h>

#ifdef __cplusplus
extern "C" {
#endif 

typedef struct SDL_Window SDL_Window;

extern SDL_DECLSPEC SDL_Window* SDLCALL SDL_CreateWindow(const char* title, int x, int y, int w, int h, Uint32 flags);
extern SDL_DECLSPEC void        SDLCALL SDL_DestroyWindow(SDL_Window* window);

#ifdef __cplusplus
}
#endif

#endif
