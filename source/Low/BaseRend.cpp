#include <LDL/Low/BaseRend.hpp>

LDL_BaseRender::LDL_BaseRender(const LDL_Vec2u& size) :
	_Size(size)
{
}

const LDL_Vec2u& LDL_BaseRender::Size()
{
	return _Size;
}

const LDL_Color& LDL_BaseRender::Color()
{
	return _Color;
}

void LDL_BaseRender::SetColor(const LDL_Color& color)
{
	_Color = color;
}
