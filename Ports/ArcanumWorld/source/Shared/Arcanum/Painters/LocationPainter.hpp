#ifndef Arcanum_Painters_LocationPainter_hpp
#define Arcanum_Painters_LocationPainter_hpp

#include <LDL/Graphics/Render.hpp>
#include <LDL/Graphics/Isometric.hpp>
#include <Arcanum/Objects/LocationData.hpp>

namespace Arcanum
{
    namespace Painters
    {
        class LocationPainter
        {
        public:
            LocationPainter(LDL::Graphics::Render* render, Objects::LocationData* location);
            void DrawTiles(const LDL::Math::Vec2u& start);
            void DrawSceneries(const LDL::Math::Vec2u& start);
            void Draw(const LDL::Math::Vec2u& start);
        private:
            LDL::Graphics::Render*   _Render;
            Objects::LocationData* _Location;
            LDL::Graphics::Isometric _Isometric;
        };
    }
}

#endif