#include <LDL/Graphics/Gpu/GpuWindow.hpp>
#include <LDL/Graphics/Gpu/GpuImage.hpp>
#include <LDL/Graphics/Gpu/GpuRender.hpp>
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Loaders/ImageBufferLoader.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <iostream>
#include <LDL/Time/FpsCounter.hpp>
#include <LDL/Core/IntegerToString.hpp>
#include <LDL/Graphics/Gpu/GpuScreenshoter.hpp>

int main()
{
	try
	{
		LDL::Graphics::GpuWindow window(LDL::Graphics::Point2u(0, 0), LDL::Graphics::Point2u(800, 600), "Window!");

		LDL::Graphics::GpuRender render(&window);

		LDL::Events::Event report;

		LDL::Allocators::FixedLinear allocator(LDL::Allocators::Allocator::Mb * 8);
		LDL::Loaders::ImageBufferLoader loader(&allocator);

		loader.Load("Gorgosaurus_BW_transparent.png");
		LDL::Graphics::GpuImage image(loader.Size(), loader.BytesPerPixel(), loader.Pixels());

		size_t x = 0;
		size_t y = 0;

		LDL::Time::FpsCounter fpsCounter;
		LDL::Core::IntegerToString convert;

		LDL::Graphics::CpuImage screenshot(LDL::Graphics::Point2u(800, 600), 4, (uint8_t*)allocator.Allocate(800 * 600 * 4));
		LDL::Graphics::GpuScreenshoter screenshoter("", "06_Gpu_Click", &render, &screenshot);

		while (window.GetEvent(report))
		{
			fpsCounter.Start();

			render.Begin();

			render.Color(LDL::Graphics::Color(0, 162, 232));
			render.Clear();

			if (report.Type == LDL::Events::IsQuit)
			{
				window.StopEvent();
			}

			render.Draw(&image, LDL::Graphics::Point2u(x, y), LDL::Graphics::Point2u(150, 150));

			if (report.Type == LDL::Events::IsMouseClick)
			{
				x = report.Mouse.PosX;
				y = report.Mouse.PosY;

				screenshoter.Shot();
			}

			render.End();

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