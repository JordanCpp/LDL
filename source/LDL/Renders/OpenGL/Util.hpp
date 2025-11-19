// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_OpenGL_Util_hpp
#define LDL_Graphics_OpenGL_Util_hpp

#include <LDL/Vec2u.hpp>
#include <LDL/Types.hpp>
#include <LDL/Color.hpp>
#include <LDL/OpenGL/OpenGL1_1.hpp>

struct Quad
{
	float data[5 * 6];
};

void CalcQuad(Quad& quad, uint16_t dstPosX, uint16_t dstPosY, uint16_t dstSizeX, uint16_t dstSizeY, uint16_t srcPosX, uint16_t srcPosY, uint16_t srcSizeX, uint16_t srcSizeY, size_t textureSize);
GLuint CreateTexture(GLsizei width, GLsizei heigth, GLint format);
void DeleteTexture(GLint id);
void DrawQuad(const LDL_Vec2u& dstPos, const LDL_Vec2u& dstSize, const LDL_Vec2u& srcPos, const LDL_Vec2u& srcSize, size_t textureSize);
void Normalize(const LDL_Color& color, GLclampf& r, GLclampf& g, GLclampf& b);
void Check(const char* file, int line, const char* expression);
size_t MaxTextureSize();
bool IsMaxTextureSize(const LDL_Vec2u& resolutionSize, size_t textureSize);
uint32_t SelectTextureSize(const LDL_Vec2u& size);

#define GL_CHECK(expr)                    \
    do                                    \
    {                                     \
        expr;                             \
        Check(__FILE__, __LINE__, #expr); \
    } while (false)                                           

#endif
