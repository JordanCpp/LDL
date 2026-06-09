/*
 * -----------------------------------------------------------------------------
 * This example is in the public domain (CC0 1.0 Universal).
 * You can copy, modify, use, and distribute it for any purpose.
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <LDL/C++98/LDL.hpp>

int Random(int min, int max)
{
	int range = max - min + 1;

	return min + rand() % range;
}

int count = 10;

int main()
{
	LDL::Result  result;
	LDL::Context context(result);
	LDL::Event   event;
	LDL::Window  window(result, context, LDL::Vec2i(0, 0), LDL::Vec2i(800, 600), "LDL C++98 lesson 06 - Texture. Q: +10 W: -10", LDL_WindowModeResized);
	LDL::Render2D  render(result, context, window);

	LDL::BmpLoader loader(result);

	loader.Load("LDL_24_256_0.bmp");
	LDL::Texture texture0(result, context, loader.GetPixelFormat(), loader.GetSize(), loader.GetPixels());

	loader.Load("LDL_24_256_1.bmp");
	LDL::Texture texture1(result, context, loader.GetPixelFormat(), loader.GetSize(), loader.GetPixels());

	loader.Load("LDL_24_256_2.bmp");
	LDL::Texture texture2(result, context, loader.GetPixelFormat(), loader.GetSize(), loader.GetPixels());

	while (window.IsRunning() && result.IsOk())
	{
		while (window.GetEvent(event))
		{
			if (event.Type == LDL_EventIsQuit || event.IsKeyPressed(LDL_KeyEscape))
			{
				window.StopEvent();
			}

			if (event.IsKeyPressed(LDL_KeyQ))
			{
				count += 10;
			}

			if (event.IsKeyPressed(LDL_KeyW))
			{
				count -= 10;
			}
		}

		render.Begin();

		render.SetColor(LDL::Color(255, 127, 39));
		render.Clear();

		if (count > 0)
		{
			for (size_t i = 0; i < count; i++)
			{
				render.SetLayer(1);
				render.Draw(&texture0, LDL::Vec2i(Random(0, window.GetSize().x), Random(0, window.GetSize().y)), LDL::Vec2i(Random(25, 50), Random(25, 50)));

				render.SetLayer(2);
				render.Draw(&texture1, LDL::Vec2i(Random(0, window.GetSize().x), Random(0, window.GetSize().y)), LDL::Vec2i(Random(25, 50), Random(25, 50)));

				render.SetLayer(3);
				render.Draw(&texture2, LDL::Vec2i(Random(0, window.GetSize().x), Random(0, window.GetSize().y)), LDL::Vec2i(Random(25, 50), Random(25, 50)));
			}
		}

		render.End();
	}

	if (result.IsFail())
	{
		std::cout << "LDL result error: " << result.Message() << std::endl;
	}

	return result.IsOk() ? 0 : -1;
}
