#include "GL1Screen.hpp"
#include "OpenGL.hpp"
#include "GpuUtil.hpp"

using namespace LDL::Graphics;

GL1Screen::GL1Screen(const Point2u& size) :
	_Size(size),
	_Screen(0)
{
	glGenTextures(1, (GLuint*)&_Screen);

	glBindTexture(GL_TEXTURE_2D, (GLuint)_Screen);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei)_Size.PosX(), (GLsizei)_Size.PosY(), 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
}

GL1Screen::~GL1Screen()
{
	glDeleteTextures(0, (GLuint*)&_Screen);
}

void GL1Screen::Draw(CpuImage* image, const Point2u& pos, const Point2u& size)
{
	glBindTexture(GL_TEXTURE_2D, (GLuint)_Screen);

	glEnable(GL_TEXTURE_2D);

	GpuUtil::DrawQuad(pos, size);

	glDisable(GL_TEXTURE_2D);

	GLenum format = 0;

	if (image->BytesPerPixel() == 4)
		format = GL_RGBA;
	else
		format = GL_RGB;

	glTexSubImage2D(GL_TEXTURE_2D, 0, pos.PosX(), pos.PosY(), (GLsizei)image->Size().PosX(), (GLsizei)image->Size().PosY(), format, GL_UNSIGNED_BYTE, image->Pixels());
}

void GL1Screen::Draw(CpuImage* image, const Point2u& pos)
{
	Draw(image, pos, image->Size());
}