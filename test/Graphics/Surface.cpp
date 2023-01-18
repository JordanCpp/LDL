#include <LDL/Core/TestEqual.hpp>
#include <LDL/Graphics/Surface.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <LDL/Loaders/ImageLoader.hpp>

using namespace LDL::Graphics;

const size_t bytes = LDL::Allocators::Allocator::Mb * 4;

void InitDefault()
{
	Surface surface(Point2u(640, 480), 4);

	LDL_TEST_EQUAL(surface.BytesPerPixel() == 4);
	
	LDL_TEST_EQUAL(surface.Size().PosX() == 640);
	LDL_TEST_EQUAL(surface.Size().PosY() == 480);

	LDL_TEST_EQUAL(surface.Capacity().PosX() == 640);
	LDL_TEST_EQUAL(surface.Capacity().PosY() == 480);

	LDL_TEST_EQUAL(surface.Pixels() != NULL);
}

void InitCapacityDefault()
{
	Surface surface(Point2u(640, 480), Point2u(800, 600), 4);

	LDL_TEST_EQUAL(surface.BytesPerPixel() == 4);

	LDL_TEST_EQUAL(surface.Size().PosX() == 640);
	LDL_TEST_EQUAL(surface.Size().PosY() == 480);

	LDL_TEST_EQUAL(surface.Capacity().PosX() == 800);
	LDL_TEST_EQUAL(surface.Capacity().PosY() == 600);

	LDL_TEST_EQUAL(surface.Pixels() != NULL);
}

void InitFrom()
{
	LDL::Allocators::FixedLinear allocator(bytes);
	LDL::Loaders::ImageLoader loader(&allocator);

	loader.Load("TestFiles/359500_600.jpg");

	Surface surface(loader.Size(), loader.Pixels(), loader.BytesPerPixel());

	LDL_TEST_EQUAL(surface.BytesPerPixel() == 3);

	LDL_TEST_EQUAL(surface.Size().PosX() == 600);
	LDL_TEST_EQUAL(surface.Size().PosY() == 438);

	LDL_TEST_EQUAL(surface.Capacity().PosX() == 600);
	LDL_TEST_EQUAL(surface.Capacity().PosY() == 438);

	LDL_TEST_EQUAL(surface.Pixels() != NULL);
}

void InitCapacityFrom()
{
	LDL::Allocators::FixedLinear allocator(bytes);
	LDL::Loaders::ImageLoader loader(&allocator);

	loader.Load("TestFiles/359500_600.jpg");

	Surface surface(loader.Size(), Point2u(800, 600),loader.Pixels(), loader.BytesPerPixel());

	LDL_TEST_EQUAL(surface.BytesPerPixel() == 3);

	LDL_TEST_EQUAL(surface.Size().PosX() == 600);
	LDL_TEST_EQUAL(surface.Size().PosY() == 438);

	LDL_TEST_EQUAL(surface.Capacity().PosX() == 800);
	LDL_TEST_EQUAL(surface.Capacity().PosY() == 600);

	LDL_TEST_EQUAL(surface.Pixels() != NULL);
}

void Resize()
{
	Surface surface(Point2u(640, 480), 4);

	surface.Resize(Point2u(320, 240));

	LDL_TEST_EQUAL(surface.Size().PosX() == 320);
	LDL_TEST_EQUAL(surface.Size().PosY() == 240);
	LDL_TEST_EQUAL(surface.Capacity().PosX() == 640);
	LDL_TEST_EQUAL(surface.Capacity().PosY() == 480);
	LDL_TEST_EQUAL(surface.Pixels() != NULL);

	surface.Resize(Point2u(100500, 100500));

	LDL_TEST_EQUAL(surface.Size().PosX() == 320);
	LDL_TEST_EQUAL(surface.Size().PosY() == 240);
	LDL_TEST_EQUAL(surface.Capacity().PosX() == 640);
	LDL_TEST_EQUAL(surface.Capacity().PosY() == 480);
	LDL_TEST_EQUAL(surface.Pixels() != NULL);
}

void Clear()
{
	Surface surface(Point2u(640, 480), 4);

	surface.Clear();

	LDL_TEST_EQUAL(surface.Size().PosX() == 0);
	LDL_TEST_EQUAL(surface.Size().PosY() == 0);
	LDL_TEST_EQUAL(surface.Capacity().PosX() == 640);
	LDL_TEST_EQUAL(surface.Capacity().PosY() == 480);
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