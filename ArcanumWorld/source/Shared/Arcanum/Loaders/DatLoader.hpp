#ifndef Arcanum_Loaders_DatLoader_hpp
#define Arcanum_Loaders_DatLoader_hpp

#include <fstream>
#include <Arcanum/Readers/DatReader.hpp>
#include <Arcanum/Readers/MemoryReader.hpp>
#include <Arcanum/Readers/DatReader.hpp>

namespace Arcanum
{
	namespace Loaders
	{
		class DatLoader
		{
		public:
			enum
			{
				Bytes = 1024 * 1024
			};
			DatLoader(Readers::DatList* archiveList);
			std::vector<uint8_t>& GetData(const std::string& path);
			Readers::MemoryReader& GetFile(const std::string& path);
		private:
			std::ifstream         _File;
			std::vector<uint8_t>  _Result;
			std::vector<uint8_t>  _Buffer;
			Readers::DatList*     _ArchiveList;
			Readers::ByteReader   _ByteReader;
			Readers::MemoryReader _MemoryReader;
		};
	}
}

#endif    