// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/StdFuncs.hpp>
#include <LDL/SDL/SDLSurf.hpp>

SDL_SurfaceDetail::SDL_SurfaceDetail(size_t pixelFormat, const LDL_Vec2u& size) :
	_surface(pixelFormat, size)
{
	SDL_memset(&_format, 0, sizeof(SDL_PixelFormat));
}

SDL_SurfaceDetail::SDL_SurfaceDetail(size_t pixelFormat, const LDL_Vec2u& size, uint8_t* pixels) :
	_surface(pixelFormat, size, pixels)
{
	SDL_memset(&_format, 0, sizeof(SDL_PixelFormat));
}

LDL_Surface& SDL_SurfaceDetail::GetSurface()
{
	return _surface;
}

SDL_PixelFormat* SDL_SurfaceDetail::GetPixelFormat()
{
	return &_format;
}
