#include <LDL/Core/TestEqual.hpp>
#include <LDL/Graphics/Surface.hpp>
#include <LDL/Allocators/FixedLinear.hpp>

using namespace LDL::Graphics;

const size_t bytes = LDL::Allocators::Allocator::Mb * 4;

void InitDefault()
{
	Surface surface(Point2u(640, 480), 4);

	LDL_TEST_EQUAL(surface.BytesPerPixel() == 4);
	LDL_TEST_EQUAL(surface.Size().PosX() == 640);
	LDL_TEST_EQUAL(surface.Size().PosY() == 480);
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
	LDL_TEST_EQUAL(surface.Pixels() != NULL);
}

int main()
{
	InitDefault();
	InitFrom();

	return 0;
}