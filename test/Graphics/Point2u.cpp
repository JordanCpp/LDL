#include <LDL/Core/TestEqual.hpp>
#include <LDL/Graphics/Primitives/Point2u.hpp>

using namespace LDL::Graphics;

void InitDefault()
{
	Point2u point;

	LDL_TEST_EQUAL(point.PosX() == 0);
	LDL_TEST_EQUAL(point.PosY() == 0);
}

void InitValue()
{
	Point2u point(125, 385);

	LDL_TEST_EQUAL(point.PosX() == 125);
	LDL_TEST_EQUAL(point.PosY() == 385);
}

void InitPosX()
{
	Point2u point;

	point.PosX(45);

	LDL_TEST_EQUAL(point.PosX() == 45);
	LDL_TEST_EQUAL(point.PosY() == 0);
}

void InitPosY()
{
	Point2u point;

	point.PosY(45);

	LDL_TEST_EQUAL(point.PosX() == 0);
	LDL_TEST_EQUAL(point.PosY() == 45);
}

int main()
{
	InitDefault();
	InitValue();
	InitPosX();
	InitPosY();

	return 0;
}