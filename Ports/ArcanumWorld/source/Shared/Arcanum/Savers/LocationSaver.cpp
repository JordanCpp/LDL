#include <Arcanum/Savers/LocationSaver.hpp>

using namespace Arcanum::Savers;
using namespace Arcanum::Writers;
using namespace Arcanum::Objects;

LocationSaver::LocationSaver(XmlWriter* xmlWriter) :
	_xmlWriter(xmlWriter)
{
}

void LocationSaver::Save(LocationData* locationData, const std::string& path)
{
	_xmlWriter->Reset(path);

	_xmlWriter->TagBegin("Location");

	_xmlWriter->TagBegin("Info");
	_xmlWriter->Node("Width", locationData->Size().x);
	_xmlWriter->Node("Height", locationData->Size().y);
	_xmlWriter->TagEnd("Info");

	_xmlWriter->TagEnd("Location");
}