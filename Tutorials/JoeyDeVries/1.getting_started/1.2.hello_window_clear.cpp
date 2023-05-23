#include <iostream>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Graphics/Render.hpp>
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/OpenGL/OpenGL3_3.hpp>

using namespace LDL::Graphics;
using namespace LDL::Events;
using namespace LDL::Enums;
using namespace LDL::Core;

// settings
const unsigned int SCR_WIDTH  = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
	try
	{
		Window window(Point2u(0, 0), Point2u(SCR_WIDTH, SCR_HEIGHT), "LearnOpenGL");

		RenderContext renderContext;
		Render render(&renderContext, &window);

		Event report;

		while (window.Running())
		{
			while (window.GetEvent(report))
			{
				if (report.Type == IsResize)
				{
					glViewport(0, 0, (GLsizei)report.Resize.Width, (GLsizei)report.Resize.Height);
				}

				if (report.Type == IsQuit || report.IsKeyPressed(KeyboardKey::Escape))
				{
					window.StopEvent();
				}
			}

			render.Begin();

			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			render.End();

			window.PollEvents();
		}
	}
	catch (const RuntimeError& error)
	{
		std::cout << error.what() << '\n';
	}

	return 0;
}