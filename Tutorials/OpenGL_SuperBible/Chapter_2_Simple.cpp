// Simple.c
// The Simplest OpenGL program with GLUT
// OpenGL SuperBible, 3rd Edition
// Richard S. Wright Jr.
// rwright@starstonesoftware.com  
// Modifed for LDL framework by Zoshchuk Evgeniy (Jordan)

#include <iostream>
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Time/FpsCounter.hpp>
#include <LDL/Core/NumberToString.hpp>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Graphics/Render.hpp>
#include <LDL/OpenGL/OpenGL1_2.hpp>

using namespace LDL::Graphics;
using namespace LDL::Events;
using namespace LDL::Time;
using namespace LDL::Core;
using namespace LDL::Math;

///////////////////////////////////////////////////////////
// Called to draw scene
void RenderScene(void)
{
	// Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT);

	// Flush drawing commands
	glFlush();
}

///////////////////////////////////////////////////////////
// Setup the rendering state
void SetupRC(void)
{
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

///////////////////////////////////////////////////////////
// Main program entry point 
int main()
{
	try
	{
		RenderContext renderContext;

		Window window(&renderContext, Vec2u(0, 0), Vec2u(800, 600), "Simple");
		Render render(&renderContext, &window);

		Event report;

		FpsCounter fpsCounter;
		NumberToString convert;

		SetupRC();

		while (window.Running())
		{
			fpsCounter.Start();

			while (window.GetEvent(report))
			{
				if (report.Type == IsQuit)
				{
					window.StopEvent();
				}
			}

			render.Begin();

			RenderScene();

			render.End();

			if (fpsCounter.Calc())
			{
				window.Title(convert.Convert(fpsCounter.Fps()));
				fpsCounter.Clear();
			}

			window.PollEvents();
		}
	}
	catch (const RuntimeError& error)
	{
		std::cout << error.what() << '\n';
	}

	return 0;
}