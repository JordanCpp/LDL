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

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <LDL/Format.h>

enum
{
	LDL_FormatterMax = 512
};

typedef struct LDL_Formatter
{
    char Buffer[LDL_FormatterMax];
} LDL_Formatter;

void LDL_FormatterClear(LDL_Formatter* formatter)
{
    memset(formatter->Buffer, 0, LDL_FormatterMax);
}

LDL_Formatter* LDL_FormatterNew()
{
    LDL_Formatter* formatter = (LDL_Formatter*)malloc(sizeof(LDL_Formatter));

    if (formatter)
    {
        LDL_FormatterClear(formatter);

        return formatter;
    }

    return NULL;
}

void LDL_FormatterFree(LDL_Formatter* formatter)
{
    if (formatter)
    {
        free(formatter);
    }
}

char* LDL_FormatterGetData(LDL_Formatter* formatter)
{
    return formatter ? formatter->Buffer : NULL;
}

void LDL_FormatterReverse(char* s, int len)
{
    int i;
    int j;
    char temp;

    for (i = 0, j = len - 1; i < j; i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

int LDL_FormatterItoa(int num, char* str)
{
    int i = 0;
    unsigned int n;

    if (num < 0)
    {
        n = (unsigned int)(-(num + 1)) + 1;
    }
    else
    {
        n = (unsigned int)num;
    }

    if (num == 0)
    {
        str[i++] = '0';
    }
    else
    {
        while (n != 0)
        {
            str[i++] = (n % 10) + '0';
            n /= 10;
        }

        if (num < 0) str[i++] = '-';
    }

    str[i] = '\0';

    LDL_FormatterReverse(str, i);

    return i;
}

const char* LDL_FormatterVFormat(LDL_Formatter* formatter, const char* format, va_list args) 
{
    char* dst, * end, * p;
    const char* src;
    char numBuf[32];

    if (!formatter || !format)
    {
        return (formatter ? formatter->Buffer : NULL);
    }

    dst = formatter->Buffer;
    end = formatter->Buffer + LDL_FormatterMax - 1;
    src = format;

    while (*src != '\0' && dst < end) 
    {
        if (*src == '%') 
        {
            src++;
            switch (*src)
            {
            case 's':
            {
                char* s = va_arg(args, char*);
                if (!s) s = "(null)";
                while (*s && dst < end) *dst++ = *s++;
                break;
            }
            case 'd': 
            {
                LDL_FormatterItoa(va_arg(args, int), numBuf);
                p = numBuf;
                while (*p && dst < end) *dst++ = *p++;
                break;
            }
            case 'c':
            {
                if (dst < end) *dst++ = (char)va_arg(args, int);
                break;
            }
            case '%': 
            {
                *dst++ = '%';
                break;
            }
            default: 
            {
                if (dst < end) *dst++ = '%';
                if (dst < end) *dst++ = *src;
                break;
            }
            }
        }
        else 
        {
            *dst++ = *src;
        }

        src++;
    }

    *dst = '\0';

    return formatter->Buffer;
}

const char* LDL_FormatterFormat(LDL_Formatter* formatter, const char* format, ...) {
    va_list args;
    const char* res;

    va_start(args, format);
    res = LDL_FormatterVFormat(formatter, format, args);
    va_end(args);

    return res;
}