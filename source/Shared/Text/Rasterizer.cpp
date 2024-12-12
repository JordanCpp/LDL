#include <LDL/Text/Rasterizer.hpp>
#include "RasterizerImpl.hpp"

using namespace LDL::Math;
using namespace LDL::Text;
using namespace LDL::Graphics;

Rasterizer::Rasterizer(const Vec2u& bufferSize) :
	_impl(new RasterizerImpl(bufferSize))
{
}

Rasterizer::~Rasterizer()
{
	delete _impl;
}

RasterizerImpl* Rasterizer::GetRasterizerImpl()
{
	return _impl;
}

Surface* Rasterizer::Result()
{
	return _impl->Result();
}

bool Rasterizer::RenderText(const std::string& text, Font* font, const Color& color)
{
	return _impl->RenderText(text, font, color);
}
