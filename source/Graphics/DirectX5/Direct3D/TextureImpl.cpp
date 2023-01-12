#include "TextureImpl.hpp"
#include <assert.h>

using namespace LDL::Graphics;

TextureImpl::TextureImpl(const Point2u& size, size_t bytesPerPixel, uint8_t* pixels):
	_Id(0)
{
	assert(size.PosX() > 0);
	assert(size.PosY() > 0);
	assert(bytesPerPixel >= 1 && bytesPerPixel <= 4);
	assert(pixels != NULL);
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