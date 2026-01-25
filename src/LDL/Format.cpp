// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <stdarg.h>
#include <LDL/StdFuncs.hpp>
#include <LDL/Format.hpp>

LDL_Formatter::LDL_Formatter()
{
	Clear();
}

void LDL_Formatter::Clear()
{
	LDL_memset(&_buffer, 0, sizeof(_buffer));
}

char* LDL_Formatter::Data()
{
	return _buffer;
}

const char* LDL_Formatter::Data() const
{
	return _buffer;
}

const char* LDL_Formatter::Format(const char* format, ...) 
{
    if (!format)
    {
        return _buffer;
    }

    va_list args;
    va_start(args, format);

    char* dst = _buffer;
    char* end = _buffer + Max - 1;
    const char* src = format;

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

                while (*s && dst < end)
                {
                    *dst++ = *s++;
                }

                break;
            }
            case 'd': 
            {
                int n = va_arg(args, int);

                char numBuf[12];

                LDL_itoa(n, numBuf);

                char* p = numBuf;

                while (*p && dst < end) 
                {
                    *dst++ = *p++;
                }

                break;
            }
            case 'c': 
            {
                *dst++ = (char)va_arg(args, int);

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
    va_end(args);

    return _buffer;
}

void LDL_Formatter::LDL_Reverse(char* s, int len)
{
	for (int i = 0, j = len - 1; i < j; i++, j--) 
	{
		char temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}

int LDL_Formatter::LDL_itoa(int num, char* str)
{
	int i = 0;
	unsigned int n = (num < 0) ? (unsigned int)(-num) : (unsigned int)num;

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

	LDL_Reverse(str, i);

	return i;
}