#include <LDL/Low/Equal.hpp>
#include <LDL/Low/Conv.hpp>
#include <stdio.h>

void LDL_TestEqual(bool condition, const char* description, const char* file, size_t line)
{
	if (!condition)
	{
		LDL_NumberToString conv;

		printf("Test failed: %s, file: %s, line: %s\n", description, file, conv.Convert(line));
	}
}
