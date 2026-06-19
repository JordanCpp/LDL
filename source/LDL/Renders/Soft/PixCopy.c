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
#include <LDL/PixFrmt.h>
#include <LDL/Renders/Soft/PixCopy.h>

void LDL_PixelCopyBGR24FromRGB24(uint8_t* dstPixels, LDL_Vec2i dstArea, LDL_Vec2i dstPos, LDL_Vec2i dstSize, uint8_t* srcPixels, LDL_Vec2i srcArea, LDL_Vec2i srcPos, LDL_Vec2i srcSize, bool isColorKey, LDL_Color colorKey)
{
	const size_t bppDst = LDL_BytesPerPixelFromPixelFormat(LDL_PixelFormatBGR24);
	const size_t bppSrc = LDL_BytesPerPixelFromPixelFormat(LDL_PixelFormatRGB24);

	float scaleX;
	float scaleY;

	LDL_Vec2i start;
	LDL_Vec2i end;

	int j;
	int i;

	int targetX;
	int targetY;

	int srcX;
	int srcY;

	size_t dstIdx;
	size_t srcIdx;

	if (!dstPixels || !srcPixels || dstSize.x <= 0 || dstSize.y <= 0)
	{
		return;
	}

	scaleX = (float)srcSize.x / (float)dstSize.x;
	scaleY = (float)srcSize.y / (float)dstSize.y;

	start.x = 0;
	if (dstPos.x < 0)
	{
		start.x = -dstPos.x;
	}

	end.x = dstSize.x;
	if (dstPos.x + dstSize.x > dstArea.x) 
	{
		end.x = dstArea.x - dstPos.x;
	}

	start.y = 0;
	if (dstPos.y < 0)
	{
		start.y = -dstPos.y;
	}

	end.y = dstSize.y;
	if (dstPos.y + dstSize.y > dstArea.y) 
	{
		end.y = dstArea.y - dstPos.y;
	}

	if (start.x >= end.x || start.y >= end.y)
	{
		return;
	}

	for (j = start.y; j < end.y; j++)
	{
		for (i = start.x; i < end.x; i++)
		{
			targetX = dstPos.x + i;
			targetY = dstPos.y + j;

			srcX = srcPos.x + (int)(i * scaleX);
			srcY = srcPos.y + (int)(j * scaleY);

			if (srcX >= srcPos.x + srcSize.x || srcY >= srcPos.y + srcSize.y || srcX < srcPos.x || srcY < srcPos.y)
			{
				continue;
			}

			dstIdx = (targetY * (size_t)dstArea.x + targetX) * bppDst;
			srcIdx = (srcY * (size_t)srcArea.x + srcX) * bppSrc;

			if (isColorKey)
			{
				if (srcPixels[srcIdx + 0] == colorKey.r &&
					srcPixels[srcIdx + 1] == colorKey.g &&
					srcPixels[srcIdx + 2] == colorKey.b)
				{
					continue;
				}
			}

			dstPixels[dstIdx + 0] = srcPixels[srcIdx + 2];
			dstPixels[dstIdx + 1] = srcPixels[srcIdx + 1];
			dstPixels[dstIdx + 2] = srcPixels[srcIdx + 0];
		}
	}
}

