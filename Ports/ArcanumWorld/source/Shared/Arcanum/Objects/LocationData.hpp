#ifndef Arcanum_Objects_LocationData_hpp
#define Arcanum_Objects_LocationData_hpp

#include <LDL/Graphics/Isometric.hpp>
#include <Arcanum/Objects/Tile.hpp>
#include <Arcanum/Objects/Critter.hpp>
#include <Arcanum/Objects/Scenery.hpp>
#include <Arcanum/Objects/Wall.hpp>

namespace Arcanum
{
	namespace Objects
	{
		class LocationData
		{
		public:
			LocationData();
			void Reset(const LDL::Math::Vec2u& size);
			void CalculateTiles();
			size_t Index(size_t x, size_t y);
			size_t Index(const LDL::Math::Vec2u& pos);
			const LDL::Math::Vec2u& Size();

			std::vector<Tile>& TileObjects();

			std::vector<Scenery*>& SceneryObjects();
			std::vector<Scenery*>& SceneryTiles();

			std::vector<Critter*>& CritterObjects();
			std::vector<Critter*>& CritterTiles();

			std::vector<Wall*>& WallObjects();
			std::vector<Wall*>& WallTiles();

			std::vector<CritterScript*>& CritterScripts();

			Scenery* GetScenery(const LDL::Math::Vec2u& pos);
			Tile* GetTile(const LDL::Math::Vec2u& pos);

			void Append(Scenery* object);
		private:
			LDL::Graphics::Isometric _Isometric;
			LDL::Math::Vec2u         _Size;

			std::vector<Tile>     _TileObjects;

			std::vector<Scenery*> _SceneryObjects;
			std::vector<Scenery*> _SceneryTiles;

			std::vector<Critter*> _CritterObjects;
			std::vector<Critter*> _CritterTiles;

			std::vector<Wall*>   _WallObjects;
			std::vector<Wall*>   _WallTiles;

			std::vector<CritterScript*> _CritterScripts;
		};
	}
}

#endif