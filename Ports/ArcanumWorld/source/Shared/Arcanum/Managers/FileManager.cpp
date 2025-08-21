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
	Directory directory;
	FileInfo fileInfo;

	if (directory.Open(directory.AllFiles()))
	{
		while (directory.Next(fileInfo))
		{
			if (fileInfo.Name().find(".dat") != std::string::npos)
			{
				_archiveReader.Reset("", fileInfo.Name(), _archiveList);
			}
		}
	}
}

MemoryReader& FileManager::GetFile(const std::string& path)
{
	Directory directory;

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