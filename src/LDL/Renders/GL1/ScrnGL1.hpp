// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Renders_GL1_ScrnGL1_hpp
#define LDL_Renders_GL1_ScrnGL1_hpp

#include <LDL/Surface.hpp>
#include <LDL/TexSizer.hpp>

class LDL_ScreenOpenGL1
{
public:
	LDL_ScreenOpenGL1(const LDL_Vec2u& size);
	~LDL_ScreenOpenGL1();
	void Draw(LDL_Surface* image, const LDL_Vec2u& pos, const LDL_Vec2u& size);
	void Draw(LDL_Surface* image, const LDL_Vec2u& pos);
private:
	void DrawTexture(LDL_Surface* image, const LDL_Vec2u& pos, const LDL_Vec2u& size);
	void DrawPixels(LDL_Surface* image, const LDL_Vec2u& pos, const LDL_Vec2u& size);
	LDL_Vec2u           _size;
	size_t          _screen;
	size_t          _maxTextureSize;
	size_t          _curTextureSize;
	LDL_PotTextureSizer _potTextureSizer;
};

#endif    
