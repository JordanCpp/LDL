// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include "RenderImplOpenGL1.hpp"
#include "../OpenGL/Util.hpp"
#include "TextureImplOpenGL1.hpp"

#include <LDL/Math/Funcs.hpp>

#if defined(_WIN32)
#include <LDL/Platforms/Windows/Graphics/WindowImplOpenGL1.hpp>
#elif defined(__unix__)
#include <LDL/Platforms/Linux/Graphics/OpenGL1/WindowImplOpenGL1.hpp>
#endif

using namespace LDL::Core;
using namespace LDL::Graphics;
using namespace LDL::Math;

RenderImplOpenGL1::RenderImplOpenGL1(Result& result, RenderContextImpl* renderContextImpl, Window* window) :
	_result(result),
	_window(window),
	_screen(_window->Size()),
	_renderContextImpl(renderContextImpl)
{
	Begin();

	GL_CHECK(glEnable(GL_BLEND));
	GL_CHECK(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
}

void LDL::Graphics::RenderImplOpenGL1::Buffer(uint8_t* dst)
{
	GL_CHECK(glReadPixels(0, 0, (GLsizei)_window->Size().x, (GLsizei)_window->Size().y, GL_RGBA, GL_UNSIGNED_BYTE, dst));
}

void RenderImplOpenGL1::Begin()
{
	Vec2u size = _window->Size();

	GL_CHECK(glViewport(0, 0, (GLsizei)size.x, (GLsizei)size.y));

	_projection = Ortho(0.0f, (float)size.x, (float)size.y, 0.0f, 0.0f, 1.0f);
	GL_CHECK(glMatrixMode(GL_PROJECTION));
	GL_CHECK(glLoadMatrixf(_projection.Values()));

	GL_CHECK(glMatrixMode(GL_MODELVIEW));
	GL_CHECK(glLoadMatrixf(_modelView.Values()));
}

void RenderImplOpenGL1::End()
{
	_modelView.Identity();
	_renderBuffer.Draw();

	_window->GetWindowImpl()->Present();

	_renderBuffer.Reset();
}

const Vec2u& RenderImplOpenGL1::Size()
{
	return _window->Size();
}

const Color& RenderImplOpenGL1::Color()
{
	return _color;
}

void RenderImplOpenGL1::Clear()
{
	GLclampf r;
	GLclampf g;
	GLclampf b;

	Util::Normalize(_color, r, g, b);

	GL_CHECK(glClearColor(r, g, b, 1.0f));
	GL_CHECK(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}

void RenderImplOpenGL1::Color(const LDL::Graphics::Color& color)
{
	_color = color;
}

void RenderImplOpenGL1::Pixel(const Vec2u& pos)
{
	GLclampf r;
	GLclampf g;
	GLclampf b;

	Util::Normalize(_color, r, g, b);

	glBegin(GL_POINTS);
	glColor3f(r, g, b);
	glVertex2i((GLint)pos.x, (GLint)pos.y);
	glEnd();
}

void RenderImplOpenGL1::Line(const Vec2u& pos1, const Vec2u& pos2)
{
	_renderBuffer.Line(pos1, pos2, _color);
}

void RenderImplOpenGL1::Fill(const Vec2u& pos, const Vec2u& size)
{
	_renderBuffer.Fill(pos, size, _color);
}

void RenderImplOpenGL1::Draw(Surface* image, const Vec2u& pos)
{
	_screen.Draw(image, pos);
}

void RenderImplOpenGL1::Draw(Surface* image, const Vec2u& pos, const Vec2u& size)
{
	_screen.Draw(image, pos, size);
}

void RenderImplOpenGL1::Draw(Surface* image, const Vec2u& dstPos, const Vec2u& srcPos, const Vec2u& srcSize)
{
}

void RenderImplOpenGL1::Draw(Surface* image, const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize)
{
}

void RenderImplOpenGL1::Draw(Texture* image, const Vec2u& pos)
{
	Draw(image, pos, image->Size(), Vec2u(0, 0), image->Size());
}

void RenderImplOpenGL1::Draw(Texture* image, const Vec2u& pos, const Vec2u& size)
{
	Draw(image, pos, size, Vec2u(0, 0), image->Size());
}

void RenderImplOpenGL1::Draw(Texture* image, const Vec2u& dstPos, const Vec2u& srcPos, const Vec2u& srcSize)
{
	Draw(image, dstPos, srcSize, srcPos, srcSize);
}

void RenderImplOpenGL1::Draw(Texture* image, const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize)
{
	_renderBuffer.Texture(dstPos, dstSize, srcPos, srcSize, ((TextureImplOpenGL1*)image->GetTextureImpl())->Id(), image->GetTextureImpl()->Quad().x);
}

void RenderImplOpenGL1::Draw(TextureBatcher* textureBatcher)
{
	TextureBatcherImplOpenGL1* batcher = (TextureBatcherImplOpenGL1*)textureBatcher->GetTextureBatcherImpl();

	_renderBuffer.TextureBatcher(batcher->TextureId(), batcher->Count(), batcher->Content());
}
