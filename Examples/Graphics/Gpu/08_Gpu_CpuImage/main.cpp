#include <LDL/Graphics/Gpu/GpuWindow.hpp>
#include <LDL/Graphics/Gpu/GpuImage.hpp>
#include <LDL/Graphics/Gpu/GpuRender.hpp>
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Loaders/ImageBufferLoader.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <LDL/Time/FpsCounter.hpp>
#include <LDL/Core/IntegerToString.hpp>
#include <iostream>
#include <LDL/Time/FpsLimiter.hpp>

int main()
{
	try
	{
		LDL::Graphics::GpuWindow window(LDL::Graphics::Point2u(0, 0), LDL::Graphics::Point2u(800, 600), "Window!");

		LDL::Graphics::GpuRender render(&window);

		LDL::Events::Event report;

		LDL::Allocators::FixedLinear allocator(LDL::Allocators::Allocator::Mb * 4);
		LDL::Loaders::ImageBufferLoader loader(&allocator);

		loader.Load("Gorgosaurus_BW_transparent.png");
		LDL::Graphics::CpuImage image(loader.Size(), loader.BytesPerPixel(), loader.Pixels());

		LDL::Time::FpsCounter fpsCounter;
		LDL::Core::IntegerToString convert;
		LDL::Time::FpsLimiter fpsLimiter;

		while (window.GetEvent(report))
		{
			fpsLimiter.Mark();

			fpsCounter.Start();

			render.Begin();

			render.Color(LDL::Graphics::Color(0, 162, 232));
			render.Clear();

			if (report.Type == LDL::Events::IsQuit)
			{
				window.StopEvent();
			}

			render.Draw(&image, window.Pos(), window.Size());

			render.End();

			fpsLimiter.Throttle();

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