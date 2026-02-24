// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/LDL.hpp>

using namespace LDL;

int main()
{
	Result result;
	RenderContext renderContext;

	Window window(result, renderContext, Vec2u(0, 0), Vec2u(800, 600), "15_AudioPlay");
	Render render(result, renderContext, &window);

	AudioContext audioContext(&window, 44100, 16, 2);

	Mixer mixer;

	Event report;

	FpsLimiter fpsLimiter;

	FixedLinear allocator(Allocator::Mb * 128);
	SoundLoader soundLoader(&allocator);

	soundLoader.LoadOgg("Data/1.ogg");

	Sound sound(&audioContext, soundLoader.Channels(), soundLoader.Rate(), soundLoader.Samples(), soundLoader.Bytes());
	mixer.Play(&sound);

	while (window.Running())
	{
		fpsLimiter.Mark();

		while (window.GetEvent(report))
		{
			if (report.Type == Event::IsQuit)
			{
				window.StopEvent();
			}

			if (report.IsMousePressed(MouseButton::Left))
				mixer.Stop(&sound);

			if (report.IsMousePressed(MouseButton::Right))
				mixer.Play(&sound);
		}

		render.Begin();

		render.SetColor(Color(0, 162, 232));
		render.Clear();

		render.End();

		fpsLimiter.Throttle();
	}

	return 0;
}
