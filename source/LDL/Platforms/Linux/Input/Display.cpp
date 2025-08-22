// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Input/Display.hpp>

using namespace LDL::Input;
using namespace LDL::Graphics;
using namespace LDL::Math;

Display::Display()
{
	_videoModes.reserve(VideoMode::Limit);
}

const std::vector<VideoMode>& Display::Modes()
{
	return _videoModes;
}

const VideoMode& Display::Current()
{
	return _videoMode;
}