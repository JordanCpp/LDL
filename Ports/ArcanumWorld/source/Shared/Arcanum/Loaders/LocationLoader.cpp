#include <Arcanum/Loaders/LocationLoader.hpp>

using namespace LDL;
using namespace Arcanum::Objects;
using namespace Arcanum::Loaders;
using namespace Arcanum::Readers;

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
	size_t width = _xmlReader->ValueInt();

	_xmlReader->NextNode("Heigth");
	size_t heigth = _xmlReader->ValueInt();

	_locationCreator->Reset(Vec2u(width, heigth));

	_xmlReader->NextNode("Sceneries");
	_sceneryCount = _xmlReader->ValueInt();

	_xmlReader->NextClosing("Info");

	_xmlReader->NextOpening("Tiles");

	for (size_t i = 0; i < width * heigth; i++)
	{
		_xmlReader->NextOpening("Tile");
		_xmlReader->NextNode("Body");
		_locationCreator->NewTile(i, _xmlReader->Value());
		_xmlReader->NextClosing("Tile");
	}

	_xmlReader->NextClosing("Tiles");

	_xmlReader->NextOpening("Sceneries");

	for (size_t i = 0; i < _sceneryCount; i++)
	{
		_xmlReader->NextOpening("Scenery");

		_xmlReader->NextNode("X");
		size_t x = _xmlReader->ValueInt();

		_xmlReader->NextNode("Y");
		size_t y = _xmlReader->ValueInt();

		_xmlReader->NextNode("Body");
		_locationCreator->NewScenery(Vec2u(x, y), _xmlReader->Value());

		_xmlReader->NextClosing("Scenery");
	}

	_xmlReader->NextClosing("Sceneries");
}