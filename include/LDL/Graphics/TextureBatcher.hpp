// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_TextureBatcher_hpp
#define LDL_Graphics_TextureBatcher_hpp

#include <LDL/Graphics/Texture.hpp>

namespace LDL
{
	namespace Graphics
	{
		class TextureBatcherImpl;

		class LDL_LIBRARY TextureBatcher
		{
		public:
			TextureBatcher(RenderContext* renderContext, Texture* texture, size_t count);
			~TextureBatcher();
			TextureBatcherImpl* GetTextureBatcherImpl();
			void Draw(const Math::Vec2u& dstPos, const Math::Vec2u& dstSize, const Math::Vec2u& srcPos, const Math::Vec2u& srcSize);
			void Clear();
		private:
			TextureBatcherImpl* _impl;
		};
	}
}

#endif    
