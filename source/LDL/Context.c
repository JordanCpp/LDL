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

#include <stdlib.h>
#include <LDL/Context.h>

typedef struct LDL_Context
{
	size_t Mode;
} LDL_Context;

LDL_Context* LDL_ContextNew(size_t mode)
{
	LDL_Context* context = (LDL_Context*)malloc(sizeof(LDL_Context));

	if (context)
	{
		context->Mode = mode;

		return context;
	}

	return NULL;
}

void LDL_ContextFree(LDL_Context* context)
{
	if (context)
	{
		free(context);
	}
}

size_t LDL_ContextGet(LDL_Context* context)
{
	return context->Mode;
}
