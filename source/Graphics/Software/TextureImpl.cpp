#include "TextureImpl.hpp"

using namespace LDL::Graphics;

TextureImpl::TextureImpl(const Point2u& size, size_t bytesPerPixel, uint8_t* pixels):
	_Id(0)
{
}

TextureImpl::~TextureImpl()
{
}

const Point2u& TextureImpl::Size()
{
	return _Size;
}

size_t TextureImpl::Id()
{
	return _Id;
}