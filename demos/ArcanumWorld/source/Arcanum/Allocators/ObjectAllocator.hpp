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
	class ObjectAllocator
	{
	public:
		Tile* NewTile();
		void Delete(Tile* object);

		Wall* NewWall();
		void Delete(Wall* object);

		Scenery* NewScenery();
		void Delete(Scenery* object);

		Critter* NewCritter();
		void Delete(Critter* object);
	};
}

#endif
