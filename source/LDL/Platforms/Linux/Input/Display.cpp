#include <LDL/Input/Display.hpp>
#include <LDL/Core/RuntimeError.hpp>

using namespace LDL::Input;
using namespace LDL::Graphics;
using namespace LDL::Math;

Display::Display()
{
	_VideoModes.reserve(VideoMode::Limit);
}

const std::vector<VideoMode>& Display::Modes()
{
	return _VideoModes;
}

const VideoMode& Display::Current()
{
	return _VideoMode;
}