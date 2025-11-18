// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/Assert.hpp>
#include <LDL/APIs/OpenGL/OpenGL1_1.hpp>
#include <LDL/Shared/Graphics/Renders/OpenGL/Util.hpp>
#include <LDL/Shared/Graphics/Renders/OpenGL3/TextureImplOpenGL3.hpp>

using namespace LDL;

TextureImplOpenGL3::TextureImplOpenGL3(RenderContext* renderContextImpl, size_t pixelFormat, const Vec2u& size, uint8_t* pixels) :
	_renderContextImpl(renderContextImpl),
	_id(0)
{
	LDL_ASSERT(size.x > 0);
	LDL_ASSERT(size.y > 0);
	LDL_ASSERT(pixels != NULL);

	_size = size;

	GL_CHECK(glGenTextures(1, (GLuint*)&_id));
	GL_CHECK(glBindTexture(GL_TEXTURE_2D, (GLuint)_id));

	GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
	GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));

	GLint format = 0;
	uint8_t bpp  = BytesPerPixelFromPixelFormat(pixelFormat);

	if (bpp == 3)
	{
		format = GL_RGB;
	}
	else
	{
		format = GL_RGBA;
	}

	GL_CHECK(glTexImage2D(GL_TEXTURE_2D, 0, format, (GLsizei)_size.x, (GLsizei)_size.y, 0, format, GL_UNSIGNED_BYTE, pixels));
}

TextureImplOpenGL3::TextureImplOpenGL3(RenderContext* renderContextImpl, size_t pixelFormat, const Vec2u& size) :
	_renderContextImpl(renderContextImpl),
	_id(0)
{
	LDL_UNUSED(size);
	LDL_UNUSED(pixelFormat);
}

TextureImplOpenGL3::~TextureImplOpenGL3()
{
	GL_CHECK(glDeleteTextures(1, (GLuint*)&_id));
}

const Vec2u& TextureImplOpenGL3::Size()
{
	return _size;
}

const Vec2u& TextureImplOpenGL3::Quad()
{
	return _quad;
}

size_t TextureImplOpenGL3::Id()
{
	return _id;
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
