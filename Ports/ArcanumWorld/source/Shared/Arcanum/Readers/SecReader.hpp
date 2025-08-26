// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Readers_SecReader_hpp
#define Arcanum_Readers_SecReader_hpp

#include <Arcanum/Readers/ByteReader.hpp>
#include <Arcanum/Formats/Sec.hpp>

namespace Arcanum
{
    namespace Readers
    {
        class SecReader
        {
        public:
            SecReader(ByteReader* byteReader);
            void Reset(const std::string& path);
            void ReadLights();
            void ReadTiles();
            void ReadRoofs();
        private:
            ByteReader*  _byteReader;
            Formats::Sec _sec;
        };
    }
}

#endif