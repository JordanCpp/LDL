#include "GpuUtil.hpp"
#include "OpenGL.hpp"

void LDL::Graphics::GpuUtil::DrawQuad(const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size)
{
	GLfloat x = (GLfloat)pos.PosX();
	GLfloat y = (GLfloat)pos.PosY();
	GLfloat w = (GLfloat)size.PosX();
	GLfloat h = (GLfloat)size.PosY();

	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex2f(x, y);
	glTexCoord2f(1, 0); glVertex2f(x + w, y);
	glTexCoord2f(1, 1); glVertex2f(x + w, y + h);
	glTexCoord2f(0, 1); glVertex2f(x, y + h);
	glEnd();
}

void LDL::Graphics::GpuUtil::DrawQuad(const LDL::Graphics::Point2u& dstPos, const LDL::Graphics::Point2u& dstSize, const LDL::Graphics::Point2u& srcPos, const LDL::Graphics::Point2u& srcSize)
{
	GLfloat x = (GLfloat)dstPos.PosX();
	GLfloat y = (GLfloat)dstPos.PosY();
	GLfloat w = (GLfloat)dstSize.PosX();
	GLfloat h = (GLfloat)dstSize.PosY();

	GLfloat cx = (GLfloat)srcPos.PosX();
	GLfloat cy = (GLfloat)srcPos.PosY();
	GLfloat cw = (GLfloat)srcSize.PosX();
	GLfloat ch = (GLfloat)srcSize.PosY();

	GLfloat dcx = cx / w;
	GLfloat dcy = cy / h;

	GLfloat dcw = (cx + cw) / w;
	GLfloat dch = (cy + ch) / h;

	glBegin(GL_QUADS);
	glTexCoord2f(dcx, dcy); glVertex2f(x, y);
	glTexCoord2f(dcw, dcy); glVertex2f(x + cw, y);
	glTexCoord2f(dcw, dch); glVertex2f(x + cw, y + ch);
	glTexCoord2f(dcx, dch); glVertex2f(x, y + ch);
	glEnd();
}