#include <iostream>
#include "Engine.hpp"

int main()
{
	try
	{
		Game::Engine engine(LDL::Graphics::Point2u(0, 0), LDL::Graphics::Point2u(800, 600), "Window!");
		engine.Run();
	}
	catch (const LDL::Core::RuntimeError& error)
	{
		std::cout << error.what() << '\n';
	}

	return 0;
}