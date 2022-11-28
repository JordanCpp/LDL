#ifndef LDL_Graphics_IGpuImage_hpp
#define LDL_Graphics_IGpuImage_hpp

#include <LDL/Graphics/Primitives/Point2u.hpp>

namespace LDL
{
	namespace Graphics
	{
		class IGpuImage
		{
		public:
			virtual const LDL::Graphics::Point2u& Size() = 0;
			virtual ~IGpuImage() {};
		};
	}
}

#endif    