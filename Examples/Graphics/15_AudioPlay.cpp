#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Time/FpsLimiter.hpp>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Graphics/Render.hpp>
#include <LDL/Audio/Mixer.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <LDL/Loaders/SoundLoader.hpp>
#include <iostream>

using namespace LDL::Graphics;
using namespace LDL::Events;
using namespace LDL::Time;
using namespace LDL::Core;
using namespace LDL::Enums;
using namespace LDL::Math;
using namespace LDL::Audio;
using namespace LDL::Allocators;
using namespace LDL::Loaders;

int main()
{
	try
	{
		Window window(Vec2u(0, 0), Vec2u(800, 600), "15_AudioPlay");
		AudioContext audioContext(&window, 44100, 16, 2);

		Mixer mixer;

		RenderContext renderContext;
		Render render(&renderContext, &window);

		Event report;

		FpsLimiter fpsLimiter;

		FixedLinear allocator(Allocator::Mb * 8);
		SoundLoader soundLoader(&allocator);

		if (soundLoader.LoadMp3("sound01.wav"))
		{
			Sound sound(&audioContext, soundLoader.Channels(), soundLoader.Rate(), soundLoader.Samples(), soundLoader.Bytes());

			mixer.Play(&sound);
		}

		while (window.Running())
		{
			fpsLimiter.Mark();

			while (window.GetEvent(report))
			{
				if (report.Type == IsQuit)
				{
					window.StopEvent();
				}
			}

			render.Begin();

			render.Color(Color(0, 162, 232));
			render.Clear();

			render.End();

			fpsLimiter.Throttle();

			window.PollEvents();
		}
	}
	catch (const RuntimeError& error)
	{
		std::cout << error.what() << '\n';
	}

	return 0;
}