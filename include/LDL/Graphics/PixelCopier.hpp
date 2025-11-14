// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_PixelCopier_hpp
#define LDL_Graphics_PixelCopier_hpp

#include <LDL/Graphics/Surface.hpp>

namespace LDL
{
	class LDL_LIBRARY PixelCopier
	{
	public:
		void Copy(uint8_t* dstPixels, size_t dstFormat, const Vec2u& dstArea, const Vec2u& dstPos, const Vec2u& dstSize, uint8_t* srcPixels, size_t srcFormat, const Vec2u& srcArea, const Vec2u& srcPos, const Vec2u& srcSize);
		void RGB24FromRGB24(uint8_t* dstPixels, const Vec2u& dstArea, const Vec2u& dstPos, const Vec2u& dstSize, uint8_t* srcPixels, const Vec2u& srcArea, const Vec2u& srcPos, const Vec2u& srcSize);
		void RGB24FromRGBA32(uint8_t* dstPixels, const Vec2u& dstArea, const Vec2u& dstPos, const Vec2u& dstSize, uint8_t* srcPixels, const Vec2u& srcArea, const Vec2u& srcPos, const Vec2u& srcSize);

		void Copy(size_t srcFormat, uint8_t* srcPixels, const Vec2u& srcSize, Surface* srcSurf, size_t dstFormat, uint8_t* dstPixels, const Vec2u& dstSize, const Vec2u& pos, Surface* dstSurf);
		
		//BGR24
		void CopyRGB24ToBGR24(uint8_t* srcPixels, const Vec2u& srcSize, Surface* srcSurf, uint8_t* dstPixels, const Vec2u& dstSize, const Vec2u& pos, Surface* dstSurf);
		void CopyBGR24ToBGR24(uint8_t* srcPixels, const Vec2u& srcSize, Surface* srcSurf, uint8_t* dstPixels, const Vec2u& dstSize, const Vec2u& pos, Surface* dstSurf);
		void CopyRGBA32ToBGR24(uint8_t* srcPixels, const Vec2u& srcSize, Surface* srcSurf, uint8_t* dstPixels, const Vec2u& dstSize, const Vec2u& pos, Surface* dstSurf);
		void CopyBGRA32ToBGR24(uint8_t* srcPixels, const Vec2u& srcSize, Surface* srcSurf, uint8_t* dstPixels, const Vec2u& dstSize, const Vec2u& pos, Surface* dstSurf);
	
		//RGB24
		void CopyRGB24ToRGB24(uint8_t* srcPixels, const Vec2u& srcSize, Surface* srcSurf, uint8_t* dstPixels, const Vec2u& dstSize, const Vec2u& pos, Surface* dstSurf);
		void CopyBGR24ToRGB24(uint8_t* srcPixels, const Vec2u& srcSize, Surface* srcSurf, uint8_t* dstPixels, const Vec2u& dstSize, const Vec2u& pos, Surface* dstSurf);
		void CopyRGBA32ToRGB24(uint8_t* srcPixels, const Vec2u& srcSize, Surface* srcSurf, uint8_t* dstPixels, const Vec2u& dstSize, const Vec2u& pos, Surface* dstSurf);
	private:
	};
}

#endif 