void LDL_PixelCopyBGR24FromBGR24(uint8_t* dstPixels, LDL_Vec2i dstArea, LDL_Vec2i dstPos, LDL_Vec2i dstSize, uint8_t* srcPixels, LDL_Vec2i srcArea, LDL_Vec2i srcPos, LDL_Vec2i srcSize, bool isColorKey, LDL_Color colorKey)
{
	const size_t bppDst = LDL_BytesPerPixelFromPixelFormat(LDL_PixelFormatBGR24);
	const size_t bppSrc = LDL_BytesPerPixelFromPixelFormat(LDL_PixelFormatBGR24);

	float scaleX;
	float scaleY;

	LDL_Vec2i start;
	LDL_Vec2i end;

	int j;
	int i;

	int targetX;
	int targetY;

	int srcX;
	int srcY;

	size_t dstIdx;
	size_t srcIdx;

	if (!dstPixels || !srcPixels || dstSize.x <= 0 || dstSize.y <= 0)
	{
		return;
	}

	scaleX = (float)srcSize.x / (float)dstSize.x;
	scaleY = (float)srcSize.y / (float)dstSize.y;

	start.x = 0;
	if (dstPos.x < 0)
	{
		start.x = -dstPos.x;
	}

	end.x = dstSize.x;
	if (dstPos.x + dstSize.x > dstArea.x)
	{
		end.x = dstArea.x - dstPos.x;
	}

	start.y = 0;
	if (dstPos.y < 0)
	{
		start.y = -dstPos.y;
	}

	end.y = dstSize.y;
	if (dstPos.y + dstSize.y > dstArea.y)
	{
		end.y = dstArea.y - dstPos.y;
	}

	if (start.x >= end.x || start.y >= end.y)
	{
		return;
	}

	for (j = start.y; j < end.y; j++)
	{
		for (i = start.x; i < end.x; i++)
		{
			targetX = dstPos.x + i;
			targetY = dstPos.y + j;

			srcX = srcPos.x + (int)(i * scaleX);
			srcY = srcPos.y + (int)(j * scaleY);

			if (srcX >= srcPos.x + srcSize.x || srcY >= srcPos.y + srcSize.y || srcX < srcPos.x || srcY < srcPos.y)
			{
				continue;
			}

			dstIdx = (targetY * (size_t)dstArea.x + targetX) * bppDst;
			srcIdx = (srcY * (size_t)srcArea.x + srcX) * bppSrc;

			if (isColorKey)
			{
				if (srcPixels[srcIdx + 2] == colorKey.r &&
					srcPixels[srcIdx + 1] == colorKey.g &&
					srcPixels[srcIdx + 0] == colorKey.b)
				{
					continue;
				}
			}

			dstPixels[dstIdx + 0] = srcPixels[srcIdx + 0];
			dstPixels[dstIdx + 1] = srcPixels[srcIdx + 1];
			dstPixels[dstIdx + 2] = srcPixels[srcIdx + 2];
		}
	}
}

void LDL_PixelCopyBGR24FromRGBA32(uint8_t* dstPixels, LDL_Vec2i dstArea, LDL_Vec2i dstPos, LDL_Vec2i dstSize, uint8_t* srcPixels, LDL_Vec2i srcArea, LDL_Vec2i srcPos, LDL_Vec2i srcSize)
{
	const size_t bppDst = LDL_BytesPerPixelFromPixelFormat(LDL_PixelFormatBGR24);
	const size_t bppSrc = LDL_BytesPerPixelFromPixelFormat(LDL_PixelFormatRGBA32);

	float scaleX;
	float scaleY;

	LDL_Vec2i start;
	LDL_Vec2i end;

	int j;
	int i;

	int targetX;
	int targetY;

	int srcX;
	int srcY;

	size_t dstIdx;
	size_t srcIdx;

	if (!dstPixels || !srcPixels || dstSize.x <= 0 || dstSize.y <= 0)
	{
		return;
	}

	scaleX = (float)srcSize.x / (float)dstSize.x;
	scaleY = (float)srcSize.y / (float)dstSize.y;

	start.x = 0;
	if (dstPos.x < 0)
	{
		start.x = -dstPos.x;
	}

	end.x = dstSize.x;
	if (dstPos.x + dstSize.x > dstArea.x)
	{
		end.x = dstArea.x - dstPos.x;
	}

	start.y = 0;
	if (dstPos.y < 0)
	{
		start.y = -dstPos.y;
	}

	end.y = dstSize.y;
	if (dstPos.y + dstSize.y > dstArea.y)
	{
		end.y = dstArea.y - dstPos.y;
	}

	if (start.x >= end.x || start.y >= end.y)
	{
		return;
	}

	for (j = start.y; j < end.y; j++)
	{
		for (i = start.x; i < end.x; i++)
		{
			targetX = dstPos.x + i;
			targetY = dstPos.y + j;

			srcX = srcPos.x + (int)(i * scaleX);
			srcY = srcPos.y + (int)(j * scaleY);

			if (srcX >= srcPos.x + srcSize.x || srcY >= srcPos.y + srcSize.y || srcX < srcPos.x || srcY < srcPos.y)
			{
				continue;
			}

			dstIdx = (targetY * (size_t)dstArea.x + targetX) * bppDst;
			srcIdx = (srcY * (size_t)srcArea.x + srcX) * bppSrc;

			if (srcPixels[srcIdx + 3] == 0)
			{
				continue;
			}

			dstPixels[dstIdx + 0] = srcPixels[srcIdx + 2];
			dstPixels[dstIdx + 1] = srcPixels[srcIdx + 1];
			dstPixels[dstIdx + 2] = srcPixels[srcIdx + 0];
		}
	}
}

