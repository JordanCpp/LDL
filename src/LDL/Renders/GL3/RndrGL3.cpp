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
    #include <LDL/Linux/WinGL3.hpp>
#endif

LDL_RenderOpenGL3::LDL_RenderOpenGL3(LDL_Result& result, LDL_RenderContext* renderContextImpl, LDL_IWindow* window) :
	_result(result),
	_window(window),
	_linePainter(&_shaderLoader),
	_texturePainter(&_shaderLoader)
{
	LDL_UNUSED(renderContextImpl);
}

void LDL_RenderOpenGL3::Buffer(uint8_t* dst)
{
	LDL_UNUSED(dst);
}

void LDL_RenderOpenGL3::Begin()
{
	glViewport(0, 0, (GLsizei)_window->Size().x, (GLsizei)_window->Size().y);

	_projection = LDL_Ortho(0.0f, (float)_window->Size().x, (float)_window->Size().y, 0.0f, 0.0f, 1.0f);
}

void LDL_RenderOpenGL3::End()
{
	_window->Present();
}

const LDL_Vec2u& LDL_RenderOpenGL3::Size()
{
	return _window->Size();
}

const LDL_Color& LDL_RenderOpenGL3::GetColor()
{
	return _color;
}

void LDL_RenderOpenGL3::Clear()
{
	GLclampf r;
	GLclampf g;
	GLclampf b;

	Normalize(_color, r, g, b);

	GL_CHECK(glClearColor(r, g, b, 1.0f));
	GL_CHECK(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}

void LDL_RenderOpenGL3::SetColor(const LDL_Color& color)
{
	_color = color;
}

void LDL_RenderOpenGL3::Pixel(const LDL_Vec2u& pos)
{
	LDL_UNUSED(pos);
}

void LDL_RenderOpenGL3::Line(const LDL_Vec2u& pos1, const LDL_Vec2u& pos2)
{
	GLclampf r;
	GLclampf g;
	GLclampf b;

	Normalize(_color, r, g, b);

	_linePainter.Draw(_projection, LDL_Vec3f((float)pos1.x, (float)pos1.y, 0), LDL_Vec3f((float)pos2.x, (float)pos2.y, 0), LDL_Vec3f((float)r, (float)g, (float)b));
}

void LDL_RenderOpenGL3::Fill(const LDL_Vec2u& pos, const LDL_Vec2u& size)
{
	LDL_UNUSED(pos);
	LDL_UNUSED(size);
}

void LDL_RenderOpenGL3::Draw(LDL_Surface* image, const LDL_Vec2u& pos)
{
	Draw(image, pos, image->Size(), LDL_Vec2u(0,0), image->Size());
}

void LDL_RenderOpenGL3::Draw(LDL_Surface* image, const LDL_Vec2u& pos, const LDL_Vec2u& size)
{
	Draw(image, pos, size, LDL_Vec2u(0, 0), image->Size());
}

void LDL_RenderOpenGL3::Draw(LDL_Surface* image, const LDL_Vec2u& dstPos, const LDL_Vec2u& srcPos, const LDL_Vec2u& srcSize)
{
	Draw(image, dstPos, image->Size(), srcPos, srcSize);
}

void LDL_RenderOpenGL3::Draw(LDL_Surface* image, const LDL_Vec2u& dstPos, const LDL_Vec2u& dstSize, const LDL_Vec2u& srcPos, const LDL_Vec2u& srcSize)
{
	LDL_UNUSED(image);
	LDL_UNUSED(dstPos);
	LDL_UNUSED(dstSize);
	LDL_UNUSED(srcPos);
	LDL_UNUSED(srcSize);
}

void LDL_RenderOpenGL3::Draw(LDL_ITexture* image, const LDL_Vec2u& pos)
{
	Draw(image, pos, image->Size(), LDL_Vec2u(0,0), image->Size());
}

void LDL_RenderOpenGL3::Draw(LDL_ITexture* image, const LDL_Vec2u& pos, const LDL_Vec2u& size)
{
	Draw(image, pos, size, LDL_Vec2u(0, 0), image->Size());
}

void LDL_RenderOpenGL3::Draw(LDL_ITexture* image, const LDL_Vec2u& dstPos, const LDL_Vec2u& srcPos, const LDL_Vec2u& srcSize)
{
	Draw(image, dstPos, image->Size(), srcPos, srcSize);
}

void LDL_RenderOpenGL3::Draw(LDL_ITexture* image, const LDL_Vec2u& dstPos, const LDL_Vec2u& dstSize, const LDL_Vec2u& srcPos, const LDL_Vec2u& srcSize)
{
	LDL_UNUSED(dstPos);
	LDL_UNUSED(dstSize);
	LDL_UNUSED(srcPos);
	LDL_UNUSED(srcSize);

	_texturePainter.Draw(_projection, image);
}

void LDL_RenderOpenGL3::Draw(LDL_ISpriteBatcher* textureBatcher)
{
	LDL_UNUSED(textureBatcher);
}
