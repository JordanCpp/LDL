#include <LDL/Core/TestEqual.hpp>
#include <LDL/Graphics/Camera.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;

void InitDefault()
{
	Window window(Vec2u(0, 0), Vec2u(800, 600), "Window!");
	RenderContext renderContext;
	Render render(&renderContext, &window);

	Camera camera(&render, Vec2u(50, 75), Vec2u(800, 600));

	LDL_TEST_EQUAL(camera.Pos().x  == 50);
	LDL_TEST_EQUAL(camera.Pos().y  == 75);
	LDL_TEST_EQUAL(camera.Size().x == 800);
	LDL_TEST_EQUAL(camera.Size().y == 600);

}

void InitPos()
{
	Window window(Vec2u(0, 0), Vec2u(800, 600), "Window!");
	RenderContext renderContext;
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
	Window window(Vec2u(0, 0), Vec2u(800, 600), "Window!");
	RenderContext renderContext;
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