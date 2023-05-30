#ifndef LDL_Graphics_OpenGL3_Util_hpp
#define LDL_Graphics_OpenGL3_Util_hpp

#include <LDL/Math/Vec2.hpp>
#include <LDL/Graphics/Color.hpp>
#include <LDL/OpenGL/OpenGL1_0.hpp>
#include <string>

namespace LDL
{
	namespace Graphics
	{
		namespace Util
		{
			void DrawQuad(const Math::Vec2u& pos, const Math::Vec2u& size);
			void DrawQuad(const Math::Vec2u& pos, const Math::Vec2u& size, const Math::Vec2u& srcSize, size_t textureSize);
			void DrawQuad(const Math::Vec2u& dstPos, const Math::Vec2u& dstSize, const Math::Vec2u& srcPos, const Math::Vec2u& srcSize);
			void Normalize(const Color& color, GLclampf& r, GLclampf& g, GLclampf& b);
			void Check(const std::string& file, size_t line, const std::string& expression);
			size_t MaxTextureSize();
			bool IsMaxTextureSize(const Math::Vec2u& resolutionSize, size_t textureSize);
			size_t SelectTextureSize(const Math::Vec2u& size);
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