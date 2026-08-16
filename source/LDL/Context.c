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
#include <LDL/ErrorMsg.h>

struct LDL_Context
{
	size_t Type;
};

LDL_Context* LDL_ContextCreate(LDL_Result* result, LDL_ContextType type)
{
    LDL_Context* context = (LDL_Context*)malloc(sizeof(LDL_Context));

    if (context == NULL)
    {
        if (result)
        {
            LDL_ResultAddMessage(result, LDL_ErrorOutOfMemory());
        }

        return NULL;
    }

    context->Type = (size_t)type;

    return context;
}

void LDL_ContextDestroy(LDL_Context* context)
{
    if (context)
    {
        free(context);
    }
}

size_t LDL_ContextGet(LDL_Context* context)
{
    return context ? context->Type : 0;
}
