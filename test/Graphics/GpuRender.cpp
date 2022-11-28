#include <iostream>
#include <LDL/Core/TestEqual.hpp>
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Creators/GraphicsCreator.hpp>

int main()
{
	try
	{
		LDL::Creators::GraphicsCreator graphics;

		const std::string title = "LDL Window title!";

		LDL::Graphics::IGpuWindow* window = graphics.CreateGpuWindow(LDL::Graphics::Point2u(1, 2), LDL::Graphics::Point2u(640, 480), title);

		LDL::Graphics::IGpuRender* render = graphics.CreateGpuRender(window);

		LDL_TEST_EQUAL(render->Size().PosX() == 640);
		LDL_TEST_EQUAL(render->Size().PosY() == 480);
	}
	catch (const LDL::Core::RuntimeError& error)
	{
		std::cout << error.what() << '\n';
	}

	return 0;
}