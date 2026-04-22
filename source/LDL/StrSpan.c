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

#include <string.h>
#include <LDL/StrSpan.h>

LDL_StringSpan LDL_GetStringSpan(char* data, size_t capacity)
{
    LDL_StringSpan span;

    span.Data     = data;
    span.Capacity = capacity;

    return span;
}

void LDL_StringSpanCopy(LDL_StringSpan* span, const char* source)
{
    if (span && span->Data && source)
    {
        strncpy(span->Data, source, span->Capacity - 1);
        span->Data[span->Capacity - 1] = '\0';
    }
}
