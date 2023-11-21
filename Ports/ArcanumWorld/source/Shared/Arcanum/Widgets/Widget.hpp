#ifndef Arcanum_Widgets_Widget_hpp
#define Arcanum_Widgets_Widget_hpp

#include <LDL/Graphics/Render.hpp>
#include <LDL/Graphics/Rect.hpp>
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
            LDL::Graphics::Render* _Render;
            LDL::Graphics::Rectu   _Area;
        };
    }
}

#endif