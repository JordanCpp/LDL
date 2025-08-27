// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Graphics/ScreenShotter.hpp>
#include <LDL/Shared/Graphics/Renders/OpenGL1/ScreenshoterImplOpenGL1.hpp>

using namespace LDL;

ScreenShotter::ScreenShotter(const char* path, const char* name, Render* render, Surface* image)
{
	_impl = new ScreenShotterImplOpenGL1(path, name, render, image);
}

ScreenShotter::~ScreenShotter()
{
	delete _impl;
}

void ScreenShotter::Shot()
{
	_impl->Shot();
}
