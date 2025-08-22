// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/TestEqual.hpp>
#include <LDL/Graphics/Surface.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <LDL/Loaders/ImageLoader.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;

const size_t bytes = LDL::Allocators::Allocator::Mb * 4;

void InitDefault()
{
	Surface surface(Vec2u(640, 480), 4);

	LDL_TEST_EQUAL(surface.BytesPerPixel() == 4);
	
	LDL_TEST_EQUAL(surface.Size().x == 640);
	LDL_TEST_EQUAL(surface.Size().y == 480);

	LDL_TEST_EQUAL(surface.Capacity().x == 640);
	LDL_TEST_EQUAL(surface.Capacity().y == 480);

	LDL_TEST_EQUAL(surface.Pixels() != NULL);
}

void InitCapacityDefault()
{
	Surface surface(Vec2u(640, 480), Vec2u(800, 600), 4);

	LDL_TEST_EQUAL(surface.BytesPerPixel() == 4);

	LDL_TEST_EQUAL(surface.Size().x == 640);
	LDL_TEST_EQUAL(surface.Size().y == 480);

	LDL_TEST_EQUAL(surface.Capacity().x == 800);
	LDL_TEST_EQUAL(surface.Capacity().y == 600);

	LDL_TEST_EQUAL(surface.Pixels() != NULL);
}

void InitFrom()
{
	LDL::Allocators::FixedLinear allocator(bytes);
	LDL::Loaders::ImageLoader loader(&allocator);

	loader.Load("TestFiles/359500_600.jpg");

	Surface surface(loader.Size(), loader.Pixels(), loader.BytesPerPixel());

	LDL_TEST_EQUAL(surface.BytesPerPixel() == 3);

	LDL_TEST_EQUAL(surface.Size().x == 600);
	LDL_TEST_EQUAL(surface.Size().y == 438);

	LDL_TEST_EQUAL(surface.Capacity().x == 600);
	LDL_TEST_EQUAL(surface.Capacity().y == 438);

	LDL_TEST_EQUAL(surface.Pixels() != NULL);
}

void InitCapacityFrom()
{
	LDL::Allocators::FixedLinear allocator(bytes);
	LDL::Loaders::ImageLoader loader(&allocator);

	loader.Load("TestFiles/359500_600.jpg");

	Surface surface(loader.Size(), Vec2u(800, 600),loader.Pixels(), loader.BytesPerPixel());

	LDL_TEST_EQUAL(surface.BytesPerPixel() == 3);

	LDL_TEST_EQUAL(surface.Size().x == 600);
	LDL_TEST_EQUAL(surface.Size().y == 438);

	LDL_TEST_EQUAL(surface.Capacity().x == 800);
	LDL_TEST_EQUAL(surface.Capacity().y == 600);

	LDL_TEST_EQUAL(surface.Pixels() != NULL);
}

void Resize()
{
	Surface surface(Vec2u(640, 480), 4);

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
	Surface surface(Vec2u(640, 480), 4);

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
	InitFrom();
	InitCapacityFrom();
	Resize();
	Clear();

	return 0;
}
