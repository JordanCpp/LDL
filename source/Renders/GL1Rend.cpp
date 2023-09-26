#include "GL1Rend.hpp"
#include "OpenGL.hpp"
#include <LDL/OpenGL/OpenGL1_2.hpp>
#include "GL1Texture.hpp"

#if defined(_WIN32)
#include "../WinGL/GL1Win.hpp"
#elif defined(__unix__)
#include "../Linux/GL1Win.hpp"
#endif
#include <LDL/Low/Assert.hpp>

LDL_GL1Render::LDL_GL1Render(LDL_IRenderContext* context, LDL_IWindow* window) :
	_RenderContext(context),
	_Window(window)
{
	Begin();

	GL_CHECK(glEnable(GL_BLEND));
	GL_CHECK(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
}

LDL_GL1Render::~LDL_GL1Render()
{
}

void LDL_GL1Render::SetColor(const LDL_Color& color)
{
	_Color = color;
}

void LDL_GL1Render::Line(const LDL_Point2u& first, const LDL_Point2u& last)
{
	GLclampf r = 0;
	GLclampf g = 0;
	GLclampf b = 0;

	GLNormalize(_Color, r, g, b);

	glBegin(GL_LINES);
	glColor3f(r, g, b);
	glVertex2i((GLint)first.x, (GLint)first.y);
	glVertex2i((GLint)last.x, (GLint)last.y);
	glEnd();
}

void LDL_GL1Render::Fill(const LDL_Point2u& pos, const LDL_Point2u& size)
{
	GLclampf r = 0;
	GLclampf g = 0;
	GLclampf b = 0;

	GLNormalize(_Color, r, g, b);

	GLint x = (GLint)pos.x;
	GLint y = (GLint)pos.y;
	GLint w = (GLint)size.x;
	GLint h = (GLint)size.y;

	glBegin(GL_QUADS);
	glColor3f(r, g, b);
	glVertex2i(x, y + h);
	glVertex2i(x, y);
	glVertex2i(x + w, y);
	glVertex2i(x + w, y + h);
	glEnd();
}

void LDL_GL1Render::Clear()
{
	GLclampf r = 0;
	GLclampf g = 0;
	GLclampf b = 0;

	GLNormalize(_Color, r, g, b);

	GL_CHECK(glClearColor(r, g, b, 1.0f));
	GL_CHECK(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
}

void LDL_GL1Render::Begin()
{
	LDL_Point2u size = _Window->Size();

	GL_CHECK(glViewport(0, 0, (GLsizei)size.x, (GLsizei)size.y));

	_Projection = LDL_Orthof(0.0f, (float)size.x, (float)size.y, 0.0f, 0.0f, 1.0f);
	GL_CHECK(glMatrixMode(GL_PROJECTION));
	GL_CHECK(glLoadMatrixf(_Projection.Values()));

	GL_CHECK(glMatrixMode(GL_MODELVIEW));
	GL_CHECK(glLoadMatrixf(_ModelView.Values()));
}

void LDL_GL1Render::End()
{
	_ModelView.Identity();

	LDL_GL1Window* p = (LDL_GL1Window*)_Window;

	p->Present();
}

void LDL_GL1Render::Draw(LDL_ISurface* surface, const LDL_Point2u& pos)
{
}

void LDL_GL1Render::Draw(LDL_ITexture* texture, const LDL_Point2u& pos)
{
	LDL_ASSERT(texture != NULL);

	GL_CHECK(glEnable(GL_TEXTURE_2D));

	LDL_GL1Texture* p = (LDL_GL1Texture*)texture;

	GL_CHECK(glBindTexture(GL_TEXTURE_2D, (GLuint)p->Id()));

	GLDrawQuad(pos, texture->Size(), LDL_Point2u(0, 0), texture->Size(), texture->Quad().x);

	GL_CHECK(glDisable(GL_TEXTURE_2D));
}