void LDL_PixelCopyBGR24FromBGRA32(uint8_t* dstPixels, LDL_Vec2i dstArea, LDL_Vec2i dstPos, LDL_Vec2i dstSize, uint8_t* srcPixels, LDL_Vec2i srcArea, LDL_Vec2i srcPos, LDL_Vec2i srcSize)
{
	const size_t bppDst = LDL_BytesPerPixelFromPixelFormat(LDL_PixelFormatBGR24);
	const size_t bppSrc = LDL_BytesPerPixelFromPixelFormat(LDL_PixelFormatBGRA32);

	float scaleX;
	float scaleY;

	LDL_Vec2i start;
	LDL_Vec2i end;

	int j;
	int i;

	int targetX;
	int targetY;

	int srcX;
	int srcY;

	size_t dstIdx;
	size_t srcIdx;

	if (!dstPixels || !srcPixels || dstSize.x <= 0 || dstSize.y <= 0)
	{
		return;
	}

	scaleX = (float)srcSize.x / (float)dstSize.x;
	scaleY = (float)srcSize.y / (float)dstSize.y;

	start.x = 0;
	if (dstPos.x < 0)
	{
		start.x = -dstPos.x;
	}

	end.x = dstSize.x;
	if (dstPos.x + dstSize.x > dstArea.x)
	{
		end.x = dstArea.x - dstPos.x;
	}

	start.y = 0;
	if (dstPos.y < 0)
	{
		start.y = -dstPos.y;
	}

	end.y = dstSize.y;
	if (dstPos.y + dstSize.y > dstArea.y)
	{
		end.y = dstArea.y - dstPos.y;
	}

	if (start.x >= end.x || start.y >= end.y)
	{
		return;
	}

	for (j = start.y; j < end.y; j++)
	{
		for (i = start.x; i < end.x; i++)
		{
			targetX = dstPos.x + i;
			targetY = dstPos.y + j;

			srcX = srcPos.x + (int)(i * scaleX);
			srcY = srcPos.y + (int)(j * scaleY);

			if (srcX >= srcPos.x + srcSize.x || srcY >= srcPos.y + srcSize.y || srcX < srcPos.x || srcY < srcPos.y)
			{
				continue;
			}

			dstIdx = (targetY * (size_t)dstArea.x + targetX) * bppDst;
			srcIdx = (srcY * (size_t)srcArea.x + srcX) * bppSrc;

			if (srcPixels[srcIdx + 3] == 0)
			{
				continue;
			}

			dstPixels[dstIdx + 0] = srcPixels[srcIdx + 0];
			dstPixels[dstIdx + 1] = srcPixels[srcIdx + 1];
			dstPixels[dstIdx + 2] = srcPixels[srcIdx + 2];
		}
	}
}

void LDL_PixelCopyRGB24FromRGB24(uint8_t* dstPixels, LDL_Vec2i dstArea, LDL_Vec2i dstPos, LDL_Vec2i dstSize, uint8_t* srcPixels, LDL_Vec2i srcArea, LDL_Vec2i srcPos, LDL_Vec2i srcSize)
{
}

