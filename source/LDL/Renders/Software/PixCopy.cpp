// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Assert.hpp>
#include <LDL/PixCopy.hpp>

void LDL_PixelCopier::Copy(uint8_t* dstPixels, size_t dstFormat, const LDL_Vec2u& dstArea, const LDL_Vec2u& dstPos, const LDL_Vec2u& dstSize, uint8_t* srcPixels, size_t srcFormat, const LDL_Vec2u& srcArea, const LDL_Vec2u& srcPos, const LDL_Vec2u& srcSize)
{
	switch (dstFormat)
	{
	case LDL_PixelFormat::BGR24:
		switch (srcFormat)
		{
		case LDL_PixelFormat::RGB24:
			break;
		case LDL_PixelFormat::BGR24:
			break;
		case LDL_PixelFormat::RGBA32:
			break;
		case LDL_PixelFormat::BGRA32:
			break;
		}
		break;
	case LDL_PixelFormat::RGB24:
		switch (srcFormat)
		{
		case LDL_PixelFormat::RGB24:
			RGB24FromRGB24(dstPixels, dstArea, dstPos, dstSize, srcPixels, srcArea, srcPos, srcSize);
			break;
		case LDL_PixelFormat::BGR24:
			break;
		case LDL_PixelFormat::RGBA32:
			RGB24FromRGBA32(dstPixels, dstArea, dstPos, dstSize, srcPixels, srcArea, srcPos, srcSize);
			break;
		case LDL_PixelFormat::BGRA32:
			break;
		}
		break;
	}
}

void LDL_PixelCopier::RGB24FromRGB24(uint8_t* dstPixels, const LDL_Vec2u& dstArea, const LDL_Vec2u& dstPos, const LDL_Vec2u& dstSize, uint8_t* srcPixels, const LDL_Vec2u& srcArea, const LDL_Vec2u& srcPos, const LDL_Vec2u& srcSize)
{
	size_t dstBpp = LDL_BytesPerPixelFromPixelFormat(LDL_PixelFormat::RGB24);
	size_t srcBpp = LDL_BytesPerPixelFromPixelFormat(LDL_PixelFormat::RGB24);

	size_t x = dstPos.x;
	size_t y = dstPos.y;

	size_t dstSizeX = dstArea.x;
	size_t dstSizeY = dstArea.y;
	size_t dstIndex = 0;

	size_t srcSizeX = srcArea.x;
	size_t srcSizeY = srcArea.y;
	size_t srcIndex = 0;

	size_t limitSizeX = 0;
	size_t limitSizeY = 0;

	if (srcSizeX + x > dstSizeX)
	{
		limitSizeX = dstSizeX - x;
	}
	else
	{
		limitSizeX = srcSizeX;
	}

	if (srcSizeY + y > dstSizeY)
	{
		limitSizeY = dstSizeY - y;
	}
	else
	{
		limitSizeY = srcSizeY;
	}

	for (size_t i = 0; i < limitSizeX; i++)
	{
		for (size_t j = 0; j < limitSizeY; j++)
		{
			dstIndex = (dstSizeX * (y + j) + (x + i)) * dstBpp;
			srcIndex = (srcSizeX * j + i) * srcBpp;

			if (dstIndex < dstSizeX * dstSizeY * dstBpp)
			{
				dstPixels[dstIndex + 0] = srcPixels[srcIndex + 0];
				dstPixels[dstIndex + 1] = srcPixels[srcIndex + 1];
				dstPixels[dstIndex + 2] = srcPixels[srcIndex + 2]; 
			}
		}
	}
}

