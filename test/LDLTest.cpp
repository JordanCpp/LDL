// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <stdlib.h>
#include <string.h>
#include <LDL/LDL.hpp>
#include <LDL/TestEq.hpp>

/****************************************************************************************************************************
                                                              Color
****************************************************************************************************************************/

void ColorDefaultTest()
{
	LDL_Color color;

	LDL_TEST_EQUAL(color.r == 0);
	LDL_TEST_EQUAL(color.g == 0);
	LDL_TEST_EQUAL(color.b == 0);
	LDL_TEST_EQUAL(color.a == 255);
}

void ColorNoAlphaTest()
{
	LDL_Color color(15, 20, 25);

	LDL_TEST_EQUAL(color.r == 15);
	LDL_TEST_EQUAL(color.g == 20);
	LDL_TEST_EQUAL(color.b == 25);
	LDL_TEST_EQUAL(color.a == 255);
}

void ColorYesAlphaTest()
{
	LDL_Color color(15, 20, 25, 100);

	LDL_TEST_EQUAL(color.r == 15);
	LDL_TEST_EQUAL(color.g == 20);
	LDL_TEST_EQUAL(color.b == 25);
	LDL_TEST_EQUAL(color.a == 100);
}

/****************************************************************************************************************************
															  Window
****************************************************************************************************************************/

void CreateWindowTest()
{
	const char title[] = "LDL Window title!";

	LDL_Result result;
	LDL_RenderContext renderContext;

	LDL_IWindow* window = LDL_CreateWindow(result, renderContext, LDL_Vec2u(0, 0), LDL_Vec2u(640, 480), __FILE__, 0);

	LDL_TEST_EQUAL(window->Pos().x  == 1);
	LDL_TEST_EQUAL(window->Pos().y  == 2);
	LDL_TEST_EQUAL(window->Size().x == 640);
	LDL_TEST_EQUAL(window->Size().y == 480);
	LDL_TEST_EQUAL(window->Title()  == title);
}

/****************************************************************************************************************************
															  Formatter
****************************************************************************************************************************/

void FormatterTest()
{
	const size_t limit = 1024;

	LDL_Formatter formatter;

	InPlaceString<limit> strEmpty = formatter.Format("");
	LDL_TEST_EQUAL(strcmp(strEmpty.c_str(), "") == 0);

	InPlaceString<limit> strData = formatter.Format("Test string %s and number %d", "hello", 42);
	LDL_TEST_EQUAL(strcmp(strData.c_str(), "Test string hello and number 42") == 0);
}

/****************************************************************************************************************************
											      BytesPerPixelFromPixelFormat
****************************************************************************************************************************/

void BytesPerPixelFromPixelFormatTest()
{
	LDL_TEST_EQUAL(LDL_BytesPerPixelFromPixelFormat(100500)              == LDL_PixelFormat::UNKNOWN);
	LDL_TEST_EQUAL(LDL_BytesPerPixelFromPixelFormat(LDL_PixelFormat::RGB24)  == 3);
	LDL_TEST_EQUAL(LDL_BytesPerPixelFromPixelFormat(LDL_PixelFormat::BGR24)  == 3);
	LDL_TEST_EQUAL(LDL_BytesPerPixelFromPixelFormat(LDL_PixelFormat::RGBA32) == 4);
	LDL_TEST_EQUAL(LDL_BytesPerPixelFromPixelFormat(LDL_PixelFormat::BGRA32) == 4);
}

/****************************************************************************************************************************
															  Surface
****************************************************************************************************************************/

void SurfaceRGB24InitDefaultTest()
{
	LDL_Surface surface(LDL_PixelFormat::RGB24, LDL_Vec2u(640, 480));

	LDL_TEST_EQUAL(surface.Format()        == LDL_PixelFormat::RGB24);
	LDL_TEST_EQUAL(surface.BytesPerPixel() == 3);
	LDL_TEST_EQUAL(surface.Size().x        == 640);
	LDL_TEST_EQUAL(surface.Size().y        == 480);
	LDL_TEST_EQUAL(surface.Capacity().x    == 640);
	LDL_TEST_EQUAL(surface.Capacity().y    == 480);
	LDL_TEST_EQUAL(surface.Pitch()         == 3 * 640);
	LDL_TEST_EQUAL(surface.Pixels()        != NULL);
}

void SurfaceRGBA32InitDefaultTest()
{
	LDL_Surface surface(LDL_PixelFormat::RGBA32, LDL_Vec2u(640, 480));

	LDL_TEST_EQUAL(surface.Format()        == LDL_PixelFormat::RGBA32);
	LDL_TEST_EQUAL(surface.BytesPerPixel() == 4);
	LDL_TEST_EQUAL(surface.Size().x        == 640);
	LDL_TEST_EQUAL(surface.Size().y        == 480);
	LDL_TEST_EQUAL(surface.Capacity().x    == 640);
	LDL_TEST_EQUAL(surface.Capacity().y    == 480);
	LDL_TEST_EQUAL(surface.Pitch()         == 4 * 640);
	LDL_TEST_EQUAL(surface.Pixels()        != NULL);
}

void SurfaceBGR24InitDefaultTest()
{
	LDL_Surface surface(LDL_PixelFormat::BGR24, LDL_Vec2u(640, 480));

	LDL_TEST_EQUAL(surface.Format()        == LDL_PixelFormat::BGR24);
	LDL_TEST_EQUAL(surface.BytesPerPixel() == 3);
	LDL_TEST_EQUAL(surface.Size().x        == 640);
	LDL_TEST_EQUAL(surface.Size().y        == 480);
	LDL_TEST_EQUAL(surface.Capacity().x    == 640);
	LDL_TEST_EQUAL(surface.Capacity().y    == 480);
	LDL_TEST_EQUAL(surface.Pitch()         == 3 * 640);
	LDL_TEST_EQUAL(surface.Pixels()        != NULL);
}

