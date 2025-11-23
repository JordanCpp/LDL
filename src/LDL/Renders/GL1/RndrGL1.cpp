// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Funcs.hpp>
#include <LDL/Renders/GL/Util.hpp>
#include <LDL/Renders/GL1/RndrGL1.hpp>
#include <LDL/Renders/GL1/TexGL1.hpp>

#if defined(LDL_WINDOWS_NT)
    #include <LDL/WinNT/WinGL1.hpp>
#elif defined(LDL_WINDOWS_9X)
    #include <LDL/Win9X/WinGL1.hpp>
#elif defined(__unix__)
    #include <LDL/Linux/WinGL1.hpp>
#endif

RenderImplOpenGL1::RenderImplOpenGL1(LDL_Result& result, LDL_RenderContext* renderContextImpl, LDL_IWindow* window) :
	_result(result),
	_window(window),
	_screen(_window->Size()),
	_context(renderContextImpl)
{
	Begin();

	GL_CHECK(glEnable(GL_BLEND));
	GL_CHECK(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
}

void RenderImplOpenGL1::Buffer(uint8_t* dst)
{
	GL_CHECK(glReadPixels(0, 0, (GLsizei)_window->Size().x, (GLsizei)_window->Size().y, GL_RGBA, GL_UNSIGNED_BYTE, dst));
}

void RenderImplOpenGL1::Begin()
{
	LDL_Vec2u size = _window->Size();

	GL_CHECK(glViewport(0, 0, (GLsizei)size.x, (GLsizei)size.y));

	_projection = LDL_Ortho(0.0f, (float)size.x, (float)size.y, 0.0f, 0.0f, 1.0f);
	GL_CHECK(glMatrixMode(GL_PROJECTION));
	GL_CHECK(glLoadMatrixf(_projection.Values()));

	GL_CHECK(glMatrixMode(GL_MODELVIEW));
	GL_CHECK(glLoadMatrixf(_modelView.Values()));
}

void RenderImplOpenGL1::End()
{
	_modelView.Identity();
	_renderBuffer.Draw();

	_window->Present();

	_renderBuffer.Reset();
}

const LDL_Vec2u& RenderImplOpenGL1::Size()
{
	return _window->Size();
}

const LDL_Color& RenderImplOpenGL1::GetColor()
{
	return _color;
}

void RenderImplOpenGL1::Clear()
{
	GLclampf r;
	GLclampf g;
	GLclampf b;

	Normalize(_color, r, g, b);

	GL_CHECK(glClearColor(r, g, b, 1.0f));
	GL_CHECK(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}

void RenderImplOpenGL1::SetColor(const LDL_Color& color)
{
	_color = color;
}

void RenderImplOpenGL1::Pixel(const LDL_Vec2u& pos)
{
	GLclampf r;
	GLclampf g;
	GLclampf b;

	Normalize(_color, r, g, b);

	glBegin(GL_POINTS);
	glColor3f(r, g, b);
	glVertex2i((GLint)pos.x, (GLint)pos.y);
	glEnd();
}

void RenderImplOpenGL1::Line(const LDL_Vec2u& pos1, const LDL_Vec2u& pos2)
{
	_renderBuffer.Line(pos1, pos2, _color);
}

void RenderImplOpenGL1::Fill(const LDL_Vec2u& pos, const LDL_Vec2u& size)
{
	_renderBuffer.Fill(pos, size, _color);
}

void RenderImplOpenGL1::Draw(LDL_Surface* image, const LDL_Vec2u& pos)
{
	_screen.Draw(image, pos);
}

void RenderImplOpenGL1::Draw(LDL_Surface* image, const LDL_Vec2u& pos, const LDL_Vec2u& size)
{
	_screen.Draw(image, pos, size);
}

void RenderImplOpenGL1::Draw(LDL_Surface* image, const LDL_Vec2u& dstPos, const LDL_Vec2u& srcPos, const LDL_Vec2u& srcSize)
{
	LDL_UNUSED(image);
	LDL_UNUSED(dstPos);
	LDL_UNUSED(srcPos);
	LDL_UNUSED(srcSize);
}

void RenderImplOpenGL1::Draw(LDL_Surface* image, const LDL_Vec2u& dstPos, const LDL_Vec2u& dstSize, const LDL_Vec2u& srcPos, const LDL_Vec2u& srcSize)
{
	LDL_UNUSED(image);
	LDL_UNUSED(dstPos);
	LDL_UNUSED(dstSize);
	LDL_UNUSED(srcPos);
	LDL_UNUSED(srcSize);
}

void RenderImplOpenGL1::Draw(LDL_ITexture* image, const LDL_Vec2u& pos)
{
	Draw(image, pos, image->Size(), LDL_Vec2u(0, 0), image->Size());
}

void RenderImplOpenGL1::Draw(LDL_ITexture* image, const LDL_Vec2u& pos, const LDL_Vec2u& size)
{
	Draw(image, pos, size, LDL_Vec2u(0, 0), image->Size());
}

void RenderImplOpenGL1::Draw(LDL_ITexture* image, const LDL_Vec2u& dstPos, const LDL_Vec2u& srcPos, const LDL_Vec2u& srcSize)
{
	Draw(image, dstPos, srcSize, srcPos, srcSize);
}

void RenderImplOpenGL1::Draw(LDL_ITexture* image, const LDL_Vec2u& dstPos, const LDL_Vec2u& dstSize, const LDL_Vec2u& srcPos, const LDL_Vec2u& srcSize)
{
	_renderBuffer.Texture(dstPos, dstSize, srcPos, srcSize, ((LDL_TextureOpenGL1*)image)->Id(), image->Quad().x);
}

void RenderImplOpenGL1::Draw(LDL_ISpriteBatcher* textureBatcher)
{
	LDL_SpriteBatcherImplOpenGL1* batcher = (LDL_SpriteBatcherImplOpenGL1*)textureBatcher;

	_renderBuffer.TextureBatcher(batcher->TextureId(), batcher->Count(), batcher->Content());
}
