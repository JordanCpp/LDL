// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Widgets_Container_hpp
#define Arcanum_Widgets_Container_hpp

#include <Arcanum/Widgets/Widget.hpp>
#include <vector>

namespace Arcanum
{
    class Container
    {
    public:
        void Append(Widget* widget);
        void Draw();
    private:
        std::vector<Widget*> _widgets;
    };
}

#endif
