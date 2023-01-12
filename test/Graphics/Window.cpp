#include <iostream>
#include <LDL/Core/TestEqual.hpp>
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <LDL/Graphics/Window.hpp>

int main()
{
	try
	{
		LDL::Allocators::FixedLinear graphicsAllocator(LDL::Allocators::Allocator::Mb * 1);

		const std::string title = "LDL Window title!";

		LDL::Graphics::Window window(LDL::Graphics::Point2u(1, 2), LDL::Graphics::Point2u(640, 480), title);

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