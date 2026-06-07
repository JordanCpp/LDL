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

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <LDL/Result.h>
#include <LDL/Format.h>

struct LDL_Result
{
	bool Ok;
	LDL_Formatter* Formatter;
};

void LDL_ResultReset(LDL_Result* result)
{
	if (result)
	{
		result->Ok = true;
	}
}

LDL_Result* LDL_ResultNew()
{
	LDL_Result* result = (LDL_Result*)malloc(sizeof(LDL_Result));

	if (result)
	{
		LDL_ResultReset(result);

		result->Formatter = LDL_FormatterNew();

		return result;
	}

	return NULL;
}

void LDL_ResultFree(LDL_Result* result)
{
	if (result)
	{
		if (result->Formatter)
		{
			LDL_FormatterFree(result->Formatter);
		}

		free(result);
	}
}

bool LDL_ResultIsOk(LDL_Result* result)
{
	if (result)
	{
		return result->Ok == true;
	}

	return false;
}

bool LDL_ResultIsFail(LDL_Result* result)
{
	if (result)
	{
		return result->Ok == false;
	}

	return true;
}

const char* LDL_ResultGetMessage(LDL_Result* result)
{
	if (result)
	{
		if (result->Formatter)
		{
			return LDL_FormatterGetData(result->Formatter);
		}
	}

	return NULL;
}

void LDL_ResultAddMessage(LDL_Result* result, const char* format, ...)
{
	if (result && result->Formatter)
	{
		if (result->Ok)
		{
			va_list args;
			va_start(args, format);
			LDL_FormatterVFormat(result->Formatter, format, args);
			va_end(args);
		}

		result->Ok = false;
	}
}
