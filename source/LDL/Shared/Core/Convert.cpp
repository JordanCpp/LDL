// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/Convert.hpp>

using namespace LDL::Core;

Convert::Convert()
{
}

const char* Convert::ToString(intmax_t num, uint8_t base)
{
    int i = 0;
    bool isNegative = false;

    /* Handle 0 explicitly, otherwise empty string is printed for 0 */
    if (num == 0)
    {
        _buffer[i++] = '0';
        _buffer[i] = '\0';
    }

    // In standard itoa(), negative numbers are handled only with
    // base 10. Otherwise numbers are considered unsigned.
    if (num < 0 && base == 10)
    {
        isNegative = true;
        num = -num;
    }

    // Process individual digits
    while (num != 0)
    {
        int rem = num % base;
        _buffer[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }

    // If number is negative, append '-'
    if (isNegative)
        _buffer[i++] = '-';

    _buffer[i] = '\0'; // Append string terminator

    // Reverse the string
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
