#include "TextureImpl.hpp"
#include <assert.h>

using namespace LDL::Graphics;

TextureImpl::TextureImpl(RenderImpl* renderImpl, const Vec2u& size, uint8_t* pixels, size_t bytesPerPixel):
	_Id(0)
{
	assert(size.x > 0);
	assert(size.y > 0);
	assert(pixels != NULL);
	assert(bytesPerPixel >= 1 && bytesPerPixel <= 4);
}

TextureImpl::~TextureImpl()
{
}

const Vec2u& TextureImpl::Size()
{
	return _Size;
}

const size_t TextureImpl::Id()
{
	return _Id;
}