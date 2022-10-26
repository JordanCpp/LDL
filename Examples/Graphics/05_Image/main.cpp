#include <LDL/Graphics/Render.hpp>
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Loaders/ImageBufferLoader.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <iostream>

int main()
{
	try
	{
		LDL::Graphics::Window window(LDL::Graphics::Point2u(0, 0), LDL::Graphics::Point2u(800, 600), "Window!");

		LDL::Graphics::Render render(&window);

		LDL::Events::Event report;

		LDL::Allocators::FixedLinear allocator(LDL::Allocators::Allocator::Mb * 4);
		LDL::Loaders::ImageBufferLoader loader(&allocator);

		loader.Load("trehmachtovyiy-korabl-kartina-maslom-60x50_512x.jpg");
		LDL::Graphics::Image image(loader.Size(), loader.BytesPerPixel(), loader.Pixels());

		while (window.GetEvent(report))
		{
			render.Color(LDL::Graphics::Color(0, 162, 232));
			render.Clear();

			if (report.Type == LDL::Events::IsQuit)
			{
				window.StopEvent();
			}

			render.Draw(&image, window.Pos(), window.Size());

			render.Present();
		}
	}
	catch (const LDL::Core::RuntimeError& error)
	{
		std::cout << error.what() << '\n';
	}

	return 0;
}