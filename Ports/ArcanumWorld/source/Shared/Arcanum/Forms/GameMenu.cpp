#include <Arcanum/Forms/GameMenu.hpp>

using namespace LDL::Math;
using namespace LDL::Graphics;
using namespace Arcanum::Forms;

GameMenu::GameMenu(Render* render) :
	Widgets::Form(render, Vec2u(0, 0), render->Size()),
	_Button(render, Vec2u(0, 0), Vec2u(300, 300))
{
	Attach(&_Button);
}