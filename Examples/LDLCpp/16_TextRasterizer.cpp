#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Time/FpsLimiter.hpp>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Graphics/Render.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <LDL/Loaders/FontLoader.hpp>
#include <LDL/Text/Rasterizer.hpp>
#include <iostream>

using namespace LDL::Allocators;
using namespace LDL::Loaders;
using namespace LDL::Graphics;
using namespace LDL::Events;
using namespace LDL::Time;
using namespace LDL::Text;
using namespace LDL::Core;
using namespace LDL::Enums;
using namespace LDL::Math;

int main()
{
	try
	{
		RenderContext renderContext;

		Window window(&renderContext, Vec2u(0, 0), Vec2u(800, 600), "16_TextRasterizer");
		Render render(&renderContext, &window);

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
				if (report.Type == IsQuit)
				{
					window.StopEvent();
				}
			}

			render.Begin();

			render.Color(Color(0, 162, 232));
			render.Clear();

			render.Draw(imageText, Vec2u(5, 5));

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
