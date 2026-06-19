/*
Copyright(C) 2026 Evgeny Zoshchuk (JordanCpp)

This library is free software; you can redistribute it and /or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.See the GNU Lesser General Public
License for more details.
*/

#include <math.h>
#include <stdlib.h>
#include <LDL/PixFrmt.h>
#include <LDL/Renders/Soft/PixPaint.h>

void LDL_PixelPaintClearBGR24(uint8_t* pixels, LDL_Vec2i size, LDL_Color color)
{
	size_t numPixels;
	uint8_t	r = color.r;
	uint8_t	g = color.g;
	uint8_t b = color.b;

	numPixels = (size_t)size.x * size.y;

	while (numPixels >= 4)
	{
		*pixels++ = b; 
		*pixels++ = g; 
		*pixels++ = r;

		*pixels++ = b; 
		*pixels++ = g; 
		*pixels++ = r;

		*pixels++ = b; 
		*pixels++ = g; 
		*pixels++ = r;

		*pixels++ = b; 
		*pixels++ = g; 
		*pixels++ = r;

		numPixels -= 4;
	}

	while (numPixels > 0)
	{
		*pixels++ = b; 
		*pixels++ = g; 
		*pixels++ = r;

		numPixels--;
	}
}

void LDL_PixelPaintClearRGB24(uint8_t* pixels, LDL_Vec2i size, LDL_Color color)
{
	size_t numPixels;
	uint8_t	r = color.r;
	uint8_t	g = color.g;
	uint8_t b = color.b;

	numPixels = (size_t)size.x * size.y;

	while (numPixels >= 4) 
	{
		*pixels++ = r; 
		*pixels++ = g; 
		*pixels++ = b;

		*pixels++ = r; 
		*pixels++ = g; 
		*pixels++ = b;

		*pixels++ = r; 
		*pixels++ = g; 
		*pixels++ = b;

		*pixels++ = r; 
		*pixels++ = g; 
		*pixels++ = b;

		numPixels -= 4;
	}

	while (numPixels > 0) 
	{
		*pixels++ = r; 
		*pixels++ = g; 
		*pixels++ = b;

		numPixels--;
	}
}

void LDL_PixelPaintClear(size_t pixelFormat, uint8_t* pixels, LDL_Vec2i size, LDL_Color color)
{
	switch (pixelFormat)
	{
	case LDL_PixelFormatBGR24:
		LDL_PixelPaintClearBGR24(pixels, size, color);
		break;
	case LDL_PixelFormatRGB24:
		LDL_PixelPaintClearRGB24(pixels, size, color);
		break;
	}
}

void LDL_PixelPaintLineBGR24(uint8_t* pixels, LDL_Vec2i size, LDL_Vec2i first, LDL_Vec2i last, LDL_Color color)
{
	int x0 = first.x;
	int y0 = first.y;
	int x1 = last.x;
	int y1 = last.y;

	uint8_t	r = color.r;
	uint8_t	g = color.g;
	uint8_t b = color.b;

	uint8_t* p;

	int dx = abs(x1 - x0);
	int dy = -abs(y1 - y0);
	int sx = (x0 < x1) ? 1 : -1;
	int sy = (y0 < y1) ? 1 : -1;
	int err = dx + dy;

	int x = x0;
	int y = y0;

	int e2;

	while (1)
	{
		if (x >= 0 && x < size.x && y >= 0 && y < size.y)
		{
			p = pixels + (y * size.x + x) * 3;
			p[0] = b; p[1] = g; p[2] = r;
		}

		if (x == x1 && y == y1) break;

		e2 = 2 * err;

		if (e2 >= dy)
		{
			err += dy;
			x += sx;
		}

		if (e2 <= dx)
		{
			err += dx;
			y += sy;
		}
	}
}

