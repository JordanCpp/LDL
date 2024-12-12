#include <LDL/Graphics/Palette.hpp>

using namespace LDL::Graphics;

Palette::Palette()
{
	for (size_t i = 0; i < Count(); i++)
	{
		_colors[i].r = 0;
		_colors[i].g = 0;
		_colors[i].b = 0;
		_colors[i].a = 0;
	}
}

Color* Palette::Colors()
{
	return _colors;
}

size_t Palette::Count()
{
	return Max;
}
