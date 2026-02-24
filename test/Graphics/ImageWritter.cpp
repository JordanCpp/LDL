// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/TestEqual.hpp>
#include <LDL/Graphics/ImageWritter.hpp>
#include <LDL/Graphics/Surface.hpp>
#include <LDL/Core/Directory.hpp>

using namespace LDL;

const Vec2u size = Vec2u(640, 480);
const std::string path = "TestFiles/ImageWritterTest.png";

void Save()
{
	Surface image(Vec2u(640, 480), 4);

	ImageWriter writter;

	writter.Save(path, size, 4, image.Pixels());

	Directory directory;

	LDL_TEST_EQUAL(directory.FileExist(path) == true);

	directory.Remove(path);
}


int main()
{
	Save();

	return 0;
}
