// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Assert.hpp>
#include <LDL/StdFuncs.hpp>
#include <LDL/PixPaint.hpp>

LDL_PixelPainter::LDL_PixelPainter()
{
}

LDL_PixelPainter::~LDL_PixelPainter()
{
}

void LDL_PixelPainter::Fill(size_t pixelFormat, uint8_t* pixels, const LDL_Vec2u& dstSize, const LDL_Vec2u& pos, const LDL_Vec2u& size, const LDL_Color& color)
{
	switch (pixelFormat)
	{
	case LDL_PixelFormat::BGR24:
		FillBGR24(pixels, dstSize, pos, size, color);
		break;
	case LDL_PixelFormat::RGB24:
		FillRGB24(pixels, dstSize, pos, size, color);
		break;
	}
}

void LDL_PixelPainter::FillBGR24(uint8_t* pixels, const LDL_Vec2u& dstSize, const LDL_Vec2u& pos, const LDL_Vec2u& size, const LDL_Color& color)
{
	size_t x = pos.x;
	size_t y = pos.y;
	size_t w = size.x;
	size_t h = size.y;

	LDL_UNUSED(w);
	LDL_UNUSED(h);

	size_t   dstW = dstSize.x;
	size_t   dstH = dstSize.y;
	uint8_t* dstP = pixels;
	uint8_t  dstB = LDL_BytesPerPixelFromPixelFormat(LDL_PixelFormat::BGR24);

	for (size_t i = 0; i < size.x; i++)
	{
		for (size_t j = 0; j < size.y; j++)
		{
			size_t index = (dstW * (y + j) + (x + i)) * dstB;

			if (index < dstW * dstH * dstB)
			{
				dstP[index + 0] = color.b;
				dstP[index + 1] = color.g;
				dstP[index + 2] = color.r;
			}
		}
	}
}

void LDL_PixelPainter::FillRGB24(uint8_t* pixels, const LDL_Vec2u& dstSize, const LDL_Vec2u& pos, const LDL_Vec2u& size, const LDL_Color& color)
{
	size_t x = (size_t)pos.x;
	size_t y = (size_t)pos.y;
	size_t w = (size_t)size.x;
	size_t h = (size_t)size.y;

	LDL_UNUSED(w);
	LDL_UNUSED(h);

	size_t   dstW = dstSize.x;
	size_t   dstH = dstSize.y;
	uint8_t* dstP = pixels;
	uint8_t  dstB = LDL_BytesPerPixelFromPixelFormat(LDL_PixelFormat::RGB24);

	for (size_t i = 0; i < size.x; i++)
	{
		for (size_t j = 0; j < size.y; j++)
		{
			size_t index = (dstW * (y + j) + (x + i)) * dstB;

			if (index < dstW * dstH * dstB)
			{
				dstP[index + 0] = color.r;
				dstP[index + 1] = color.g;
				dstP[index + 2] = color.b;
			}
		}
	}
}

void LDL_PixelPainter::Clear(size_t pixelFormat, uint8_t* pixels, const LDL_Vec2u& dstSize, const LDL_Color& color)
{
	size_t total = dstSize.x * dstSize.y * LDL_BytesPerPixelFromPixelFormat(pixelFormat);

	LDL_UNUSED(total);

	switch (pixelFormat)
	{
	case LDL_PixelFormat::BGR24:
		ClearBGR24(pixels, dstSize, color);
		break;
	case LDL_PixelFormat::RGB24:
		ClearRGB24(pixels, dstSize, color);
		break;
	case LDL_PixelFormat::BGRA32:
		ClearBGRA32(pixels, dstSize, color);
		break;
	case LDL_PixelFormat::RGBA32:
		ClearRGBA32(pixels, dstSize, color);
		break;
	}
}

void LDL_PixelPainter::ClearRGB24(uint8_t* pixels, const LDL_Vec2u& dstSize, const LDL_Color& color)
{
	size_t bpp   = LDL_BytesPerPixelFromPixelFormat(LDL_PixelFormat::RGB24);
	size_t total = dstSize.x * dstSize.y * bpp;

	for (size_t i = 0; i < total; i += bpp)
	{
		pixels[i + 0] = color.r;
		pixels[i + 1] = color.g;
		pixels[i + 2] = color.b;
	}
}

void LDL_PixelPainter::ClearBGR24(uint8_t* pixels, const LDL_Vec2u& dstSize, const LDL_Color& color)
{
	size_t bpp   = LDL_BytesPerPixelFromPixelFormat(LDL_PixelFormat::BGR24);
	size_t total = dstSize.x * dstSize.y * bpp;

	for (size_t i = 0; i < total; i += bpp)
	{
		pixels[i + 0] = color.b;
		pixels[i + 1] = color.g;
		pixels[i + 2] = color.r;
	}
}

