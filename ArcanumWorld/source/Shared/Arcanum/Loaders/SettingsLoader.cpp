#include <Arcanum/Loaders/SettingsLoader.hpp>
#include <Arcanum/Core/RuntimeError.hpp>

using namespace LDL::Math;
using namespace Arcanum::Core;
using namespace Arcanum::Game;
using namespace Arcanum::Loaders;
using namespace Arcanum::Readers;

SettingsLoader::SettingsLoader(XmlReader* xmlReader) :
	_XmlReader(xmlReader)
{
}

bool SettingsLoader::Reset(const std::string& path, Settings& settings)
{
	bool result = _XmlReader->Reset(path);

	if (!result)
		throw RuntimeError("Cannot open the file: " + path);

	_XmlReader->NextOpening("Config");

	_XmlReader->NextOpening("Video");

	_XmlReader->NextNode("Render");
	settings.Render(_XmlReader->ValueInt());

	_XmlReader->NextNode("Width");
	size_t width = _XmlReader->ValueInt();

	_XmlReader->NextNode("Heigth");
	size_t heigth = _XmlReader->ValueInt();

	settings.Size(Vec2u(width, heigth));

	_XmlReader->NextNode("Fps");
	settings.Fps(_XmlReader->ValueInt());

	_XmlReader->NextNode("Title");
	settings.Title(_XmlReader->Value());

	_XmlReader->NextClosing("Video");

	_XmlReader->NextOpening("Files");

	_XmlReader->NextNode("DatFiles");
	settings.DatFiles(_XmlReader->Value());

	_XmlReader->NextNode("DataFiles");
	settings.DataFiles(_XmlReader->Value());

	_XmlReader->NextClosing("Files");

	_XmlReader->NextClosing("Config");

	return result;
}