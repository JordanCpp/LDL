// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Input/Display.hpp>
#include <LDL/Core/Assert.hpp>
#include <LDL/Platforms/Windows/Windows.hpp>

using namespace LDL;

Display::Display()
{
	_videoModes.reserve(VideoMode::Limit);

	DWORD i = 0;
	DEVMODE dev;

	ZeroMemory(&dev, sizeof(dev));
	dev.dmSize = sizeof(dev);

	while (EnumDisplaySettings(NULL, i++, &dev) != 0)
	{
		_videoModes.push_back(VideoMode(Vec2u(dev.dmPelsWidth, dev.dmPelsHeight), dev.dmBitsPerPel));

		ZeroMemory(&dev, sizeof(dev));
	}
}

const vector<VideoMode>& Display::Modes()
{
	return _videoModes;
}

const VideoMode& Display::Current()
{
	HDC hdc = GetDC(NULL);
	LDL_ASSERT_DETAIL(hdc != NULL, "GetDC failed");

	int width  = GetDeviceCaps(hdc, HORZRES);
	int height = GetDeviceCaps(hdc, VERTRES);
	int bpp    = GetDeviceCaps(hdc, BITSPIXEL);

	_videoMode = VideoMode(Vec2u(width, height), bpp);

	return _videoMode;
}
