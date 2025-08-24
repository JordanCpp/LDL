// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Containers_inplace_string_hpp
#define LDL_Containers_inplace_string_hpp

#include <string.h>
#include <LDL/Core/Types.hpp>

template <size_t Max>
class inplace_string
{
    enum { Null = Max - 1 };

public:
    inplace_string()
    {
        _buffer[0] = '\0';
    }

    inplace_string(const char* str)
    {
        assign(str);
    }

    inplace_string& operator=(const char* str)
    {
        assign(str);

        return *this;
    }

    void clear()
    {
        _buffer[0] = '\0';
    }

    bool empty() const
    {
        return _buffer[0] == '\0';
    }

    size_t size() const
    {
        return strlen(_buffer);
    }

    size_t length() const
    {
        return size();
    }

    const char* c_str() const
    {
        return _buffer;
    }

    char* data()
    {
        return _buffer;
    }

    void assign(const char* str)
    {
        clear();

        if (str)
        {
            size_t i = 0;

            while (i < Null && str[i] != '\0')
            {
                _buffer[i] = str[i];
                ++i;
            }

            _buffer[i] = '\0';
        }
    }

    void append(const char* str)
    {
        if (!str || !str[0])
        {
            return;
        }

        size_t pos = size();
        size_t i   = 0;

        while (pos < Null && str[i] != '\0')
        {
            _buffer[pos++] = str[i++];
        }

        _buffer[pos] = '\0';
    }

    void append(char c)
    {
        size_t pos = size();

        if (pos < Null)
        {
            _buffer[pos]     = c;
            _buffer[pos + 1] = '\0';
        }
    }

    void resize(size_t count)
    {
        if (count >= Max)
        {
            count = Null;
        }
     
        _buffer[count] = '\0';
    }

    size_t capacity() const
    {
        return Null;
    }

private:
    char _buffer[Max];
};

#endif