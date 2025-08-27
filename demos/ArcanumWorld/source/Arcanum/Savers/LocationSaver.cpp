// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <Arcanum/Savers/LocationSaver.hpp>

using namespace Arcanum;

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
