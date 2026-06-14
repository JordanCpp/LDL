/*
 * -----------------------------------------------------------------------------
 * This example is in the public domain (CC0 1.0 Universal).
 * You can copy, modify, use, and distribute it for any purpose.
 * -----------------------------------------------------------------------------
 */

#include <vector>
#include <iostream>
#include <LDL/C++98/LDL.hpp>

int main()
{
	LDL::Result result;
	LDL::Context context(result);
	LDL::Event event;
	LDL::Window window(result, context, LDL::Vec2i(0, 0), LDL::Vec2i(800, 600), "LDL C++98 lesson 09 - Tile map", LDL_WindowModeResized);
	LDL::Render2D render(result, context, window);
	LDL::Font font(result, "Files/Lato-Bold.ttf", 30);
	LDL::Rasterizer rasterizer(result);

	rasterizer.Text(&font, LDL::Color(0, 162, 232), "Hello LDL!");
	LDL::Texture english(result, context, rasterizer.GetPixelFormat(), rasterizer.GetSize(), rasterizer.GetPixels());

	rasterizer.Text(&font, LDL::Color(34, 177, 76), "Привет LDL!");
	LDL::Texture russian(result, context, rasterizer.GetPixelFormat(), rasterizer.GetSize(), rasterizer.GetPixels());

	while (window.IsRunning() && result.IsOk())
	{
		while (window.GetEvent(event))
		{
			if (event.Type == LDL_EventIsQuit || event.IsKeyPressed(LDL_KeyEscape))
			{
				window.StopEvent();
			}
		}

		render.Begin();

		render.SetColor(LDL::Color(255, 127, 39));
		render.Clear();

		render.Draw(&russian, LDL::Vec2i(5, 5));
		render.Draw(&english, LDL::Vec2i(5, 50));
		
		render.End();
	}

	if (result.IsFail())
	{
		std::cout << "LDL result error: " << result.Message() << std::endl;
	}

	return result.IsOk() ? 0 : -1;
}
