// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/TestEqual.hpp>
#include <LDL/Loaders/SoundLoader.hpp>
#include <LDL/Allocators/FixedLinear.hpp>

using namespace LDL::Allocators;
using namespace LDL::Loaders;

void Init()
{
	FixedLinear allocator(Allocator::Mb * 4);
	SoundLoader loader(&allocator);

	LDL_TEST_EQUAL(loader.Allocator() == &allocator);
	LDL_TEST_EQUAL(loader.Bytes()     == 0);
	LDL_TEST_EQUAL(loader.Channels()  == 0);
	LDL_TEST_EQUAL(loader.Rate()      == 0);
	LDL_TEST_EQUAL(loader.Samples()   == 0);
}

void LoadOgg()
{
	FixedLinear allocator(Allocator::Mb * 4);
	SoundLoader loader(&allocator);

	LDL_TEST_EQUAL(loader.Load("TestFiles/ambient_night_01.ogg"));
	  
	LDL_TEST_EQUAL(loader.Bytes()    != NULL);
	LDL_TEST_EQUAL(loader.Channels() == 1);
	LDL_TEST_EQUAL(loader.Rate()     == 44100);
	LDL_TEST_EQUAL(loader.Samples()  == 840122);
}

int main()
{
	Init();
	LoadOgg();

	return 0;
}
