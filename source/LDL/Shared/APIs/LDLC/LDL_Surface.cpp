// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDLC/LDL_Surface.h>
#include <LDL/Graphics/Surface.hpp>

using namespace LDL;

struct LDL_Surface
{
	Surface _surface;
	LDL_Surface(size_t w, size_t h, uint8_t bytesPerPixel);
	LDL_Surface(size_t w, size_t h, uint8_t* pixels, uint8_t bytesPerPixel);
	LDL_Surface(size_t w, size_t h, size_t capacityW, size_t capacityH, uint8_t bytesPerPixel);
	LDL_Surface(size_t w, size_t h, size_t capacityW, size_t capacityH, uint8_t* pixels, uint8_t bytesPerPixel);
};

LDL_Surface::LDL_Surface(size_t w, size_t h, uint8_t bytesPerPixel) :
	_surface(Vec2u(w, h), bytesPerPixel)
{
}

LDL_Surface::LDL_Surface(size_t w, size_t h, uint8_t* pixels, uint8_t bytesPerPixel) :
	_surface(Vec2u(w, h), pixels, bytesPerPixel)
{
}

LDL_Surface::LDL_Surface(size_t w, size_t h, size_t capacityW, size_t capacityH, uint8_t bytesPerPixel) :
	_surface(Vec2u(w, h), Vec2u(capacityW, capacityH), bytesPerPixel)
{
}

LDL_Surface::LDL_Surface(size_t w, size_t h, size_t capacityW, size_t capacityH, uint8_t* pixels, uint8_t bytesPerPixel) :
	_surface(Vec2u(w, h), Vec2u(capacityW, capacityH), pixels, bytesPerPixel)
{
}

void LDL_SurfaceFree(LDL_Surface* surface)
{
	delete surface;
}

LDL_Surface* LDL_SurfaceNew(size_t w, size_t h, uint8_t bytesPerPixel)
{
	LDL_Surface* p = new LDL_Surface(w, h, bytesPerPixel);

	return p;
}

LDL_Surface* LDL_SurfaceNewFromBytes(size_t w, size_t h, uint8_t* pixels, uint8_t bytesPerPixel)
{
	LDL_Surface* p = new LDL_Surface(w, h, pixels, bytesPerPixel);

	return p;
}

LDL_Surface* LDL_SurfaceNewCapacity(size_t w, size_t h, size_t capacityW, size_t capacityH, uint8_t bytesPerPixel)
{
	LDL_Surface* p = new LDL_Surface(w, h, capacityW, capacityH, bytesPerPixel);

	return p;
}

LDL_Surface* LDL_SurfaceNewCapacityFromBytes(size_t w, size_t h, size_t capacityW, size_t capacityH, uint8_t* pixels, uint8_t bytesPerPixel)
{
	LDL_Surface* p = new LDL_Surface(w, h, capacityW, capacityH, pixels, bytesPerPixel);

	return p;
}

size_t  LDL_SurfaceGetSizeX(LDL_Surface* surface)
{
	return surface->_surface.Size().x;
}

size_t  LDL_SurfaceGetSizeY(LDL_Surface* surface)
{
	return surface->_surface.Size().y;
}

size_t  LDL_SurfaceGetCapacitySizeX(LDL_Surface* surface)
{
	return surface->_surface.Capacity().x;
}

size_t  LDL_SurfaceGetCapacitySizeY(LDL_Surface* surface)
{
	return surface->_surface.Capacity().y;
}

void LDL_SurfaceResize(LDL_Surface* surface, size_t w, size_t h)
{
	surface->_surface.Resize(Vec2u(w, h));
}

void LDL_SurfaceClear(LDL_Surface* surface)
{
	surface->_surface.Clear();
}

uint8_t LDL_SurfaceBytesPerPixel(LDL_Surface* surface)
{
	return surface->_surface.BytesPerPixel();
}

uint8_t* LDL_SurfacePixels(LDL_Surface* surface)
{
	return surface->_surface.Pixels();
}
