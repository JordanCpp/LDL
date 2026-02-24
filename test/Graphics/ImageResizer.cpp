// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/TestEqual.hpp>
#include <LDL/Loaders/ImageLoader.hpp>
#include <LDL/Allocators/FixedLinear.hpp>
#include <LDL/Graphics/ImageResizer.hpp>

using namespace LDL;

const size_t bytes = Allocator::Mb * 4;

void Resize()
{
	FixedLinear allocator(bytes);
	ImageLoader imageLoader(&allocator);
	ImageResizer imageResizer(Vec2u(1000, 1000));

	//LDL_TEST_EXCEPTION(imageLoader.Load("TestFiles/Gorgosaurus_BW_transparent.png"));

	Surface surface(imageLoader.Size(), imageLoader.Pixels(), imageLoader.BytesPerPixel());

	Surface * result = imageResizer.Resize(Vec2u(997, 998), &surface);

	LDL_TEST_EQUAL(result->BytesPerPixel() == 4);
	LDL_TEST_EQUAL(result->Size().x == 997);
	LDL_TEST_EQUAL(result->Size().y == 998);
	LDL_TEST_EQUAL(result->Pixels() != NULL);
}


int main()
{
	Resize();

	return 0;
}
