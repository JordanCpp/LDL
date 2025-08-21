#include <Arcanum/Managers/WidgetManager.hpp>

using namespace LDL::Math;
using namespace LDL::Graphics;
using namespace Arcanum::Managers;
using namespace Arcanum::Widgets;

WidgetManager::WidgetManager(Render* render) :
	_render(render)
{
}

WidgetManager::~WidgetManager()
{
	for (size_t i = 0; i < _widgets.size(); i++)
		delete _widgets[i];
}

Button* WidgetManager::GetButton(const Vec2u& pos, const Vec2u& size)
{
	auto result = new Button(_render, pos, size);

	_widgets.push_back(result);

	return result;
}

Form* WidgetManager::GetForm()
{
	auto result = new Form(_render, Vec2u(0,0), _render->Size());

	_widgets.push_back(result);

	return result;
}