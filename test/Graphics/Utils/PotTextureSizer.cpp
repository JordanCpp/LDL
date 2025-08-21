#include <LDL/Core/TestEqual.hpp>
#include <LDL/Shared/Graphics/Utils/PotTextureSizer.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;

void Calc()
{
	Utils::PotTextureSizer sizer;

	LDL_TEST_EQUAL(sizer.Calc(Vec2u(100500, 100500)) == 0);

	LDL_TEST_EQUAL(sizer.Calc(Vec2u(31, 31)) == 32);

	LDL_TEST_EQUAL(sizer.Calc(Vec2u(63, 63)) == 64);

	LDL_TEST_EQUAL(sizer.Calc(Vec2u(127, 127)) == 128);

	LDL_TEST_EQUAL(sizer.Calc(Vec2u(255, 255)) == 256);

	LDL_TEST_EQUAL(sizer.Calc(Vec2u(511, 511)) == 512);

	LDL_TEST_EQUAL(sizer.Calc(Vec2u(1023, 1023)) == 1024);

	LDL_TEST_EQUAL(sizer.Calc(Vec2u(2047, 2047)) == 2048);

	LDL_TEST_EQUAL(sizer.Calc(Vec2u(4095, 4095)) == 4096);

	LDL_TEST_EQUAL(sizer.Calc(Vec2u(8191, 8191)) == 8192);

	LDL_TEST_EQUAL(sizer.Calc(Vec2u(16383, 16383)) == 16384);

	LDL_TEST_EQUAL(sizer.Calc(Vec2u(32767, 32767)) == 32768);

	LDL_TEST_EQUAL(sizer.Calc(Vec2u(65535, 65535)) == 65536);
}

int main()
{
	Calc();

	return 0;
}
