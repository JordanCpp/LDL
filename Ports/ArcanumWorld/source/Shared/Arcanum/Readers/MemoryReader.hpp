// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Readers_MemoryReader_hpp
#define Arcanum_Readers_MemoryReader_hpp

#include <Arcanum/Readers/ByteReader.hpp>
#include <vector>

namespace Arcanum
{
    namespace Readers
    {
        class MemoryReader
        {
        public:
            MemoryReader(ByteReader* byteReader);
            void Close();
            bool Reset(const std::string& path);
            bool Reset(const std::vector<uint8_t>& data);
            std::vector<uint8_t>& Content();
            void Read(void* buffer, size_t bytes);
        private:
            ByteReader*          _byteReader;
            size_t               _offset;
            std::vector<uint8_t> _content;
        };
    }
}

#endif