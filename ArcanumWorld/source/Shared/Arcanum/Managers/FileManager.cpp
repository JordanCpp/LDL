#include <Arcanum/Managers/FileManager.hpp>
#include <LDL/Core/Directory.hpp>

using namespace LDL::Core;
using namespace Arcanum::Managers;
using namespace Arcanum::Readers;
using namespace Arcanum::Loaders;

FileManager::FileManager(PathManager* pathManager) :
	_PathManager(pathManager),
	_DatLoader(&_ArchiveList),
	_MemoryReader(&_ByteReader)
{
	Directory directory;
	FileInfo fileInfo;

	if (directory.Open(directory.AllFiles()))
	{
		while (directory.Next(fileInfo))
		{
			if (fileInfo.Name().find(".dat") != std::string::npos)
			{
				_ArchiveReader.Reset("", fileInfo.Name(), _ArchiveList);
			}
		}
	}
}

MemoryReader& FileManager::GetFile(const std::string& path)
{
	Directory directory;

	const char* filePath = _PathManager->NewFullPath("data/", path).c_str();

	if (directory.Exist(filePath))
	{
		_MemoryReader.Reset(filePath);

		return _MemoryReader;
	}
	else
	{
		return _DatLoader.GetFile(path);
	}
}