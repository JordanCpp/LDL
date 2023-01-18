#ifndef LDL_Graphics_PixelPainter_hpp
#define LDL_Graphics_PixelPainter_hpp

#include <LDL/Graphics/Surface.hpp>

namespace LDL
{
	namespace Graphics
	{
		class PixelPainter
		{
		public:
			PixelPainter();
			~PixelPainter();
			Surface* Target();
			const Point2u& Size();
			uint8_t BytesPerPixel();
			uint8_t* Pixels();
			const LDL::Graphics::Color& Color();
			void Color(const LDL::Graphics::Color & color);
			void Clear();
			void Bind(Surface* source);
			void Pixel(const Point2u& pos);
			const LDL::Graphics::Color& GetPixel(const Point2u& pos);
		private:
			Surface* _Target;
			size_t   _Width;
			size_t   _Heigth;
			uint8_t  _BytesPerPixel;
			uint8_t* _Pixels;
			Point2u  _Size;
			LDL::Graphics::Color _Color;
			LDL::Graphics::Color _ColorGetPixel;
		};
	}
}

#endif 