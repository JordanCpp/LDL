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

	size_t srcLength = 0;

	while (src[srcLength] != '\0')
	{
		srcLength++;
	}

	if (size > 1)
	{
		size_t copyLength = (srcLength < size - 1) ? srcLength : size - 1;

		for (size_t i = 0; i < copyLength; ++i)
		{
			dst[i] = src[i];
		}

		dst[copyLength] = '\0';
	}
	else
	{
		dst[0] = '\0';
	}

	return srcLength;
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
