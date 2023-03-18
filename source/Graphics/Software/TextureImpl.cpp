#include "TextureImpl.hpp"

using namespace LDL::Graphics;

TextureImpl::TextureImpl(RenderImpl* renderImpl, const Point2u& size, uint8_t* pixels, uint8_t bytesPerPixel) :
	_Surface(size, pixels, bytesPerPixel)
{
}

TextureImpl::~TextureImpl()
{
}

const Point2u& TextureImpl::Size()
{
	return _Surface.Size();
}

Surface* LDL::Graphics::TextureImpl::GetSurface()
{
	return &_Surface;
}