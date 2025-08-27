// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <Arcanum/Managers/FileManager.hpp>

using namespace Arcanum;

FileManager::FileManager(PathManager* pathManager) :
	_pathManager(pathManager),
	_memoryReader(&_byteReader)
{
}

MemoryReader& FileManager::GetFile(const std::string& path)
{
	const char* filePath = _pathManager->NewFullPath("data/", path).c_str();
	
	_memoryReader.Reset(filePath);
	
	return _memoryReader;
}
