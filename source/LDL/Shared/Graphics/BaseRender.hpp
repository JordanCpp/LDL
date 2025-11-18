// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_BaseRender_hpp
#define LDL_Graphics_BaseRender_hpp

#include <LDL/Config.hpp>
#include <LDL/Math/Vec2u.hpp>
#include <LDL/Graphics/Color.hpp>

namespace LDL
{
	class LDL_LIBRARY BaseRender
	{
	public:
		BaseRender(const Vec2u& size);
		const Vec2u& Size();
		const Color& GetColor();
		void SetColor(const Color& color);
	public:
		Color _current;
		Vec2u _size;
	};
}

#endif    
