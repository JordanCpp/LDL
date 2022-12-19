#include <iostream>
#include <LDL/Core/TestEqual.hpp>
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <LDL/Graphics/Gpu/GpuWindow.hpp>
#include <LDL/Graphics/Gpu/GpuRender.hpp>

int main()
{
	try
	{
		LDL::Allocators::FixedLinear graphicsAllocator(LDL::Allocators::Allocator::Mb * 1);

		const std::string title = "LDL Window title!";

		LDL::Graphics::GpuWindow window(LDL::Graphics::Point2u(1, 2), LDL::Graphics::Point2u(640, 480), title);

		LDL::Graphics::GpuRender render(&window);

		LDL_TEST_EQUAL(render.Size().PosX() > 0);
		LDL_TEST_EQUAL(render.Size().PosX() < 640);

		LDL_TEST_EQUAL(render.Size().PosY() > 0);
		LDL_TEST_EQUAL(render.Size().PosY() < 480);
	}
	catch (const LDL::Core::RuntimeError& error)
	{
		std::cout << error.what() << '\n';
	}

	return 0;
}