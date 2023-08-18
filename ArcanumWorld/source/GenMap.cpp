#include <iostream>
#include <Arcanum/Writters/XmlWritter.hpp>
#include <LDL/Math/Vec2.hpp>

using namespace LDL::Math;
using namespace Arcanum::Writters;


void NewScenery(XmlWritter& writter, const Vec2u& pos, const std::string& path)
{
	writter.TagBegin("Scenery");
	writter.Node("X", pos.x);
	writter.Node("Y", pos.y);
	writter.Node("Body", path);
	writter.TagEnd("Scenery");
}

int main()
{
	XmlWritter writter;

	writter.Reset("data/maps/Test.xml");

	LDL::Math::Vec2u size(15, 15);

	writter.TagBegin("Info");
	writter.Node("Width", size.x);
	writter.Node("Heigth", size.y);
	writter.Node("Sceneries", 3);
	writter.TagEnd("Info");

	writter.TagBegin("Tiles");

	for (size_t i = 0; i < size.x * size.y; i++)
	{
		writter.TagBegin("Tile");
		writter.Node("Body", "grsbse0c.ART");
		writter.TagEnd("Tile");
	}

	writter.TagEnd("Tiles");

	writter.TagBegin("Sceneries");

	NewScenery(writter, Vec2u(3, 7), "savanna_tree02.ART");
	NewScenery(writter, Vec2u(6, 5), "engine.ART");
	NewScenery(writter, Vec2u(0, 0), "ArmorDisplay2.ART");

	writter.TagEnd("Sceneries");

	return 0;
}