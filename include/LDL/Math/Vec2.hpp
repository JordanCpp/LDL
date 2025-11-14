// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Math_Vec2_hpp
#define LDL_Math_Vec2_hpp

#include <LDL/Core/Types.hpp>

namespace LDL
{
	template<class T>
	class Vec2
	{
	public:
		Vec2()
		{
			x = T();
			y = T();
		}

		Vec2(T v1, T v2)
		{
			x = v1;
			y = v2;
		}

		T x;
		T y;
	};
}

#endif     
