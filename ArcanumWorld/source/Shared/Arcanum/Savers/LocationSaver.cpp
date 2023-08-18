#include <Arcanum/Savers/LocationSaver.hpp>

using namespace Arcanum::Savers;
using namespace Arcanum::Writters;
using namespace Arcanum::Objects;

LocationSaver::LocationSaver(XmlWritter* xmlWritter) :
	_XmlWritter(xmlWritter)
{
}

void LocationSaver::Save(LocationData* locationData, const std::string& path)
{
	_XmlWritter->Reset(path);

	_XmlWritter->TagBegin("Location");

	_XmlWritter->TagBegin("Info");
	_XmlWritter->Node("Width", locationData->Size().x);
	_XmlWritter->Node("Height", locationData->Size().y);
	_XmlWritter->TagEnd("Info");

	_XmlWritter->TagEnd("Location");
}