#include <Arcanum/Managers/ObjectManager.hpp>

using namespace Arcanum;
using namespace Arcanum::Managers;
using namespace Arcanum::Objects;

ObjectManager::ObjectManager(ObjectAllocator* objectAllocator, SpriteManager* spriteManager) :
	_objectAllocator(objectAllocator),
	_spriteManager(spriteManager)
{
}

Scenery* ObjectManager::NewScenery(const std::string& name)
{
	Scenery* result = _objectAllocator->NewScenery();

	result->Init(_spriteManager->GetScenery(name));

	return result;
}

void ObjectManager::NewTile(Tile& object, const std::string& name)
{
	object.Init(_spriteManager->GetTile(name));
}