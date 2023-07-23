#include <LDL/Core/TestEqual.hpp>
#include <LDL/Graphics/Rect.hpp>
#include <LDL/Math/Vec2.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;

void DefaultInit()
{
	Rectu rect;

	LDL_TEST_EQUAL(rect.Pos().x  == 0);
	LDL_TEST_EQUAL(rect.Pos().y  == 0);
	LDL_TEST_EQUAL(rect.Size().x == 0);
	LDL_TEST_EQUAL(rect.Size().y == 0);
}

void ValueInit()
{
	Rectu rect(15, 25, 35, 45);

	LDL_TEST_EQUAL(rect.Pos().x  == 15);
	LDL_TEST_EQUAL(rect.Pos().y  == 25);
	LDL_TEST_EQUAL(rect.Size().x == 35);
	LDL_TEST_EQUAL(rect.Size().y == 45);
}

void Point2Init()
{
	Rectu rect(Vec2u(115, 125), Vec2u(135, 145));

	LDL_TEST_EQUAL(rect.Pos().x  == 115);
	LDL_TEST_EQUAL(rect.Pos().y  == 125);
	LDL_TEST_EQUAL(rect.Size().x == 135);
	LDL_TEST_EQUAL(rect.Size().y == 145);
}

void Contains()
{
	Rectu rect(Vec2u(0, 0), Vec2u(640, 480));

	LDL_TEST_EQUAL(rect.Contains(Vec2u(143, 67))  == true);
	LDL_TEST_EQUAL(rect.Contains(Vec2u(641, 481)) == false);
}

int main()
{
	DefaultInit();
	ValueInit();
	Point2Init();
	Contains();

	return 0;
}
