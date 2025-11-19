// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_PixCopy_hpp
#define LDL_PixCopy_hpp

#include <LDL/Surface.hpp>

class LDL_LIBRARY LDL_PixelCopier
{
public:
	void Copy(uint8_t* dstPixels, size_t dstFormat, const LDL_Vec2u& dstArea, const LDL_Vec2u& dstPos, const LDL_Vec2u& dstSize, uint8_t* srcPixels, size_t srcFormat, const LDL_Vec2u& srcArea, const LDL_Vec2u& srcPos, const LDL_Vec2u& srcSize);
	void RGB24FromRGB24(uint8_t* dstPixels, const LDL_Vec2u& dstArea, const LDL_Vec2u& dstPos, const LDL_Vec2u& dstSize, uint8_t* srcPixels, const LDL_Vec2u& srcArea, const LDL_Vec2u& srcPos, const LDL_Vec2u& srcSize);
	void RGB24FromRGBA32(uint8_t* dstPixels, const LDL_Vec2u& dstArea, const LDL_Vec2u& dstPos, const LDL_Vec2u& dstSize, uint8_t* srcPixels, const LDL_Vec2u& srcArea, const LDL_Vec2u& srcPos, const LDL_Vec2u& srcSize);

	void Copy(size_t srcFormat, uint8_t* srcPixels, const LDL_Vec2u& srcSize, LDL_Surface* srcSurf, size_t dstFormat, uint8_t* dstPixels, const LDL_Vec2u& dstSize, const LDL_Vec2u& pos, LDL_Surface* dstSurf);

	//BGR24
	void CopyRGB24ToBGR24(uint8_t* srcPixels, const LDL_Vec2u& srcSize, LDL_Surface* srcSurf, uint8_t* dstPixels, const LDL_Vec2u& dstSize, const LDL_Vec2u& pos, LDL_Surface* dstSurf);
	void CopyBGR24ToBGR24(uint8_t* srcPixels, const LDL_Vec2u& srcSize, LDL_Surface* srcSurf, uint8_t* dstPixels, const LDL_Vec2u& dstSize, const LDL_Vec2u& pos, LDL_Surface* dstSurf);
	void CopyRGBA32ToBGR24(uint8_t* srcPixels, const LDL_Vec2u& srcSize, LDL_Surface* srcSurf, uint8_t* dstPixels, const LDL_Vec2u& dstSize, const LDL_Vec2u& pos, LDL_Surface* dstSurf);
	void CopyBGRA32ToBGR24(uint8_t* srcPixels, const LDL_Vec2u& srcSize, LDL_Surface* srcSurf, uint8_t* dstPixels, const LDL_Vec2u& dstSize, const LDL_Vec2u& pos, LDL_Surface* dstSurf);

	//RGB24
	void CopyRGB24ToRGB24(uint8_t* srcPixels, const LDL_Vec2u& srcSize, LDL_Surface* srcSurf, uint8_t* dstPixels, const LDL_Vec2u& dstSize, const LDL_Vec2u& pos, LDL_Surface* dstSurf);
	void CopyBGR24ToRGB24(uint8_t* srcPixels, const LDL_Vec2u& srcSize, LDL_Surface* srcSurf, uint8_t* dstPixels, const LDL_Vec2u& dstSize, const LDL_Vec2u& pos, LDL_Surface* dstSurf);
	void CopyRGBA32ToRGB24(uint8_t* srcPixels, const LDL_Vec2u& srcSize, LDL_Surface* srcSurf, uint8_t* dstPixels, const LDL_Vec2u& dstSize, const LDL_Vec2u& pos, LDL_Surface* dstSurf);
private:
};

#endif 
