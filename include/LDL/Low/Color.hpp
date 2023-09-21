#ifndef LDL_Low_Color_hpp
#define LDL_Low_Color_hpp

#include <LDL/Low/Types.hpp>

class LDL_Color
{
public:
	LDL_Color() :
#ifdef LDL_COLOR_RGBA
		r(0),
		g(0),
		b(0),
#else
		b(0),
		g(0),
		r(0),
#endif  
		a(255)
	{
	}

	LDL_Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255) :
#ifdef LDL_COLOR_RGBA
		r(r),
		g(g),
		b(b),
#else
		b(b),
		g(g),
		r(r),
#endif
		a(a)
	{
	}

	bool Equal(const LDL_Color& color) const
	{
		return color.r == r && color.g == g && color.b == b;
	}

#ifdef LDL_COLOR_RGBA
	uint8_t r;
	uint8_t g;
	uint8_t b;
#else
	uint8_t b;
	uint8_t g;
	uint8_t r;
#endif  

	uint8_t a;
};

#endif
