// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <Arcanum/Allocators/ObjectAllocator.hpp>

using namespace LDL;
using namespace Arcanum;

Tile* ObjectAllocator::NewTile()
{
	return new Tile;
}

void ObjectAllocator::Delete(Tile* object)
{
	delete object;
}

Wall* ObjectAllocator::NewWall()
{
	return new Wall;
}

void ObjectAllocator::Delete(Wall* object)
{
	delete object;
}

Scenery* ObjectAllocator::NewScenery()
{
	return new Scenery;
}

void ObjectAllocator::Delete(Scenery* object)
{
	delete object;
}

Critter* ObjectAllocator::NewCritter()
{
	return new Critter;
}

void ObjectAllocator::Delete(Critter* object)
{
	delete object;
}
