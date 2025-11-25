// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Renders_GL1_BatchGL1_hpp
#define LDL_Renders_GL1_BatchGL1_hpp

#include <LDL/PVector.hpp>
#include <LDL/Texture.hpp>
#include <LDL/Batcher.hpp>
#include <LDL/Renders/GL/Util.hpp>

class LDL_SpriteBatcherOpenGL1 : public LDL_ISpriteBatcher
{
public:
	LDL_SpriteBatcherOpenGL1(LDL_ITexture* texture, size_t count);
	void Draw(const LDL_Vec2u& dstPos, const LDL_Vec2u& dstSize, const LDL_Vec2u& srcPos, const LDL_Vec2u& srcSize);
	void Clear();
	size_t TextureId();
	size_t Count();
	Quad* Content();
private:
	size_t              _texture;
	size_t              _textureSize;
	LDL_PodVector<Quad> _quads;
};

#endif    
