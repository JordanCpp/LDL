#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Graphics/Cpu/CpuRender.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <iostream>

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

		render.Color(LDL::Graphics::Color(0, 162, 232));

		while (window.GetEvent(report))
		{
			render.Clear();

			if (report.Type == LDL::Events::IsQuit)
			{
				window.StopEvent();
			}

			render.Present();
		}
	}
	catch (const LDL::Core::RuntimeError& error)
	{
		std::cout << error.what() << '\n';
	}

	return 0;
}