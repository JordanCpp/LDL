#include "RenderImpl.hpp"
#include "Util.hpp"
#include "TextureImpl.hpp"
#include <LDL/Math/Mat4f.hpp>
#include <LDL/Math/Funcs.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;

RenderImpl::RenderImpl(RenderContextImpl* renderContextImpl, Window* window) :
	_Window(window),
	_Screen(_Window->Size())
{
	Begin();

	GL_CHECK(glEnable(GL_BLEND));
	GL_CHECK(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
}

void LDL::Graphics::RenderImpl::Buffer(uint8_t* dst)
{
	GL_CHECK(glReadPixels(0, 0, (GLsizei)_Window->Size().PosX(), (GLsizei)_Window->Size().PosY(), GL_RGBA, GL_UNSIGNED_BYTE, dst));
}

void RenderImpl::Begin()
{
	GL_CHECK(glViewport(0, 0, (GLsizei)_Window->Size().PosX(), (GLsizei)_Window->Size().PosY()));

	Mat4f projection;
	Mat4f modelView;

	GL_CHECK(glMatrixMode(GL_PROJECTION));
	projection = Ortho(0.0f, (float)_Window->Size().PosX(), (float)_Window->Size().PosY(), 0.0f, 0.0f, 1.0f);
	GL_CHECK(glLoadMatrixf(projection.Values()));

	GL_CHECK(glMatrixMode(GL_MODELVIEW));
	GL_CHECK(glLoadMatrixf(modelView.Values()));
}

void RenderImpl::End()
{
	_Window->Present(NULL, NULL);
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
	GLclampf r;
	GLclampf g;
	GLclampf b;

	Util::Normalize(_Color, r, g, b);

	glBegin(GL_POINTS);
	glColor3f(r, g, b);
	glVertex2i((GLint)pos.PosX(), (GLint)pos.PosY());
	glEnd();
}

void RenderImpl::Line(const Point2u& pos1, const Point2u& pos2)
{
	GLclampf r;
	GLclampf g;
	GLclampf b;

	Util::Normalize(_Color, r, g, b);

	GLint x1 = (GLint)pos1.PosX();
	GLint y1 = (GLint)pos1.PosY();
	GLint x2 = (GLint)pos2.PosX();
	GLint y2 = (GLint)pos2.PosY();

	glBegin(GL_LINES);
	glColor3f(r, g, b);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glEnd();
}

void RenderImpl::Fill(const Point2u& pos, const Point2u& size)
{
	GLclampf r;
	GLclampf g;
	GLclampf b;

	Util::Normalize(_Color, r, g, b);

	GLint x = (GLint)pos.PosX();
	GLint y = (GLint)pos.PosY();
	GLint w = (GLint)size.PosX();
	GLint h = (GLint)size.PosY();

	glBegin(GL_QUADS);
	glColor3f(r, g, b);
	glVertex2i(x, y + h);
	glVertex2i(x, y);
	glVertex2i(x + w, y);
	glVertex2i(x + w, y + h);
	glEnd();
}

void RenderImpl::Draw(Texture* image, const Point2u& pos, const Point2u& size)
{
	GL_CHECK(glEnable(GL_TEXTURE_2D));

	GL_CHECK(glBindTexture(GL_TEXTURE_2D, (GLuint)image->GetTextureImpl()->Id()));

	Util::DrawQuad(pos, size);

	GL_CHECK(glDisable(GL_TEXTURE_2D));
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
	GL_CHECK(glEnable(GL_TEXTURE_2D));

	GL_CHECK(glBindTexture(GL_TEXTURE_2D, (GLuint)image->GetTextureImpl()->Id()));

	Util::DrawQuad(dstPos, image->Size(), srcPos, srcSize);

	GL_CHECK(glDisable(GL_TEXTURE_2D));
}