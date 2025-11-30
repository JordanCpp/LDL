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
	bool HasMode(size_t mode) const;
	const LDL_Vec2u& Pos() const;
	void Pos(const LDL_Vec2u& size);
	const LDL_Vec2u& Size() const;
	void Size(const LDL_Vec2u& size);
	const char* Title() const;
	void Title(const char* source);
	bool IsFullScreen() const;
	bool IsResized() const;
	bool IsFixed() const;
	bool IsMinimized() const;
	bool IsMaximized() const;
	bool IsCentered() const;
private:
	size_t         _mode;
	LDL_Vec2u      _pos;
	LDL_Vec2u      _size;
	LDL_StringView _title;
	char           _bufferTitle[LDL_TitleMax];
};

#endif  
