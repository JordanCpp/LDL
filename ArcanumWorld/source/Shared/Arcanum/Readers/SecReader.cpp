#include <Arcanum/Readers/SecReader.hpp>

using namespace Arcanum::Readers;
using namespace Arcanum::Formats;

SecReader::SecReader(ByteReader* byteReader) :
	_ByteReader(byteReader)
{
}

void SecReader::Reset(const std::string& path)
{
	_ByteReader->Reset(path, ByteReader::BigEndian);

	_Sec.lights.clear();
	_Sec.tiles.clear();
	_Sec.roofs.clear();

	ReadLights();
	ReadTiles();
	ReadRoofs();
}

void SecReader::ReadLights()
{
	_Sec.lights_count = _ByteReader->u32();

	Light light = { 0 };

	for (size_t i = 0; i < _Sec.lights_count; i++)
	{
		_ByteReader->Read(&light, sizeof(Light));
		_Sec.lights.push_back(light);
	}
}

void SecReader::ReadTiles()
{
	for (size_t i = 0; i < _Sec.MaxTiles; i++)
		_Sec.tiles.push_back(_ByteReader->u32());
}

void SecReader::ReadRoofs()
{
	for (size_t i = 0; i < _Sec.MaxRoffs; i++)
		_Sec.roofs.push_back(_ByteReader->u32());
}