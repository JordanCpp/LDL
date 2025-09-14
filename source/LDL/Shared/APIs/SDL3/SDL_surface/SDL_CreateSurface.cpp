// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/std/stdlib.hpp>
#include <LDL/Shared/APIs/SDL3/SDL_surface/SDL_Surface.hpp>

using namespace LDL;

SDL_Surface* SDL_CreateSurface(int width, int height, SDL_PixelFormat format)
{
    void* memory = LDL_malloc(sizeof(SDL_SurfaceDetail));

    SDL_SurfaceDetail* surface = new(memory) SDL_SurfaceDetail(width, height, format);

    surface->flags    = 0;
    surface->format   = LDL_PixelFormatToSDL_PixelFormat(surface->GetSurface().Format());
    surface->w        = (int)surface->GetSurface().Size().x;
    surface->h        = (int)surface->GetSurface().Size().y;
    surface->pitch    = (int)surface->GetSurface().Pitch();
    surface->pixels   = surface->GetSurface().Pixels();
    surface->refcount = 0;
    surface->reserved = 0;

    return surface;
}
