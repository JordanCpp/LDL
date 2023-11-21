#ifndef Arcanum_Objects_LocationCreator_hpp
#define Arcanum_Objects_LocationCreator_hpp

#include <Arcanum/Objects/LocationData.hpp>
#include <Arcanum/Managers/ObjectManager.hpp>

namespace Arcanum
{
	namespace Objects
	{
		class LocationCreator
		{
		public:
			LocationCreator(LocationData * locationData, Managers::ObjectManager* objectManager);
			void Reset(const LDL::Math::Vec2u& size);
			void NewTile(size_t index, const std::string& path);
			Scenery* NewScenery(const LDL::Math::Vec2u& pos, const std::string& path);
		private:
			LocationData* _LocationData;
			Managers::ObjectManager* _ObjectManager;
		};
	}
}

#endif