#include <LDL/Graphics/Isometric.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;

const Vec2u& Isometric::CartesianToIsometric(const Vec2u& pt)
{
	size_t x = pt.x - pt.y;
	size_t y = (pt.x + pt.y) / 2;

	_result = Vec2u(x, y);

	return _result;
}

const Vec2u& Isometric::IsometricToCartesian(const Vec2u& pt)
{
	size_t x = (2 * pt.y + pt.x) / 2;
	size_t y = (2 * pt.y - pt.x) / 2;

	_result = Vec2u(x, y);

	return _result;
}
