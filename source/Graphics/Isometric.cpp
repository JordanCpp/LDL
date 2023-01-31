#include <LDL/Graphics/Isometric.hpp>

using namespace LDL::Graphics;

const Point2u& Isometric::CartesianToIsometric(const Point2u& pt)
{
	size_t x = pt.PosX() - pt.PosY();
	size_t y = (pt.PosX() + pt.PosY()) / 2;

	_Result = Point2u(x, y);

	return _Result;
}

const Point2u& Isometric::IsometricToCartesian(const Point2u& pt)
{
	size_t x = (2 * pt.PosY() + pt.PosX()) / 2;
	size_t y = (2 * pt.PosY() - pt.PosX()) / 2;

	_Result = Point2u(x, y);

	return _Result;
}