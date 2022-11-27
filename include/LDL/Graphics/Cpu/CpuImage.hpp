#ifndef LDL_Graphics_Cpu_CpuImage_hpp
#define LDL_Graphics_Cpu_CpuImage_hpp

#include <LDL/Graphics/Primitives/Point2u.hpp>
#include <LDL/Graphics/Primitives/Color.hpp>
#include <LDL/Loaders/ImageLoader.hpp>
#include <string>

namespace LDL
{
	namespace Graphics
	{
		class CpuImage
		{
		public:
			CpuImage(LDL::Loaders::ImageLoader* imageLoader);
			CpuImage(const LDL::Graphics::Point2u& size, uint8_t bytesPerPixel);
			~CpuImage();
			const LDL::Graphics::Point2u& Size();
			uint8_t BytesPerPixel();
			uint8_t* Pixels();
			LDL::Graphics::Color Pixel(const LDL::Graphics::Point2u& pos);
		private:
			void Copy(LDL::Loaders::ImageLoader* imageLoader);
			LDL::Graphics::Point2u _Size;
			uint8_t _BytesPerPixel;
			uint8_t* _Pixels;
		};
	}
}

#endif 