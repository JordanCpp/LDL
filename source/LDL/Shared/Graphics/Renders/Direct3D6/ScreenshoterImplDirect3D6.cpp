// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include "ScreenshoterImplDirect3D6.hpp"

using namespace LDL::Graphics;

ScreenShotterImplDirect3D6::ScreenShotterImplDirect3D6(const char* path, const char* name, Render* render, Surface* image) :
	_shortPath(path),
	_name(name),
	_render(render),
	_image(image)
{
}

void ScreenShotterImplDirect3D6::Shot()
{
	_fullPath = "";

	_fullPath += _shortPath.c_str();
	_fullPath += _name.c_str();
	_fullPath += _baseScreenShotter.Prefix();
	_fullPath += ".png";

	_imageWriter.Save(_fullPath.c_str(), _render->Size(), 4, _image->Pixels());
}
