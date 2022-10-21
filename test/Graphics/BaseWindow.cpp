#include <LDL/Core/TestEqual.hpp>
#include <LDL/Graphics/BaseWindow.hpp>

void Init()
{
	LDL::Graphics::BaseWindow baseWindow(LDL::Graphics::Point2u(25, 50), LDL::Graphics::Point2u(800, 600), "Hello world!");

	LDL_TEST_EQUAL(baseWindow.Pos().PosX() == 25);
	LDL_TEST_EQUAL(baseWindow.Pos().PosY() == 50);
	LDL_TEST_EQUAL(baseWindow.Size().PosX() == 800);
	LDL_TEST_EQUAL(baseWindow.Size().PosY() == 600);
	LDL_TEST_EQUAL(baseWindow.Title() == "Hello world!");
}

void ChangeTitle()
{
	LDL::Graphics::BaseWindow baseWindow(LDL::Graphics::Point2u(25, 50), LDL::Graphics::Point2u(800, 600), "Hello!");

	baseWindow.Title("World!");

	LDL_TEST_EQUAL(baseWindow.Title() == "World!");
}

int main()
{
	Init();
	ChangeTitle();

	return 0;
}