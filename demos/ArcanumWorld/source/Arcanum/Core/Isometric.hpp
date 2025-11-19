// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Core_Isometric_hpp
#define Arcanum_Core_Isometric_hpp

#include <LDL/Vec2u.hpp>

namespace Arcanum
{
    class Isometric
    {
    public:
        const LDL_Vec2u& CartesianToIsometric(const LDL_Vec2u& pt);
        const LDL_Vec2u& IsometricToCartesian(const LDL_Vec2u& pt);
    private:
        LDL_Vec2u _result;
    };
}

#endif