void LDL_PixelPaintLineRGB24(uint8_t* pixels, LDL_Vec2i size, LDL_Vec2i first, LDL_Vec2i last, LDL_Color color)
{
	int x0 = first.x;
	int y0 = first.y;
	int x1 = last.x;
	int y1 = last.y;

	uint8_t	r = color.r;
	uint8_t	g = color.g;
	uint8_t b = color.b;

	uint8_t* p;

	int dx = abs(x1 - x0);
	int dy = -abs(y1 - y0);
	int sx = (x0 < x1) ? 1 : -1;
	int sy = (y0 < y1) ? 1 : -1;
	int err = dx + dy;

	int x = x0;
	int y = y0;

	int e2;

	while (1)
	{
		if (x >= 0 && x < size.x && y >= 0 && y < size.y)
		{
			p = pixels + (y * size.x + x) * 3;
			p[0] = r; p[1] = g; p[2] = b;
		}

		if (x == x1 && y == y1) break;

		e2 = 2 * err;

		if (e2 >= dy)
		{
			err += dy;
			x += sx;
		}

		if (e2 <= dx)
		{
			err += dx;
			y += sy;
		}
	}
}

void LDL_PixelPaintLine(size_t pixelFormat, uint8_t* pixels, LDL_Vec2i size, LDL_Vec2i first, LDL_Vec2i last, LDL_Color color)
{
	switch (pixelFormat)
	{
	case LDL_PixelFormatBGR24:
		LDL_PixelPaintLineBGR24(pixels, size, first, last, color);
		break;
	case LDL_PixelFormatRGB24:
		LDL_PixelPaintLineRGB24(pixels, size, first, last, color);
		break;
	}
}

void LDL_PixelPaintFillBGR24(uint8_t* pixels, LDL_Vec2i size, LDL_Vec2i first, LDL_Vec2i last, LDL_Color color)
{
	int x_min, x_max, y_min, y_max;
	int cur_x, cur_y;
	uint8_t	r = color.r;
	uint8_t	g = color.g;
	uint8_t b = color.b;

	if (first.x < last.x) 
	{ 
		x_min = first.x; 
		x_max = last.x; 
	}
	else 
	{ 
		x_min = last.x;
		x_max = first.x; 
	}

	if (first.y < last.y) 
	{ 
		y_min = first.y; 
		y_max = last.y; 
	}
	else 
	{
		y_min = last.y; 
		y_max = first.y; 
	}

	if (x_min < 0) x_min = 0;
	if (y_min < 0) y_min = 0;
	if (x_max >= size.x) x_max = size.x - 1;
	if (y_max >= size.y) y_max = size.y - 1;

	for (cur_y = y_min; cur_y <= y_max; cur_y++)
	{
		for (cur_x = x_min; cur_x <= x_max; cur_x++) 
		{
			uint8_t* p = pixels + (cur_y * size.x + cur_x) * 3;
			p[0] = b; p[1] = g; p[2] = r;
		}
	}
}

void LDL_PixelPaintFillRGB24(uint8_t* pixels, LDL_Vec2i size, LDL_Vec2i first, LDL_Vec2i last, LDL_Color color)
{
	int x_min, x_max, y_min, y_max;
	int cur_x, cur_y;
	uint8_t	r = color.r;
	uint8_t	g = color.g;
	uint8_t b = color.b;

	if (first.x < last.x)
	{
		x_min = first.x;
		x_max = last.x;
	}
	else
	{
		x_min = last.x;
		x_max = first.x;
	}

	if (first.y < last.y)
	{
		y_min = first.y;
		y_max = last.y;
	}
	else
	{
		y_min = last.y;
		y_max = first.y;
	}

	if (x_min < 0) x_min = 0;
	if (y_min < 0) y_min = 0;
	if (x_max >= size.x) x_max = size.x - 1;
	if (y_max >= size.y) y_max = size.y - 1;

	for (cur_y = y_min; cur_y <= y_max; cur_y++)
	{
		for (cur_x = x_min; cur_x <= x_max; cur_x++)
		{
			uint8_t* p = pixels + (cur_y * size.x + cur_x) * 3;
			p[0] = r; p[1] = g; p[2] = b;
		}
	}
}

void LDL_PixelPaintFill(size_t pixelFormat, uint8_t* pixels, LDL_Vec2i size, LDL_Vec2i first, LDL_Vec2i last, LDL_Color color)
{
	switch (pixelFormat)
	{
	case LDL_PixelFormatBGR24:
		LDL_PixelPaintFillBGR24(pixels, size, first, last, color);
		break;
	case LDL_PixelFormatRGB24:
		LDL_PixelPaintFillRGB24(pixels, size, first, last, color);
		break;
	}
}
