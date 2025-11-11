// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/APIs/SDL3/SDL_Surface.hpp>
#include <LDL/Loaders/BmpLoader.hpp>
#include <LDL/APIs/SDL3/SDL_Application.hpp>

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

SDL_SurfaceDetail::SDL_SurfaceDetail(int width, int height, SDL_PixelFormat pixelFormat) :
	_surface(pixelFormat, Vec2u(width, height))
{
}

SDL_SurfaceDetail::SDL_SurfaceDetail(int width, int height, SDL_PixelFormat pixelFormat, uint8_t* pixels) :
	_surface(pixelFormat, Vec2u(width, height), pixels)
{
}

Surface& SDL_SurfaceDetail::GetSurface()
{
	return _surface;
}

SDL_Surface* SDL_CreateSurface(int width, int height, SDL_PixelFormat pixelFormat)
{
	void* memory = SDL_malloc(sizeof(SDL_SurfaceDetail));

	SDL_SurfaceDetail* surface = new(memory) SDL_SurfaceDetail(width, height, pixelFormat);

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

SDL_Surface* SDL_CreateSurfaceFrom(int width, int height, SDL_PixelFormat pixelFormat, void* pixels, int pitch)
{
	void* memory = SDL_malloc(sizeof(SDL_SurfaceDetail));

	SDL_SurfaceDetail* surface = new(memory) SDL_SurfaceDetail(width, height, pixelFormat, (uint8_t*)pixels);

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

void SDL_DestroySurface(SDL_Surface* surface)
{
	surface->~SDL_Surface();
	SDL_free(surface);
}

SDL_Surface* SDL_LoadBMP(const char* file)
{
	BmpLoader loader(App().GetResult());
	SDL_Surface* result = NULL;

	if (loader.Load(file))
	{
		result = SDL_CreateSurfaceFrom(loader.Size().x, loader.Size().y, LDL_PixelFormatToSDL_PixelFormat(loader.Format()), loader.Pixels(), 0);
	}
	
	return result;
}
