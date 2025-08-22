// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include "TextureImplOpenGL1.hpp"
#include <LDL/APIs/OpenGL/OpenGL1_0.hpp>
#include <assert.h>
#include "../OpenGL/Util.hpp"
#include <iostream>

using namespace LDL::Graphics;
using namespace LDL::Math;

TextureImplOpenGL1::TextureImplOpenGL1(RenderContextImpl* renderContextImpl, const Vec2u& size, uint8_t* pixels, uint8_t bytesPerPixel) :
	_renderContextImpl(renderContextImpl),
	_id(0)
{
	assert(size.x > 0);
	assert(size.y > 0);
	assert(bytesPerPixel >= 1 && bytesPerPixel <= 4);
	assert(pixels != NULL);

	_size = size;

	GLint format = 0;

	if (bytesPerPixel == 3)
		format = GL_RGB;
	else
		format = GL_RGBA;

	size_t sz = Util::SelectTextureSize(_size);

	_quad = Vec2u(sz, sz);

	_id = Util::CreateTexture((GLsizei)_quad.x, (GLsizei)_quad.y, format);

	Copy(Vec2u(0, 0), _size, pixels, bytesPerPixel);
}

TextureImplOpenGL1::TextureImplOpenGL1(RenderContextImpl* renderContextImpl, const Vec2u& size, uint8_t bytesPerPixel) :
	_renderContextImpl(renderContextImpl),
	_id(0)
{
	_size = size;

	GLint format = 0;

	if (bytesPerPixel == 3)
		format = GL_RGB;
	else
		format = GL_RGBA;

	size_t sz = Util::SelectTextureSize(_size);

	_quad = Vec2u(sz, sz);

	_id = Util::CreateTexture((GLsizei)_quad.x, (GLsizei)_quad.y, format);
}

TextureImplOpenGL1::~TextureImplOpenGL1()
{
	Util::DeleteTexture((GLint)_id);
}

void TextureImplOpenGL1::Copy(const Vec2u& dstPos, const Vec2u& srcSize, uint8_t* pixels, uint8_t bytesPerPixel)
{
	GLint format = 0;

	if (bytesPerPixel == 3)
		format = GL_RGB;
	else
		format = GL_RGBA;

	GL_CHECK(glTexSubImage2D(GL_TEXTURE_2D, 0, (GLint)dstPos.x, (GLint)dstPos.y, (GLsizei)srcSize.x, (GLsizei)srcSize.y, format, GL_UNSIGNED_BYTE, pixels));
}

void TextureImplOpenGL1::Copy(const Vec2u& dstPos, Surface* surface, const Vec2u& srcSize)
{
	Copy(dstPos, srcSize, surface->Pixels(), surface->BytesPerPixel());
}

const Vec2u& TextureImplOpenGL1::Size()
{
	return _size;
}

const Vec2u& TextureImplOpenGL1::Quad()
{
	return _quad;
}

size_t TextureImplOpenGL1::Id()
{
	return _id;
}
