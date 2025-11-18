// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Painters_LocationPainter_hpp
#define Arcanum_Painters_LocationPainter_hpp

#include <LDL/Graphics/Render.hpp>
#include <Arcanum/Core/Isometric.hpp>
#include <Arcanum/Objects/LocationData.hpp>

namespace Arcanum
{
    class LocationPainter
    {
    public:
        LocationPainter(LDL::IRender* render, LocationData* location);
        void DrawTiles(const LDL::Vec2u& start);
        void DrawSceneries(const LDL::Vec2u& start);
        void Draw(const LDL::Vec2u& start);
    private:
        LDL::IRender*   _render;
        LocationData*  _location;
        Isometric      _isometric;
    };
}

#endif
