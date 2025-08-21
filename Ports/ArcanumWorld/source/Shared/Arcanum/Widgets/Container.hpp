#ifndef Arcanum_Widgets_Container_hpp
#define Arcanum_Widgets_Container_hpp

#include <Arcanum/Widgets/Widget.hpp>
#include <vector>

namespace Arcanum
{
    namespace Widgets
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
}

#endif