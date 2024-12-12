#include <LDL/Core/TestEqual.hpp>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Audio/Mixer.hpp>

using namespace LDL::Graphics;
using namespace LDL::Audio;
using namespace LDL::Math;

int main()
{
		RenderContext renderContext;

		Window window(&renderContext, Vec2u(1, 2), Vec2u(640, 480), "Mixer.cpp");
		AudioContext audioContext(&window, 44100, 16, 2);

	return 0;
}
