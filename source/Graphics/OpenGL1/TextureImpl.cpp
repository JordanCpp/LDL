#include "TextureImpl.hpp"
#include <LDL/OpenGL/OpenGL1_0.hpp>

using namespace LDL::Graphics;

TextureImpl::TextureImpl(const Point2u& size, size_t bytesPerPixel, uint8_t* pixels)
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
