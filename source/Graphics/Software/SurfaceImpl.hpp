#ifndef LDL_Graphics_Software_SurfaceImpl_hpp
#define LDL_Graphics_Software_SurfaceImpl_hpp

#include <LDL/Graphics/Primitives/Point2u.hpp>
#include <LDL/Graphics/Primitives/Color.hpp>

namespace LDL
{
	namespace Graphics
	{
		class SurfaceImpl
		{
		public:
			SurfaceImpl(const Point2u& size, uint8_t bytesPerPixel);
			SurfaceImpl(const Point2u& size, uint8_t bytesPerPixel, const Point2u& capacity);
			~SurfaceImpl();
			uint8_t* Pixels();
			const Point2u& Capacity();
			const Point2u& Size();
			size_t Bytes();
			uint8_t BytesPerPixel();
			bool Empty();
			void Clear();
			void Clear(const Color& color);
		private:
			Point2u _Capacity;
			Point2u _Size;
			uint8_t* _Pixels;
			uint8_t _BytesPerPixel;
		};
	}
}

#endif    