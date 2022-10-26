#include <LDL/Graphics/Render.hpp>
#include <LDL/Core/RuntimeError.hpp>
#include <iostream>

int main()
{
	try
	{
		LDL::Graphics::Window window(LDL::Graphics::Point2u(0, 0), LDL::Graphics::Point2u(800, 600), "Window!");

		LDL::Graphics::Render render(&window);

		LDL::Events::Event report;

		while (window.GetEvent(report))
		{
			render.Color(LDL::Graphics::Color(0, 162, 232));
			render.Clear();

			if (report.Type == LDL::Events::IsQuit)
			{
				window.StopEvent();
			}

			render.Color(LDL::Graphics::Color(237, 28, 36));
			render.Line(LDL::Graphics::Point2u(0, 0), render.Size());
			render.Line(LDL::Graphics::Point2u(render.Size().PosX(), 0), LDL::Graphics::Point2u(0, render.Size().PosY()));

			render.Present();
		}
	}
	catch (const LDL::Core::RuntimeError& error)
	{
		std::cout << error.what() << '\n';
	}

	return 0;
}