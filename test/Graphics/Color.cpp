#include <LDL/Core/TestEqual.hpp>
#include <LDL/Graphics/Color.hpp>

using namespace LDL::Graphics;

void Default()
{
	Color color;

	LDL_TEST_EQUAL(color.Red() == 0);
	LDL_TEST_EQUAL(color.Green() == 0);
	LDL_TEST_EQUAL(color.Blue() == 0);
	LDL_TEST_EQUAL(color.Alpha() == 255);
}

void NoAlpha()
{
	Color color(15, 20, 25);

	LDL_TEST_EQUAL(color.Red() == 15);
	LDL_TEST_EQUAL(color.Green() == 20);
	LDL_TEST_EQUAL(color.Blue() == 25);
	LDL_TEST_EQUAL(color.Alpha() == 255);
}

void YesAlpha()
{
	Color color(15, 20, 25, 100);

	LDL_TEST_EQUAL(color.Red() == 15);
	LDL_TEST_EQUAL(color.Green() == 20);
	LDL_TEST_EQUAL(color.Blue() == 25);
	LDL_TEST_EQUAL(color.Alpha() == 100);
}

int main()
{
	Default();
	NoAlpha();
	YesAlpha();

	return 0;
}