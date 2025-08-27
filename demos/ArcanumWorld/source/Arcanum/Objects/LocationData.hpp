// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Objects_LocationData_hpp
#define Arcanum_Objects_LocationData_hpp

#include <LDL/Math/Isometric.hpp>
#include <Arcanum/Objects/Tile.hpp>
#include <Arcanum/Objects/Critter.hpp>
#include <Arcanum/Objects/Scenery.hpp>
#include <Arcanum/Objects/Wall.hpp>

namespace Arcanum
{
	class LocationData
	{
	public:
		LocationData();
		void Reset(const LDL::Vec2u& size);
		void CalculateTiles();
		size_t Index(size_t x, size_t y);
		size_t Index(const LDL::Vec2u& pos);
		const LDL::Vec2u& Size();

		std::vector<Tile>& TileObjects();

		std::vector<Scenery*>& SceneryObjects();
		std::vector<Scenery*>& SceneryTiles();

		std::vector<Critter*>& CritterObjects();
		std::vector<Critter*>& CritterTiles();

		std::vector<Wall*>& WallObjects();
		std::vector<Wall*>& WallTiles();

		std::vector<CritterScript*>& CritterScripts();

		Scenery* GetScenery(const LDL::Vec2u& pos);
		Tile* GetTile(const LDL::Vec2u& pos);

		void Append(Scenery* object);
	private:
		LDL::Isometric              _isometric;
		LDL::Vec2u                  _size;
		std::vector<Tile>           _tileObjects;
		std::vector<Scenery*>       _sceneryObjects;
		std::vector<Scenery*>       _sceneryTiles;
		std::vector<Critter*>       _critterObjects;
		std::vector<Critter*>       _critterTiles;
		std::vector<Wall*>          _wallObjects;
		std::vector<Wall*>          _wallTiles;
		std::vector<CritterScript*> _critterScripts;
	};
}

#endif
