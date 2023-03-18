#include "TextureImpl.hpp"
#include <assert.h>

using namespace LDL::Graphics;

TextureImpl::TextureImpl(RenderImpl* renderImpl, const Point2u& size, uint8_t* pixels, size_t bytesPerPixel):
	_Id(0)
{
	assert(size.PosX() > 0);
	assert(size.PosY() > 0);
	assert(pixels != NULL);
	assert(bytesPerPixel >= 1 && bytesPerPixel <= 4);
}

TextureImpl::~TextureImpl()
{
}

const Point2u& TextureImpl::Size()
{
	return _Size;
}

const size_t TextureImpl::Id()
{
	return _Id;
}