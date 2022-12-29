#include "GpuUtil.hpp"
#include <LDL/OpenGL/OpenGL1_0.hpp>
#include <iostream>
#include <LDL/Core/IntegerToString.hpp>

using namespace LDL::Graphics;

void GpuUtil::DrawQuad(const Point2u& pos, const Point2u& size)
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

void GpuUtil::DrawQuad(const Point2u& dstPos, const Point2u& dstSize, const Point2u& srcPos, const Point2u& srcSize)
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

void GpuUtil::Normalize(const Color& color, GLclampf& r, GLclampf& g, GLclampf& b)
{
	 r = color.Red() / 255.0f;
	 g = color.Green() / 255.0f;
	 b = color.Blue() / 255.0f;
}

void GpuUtil::Check(const std::string& file, size_t line, const std::string& expression)
{
    GLenum code = glGetError();

	std::string error;

    if (code != GL_NO_ERROR)
    { 
		if (code == GL_INVALID_ENUM)
			error = "GL_INVALID_ENUM";
		else if (code == GL_INVALID_VALUE)
			error = "GL_INVALID_VALUE";
		else if (code == GL_INVALID_OPERATION)
			error = "GL_INVALID_OPERATION";
		else if (code == GL_STACK_OVERFLOW)
			error = "GL_STACK_OVERFLOW";
		else if (code == GL_STACK_UNDERFLOW)
			error = "GL_STACK_UNDERFLOW";
		else if (code == GL_OUT_OF_MEMORY)
			error = "GL_OUT_OF_MEMORY";
		else
			error = "Unknown error";

		LDL::Core::IntegerToString conv;

		std::cout << "OpenGL error: " << error << " File: " << file << " Line: " << conv.Convert(line) << " Detail: " << expression << '\n';
		
		abort();
    }
}