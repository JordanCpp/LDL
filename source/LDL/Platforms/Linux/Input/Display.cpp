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