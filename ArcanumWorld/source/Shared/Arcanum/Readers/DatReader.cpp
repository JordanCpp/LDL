#include <Arcanum/Readers/DatReader.hpp>
#include <string.h>
#include <zlib.h>

using namespace Arcanum::Readers;

bool DatReader::Reset(const std::string& dir, const std::string& file, DatList& archiveList)
{
	if (_File.is_open())
		_File.close();

	_FullPath.clear();
	_FullPath += dir;
	_FullPath += file;

	_File.open(_FullPath.c_str(), std::ios::binary);

	if (_File.is_open())
	{
		int treesubs   = 0;	
		int filestotal = 0;

		_File.seekg(-0x1Cl, std::ios::end);
		_File.seekg(16, std::ios::cur);
		_File.seekg(4, std::ios::cur);
		_File.seekg(4, std::ios::cur);
		_File.read((char*)&treesubs, 0x04);
		_File.seekg(-treesubs, std::ios::end);
		_File.read((char*)&filestotal, 0x04);

		for (int i = 1; i <= filestotal; i++)
		{
			DatItem item;

			_File.read((char*)&item.NameSize, 0x04);
			_File.read((char*)&item.Name    , item.NameSize);

			_PathNormalizer.Normalize(item.Name);

			_File.read((char*)&item.Unknown1  , 0x04);
			_File.read((char*)&item.Type      , 0x04);
			_File.read((char*)&item.RealSize  , 0x04);
			_File.read((char*)&item.PackedSize, 0x04);
			_File.read((char*)&item.Offset    , 0x04);
			strcpy(item.Archive, file.c_str());

			auto j = archiveList._List.find(item.Name);

			if (j == archiveList._List.end())
				archiveList._List.emplace(item.Name, item);
			else
				strcpy(j->second.Archive, file.c_str());
		}

		_File.close();

		return true;
	}

	return false;
}

DatItem* DatList::GetItem(const std::string& file)
{
	auto i = _List.find(file);

	if (i != _List.end())
		return &i->second;

	return nullptr;
}

DatItem::DatItem() :
	NameSize(0),
	Unknown1(0),
	Type(0),
	RealSize(0),
	PackedSize(0),
	Offset(0)
{
	memset(Name, 0, DatItem::MaxPath);
	memset(Archive, 0, DatItem::MaxName);
}