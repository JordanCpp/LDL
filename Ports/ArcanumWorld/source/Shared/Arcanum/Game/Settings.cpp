#include <Arcanum/Game/Settings.hpp>

using namespace Arcanum::Game;
using namespace LDL::Math;

Settings::Settings() : 
	_fps(0)
{
}

const std::string& Settings::Path()
{
	return _path;
}

void Settings::Path(const std::string& path)
{
	_path = path;
}

const std::string& Settings::Title()
{
	return _title;
}

void Settings::Title(const std::string& title)
{
	_title = title;
}

const Vec2u& Settings::Size()
{
	return _size;
}

void Settings::Size(const Vec2u& size)
{
	_size = size;
}

size_t Settings::Fps()
{
	return _fps;
}

void Settings::Fps(size_t fps)
{
	_fps = fps;
}

size_t Settings::Render()
{
	return _render;
}

void Settings::Render(size_t render)
{
	_render = render;
}

const std::string& Settings::DatFiles()
{
	return _datFiles;
}

void Settings::DatFiles(const std::string& value)
{
	_datFiles = value;
}

const std::string& Settings::DataFiles()
{
	return _dataFiles;
}

void Settings::DataFiles(const std::string& value)
{
	_dataFiles = value;
}