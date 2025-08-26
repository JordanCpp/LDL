// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Widgets_Button_hpp
#define Arcanum_Widgets_Button_hpp

#include <Arcanum/Widgets/Widget.hpp>

namespace Arcanum
{
    namespace Widgets
    {
        class Button : public Widget
        {
        public:
            Button(LDL::Graphics::Render* render, const LDL::Math::Vec2u& pos, const LDL::Math::Vec2u& size);
            void Draw();
        private:
        };
    }
}

#endif