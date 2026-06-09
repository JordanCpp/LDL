/*
 * -----------------------------------------------------------------------------
 * This example is in the public domain (CC0 1.0 Universal).
 * You can copy, modify, use, and distribute it for any purpose.
 * -----------------------------------------------------------------------------
 */

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <LDL/LDL.h>
#include <LDL/Mat4f.h>

void LDL_TestEqual(bool condition, const char* description, const char* function, const char* file, int line)
{
	if (!condition)
	{
		printf("Test failed: %s, function: %s, file: %s, line: %d\n", description, function, file, line);
	}
}

#define LDL_TEST(x) LDL_TestEqual(x, #x, "__FUNCTION__", __FILE__, __LINE__)

void Vec2iTest()
{
	LDL_Vec2i vec = LDL_GetVec2i(5, 10);

	LDL_TEST(vec.x == 5);
	LDL_TEST(vec.y == 10);
}

void ColorTest()
{
	LDL_Color rgb  = LDL_ColorRgb(1, 2, 3);
	LDL_Color rgba = LDL_ColorRgba(1, 2, 3, 4);

	LDL_TEST(rgb.r == 1);
	LDL_TEST(rgb.g == 2);
	LDL_TEST(rgb.b == 3);
	LDL_TEST(rgb.a == 0);

	LDL_TEST(rgba.r == 1);
	LDL_TEST(rgba.g == 2);
	LDL_TEST(rgba.b == 3);
	LDL_TEST(rgba.a == 4);
}

void FormatterTest()
{
	const char* str;
	LDL_Formatter* formatter;

	formatter = LDL_FormatterCreate();
	LDL_TEST(formatter != NULL);

	str = LDL_FormatterGetData(formatter);
	LDL_TEST(strcmp(str, "") == 0);

	str = LDL_FormatterFormat(formatter, "Word %s and Number %d\n", "one", 1);
	LDL_TEST(strcmp(str, "Word one and Number 1\n") == 0);
	LDL_TEST(formatter != NULL);

	str = LDL_FormatterFormat(formatter, "Word %s and Number %d\n", "two", 2);
	LDL_TEST(strcmp(str, "Word two and Number 2\n") == 0);
	LDL_TEST(formatter != NULL);

	str = LDL_FormatterFormat(formatter, "Word %s and Number %d\n", "tree", 3);
	LDL_TEST(strcmp(str, "Word tree and Number 3\n") == 0);
	LDL_TEST(formatter != NULL);

	LDL_FormatterDestroy(formatter);
}

void ResultTest()
{
	const char* str;
	LDL_Result* result = LDL_ResultCreate();
	LDL_TEST(result != NULL);
	LDL_TEST(LDL_ResultIsOk(result)   == true);
	LDL_TEST(LDL_ResultIsFail(result) == false);
	str = LDL_ResultGetMessage(result);
	LDL_TEST(strcmp(str, "") == 0);

	LDL_ResultAddMessage(result, "Word %s and Number %d\n", "hello", 42);
	LDL_TEST(result != NULL);
	LDL_TEST(LDL_ResultIsOk(result) == false);
	LDL_TEST(LDL_ResultIsFail(result) == true);
	str = LDL_ResultGetMessage(result);
	LDL_TEST(strcmp(str, "Word hello and Number 42\n") == 0);

	LDL_ResultDestroy(result);
}

void PixelFormatTest()
{
	LDL_TEST(LDL_BytesPerPixelFromPixelFormat(LDL_PixelFormatRGBA32) == 4);
	LDL_TEST(LDL_BytesPerPixelFromPixelFormat(LDL_PixelFormatBGRA32) == 4);
	LDL_TEST(LDL_BytesPerPixelFromPixelFormat(LDL_PixelFormatRGB24)  == 3);
	LDL_TEST(LDL_BytesPerPixelFromPixelFormat(LDL_PixelFormatBGR24)  == 3);
	LDL_TEST(LDL_BytesPerPixelFromPixelFormat(100500) == LDL_PixelFormatUnknown);
}

void WindowTest(size_t contextType)
{
	LDL_Result*  result;
	LDL_Context* context;
	LDL_Window*  window;

	result  = LDL_ResultCreate();
	context = LDL_ContextCreate(result, contextType);
	window  = LDL_WindowCreate(result, context, LDL_GetVec2i(5, 10), LDL_GetVec2i(640, 480), "WindowTest", LDL_WindowModeResized);

	LDL_TEST(window != NULL);
	LDL_TEST(LDL_ResultIsOk(result) == true);

	LDL_TEST(LDL_WindowIsRunning(window) == true);
	LDL_TEST(LDL_ResultIsOk(result) == true);

	/*
	LDL_TEST(LDL_WindowGetSize(window).x == 640);
	LDL_TEST(LDL_ResultIsOk(result) == true);
	LDL_TEST(LDL_WindowGetSize(window).y == 480);
	LDL_TEST(LDL_ResultIsOk(result) == true);
	*/

	LDL_TEST(strcmp(LDL_WindowGetTitle(window), "WindowTest") == 0);
	LDL_TEST(LDL_ResultIsOk(result) == true);

	LDL_WindowSetTitle(window, "WindowTest new title");
	LDL_TEST(LDL_ResultIsOk(result) == true);
	LDL_TEST(strcmp(LDL_WindowGetTitle(window), "WindowTest new title") == 0);

	LDL_TEST(window != NULL);
	LDL_WindowDestroy(window);

	LDL_TEST(context != NULL);
	LDL_ContextDestroy(context);

	LDL_TEST(result != NULL);
	LDL_ResultDestroy(result);
}

