#include <LDL/Core/TestEqual.hpp>
#include <LDL/Math/Vec3f.hpp>

using namespace LDL::Math;

void Default()
{
	Vec3f vec;

	LDL_TEST_EQUAL(vec._Values[0] == 0);
	LDL_TEST_EQUAL(vec._Values[1] == 0);
	LDL_TEST_EQUAL(vec._Values[2] == 0);
}

int main()
{
	Default();

	return 0;
}