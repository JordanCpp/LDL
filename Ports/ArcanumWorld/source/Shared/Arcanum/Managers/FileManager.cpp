// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <Arcanum/Managers/FileManager.hpp>
#include <LDL/Core/Directory.hpp>

using namespace LDL::Core;
using namespace Arcanum::Managers;
using namespace Arcanum::Readers;
using namespace Arcanum::Loaders;

FileManager::FileManager(PathManager* pathManager) :
	_pathManager(pathManager),
	_datLoader(&_archiveList),
	_memoryReader(&_byteReader)
{
	Result result;
	Directory directory(result);
	FileInfo fileInfo;

	if (directory.Open(directory.AllFiles()))
	{
		while (directory.Next(fileInfo))
		{
			if (strstr(fileInfo.Name(), ".dat") != NULL)
			{
				_archiveReader.Reset("", fileInfo.Name(), _archiveList);
			}
		}
	}
}

MemoryReader& FileManager::GetFile(const std::string& path)
{
	Result result;
	Directory directory(result);

	const char* filePath = _pathManager->NewFullPath("data/", path).c_str();

	if (directory.FileExist(filePath))
	{
		_memoryReader.Reset(filePath);

		return _memoryReader;
	}
	else
	{
		return _datLoader.GetFile(path);
	}
}
