#include <LDL/Core/TestEqual.hpp>
#include <LDL/Creators/GraphicsCreator.hpp>
#include <LDL/Allocators/FixedLinear.hpp>

LDL::Allocators::FixedLinear graphicsAllocator(LDL::Allocators::Allocator::Mb * 1);
LDL::Creators::GraphicsCreator graphicsCreator(&graphicsAllocator);

void CreateGpuRender()
{
	LDL::Graphics::IGpuWindow* window = graphicsCreator.CreateGpuWindow(LDL::Graphics::Point2u(0, 0), LDL::Graphics::Point2u(800, 600), "Window!");
	LDL_TEST_EQUAL(window != NULL);

	LDL::Graphics::IGpuRender* render = graphicsCreator.CreateGpuRender(window);
	LDL_TEST_EQUAL(render != NULL);

	LDL::Graphics::Point2u size = LDL::Graphics::Point2u(800, 600);
	size_t bpp = 4;
	size_t bytes = size.PosX() * size.PosY() * bpp;

	uint8_t* pixels = new uint8_t[bytes];

	LDL::Graphics::IGpuImage* image1 = graphicsCreator.CreateGpuImage(size, bpp, pixels);
	LDL_TEST_EQUAL(image1 != NULL);

	graphicsCreator.Destroy(image1);
	LDL_TEST_EQUAL(image1 != NULL);

	LDL::Graphics::IGpuImage* image2 = graphicsCreator.CreateGpuImage(size, bpp, pixels);
	LDL_TEST_EQUAL(image2 != NULL);
	LDL_TEST_EQUAL(image2 == image1);
}

int main()
{
	CreateGpuRender();

	return 0;
}