void RenderTest(size_t contextType)
{
	enum
	{
		TexturesMax = 32
	};

	LDL_Result*  result;
	LDL_Context* context;
	LDL_Window*  window;
	LDL_2DRender*  render;
	LDL_Texture* textures[TexturesMax];
	size_t i;
	size_t j;
	size_t k;
	LDL_Vec2i pos;

	result  = LDL_ResultCreate();
	context = LDL_ContextCreate(result, contextType);
	window  = LDL_WindowCreate(result, context, LDL_GetVec2i(5, 10), LDL_GetVec2i(640, 480), "RenderTest", LDL_WindowModeResized);
	render  = LDL_2DRenderCreate(result, context, window);

	LDL_TEST(render != NULL);
	LDL_TEST(LDL_ResultIsOk(result) == true);

	for (i = 0; i < TexturesMax; i++)
	{
		textures[i] = LDL_TextureCreateFromSize(result, context, LDL_PixelFormatRGB24, LDL_GetVec2i(256, 256));
		LDL_TEST(textures[i] != NULL);
		LDL_TEST(LDL_ResultIsOk(result) == true);
		LDL_TEST(LDL_TextureGetSize(textures[i]).x == 256);
		LDL_TEST(LDL_TextureGetSize(textures[i]).y == 256);
	}

	for (j = 0; j < TexturesMax; j++)
	{
		LDL_2DRenderBegin(render);
		LDL_TEST(LDL_ResultIsOk(result) == true);

		LDL_2DRenderClear(render);
		LDL_TEST(LDL_ResultIsOk(result) == true);

		pos = LDL_GetVec2i(15, 35);
		LDL_2DRenderDraw(render, textures[j], &pos, NULL, NULL, NULL);
		LDL_TEST(LDL_ResultIsOk(result) == true);

		LDL_2DRenderLine(render, LDL_GetVec2i(15, 35), LDL_GetVec2i(150, 250));
		LDL_TEST(LDL_ResultIsOk(result) == true);

		LDL_2DRenderFill(render, LDL_GetVec2i(15, 35), LDL_GetVec2i(150, 250));
		LDL_TEST(LDL_ResultIsOk(result) == true);

		LDL_2DRenderEnd(render);
		LDL_TEST(LDL_ResultIsOk(result) == true);
	}

	for (k = 0; k < TexturesMax; k++)
	{
		LDL_TextureDestroy(textures[k]);
	}

	LDL_TEST(render != NULL);
	LDL_2DRenderDestroy(render);

	LDL_TEST(window != NULL);
	LDL_WindowDestroy(window);

	LDL_TEST(context != NULL);
	LDL_ContextDestroy(context);

	LDL_TEST(result != NULL);
	LDL_ResultDestroy(result);
}

void SurfaceTest(uint8_t pixelFormat)
{
	LDL_Result* result = LDL_ResultCreate();

	LDL_Surface* surface = LDL_SurfaceCreateFromSize(result, pixelFormat, LDL_GetVec2i(640, 480));
	LDL_TEST(LDL_ResultIsOk(result)             == true);
	LDL_TEST(LDL_SurfaceGetPixels(surface)      != NULL);
	LDL_TEST(LDL_SurfaceGetPixelFormat(surface) == pixelFormat);
	LDL_TEST(LDL_SurfaceGetSize(surface).x      == 640);
	LDL_TEST(LDL_SurfaceGetSize(surface).y      == 480);
	LDL_TEST(LDL_SurfaceGetCapacity(surface).x  == 640);
	LDL_TEST(LDL_SurfaceGetCapacity(surface).y  == 480);
	
	LDL_SurfaceDestroy(surface);
	LDL_ResultDestroy(result);
}

/* Вспомогательная функция для сравнения float (с учетом погрешности) */
static int IsFloatEqual(float a, float b)
{
	float epsilon;
	epsilon = 0.0001f;

	return (float)fabs(a - b) < epsilon;
}

