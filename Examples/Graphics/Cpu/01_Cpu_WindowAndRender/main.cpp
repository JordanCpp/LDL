#include <iostream>
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Graphics/Cpu/CpuRender.hpp>
#include <LDL/Time/FpsCounter.hpp>
#include <LDL/Core/IntegerToString.hpp>

const LDL::Graphics::Point2u windowSize = LDL::Graphics::Point2u(800, 600);

int main()
{
	try
	{ 
		LDL::Graphics::CpuWindow window(LDL::Graphics::Point2u(0, 0), windowSize, "01_Cpu_WindowAndRender");

		LDL::Graphics::CpuRender render(&window);

		LDL::Events::Event report;

		LDL::Time::FpsCounter fpsCounter;
		LDL::Core::IntegerToString convert;

		while (window.GetEvent(report))
		{
			fpsCounter.Start();

			if (report.Type == LDL::Events::IsQuit)
			{
				window.StopEvent();
			}

			render.Present();

			if (fpsCounter.Calc())
			{
				if (convert.Convert(fpsCounter.Fps()))
				{
					window.Title(convert.Result());
				}

				fpsCounter.Clear();
			}
		}
	}
	catch (const LDL::Core::RuntimeError& error)
	{
		std::cout << error.what() << '\n';
	}

	return 0;
}