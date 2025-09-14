// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/std/stdio.hpp>

struct LDL::FILE
{
	HANDLE file;
};

LDL::FILE* LDL::fopen(const char* path, const char* mode)
{
	return NULL;
}

void LDL::fclose(LDL::FILE* file)
{
}

size_t LDL::fread(void* buffer, size_t elementSize, size_t elementCount, LDL::FILE* file)
{
	return 0;
}

size_t LDL::fwrite(void* buffer, size_t elementSize, size_t elementCount, LDL::FILE* file)
{
	return 0;
}

int LDL::fseek(LDL::FILE* file, size_t offset, size_t origin)
{
	return 0;
}
