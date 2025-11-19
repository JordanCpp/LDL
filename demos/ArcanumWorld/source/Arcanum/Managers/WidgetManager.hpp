// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Managers_WidgetManager_hpp
#define Arcanum_Managers_WidgetManager_hpp

#include <vector>
#include <Arcanum/Widgets/Button.hpp>
#include <Arcanum/Widgets/Form.hpp>

namespace Arcanum
{
	class WidgetManager
	{
	public:
		WidgetManager(LDL_IRender* render);
		~WidgetManager();
		Button* GetButton(const LDL_Vec2u& pos, const LDL_Vec2u& size);
		Form* GetForm();
	private:
		LDL_IRender*    _render;
		std::vector<Widget*> _widgets;
	};
}

#endif    
