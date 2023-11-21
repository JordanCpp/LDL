#include <Arcanum/Graphics/Image.hpp>

using namespace Arcanum::Graphics;
using namespace LDL::Graphics;
using namespace LDL::Math;

Image::Image(LDL::Graphics::RenderContext* renderContext, const Vec2u& size, uint8_t* pixels, const Vec2u& offset, const Vec2u& delta) :
	_Texture(renderContext, size, pixels, 4),
	_Offset(offset),
	_Delta(delta)
{
}

Texture* Image::GetTexture()
{
	return &_Texture;
}

const Vec2u& Image::Offset()
{
	return _Offset;
}

const Vec2u& Image::Delta()
{
	return _Delta;
}