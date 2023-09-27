#include "OpenGL.hpp"
#include <LDL/OpenGL/OpenGL1_1.hpp>
#include <LDL/Low/String.hpp>
#include <LDL/Low/Conv.hpp>
#include <LDL/Low/Errors.hpp>

const size_t TextureCount = 12;
const size_t TextureSizes[TextureCount] = { 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536 };

void GLDrawQuad(const LDL_Vec2u& dstPos, const LDL_Vec2u& dstSize, const LDL_Vec2u& srcPos, const LDL_Vec2u& srcSize, size_t textureSize)
{
	GLfloat x = (GLfloat)dstPos.x;
	GLfloat y = (GLfloat)dstPos.y;
	GLfloat w = (GLfloat)dstSize.x;
	GLfloat h = (GLfloat)dstSize.y;

	GLfloat cx = (GLfloat)srcPos.x;
	GLfloat cy = (GLfloat)srcPos.y;
	GLfloat cw = (GLfloat)srcSize.x;
	GLfloat ch = (GLfloat)srcSize.y;

	GLfloat dcx = cx / textureSize;
	GLfloat dcy = cy / textureSize;

	GLfloat dcw = (cx + cw) / textureSize;
	GLfloat dch = (cy + ch) / textureSize;

	glBegin(GL_QUADS);
	glTexCoord2f(dcx, dcy); glVertex2f(x, y);
	glTexCoord2f(dcw, dcy); glVertex2f(x + cw + (w - cw), y);
	glTexCoord2f(dcw, dch); glVertex2f(x + cw + (w - cw), y + ch + (h - ch));
	glTexCoord2f(dcx, dch); glVertex2f(x, y + ch + (h - ch));
	glEnd();
}

size_t GLSelectTextureSize(const LDL_Vec2u& size)
{
	size_t w = size.x;
	size_t h = size.y;

	for (size_t i = 0; i < TextureCount; i++)
	{
		if (w <= TextureSizes[i] && h <= TextureSizes[i])
			return TextureSizes[i];
	}

	return 0;
}

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
