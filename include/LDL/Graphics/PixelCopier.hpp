// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_PixelCopier_hpp
#define LDL_Graphics_PixelCopier_hpp

#include <LDL/Graphics/Surface.hpp>

namespace LDL
{
	class PixelCopier
	{
	public:
		void Copy(size_t srcFormat, uint8_t* srcPixels, const Vec2u& srcSize, Surface* srcSurf, size_t dstFormat, uint8_t* dstPixels, const Vec2u& dstSize, const Vec2u& pos, Surface* dstSurf);
		void CopyRGB24ToBGR24(uint8_t* srcPixels, const Vec2u& srcSize, Surface* srcSurf, uint8_t* dstPixels, const Vec2u& dstSize, const Vec2u& pos, Surface* dstSurf);
		void CopyBGR24ToBGR24(uint8_t* srcPixels, const Vec2u& srcSize, Surface* srcSurf, uint8_t* dstPixels, const Vec2u& dstSize, const Vec2u& pos, Surface* dstSurf);
		void CopyRGBA32ToBGR24(uint8_t* srcPixels, const Vec2u& srcSize, Surface* srcSurf, uint8_t* dstPixels, const Vec2u& dstSize, const Vec2u& pos, Surface* dstSurf);
		void CopyBGRA32ToBGR24(uint8_t* srcPixels, const Vec2u& srcSize, Surface* srcSurf, uint8_t* dstPixels, const Vec2u& dstSize, const Vec2u& pos, Surface* dstSurf);
	private:
	};
}

#endif 
