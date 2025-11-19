// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Batcher_hpp
#define LDL_Batcher_hpp

#include <LDL/Vec2u.hpp>
#include <LDL/Texture.hpp>

class LDL_ISpriteBatcher
{
public:
	virtual ~LDL_ISpriteBatcher() {};
	virtual void Draw(const LDL_Vec2u& dstPos, const LDL_Vec2u& dstSize, const LDL_Vec2u& srcPos, const LDL_Vec2u& srcSize) = 0;
	virtual void Clear() = 0;
};

LDL_ISpriteBatcher* CreateSpriteBatcherImpl(LDL_RenderContext* renderContext, LDL_ITexture* texture, size_t count);

#endif    
