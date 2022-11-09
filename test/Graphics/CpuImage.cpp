#include <LDL/Core/TestEqual.hpp>
#include <LDL/Graphics/Cpu/CpuImage.hpp>
#include <LDL/Allocators/FixedLinear.hpp>

void Init()
{
	LDL::Allocators::FixedLinear allocator(LDL::Allocators::Allocator::Mb * 4);

	LDL::Graphics::Point2u size = LDL::Graphics::Point2u(640, 480);

	uint8_t* pixels = (uint8_t*)allocator.Allocate(size.PosX() * size.PosX() * 4);

	LDL::Graphics::CpuImage cpuImage(size, 4, pixels);

	LDL_TEST_EQUAL(cpuImage.Size().PosX() == 640);
	LDL_TEST_EQUAL(cpuImage.Size().PosY() == 480);
	LDL_TEST_EQUAL(cpuImage.BytesPerPixel() == 4);
	LDL_TEST_EQUAL(cpuImage.Pixels() != NULL);
}

int main()
{
	Init();

	return 0;
}