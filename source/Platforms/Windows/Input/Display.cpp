#include <LDL/Input/Display.hpp>
#include "../Windows.hpp"
#include <LDL/Core/RuntimeError.hpp>

using namespace LDL::Core;
using namespace LDL::Input;
using namespace LDL::Graphics;
using namespace LDL::Math;

Display::Display()
{
	_VideoModes.reserve(VideoMode::Limit);

	DWORD i = 0;
	DEVMODE dev;

	ZeroMemory(&dev, sizeof(dev));
	dev.dmSize = sizeof(dev);

	while (EnumDisplaySettings(NULL, i++, &dev) != 0)
	{
		_VideoModes.push_back(VideoMode(Vec2u(dev.dmPelsWidth, dev.dmPelsHeight), dev.dmBitsPerPel));

		ZeroMemory(&dev, sizeof(dev));
	}
}

const std::vector<VideoMode>& Display::Modes()
{
	return _VideoModes;
}

const VideoMode& Display::Current()
{
	HDC hdc = GetDC(NULL);

	if (hdc == NULL)
		throw RuntimeError("GetDC failed");

	int width  = GetDeviceCaps(hdc, HORZSIZE);
	int height = GetDeviceCaps(hdc, VERTSIZE);
	int bpp    = GetDeviceCaps(hdc, BITSPIXEL);

	_VideoMode = VideoMode(Vec2u(width, height), bpp);

	return _VideoMode;
}
