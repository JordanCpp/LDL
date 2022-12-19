#ifndef LDL_Graphics_GpuUtil_hpp
#define LDL_Graphics_GpuUtil_hpp

#include <LDL/Graphics/Primitives/Point2u.hpp>
#include <LDL/Graphics/Primitives/Color.hpp>
#include "OpenGL.hpp"

namespace LDL
{
	namespace Graphics
	{
		namespace GpuUtil
		{
			void DrawQuad(const Point2u& pos, const Point2u& size);
			void DrawQuad(const Point2u& dstPos, const Point2u& dstSize, const Point2u& srcPos, const Point2u& srcSize);
			void Normalize(const Color& color, GLclampf& r, GLclampf& g, GLclampf& b);
		}
	}
}

#endif