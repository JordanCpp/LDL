#include <LDL/Graphics/BaseRender.hpp>

LDL::Graphics::BaseRender::BaseRender(const LDL::Graphics::Point2u& size) :
	_Size(size)
{
}

const LDL::Graphics::Point2u& LDL::Graphics::BaseRender::Size()
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