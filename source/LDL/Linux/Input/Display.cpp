// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Input/Display.hpp>

using namespace LDL;

LDL_Display::LDL_Display()
{
	_videoModes.reserve(LDL_VideoMode::Limit);
}

const LDL_Vector<LDL_VideoMode>& LDL_Display::Modes()
{
	return _videoModes;
}

const LDL_VideoMode& LDL_Display::Current()
{
	return _videoMode;
}
