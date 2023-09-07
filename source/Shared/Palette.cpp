#include <LDL/Low/Palette.hpp>
#include <stdlib.h>

LDL_Palette::LDL_Palette(size_t count) :
	_Count(count),
	_Colors(NULL)
{
	_Colors = (LDL_Color*)malloc(sizeof(LDL_Color) * count);
}

LDL_Palette::~LDL_Palette()
{
	free(_Colors);
}

size_t LDL_Palette::Count()
{
	return _Count;
}

LDL_Color* LDL_Palette::Colors()
{
	return _Colors;
}

void LDL_Palette::Red(size_t index, uint8_t byte)
{
	_Colors[index].r = byte;
}

void LDL_Palette::Green(size_t index, uint8_t byte)
{
	_Colors[index].g = byte;
}

void LDL_Palette::Blue(size_t index, uint8_t byte)
{
	_Colors[index].b = byte;
}
