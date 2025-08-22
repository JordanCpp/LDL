// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_PixelConverter_hpp
#define LDL_Graphics_PixelConverter_hpp

#include <LDL/Math/Vec2.hpp>
#include <LDL/Graphics/Color.hpp>

namespace LDL
{
	namespace Graphics
	{
		class LDL_LIBRARY PixelConverter
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
