// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Rect_hpp
#define LDL_Rect_hpp

#include <LDL/Vec2.hpp>

template<class T>
class LDL_Rect
{
public:
	LDL_Rect() :
		_pos(0, 0),
		_size(0, 0)
	{
	}

	LDL_Rect(const T& x, const T& y, const T& w, const T& h) :
		_pos(x, y),
		_size(w, h)
	{
	}

	LDL_Rect(const LDL_Vec2<T>& pos, const LDL_Vec2<T>& size) :
		_pos(pos),
		_size(size)
	{
	}

	const LDL_Vec2<T>& Pos() const
	{
		return _pos;
	}

	const LDL_Vec2<T>& Size() const
	{
		return _size;
	}

	void Pos(const T& x, const T& y)
	{
		_pos.x = x;
		_pos.y = y;
	}

	void Size(const T& x, const T& y)
	{
		_size.x = x;
		_size.y = y;
	}

	bool Contains(const LDL_Vec2<T>& Pt)
	{
		return Pt.x >= _pos.x && Pt.y >= _pos.y && Pt.x <= _pos.x + _size.x && Pt.y <= _pos.y + _size.y;
	}
private:
	LDL_Vec2<T> _pos;
	LDL_Vec2<T> _size;
};

#endif    
