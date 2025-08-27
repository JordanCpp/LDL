// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <Arcanum/Loaders/LocationLoader.hpp>

using namespace LDL;
using namespace Arcanum;

LocationLoader::LocationLoader(XmlReader* xmlReader, LocationCreator* locationCreator) :
	_xmlReader(xmlReader),
	_locationCreator(locationCreator),
	_sceneryCount(0)
{
}

void LocationLoader::Reset(const std::string& path)
{
	_xmlReader->Reset(path);

	_xmlReader->NextOpening("Info");

	_xmlReader->NextNode("Width");
	uint32_t width = _xmlReader->ValueInt();

	_xmlReader->NextNode("Heigth");
	uint32_t height = _xmlReader->ValueInt();

	_locationCreator->Reset(Vec2u(width, height));

	_xmlReader->NextNode("Sceneries");
	_sceneryCount = _xmlReader->ValueInt();

	_xmlReader->NextClosing("Info");

	_xmlReader->NextOpening("Tiles");

	for (size_t i = 0; i < width * height; i++)
	{
		_xmlReader->NextOpening("Tile");
		_xmlReader->NextNode("Body");
		_locationCreator->NewTile(i, _xmlReader->Value());
		_xmlReader->NextClosing("Tile");
	}

	_xmlReader->NextClosing("Tiles");

	_xmlReader->NextOpening("Sceneries");

	for (size_t j = 0; j < _sceneryCount; j++)
	{
		_xmlReader->NextOpening("Scenery");

		_xmlReader->NextNode("X");
		uint32_t x = _xmlReader->ValueInt();

		_xmlReader->NextNode("Y");
		uint32_t y = _xmlReader->ValueInt();

		_xmlReader->NextNode("Body");
		_locationCreator->NewScenery(Vec2u(x, y), _xmlReader->Value());

		_xmlReader->NextClosing("Scenery");
	}

	_xmlReader->NextClosing("Sceneries");
}
