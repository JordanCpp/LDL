#include <LDL/Graphics/Primitives/Color.hpp>

LDL::Graphics::Color::Color() :
	_Red(0),
	_Green(0),
	_Blue(0),
	_Alpha(255)
{
}

LDL::Graphics::Color::Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) :
	_Red(red),
	_Green(green),
	_Blue(blue),
	_Alpha(alpha)
{
}

uint8_t LDL::Graphics::Color::Red() const
{
	return _Red;
}

uint8_t LDL::Graphics::Color::Green() const
{
	return _Green;
}

uint8_t LDL::Graphics::Color::Blue() const
{
	return _Blue;
}

uint8_t LDL::Graphics::Color::Alpha() const
{
	return _Alpha;
}