// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Widgets_Widget_hpp
#define Arcanum_Widgets_Widget_hpp

#include <LDL/Graphics/Render.hpp>
#include <LDL/Math/Rect.hpp>
#include <LDL/Math/Vec2.hpp>

namespace Arcanum
{
    class Widget
    {
    public:
        Widget(LDL::Render& render, const LDL::Vec2u& pos, const LDL::Vec2u& size);
        virtual ~Widget();
        const LDL::Vec2u Pos();
        const LDL::Vec2u Size();
        LDL::Render& GetRender();
        virtual void Draw() = 0;
    private:
        LDL::Render& _render;
        LDL::Rectu   _area;
    };
}

#endif
