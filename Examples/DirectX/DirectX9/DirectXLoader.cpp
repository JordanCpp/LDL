#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Loaders/ImageLoader.hpp>
#include <LDL/Time/FpsCounter.hpp>
#include <LDL/Core/NumberToString.hpp>
#include <LDL/Time/FpsLimiter.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Graphics/Render.hpp>
#include <LDL/DirectX/DirectXLoader.hpp>
#include <iostream>

using namespace LDL::Graphics;
using namespace LDL::Enums;
using namespace LDL::Events;
using namespace LDL::Time;
using namespace LDL::Core;
using namespace LDL::Allocators;
using namespace LDL::Loaders;
using namespace LDL::Math;
using namespace LDL::DirectX;
using namespace LDL::DirectX9;

int main()
{
	try
	{
		DirectXLoader directXLoader;
		IDirect3D9* direct3D9 = directXLoader.GetDirect3D();

		RenderContext renderContext(RenderMode::OpenGL1);

		Window window(&renderContext, Vec2u(0, 0), Vec2u(800, 600), "DirectXLoader.cpp");
		Render render(&renderContext, &window);

		Event report;

		FpsCounter fpsCounter;
		NumberToString convert;
		FpsLimiter fpsLimiter;

		while (window.Running())
		{
			fpsLimiter.Mark();
			fpsCounter.Start();

			while (window.GetEvent(report))
			{
				if (report.Type == IsQuit)
				{
					window.StopEvent();
				}

				if (report.IsKeyPressed(KeyboardKey::Escape))
					window.StopEvent();
			}

			render.Begin();

			render.End();

			fpsLimiter.Throttle();

			if (fpsCounter.Calc())
			{
				window.Title(convert.Convert(fpsCounter.Fps()));
				fpsCounter.Clear();
			}

			window.PollEvents();
		}
	}
	catch (const RuntimeError& error)
	{
		std::cout << error.what() << '\n';
	}

	return 0;
}
