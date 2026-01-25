// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <stdlib.h>
#include <string.h>
#include <LDL/StdFuncs.hpp>
#include <LDL/MemMngr.hpp>

int LDL_abs(int x)
{
	return (x < 0) ? -x : x;
}

double LDL_sin(double x)
{
	const double PI = 3.141592653589793;

	x = x - ((long)(x / (2 * PI)) * (2 * PI));

	if (x < 0)
	{
		x += 2 * PI;
	}

	bool negative = false;

	if (x > PI) 
	{
		x -= PI;
		negative = true;
	}

	double common = x * (PI - x);
	double result = (16.0 * common) / (5.0 * PI * PI - 4.0 * common);

	return negative ? -result : result;
}

double LDL_cos(double x)
{
	const double PI     = 3.141592653589793;
	const double PI_SQR = 9.869604401089358;

	x = x - (double)((long)(x / (2.0 * PI))) * (2.0 * PI);

	if (x > PI)
	{
		x -= 2.0 * PI;
	}
	if (x < -PI)
	{
		x += 2.0 * PI;
	}

	if (x < 0)
	{
		x = -x;
	}

	bool negative = false;

	if (x > PI / 2.0) 
	{
		x = PI - x;
		negative = true;
	}

	double x_sqr  = x * x;
	double result = (PI_SQR - 4.0 * x_sqr) / (PI_SQR + x_sqr);

	return negative ? -result : result;
}

double LDL_sqrt(double x)
{
	if (x <= 0) return 0;

	double res = x;

	for (int i = 0; i < 10; i++)
	{
		res = 0.5 * (res + x / res);
	}

	return res;
}

double LDL_tan(double x)
{
	double s = LDL_sin(x);
	double c = LDL_cos(x);

	if (c == 0.0)
	{
		return 0.0;
	}

	return s / c;
}

void* LDL_malloc(size_t bytes)
{
	return LDL_MemoryManager::Instance().GetMalloc()(bytes);
}

void* LDL_realloc(void* block, size_t bytes)
{
	return realloc(block, bytes);
}

void LDL_free(void* ptr)
{
	LDL_MemoryManager::Instance().GetFree()(ptr);
}

size_t LDL_strlcpy(char* dst, const char* src, size_t size)
{
	if (!dst || !src || size == 0)
	{
		return 0;
	}

	size_t srcLen = 0;

	while (src[srcLen] != '\0')
	{
		srcLen++;
	}

	if (size > 1)
	{
		size_t copyLen = (srcLen < size - 1) ? srcLen : size - 1;

		for (size_t i = 0; i < copyLen; ++i)
		{
			dst[i] = src[i];
		}

		dst[copyLen] = '\0';
	}
	else
	{
		dst[0] = '\0';
	}

	return srcLen;
}

size_t LDL_strlcat(char* dst, const char* src, size_t dstSize)
{
	if (dst == NULL || src == NULL || dstSize == 0)
	{
		return 0;
	}

	size_t dstLen = LDL_strlen(dst);

	if (dstLen >= dstSize)
	{
		return dstSize + LDL_strlen(src);
	}

	size_t remaining = dstSize - dstLen - 1;

	size_t srcLen  = LDL_strlen(src);
	size_t copyLen = srcLen;

	if (copyLen > remaining)
	{
		copyLen = remaining;
	}

	LDL_memcpy(dst + dstLen, src, copyLen);
	dst[dstLen + copyLen] = '\0';

	return dstLen + srcLen;
}

size_t LDL_strlen(const char* src)
{
	return strlen(src);
}

void* LDL_memcpy(void* dst, const void* src, size_t size)
{
	return memcpy(dst, src, size);
}

void* LDL_memset(void* ptr, int value, size_t num)
{
	return memset(ptr, value, num);
}
