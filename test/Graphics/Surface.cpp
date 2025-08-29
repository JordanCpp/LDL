// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/TestEqual.hpp>
#include <LDL/Graphics/Surface.hpp>

using namespace LDL;

void InitDefault()
{
	Surface surface(PixelFormat::RGBA32, Vec2u(640, 480));

	LDL_TEST_EQUAL(surface.BytesPerPixel() == 4);
	
	LDL_TEST_EQUAL(surface.Size().x == 640);
	LDL_TEST_EQUAL(surface.Size().y == 480);

	LDL_TEST_EQUAL(surface.Capacity().x == 640);
	LDL_TEST_EQUAL(surface.Capacity().y == 480);

	LDL_TEST_EQUAL(surface.Pixels() != NULL);
}

void InitCapacityDefault()
{
	Surface surface(PixelFormat::RGBA32, Vec2u(640, 480), Vec2u(800, 600));

	LDL_TEST_EQUAL(surface.BytesPerPixel() == 4);

	LDL_TEST_EQUAL(surface.Size().x == 640);
	LDL_TEST_EQUAL(surface.Size().y == 480);

	LDL_TEST_EQUAL(surface.Capacity().x == 800);
	LDL_TEST_EQUAL(surface.Capacity().y == 600);

	LDL_TEST_EQUAL(surface.Pixels() != NULL);
}

void Resize()
{
	Surface surface(PixelFormat::RGBA32, Vec2u(640, 480));

	surface.Resize(Vec2u(320, 240));

	LDL_TEST_EQUAL(surface.Size().x == 320);
	LDL_TEST_EQUAL(surface.Size().y == 240);
	LDL_TEST_EQUAL(surface.Capacity().x == 640);
	LDL_TEST_EQUAL(surface.Capacity().y == 480);
	LDL_TEST_EQUAL(surface.Pixels() != NULL);

	surface.Resize(Vec2u(100500, 100500));

	LDL_TEST_EQUAL(surface.Size().x == 320);
	LDL_TEST_EQUAL(surface.Size().y == 240);
	LDL_TEST_EQUAL(surface.Capacity().x == 640);
	LDL_TEST_EQUAL(surface.Capacity().y == 480);
	LDL_TEST_EQUAL(surface.Pixels() != NULL);
}

void Clear()
{
	Surface surface(PixelFormat::RGBA32, Vec2u(640, 480));

	surface.Clear();

	LDL_TEST_EQUAL(surface.Size().x == 0);
	LDL_TEST_EQUAL(surface.Size().y == 0);
	LDL_TEST_EQUAL(surface.Capacity().x == 640);
	LDL_TEST_EQUAL(surface.Capacity().y == 480);
	LDL_TEST_EQUAL(surface.Pixels() != NULL);
}

int main()
{
	InitDefault();
	InitCapacityDefault();
	Resize();
	Clear();

	return 0;
}