void LDL_PixelCopier::RGB24FromRGBA32(uint8_t* dstPixels, const LDL_Vec2u& dstArea, const LDL_Vec2u& dstPos, const LDL_Vec2u& dstSize, uint8_t* srcPixels, const LDL_Vec2u& srcArea, const LDL_Vec2u& srcPos, const LDL_Vec2u& srcSize)
{
	size_t dstBpp = LDL_BytesPerPixelFromPixelFormat(LDL_PixelFormat::RGB24);
	size_t srcBpp = LDL_BytesPerPixelFromPixelFormat(LDL_PixelFormat::RGBA32);

	size_t x = dstPos.x;
	size_t y = dstPos.y;

	size_t dstSizeX = dstArea.x;
	size_t dstSizeY = dstArea.y;
	size_t dstIndex = 0;

	size_t srcSizeX = srcArea.x;
	size_t srcSizeY = srcArea.y;
	size_t srcIndex = 0;

	size_t limitSizeX = 0;
	size_t limitSizeY = 0;

	if (srcSizeX + x > dstSizeX)
	{
		limitSizeX = dstSizeX - x;
	}
	else
	{
		limitSizeX = srcSizeX;
	}

	if (srcSizeY + y > dstSizeY)
	{
		limitSizeY = dstSizeY - y;
	}
	else
	{
		limitSizeY = srcSizeY;
	}

	for (size_t i = 0; i < limitSizeX; i++)
	{
		for (size_t j = 0; j < limitSizeY; j++)
		{
			dstIndex = (dstSizeX * (y + j) + (x + i)) * dstBpp;
			srcIndex = (srcSizeX * j + i) * srcBpp;

			if (dstIndex < dstSizeX * dstSizeY * dstBpp)
			{
				dstPixels[dstIndex + 0] = srcPixels[srcIndex + 0];
				dstPixels[dstIndex + 1] = srcPixels[srcIndex + 1];
				dstPixels[dstIndex + 2] = srcPixels[srcIndex + 2];
			}
		}
	}
}

void LDL_PixelCopier::Copy(size_t srcFormat, uint8_t* srcPixels, const LDL_Vec2u& srcSize, LDL_Surface* srcSurf, size_t dstFormat, uint8_t* dstPixels, const LDL_Vec2u& dstSize, const LDL_Vec2u& pos, LDL_Surface* dstSurf)
{
	switch (dstFormat)
	{
	case LDL_PixelFormat::BGR24:
		switch (srcFormat)
		{
		case LDL_PixelFormat::RGB24:
			CopyRGB24ToBGR24(srcPixels, srcSize, srcSurf, dstPixels, dstSize, pos, dstSurf);
			break;
		case LDL_PixelFormat::BGR24:
			CopyRGB24ToBGR24(srcPixels, srcSize, srcSurf, dstPixels, dstSize, pos, dstSurf);
			break;
		case LDL_PixelFormat::RGBA32:
			CopyRGBA32ToBGR24(srcPixels, srcSize, srcSurf, dstPixels, dstSize, pos, dstSurf);
			break;
		case LDL_PixelFormat::BGRA32:
			CopyRGBA32ToBGR24(srcPixels, srcSize, srcSurf, dstPixels, dstSize, pos, dstSurf);
			break;
		}
		break;
	case LDL_PixelFormat::RGB24:
		switch (srcFormat)
		{
		case LDL_PixelFormat::RGB24:
			CopyRGB24ToRGB24(srcPixels, srcSize, srcSurf, dstPixels, dstSize, pos, dstSurf);
			break;
		case LDL_PixelFormat::BGR24:
			CopyBGR24ToRGB24(srcPixels, srcSize, srcSurf, dstPixels, dstSize, pos, dstSurf);
			break;
		case LDL_PixelFormat::RGBA32:
			CopyRGBA32ToRGB24(srcPixels, srcSize, srcSurf, dstPixels, dstSize, pos, dstSurf);
			break;
		}
		break;
	}
}

