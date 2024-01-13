# Greetings

This project is an attempt to do only for headers. (https://github.com/JordanCpp/Lib-LDL)

# LDL - Little Directmedia Layer (Header only)
Free cross-platform library.

1. Free for everyone.
2. Consider and accept all ideas.
3. We do not limit the developer.
4. We support old and new platforms.
5. Cross-platform.
6. Static and dynamic link.

# Description of files
LDL_Util.hpp - Common helper classes.
LDL_WinX.hpp - Window and OS event handling.
LDL_RdrX.hpp - Simple 2D render.
LDL_GL.hpp   - Supports all versions of OpenGL (1.0 - 4.6).

# Support platforms.
1. Windows 95 and higher

# Support graphics API.
1. OpenGL >= 1.0 and <= 4.6

# Support renders.

# The main idea is to write an analogue of the SDL library. 
Accessible to everyone, without exception. 
Under a free license. Add interesting functionality.

# License.
Boost Software License - Version 1.0 - August 17th, 2003

# Support compillers (C++ any standarts)
1. MinGW (gcc 3) and higher
2. GCC 3 and higher
3. Visual C++ 5.0 and higher
4. Open Watcom V2
5. Borland C++ 6.0 and higher

# Example
No dependencies

```c++
//Support OpenGL >= 1.0
#define LDL_RENDER_OPENGL1
//Support OpenGL >= 3.0
//#define LDL_RENDER_OPENGL3
#include <LDL/LDL_WinX.hpp>
#include <LDL/LDL_GL.hpp>

#include <stdio.h>

int main()
{
	LDL_Result result;

	LDL_Window window(&result, LDL_Vec2i(0, 0), LDL_Vec2i(800, 600), "test.cpp", LDL_WindowMode::Resized);

	if (result.Ok())
	{
		LDL_OpenGLLoader loader(1, 2);

		LDL_Event report;

		while (window.Running())
		{
			while (window.GetEvent(report))
			{
				if (report.Type == LDL_Event::IsQuit)
				{
					window.StopEvent();
				}
			}

			glClearColor(0.0f, 3.0f, 0.0f, 0.5f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			window.Present();
			window.PollEvents();
		}
	}
	else
	{
		printf("%s/n", result.Message());
	}

	return 0;
}
```