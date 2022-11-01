#ifndef LDL_Graphics_PixelConverter_hpp
#define LDL_Graphics_PixelConverter_hpp

#include <LDL/Graphics/Primitives/Color.hpp>
#include <LDL/Graphics/Primitives/Point2u.hpp>

namespace LDL
{
	namespace Graphics
	{
		class PixelConverter
		{
		public:
			void RgbToBgr(uint8_t* pixels, const LDL::Graphics::Point2u& size, uint8_t bytesPerPixel);
			void BgrToRgb(uint8_t* pixels, const LDL::Graphics::Point2u& size, uint8_t bytesPerPixel);
		private:
		};
	}
}

#endif    