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
			WidgetManager(LDL::Graphics::Render* render);
			~WidgetManager();
			Widgets::Button* GetButton(const LDL::Math::Vec2u& pos, const LDL::Math::Vec2u& size);
			Widgets::Form* GetForm();
		private:
			LDL::Graphics::Render* _Render;
			std::vector<Widgets::Widget*> _Widgets;
		};
	}
}

#endif    