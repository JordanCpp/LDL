#ifndef Arcanum_Managers_FileManager_hpp
#define Arcanum_Managers_FileManager_hpp

#include <Arcanum/Managers/PathManager.hpp>
#include <Arcanum/Loaders/DatLoader.hpp>

namespace Arcanum
{
	namespace Managers
	{
		class FileManager
		{
		public:
			FileManager(Managers::PathManager* pathManager);
			Readers::MemoryReader& GetFile(const std::string& path);
		private:
			Managers::PathManager* _PathManager;
			Readers::DatList       _ArchiveList;
			Readers::DatReader     _ArchiveReader;
			Loaders::DatLoader     _DatLoader;
			Readers::ByteReader    _ByteReader;
			Readers::MemoryReader  _MemoryReader;
		};
	}
}

#endif