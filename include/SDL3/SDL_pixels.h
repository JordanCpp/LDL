// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef SDL3_SDL_pixels_h
#define SDL3_SDL_pixels_h

#include <SDL3/SDL_stdinc.h>

typedef enum SDL_PixelFormat
{
    SDL_PIXELFORMAT_UNKNOWN = 0,
    SDL_PIXELFORMAT_RGBA32,
    SDL_PIXELFORMAT_BGRA32,
    SDL_PIXELFORMAT_RGB24,
    SDL_PIXELFORMAT_BGR24
} SDL_PixelFormat;

#endif
