// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Input_Mouse_hpp
#define LDL_Input_Mouse_hpp

#include <LDL/Math/Vec2.hpp>

namespace LDL
{
	namespace Input
	{
		class LDL_LIBRARY Mouse
		{
		public:
			Math::Vec2u Pos();
			void Pos(const Math::Vec2u& pos);
			void Hide();
			void Show();
		private:
			Math::Vec2u _pos;
		};
	}
}

#endif  
