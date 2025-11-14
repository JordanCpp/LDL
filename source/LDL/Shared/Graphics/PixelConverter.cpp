// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/Types.hpp>
#include <LDL/Graphics/PixelConverter.hpp>

using namespace LDL;

void PixelConverter::Fill(uint8_t* pixels, const Vec2u& size, uint8_t bytesPerPixel, const Color& color)
{
	size_t bytes = size.x * size.y * bytesPerPixel;

	for (size_t i = 0; i < bytes; i += bytesPerPixel)
	{
#if defined(LDL_CONFIG_COLOR_BGRA)
		pixels[i + 0] = color.b;
		pixels[i + 1] = color.g;
		pixels[i + 2] = color.r;
		pixels[i + 3] = color.a;
#else 
		pixels[i + 0] = color.r;
		pixels[i + 1] = color.g;
		pixels[i + 2] = color.b;
		pixels[i + 3] = color.a;
#endif
	}
}

void PixelConverter::RgbToBgr(uint8_t* pixels, const Vec2u& size, uint8_t bytesPerPixel)
{
	size_t bytes = size.x * size.y * bytesPerPixel;

	for (size_t i = 0; i < bytes; i += 4)
	{
		uint8_t temp = pixels[i + 2];
		pixels[i + 2] = pixels[i + 0];
		pixels[i + 0] = temp;
	}
}

void PixelConverter::BgrToRgb(uint8_t* pixels, const Vec2u& size, uint8_t bytesPerPixel)
{
	size_t bytes = size.x * size.y * bytesPerPixel;

	for (size_t i = 0; i < bytes; i += 4)
	{
		uint8_t temp = pixels[i + 0];
		pixels[i + 0] = pixels[i + 2];
		pixels[i + 2] = temp;
	}
}
