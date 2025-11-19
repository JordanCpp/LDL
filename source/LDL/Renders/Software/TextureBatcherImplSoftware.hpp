// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_Software_TextureBatcherImpl_hpp
#define LDL_Graphics_Software_TextureBatcherImpl_hpp

#include <LDL/Batcher.hpp>
#include <LDL/Renders/OpenGL/Util.hpp>

class SpriteBatcherImplSoftware : public LDL_ISpriteBatcher
{
public:
	SpriteBatcherImplSoftware(LDL_ITexture* texture, size_t count);
	void Draw(const LDL_Vec2u& dstPos, const LDL_Vec2u& dstSize, const LDL_Vec2u& srcPos, const LDL_Vec2u& srcSize);
	void Clear();
};

#endif    
