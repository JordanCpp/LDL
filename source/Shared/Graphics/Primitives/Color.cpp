#include <LDL/Graphics/Color.hpp>

using namespace LDL::Graphics;

Color::Color() :
#if defined(LDL_CONFIG_COLOR_BGRA)
	b(0),
	g(0),
	r(0),
#else
	r(0),
	g(0),
	b(0),
#endif
	a(255)
{
}

Color::Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) :
#if defined(LDL_CONFIG_COLOR_BGRA)
	b(blue),
	g(green),
	r(red),
#else
	r(red),
	g(green),
	b(blue),
#endif
	a(alpha)
{
}

uint32_t Color::toInt() const
{
	return (uint32_t)((r << 24) | (g << 16) | (b << 8) | a);
}