// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_BaseWindow_hpp
#define LDL_Graphics_BaseWindow_hpp

#include <LDL/Vec2u.hpp>
#include <LDL/InPlaceStrings.hpp>

class LDL_LIBRARY LDL_BaseWindow
{
public:
	LDL_BaseWindow(const LDL_Vec2u& pos, const LDL_Vec2u& size, const char* title);
	const LDL_Vec2u& Pos();
	const LDL_Vec2u& Size();
	void Size(const LDL_Vec2u& size);
	const char* Title();
	void Title(const char* source);
private:
	LDL_Vec2u _pos;
	LDL_Vec2u _size;
	LDL_Vec2u _view;
	TitleString _title;
};

#endif  
