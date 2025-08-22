// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include "Util.hpp"
#include <LDL/APIs/OpenGL/OpenGL1_0.hpp>
#include <LDL/Core/Convert.hpp>
#include <LDL/Core/Assert.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;

const size_t TextureCount = 12;
const size_t TextureSizes[TextureCount] = { 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536 };

void Util::CalcQuad(Util::Quad& quad, uint16_t dstPosX, uint16_t dstPosY, uint16_t dstSizeX, uint16_t dstSizeY, uint16_t srcPosX, uint16_t srcPosY, uint16_t srcSizeX, uint16_t srcSizeY, size_t textureSize)
{
	float ps = 1.0f / (float)textureSize;

	quad.data[0] = dstPosX;
	quad.data[1] = float(dstSizeY + dstPosY);
	quad.data[2] = 0.0f;
	quad.data[3] = ps * srcPosX;
	quad.data[4] = ps * (srcSizeY + srcPosY);

	quad.data[5] = float(dstSizeX + dstPosX);
	quad.data[6] = float(dstSizeY + dstPosY);
	quad.data[7] = 0.0f;
	quad.data[8] = ps * (srcSizeX + srcPosX);
	quad.data[9] = ps * (srcSizeY + srcPosY);

	quad.data[10] = dstPosX;
	quad.data[11] = dstPosY;
	quad.data[12] = 0.0f;
	quad.data[13] = ps * srcPosX;
	quad.data[14] = ps * srcPosY;

	quad.data[15] = float(dstSizeX + dstPosX);
	quad.data[16] = float(dstSizeY + dstPosY);
	quad.data[17] = 0.0f;
	quad.data[18] = ps * (srcSizeX + srcPosX);
	quad.data[19] = ps * (srcSizeY + srcPosY);

	quad.data[20] = float(dstSizeX + dstPosX);
	quad.data[21] = dstPosY;
	quad.data[22] = 0.0f;
	quad.data[23] = ps * (srcSizeX + srcPosX);
	quad.data[24] = ps * srcPosY;

	quad.data[25] = dstPosX;
	quad.data[26] = dstPosY;
	quad.data[27] = 0.0f;
	quad.data[28] = ps * srcPosX;
	quad.data[29] = ps * srcPosY;
}

GLuint Util::CreateTexture(GLsizei width, GLsizei heigth, GLint format)
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

void Util::DeleteTexture(GLint id)
{
	GL_CHECK(glDeleteTextures(0, (GLuint*)&id));
}

void Util::DrawQuad(const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize, size_t textureSize)
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

void Util::Normalize(const Color& color, GLclampf& r, GLclampf& g, GLclampf& b)
{
	 r = color.r / 255.0f;
	 g = color.g / 255.0f;
	 b = color.b / 255.0f;
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

		LDL::Core::Convert conv;

		LDL_ASSERT_DETAIL(code == GL_NO_ERROR, "OpenGL error: " + error + " File: " + file + " Line: " + conv.ToString(line) + " Detail: " + expression);
    }
}

size_t Util::MaxTextureSize()
{
	GLint result = 0;

	GL_CHECK(glGetIntegerv(GL_MAX_TEXTURE_SIZE, &result));

	return result;
}

bool Util::IsMaxTextureSize(const Vec2u& resolutionSize, size_t textureSize)
{
	if (textureSize >= resolutionSize.x && textureSize >= resolutionSize.y)
	{
		return true;
	}

	return false;
}

size_t Util::SelectTextureSize(const Vec2u& size)
{
	size_t w = size.x;
	size_t h = size.y;

	for (size_t i = 0; i < TextureCount; i++)
	{
		if (w <= TextureSizes[i] && h <= TextureSizes[i])
		{
			return TextureSizes[i];
		}
	}
	
	return 0;
}