void LDL_PixelCopyRGB24FromBGR24(uint8_t* dstPixels, LDL_Vec2i dstArea, LDL_Vec2i dstPos, LDL_Vec2i dstSize, uint8_t* srcPixels, LDL_Vec2i srcArea, LDL_Vec2i srcPos, LDL_Vec2i srcSize)
{
}

void LDL_PixelCopyRGB24FromRGBA32(uint8_t* dstPixels, LDL_Vec2i dstArea, LDL_Vec2i dstPos, LDL_Vec2i dstSize, uint8_t* srcPixels, LDL_Vec2i srcArea, LDL_Vec2i srcPos, LDL_Vec2i srcSize)
{
}

void LDL_PixelCopyRGB24FromBGRA32(uint8_t* dstPixels, LDL_Vec2i dstArea, LDL_Vec2i dstPos, LDL_Vec2i dstSize, uint8_t* srcPixels, LDL_Vec2i srcArea, LDL_Vec2i srcPos, LDL_Vec2i srcSize)
{
}

void LDL_PixelCopyBGRA32FromRGB24(uint8_t* dstPixels, LDL_Vec2i dstArea, LDL_Vec2i dstPos, LDL_Vec2i dstSize, uint8_t* srcPixels, LDL_Vec2i srcArea, LDL_Vec2i srcPos, LDL_Vec2i srcSize)
{
}

void LDL_PixelCopyBGRA32FromBGR24(uint8_t* dstPixels, LDL_Vec2i dstArea, LDL_Vec2i dstPos, LDL_Vec2i dstSize, uint8_t* srcPixels, LDL_Vec2i srcArea, LDL_Vec2i srcPos, LDL_Vec2i srcSize)
{
}

void LDL_PixelCopyBGRA32FromRGBA32(uint8_t* dstPixels, LDL_Vec2i dstArea, LDL_Vec2i dstPos, LDL_Vec2i dstSize, uint8_t* srcPixels, LDL_Vec2i srcArea, LDL_Vec2i srcPos, LDL_Vec2i srcSize)
{
}

void LDL_PixelCopyBGRA32FromBGRA32(uint8_t* dstPixels, LDL_Vec2i dstArea, LDL_Vec2i dstPos, LDL_Vec2i dstSize, uint8_t* srcPixels, LDL_Vec2i srcArea, LDL_Vec2i srcPos, LDL_Vec2i srcSize)
{
}

void LDL_PixelCopyRGBA32FromRGB24(uint8_t* dstPixels, LDL_Vec2i dstArea, LDL_Vec2i dstPos, LDL_Vec2i dstSize, uint8_t* srcPixels, LDL_Vec2i srcArea, LDL_Vec2i srcPos, LDL_Vec2i srcSize)
{
}

void LDL_PixelCopyRGBA32FromBGR24(uint8_t* dstPixels, LDL_Vec2i dstArea, LDL_Vec2i dstPos, LDL_Vec2i dstSize, uint8_t* srcPixels, LDL_Vec2i srcArea, LDL_Vec2i srcPos, LDL_Vec2i srcSize)
{
}

void LDL_PixelCopyRGBA32FromRGBA32(uint8_t* dstPixels, LDL_Vec2i dstArea, LDL_Vec2i dstPos, LDL_Vec2i dstSize, uint8_t* srcPixels, LDL_Vec2i srcArea, LDL_Vec2i srcPos, LDL_Vec2i srcSize)
{
}

void LDL_PixelCopyRGBA32FromBGRA32(uint8_t* dstPixels, LDL_Vec2i dstArea, LDL_Vec2i dstPos, LDL_Vec2i dstSize, uint8_t* srcPixels, LDL_Vec2i srcArea, LDL_Vec2i srcPos, LDL_Vec2i srcSize)
{
}

