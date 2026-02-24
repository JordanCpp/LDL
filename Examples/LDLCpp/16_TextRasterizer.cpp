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

	Window window(result, renderContext, Vec2u(0, 0), Vec2u(800, 600), "16_TextRasterizer");
	Render render(result, renderContext, &window);

	Event report;

	FpsLimiter fpsLimiter;

	RasterizerContext rasterizerContext;
	Rasterizer rasterizer(Vec2u(512, 512));

	FixedLinear allocator(Allocator::Mb * 1);
	FontLoader fontLoader(&allocator);

	fontLoader.Load("Data/UbuntuMono-Regular.ttf");
	Font font(&rasterizerContext, 64, fontLoader.Font(), fontLoader.Size());

	Surface* imageText = NULL;

	if (rasterizer.RenderText("LDL framework!", &font, Color(255, 0, 0)))
	{
		imageText = rasterizer.Result();
	}

	Texture textureText(&renderContext, imageText->Size(), imageText->BytesPerPixel());

	while (window.Running())
	{
		fpsLimiter.Mark();

		while (window.GetEvent(report))
		{
			if (report.Type == Event::IsQuit)
			{
				window.StopEvent();
			}
		}

		render.Begin();

		render.SetColor(Color(0, 162, 232));
		render.Clear();

		render.Draw(imageText, Vec2u(5, 5));

		render.End();

		fpsLimiter.Throttle();	
	}

	return 0;
}
