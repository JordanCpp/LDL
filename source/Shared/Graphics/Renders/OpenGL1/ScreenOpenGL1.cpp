#include "ScreenOpenGL1.hpp"
#include <LDL/OpenGL/OpenGL1_0.hpp>
#include "../OpenGL/Util.hpp"

using namespace LDL::Graphics;
using namespace LDL::Math;

ScreenOpenGL1::ScreenOpenGL1(const Vec2u& size) :
	_Size(size),
	_Screen(0),
	_MaxTextureSize(Util::MaxTextureSize()),
	_CurTextureSize(0)
{
	if (Util::IsMaxTextureSize(_Size, Util::MaxTextureSize()))
	{
		_CurTextureSize = _PotTextureSizer.Calc(_Size);

		GL_CHECK(glEnable(GL_TEXTURE_2D));

		GL_CHECK(glGenTextures(1, (GLuint*)&_Screen));

		GL_CHECK(glBindTexture(GL_TEXTURE_2D, (GLuint)_Screen));

		GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
		GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));

		GL_CHECK(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei)_CurTextureSize, (GLsizei)_CurTextureSize, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL));

		GL_CHECK(glDisable(GL_TEXTURE_2D));
	}
}

ScreenOpenGL1::~ScreenOpenGL1()
{
	if (Util::IsMaxTextureSize(_Size, _MaxTextureSize))
		GL_CHECK(glDeleteTextures(0, (GLuint*)&_Screen));
}

void ScreenOpenGL1::Draw(Surface* image, const Vec2u& pos, const Vec2u& size)
{
	if (Util::IsMaxTextureSize(_Size, _MaxTextureSize))
		DrawTexture(image, pos, size);
	else
		DrawPixels(image, pos, size);
}

void ScreenOpenGL1::Draw(Surface* image, const Vec2u& pos)
{
	Draw(image, pos, image->Size());
}

void ScreenOpenGL1::DrawTexture(Surface* image, const Vec2u& pos, const Vec2u& size)
{
	GL_CHECK(glEnable(GL_TEXTURE_2D));

	GL_CHECK(glBindTexture(GL_TEXTURE_2D, (GLuint)_Screen));

	Util::DrawQuad(pos, size, Vec2u(0, 0), image->Size(), _CurTextureSize);

	GLenum format = 0;

	if (image->BytesPerPixel() == 4)
		format = GL_RGBA;
	else
		format = GL_RGB;

	GL_CHECK(glTexSubImage2D(GL_TEXTURE_2D, 0, (GLint)pos.x, (GLint)pos.y, (GLsizei)image->Size().x, (GLsizei)image->Size().y, format, GL_UNSIGNED_BYTE, image->Pixels()));

	GL_CHECK(glDisable(GL_TEXTURE_2D));
}

void ScreenOpenGL1::DrawPixels(Surface* image, const Vec2u& pos, const Vec2u& size)
{
	GL_CHECK(glPixelZoom(1.0, -1.0));

	GL_CHECK(glRasterPos2i((GLint)pos.x, (GLint)pos.y));

	GLenum format = 0;

	if (image->BytesPerPixel() == 4)
		format = GL_RGBA;
	else
		format = GL_RGB;

	GL_CHECK(glDrawPixels((GLsizei)image->Size().x, (GLsizei)image->Size().y, format, GL_UNSIGNED_BYTE, image->Pixels()));
}
