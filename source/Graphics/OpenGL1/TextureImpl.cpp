#include "TextureImpl.hpp"
#include <LDL/OpenGL/OpenGL1_0.hpp>
#include <assert.h>
#include "../OpenGL/Util.hpp"
#include <iostream>

using namespace LDL::Graphics;
using namespace LDL::Math;

TextureImpl::TextureImpl(RenderContextImpl* renderContextImpl, const Vec2u& size, uint8_t* pixels, size_t bytesPerPixel) :
	_RenderContextImpl(renderContextImpl),
	_Id(0)
{
	assert(size.x > 0);
	assert(size.y > 0);
	assert(bytesPerPixel >= 1 && bytesPerPixel <= 4);
	assert(pixels != NULL);

	_Size = size;

	GLint format = 0;

	if (bytesPerPixel == 3)
		format = GL_RGB;
	else
		format = GL_RGBA;

	size_t sz = Util::SelectTextureSize(_Size);

	_Quad = Vec2u(sz, sz);

	_Id = Util::CreateTexture((GLsizei)_Quad.x, (GLsizei)_Quad.y, format);

	Copy(Vec2u(0, 0), _Size, pixels, bytesPerPixel);
}

TextureImpl::TextureImpl(RenderContextImpl* renderContextImpl, const Vec2u& size, size_t bytesPerPixel) :
	_RenderContextImpl(renderContextImpl),
	_Id(0)
{
	_Size = size;

	GLint format = 0;

	if (bytesPerPixel == 3)
		format = GL_RGB;
	else
		format = GL_RGBA;

	size_t sz = Util::SelectTextureSize(_Size);

	_Quad = Vec2u(sz, sz);

	_Id = Util::CreateTexture((GLsizei)_Quad.x, (GLsizei)_Quad.y, format);
}

TextureImpl::~TextureImpl()
{
	Util::DeleteTexture((GLint)_Id);
}

void TextureImpl::Copy(const Vec2u& dstPos, const Vec2u& srcSize, uint8_t* pixels, size_t bytesPerPixel)
{
	GLint format = 0;

	if (bytesPerPixel == 3)
		format = GL_RGB;
	else
		format = GL_RGBA;

	GL_CHECK(glTexSubImage2D(GL_TEXTURE_2D, 0, (GLint)dstPos.x, (GLint)dstPos.y, (GLsizei)srcSize.x, (GLsizei)srcSize.y, format, GL_UNSIGNED_BYTE, pixels));
}

void TextureImpl::Copy(const Vec2u& dstPos, Surface* surface, const Vec2u& srcSize)
{
	Copy(dstPos, srcSize, surface->Pixels(), surface->BytesPerPixel());
}

const Vec2u& TextureImpl::Size()
{
	return _Size;
}

const Vec2u& TextureImpl::Quad()
{
	return _Quad;
}

size_t TextureImpl::Id()
{
	return _Id;
}