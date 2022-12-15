#ifndef LDL_Graphics_GpuUtil_hpp
#define LDL_Graphics_GpuUtil_hpp

#include <LDL/Graphics/Primitives/Point2u.hpp>

namespace LDL
{
	namespace Graphics
	{
		namespace GpuUtil
		{
			void DrawQuad(const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size);
			void DrawQuad(const LDL::Graphics::Point2u& dstPos, const LDL::Graphics::Point2u& dstSize, const LDL::Graphics::Point2u& srcPos, const LDL::Graphics::Point2u& srcSize);
		}
	}
}

#endif