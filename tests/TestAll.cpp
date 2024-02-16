#include <LDL/LDL.hpp>
#include <string.h>

void LDL_ColorTest()
{
	LDL_Color color1;

	LDL_TEST_EQUAL(color1.r == 0);
	LDL_TEST_EQUAL(color1.g == 0);
	LDL_TEST_EQUAL(color1.b == 0);
	LDL_TEST_EQUAL(color1.a == 255);
}

void LDL_Vec2iTest()
{
	LDL_Vec2i vec1;

	LDL_TEST_EQUAL(vec1.x == 0);
	LDL_TEST_EQUAL(vec1.y == 0);

	LDL_Vec2i vec2(100, 150);

	LDL_TEST_EQUAL(vec2.x == 100);
	LDL_TEST_EQUAL(vec2.y == 150);
}

void LDL_PaletteTest()
{
	LDL_Palette palette;

	for (size_t i = 0; i < LDL_Palette::Max; i++)
	{
		LDL_TEST_EQUAL(palette.Get(i).r == 0);
		LDL_TEST_EQUAL(palette.Get(i).g == 0);
		LDL_TEST_EQUAL(palette.Get(i).b == 0);
		LDL_TEST_EQUAL(palette.Get(i).a == 0);
	}

	for (size_t j = 0; j < LDL_Palette::Max; j++)
	{
		palette.Set(j, LDL_Color(1, 2, 3, 4));
	}

	for (size_t k = 0; k < LDL_Palette::Max; k++)
	{
		LDL_TEST_EQUAL(palette.Get(k).r == 1);
		LDL_TEST_EQUAL(palette.Get(k).g == 2);
		LDL_TEST_EQUAL(palette.Get(k).b == 3);
		LDL_TEST_EQUAL(palette.Get(k).a == 4);
	}
}

void LDL_WindowTest()
{
	LDL_Result result;

	LDL_Window window(&result, LDL_Vec2i(5, 15), LDL_Vec2i(800, 600), "LDL_WindowTest");

	LDL_TEST_EQUAL(result.Ok()     == true);
	LDL_TEST_EQUAL(window.Pos().x  == 5);
	LDL_TEST_EQUAL(window.Pos().y  == 15);
	LDL_TEST_EQUAL(window.Size().x == 800);
	LDL_TEST_EQUAL(window.Size().y == 600);
	LDL_TEST_EQUAL(strcmp(window.Title(), "LDL_WindowTest") == 0);
}

void LDL_RenderTest()
{
	LDL_Result result;

	LDL_Window window(&result, LDL_Vec2i(5, 15), LDL_Vec2i(800, 600), "LDL_WindowTest");
	LDL_Render render(&window);

	LDL_TEST_EQUAL(result.Ok()     == true);
	LDL_TEST_EQUAL(window.Pos().x  == 5);
	LDL_TEST_EQUAL(window.Pos().y  == 15);
	LDL_TEST_EQUAL(window.Size().x == 800);
	LDL_TEST_EQUAL(window.Size().y == 600);
	LDL_TEST_EQUAL(strcmp(window.Title(), "LDL_WindowTest") == 0);
}

int main()
{
	LDL_ColorTest();
	LDL_Vec2iTest();
	LDL_PaletteTest();
	LDL_WindowTest();
	LDL_RenderTest();

	return 0;
}