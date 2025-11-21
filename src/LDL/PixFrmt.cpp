// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/PixFrmt.hpp>

uint8_t LDL_BytesPerPixelFromPixelFormat(size_t pixelFormat)
{
	uint8_t bytesPerPixel = LDL_PixelFormat::UNKNOWN;

	switch (pixelFormat)
	{
	case LDL_PixelFormat::RGB24:
		bytesPerPixel = 3;
		break;
	case LDL_PixelFormat::BGR24:
		bytesPerPixel = 3;
		break;
	case LDL_PixelFormat::RGBA32:
		bytesPerPixel = 4;
		break;
	case LDL_PixelFormat::BGRA32:
		bytesPerPixel = 4;
		break;
	}

	return bytesPerPixel;
}
