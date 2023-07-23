#include <LDL/Core/TestEqual.hpp>
#include <LDLC/LDL_Render.h>

int main()
{
	LDL_RenderContext* renderContext = LDL_RenderContextNew();
	LDL_TEST_EQUAL(renderContext != NULL);

	LDL_Window* window = LDL_WindowNew(renderContext, 0, 0, 640, 480, "LDL_WindowTest", 1);

	LDL_Render* render = LDL_RenderNew(renderContext, window);
	LDL_TEST_EQUAL(render != NULL);

	LDL_TEST_EQUAL(LDL_RenderGetSizeX(render) > 0);
	LDL_TEST_EQUAL(LDL_RenderGetSizeX(render) <= 640);

	LDL_TEST_EQUAL(LDL_RenderGetSizeY(render) > 0);
	LDL_TEST_EQUAL(LDL_RenderGetSizeY(render) <= 480);

	LDL_RenderContextFree(renderContext);
	LDL_RenderFree(render);
	LDL_WindowFree(window);

	return 0;
}
