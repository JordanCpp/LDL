// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/TestEqual.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Graphics/Render.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;

int main()
{
	const std::string title = "LDL Window title!";

	RenderContext renderContext;

	Window window(renderContext, Vec2u(1, 2), Vec2u(640, 480), title);
	Render render(renderContext, &window);

	LDL_TEST_EQUAL(render.Size().x > 0);
	LDL_TEST_EQUAL(render.Size().x <= 640);

	LDL_TEST_EQUAL(render.Size().y > 0);
	LDL_TEST_EQUAL(render.Size().y <= 480);

	return 0;
}
