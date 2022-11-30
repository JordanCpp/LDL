#include <iostream>
#include <LDL/Creators/GraphicsCreator.hpp>
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Loaders/ImageLoader.hpp>
#include <LDL/Time/FpsCounter.hpp>
#include <LDL/Core/IntegerToString.hpp>
#include <LDL/Allocators/FixedLinear.hpp>

int main()
{
	try
	{
		LDL::Allocators::FixedLinear graphicsAllocator(LDL::Allocators::Allocator::Mb * 1);

		LDL::Creators::GraphicsCreator graphics(&graphicsAllocator);

		LDL::Graphics::IGpuWindow* window = graphics.CreateGpuWindow(LDL::Graphics::Point2u(0, 0), LDL::Graphics::Point2u(800, 600), "Window!");

		LDL::Graphics::IGpuRender* render = graphics.CreateGpuRender(window);

		LDL::Events::Event report;

		LDL::Allocators::FixedLinear allocator(LDL::Allocators::Allocator::Mb * 4);
		LDL::Loaders::ImageLoader loader(&allocator);

		loader.Load("Gorgosaurus_BW_transparent.png");
		LDL::Graphics::IGpuImage* image = graphics.CreateGpuImage(loader.Size(), loader.BytesPerPixel(), loader.Pixels());

		size_t x = 0;
		size_t y = 0;

		LDL::Time::FpsCounter fpsCounter;
		LDL::Core::IntegerToString convert;

		while (window->GetEvent(report))
		{
			fpsCounter.Start();

			render->Begin();

			render->Color(LDL::Graphics::Color(0, 162, 232));
			render->Clear();

			if (report.Type == LDL::Events::IsQuit)
			{
				window->StopEvent();
			}

			if (report.Type == LDL::Events::IsMouseMove)
			{
				x = report.Mouse.PosX;
				y = report.Mouse.PosY;
			}

			render->Draw(image, LDL::Graphics::Point2u(x, y), LDL::Graphics::Point2u(150, 150));

			render->End();

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