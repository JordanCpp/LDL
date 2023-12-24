#include "TextureImplDirect3D6.hpp"

using namespace LDL::Graphics;
using namespace LDL::Math;

TextureImplDirect3D6::TextureImplDirect3D6(RenderContextImpl* renderContextImpl, const Vec2u& size, uint8_t* pixels, uint8_t bytesPerPixel) :
	_RenderContextImpl(renderContextImpl)
{
}

TextureImplDirect3D6::TextureImplDirect3D6(RenderContextImpl* renderContextImpl, const Vec2u& size, uint8_t bytesPerPixel) :
	_RenderContextImpl(renderContextImpl)
{
}

TextureImplDirect3D6::~TextureImplDirect3D6()
{
}

void TextureImplDirect3D6::Copy(const Vec2u& dstPos, const Vec2u& srcSize, uint8_t* pixels, uint8_t bytesPerPixel)
{
}

void TextureImplDirect3D6::Copy(const Vec2u& dstPos, Surface* surface, const Vec2u& srcSize)
{
	Copy(dstPos, srcSize, surface->Pixels(), surface->BytesPerPixel());
}

const Vec2u& TextureImplDirect3D6::Size()
{
	return _Size;
}

const Vec2u& TextureImplDirect3D6::Quad()
{
	return _Quad;
}
