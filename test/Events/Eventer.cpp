#include <LDL/Core/TestEqual.hpp>
#include <LDL/Events/Eventer.hpp>

using namespace LDL::Events;

void EventerTest()
{
	Eventer eventer;
	LDL_TEST_EQUAL(eventer.Running() == true);

	Event event;

	event.Type = IsQuit;
	eventer.Push(event);
	LDL_TEST_EQUAL(eventer.Running() == true);

	event.Type = IsMouseClick;
	eventer.Push(event);
	LDL_TEST_EQUAL(eventer.Running() == true);

	event.Type = IsMouseMove;
	eventer.Push(event);
	LDL_TEST_EQUAL(eventer.Running() == true);

	Event dest;

	LDL_TEST_EQUAL(eventer.Pop(dest) == true);
	LDL_TEST_EQUAL(dest.Type == IsQuit);
	LDL_TEST_EQUAL(eventer.Running() == true);

	LDL_TEST_EQUAL(eventer.Pop(dest) == true);
	LDL_TEST_EQUAL(dest.Type == IsMouseClick);
	LDL_TEST_EQUAL(eventer.Running() == true);

	LDL_TEST_EQUAL(eventer.Pop(dest) == true);
	LDL_TEST_EQUAL(dest.Type == IsMouseMove);
	LDL_TEST_EQUAL(eventer.Running() == true);

	LDL_TEST_EQUAL(eventer.Pop(dest) == false);

	eventer.Stop();
	LDL_TEST_EQUAL(eventer.Running() == false);
}

int main()
{
	EventerTest();

	return 0;
}
