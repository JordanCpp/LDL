#include <LDL/Graphics/GL1/GL1Image.hpp>
#include <LDL/Graphics/OpenGL.hpp>
#include <assert.h>

LDL::Graphics::GL1Image::GL1Image(const LDL::Graphics::Point2u& size, size_t bytesPerPixel, uint8_t* pixels):
	_Id(0)
{
	assert(size.PosX() > 0);
	assert(size.PosY() > 0);
	assert(bytesPerPixel >= 1 && bytesPerPixel <= 4);
	assert(pixels != NULL);

	_Size = size;

	glGenTextures(1, (GLuint*)&_Id);

	glBindTexture(GL_TEXTURE_2D, (GLuint)_Id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	int format = 0;

	if (bytesPerPixel == 3)
		format = GL_RGB;
	else
		format = GL_RGBA;

	glTexImage2D(GL_TEXTURE_2D, 0, format, (GLsizei)_Size.PosX(), (GLsizei)_Size.PosY(), 0, format, GL_UNSIGNED_BYTE, pixels);
}

LDL::Graphics::GL1Image::~GL1Image()
{
	glDeleteTextures(0, (GLuint*)&_Id);
}

const LDL::Graphics::Point2u& LDL::Graphics::GL1Image::Size()
{
	return _Size;
}

size_t LDL::Graphics::GL1Image::Id()
{
	return _Id;
}