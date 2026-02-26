// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_BaseWindow_hpp
#define LDL_Graphics_BaseWindow_hpp

#include <string>
#include <LDL/Math/Vec2.hpp>

namespace LDL
{
	class BaseWindow
	{
	public:
		BaseWindow(const Vec2u& pos, const Vec2u& size, const std::string& title);
		const Vec2u& Pos();
		const Vec2u& Size();
		void Size(const Vec2u& size);
		const std::string& Title();
		void Title(const std::string& source);
	private:
		Vec2u       _pos;
		Vec2u       _size;
		Vec2u       _view;
		std::string _title;
	};
}

#endif  
