
#include <LDL/Shared/Graphics/Base/BaseRender.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;

BaseRender::BaseRender(const Vec2u& size) :
	_size(size)
{
}

const Vec2u& BaseRender::Size()
{
	return _size;
}

const LDL::Graphics::Color& BaseRender::Color()
{
	return _current;
}

void BaseRender::Color(const LDL::Graphics::Color& color)
{
	_current = color;
}
