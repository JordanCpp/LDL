#include "OpenGL.hpp"
#include <LDL/OpenGL/OpenGL1_1.hpp>
#include <LDL/Low/String.hpp>
#include <LDL/Low/Conv.hpp>
#include <LDL/Low/Errors.hpp>

void GLCheck(const char* file, size_t line, const char* expression)
{
	GLenum code = glGetError();

	LDL_String error = "OpenGL error: ";

	if (code != GL_NO_ERROR)
	{
		switch (code)
		{
		case GL_INVALID_ENUM:
			error.Append("GL_INVALID_ENUM");
			break;
		case GL_INVALID_VALUE:
			error.Append("GL_INVALID_VALUE");
			break;
		case GL_INVALID_OPERATION:
			error.Append("GL_INVALID_OPERATION");
			break;
		case GL_STACK_OVERFLOW:
			error.Append("GL_STACK_OVERFLOW");
			break;
		case GL_STACK_UNDERFLOW:
			error.Append("GL_STACK_UNDERFLOW");
			break;
		case GL_OUT_OF_MEMORY:
			error.Append("GL_OUT_OF_MEMORY");
			break;
		default:
			error.Append("Unknown error");
		}

		LDL_NumberToString conv;

		error.Append(" File: ");
		error.Append(file);

		error.Append(" Line: ");
		error.Append(conv.Convert(line));

		error.Append(" Detail: ");
		error.Append(expression);

		LDL_Alert(error.CStr());
	}
}

void GLNormalize(const LDL_Color& color, GLclampf& r, GLclampf& g, GLclampf& b)
{
	r = color.r / 255.0f;
	g = color.g / 255.0f;
	b = color.b / 255.0f;
}

GLuint GLCreateTexture(GLsizei width, GLsizei heigth, GLint format)
{
	GLuint result = 0;

	GL_CHECK(glGenTextures(1, (GLuint*)&result));

	GL_CHECK(glEnable(GL_TEXTURE_2D));

	GL_CHECK(glBindTexture(GL_TEXTURE_2D, (GLuint)result));

	GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
	GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));

	GL_CHECK(glTexImage2D(GL_TEXTURE_2D, 0, format, width, heigth, 0, format, GL_UNSIGNED_BYTE, NULL));

	GL_CHECK(glDisable(GL_TEXTURE_2D));

	return result;
}

void GLDeleteTexture(GLint id)
{
	GL_CHECK(glDeleteTextures(0, (GLuint*)&id));
}
