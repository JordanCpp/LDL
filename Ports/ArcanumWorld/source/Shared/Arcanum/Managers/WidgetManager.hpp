#ifndef Arcanum_Managers_WidgetManager_hpp
#define Arcanum_Managers_WidgetManager_hpp

#include <Arcanum/Widgets/Button.hpp>
#include <Arcanum/Widgets/Form.hpp>
#include <vector>

namespace Arcanum
{
	namespace Managers
	{
		class WidgetManager
		{
		public:
			WidgetManager(LDL::Render* render);
			~WidgetManager();
			Widgets::Button* GetButton(const LDL::Vec2u& pos, const LDL::Vec2u& size);
			Widgets::Form* GetForm();
		private:
			LDL::Render*        _render;
			std::vector<Widgets::Widget*> _widgets;
		};
	}
}

#endif    