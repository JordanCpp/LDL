#include <LDL/Graphics/Base/BaseRender.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;

BaseRender::BaseRender(const Vec2u& size) :
	_Size(size)
{
}

const Vec2u& BaseRender::Size()
{
	return _Size;
}

const LDL::Graphics::Color& BaseRender::Color()
{
	return _Current;
}

void BaseRender::Color(const LDL::Graphics::Color& color)
{
	_Current = color;
}
