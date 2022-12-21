#include <LDL/Core/TestEqual.hpp>
#include <LDL/Graphics/Primitives/Rect2u.hpp>
#include <LDL/Graphics/Primitives/Point2u.hpp>

using namespace LDL::Graphics;

void DefaultInit()
{
	Rect2u rect;

	LDL_TEST_EQUAL(rect.Pos().PosX()  == 0);
	LDL_TEST_EQUAL(rect.Pos().PosY()  == 0);
	LDL_TEST_EQUAL(rect.Size().PosX() == 0);
	LDL_TEST_EQUAL(rect.Size().PosY() == 0);
}

void ValueInit()
{
	Rect2u rect(15, 25, 35, 45);

	LDL_TEST_EQUAL(rect.Pos().PosX()  == 15);
	LDL_TEST_EQUAL(rect.Pos().PosY()  == 25);
	LDL_TEST_EQUAL(rect.Size().PosX() == 35);
	LDL_TEST_EQUAL(rect.Size().PosY() == 45);
}

void Point2Init()
{
	Rect2u rect(Point2u(115, 125), Point2u(135, 145));

	LDL_TEST_EQUAL(rect.Pos().PosX()  == 115);
	LDL_TEST_EQUAL(rect.Pos().PosY()  == 125);
	LDL_TEST_EQUAL(rect.Size().PosX() == 135);
	LDL_TEST_EQUAL(rect.Size().PosY() == 145);
}

void Contains()
{
	Rect2u rect(Point2u(0, 0), Point2u(640, 480));

	LDL_TEST_EQUAL(rect.Contains(Point2u(143, 67))  == true);
	LDL_TEST_EQUAL(rect.Contains(Point2u(641, 481)) == false);
}

int main()
{
	DefaultInit();
	ValueInit();
	Point2Init();
	Contains();

	return 0;
}