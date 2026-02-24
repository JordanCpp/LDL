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
		Objects::Tile* NewTile();
		void Delete(Objects::Tile* object);

		Objects::Wall* NewWall();
		void Delete(Objects::Wall* object);

		Objects::Scenery* NewScenery();
		void Delete(Objects::Scenery* object);

		Objects::Critter* NewCritter();
		void Delete(Objects::Critter* object);
	private:
		LDL::ObjectPool<Objects::Tile, Objects::LocationLimits::Tiles>        _tilePool;
		LDL::ObjectPool<Objects::Wall, Objects::LocationLimits::Walls>        _wallPool;
		LDL::ObjectPool<Objects::Scenery, Objects::LocationLimits::Sceneries> _sceneryPool;
		LDL::ObjectPool<Objects::Critter, Objects::LocationLimits::Critters>  _critterPool;
	};
}

#endif