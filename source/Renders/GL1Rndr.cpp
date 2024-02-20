/*
Boost Software License - Version 1.0 - August 17th, 2003

Permission is hereby granted, free of charge, to any person or organization
obtaining a copy of the software and accompanying documentation covered by
this license (the "Software") to use, reproduce, display, distribute,
execute, and transmit the Software, and to prepare derivative works of the
Software, and to permit third-parties to whom the Software is furnished to
do so, all subject to the following:

The copyright notices in the Software and this entire statement, including
the above license grant, this restriction and the following disclaimer,
must be included in all copies of the Software, in whole or in part, and
all derivative works of the Software, unless such copies or derivative
works are solely in the form of machine-executable object code generated by
a source language processor.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

#include <LDL/Renders/GL1Rndr.hpp>
#include <LDL/Funcs.hpp>
#include <LDL/UtilGL.hpp>
#include <assert.h>

/********************************************************************************************************************************
													      LDL_TextureOpenGL1
********************************************************************************************************************************/
LDL_TextureOpenGL1::LDL_TextureOpenGL1(const LDL_Vec2i& size, uint8_t* pixels, uint8_t bytesPerPixel) :
	_Id(0)
{
	assert(size.x > 0);
	assert(size.y > 0);
	assert(bytesPerPixel >= 1 && bytesPerPixel <= 4);
	assert(pixels != NULL);

	_Size = size;

	GLint format = GetFormat(bytesPerPixel);

	int sz = LDL_SelectTextureSize(_Size);

	_Quad = LDL_Vec2i(sz, sz);

	_Id = LDL_CreateTexture((GLsizei)_Quad.x, (GLsizei)_Quad.y, format);

	Copy(LDL_Vec2i(0, 0), _Size, pixels, bytesPerPixel);
}

LDL_TextureOpenGL1::LDL_TextureOpenGL1(const LDL_Vec2i& size, uint8_t bytesPerPixel) :
	_Id(0)
{
	_Size = size;

	GLint format = GetFormat(bytesPerPixel);

	int sz = LDL_SelectTextureSize(_Size);

	_Quad = LDL_Vec2i(sz, sz);

	_Id = LDL_CreateTexture((GLsizei)_Quad.x, (GLsizei)_Quad.y, format);
}

LDL_TextureOpenGL1::LDL_TextureOpenGL1(const LDL_Vec2i& size, uint8_t* pixels, LDL_Palette* palette) :
	_Id(0)
{
	_Size = size;

	GLint format = GetFormat(3);

	int sz = LDL_SelectTextureSize(_Size);

	_Quad = LDL_Vec2i(sz, sz);

	_Id = LDL_CreateTexture((GLsizei)_Quad.x, (GLsizei)_Quad.y, format);

	uint8_t* LDL_FAR rgbPixels = new uint8_t[size.x * size.y * 3];

	for (size_t i = 0; i < size.x * size.y; i++)
	{
		size_t index = i * 3;

		rgbPixels[index    ] = palette->Get(pixels[i]).r;
		rgbPixels[index + 1] = palette->Get(pixels[i]).g;
		rgbPixels[index + 2] = palette->Get(pixels[i]).b;
	}

	Copy(LDL_Vec2i(0, 0), _Size, rgbPixels, 3);

	delete[] rgbPixels;
}

LDL_TextureOpenGL1::~LDL_TextureOpenGL1()
{
	LDL_DeleteTexture((GLint)_Id);
}

void LDL_TextureOpenGL1::Copy(const LDL_Vec2i& dstPos, const LDL_Vec2i& srcSize, uint8_t* pixels, uint8_t bytesPerPixel)
{
	GLint format = GetFormat(bytesPerPixel);

	LDL_GL_CHECK(glTexSubImage2D(GL_TEXTURE_2D, 0, (GLint)dstPos.x, (GLint)dstPos.y, (GLsizei)srcSize.x, (GLsizei)srcSize.y, format, GL_UNSIGNED_BYTE, pixels));
}

void LDL_TextureOpenGL1::Copy(const LDL_Vec2i& dstPos, LDL_Surface* surface, const LDL_Vec2i& srcSize)
{
	Copy(dstPos, srcSize, surface->Pixels(), surface->Bpp());
}

const LDL_Vec2i& LDL_TextureOpenGL1::Size()
{
	return _Size;
}

const LDL_Vec2i& LDL_TextureOpenGL1::Quad()
{
	return _Quad;
}

GLuint LDL_TextureOpenGL1::Id()
{
	return _Id;
}

GLint LDL_TextureOpenGL1::GetFormat(uint8_t bpp)
{
	if (bpp == 3)
	{
		return GL_RGB;
	}
	
	return GL_RGBA;
}

/********************************************************************************************************************************
													       LDL_RenderOpenGL1
********************************************************************************************************************************/
LDL_RenderOpenGL1::LDL_RenderOpenGL1(LDL_WindowOpenGL1* window, LDL_Palette* palette) :
	_Window(window),
	_BaseRender(_Window->Size(), palette),
	_OpenGLLoader(1, 2)
{
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
}

