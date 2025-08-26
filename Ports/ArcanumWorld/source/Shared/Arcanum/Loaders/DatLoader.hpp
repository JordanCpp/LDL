// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Loaders_DatLoader_hpp
#define Arcanum_Loaders_DatLoader_hpp

#include <fstream>
#include <Arcanum/Readers/DatReader.hpp>
#include <Arcanum/Readers/MemoryReader.hpp>

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
			std::fstream          _File;
			std::vector<uint8_t>  _Result;
			std::vector<uint8_t>  _Buffer;
			Readers::DatList*     _ArchiveList;
			Readers::ByteReader   _ByteReader;
			Readers::MemoryReader _MemoryReader;
		};
	}
}

#endif    