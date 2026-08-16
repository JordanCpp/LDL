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

    span.Data = data;
    span.Capacity = capacity;

    return span;
}

void LDL_StringSpanCopy(LDL_StringSpan* span, const char* source)
{
    if (span && span->Data && source && span->Capacity > 0)
    {
        size_t i = 0;
        size_t max_len = span->Capacity - 1;

        while (i < max_len && source[i] != '\0')
        {
            span->Data[i] = source[i];
            i++;
        }
        span->Data[i] = '\0';
    }
    else if (span && span->Data && span->Capacity > 0)
    {
        span->Data[0] = '\0';
    }
}
