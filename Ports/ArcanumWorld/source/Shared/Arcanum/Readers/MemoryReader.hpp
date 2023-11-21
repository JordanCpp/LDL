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
            size_t _Offset;
            ByteReader* _ByteReader;
            std::vector<uint8_t> _Content;
        };
    }
}

#endif