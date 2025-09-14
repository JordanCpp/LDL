// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_std_stdio_hpp
#define LDL_std_stdio_hpp

#include <LDL/std/stddef.hpp>

namespace LDL
{
	const size_t SEEK_CUR = 1;
	const size_t SEEK_END = 2;
	const size_t SEEK_SET = 0;

	typedef struct FILE FILE;

	FILE* fopen(const char* path, const char* mode);
	void fclose(FILE* file);
	size_t fread(void* buffer, size_t elementSize, size_t elementCount, FILE* file);
	size_t fwrite(void* buffer, size_t elementSize, size_t elementCount, FILE* file);
	int fseek(FILE* file, size_t offset, size_t origin);
}

#endif
