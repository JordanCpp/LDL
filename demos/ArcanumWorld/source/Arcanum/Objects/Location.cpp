// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <Arcanum/Objects/Location.hpp>

using namespace Arcanum;

Location::Location(LocationData* locationData, LocationCreator* locationCreator, LocationPainter* locationPainter) :
	_locationData(locationData),
	_locationCreator(locationCreator),
	_locationPainter(locationPainter)
{
}

void Location::Draw(const LDL_Vec2u& start)
{
	_locationPainter->DrawTiles(start);
	_locationPainter->DrawSceneries(start);
}

Scenery* Location::NewScenery(const LDL_Vec2u& pos, const std::string& path)
{
	return _locationCreator->NewScenery(pos, path);
}

Tile* Location::NewTile(const LDL_Vec2u& pos, const std::string& path)
{
	size_t index = _locationData->Index(pos);

	_locationCreator->NewTile(index, path);

	return &_locationData->TileObjects()[index];
}
