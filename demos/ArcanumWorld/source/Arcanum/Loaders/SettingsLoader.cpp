// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <Arcanum/Loaders/SettingsLoader.hpp>
#include <Arcanum/Core/RuntimeError.hpp>

using namespace Arcanum;

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
	uint32_t width = _xmlReader->ValueInt();

	_xmlReader->NextNode("Height");
	uint32_t height = _xmlReader->ValueInt();

	settings.Size(LDL_Vec2u(width, height));

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
