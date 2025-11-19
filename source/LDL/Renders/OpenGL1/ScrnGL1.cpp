// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/OpenGL/OpenGL1_0.hpp>
#include <LDL/Renders/OpenGL/Util.hpp>
#include <LDL/Renders/OpenGL1/ScrnGL1.hpp>

ScreenOpenGL1::ScreenOpenGL1(const LDL_Vec2u& size) :
	_size(size),
	_screen(0),
	_maxTextureSize(MaxTextureSize()),
	_curTextureSize(0)
{
	if (IsMaxTextureSize(_size, MaxTextureSize()))
	{
		_curTextureSize = _potTextureSizer.Calc(_size);

		GL_CHECK(glEnable(GL_TEXTURE_2D));

		GL_CHECK(glGenTextures(1, (GLuint*)&_screen));

		GL_CHECK(glBindTexture(GL_TEXTURE_2D, (GLuint)_screen));

		GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
		GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));

		GL_CHECK(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei)_curTextureSize, (GLsizei)_curTextureSize, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL));

		GL_CHECK(glDisable(GL_TEXTURE_2D));
	}
}

ScreenOpenGL1::~ScreenOpenGL1()
{
	if (IsMaxTextureSize(_size, _maxTextureSize))
	{
		GL_CHECK(glDeleteTextures(1, (GLuint*)&_screen));
	}
}

void ScreenOpenGL1::Draw(LDL_Surface* image, const LDL_Vec2u& pos, const LDL_Vec2u& size)
{
	if (IsMaxTextureSize(_size, _maxTextureSize))
	{
		DrawTexture(image, pos, size);
	}
	else
	{
		DrawPixels(image, pos, size);
	}
}

void ScreenOpenGL1::Draw(LDL_Surface* image, const LDL_Vec2u& pos)
{
	Draw(image, pos, image->Size());
}

void ScreenOpenGL1::DrawTexture(LDL_Surface* image, const LDL_Vec2u& pos, const LDL_Vec2u& size)
{
	GL_CHECK(glEnable(GL_TEXTURE_2D));

	GL_CHECK(glBindTexture(GL_TEXTURE_2D, (GLuint)_screen));

	DrawQuad(pos, size, LDL_Vec2u(0, 0), image->Size(), _curTextureSize);

	GLenum format = 0;

	if (image->BytesPerPixel() == 4)
		format = GL_RGBA;
	else
		format = GL_RGB;

	GL_CHECK(glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, (GLsizei)image->Size().x, (GLsizei)image->Size().y, format, GL_UNSIGNED_BYTE, image->Pixels()));

	GL_CHECK(glDisable(GL_TEXTURE_2D));
}

void ScreenOpenGL1::DrawPixels(LDL_Surface* image, const LDL_Vec2u& pos, const LDL_Vec2u& size)
{
	LDL_UNUSED(size);

	GL_CHECK(glPixelZoom(1.0, -1.0));

	GL_CHECK(glRasterPos2i((GLint)pos.x, (GLint)pos.y));

	GLenum format = 0;

	if (image->BytesPerPixel() == 4)
		format = GL_RGBA;
	else
		format = GL_RGB;

	GL_CHECK(glDrawPixels((GLsizei)image->Size().x, (GLsizei)image->Size().y, format, GL_UNSIGNED_BYTE, image->Pixels()));
}
