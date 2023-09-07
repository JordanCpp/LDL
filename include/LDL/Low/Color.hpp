#ifndef LDL_Color_hpp
#define LDL_Color_hpp

#include <LDL/Low/Types.hpp>

class LDL_Color
{
public:
	LDL_Color() :
		r(0),
		g(0),
		b(0),
		a(255)
	{
	}

	LDL_Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255) :
		r(r),
		g(g),
		b(b),
		a(a)
	{
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
