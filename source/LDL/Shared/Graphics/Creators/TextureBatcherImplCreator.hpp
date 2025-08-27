// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_Creators_TextureBatcherImplCreator_hpp
#define LDL_Graphics_Creators_TextureBatcherImplCreator_hpp

#include <LDL/Graphics/TextureBatcher.hpp>
#include "../Impls/TextureBatcherImpl.hpp"

namespace LDL
{
	class TextureBatcherImplCreator
	{
	public:
		SpriteBatcherImpl* Create(uint8_t* memory, RenderContext* renderContext, Texture* texture, size_t count);
	private:
	};
}

#endif    
