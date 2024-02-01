#include <LDL/LDL.hpp>

void LDL_ColorTest()
{
	LDL_Color color1;

	LDL_TEST_EQUAL(color1.r == 0);
	LDL_TEST_EQUAL(color1.g == 0);
	LDL_TEST_EQUAL(color1.b == 0);
	LDL_TEST_EQUAL(color1.a == 255);
}

int main()
{
	LDL_ColorTest();

	return 0;
}