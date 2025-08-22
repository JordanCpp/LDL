// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef SDL3_SDL_render_h
#define SDL3_SDL_render_h

#include <SDL3/SDL_video.h>

typedef struct SDL_Renderer SDL_Renderer;

SDL_Renderer* SDL_CreateRenderer(SDL_Window* window, const char* name);
void SDL_DestroyRenderer(SDL_Renderer* renderer);
bool SDL_RenderPresent(SDL_Renderer* renderer);
bool SDL_RenderClear(SDL_Renderer* renderer);

bool SDL_SetRenderDrawColor(SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
bool SDL_GetRenderDrawColor(SDL_Renderer* renderer, Uint8* r, Uint8* g, Uint8* b, Uint8* a);

#endif
