#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Graphics/Cpu/CpuRender.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <iostream>
#include <LDL/Time/FpsCounter.hpp>
#include <LDL/Core/IntegerToString.hpp>

const LDL::Graphics::Point2u windowSize = LDL::Graphics::Point2u(800, 600);
const size_t bytesBuffer = windowSize.PosX() * windowSize.PosY() * 4;

int main()
{
	try
	{
		LDL::Allocators::FixedLinear allocator(LDL::Allocators::Allocator::Mb * 4);

		uint8_t* pixels = (uint8_t*)allocator.Allocate(bytesBuffer);

		LDL::Graphics::CpuImage buffer(windowSize, 4, pixels);

		LDL::Graphics::CpuWindow window(LDL::Graphics::Point2u(0, 0), windowSize, "01_Cpu_WindowAndRender");

		LDL::Graphics::CpuRender render(&window, &buffer);

		LDL::Events::Event report;

		LDL::Time::FpsCounter fpsCounter;
		LDL::Core::IntegerToString convert;

		while (window.GetEvent(report))
		{
			fpsCounter.Start();

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