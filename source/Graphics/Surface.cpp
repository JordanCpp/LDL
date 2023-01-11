#include <LDL/Graphics/Surface.hpp>
#include "../Graphics/Software/SurfaceImpl.hpp"

using namespace LDL::Graphics;

Surface::Surface(const Point2u& size, uint8_t bytesPerPixel) :
	_SurfaceImpl(new SurfaceImpl(size, bytesPerPixel))
{
}

LDL::Graphics::Surface::Surface(const Point2u& size, const Point2u& capacity, uint8_t bytesPerPixel) :
	_SurfaceImpl(new SurfaceImpl(size, bytesPerPixel, capacity))
{
}

LDL::Graphics::Surface::~Surface()
{
	delete _SurfaceImpl;
}

uint8_t* LDL::Graphics::Surface::Pixels()
{
	return _SurfaceImpl->Pixels();
}

const Point2u& Surface::Capacity()
{
	return _SurfaceImpl->Capacity();
}

const Point2u& Surface::Size()
{
	return _SurfaceImpl->Size();
}

size_t Surface::Bytes()
{
	return _SurfaceImpl->Bytes();
}

uint8_t Surface::BytesPerPixel()
{
	return _SurfaceImpl->BytesPerPixel();
}

bool Surface::Empty()
{
	return _SurfaceImpl->Empty();
}

void LDL::Graphics::Surface::Clear()
{
	_SurfaceImpl->Clear();
}

void LDL::Graphics::Surface::Clear(const Color& color)
{
	_SurfaceImpl->Clear(color);
}