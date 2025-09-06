// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_PixelPainter_hpp
#define LDL_Graphics_PixelPainter_hpp

#include <LDL/Graphics/Surface.hpp>

namespace LDL
{
	class LDL_LIBRARY PixelPainter
	{
	public:
		PixelPainter();
		~PixelPainter();
		void Line(const Vec2u& pos1, const Vec2u& pos2);
		void Fill(size_t pixelFormat, uint8_t* pixels, const Vec2u& dstSize, const Vec2u& pos, const Vec2u& size, const LDL::Color& color);
		void Clear(size_t pixelFormat, uint8_t* pixels, const Vec2u& dstSize, const LDL::Color& color);
		void Line(size_t pixelFormat, uint8_t* pixels, const Vec2u& dstSize, const Vec2u& pos1, const Vec2u& pos2, const LDL::Color& color);
	};
}

#endif 
