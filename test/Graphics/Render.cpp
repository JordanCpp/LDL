#include <iostream>
#include <LDL/Core/TestEqual.hpp>
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Graphics/Render.hpp>

using namespace LDL::Graphics;

int main()
{
	try
	{
		const std::string title = "LDL Window title!";

		Window window(Point2u(1, 2), Point2u(640, 480), title);

		RenderContext renderContext;
		Render render(&renderContext, &window);

		LDL_TEST_EQUAL(render.Size().PosX() > 0);
		LDL_TEST_EQUAL(render.Size().PosX() <= 640);

		LDL_TEST_EQUAL(render.Size().PosY() > 0);
		LDL_TEST_EQUAL(render.Size().PosY() <= 480);
	}
	catch (const LDL::Core::RuntimeError& error)
	{
		std::cout << error.what() << '\n';
	}

	return 0;
}