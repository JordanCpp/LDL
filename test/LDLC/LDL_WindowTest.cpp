#include <LDL/Core/TestEqual.hpp>
#include <LDLC/LDL_Window.h>
#include <string.h>

int main()
{
	LDL_RenderContext* renderContext = LDL_RenderContextNew();

	LDL_Window* window = LDL_WindowNew(renderContext, 5, 10, 640, 480, "LDL_WindowTest", 1);

	LDL_TEST_EQUAL(window != NULL);
	LDL_TEST_EQUAL(LDL_WindowGetPosX(window)  == 5);
	LDL_TEST_EQUAL(LDL_WindowGetPosY(window)  == 10);
	LDL_TEST_EQUAL(LDL_WindowGetSizeX(window) == 640);
	LDL_TEST_EQUAL(LDL_WindowGetSizeY(window) == 480);
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
