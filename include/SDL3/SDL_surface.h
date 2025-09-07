// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef SDL3_SDL_surface_h
#define SDL3_SDL_surface_h

#include <LDL/Config.hpp>
#include <SDL3/SDL_pixels.h>

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

LDL_LIBRARY SDL_Surface* SDL_CreateSurface(int width, int height, SDL_PixelFormat format);
LDL_LIBRARY SDL_Surface* SDL_CreateSurfaceFrom(int width, int height, SDL_PixelFormat format, void* pixels, int pitch);
LDL_LIBRARY void SDL_DestroySurface(SDL_Surface* surface);

#endif
