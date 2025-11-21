// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_APIs_SDL3_SDL_video_h
#define LDL_APIs_SDL3_SDL_video_h

#include <LDL/SDL3/config.h>
#include <LDL/SDL3/SDL_stdinc.h>

#ifdef __cplusplus
extern "C" {
#endif 

typedef Uint64 SDL_WindowFlags;
typedef Uint32 SDL_WindowID;

typedef struct SDL_Window SDL_Window;

extern SDL_DECLSPEC SDL_Window* SDLCALL SDL_CreateWindow(const char* title, int w, int h, SDL_WindowFlags flags);
extern SDL_DECLSPEC void SDLCALL SDL_DestroyWindow(SDL_Window* window);

#ifdef __cplusplus
}
#endif

#endif
