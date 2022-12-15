#ifndef LDL_Graphics_GpuUtil_hpp
#define LDL_Graphics_GpuUtil_hpp

#include <LDL/Graphics/Primitives/Point2u.hpp>

namespace LDL
{
	namespace Graphics
	{
		namespace GpuUtil
		{
			void DrawQuad(const Point2u& pos, const Point2u& size);
			void DrawQuad(const Point2u& dstPos, const Point2u& dstSize, const Point2u& srcPos, const Point2u& srcSize);
		}
	}
}

#endif