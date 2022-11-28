#include <iostream>
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Graphics/Cpu/CpuRender.hpp>
#include <LDL/Time/FpsCounter.hpp>
#include <LDL/Core/IntegerToString.hpp>
#include <LDL/Loaders/ImageLoader.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <LDL/Creators/GraphicsCreator.hpp>

const LDL::Graphics::Point2u windowSize = LDL::Graphics::Point2u(800, 600);

int main()
{
	try
	{
		LDL::Creators::GraphicsCreator graphics;

		LDL::Graphics::ICpuWindow* window = graphics.CreateCpuWindow(LDL::Graphics::Point2u(0, 0), windowSize, "05_Cpu_Image");

		LDL::Graphics::CpuRender render(window);

		LDL::Allocators::FixedLinear allocator(LDL::Allocators::Allocator::Mb * 4);
		LDL::Loaders::ImageLoader loader(&allocator);

		loader.Load("Gorgosaurus_BW_transparent.png");
		LDL::Graphics::CpuImage image(&loader);

		LDL::Events::Event report;

		LDL::Time::FpsCounter fpsCounter;
		LDL::Core::IntegerToString convert;

		while (window->GetEvent(report))
		{
			fpsCounter.Start();

			render.Color(LDL::Graphics::Color(0, 162, 232));
			render.Clear();

			if (report.Type == LDL::Events::IsQuit)
			{
				window->StopEvent();
			}

			render.Draw(image, LDL::Graphics::Point2u(0, 0));

			render.Present();

			if (fpsCounter.Calc())
			{
				if (convert.Convert(fpsCounter.Fps()))
				{
					window->Title(convert.Result());
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