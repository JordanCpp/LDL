#include <LDL/LDL.hpp>

using namespace LDL::Graphics;
using namespace LDL::Events;
using namespace LDL::Time;
using namespace LDL::Enums;
using namespace LDL::Math;
using namespace LDL::Audio;
using namespace LDL::Allocators;
using namespace LDL::Loaders;

int main()
{
	RenderContext renderContext;

	Window window(&renderContext, Vec2u(0, 0), Vec2u(800, 600), "15_AudioPlay");
	Render render(&renderContext, &window);

	AudioContext audioContext(&window, 44100, 16, 2);

	Mixer mixer;

	Event report;

	FpsLimiter fpsLimiter;

	FixedLinear allocator(Allocator::Mb * 128);
	SoundLoader soundLoader(&allocator);

	//soundLoader.LoadMp3("Arcanum.mp3");
	soundLoader.LoadOgg("Data/1.ogg");

	Sound sound(&audioContext, soundLoader.Channels(), soundLoader.Rate(), soundLoader.Samples(), soundLoader.Bytes());
	mixer.Play(&sound);

	while (window.Running())
	{
		fpsLimiter.Mark();

		while (window.GetEvent(report))
		{
			if (report.Type == IsQuit)
			{
				window.StopEvent();
			}

			if (report.IsMousePressed(MouseButton::Left))
				mixer.Stop(&sound);

			if (report.IsMousePressed(MouseButton::Right))
				mixer.Play(&sound);
		}

		render.Begin();

		render.Color(Color(0, 162, 232));
		render.Clear();

		render.End();

		fpsLimiter.Throttle();

		window.PollEvents();
	}

	return 0;
}
