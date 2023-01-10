#include "SurfaceImpl.hpp"

using namespace LDL::Graphics;

SurfaceImpl::SurfaceImpl(const Point2u& size, uint8_t bytesPerPixel) :
	_Capacity(size),
	_Size(size),
	_BytesPerPixel(bytesPerPixel),
	_Pixels(NULL)
{
	size_t bytes = Bytes();
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
	return Size().PosX() > 0 && Capacity().PosY() > 0;
}