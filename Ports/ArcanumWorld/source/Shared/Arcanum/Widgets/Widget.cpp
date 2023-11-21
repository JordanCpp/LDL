#include <Arcanum/Widgets/Widget.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;
using namespace Arcanum::Widgets;

Widget::Widget(Render* render, const Vec2u& pos, const Vec2u& size) :
	_Render(render),
	_Area(pos, size)
{
}

Widget::~Widget()
{
}

const Vec2u Widget::Pos()
{
	return _Area.Pos();
}

const Vec2u Widget::Size()
{
	return _Area.Size();
}

Render* Widget::GetRender()
{
	return _Render;
}