#include "SurfaceImpl.hpp"

using namespace LDL::Graphics;

SurfaceImpl::SurfaceImpl(const Point2u& size, uint8_t bytesPerPixel) :
	_Capacity(size),
	_Size(size),
	_BytesPerPixel(bytesPerPixel),
	_Pixels(NULL)
{
	_Pixels = new uint8_t[Bytes()];
}

LDL::Graphics::SurfaceImpl::SurfaceImpl(const Point2u& size, uint8_t bytesPerPixel, const Point2u& capacity) :
	_Capacity(capacity),
	_Size(size),
	_BytesPerPixel(bytesPerPixel),
	_Pixels(NULL)
{
	_Pixels = new uint8_t[Bytes()];
}

LDL::Graphics::SurfaceImpl::~SurfaceImpl()
{
	delete _Pixels;
}

uint8_t* LDL::Graphics::SurfaceImpl::Pixels()
{
	return _Pixels;
}

const Point2u& SurfaceImpl::Capacity()
{
	return _Capacity;
}

const Point2u& SurfaceImpl::Size()
{
	return _Size;
}

size_t SurfaceImpl::Bytes()
{
	return Capacity().PosX() * Capacity().PosY() * BytesPerPixel();
}

uint8_t SurfaceImpl::BytesPerPixel()
{
	return _BytesPerPixel;
}

bool SurfaceImpl::Empty()
{
	return Size().PosX() == 0 && Size().PosY() == 0;
}

void LDL::Graphics::SurfaceImpl::Clear()
{
	_Size = Point2u(0, 0);
}

void LDL::Graphics::SurfaceImpl::Clear(const Color& color)
{
	Color* pixels = (Color*)_Pixels;

	for (size_t i = 0; i < Size().PosX() * Size().PosY(); i++)
	{
		pixels[i] = color;
	}
}