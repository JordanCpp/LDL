#include <LDL/Renders/GL1Rndr.hpp>
#include <LDL/Funcs.hpp>

void LDL_Normalize(const LDL_Color& color, GLclampf& r, GLclampf& g, GLclampf& b)
{
	r = color.r / 255.0f;
	g = color.g / 255.0f;
	b = color.b / 255.0f;
}

LDL_Render::LDL_Render(LDL_Window* window, LDL_Palette* palette) :
	_Window(window),
	_BaseRender(_Window->Size(), palette),
	_OpenGLLoader(1, 2)
{
}

void LDL_Render::Begin()
{
	LDL_Vec2i size = _Window->Size();

	LDL_GL_CHECK(glViewport(0, 0, (GLsizei)size.x, (GLsizei)size.y));

	_Projection = LDL_Ortho(0.0f, (float)size.x, (float)size.y, 0.0f, -1.0f, 1.0f);
	LDL_GL_CHECK(glMatrixMode(GL_PROJECTION));
	LDL_GL_CHECK(glLoadMatrixf(_Projection.Values()));

	LDL_GL_CHECK(glMatrixMode(GL_MODELVIEW));
	LDL_GL_CHECK(glLoadMatrixf(_ModelView.Values()));
}

void LDL_Render::End()
{
	_Window->Present();
}

void LDL_Render::Line(const LDL_Vec2i& pos1, const LDL_Vec2i& pos2)
{
	GLclampf r;
	GLclampf g;
	GLclampf b;

	LDL_Normalize(_BaseRender.Color(), r, g, b);

	glBegin(GL_LINES);
	glColor3f(r, g, b);
	glVertex2i(pos1.x, pos1.y);
	glVertex2i(pos2.x, pos2.y);
	glEnd();
}

void LDL_Render::Fill(const LDL_Vec2i& pos, const LDL_Vec2i& size)
{
	GLclampf r;
	GLclampf g;
	GLclampf b;

	LDL_Normalize(_BaseRender.Color(), r, g, b);
	glColor3f(r, g, b);

	GLint x = (GLint)pos.x;
	GLint y = (GLint)pos.y;
	GLint w = (GLint)size.x;
	GLint h = (GLint)size.y;

	glBegin(GL_QUADS);
	glVertex2i(x, y + h);
	glVertex2i(x, y);
	glVertex2i(x + w, y);
	glVertex2i(x + w, y + h);
	glEnd();
}

void LDL_Render::SetColor(const LDL_Color& color)
{
	_BaseRender.SetColor(color);
}

void LDL_Render::Clear()
{
	GLclampf r;
	GLclampf g;
	GLclampf b;

	LDL_Normalize(_BaseRender.Color(), r, g, b);

	glClearColor(r, g, b, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}