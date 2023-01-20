#include <LDL/Graphics/Primitives/Color.hpp>

using namespace LDL::Graphics;

Color::Color() :
#if defined(LDL_CONFIG_COLOR_BGRA)
	_Blue(0),
	_Green(0),
	_Red(0),
#else
	_Red(0),
	_Green(0),
	_Blue(0),
#endif
	_Alpha(255)
{
}

Color::Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) :
#if defined(LDL_CONFIG_COLOR_BGRA)
	_Blue(blue),
	_Green(green),
	_Red(red),
#else
	_Red(red),
	_Green(green),
	_Blue(blue),
#endif
	_Alpha(alpha)
{
}

uint8_t Color::Red() const
{
	return _Red;
}

uint8_t Color::Green() const
{
	return _Green;
}

uint8_t Color::Blue() const
{
	return _Blue;
}

uint8_t Color::Alpha() const
{
	return _Alpha;
}

uint32_t Color::toInt() const
{
	return (uint32_t)((_Red << 24) | (_Green << 16) | (_Blue << 8) | _Alpha);
}