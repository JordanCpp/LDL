#include <LDLC/LDL_Texture.h>
#include <LDL/Graphics/Texture.hpp>
#include <LDL/Graphics/RenderContext.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;

struct LDL_Texture
{
	Texture _Texture;
	LDL_Texture(LDL_RenderContext* renderContext, const Vec2u& size, uint8_t* pixels, uint8_t bytesPerPixel);
};

LDL_Texture::LDL_Texture(LDL_RenderContext* renderContext, const Vec2u& size, uint8_t* pixels, uint8_t bytesPerPixel) :
	_Texture((RenderContext*)renderContext, size, pixels, bytesPerPixel)
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
	return render->_Texture.Size().x;
}

size_t LDL_TextureGetSizeY(LDL_Texture* render)
{
	return render->_Texture.Size().y;
}
