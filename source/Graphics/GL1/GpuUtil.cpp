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
