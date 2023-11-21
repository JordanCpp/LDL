#include <Arcanum/Allocators/ObjectAllocator.hpp>

using namespace LDL::Allocators;
using namespace Arcanum::Allocators;
using namespace Arcanum::Objects;

Tile* ObjectAllocator::NewTile()
{
	Tile* result = _TilePool.New();

	return new(result) Tile;
}

void ObjectAllocator::Delete(Tile* object)
{
	_TilePool.Delete(object);
}

Wall* ObjectAllocator::NewWall()
{
	Wall* result = _WallPool.New();

	return new(result) Wall;
}

void ObjectAllocator::Delete(Wall* object)
{
	_WallPool.Delete(object);
}

Scenery* ObjectAllocator::NewScenery()
{
	Scenery* result = _SceneryPool.New();

	return new(result) Scenery;
}

void ObjectAllocator::Delete(Scenery* object)
{
	_SceneryPool.Delete(object);
}

Critter* ObjectAllocator::NewCritter()
{
	Critter* result = _CritterPool.New();

	return new(result) Critter;
}

void ObjectAllocator::Delete(Critter* object)
{
	_CritterPool.Delete(object);
}