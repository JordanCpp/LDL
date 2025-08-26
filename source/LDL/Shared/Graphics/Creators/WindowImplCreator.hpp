// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_Creators_WindowImplCreator_hpp
#define LDL_Graphics_Creators_WindowImplCreator_hpp

#include <LDL/Platforms/WindowImpl.hpp>
#include <LDL/Core/Result.hpp>
#include <LDL/Graphics/RenderContext.hpp>
#include <LDL/Math/Vec2.hpp>

namespace LDL
{
	namespace Graphics
	{
		class WindowImplCreator
		{
		public:
			WindowImpl* Create(Core::Result& result, RenderContext& renderContext, const Math::Vec2u& pos, const Math::Vec2u& size, const char* title, size_t mode);
		private:
		};
	}
}

#endif   
