// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Shared/APIs/SDL3/SDL_Surface.hpp>

using namespace LDL;

SDL_PixelFormat LDL_PixelFormatToSDL_PixelFormat(size_t pixelFormat)
{
	SDL_PixelFormat format = SDL_PIXELFORMAT_UNKNOWN;

	switch (pixelFormat)
	{
	case PixelFormat::RGB24:
		format = SDL_PIXELFORMAT_RGB24;
		break;
	case PixelFormat::BGR24:
		format = SDL_PIXELFORMAT_BGR24;
		break;
	case PixelFormat::RGBA32:
		format = SDL_PIXELFORMAT_RGBA32;
		break;
	case PixelFormat::BGRA32:
		format = SDL_PIXELFORMAT_BGRA32;
		break;
	}

	return format;
}

SDL_SurfaceDetail::SDL_SurfaceDetail(int width, int height, SDL_PixelFormat format) :
	_surface(format, Vec2u(width, height))
{
}

Surface& SDL_SurfaceDetail::GetSurface()
{
	return _surface;
}

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

SDL_Surface* SDL_CreateSurfaceFrom(int width, int height, SDL_PixelFormat format, void* pixels, int pitch)
{
	return NULL;
}

void SDL_DestroySurface(SDL_Surface* surface)
{
	delete surface;
}
