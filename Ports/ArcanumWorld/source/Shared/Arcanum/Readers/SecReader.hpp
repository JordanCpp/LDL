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
            Sec          _sec;
        };
    }
}

#endif