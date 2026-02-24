#include <Arcanum/Forms/GameMenu.hpp>

using namespace LDL;
using namespace Arcanum::Forms;

GameMenu::GameMenu(Render* render) :
	Widgets::Form(render, Vec2u(0, 0), render->Size()),
	_button(render, Vec2u(0, 0), Vec2u(300, 300))
{
	Attach(&_button);
}