// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_OpenGL1_Screen_hpp
#define LDL_Graphics_OpenGL1_Screen_hpp

#include <LDL/Graphics/Surface.hpp>
#include <LDL/Shared/Math/PotTextureSizer.hpp>

namespace LDL
{
	class ScreenOpenGL1
	{
	public:
		ScreenOpenGL1(const Vec2u& size);
		~ScreenOpenGL1();
		void Draw(Surface* image, const Vec2u& pos, const Vec2u& size);
		void Draw(Surface* image, const Vec2u& pos);
	private:
		void DrawTexture(Surface* image, const Vec2u& pos, const Vec2u& size);
		void DrawPixels(Surface* image, const Vec2u& pos, const Vec2u& size);
		Vec2u           _size;
		size_t          _screen;
		size_t          _maxTextureSize;
		size_t          _curTextureSize;
		PotTextureSizer _potTextureSizer;
	};
}

#endif    
