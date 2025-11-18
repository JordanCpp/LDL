// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_SpriteBatcher_hpp
#define LDL_Graphics_SpriteBatcher_hpp

#include <LDL/Graphics/Texture.hpp>
#include <LDL/Graphics/RenderContext.hpp>

namespace LDL
{
	class SpriteBatcherImpl;

	class LDL_LIBRARY SpriteBatcher
	{
	public:
		enum
		{
			SizeOf = 64
		};
		SpriteBatcher(RenderContext* renderContext, ITexture* texture, size_t count);
		~SpriteBatcher();
		SpriteBatcherImpl* GetTextureBatcherImpl();
		void Draw(const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize);
		void Clear();
	private:
		SpriteBatcherImpl* _impl;
		uint8_t            _memory[SizeOf];
	};
}

#endif    
