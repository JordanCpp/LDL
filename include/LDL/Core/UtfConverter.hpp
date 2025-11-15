// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Core_UtfConverter_hpp
#define LDL_Core_UtfConverter_hpp

#include <LDL/Core/Types.hpp>
#include <LDL/Core/Vector.hpp>

namespace LDL
{
    class UtfConverter
    {
    public:
        UtfConverter();
        bool convertToUTF16(const char* utf8_str);
        bool convertToUTF8(const uint16_t* utf16_str, size_t utf16_len = 0);
        bool convertToUTF8(const Vector<uint16_t>& utf16_data);
        const uint16_t* getUTF16Data() const;
        const char* getUTF8Data() const;
        const Vector<uint16_t>& getUTF16Vector() const;
        const Vector<char>& getUTF8Vector() const;
        void clear();
        bool hasUTF16() const;
        bool hasUTF8() const;

    private:
        Vector<uint16_t> utf16_buffer;
        Vector<char>     utf8_buffer;
        uint32_t decodeUTF8Char(const char* utf8_str, size_t& pos, size_t max_len);
        void encodeUTF8Char(uint32_t code_point, Vector<char>& output);
    };
}

#endif
