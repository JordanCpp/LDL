// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_OpenGL3_TextureBatcherImpl_hpp
#define LDL_Graphics_OpenGL3_TextureBatcherImpl_hpp

#include <LDL/Graphics/Texture.hpp>
#include <LDL/STL/vector.hpp>
#include "../../Impls/TextureBatcherImpl.hpp"

namespace LDL
{
	namespace Graphics
	{
		struct Quad
		{
			float data[5 * 6];
		};

		class TextureBatcherImplOpenGL3 :public TextureBatcherImpl
		{
		public:
			TextureBatcherImplOpenGL3(Texture* texture, size_t count);
			void Draw(const Math::Vec2u& dstPos, const Math::Vec2u& dstSize, const Math::Vec2u& srcPos, const Math::Vec2u& srcSize);
			void Clear();
			size_t TextureId();
			size_t Count();
			Quad* Content();
		private:
			size_t       _Texture;
			size_t       _TextureSize;
			vector<Quad> _Quads;
		};
	}
}

#endif    
