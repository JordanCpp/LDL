#include <Arcanum/Widgets/Window.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;
using namespace Arcanum;

Widgets::Window::Window(Render* render, const Vec2u& pos, const Vec2u& size) :
	Widget(render, pos, size)
{
}

void Widgets::Window::Attach(Widget* widget)
{
	_Container.Append(widget);
}

void Widgets::Window::Draw()
{
	_Container.Draw();
}