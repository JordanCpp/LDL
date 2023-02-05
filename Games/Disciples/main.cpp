#include <iostream>
#include <Disciples/Game/Engine.hpp>
#include <Disciples/Game/Settings.hpp>

using namespace Disciples::Game;

int main()
{
	try
	{
		Settings settings;
		settings.Title("Disciples project");
		settings.Size(LDL::Graphics::Point2u(800, 600));
		settings.Fps(60);

		Engine engine(&settings);
		engine.Run();
	}
	catch (const LDL::Core::RuntimeError& error)
	{
		std::cout << error.what() << '\n';
	}

	return 0;
}