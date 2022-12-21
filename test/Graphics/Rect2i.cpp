#include <LDL/Core/TestEqual.hpp>
#include <LDL/Graphics/Primitives/Rect2i.hpp>
#include <LDL/Graphics/Primitives/Point2i.hpp>

using namespace LDL::Graphics;

void DefaultInit()
{
	Rect2i rect;

	LDL_TEST_EQUAL(rect.Pos().PosX()  == 0);
	LDL_TEST_EQUAL(rect.Pos().PosY()  == 0);
	LDL_TEST_EQUAL(rect.Size().PosX() == 0);
	LDL_TEST_EQUAL(rect.Size().PosY() == 0);
}

void ValueInit()
{
	Rect2i rect(15, 25, 35, 45);

	LDL_TEST_EQUAL(rect.Pos().PosX()  == 15);
	LDL_TEST_EQUAL(rect.Pos().PosY()  == 25);
	LDL_TEST_EQUAL(rect.Size().PosX() == 35);
	LDL_TEST_EQUAL(rect.Size().PosY() == 45);
}

void Point2Init()
{
	Rect2i rect(Point2i(115, 125), Point2i(135, 145));

	LDL_TEST_EQUAL(rect.Pos().PosX()  == 115);
	LDL_TEST_EQUAL(rect.Pos().PosY()  == 125);
	LDL_TEST_EQUAL(rect.Size().PosX() == 135);
	LDL_TEST_EQUAL(rect.Size().PosY() == 145);
}

void Contains()
{
	Rect2i rect(Point2i(0, 0), Point2i(640, 480));

	LDL_TEST_EQUAL(rect.Contains(Point2i(143, 67))  == true);
	LDL_TEST_EQUAL(rect.Contains(Point2i(641, 481)) == false);
}

int main()
{
	DefaultInit();
	ValueInit();
	Point2Init();
	Contains();

	return 0;
}