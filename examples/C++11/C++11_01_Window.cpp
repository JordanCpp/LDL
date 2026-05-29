/*
 * -----------------------------------------------------------------------------
 * This example is in the public domain (CC0 1.0 Universal).
 * You can copy, modify, use, and distribute it for any purpose.
 * -----------------------------------------------------------------------------
 */

#include <iostream>
#include <LDL/C++11/LDL.hpp>

int main()
{
	LDL::Result result{};
	LDL::Context context{};
	LDL::Event event{};

	LDL::Window window(
		result, 
		context, 
		{ 0, 0 },
		{ 800, 600 },
		"LDL C++11 lesson 01 - Window", 
		LDL_WindowModeResized
	);

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

			window.Present();
		}
	}

	if (result.IsFail())
	{
		std::cerr << "LDL result error: " << result.Message() << std::endl;
	}

	return result.IsOk() ? 0 : -1;
}
