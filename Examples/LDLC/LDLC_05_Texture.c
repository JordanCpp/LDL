#include <LDLC/LDL_Render.h>
#include <LDLC/LDL_FpsCounter.h>
#include <LDLC/LDL_NumberToString.h>
#include <LDLC/LDL_FixedLinear.h>
#include <LDLC/LDL_ImageLoader.h>
#include <LDLC/LDL_Texture.h>

int main()
{
	LDL_Window* window = LDL_WindowNew(0, 0, 800, 600, "05_Texture", LDL_WindowModeResized);

	LDL_RenderContext* renderContext = LDL_RenderContextNew();
	LDL_Render* render = LDL_RenderNew(renderContext, window);
	LDL_NumberToString* convert = LDL_NumberToStringNew();
	LDL_FpsCounter* counter = LDL_FpsCounterNew(60);

	LDL_FixedLinear* allocator = LDL_FixedLinearNew(1024 * 1024 * 4, NULL);
	LDL_ImageLoader* loader = LDL_ImageLoaderNew(allocator);

	LDL_Event report;

	LDL_RenderSetColor(render, 0, 162, 232, 0);

	LDL_ImageLoaderLoadFromFile(loader, "trehmachtovyiy-korabl-kartina-maslom-60x50_512x.jpg");

	size_t w = LDL_ImageLoaderGetSizeX(loader);
	size_t h = LDL_ImageLoaderGetSizeY(loader);
	uint8_t * pixels = LDL_ImageLoaderGetPixels(loader);
	uint8_t bpp = LDL_ImageLoaderGetBytesPerPixel(loader);

	LDL_Texture* texture = LDL_TextureNew(renderContext, w, h, pixels, bpp);

	while (LDL_WindowGetEvent(window, &report))
	{
		LDL_FpsCounterStart(counter);

		LDL_RenderBegin(render);

		LDL_RenderSetColor(render, 0, 162, 232, 0);
		LDL_RenderClear(render);

		size_t x = LDL_WindowGetPosX(window);
		size_t y = LDL_WindowGetPosY(window);
		size_t w = LDL_WindowGetSizeX(window);
		size_t h = LDL_WindowGetSizeY(window);

		LDL_RenderDrawTexture2(render, texture, x, y, w, h);

		LDL_RenderEnd(render);

		if (LDL_FpsCounterCalc(counter))
		{
			LDL_WindowSetTitle(window, LDL_NumberToStringConvertInt(convert, LDL_FpsCounterGetFps(counter)));
			LDL_FpsCounterClear(counter);
		}

		if (report.Type == LDL_EventIsQuit)
		{
			LDL_WindowStopEvent(window);
		}
	}

	LDL_FixedLinearFree(allocator);
	LDL_ImageLoaderFree(loader);
	LDL_FpsCounterFree(counter);
	LDL_NumberToStringFree(convert);
	LDL_WindowFree(window);
	LDL_RenderFree(render);

	return 0;
}