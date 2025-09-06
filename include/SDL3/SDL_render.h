// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef SDL3_SDL_render_h
#define SDL3_SDL_render_h

#include <LDL/Config.hpp>
#include <SDL3/SDL_video.h>

typedef struct SDL_Renderer SDL_Renderer;

LDL_LIBRARY SDL_Renderer* SDL_CreateRenderer(SDL_Window* window, const char* name);
LDL_LIBRARY void SDL_DestroyRenderer(SDL_Renderer* renderer);
LDL_LIBRARY bool SDL_RenderPresent(SDL_Renderer* renderer);
LDL_LIBRARY bool SDL_RenderClear(SDL_Renderer* renderer);

LDL_LIBRARY bool SDL_SetRenderDrawColor(SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
LDL_LIBRARY bool SDL_GetRenderDrawColor(SDL_Renderer* renderer, Uint8* r, Uint8* g, Uint8* b, Uint8* a);

#endif
