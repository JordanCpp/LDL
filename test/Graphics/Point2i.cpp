#include <LDL/Core/TestEqual.hpp>
#include <LDL/Graphics/Point2i.hpp>

void DefaultInit()
{
	LDL::Graphics::Point2i point;

	LDL_TEST_EQUAL(point.PosX() == 0);
	LDL_TEST_EQUAL(point.PosY() == 0);
}

void ValueInit()
{
	LDL::Graphics::Point2i point2(125, 385);

	LDL_TEST_EQUAL(point2.PosX() == 125);
	LDL_TEST_EQUAL(point2.PosY() == 385);
}

int main()
{
	DefaultInit();
	ValueInit();

	return 0;
}