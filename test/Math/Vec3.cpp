// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/TestEqual.hpp>
#include <LDL/Math/Vec3.hpp>

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

void Subtract()
{
	Vec3f vec1(1.0f, 2.0f, 3.0f);
	Vec3f vec2(4.0f, 6.0f, 8.0f);

	Vec3f vec3 = vec1 - vec2;

	LDL_TEST_EQUAL(vec3.x == -3.0f);
	LDL_TEST_EQUAL(vec3.y == -4.0f);
	LDL_TEST_EQUAL(vec3.z == -5.0f);
}

void Assign()
{
	Vec3f vec1(1.0f, 2.0f, 3.0f);
	Vec3f vec2(4.0f, 5.0f, 6.0f);

	vec1 = vec2;

	LDL_TEST_EQUAL(vec1.x == 4.0f);
	LDL_TEST_EQUAL(vec1.y == 5.0f);
	LDL_TEST_EQUAL(vec1.z == 6.0f);
}

void AdditionAssign()
{
	Vec3f vec1(1.0f, 2.0f, 3.0f);
	Vec3f vec2(4.0f, 5.0f, 6.0f);

	vec2 += vec1;

	LDL_TEST_EQUAL(vec2.x == 5.0f);
	LDL_TEST_EQUAL(vec2.y == 7.0f);
	LDL_TEST_EQUAL(vec2.z == 9.0f);
}

void SubtractAssign()
{
	Vec3f vec1(1.0f, 2.0f, 3.0f);
	Vec3f vec2(4.0f, 6.0f, 8.0f);

	vec1 -= vec2;

	LDL_TEST_EQUAL(vec1.x == -3.0f);
	LDL_TEST_EQUAL(vec1.y == -4.0f);
	LDL_TEST_EQUAL(vec1.z == -5.0f);
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
	Subtract();
	Assign();
	AdditionAssign();
	SubtractAssign();
	Multiply();

	return 0;
}