void LDL_PixelPainter::ClearBGRA32(uint8_t* pixels, const LDL_Vec2u& dstSize, const LDL_Color& color)
{
	size_t bpp   = LDL_BytesPerPixelFromPixelFormat(LDL_PixelFormat::BGRA32);
	size_t total = dstSize.x * dstSize.y * bpp;

	for (size_t i = 0; i < total; i += bpp)
	{
		pixels[i + 0] = color.b;
		pixels[i + 1] = color.g;
		pixels[i + 2] = color.r;
		pixels[i + 3] = color.a;
	}
}

void LDL_PixelPainter::ClearRGBA32(uint8_t* pixels, const LDL_Vec2u& dstSize, const LDL_Color& color)
{
	size_t bpp   = LDL_BytesPerPixelFromPixelFormat(LDL_PixelFormat::RGBA32);
	size_t total = dstSize.x * dstSize.y * bpp;

	for (size_t i = 0; i < total; i += bpp)
	{
		pixels[i + 0] = color.r;
		pixels[i + 1] = color.g;
		pixels[i + 2] = color.b;
		pixels[i + 3] = color.a;
	}
}

void LDL_PixelPainter::Line(size_t pixelFormat, uint8_t* pixels, const LDL_Vec2u& dstSize, const LDL_Vec2u& pos1, const LDL_Vec2u& pos2, const LDL_Color& color)
{
	size_t   dstW = dstSize.x;
	size_t   dstH = dstSize.y;
	uint8_t* dstP = pixels;
	uint8_t  dstB = LDL_BytesPerPixelFromPixelFormat(pixelFormat);

	LDL_UNUSED(dstH);
	LDL_UNUSED(dstP);

	int x1 = (int)pos1.x;
	int y1 = (int)pos1.y;

	int x2 = (int)pos2.x;
	int y2 = (int)pos2.y;

	int deltaX;
	int deltaY;
	int signX;
	int signY;
	int error;
	int error2;

	deltaX = LDL_abs(x2 - x1);
	deltaY = LDL_abs(y2 - y1);
	signX = x1 < x2 ? 1 : -1;
	signY = y1 < y2 ? 1 : -1;

	error = deltaX - deltaY;

	size_t index = (dstW * y2 + x2) * dstB;

	switch (pixelFormat)
	{
	case LDL_PixelFormat::BGR24:
			pixels[index + 0] = color.b;
			pixels[index + 1] = color.g;
			pixels[index + 2] = color.r;
		break;
	case LDL_PixelFormat::RGB24:
			pixels[index + 0] = color.r;
			pixels[index + 1] = color.g;
			pixels[index + 2] = color.b;
		break;
	case LDL_PixelFormat::BGRA32:
			pixels[index + 0] = color.b;
			pixels[index + 1] = color.g;
			pixels[index + 2] = color.r;
			pixels[index + 3] = color.a;
		break;
	case LDL_PixelFormat::RGBA32:
			pixels[index + 0] = color.r;
			pixels[index + 1] = color.g;
			pixels[index + 2] = color.b;
			pixels[index + 3] = color.a;
		break;
	}

	while (x1 != x2 || y1 != y2)
	{
		index = (dstW * y1 + x1) * dstB;

		switch (pixelFormat)
		{
		case LDL_PixelFormat::BGR24:
			pixels[index + 0] = color.b;
			pixels[index + 1] = color.g;
			pixels[index + 2] = color.r;
			break;
		case LDL_PixelFormat::RGB24:
			pixels[index + 0] = color.r;
			pixels[index + 1] = color.g;
			pixels[index + 2] = color.b;
			break;
		case LDL_PixelFormat::BGRA32:
			pixels[index + 0] = color.b;
			pixels[index + 1] = color.g;
			pixels[index + 2] = color.r;
			pixels[index + 3] = color.a;
			break;
		case LDL_PixelFormat::RGBA32:
			pixels[index + 0] = color.r;
			pixels[index + 1] = color.g;
			pixels[index + 2] = color.b;
			pixels[index + 3] = color.a;
			break;
		}

		error2 = error * 2;

		if (error2 > -deltaY)
		{
			error -= deltaY;
			x1 += signX;
		}

		if (error2 < deltaX)
		{
			error += deltaX;
			y1 += signY;
		}
	}
}
