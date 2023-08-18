#include <Arcanum/Widgets/Container.hpp>

using namespace Arcanum::Widgets;

void Container::Append(Widget* widget)
{
	_Widgets.push_back(widget);
}

void Container::Draw()
{
	for (size_t i = 0; i < _Widgets.size(); i++)
	{
		_Widgets[i]->Draw();
	}
}