void SurfaceBGRA32InitDefaultTest()
{
	LDL_Surface surface(LDL_PixelFormat::BGRA32, LDL_Vec2u(640, 480));

	LDL_TEST_EQUAL(surface.Format()        == LDL_PixelFormat::BGRA32);
	LDL_TEST_EQUAL(surface.BytesPerPixel() == 4);
	LDL_TEST_EQUAL(surface.Size().x        == 640);
	LDL_TEST_EQUAL(surface.Size().y        == 480);
	LDL_TEST_EQUAL(surface.Capacity().x    == 640);
	LDL_TEST_EQUAL(surface.Capacity().y    == 480);
	LDL_TEST_EQUAL(surface.Pitch()         == 4 * 640);
	LDL_TEST_EQUAL(surface.Pixels()        != NULL);
}

/****************************************************************************************************************************
															  Vec2
****************************************************************************************************************************/

void Vec2Test()
{
	LDL_Vec2u vec;
	LDL_TEST_EQUAL(vec.x == 0);
	LDL_TEST_EQUAL(vec.y == 0);

	LDL_Vec2u vec2 = LDL_Vec2u(50, 75);
	LDL_TEST_EQUAL(vec2.x == 50);
	LDL_TEST_EQUAL(vec2.y == 75);
}

void PixelPainterClearRGB24Test()
{
	const LDL_Vec2u size  = LDL_Vec2u(640, 480);
	const LDL_Color color = LDL_Color(25, 75, 125);

	PixelPainter painter;

	LDL_Surface surfRgb24(LDL_PixelFormat::RGB24, size);

	painter.ClearRGB24(surfRgb24.Pixels(), size, color);

	for (size_t i = 0; i < surfRgb24.Size().x * surfRgb24.Size().y * surfRgb24.BytesPerPixel(); i+= surfRgb24.BytesPerPixel())
	{
		LDL_TEST_EQUAL(surfRgb24.Pixels()[i + 0] == color.r);
		LDL_TEST_EQUAL(surfRgb24.Pixels()[i + 1] == color.g);
		LDL_TEST_EQUAL(surfRgb24.Pixels()[i + 2] == color.b);
	}
}

void PixelPainterClearBGR24Test()
{
	const LDL_Vec2u size = LDL_Vec2u(640, 480);
	const LDL_Color color = LDL_Color(25, 75, 125);

	PixelPainter painter;

	LDL_Surface surf(LDL_PixelFormat::BGR24, size);

	painter.ClearBGR24(surf.Pixels(), size, color);

	for (size_t i = 0; i < surf.Size().x * surf.Size().y * surf.BytesPerPixel(); i += surf.BytesPerPixel())
	{
		LDL_TEST_EQUAL(surf.Pixels()[i + 0] == color.b);
		LDL_TEST_EQUAL(surf.Pixels()[i + 1] == color.g);
		LDL_TEST_EQUAL(surf.Pixels()[i + 2] == color.r);
	}
}

void PixelPainterClearRGBA32Test()
{
	const LDL_Vec2u size  = LDL_Vec2u(640, 480);
	const LDL_Color color = LDL_Color(25, 75, 125, 235);

	PixelPainter painter;

	LDL_Surface surf(LDL_PixelFormat::RGBA32, size);

	painter.ClearRGBA32(surf.Pixels(), size, color);

	for (size_t i = 0; i < surf.Size().x * surf.Size().y * surf.BytesPerPixel(); i += surf.BytesPerPixel())
	{
		LDL_TEST_EQUAL(surf.Pixels()[i + 0] == color.r);
		LDL_TEST_EQUAL(surf.Pixels()[i + 1] == color.g);
		LDL_TEST_EQUAL(surf.Pixels()[i + 2] == color.b);
		LDL_TEST_EQUAL(surf.Pixels()[i + 3] == color.a);
	}
}

void PixelPainterClearBGRA32Test()
{
	const LDL_Vec2u size  = LDL_Vec2u(640, 480);
	const LDL_Color color = LDL_Color(25, 75, 125, 235);

	PixelPainter painter;

	LDL_Surface surf(LDL_PixelFormat::BGRA32, size);

	painter.ClearBGRA32(surf.Pixels(), size, color);

	for (size_t i = 0; i < surf.Size().x * surf.Size().y * surf.BytesPerPixel(); i += surf.BytesPerPixel())
	{
		LDL_TEST_EQUAL(surf.Pixels()[i + 0] == color.b);
		LDL_TEST_EQUAL(surf.Pixels()[i + 1] == color.g);
		LDL_TEST_EQUAL(surf.Pixels()[i + 2] == color.r);
		LDL_TEST_EQUAL(surf.Pixels()[i + 3] == color.a);
	}
}

int main()
{
	LDL_MemoryManager::Instance().Functions(malloc, NULL, NULL, free);

	ColorDefaultTest();
	ColorNoAlphaTest();
	ColorYesAlphaTest();

	//CreateWindowTest();

	FormatterTest();

	BytesPerPixelFromPixelFormatTest();

	SurfaceRGB24InitDefaultTest();
	SurfaceRGBA32InitDefaultTest();
	SurfaceBGR24InitDefaultTest();
	SurfaceBGRA32InitDefaultTest();

	Vec2Test();

	PixelPainterClearRGB24Test();
	PixelPainterClearBGR24Test();
	PixelPainterClearRGBA32Test();
	PixelPainterClearBGRA32Test();

	return 0;
}
