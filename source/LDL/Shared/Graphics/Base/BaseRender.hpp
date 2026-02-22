// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_BaseRender_hpp
#define LDL_Graphics_BaseRender_hpp

#include <LDL/Math/Vec2.hpp>
#include <LDL/Graphics/Color.hpp>

namespace LDL
{
	namespace Graphics
	{
		class LDL_LIBRARY BaseRender
		{
		public:
			BaseRender(const Math::Vec2u& size);
			const Math::Vec2u& Size();
			const Graphics::Color& Color();
			void Color(const Graphics::Color& color);
		public:
			Graphics::Color _current;
			Math::Vec2u     _size;
		};
	}
}

#endif    
