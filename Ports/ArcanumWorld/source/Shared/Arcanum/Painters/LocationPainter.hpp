#ifndef Arcanum_Painters_LocationPainter_hpp
#define Arcanum_Painters_LocationPainter_hpp

#include <LDL/Graphics/Render.hpp>
#include <LDL/Math/Isometric.hpp>
#include <Arcanum/Objects/LocationData.hpp>

namespace Arcanum
{
    namespace Painters
    {
        class LocationPainter
        {
        public:
            LocationPainter(LDL::Render* render, Objects::LocationData* location);
            void DrawTiles(const LDL::Vec2u& start);
            void DrawSceneries(const LDL::Vec2u& start);
            void Draw(const LDL::Vec2u& start);
        private:
            LDL::Render* _render;
            Objects::LocationData* _location;
            LDL::Isometric   _isometric;
        };
    }
}

#endif