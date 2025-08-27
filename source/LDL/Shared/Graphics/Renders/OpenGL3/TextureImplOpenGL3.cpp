// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include "TextureImplOpenGL3.hpp"
#include <LDL/APIs/OpenGL/OpenGL1_1.hpp>
#include <LDL/Core/Assert.hpp>
#include "../OpenGL/Util.hpp"

using namespace LDL;

TextureImplOpenGL3::TextureImplOpenGL3(RenderContextImpl* renderContextImpl, const Vec2u& size, uint8_t* pixels, uint8_t bytesPerPixel) :
	_RenderContextImpl(renderContextImpl),
	_Id(0)
{
	LDL_ASSERT(size.x > 0);
	LDL_ASSERT(size.y > 0);
	LDL_ASSERT(bytesPerPixel >= 1 && bytesPerPixel <= 4);
	LDL_ASSERT(pixels != NULL);

	_Size = size;

	GL_CHECK(glGenTextures(1, (GLuint*)&_Id));
	GL_CHECK(glBindTexture(GL_TEXTURE_2D, (GLuint)_Id));

	GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
	GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));

	GLint format = 0;

	if (bytesPerPixel == 3)
		format = GL_RGB;
	else
		format = GL_RGBA;

	GL_CHECK(glTexImage2D(GL_TEXTURE_2D, 0, format, (GLsizei)_Size.x, (GLsizei)_Size.y, 0, format, GL_UNSIGNED_BYTE, pixels));
}

TextureImplOpenGL3::TextureImplOpenGL3(RenderContextImpl* renderContextImpl, const Vec2u& size, uint8_t bytesPerPixel) :
	_RenderContextImpl(renderContextImpl),
	_Id(0)
{
	LDL_UNUSED(size);
	LDL_UNUSED(bytesPerPixel);
}

TextureImplOpenGL3::~TextureImplOpenGL3()
{
	GL_CHECK(glDeleteTextures(0, (GLuint*)&_Id));
}

const Vec2u& TextureImplOpenGL3::Size()
{
	return _Size;
}

const Vec2u& TextureImplOpenGL3::Quad()
{
	return _Quad;
}

size_t TextureImplOpenGL3::Id()
{
	return _Id;
}

void TextureImplOpenGL3::Copy(const Vec2u& dstPos, const Vec2u& srcSize, uint8_t* pixels, uint8_t bytesPerPixel)
{
	GLint format = 0;

	if (bytesPerPixel == 3)
		format = GL_RGB;
	else
		format = GL_RGBA;

	GL_CHECK(glTexSubImage2D(GL_TEXTURE_2D, 0, (GLint)dstPos.x, (GLint)dstPos.y, (GLsizei)srcSize.x, (GLsizei)srcSize.y, format, GL_UNSIGNED_BYTE, pixels));
}

void TextureImplOpenGL3::Copy(const Vec2u& dstPos, Surface* surface, const Vec2u& srcSize)
{
	Copy(dstPos, srcSize, surface->Pixels(), surface->BytesPerPixel());
}
