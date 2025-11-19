// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_PixelPainter_hpp
#define LDL_Graphics_PixelPainter_hpp

#include <LDL/Surface.hpp>

class LDL_LIBRARY PixelPainter
{
public:
	PixelPainter();
	~PixelPainter();
	void Line(const LDL_Vec2u& pos1, const LDL_Vec2u& pos2);
	void Fill(size_t pixelFormat, uint8_t* pixels, const LDL_Vec2u& dstSize, const LDL_Vec2u& pos, const LDL_Vec2u& size, const LDL_Color& color);
	void FillBGR24(uint8_t* pixels, const LDL_Vec2u& dstSize, const LDL_Vec2u& pos, const LDL_Vec2u& size, const LDL_Color& color);
	void FillRGB24(uint8_t* pixels, const LDL_Vec2u& dstSize, const LDL_Vec2u& pos, const LDL_Vec2u& size, const LDL_Color& color);
	void Clear(size_t pixelFormat, uint8_t* pixels, const LDL_Vec2u& dstSize, const LDL_Color& color);
	void ClearRGB24(uint8_t* pixels, const LDL_Vec2u& dstSize, const LDL_Color& color);
	void ClearBGR24(uint8_t* pixels, const LDL_Vec2u& dstSize, const LDL_Color& color);
	void ClearBGRA32(uint8_t* pixels, const LDL_Vec2u& dstSize, const LDL_Color& color);
	void ClearRGBA32(uint8_t* pixels, const LDL_Vec2u& dstSize, const LDL_Color& color);
	void Line(size_t pixelFormat, uint8_t* pixels, const LDL_Vec2u& dstSize, const LDL_Vec2u& pos1, const LDL_Vec2u& pos2, const LDL_Color& color);
};

#endif 
