#include <Arcanum/Allocators/ObjectAllocator.hpp>

using namespace LDL;
using namespace Arcanum;
using namespace Arcanum::Objects;

Tile* ObjectAllocator::NewTile()
{
	Tile* result = _tilePool.New();

	return new(result) Tile;
}

void ObjectAllocator::Delete(Tile* object)
{
	_tilePool.Delete(object);
}

Wall* ObjectAllocator::NewWall()
{
	Wall* result = _wallPool.New();

	return new(result) Wall;
}

void ObjectAllocator::Delete(Wall* object)
{
	_wallPool.Delete(object);
}

Scenery* ObjectAllocator::NewScenery()
{
	Scenery* result = _sceneryPool.New();

	return new(result) Scenery;
}

void ObjectAllocator::Delete(Scenery* object)
{
	_sceneryPool.Delete(object);
}

Critter* ObjectAllocator::NewCritter()
{
	Critter* result = _critterPool.New();

	return new(result) Critter;
}

void ObjectAllocator::Delete(Critter* object)
{
	_critterPool.Delete(object);
}