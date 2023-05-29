#include "TextureImpl.hpp"
#include <assert.h>
#include <LDL/Core/RuntimeError.hpp>
#include "RenderContextImpl.hpp"

using namespace LDL::Graphics;

TextureImpl::TextureImpl(RenderContextImpl* renderContextImpl, const Vec2u& size, uint8_t* pixels, size_t bytesPerPixel)
{
	assert(size.x > 0);
	assert(size.y > 0);
	assert(pixels != NULL);
	assert(bytesPerPixel >= 1 && bytesPerPixel <= 4);

	_Size = size;
}

TextureImpl::~TextureImpl()
{
}

const Vec2u& TextureImpl::Size()
{
	return _Size;
}