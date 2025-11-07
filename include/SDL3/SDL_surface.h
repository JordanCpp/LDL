// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef SDL3_SDL_surface_h
#define SDL3_SDL_surface_h

#include <SDL3/SDL_config.h>
#include <SDL3/SDL_pixels.h>

#ifdef __cplusplus
extern "C" {
#endif 

typedef Uint32 SDL_SurfaceFlags;

#define SDL_SURFACE_PREALLOCATED    (0x00000001u)
#define SDL_SURFACE_LOCK_NEEDED     (0x00000002u)
#define SDL_SURFACE_LOCKED          (0x00000004u)
#define SDL_SURFACE_SIMD_ALIGNED    (0x00000008u)

struct SDL_Surface
{
    SDL_SurfaceFlags flags;
    SDL_PixelFormat  format;
    int              w;                     
    int              h;
    int              pitch;
    void*            pixels;
    int              refcount;
    void*            reserved;
};

typedef struct SDL_Surface SDL_Surface;

extern SDL_DECLSPEC SDL_Surface* SDLCALL SDL_CreateSurface(int width, int height, SDL_PixelFormat format);
extern SDL_DECLSPEC SDL_Surface* SDLCALL SDL_CreateSurfaceFrom(int width, int height, SDL_PixelFormat format, void* pixels, int pitch);
extern SDL_DECLSPEC void SDLCALL SDL_DestroySurface(SDL_Surface* surface);

#ifdef __cplusplus
}
#endif

#endif
