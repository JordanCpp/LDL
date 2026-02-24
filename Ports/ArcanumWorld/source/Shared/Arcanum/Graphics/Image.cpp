#include <Arcanum/Graphics/Image.hpp>

using namespace Arcanum::Graphics;
using namespace LDL;

Image::Image(RenderContext* renderContext, const Vec2u& size, uint8_t* pixels, const Vec2u& offset, const Vec2u& delta) :
	_texture(renderContext, size, pixels, 4),
	_offset(offset),
	_delta(delta)
{
}

Texture* Image::GetTexture()
{
	return &_texture;
}

const Vec2u& Image::Offset()
{
	return _offset;
}

const Vec2u& Image::Delta()
{
	return _delta;
}