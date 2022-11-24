#include <LDL/Platforms/Windows/Input/Display.hpp>
#include <LDL/Platforms/Windows/Windows.hpp>
#include <LDL/Core/RuntimeError.hpp>

LDL::Input::Windows::Display::Display()
{
	_VideoModes.reserve(LDL::Graphics::VideoMode::Limit);

	DWORD i = 0;
	DEVMODE dev;

	ZeroMemory(&dev, sizeof(dev));
	dev.dmSize = sizeof(dev);

	while (EnumDisplaySettings(NULL, i++, &dev) != 0)
	{
		_VideoModes.push_back(LDL::Graphics::VideoMode(LDL::Graphics::Point2u(dev.dmPelsWidth, dev.dmPelsHeight), dev.dmBitsPerPel));

		ZeroMemory(&dev, sizeof(dev));
	}
}

const std::vector<LDL::Graphics::VideoMode>& LDL::Input::Windows::Display::Modes()
{
	return _VideoModes;
}

const LDL::Graphics::VideoMode& LDL::Input::Windows::Display::Current()
{
	HDC hdc = GetDC(NULL);

	if (hdc == NULL)
		throw LDL::Core::RuntimeError("GetDC failed");

	int width  = GetDeviceCaps(hdc, HORZSIZE);
	int height = GetDeviceCaps(hdc, VERTSIZE);
	int bpp    = GetDeviceCaps(hdc, BITSPIXEL);

	_VideoMode = LDL::Graphics::VideoMode(LDL::Graphics::Point2u(width, height), bpp);

	return _VideoMode;
}