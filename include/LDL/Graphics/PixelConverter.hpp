#ifndef LDL_Graphics_PixelConverter_hpp
#define LDL_Graphics_PixelConverter_hpp

#include <LDL/Graphics/Color.hpp>
#include <LDL/Math/Vec2.hpp>

namespace LDL
{
	namespace Graphics
	{
		class LDL_EXPORT PixelConverter
		{
		public:
			void Fill(uint8_t* pixels, const Math::Vec2u& size, uint8_t bytesPerPixel, const Color& color);
			void RgbToBgr(uint8_t* pixels, const Math::Vec2u& size, uint8_t bytesPerPixel);
			void BgrToRgb(uint8_t* pixels, const Math::Vec2u& size, uint8_t bytesPerPixel);
		private:
		};
	}
}

#endif    