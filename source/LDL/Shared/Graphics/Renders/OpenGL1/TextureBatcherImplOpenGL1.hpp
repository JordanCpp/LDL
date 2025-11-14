// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_OpenGL1_TextureBatcherImpl_hpp
#define LDL_Graphics_OpenGL1_TextureBatcherImpl_hpp

#include <LDL/Core/Vector.hpp>
#include <LDL/Graphics/Texture.hpp>
#include <LDL/Shared/Graphics/Renders/OpenGL/Util.hpp>
#include <LDL/Shared/Graphics/Impls/TextureBatcherImpl.hpp>

namespace LDL
{
	class SpriteBatcherImplOpenGL1 : public SpriteBatcherImpl
	{
	public:
		SpriteBatcherImplOpenGL1(Texture* texture, size_t count);
		void Draw(const Vec2u& dstPos, const Vec2u& dstSize, const Vec2u& srcPos, const Vec2u& srcSize);
		void Clear();
		size_t TextureId();
		size_t Count();
		Quad* Content();
	private:
		size_t       _texture;
		size_t       _textureSize;
		Vector<Quad> _quads;
	};
}

#endif    
