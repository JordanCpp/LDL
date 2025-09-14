// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/Assert.hpp>
#include <LDL/Graphics/PixelCopier.hpp>

using namespace LDL;

void PixelCopier::Copy(size_t srcFormat, uint8_t* srcPixels, const Vec2u& srcSize, Surface* srcSurf, size_t dstFormat, uint8_t* dstPixels, const Vec2u& dstSize, const Vec2u& pos, Surface* dstSurf)
{
	switch (dstFormat)
	{
	case PixelFormat::BGR24:
		switch (srcFormat)
		{
		case PixelFormat::RGB24:
			CopyRGB24ToBGR24(srcPixels, srcSize, srcSurf, dstPixels, dstSize, pos, dstSurf);
			break;
		case PixelFormat::BGR24:
			CopyRGB24ToBGR24(srcPixels, srcSize, srcSurf, dstPixels, dstSize, pos, dstSurf);
			break;
		case PixelFormat::RGBA32:
			CopyRGBA32ToBGR24(srcPixels, srcSize, srcSurf, dstPixels, dstSize, pos, dstSurf);
			break;
		case PixelFormat::BGRA32:
			CopyRGBA32ToBGR24(srcPixels, srcSize, srcSurf, dstPixels, dstSize, pos, dstSurf);
			break;
		}
		break;
	}
}

void PixelCopier::CopyRGB24ToBGR24(uint8_t* srcPixels, const Vec2u& srcSize, Surface* srcSurf, uint8_t* dstPixels, const Vec2u& dstSize, const Vec2u& pos, Surface* dstSurf)
{
	size_t dstBpp = BytesPerPixelFromPixelFormat(PixelFormat::BGR24);
	size_t srcBpp = BytesPerPixelFromPixelFormat(PixelFormat::RGB24);

	size_t limit = dstSize.x * dstSize.y * dstBpp;

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
}

void PixelCopier::CopyBGR24ToBGR24(uint8_t* srcPixels, const Vec2u& srcSize, Surface* srcSurf, uint8_t* dstPixels, const Vec2u& dstSize, const Vec2u& pos, Surface* dstSurf)
{
	size_t dstBpp = BytesPerPixelFromPixelFormat(PixelFormat::BGR24);
	size_t srcBpp = BytesPerPixelFromPixelFormat(PixelFormat::BGR24);

	size_t limit = dstSize.x * dstSize.y * dstBpp;

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
}

void PixelCopier::CopyRGBA32ToBGR24(uint8_t* srcPixels, const Vec2u& srcSize, Surface* srcSurf, uint8_t* dstPixels, const Vec2u& dstSize, const Vec2u& pos, Surface* dstSurf)
{
	size_t dstBpp = BytesPerPixelFromPixelFormat(PixelFormat::BGR24);
	size_t srcBpp = BytesPerPixelFromPixelFormat(PixelFormat::RGBA32);

	size_t limit = dstSize.x * dstSize.y * dstBpp;

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
}

void PixelCopier::CopyBGRA32ToBGR24(uint8_t* srcPixels, const Vec2u& srcSize, Surface* srcSurf, uint8_t* dstPixels, const Vec2u& dstSize, const Vec2u& pos, Surface* dstSurf)
{
	size_t dstBpp = BytesPerPixelFromPixelFormat(PixelFormat::BGR24);
	size_t srcBpp = BytesPerPixelFromPixelFormat(PixelFormat::BGRA32);

	size_t limit = dstSize.x * dstSize.y * dstBpp;

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
}
