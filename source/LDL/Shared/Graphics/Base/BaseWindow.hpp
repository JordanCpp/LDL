// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_BaseWindow_hpp
#define LDL_Graphics_BaseWindow_hpp

#include <LDL/Math/Vec2.hpp>
#include <LDL/STL/inplace_strings.hpp>

namespace LDL
{
	namespace Graphics
	{
		class LDL_LIBRARY BaseWindow
		{
		public:
			BaseWindow(const Math::Vec2u& pos, const Math::Vec2u& size, const char* title);
			const Math::Vec2u& Pos();
			const Math::Vec2u& Size();
			void Size(const Math::Vec2u& size);
			const char* Title();
			void Title(const char* source);
		private:
			Math::Vec2u _pos;
			Math::Vec2u _size;
			Math::Vec2u _view;
			TitleString _title;
		};
	}
}

#endif  
