#ifndef Arcanum_Widgets_Form_hpp
#define Arcanum_Widgets_Form_hpp

#include <Arcanum/Widgets/Widget.hpp>
#include <Arcanum/Widgets/Container.hpp>

namespace Arcanum
{
    namespace Widgets
    {
        class Form : public Widget
        {
        public:
            Form(LDL::Render* render, const LDL::Vec2u& pos, const LDL::Vec2u& size);
            void Attach(Widget* widget);
            void Draw();
        private:
            Container _container;
        };
    }
}

#endif