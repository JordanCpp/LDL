#include <iostream>
#include <Arcanum/Game/Engine.hpp>
#include <Arcanum/Game/Settings.hpp>

using namespace Arcanum::Game;
using namespace LDL::Graphics;
using namespace LDL::Core;

int main()
{
	try
	{
		Settings settings;
		settings.Title("Arcanum project");
		settings.Size(Point2u(800, 600));
		settings.Fps(60);

		Engine engine(&settings);
		engine.Run();
	}
	catch (const RuntimeError& error)
	{
		std::cout << error.what() << '\n';
	}

	return 0;
}