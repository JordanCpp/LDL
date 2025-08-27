// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Managers_FileManager_hpp
#define Arcanum_Managers_FileManager_hpp

#include <Arcanum/Managers/PathManager.hpp>
#include <Arcanum/Readers/MemoryReader.hpp>

namespace Arcanum
{
	class FileManager
	{
	public:
		FileManager(PathManager* pathManager);
		MemoryReader& GetFile(const std::string& path);
	private:
		PathManager*  _pathManager;
		ByteReader    _byteReader;
		MemoryReader  _memoryReader;
	};
}

#endif
