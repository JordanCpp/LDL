#include <LDL/Text/Rasterizer.hpp>
#include "RasterizerImpl.hpp"

using namespace LDL::Text;
using namespace LDL::Graphics;

Rasterizer::Rasterizer(const Math::Vec2u& bufferSize) :
	_RasterizerImpl(new RasterizerImpl(bufferSize))
{
}

Rasterizer::~Rasterizer()
{
	delete _RasterizerImpl;
}

RasterizerImpl* Rasterizer::GetRasterizerImpl()
{
	return _RasterizerImpl;
}

Surface* Rasterizer::Result()
{
	return _RasterizerImpl->Result();
}

bool Rasterizer::RenderText(const std::string& text, Font* font, const Color& color)
{
	return _RasterizerImpl->RenderText(text, font, color);
}
