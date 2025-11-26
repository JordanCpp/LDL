// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_PixConv_hpp
#define LDL_PixConv_hpp

#include <LDL/Config.hpp>
#include <LDL/Vec2u.hpp>
#include <LDL/Color.hpp>

class LDL_LIBRARY LDL_PixelConverter
{
public:
	void Fill(uint8_t* pixels, const LDL_Vec2u& size, uint8_t bytesPerPixel, const LDL_Color& color);
	void RgbToBgr(uint8_t* pixels, const LDL_Vec2u& size, uint8_t bytesPerPixel);
	void BgrToRgb(uint8_t* pixels, const LDL_Vec2u& size, uint8_t bytesPerPixel);
private:
};

#endif    
