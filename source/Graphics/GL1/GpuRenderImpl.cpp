#include "GpuRenderImpl.hpp"
#include "OpenGL.hpp"

LDL::Graphics::GpuRenderImpl::GpuRenderImpl(LDL::Graphics::GpuWindow* window) :
	_Window(window),
	_BaseRender(_Window->Size()),
	_Screen(_Window->Size())
{
}

void LDL::Graphics::GpuRenderImpl::Begin()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0f, (GLdouble)_Window->Size().PosX(), (GLdouble)_Window->Size().PosY(), 0.0f, 0.0f, 1.0f);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void LDL::Graphics::GpuRenderImpl::End()
{
	_Window->Present();
}

const LDL::Graphics::Point2u& LDL::Graphics::GpuRenderImpl::Size()
{
	return _BaseRender.Size();
}

const LDL::Graphics::Color& LDL::Graphics::GpuRenderImpl::Color()
{
	return _BaseRender.Color();
}

void LDL::Graphics::GpuRenderImpl::Clear()
{
	GLclampf r = _BaseRender.Color().Red() / 255.0f;
	GLclampf g = _BaseRender.Color().Green() / 255.0f;
	GLclampf b = _BaseRender.Color().Blue() / 255.0f;

	glClearColor(r, g, b, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void LDL::Graphics::GpuRenderImpl::Color(const LDL::Graphics::Color& color)
{
	_BaseRender.Color(color);
}

void LDL::Graphics::GpuRenderImpl::Pixel(const LDL::Graphics::Point2u& pos)
{
	GLclampf r = _BaseRender.Color().Red() / 255.0f;
	GLclampf g = _BaseRender.Color().Green() / 255.0f;
	GLclampf b = _BaseRender.Color().Blue() / 255.0f;

	glBegin(GL_POINTS);
	glColor3f(r, g, b);
	glVertex2i((GLint)pos.PosX(), (GLint)pos.PosY());
	glEnd();
}

void LDL::Graphics::GpuRenderImpl::Line(const LDL::Graphics::Point2u& pos1, const LDL::Graphics::Point2u& pos2)
{
	GLclampf r = _BaseRender.Color().Red() / 255.0f;
	GLclampf g = _BaseRender.Color().Green() / 255.0f;
	GLclampf b = _BaseRender.Color().Blue() / 255.0f;

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

void LDL::Graphics::GpuRenderImpl::Fill(const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size)
{
	GLclampf r = _BaseRender.Color().Red() / 255.0f;
	GLclampf g = _BaseRender.Color().Green() / 255.0f;
	GLclampf b = _BaseRender.Color().Blue() / 255.0f;

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

void LDL::Graphics::GpuRenderImpl::Draw(LDL::Graphics::GpuImage* image, const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size)
{
	glBindTexture(GL_TEXTURE_2D, (GLuint)image->Id());

	GLint x = (GLint)pos.PosX();
	GLint y = (GLint)pos.PosY();
	GLint w = (GLint)size.PosX();
	GLint h = (GLint)size.PosY();

	glBegin(GL_QUADS);
	glTexCoord2i(0, 1);
	glVertex2i(x, y + h);
	glTexCoord2i(0, 0);
	glVertex2i(x, y);
	glTexCoord2i(1, 0);
	glVertex2i(x + w, y);
	glTexCoord2i(1, 1);
	glVertex2i(x + w, y + h);
	glEnd();
}

void LDL::Graphics::GpuRenderImpl::Draw(LDL::Graphics::GpuImage* image, const LDL::Graphics::Point2u& pos)
{
	Draw(image, pos, image->Size());
}

void LDL::Graphics::GpuRenderImpl::Draw(LDL::Graphics::CpuImage* image, const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size)
{
	_Screen.Draw(image, pos, size);
}

void LDL::Graphics::GpuRenderImpl::Draw(LDL::Graphics::CpuImage* image, const LDL::Graphics::Point2u& pos)
{
	_Screen.Draw(image, pos);
}