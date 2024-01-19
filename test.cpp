//#define LDL_RENDER_OPENGL1
#define LDL_RENDER_SOFTWARE
#include <LDL/LDL_RdrX.hpp>

void LDL_ColorTest()
{
	LDL_Color color1;
	LDL_TEST_EQUAL(color1.r == 0);
	LDL_TEST_EQUAL(color1.g == 0);
	LDL_TEST_EQUAL(color1.b == 0);
	LDL_TEST_EQUAL(color1.a == 255);

	LDL_Color color2(1, 2, 3, 4);
	LDL_TEST_EQUAL(color2.r == 1);
	LDL_TEST_EQUAL(color2.g == 2);
	LDL_TEST_EQUAL(color2.b == 3);
	LDL_TEST_EQUAL(color2.a == 4);
}

void LDL_Vec2iTest()
{
	LDL_Vec2i vec1;
	LDL_TEST_EQUAL(vec1.x == 0);
	LDL_TEST_EQUAL(vec1.y == 0);

	LDL_Vec2i vec2(1, 2);
	LDL_TEST_EQUAL(vec2.x == 1);
	LDL_TEST_EQUAL(vec2.y == 2);
}

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

void LDL_RenderTest()
{
	LDL_Result result;
	LDL_Window window(&result, LDL_Vec2i(0, 0), LDL_Vec2i(800, 600), "WindowTest");

	LDL_Render render(&window);
	LDL_TEST_EQUAL(result.Ok() == true);

	render.Begin();
	LDL_TEST_EQUAL(result.Ok() == true);

	render.End();
	LDL_TEST_EQUAL(result.Ok() == true);
}

void LDL_NumberToStringTest()
{
	LDL_NumberToString conv;

	LDL_TEST_EQUAL(strcmp(conv.Convert((int)100500L), "100500") == 0);
	LDL_TEST_EQUAL(strcmp(conv.Convert((int)+100500L), "100500") == 0);
	LDL_TEST_EQUAL(strcmp(conv.Convert((int)-100500L), "-100500") == 0);

	LDL_TEST_EQUAL(strcmp(conv.Convert((size_t)100500L), "100500") == 0);
	LDL_TEST_EQUAL(strcmp(conv.Convert((size_t)+100500L), "100500") == 0);
}

void LDL_BmpLoaderTest()
{
	LDL_Result result;

	LDL_BmpLoader loader(&result);
	LDL_TEST_EQUAL(result.Ok() == true);
	LDL_TEST_EQUAL(loader.Bpp() == 0);
	LDL_TEST_EQUAL(loader.Pixels() == NULL);
	LDL_TEST_EQUAL(loader.Size().x == 0);
	LDL_TEST_EQUAL(loader.Size().y == 0);
}

void LDL_SurfaceTest()
{
	LDL_Surface surface1(LDL_Vec2i(640, 480), 4);
	LDL_TEST_EQUAL(surface1.Pixels() != NULL);
	LDL_TEST_EQUAL(surface1.Capacity().x == 640);
	LDL_TEST_EQUAL(surface1.Capacity().y == 480);
	LDL_TEST_EQUAL(surface1.Size().x == 640);
	LDL_TEST_EQUAL(surface1.Size().y == 480);
	LDL_TEST_EQUAL(surface1.Bpp() == 4);
}

int main()
{
	LDL_ColorTest();
	LDL_Vec2iTest();
	LDL_ResultTest();
	LDL_WindowTest();
	LDL_RenderTest();
	LDL_NumberToStringTest();
	LDL_BmpLoaderTest();
	LDL_SurfaceTest();

	return 0;
}