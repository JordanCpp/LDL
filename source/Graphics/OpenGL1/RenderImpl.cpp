#include "RenderImpl.hpp"
#include "../OpenGL/Util.hpp"
#include "TextureImpl.hpp"

#include <LDL/Math/Funcs.hpp>
#include "../../Platforms/Windows/Graphics/OpenGL1/WindowImpl.hpp"

using namespace LDL::Graphics;
using namespace LDL::Math;

RenderImpl::RenderImpl(RenderContextImpl* renderContextImpl, Window* window) :
	_Window(window),
	_Screen(_Window->Size()),
	_RenderContextImpl(renderContextImpl)
{
	Begin();

	GL_CHECK(glEnable(GL_BLEND));
	GL_CHECK(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
}

void LDL::Graphics::RenderImpl::Buffer(uint8_t* dst)
{
	GL_CHECK(glReadPixels(0, 0, (GLsizei)_Window->Size().x, (GLsizei)_Window->Size().y, GL_RGBA, GL_UNSIGNED_BYTE, dst));
}

void RenderImpl::Begin()
{
	GL_CHECK(glViewport(0, 0, (GLsizei)_Window->Size().x, (GLsizei)_Window->Size().y));

	GL_CHECK(glMatrixMode(GL_PROJECTION));
	_Projection = Ortho(0.0f, (float)_Window->Size().x, (float)_Window->Size().y, 0.0f, 0.0f, 1.0f);
	GL_CHECK(glLoadMatrixf(_Projection.Values()));


	GL_CHECK(glMatrixMode(GL_MODELVIEW));
	GL_CHECK(glLoadMatrixf(_ModelView.Values()));
}

void RenderImpl::End()
{
	_ModelView.Identity();
	_RenderBuffer.Draw();

	_Window->GetWindowImpl()->Present();

	_RenderBuffer.Reset();
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
	GLclampf r;
	GLclampf g;
	GLclampf b;

	Util::Normalize(_Color, r, g, b);

	glBegin(GL_POINTS);
	glColor3f(r, g, b);
	glVertex2i((GLint)pos.x, (GLint)pos.y);
	glEnd();
}

void RenderImpl::Line(const Vec2u& pos1, const Vec2u& pos2)
{
	_RenderBuffer.Line(pos1, pos2, _Color);
}

void RenderImpl::Fill(const Vec2u& pos, const Vec2u& size)
{
	_RenderBuffer.Fill(pos, size, _Color);
}

void RenderImpl::Draw(Surface* image, const Vec2u& pos)
{
	_Screen.Draw(image, pos);
}

void RenderImpl::Draw(Surface* image, const Vec2u& pos, const Vec2u& size)
{
	_Screen.Draw(image, pos, size);
}

void RenderImpl::Draw(Texture* image, const Vec2u& pos)
{
	Draw(image, pos, image->Size(), Vec2u(0, 0), image->Size());
}

void RenderImpl::Draw(Texture* image, const Vec2u& pos, const Vec2u& size)
{
	Draw(image, pos, size, Vec2u(0, 0), image->Size());
}

void RenderImpl::Draw(Texture* image, const Vec2u& dstPos, const Vec2u& srcPos, const Vec2u& srcSize)
{
	Draw(image, dstPos, srcSize, srcPos, srcSize);
}

void RenderImpl::Draw(Texture* image, const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize)
{
	_RenderBuffer.Texture(dstPos, dstSize, srcPos, srcSize, image->GetTextureImpl()->Id(), image->GetTextureImpl()->Quad().x);
}

void RenderImpl::Draw(TextureBatcher* textureBatcher)
{
	TextureBatcherImpl* batcher = textureBatcher->GetTextureBatcherImpl();

	_RenderBuffer.TextureBatcher(batcher->TextureId(), batcher->Count(), batcher->Content());
}