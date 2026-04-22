
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <LDL/Result.h>
#include <LDL/Format.h>

typedef struct LDL_Result
{
	bool Ok;
	LDL_Formatter* Formatter;
} LDL_Result;

void LDL_ResultReset(LDL_Result* result)
{
	result->Ok = true;
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
	return result->Ok == true;
}

bool LDL_ResultIsFail(LDL_Result* result)
{
	return result->Ok == false;
}

const char* LDL_ResultGetMessage(LDL_Result* result)
{
	
	return LDL_FormatterGetData(result->Formatter);
}

void LDL_ResultAddMessage(LDL_Result* result, const char* format, ...)
{
	if (result)
	{
		if (result->Formatter)
		{
			LDL_FormatterFormat(result->Formatter, format);
		}

		result->Ok = false;
	}
}
