#ifndef LDL_Low_Point2u_hpp
#define LDL_Low_Point2u_hpp

#include <LDL/Low/Types.hpp>
#include <LDL/Low/Config.hpp>

class LDL_Point2u
{
public:
	LDL_Point2u() :
		x(0),
		y(0)
	{
	}

	LDL_Point2u(size_t x, size_t y) :
		x(x),
		y(y)
	{
	}

	size_t x;
	size_t y;
};

#endif
