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
	LDL::Context context(result);
	LDL::Event   event;
	LDL::Formatter formatter;
	LDL::FpsCounter fpsCounter(result);
	LDL::Window  window(result, context, LDL::Vec2i(0, 0), LDL::Vec2i(800, 600), "LDL C++98 lesson 01 - Window", LDL::Window::Resized);

	while (window.IsRunning() && result.IsOk())
	{
		fpsCounter.Start();

		while (window.GetEvent(event))
		{
			if (event.Type == LDL_EventIsQuit || event.IsKeyPressed(LDL_KeyEscape))
			{
				window.StopEvent();
			}
		}

		window.Present();

		if (fpsCounter.Calc())
		{
			window.SetTitle(formatter.Format("LDL C89 lesson 06 - Texture. Fps: %d", fpsCounter.Fps()));
		}
	}

	if (result.IsFail())
	{
		std::cout << "LDL result error: " << result.Message() << std::endl;
	}

	return result.IsOk() ? 0 : -1;
}
