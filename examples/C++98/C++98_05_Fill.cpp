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

const size_t count = 1000;

int main()
{
	LDL::Result  result;
	LDL::Context context(result);
	LDL::Event   event;
	LDL::Window  window(result, context, LDL::Vec2i(0, 0), LDL::Vec2i(800, 600), "LDL C++98 lesson 05 - Fill", LDL_WindowModeResized);
	LDL::Render2D  render(result, context, window);

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

		render.SetColor(LDL::Color(0, 128, 255));
		render.Clear();

		int w = window.GetSize().x;
		int h = window.GetSize().y;

		for (size_t i = 0; i < count; i++)
		{
			render.SetColor(LDL::Color(Random(0, 255), Random(0, 255), Random(0, 255)));
			render.Fill(LDL::Vec2i(Random(0, w), Random(0, h)), LDL::Vec2i(Random(25, 50), Random(25, 50)));
		}

		render.End();
	}

	if (result.IsFail())
	{
		std::cout << "LDL result error: " << result.Message() << std::endl;
	}

	return result.IsOk() ? 0 : -1;
}
