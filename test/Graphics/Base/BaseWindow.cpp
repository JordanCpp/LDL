#include <LDL/Core/TestEqual.hpp>
#include <LDL/Graphics/Base/BaseWindow.hpp>

using namespace LDL::Graphics;

void Init()
{
	BaseWindow baseWindow(Point2u(25, 50), Point2u(800, 600), "Hello world!");

	LDL_TEST_EQUAL(baseWindow.Pos().PosX() == 25);
	LDL_TEST_EQUAL(baseWindow.Pos().PosY() == 50);
	LDL_TEST_EQUAL(baseWindow.Size().PosX() == 800);
	LDL_TEST_EQUAL(baseWindow.Size().PosY() == 600);
	LDL_TEST_EQUAL(baseWindow.Title() == "Hello world!");
}

void ChangeTitle()
{
	BaseWindow baseWindow(Point2u(25, 50), Point2u(800, 600), "Hello!");

	baseWindow.Title("World!");

	LDL_TEST_EQUAL(baseWindow.Title() == "World!");
}

void ChangeSize()
{
	BaseWindow baseWindow(Point2u(25, 50), Point2u(800, 600), "Hello!");

	baseWindow.Size(Point2u(320, 200));

	LDL_TEST_EQUAL(baseWindow.Size().PosX() == 320);
	LDL_TEST_EQUAL(baseWindow.Size().PosY() == 200);
}

int main()
{
	Init();
	ChangeTitle();
	ChangeSize();

	return 0;
}