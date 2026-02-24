// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_OpenGL_Util_hpp
#define LDL_Graphics_OpenGL_Util_hpp

#include <LDL/Math/Vec2.hpp>
#include <LDL/Graphics/Color.hpp>
#include <LDL/APIs/OpenGL/OpenGL1_1.hpp>
#include <string>

namespace LDL
{
	namespace Util
	{
		struct Quad
		{
			float data[5 * 6];
		};

		void CalcQuad(Util::Quad& quad, uint16_t dstPosX, uint16_t dstPosY, uint16_t dstSizeX, uint16_t dstSizeY, uint16_t srcPosX, uint16_t srcPosY, uint16_t srcSizeX, uint16_t srcSizeY, size_t textureSize);
		GLuint CreateTexture(GLsizei width, GLsizei heigth, GLint format);
		void DeleteTexture(GLint id);
		void DrawQuad(const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize, size_t textureSize);
		void Normalize(const Color& color, GLclampf& r, GLclampf& g, GLclampf& b);
		void Check(const char* file, size_t line, const char* expression);
		size_t MaxTextureSize();
		bool IsMaxTextureSize(const Vec2u& resolutionSize, size_t textureSize);
		size_t SelectTextureSize(const Vec2u& size);
	}
}

#define GL_CHECK(expr)                               \
    do                                               \
    {                                                \
        expr;                                        \
        LDL::Util::Check(__FILE__, __LINE__, #expr); \
    } while (false)                                           

#endif
