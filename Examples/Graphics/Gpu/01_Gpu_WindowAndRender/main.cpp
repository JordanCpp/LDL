#include <iostream>
#include <LDL/Creators/GraphicsCreator.hpp>
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Time/FpsCounter.hpp>
#include <LDL/Core/IntegerToString.hpp>

int main()
{
	try
	{
		LDL::Creators::GraphicsCreator graphics;

		LDL::Graphics::IGpuWindow* window = graphics.CreateGpuWindow(LDL::Graphics::Point2u(0, 0), LDL::Graphics::Point2u(800, 600), "Window!");

		LDL::Graphics::IGpuRender* render = graphics.CreateGpuRender(window);

		LDL::Events::Event report;

		LDL::Time::FpsCounter fpsCounter;
		LDL::Core::IntegerToString convert;

		while (window->GetEvent(report))
		{
			fpsCounter.Start();

			render->Begin();

			if (report.Type == LDL::Events::IsQuit)
			{
				window->StopEvent();
			}

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