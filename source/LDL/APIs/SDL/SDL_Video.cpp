// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/New.hpp>
#include <LDL/Core/StdFuncs.hpp>
#include <LDL/Loaders/BmpLoader.hpp>
#include <LDL/APIs/SDL/SDL_Surface.hpp>
#include <LDL/APIs/SDL/SDL_Application.hpp>
#include <LDL/Graphics/PixelCopier.hpp>
#include <LDL/Graphics/WindowImplCreator.hpp>
#include <LDL/Graphics//RenderCreator.hpp>

using namespace LDL;

SDL_Surface* SDL_CreateRGBSurfaceFromPixels(size_t pixelFormat, void* pixels, int width, int height, int depth, int pitch, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask)
{
	LDL_UNUSED(depth);
	LDL_UNUSED(pitch);
	LDL_UNUSED(Rmask);
	LDL_UNUSED(Gmask);
	LDL_UNUSED(Bmask);
	LDL_UNUSED(Amask);

	void* memory = SDL_malloc(sizeof(SDL_SurfaceDetail));

	SDL_SurfaceDetail* surface = new(memory) SDL_SurfaceDetail(pixelFormat, Vec2u(width, height), (uint8_t*)pixels);

	surface->flags  = 0;
	surface->format = surface->GetPixelFormat();
	surface->w      = (int)width;
	surface->h      = (int)height;
	surface->pitch  = (Uint16)surface->GetSurface().Pitch();
	surface->pixels = pixels;

	surface->format->BytesPerPixel = surface->GetSurface().BytesPerPixel();

	return surface;
}

SDL_Surface* SDL_CreateRGBSurfaceFrom(void* pixels, int width, int height, int depth, int pitch, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask)
{
	LDL_UNUSED(depth);
	LDL_UNUSED(pitch);
	LDL_UNUSED(Rmask);
	LDL_UNUSED(Gmask);
	LDL_UNUSED(Bmask);
	LDL_UNUSED(Amask);

	return SDL_CreateRGBSurfaceFromPixels(PixelFormat::RGB24, (uint8_t*)pixels, width, height, 0, 0, 0, 0, 0, 0);
}

SDL_Surface* SDL_CreateRGBSurface(Uint32 flags, int width, int height, int depth, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask)
{
	LDL_UNUSED(flags);
	LDL_UNUSED(depth);
	LDL_UNUSED(Rmask);
	LDL_UNUSED(Gmask);
	LDL_UNUSED(Bmask);
	LDL_UNUSED(Amask);

	void* memory = SDL_malloc(sizeof(SDL_SurfaceDetail));

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

int SDL_BlitSurface(SDL_Surface* src, SDL_Rect* srcRect, SDL_Surface* dst, SDL_Rect* dstRect)
{
	Vec2u srcPos;
	Vec2u srcSize;

	Vec2u dstPos;
	Vec2u dstSize;

	if (srcRect == NULL)
	{
		srcPos  = Vec2u(0, 0);
		srcSize = Vec2u(src->w, src->h);
	}
	else
	{
		srcPos  = Vec2u(srcRect->x, srcRect->y);
		srcSize = Vec2u(srcRect->w, srcRect->h);
	}

	if (dstRect == NULL)
	{
		dstPos  = Vec2u(0, 0);
		dstSize = Vec2u(dst->w, dst->h);
	}
	else
	{
		dstPos  = Vec2u(dstRect->x, dstRect->y);
		dstSize = Vec2u(dstRect->w, dstRect->h);
	}

	SDL_SurfaceDetail* srcSurf = (SDL_SurfaceDetail*)src;
	SDL_SurfaceDetail* dstSurf = (SDL_SurfaceDetail*)dst;

	PixelCopier copier;

	copier.Copy(dstSurf->GetSurface().Pixels(), dstSurf->GetSurface().Format(), dstSurf->GetSurface().Size(), dstPos, dstSize,
		        srcSurf->GetSurface().Pixels(), srcSurf->GetSurface().Format(), srcSurf->GetSurface().Size(), srcPos, srcSize);

	//copier.Copy(srcSurf->GetSurface().Format(), srcSurf->GetSurface().Pixels(), srcSize, &srcSurf->GetSurface(),
	//	        dstSurf->GetSurface().Format(), dstSurf->GetSurface().Pixels(), dstSize, dstPos, &dstSurf->GetSurface());

	return 0;
}

SDL_Surface* SDL_SetVideoMode(int width, int height, int bpp, Uint32 flags)
{
	LDL_UNUSED(bpp);

	IWindow* window = CreateWindowImpl(App().GetResult(), App().GetContext(), Vec2u(0, 0), Vec2u(width, height), "", flags);
	App().SetWindow(window);

	IRender* render = CreateRenderImpl(App().GetResult(), App().GetContext(), App().GetWindow());
	App().SetRender(render);

	SDL_Surface* surface = SDL_CreateRGBSurface(0, width, height, 0, 0, 0, 0, 0);

	return surface;
}

int SDL_Flip(SDL_Surface* screen)
{
	App().GetRender()->Begin();

	SDL_SurfaceDetail* surface = (SDL_SurfaceDetail*)screen;

	App().GetRender()->Draw(&surface->GetSurface(), Vec2u(0, 0));

	App().GetRender()->End();

	return 0;
}

SDL_Surface* SDL_LoadBMP(const char* path)
{
	BmpLoader loader(App().GetResult());

	SDL_Surface* result = NULL;

	if (loader.Load(path))
	{
		result = SDL_CreateRGBSurfaceFromPixels(loader.Format(), loader.Pixels(), loader.Size().x, loader.Size().y, 0, 0, 0, 0, 0, 0);
	}

	return result;
}

void SDL_WM_SetCaption(const char* title, const char* icon)
{
	LDL_UNUSED(icon);

	App().GetWindow()->Title(title);
}
