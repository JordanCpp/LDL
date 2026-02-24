#include <Arcanum/Loaders/SettingsLoader.hpp>
#include <Arcanum/Core/RuntimeError.hpp>

using namespace LDL;
using namespace Arcanum;
using namespace Arcanum::Game;
using namespace Arcanum::Loaders;
using namespace Arcanum::Readers;

SettingsLoader::SettingsLoader(XmlReader* xmlReader) :
	_xmlReader(xmlReader)
{
}

bool SettingsLoader::Reset(const std::string& path, Settings& settings)
{
	bool result = _xmlReader->Reset(path);

	if (!result)
		throw RuntimeError("Cannot open the file: " + path);

	_xmlReader->NextOpening("Config");

	_xmlReader->NextOpening("Video");

	_xmlReader->NextNode("Render");
	settings.Render(_xmlReader->ValueInt());

	_xmlReader->NextNode("Width");
	size_t width = _xmlReader->ValueInt();

	_xmlReader->NextNode("Heigth");
	size_t heigth = _xmlReader->ValueInt();

	settings.Size(Vec2u(width, heigth));

	_xmlReader->NextNode("Fps");
	settings.Fps(_xmlReader->ValueInt());

	_xmlReader->NextNode("Title");
	settings.Title(_xmlReader->Value());

	_xmlReader->NextClosing("Video");

	_xmlReader->NextOpening("Files");

	_xmlReader->NextNode("DatFiles");
	settings.DatFiles(_xmlReader->Value());

	_xmlReader->NextNode("DataFiles");
	settings.DataFiles(_xmlReader->Value());

	_xmlReader->NextClosing("Files");

	_xmlReader->NextClosing("Config");

	return result;
}