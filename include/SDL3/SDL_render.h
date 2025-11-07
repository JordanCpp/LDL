// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef SDL3_SDL_render_h
#define SDL3_SDL_render_h

#include <SDL3/SDL_config.h>
#include <SDL3/SDL_video.h>
#include <SDL3/SDL_surface.h>
#include <SDL3/SDL_rect.h>
#include <LDL/std/stdbool.hpp>

#ifdef __cplusplus
extern "C" {
#endif 

/******************************************************************************************************************
                                                   Render - functions
******************************************************************************************************************/

typedef struct SDL_Renderer SDL_Renderer;

extern SDL_DECLSPEC SDL_Renderer* SDLCALL SDL_CreateRenderer(SDL_Window* window, const char* name);
extern SDL_DECLSPEC void SDLCALL SDL_DestroyRenderer(SDL_Renderer* renderer);
extern SDL_DECLSPEC bool SDLCALL SDL_RenderPresent(SDL_Renderer* renderer);
extern SDL_DECLSPEC bool SDLCALL SDL_RenderClear(SDL_Renderer* renderer);
extern SDL_DECLSPEC bool SDLCALL SDL_SetRenderDrawColor(SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
extern SDL_DECLSPEC bool SDLCALL SDL_GetRenderDrawColor(SDL_Renderer* renderer, Uint8* r, Uint8* g, Uint8* b, Uint8* a);

/******************************************************************************************************************
                                                   Texture - functions
******************************************************************************************************************/
typedef enum SDL_TextureAccess
{
    SDL_TEXTUREACCESS_STATIC,
    SDL_TEXTUREACCESS_STREAMING,
    SDL_TEXTUREACCESS_TARGET
} SDL_TextureAccess;

typedef struct SDL_Texture SDL_Texture;

extern SDL_DECLSPEC SDL_Texture* SDLCALL SDL_CreateTexture(SDL_Renderer* renderer, SDL_PixelFormat format, SDL_TextureAccess access, int w, int h);
extern SDL_DECLSPEC void SDLCALL SDL_DestroyTexture(SDL_Texture* texture);
extern SDL_DECLSPEC bool SDLCALL SDL_GetTextureSize(SDL_Texture* texture, float* w, float* h);
extern SDL_DECLSPEC SDL_Texture* SDLCALL SDL_CreateTextureFromSurface(SDL_Renderer* renderer, SDL_Surface* surface);
extern SDL_DECLSPEC bool SDLCALL SDL_RenderTexture(SDL_Renderer* renderer, SDL_Texture* texture, const SDL_FRect* srcrect, const SDL_FRect* dstrect);

#ifdef __cplusplus
}
#endif

#endif
