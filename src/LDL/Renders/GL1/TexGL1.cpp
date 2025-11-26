// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Assert.hpp>
#include <LDL/OpenGL/GL1_0.hpp>
#include <LDL/Renders/GL/Util.hpp>
#include <LDL/Renders/GL1/TexGL1.hpp>

LDL_TextureOpenGL1::LDL_TextureOpenGL1(LDL_RenderContext* renderContextImpl, LDL_Surface* surface) :
	_context(renderContextImpl),
	_id(0)
{
	GLint format = 0;

	LDL_PodVector<uint8_t> pixels;

	if (surface->Enabled())
	{
		pixels.resize(surface->Size().x * surface->Size().y * 4);

		const uint8_t*  src = surface->Pixels();
		const LDL_Color key = surface->ColorKey();

		if (surface->BytesPerPixel() == 3)
		{
			for (size_t i = 0; i < surface->Size().x * surface->Size().y; i++)
			{
				uint8_t r = src[i * 3 + 0];
				uint8_t g = src[i * 3 + 1];
				uint8_t b = src[i * 3 + 2];

				bool isKeyColor = (r == key.r && g == key.g && b == key.b);

				pixels[i * 4 + 0] = r;
				pixels[i * 4 + 1] = g;
				pixels[i * 4 + 2] = b;
				pixels[i * 4 + 3] = isKeyColor ? 0 : 255;
			}
		}

		format = GL_RGBA;
	}
	else
	{
		if (surface->BytesPerPixel() == 3)
			format = GL_RGB;
		else
			format = GL_RGBA;
	}

	_size = surface->Size();

	uint32_t sz = SelectTextureSize(_size);

	_quad = LDL_Vec2u(sz, sz);

	_id = CreateTexture((GLsizei)_quad.x, (GLsizei)_quad.y, format);

	if (surface->Enabled())
	{
		Copy(LDL_Vec2u(0, 0), _size, pixels.data(), 4);
	}
	else
	{
		Copy(LDL_Vec2u(0, 0), _size, surface->Pixels(), surface->BytesPerPixel());
	}
}

LDL_TextureOpenGL1::LDL_TextureOpenGL1(LDL_RenderContext* renderContextImpl, size_t pixelFormat, const LDL_Vec2u& size, uint8_t* pixels) :
	_context(renderContextImpl),
	_id(0)
{
	LDL_ASSERT(size.x > 0);
	LDL_ASSERT(size.y > 0);
	LDL_ASSERT(pixels != NULL);

	_size = size;

	GLint format = 0;
	uint8_t bpp  = LDL_BytesPerPixelFromPixelFormat(pixelFormat);

	if (bpp == 3)
	{
		format = GL_RGB;
	}
	else
	{
		format = GL_RGBA;
	}

	uint32_t sz = SelectTextureSize(_size);

	_quad = LDL_Vec2u(sz, sz);

	_id = CreateTexture((GLsizei)_quad.x, (GLsizei)_quad.y, format);

	Copy(LDL_Vec2u(0, 0), _size, pixels, bpp);
}

LDL_TextureOpenGL1::LDL_TextureOpenGL1(LDL_RenderContext* renderContextImpl, size_t pixelFormat, const LDL_Vec2u& size) :
	_context(renderContextImpl),
	_id(0)
{
	_size = size;

	GLint format = 0;
	uint8_t bpp  = LDL_BytesPerPixelFromPixelFormat(pixelFormat);

	if (bpp == 3)
	{
		format = GL_RGB;
	}
	else
	{
		format = GL_RGBA;
	}

	uint32_t sz = SelectTextureSize(_size);

	_quad = LDL_Vec2u(sz, sz);

	_id = CreateTexture((GLsizei)_quad.x, (GLsizei)_quad.y, format);
}

LDL_TextureOpenGL1::~LDL_TextureOpenGL1()
{
	DeleteTexture((GLint)_id);
}

void LDL_TextureOpenGL1::Copy(const LDL_Vec2u& dstPos, const LDL_Vec2u& srcSize, uint8_t* pixels, uint8_t bytesPerPixel)
{
	GLint format = 0;

	if (bytesPerPixel == 3)
	{
		format = GL_RGB;
	}
	else
	{
		format = GL_RGBA;
	}

	GL_CHECK(glTexSubImage2D(GL_TEXTURE_2D, 0, (GLint)dstPos.x, (GLint)dstPos.y, (GLsizei)srcSize.x, (GLsizei)srcSize.y, format, GL_UNSIGNED_BYTE, pixels));
}

void LDL_TextureOpenGL1::Copy(const LDL_Vec2u& dstPos, LDL_Surface* surface, const LDL_Vec2u& srcSize)
{
	Copy(dstPos, srcSize, surface->Pixels(), surface->BytesPerPixel());
}

const LDL_Vec2u& LDL_TextureOpenGL1::Size()
{
	return _size;
}

const LDL_Vec2u& LDL_TextureOpenGL1::Quad()
{
	return _quad;
}

size_t LDL_TextureOpenGL1::Id()
{
	return _id;
}
