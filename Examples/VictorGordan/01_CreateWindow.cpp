#include <LDL/Loaders/ImageLoader.hpp>
#include <LDL/Time/FpsCounter.hpp>
#include <LDL/Core/Convert.hpp>
#include <LDL/Time/FpsLimiter.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Graphics/Render.hpp>
#include <LDL/APIs/OpenGL/OpenGL3_3.hpp>

using namespace LDL::Graphics;
using namespace LDL::Enums;
using namespace LDL::Events;
using namespace LDL::Time;
using namespace LDL::Core;
using namespace LDL::Allocators;
using namespace LDL::Loaders;
using namespace LDL::Math;

int main()
{
		RenderContext renderContext(RenderMode::OpenGL3);

		Window window(&renderContext, Vec2u(0, 0), Vec2u(800, 800), "YoutubeOpenGL");
		Render render(&renderContext, &window);

		Event report;

		FpsCounter fpsCounter;
		Convert convert;
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

			glViewport(0, 0, (GLsizei)window.Size().x, (GLsizei)window.Size().y);
			glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			render.End();

			fpsLimiter.Throttle();

			if (fpsCounter.Calc())
			{
				window.Title(convert.ToString(fpsCounter.Fps()));
				fpsCounter.Clear();
			}

			window.PollEvents();
		}

	return 0;
}
