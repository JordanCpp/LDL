// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <iostream>
#include <LDL/LDL.hpp>
#include <Arcanum/Writers/XmlWriter.hpp>

using namespace LDL::Math;
using namespace Arcanum::Writers;


void NewScenery(XmlWriter& writer, const Vec2u& pos, const std::string& path)
{
	writer.TagBegin("Scenery");
	writer.Node("X", pos.x);
	writer.Node("Y", pos.y);
	writer.Node("Body", path);
	writer.TagEnd("Scenery");
}

int main()
{
	XmlWriter writer;

	writer.Reset("data/maps/Test.xml");

	LDL::Math::Vec2u size(15, 15);

	writer.TagBegin("Info");
	writer.Node("Width", size.x);
	writer.Node("Heigth", size.y);
	writer.Node("Sceneries", 3);
	writer.TagEnd("Info");

	writer.TagBegin("Tiles");

	for (size_t i = 0; i < size.x * size.y; i++)
	{
		writer.TagBegin("Tile");
		writer.Node("Body", "grsbse0c.ART");
		writer.TagEnd("Tile");
	}

	writer.TagEnd("Tiles");

	writer.TagBegin("Sceneries");

	NewScenery(writer, Vec2u(3, 7), "savanna_tree02.ART");
	NewScenery(writer, Vec2u(6, 5), "engine.ART");
	NewScenery(writer, Vec2u(0, 0), "ArmorDisplay2.ART");

	writer.TagEnd("Sceneries");

	return 0;
}