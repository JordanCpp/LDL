#include <iostream>
#include <LDL/Core/TestEqual.hpp>
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Graphics/Render.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;

int main()
{
	try
	{
		const std::string title = "LDL Window title!";

		Window window(Vec2u(1, 2), Vec2u(640, 480), title);

		RenderContext renderContext;
		Render render(&renderContext, &window);

		LDL_TEST_EQUAL(render.Size().x > 0);
		LDL_TEST_EQUAL(render.Size().x <= 640);

		LDL_TEST_EQUAL(render.Size().y > 0);
		LDL_TEST_EQUAL(render.Size().y <= 480);
	}
	catch (const LDL::Core::RuntimeError& error)
	{
		std::cout << error.what() << '\n';
	}

	return 0;
}