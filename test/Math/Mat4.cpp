// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/TestEqual.hpp>
#include <LDL/Math/Mat4.hpp>

using namespace LDL;

void Default()
{
	Mat4f mat;
}

void Multiply()
{
	Mat4f mat1;
	Mat4f mat2;

	Mat4f mat3 = mat1 * mat2;
}

int main()
{
	Default();
	Multiply();

	return 0;
}
