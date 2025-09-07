// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Shared/APIs/SDL3/SDL_surface/SDL_Surface.hpp>

SDL_PixelFormat LDL_PixelFormatToSDL_PixelFormat(size_t pixelFormat)
{
	SDL_PixelFormat format = SDL_PIXELFORMAT_UNKNOWN;

	switch (pixelFormat)
	{
	case LDL::PixelFormat::RGB24:
		format = SDL_PIXELFORMAT_RGB24;
		break;
	case LDL::PixelFormat::BGR24:
		format = SDL_PIXELFORMAT_BGR24;
		break;
	case LDL::PixelFormat::RGBA32:
		format = SDL_PIXELFORMAT_RGBA32;
		break;
	case LDL::PixelFormat::BGRA32:
		format = SDL_PIXELFORMAT_BGRA32;
		break;
	}

	return format;
}

SDL_SurfaceDetail::SDL_SurfaceDetail(int width, int height, SDL_PixelFormat format) :
	_surface(format, LDL::Vec2u(width, height))
{
}

LDL::Surface& SDL_SurfaceDetail::GetSurface()
{
	return _surface;
}
