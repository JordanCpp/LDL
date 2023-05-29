#include "TextureImpl.hpp"

using namespace LDL::Graphics;

TextureImpl::TextureImpl(RenderImpl* renderImpl, const Vec2u& size, uint8_t* pixels, size_t bytesPerPixel):
	_Id(0)
{
}

TextureImpl::~TextureImpl()
{
}

const Vec2u& TextureImpl::Size()
{
	return _Size;
}

size_t TextureImpl::Id()
{
	return _Id;
}