#include "RenderImplOpenGL3.hpp"
#include "../OpenGL/Util.hpp"
#include "TextureImplOpenGL3.hpp"
#include <LDL/Math/Funcs.hpp>

#if defined(_WIN32)
#include "../source/Platforms/Windows/Graphics/OpenGL3/WindowImplOpenGL3.hpp"
#elif defined(__unix__)
#include "../source/Platforms/Linux/Graphics/OpenGL3/WindowImplOpenGL3.hpp"
#endif

using namespace LDL::Graphics;
using namespace LDL::Math;

RenderImplOpenGL3::RenderImplOpenGL3(RenderContextImpl* renderContextImpl, Window* window) :
	_Window(window),
	_Screen(_Window->Size()),
	_LinePainter(&_ShaderLoader),
	_TexturePainter(&_ShaderLoader)
{
}

void LDL::Graphics::RenderImplOpenGL3::Buffer(uint8_t* dst)
{
}

void RenderImplOpenGL3::Begin()
{
	glViewport(0, 0, (GLsizei)_Window->Size().x, (GLsizei)_Window->Size().y);

	projection = Ortho(0.0f, (float)_Window->Size().x, (float)_Window->Size().y, 0.0f, 0.0f, 1.0f);
}

void RenderImplOpenGL3::End()
{
	_Window->GetWindowImpl()->Present();
}

const Vec2u& RenderImplOpenGL3::Size()
{
	return _Window->Size();
}

const Color& RenderImplOpenGL3::Color()
{
	return _Color;
}

void RenderImplOpenGL3::Clear()
{
	GLclampf r;
	GLclampf g;
	GLclampf b;

	Util::Normalize(_Color, r, g, b);

	GL_CHECK(glClearColor(r, g, b, 1.0f));
	GL_CHECK(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}

void RenderImplOpenGL3::Color(const LDL::Graphics::Color& color)
{
	_Color = color;
}

void RenderImplOpenGL3::Pixel(const Vec2u& pos)
{
}

void RenderImplOpenGL3::Line(const Vec2u& pos1, const Vec2u& pos2)
{
	GLclampf r;
	GLclampf g;
	GLclampf b;

	Util::Normalize(_Color, r, g, b);

	_LinePainter.Draw(projection, Vec3f((float)pos1.x, (float)pos1.y, 0), Vec3f((float)pos2.x, (float)pos2.y, 0), Vec3f((float)r, (float)g, (float)b));
}

void RenderImplOpenGL3::Fill(const Vec2u& pos, const Vec2u& size)
{
}

void RenderImplOpenGL3::Draw(Texture* image, const Vec2u& pos, const Vec2u& size)
{
	_TexturePainter.Draw(projection, image);
}

void RenderImplOpenGL3::Draw(Texture* image, const Vec2u& pos)
{
	Draw(image, pos, image->Size());
}

void RenderImplOpenGL3::Draw(Surface* image, const Vec2u& pos, const Vec2u& size)
{
	_Screen.Draw(image, pos, size);
}

void RenderImplOpenGL3::Draw(Surface* image, const Vec2u& dstPos, const Vec2u& srcPos, const Vec2u& srcSize)
{
}

void RenderImplOpenGL3::Draw(Surface* image, const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize)
{
}

void RenderImplOpenGL3::Draw(Surface* image, const Vec2u& pos)
{
	_Screen.Draw(image, pos);
}

void RenderImplOpenGL3::Draw(Texture* image, const Vec2u& dstPos, const Vec2u& srcPos, const Vec2u& srcSize)
{
}

void RenderImplOpenGL3::Draw(Texture* image, const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize)
{
}

void RenderImplOpenGL3::Draw(TextureBatcher* textureBatcher)
{

}