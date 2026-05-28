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

#include <LDL/PixFrmt.h>

uint8_t LDL_BytesPerPixelFromPixelFormat(size_t pixelFormat)
{
	uint8_t bytesPerPixel = LDL_PixelFormatUnknown;

	switch (pixelFormat)
	{
	case LDL_PixelFormatRGB24:
		bytesPerPixel = 3;
		break;
	case LDL_PixelFormatBGR24:
		bytesPerPixel = 3;
		break;
	case LDL_PixelFormatRGBA32:
		bytesPerPixel = 4;
		break;
	case LDL_PixelFormatBGRA32:
		bytesPerPixel = 4;
		break;
	}

	return bytesPerPixel;
}
