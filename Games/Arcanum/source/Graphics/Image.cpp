#include <Arcanum/Graphics/Image.hpp>

using namespace Arcanum::Graphics;

Image::Image(LDL::Graphics::RenderContext* renderContext, const LDL::Graphics::Point2u& size, uint8_t* pixels, const LDL::Graphics::Point2u& pos) :
	_Texture(renderContext, size, pixels, 4),
	_Pos(pos)
{
}