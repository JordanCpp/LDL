// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <Arcanum/Readers/SecReader.hpp>

using namespace Arcanum::Readers;
using namespace Arcanum::Formats;

SecReader::SecReader(ByteReader* byteReader) :
	_byteReader(byteReader)
{
}

void SecReader::Reset(const std::string& path)
{
	_byteReader->Reset(path, ByteReader::BigEndian);

	_sec.lights.clear();
	_sec.tiles.clear();
	_sec.roofs.clear();

	ReadLights();
	ReadTiles();
	ReadRoofs();
}

void SecReader::ReadLights()
{
	_sec.lights_count = _byteReader->u32();

	Light light = { 0 };

	for (size_t i = 0; i < _sec.lights_count; i++)
	{
		_byteReader->Read(&light, sizeof(Light));
		_sec.lights.push_back(light);
	}
}

void SecReader::ReadTiles()
{
	for (size_t i = 0; i < _sec.MaxTiles; i++)
		_sec.tiles.push_back(_byteReader->u32());
}

void SecReader::ReadRoofs()
{
	for (size_t i = 0; i < _sec.MaxRoffs; i++)
		_sec.roofs.push_back(_byteReader->u32());
}