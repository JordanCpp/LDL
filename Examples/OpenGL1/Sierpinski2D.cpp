// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/LDL.hpp>
#include <LDL/APIs/OpenGL/OpenGL1_2.hpp>
#include <LDL/APIs/OpenGL/GLU.hpp>
#include <stdlib.h>

using namespace LDL::Graphics;
using namespace LDL::Enums;
using namespace LDL::Events;
using namespace LDL::Time;
using namespace LDL::Core;
using namespace LDL::Allocators;
using namespace LDL::Math;

// A simple two-dimensional point class to make life easy.  It allows you to
// reference points with x and y coordinates instead of array indices) and
// encapsulates a midpoint function.
struct Point {
	GLfloat x, y;
	Point(GLfloat x = 0, GLfloat y = 0) : x(x), y(y) {}
	Point midpoint(Point p) { return Point((x + p.x) / 2.0f, (y + p.y) / 2.0f); }
};

void Identity()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// Performs application-specific initialization. Sets colors and sets up a
// simple orthographic projection.
void Init()
{
	// Set a deep purple background and draw in a greenish yellow.
	glClearColor(0.25f, 0.0f, 0.2f, 1.0f);
	glColor3f(0.6f, 1.0f, 0.0f);

	// Set up the viewing volume: 500 x 500 x 1 window with origin lower left.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 500.0, 0.0, 500.0, 0.0, 1.0);
}

// Draws a Sierpinski triangle with a fixed number of points. (Note that the
// number of points is kept fairly small because a display callback should
// NEVER run for too long.
void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	static Point vertices[] = { Point(0, 0), Point(200, 500), Point(500, 0) };

	// Compute and plot 100000 new points, starting (arbitrarily) with one of
	// the vertices. Each point is halfway between the previous point and a
	// randomly chosen vertex.
	static Point p = vertices[0];

	glBegin(GL_POINTS);

	for (int k = 0; k < 100000; k++)
	{
		p = p.midpoint(vertices[rand() % 3]);
		glVertex2f(p.x, p.y);
	}

	glEnd();
}

int main()
{
	MemoryManager::Instance().Functions(malloc, NULL, NULL, free);

	Result result;
	RenderContext renderContext(RenderMode::OpenGL1);

	Window window(result, renderContext, Vec2u(0, 0), Vec2u(800, 600), "Window!");
	Render render(result, renderContext, &window);

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
			
		}

		
	}

	return 0;
}
