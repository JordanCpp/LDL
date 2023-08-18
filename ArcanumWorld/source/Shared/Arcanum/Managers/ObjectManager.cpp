#include <Arcanum/Managers/ObjectManager.hpp>

using namespace Arcanum::Allocators;
using namespace Arcanum::Managers;
using namespace Arcanum::Objects;

ObjectManager::ObjectManager(ObjectAllocator* objectAllocator, SpriteManager* spriteManager) :
	_ObjectAllocator(objectAllocator),
	_SpriteManager(spriteManager)
{
}

Scenery* ObjectManager::NewScenery(const std::string& name)
{
	Scenery* result = _ObjectAllocator->NewScenery();

	result->Init(_SpriteManager->GetScenery(name));

	return result;
}

void ObjectManager::NewTile(Tile& object, const std::string& name)
{
	object.Init(_SpriteManager->GetTile(name));
}