void LDL_PixelCopy(uint8_t* dstPixels, size_t dstFormat, LDL_Vec2i dstArea, LDL_Vec2i dstPos, LDL_Vec2i dstSize, uint8_t* srcPixels, size_t srcFormat, LDL_Vec2i srcArea, LDL_Vec2i srcPos, LDL_Vec2i srcSize, bool isColorKey, LDL_Color colorKey)
{
	switch (dstFormat)
	{
	case LDL_PixelFormatBGR24:
		switch (srcFormat)
		{
		case LDL_PixelFormatRGB24:
			LDL_PixelCopyBGR24FromRGB24(dstPixels, dstArea, dstPos, dstSize, srcPixels, srcArea, srcPos, srcSize, isColorKey, colorKey);
			break;
		case LDL_PixelFormatBGR24:
			LDL_PixelCopyBGR24FromBGR24(dstPixels, dstArea, dstPos, dstSize, srcPixels, srcArea, srcPos, srcSize, isColorKey, colorKey);
			break;
		case LDL_PixelFormatRGBA32:
			LDL_PixelCopyBGR24FromRGBA32(dstPixels, dstArea, dstPos, dstSize, srcPixels, srcArea, srcPos, srcSize);
			break;
		case LDL_PixelFormatBGRA32:
			LDL_PixelCopyBGR24FromBGRA32(dstPixels, dstArea, dstPos, dstSize, srcPixels, srcArea, srcPos, srcSize);
			break;
		}
		break;
	case LDL_PixelFormatRGB24:
		switch (srcFormat)
		{
		case LDL_PixelFormatRGB24:
			LDL_PixelCopyRGB24FromRGB24(dstPixels, dstArea, dstPos, dstSize, srcPixels, srcArea, srcPos, srcSize);
			break;
		case LDL_PixelFormatBGR24:
			LDL_PixelCopyRGB24FromBGR24(dstPixels, dstArea, dstPos, dstSize, srcPixels, srcArea, srcPos, srcSize);
			break;
		case LDL_PixelFormatRGBA32:
			LDL_PixelCopyRGB24FromRGBA32(dstPixels, dstArea, dstPos, dstSize, srcPixels, srcArea, srcPos, srcSize);
			break;
		case LDL_PixelFormatBGRA32:
			LDL_PixelCopyRGB24FromBGRA32(dstPixels, dstArea, dstPos, dstSize, srcPixels, srcArea, srcPos, srcSize);
			break;
		}
		break;
	case LDL_PixelFormatBGRA32:
		switch (srcFormat)
		{
		case LDL_PixelFormatRGB24:
			LDL_PixelCopyBGRA32FromRGB24(dstPixels, dstArea, dstPos, dstSize, srcPixels, srcArea, srcPos, srcSize);
			break;
		case LDL_PixelFormatBGR24:
			LDL_PixelCopyBGRA32FromBGR24(dstPixels, dstArea, dstPos, dstSize, srcPixels, srcArea, srcPos, srcSize);
			break;
		case LDL_PixelFormatRGBA32:
			LDL_PixelCopyBGRA32FromRGBA32(dstPixels, dstArea, dstPos, dstSize, srcPixels, srcArea, srcPos, srcSize);
			break;
		case LDL_PixelFormatBGRA32:
			LDL_PixelCopyBGRA32FromBGRA32(dstPixels, dstArea, dstPos, dstSize, srcPixels, srcArea, srcPos, srcSize);
			break;
		}
		break;
	case LDL_PixelFormatRGBA32:
		switch (srcFormat)
		{
		case LDL_PixelFormatRGB24:
			LDL_PixelCopyRGBA32FromRGB24(dstPixels, dstArea, dstPos, dstSize, srcPixels, srcArea, srcPos, srcSize);
			break;
		case LDL_PixelFormatBGR24:
			LDL_PixelCopyRGBA32FromBGR24(dstPixels, dstArea, dstPos, dstSize, srcPixels, srcArea, srcPos, srcSize);
			break;
		case LDL_PixelFormatRGBA32:
			LDL_PixelCopyRGBA32FromRGBA32(dstPixels, dstArea, dstPos, dstSize, srcPixels, srcArea, srcPos, srcSize);
			break;
		case LDL_PixelFormatBGRA32:
			LDL_PixelCopyRGBA32FromBGRA32(dstPixels, dstArea, dstPos, dstSize, srcPixels, srcArea, srcPos, srcSize);
			break;
		}
		break;
	}
}

