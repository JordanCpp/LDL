// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef SDL3_SDL_video_h
#define SDL3_SDL_video_h

#include <SDL3/SDL_stdinc.h>

typedef Uint64 SDL_WindowFlags;
typedef Uint32 SDL_WindowID;

typedef struct SDL_Window SDL_Window;

SDL_Window* SDL_CreateWindow(const char* title, int w, int h, SDL_WindowFlags flags);
void SDL_DestroyWindow(SDL_Window* window);

#endif
