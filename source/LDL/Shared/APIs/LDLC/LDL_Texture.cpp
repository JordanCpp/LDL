// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDLC/LDL_Texture.h>
#include <LDL/Graphics/Texture.hpp>
#include <LDL/Graphics/RenderContext.hpp>

using namespace LDL;

struct LDL_Texture
{
	Texture _texture;
	LDL_Texture(LDL_RenderContext* renderContext, const Vec2u& size, uint8_t* pixels, uint8_t bytesPerPixel);
};

LDL_Texture::LDL_Texture(LDL_RenderContext* renderContext, const Vec2u& size, uint8_t* pixels, uint8_t bytesPerPixel) :
	_texture((RenderContext*)renderContext, size, pixels, bytesPerPixel)
{
}

LDL_Texture* LDL_TextureNew(LDL_RenderContext* renderContext, size_t w, size_t h, uint8_t* pixels, uint8_t bytesPerPixel)
{
	LDL_Texture* p = new LDL_Texture(renderContext, Vec2u(w, h), pixels, bytesPerPixel);

	return p;
}

void LDL_TextureFree(LDL_Texture* render)
{
	delete render;
}

size_t LDL_TextureGetSizeX(LDL_Texture* render)
{
	return render->_texture.Size().x;
}

size_t LDL_TextureGetSizeY(LDL_Texture* render)
{
	return render->_texture.Size().y;
}
