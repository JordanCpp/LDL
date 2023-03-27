#include "TextureImpl.hpp"
#include <LDL/OpenGL/OpenGL1_0.hpp>
#include <assert.h>
#include "Util.hpp"
#include <iostream>

using namespace LDL::Graphics;

TextureImpl::TextureImpl(RenderContextImpl* renderContextImpl, const Point2u& size, uint8_t* pixels, size_t bytesPerPixel) :
	_RenderContextImpl(renderContextImpl),
	_Id(0)
{
	assert(size.PosX() > 0);
	assert(size.PosY() > 0);
	assert(bytesPerPixel >= 1 && bytesPerPixel <= 4);
	assert(pixels != NULL);

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

	GL_CHECK(glTexImage2D(GL_TEXTURE_2D, 0, format, (GLsizei)_Size.PosX(), (GLsizei)_Size.PosY(), 0, format, GL_UNSIGNED_BYTE, pixels));
}

TextureImpl::~TextureImpl()
{
	GL_CHECK(glDeleteTextures(0, (GLuint*)&_Id));
}

const Point2u& TextureImpl::Size()
{
	return _Size;
}

size_t TextureImpl::Id()
{
	return _Id;
}