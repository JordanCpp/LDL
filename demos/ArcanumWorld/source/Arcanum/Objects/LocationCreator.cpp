// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <Arcanum/Objects/LocationCreator.hpp>

using namespace LDL;
using namespace Arcanum;

LocationCreator::LocationCreator(LocationData* locationData, ObjectManager* objectManager) :
	_locationData(locationData),
	_objectManager(objectManager)
{
}

void LocationCreator::Reset(const Vec2u& size)
{
	_locationData->Reset(size);
}

void LocationCreator::NewTile(size_t index, const std::string& path)
{
	_objectManager->NewTile(_locationData->TileObjects()[index], path);
}

Scenery* LocationCreator::NewScenery(const Vec2u& pos, const std::string& path)
{
	Scenery* result = _objectManager->NewScenery(path);

	result->Pos(pos);

	_locationData->Append(result);

	return result;
}
