#include <LDL/Core/TestEqual.hpp>
#include <LDL/Graphics/Camera.hpp>

using namespace LDL::Graphics;

void InitDefault()
{
	Window window(Point2u(0, 0), Point2u(800, 600), "Window!");
	RenderContext renderContext;
	Render render(&renderContext, &window);

	Camera camera(&render, Point2u(50, 75), Point2u(800, 600));

	LDL_TEST_EQUAL(camera.Pos().PosX()  == 50);
	LDL_TEST_EQUAL(camera.Pos().PosY()  == 75);
	LDL_TEST_EQUAL(camera.Size().PosX() == 800);
	LDL_TEST_EQUAL(camera.Size().PosY() == 600);

}

void InitPos()
{
	Window window(Point2u(0, 0), Point2u(800, 600), "Window!");
	RenderContext renderContext;
	Render render(&renderContext, &window);

	Camera camera(&render, Point2u(50, 75), Point2u(800, 600));

	camera.Pos(Point2u(95, 115));

	LDL_TEST_EQUAL(camera.Pos().PosX()  == 95);
	LDL_TEST_EQUAL(camera.Pos().PosY()  == 115);
	LDL_TEST_EQUAL(camera.Size().PosX() == 800);
	LDL_TEST_EQUAL(camera.Size().PosY() == 600);

}

void InitSize()
{
	Window window(Point2u(0, 0), Point2u(800, 600), "Window!");
	RenderContext renderContext;
	Render render(&renderContext, &window);

	Camera camera(&render, Point2u(0, 0), Point2u(800, 600));

	camera.Size(Point2u(400, 300));

	LDL_TEST_EQUAL(camera.Pos().PosX() == 50);
	LDL_TEST_EQUAL(camera.Pos().PosY() == 75);
	LDL_TEST_EQUAL(camera.Size().PosX() == 400);
	LDL_TEST_EQUAL(camera.Size().PosY() == 300);

}

int main()
{
	InitDefault();
	InitPos();
	InitSize();

	return 0;
}