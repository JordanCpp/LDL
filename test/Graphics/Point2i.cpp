#include <LDL/Core/TestEqual.hpp>
#include <LDL/Graphics/Primitives/Point2i.hpp>

using namespace LDL::Graphics;

void InitDefault()
{
	Point2i point;

	LDL_TEST_EQUAL(point.PosX() == 0);
	LDL_TEST_EQUAL(point.PosY() == 0);
}

void InitValue()
{
	Point2i point(125, 385);

	LDL_TEST_EQUAL(point.PosX() == 125);
	LDL_TEST_EQUAL(point.PosY() == 385);
}

void InitPosX()
{
	Point2i point;

	point.PosX(45);

	LDL_TEST_EQUAL(point.PosX() == 45);
	LDL_TEST_EQUAL(point.PosY() == 0);
}

void InitPosY()
{
	Point2i point;

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