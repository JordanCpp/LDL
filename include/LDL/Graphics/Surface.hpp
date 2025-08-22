#ifndef LDL_Graphics_Surface_hpp
#define LDL_Graphics_Surface_hpp

#include <LDL/Math/Vec2.hpp>
#include <LDL/Graphics/Color.hpp>

namespace LDL
{
	namespace Graphics
	{
		class LDL_LIBRARY Surface
		{
		public:
			Surface(const Math::Vec2u& size, uint8_t bytesPerPixel);
			Surface(const Math::Vec2u& size, uint8_t * pixels, uint8_t bytesPerPixel);
			Surface(const Math::Vec2u& size, const Math::Vec2u& capacity, uint8_t bytesPerPixel);
			Surface(const Math::Vec2u& size, const Math::Vec2u& capacity, uint8_t* pixels, uint8_t bytesPerPixel);
			~Surface();
			const Math::Vec2u& Capacity();
			const Math::Vec2u& Size();
			void Resize(const Math::Vec2u& size);
			void Clear();
			uint8_t BytesPerPixel();
			uint8_t* Pixels();
			Color Pixel(const Math::Vec2u& pos);
		private:
			Math::Vec2u _capacity;
			Math::Vec2u _size;
			uint8_t     _bytesPerPixel;
			uint8_t*    _pixels;
		};
	}
}

#endif 
