// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <Arcanum/Objects/Location.hpp>

using namespace LDL::Math;
using namespace Arcanum::Objects;
using namespace Arcanum::Painters;

Location::Location(LocationData* locationData, LocationCreator* locationCreator, LocationPainter* locationPainter) :
	_LocationData(locationData),
	_LocationCreator(locationCreator),
	_LocationPainter(locationPainter)
{
}

void Location::Draw(const Vec2u& start)
{
	_LocationPainter->DrawTiles(start);
	_LocationPainter->DrawSceneries(start);
}

Scenery* Location::NewScenery(const Vec2u& pos, const std::string& path)
{
	return _LocationCreator->NewScenery(pos, path);
}

Tile* Location::NewTile(const Vec2u& pos, const std::string& path)
{
	size_t index = _LocationData->Index(pos);

	_LocationCreator->NewTile(index, path);

	return &_LocationData->TileObjects()[index];
}