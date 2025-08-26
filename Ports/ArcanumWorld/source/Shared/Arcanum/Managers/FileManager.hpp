// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

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
			Managers::PathManager* _pathManager;
			Readers::DatList       _archiveList;
			Readers::DatReader     _archiveReader;
			Loaders::DatLoader     _datLoader;
			Readers::ByteReader    _byteReader;
			Readers::MemoryReader  _memoryReader;
		};
	}
}

#endif