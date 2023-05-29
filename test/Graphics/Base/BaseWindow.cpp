#include <LDL/Core/TestEqual.hpp>
#include <LDL/Graphics/Base/BaseWindow.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;

void Init()
{
	BaseWindow baseWindow(Vec2u(25, 50), Vec2u(800, 600), "Hello world!");

	LDL_TEST_EQUAL(baseWindow.Pos().x == 25);
	LDL_TEST_EQUAL(baseWindow.Pos().y == 50);
	LDL_TEST_EQUAL(baseWindow.Size().x == 800);
	LDL_TEST_EQUAL(baseWindow.Size().y == 600);
	LDL_TEST_EQUAL(baseWindow.Title() == "Hello world!");
}

void ChangeTitle()
{
	BaseWindow baseWindow(Vec2u(25, 50), Vec2u(800, 600), "Hello!");

	baseWindow.Title("World!");

	LDL_TEST_EQUAL(baseWindow.Title() == "World!");
}

void ChangeSize()
{
	BaseWindow baseWindow(Vec2u(25, 50), Vec2u(800, 600), "Hello!");

	baseWindow.Size(Vec2u(320, 200));

	LDL_TEST_EQUAL(baseWindow.Size().x == 320);
	LDL_TEST_EQUAL(baseWindow.Size().y == 200);
}

int main()
{
	Init();
	ChangeTitle();
	ChangeSize();

	return 0;
}