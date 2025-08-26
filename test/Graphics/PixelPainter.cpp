// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/TestEqual.hpp>
#include <LDL/Graphics/PixelPainter.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;

void InitDefault()
{
	Surface surface(Vec2u(640, 480), 4);

	PixelPainter painter;

	LDL_TEST_EQUAL(painter.Target()        == NULL);
	LDL_TEST_EQUAL(painter.Size().x        == 0);
	LDL_TEST_EQUAL(painter.Size().y        == 0);
	LDL_TEST_EQUAL(painter.BytesPerPixel() == 0);
	LDL_TEST_EQUAL(painter.Pixels()        == NULL);
	LDL_TEST_EQUAL(painter.Color().r       == 0);
	LDL_TEST_EQUAL(painter.Color().g       == 0);
	LDL_TEST_EQUAL(painter.Color().b       == 0);
}

void InitValue()
{
	Surface surface(Vec2u(640, 480), 4);

	PixelPainter painter;

	painter.Bind(&surface);

	LDL_TEST_EQUAL(painter.Target()        == &surface);
	LDL_TEST_EQUAL(painter.Size().x        == 640);
	LDL_TEST_EQUAL(painter.Size().y        == 480);
	LDL_TEST_EQUAL(painter.BytesPerPixel() == 4);
	LDL_TEST_EQUAL(painter.Pixels()        != NULL);
	LDL_TEST_EQUAL(painter.Color().r       == 0);
	LDL_TEST_EQUAL(painter.Color().g       == 0);
	LDL_TEST_EQUAL(painter.Color().b       == 0);
}

void InitColor()
{
	Surface surface(Vec2u(640, 480), 4);

	PixelPainter painter;

	painter.Bind(&surface);

	painter.Color(LDL::Graphics::Color(1, 2, 3, 4));

	LDL_TEST_EQUAL(painter.Color().r == 1);
	LDL_TEST_EQUAL(painter.Color().g == 2);
	LDL_TEST_EQUAL(painter.Color().b == 3);
	LDL_TEST_EQUAL(painter.Color().a == 4);
}

void Clear()
{
	Surface surface(Vec2u(640, 480), 4);

	PixelPainter painter;

	painter.Bind(&surface);

	painter.Color(LDL::Graphics::Color(1, 2, 3, 4));
	painter.Clear();

	for (uint32_t i = 0; i < painter.Size().x; i++)
	{
		for (uint32_t j = 0; j < painter.Size().y; j++)
		{
			LDL_TEST_EQUAL(painter.GetPixel(Vec2u(i, j)).r == 1);
			LDL_TEST_EQUAL(painter.GetPixel(Vec2u(i, j)).g == 2);
			LDL_TEST_EQUAL(painter.GetPixel(Vec2u(i, j)).b == 3);
			LDL_TEST_EQUAL(painter.GetPixel(Vec2u(i, j)).a == 4);
		}
	}
}

void Fill()
{
	Surface surface(Vec2u(640, 480), 4);

	PixelPainter painter;

	painter.Bind(&surface);

	painter.Color(LDL::Graphics::Color(0, 0, 0, 0));
	painter.Clear();

	painter.Color(LDL::Graphics::Color(1, 2, 3, 4));
	painter.Fill(Vec2u(50, 50), Vec2u(320, 240));

	for (uint32_t i = 50; i < 320; i++)
	{
		for (uint32_t j = 50; j < 240; j++)
		{
			LDL_TEST_EQUAL(painter.GetPixel(Vec2u(i, j)).r == 1);
			LDL_TEST_EQUAL(painter.GetPixel(Vec2u(i, j)).g == 2);
			LDL_TEST_EQUAL(painter.GetPixel(Vec2u(i, j)).b == 3);
			LDL_TEST_EQUAL(painter.GetPixel(Vec2u(i, j)).a == 4);
		}
	}
}

void Line()
{
	Surface surface(Vec2u(640, 480), 4);

	PixelPainter painter;

	painter.Bind(&surface);

	painter.Color(LDL::Graphics::Color(0, 0, 0, 0));
	painter.Clear();

	painter.Color(LDL::Graphics::Color(1, 2, 3, 4));
	painter.Line(Vec2u(0, 0), Vec2u(320, 0));

	for (uint32_t i = 0; i < 320; i++)
	{
		LDL_TEST_EQUAL(painter.GetPixel(Vec2u(i, 0)).r == 1);
		LDL_TEST_EQUAL(painter.GetPixel(Vec2u(i, 0)).g == 2);
		LDL_TEST_EQUAL(painter.GetPixel(Vec2u(i, 0)).b == 3);
		LDL_TEST_EQUAL(painter.GetPixel(Vec2u(i, 0)).a == 4);
	}
}

void Pixel()
{
	Surface surface(Vec2u(640, 480), 4);

	PixelPainter painter;

	painter.Bind(&surface);

	painter.Color(LDL::Graphics::Color(1, 2, 3, 4));
	painter.Clear();

	painter.Color(LDL::Graphics::Color(5, 6, 7, 8));
	painter.Pixel(Vec2u(150, 300));

	LDL_TEST_EQUAL(painter.GetPixel(Vec2u(150, 300)).r == 5);
	LDL_TEST_EQUAL(painter.GetPixel(Vec2u(150, 300)).g == 6);
	LDL_TEST_EQUAL(painter.GetPixel(Vec2u(150, 300)).b == 7);
	LDL_TEST_EQUAL(painter.GetPixel(Vec2u(150, 300)).a == 8);
}

int main()
{
	InitDefault();
	InitValue();
	InitColor();
	Clear();
	Pixel();
	Fill();
	Line();

	return 0;
}
