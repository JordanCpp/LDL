#include <LDL/Graphics/Palette.hpp>

using namespace LDL::Graphics;

Palette::Palette()
{
	for (size_t i = 0; i < Count(); i++)
	{
		_Colors[i].r = 0;
		_Colors[i].g = 0;
		_Colors[i].b = 0;
		_Colors[i].a = 0;
	}
}

Color* Palette::Colors()
{
	return _Colors;
}

size_t Palette::Count()
{
	return Max;
}
