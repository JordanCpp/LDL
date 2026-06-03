/*
 * -----------------------------------------------------------------------------
 * This example is in the public domain (CC0 1.0 Universal).
 * You can copy, modify, use, and distribute it for any purpose.
 * -----------------------------------------------------------------------------
 */

#include <stdio.h>
#include <string.h>
#include <LDL/LDL.h>

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

	formatter = LDL_FormatterNew();
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

	LDL_FormatterFree(formatter);
}

void ResultTest()
{
	const char* str;
	LDL_Result* result = LDL_ResultNew();
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

	LDL_ResultFree(result);
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

	result  = LDL_ResultNew();
	context = LDL_ContextNew(result, contextType);
	window  = LDL_WindowNew(result, context, LDL_GetVec2i(5, 10), LDL_GetVec2i(640, 480), "WindowTest", LDL_WindowModeResized);

	LDL_TEST(window != NULL);
	LDL_TEST(LDL_ResultIsOk(result) == true);

	LDL_TEST(LDL_WindowIsRunning(window) == true);
	LDL_TEST(LDL_ResultIsOk(result) == true);

	LDL_TEST(LDL_WindowGetSize(window).x == 640);
	LDL_TEST(LDL_ResultIsOk(result) == true);

	LDL_TEST(LDL_WindowGetSize(window).y == 480);
	LDL_TEST(LDL_ResultIsOk(result) == true);

	LDL_TEST(strcmp(LDL_WindowGetTitle(window), "WindowTest") == 0);
	LDL_TEST(LDL_ResultIsOk(result) == true);

	LDL_WindowSetTitle(window, "WindowTest new title");
	LDL_TEST(LDL_ResultIsOk(result) == true);
	LDL_TEST(strcmp(LDL_WindowGetTitle(window), "WindowTest new title") == 0);

	LDL_TEST(window != NULL);
	LDL_WindowFree(window);

	LDL_TEST(context != NULL);
	LDL_ContextFree(context);

	LDL_TEST(result != NULL);
	LDL_ResultFree(result);
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
	LDL_Render*  render;
	LDL_Texture* textures[TexturesMax];
	size_t i;
	size_t j;
	size_t k;
	LDL_Vec2i pos;

	result  = LDL_ResultNew();
	context = LDL_ContextNew(result, contextType);
	window  = LDL_WindowNew(result, context, LDL_GetVec2i(5, 10), LDL_GetVec2i(640, 480), "RenderTest", LDL_WindowModeResized);
	render  = LDL_RenderNew(result, context, window);

	LDL_TEST(render != NULL);
	LDL_TEST(LDL_ResultIsOk(result) == true);

	for (i = 0; i < TexturesMax; i++)
	{
		textures[i] = LDL_TextureNewFromSize(result, context, LDL_PixelFormatRGB24, LDL_GetVec2i(256, 256));
		LDL_TEST(textures[i] != NULL);
		LDL_TEST(LDL_ResultIsOk(result) == true);
		LDL_TEST(LDL_TextureGetSize(textures[i]).x == 256);
		LDL_TEST(LDL_TextureGetSize(textures[i]).y == 256);
	}

	for (j = 0; j < TexturesMax; j++)
	{
		LDL_RenderBegin(render);
		LDL_TEST(LDL_ResultIsOk(result) == true);

		LDL_RenderClear(render);
		LDL_TEST(LDL_ResultIsOk(result) == true);

		pos = LDL_GetVec2i(15, 35);
		LDL_RenderDraw(render, textures[j], &pos, NULL, NULL, NULL);
		LDL_TEST(LDL_ResultIsOk(result) == true);

		LDL_RenderLine2i(render, LDL_GetVec2i(15, 35), LDL_GetVec2i(150, 250));
		LDL_TEST(LDL_ResultIsOk(result) == true);

		LDL_RenderFill2i(render, LDL_GetVec2i(15, 35), LDL_GetVec2i(150, 250));
		LDL_TEST(LDL_ResultIsOk(result) == true);

		LDL_RenderEnd(render);
		LDL_TEST(LDL_ResultIsOk(result) == true);
	}

	for (k = 0; k < TexturesMax; k++)
	{
		LDL_TextureFree(textures[k]);
	}

	LDL_TEST(render != NULL);
	LDL_RenderFree(render);

	LDL_TEST(window != NULL);
	LDL_WindowFree(window);

	LDL_TEST(context != NULL);
	LDL_ContextFree(context);

	LDL_TEST(result != NULL);
	LDL_ResultFree(result);
}

int main()
{
	Vec2iTest();
	ColorTest();
	FormatterTest();
	ResultTest();
	PixelFormatTest();

	WindowTest(LDL_ContextOpenGLLegacy);
	WindowTest(LDL_ContextOpenGLHybrid);
	WindowTest(LDL_ContextOpenGLModern);

	RenderTest(LDL_ContextOpenGLLegacy);
	RenderTest(LDL_ContextOpenGLLegacy);
	RenderTest(LDL_ContextOpenGLModern);

    return 0;
}
