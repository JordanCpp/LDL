// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Core_InPlaceString_hpp
#define LDL_Core_InPlaceString_hpp

#include <LDL/Core/StdFuncs.hpp>
#include <LDL/Core/Types.hpp>

namespace LDL
{
    template <size_t Max>
    class InPlaceString
    {
        enum 
        { 
            Null = Max - 1 
        };

    public:
        InPlaceString()
        {
            _buffer[0] = '\0';
        }

        InPlaceString(const char* str)
        {
            assign(str);
        }

        InPlaceString(const InPlaceString& other)
        {
            LDL::strlcpy(_buffer, other._buffer, Max);
        }

        InPlaceString& operator=(const char* str)
        {
            assign(str);

            return *this;
        }

        InPlaceString& operator=(const InPlaceString& other)
        {
            if (this != &other)
            {
                LDL::strlcpy(_buffer, other._buffer, Max);
            }

            return *this;
        }

        InPlaceString& operator+=(const char* str)
        {
            append(str);

            return *this;
        }

        InPlaceString& operator+=(char c)
        {
            append(c);

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
            return LDL::strlen(_buffer);
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
                _buffer[pos] = c;
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

        friend InPlaceString operator+(const InPlaceString& lhs, const char* rhs)
        {
            InPlaceString result = lhs;

            result.append(rhs);

            return result;
        }

        friend InPlaceString operator+(const char* lhs, const InPlaceString& rhs)
        {
            InPlaceString result;

            result.append(lhs);
            result.append(rhs._buffer);

            return result;
        }

        friend InPlaceString operator+(const InPlaceString& lhs, char rhs)
        {
            InPlaceString result = lhs;

            result.append(rhs);

            return result;
        }

        friend InPlaceString operator+(char lhs, const InPlaceString& rhs)
        {
            InPlaceString result;

            result.append(&lhs, 1);
            result.append(rhs._buffer);

            return result;
        }

    private:
        void append(const char* str, size_t count)
        {
            size_t pos = size();
            size_t n = 0;

            while (n < count && pos + n < Null)
            {
                _buffer[pos + n] = str[n];
                ++n;
            }

            _buffer[pos + n] = '\0';
        }

    private:
        char _buffer[Max];
    };
}

#endif
