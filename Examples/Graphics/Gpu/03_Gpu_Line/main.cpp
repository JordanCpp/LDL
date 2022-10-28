#include <LDL/Graphics/Gpu/GpuWindow.hpp>
#include <LDL/Graphics/Gpu/GpuRender.hpp>
#include <LDL/Core/RuntimeError.hpp>
#include <iostream>

int main()
{
	try
	{
		LDL::Graphics::GpuWindow window(LDL::Graphics::Point2u(0, 0), LDL::Graphics::Point2u(800, 600), "Window!");

		LDL::Graphics::GpuRender render(&window);

		LDL::Events::Event report;

		while (window.GetEvent(report))
		{
			render.Begin();

			render.Color(LDL::Graphics::Color(0, 162, 232));
			render.Clear();

			if (report.Type == LDL::Events::IsQuit)
			{
				window.StopEvent();
			}

			render.Color(LDL::Graphics::Color(237, 28, 36));
			render.Line(LDL::Graphics::Point2u(0, 0), render.Size());
			render.Line(LDL::Graphics::Point2u(render.Size().PosX(), 0), LDL::Graphics::Point2u(0, render.Size().PosY()));

			render.End();
		}
	}
	catch (const LDL::Core::RuntimeError& error)
	{
		std::cout << error.what() << '\n';
	}

	return 0;
}