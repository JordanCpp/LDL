#include <Arcanum/Objects/LocationCreator.hpp>

using namespace LDL;
using namespace Arcanum::Objects;
using namespace Arcanum::Managers;

LocationCreator::LocationCreator(LocationData* locationData, ObjectManager* objectManager) :
	_LocationData(locationData),
	_ObjectManager(objectManager)
{
}

void LocationCreator::Reset(const Vec2u& size)
{
	_LocationData->Reset(size);
}

void LocationCreator::NewTile(size_t index, const std::string& path)
{
	_ObjectManager->NewTile(_LocationData->TileObjects()[index], path);
}

Scenery* LocationCreator::NewScenery(const Vec2u& pos, const std::string& path)
{
	Scenery* result = _ObjectManager->NewScenery(path);

	result->Pos(pos);

	_LocationData->Append(result);

	return result;
}