#include "TextureImpl.hpp"
#include <assert.h>
#include <LDL/Core/RuntimeError.hpp>
#include "RenderContextImpl.hpp"

using namespace LDL::Graphics;

TextureImpl::TextureImpl(RenderContextImpl* renderContextImpl, const Point2u& size, uint8_t* pixels, size_t bytesPerPixel)
{
	assert(size.PosX() > 0);
	assert(size.PosY() > 0);
	assert(pixels != NULL);
	assert(bytesPerPixel >= 1 && bytesPerPixel <= 4);

	_Size = size;
}

TextureImpl::~TextureImpl()
{
}

const Point2u& TextureImpl::Size()
{
	return _Size;
}