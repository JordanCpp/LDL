// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Input/Display.hpp>

using namespace LDL;

Display::Display()
{
	_videoModes.reserve(VideoMode::Limit);
}

const vector<VideoMode>& Display::Modes()
{
	return _videoModes;
}

const VideoMode& Display::Current()
{
	return _videoMode;
}