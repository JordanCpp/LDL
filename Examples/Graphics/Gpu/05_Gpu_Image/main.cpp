#include <LDL/Graphics/Gpu/GpuWindow.hpp>
#include <LDL/Graphics/Gpu/GpuImage.hpp>
#include <LDL/Graphics/Gpu/GpuRender.hpp>
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Loaders/ImageLoader.hpp>
#include <LDL/Time/FpsCounter.hpp>
#include <LDL/Core/IntegerToString.hpp>
#include <iostream>

int main()
{
	try
	{
		LDL::Graphics::GpuWindow window(LDL::Graphics::Point2u(0, 0), LDL::Graphics::Point2u(800, 600), "Window!");

		LDL::Graphics::GpuRender render(&window);

		LDL::Events::Event report;

		LDL::Loaders::ImageLoader loader;

		loader.Load("trehmachtovyiy-korabl-kartina-maslom-60x50_512x.jpg");
		LDL::Graphics::GpuImage image(loader.Size(), loader.BytesPerPixel(), loader.Pixels());

		LDL::Time::FpsCounter fpsCounter;
		LDL::Core::IntegerToString convert;

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

			render.Draw(&image, window.Pos(), window.Size());

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