#ifndef LDL_Low_Vec2u_hpp
#define LDL_Low_Vec2u_hpp

#include <LDL/Low/Types.hpp>
#include <LDL/Low/Config.hpp>

class LDL_Vec2u
{
public:
	LDL_Vec2u() :
		x(0),
		y(0)
	{
	}

	LDL_Vec2u(size_t x, size_t y) :
		x(x),
		y(y)
	{
	}

	size_t x;
	size_t y;
};

#endif
