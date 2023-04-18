#include "RenderImpl.hpp"
#include "Util.hpp"
#include "TextureImpl.hpp"
#include <LDL/Math/Funcs.hpp>
#include "../../Platforms/Windows/Graphics/OpenGL3/WindowImpl.hpp"

using namespace LDL::Graphics;
using namespace LDL::Math;

RenderImpl::RenderImpl(RenderContextImpl* renderContextImpl, Window* window) :
	_Window(window),
	_Screen(_Window->Size()),
	_LinePainter(&_ShaderLoader),
	_TexturePainter(&_ShaderLoader)
{
}

void LDL::Graphics::RenderImpl::Buffer(uint8_t* dst)
{
}

void RenderImpl::Begin()
{
	glViewport(0, 0, (GLsizei)_Window->Size().PosX(), (GLsizei)_Window->Size().PosY());

	projection = Ortho(0.0f, (float)_Window->Size().PosX(), (float)_Window->Size().PosY(), 0.0f, 0.0f, 1.0f);
}

void RenderImpl::End()
{
	_Window->GetWindowImpl()->Present();
}

const Point2u& RenderImpl::Size()
{
	return _Window->Size();
}

const Color& RenderImpl::Color()
{
	return _Color;
}

void RenderImpl::Clear()
{
	GLclampf r;
	GLclampf g;
	GLclampf b;

	Util::Normalize(_Color, r, g, b);

	GL_CHECK(glClearColor(r, g, b, 1.0f));
	GL_CHECK(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}

void RenderImpl::Color(const LDL::Graphics::Color& color)
{
	_Color = color;
}

void RenderImpl::Pixel(const Point2u& pos)
{
}

void RenderImpl::Line(const Point2u& pos1, const Point2u& pos2)
{
	GLclampf r;
	GLclampf g;
	GLclampf b;

	Util::Normalize(_Color, r, g, b);

	_LinePainter.Draw(projection, Vec3f((float)pos1.PosX(), (float)pos1.PosY(), 0), Vec3f((float)pos2.PosX(), (float)pos2.PosY(), 0), Vec3f((float)r, (float)g, (float)b));
}

void RenderImpl::Fill(const Point2u& pos, const Point2u& size)
{
}

void RenderImpl::Draw(Texture* image, const Point2u& pos, const Point2u& size)
{
}

void RenderImpl::Draw(Texture* image, const Point2u& pos)
{
	Draw(image, pos, image->Size());
}

void RenderImpl::Draw(Surface* image, const Point2u& pos, const Point2u& size)
{
	_Screen.Draw(image, pos, size);
}

void RenderImpl::Draw(Surface* image, const Point2u& pos)
{
	_Screen.Draw(image, pos);
}

void RenderImpl::Draw(Texture* image, const Point2u& dstPos, const Point2u& srcPos, const Point2u& srcSize)
{
}