// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/TestEqual.hpp>
#include <LDL/Graphics/VideoMode.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;

void Limit()
{
	LDL_TEST_EQUAL(VideoMode::Limit > 0);
}

void Default()
{
	VideoMode videoMode;

	LDL_TEST_EQUAL(videoMode.Size().x  == 0);
	LDL_TEST_EQUAL(videoMode.Size().y  == 0);
	LDL_TEST_EQUAL(videoMode.BitsPerPixel() == 0);
}

void Init()
{
	LDL_TEST_EQUAL(VideoMode::Limit > 0);

	VideoMode videoMode(Vec2u(800, 600), 32);

	LDL_TEST_EQUAL(videoMode.Size().x  == 800);
	LDL_TEST_EQUAL(videoMode.Size().y  == 600);
	LDL_TEST_EQUAL(videoMode.BitsPerPixel() == 32);
}

int main()
{
	Limit();
	Default();
	Init();

	return 0;
}
