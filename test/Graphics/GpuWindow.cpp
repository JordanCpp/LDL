#include <iostream>
#include <LDL/Core/TestEqual.hpp>
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Creators/GraphicsCreator.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <LDL/Graphics/GpuWindow.hpp>

int main()
{
	try
	{
		LDL::Allocators::FixedLinear graphicsAllocator(LDL::Allocators::Allocator::Mb * 1);

		LDL::Creators::GraphicsCreator graphics(&graphicsAllocator);

		const std::string title = "LDL Window title!";

		LDL::Graphics::GpuWindow window(LDL::Graphics::Point2u(1, 2), LDL::Graphics::Point2u(640, 480), title);

		LDL_TEST_EQUAL(window.Pos().PosX() == 1);
		LDL_TEST_EQUAL(window.Pos().PosY() == 2);

		LDL_TEST_EQUAL(window.Size().PosX() == 640);
		LDL_TEST_EQUAL(window.Size().PosY() == 480);

		LDL_TEST_EQUAL(window.Title() == title);
	}
	catch (const LDL::Core::RuntimeError& error)
	{
		std::cout << error.what() << '\n';
	}

	return 0;
}