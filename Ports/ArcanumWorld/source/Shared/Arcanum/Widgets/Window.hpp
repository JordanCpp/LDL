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
            Window(LDL::Render* render, const LDL::Vec2u& pos, const LDL::Vec2u& size);
            void Attach(Widget* widget);
            void Draw();
        private:
            Container _container;
        };
    }
}

#endif