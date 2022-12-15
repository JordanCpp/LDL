#include <LDL/Core/TestEqual.hpp>
#include <LDL/Graphics/Cpu/CpuImage.hpp>
#include <LDL/Allocators/FixedLinear.hpp>

const size_t bytes = LDL::Allocators::Allocator::Mb * 4;

void InitFromHeap()
{
	LDL::Graphics::Point2u size = LDL::Graphics::Point2u(640, 480);

	LDL::Graphics::CpuImage cpuImage(size, 4);

	LDL_TEST_EQUAL(cpuImage.Size().PosX() == 640);
	LDL_TEST_EQUAL(cpuImage.Size().PosY() == 480);
	LDL_TEST_EQUAL(cpuImage.BytesPerPixel() == 4);
	LDL_TEST_EQUAL(cpuImage.Pixels() != NULL);
	LDL_TEST_EQUAL(cpuImage.Allocator() == NULL);
}

void InitFromAllocator()
{
	LDL::Allocators::FixedLinear allocator(bytes);

	LDL::Graphics::Point2u size = LDL::Graphics::Point2u(640, 480);

	LDL::Graphics::CpuImage cpuImage(size, 4, &allocator);

	LDL_TEST_EQUAL(cpuImage.Size().PosX() == 640);
	LDL_TEST_EQUAL(cpuImage.Size().PosY() == 480);
	LDL_TEST_EQUAL(cpuImage.BytesPerPixel() == 4);
	LDL_TEST_EQUAL(cpuImage.Pixels() != NULL);
	LDL_TEST_EQUAL(cpuImage.Allocator() == &allocator);
}

void LoadFromHeap()
{
	LDL::Allocators::FixedLinear allocator(bytes);
	LDL::Loaders::ImageLoader imageLoader(&allocator);

	imageLoader.Load("TestFiles/359500_600.jpg");

	LDL::Graphics::CpuImage cpuImage(&imageLoader);

	LDL_TEST_EQUAL(imageLoader.BytesPerPixel() == 3);
	LDL_TEST_EQUAL(imageLoader.Size().PosX() == 600);
	LDL_TEST_EQUAL(imageLoader.Size().PosY() == 438);
	LDL_TEST_EQUAL(cpuImage.Pixels() != NULL);
	LDL_TEST_EQUAL(cpuImage.Allocator() == NULL);
}

void LoadFromAllocator()
{
	LDL::Allocators::FixedLinear allocator(bytes);
	LDL::Loaders::ImageLoader imageLoader(&allocator);

	imageLoader.Load("TestFiles/359500_600.jpg");

	LDL::Graphics::CpuImage cpuImage(&imageLoader, &allocator);

	LDL_TEST_EQUAL(imageLoader.BytesPerPixel() == 3);
	LDL_TEST_EQUAL(imageLoader.Size().PosX() == 600);
	LDL_TEST_EQUAL(imageLoader.Size().PosY() == 438);
	LDL_TEST_EQUAL(cpuImage.Pixels() != NULL);
	LDL_TEST_EQUAL(cpuImage.Allocator() == &allocator);
}

int main()
{
	InitFromHeap();
	InitFromAllocator();
	LoadFromHeap();
	LoadFromAllocator();

	return 0;
}