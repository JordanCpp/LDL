#include <LDL/Core/TestEqual.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <LDL/Graphics/Window.hpp>

using namespace LDL::Graphics;
using namespace LDL::Allocators;
using namespace LDL::Math;

int main()
{
		FixedLinear graphicsAllocator(Allocator::Mb * 1);

		const std::string title = "LDL Window title!";

		RenderContext renderContext;

		Window window(&renderContext, Vec2u(1, 2), Vec2u(640, 480), title);

		LDL_TEST_EQUAL(window.Pos().x == 1);
		LDL_TEST_EQUAL(window.Pos().y == 2);

		LDL_TEST_EQUAL(window.Size().x == 640);
		LDL_TEST_EQUAL(window.Size().y == 480);

		LDL_TEST_EQUAL(window.Title() == title);

	return 0;
}
