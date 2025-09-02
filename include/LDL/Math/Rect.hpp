// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Math_Rect_hpp
#define LDL_Math_Rect_hpp

#include <LDL/Math/Vec2.hpp>

namespace LDL
{
	template<typename T>
	class Rect
	{
	public:
		Rect() :
			_pos(0, 0),
			_size(0, 0)
		{
		}

		Rect(const T& x, const T& y, const T& w, const T& h) :
			_pos(x, y),
			_size(w, h)
		{
		}

		Rect(const Vec2<T>& pos, const Vec2<T>& size) :
			_pos(pos),
			_size(size)
		{
		}

		const Vec2<T>& Pos() const
		{
			return _pos;
		}

		const Vec2<T>& Size() const
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

		bool Contains(const Vec2<T>& Pt)
		{
			return Pt.x >= _pos.x && Pt.y >= _pos.y && Pt.x <= _pos.x + _size.x && Pt.y <= _pos.y + _size.y;
		}
	private:
		Vec2<T> _pos;
		Vec2<T> _size;
	};
}

#endif    
