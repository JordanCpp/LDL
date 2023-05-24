#include "TextureImpl.hpp"

using namespace LDL::Graphics;

TextureImpl::TextureImpl(RenderContextImpl* renderContextImpl, const Point2u& size, uint8_t* pixels, uint8_t bytesPerPixel) :
	_Surface(size, pixels, bytesPerPixel)
{
}

TextureImpl::TextureImpl(RenderContextImpl* renderContextImpl, const Point2u& size, size_t bytesPerPixel) :
	_Surface(size, size, bytesPerPixel)
{
}

TextureImpl::~TextureImpl()
{
}

void TextureImpl::Copy(const Point2u& dstPos, const Point2u& srcSize, uint8_t* pixels, size_t bytesPerPixel)
{

}

void TextureImpl::Copy(const Point2u& dstPos, Surface* surface, const Point2u& srcSize)
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