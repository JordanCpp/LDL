#ifndef Arcanum_Managers_ObjectManager_hpp
#define Arcanum_Managers_ObjectManager_hpp

#include <Arcanum/Objects/Tile.hpp>
#include <Arcanum/Allocators/ObjectAllocator.hpp>
#include <Arcanum/Managers/SpriteManager.hpp>

namespace Arcanum
{
	namespace Managers
	{
		class ObjectManager
		{
		public:
			ObjectManager(Allocators::ObjectAllocator* objectAllocator, SpriteManager* spriteManager);
			Objects::Scenery* NewScenery(const std::string& name);
			void NewTile(Objects::Tile& object, const std::string& name);
		private:
			Allocators::ObjectAllocator* _objectAllocator;
			SpriteManager*               _spriteManager;
		};
	}
}

#endif    