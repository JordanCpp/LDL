#include "TextureImpl.hpp"

using namespace LDL::Graphics;
using namespace LDL::Math;

TextureImpl::TextureImpl(RenderContextImpl* renderContextImpl, const Vec2u& size, uint8_t* pixels, uint8_t bytesPerPixel) :
	_Surface(size, pixels, bytesPerPixel)
{
}

TextureImpl::TextureImpl(RenderContextImpl* renderContextImpl, const Vec2u& size, size_t bytesPerPixel) :
	_Surface(size, size, bytesPerPixel)
{
}

TextureImpl::~TextureImpl()
{
}

void TextureImpl::Copy(const Vec2u& dstPos, const Vec2u& srcSize, uint8_t* pixels, size_t bytesPerPixel)
{

}

void TextureImpl::Copy(const Vec2u& dstPos, Surface* surface, const Vec2u& srcSize)
{

}

const Vec2u& TextureImpl::Size()
{
	return _Surface.Size();
}

Surface* LDL::Graphics::TextureImpl::GetSurface()
{
	return &_Surface;
}