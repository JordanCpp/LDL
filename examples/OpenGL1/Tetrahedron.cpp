// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <stdlib.h>
#include <LDL/LDL.hpp>
#include <LDL/OpenGL/GL1_2.hpp>
#include <LDL/OpenGL/GLLoader.hpp>

void Identity()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Init()
{
	// Set the current clear color to sky blue and the current drawing color to
	// white.
	glClearColor(0.1f, 0.39f, 0.88f, 1.0f);
	glColor3f(1.0, 1.0, 1.0);

	// Tell the rendering engine not to draw backfaces.  Without this code,
	// all four faces of the tetrahedron would be drawn and it is possible
	// that faces farther away could be drawn after nearer to the viewer.
	// Since there is only one closed polyhedron in the whole scene,
	// eliminating the drawing of backfaces gives us the realism we need.
	// THIS DOES NOT WORK IN GENERAL.
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	// Set the camera lens so that we have a perspective viewing volume whose
	// horizontal bounds at the near clipping plane are -2..2 and vertical
	// bounds are -1.5..1.5.  The near clipping plane is 1 unit from the camera
	// and the far clipping plane is 40 units away.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-2, 2, -1.5, 1.5, 1, 40);

	// Set up transforms so that the tetrahedron which is defined right at
	// the origin will be rotated and moved into the view volume.  First we
	// rotate 70 degrees around y so we can see a lot of the left side.
	// Then we rotate 50 degrees around x to "drop" the top of the pyramid
	// down a bit.  Then we move the object back 3 units "into the screen".
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0, 0, -3);
	glRotatef(50, 1, 0, 0);
	glRotatef(70, 0, 1, 0);
}

void LDL_Display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	// Draw a white grid "floor" for the tetrahedron to sit on.
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);

	for (GLfloat i = -2.5; i <= 2.5; i += 0.25)
	{
		glVertex3f(i, 0, 2.5); glVertex3f(i, 0, -2.5);
		glVertex3f(2.5, 0, i); glVertex3f(-2.5, 0, i);
	}

	glEnd();

	// Draw the tetrahedron.  It is a four sided figure, so when defining it
	// with a triangle strip we have to repeat the last two vertices.
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(1, 1, 1); glVertex3f(0, 2, 0);
	glColor3f(1, 0, 0); glVertex3f(-1, 0, 1);
	glColor3f(0, 1, 0); glVertex3f(1, 0, 1);
	glColor3f(0, 0, 1); glVertex3f(0, 0, -1.4f);
	glColor3f(1, 1, 1); glVertex3f(0, 2, 0);
	glColor3f(1, 0, 0); glVertex3f(-1, 0, 1);
	glEnd();
}

int main()
{
	LDL_MemoryManager::Instance().Functions(malloc, NULL, NULL, free);

	LDL_Result result;
	LDL_RenderContext renderContext(LDL_RenderMode::OpenGL1);

	LDL_IWindow* window = LDL_CreateWindow(result, renderContext, LDL_Vec2u(0, 0), LDL_Vec2u(800, 600), __FILE__, LDL_WindowMode::Fixed);

	LDL_OpenGLLoader loader(result);
	loader.Init(1, 1);

	LDL_Event report;

	LDL_FpsCounter fpsCounter;
	LDL_Convert convert;
	LDL_FpsLimiter fpsLimiter;

	while (window->Running())
	{
		fpsLimiter.Mark();
		fpsCounter.Start();

		while (window->GetEvent(report))
		{
			if (report.Type == IsQuit)
			{
				window->StopEvent();
			}

			if (report.IsKeyPressed(LDL_KeyboardKey::Escape))
				window->StopEvent();
		}

		Init();
		LDL_Display();

		window->Present();

		fpsLimiter.Throttle();

		if (fpsCounter.Calc())
		{
			window->Title(convert.ToString(fpsCounter.Fps()));
		}
	}

	return 0;
}
