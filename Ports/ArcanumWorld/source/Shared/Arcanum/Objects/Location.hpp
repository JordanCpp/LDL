#ifndef Arcanum_Objects_Location_hpp
#define Arcanum_Objects_Location_hpp

#include <Arcanum/Objects/LocationData.hpp>
#include <Arcanum/Managers/ObjectManager.hpp>
#include <Arcanum/Painters/LocationPainter.hpp>
#include <Arcanum/Objects/LocationCreator.hpp>

namespace Arcanum
{
	namespace Objects
	{
		class Location
		{
		public:
			Location(LocationData* locationData, LocationCreator* locationCreator, Painters::LocationPainter* locationPainter);
			void Draw(const LDL::Vec2u& start);
			Scenery* NewScenery(const LDL::Vec2u& pos, const std::string& path);
			Tile* NewTile(const LDL::Vec2u& pos, const std::string& path);
		private:
			LocationData* _LocationData;
			LocationCreator* _LocationCreator;
			Painters::LocationPainter* _LocationPainter;
		};
	}
}

#endif