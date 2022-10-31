#include <LDL/Graphics/Gpu/GpuWindow.hpp>
#include <LDL/Graphics/Gpu/GpuImage.hpp>
#include <LDL/Graphics/Gpu/GpuRender.hpp>
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Loaders/ImageBufferLoader.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <iostream>

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
		LDL::Graphics::GpuImage image(loader.Size(), loader.BytesPerPixel(), loader.Pixels());

		size_t x = 0;
		size_t y = 0;

		while (window.GetEvent(report))
		{
			render.Begin();

			render.Color(LDL::Graphics::Color(0, 162, 232));
			render.Clear();

			if (report.Type == LDL::Events::IsQuit)
			{
				window.StopEvent();
			}

			if (report.Type == LDL::Events::IsMouseClick)
			{
				x = report.Mouse.PosX;
				y = report.Mouse.PosY;
			}

			render.Draw(&image, LDL::Graphics::Point2u(x, y), LDL::Graphics::Point2u(150, 150));

			render.End();
		}
	}
	catch (const LDL::Core::RuntimeError& error)
	{
		std::cout << error.what() << '\n';
	}

	return 0;
}