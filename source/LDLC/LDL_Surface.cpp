#include <LDLC/LDL_Surface.h>
#include <LDL/Graphics/Surface.hpp>

using namespace LDL::Graphics;

struct LDL_Surface
{
	Surface _Surface;
	LDL_Surface(size_t w, size_t h, uint8_t bytesPerPixel);
	LDL_Surface(size_t w, size_t h, uint8_t* pixels, uint8_t bytesPerPixel);
	LDL_Surface(size_t w, size_t h, size_t capacityW, size_t capacityH, uint8_t bytesPerPixel);
	LDL_Surface(size_t w, size_t h, size_t capacityW, size_t capacityH, uint8_t* pixels, uint8_t bytesPerPixel);
};

LDL_Surface::LDL_Surface(size_t w, size_t h, uint8_t bytesPerPixel) :
	_Surface(Point2u(w, h), bytesPerPixel)
{
}

LDL_Surface::LDL_Surface(size_t w, size_t h, uint8_t* pixels, uint8_t bytesPerPixel) :
	_Surface(Point2u(w, h), pixels, bytesPerPixel)
{
}

LDL_Surface::LDL_Surface(size_t w, size_t h, size_t capacityW, size_t capacityH, uint8_t bytesPerPixel) :
	_Surface(Point2u(w, h), Point2u(capacityW, capacityH), bytesPerPixel)
{
}

LDL_Surface::LDL_Surface(size_t w, size_t h, size_t capacityW, size_t capacityH, uint8_t* pixels, uint8_t bytesPerPixel) :
	_Surface(Point2u(w, h), Point2u(capacityW, capacityH), pixels, bytesPerPixel)
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
	return surface->_Surface.Size().PosX();
}

size_t  LDL_SurfaceGetSizeY(LDL_Surface* surface)
{
	return surface->_Surface.Size().PosY();
}

size_t  LDL_SurfaceGetCapacitySizeX(LDL_Surface* surface)
{
	return surface->_Surface.Capacity().PosX();
}

size_t  LDL_SurfaceGetCapacitySizeY(LDL_Surface* surface)
{
	return surface->_Surface.Capacity().PosY();
}

void LDL_SurfaceResize(LDL_Surface* surface, size_t w, size_t h)
{
	surface->_Surface.Resize(Point2u(w, h));
}

void LDL_SurfaceClear(LDL_Surface* surface)
{
	surface->_Surface.Clear();
}

uint8_t LDL_SurfaceBytesPerPixel(LDL_Surface* surface)
{
	return surface->_Surface.BytesPerPixel();
}

uint8_t* LDL_SurfacePixels(LDL_Surface* surface)
{
	return surface->_Surface.Pixels();
}