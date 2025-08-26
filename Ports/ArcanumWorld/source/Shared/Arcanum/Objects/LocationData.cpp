// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <Arcanum/Objects/LocationData.hpp>
#include <Arcanum/Objects/LocationLimits.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;
using namespace Arcanum::Objects;

LocationData::LocationData()
{
	_TileObjects.reserve(LocationLimits::Tiles);

	_SceneryTiles.reserve(LocationLimits::Sceneries);
	_SceneryObjects.reserve(LocationLimits::Sceneries);

	_CritterTiles.reserve(LocationLimits::Critters);
	_CritterObjects.reserve(LocationLimits::Critters);

	_WallTiles.reserve(LocationLimits::Walls);
	_WallObjects.reserve(LocationLimits::Walls);
}

void LocationData::Reset(const Vec2u& size)
{
    _Size = size;

	size_t sz = _Size.x * _Size.y;

    _TileObjects.resize(sz);
	_SceneryTiles.resize(sz);
	_CritterTiles.resize(sz);
	_WallTiles.reserve(sz);

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

			Vec2u pt = _Isometric.CartesianToIsometric(Vec2u(dx, dy));

			size_t index = Index(x, y);
			
			TileObjects()[index].Pos(pt);
		}
	}
}

size_t LocationData::Index(size_t x, size_t y)
{
    return (_Size.x * y) + x;
}

size_t LocationData::Index(const Vec2u& pos)
{
	return Index(pos.x, pos.y);
}

const Vec2u& LocationData::Size()
{
    return _Size;
}

std::vector<Tile>& LocationData::TileObjects()
{
    return _TileObjects;
}

std::vector<Scenery*>& LocationData::SceneryObjects()
{
    return _SceneryObjects;
}

std::vector<Scenery*>& LocationData::SceneryTiles()
{
	return _SceneryTiles;
}

std::vector<Critter*>& LocationData::CritterObjects()
{
	return _CritterObjects;
}

std::vector<Critter*>& LocationData::CritterTiles()
{
	return _CritterTiles;
}

std::vector<Wall*>& LocationData::WallObjects()
{
	return _WallObjects;
}

std::vector<Wall*>& LocationData::WallTiles()
{
	return _WallTiles;
}

std::vector<CritterScript*>& LocationData::CritterScripts()
{
	return _CritterScripts;
}

Scenery* LocationData::GetScenery(const Vec2u& pos)
{
	return _SceneryObjects.at(Index(pos.x, pos.y));
}

Tile* LocationData::GetTile(const Vec2u& pos)
{
	return &_TileObjects.at(Index(pos.x, pos.y));
}

void LocationData::Append(Scenery* object)
{
	_SceneryObjects.push_back(object);
}