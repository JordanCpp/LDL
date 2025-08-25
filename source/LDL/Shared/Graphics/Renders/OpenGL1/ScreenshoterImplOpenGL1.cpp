// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include "ScreenshoterImplOpenGL1.hpp"
#include <LDL/APIs/OpenGL/OpenGL1_0.hpp>
#include "../OpenGL/Util.hpp"

using namespace LDL::Graphics;

ScreenShotterImplOpenGL1::ScreenShotterImplOpenGL1(const char* path, const char* name, Render* render, Surface* image) :
	_shortPath(path),
	_name(name),
	_render(render),
	_image(image)
{
}

void ScreenShotterImplOpenGL1::Shot()
{
	GL_CHECK(glPixelStorei(GL_PACK_ALIGNMENT, 1));
	GL_CHECK(glReadPixels(0, 0, (GLsizei)_image->Size().x, (GLsizei)_image->Size().y, GL_RGBA, GL_UNSIGNED_BYTE, _image->Pixels()));

	_fullPath = "";

	_fullPath += _shortPath.c_str();
	_fullPath += _name.c_str();
	_fullPath += _baseScreenShotter.Prefix();
	_fullPath += ".png";

	_imageWriter.Save(_fullPath.c_str(), _render->Size(), 4, _image->Pixels());
}
