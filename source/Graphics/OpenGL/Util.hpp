#ifndef LDL_Graphics_OpenGL_Util_hpp
#define LDL_Graphics_OpenGL_Util_hpp

#include <LDL/Graphics/Primitives/Point2u.hpp>
#include <LDL/Graphics/Primitives/Color.hpp>
#include <LDL/OpenGL/OpenGL1_1.hpp>
#include <string>

namespace LDL
{
	namespace Graphics
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
			void DrawQuad(const Point2u& dstPos, const Point2u& dstSize, const Point2u& srcPos, const Point2u& srcSize, size_t textureSize);
			void Normalize(const Color& color, GLclampf& r, GLclampf& g, GLclampf& b);
			void Check(const std::string& file, size_t line, const std::string& expression);
			size_t MaxTextureSize();
			bool IsMaxTextureSize(const Point2u& resolutionSize, size_t textureSize);
			size_t SelectTextureSize(const Point2u& size);
		}
	}
}

#define GL_CHECK(expr)                                         \
    do                                                         \
    {                                                          \
        expr;                                                  \
        LDL::Graphics::Util::Check(__FILE__, __LINE__, #expr); \
    } while (false)                                           

#endif