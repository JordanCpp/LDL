#ifndef LDL_Graphics_Surface_hpp
#define LDL_Graphics_Surface_hpp

#include <LDL/Allocators/Allocator.hpp>
#include <LDL/Graphics/Primitives/Point2u.hpp>
#include <LDL/Graphics/Primitives/Color.hpp>
#include <LDL/Loaders/ImageLoader.hpp>
#include <LDL/Config.hpp>
#include <string>

namespace LDL
{
	namespace Graphics
	{
		class Surface
		{
		public:
			Surface(const Point2u& size, uint8_t bytesPerPixel);
			Surface(const Point2u& size, uint8_t * pixels, uint8_t bytesPerPixel);
			~Surface();
			const Point2u& Size();
			uint8_t BytesPerPixel();
			uint8_t* Pixels();
			Color Pixel(const Point2u& pos);
		private:
			Point2u _Size;
			uint8_t _BytesPerPixel;
			uint8_t* _Pixels;
		};
	}
}

#endif 