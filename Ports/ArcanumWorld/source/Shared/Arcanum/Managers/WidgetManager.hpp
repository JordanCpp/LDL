// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

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
			LDL::Graphics::Render*        _render;
			std::vector<Widgets::Widget*> _widgets;
		};
	}
}

#endif    