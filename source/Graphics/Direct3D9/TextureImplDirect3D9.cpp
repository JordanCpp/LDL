#include "TextureImplDirect3D9.hpp"

using namespace LDL::Graphics;
using namespace LDL::Math;

TextureImplDirect3D9::TextureImplDirect3D9(RenderContextImpl* renderContextImpl, const Vec2u& size, uint8_t* pixels, size_t bytesPerPixel) :
	_RenderContextImpl(renderContextImpl),
	_Id(0)
{
}

TextureImplDirect3D9::TextureImplDirect3D9(RenderContextImpl* renderContextImpl, const Vec2u& size, size_t bytesPerPixel) :
	_RenderContextImpl(renderContextImpl),
	_Id(0)
{
}

TextureImplDirect3D9::~TextureImplDirect3D9()
{
}

void TextureImplDirect3D9::Copy(const Vec2u& dstPos, const Vec2u& srcSize, uint8_t* pixels, size_t bytesPerPixel)
{
}

void TextureImplDirect3D9::Copy(const Vec2u& dstPos, Surface* surface, const Vec2u& srcSize)
{
	Copy(dstPos, srcSize, surface->Pixels(), surface->BytesPerPixel());
}

const Vec2u& TextureImplDirect3D9::Size()
{
	return _Size;
}

const Vec2u& TextureImplDirect3D9::Quad()
{
	return _Quad;
}

size_t TextureImplDirect3D9::Id()
{
	return _Id;
}