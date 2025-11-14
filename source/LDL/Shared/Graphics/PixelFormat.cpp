// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Graphics/PixelFormat.hpp>

using namespace LDL;

uint8_t LDL::BytesPerPixelFromPixelFormat(size_t pixelFormat)
{
	uint8_t bytesPerPixel = PixelFormat::UNKNOWN;

	switch (pixelFormat)
	{
	case PixelFormat::RGB24:
		bytesPerPixel = 3;
		break;
	case PixelFormat::BGR24:
		bytesPerPixel = 3;
		break;
	case PixelFormat::RGBA32:
		bytesPerPixel = 4;
		break;
	case PixelFormat::BGRA32:
		bytesPerPixel = 4;
		break;
	}

	return bytesPerPixel;
}
