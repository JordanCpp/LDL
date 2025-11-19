// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Display.hpp>
#include <LDL/Assert.hpp>
#include <LDL/WinNT/Windows.hpp>

LDL_Display::LDL_Display()
{
	_videoModes.reserve(LDL_VideoMode::Limit);

	DWORD i = 0;
	DEVMODE dev;

	ZeroMemory(&dev, sizeof(dev));
	dev.dmSize = sizeof(dev);

	while (EnumDisplaySettings(NULL, i++, &dev) != 0)
	{
		_videoModes.push_back(LDL_VideoMode(LDL_Vec2u(dev.dmPelsWidth, dev.dmPelsHeight), dev.dmBitsPerPel));

		ZeroMemory(&dev, sizeof(dev));
	}
}

const LDL_Vector<LDL_VideoMode>& LDL_Display::Modes()
{
	return _videoModes;
}

const LDL_VideoMode& LDL_Display::Current()
{
	HDC hdc = GetDC(NULL);
	LDL_ASSERT_DETAIL(hdc != NULL, "GetDC failed");

	int width  = GetDeviceCaps(hdc, HORZRES);
	int height = GetDeviceCaps(hdc, VERTRES);
	int bpp    = GetDeviceCaps(hdc, BITSPIXEL);

	_videoMode = LDL_VideoMode(LDL_Vec2u(width, height), bpp);

	return _videoMode;
}
