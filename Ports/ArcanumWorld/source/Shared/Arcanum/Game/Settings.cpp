#include <Arcanum/Game/Settings.hpp>

using namespace Arcanum::Game;
using namespace LDL::Math;

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

const Vec2u& Settings::Size()
{
	return _Size;
}

void Settings::Size(const Vec2u& size)
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

size_t Settings::Render()
{
	return _Render;
}

void Settings::Render(size_t render)
{
	_Render = render;
}

const std::string& Settings::DatFiles()
{
	return _DatFiles;
}

void Settings::DatFiles(const std::string& value)
{
	_DatFiles = value;
}

const std::string& Settings::DataFiles()
{
	return _DataFiles;
}

void Settings::DataFiles(const std::string& value)
{
	_DataFiles = value;
}