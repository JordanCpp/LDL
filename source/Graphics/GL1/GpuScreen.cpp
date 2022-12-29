#include "GpuScreen.hpp"
#include <LDL/OpenGL/OpenGL1_0.hpp>
#include "GpuUtil.hpp"

using namespace LDL::Graphics;

GpuScreen::GpuScreen(const Point2u& size) :
	_Size(size),
	_Screen(0)
{
	GL_CHECK(glEnable(GL_TEXTURE_2D));

	GL_CHECK(glGenTextures(1, (GLuint*)&_Screen));

	GL_CHECK(glBindTexture(GL_TEXTURE_2D, (GLuint)_Screen));

	GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
	GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));

	GL_CHECK(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei)_Size.PosX(), (GLsizei)_Size.PosY(), 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL));

	GL_CHECK(glDisable(GL_TEXTURE_2D));
}

GpuScreen::~GpuScreen()
{
	GL_CHECK(glDeleteTextures(0, (GLuint*)&_Screen));
}

void GpuScreen::Draw(CpuImage* image, const Point2u& pos, const Point2u& size)
{
	GL_CHECK(glEnable(GL_TEXTURE_2D));

	GL_CHECK(glBindTexture(GL_TEXTURE_2D, (GLuint)_Screen));

	GpuUtil::DrawQuad(pos, size);

	GLenum format = 0;

	if (image->BytesPerPixel() == 4)
		format = GL_RGBA;
	else
		format = GL_RGB;

	GL_CHECK(glTexSubImage2D(GL_TEXTURE_2D, 0, pos.PosX(), pos.PosY(), (GLsizei)image->Size().PosX(), (GLsizei)image->Size().PosY(), format, GL_UNSIGNED_BYTE, image->Pixels()));

	GL_CHECK(glDisable(GL_TEXTURE_2D));
}

void GpuScreen::Draw(CpuImage* image, const Point2u& pos)
{
	Draw(image, pos, image->Size());
}