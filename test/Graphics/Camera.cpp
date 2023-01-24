#include <LDL/Core/TestEqual.hpp>
#include <LDL/Graphics/Camera.hpp>

using namespace LDL::Graphics;

void InitDefault()
{
	Camera camera(Point2u(50, 75), Point2u(800, 600));

	LDL_TEST_EQUAL(camera.Pos().PosX()  == 50);
	LDL_TEST_EQUAL(camera.Pos().PosY()  == 75);
	LDL_TEST_EQUAL(camera.Size().PosX() == 800);
	LDL_TEST_EQUAL(camera.Size().PosY() == 600);

}

void InitPosX()
{
	Camera camera(Point2u(50, 75), Point2u(800, 600));

	camera.PosX(95);

	LDL_TEST_EQUAL(camera.Pos().PosX() == 95);
	LDL_TEST_EQUAL(camera.Pos().PosY() == 75);
	LDL_TEST_EQUAL(camera.Size().PosX() == 800);
	LDL_TEST_EQUAL(camera.Size().PosY() == 600);

}

void InitPosY()
{
	Camera camera(Point2u(50, 75), Point2u(800, 600));

	camera.PosY(95);

	LDL_TEST_EQUAL(camera.Pos().PosX() == 50);
	LDL_TEST_EQUAL(camera.Pos().PosY() == 95);
	LDL_TEST_EQUAL(camera.Size().PosX() == 800);
	LDL_TEST_EQUAL(camera.Size().PosY() == 600);

}

void InitSizeX()
{
	Camera camera(Point2u(50, 75), Point2u(800, 600));

	camera.SizeX(500);

	LDL_TEST_EQUAL(camera.Pos().PosX() == 50);
	LDL_TEST_EQUAL(camera.Pos().PosY() == 75);
	LDL_TEST_EQUAL(camera.Size().PosX() == 500);
	LDL_TEST_EQUAL(camera.Size().PosY() == 600);

}

void InitSizeY()
{
	Camera camera(Point2u(50, 75), Point2u(800, 600));

	camera.SizeY(500);

	LDL_TEST_EQUAL(camera.Pos().PosX() == 50);
	LDL_TEST_EQUAL(camera.Pos().PosY() == 75);
	LDL_TEST_EQUAL(camera.Size().PosX() == 800);
	LDL_TEST_EQUAL(camera.Size().PosY() == 500);

}

int main()
{
	InitDefault();
	InitPosX();
	InitPosY();
	InitSizeX();
	InitSizeY();

	return 0;
}