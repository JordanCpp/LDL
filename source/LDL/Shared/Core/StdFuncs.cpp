// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/StdFuncs.hpp>
#include <LDL/Core/MemoryManager.hpp>

using namespace LDL;

void* LDL::LDL_malloc(size_t bytes)
{
	return MemoryManager::Instance().GetMalloc()(bytes);
}

void LDL::LDL_free(void* ptr)
{
	MemoryManager::Instance().GetFree()(ptr);
}

int LDL::abs(int x)
{
	return x < 0 ? -x : x;
}

size_t LDL::strlcpy(char* dst, const char* src, size_t size)
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

size_t LDL::strlen(const char* src)
{
	size_t i = 0;

	while (src[i] != 0)
	{
		i++;
	}

	return i;
}

void* LDL::LDL_memcpy(void* dst, const void* src, size_t size)
{
	char* d = (char*)dst;
	const char* s = (const char*)src;

	while (size--)
	{
		*d++ = *s++;
	}

	return dst;
}

void* LDL::LDL_memset(void* ptr, int value, size_t num)
{
	if (!ptr || num == 0)
	{
		return ptr;
	}

	uint8_t* p = (uint8_t*)(ptr);
	uint8_t  v = (uint8_t)(value);

	for (size_t i = 0; i < num; i++)
	{
		p[i] = v;
	}

	return ptr;
}
