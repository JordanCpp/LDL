// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_Direct3D6_TextureBatcherImpl_hpp
#define LDL_Graphics_Direct3D6_TextureBatcherImpl_hpp

#include <vector>
#include <LDL/Graphics/Texture.hpp>
#include <LDL/Shared/Graphics/Impls/TextureBatcherImpl.hpp>

namespace LDL
{
	class TextureBatcherImplDirect3D6 : public TextureBatcherImpl
	{
	public:
		TextureBatcherImplDirect3D6(Texture* texture, size_t count);
		void Draw(const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize);
		void Clear();
	private:
	};
}

#endif    