void LDL_RenderOpenGL1::Begin()
{
	LDL_Vec2i size = _Window->Size();

	LDL_GL_CHECK(glViewport(0, 0, (GLsizei)size.x, (GLsizei)size.y));

	_Projection = LDL_Ortho(0.0f, (float)size.x, (float)size.y, 0.0f, -1.0f, 1.0f);
	LDL_GL_CHECK(glMatrixMode(GL_PROJECTION));
	LDL_GL_CHECK(glLoadMatrixf(_Projection.Values()));

	LDL_GL_CHECK(glMatrixMode(GL_MODELVIEW));
	LDL_GL_CHECK(glLoadMatrixf(_ModelView.Values()));
}

void LDL_RenderOpenGL1::End()
{
	_Window->Present();
}

void LDL_RenderOpenGL1::Line(const LDL_Vec2i& pos1, const LDL_Vec2i& pos2)
{
	GLclampf r;
	GLclampf g;
	GLclampf b;

	LDL_Normalize(_BaseRender.Color(), r, g, b);

	glBegin(GL_LINES);
	glColor3f(r, g, b);
	glVertex2i(pos1.x, pos1.y);
	glVertex2i(pos2.x, pos2.y);
	glEnd();
}

void LDL_RenderOpenGL1::Fill(const LDL_Vec2i& pos, const LDL_Vec2i& size)
{
	GLclampf r;
	GLclampf g;
	GLclampf b;

	LDL_Normalize(_BaseRender.Color(), r, g, b);
	glColor3f(r, g, b);

	GLint x = (GLint)pos.x;
	GLint y = (GLint)pos.y;
	GLint w = (GLint)size.x;
	GLint h = (GLint)size.y;

	glBegin(GL_QUADS);
	glVertex2i(x, y + h);
	glVertex2i(x, y);
	glVertex2i(x + w, y);
	glVertex2i(x + w, y + h);
	glEnd();
}

void LDL_RenderOpenGL1::SetColor(uint8_t index)
{
	_BaseRender.SetColor(index);
}

void LDL_RenderOpenGL1::SetColor(const LDL_Color& color)
{
	_BaseRender.SetColor(color);
}

void LDL_RenderOpenGL1::Clear()
{
	GLclampf r;
	GLclampf g;
	GLclampf b;

	LDL_Normalize(_BaseRender.Color(), r, g, b);

	glClearColor(r, g, b, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void LDL_RenderOpenGL1::Draw(LDL_TextureOpenGL1* image, const LDL_Vec2i& pos)
{
	Draw(image, pos, image->Size(), LDL_Vec2i(0, 0), image->Size());
}

void LDL_RenderOpenGL1::Draw(LDL_TextureOpenGL1* image, const LDL_Vec2i& pos, const LDL_Vec2i& size)
{
	Draw(image, pos, size, LDL_Vec2i(0, 0), image->Size());
}

void LDL_RenderOpenGL1::Draw(LDL_TextureOpenGL1* image, const LDL_Vec2i& dstPos, const LDL_Vec2i& srcPos, const LDL_Vec2i& srcSize)
{
	Draw(image, dstPos, srcSize, srcPos, srcSize);
}

void LDL_RenderOpenGL1::Draw(LDL_TextureOpenGL1* image, const LDL_Vec2i& dstPos, const LDL_Vec2i& dstSize, const LDL_Vec2i& srcPos, const LDL_Vec2i& srcSize)
{
	assert(image);

	LDL_GL_CHECK(glEnable(GL_TEXTURE_2D));
	LDL_GL_CHECK(glBindTexture(GL_TEXTURE_2D, image->Id()));

	LDL_DrawQuad(dstPos, dstSize, srcPos, srcSize, image->Quad().x);

	LDL_GL_CHECK(glDisable(GL_TEXTURE_2D));
}

void LDL_RenderOpenGL1::Draw(LDL_Surface* image, const LDL_Vec2i& pos)
{
	Draw(image, pos, image->Size(), LDL_Vec2i(0, 0), image->Size());
}

void LDL_RenderOpenGL1::Draw(LDL_Surface* image, const LDL_Vec2i& pos, const LDL_Vec2i& size)
{
	Draw(image, pos, size, LDL_Vec2i(0, 0), image->Size());
}

void LDL_RenderOpenGL1::Draw(LDL_Surface* image, const LDL_Vec2i& dstPos, const LDL_Vec2i& srcPos, const LDL_Vec2i& srcSize)
{
	Draw(image, dstPos, srcSize, srcPos, srcSize);
}

void LDL_RenderOpenGL1::Draw(LDL_Surface* image, const LDL_Vec2i& dstPos, const LDL_Vec2i& dstSize, const LDL_Vec2i& srcPos, const LDL_Vec2i& srcSize)
{
	LDL_GL_CHECK(glPixelZoom(1.0, -1.0));

	LDL_GL_CHECK(glRasterPos2i((GLint)dstPos.x, (GLint)dstPos.y));

	GLenum format;

	if (image->Bpp() == 4)
		format = GL_RGBA;
	else
		format = GL_RGB;

	LDL_GL_CHECK(glDrawPixels((GLsizei)image->Size().x, (GLsizei)image->Size().y, format, GL_UNSIGNED_BYTE, image->Pixels()));
}
