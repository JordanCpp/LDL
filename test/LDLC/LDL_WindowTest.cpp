#include <LDL/Core/TestEqual.hpp>
#include <LDLC/LDL_Window.h>

int main()
{
	LDL_Window* window = LDL_WindowNew(5, 10, 800, 600, "LDL_WindowTest", 1);

	LDL_TEST_EQUAL(window != NULL);
	LDL_TEST_EQUAL(LDL_WindowGetPosX(window)  == 5);
	LDL_TEST_EQUAL(LDL_WindowGetPosY(window)  == 10);
	LDL_TEST_EQUAL(LDL_WindowGetSizeX(window) == 800);
	LDL_TEST_EQUAL(LDL_WindowGetSizeY(window) == 600);
	LDL_TEST_EQUAL(strcmp(LDL_WindowGetTitle(window), "LDL_WindowTest") == 0);

	LDL_WindowSetTitle(window, "New LDL_WindowTest");
	LDL_TEST_EQUAL(strcmp(LDL_WindowGetTitle(window), "New LDL_WindowTest") == 0);

	LDL_Event event;
	LDL_TEST_EQUAL(LDL_WindowGetEvent(window, &event)  == true);
	LDL_TEST_EQUAL(LDL_WindowWaitEvent(window, &event) == true);

	LDL_WindowStopEvent(window);
	LDL_TEST_EQUAL(LDL_WindowGetEvent(window, &event)  == false);
	LDL_TEST_EQUAL(LDL_WindowWaitEvent(window, &event) == false);

	LDL_WindowFree(window);

	return 0;
}