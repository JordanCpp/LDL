#ifndef Arcanum_Forms_GameMenu_hpp
#define Arcanum_Forms_GameMenu_hpp

#include <Arcanum/Widgets/Form.hpp>
#include <Arcanum/Widgets/Button.hpp>

namespace Arcanum
{
	namespace Forms
	{
		class GameMenu: public Widgets::Form
		{
		public:
			GameMenu(LDL::Graphics::Render* render);
		private:
			Widgets::Button _button;
		};
	}
}

#endif