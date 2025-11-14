// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_RenderContext_hpp
#define LDL_Graphics_RenderContext_hpp

#include <LDL/Config.hpp>
#include <LDL/Core/Types.hpp>
#include <LDL/Enums/RenderMode.hpp>

namespace LDL
{
	class RenderContextImpl;

	class LDL_LIBRARY RenderContext
	{
	public:
		enum
		{
			SizeOf = 32
		};
		RenderContext(size_t mode = RenderMode::OpenGL1);
		~RenderContext();
		RenderContextImpl* GetRenderContextImpl();
		size_t Mode();
		void* Context();
	private:
		RenderContextImpl* _impl;
		uint8_t            _memory[SizeOf];
	};
}

#endif  
