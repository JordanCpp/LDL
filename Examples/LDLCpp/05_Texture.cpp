// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/LDL.hpp>

using namespace LDL::Graphics;
using namespace LDL::Events;
using namespace LDL::Time;
using namespace LDL::Core;
using namespace LDL::Allocators;
using namespace LDL::Loaders;
using namespace LDL::Math;

int main()
{
	RenderContext renderContext;

	Window window(renderContext, Vec2u(0, 0), Vec2u(800, 600), "Window!");
	Render render(renderContext, &window);

	Event report;

	FixedLinear allocator(Allocator::Mb * 4);
	ImageLoader loader(&allocator);

	loader.Load("Data/trehmachtovyiy-korabl-kartina-maslom-60x50_512x.jpg");
	Texture image(&renderContext, loader.Size(), loader.Pixels(), loader.BytesPerPixel());

	FpsCounter fpsCounter;
	Convert convert;

	while (window.Running())
	{
		fpsCounter.Start();

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

		render.Draw(&image, Vec2u(0, 0), window.Size(), Vec2u(0, 0), image.Size());

		render.End();

		if (fpsCounter.Calc())
		{
			window.Title(convert.ToString(fpsCounter.Fps()));
			fpsCounter.Clear();
		}

		window.PollEvents();
	}

	return 0;
}
