#include <Arcanum/Widgets/Form.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;
using namespace Arcanum::Widgets;

Form::Form(Render* render, const Vec2u& pos, const Vec2u& size) :
	Widget(render, pos, size)
{
}

void Form::Attach(Widget* widget)
{
	_container.Append(widget);
}

void Form::Draw()
{
	_container.Draw();
}