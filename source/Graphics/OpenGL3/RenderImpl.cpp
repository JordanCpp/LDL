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
	glViewport(0, 0, (GLsizei)_Window->Size().x, (GLsizei)_Window->Size().y);

	projection = Ortho(0.0f, (float)_Window->Size().x, (float)_Window->Size().y, 0.0f, 0.0f, 1.0f);
}

void RenderImpl::End()
{
	_Window->GetWindowImpl()->Present();
}

const Vec2u& RenderImpl::Size()
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

void RenderImpl::Pixel(const Vec2u& pos)
{
}

void RenderImpl::Line(const Vec2u& pos1, const Vec2u& pos2)
{
	GLclampf r;
	GLclampf g;
	GLclampf b;

	Util::Normalize(_Color, r, g, b);

	_LinePainter.Draw(projection, Vec3f((float)pos1.x, (float)pos1.y, 0), Vec3f((float)pos2.x, (float)pos2.y, 0), Vec3f((float)r, (float)g, (float)b));
}

void RenderImpl::Fill(const Vec2u& pos, const Vec2u& size)
{
}

void RenderImpl::Draw(Texture* image, const Vec2u& pos, const Vec2u& size)
{
	_TexturePainter.Draw(projection, image);
}

void RenderImpl::Draw(Texture* image, const Vec2u& pos)
{
	Draw(image, pos, image->Size());
}

void RenderImpl::Draw(Surface* image, const Vec2u& pos, const Vec2u& size)
{
	_Screen.Draw(image, pos, size);
}

void RenderImpl::Draw(Surface* image, const Vec2u& pos)
{
	_Screen.Draw(image, pos);
}

void RenderImpl::Draw(Texture* image, const Vec2u& dstPos, const Vec2u& srcPos, const Vec2u& srcSize)
{
}

void RenderImpl::Draw(Texture* image, const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize)
{
}

void RenderImpl::Draw(TextureBatcher* textureBatcher)
{

}