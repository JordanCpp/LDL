#include "TextureImpl.hpp"
#include <LDL/OpenGL/OpenGL1_0.hpp>
#include <assert.h>
#include "Util.hpp"
#include <iostream>

using namespace LDL::Graphics;

TextureImpl::TextureImpl(RenderContextImpl* renderContextImpl, const Vec2u& size, uint8_t* pixels, size_t bytesPerPixel)
{
}

TextureImpl::~TextureImpl()
{
}

const Vec2u& TextureImpl::Size()
{
	return _Size;
}