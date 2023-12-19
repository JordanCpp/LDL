#include "TextureImplGlide.hpp"

using namespace LDL::Graphics;
using namespace LDL::Math;

TextureImplGlide::TextureImplGlide(RenderContextImpl* renderContextImpl, const Vec2u& size, uint8_t* pixels, uint8_t bytesPerPixel) :
	_RenderContextImpl(renderContextImpl)
{
}

TextureImplGlide::TextureImplGlide(RenderContextImpl* renderContextImpl, const Vec2u& size, uint8_t bytesPerPixel) :
	_RenderContextImpl(renderContextImpl)
{
}

TextureImplGlide::~TextureImplGlide()
{
}

void TextureImplGlide::Copy(const Vec2u& dstPos, const Vec2u& srcSize, uint8_t* pixels, uint8_t bytesPerPixel)
{
}

void TextureImplGlide::Copy(const Vec2u& dstPos, Surface* surface, const Vec2u& srcSize)
{
	Copy(dstPos, srcSize, surface->Pixels(), surface->BytesPerPixel());
}

const Vec2u& TextureImplGlide::Size()
{
	return _Size;
}

const Vec2u& TextureImplGlide::Quad()
{
	return _Quad;
}
