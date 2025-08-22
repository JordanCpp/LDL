// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/LDL.hpp>
#include <LDL/APIs/OpenGL/OpenGL1_2.hpp>
#include <LDL/APIs/OpenGL/GLU.hpp>
#include <LDL/APIs/OpenGL/OpenGLUtilityToolkit.hpp>

using namespace LDL::Graphics;
using namespace LDL::Enums;
using namespace LDL::Events;
using namespace LDL::Time;
using namespace LDL::Core;
using namespace LDL::Allocators;
using namespace LDL::Loaders;
using namespace LDL::Math;

void Identity()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Init()
{
	// Set the current clear color to black and the current drawing color to
	// white.
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);

	// Set the camera lens to have a 60 degree (vertical) field of view, an
	// aspect ratio of 4/3, and have everything closer than 1 unit to the
	// camera and greater than 40 units distant clipped away.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, 4.0 / 3.0, 1, 40);

	// Position camera at (4, 6, 5) looking at (0, 0, 0) with the vector
	// <0, 1, 0> pointing upward.
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(4, 6, 5, 0, 0, 0, 0, 1, 0);
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	// Draw a white torus of outer radius 3, inner radius 0.5 with 15 stacks
	// and 30 slices.
	glColor3f(1.0, 1.0, 1.0);
	glutWireTorus(0.5, 3, 15, 30);

	// Draw a red x-axis, a green y-axis, and a blue z-axis.  Each of the
	// axes are ten units long.
	glBegin(GL_LINES);
	glColor3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(10, 0, 0);
	glColor3f(0, 1, 0); glVertex3f(0, 0, 0); glVertex3f(0, 10, 0);
	glColor3f(0, 0, 1); glVertex3f(0, 0, 0); glVertex3f(0, 0, 10);
	glEnd();
}

int main()
{
	RenderContext renderContext(RenderMode::OpenGL1);

	Window window(renderContext, Vec2u(0, 0), Vec2u(800, 600), "Window!");
	Render render(renderContext, &window);

	Event report;

	FpsCounter fpsCounter;
	Convert convert;
	FpsLimiter fpsLimiter;

	while (window.Running())
	{
		fpsLimiter.Mark();
		fpsCounter.Start();

		while (window.GetEvent(report))
		{
			if (report.Type == IsQuit)
			{
				window.StopEvent();
			}

			if (report.IsKeyPressed(KeyboardKey::Escape))
				window.StopEvent();
		}

		render.Begin();

		Init();
		Display();

		render.End();

		fpsLimiter.Throttle();

		if (fpsCounter.Calc())
		{
			window.Title(convert.ToString(fpsCounter.Fps()));
			fpsCounter.Clear();
		}

		window.PollEvents();
	}

	return 0;
}
