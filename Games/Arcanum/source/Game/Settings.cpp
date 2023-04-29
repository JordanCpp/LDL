#include <Arcanum/Game/Settings.hpp>

using namespace Arcanum::Game;
using namespace LDL::Graphics;

Settings::Settings() : 
	_Fps(0)
{
}

const std::string& Settings::Path()
{
	return _Path;
}

void Settings::Path(const std::string& path)
{
	_Path = path;
}

const std::string& Settings::Title()
{
	return _Title;
}

void Settings::Title(const std::string& title)
{
	_Title = title;
}

const Point2u& Settings::Size()
{
	return _Size;
}

void Settings::Size(const Point2u& size)
{
	_Size = size;
}

size_t Settings::Fps()
{
	return _Fps;
}

void Settings::Fps(size_t fps)
{
	_Fps = fps;
}