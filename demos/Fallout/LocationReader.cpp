/*
Copyright(C) 2026 Evgeny Zoshchuk (JordanCpp)

This library is free software; you can redistribute it and /or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.See the GNU Lesser General Public
License for more details.
*/

#include "LocationReader.hpp"

using namespace LDL;
using namespace Fallout;

LocationReader::LocationReader(LDL::Result& result) :
	_result(result),
	_file(NULL)
{
}

bool LocationReader::Load(const std::string& path, LocationData& locationData)
{
	_file = fopen(path.c_str(), "r");

	if (!_file)
	{
		_result.AddMessage("Error load file: " + path);
		return _result.IsOk();
	}

	if (fscanf(_file, "Width %d\n", &locationData.Size.x) != 1)
	{
		_result.AddMessage("Error read: Width " + path);
		return _result.IsOk();
	}

	if (fscanf(_file, "Height %d\n", &locationData.Size.y) != 1)
	{
		_result.AddMessage("Error read: Height " + path);
		return _result.IsOk();
	}

	locationData.Tiles.resize(locationData.Size.x * locationData.Size.y);

	for (size_t i = 0; i < locationData.Size.x * locationData.Size.y; i++)
	{
		char pathString[256] = { 0 };

		if (fscanf(_file, "Tile %s\n", pathString) != 1)
		{
			_result.AddMessage("Error read: Tile " + path);
			return _result.IsOk();
		}

		locationData.Tiles[i]._spriteName = pathString;
	}

	fclose(_file);

	return _result.IsOk();
}
