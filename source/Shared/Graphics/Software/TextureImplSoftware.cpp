#include "TextureImplSoftware.hpp"

using namespace LDL::Graphics;
using namespace LDL::Math;

TextureImplSoftware::TextureImplSoftware(RenderContextImpl* renderContextImpl, const Vec2u& size, uint8_t* pixels, uint8_t bytesPerPixel) :
	_Surface(size, pixels, bytesPerPixel)
{
}

TextureImplSoftware::TextureImplSoftware(RenderContextImpl* renderContextImpl, const Vec2u& size, uint8_t bytesPerPixel) :
	_Surface(size, size, bytesPerPixel)
{
}

TextureImplSoftware::~TextureImplSoftware()
{
}

void TextureImplSoftware::Copy(const Vec2u& dstPos, const Vec2u& srcSize, uint8_t* pixels, uint8_t bytesPerPixel)
{

}

void TextureImplSoftware::Copy(const Vec2u& dstPos, Surface* surface, const Vec2u& srcSize)
{

}

const Vec2u& TextureImplSoftware::Size()
{
	return _Surface.Size();
}

const Vec2u& TextureImplSoftware::Quad()
{
	return _Surface.Size();
}

Surface* TextureImplSoftware::GetSurface()
{
	return &_Surface;
}