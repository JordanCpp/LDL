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

bool LocationReader::Load(const std::string& path, Location& location)
{
	_file = fopen(path.c_str(), "r");

	if (!_file)
	{
		_result.AddMessage("Error load file: " + path);
		return false;
	}

	if (fscanf(_file, "Width %d\n", &location.Size.x) != 1)
	{
		_result.AddMessage("Error read: Width " + path);
		fclose(_file);
		return false;
	}

	if (fscanf(_file, "Height %d\n", &location.Size.y) != 1)
	{
		_result.AddMessage("Error read: Height " + path);
		fclose(_file);
		return false;
	}

	location.Tiles.resize(location.Size.x * location.Size.y);

	size_t objects = 0;

	if (fscanf(_file, "Objects %d\n", &objects) != 1)
	{
		_result.AddMessage("Error read: Objects " + path);
		fclose(_file);
		return false;
	}

	for (size_t i = 0; i < location.Size.x * location.Size.y; i++)
	{
		char pathString[256] = { 0 };

		if (fscanf(_file, "Tile %s\n", pathString) != 1)
		{
			_result.AddMessage("Error read: Tile " + path);
			fclose(_file);
			return false;
		}

		location.Tiles[i]._spriteName = pathString;
	}

	for (size_t j = 0; j < objects; j++)
	{
		char pathString[256] = { 0 };

		if (fscanf(_file, "Object %s\n", pathString) != 1)
		{
			_result.AddMessage("Error read: Object " + path);
			fclose(_file);
			return false;
		}

		int hex = 0;

		if (fscanf(_file, "Hex %d\n", &hex) != 1)
		{
			_result.AddMessage("Error read: Hex " + path);
			fclose(_file);
			return false;
		}

		MapObject object;
		object._hex        = hex;
		object._spriteName = pathString;

		location.Objects.push_back(object);
	}

	fclose(_file);

	return _result.IsOk();
}
