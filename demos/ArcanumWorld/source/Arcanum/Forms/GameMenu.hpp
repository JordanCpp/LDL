// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Forms_GameMenu_hpp
#define Arcanum_Forms_GameMenu_hpp

#include <Arcanum/Widgets/Form.hpp>
#include <Arcanum/Widgets/Button.hpp>

namespace Arcanum
{
	class GameMenu : public Form
	{
	public:
		GameMenu(LDL::IRender* render);
	private:
		Button _button;
	};
}

#endif
