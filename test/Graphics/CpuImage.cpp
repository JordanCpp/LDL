#include <LDL/Core/TestEqual.hpp>
#include <LDL/Graphics/CpuImage.hpp>

void DefaultInit()
{
	LDL::Graphics::CpuImage cpuImage;

	LDL_TEST_EQUAL(cpuImage.Size().PosX() == 0);
	LDL_TEST_EQUAL(cpuImage.Size().PosY() == 0);
	LDL_TEST_EQUAL(cpuImage.BytesPerPixel() == 0);
	LDL_TEST_EQUAL(cpuImage.Pixels() == nullptr);
}

int main()
{
	DefaultInit();

	return 0;
}