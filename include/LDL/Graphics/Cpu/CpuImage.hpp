#ifndef LDL_Graphics_Cpu_CpuImage_hpp
#define LDL_Graphics_Cpu_CpuImage_hpp

#include <LDL/Allocators/Allocator.hpp>
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
			CpuImage(LDL::Loaders::ImageLoader* imageLoader, LDL::Allocators::Allocator* allocator);
			CpuImage(LDL::Loaders::ImageLoader* imageLoader);
			CpuImage(const Point2u& size, uint8_t bytesPerPixel = 4);
			CpuImage(LDL::Allocators::Allocator* allocator, const Point2u& size, uint8_t bytesPerPixel = 4);
			~CpuImage();
			const Point2u& Size();
			uint8_t BytesPerPixel();
			uint8_t* Pixels();
			LDL::Allocators::Allocator* Allocator();
			Color Pixel(const Point2u& pos);
		private:
			LDL::Allocators::Allocator* _Allocator;
			Point2u _Size;
			uint8_t _BytesPerPixel;
			uint8_t* _Pixels;
		};
	}
}

#endif 