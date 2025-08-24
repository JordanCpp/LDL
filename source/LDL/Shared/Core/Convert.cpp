// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/Convert.hpp>
#include <LDL/std/string.hpp>

using namespace LDL::Core;

Convert::Convert()
{
    LDL::memset(&_buffer, 0, sizeof(_buffer));
}

const char* Convert::ToString(intmax_t num, uint8_t base)
{
    if (base < 2 || base > 36)
    {
        _buffer[0] = '\0';

        return _buffer;
    }

    if (num == INTMAX_MIN && base == 10)
    {
        const char* min_str = "-9223372036854775808";
        
        size_t len = strlen(min_str);
        
        LDL::memcpy(_buffer, min_str, len + 1);

        return _buffer;
    }

    int i           = 0;
    bool isNegative = false;
    uintmax_t unum;

    if (num < 0 && base == 10)
    {
        isNegative = true;
        unum = (uintmax_t)(-num);
    }
    else
    {
        unum = (uintmax_t)num;
    }

    if (unum == 0)
    {
        _buffer[i++] = '0';
    }
    else
    {
        while (unum != 0)
        {
            uintmax_t rem = unum % base;
            _buffer[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
            unum = unum / base;
        }
    }

    if (isNegative)
    {
        _buffer[i++] = '-';
    }

    _buffer[i] = '\0';

    Reverse(_buffer, i);

    return _buffer;
}

void Convert::Swap(char& t1, char& t2)
{
    char tmp = t1;
    t1 = t2;
    t2 = tmp;
}

void Convert::Reverse(char* str, size_t length)
{
    size_t start = 0;
    size_t end = length - 1;

    while (start < end)
    {
        Swap(*(str + start), *(str + end));
        start++;
        end--;
    }
}
