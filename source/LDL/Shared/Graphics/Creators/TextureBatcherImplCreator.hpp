// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_Creators_TextureBatcherImplCreator_hpp
#define LDL_Graphics_Creators_TextureBatcherImplCreator_hpp

#include <LDL/Graphics/TextureBatcher.hpp>
#include <LDL/Shared/Graphics/Impls/TextureBatcherImpl.hpp>

namespace LDL
{
	namespace Graphics
	{
		namespace Creators
		{
			class TextureBatcherImplCreator
			{
			public:
				TextureBatcherImpl* Create(RenderContext* renderContext, Texture* texture, size_t count);
			};
		}
	}
}

#endif    
