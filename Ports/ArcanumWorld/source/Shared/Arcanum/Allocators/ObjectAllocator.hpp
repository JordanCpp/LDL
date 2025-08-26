// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Allocators_ObjectAllocator_hpp
#define Arcanum_Allocators_ObjectAllocator_hpp

#include <LDL/LDL.hpp>
#include <Arcanum/Objects/LocationLimits.hpp>
#include <Arcanum/Objects/Critter.hpp>
#include <Arcanum/Objects/Scenery.hpp>
#include <Arcanum/Objects/Wall.hpp>
#include <Arcanum/Objects/Tile.hpp>

namespace Arcanum
{
	namespace Allocators
	{
		class ObjectAllocator
		{
		public:
			Objects::Tile* NewTile();
			void Delete(Objects::Tile* object);

			Objects::Wall* NewWall();
			void Delete(Objects::Wall* object);

			Objects::Scenery* NewScenery();
			void Delete(Objects::Scenery* object);

			Objects::Critter* NewCritter();
			void Delete(Objects::Critter* object);
		private:
			LDL::Allocators::ObjectPool<Objects::Tile, Objects::LocationLimits::Tiles>        _tilePool;
			LDL::Allocators::ObjectPool<Objects::Wall, Objects::LocationLimits::Walls>        _wallPool;
			LDL::Allocators::ObjectPool<Objects::Scenery, Objects::LocationLimits::Sceneries> _sceneryPool;
			LDL::Allocators::ObjectPool<Objects::Critter, Objects::LocationLimits::Critters>  _critterPool;
		};
	}
}

#endif