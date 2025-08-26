// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Math/Isometric.hpp>

using namespace LDL::Math;

const Vec2u& Isometric::CartesianToIsometric(const Vec2u& pt)
{
	uint32_t x = pt.x - pt.y;
	uint32_t y = (pt.x + pt.y) / 2;

	_result = Vec2u(x, y);

	return _result;
}

const Vec2u& Isometric::IsometricToCartesian(const Vec2u& pt)
{
	uint32_t x = (2 * pt.y + pt.x) / 2;
	uint32_t y = (2 * pt.y - pt.x) / 2;

	_result = Vec2u(x, y);

	return _result;
}
