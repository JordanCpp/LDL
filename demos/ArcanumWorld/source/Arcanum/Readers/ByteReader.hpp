// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Readers_ByteReader_hpp
#define Arcanum_Readers_ByteReader_hpp

#include <LDL/LDL.hpp>
#include <iostream>
#include <fstream>
#include <string>

namespace Arcanum
{
    class ByteReader
    {
    public:
        enum
        {
            BigEndian,
            LittleEndian
        };

        bool Reset(const std::string& path, size_t type);
        void Close();
        ~ByteReader();
        size_t Bytes();
        bool Eof();
        uint8_t u8();
        uint16_t u16();
        uint32_t u32();
        int16_t i16();
        int32_t i32();
        void Pos(size_t value);
        void Read(void* buffer, size_t bytes);
    private:
        size_t       _type;
        size_t       _bytes;
        std::fstream _file;
    };
}

#endif