void LDL_PixelCopier::CopyRGB24ToBGR24(uint8_t* srcPixels, const LDL_Vec2u& srcSize, LDL_Surface* srcSurf, uint8_t* dstPixels, const LDL_Vec2u& dstSize, const LDL_Vec2u& pos, LDL_Surface* dstSurf)
{
	LDL_UNUSED(srcSurf);
	LDL_UNUSED(dstSurf);

	size_t dstBpp = LDL_BytesPerPixelFromPixelFormat(LDL_PixelFormat::BGR24);
	size_t srcBpp = LDL_BytesPerPixelFromPixelFormat(LDL_PixelFormat::RGB24);

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

void LDL_PixelCopier::CopyBGR24ToBGR24(uint8_t* srcPixels, const LDL_Vec2u& srcSize, LDL_Surface* srcSurf, uint8_t* dstPixels, const LDL_Vec2u& dstSize, const LDL_Vec2u& pos, LDL_Surface* dstSurf)
{
	LDL_UNUSED(srcSurf);
	LDL_UNUSED(dstSurf);

	size_t dstBpp = LDL_BytesPerPixelFromPixelFormat(LDL_PixelFormat::BGR24);
	size_t srcBpp = LDL_BytesPerPixelFromPixelFormat(LDL_PixelFormat::BGR24);

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

void LDL_PixelCopier::CopyRGBA32ToBGR24(uint8_t* srcPixels, const LDL_Vec2u& srcSize, LDL_Surface* srcSurf, uint8_t* dstPixels, const LDL_Vec2u& dstSize, const LDL_Vec2u& pos, LDL_Surface* dstSurf)
{
	LDL_UNUSED(srcSurf);
	LDL_UNUSED(dstSurf);

	size_t dstBpp = LDL_BytesPerPixelFromPixelFormat(LDL_PixelFormat::BGR24);
	size_t srcBpp = LDL_BytesPerPixelFromPixelFormat(LDL_PixelFormat::RGBA32);

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

void LDL_PixelCopier::CopyBGRA32ToBGR24(uint8_t* srcPixels, const LDL_Vec2u& srcSize, LDL_Surface* srcSurf, uint8_t* dstPixels, const LDL_Vec2u& dstSize, const LDL_Vec2u& pos, LDL_Surface* dstSurf)
{
	LDL_UNUSED(srcSurf);
	LDL_UNUSED(dstSurf);

	size_t dstBpp = LDL_BytesPerPixelFromPixelFormat(LDL_PixelFormat::BGR24);
	size_t srcBpp = LDL_BytesPerPixelFromPixelFormat(LDL_PixelFormat::BGRA32);

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

void LDL_PixelCopier::CopyRGB24ToRGB24(uint8_t* srcPixels, const LDL_Vec2u& srcSize, LDL_Surface* srcSurf, uint8_t* dstPixels, const LDL_Vec2u& dstSize, const LDL_Vec2u& pos, LDL_Surface* dstSurf)
{
	LDL_UNUSED(srcSurf);
	LDL_UNUSED(dstSurf);

	size_t dstBpp = LDL_BytesPerPixelFromPixelFormat(LDL_PixelFormat::RGB24);
	size_t srcBpp = LDL_BytesPerPixelFromPixelFormat(LDL_PixelFormat::RGB24);

	size_t limit = dstSize.x * dstSize.y * dstBpp;

	for (size_t y = 0; y < srcSize.y; y++)
	{
		for (size_t x = 0; x < srcSize.x; x++)
		{
			size_t dstIndex = (dstSize.x * (pos.y + y) + pos.x + x) * dstBpp;
			size_t srcIndex = (srcSize.x * y + x) * srcBpp;

			if (dstIndex < limit)
			{
				dstPixels[dstIndex + 0] = srcPixels[srcIndex + 0];
				dstPixels[dstIndex + 1] = srcPixels[srcIndex + 1];
				dstPixels[dstIndex + 2] = srcPixels[srcIndex + 2];
			}
		}
	}
}

void LDL_PixelCopier::CopyBGR24ToRGB24(uint8_t* srcPixels, const LDL_Vec2u& srcSize, LDL_Surface* srcSurf, uint8_t* dstPixels, const LDL_Vec2u& dstSize, const LDL_Vec2u& pos, LDL_Surface* dstSurf)
{
	LDL_UNUSED(srcSurf);
	LDL_UNUSED(dstSurf);

	size_t dstBpp = LDL_BytesPerPixelFromPixelFormat(LDL_PixelFormat::RGB24);
	size_t srcBpp = LDL_BytesPerPixelFromPixelFormat(LDL_PixelFormat::BGR24);

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

void LDL_PixelCopier::CopyRGBA32ToRGB24(uint8_t* srcPixels, const LDL_Vec2u& srcSize, LDL_Surface* srcSurf, uint8_t* dstPixels, const LDL_Vec2u& dstSize, const LDL_Vec2u& pos, LDL_Surface* dstSurf)
{
	LDL_UNUSED(srcSurf);
	LDL_UNUSED(dstSurf);

	size_t dstBpp = LDL_BytesPerPixelFromPixelFormat(LDL_PixelFormat::RGB24);
	size_t srcBpp = LDL_BytesPerPixelFromPixelFormat(LDL_PixelFormat::RGBA32);

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
