// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Input_Mouse_hpp
#define LDL_Input_Mouse_hpp

#include <LDL/Config.hpp>
#include <LDL/Vec2u.hpp>

class LDL_LIBRARY LDL_Mouse
{
public:
	LDL_Vec2u Pos();
	void Pos(const LDL_Vec2u& pos);
	void Hide();
	void Show();
private:
	LDL_Vec2u _pos;
};

#endif  
