#include "TextureImpl.hpp"

using namespace LDL::Graphics;
using namespace LDL::Math;

TextureImpl::TextureImpl(RenderContextImpl* renderContextImpl, const LDL::Math::Vec2u& size, uint8_t* pixels, size_t bytesPerPixel)
{
}

TextureImpl::TextureImpl(RenderContextImpl* renderContextImpl, const Math::Vec2u& size, size_t bytesPerPixel)
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
	Copy(dstPos, srcSize, surface->Pixels(), surface->BytesPerPixel());
}

const Vec2u& TextureImpl::Size()
{
	return _Size;
}