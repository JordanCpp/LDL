// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/TestEqual.hpp>
#include <LDL/Loaders/BmpLoader.hpp>

using namespace LDL::Core;
using namespace LDL::Loaders;

int main()
{
	Result result;
	BmpLoader bmpLoader(result);

	//LDL_TEST_EXCEPTION(imageLoader.Load("TestFiles/359500_600.jpg"));

	LDL_TEST_EQUAL(imageLoader.BytesPerPixel() == 3);
	LDL_TEST_EQUAL(imageLoader.Size().x == 600);
	LDL_TEST_EQUAL(imageLoader.Size().y == 438);
	LDL_TEST_EQUAL(imageLoader.Pixels() != NULL);

	return 0;
}
