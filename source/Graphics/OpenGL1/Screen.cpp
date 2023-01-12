#include "Screen.hpp"
#include <LDL/OpenGL/OpenGL1_0.hpp>
#include "Util.hpp"

using namespace LDL::Graphics;

Screen::Screen(const Point2u& size) :
	_Size(size),
	_Screen(0),
	_MaxTextureSize(GpuUtil::MaxTextureSize())
{
	if (GpuUtil::IsMaxTextureSize(_Size, GpuUtil::MaxTextureSize()))
	{
		size_t sz = GpuUtil::SelectTextureSize(_Size);

		GL_CHECK(glEnable(GL_TEXTURE_2D));

		GL_CHECK(glGenTextures(1, (GLuint*)&_Screen));

		GL_CHECK(glBindTexture(GL_TEXTURE_2D, (GLuint)_Screen));

		GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
		GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));

		GL_CHECK(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei)sz, (GLsizei)sz, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL));

		GL_CHECK(glDisable(GL_TEXTURE_2D));
	}
}

Screen::~Screen()
{
	if (GpuUtil::IsMaxTextureSize(_Size, _MaxTextureSize))
		GL_CHECK(glDeleteTextures(0, (GLuint*)&_Screen));
}

void Screen::Draw(Surface* image, const Point2u& pos, const Point2u& size)
{
	if (GpuUtil::IsMaxTextureSize(_Size, _MaxTextureSize))
		DrawTexture(image, pos, size);
	else
		DrawPixels(image, pos, size);
}

void Screen::Draw(Surface* image, const Point2u& pos)
{
	Draw(image, pos, image->Size());
}

void LDL::Graphics::Screen::DrawTexture(Surface* image, const Point2u& pos, const Point2u& size)
{
	GL_CHECK(glEnable(GL_TEXTURE_2D));

	GL_CHECK(glBindTexture(GL_TEXTURE_2D, (GLuint)_Screen));

	GpuUtil::DrawQuad(pos, size);

	GLenum format = 0;

	if (image->BytesPerPixel() == 4)
		format = GL_RGBA;
	else
		format = GL_RGB;

	GL_CHECK(glTexSubImage2D(GL_TEXTURE_2D, 0, (GLint)pos.PosX(), (GLint)pos.PosY(), (GLsizei)image->Size().PosX(), (GLsizei)image->Size().PosY(), format, GL_UNSIGNED_BYTE, image->Pixels()));

	GL_CHECK(glDisable(GL_TEXTURE_2D));
}

void LDL::Graphics::Screen::DrawPixels(Surface* image, const Point2u& pos, const Point2u& size)
{
	GL_CHECK(glPixelZoom(1.0, -1.0));

	GL_CHECK(glRasterPos2i((GLint)pos.PosX(), (GLint)pos.PosY()));

	GLenum format = 0;

	if (image->BytesPerPixel() == 4)
		format = GL_RGBA;
	else
		format = GL_RGB;

	GL_CHECK(glDrawPixels((GLsizei)image->Size().PosX(), (GLsizei)image->Size().PosY(), format, GL_UNSIGNED_BYTE, image->Pixels()));
}