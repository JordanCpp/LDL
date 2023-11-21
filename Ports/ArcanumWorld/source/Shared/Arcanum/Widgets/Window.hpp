#ifndef Arcanum_Widgets_Window_hpp
#define Arcanum_Widgets_Window_hpp

#include <Arcanum/Widgets/Widget.hpp>
#include <Arcanum/Widgets/Container.hpp>

namespace Arcanum
{
    namespace Widgets
    {
        class Window : public Widget
        {
        public:
            Window(LDL::Graphics::Render* render, const LDL::Math::Vec2u& pos, const LDL::Math::Vec2u& size);
            void Attach(Widget* widget);
            void Draw();
        private:
            Container _Container;
        };
    }
}

#endif