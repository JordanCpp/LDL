#include <LDL/Low/Assert.hpp>
#include <LDL/Low/Conv.hpp>
#include <stdio.h>

void LDL_Assert(bool condition, const char* description, const char* file, size_t line)
{
	if (!condition)
	{
		LDL_NumberToString conv;

		printf("Assert: %s, file: %s, line: %s\n", description, file, conv.Convert(line));
		abort();
	}
}