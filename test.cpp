//#define LDL_RENDER_OPENGL1
#define LDL_RENDER_SOFTWARE
#include <LDL/LDL_RdrX.hpp>

void LDL_ResultTest()
{
	LDL_Result result;
	LDL_TEST_EQUAL(result.Ok() == true);
	LDL_TEST_EQUAL(strcmp(result.Message(), "") == 0);

	result.Message("Error!");
	LDL_TEST_EQUAL(result.Ok() == false);
	LDL_TEST_EQUAL(strcmp(result.Message(), "Error!") == 0);

	result.Clear();
	LDL_TEST_EQUAL(result.Ok() == true);
	LDL_TEST_EQUAL(strcmp(result.Message(), "") == 0);
}

void LDL_WindowTest()
{
	LDL_Result result;
	LDL_Window window(&result, LDL_Vec2i(0, 0), LDL_Vec2i(800, 600), "WindowTest");

	LDL_TEST_EQUAL(result.Ok() == true);
	LDL_TEST_EQUAL(window.Pos().x == 0);
	LDL_TEST_EQUAL(window.Pos().y == 0);
	LDL_TEST_EQUAL(window.Size().x == 800);
	LDL_TEST_EQUAL(window.Size().y == 600);
	LDL_TEST_EQUAL(strcmp(window.Title(), "WindowTest") == 0);
}

int main()
{
	LDL_ResultTest();
	LDL_WindowTest();

	return 0;
}