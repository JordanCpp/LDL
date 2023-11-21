#include <Arcanum/Loaders/LocationLoader.hpp>

using namespace LDL::Math;
using namespace Arcanum::Objects;
using namespace Arcanum::Loaders;
using namespace Arcanum::Readers;

LocationLoader::LocationLoader(XmlReader* xmlReader, LocationCreator* locationCreator) :
	_XmlReader(xmlReader),
	_LocationCreator(locationCreator),
	_SceneryCount(0)
{
}

void LocationLoader::Reset(const std::string& path)
{
	_XmlReader->Reset(path);

	_XmlReader->NextOpening("Info");

	_XmlReader->NextNode("Width");
	size_t width = _XmlReader->ValueInt();

	_XmlReader->NextNode("Heigth");
	size_t heigth = _XmlReader->ValueInt();

	_LocationCreator->Reset(Vec2u(width, heigth));

	_XmlReader->NextNode("Sceneries");
	_SceneryCount = _XmlReader->ValueInt();

	_XmlReader->NextClosing("Info");

	_XmlReader->NextOpening("Tiles");

	for (size_t i = 0; i < width * heigth; i++)
	{
		_XmlReader->NextOpening("Tile");
		_XmlReader->NextNode("Body");
		_LocationCreator->NewTile(i, _XmlReader->Value());
		_XmlReader->NextClosing("Tile");
	}

	_XmlReader->NextClosing("Tiles");

	_XmlReader->NextOpening("Sceneries");

	for (size_t i = 0; i < _SceneryCount; i++)
	{
		_XmlReader->NextOpening("Scenery");

		_XmlReader->NextNode("X");
		size_t x = _XmlReader->ValueInt();

		_XmlReader->NextNode("Y");
		size_t y = _XmlReader->ValueInt();

		_XmlReader->NextNode("Body");
		_LocationCreator->NewScenery(Vec2u(x, y), _XmlReader->Value());

		_XmlReader->NextClosing("Scenery");
	}

	_XmlReader->NextClosing("Sceneries");
}