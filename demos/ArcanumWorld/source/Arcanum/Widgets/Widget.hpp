// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Widgets_Widget_hpp
#define Arcanum_Widgets_Widget_hpp

#include <LDL/Render.hpp>
#include <LDL/Rectu.hpp>
#include <LDL/Vec2.hpp>

namespace Arcanum
{
    class Widget
    {
    public:
        Widget(LDL_IRender* render, const LDL_Vec2u& pos, const LDL_Vec2u& size);
        virtual ~Widget();
        const LDL_Vec2u Pos();
        const LDL_Vec2u Size();
        LDL_IRender* GetRender();
        virtual void Draw() = 0;
    private:
        LDL_IRender* _render;
        LDL_Rectu    _area;
    };
}

#endif