/* Тест Identity: проверка единичной матрицы */
void Mat4fIdentityTest()
{
	LDL_Mat4f mat;

	LDL_Mat4fIdentity(&mat);

	/* Проверка диагональных элементов */
	LDL_TEST(IsFloatEqual(mat.Values[0], 1.0f));
	LDL_TEST(IsFloatEqual(mat.Values[5], 1.0f));
	LDL_TEST(IsFloatEqual(mat.Values[10], 1.0f));
	LDL_TEST(IsFloatEqual(mat.Values[15], 1.0f));

	/* Проверка недиагональных элементов (должны быть 0) */
	LDL_TEST(IsFloatEqual(mat.Values[1], 0.0f));
	LDL_TEST(IsFloatEqual(mat.Values[4], 0.0f));
	LDL_TEST(IsFloatEqual(mat.Values[14], 0.0f));
}

/* Тест Translate: проверка смещения */
void Mat4fTranslateTest()
{
	LDL_Mat4f mat;
	float tx, ty, tz;

	tx = 10.0f;
	ty = -5.0f;
	tz = 2.5f;

	LDL_Mat4fIdentity(&mat);
	LDL_Mat4fTranslate(&mat, tx, ty, tz);

	/* В колонке 4 (индексы 12, 13, 14) должны быть наши значения */
	LDL_TEST(IsFloatEqual(mat.Values[12], tx));
	LDL_TEST(IsFloatEqual(mat.Values[13], ty));
	LDL_TEST(IsFloatEqual(mat.Values[14], tz));
}

/* Тест Multiply: проверка умножения матриц (Identity * A = A) */
void Mat4fMultiplyTest()
{
	LDL_Mat4f identity;
	LDL_Mat4f translation;
	LDL_Mat4f res;

	LDL_Mat4fIdentity(&identity);
	LDL_Mat4fIdentity(&translation);
	LDL_Mat4fTranslate(&translation, 1.0f, 2.0f, 3.0f);

	LDL_Mat4fMultiply(&res, &identity, &translation);

	/* Результат должен быть равен translation */
	LDL_TEST(IsFloatEqual(res.Values[12], 1.0f));
	LDL_TEST(IsFloatEqual(res.Values[13], 2.0f));    LDL_TEST(IsFloatEqual(res.Values[14], 3.0f));
}

/* Тест Rotate: проверка поворота на 90 градусов вокруг Z */
void Mat4fRotateTest()
{
	LDL_Mat4f mat;
	float angle;
	float deg2rad;

	/* 90 градусов в радианах */
	angle = 1.570796f;
	deg2rad = 1.0f; /* просто заглушка для логики, если нужно было бы переводить */

	LDL_Mat4fIdentity(&mat);
	/* Поворот вокруг оси Z (0,0,1) */
	LDL_Mat4fRotate(&mat, angle, 0.0f, 0.0f, 1.0f);

	/* При повороте на 90 по Z:
	   x' = x*cos - y*sin
	   y' = x*sin + y*cos
	   Матрица должна иметь cos(90)=0 и sin(90)=1 в нужных ячейках
	*/
	LDL_TEST(IsFloatEqual(mat.Values[0], 0.0f)); /* cos */
	LDL_TEST(IsFloatEqual(mat.Values[1], -1.0f)); /* -sin */
	LDL_TEST(IsFloatEqual(mat.Values[4], 1.0f)); /* sin */
	LDL_TEST(IsFloatEqual(mat.Values[5], 0.0f)); /* cos */
}

/* Тест Ortho: проверка базовых параметров ортографической матрицы */
void Mat4fOrthoTest()
{
	LDL_Mat4f mat;
	float l, r, b, t, f, n;

	l = -10.0f; r = 10.0f;
	b = -5.0f;  t = 5.0f;
	f = 1.0f;   n = 1.0f;

	LDL_Mat4fOrtho(&mat, l, r, b, t, f, n);

	/* Масштаб по X должен быть 2 / (r - l) -> 2 / 20 = 0.1 */
	LDL_TEST(IsFloatEqual(mat.Values[0], 0.1f));
	/* Масштаб по Y должен быть 2 / (t - b) -> 2 / 10 = 0.2 */
	LDL_TEST(IsFloatEqual(mat.Values[5], 0.2f));
}

int main()
{
	Vec2iTest();
	ColorTest();
	FormatterTest();
	ResultTest();
	PixelFormatTest();

	SurfaceTest(LDL_PixelFormatRGB24);
	SurfaceTest(LDL_PixelFormatBGR24);
	SurfaceTest(LDL_PixelFormatRGBA32);
	SurfaceTest(LDL_PixelFormatBGRA32);

	WindowTest(LDL_ContextOpenGLLegacy);
	WindowTest(LDL_ContextOpenGLHybrid);
	WindowTest(LDL_ContextOpenGLModern);

	RenderTest(LDL_ContextOpenGLLegacy);
	RenderTest(LDL_ContextOpenGLLegacy);
	RenderTest(LDL_ContextOpenGLModern);

	Mat4fIdentityTest();
	Mat4fTranslateTest();
	Mat4fMultiplyTest();
	Mat4fRotateTest();
	Mat4fOrthoTest();

    return 0;
}
