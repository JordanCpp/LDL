#ifndef Arcanum_Readers_DatReader_hpp
#define Arcanum_Readers_DatReader_hpp

#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <Arcanum/Core/PathNormalizer.hpp>

namespace Arcanum
{
    namespace Readers
    {
        class DatItem
        {
        public:
            enum
            {
                Uncompressed = 0x01,
                Compressed   = 0x02,
                MaxPath      = 128,
                MaxName      = 64
            };

            DatItem();

            int  NameSize;
            char Name[MaxPath];
            int  Unknown1;
            int  Type;
            int  RealSize;
            int  PackedSize;
            int  Offset;
            char Archive[MaxName];
        };

        class DatList
        {
        public:
            DatItem* GetItem(const std::string& file);
            std::unordered_map<std::string, DatItem> _List;
        };

        class DatReader
        {
        public:
            bool Reset(const std::string& dir, const std::string& file, DatList& archiveList);
        private:
            Core::PathNormalizer _PathNormalizer;
            std::string _FullPath;
            std::ifstream _File;
        };
    }
}

#endif