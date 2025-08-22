// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/TestEqual.hpp>
#include <LDL/Math/Funcs.hpp>
#include <LDL/Math/Vec3.hpp>
#include <LDL/Math/Mat4.hpp>

using namespace LDL::Math;

int main()
{
	Mat4f mat1 = Ortho(0.0f, 800.0f, 600.0f, 0.0f, 0.0f, 1.0f);
	
	Mat4f mat2 = Perspective(45.0f, (float)800 / 600, 0.1f, 100.0f);

	return 0;
}
