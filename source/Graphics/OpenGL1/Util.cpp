#include "Util.hpp"
#include <LDL/OpenGL/OpenGL1_0.hpp>
#include <LDL/Core/NumberToString.hpp>
#include <LDL/Core/RuntimeError.hpp>

using namespace LDL::Graphics;

const size_t TextureCount = 12;
const size_t TextureSizes[TextureCount] = {32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536 };

void LDL::Graphics::Util::DrawQuad(const Point2u& pos, const Point2u& size)
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

void Util::DrawQuad(const Point2u& pos, const Point2u& size, const Point2u& srcSize, size_t textureSize)
{
	GLfloat x = (GLfloat)pos.PosX();
	GLfloat y = (GLfloat)pos.PosY();
	GLfloat w = (GLfloat)size.PosX();
	GLfloat h = (GLfloat)size.PosY();

	GLfloat dw = (GLfloat)srcSize.PosX() / (GLfloat)textureSize;
	GLfloat dh = (GLfloat)srcSize.PosY() / (GLfloat)textureSize;

	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex2f(x, y);
	glTexCoord2f(dw, 0); glVertex2f(x + w, y);
	glTexCoord2f(dw, dh); glVertex2f(x + w, y + h);
	glTexCoord2f(0, dh); glVertex2f(x, y + h);
	glEnd();
}

void Util::DrawQuad(const Point2u& dstPos, const Point2u& dstSize, const Point2u& srcPos, const Point2u& srcSize)
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

void Util::Normalize(const Color& color, GLclampf& r, GLclampf& g, GLclampf& b)
{
	 r = color.Red() / 255.0f;
	 g = color.Green() / 255.0f;
	 b = color.Blue() / 255.0f;
}

void Util::Check(const std::string& file, size_t line, const std::string& expression)
{
    GLenum code = glGetError();

	std::string error;

    if (code != GL_NO_ERROR)
    { 
		switch (code)
		{
		case GL_INVALID_ENUM:
			error = "GL_INVALID_ENUM";
			break;
		case GL_INVALID_VALUE:
			error = "GL_INVALID_VALUE";
			break;
		case GL_INVALID_OPERATION:
			error = "GL_INVALID_OPERATION";
			break;
		case GL_STACK_OVERFLOW:
			error = "GL_STACK_OVERFLOW";
			break;
		case GL_STACK_UNDERFLOW:
			error = "GL_STACK_UNDERFLOW";
			break;
		case GL_OUT_OF_MEMORY:
			error = "GL_OUT_OF_MEMORY";
			break;
		default:
			error = "Unknown error";
		}

		LDL::Core::NumberToString conv;

		throw LDL::Core::RuntimeError("OpenGL error: " + error + " File: " + file + " Line: " + conv.Convert(line) + " Detail: " + expression);
    }
}

size_t Util::MaxTextureSize()
{
	GLint result = 0;

	GL_CHECK(glGetIntegerv(GL_MAX_TEXTURE_SIZE, &result));

	return result;
}

bool Util::IsMaxTextureSize(const Point2u& resolutionSize, size_t textureSize)
{
	if (textureSize >= resolutionSize.PosX() && textureSize >= resolutionSize.PosY())
		return true;

	return false;
}

size_t Util::SelectTextureSize(const Point2u& size)
{
	size_t w = size.PosX();
	size_t h = size.PosY();

	for (size_t i = 0; i < TextureCount; i++)
	{
		if (w <= TextureSizes[i] && h <= TextureSizes[i])
			return TextureSizes[i];
	}
	
	return 0;
}