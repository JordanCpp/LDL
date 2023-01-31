#include <LDL/Core/TestEqual.hpp>
#include <LDL/Input/Mouse.hpp>

using namespace LDL::Input;

void GetPos()
{
	Mouse mouse;
	
	LDL_TEST_EQUAL(mouse.Pos().PosX() > 0);
	LDL_TEST_EQUAL(mouse.Pos().PosY() > 0);
}

int main()
{
	GetPos();

	return 0;
}