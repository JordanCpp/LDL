// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Funcs.hpp>
#include <LDL/Renders/GL/Util.hpp>
#include <LDL/Renders/GL3/RndrGL3.hpp>
#include <LDL/Renders/GL3/TexGL3.hpp>

#if defined(LDL_WINDOWS_NT)
    #include <LDL/WinNT/WinGL3.hpp>
#elif defined(LDL_WINDOWS_9X)
    #include <LDL/Win9X/WinGL3.hpp>
#elif defined(__unix__)
    #include <LDL/Linux/Graphics/OpenGL3/WindowImplOpenGL3.hpp>
#endif

RenderImplOpenGL3::RenderImplOpenGL3(LDL_Result& result, LDL_RenderContext* renderContextImpl, LDL_IWindow* window) :
	_result(result),
	_window(window),
	_linePainter(&_shaderLoader),
	_texturePainter(&_shaderLoader)
{
	LDL_UNUSED(renderContextImpl);
}

void RenderImplOpenGL3::Buffer(uint8_t* dst)
{
	LDL_UNUSED(dst);
}

void RenderImplOpenGL3::Begin()
{
	glViewport(0, 0, (GLsizei)_window->Size().x, (GLsizei)_window->Size().y);

	_projection = LDL_Ortho(0.0f, (float)_window->Size().x, (float)_window->Size().y, 0.0f, 0.0f, 1.0f);
}

void RenderImplOpenGL3::End()
{
	_window->Present();
}

const LDL_Vec2u& RenderImplOpenGL3::Size()
{
	return _window->Size();
}

const LDL_Color& RenderImplOpenGL3::GetColor()
{
	return _color;
}

void RenderImplOpenGL3::Clear()
{
	GLclampf r;
	GLclampf g;
	GLclampf b;

	Normalize(_color, r, g, b);

	GL_CHECK(glClearColor(r, g, b, 1.0f));
	GL_CHECK(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}

void RenderImplOpenGL3::SetColor(const LDL_Color& color)
{
	_color = color;
}

void RenderImplOpenGL3::Pixel(const LDL_Vec2u& pos)
{
	LDL_UNUSED(pos);
}

void RenderImplOpenGL3::Line(const LDL_Vec2u& pos1, const LDL_Vec2u& pos2)
{
	GLclampf r;
	GLclampf g;
	GLclampf b;

	Normalize(_color, r, g, b);

	_linePainter.Draw(_projection, Vec3f((float)pos1.x, (float)pos1.y, 0), Vec3f((float)pos2.x, (float)pos2.y, 0), Vec3f((float)r, (float)g, (float)b));
}

void RenderImplOpenGL3::Fill(const LDL_Vec2u& pos, const LDL_Vec2u& size)
{
	LDL_UNUSED(pos);
	LDL_UNUSED(size);
}

void RenderImplOpenGL3::Draw(LDL_Surface* image, const LDL_Vec2u& pos)
{
	Draw(image, pos, image->Size(), LDL_Vec2u(0,0), image->Size());
}

void RenderImplOpenGL3::Draw(LDL_Surface* image, const LDL_Vec2u& pos, const LDL_Vec2u& size)
{
	Draw(image, pos, size, LDL_Vec2u(0, 0), image->Size());
}

void RenderImplOpenGL3::Draw(LDL_Surface* image, const LDL_Vec2u& dstPos, const LDL_Vec2u& srcPos, const LDL_Vec2u& srcSize)
{
	Draw(image, dstPos, image->Size(), srcPos, srcSize);
}

void RenderImplOpenGL3::Draw(LDL_Surface* image, const LDL_Vec2u& dstPos, const LDL_Vec2u& dstSize, const LDL_Vec2u& srcPos, const LDL_Vec2u& srcSize)
{
	LDL_UNUSED(image);
	LDL_UNUSED(dstPos);
	LDL_UNUSED(dstSize);
	LDL_UNUSED(srcPos);
	LDL_UNUSED(srcSize);
}

void RenderImplOpenGL3::Draw(LDL_ITexture* image, const LDL_Vec2u& pos)
{
	Draw(image, pos, image->Size(), LDL_Vec2u(0,0), image->Size());
}

void RenderImplOpenGL3::Draw(LDL_ITexture* image, const LDL_Vec2u& pos, const LDL_Vec2u& size)
{
	Draw(image, pos, size, LDL_Vec2u(0, 0), image->Size());
}

void RenderImplOpenGL3::Draw(LDL_ITexture* image, const LDL_Vec2u& dstPos, const LDL_Vec2u& srcPos, const LDL_Vec2u& srcSize)
{
	Draw(image, dstPos, image->Size(), srcPos, srcSize);
}

void RenderImplOpenGL3::Draw(LDL_ITexture* image, const LDL_Vec2u& dstPos, const LDL_Vec2u& dstSize, const LDL_Vec2u& srcPos, const LDL_Vec2u& srcSize)
{
	LDL_UNUSED(dstPos);
	LDL_UNUSED(dstSize);
	LDL_UNUSED(srcPos);
	LDL_UNUSED(srcSize);

	_texturePainter.Draw(_projection, image);
}

void RenderImplOpenGL3::Draw(LDL_ISpriteBatcher* textureBatcher)
{
	LDL_UNUSED(textureBatcher);
}
