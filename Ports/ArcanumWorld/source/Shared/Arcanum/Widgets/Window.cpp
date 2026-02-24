#include <Arcanum/Widgets/Window.hpp>

using namespace LDL;
using namespace Arcanum;

Widgets::Window::Window(Render* render, const Vec2u& pos, const Vec2u& size) :
	Widget(render, pos, size)
{
}

void Widgets::Window::Attach(Widget* widget)
{
	_container.Append(widget);
}

void Widgets::Window::Draw()
{
	_container.Draw();
}