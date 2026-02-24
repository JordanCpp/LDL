// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_OpenGL1_TextureBatcherImpl_hpp
#define LDL_Graphics_OpenGL1_TextureBatcherImpl_hpp

#include <LDL/Graphics/Texture.hpp>
#include "../OpenGL/Util.hpp"
#include <vector>
#include "../../Impls/TextureBatcherImpl.hpp"

namespace LDL
{
	class TextureBatcherImplOpenGL1 : public TextureBatcherImpl
	{
	public:
		TextureBatcherImplOpenGL1(Texture* texture, size_t count);
		void Draw(const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize);
		void Clear();
		size_t TextureId();
		size_t Count();
		Util::Quad* Content();
	private:
		size_t                  _texture;
		size_t                  _textureSize;
		std::vector<Util::Quad> _quads;
	};
}

#endif    
