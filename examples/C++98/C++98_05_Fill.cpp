/*
 * -----------------------------------------------------------------------------
 * This example is in the public domain (CC0 1.0 Universal).
 * You can copy, modify, use, and distribute it for any purpose.
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <LDL/C++98/LDL.hpp>

int main()
{
	LDL::Result  result;
	LDL::Context context;
	LDL::Event   event;
	LDL::Window  window = LDL::Window(result, context, LDL::Vec2i(0, 0), LDL::Vec2i(800, 600), "LDL C++98 lesson 05 - Fill", LDL_WindowModeResized);
	LDL::Render  render = LDL::Render(result, context, window);

	if (result.IsOk())
	{
		while (window.IsRunning() && result.IsOk())
		{
			while (window.GetEvent(event))
			{
				if (event.Type == LDL_EventIsQuit || LDL_EventIsKeyPressed(&event, LDL_KeyEscape))
				{
					window.StopEvent();
				}
			}

			render.Begin();

			render.SetColor(LDL::Color(0, 128, 255));
			render.Clear();

			render.SetColor(LDL::Color(237, 28, 36));
			render.Fill(LDL::Vec2i(0, 0), LDL::Vec2i(window.GetSize().x / 2, window.GetSize().y / 2));

			render.End();
		}
	}

	if (result.IsFail())
	{
		std::cout << "LDL result error: " << result.Message() << std::endl;
	}

	return result.IsOk() ? 0 : -1;
}
