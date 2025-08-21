#include <Arcanum/Widgets/Container.hpp>

using namespace Arcanum::Widgets;

void Container::Append(Widget* widget)
{
	_widgets.push_back(widget);
}

void Container::Draw()
{
	for (size_t i = 0; i < _widgets.size(); i++)
	{
		_widgets[i]->Draw();
	}
}