// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_BaseWin_hpp
#define LDL_BaseWin_hpp

#include <LDL/Vec2u.hpp>
#include <LDL/StrView.hpp>
#include <LDL/StrTypes.hpp>

class LDL_LIBRARY LDL_BaseWindow
{
public:
	LDL_BaseWindow(const LDL_Vec2u& pos, const LDL_Vec2u& size, const char* title, size_t mode);
	const LDL_Vec2u& Pos();
	void Pos(const LDL_Vec2u& size);
	const LDL_Vec2u& Size();
	void Size(const LDL_Vec2u& size);
	const char* Title();
	void Title(const char* source);
	bool IsFullScreen();
	bool IsResized();
	bool IsFixed();
	bool IsMinimized();
	bool IsMaximized();
	bool IsCentered();
private:
	size_t         _mode;
	LDL_Vec2u      _pos;
	LDL_Vec2u      _size;
	LDL_Vec2u      _view;
	char           _bufferTitle[LDL_TitleMax];
	LDL_StringView _title;
};

#endif  
