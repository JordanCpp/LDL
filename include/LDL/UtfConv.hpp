// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_UtfConv_hpp
#define LDL_UtfConv_hpp

#include <LDL/Types.hpp>
#include <LDL/PVector.hpp>

class LDL_UtfConverter
{
public:
    LDL_UtfConverter();
    bool convertToUTF16(const char* utf8_str);
    bool convertToUTF8(const uint16_t* utf16_str, size_t utf16_len = 0);
    bool convertToUTF8(const LDL_PodVector<uint16_t>& utf16_data);
    const uint16_t* getUTF16Data() const;
    const char* getUTF8Data() const;
    const LDL_PodVector<uint16_t>& getUTF16Vector() const;
    const LDL_PodVector<char>& getUTF8Vector() const;
    void clear();
    bool hasUTF16() const;
    bool hasUTF8() const;

private:
    LDL_PodVector<uint16_t> utf16_buffer;
    LDL_PodVector<char>     utf8_buffer;
    uint32_t decodeUTF8Char(const char* utf8_str, size_t& pos, size_t max_len);
    void encodeUTF8Char(uint32_t code_point, LDL_PodVector<char>& output);
};

#endif
