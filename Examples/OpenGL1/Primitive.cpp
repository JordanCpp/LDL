// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <stdio.h>
#include <stdlib.h>
#include <LDL/LDL.hpp>
#include <LDL/APIs/OpenGL/OpenGL1_2.hpp>

void Identity()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Display()
{
	Identity();

	glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

	// Define shapes enclosed within a pair of glBegin and glEnd
	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
	glColor3f(1.0f, 0.0f, 0.0f); // Red
	glVertex2f(-0.8f, 0.1f);     // Define vertices in counter-clockwise (CCW) order
	glVertex2f(-0.2f, 0.1f);     //  so that the normal (front-face) is facing you
	glVertex2f(-0.2f, 0.7f);
	glVertex2f(-0.8f, 0.7f);

	glColor3f(0.0f, 1.0f, 0.0f); // Green
	glVertex2f(-0.7f, -0.6f);
	glVertex2f(-0.1f, -0.6f);
	glVertex2f(-0.1f, 0.0f);
	glVertex2f(-0.7f, 0.0f);

	glColor3f(0.2f, 0.2f, 0.2f); // Dark Gray
	glVertex2f(-0.9f, -0.7f);
	glColor3f(1.0f, 1.0f, 1.0f); // White
	glVertex2f(-0.5f, -0.7f);
	glColor3f(0.2f, 0.2f, 0.2f); // Dark Gray
	glVertex2f(-0.5f, -0.3f);
	glColor3f(1.0f, 1.0f, 1.0f); // White
	glVertex2f(-0.9f, -0.3f);
	glEnd();

	glBegin(GL_TRIANGLES);          // Each set of 3 vertices form a triangle
	glColor3f(0.0f, 0.0f, 1.0f); // Blue
	glVertex2f(0.1f, -0.6f);
	glVertex2f(0.7f, -0.6f);
	glVertex2f(0.4f, -0.1f);

	glColor3f(1.0f, 0.0f, 0.0f); // Red
	glVertex2f(0.3f, -0.4f);
	glColor3f(0.0f, 1.0f, 0.0f); // Green
	glVertex2f(0.9f, -0.4f);
	glColor3f(0.0f, 0.0f, 1.0f); // Blue
	glVertex2f(0.6f, -0.9f);
	glEnd();

	glBegin(GL_POLYGON);            // These vertices form a closed polygon
	glColor3f(1.0f, 1.0f, 0.0f); // Yellow
	glVertex2f(0.4f, 0.2f);
	glVertex2f(0.6f, 0.2f);
	glVertex2f(0.7f, 0.4f);
	glVertex2f(0.6f, 0.6f);
	glVertex2f(0.4f, 0.6f);
	glVertex2f(0.3f, 0.4f);
	glEnd();
}

int main()
{
	LDL::MemoryManager::Instance().Functions(malloc, NULL, NULL, free);

	LDL::Result result;
	LDL::RenderContext renderContext(LDL::RenderMode::OpenGL1);

	LDL::Window window(result, renderContext, LDL::Vec2u(0, 0), LDL::Vec2u(800, 600), "Window!");
	LDL::Render render(result, renderContext, &window);

	LDL::Event report;

	LDL::FpsCounter fpsCounter;
	LDL::Convert convert;
	LDL::FpsLimiter fpsLimiter;

	while (window.Running())
	{
		fpsLimiter.Mark();
		fpsCounter.Start();

		while (window.GetEvent(report))
		{
			if (report.Type == LDL::IsQuit)
			{
				window.StopEvent();
			}

			if (report.IsKeyPressed(LDL::KeyboardKey::Escape))
				window.StopEvent();
		}

		render.Begin();

		Display();

		render.End();

		fpsLimiter.Throttle();

		if (fpsCounter.Calc())
		{
			window.Title(convert.ToString(fpsCounter.Fps()));
			
		}
	}

	return 0;
}
