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
	Result result;
	RenderContext renderContext;

	Window window(result, renderContext, Vec2u(0, 0), Vec2u(800, 600), "Window!");
	Render render(result, renderContext, &window);

	Event report;

	FixedLinear allocator(Allocator::Mb * 4);
	ImageLoader loader(&allocator);

	loader.Load("Data/Gorgosaurus_BW_transparent.png");
	Texture image(&renderContext, loader.Size(), loader.Pixels(), loader.BytesPerPixel());

	size_t x = 0;
	size_t y = 0;

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

			if (report.Type == IsMouseMove)
			{
				x = report.Mouse.PosX;
				y = report.Mouse.PosY;
			}
		}

		render.Begin();

		render.Color(Color(0, 162, 232));
		render.Clear();

		render.Draw(&image, Vec2u(x, y), Vec2u(150, 150));

		render.End();

		if (fpsCounter.Calc())
		{
			window.Title(convert.ToString(fpsCounter.Fps()));
			
		}

		
	}

	return 0;
}
