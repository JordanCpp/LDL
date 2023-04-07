#include <LDL/Core/TestEqual.hpp>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Audio/Mixer.hpp>

using namespace LDL::Graphics;
using namespace LDL::Audio;

int main()
{
	Window window(Point2u(1, 2), Point2u(640, 480), "Mixer.cpp");

	try
	{
		Mixer mixer(&window, 44100, 16, 2);
	}
	catch (const LDL::Core::RuntimeError& error)
	{
		std::cout << error.what() << '\n';
	}

	return 0;
}