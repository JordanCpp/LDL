// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <LDL/StdFuncs.hpp>
#include <LDL/MemMngr.hpp>

int LDL_abs(int x)
{
	return abs(x);
}

double LDL_sin(double x)
{
	return sin(x);
}

double LDL_cos(double x)
{
	return cos(x);
}

double LDL_sqrt(double x)
{
	return sqrt(x);
}

double LDL_tan(double x)
{
	return tan(x);
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
