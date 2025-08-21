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
            Form(LDL::Graphics::Render* render, const LDL::Math::Vec2u& pos, const LDL::Math::Vec2u& size);
            void Attach(Widget* widget);
            void Draw();
        private:
            Container _container;
        };
    }
}

#endif