#include <LDL/Core/TestEqual.hpp>
#include <LDL/Graphics/Color.hpp>

using namespace LDL::Graphics;

void Default()
{
	Color color;

	LDL_TEST_EQUAL(color.r == 0);
	LDL_TEST_EQUAL(color.g == 0);
	LDL_TEST_EQUAL(color.b == 0);
	LDL_TEST_EQUAL(color.a == 255);
}

void NoAlpha()
{
	Color color(15, 20, 25);

	LDL_TEST_EQUAL(color.r == 15);
	LDL_TEST_EQUAL(color.g == 20);
	LDL_TEST_EQUAL(color.b == 25);
	LDL_TEST_EQUAL(color.a == 255);
}

void YesAlpha()
{
	Color color(15, 20, 25, 100);

	LDL_TEST_EQUAL(color.r == 15);
	LDL_TEST_EQUAL(color.g == 20);
	LDL_TEST_EQUAL(color.b == 25);
	LDL_TEST_EQUAL(color.a == 100);
}

int main()
{
	Default();
	NoAlpha();
	YesAlpha();

	return 0;
}
