#include <LDL/Core/TestEqual.hpp>
#include <LDL/Math/Vec3f.hpp>

using namespace LDL::Math;

void Default()
{
	Vec3f vec;

	LDL_TEST_EQUAL(vec.x == 0.0f);
	LDL_TEST_EQUAL(vec.y == 0.0f);
	LDL_TEST_EQUAL(vec.z == 0.0f);
}

void InitValues()
{
	Vec3f vec(1.0f, 2.0f, 3.0f);

	LDL_TEST_EQUAL(vec.x == 1.0f);
	LDL_TEST_EQUAL(vec.y == 2.0f);
	LDL_TEST_EQUAL(vec.z == 3.0f);
}

void Addition()
{
	Vec3f vec1(1.0f, 2.0f, 3.0f);
	Vec3f vec2(4.0f, 5.0f, 6.0f);

	Vec3f vec3 = vec1 + vec2;

	LDL_TEST_EQUAL(vec3.x == 5.0f);
	LDL_TEST_EQUAL(vec3.y == 7.0f);
	LDL_TEST_EQUAL(vec3.z == 9.0f);
}

void Multiply()
{
	Vec3f vec1(1.0f, 2.0f, 3.0f);
	Vec3f vec2(4.0f, 5.0f, 6.0f);

	Vec3f vec3 = vec1 * vec2;

	LDL_TEST_EQUAL(vec3.x == 4.0f);
	LDL_TEST_EQUAL(vec3.y == 10.0f);
	LDL_TEST_EQUAL(vec3.z == 18.0f);
}

int main()
{
	Default();
	InitValues();
	Addition();
	Multiply();

	return 0;
}