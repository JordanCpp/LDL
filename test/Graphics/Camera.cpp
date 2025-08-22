// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/TestEqual.hpp>
#include <LDL/Graphics/Camera.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;

void InitDefault()
{
	RenderContext renderContext;

	Window window(&renderContext, Vec2u(0, 0), Vec2u(800, 600), "Window!");
	Render render(&renderContext, &window);

	Camera camera(&render, Vec2u(50, 75), Vec2u(800, 600));

	LDL_TEST_EQUAL(camera.Pos().x  == 50);
	LDL_TEST_EQUAL(camera.Pos().y  == 75);
	LDL_TEST_EQUAL(camera.Size().x == 800);
	LDL_TEST_EQUAL(camera.Size().y == 600);

}

void InitPos()
{
	RenderContext renderContext;

	Window window(&renderContext, Vec2u(0, 0), Vec2u(800, 600), "Window!");
	Render render(&renderContext, &window);

	Camera camera(&render, Vec2u(50, 75), Vec2u(800, 600));

	camera.Pos(Vec2u(95, 115));

	LDL_TEST_EQUAL(camera.Pos().x  == 95);
	LDL_TEST_EQUAL(camera.Pos().y  == 115);
	LDL_TEST_EQUAL(camera.Size().x == 800);
	LDL_TEST_EQUAL(camera.Size().y == 600);

}

void InitSize()
{
	RenderContext renderContext;

	Window window(&renderContext, Vec2u(0, 0), Vec2u(800, 600), "Window!");
	Render render(&renderContext, &window);

	Camera camera(&render, Vec2u(0, 0), Vec2u(800, 600));

	camera.Size(Vec2u(400, 300));

	LDL_TEST_EQUAL(camera.Pos().x == 50);
	LDL_TEST_EQUAL(camera.Pos().y == 75);
	LDL_TEST_EQUAL(camera.Size().x == 400);
	LDL_TEST_EQUAL(camera.Size().y == 300);

}

int main()
{
	InitDefault();
	InitPos();
	InitSize();

	return 0;
}
