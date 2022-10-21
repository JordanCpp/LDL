#include <LDL/Core/TestEqual.hpp>
#include <LDL/Events/Eventer.hpp>

void Eventer()
{
	LDL::Events::Eventer eventer;
	LDL_TEST_EQUAL(eventer.Running() == true);

	LDL::Events::Event event;

	event.Type = LDL::Events::IsQuit;
	eventer.Push(event);
	LDL_TEST_EQUAL(eventer.Running() == true);

	event.Type = LDL::Events::IsMouseClick;
	eventer.Push(event);
	LDL_TEST_EQUAL(eventer.Running() == true);

	event.Type = LDL::Events::IsMouseMove;
	eventer.Push(event);
	LDL_TEST_EQUAL(eventer.Running() == true);

	LDL::Events::Event dest;

	LDL_TEST_EQUAL(eventer.Pop(dest) == true);
	LDL_TEST_EQUAL(dest.Type == LDL::Events::IsQuit);
	LDL_TEST_EQUAL(eventer.Running() == true);

	LDL_TEST_EQUAL(eventer.Pop(dest) == true);
	LDL_TEST_EQUAL(dest.Type == LDL::Events::IsMouseClick);
	LDL_TEST_EQUAL(eventer.Running() == true);

	LDL_TEST_EQUAL(eventer.Pop(dest) == true);
	LDL_TEST_EQUAL(dest.Type == LDL::Events::IsMouseMove);
	LDL_TEST_EQUAL(eventer.Running() == true);

	LDL_TEST_EQUAL(eventer.Pop(dest) == false);

	eventer.Stop();
	LDL_TEST_EQUAL(eventer.Running() == false);
}

int main()
{
	Eventer();

	return 0;
}