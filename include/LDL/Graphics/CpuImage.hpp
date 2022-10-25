#ifndef LDL_Graphics_CpuImage_hpp
#define LDL_Graphics_CpuImage_hpp

#include <LDL/Graphics/Primitives/Point2u.hpp>

namespace LDL
{
	namespace Graphics
	{
		class CpuImage
		{
		public:
			CpuImage();
			const LDL::Graphics::Point2u& Size();
			size_t BytesPerPixel();
			uint8_t* Pixels();
		private:
			LDL::Graphics::Point2u _Size;
			size_t _BytesPerPixel;
			uint8_t* _Pixels;
		};
	}
}

#endif 