// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/Assert.hpp>
#include <LDL/Graphics/PixelCopier.hpp>

using namespace LDL;

void PixelCopier::Copy(size_t srcFormat, uint8_t* srcPixels, const Vec2u& srcSize, Surface* srcSurf, size_t dstFormat, uint8_t* dstPixels, const Vec2u& dstSize, const Vec2u& pos, Surface* dstSurf)
{
	size_t dstBpp  = BytesPerPixelFromPixelFormat(dstFormat);
	size_t srcBpp  = BytesPerPixelFromPixelFormat(srcFormat);

	size_t limit = dstSize.x * dstSize.y * dstBpp;

	switch (dstFormat)
	{
	case PixelFormat::BGR24:
		switch (srcFormat)
		{
		case PixelFormat::RGB24:
			for (size_t y = 0; y < srcSize.y; y++)
			{
				for (size_t x = 0; x < srcSize.x; x++)
				{
					size_t dstIndex = (dstSize.x * (pos.y + y) + pos.x + x) * dstBpp;
					size_t srcIndex = (srcSize.x * y + x) * srcBpp;

					if (dstIndex < limit)
					{
						dstPixels[dstIndex + 0] = srcPixels[srcIndex + 2];
						dstPixels[dstIndex + 1] = srcPixels[srcIndex + 1];
						dstPixels[dstIndex + 2] = srcPixels[srcIndex + 0];
					}
				}
			}
			break;
		case PixelFormat::RGBA32:
			for (size_t y = 0; y < srcSize.y; y++)
			{
				for (size_t x = 0; x < srcSize.x; x++)
				{
					size_t dstIndex = (dstSize.x * (pos.y + y) + pos.x + x) * dstBpp;
					size_t srcIndex = (srcSize.x * y + x) * srcBpp;

					if (dstIndex < limit)
					{
						if (srcPixels[srcIndex + 3] != 0)
						{
							dstPixels[dstIndex + 0] = srcPixels[srcIndex + 2];
							dstPixels[dstIndex + 1] = srcPixels[srcIndex + 1];
							dstPixels[dstIndex + 2] = srcPixels[srcIndex + 0];
						}
					}
				}
			}
			break;
		case PixelFormat::BGRA32:
			for (size_t y = 0; y < srcSize.y; y++)
			{
				for (size_t x = 0; x < srcSize.x; x++)
				{
					size_t dstIndex = (dstSize.x * (pos.y + y) + pos.x + x) * dstBpp;
					size_t srcIndex = (srcSize.x * y + x) * srcBpp;

					if (dstIndex < limit)
					{
						if (srcPixels[srcIndex + 3] != 0)
						{
							dstPixels[dstIndex + 0] = srcPixels[srcIndex + 0];
							dstPixels[dstIndex + 1] = srcPixels[srcIndex + 1];
							dstPixels[dstIndex + 2] = srcPixels[srcIndex + 2];
						}
					}
				}
			}
			break;
		}
		break;
	}
}
