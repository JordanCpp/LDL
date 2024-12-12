#ifndef LDL_Graphics_PixelPainter_hpp
#define LDL_Graphics_PixelPainter_hpp

#include <LDL/Graphics/Surface.hpp>

namespace LDL
{
	namespace Graphics
	{
		class LDL_LIBRARY PixelPainter
		{
		public:
			PixelPainter();
			~PixelPainter();
			Surface* Target();
			const Math::Vec2u& Size();
			uint8_t BytesPerPixel();
			uint8_t* Pixels();
			const LDL::Graphics::Color& Color();
			void Color(const LDL::Graphics::Color & color);
			void Clear();
			void Bind(Surface* source);
			void Pixel(const Math::Vec2u& pos);
			const LDL::Graphics::Color& GetPixel(const Math::Vec2u& pos);
			void Fill(const Math::Vec2u& pos, const Math::Vec2u& size);
			void Line(const Math::Vec2u& pos1, const Math::Vec2u& pos2);
		private:
			uint8_t         _red;
			uint8_t         _green;
			uint8_t         _blue;
			uint8_t         _alpha;
			Surface*        _target;
			size_t          _width;
			size_t          _heigth;
			uint8_t         _bytesPerPixel;
			uint8_t*        _pixels;
			Math::Vec2u     _size;
			Graphics::Color _color;
			Graphics::Color _colorGetPixel;
		};
	}
}

#endif 
