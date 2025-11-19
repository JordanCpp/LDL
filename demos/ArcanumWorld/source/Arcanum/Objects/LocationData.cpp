// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <Arcanum/Objects/LocationData.hpp>
#include <Arcanum/Objects/LocationLimits.hpp>

using namespace Arcanum;

LocationData::LocationData()
{
	_tileObjects.reserve(LocationLimits::Tiles);

	_sceneryTiles.reserve(LocationLimits::Sceneries);
	_sceneryObjects.reserve(LocationLimits::Sceneries);

	_critterTiles.reserve(LocationLimits::Critters);
	_critterObjects.reserve(LocationLimits::Critters);

	_wallTiles.reserve(LocationLimits::Walls);
	_wallObjects.reserve(LocationLimits::Walls);
}

void LocationData::Reset(const LDL_Vec2u& size)
{
    _size = size;

	size_t sz = _size.x * _size.y;

    _tileObjects.resize(sz);
	_sceneryTiles.resize(sz);
	_critterTiles.resize(sz);
	_wallTiles.reserve(sz);

	CalculateTiles();
}

void LocationData::CalculateTiles()
{
	for (uint32_t x = 0; x < Size().x; x++)
	{
		for (uint32_t y = 0; y < Size().y; y++)
		{
			uint32_t dx = y * Tile::Width / 2;
			uint32_t dy = x * Tile::Height;

			LDL_Vec2u pt = _isometric.CartesianToIsometric(LDL_Vec2u(dx, dy));

			size_t index = Index(x, y);
			
			TileObjects()[index].Pos(pt);
		}
	}
}

size_t LocationData::Index(size_t x, size_t y)
{
    return (_size.x * y) + x;
}

size_t LocationData::Index(const LDL_Vec2u& pos)
{
	return Index(pos.x, pos.y);
}

const LDL_Vec2u& LocationData::Size()
{
    return _size;
}

std::vector<Tile>& LocationData::TileObjects()
{
    return _tileObjects;
}

std::vector<Scenery*>& LocationData::SceneryObjects()
{
    return _sceneryObjects;
}

std::vector<Scenery*>& LocationData::SceneryTiles()
{
	return _sceneryTiles;
}

std::vector<Critter*>& LocationData::CritterObjects()
{
	return _critterObjects;
}

std::vector<Critter*>& LocationData::CritterTiles()
{
	return _critterTiles;
}

std::vector<Wall*>& LocationData::WallObjects()
{
	return _wallObjects;
}

std::vector<Wall*>& LocationData::WallTiles()
{
	return _wallTiles;
}

std::vector<CritterScript*>& LocationData::CritterScripts()
{
	return _critterScripts;
}

Scenery* LocationData::GetScenery(const LDL_Vec2u& pos)
{
	return _sceneryObjects.at(Index(pos.x, pos.y));
}

Tile* LocationData::GetTile(const LDL_Vec2u& pos)
{
	return &_tileObjects.at(Index(pos.x, pos.y));
}

void LocationData::Append(Scenery* object)
{
	_sceneryObjects.push_back(object);
}
