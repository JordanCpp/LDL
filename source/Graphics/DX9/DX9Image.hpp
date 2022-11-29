#ifndef LDL_Graphics_DX9Image_hpp
#define LDL_Graphics_DX9Image_hpp

#include <LDL/Graphics/IGpuImage.hpp>
#include <LDL/Graphics/Primitives/Point2u.hpp>

namespace LDL
{
	namespace Graphics
	{
		class DX9Image: public LDL::Graphics::IGpuImage
		{
		public:
			DX9Image(const LDL::Graphics::Point2u & size, size_t bytesPerPixel, uint8_t* pixels);
			~DX9Image();
			const LDL::Graphics::Point2u& Size();
		private:
			LDL::Graphics::Point2u _Size;
		};
	}
}

#endif    