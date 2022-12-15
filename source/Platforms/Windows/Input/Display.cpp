#include <LDL/Input/Display.hpp>
#include "../Windows.hpp"
#include <LDL/Core/RuntimeError.hpp>

using namespace LDL::Input;
using namespace LDL::Graphics;

Display::Display()
{
	_VideoModes.reserve(VideoMode::Limit);

	DWORD i = 0;
	DEVMODE dev;

	ZeroMemory(&dev, sizeof(dev));
	dev.dmSize = sizeof(dev);

	while (EnumDisplaySettings(NULL, i++, &dev) != 0)
	{
		_VideoModes.push_back(VideoMode(Point2u(dev.dmPelsWidth, dev.dmPelsHeight), dev.dmBitsPerPel));

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
		throw LDL::Core::RuntimeError("GetDC failed");

	int width  = GetDeviceCaps(hdc, HORZSIZE);
	int height = GetDeviceCaps(hdc, VERTSIZE);
	int bpp    = GetDeviceCaps(hdc, BITSPIXEL);

	_VideoMode = VideoMode(Point2u(width, height), bpp);

	return _VideoMode;
}