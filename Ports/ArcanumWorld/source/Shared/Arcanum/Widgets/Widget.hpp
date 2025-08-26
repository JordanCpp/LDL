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
    namespace Widgets
    {
        class Widget
        {
        public:
            Widget(LDL::Graphics::Render* render, const LDL::Math::Vec2u& pos, const LDL::Math::Vec2u& size);
            virtual ~Widget();
            const LDL::Math::Vec2u Pos();
            const LDL::Math::Vec2u Size();
            LDL::Graphics::Render* GetRender();
            virtual void Draw() = 0;
        private:
            LDL::Graphics::Render* _render;
            LDL::Math::Rectu       _area;
        };
    }
}

#endif