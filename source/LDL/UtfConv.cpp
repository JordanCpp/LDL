// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/UtfConv.hpp>

uint32_t LDL_UtfConverter::decodeUTF8Char(const char* utf8_str, size_t& pos, size_t max_len) 
{
    if (pos >= max_len) return 0xFFFFFFFF;

    unsigned char c = utf8_str[pos];

    uint32_t code_point = 0;

    if ((c & 0x80) == 0x00) 
    {
        code_point = c;
        pos += 1;
    }
    else if ((c & 0xE0) == 0xC0 && pos + 1 < max_len)
    {
        unsigned char c2 = utf8_str[pos + 1];

        if ((c2 & 0xC0) == 0x80) 
        {
            code_point = ((c & 0x1F) << 6) | (c2 & 0x3F);
            pos += 2;
        }
        else 
        {
            pos += 1;
            return 0xFFFD;
        }
    }
    else if ((c & 0xF0) == 0xE0 && pos + 2 < max_len) 
    {
        unsigned char c2 = utf8_str[pos + 1];
        unsigned char c3 = utf8_str[pos + 2];

        if ((c2 & 0xC0) == 0x80 && (c3 & 0xC0) == 0x80)
        {
            code_point = ((c & 0x0F) << 12) | ((c2 & 0x3F) << 6) | (c3 & 0x3F);
            pos += 3;
        }
        else 
        {
            pos += 1;
            return 0xFFFD;
        }
    }
    else if ((c & 0xF8) == 0xF0 && pos + 3 < max_len) 
    {
        unsigned char c2 = utf8_str[pos + 1];
        unsigned char c3 = utf8_str[pos + 2];
        unsigned char c4 = utf8_str[pos + 3];

        if ((c2 & 0xC0) == 0x80 && (c3 & 0xC0) == 0x80 && (c4 & 0xC0) == 0x80) 
        {
            code_point = ((c & 0x07) << 18) | ((c2 & 0x3F) << 12) | ((c3 & 0x3F) << 6) | (c4 & 0x3F);
            pos += 4;
        }
        else
        {
            pos += 1;
            return 0xFFFD;
        }
    }
    else 
    {
        pos += 1;
        return 0xFFFD;
    }

    return code_point;
}

void LDL_UtfConverter::encodeUTF8Char(uint32_t code_point, LDL_Vector<char>& output) 
{
    if (code_point <= 0x7F) 
    {
        output.push_back(static_cast<char>(code_point));
    }
    else if (code_point <= 0x7FF) 
    {
        output.push_back(static_cast<char>(0xC0 | ((code_point >> 6) & 0x1F)));
        output.push_back(static_cast<char>(0x80 | (code_point & 0x3F)));
    }
    else if (code_point <= 0xFFFF) 
    {
        output.push_back(static_cast<char>(0xE0 | ((code_point >> 12) & 0x0F)));
        output.push_back(static_cast<char>(0x80 | ((code_point >> 6) & 0x3F)));
        output.push_back(static_cast<char>(0x80 | (code_point & 0x3F)));
    }
    else if (code_point <= 0x10FFFF) 
    {
        output.push_back(static_cast<char>(0xF0 | ((code_point >> 18) & 0x07)));
        output.push_back(static_cast<char>(0x80 | ((code_point >> 12) & 0x3F)));
        output.push_back(static_cast<char>(0x80 | ((code_point >> 6) & 0x3F)));
        output.push_back(static_cast<char>(0x80 | (code_point & 0x3F)));
    }
    else 
    {
        output.push_back(0xEF);
        output.push_back(0xBF);
        output.push_back(0xBD);
    }
}


LDL_UtfConverter::LDL_UtfConverter()
{
}

bool LDL_UtfConverter::convertToUTF16(const char* utf8_str)
{
    utf16_buffer.clear();
    if (!utf8_str) return false;

    size_t len = 0;
    while (utf8_str[len] != '\0') len++;

    if (len == 0) {
        utf16_buffer.push_back(0);
        return true;
    }

    size_t pos = 0;
    while (pos < len) 
    {
        uint32_t code_point = decodeUTF8Char(utf8_str, pos, len);

        if (code_point == 0xFFFFFFFF) break;

        if (code_point <= 0xFFFF)
        {
            utf16_buffer.push_back(static_cast<uint16_t>(code_point));
        }
        else if (code_point <= 0x10FFFF) 
        {
            code_point -= 0x10000;
            uint16_t high_surrogate = 0xD800 | static_cast<uint16_t>((code_point >> 10) & 0x3FF);
            uint16_t low_surrogate = 0xDC00 | static_cast<uint16_t>(code_point & 0x3FF);
            utf16_buffer.push_back(high_surrogate);
            utf16_buffer.push_back(low_surrogate);
        }
        else 
        {
            utf16_buffer.push_back(0xFFFD);
        }
    }

    utf16_buffer.push_back(0);

    return true;
}

bool LDL_UtfConverter::convertToUTF8(const uint16_t* utf16_str, size_t utf16_len) 
{
    utf8_buffer.clear();
    if (!utf16_str) return false;

    size_t len = utf16_len;
    if (len == 0) 
    {
        while (utf16_str[len] != 0) len++;
    }

    if (len == 0)
    {
        utf8_buffer.push_back(0);
        return true;
    }

    for (size_t i = 0; i < len; i++) 
    {
        uint16_t code_unit = utf16_str[i];

        if (code_unit >= 0xD800 && code_unit <= 0xDBFF && i + 1 < len) 
        {
            uint16_t high_surrogate = code_unit;
            uint16_t low_surrogate = utf16_str[i + 1];

            if (low_surrogate >= 0xDC00 && low_surrogate <= 0xDFFF)
            {
                uint32_t code_point = 0x10000 + ((high_surrogate & 0x3FF) << 10) + (low_surrogate & 0x3FF);
                encodeUTF8Char(code_point, utf8_buffer);
                i++;
            }
            else 
            {
                encodeUTF8Char(0xFFFD, utf8_buffer);
            }
        }
        else if (code_unit >= 0xDC00 && code_unit <= 0xDFFF)
        {
            encodeUTF8Char(0xFFFD, utf8_buffer);
        }
        else 
        {
            encodeUTF8Char(code_unit, utf8_buffer);
        }
    }

    utf8_buffer.push_back(0);

    return true;
}

bool LDL_UtfConverter::convertToUTF8(const LDL_Vector<uint16_t>& utf16_data) 
{
    if (utf16_data.empty()) return false;

    return convertToUTF8(&utf16_data[0], utf16_data.size());
}

const uint16_t* LDL_UtfConverter::getUTF16Data() const 
{
    return utf16_buffer.empty() ? NULL : &utf16_buffer[0];
}

const char* LDL_UtfConverter::getUTF8Data() const
{
    return utf8_buffer.empty() ? NULL : &utf8_buffer[0];
}

const LDL_Vector<uint16_t>& LDL_UtfConverter::getUTF16Vector() const
{
    return utf16_buffer;
}

const LDL_Vector<char>& LDL_UtfConverter::getUTF8Vector() const 
{
    return utf8_buffer;
}

void LDL_UtfConverter::clear() 
{
    utf16_buffer.clear();
    utf8_buffer.clear();
}

bool LDL_UtfConverter::hasUTF16() const
{
    return !utf16_buffer.empty();
}

bool LDL_UtfConverter::hasUTF8() const 
{
    return !utf8_buffer.empty();
}
