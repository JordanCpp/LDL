// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Convert.hpp>
#include <LDL/StdFuncs.hpp>
#include <LDL/Types.hpp>

LDL_Convert::LDL_Convert()
{
    LDL_memset(_buffer, 0, sizeof(_buffer));
}

const char* LDL_Convert::ToString(intmax_t num, uint8_t base)
{
    if (base < 2 || base > 36)
    {
        _buffer[0] = '\0';
        return _buffer;
    }

    int i = 0;
    bool isNegative = false;
    uintmax_t number;

    const intmax_t min_value = (intmax_t)1 << (sizeof(intmax_t) * 8 - 1);
    if (num == min_value && base == 10)
    {
        if (sizeof(intmax_t) == 8)
        {
            LDL_memcpy(_buffer, "-9223372036854775808", 21);
        }
        else
        {
            LDL_memcpy(_buffer, "-2147483648", 12);
        }
        return _buffer;
    }

    if (num < 0 && base == 10)
    {
        isNegative = true;
        number = (uintmax_t)(-num);
    }
    else
    {
        number = (uintmax_t)num;
    }

    if (number == 0)
    {
        _buffer[i++] = '0';
    }
    else
    {
        while (number != 0 && i < (int)(sizeof(_buffer) - 2))
        {
            uintmax_t rem = number % base;
            _buffer[i++] = (char)((rem > 9) ? (rem - 10) + 'a' : rem + '0');
            number = number / base;
        }
    }

    if (isNegative && i < (int)(sizeof(_buffer) - 1))
    {
        _buffer[i++] = '-';
    }

    _buffer[i] = '\0';

    if (i > 1)
    {
        size_t start = 0;
        size_t end = i - 1;
        while (start < end)
        {
            char temp = _buffer[start];
            _buffer[start] = _buffer[end];
            _buffer[end] = temp;
            start++;
            end--;
        }
    }

    return _buffer;
}
