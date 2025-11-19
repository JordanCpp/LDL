// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_OpenGL3_TextureBatcherImpl_hpp
#define LDL_Graphics_OpenGL3_TextureBatcherImpl_hpp

#include <LDL/Vector.hpp>
#include <LDL/Texture.hpp>
#include <LDL/Renders/GL/Util.hpp>
#include <LDL/Batcher.hpp>

class SpriteBatcherImplOpenGL3 :public LDL_ISpriteBatcher
{
public:
	SpriteBatcherImplOpenGL3(LDL_ITexture* texture, size_t count);
	void Draw(const LDL_Vec2u& dstPos, const LDL_Vec2u& dstSize, const LDL_Vec2u& srcPos, const LDL_Vec2u& srcSize);
	void Clear();
	size_t TextureId();
	size_t Count();
	Quad* Content();
private:
	size_t       _texture;
	size_t       _textureSize;
	LDL_Vector<Quad> _quads;
};

#endif    
