#include <LDL/Graphics/Base/BaseRender.hpp>

using namespace LDL::Graphics;

BaseRender::BaseRender(const Point2u& size) :
	_Size(size)
{
}

const Point2u& BaseRender::Size()
{
	return _Size;
}

const LDL::Graphics::Color& LDL::Graphics::BaseRender::Color()
{
	return _Current;
}

void LDL::Graphics::BaseRender::Color(const LDL::Graphics::Color& color)
{
	_Current = color;
}