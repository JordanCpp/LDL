#include "GpuUtil.hpp"
#include "OpenGL.hpp"

void LDL::Graphics::GpuUtil::DrawQuad(const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size)
{
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

void LDL::Graphics::GpuUtil::DrawQuad(const LDL::Graphics::Point2u& dstPos, const LDL::Graphics::Point2u& dstSize, const LDL::Graphics::Point2u& srcPos, const LDL::Graphics::Point2u& srcSize)
{
	GLint x = (GLint)dstPos.PosX();
	GLint y = (GLint)dstPos.PosY();
	GLint w = (GLint)dstSize.PosX();
	GLint h = (GLint)dstSize.PosY();

	GLint cx = (GLint)srcPos.PosX();
	GLint cy = (GLint)srcPos.PosY();
	GLint cw = (GLint)srcSize.PosX();
	GLint ch = (GLint)srcSize.PosY();

	GLfloat dcx = GLfloat(cx) / GLfloat(w);
	GLfloat dcy = GLfloat(cy) / GLfloat(h);

	GLfloat dcw = (GLfloat(cx) + GLfloat(cw)) / GLfloat(w);
	GLfloat dch = (GLfloat(cy) + GLfloat(ch)) / GLfloat(h);

	glBegin(GL_QUADS);

	glTexCoord2f(dcx, dcy); glVertex2f(x, y);
	glTexCoord2f(dcw, dcy); glVertex2f(x + cw, y);
	glTexCoord2f(dcw, dch); glVertex2f(x + cw, y + ch);
	glTexCoord2f(dcx, dch); glVertex2f(x, y + ch);

	glEnd();
}