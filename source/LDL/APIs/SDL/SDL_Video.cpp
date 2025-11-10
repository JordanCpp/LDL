// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/STL/new.hpp>
#include <LDL/std/stdlib.hpp>
#include <LDL/APIs/SDL/SDL_Application.hpp>
#include <LDL/APIs/SDL/SDL_Surface.hpp>
#include <LDL/Loaders/BmpLoader.hpp>

using namespace LDL;

SDL_Surface* SDL_CreateRGBSurface(Uint32 flags, int width, int height, int depth, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask)
{
	void* memory = LDL_malloc(sizeof(SDL_SurfaceDetail));

	SDL_SurfaceDetail* surface = new(memory) SDL_SurfaceDetail(PixelFormat::RGB24, Vec2u(width, height));

	surface->flags  = 0;
	surface->format = surface->GetPixelFormat();
	surface->w      = (int)surface->GetSurface().Size().x;
	surface->h      = (int)surface->GetSurface().Size().y;
	surface->pitch  = (Uint16)surface->GetSurface().Pitch();
	surface->pixels = surface->GetSurface().Pixels();

	surface->format->BytesPerPixel = surface->GetSurface().BytesPerPixel();

	return surface;
}

void SDL_FreeSurface(SDL_Surface* surface)
{
	surface->~SDL_Surface();
	LDL_free(surface);
}

SDL_Surface* SDL_SetVideoMode(int width, int height, int bpp, Uint32 flags)
{
	void* memoryWindow = LDL_malloc(sizeof(Window));
	App()._window = new(memoryWindow) Window(App()._result, App()._context, Vec2u(0, 0), Vec2u(width, height), "", flags);

	void* memoryRender = LDL_malloc(sizeof(Window));
	App()._render = new(memoryRender) Render(App()._result, App()._context, App()._window);

	SDL_Surface* surface = SDL_CreateRGBSurface(0, width, height, 0, 0, 0, 0, 0);

	return surface;
}

int SDL_Flip(SDL_Surface* screen)
{
	App()._render->Begin();

	SDL_SurfaceDetail* surface = (SDL_SurfaceDetail*)screen;

	App()._render->Draw(&surface->GetSurface(), Vec2u(0, 0));

	App()._render->End();

	return 0;
}

SDL_Surface* SDL_LoadBMP(const char* path)
{
	BmpLoader loader(App()._result);

	loader.Load(path);

	return NULL;
}
