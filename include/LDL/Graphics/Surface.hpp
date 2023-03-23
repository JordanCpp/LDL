#ifndef LDL_Graphics_Surface_hpp
#define LDL_Graphics_Surface_hpp

#include <LDL/Graphics/Primitives/Point2u.hpp>
#include <LDL/Graphics/Primitives/Color.hpp>

namespace LDL
{
	namespace Graphics
	{
		class LDL_EXPORT Surface
		{
		public:
			Surface(const Point2u& size, uint8_t bytesPerPixel);
			Surface(const Point2u& size, uint8_t * pixels, uint8_t bytesPerPixel);
			Surface(const Point2u& size, const Point2u& capacity, uint8_t bytesPerPixel);
			Surface(const Point2u& size, const Point2u& capacity, uint8_t* pixels, uint8_t bytesPerPixel);
			~Surface();
			const Point2u& Capacity();
			const Point2u& Size();
			void Resize(const Point2u& size);
			void Clear();
			uint8_t BytesPerPixel();
			uint8_t* Pixels();
			Color Pixel(const Point2u& pos);
		private:
			Point2u _Capacity;
			Point2u _Size;
			uint8_t _BytesPerPixel;
			uint8_t* _Pixels;
		};
	}
}

#endif 