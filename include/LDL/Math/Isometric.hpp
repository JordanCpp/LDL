// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Math_Isometric_hpp
#define LDL_Math_Isometric_hpp

#include <LDL/Math/Vec2.hpp>

namespace LDL
{
    class LDL_LIBRARY Isometric
    {
    public:
        const Vec2u& CartesianToIsometric(const Vec2u& pt);
        const Vec2u& IsometricToCartesian(const Vec2u& pt);
    private:
        Vec2u _result;
    };
}

#endif
