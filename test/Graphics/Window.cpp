// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/TestEqual.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <LDL/Graphics/Window.hpp>

using namespace LDL::Core;
using namespace LDL::Graphics;
using namespace LDL::Allocators;
using namespace LDL::Math;

int main()
{
		FixedLinear graphicsAllocator(Allocator::Mb * 1);

		const std::string title = "LDL Window title!";

		Result result;
		RenderContext renderContext;

		Window window(result, renderContext, Vec2u(1, 2), Vec2u(640, 480), title);

		LDL_TEST_EQUAL(window.Pos().x == 1);
		LDL_TEST_EQUAL(window.Pos().y == 2);

		LDL_TEST_EQUAL(window.Size().x == 640);
		LDL_TEST_EQUAL(window.Size().y == 480);

		LDL_TEST_EQUAL(window.Title() == title);

	return 0;
}
